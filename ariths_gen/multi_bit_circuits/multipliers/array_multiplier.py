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


class UnsignedArrayMultiplier(MultiplierCircuit):
    """Class representing unsigned array multiplier.

    Unsigned array multiplier represents N-bit multiplier composed of
    many AND gates and half/full adders to calculate partial products and
    gradually sum them.

    Downside is its rather big area because it is composed of many logic gates.

    ```
                                       A3B0     A2B0     A1B0     A0B0
                                       │ │      │ │      │ │      │ │
                                      ┌▼─▼┐    ┌▼─▼┐    ┌▼─▼┐    ┌▼─▼┐
                                      │AND│    │AND│    │AND│    │AND│
                                      └┬──┘    └┬──┘    └┬──┘    └─┬─┘
                                 A3B1  │  A2B1  │ A1B1   │  A0B1   │
                                ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │
                                │AND│  │ │AND│  │ │AND│  │ │AND│   │
                                └┬──┘  │ └┬──┘  │ └┬──┘  │ └┬──┘   │
                                 │     │  │     │  │     │  │      │
                             ┌───▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │
                             │    │   │    │   │    │   │    │     │
                     ┌───────┤ HA │◄──┤ FA │◄──┤ FA │◄──┤ HA │     │
                     │       │    │   │    │   │    │   │    │     │
                     │       └┬───┘   └┬───┘   └┬───┘   └─┬──┘     │
                     │  A3B2  │  A2B2  │  A1B2  │  A0B2   │        │
                     │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │        │
                     │ │AND│  │ │AND│  │ │AND│  │ │AND│   │        │
                     │ └┬──┘  │ └┬──┘  │ └┬──┘  │ └┬──┘   │        │
                     │  │     │  │     │  │     │  │      │        │
                    ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │        │
                    │    │   │    │   │    │   │    │     │        │
            ┌───────┤ FA │◄──┤ FA │◄──┤ FA │◄──┤ HA │     │        │
            │       │    │   │    │   │    │   │    │     │        │
            │       └┬───┘   └┬───┘   └┬───┘   └─┬──┘     │        │
            │  A3B3  │  A2B3  │  A1B3  │  A0B3   │        │        │
            │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │        │        │
            │ │AND│  │ │AND│  │ │AND│  │ │AND│   │        │        │
            │ └┬──┘  │ └┬──┘  │ └┬──┘  │ └┬──┘   │        │        │
            │  │     │  │     │  │     │  │      │        │        │
           ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │        │        │
           │    │   │    │   │    │   │    │     │        │        │
    ┌──────┤ FA │◄──┤ FA │◄──┤ FA │◄──┤ HA │     │        │        │
    │      │    │   │    │   │    │   │    │     │        │        │
    │      └─┬──┘   └─┬──┘   └─┬──┘   └─┬──┘     │        │        │
    │        │        │        │        │        │        │        │
    ▼        ▼        ▼        ▼        ▼        ▼        ▼        ▼
    P7       P6       P5       P4       P3       P2       P1       P0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned array multiplier. Defaults to "u_arrmul".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "u_arrmul"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = Bus(prefix=a.prefix, wires_list=a.bus)
        self.b = Bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = Bus(self.prefix+"_out", self.N*2)

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if b_multiplier_index != 0:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index].out if b_multiplier_index == 1 else self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index)
                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # HA generation, last 1-bit adder in second row
                    elif a_multiplicand_index == self.N-1 and b_multiplier_index == 1:
                        obj_adder = HalfAdder(self.get_previous_component().out, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                    # FA generation
                    else:
                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        self.out.connect(a_multiplicand_index+1, ConstantWireValue0)

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, obj_adder.get_carry_wire())


class SignedArrayMultiplier(MultiplierCircuit):
    """Class representing signed array multiplier.

    Signed array multiplier represents N-bit multiplier composed of
    many AND/NAND gates and half/full adders to calculate partial products and
    gradually sum them.

    Downside is its rather big area because it is composed of many logic gates.

    ```
                                         A3B0     A2B0     A1B0     A0B0
                                         │ │      │ │      │ │      │ │
                                        ┌▼─▼─┐   ┌▼─▼┐    ┌▼─▼┐    ┌▼─▼┐
                                        │NAND│   │AND│    │AND│    │AND│
                                        └┬───┘   └┬──┘    └┬──┘    └─┬─┘
                                   A3B1  │  A2B1  │ A1B1   │  A0B1   │
                                  ┌▼─▼─┐ │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │
                                  │NAND│ │ │AND│  │ │AND│  │ │AND│   │
                                1 └┬───┘ │ └┬──┘  │ └┬──┘  │ └┬──┘   │
                                │  │     │  │     │  │     │  │      │
                               ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │
                               │    │   │    │   │    │   │    │     │
                       ┌───────┤ FA │◄──┤ FA │◄──┤ FA │◄──┤ HA │     │
                       │       │    │   │    │   │    │   │    │     │
                       │       └┬───┘   └┬───┘   └┬───┘   └─┬──┘     │
                       │  A3B2  │  A2B2  │  A1B2  │  A0B2   │        │
                       │ ┌▼─▼─┐ │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │        │
                       │ │NAND│ │ │AND│  │ │AND│  │ │AND│   │        │
                       │ └┬───┘ │ └┬──┘  │ └┬──┘  │ └┬──┘   │        │
                       │  │     │  │     │  │     │  │      │        │
                      ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │        │
                      │    │   │    │   │    │   │    │     │        │
              ┌───────┤ FA │◄──┤ FA │◄──┤ FA │◄──┤ HA │     │        │
              │       │    │   │    │   │    │   │    │     │        │
              │       └┬───┘   └┬───┘   └┬───┘   └─┬──┘     │        │
              │  A3B3  │  A2B3  │  A1B3  │  A0B3   │        │        │
              │ ┌▼─▼┐  │ ┌▼─▼─┐ │ ┌▼─▼─┐ │ ┌▼─▼─┐  │        │        │
              │ │AND│  │ │NAND│ │ │NAND│ │ │NAND│  │        │        │
      1       │ └┬──┘  │ └┬───┘ │ └┬───┘ │ └┬───┘  │        │        │
      │       │  │     │  │     │  │     │  │      │        │        │
    ┌─▼──┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │        │        │
    │    │   │    │   │    │   │    │   │    │     │        │        │
    │XOR │◄──┤ FA │◄──┤ FA │◄──┤ FA │◄──┤ HA │     │        │        │
    │    │   │    │   │    │   │    │   │    │     │        │        │
    └─┬──┘   └─┬──┘   └─┬──┘   └─┬──┘   └─┬──┘     │        │        │
      │        │        │        │        │        │        │        │
      ▼        ▼        ▼        ▼        ▼        ▼        ▼        ▼
      P7       P6       P5       P4       P3       P2       P1       P0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed array multiplier. Defaults to "s_arrmul".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "s_arrmul"):
        super().__init__()
        self.c_data_type = "int64_t"
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = Bus(prefix=a.prefix, wires_list=a.bus)
        self.b = Bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = Bus(self.prefix+"_out", self.N*2)

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND and NAND gates generation for calculation of partial products and sign extension
                if (b_multiplier_index == self.N-1 and a_multiplicand_index != self.N-1) or (b_multiplier_index != self.N-1 and a_multiplicand_index == self.N-1):
                    obj_nand = NandGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_nand"+str(a_multiplicand_index)+"_"+str(b_multiplier_index), parent_component=self)
                    self.add_component(obj_nand)
                else:
                    obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index), parent_component=self)
                    self.add_component(obj_and)

                if b_multiplier_index != 0:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index].out if b_multiplier_index == 1 else self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index)
                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # FA generation
                    else:
                        # Constant wire with value 1 used at the last FA in second row (as one of its inputs) for signed multiplication (based on Baugh Wooley algorithm)
                        if a_multiplicand_index == self.N-1 and b_multiplier_index == 1:
                            previous_product = ConstantWireValue1()

                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        obj_nor = NorGate(ConstantWireValue1(), self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend", parent_component=self)
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        obj_xor = XorGate(self.get_previous_component().get_carry_wire(), ConstantWireValue1(), prefix=self.prefix+"_xor"+str(a_multiplicand_index+1)+"_"+str(b_multiplier_index), parent_component=self)
                        self.add_component(obj_xor)

                        self.out.connect(self.out.N-1, obj_xor.out)
