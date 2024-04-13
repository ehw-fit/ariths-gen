from ariths_gen.wire_components import (
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    FullAdder
)
from ariths_gen.multi_bit_circuits.adders import (
    UnsignedCarryLookaheadAdder
)


class CarrySaveAdderComponent(GeneralCircuit):
    """Class representing carry save adder component.

    The carry save adder component is especially useful when constructing tree multiplier architectures to reduce the propagation delay as opposed to traditional implementation of tree multipliers with half/full adders.

    The circuit is composed of full adders that operate in parallel and each take 3 input operands.
    The final output bus is composed of sum and carry bits of its corresponding contained full adders.
    ```
          C3 B3 A3   C2 B2 A2   C1 B1 A1   C0 B0 A0
         │ │ │      │ │ │      │ │ │      │ │ │
        ┌▼─▼─▼─┐   ┌▼─▼─▼─┐   ┌▼─▼─▼─┐   ┌▼─▼─▼─┐
        │      │   │      │   │      │   │      │
        │  FA  │   │  FA  │   │  FA  │   │  FA  │
        │      │   │      │   │      │   │      │
        └─┬──┬─┘   └─┬──┬─┘   └─┬──┬─┘   └─┬──┬─┘
          │c3│s3     │c2│s2     │c1│s1     │c0│s0
          └──┼──┐  ┌─┘  │┌──────┼──┼───────┘  │
             │  │  │  ┌─┼┼──────┘  └───────┐  │
             │  │  │  │ └┼──────────────┐  │  │
             └──┼──┼──┼──┼───────────┐  │  │  │
                │  │  │  │  0     0/1│  │  │  │
                │  │  │  │  │     │  │  │  │  │
                o9 o8 o7 o6 o5    o4 o3 o2 o1 o0
                c3 c2 c1 c0 0    0/1 s3 s2 s1 s0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        c (Bus): Third input bus.
        prefix (str, optional): Prefix name of csa component. Defaults to "".
        name (str, optional): Name of csa component. Defaults to "csa_component".
        signed (bool, optional): Specifies whether the component should be used in (un)signed context (used during the construction of tree multipliers). Defaults to False.
    """
    def __init__(self, a: Bus, b: Bus, c: Bus, prefix: str = "", name: str = "csa_component", signed: bool = False, **kwargs):
        self.N = max(a.N, b.N, c.N)
        super().__init__(inputs=[a, b, c], prefix=prefix, name=name, out_N=(2*self.N)+2, signed=signed, **kwargs)
        self.out.signed = False  # CSA component has always unsigned output

        bus_extension_wire = ConstantWireValue1() if self.signed is True else ConstantWireValue0()
        self.a.bus_extend(N=self.N, prefix=a.prefix, desired_extension_wire=bus_extension_wire)
        self.b.bus_extend(N=self.N, prefix=b.prefix, desired_extension_wire=bus_extension_wire)
        self.c.bus_extend(N=self.N, prefix=c.prefix, desired_extension_wire=bus_extension_wire)

        self.sum_bits = Bus(prefix=self.prefix + "_sums", N=int(self.out.N/2))
        self.carry_bits = Bus(prefix=self.prefix + "_carries", N=int(self.out.N/2))
        self.sum_bits.connect(-1, bus_extension_wire)
        self.carry_bits.connect(0, ConstantWireValue0())

        # Gradual addition of 1-bit CSA components (FAs are used)
        for input_index in range(self.N):
            obj_adder = FullAdder(self.a.get_wire(input_index), self.b.get_wire(input_index), self.c.get_wire(input_index), prefix=self.prefix+"_fa"+str(input_index))
            self.add_component(obj_adder)

            self.sum_bits.connect(input_index, obj_adder.get_sum_wire())
            self.carry_bits.connect(input_index+1, obj_adder.get_carry_wire())

        [self.out.connect(o, self.sum_bits.get_wire(o)) for o in range(0, int(self.out.N/2))]
        [self.out.connect(o, self.carry_bits.get_wire(o-int(self.out.N/2))) for o in range(int(self.out.N/2), self.out.N)]


class UnsignedCarrySaveAdder(GeneralCircuit):
    """Class representing unsigned carry save adder.

    Unsigned carry save adder represents 3 input N-bit unsigned adder which is composed of
    N one bit full adders, that are not interconnected as in for example the ripple carry adder,
    but instead operate in parallel.

    The sum and carry bits of the individual full adders are connected to a multi bit adder to sum the final result.
    ```
       C3 B3 A3   C2 B2 A2   C1 B1 A1   C0 B0 A0
         │ │ │      │ │ │      │ │ │      │ │ │
        ┌▼─▼─▼─┐   ┌▼─▼─▼─┐   ┌▼─▼─▼─┐   ┌▼─▼─▼─┐
        │      │   │      │   │      │   │      │
        │  FA  │   │  FA  │   │  FA  │   │  FA  │
        │      │   │      │   │      │   │      │
        └─┬──┬─┘   └─┬──┬─┘   └─┬──┬─┘   └─┬──┬─┘
         ┌┘c3│s3┌────┘c2│s2┌────┘c1│s1┌────┘c0│s0
      0  │   │  │       │  │       │  │       │  0
      │Y4│X4 │Y3│X3     │Y2│X2     │Y1│X1     │Y0│X0
    ┌─▼──▼───▼──▼───────▼──▼───────▼──▼───────▼──▼─┐
    │            5-bit multi bit adder             │
    │                                              │
    └┬────────┬────────┬────────┬────────┬────────┬┘
    Cout     S4       S3       S2       S1       S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        c (Bus): Third input bus.
        prefix (str, optional): Prefix name of unsigned csa. Defaults to "".
        name (str, optional): Name of unsigned csa. Defaults to "u_csa".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used to obtain final sum. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, c: Bus, prefix: str = "", name: str = "u_csa", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N, c.N)
        super().__init__(inputs=[a, b, c], prefix=prefix, name=name, out_N=self.N+2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)
        self.c.bus_extend(N=self.N, prefix=c.prefix)

        csa_adder = CarrySaveAdderComponent(a=self.a, b=self.b, c=self.c, prefix=prefix, name="csa_comp" + str(self.N), inner_component=True)
        self.add_component(csa_adder)

        # Obtain proper adder name with its bit width
        adder_name = unsigned_adder_class_name(a=self.a, b=self.b).prefix + str(self.N+1)
        adder_a = Bus(prefix="a", N=csa_adder.sum_bits.N)
        adder_b = Bus(prefix="b", N=csa_adder.carry_bits.N)
        adder_a.connect_bus(connecting_bus=csa_adder.out, end_connection_pos=int(csa_adder.out.N/2))
        adder_b.connect_bus(connecting_bus=csa_adder.out, start_connection_pos=int(csa_adder.out.N/2), end_connection_pos=csa_adder.out.N, offset=int(csa_adder.out.N/2))
        final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
        self.add_component(final_adder)
        self.out.connect_bus(connecting_bus=final_adder.out)
