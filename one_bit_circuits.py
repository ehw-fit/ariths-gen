from arithmetic_circuits import arithmetic_circuit
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from wire_components import wire, bus

""" ONE BIT CIRCUITS """


class one_bit_circuit(arithmetic_circuit):
    def __init__(self):
        super().__init__()

    """ C CODE GENERATION """
    # FLAT C #
    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Half adder (2 inputs adder) wires values initialization
    def get_init_c_flat(self):
        return f"{self.components[0].a.get_assign_c(name=self.components[0].a.get_wire_value_c(name=self.a.name))}" + \
               f"{self.components[0].b.get_assign_c(name=self.components[0].b.get_wire_value_c(name=self.b.name))}" + \
               "".join([f"  {c.out.name} = {c.get_init_c_flat()};\n" for c in self.components])

    # Generating flat C code representation of circuit
    def get_c_code_flat(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declaration_c_flat()+"\n")
        file_object.write(self.get_init_c_flat()+"\n")
        file_object.write(self.get_function_out_c_flat())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_block_c(self):
        adder_block = half_adder(a=wire(name="a"), b=wire(name="b")) if isinstance(self, half_adder) else full_adder(a=wire(name="a"), b=wire(name="b"), c=wire(name="cin"))
        return f"{adder_block.get_circuit_c()}\n\n"

    def get_wire_declaration_c_hier(self):
        return f"{self.out.get_wire_declaration_c()}"

    def get_out_invocation_c(self, **kwargs):
        return self.get_sum_invocation_c()+"\n" + \
               self.get_cout_invocation_c()+"\n"

    def get_sum_invocation_c(self):
        return f"  {self.get_sum_wire().name} = (ha({self.a.name}, {self.b.name}) >> 0) & 0x01;"

    def get_cout_invocation_c(self):
        return f"  {self.get_carry_wire().name} = (ha({self.a.name}, {self.b.name}) >> 1) & 0x01;"

    def get_function_sum_c_hier(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.components[0].get_gate_output_c(a=self.a ,b=self.b, offset=offset)};\n"

    def get_function_carry_c_hier(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.components[1].get_gate_output_c(a=self.a ,b=self.b, offset=offset)};\n"

    def get_circuit_c(self):
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_function_sum_c_hier()}" + \
               f"{self.get_function_carry_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, output {self.out.get_wire(0).name}, output {self.out.get_wire(1).name});\n"

    def get_declaration_v_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires])

    # Half adder (2 inputs adder) wires values initialization
    def get_init_v_flat(self):
        return f"{self.components[0].get_assign_v_flat()}" + \
               f"  assign {self.components[1].out.name} = {self.components[1].get_init_v_flat()};\n"

    # Not used in 1 bit circuits (no effect when calling while generating)
    def get_function_out_v_flat(self):
        return ""

    # HIERARCHICAL VERILOG #
    def get_function_block_v(self):
        adder_block = half_adder(a=wire(name="a"), b=wire(name="b")) if isinstance(self, half_adder) else full_adder(a=wire(name="a"), b=wire(name="b"), c=wire(name="cin"))
        return f"{adder_block.get_circuit_v()}\n\n"

    def get_wire_declaration_v_hier(self):
        return f"{self.out.get_wire_declaration_v()}"

    def get_invocation_v(self, **kwargs):
        return f"  ha ha_{self.get_carry_wire().name}({self.a.name}, {self.b.name}, {self.get_sum_wire().name}, {self.get_carry_wire().name});\n"

    def get_function_sum_v_hier(self):
        return f"{self.components[0].get_gate_invocation_v()}"

    def get_function_carry_v_hier(self):
        return f"{self.components[1].get_gate_invocation_v()}"

    def get_circuit_v(self):
        return f"{self.get_prototype_v()}" + \
               f"{self.get_function_sum_v_hier()}" + \
               f"{self.get_function_carry_v_hier()}" + \
               f"endmodule"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_declaration_blif(self):
        return f".inputs {self.a.name} {self.b.name}" + \
               f"\n.outputs" + \
               "".join([f" {w.name}" for w in self.out.bus])+"\n"

    def get_wire_mapping_blif(self):
        # For unique mapping of all circuit's input interconnections
        self.get_circuit_wires()
        return "".join([c[0].get_assign_blif(name=c[0].name.replace(self.prefix+'_', '')) for c in self.circuit_wires[:self.out.N]])

    def get_function_blif_flat(self):
        return f"{self.get_wire_mapping_blif()}"+"".join([c.get_function_blif_flat() for c in self.components])

    # Not needed in 1-bit circuits
    def get_function_out_blif(self):
        return ""

    # HIERARCHICAL BLIF #
    def get_function_block_blif(self):
        adder_block = half_adder(a=wire(name="a"), b=wire(name="b")) if isinstance(self, half_adder) else full_adder(a=wire(name="a"), b=wire(name="b"), c=wire(name="cin"))
        return f"{adder_block.get_circuit_blif()}"

    def get_function_blif_hier(self):
        return "".join(c.get_invocation_blif_hier(init=False) for c in self.components)

    def get_invocation_blif_hier(self, **kwargs):
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt ha a={self.circuit_wires[0][0].name} b={self.circuit_wires[1][0].name} ha_y0={self.out.get_wire(0).name} ha_y1={self.out.get_wire(1).name}\n"

    def get_circuit_blif(self):
        return f"{self.get_prototype_blif()}" + \
               f"{self.get_declaration_blif()}" + \
               f"{self.get_wire_mapping_blif()}" + \
               f"{self.get_function_blif_hier()}" + \
               f".end\n"
    
    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{2,2,1,{len(self.circuit_gates)},2,1,0}}"


class half_adder(one_bit_circuit):
    def __init__(self, a: wire, b: wire, prefix: str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", self.N+1)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor_gate = xor_gate(a, b, prefix, outid=0)
        self.add_component(obj_xor_gate)
        self.out.connect(0, obj_xor_gate.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and_gate = and_gate(a, b, prefix, outid=1)
        self.add_component(obj_and_gate)
        self.out.connect(1, obj_and_gate.out)


class full_adder(one_bit_circuit):
    def __init__(self, a: wire, b: wire, c: wire, prefix: str = "fa"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", self.N+1)

        # PG logic
        propagate_xor_gate1 = xor_gate(a, b, prefix, outid=0)
        self.add_component(propagate_xor_gate1)
        generate_and_gate1 = and_gate(a, b, prefix, outid=1)
        self.add_component(generate_and_gate1)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.out, c, prefix, outid=2)
        self.add_component(obj_xor_gate2)
        self.out.connect(0, obj_xor_gate2.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and_gate2 = and_gate(propagate_xor_gate1.out, c, prefix, outid=3)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.out, obj_and_gate2.out, prefix, outid=4)
        self.add_component(obj_or_gate)

        self.out.connect(1, obj_or_gate.out)

        # TODO delete?
        # Storing PG logic gates for better accessibility
        self.propagate = propagate_xor_gate1
        self.generate = generate_and_gate1

    """ C CODE GENERATION """
    # FLAT C #
    # Full adder function prototype with three inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix}, {self.c_data_type} {self.c.prefix})" + "{" + "\n"

    # Full adder wires values initialization
    def get_init_c_flat(self):
        return f"{self.components[0].a.get_assign_c(name=self.components[0].a.get_wire_value_c(name=self.a.name))}" + \
               f"{self.components[0].b.get_assign_c(name=self.components[0].b.get_wire_value_c(name=self.b.name))}" + \
               f"{self.components[2].b.get_assign_c(name=self.components[2].b.get_wire_value_c(name=self.c.name))}" + \
               "".join([f"  {c.out.name} = {c.get_init_c_flat()};\n" for c in self.components])

    # HIERARCHICAL C #
    def get_declaration_c_hier(self):
        return f"{self.components[0].out.get_declaration_c()}" + \
               f"{self.components[1].out.get_declaration_c()}" + \
               f"{self.components[3].out.get_declaration_c()}"

    def get_init_c_hier(self):
        # Temporarily change cin name for proper gate invocation
        self.components[2].b.name = self.components[3].b.name = self.components[2].b.name.replace(self.prefix+"_", "")
        return f"  {self.components[0].out.name} = {self.components[0].get_gate_invocation_c()}" + \
               f"  {self.components[1].out.name} = {self.components[1].get_gate_invocation_c()}" + \
               f"  {self.components[3].out.name} = {self.components[3].get_gate_invocation_c(remove_prefix=False)}"

    def get_sum_invocation_c(self):
        return f"  {self.get_sum_wire().name} = (fa({self.a.name}, {self.b.name}, {self.c.name}) >> 0) & 0x01;"

    def get_cout_invocation_c(self):
        return f"  {self.get_carry_wire().name} = (fa({self.a.name}, {self.b.name}, {self.c.name}) >> 1) & 0x01;"

    def get_function_sum_c_hier(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.components[0].get_gate_output_c(a=self.components[0].out, b=self.c, offset=offset)};\n"

    def get_function_carry_c_hier(self, offset: int = 1):
        # Return cin name to previous string value for sake of consistency
        self.components[2].b.name = self.components[3].b.name = self.prefix+"_"+self.c.name
        return f"  {self.out.prefix} |= {self.get_previous_component().get_gate_output_c(a=self.components[1].out, b=self.components[3].out, offset=offset)};\n"

    def get_circuit_c(self):
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_declaration_c_hier()}\n" + \
               f"{self.get_init_c_hier()}\n" + \
               f"{self.get_function_sum_c_hier()}" + \
               f"{self.get_function_carry_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, input {self.c.name}, output {self.out.get_wire(0).name}, output {self.out.get_wire(1).name});\n"

    # Full adder wires values initialization
    def get_init_v_flat(self):
        return f"{self.components[0].a.get_assign_v(name=self.components[0].a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.components[0].b.get_assign_v(name=self.components[0].b.name.replace(self.prefix+'_', ''))}" + \
               f"{self.components[2].b.get_assign_v(name=self.components[2].b.name.replace(self.prefix+'_', ''))}" + \
               "".join([f"  assign {c.out.name} = {c.get_init_v_flat()};\n" for c in self.components])

    # HIERARCHICAL VERILOG #
    def get_invocation_v(self, **kwargs):
        return f"  fa fa_{self.get_carry_wire().name}({self.a.name}, {self.b.name}, {self.c.name}, {self.get_sum_wire().name}, {self.get_carry_wire().name});\n"

    def get_declaration_v_hier(self):
        return f"{self.components[0].out.get_declaration_v()}" + \
               f"{self.components[1].out.get_declaration_v()}" + \
               f"{self.components[3].out.get_declaration_v()}"

    def get_init_v_hier(self):
        # Temporarily change cin name for proper gate invocation
        self.components[2].b.name = self.components[3].b.name = self.components[2].b.name.replace(self.prefix+"_", "")
        return f"{self.components[0].get_gate_invocation_v()}" + \
               f"{self.components[1].get_gate_invocation_v()}" + \
               f"{self.components[3].get_gate_invocation_v(remove_prefix=False)}"

    def get_function_sum_v_hier(self):
        return f"{self.components[2].get_gate_invocation_v(remove_prefix=False)}"

    def get_function_carry_v_hier(self):
        # Return cin name to previous string value for sake of consistency
        self.components[2].b.name = self.components[3].b.name = self.prefix+"_"+self.c.name
        return f"{self.components[4].get_gate_invocation_v(remove_prefix=False)}"

    def get_circuit_v(self):
        return f"{self.get_prototype_v()}" + \
               f"{self.get_declaration_v_hier()}\n" + \
               f"{self.get_init_v_hier()}\n" + \
               f"{self.get_function_sum_v_hier()}" + \
               f"{self.get_function_carry_v_hier()}" + \
               f"endmodule"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_declaration_blif(self):
        return f".inputs {self.a.name} {self.b.name} {self.c.name}" + \
               f"\n.outputs" + \
               "".join([f" {w.name}" for w in self.out.bus])+"\n"

    def get_wire_mapping_blif(self):
        # For unique mapping of all circuit's input interconnections
        self.get_circuit_wires()
        # getting desired inner wires and selecting first element from list of tuples containing wires and other info
        return f"{self.circuit_wires[0][0].get_assign_blif(name=self.circuit_wires[0][0].name.replace(self.prefix+'_', ''))}" + \
               f"{self.circuit_wires[1][0].get_assign_blif(name=self.circuit_wires[1][0].name.replace(self.prefix+'_', ''))}" + \
               f"{self.circuit_wires[4][0].get_assign_blif(name=self.circuit_wires[4][0].name.replace(self.prefix+'_', ''))}"

    # HIERARCHICAL BLIF #
    def get_invocation_blif_hier(self, **kwargs):
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt fa a={self.circuit_wires[0][0].name} b={self.circuit_wires[1][0].name} cin={self.circuit_wires[4][0].name} fa_y2={self.out.get_wire(0).name} fa_y4={self.out.get_wire(1).name}\n"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{3,2,1,{len(self.circuit_gates)},2,1,0}}"