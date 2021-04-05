from ariths_gen.wire_components import (
    Wire,
    Bus
)
from ariths_gen.core import (
    ArithmeticCircuit,
    MultiplierCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    PGLogicBlock,
    ConstantWireValue0,
    ConstantWireValue1,
    FullAdder,
    FullAdderPG
)
from ariths_gen.one_bit_circuits.logic_gates import (
    LogicGate,
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)


class UnsignedCarryLookaheadAdder(ArithmeticCircuit):
    """Class representing unsigned carry look-ahead adder.

    Unsigned carry look-ahead adder represents faster adder circuit which is composed
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
    def __init__(self, a: Bus, b: Bus, prefix: str = "u_cla"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = Bus(prefix=a.prefix, wires_list=a.bus)
        self.b = Bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Lists containing all propagate/generate wires
        self.propagate = []
        self.generate = []

        # Output wires for N sum bits and additional cout bit
        self.out = Bus("out", self.N+1)

        # Constant wire with value 0 for cin 0
        constant_wire_0 = ConstantWireValue0(self.a.get_wire(), self.b.get_wire())
        self.add_component(constant_wire_0)
        # Used as a first generate wire for obtaining next carry bits
        self.generate.append(constant_wire_0.out.get_wire())

        # Gradual addition of propagate/generate logic blocks and AND/OR gates for Cout bits generation, XOR gates for Sum bits generation
        for input_index in range(self.N):
            pg_block = PGLogicBlock(self.a.get_wire(input_index), self.b.get_wire(input_index), prefix=self.prefix+"_pg_logic"+str(input_index))
            self.propagate.append(pg_block.get_propagate_wire())
            self.generate.append(pg_block.get_generate_wire())
            self.add_component(pg_block)

            if input_index == 0:
                obj_sum_xor = XorGate(pg_block.get_sum_wire(), constant_wire_0.out.get_wire(), prefix=self.prefix+"_xor"+str(input_index))
                self.add_component(obj_sum_xor)
                self.out.connect(input_index, obj_sum_xor.out)

                # Carry propagation calculation
                obj_and = AndGate(self.propagate[input_index], self.generate[input_index], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)))
                self.add_component(obj_and)

                # Carry bit generation
                obj_cout_or = OrGate(pg_block.get_generate_wire(), self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)))
                self.add_component(obj_cout_or)
            else:
                obj_sum_xor = XorGate(pg_block.get_sum_wire(), self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(input_index))
                self.add_component(obj_sum_xor)
                self.out.connect(input_index, obj_sum_xor.out)

                # For each pg pair values algorithmically combine two input AND gates to replace multiple input gates (resolves fan-in issue)
                composite_and_gates = []
                # And combine AND gate pairs into OR gates
                composite_or_gates = []

                # Carry propagation calculation
                for g_index in range(len(self.generate)-1):
                    for p_index in range(g_index, len(self.propagate)):
                        # No gate to cascade with, add to list
                        if len(composite_and_gates) == 0:
                            obj_and = AndGate(self.propagate[p_index], self.generate[g_index], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)))
                        # Combine 2 gates into another one to cascade them
                        else:
                            # Create new AND gate
                            obj_and = AndGate(self.propagate[p_index], self.generate[g_index], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)))
                            self.add_component(obj_and)

                            # Combine new gate with previous one stored in list
                            obj_and = AndGate(self.get_previous_component(1).out, self.get_previous_component(2).out, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)))
                            composite_and_gates.pop(composite_and_gates.index(self.get_previous_component(2)))

                        # Add gate to circuit components and to list of composite AND gates for this pg pair value
                        self.add_component(obj_and)
                        composite_and_gates.append(obj_and)

                    composite_or_gates.append(composite_and_gates.pop())

                # Final OR gates cascade using generated AND gates representing multiple input AND gates (cascade of multiple two input ones)
                for a in range(len(composite_or_gates)-1):
                    obj_or = OrGate(self.get_previous_component().out, composite_or_gates[a].out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)))
                    self.add_component(obj_or)

                # Carry bit generation
                obj_cout_or = OrGate(pg_block.get_generate_wire(), self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)))
                self.add_component(obj_cout_or)

            # Connecting last output bit to last cout
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_cout_or.out)


class SignedCarryLookaheadAdder(UnsignedCarryLookaheadAdder, ArithmeticCircuit):
    """Class representing signed carry look-ahead adder.

    Signed carry look-ahead adder represents faster adder circuit which is composed
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
    def __init__(self, a: Bus, b: Bus, prefix: str = "s_cla"):
        super().__init__(a=a, b=b, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)))
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)))
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
