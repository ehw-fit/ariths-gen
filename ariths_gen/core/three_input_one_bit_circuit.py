from .two_input_one_bit_circuit import (
    TwoInputOneBitCircuit
)


class ThreeInputOneBitCircuit(TwoInputOneBitCircuit):
    """Class represents a general three input one bit circuit and implements their generation to various representations. It is derived from `TwoInputOneBitCircuit` class.
    """
    def __init__(self):
        super().__init__()

    """ C CODE GENERATION """
    # FLAT C #
    # Function prototype with three inputs
    def get_prototype_c(self):
        """Generates C code function header to describe corresponding three input one bit circuit's interface in C code.

        Returns:
            str: Function's name and parameters in C code.
        """
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix}, {self.c_data_type} {self.c.prefix})" + "{" + "\n"

    # HIERARCHICAL C #
    # Subcomponent generation (three inputs)
    def get_out_invocation_c(self, **kwargs):
        """Generates hierarchical C code invocation of corresponding three input one bit circuit's generated function block.

           Assigns output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchiacal C code subcomponent's C function invocation and output assignment.
        """
        circuit_class = self.__class__()
        return "".join([f'  {o.name} = ({circuit_class.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> {self.out.bus.index(o)}) & 0x01;\n' for o in self.out.bus])

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    # Module prototype with three inputs
    def get_prototype_v(self):
        """Generates Verilog module header to describe corresponding three input one bit circuit's interface in Verilog.

        Returns:
            str: Module's name and parameters in Verilog.
        """
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, input {self.c.name}{''.join([f', output {o.name}' for o in self.out.bus])});\n"

    # HIERARCHICAL VERILOG #
    # Subcomponent generation (three inputs)
    def get_invocation_v(self, **kwargs):
        """Generates hierarchical Verilog code invocation of corresponding three input one bit circuit's generated function block.

        Returns:
            str: Hierarchiacal Verilog code subcomponent's module invocation.
        """
        circuit_class = self.__class__()
        return f"  {circuit_class.prefix} {circuit_class.prefix}_{self.out.get_wire().name}({self.a.name}, {self.b.name}, {self.c.name}{''.join([f', {o.name}' for o in self.out.bus])});\n"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    # Model prototype with three inputs
    def get_declaration_blif(self):
        """Generates flat Blif code declaration of three input one bit circuit's input/output wires.

        Returns:
            str: Flattened Blif code containing declaration of circuit's interface wires.
        """
        return f".inputs {self.a.name} {self.b.name} {self.c.name}\n" + \
               f".outputs{self.out.get_wire_declaration_blif(array=False)}\n"

    # HIERARCHICAL BLIF #
    # Subcomponent generation (3 inputs)
    def get_invocation_blif_hier(self, **kwargs):
        """Generates hierarchical Blif code invocation of corresponding three input one bit circuit's generated function block.

        Returns:
            str: Hierarchiacal Blif code subcomponent's model invocation.
        """
        circuit_class = self.__class__()
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt {circuit_class.prefix} a={self.inputs[0].name} b={self.inputs[1].name} cin={self.inputs[2].name}{''.join([f' {o.name}={self.out.get_wire(circuit_class.out.bus.index(o)).name}' for o in circuit_class.out.bus])}\n"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    # Chromosome prototype with three inputs
    def get_parameters_cgp(self):
        """Generates CGP chromosome parameters of corresponding three input one bit circuit.
           In total seven parameters represent: total inputs, total outputs, number of rows, number of columns (gates),
           number of each gate's inputs, number of each gate's outputs, quality constant value.

        Returns:
            str: CGP chromosome parameters of described circuit.
        """
        self.circuit_gates = self.get_circuit_gates()
        return f"{{3,2,1,{len(self.circuit_gates)},2,1,0}}"
