from .arithmetic_circuit import(
    ArithmeticCircuit
)

class TwoInputOneBitCircuit(ArithmeticCircuit):
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

    # Wires values initialization and assignment
    def get_init_c_flat(self):
        return "".join([i.get_assign_c(name=i.get_wire_value_c(name=i.name.replace(self.prefix+"_",""))) for i in self.inputs]) + \
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
    # Subcomponent generation
    def get_function_block_c(self):
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_c()}\n\n"

    def get_wire_declaration_c_hier(self):
        return f"{self.out.get_wire_declaration_c()}"

    def get_out_invocation_c(self, **kwargs):
        circuit_class = self.__class__()
        return "".join([f'  {o.name} = ({circuit_class.prefix}({self.a.name}, {self.b.name}) >> {self.out.bus.index(o)}) & 0x01;\n' for o in self.out.bus])

    # Self circuit hierarchical generation
    def get_declaration_c_hier(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    def get_init_c_hier(self):
        return "".join([i.get_assign_c(name=i.get_wire_value_c(name=i.name.replace(self.prefix+"_",""))) for i in self.inputs]) + \
               "".join([f"  {c.out.name} = {c.get_gate_invocation_c(remove_prefix=False)}" for c in self.components])

    def get_function_out_c_hier(self):
        return "".join([f"  {self.out.prefix} |= {o.return_wire_value_c(offset=self.out.bus.index(o))};\n" for o in self.out.bus])

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}{''.join([f', output {o.name}' for o in self.out.bus])});\n"

    def get_declaration_v_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires])

    # Wires values initialization and assignment
    def get_init_v_flat(self):
        return "".join([i.get_assign_v(name=i.name.replace(self.prefix+"_","")) for i in self.inputs]) + \
               "".join([f"  assign {c.out.name} = {c.get_init_v_flat()};\n" for c in self.components])

    # Generating flat Verilog code representation of circuit
    def get_v_code_flat(self, file_object):
        file_object.write(self.get_prototype_v())
        file_object.write(self.get_declaration_v_flat()+"\n")
        file_object.write(self.get_init_v_flat())
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    # Subcomponent generation
    def get_function_block_v(self):
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_v()}\n\n"

    def get_wire_declaration_v_hier(self):
        return f"{self.out.get_wire_declaration_v()}"

    def get_invocation_v(self, **kwargs):
        circuit_class = self.__class__()
        return f"  {circuit_class.prefix} {circuit_class.prefix}_{self.out.get_wire().name}({self.a.name}, {self.b.name}{''.join([f', {o.name}' for o in self.out.bus])});\n"

    # Self circuit hierarchical generation
    def get_declaration_v_hier(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires if c[0] not in self.out.bus])

    def get_init_v_hier(self):
        return "".join([i.get_assign_v(name=i.name.replace(self.prefix+"_","")) for i in self.inputs])

    def get_function_out_v_hier(self):
        return "".join([f"{c.get_gate_invocation_v(remove_prefix=False)}" for c in self.components])

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_declaration_blif(self):
        return f".inputs {self.a.name} {self.b.name}\n" + \
               f".outputs{self.out.get_wire_declaration_blif(array=False)}\n"

    def get_wire_mapping_blif(self):
        # For unique mapping of all circuit's input interconnections
        self.get_circuit_wires()
        return "".join([i.get_assign_blif(name=i.name.replace(self.prefix+"_","")) for i in self.inputs])

    def get_function_blif_flat(self):
        return f"{self.get_wire_mapping_blif()}"+"".join([c.get_function_blif_flat() for c in self.components])

    def get_function_out_blif(self):
        return f""

    # HIERARCHICAL BLIF #
    # Subcomponent generation
    def get_function_block_blif(self):
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_blif()}"

    def get_invocation_blif_hier(self, **kwargs):
        circuit_class = self.__class__()
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt {circuit_class.prefix} a={self.inputs[0].name} b={self.inputs[1].name}{''.join([f' {o.name}={self.out.get_wire(circuit_class.out.bus.index(o)).name}' for o in circuit_class.out.bus])}\n"

    # Self circuit hierarchical generation
    def get_function_blif_hier(self):
        return f"{self.get_wire_mapping_blif()}"+"".join(c.get_invocation_blif_hier(init=False) for c in self.components)

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{2,2,1,{len(self.circuit_gates)},2,1,0}}"