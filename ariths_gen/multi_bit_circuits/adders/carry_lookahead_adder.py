from ariths_gen.wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.core.logic_gate_circuits import (
    MultipleInputLogicGate
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    PGLogicBlock
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    OrGate,
    XorGate
)


class UnsignedCarryLookaheadAdder(GeneralCircuit):
    """Class representing unsigned carry-lookahead adder.

    Unsigned carry-lookahead adder represents faster adder circuit which is composed
    of more complex circuitry but provides much less propagation delay as opposed to rca.
    It is mainly composed of propagate/generate blocks and many AND/OR gates to calculate carries individually.

    Class enables to choose the size of composite inner cla blocks (default is 4). These cla blocks are then cascaded
    to form the final N bit adder.

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
    │     Carry Lookahead logic block       │
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
        cla_block_size (int, optional): Size of each composite cla adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of unsigned cla. Defaults to "".
        name (str, optional): Name of unsigned cla. Defaults to "u_cla".
    """
    def __init__(self, a: Bus, b: Bus, cla_block_size: int = 4, prefix: str = "", name: str = "u_cla", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        assert cla_block_size > 0, "Block size of the individual cla groups must be greater than 0."

        # To signify current number of blocks and number of bits that remain to be added into function blocks
        block_n = 0
        N_wires = self.N
        cin = ConstantWireValue0()
        while N_wires != 0:
            # Lists containing all propagate/generate wires for the current cla block
            propagate_sig = []
            generate_sig = []
            # Cin0 used as a first generate wire for obtaining next carry bits
            generate_sig.append(cin)
            block_size = cla_block_size if N_wires >= cla_block_size else N_wires

            # Gradual addition of propagate/generate logic blocks and AND/OR gates for Cout bits generation, XOR gates for Sum bits generation
            for i in range(block_size):
                pg_block = PGLogicBlock(self.a.get_wire((block_n*cla_block_size)+i), self.b.get_wire((block_n*cla_block_size)+i), prefix=self.prefix+"_pg_logic"+str(self.get_instance_num(cls=PGLogicBlock)))
                propagate_sig.append(pg_block.get_propagate_wire())
                generate_sig.append(pg_block.get_generate_wire())
                self.add_component(pg_block)

                self.add_component(XorGate(pg_block.get_sum_wire(), cin, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self))
                self.out.connect(i+(block_n*cla_block_size), self.get_previous_component().out)

                # List of AND gates outputs that are later combined in a multi-bit OR gate
                composite_or_gates_inputs = []
                for g_index in range(len(generate_sig)-1):
                    composite_wires = []
                    # Getting a list of wires used for current bit position cout composite AND gate's generation
                    # E.g. for Cout2 = G1 + G0·P1 C0·P0·P1 it gets a list containing [C0,P0,P1] then [G0,P1]
                    composite_wires.append(generate_sig[g_index])
                    for p_index in range(len(propagate_sig)-1, g_index-1, -1):
                        composite_wires.append(propagate_sig[p_index])

                    # For each pg pair values algorithmically combine two input AND gates to replace multiple input gates (resolves fan-in issue)
                    pg_wires = Bus(wires_list=composite_wires)
                    multi_bit_and_gate = MultipleInputLogicGate(a=pg_wires, two_input_gate_cls=AndGate, prefix=self.prefix+f"_and{block_n}_{i}_{g_index}", parent_component=self)
                    composite_or_gates_inputs.append(multi_bit_and_gate.out)

                # Final OR gates cascade using generated AND gates output wires
                composite_or_wires = Bus(wires_list=composite_or_gates_inputs)
                multi_bit_or_gate = MultipleInputLogicGate(a=composite_or_wires, two_input_gate_cls=OrGate, prefix=self.prefix+f"_orred{block_n}_{i}_{g_index}_", parent_component=self)
                # Carry bit generation
                obj_cout_or = OrGate(pg_block.get_generate_wire(), multi_bit_or_gate.out, prefix=self.prefix+f"_or{block_n}_{i}_{g_index}_"+str(self.get_instance_num(cls=OrGate, count_disabled_gates=False)), parent_component=self)
                self.add_component(obj_cout_or)
                # Updating cin for the the next cla block/sum XOR
                cin = obj_cout_or.out

            N_wires -= block_size
            block_n += 1

        # Connection of final Cout
        self.out.connect(self.N, cin)


class SignedCarryLookaheadAdder(UnsignedCarryLookaheadAdder, GeneralCircuit):
    """Class representing signed carry-lookahead adder.

    Signed carry-lookahead adder represents faster adder circuit which is composed
    of more complex circuitry but provides much less propagation delay as opposed to rca.
    It is mainly composed of propagate/generate blocks and many AND/OR gates to calculate carries individually.

    Class enables to choose the size of composite inner cla blocks (default is 4). These cla blocks are then cascaded
    to form the final N bit adder.
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
        cla_block_size (int, optional): Size of each composite cla adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of signed cla. Defaults to "".
        name (str, optional): Name of signed cla. Defaults to "s_cla".
    """
    def __init__(self, a: Bus, b: Bus, cla_block_size: int = 4, prefix: str = "", name: str = "s_cla", **kwargs):
        super().__init__(a=a, b=b, cla_block_size=cla_block_size, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
