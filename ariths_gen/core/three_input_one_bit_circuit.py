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
               f".outputs{self.out.get_wire_declaration_blif(array=False)}\n"

    # HIERARCHICAL BLIF #
    # Subcomponent generation (3 inputs)
    def get_invocation_blif_hier(self, **kwargs):
        circuit_class = self.__class__()
        return f"{self.get_wire_mapping_blif()}" + \
               f".subckt {circuit_class.prefix} a={self.inputs[0].name} b={self.inputs[1].name} cin={self.inputs[2].name}{''.join([f' {o.name}={self.out.get_wire(circuit_class.out.bus.index(o)).name}' for o in circuit_class.out.bus])}\n"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    # Chromosome prototype with three inputs
    def get_parameters_cgp(self):
        self.circuit_gates = self.get_circuit_gates()
        return f"{{3,2,1,{len(self.circuit_gates)},2,1,0}}"
