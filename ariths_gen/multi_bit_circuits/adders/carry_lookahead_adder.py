from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    ArithmeticCircuit,
    MultiplierCircuit
)
from ariths_gen.core.logic_gate_circuits import (
    MultipleInputLogicGate
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    PGLogicBlock,
    FullAdder,
    FullAdderPG
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)


class UnsignedCarryLookaheadAdder(ArithmeticCircuit):
    """Class representing unsigned carry-lookahead adder.

    Unsigned carry-lookahead adder represents faster adder circuit which is composed
    of more complex circuitry but provides much less propagation delay as opposed to rca.
    It is mainly composed of propagate/generate blocks and many AND/OR gates to calculate carries individually.

    ```
      B3 A3      B2 A2      B1 A1      B0 A0
      │  │       │  │       │  │       │  │
    ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐
    │  PG  │   │  PG  │   │  PG  │   │  PG  │
    │ block│   │ block│   │ block│   │ block│
    │      │   │      │   │      │   │      │
    └─┬┬┬──┘   └─┬┬┬──┘   └─┬┬┬──┘   └─┬┬┬──┘
      │││G3P3S3  │││G2P2S2  │││G1P1S1  │││G0P0S0
    ┌─▼▼▼────────▼▼▼────────▼▼▼────────▼▼▼──┐
    │         Carry Lookahead logic         │
    │                                       │
    └┬────┬───────┬──────────┬──────────┬───┘
     │    │       │          │          │
     ▼    ▼       ▼          ▼          ▼
    Cout  S3      S1         S0         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned cla. Defaults to "u_cla".
    """
    def __init__(self, a: Bus, b: Bus, cla_block_size: int = 4, prefix: str = "u_cla"):
        #TODO
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = Bus(prefix=a.prefix, wires_list=a.bus)
        self.b = Bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for N sum bits and additional cout bit
        self.out = Bus(self.prefix+"_out", self.N+1)

        # To signify current number of blocks and number of bits that remain to be added into function blocks
        N_blocks = 0
        N_wires = self.N
        cin = ConstantWireValue0()

        while N_wires != 0:
            # Lists containing all propagate/generate wires
            self.propagate = []
            self.generate = []
            # Cin0 used as a first generate wire for obtaining next carry bits
            self.generate.append(cin)
            block_size = cla_block_size if N_wires >= cla_block_size else N_wires

            # Gradual addition of propagate/generate logic blocks and AND/OR gates for Cout bits generation, XOR gates for Sum bits generation
            for i in range(block_size):
                pg_block = PGLogicBlock(self.a.get_wire((N_blocks*cla_block_size)+i), self.b.get_wire((N_blocks*cla_block_size)+i), prefix=self.prefix+"_pg_logic"+str(self.get_instance_num(cls=PGLogicBlock)))
                self.propagate.append(pg_block.get_propagate_wire())
                self.generate.append(pg_block.get_generate_wire())
                self.add_component(pg_block)

                if i == 0 and N_blocks == 0:
                    obj_sum_xor = XorGate(pg_block.get_sum_wire(), cin, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
                    self.add_component(obj_sum_xor)
                    self.out.connect(i+(N_blocks*cla_block_size), obj_sum_xor.out)

                    # Carry propagation calculation
                    obj_and = AndGate(self.propagate[(N_blocks*cla_block_size)+i], self.generate[(N_blocks*cla_block_size)+i], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
                    self.add_component(obj_and)

                    # Carry bit generation
                    obj_cout_or = OrGate(pg_block.get_generate_wire(), self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate, count_disabled_gates=False)), parent_component=self)
                    self.add_component(obj_cout_or)
                else:
                    obj_sum_xor = XorGate(pg_block.get_sum_wire(), self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
                    self.add_component(obj_sum_xor)
                    self.out.connect(i+(N_blocks*cla_block_size), obj_sum_xor.out)

                    # List of AND gates outputs that are later combined in a multi-bit OR gate
                    composite_or_gates_inputs = []

                    for g_index in range(len(self.generate)-1):
                        composite_wires = []
                        # Getting a list of wires used for current bit position cout composite AND gate's generation
                        # E.g. for Cout2 = G1 + G0·P1 C0·P0·P1 it gets a list containing [C0,P0,P1] then [G0,P1]
                        composite_wires.append(self.generate[g_index])
                        for p_index in range(len(self.propagate)-1, g_index-1, -1):
                            composite_wires.append(self.propagate[p_index])

                        # For each pg pair values algorithmically combine two input AND gates to replace multiple input gates (resolves fan-in issue)
                        pg_wires = Bus(wires_list=composite_wires)
                        multi_bit_and_gate = MultipleInputLogicGate(a=pg_wires, two_input_gate_cls=AndGate, prefix=self.prefix+"_and", parent_component=self)
                        composite_or_gates_inputs.append(multi_bit_and_gate.out)

                    # Final OR gates cascade using generated AND gates output wires
                    composite_or_wires = Bus(wires_list=composite_or_gates_inputs)
                    multi_bit_or_gate = MultipleInputLogicGate(a=composite_or_wires, two_input_gate_cls=OrGate, prefix=self.prefix+"_or", parent_component=self)

                    # Carry bit generation
                    obj_cout_or = OrGate(pg_block.get_generate_wire(), multi_bit_or_gate.out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate, count_disabled_gates=False)), parent_component=self)
                    self.add_component(obj_cout_or)

            # Updating cin for the the next bypass block
            # Also updating cout value which is used as cin for the first adder of the next block
            cin = obj_cout_or.out

            N_wires -= block_size
            N_blocks += 1


        # Connection of final Cout
        self.out.connect(self.N, cin)


class SignedCarryLookaheadAdder(UnsignedCarryLookaheadAdder, ArithmeticCircuit):
    """Class representing signed carry-lookahead adder.

    Signed carry-lookahead adder represents faster adder circuit which is composed
    of more complex circuitry but provides much less propagation delay as opposed to rca.
    It is mainly composed of propagate/generate blocks and many AND/OR gates to calculate carries individually.
    At last XOR gates are used to ensure proper sign extension.

    ```
      B3 A3      B2 A2      B1 A1      B0 A0
      │  │       │  │       │  │       │  │
    ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐
    │  PG  │   │  PG  │   │  PG  │   │  PG  │
    │ block│   │ block│   │ block│   │ block│
    │      │   │      │   │      │   │      │
    └─┬┬┬──┘   └─┬┬┬──┘   └─┬┬┬──┘   └─┬┬┬──┘
      │││G3P3S3  │││G2P2S2  │││G1P1S1  │││G0P0S0
    ┌─▼▼▼────────▼▼▼────────▼▼▼────────▼▼▼──┐
    │         Carry Lookahead logic         │
    │          with sign extension          │
    └┬────┬───────┬──────────┬──────────┬───┘
     │    │       │          │          │
     ▼    ▼       ▼          ▼          ▼
    Cout  S3      S1         S0         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed cla. Defaults to "s_cla".
    """
    def __init__(self, a: Bus, b: Bus, cla_block_size: int = 4, prefix: str = "s_cla"):
        super().__init__(a=a, b=b, cla_block_size=cla_block_size, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
