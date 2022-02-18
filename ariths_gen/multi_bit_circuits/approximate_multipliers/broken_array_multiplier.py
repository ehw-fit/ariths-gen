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


class UnsignedBrokenArrayMultiplier(MultiplierCircuit):
    """Class representing unsigned broken array multiplier.

    It represents an approximative version of unsigned array multiplier with simpler structure.
    It is created by modifying an ordinary N-bit unsigned array multiplier by omitting partial product
    stage cells by the specified horizontal and vertical cut levels.

    The design promises better area and power parameters in exchange for the loss of computation precision.
    The BAM design allows to save more partial product stage adders than truncated multiplier.
    ```
                            VERTICAL CUT=4

                                │
                                            A3B0       A2B0       A1B0       A0B0
                                │          ┌───┐      ┌───┐      ┌───┐      ┌───┐
                                           │AND│      │AND│      │AND│      │AND│
                                │          └───┘      └───┘      └───┘      └───┘
                                 
                                │
                                      A3B1       A2B1       A1B1       A0B1
                                │    ┌───┐      ┌───┐      ┌───┐      ┌───┐
                                     │AND│      │AND│      │AND│      │AND│
                                │    └───┘      └───┘      └───┘      └───┘
                                 
                                │ ┌────┐     ┌────┐     ┌────┐     ┌────┐
                                  │    │     │    │     │    │     │    │
                                │ │ HA │     │ FA │     │ FA │     │ HA │
                                  │    │     │    │     │    │     │    │
                                │ └────┘     └────┘     └────┘     └────┘
                                 
              ─ ─ ─ ─ ─ ─ ─ ─ ─ ┼ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ HORIZONTAL CUT=2
                       A3B2           A2B2       A1B2       A0B2
                      ┌▼─▼┐     │    ┌───┐      ┌───┐      ┌───┐
                      │AND│          │AND│      │AND│      │AND│
                      └┬──┘     │    └───┘      └───┘      └───┘
                       │         
                       │        │ ┌────┐     ┌────┐     ┌────┐
                       │          │    │     │    │     │    │
                       │        │ │ FA │     │ FA │     │ HA │
                       │          │    │     │    │     │    │
                       │        │ └────┘     └────┘     └────┘
            A3B3       │  A2B3       A1B3      A0B3
           ┌▼─▼┐       │ ┌▼─▼┐  │   ┌───┐     ┌───┐
           │AND│       │ │AND│      │AND│     │AND│
           └┬──┘       │ └┬──┘  │   └───┘     └───┘
            │          │  │      
           ┌▼───┐     ┌▼──▼┐    │ ┌────┐    ┌────┐
           │    │     │    │      │    │    │    │
    ┌──────┤ HA │◄────┤ HA │    │ │ FA │    │ HA │ 
    │      │    │     │    │      │    │    │    │
    │      └──┬─┘     └──┬─┘    │ └────┘    └────┘
    │         │          │       
    │         │          │      │
    ▼         ▼          ▼          ▼           ▼          ▼          ▼          ▼
    P7        P6         P5     │   P4=0        P3=0       P2=0       P1=0       P0=0
    ```
    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        horizontal_cut (int, optional): Specifies horizontal cut used in broken array multiplier circuit creation. Defaults to 0.
        vertical_cut (int, optional): Specifies vertical cut used in broken array multiplier circuit creation. Defaults to 0.
        prefix (str, optional): Prefix name of unsigned broken array multiplier. Defaults to "".
        name (str, optional): Name of unsigned broken array multiplier. Defaults to "u_bam".
    """
    def __init__(self, a: Bus, b: Bus, horizontal_cut: int = 0, vertical_cut: int = 0, prefix: str = "", name: str = "u_bam", **kwargs):
        # NOTE: If horizontal/vertical cut is specified as 0 the final circuit is a simple array multiplier
        self.horizontal_cut = horizontal_cut
        self.vertical_cut = vertical_cut
        
        self.N = max(a.N, b.N)
        # Horizontal cut level should be: 0 <= horizontal_cut < N
        # Vertical cut level should be: horizontal_cut <= vertical_cut < 2*N
        assert horizontal_cut < self.N
        assert vertical_cut < 2*self.N
        
        # Vertical cut should be greater or equal to horizontal cut
        assert vertical_cut >= horizontal_cut
        
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)
        
        self.ommited_rows = 0
        # Gradual generation of partial products
        for b_multiplier_index in range(self.horizontal_cut, self.N):
            # Number of elements that should be ommited in the current level based on vertical cut
            pp_row_elems_to_skip = self.vertical_cut - b_multiplier_index if self.vertical_cut - b_multiplier_index > 0 else 0
            # Number of pp pairs present in the current row 
            pp_row_elems = self.N-pp_row_elems_to_skip if self.N-pp_row_elems_to_skip > 0 else 0
            self.ommited_rows += 1 if pp_row_elems == 0 else 0
            
            for a_multiplicand_index in range((self.N-pp_row_elems), self.N): 
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if b_multiplier_index != self.horizontal_cut + self.ommited_rows:
                    if b_multiplier_index == self.horizontal_cut + self.ommited_rows + 1:
                        previous_product = self.components[a_multiplicand_index + b_multiplier_index - self.vertical_cut].out
                    else:
                        previous_product = self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, mult_type="bam")

                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0 or self.vertical_cut-b_multiplier_index == a_multiplicand_index:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # HA generation, last 1-bit adder in second row
                    elif a_multiplicand_index == self.N-1 and b_multiplier_index == self.horizontal_cut+self.ommited_rows+1:
                        obj_adder = HalfAdder(self.get_previous_component().out, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                    # FA generation
                    else:
                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if (a_multiplicand_index == 0 and b_multiplier_index == self.horizontal_cut) or (self.horizontal_cut + self.ommited_rows == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)
                    
                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        self.out.connect(a_multiplicand_index+b_multiplier_index+1, ConstantWireValue0())

                elif b_multiplier_index == self.N-1 and self.horizontal_cut != self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, obj_adder.get_carry_wire())

        # Connecting the output bits generated from ommited cells to ground
        if self.vertical_cut == 2*self.N-1:
            [self.out.connect(out_id, ConstantWireValue0()) for out_id in range(self.out.N)]
        else:
            for grounded_out_index in range(0, max(self.horizontal_cut, self.vertical_cut)):
                self.out.connect(grounded_out_index, ConstantWireValue0())

class SignedBrokenArrayMultiplier(MultiplierCircuit):
    """Class representing signed broken array multiplier.

    It represents an approximative version of signed array multiplier with simpler structure.
    It is created by modifying an ordinary N-bit unsigned array multiplier by omitting partial product
    stage cells by the specified horizontal and vertical cut levels.

    The design promises better area and power parameters in exchange for the loss of computation precision.
    The BAM design allows to save more partial product stage adders than truncated multiplier.
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
        horizontal_cut (int, optional): Specifies horizontal cut used in signed broken array multiplier circuit creation. Defaults to 0.
        vertical_cut (int, optional): Specifies vertical cut used in signed broken array multiplier circuit creation. Defaults to 0.
        prefix (str, optional): Prefix name of signed broken array multiplier. Defaults to "".
        name (str, optional): Name of signed broken array multiplier. Defaults to "s_bam".
    """
    def __init__(self, a: Bus, b: Bus, horizontal_cut: int = 0, vertical_cut: int = 0, prefix: str = "", name: str = "s_bam", **kwargs):
        # NOTE: If horizontal/vertical cut is specified as 0 the final circuit is a simple array multiplier
        self.horizontal_cut = horizontal_cut
        self.vertical_cut = vertical_cut

        self.N = max(a.N, b.N)
        # Horizontal cut level should be: 0 <= horizontal_cut < N
        # Vertical cut level should be: horizontal_cut <= vertical_cut < 2*N
        assert horizontal_cut < self.N
        assert vertical_cut < 2*self.N
        
        # Vertical cut should be greater or equal to horizontal cut
        assert vertical_cut >= horizontal_cut

        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, signed=True, **kwargs)
        
        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        self.ommited_rows = 0
        # Gradual generation of partial products
        for b_multiplier_index in range(self.horizontal_cut, self.N):
            # Number of elements that should be ommited in the current level based on vertical cut
            pp_row_elems_to_skip = self.vertical_cut - b_multiplier_index if self.vertical_cut - b_multiplier_index > 0 else 0
            # Number of pp pairs present in the current row 
            pp_row_elems = self.N-pp_row_elems_to_skip if self.N-pp_row_elems_to_skip > 0 else 0
            self.ommited_rows += 1 if pp_row_elems == 0 else 0

            for a_multiplicand_index in range(self.N-pp_row_elems, self.N):
                # AND and NAND gates generation for calculation of partial products and sign extension
                if (b_multiplier_index == self.N-1 and a_multiplicand_index != self.N-1) or (b_multiplier_index != self.N-1 and a_multiplicand_index == self.N-1):
                    obj_nand = NandGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_nand"+str(a_multiplicand_index)+"_"+str(b_multiplier_index), parent_component=self)
                    self.add_component(obj_nand)
                else:
                    obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index), parent_component=self)
                    self.add_component(obj_and)

                if b_multiplier_index != self.horizontal_cut + self.ommited_rows:
                    if b_multiplier_index == self.horizontal_cut + self.ommited_rows + 1:
                        previous_product = self.components[a_multiplicand_index + b_multiplier_index - self.vertical_cut].out
                    else:
                        previous_product = self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, mult_type="bam")

                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0 or self.vertical_cut-b_multiplier_index == a_multiplicand_index:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # FA generation
                    else:
                        # Constant wire with value 1 used at the last FA in second row (as one of its inputs) for signed multiplication (based on Baugh Wooley algorithm)
                        if a_multiplicand_index == self.N-1 and b_multiplier_index == self.horizontal_cut+self.ommited_rows+1:
                            previous_product = ConstantWireValue1()

                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if (a_multiplicand_index == 0 and b_multiplier_index == self.horizontal_cut) or (self.horizontal_cut + self.ommited_rows == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)
                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        obj_nor = NorGate(ConstantWireValue1(), self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend", parent_component=self)
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)

                elif b_multiplier_index == self.N-1 and self.horizontal_cut != self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        obj_xor = XorGate(self.get_previous_component().get_carry_wire(), ConstantWireValue1(), prefix=self.prefix+"_xor"+str(a_multiplicand_index+1)+"_"+str(b_multiplier_index), parent_component=self)
                        self.add_component(obj_xor)

                        self.out.connect(self.out.N-1, obj_xor.out)
        
        # Connecting the output bits generated from ommited cells to ground
        if self.vertical_cut == 2*self.N-1:
            [self.out.connect(out_id, ConstantWireValue0()) for out_id in range(self.out.N)]
        else:
            for grounded_out_index in range(0, max(self.horizontal_cut, self.vertical_cut)):
                self.out.connect(grounded_out_index, ConstantWireValue0())
