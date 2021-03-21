from arithmetic_circuits import arithmetic_circuit
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from wire_components import wire, bus

""" ONE BIT CIRCUITS """


class two_input_one_bit_circuit(arithmetic_circuit):
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
        return "".join([c.get_declaration_v() for c in self.inputs])

    def get_init_v_hier(self):
        return "".join([i.get_assign_v(name=i.name.replace(self.prefix+"_","")) for i in self.inputs])

    def get_function_out_v_hier(self):
        return "".join([f"{c.get_gate_invocation_v(remove_prefix=False)}" for c in self.components])

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_declaration_blif(self):
        return f".inputs {self.a.name} {self.b.name}\n" + \
               f".outputs{self.out.get_wire_declaration_blif()}\n"

    def get_wire_mapping_blif(self):
        # For unique mapping of all circuit's input interconnections
        self.get_circuit_wires()
        return "".join([i.get_assign_blif(name=i.name.replace(self.prefix+"_","")) for i in self.inputs])

    def get_function_blif_flat(self):
        return f"{self.get_wire_mapping_blif()}"+"".join([c.get_function_blif_flat() for c in self.components])

    def get_function_out_blif(self):
        return f"{self.out.get_wire_assign_blif(output=True)}"

    # HIERARCHICAL BLIF #
    # Subcomponent generation
    def get_function_block_blif(self):
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_blif()}"

    def get_invocation_blif_hier(self, **kwargs):
        circuit_class = self.__class__()
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt {circuit_class.prefix} a={self.inputs[0].name} b={self.inputs[1].name}{''.join([f' {self.out.prefix}[{circuit_class.out.bus.index(o)}]={self.out.get_wire(circuit_class.out.bus.index(o)).name}' for o in circuit_class.out.bus])}\n"

    # Self circuit hierarchical generation
    def get_function_blif_hier(self):
        return f"{self.get_wire_mapping_blif()}"+"".join(c.get_invocation_blif_hier(init=False) for c in self.components)

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{2,2,1,{len(self.circuit_gates)},2,1,0}}"


class three_input_one_bit_circuit(two_input_one_bit_circuit):
    def __init__(self):
        super().__init__()

    """ C CODE GENERATION """
    # FLAT C #
    # Function prototype with three inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix}, {self.c_data_type} {self.c.prefix})" + "{" + "\n"

    # HIERARCHICAL C #
    # Subcomponent generation (3 inputs)
    def get_out_invocation_c(self, **kwargs):
        circuit_class = self.__class__()
        return "".join([f'  {o.name} = ({circuit_class.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> {self.out.bus.index(o)}) & 0x01;\n' for o in self.out.bus])
    
    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    # Module prototype with three inputs
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, input {self.c.name}{''.join([f', output {o.name}' for o in self.out.bus])});\n"

    # HIERARCHICAL VERILOG #
    # Subcomponent generation (3 inputs)
    def get_invocation_v(self, **kwargs):
        circuit_class = self.__class__()
        return f"  {circuit_class.prefix} {circuit_class.prefix}_{self.out.get_wire().name}({self.a.name}, {self.b.name}, {self.c.name}{''.join([f', {o.name}' for o in self.out.bus])});\n"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    # Model prototype with three inputs
    def get_declaration_blif(self):
        return f".inputs {self.a.name} {self.b.name} {self.c.name}\n" + \
               f".outputs{self.out.get_wire_declaration_blif()}\n"

    # HIERARCHICAL BLIF #
    # Subcomponent generation (3 inputs)
    def get_invocation_blif_hier(self, **kwargs):
        circuit_class = self.__class__()
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt {circuit_class.prefix} a={self.inputs[0].name} b={self.inputs[1].name} cin={self.inputs[2].name}{''.join([f' {self.out.prefix}[{circuit_class.out.bus.index(o)}]={self.out.get_wire(circuit_class.out.bus.index(o)).name}' for o in circuit_class.out.bus])}\n"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    # Chromosome prototype with three inputs
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{3,2,1,{len(self.circuit_gates)},2,1,0}}"


# TWO INPUT CIRCUITS
class half_adder(two_input_one_bit_circuit):
    def __init__(self, a: wire = wire(name="a"), b: wire = wire(name="b"), prefix: str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", self.N+1)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor = xor_gate(a, b, prefix=self.prefix, outid=0)
        self.add_component(obj_xor)
        self.out.connect(0, obj_xor.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and = and_gate(a, b, prefix=self.prefix, outid=1)
        self.add_component(obj_and)
        self.out.connect(1, obj_and.out)


class pg_logic_block(two_input_one_bit_circuit):
    def __init__(self, a: wire = wire(name="a"), b: wire = wire(name="b"), prefix: str = "pg_logic"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 3 wires for component's bus output (propagate, generate, sum)
        self.out = bus("out", self.N+2)

        # PG logic
        propagate_or = or_gate(a, b, prefix=self.prefix, outid=0)
        self.add_component(propagate_or)
        generate_and = and_gate(a, b, prefix=self.prefix, outid=1)
        self.add_component(generate_and)
        sum_xor = xor_gate(a, b, prefix=self.prefix, outid=2)
        self.add_component(sum_xor)

        self.out.connect(0, propagate_or.out)
        self.out.connect(1, generate_and.out)
        self.out.connect(2, sum_xor.out)

    def get_propagate_wire(self):
        return self.out.get_wire(0)

    def get_generate_wire(self):
        return self.out.get_wire(1)

    def get_sum_wire(self):
        return self.out.get_wire(2)

class constant_wire_value_0(two_input_one_bit_circuit):
    def __init__(self, a: wire = wire(name="a"), b: wire = wire(name="b"), prefix: str = "constant_wire_value_0"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 1 wire for component's bus output (constant wire)
        self.out = bus("out", self.N)

        # Generation of wire with constant value 0
        obj_xor = xor_gate(self.a, self.b, prefix=self.prefix, outid=0)
        obj_xnor = xnor_gate(self.a, self.b, prefix=self.prefix, outid=1)
        obj_nor = nor_gate(obj_xor.out, obj_xnor.out, prefix=self.prefix, outid=2)
        obj_nor.out.name = "constant_wire_0"
        obj_nor.out.prefix = "constant_wire_0"

        self.add_component(obj_xor)
        self.add_component(obj_xnor)
        self.add_component(obj_nor)

        # Constant wire output
        self.out.connect(0, obj_nor.out)


class constant_wire_value_1(two_input_one_bit_circuit):
    def __init__(self, a: wire = wire(name="a"), b: wire = wire(name="b"), prefix: str = "constant_wire_value_1"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 1 wire for component's bus output (constant wire)
        self.out = bus("out", self.N)

        # Generation of wire with constant value 1
        obj_xor = xor_gate(self.a, self.b, prefix=self.prefix, outid=0)
        obj_xnor = xnor_gate(self.a, self.b, prefix=self.prefix, outid=1)
        obj_or = or_gate(obj_xor.out, obj_xnor.out, prefix=self.prefix, outid=2)
        obj_or.out.name = "constant_wire_1"
        obj_or.out.prefix = "constant_wire_1"
        self.add_component(obj_xor)
        self.add_component(obj_xnor)
        self.add_component(obj_or)

        # Constant wire output
        self.out.connect(0, obj_or.out)


# THREE INPUT CIRCUITS
class full_adder(three_input_one_bit_circuit):
    def __init__(self, a: wire = wire(name="a"), b: wire = wire(name="b"), c: wire = wire(name="cin"), prefix: str = "fa"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", self.N+1)

        # PG logic
        propagate_xor = xor_gate(a, b, prefix=self.prefix, outid=0)
        self.add_component(propagate_xor)
        generate_and = and_gate(a, b, prefix=self.prefix, outid=1)
        self.add_component(generate_and)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor = xor_gate(propagate_xor.out, c, prefix=self.prefix, outid=2)
        self.add_component(obj_xor)
        self.out.connect(0, obj_xor.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and = and_gate(propagate_xor.out, c, prefix=self.prefix, outid=3)
        self.add_component(obj_and)

        obj_or = or_gate(generate_and.out, obj_and.out, prefix=self.prefix, outid=4)
        self.add_component(obj_or)

        self.out.connect(1, obj_or.out)


class full_adder_pg(three_input_one_bit_circuit):
    def __init__(self, a: wire = wire(name="a"), b: wire = wire(name="b"), c: wire = wire(name="cin"), prefix: str = "fa_cla"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 3 wires for component's bus output (sum, propagate, generate)
        self.out = bus("out", self.N+2)

        # PG logic
        propagate_xor = xor_gate(a, b, prefix=self.prefix, outid=0)
        self.add_component(propagate_xor)
        self.out.connect(0, propagate_xor.out)

        generate_and = and_gate(a, b, prefix=self.prefix, outid=1)
        self.add_component(generate_and)
        self.out.connect(1, generate_and.out)

        # Sum output
        sum_xor = xor_gate(propagate_xor.out, c, prefix=self.prefix, outid=2)
        self.add_component(sum_xor)
        self.out.connect(2, sum_xor.out)
    
    def get_propagate_wire(self):
        return self.out.get_wire(0)

    def get_generate_wire(self):
        return self.out.get_wire(1)

    def get_sum_wire(self):
        return self.out.get_wire(2)