from .arithmetic_circuit import (
    ArithmeticCircuit
)


class TwoInputOneBitCircuit(ArithmeticCircuit):
    """Class represents a general two input one bit circuit and implements their generation to various representations. It is derived from `ArithmeticCircuit` class.
    """
    def __init__(self):
        super().__init__()

    """ C CODE GENERATION """
    # FLAT C #
    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c_flat(self):
        """Generates flat C code declaration of input/output wires.

        Returns:
            str: Flattened C code containing unique declaration of circuit wires.
        """
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Wires values initialization and assignment
    def get_init_c_flat(self):
        """Generates flat C code initialization and assignment of corresponding two input one bit circuit's input/output wires.

        Returns:
            str: Flattened C code initialization of two input one bit circuit wires.
        """
        return "".join([i.get_assign_c(name=i.get_wire_value_c(name=i.name.replace(self.prefix+"_", ""))) for i in self.inputs]) + \
               "".join([f"  {c.out.name} = {c.get_init_c_flat()};\n" for c in self.components])

    # Generating flat C code representation of circuit
    def get_c_code_flat(self, file_object):
        """Generates flat C code representation of corresponding two input one bit circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
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
        """Generates hierarchical C code representation of corresponding two input one bit circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical C code of two input one bit circuit's function block description.
        """
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_c()}\n\n"

    def get_wire_declaration_c_hier(self):
        """Generates hierarchical C code declaration of corresponding subcomponent output wires inside the upper component.

           Generates wires used to connect output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code of two input one bit circuit's output wires declaration.
        """
        return f"{self.out.get_wire_declaration_c()}"

    def get_out_invocation_c(self, **kwargs):
        """Generates hierarchical C code invocation of corresponding two input one bit circuit's generated function block.

           Assigns output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code subcomponent's C function invocation and output assignment.
        """
        circuit_class = self.__class__()
        return "".join([f'  {o.name} = ({circuit_class.prefix}({self.a.name}, {self.b.name}) >> {self.out.bus.index(o)}) & 0x01;\n' for o in self.out.bus])

    # Self circuit hierarchical generation
    def get_declaration_c_hier(self):
        """Generates hierarchical C code declaration of input/output wires.

        Returns:
            str: Hierarchical C code containing unique declaration of circuit wires.
        """
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    def get_init_c_hier(self):
        """Generates hierarchical C code initialization and assignment of corresponding two input one bit circuit's input/output wires.

        Returns:
            str: Hierarchical C code initialization of two input one bit circuit wires.
        """
        return "".join([i.get_assign_c(name=i.get_wire_value_c(name=i.name.replace(self.prefix+"_", ""))) for i in self.inputs]) + \
               "".join([f"  {c.out.name} = {c.get_gate_invocation_c(remove_prefix=False)}" for c in self.components])

    def get_function_out_c_hier(self):
        """Generates hierarchical C code assignment of corresponding two input one bit circuit's output wires.

        Returns:
            str: Hierarchical C code containing output bus wires assignment.
        """
        return "".join([f"  {self.out.prefix} |= {o.return_wire_value_c(offset=self.out.bus.index(o))};\n" for o in self.out.bus])

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        """Generates Verilog module header to describe corresponding two input one bit circuit's interface in Verilog.

        Returns:
            str: Module's name and parameters in Verilog.
        """
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}{''.join([f', output {o.name}' for o in self.out.bus])});\n"

    def get_declaration_v_flat(self):
        """Generates flat Verilog code declaration of input/output wires.

        Returns:
            str: Flattened Verilog code containing unique declaration of circuit wires.
        """
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires])

    # Wires values initialization and assignment
    def get_init_v_flat(self):
        """Generates flat Verilog code initialization and assignment of corresponding two input one bit circuit's input/output wires.

        Returns:
            str: Flattened Verilog code initialization of two input one bit circuit wires.
        """
        return "".join([i.get_assign_v(name=i.name.replace(self.prefix+"_", "")) for i in self.inputs]) + \
               "".join([f"  assign {c.out.name} = {c.get_init_v_flat()};\n" for c in self.components])

    # Generating flat Verilog code representation of circuit
    def get_v_code_flat(self, file_object):
        """Generates flat Verilog code representation of corresponding two input one bit circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_v())
        file_object.write(self.get_declaration_v_flat()+"\n")
        file_object.write(self.get_init_v_flat())
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    # Subcomponent generation
    def get_function_block_v(self):
        """Generates hierarchical Verilog code representation of corresponding two input one bit circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Verilog code of two input one bit circuit's function block description.
        """
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_v()}\n\n"

    def get_wire_declaration_v_hier(self):
        """Generates hierarchical Verilog code declaration of corresponding subcomponent output wires inside the upper component.

           Generates wires used to connect output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code of two input one bit circuit's output wires declaration.
        """
        return f"{self.out.get_wire_declaration_v()}"

    def get_invocation_v(self, **kwargs):
        """Generates hierarchical Verilog code invocation of corresponding two input one bit circuit's generated function block.

        Returns:
            str: Hierarchical Verilog code subcomponent's module invocation.
        """
        circuit_class = self.__class__()
        return f"  {circuit_class.prefix} {circuit_class.prefix}_{self.out.get_wire().name}({self.a.name}, {self.b.name}{''.join([f', {o.name}' for o in self.out.bus])});\n"

    # Self circuit hierarchical generation
    def get_declaration_v_hier(self):
        """Generates hierarchical Verilog code declaration of input/output wires.

        Returns:
            str: Hierarchical Verilog code containing unique declaration of circuit wires.
        """
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires if c[0] not in self.out.bus])

    def get_init_v_hier(self):
        """Generates hierarchical Verilog code initialization and assignment of corresponding two input one bit circuit's input/output wires.

        Returns:
            str: Hierarchical Verilog code initialization of two input one bit circuit wires.
        """
        return "".join([i.get_assign_v(name=i.name.replace(self.prefix+"_", "")) for i in self.inputs])

    def get_function_out_v_hier(self):
        """Generates hierarchical Verilog code invocation of corresponding two input one bit circuit's inner subcomponents to map their output values into circuit's output wires.

        Returns:
            str: Hierarchical Verilog code of inner subcomponents invocations and their inner assignment of output wires values.
        """
        return "".join([f"{c.get_gate_invocation_v(remove_prefix=False)}" for c in self.components])

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_declaration_blif(self):
        """Generates flat Blif code declaration of two input one bit circuit's input/output wires.

        Returns:
            str: Flattened Blif code containing declaration of circuit's interface wires.
        """
        return f".inputs {self.a.name} {self.b.name}\n" + \
               f".outputs{self.out.get_wire_declaration_blif(array=False)}\n"

    def get_wire_mapping_blif(self):
        """Generates flat Blif code used to map the input wires into other inner wires to obtain proper wire names used for interconnections inside the circuit.

        Returns:
            str: Flattened Blif code containing unique mapping of all circuit's input interconnections.
        """
        # For unique mapping of all circuit's input interconnections
        self.get_circuit_wires()
        return "".join([i.get_assign_blif(name=i.name.replace(self.prefix+"_", "")) for i in self.inputs])

    def get_function_blif_flat(self):
        """Generates flat Blif code with unique input wire mapping and invocation of subcomponents Boolean functions via their corresponding truth tables.

        Returns:
            str: Flattened Blif code containing input wires mapping and inner subcomponents Boolean functions invocation.
        """
        return f"{self.get_wire_mapping_blif()}"+"".join([c.get_function_blif_flat() for c in self.components])

    # Generating flat BLIF code representation of circuit
    def get_blif_code_flat(self, file_object):
        """Generates flat Blif code representation of corresponding two input one bit circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_blif())
        file_object.write(self.get_declaration_blif())
        file_object.write(self.get_function_blif_flat())
        file_object.write(f".end\n")
        file_object.close()

    # HIERARCHICAL BLIF #
    # Subcomponent generation
    def get_function_block_blif(self):
        """Generates hierarchical Blif code representation of corresponding two input one bit circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Blif code of two input one bit circuit's function block description.
        """
        adder_block = self.__class__()
        return f"{adder_block.get_circuit_blif()}"

    def get_invocation_blif_hier(self, **kwargs):
        """Generates hierarchical Blif code invocation of corresponding two input one bit circuit's generated function block.

        Returns:
            str: Hierarchical Blif code subcomponent's model invocation.
        """
        circuit_class = self.__class__()
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt {circuit_class.prefix} a={self.inputs[0].name} b={self.inputs[1].name}{''.join([f' {o.name}={self.out.get_wire(circuit_class.out.bus.index(o)).name}' for o in circuit_class.out.bus])}\n"

    # Self circuit hierarchical generation
    def get_function_blif_hier(self):
        """Generates hierarchical Blif code with unique input wire mapping and invocation of subcomponents function blocks.

        Returns:
            str: Hierarchical Blif code containing input wires mapping and inner subcomponents function blocks invocation.
        """
        return f"{self.get_wire_mapping_blif()}"+"".join(c.get_invocation_blif_hier(init=False) for c in self.components)

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        """Generates CGP chromosome parameters of corresponding two input one bit circuit.
           In total seven parameters represent: total inputs, total outputs, number of rows, number of columns (gates),
           number of each gate's inputs, number of each gate's outputs, quality constant value.

        Returns:
            str: CGP chromosome parameters of described circuit.
        """
        self.circuit_gates = self.get_circuit_gates()
        return f"{{2,2,1,{len(self.circuit_gates)},2,1,0}}"
