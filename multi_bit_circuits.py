from arithmetic_circuits import arithmetic_circuit, multiplier_circuit
from one_bit_circuits import half_adder, full_adder, constant_wire_value_0, constant_wire_value_1, full_adder_pg, pg_logic_block
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from wire_components import wire, bus

""" MULTI BIT CIRCUITS """


# ADDERS
class unsigned_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            # First adder is a half adder
            if input_index == 0:
                obj_adder = half_adder(self.a.get_wire(input_index), self.b.get_wire(input_index), prefix=self.prefix+"_ha")
            # Rest adders are full adders
            else:
                obj_adder = full_adder(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))
            
            self.add_component(obj_adder)
            self.out.connect(input_index, obj_adder.get_sum_wire())
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_adder.get_carry_wire())
    

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


class unsigned_pg_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_pg_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            if input_index == 0:
                # Constant wire with value 0 for cin 0
                constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
                self.add_component(constant_wire_0)
                obj_fa_cla = full_adder_pg(self.a.get_wire(input_index), self.b.get_wire(input_index), constant_wire_0.out.get_wire(), prefix=self.prefix+"_fa"+str(input_index))
            else:
                obj_fa_cla = full_adder_pg(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().out, prefix=self.prefix+"_fa"+str(input_index))
            
            self.add_component(obj_fa_cla)
            self.out.connect(input_index, obj_fa_cla.get_sum_wire())

            obj_and = and_gate(self.get_previous_component().c, self.get_previous_component().get_propagate_wire(), prefix=self.prefix+"_and"+str(input_index))
            obj_or = or_gate(obj_and.out, self.get_previous_component().get_generate_wire(), prefix=self.prefix+"_or"+str(input_index))
            self.add_component(obj_and)
            self.add_component(obj_or)
            
            # Connecting last output bit to last cout
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_or.out)


class signed_pg_ripple_carry_adder(unsigned_pg_ripple_carry_adder, arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_pg_rca"):
        super().__init__(a=a, b=b, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = xor_gate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_1)
        sign_xor_2 = xor_gate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)


class unsigned_carry_lookahead_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_cla"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Lists containing all propagate/generate wires
        self.propagate = []
        self.generate = []

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # Constant wire with value 0 for cin 0
        constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
        self.add_component(constant_wire_0)
        # Used as a first generate wire for obtaining next carry bits
        self.generate.append(constant_wire_0.out.get_wire())
        
        # Gradual addition of propagate/generate logic blocks and AND/OR gates for Cout bits generation, XOR gates for Sum bits generation
        for input_index in range(self.N):
            pg_block = pg_logic_block(self.a.get_wire(input_index), self.b.get_wire(input_index), prefix=self.prefix+"_pg_logic"+str(input_index))
            self.propagate.append(pg_block.get_propagate_wire())
            self.generate.append(pg_block.get_generate_wire())
            self.add_component(pg_block)

            if input_index == 0:
                obj_sum_xor = xor_gate(pg_block.get_sum_wire(), constant_wire_0.out.get_wire(), prefix=self.prefix+"_xor"+str(input_index))
                self.add_component(obj_sum_xor)
                self.out.connect(input_index, obj_sum_xor.out)

                # Carry propagation calculation
                obj_and = and_gate(self.propagate[input_index], self.generate[input_index], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=and_gate)))
                self.add_component(obj_and)

                # Carry bit generation
                obj_cout_or = or_gate(pg_block.get_generate_wire(), self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=or_gate)))
                self.add_component(obj_cout_or)
            else:
                obj_sum_xor = xor_gate(pg_block.get_sum_wire(), self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(input_index))
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
                            obj_and = and_gate(self.propagate[p_index], self.generate[g_index], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=and_gate)))
                        # Combine 2 gates into another one to cascade them
                        else:
                            # Create new AND gate
                            obj_and = and_gate(self.propagate[p_index], self.generate[g_index], prefix=self.prefix+"_and"+str(self.get_instance_num(cls=and_gate)))
                            self.add_component(obj_and)

                            # Combine new gate with previous one stored in list
                            obj_and = and_gate(self.get_previous_component(1).out, self.get_previous_component(2).out, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=and_gate)))
                            composite_and_gates.pop(composite_and_gates.index(self.get_previous_component(2)))

                        # Add gate to circuit components and to list of composite AND gates for this pg pair value
                        self.add_component(obj_and)
                        composite_and_gates.append(obj_and)

                    composite_or_gates.append(composite_and_gates.pop())
                
                # Final OR gates cascade using generated AND gates representing multiple input AND gates (cascade of multiple two input ones)
                for a in range(len(composite_or_gates)-1):
                    obj_or = or_gate(self.get_previous_component().out, composite_or_gates[a].out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=or_gate)))
                    self.add_component(obj_or)
                
                # Carry bit generation
                obj_cout_or = or_gate(pg_block.get_generate_wire(), self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=or_gate)))
                self.add_component(obj_cout_or)
            
            # Connecting last output bit to last cout
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_cout_or.out)
         

class signed_carry_lookahead_adder(unsigned_carry_lookahead_adder, arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_cla"):
        super().__init__(a=a, b=b, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = xor_gate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_1)
        sign_xor_2 = xor_gate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)


# MULTIPLIERS
class unsigned_array_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_arrmul"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

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
                        constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
                        self.add_component(constant_wire_0)

                        self.out.connect(a_multiplicand_index+1, constant_wire_0.out.get_wire())

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, obj_adder.get_carry_wire())


class signed_array_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_arrmul"):
        super().__init__()
        self.c_data_type = "int64_t"
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Generating wire with constant logic value 1
        constant_wire_1 = constant_wire_value_1(self.a.get_wire(), self.b.get_wire())
        self.add_component(constant_wire_1)

        # To adjust proper wire connection between adders and AND/NAND gates
        # we add offset equal to first block in circuits components list (used for generation of wire with constant value 1)
        components_offset = 1

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
                            previous_product = constant_wire_1.out.get_wire()

                        obj_adder = full_adder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        obj_nor = nor_gate(constant_wire_1.out.get_wire(), self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend")
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)

                elif b_multiplier_index == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        obj_xor = xor_gate(self.get_previous_component().get_carry_wire(), constant_wire_1.out.get_wire(), prefix=self.prefix+"_xor"+str(a_multiplicand_index+1)+"_"+str(b_multiplier_index))
                        self.add_component(obj_xor)

                        self.out.connect(self.out.N-1, obj_xor.out)


class unsigned_wallace_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_wallace_rca", unsigned_adder_class_name: str = unsigned_ripple_carry_adder):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Initialize all columns partial products forming AND gates matrix
        self.columns = self.init_column_heights()

        # Perform reduction until all columns have 2 or less bits in them
        while not all(height <= 2 for (height, *_) in self.columns):
            col = 0
            while col < len(self.columns):
                # If column has exactly 3 bits in height and all previous columns has maximum of 2 bits in height, combine them in a half adder
                if self.get_column_height(col) == 3 and all(height <= 2 for (height, *_) in self.columns[0:col-1]):
                    # Add half adder and also AND gates if neccesarry (via get_column_wire invocation) into list of circuit components
                    obj_adder = half_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                # If column has more than 3 bits in height, combine them in a full adder
                elif self.get_column_height(col) > 3:
                    # Add full adder and also AND gates if neccesarry (via get_column_wire invocation) into list of circuit components
                    obj_adder = full_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), self.get_column_wire(column=col, bit=3), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=full_adder)))
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
        self.out.connect(0, self.get_column_wire(column=0, bit=1))
        # Final addition of remaining bits
        # 1 bit multiplier case
        if self.N == 1:
            constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
            self.add_component(constant_wire_0)
            self.out.connect(1, constant_wire_0.out.get_wire())
        # 2 bit multiplier case
        elif self.N == 2:
            obj_ha = half_adder(self.get_column_wire(column=1, bit=1), self.get_column_wire(column=1, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_ha = half_adder(self.get_previous_component().get_carry_wire(), self.get_column_wire(column=2, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(2, obj_ha.get_sum_wire())
            self.out.connect(3, obj_ha.get_carry_wire())
        # Final addition of remaining bits using chosen unsigned multi bit adder
        else:
            adder_type = unsigned_adder_class_name(a=a, b=b)
            adder_a = bus(prefix=f"{adder_type.prefix}_a", wires_list=[self.get_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            adder_b = bus(prefix=f"{adder_type.prefix}_b", wires_list=[self.get_column_wire(column=col, bit=2) for col in range(1, len(self.columns))])
            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix+f"_{adder_type.prefix}")
            self.add_component(final_adder)

            [self.out.connect(o, final_adder.out.get_wire(o-1)) for o in range(1, len(self.out.bus))]


class signed_wallace_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_wallace_rca", unsigned_adder_class_name: str = unsigned_ripple_carry_adder):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Initialize all columns partial products forming AND/NAND gates matrix based on Baugh-Wooley multiplication
        self.columns = self.init_column_heights()

        # Generating wire with constant logic value 1 for signed multiplication
        # Based on Baugh-Wooley multiplication algorithm
        # Not used for 1 bit multiplier
        if self.N != 1:
            constant_wire_1 = constant_wire_value_1(self.a.get_wire(), self.b.get_wire())
            self.add_component(constant_wire_1)

            # Adding constant wire with value 1 to achieve signedness
            # (adding constant value bit to last column (with one bit) to combine them in XOR gate to get the correct final multplication output bit at the end)        
            self.columns[self.N].insert(1, constant_wire_1.out.get_wire())
            self.update_column_heights(curr_column=self.N, curr_height_change=1)

        # Perform reduction until all columns have 2 or less bits in them
        while not all(height <= 2 for (height, *_) in self.columns):
            col = 0
            while col < len(self.columns):
                # If column has exactly 3 bits in height and all previous columns has maximum of 2 bits in height, combine them in a half adder
                if self.get_column_height(col) == 3 and all(height <= 2 for (height, *_) in self.columns[0:col-1]):
                    # Add half adder and also AND/NAND gates if neccesarry (via get_column_wire invocation) into list of circuit components
                    obj_adder = half_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                # If column has more than 3 bits in height, combine them in a full adder
                elif self.get_column_height(col) > 3:
                    # Add full adder and also AND/NAND gates if neccesarry (via get_column_wire invocation) into list of circuit components
                    obj_adder = full_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), self.get_column_wire(column=col, bit=3), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=full_adder)))
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
        self.out.connect(0, self.get_column_wire(column=0, bit=1))
        # Final addition of remaining bits
        # 1 bit multiplier case
        if self.N == 1:
            constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
            self.add_component(constant_wire_0)
            self.out.connect(1, constant_wire_0.out.get_wire())
            return
        # 2 bit multiplier case
        elif self.N == 2:
            obj_ha = half_adder(self.get_column_wire(column=1, bit=1), self.get_column_wire(column=1, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_ha = half_adder(self.get_previous_component().get_carry_wire(), self.get_column_wire(column=2, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(2, obj_ha.get_sum_wire())
            self.out.connect(3, obj_ha.get_carry_wire())
        # Final addition of remaining bits using chosen unsigned multi bit adder
        else:
            adder_type = unsigned_adder_class_name(a=a, b=b)
            adder_a = bus(prefix=f"{adder_type.prefix}_a", wires_list=[self.get_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            adder_b = bus(prefix=f"{adder_type.prefix}_b", wires_list=[self.get_column_wire(column=col, bit=2) for col in range(1, len(self.columns))])
            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix+f"_{adder_type.prefix}")
            self.add_component(final_adder)

            [self.out.connect(o, final_adder.out.get_wire(o-1)) for o in range(1, len(self.out.bus))]

        # Final XOR to ensure proper sign extension
        obj_xor = xor_gate(constant_wire_1.out.get_wire(), self.out.get_wire(self.out.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(obj_xor)
        self.out.connect(self.out.N-1, obj_xor.out)

class unsigned_dadda_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_dadda_rca", unsigned_adder_class_name: str = unsigned_ripple_carry_adder):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Get starting stage and maximum possible column height
        self.stage, self.d = self.get_maximum_height(initial_value=min(self.a.N, self.b.N))
        # Initialize all columns partial products forming AND gates matrix
        self.columns = self.init_column_heights()

        # Perform reduction until stage 0
        for stage in range(self.stage, 0, -1):
            col = 0
            while col < len(self.columns):
                if self.get_column_height(col) == self.d + 1:
                    # Add half adder and also AND gates if neccesarry (via get_column_wire invocation) into list of circuit components
                    obj_adder = half_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))

                elif self.get_column_height(col) > self.d:
                    # Add full adder and also AND gates if neccesarry (via get_column_wire invocation) into list of circuit components
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
        # First output bit from single first pp AND gate
        self.out.connect(0, self.get_column_wire(column=0, bit=1))
        # Final addition of remaining bits
        # 1 bit multiplier case
        if self.N == 1:
            constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
            self.add_component(constant_wire_0)
            self.out.connect(1, constant_wire_0.out.get_wire())
        # 2 bit multiplier case
        elif self.N == 2:
            obj_ha = half_adder(self.get_column_wire(column=1, bit=1), self.get_column_wire(column=1, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_ha = half_adder(self.get_previous_component().get_carry_wire(), self.get_column_wire(column=2, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(2, obj_ha.get_sum_wire())
            self.out.connect(3, obj_ha.get_carry_wire())
        # Final addition of remaining bits using chosen unsigned multi bit adder
        else:
            adder_type = unsigned_adder_class_name(a=a, b=b)
            adder_a = bus(prefix=f"{adder_type.prefix}_a", wires_list=[self.get_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            adder_b = bus(prefix=f"{adder_type.prefix}_b", wires_list=[self.get_column_wire(column=col, bit=2) for col in range(1, len(self.columns))])
            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix+f"_{adder_type.prefix}")
            self.add_component(final_adder)

            [self.out.connect(o, final_adder.out.get_wire(o-1)) for o in range(1, len(self.out.bus))]


class signed_dadda_multiplier(multiplier_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_dadda_rca", unsigned_adder_class_name: str = unsigned_ripple_carry_adder):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = bus(prefix=a.prefix, wires_list=a.bus)
        self.b = bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for multiplication product
        self.out = bus("out", self.N*2)

        # Get starting stage and maximum possible column height
        self.stage, self.d = self.get_maximum_height(initial_value=min(self.a.N, self.b.N))
        # Initialize all columns partial products forming AND/NAND gates matrix based on Baugh-Wooley multiplication
        self.columns = self.init_column_heights()

        # Generating wire with constant logic value 1 for signed multiplication
        # Based on Baugh-Wooley multiplication algorithm
        # Not used for 1 bit multiplier
        if self.N != 1:
            constant_wire_1 = constant_wire_value_1(self.a.get_wire(), self.b.get_wire())
            self.add_component(constant_wire_1)

            # Adding constant wire with value 1 to achieve signedness
            # (adding constant value bit to last column (with one bit) to combine them in XOR gate to get the correct final multplication output bit at the end)        
            self.columns[self.N].insert(1, constant_wire_1.out.get_wire())
            self.update_column_heights(curr_column=self.N, curr_height_change=1)

        # Perform reduction until stage 0
        for stage in range(self.stage, 0, -1):
            col = 0
            while col < len(self.columns):
                if self.get_column_height(col) == self.d + 1:
                    # Add half adder and also AND/NAND gates if neccesarry (via get_column_wire invocation) into list of circuit components
                    obj_adder = half_adder(self.get_column_wire(column=col, bit=1), self.get_column_wire(column=col, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
                    self.add_component(obj_adder)

                    # Update the number of current and next column wires
                    self.update_column_heights(curr_column=col, curr_height_change=-1, next_column=col+1, next_height_change=1)

                    # Update current and next column wires arrangement
                    #   add ha's generated sum to the bottom of current column
                    #   add ha's generated cout to the top of next column
                    self.update_column_wires(curr_column=col, next_column=col+1, adder=self.get_previous_component(1))
                elif self.get_column_height(col) > self.d:
                    # Add full adder and also AND/NAND gates if neccesarry (via get_column_wire invocation) into list of circuit components
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
        # First output bit from single first pp AND gate
        self.out.connect(0, self.get_column_wire(column=0, bit=1))
        # Final addition of remaining bits
        # 1 bit multiplier case (no sign extension)
        if self.N == 1:
            constant_wire_0 = constant_wire_value_0(self.a.get_wire(), self.b.get_wire())
            self.add_component(constant_wire_0)
            self.out.connect(1, constant_wire_0.out.get_wire())
            return
        # 2 bit multiplier case
        elif self.N == 2:
            obj_ha = half_adder(self.get_column_wire(column=1, bit=1), self.get_column_wire(column=1, bit=2), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(1, obj_ha.get_sum_wire())

            obj_ha = half_adder(self.get_previous_component().get_carry_wire(), self.get_column_wire(column=2, bit=1), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=half_adder)))
            self.add_component(obj_ha)
            self.out.connect(2, obj_ha.get_sum_wire())
            self.out.connect(3, obj_ha.get_carry_wire())
        # Final addition of remaining bits using chosen unsigned multi bit adder
        else:
            adder_type = unsigned_adder_class_name(a=a, b=b)
            adder_a = bus(prefix=f"{adder_type.prefix}_a", wires_list=[self.get_column_wire(column=col, bit=1) for col in range(1, len(self.columns))])
            adder_b = bus(prefix=f"{adder_type.prefix}_b", wires_list=[self.get_column_wire(column=col, bit=2) for col in range(1, len(self.columns))])
            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix+f"_{adder_type.prefix}")
            self.add_component(final_adder)

            [self.out.connect(o, final_adder.out.get_wire(o-1)) for o in range(1, len(self.out.bus))]

        # Final XOR to ensure proper sign extension
        obj_xor = xor_gate(constant_wire_1.out.get_wire(), self.out.get_wire(self.out.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=xor_gate)))
        self.add_component(obj_xor)
        self.out.connect(self.out.N-1, obj_xor.out)
