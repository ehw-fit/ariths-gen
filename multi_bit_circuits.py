from itertools import combinations_with_replacement
from arithmetic_circuits import arithmetic_circuit, multiplier_circuit
from one_bit_circuits import half_adder, full_adder
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from wire_components import wire, bus

""" MULTI BIT CIRCUITS """


# ADDERS
class unsigned_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        if prefix == "u_rca" or prefix == "s_rca":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # TODO replace ha for fa???

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            # First one is a half adder
            if input_index == 0:
                obj_ha = half_adder(self.a.get_wire(input_index), self.b.get_wire(input_index), prefix=self.prefix+"_ha")
                self.add_component(obj_ha)
                self.out.connect(input_index, obj_ha.get_sum_wire())

                if input_index == (self.N-1):
                    self.out.connect(self.N, obj_ha.get_carry_wire())
            # Rest are full adders
            else:
                obj_fa = full_adder(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))
                self.add_component(obj_fa)
                self.out.connect(input_index, obj_fa.get_sum_wire())

                if input_index == (self.N-1):
                    self.out.connect(self.N, obj_fa.get_carry_wire())


class signed_ripple_carry_adder(unsigned_ripple_carry_adder, arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_rca"):
        super().__init__(a=a, b=b, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = xor_gate(self.get_previous_component(1).a, self.get_previous_component(1).b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_1)
        sign_xor_2 = xor_gate(sign_xor_1.out, self.get_previous_component(2).get_carry_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)


# TODO CHANGE!!! test, think about proper P/G gates generation
class unsigned_carry_lookahead_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_cla"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        if prefix == "u_cla" or prefix == "s_cla":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # Generating wire with constant logic value 0 (output of the nor gate), used as cin to first fa
        obj_xor = xor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xor_constant_wire")
        obj_xnor = xnor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xnor_constant_wire")
        obj_nor = nor_gate(obj_xor.out, obj_xnor.out, prefix=self.prefix+"_nor_constant_wire")
        obj_nor.out.name = "constant_wire"
        obj_nor.out.prefix = "constant_wire"

        self.add_component(obj_xor)
        self.add_component(obj_xnor)
        self.add_component(obj_nor)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            obj_fa = full_adder(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().out, prefix=self.prefix+"_fa"+str(input_index))
            self.add_component(obj_fa)
            self.out.connect(input_index, obj_fa.get_sum_wire())

            if input_index == (self.N-1):
                self.out.connect(self.N, obj_fa.get_carry_wire())
            else:
                obj_and = and_gate(self.get_previous_component().get_carry_wire(), self.get_previous_component().propagate.out, prefix=self.prefix+"_and"+str(input_index))
                obj_xor = xor_gate(obj_and.out, self.get_previous_component().generate.out, prefix=self.prefix+"_xor"+str(input_index))

                self.add_component(self.get_previous_component().propagate)
                self.add_component(self.get_previous_component(2).generate)
                self.add_component(obj_and)
                self.add_component(obj_xor)


# TODO CHANGE!!!
class signed_carry_lookahead_adder(unsigned_carry_lookahead_adder, arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_cla"):
        super().__init__(a=a, b=b, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = xor_gate(self.get_previous_component(1).a, self.get_previous_component(1).b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_1)
        sign_xor_2 = xor_gate(sign_xor_1.out, self.get_previous_component(2).get_carry_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)


# MULTIPLIERS
class unsigned_array_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_arr_mul"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        if prefix == "u_arr_mul":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND gates generation for calculation of partial products
                obj_and = and_gate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if b_multiplier_index != 0:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index].out if b_multiplier_index == 1 else self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index)
                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0:
                        obj_adder = half_adder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # HA generation, last 1-bit adder in second row
                    elif a_multiplicand_index == self.N-1 and b_multiplier_index == 1:
                        obj_adder = half_adder(self.get_previous_component().out, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                    # FA generation
                    else:
                        obj_adder = full_adder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        obj_xor = xor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xor_constant_wire")
                        obj_xnor = xnor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xnor_constant_wire")
                        obj_and = and_gate(obj_xor.out, obj_xnor.out, prefix=self.prefix+"_and_constant_wire")
                        obj_and.out.name = "constant_wire"
                        obj_and.out.prefix = "constant_wire"
                        self.add_component(obj_xor)
                        self.add_component(obj_xnor)
                        self.add_component(obj_and)

                        self.out.connect(a_multiplicand_index+1, obj_and.out)

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, obj_adder.get_carry_wire())


class signed_array_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_arr_mul"):
        super().__init__()
        self.c_data_type = "int64_t"
        self.N = max(a.N, b.N)
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        if prefix == "s_arr_mul":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Generating wire with constant logic value 1 (output of the or gate)
        obj_xor = xor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xor_constant_wire")
        obj_xnor = xnor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xnor_constant_wire")
        obj_or = or_gate(obj_xor.out, obj_xnor.out, prefix=self.prefix+"_or_constant_wire")
        obj_or.out.name = "constant_wire"
        obj_or.out.prefix = "constant_wire"

        self.add_component(obj_xor)
        self.add_component(obj_xnor)
        self.add_component(obj_or)

        # To adjust proper wire connection between adders and AND/NAND gates
        # we add offset equal to first 3 gates in circuits components list (that are present to prevent the need to use constant wire with logic value 1)
        components_offset = 3

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND and NAND gates generation for calculation of partial products and sign extension
                if (b_multiplier_index == self.N-1 and a_multiplicand_index != self.N-1) or (b_multiplier_index != self.N-1 and a_multiplicand_index == self.N-1):
                    obj_nand = nand_gate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_nand"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_nand)
                else:
                    obj_and = and_gate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_and)

                if b_multiplier_index != 0:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index + components_offset].out if b_multiplier_index == 1 else self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, offset=components_offset)
                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == 0:
                        obj_adder = half_adder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                    # FA generation
                    else:
                        if a_multiplicand_index == self.N-1 and b_multiplier_index == 1:
                            previous_product = obj_or.out

                        obj_adder = full_adder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        obj_nor = nor_gate(obj_or.out, self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend")
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        obj_xor = xor_gate(self.get_previous_component().get_carry_wire(), obj_or.out, prefix=self.prefix+"_xor"+str(a_multiplicand_index+1)+"_"+str(b_multiplier_index))
                        self.add_component(obj_xor)

                        self.out.connect(self.out.N-1, obj_xor.out)


class unsigned_dadda_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_dadda_mul"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        if prefix == "u_dadda_mul" or prefix == "s_dadda_mul":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Get starting stage and maximum possible column height
        self.stage, self.d = self.get_maximum_height(initial_value=min(self.a.N, self.b.N))
        self.columns = self.init_column_heights()

        # Perform reduction until stage 0
        for stage in range(self.stage, 0, -1):
            col = 0
            while col < len(self.columns):
                if self.get_column_height(col) == self.d + 1:
                    # Add half adder and also and gates if neccesarry (via get_column_wire invocation) into list of circuits components
                    obj_adder = half_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                elif self.get_column_height(col) > self.d:
                    # Add full adder and also and gates if neccesarry (via get_column_wire invocation) into list of circuits components
                    obj_adder = full_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), self.get_column_wire(column=col, bit=3), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=full_adder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-2, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add fa's generated sum to the bottom of current column
                    #   add fa's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                    # Next iteration with same column in case there is need for further reduction
                    col -= 1
                col += 1
            # Update maximum possible column height
            _, self.d = self.get_maximum_height(stage)

        # Output generation
        # Final addition of remaining bits using RCA # TODO add CLA
        self.out.connect(0, self.get_column_wire(column=0, bit=1))
        # 1 bit multiplier case
        if 1 == self.N:
            obj_xor = xor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xor_constant_wire")
            obj_xnor = xnor_gate(self.a.get_wire(), self.b.get_wire(), prefix=self.prefix+"_xnor_constant_wire")
            obj_and = and_gate(obj_xor.out, obj_xnor.out, prefix=self.prefix+"_and_constant_wire")
            obj_and.out.name = "constant_wire"
            obj_and.out.prefix = "constant_wire"
            self.add_component(obj_xor)
            self.add_component(obj_xnor)
            self.add_component(obj_and)

            self.out.connect(1, obj_and.out)
        # 2 bit multiplier case
        elif 2 == self.N:
            obj_ha = half_adder(self.get_column_wire(column=1, bit=1), self.get_column_wire(column=1, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_ha = half_adder(self.get_previous_component().get_carry_wire(), self.get_column_wire(column=2, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(2, obj_ha.get_sum_wire())
            self.out.connect(3, obj_ha.get_carry_wire())
        # Final addition of remaining bits using RCA # TODO add CLA
        else:
            rca_a = bus(prefix="rca_a", wires_list=[self.get_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            rca_b = bus(prefix="rca_b", wires_list=[self.get_column_wire(column=col, bit=2) for col in range(1, len(self.columns))])
            rca = unsigned_ripple_carry_adder(a=rca_a, b=rca_b, prefix=self.prefix+"_u_rca"+str(len(self.columns)-1))
            self.add_component(rca)

            [self.out.connect(o, rca.out.get_wire(o-1)) for o in range(1, len(self.out.bus))]

# TODO signed dadda_multiplier
