from ariths_gen.wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    PGSumLogic
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    OrGate,
    XorGate
)


class UnsignedPGRippleCarryAdder(GeneralCircuit):
    """Class representing unsigned ripple carry adder with propagate/generate logic.

    Unsigned ripple carry adder with PG logic represents slightly different rca implementation
    of N-bit unsigned adder which is composed of N one bit three input P/G/Sum logic function blocks.

    Each of them generates the P/G signals and contains a XOR gate responsible
    for the creation of corresponding sum bit. Besides this the Group PG logic is composed
    of AND and OR gates (basically a GreyCell) for computing the prefixes.

    You can find more info in the book: CMOS VLSI Design

    ```
      B3 A3         B2 A2       B1 A1       B0 A0
      │  │          │  │        │  │        │  │
    ┌─▼──▼─┐      ┌─▼──▼─┐    ┌─▼──▼─┐    ┌─▼──▼─┐
    │  PG  │  C3  │  PG  │ C2 │  PG  │ C1 │  PG  │
    │  SUM │◄────┐│  SUM │◄──┐│  SUM │◄──┐│  SUM │◄──0
    │      │     ││      │   ││      │   ││      │
    └─┬──┬┬┘     │└─┬┬┬──┘   │└─┬┬┬──┘   │└─┬┬┬──┘
      │  ││G3P3S3│  │││G2P2S2│  │││G1P1S1│  │││G0P0S0
      │ ┌▼▼──────┴──▼▼▼──────┴──▼▼▼──────┴──▼▼▼──┐
      │ │          Group PG logic                │
      │ │                                        │
      │ └─┬───────┬──────────┬──────────┬────────┘
      │   │S3     │S2        │S1        │S0
    ┌─▼───▼───────▼──────────▼──────────▼────────┐
    │                Sum + Cout                  │
    │                  logic                     │
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
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            if input_index == 0:
                # First full adder with connected constant wire with value 0 as cin 0
                obj_pg_fa = PGSumLogic(self.a.get_wire(input_index), self.b.get_wire(input_index), ConstantWireValue0(), prefix=self.prefix+"_pg_sum"+str(input_index))
            else:
                obj_pg_fa = PGSumLogic(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().out, prefix=self.prefix+"_pg_sum"+str(input_index))

            self.add_component(obj_pg_fa)
            self.out.connect(input_index, obj_pg_fa.get_sum_wire())

            obj_and = AndGate(self.get_previous_component().c, self.get_previous_component().get_propagate_wire(), prefix=self.prefix+"_and"+str(input_index), parent_component=self)
            obj_or = OrGate(obj_and.out, self.get_previous_component().get_generate_wire(), prefix=self.prefix+"_or"+str(input_index), parent_component=self)
            self.add_component(obj_and)
            self.add_component(obj_or)

            # Connecting last output bit to last cout
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_or.out)


class SignedPGRippleCarryAdder(UnsignedPGRippleCarryAdder, GeneralCircuit):
    """Class representing signed ripple carry adder with propagate/generate logic.

    Signed ripple carry adder with PG logic represents slightly different rca implementation
    of N-bit signed adder which is composed of N one bit three input P/G/Sum logic function blocks.

    Each of them generates the P/G signals and contains a XOR gate responsible
    for the creation of corresponding sum bit. Besides this the Group PG logic is composed
    of AND and OR gates (basically a GreyCell) for computing the prefixes.

    At last XOR gates are used to ensure proper sign extension.

    You can find more info in the book: CMOS VLSI Design

    ```
      B3 A3         B2 A2       B1 A1       B0 A0
      │  │          │  │        │  │        │  │
    ┌─▼──▼─┐      ┌─▼──▼─┐    ┌─▼──▼─┐    ┌─▼──▼─┐
    │  PG  │  C3  │  PG  │ C2 │  PG  │ C1 │  PG  │
    │  SUM │◄────┐│  SUM │◄──┐│  SUM │◄──┐│  SUM │◄──0
    │      │     ││      │   ││      │   ││      │
    └─┬──┬┬┘     │└─┬┬┬──┘   │└─┬┬┬──┘   │└─┬┬┬──┘
      │  ││G3P3S3│  │││G2P2S2│  │││G1P1S1│  │││G0P0S0
      │ ┌▼▼──────┴──▼▼▼──────┴──▼▼▼──────┴──▼▼▼──┐
      │ │          Group PG logic                │
      │ │                                        │
      │ └─┬───────┬──────────┬──────────┬────────┘
      │   │S3     │S2        │S1        │S0
    ┌─▼───▼───────▼──────────▼──────────▼────────┐
    │            Sum + Cout logic                │
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

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
