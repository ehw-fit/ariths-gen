from .two_input_one_bit_circuit import (
    TwoInputOneBitCircuit
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.wire_components.wires import Wire


class ThreeInputOneBitCircuit(TwoInputOneBitCircuit, GeneralCircuit):
    """Class represents a general three input one bit circuit and implements their generation to various representations. It is derived from `TwoInputOneBitCircuit` class.

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        c (Wire): Third input wire.
        prefix (str, optional): Prefix name of circuit. Defaults to "three_input_one_bit_circuit".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "three_input_one_bit_circuit"):
        GeneralCircuit.__init__(self, inputs=[a, b, c], prefix=prefix, name="", out_N=1)
        self.c_data_type = "uint8_t"

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
    def get_out_invocation_c(self, *args, **kwargs):
        """Generates hierarchical C code invocation of corresponding three input one bit circuit's generated function block.

        Assigns output values from invocation of the corresponding function block into inner wires present inside the upper
        component from which function block has been invoked.

        Returns:
            str: Hierarchical C code subcomponent's C function invocation and output assignment.
        """
        # Used to retrieve proper component's output wire offset position within the output bus
        output_bus_wire_names = []
        [output_bus_wire_names.append(w.prefix) for w in self.out.bus]
        circuit_block = self.__class__()
        return "".join([f"  {c.out.prefix} = ({circuit_block.prefix}({self.a.get_wire_value_c_hier()}, {self.b.get_wire_value_c_hier()}, {self.c.get_wire_value_c_hier()}) >> {output_bus_wire_names.index(c.out.prefix)}) & 0x01;\n" for c in self.components if c.disable_generation is False and c.out.prefix in output_bus_wire_names])

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    # Module prototype with three inputs
    def get_prototype_v(self):
        """Generates Verilog for flat module header to describe corresponding three input one bit circuit's interface in Verilog.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner module logic is also modified accordingly. It is used for self three input one bit circuit flat generation.

        Returns:
            str: Flat module's name and parameters in Verilog.
        """
        unique_out_wires = []
        [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, input {self.c.name}" + \
               "".join([f", output {o}" for o in unique_out_wires]) + ");\n"

    def get_self_init_v_flat(self):
        """Generates Verilog for self flat module initialization and assignment of corresponding three input one bit circuit's input/output wires.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner module prototype is also modified accordingly. It is used for self three input one bit circuit flat generation.

        Returns:
            str: Verilog flat module's inner circuit wires initialization and assignment.
        """
        unique_out_wires = []
        [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
        return "".join([c.get_assign_v_flat() if c.disable_generation is False else
                        f"  assign {unique_out_wires.pop(unique_out_wires.index(c.out.name+'_outid'+str(c.outid)))} = {c.out.v_const};\n" if f"{c.out.name+'_outid'+str(c.outid)}" in unique_out_wires and c.out.is_const() else
                        f"  assign {unique_out_wires.pop(unique_out_wires.index(c.out.name+'_outid'+str(c.outid)))} = {c.out.name};\n" if f"{c.out.name+'_outid'+str(c.outid)}" in unique_out_wires else
                        f"" for c in self.components])

    # HIERARCHICAL VERILOG #
    # Self circuit hierarchical generation
    def get_prototype_v_hier(self):
        """Generates Verilog for hierarchical module header to describe corresponding three input one bit circuit's interface in Verilog.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner module logic is also modified accordingly. It is used for self three input one bit circuit hierarchical generation.

        Returns:
            str: Hierarchical module's name and parameters in Verilog.
        """
        unique_out_wires = []
        [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
        return f"module {self.prefix}(input [0:0] {self.a.name}, input [0:0] {self.b.name}, input [0:0] {self.c.name}" + \
               "".join([f", output [0:0] {o}" for o in unique_out_wires]) + ");\n"

    def get_self_init_v_hier(self):
        """Generates Verilog for hierarchical module's inner initialization and assignment of corresponding arithmetic circuit's input/output wires.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner module prototype is also modified accordingly. It is used for self three input one bit circuit hierarchical generation.

        Returns:
            str: Verilog hierarchical module's inner circuit wires initialization and assignment.
        """
        unique_out_wires = []
        [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
        return "".join([c.get_gate_invocation_v() if c.disable_generation is False else
                        f"  assign {unique_out_wires.pop(unique_out_wires.index(c.out.name+'_outid'+str(c.outid)))}[0] = {c.out.v_const};\n" if f"{c.out.name+'_outid'+str(c.outid)}" in unique_out_wires and c.out.is_const() else
                        f"  assign {unique_out_wires.pop(unique_out_wires.index(c.out.name+'_outid'+str(c.outid)))}[0] = {c.out.name}[0];\n" if f"{c.out.name+'_outid'+str(c.outid)}" in unique_out_wires else
                        f"" for c in self.components])

    # Subcomponent generation
    def get_out_invocation_v(self, *args, **kwargs):
        """Generates hierarchical Verilog code invocation of corresponding three input one bit circuit's generated function block.

        Assigns output values from invocation of the corresponding function block into inner wires present inside the upper
        component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code subcomponent's module invocation and output assignment.
        """
        circuit_block = self.__class__()
        return f"  {circuit_block.prefix} {circuit_block.prefix}_{self.out.prefix}(.{circuit_block.a.prefix}({self.a.get_wire_value_v_hier()}), .{circuit_block.b.prefix}({self.b.get_wire_value_v_hier()}), .{circuit_block.c.prefix}({self.c.get_wire_value_v_hier()}){self.out.get_unique_assign_out_wires_v(circuit_block)});\n"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    # Model prototype with three inputs
    def get_declaration_blif(self):
        """Generates Blif code declaration of three input one bit circuit's input/output wires.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner modul logic is also modified accordingly. It is used for self three input one bit circuit flat/hierarchical generation.

        Returns:
            str: Blif code containing declaration of circuit's input/output wires.
        """
        unique_out_wires = []
        [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
        return f".inputs {self.a.get_declaration_blif()} {self.b.get_declaration_blif()} {self.c.get_declaration_blif()}\n" + \
               f".outputs" + \
               "".join([f" {o}" for o in unique_out_wires]) + "\n" + \
               f".names vdd\n1\n" + \
               f".names gnd\n0\n"

    def get_function_blif_flat(self, top_modul: bool = False):
        """Generates flat Blif code with invocation of subcomponents logic gates Boolean functions via their corresponding truth tables.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner modul prototype is also modified accordingly. It is used for self three input one bit circuit flat generation.

        Args:
            top_modul (bool, optional): Specifies whether the described circuit represents top modul component (self one bit circuit generation). Defaults to False.

        Returns:
            str: Flat Blif code containing invocation of inner subcomponents logic gates Boolean functions.
        """
        if top_modul:
            unique_out_wires = []
            [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
            return "".join([c.get_function_blif_flat() if c.disable_generation is False else
                           c.out.get_assign_blif(prefix=f"{unique_out_wires.pop(unique_out_wires.index(c.out.name+'_outid'+str(c.outid)))}", output=True) if f"{c.out.name+'_outid'+str(c.outid)}" in unique_out_wires else
                           "" for c in self.components])
        else:
            return "".join([c.get_function_blif_flat() for c in self.components])

    # HIERARCHICAL BLIF #
    # Subcomponent generation (3 inputs)
    def get_invocations_blif_hier(self):
        """Generates hierarchical Blif code with invocation of subcomponents function blocks.

        It is adapted for generation of general description of three input one bit circuits as well as their modified versions when some inputs are desired as constant values.
        In such cases the inner modul prototype is also modified accordingly. It is used for self three input one bit circuit hierarchical generation.

        Returns:
            str: Hierarchical Blif code containing invocation of inner subcomponents function blocks.
        """
        unique_out_wires = []
        [unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name, self.c.name] else unique_out_wires.append(o.name) for o in self.out.bus]
        return "".join([c.get_invocation_blif_hier() if c.disable_generation is False else
                       c.out.get_assign_blif(prefix=f"{unique_out_wires.pop(unique_out_wires.index(c.out.name+'_outid'+str(c.outid)))}", output=True) if f"{c.out.name+'_outid'+str(c.outid)}" in unique_out_wires else
                       "" for c in self.components])

    def get_invocation_blif_hier(self, *args, **kwargs):
        """Generates hierarchical Blif code invocation of corresponding three input one bit circuit's generated function block.

        Returns:
            str: Hierarchical Blif code subcomponent's model invocation.
        """
        circuit_block = self.__class__()
        return f".subckt {circuit_block.prefix} {circuit_block.a.prefix}={self.a.get_wire_value_blif()} {circuit_block.b.prefix}={self.b.get_wire_value_blif()} {circuit_block.c.prefix}={self.c.get_wire_value_blif()}{self.out.get_unique_assign_out_wires_blif(function_block_out_bus=circuit_block.out)}\n"

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
        return f"{{3,{self.out.N},1,{len(self.circuit_gates)},2,1,0}}"
