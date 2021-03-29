from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from wire_components import wire, bus
import math

""" ARITHMETIC CIRCUITS """


class arithmetic_circuit():
    def __init__(self):
        self.components = []
        self.circuit_wires = []
        self.inputs = []
        self.circuit_gates = []
        self.c_data_type = "uint64_t"
        self.N = 1

    def add_component(self, component):
        self.components.append(component)

    def get_previous_component(self, number: int = 1):
        return self.components[-number]

    def get_instance_num(self, cls):
        return sum(isinstance(c, cls) for c in self.components)

    def get_unique_one_bit_components(self):
        one_bit_comps = []
        for c in self.components:
            if isinstance(c, logic_gate):
                continue
            elif type(getattr(c, 'a')) == wire:
                one_bit_comps.append(c)
            else:
                one_bit_comps.extend(c.get_unique_one_bit_components())

        return one_bit_comps

    def get_unique_multi_bit_components(self):
        multi_bit_comps = []
        for c in self.components:
            if isinstance(c, logic_gate):
                continue
            elif type(getattr(c, 'a')) == wire:
                continue
            else:
                multi_bit_comps.append(c)
        return multi_bit_comps

    @staticmethod
    def get_unique_types(components: list):
        return list({type(c): c for c in components}.values())

    def get_component_types(self):
        gate_comps = self.get_unique_types(components=self.get_circuit_gates())
        one_bit_comps = self.get_unique_types(components=self.get_unique_one_bit_components())
        multi_bit_comps = self.get_unique_types(components=self.get_unique_multi_bit_components())

        all_components = gate_comps + one_bit_comps + multi_bit_comps
        return all_components

    def get_sum_wire(self):
        return self.out.get_wire(0)

    def get_carry_wire(self):
        return self.out.get_wire(1)

    def get_circuit_wires(self):
        self.circuit_wires = []
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if item[1] == component.out.name]:
                self.circuit_wires.append((component.out, component.out.name, len(self.circuit_wires)))

        # Get unique names of all inner input circuits (mainly used in one bit circuits)
        self.inputs = [i[0] for i in self.circuit_wires if i[0] not in [o.out for o in self.components]]

    # Search for circuit's wire unique index for cgp chromosome generation
    def get_circuit_wire_index(self, wire: wire):
        for w in self.circuit_wires:
            if wire.name.endswith(w[1]):
                return w[2]

    # Get list of all gates present in circuit
    def get_circuit_gates(self):
        gates = []
        for c in self.components:
            if isinstance(c, logic_gate):
                gates.append(c)
            else:
                gates.extend((c.get_circuit_gates()))
        return gates

    # Get list of all wires in circuit along with their index position for cgp chromosome generation
    def get_cgp_wires(self):
        self.circuit_wires = []
        if isinstance(self.a, bus):
            [self.circuit_wires.append((w, f"_{w.name}", len(self.circuit_wires))) for w in self.a.bus]
            [self.circuit_wires.append((w, f"_{w.name}", len(self.circuit_wires))) for w in self.b.bus]
        else:
            self.circuit_wires.append((self.a, f"_{self.a.name}", len(self.circuit_wires)))
            self.circuit_wires.append((self.b, f"_{self.b.name}", len(self.circuit_wires)))
            if hasattr(self, 'c'):
                self.circuit_wires.append((self.c, f"_{self.c.name}", len(self.circuit_wires)))

        for gate in self.circuit_gates:
            if not [item for item in self.circuit_wires if gate.a.name.endswith(item[1])]:
                self.circuit_wires.append((gate.a, gate.a.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if gate.b.name.endswith(item[1])]:
                self.circuit_wires.append((gate.b, gate.b.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if gate.out.name.endswith(item[1])]:
                self.circuit_wires.append((gate.out, gate.out.name, len(self.circuit_wires)))

    """ C CODE GENERATION """
    # FLAT C #
    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + "\n"

    def get_declarations_c_flat(self):
        return f"{self.a.get_wire_declaration_c()}" + \
               f"{self.b.get_wire_declaration_c()}" + \
               f"".join([c.get_declaration_c_flat() for c in self.components])

    # For multi-bit circuit wires declaration
    def get_declaration_c_flat(self):
        return f"".join([c.get_declaration_c_flat() for c in self.components])

    def get_inits_c_flat(self):
        return f"{self.a.get_wire_assign_c()}" + \
               f"{self.b.get_wire_assign_c()}" + \
               "".join([c.get_assign_c_flat() if isinstance(c, logic_gate) else c.get_init_c_flat() for c in self.components])

    # For multi-bit circuit wires initialization
    def get_init_c_flat(self):
        return "".join([c.get_assign_c_flat() if isinstance(c, logic_gate) else c.get_init_c_flat() for c in self.components])

    def get_function_out_c_flat(self):
        return "".join([f"  {self.out.prefix} |= {o.return_wire_value_c(offset=self.out.bus.index(o))};\n" for o in self.out.bus])

    # Generating flat C code representation of circuit
    def get_c_code_flat(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declarations_c_flat()+"\n")
        file_object.write(self.get_inits_c_flat()+"\n")
        file_object.write(self.get_function_out_c_flat())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_blocks_c(self):
        # Add unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_function_block_c(self):
        # Obtain proper adder name with its bit width
        adder_prefix = self.__class__(a=bus("a") , b=bus("b")).prefix + str(self.N)
        adder_block = self.__class__(a=bus(N=self.N, prefix="a"), b=bus(N=self.N, prefix="b"), prefix=adder_prefix)
        return f"{adder_block.get_circuit_c()}\n\n"

    def get_declaration_c_hier(self):
        return "".join(self.a.get_wire_declaration_c()) + \
               "".join(self.b.get_wire_declaration_c()) + \
               "".join([c.out.get_declaration_c() if isinstance(c, logic_gate) else c.get_wire_declaration_c_hier() for c in self.components])

    def get_wire_declaration_c_hier(self):
        return f"  {self.c_data_type} {self.prefix}_{self.a.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.prefix}_{self.b.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.prefix}_{self.out.prefix} = 0;\n" + \
               f"{self.out.get_wire_declaration_c()}"

    def get_init_c_hier(self):
        return f"{self.a.get_wire_assign_c()}" + \
               f"{self.b.get_wire_assign_c()}" + \
               "".join([f"  {c.out.name} = {c.get_gate_invocation_c()}" if isinstance(c, logic_gate) else c.get_out_invocation_c(circuit_prefix=self.prefix) for c in self.components])

    def get_out_invocation_c(self, circuit_prefix: str):
        # Getting name of circuit type and insitu copying out bus for proper C code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        out = bus(prefix=self.prefix+"_"+self.out.prefix, wires_list=self.out.bus)
        return "".join([f"  {self.prefix}_{self.a.prefix} |= {w.return_wire_value_c(offset=self.a.bus.index(w))};\n" for w in self.a.bus]) + \
               "".join([f"  {self.prefix}_{self.b.prefix} |= {w.return_wire_value_c(offset=self.b.bus.index(w))};\n" for w in self.b.bus]) + \
               f"  {out.prefix} = {circuit_type}({self.prefix}_{self.a.prefix}, {self.prefix}_{self.b.prefix});\n" + \
               f"{out.get_wire_assign_c()}"

    def get_function_out_c_hier(self):
        return "".join([f"  {self.out.prefix} |= {o.return_wire_value_c(offset=self.out.bus.index(o))};\n" for o in self.out.bus])

    def get_circuit_c(self):
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_declaration_c_hier()}\n" + \
               f"{self.get_init_c_hier()}\n" + \
               f"{self.get_function_out_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    # Generating hierarchical C code representation of circuit
    def get_c_code_hier(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_function_blocks_c())
        file_object.write(self.get_circuit_c())
        file_object.close()

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input [{self.N-1}:0] {self.a.prefix}, input [{self.N-1}:0] {self.b.prefix}, output [{self.out.N-1}:0] {self.out.prefix});\n"

    def get_declarations_v_flat(self):
        return f"{self.a.get_wire_declaration_v()}" + \
               f"{self.b.get_wire_declaration_v()}" + \
               f"".join([c.get_declaration_v_flat() for c in self.components])

    def get_declaration_v_flat(self):
        return f"".join([c.get_declaration_v_flat() for c in self.components])

    def get_inits_v_flat(self):
        return f"{self.a.get_wire_assign_v()}" + \
               f"{self.b.get_wire_assign_v()}" + \
               "".join([c.get_assign_v_flat() if isinstance(c, logic_gate) else c.get_init_v_flat() for c in self.components])

    def get_init_v_flat(self):
        return "".join([c.get_assign_v_flat() if isinstance(c, logic_gate) else c.get_init_v_flat() for c in self.components])

    def get_function_out_v_flat(self):
        return "".join([f"  assign {self.out.prefix}[{self.out.bus.index(o)}] = {o.prefix};\n" for o in self.out.bus])

    # Generating flat Verilog code representation of circuit
    def get_v_code_flat(self, file_object):
        file_object.write(self.get_prototype_v())
        file_object.write(self.get_declarations_v_flat()+"\n")
        file_object.write(self.get_inits_v_flat() + "\n")
        file_object.write(self.get_function_out_v_flat())
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    def get_function_blocks_v(self):
        # Add unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_v() for c in self.component_types])

    def get_function_block_v(self):
        # Obtain proper adder name with its bit width
        adder_prefix = self.__class__(a=bus("a") , b=bus("b")).prefix + str(self.N)
        adder_block = self.__class__(a=bus(N=self.N, prefix="a"), b=bus(N=self.N, prefix="b"), prefix=adder_prefix)
        return f"{adder_block.get_circuit_v()}\n\n"

    def get_declaration_v_hier(self):
        return "".join(self.a.get_wire_declaration_v()) + \
               "".join(self.b.get_wire_declaration_v()) + \
               "".join([c.out.get_declaration_v() if isinstance(c, logic_gate) else c.get_wire_declaration_v_hier() for c in self.components])

    def get_wire_declaration_v_hier(self):
        return f"  wire [{self.a.N-1}:0] {self.prefix}_{self.a.prefix};\n" + \
               f"  wire [{self.b.N-1}:0] {self.prefix}_{self.b.prefix};\n" + \
               f"  wire [{self.out.N-1}:0] {self.prefix}_{self.out.prefix};\n" + \
               f"{self.out.get_wire_declaration_v()}"

    def get_init_v_hier(self):
        return f"{self.a.get_wire_assign_v()}" + \
               f"{self.b.get_wire_assign_v()}" + \
               "".join([c.get_gate_invocation_v() if isinstance(c, logic_gate) else c.get_invocation_v(circuit_prefix=self.prefix) for c in self.components])

    def get_invocation_v(self, circuit_prefix: str):
        # Getting name of circuit type and insitu copying out bus for proper Verilog code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        out = bus(prefix=self.prefix+"_"+self.out.prefix, wires_list=self.out.bus)
        return "".join([f"  assign {self.prefix}_{self.a.prefix}[{self.a.bus.index(w)}] = {w.name};\n" for w in self.a.bus]) + \
               "".join([f"  assign {self.prefix}_{self.b.prefix}[{self.b.bus.index(w)}] = {w.name};\n" for w in self.b.bus]) + \
               f"  {circuit_type} {circuit_type}_{self.out.prefix}({self.prefix}_{self.a.prefix}, {self.prefix}_{self.b.prefix}, {out.prefix});\n" + \
               f"{out.get_wire_assign_v()}"

    def get_function_out_v_hier(self):
        return "".join([f"  assign {self.out.prefix}[{self.out.bus.index(o)}] = {o.name};\n" for o in self.out.bus])

    def get_circuit_v(self):
        return f"{self.get_prototype_v()}" + \
               f"{self.get_declaration_v_hier()}\n" + \
               f"{self.get_init_v_hier()}\n" + \
               f"{self.get_function_out_v_hier()}" + \
               f"endmodule"

    # Generating hierarchical Verilog code representation of circuit
    def get_v_code_hier(self, file_object):
        file_object.write(self.get_function_blocks_v())
        file_object.write(self.get_circuit_v())
        file_object.close()

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_prototype_blif(self):
        return f".model {self.prefix}\n"

    def get_declaration_blif(self):
        if self.N == 1:
            return f".inputs {self.a.prefix} {self.b.prefix}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f"{self.a.get_wire().get_assign_blif(name=self.a.prefix)}" + \
                   f"{self.b.get_wire().get_assign_blif(name=self.b.prefix)}"
        else:
            return f".inputs {self.a.get_wire_declaration_blif()}{self.b.get_wire_declaration_blif()}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f"{self.a.get_wire_assign_blif()}" + \
                   f"{self.b.get_wire_assign_blif()}"

    def get_function_blif_flat(self):
        return "".join(c.get_init_function_blif_flat() if isinstance(c, logic_gate) else c.get_function_blif_flat() for c in self.components)

    def get_function_out_blif(self):
        return f"{self.out.get_wire_assign_blif(output=True)}"

    # Generating flat BLIF code representation of circuit
    def get_blif_code_flat(self, file_object):
        file_object.write(self.get_prototype_blif())
        file_object.write(self.get_declaration_blif())
        file_object.write(self.get_function_blif_flat())
        file_object.write(self.get_function_out_blif())
        file_object.write(f".end\n")
        file_object.close()

    # HIERARCHICAL BLIF #
    def get_function_blif_hier(self):
        return "".join(c.get_invocation_blif_hier(init=True) if isinstance(c, logic_gate) else c.get_invocation_blif_hier(circuit_prefix=self.prefix) for c in self.components)

    def get_invocation_blif_hier(self, circuit_prefix: str):
        # Getting name of circuit type for proper Blif code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        return "".join([w.get_assign_blif(name=self.prefix+'_'+self.a.prefix+f'[{self.a.bus.index(w)}]', output=True)for w in self.a.bus]) + \
               "".join([w.get_assign_blif(name=self.prefix+'_'+self.b.prefix+f'[{self.b.bus.index(w)}]', output=True)for w in self.b.bus]) + \
               f".subckt {circuit_type}" + \
               "".join([f" a[{self.a.bus.index(w)}]={self.prefix}_{self.a.prefix}[{self.a.bus.index(w)}]" for w in self.a.bus]) + \
               "".join([f" b[{self.b.bus.index(w)}]={self.prefix}_{self.b.prefix}[{self.b.bus.index(w)}]" for w in self.b.bus]) + \
               "".join([f" out[{self.out.bus.index(o)}]={o.name}" for o in self.out.bus]) + "\n"

    def get_circuit_blif(self):
        return f"{self.get_prototype_blif()}" + \
               f"{self.get_declaration_blif()}" + \
               f"{self.get_function_blif_hier()}" + \
               f"{self.get_function_out_blif()}" + \
               f".end\n"

    def get_function_blocks_blif(self):
        # Add unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "\n".join([c.get_function_block_blif() for c in self.component_types[::-1]])

    def get_function_block_blif(self):
        # Obtain proper adder name with its bit width
        adder_prefix = self.__class__(a=bus("a") , b=bus("b")).prefix + str(self.N)
        adder_block = self.__class__(a=bus(N=self.N, prefix="a"), b=bus(N=self.N, prefix="b"), prefix=adder_prefix)
        return f"{adder_block.get_circuit_blif()}"

    # Generating hierarchical BLIF code representation of circuit
    def get_blif_code_hier(self, file_object):
        file_object.write(self.get_circuit_blif()+"\n")
        file_object.write(self.get_function_blocks_blif())
        file_object.close()

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{{self.a.N+self.a.N},{self.out.N},1,{len(self.circuit_gates)},2,1,0}}"

    def get_triplet_cgp(self):
        self.get_cgp_wires()
        return "".join([g.get_triplet_cgp(a_index=self.get_circuit_wire_index(g.a), b_index=self.get_circuit_wire_index(g.b)) for g in self.circuit_gates])

    def get_output_cgp(self):
        return "(" + ",".join([str(self.get_circuit_wire_index(o)) for o in self.out.bus[::-1]]) + ")"

    # Generating flat CGP chromosome representation of circuit
    def get_cgp_code_flat(self, file_object):
        file_object.write(self.get_parameters_cgp())
        file_object.write(self.get_triplet_cgp())
        file_object.write(self.get_output_cgp())
        file_object.close()


""" MULTIPLIER CIRCUITS """


class multiplier_circuit(arithmetic_circuit):
    def __init__(self):
        super().__init__()

    """ Array multipliers """
    # Used in array multipliers to get previous row's component output wires
    # for further connection to another component's input
    def get_previous_partial_product(self, a_index: int, b_index: int, offset: int = 0):
        # To get the index of previous row's connecting adder and its generated pp
        index = ((b_index-2) * (self.N*2)) + ((self.N-1)+2*(a_index+2)) + offset

        # Get carry wire as input for the last adder in current row
        if a_index == self.N-1:
            index = index-2
            return self.components[index].get_carry_wire()
        # Get sum wire as input for current adder
        else:
            return self.components[index].get_sum_wire()

    """ Dadda multiplier """
    # Used in dadda multipliers to get multiplier's maximum height
    @staticmethod
    def get_maximum_height(initial_value: int):
        stage = 0
        d = 2
        while True:
            stage += 1
            max_height = d
            # Calculating maximum height sequence
            # d(j=1) = 2; d(j+1) = floor(1.5*d)
            d = math.floor(1.5*d)
            if d >= initial_value:
                return stage, max_height

    def init_column_heights(self, signed=False):
        columns = [[num] if num <= self.N else [num - (num - self.N)*2] for num in range(1, self.out.N)]
        columns = [self.add_column_wires(column=col, column_index=columns.index(col)) for col in columns]
        return columns

    def add_column_wires(self, column: list, column_index: int):
        [column.append([]) for _ in range(column[0])]
        if column_index <= self.N-1:
            [column[column[0]-index].append(self.a.get_wire(index)) for index in range(0, column[0])]
            [column[index+1].append(self.b.get_wire(index)) for index in range(0, column[0])]
        else:
            [column[self.a.N-index].append(self.a.get_wire(index)) for index in range(self.a.N-1, self.a.N-column[0]-1, -1)]
            [column[index-(self.a.N-1-column[0])].append(self.b.get_wire(index)) for index in range(self.a.N-column[0], self.a.N)]

        # TODO check and refactor
        # Filling unsigned pp matrix with AND gates
        if self.__class__.__name__ == "unsigned_dadda_multiplier" or self.__class__.__name__ == "unsigned_wallace_multiplier":
            column[1:] = [and_gate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index)) for i in range(1, len(column))]
        # Filling signed pp matrix with AND/NAND gates (based on Baugh-Wooley multiplication algorithm)
        else:
            # First half of partial product columns contains only AND gates
            if column_index < self.N-1 or column_index == self.out.N-2:
                column[1:] = [and_gate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index)) for i in range(1, len(column))]
            # Second half of partial product columns contains NAND/AND gates
            else:
                column[1] = nand_gate(a=column[1][0], b=column[1][1], prefix=self.prefix+'_nand_'+str(column[1][0].index)+'_'+str(column[1][1].index))
                column[-1] = nand_gate(a=column[-1][0], b=column[-1][1], prefix=self.prefix+'_nand_'+str(column[-1][0].index)+'_'+str(column[-1][1].index))
                if len(column[2:-1]) != 0:
                    column[2:-1] = [and_gate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index)) for i in range(2, len(column)-1)]
        
        return column

    def get_column_height(self, column_num: int):
        return self.columns[column_num][0]

    def update_column_heights(self, curr_column: int, curr_height_change: int, next_column: int = 0, next_height_change: int = 0):
        self.columns[curr_column][0] = self.get_column_height(curr_column)+curr_height_change
        if next_column-1 == curr_column:
            self.columns[next_column][0] = self.get_column_height(next_column)+next_height_change

    def get_column_wire(self, column: int, bit: int):
        if isinstance(self.columns[column][bit], and_gate) or isinstance(self.columns[column][bit], nand_gate):
            self.add_component(self.columns[column][bit])
            return self.get_previous_component(1).out
        else:
            return self.columns[column][bit]

    def update_column_wires(self, curr_column: int, adder: arithmetic_circuit, next_column: int = 0):
        if hasattr(adder, "c"):
            self.columns[curr_column].pop(1)
            self.columns[curr_column].pop(1)
            self.columns[curr_column].pop(1)
            self.columns[curr_column].insert(self.get_column_height(curr_column), adder.get_sum_wire())
        else:
            self.columns[curr_column].pop(1)
            self.columns[curr_column].pop(1)
            self.columns[curr_column].insert(self.get_column_height(curr_column), adder.get_sum_wire())

        if next_column-1 == curr_column:
            self.columns[next_column].insert(1, adder.get_carry_wire())
