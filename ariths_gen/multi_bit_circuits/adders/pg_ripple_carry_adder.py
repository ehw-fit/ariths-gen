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


class UnsignedPGRippleCarryAdder(ArithmeticCircuit):
    """Class representing unsigned ripple carry adder with propagate/generate logic.

    Unsigned ripple carry adder with PG logic represents slightly different rca implementation
    of N-bit unsigned adder which is composed of N one bit full adders with P/G logic.

    ```
      B3 A3         B2 A2       B1 A1       B0 A0
      │  │          │  │        │  │        │  │
    ┌─▼──▼─┐      ┌─▼──▼─┐    ┌─▼──▼─┐    ┌─▼──▼─┐
    │  PG  │  C3  │  PG  │ C2 │  PG  │ C1 │  PG  │
    │  FA  │◄────┐│  FA  │◄──┐│  FA  │◄──┐│  FA  │◄──0
    │      │     ││      │   ││      │   ││      │
    └─┬──┬┬┘     │└─┬┬┬──┘   │└─┬┬┬──┘   │└─┬┬┬──┘
      │  ││G3P3S3│  │││G2P2S2│  │││G1P1S1│  │││G0P0S0
      │ ┌▼▼──────┴──▼▼▼──────┴──▼▼▼──────┴──▼▼▼──┐
      │ │          Group PG logic                │
      │ │                                        │
      │ └─┬───────┬──────────┬──────────┬────────┘
      │   │       │          │          │
    ┌─▼───▼───────▼──────────▼──────────▼────────┐
    │                Sum logic                   │
    │                                            │
    └┬────┬───────┬──────────┬──────────┬────────┘
     │    │       │          │          │
     ▼    ▼       ▼          ▼          ▼
    Cout  S3      S1         S0         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned P/G rca. Defaults to "".
        name (str, optional): Name of unsigned P/G rca. Defaults to "u_pg_rca".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_pg_rca", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            if input_index == 0:
                # First full adder with connected constant wire with value 0 as cin 0
                obj_pg_fa = FullAdderPG(self.a.get_wire(input_index), self.b.get_wire(input_index), ConstantWireValue0(), prefix=self.prefix+"_pg_fa"+str(input_index))
            else:
                obj_pg_fa = FullAdderPG(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().out, prefix=self.prefix+"_pg_fa"+str(input_index))

            self.add_component(obj_pg_fa)
            self.out.connect(input_index, obj_pg_fa.get_sum_wire())

            obj_and = AndGate(self.get_previous_component().c, self.get_previous_component().get_propagate_wire(), prefix=self.prefix+"_and"+str(input_index), parent_component=self)
            obj_or = OrGate(obj_and.out, self.get_previous_component().get_generate_wire(), prefix=self.prefix+"_or"+str(input_index), parent_component=self)
            self.add_component(obj_and)
            self.add_component(obj_or)

            # Connecting last output bit to last cout
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_or.out)


class SignedPGRippleCarryAdder(UnsignedPGRippleCarryAdder, ArithmeticCircuit):
    """Class representing signed ripple carry adder with propagate/generate logic.

    Signed ripple carry adder with PG logic represents slightly different rca implementation
    of N-bit signed adder which is composed of N one bit full adders with P/G logic.
    At last XOR gates are used to ensure proper sign extension.

    ```
      B3 A3         B2 A2       B1 A1       B0 A0
      │  │          │  │        │  │        │  │
    ┌─▼──▼─┐      ┌─▼──▼─┐    ┌─▼──▼─┐    ┌─▼──▼─┐
    │  PG  │  C3  │  PG  │ C2 │  PG  │ C1 │  PG  │
    │  FA  │◄────┐│  FA  │◄──┐│  FA  │◄──┐│  FA  │◄──0
    │      │     ││      │   ││      │   ││      │
    └─┬──┬┬┘     │└─┬┬┬──┘   │└─┬┬┬──┘   │└─┬┬┬──┘
      │  ││G3P3S3│  │││G2P2S2│  │││G1P1S1│  │││G0P0S0
      │ ┌▼▼──────┴──▼▼▼──────┴──▼▼▼──────┴──▼▼▼──┐
      │ │          Group PG logic                │
      │ │                                        │
      │ └─┬───────┬──────────┬──────────┬────────┘
      │   │       │          │          │
    ┌─▼───▼───────▼──────────▼──────────▼────────┐
    │                Sum logic                   │
    │           with sign extension              │
    └┬────┬───────┬──────────┬──────────┬────────┘
     │    │       │          │          │
     ▼    ▼       ▼          ▼          ▼
    Cout  S3      S1         S0         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed P/G rca. Defaults to "".
        name (str, optional): Name of signed P/G rca. Defaults to "s_pg_rca".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_pg_rca", **kwargs):
        super().__init__(a=a, b=b, prefix=prefix, name=name, signed=True, **kwargs)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
