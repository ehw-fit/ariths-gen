from ariths_gen.multi_bit_circuits.adders.carry_lookahead_adder import UnsignedCarryLookaheadAdder
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


class UnsignedWallaceMultiplier(MultiplierCircuit):
    """Class representing unsigned wallace multiplier.

    Unsigned wallace multiplier represents fast N-bit multiplier which utilizes
    the functionality of wallace tree reduction algorithm proposed by Chris Wallace.

    First partial products are calculated for each bit pair that form the partial product multiplication columns.
    At last the reduced pairs are inserted into chosen multi bit unsigned adder to execute their summation and obtain the final output bits.

    Wallace tree algorithm is described more in detail here:
    https://en.wikipedia.org/wiki/Wallace_tree

    It presents smaller circuit in area opposed to array multiplier but is slightly bigger then dadda because of less reduction stages.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned wallace multiplier. Defaults to "".
        name (str, optional): Name of unsigned wallace multiplier. Defaults to "u_wallace_cla".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used to obtain final sums of products. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_wallace_cla", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Initialize all columns partial products forming AND gates matrix
        self.columns = self.init_column_heights()

        # Perform reduction until all columns have 2 or less bits in them
        while not all(height <= 2 for (height, *_) in self.columns):
            col = 0
            while col < len(self.columns):
                # If column has exactly 3 bits in height and all previous columns has maximum of 2 bits in height, combine them in a half adder
                if self.get_column_height(col) == 3 and all(height <= 2 for (height, *_) in self.columns[0:col-1]):
                    # Add half adder and also AND gates if neccesarry (via add_column_wire invocation) into list of circuit components
                    obj_adder = HalfAdder(self.add_column_wire(column=col, bit=0), self.add_column_wire(column=col, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=HalfAdder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                # If column has more than 3 bits in height, combine them in a full adder
                elif self.get_column_height(col) > 3:
                    # Add full adder and also AND gates if neccesarry (via add_column_wire invocation) into list of circuit components
                    obj_adder = FullAdder(self.add_column_wire(column=col, bit=0), self.add_column_wire(column=col, bit=1), self.add_column_wire(column=col, bit=2), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-2, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add fa's generated sum to the bottom of current column
                    #   add fa's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))
                col += 1

        # Output generation
        # First output bit from single first pp AND gate
        self.out.connect(0, self.add_column_wire(column=0, bit=0))
        # Final addition of remaining bits
        # 1 bit multiplier case
        if self.N == 1:
            self.out.connect(1, ConstantWireValue0())
        # 2 bit multiplier case
        elif self.N == 2:
            obj_ha = HalfAdder(self.add_column_wire(column=1, bit=0), self.add_column_wire(column=1, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=HalfAdder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_ha = HalfAdder(self.get_previous_component().get_carry_wire(), self.add_column_wire(column=2, bit=0), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=HalfAdder)))
            self.add_component(obj_ha)
            self.out.connect(2, obj_ha.get_sum_wire())
            self.out.connect(3, obj_ha.get_carry_wire())
        # Final addition of remaining bits using chosen unsigned multi bit adder
        else:
            # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
            adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(len(self.columns)-1)
            adder_a = Bus(prefix=f"a", wires_list=[self.add_column_wire(column=col, bit=0) for col in range(1, len(self.columns))])
            adder_b = Bus(prefix=f"b", wires_list=[self.add_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
            self.add_component(final_adder)

            [self.out.connect(o, final_adder.out.get_wire(o-1), inserted_wire_desired_index=o-1) for o in range(1, len(self.out.bus))]


class SignedWallaceMultiplier(MultiplierCircuit):
    """Class representing signed wallace multiplier.

    Signed wallace multiplier represents fast N-bit multiplier which utilizes
    the functionality of wallace tree reduction algorithm proposed by Chris Wallace and uses Baugh-Wooley algorithm
    to perform signed multiplication.

    First partial products are calculated for each bit pair that form the partial product multiplication columns.
    At last the reduced pairs are inserted into chosen multi bit unsigned adder to execute their summation and obtain the final output bits,
    additional XOR gate serve the necessary sign extension.

    Wallace tree algorithm is described more in detail here:
    https://en.wikipedia.org/wiki/Wallace_tree

    It presents smaller circuit in area opposed to array multiplier but is slightly bigger then dadda because of less reduction stages.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed wallace multiplier. Defaults to "".
        name (str, optional): Name of signed wallace multiplier. Defaults to "s_wallace_cla".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used to obtain final sums of products. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_wallace_cla", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, signed=True, **kwargs)
        self.c_data_type = "int64_t"

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Initialize all columns partial products forming AND/NAND gates matrix based on Baugh-Wooley multiplication
        self.columns = self.init_column_heights()

        # Not used for 1 bit multiplier
        if self.N != 1:
            # Adding constant wire with value 1 to achieve signedness based on Baugh-Wooley multiplication algorithm
            # (adding constant value bit to last column (with one bit) to combine them in XOR gate to get the correct final multplication output bit at the end)
            self.columns[self.N].insert(1, ConstantWireValue1())
            self.update_column_heights(curr_column=self.N, curr_height_change=1)

        # Perform reduction until all columns have 2 or less bits in them
        while not all(height <= 2 for (height, *_) in self.columns):
            col = 0
            while col < len(self.columns):
                # If column has exactly 3 bits in height and all previous columns has maximum of 2 bits in height, combine them in a half adder
                if self.get_column_height(col) == 3 and all(height <= 2 for (height, *_) in self.columns[0:col-1]):
                    # Add half adder and also AND/NAND gates if neccesarry (via add_column_wire invocation) into list of circuit components
                    obj_adder = HalfAdder(self.add_column_wire(column=col, bit=0), self.add_column_wire(column=col, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=HalfAdder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                # If column has more than 3 bits in height, combine them in a full adder
                elif self.get_column_height(col) > 3:
                    # Add full adder and also AND/NAND gates if neccesarry (via add_column_wire invocation) into list of circuit components
                    obj_adder = FullAdder(self.add_column_wire(column=col, bit=0), self.add_column_wire(column=col, bit=1), self.add_column_wire(column=col, bit=2), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-2, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add fa's generated sum to the bottom of current column
                    #   add fa's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))
                col += 1

        # Output generation
        # First output bit from single first pp AND gate
        self.out.connect(0, self.add_column_wire(column=0, bit=0))
        # Final addition of remaining bits
        # 1 bit multiplier case
        if self.N == 1:
            self.out.connect(1, ConstantWireValue0())
            return
        # 2 bit multiplier case
        elif self.N == 2:
            obj_ha = HalfAdder(self.add_column_wire(column=1, bit=0), self.add_column_wire(column=1, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=HalfAdder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_fa = FullAdder(self.get_previous_component().get_carry_wire(), self.add_column_wire(column=2, bit=0), self.add_column_wire(column=2, bit=1), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder)))
            self.add_component(obj_fa)
            self.out.connect(2, obj_fa.get_sum_wire())
            self.out.connect(3, obj_fa.get_carry_wire())

        # Final addition of remaining bits using chosen unsigned multi bit adder
        else:
            # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
            adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(len(self.columns)-1)
            adder_a = Bus(prefix=f"a", wires_list=[self.add_column_wire(column=col, bit=0) for col in range(1, len(self.columns))])
            adder_b = Bus(prefix=f"b", wires_list=[self.add_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
            self.add_component(final_adder)

            [self.out.connect(o, final_adder.out.get_wire(o-1), inserted_wire_desired_index=o-1) for o in range(1, len(self.out.bus))]

        # Final XOR to ensure proper sign extension
        obj_xor = XorGate(ConstantWireValue1(), self.out.get_wire(self.out.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(obj_xor)
        self.out.connect(self.out.N-1, obj_xor.out)
