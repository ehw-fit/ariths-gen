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
from ariths_gen.multi_bit_circuits.multipliers import(
    UnsignedArrayMultiplier,
    SignedArrayMultiplier
)


class UnsignedTruncatedMultiplier(MultiplierCircuit):
    """Class representing unsigned truncated multiplier.

    TODO
    Unsigned truncated multiplier represents N-bit multiplier composed of
    many AND gates and half/full adders to calculate partial products and
    gradually sum them.

    Downside is its rather big area because it is composed of many logic gates.
    TODO
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
        horizontal_break (int, optional): Specifies horizontal break used in truncated multiplier circuit creation. Defaults to 0.
        vertical_break (int, optional): Specifies vertical break used in truncated multiplier circuit creation. Defaults to 0.
        prefix (str, optional): Prefix name of unsigned truncated multiplier. Defaults to "".
        name (str, optional): Name of unsigned truncated multiplier. Defaults to "u_tm".
    """
    def __init__(self, a: Bus, b: Bus, horizontal_break: int = 0, vertical_break: int = 0, prefix: str = "", name: str = "u_tm", **kwargs):
        # NOTE: If horizontal/vertical break is specified as 0 the final circuit is a simple array multiplier
        self.horizontal_break = horizontal_break
        self.vertical_break = vertical_break
        
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        break_offsets = horizontal_break + vertical_break
        # Gradual generation of partial products
        for b_multiplier_index in range(self.horizontal_break, self.N):
            for a_multiplicand_index in range(self.vertical_break, self.N):
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if b_multiplier_index != self.horizontal_break and self.vertical_break != self.N-1:
                    if b_multiplier_index == self.horizontal_break + 1:
                        previous_product = self.components[a_multiplicand_index + b_multiplier_index - break_offsets].out
                    else:
                        previous_product = self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, horizontal_break=horizontal_break, vertical_break=vertical_break)

                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == self.vertical_break:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index + self.vertical_break, obj_adder.get_sum_wire())

                    # HA generation, last 1-bit adder in second row
                    elif a_multiplicand_index == self.N-1 and b_multiplier_index == self.horizontal_break+1:
                        obj_adder = HalfAdder(self.get_previous_component().out, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                    # FA generation
                    else:
                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if (a_multiplicand_index == self.vertical_break and b_multiplier_index == self.horizontal_break) or (self.horizontal_break == self.N-1 or self.vertical_break == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)
                    
                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        self.out.connect(a_multiplicand_index+b_multiplier_index+1, ConstantWireValue0())

                elif b_multiplier_index == self.N-1 and self.horizontal_break != self.N-1 and self.vertical_break != self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, obj_adder.get_carry_wire())

        # Connecting the output bits generated from ommited cells to ground
        if self.horizontal_break >= self.N or self.vertical_break >= self.N:
            [self.out.connect(out_id, ConstantWireValue0()) for out_id in range(self.out.N)]
        else:
            for grounded_out_index in range(0, break_offsets):
                self.out.connect(grounded_out_index, ConstantWireValue0())

class SignedTruncatedMultiplier(MultiplierCircuit):
    """Class representing signed truncated multiplier.

    TODO
    Signed array multiplier represents N-bit multiplier composed of
    many AND/NAND gates and half/full adders to calculate partial products and
    gradually sum them.

    Downside is its rather big area because it is composed of many logic gates.
    TODO
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
        horizontal_break (int, optional): Specifies horizontal break used in signed truncated multiplier circuit creation. Defaults to 0.
        vertical_break (int, optional): Specifies vertical break used in signed truncated multiplier circuit creation. Defaults to 0.
        prefix (str, optional): Prefix name of signed truncated multiplier. Defaults to "".
        name (str, optional): Name of signed truncated multiplier. Defaults to "s_tm".
    """
    def __init__(self, a: Bus, b: Bus, horizontal_break: int = 0, vertical_break: int = 0, prefix: str = "", name: str = "s_tm", **kwargs):
        # NOTE: If horizontal/vertical break is specified as 0 the final circuit is a simple array multiplier
        self.horizontal_break = horizontal_break
        self.vertical_break = vertical_break

        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, signed=True, **kwargs)
        self.c_data_type = "int64_t"
        
        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        break_offsets = horizontal_break + vertical_break
        # Gradual generation of partial products
        for b_multiplier_index in range(self.horizontal_break, self.N):
            for a_multiplicand_index in range(self.vertical_break, self.N):
                # AND and NAND gates generation for calculation of partial products and sign extension
                if (b_multiplier_index == self.N-1 and a_multiplicand_index != self.N-1) or (b_multiplier_index != self.N-1 and a_multiplicand_index == self.N-1):
                    obj_nand = NandGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_nand"+str(a_multiplicand_index)+"_"+str(b_multiplier_index), parent_component=self)
                    self.add_component(obj_nand)
                else:
                    obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index), parent_component=self)
                    self.add_component(obj_and)

                if b_multiplier_index != self.horizontal_break and self.vertical_break != self.N-1:
                    if b_multiplier_index == self.horizontal_break + 1:
                        previous_product = self.components[a_multiplicand_index + b_multiplier_index - break_offsets].out
                    else:
                        previous_product = self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, horizontal_break=horizontal_break, vertical_break=vertical_break)

                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == self.vertical_break:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # FA generation
                    else:
                        # Constant wire with value 1 used at the last FA in second row (as one of its inputs) for signed multiplication (based on Baugh Wooley algorithm)
                        if a_multiplicand_index == self.N-1 and b_multiplier_index == self.horizontal_break+1:
                            previous_product = ConstantWireValue1()

                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if (a_multiplicand_index == self.vertical_break and b_multiplier_index == self.horizontal_break) or (self.horizontal_break == self.N-1 or self.vertical_break == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        obj_nor = NorGate(ConstantWireValue1(), self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend", parent_component=self)
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)

                elif b_multiplier_index == self.N-1 and self.horizontal_break != self.N-1 and self.vertical_break != self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        obj_xor = XorGate(self.get_previous_component().get_carry_wire(), ConstantWireValue1(), prefix=self.prefix+"_xor"+str(a_multiplicand_index+1)+"_"+str(b_multiplier_index), parent_component=self)
                        self.add_component(obj_xor)

                        self.out.connect(self.out.N-1, obj_xor.out)
        
        # Connecting the output bits generated from ommited cells to ground
        if self.horizontal_break >= self.N or self.vertical_break >= self.N:
            [self.out.connect(out_id, ConstantWireValue0()) for out_id in range(self.out.N)]
        else:
            for grounded_out_index in range(0, break_offsets):
                self.out.connect(grounded_out_index, ConstantWireValue0())
