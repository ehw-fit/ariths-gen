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


class UnsignedArrayMultiplier(MultiplierCircuit):
    """Class representing unsigned array multiplier.

    Unsigned array multiplier represents N-bit multiplier composed of
    many AND gates and half/full adders to calculate partial products and
    gradually sum them.

    Downside is its rather big area because it is composed of many logic gates.

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
        self.out = Bus("out", self.N*2)

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
                        constant_wire_0 = ConstantWireValue0(self.a.get_wire(), self.b.get_wire())
                        self.add_component(constant_wire_0)

                        self.out.connect(a_multiplicand_index+1, constant_wire_0.out.get_wire())

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
        self.out = Bus("out", self.N*2)

        # Generating wire with constant logic value 1
        constant_wire_1 = ConstantWireValue1(self.a.get_wire(), self.b.get_wire())
        self.add_component(constant_wire_1)

        # To adjust proper wire connection between adders and AND/NAND gates
        # we add offset equal to first block in circuits components list (used for generation of wire with constant value 1)
        components_offset = 1

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND and NAND gates generation for calculation of partial products and sign extension
                if (b_multiplier_index == self.N-1 and a_multiplicand_index != self.N-1) or (b_multiplier_index != self.N-1 and a_multiplicand_index == self.N-1):
                    obj_nand = NandGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_nand"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_nand)
                else:
                    obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_and)

                if b_multiplier_index != 0:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index + components_offset].out if b_multiplier_index == 1 else self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, offset=components_offset)
                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # FA generation
                    else:
                        if a_multiplicand_index == self.N-1 and b_multiplier_index == 1:
                            previous_product = constant_wire_1.out.get_wire()

                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        obj_nor = NorGate(constant_wire_1.out.get_wire(), self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend")
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        obj_xor = XorGate(self.get_previous_component().get_carry_wire(), constant_wire_1.out.get_wire(), prefix=self.prefix+"_xor"+str(a_multiplicand_index+1)+"_"+str(b_multiplier_index))
                        self.add_component(obj_xor)

                        self.out.connect(self.out.N-1, obj_xor.out)
