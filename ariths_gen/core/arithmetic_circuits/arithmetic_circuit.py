from ariths_gen.core.logic_gate_circuits.logic_gate_circuit import OneInputLogicGate, TwoInputLogicGate

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits.general_circuit import GeneralCircuit


class ArithmeticCircuit(GeneralCircuit):
    """Class represents a general arithmetic circuit and ensures its generation to various representations.

    The __init__ method fills some mandatory attributes concerning arithmetic circuit
    that are later used for generation into various representations.
    """

    def __init__(self, a, b, prefix: str, name: str, out_N: int, inner_component: bool = False, one_bit_circuit: bool = False, signed: bool = False, **kwargs):
        super().__init__(prefix, name, out_N, inner_component, inputs=[a, b], signed=signed, **kwargs)
        if one_bit_circuit is False:
            if prefix == "":
                self.prefix = name
            else:
                self.prefix = prefix + "_" + name

            self.inner_component = inner_component
            if self.inner_component is True:
                self.a = Bus(prefix=f"{self.prefix}_{a.prefix}", wires_list=a.bus)
                self.b = Bus(prefix=f"{self.prefix}_{b.prefix}", wires_list=b.bus)

                if a.is_output_bus():
                    self.a.connect_bus(connecting_bus=a)
                if b.is_output_bus():
                    self.b.connect_bus(connecting_bus=b)
            else:
                self.a = Bus(prefix=f"{a.prefix}", wires_list=a.bus)
                self.b = Bus(prefix=f"{b.prefix}", wires_list=b.bus)

    """ C CODE GENERATION """
    def get_prototype_c(self):
        """Generates C code function header to describe corresponding arithmetic circuit's interface in C code.

        Returns:
            str: Function's name and parameters in C code.
        """
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + "\n"

    """ VERILOG CODE GENERATION """
    def get_prototype_v(self):
        """Generates Verilog code module header to describe corresponding arithmetic circuit's interface in Verilog code.

        Returns:
            str: Module's name and parameters in Verilog code.
        """
        return f"module {self.prefix}(input [{self.N-1}:0] {self.a.prefix}, input [{self.N-1}:0] {self.b.prefix}, output [{self.out.N-1}:0] {self.out.prefix});\n"

    """ BLIF CODE GENERATION """
    def get_declaration_blif(self):
        """Generates flat Blif code declaration of input/output circuit wires.

        Returns:
            str: Flat Blif code containing declaration of circuit's wires.
        """
        if self.N == 1:
            return f".inputs {self.a.prefix} {self.b.prefix}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f".names vdd\n1\n" + \
                   f".names gnd\n0\n"
        else:
            return f".inputs{self.a.get_wire_declaration_blif()}{self.b.get_wire_declaration_blif()}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f".names vdd\n1\n" + \
                   f".names gnd\n0\n"


class ThreeInputArithmeticCircuit(GeneralCircuit):
    """Class represents a general three input arithmetic circuit and ensures its generation to various representations.

    The __init__ method fills some mandatory attributes concerning arithmetic circuit
    that are later used for generation into various representations.
    """

    def __init__(self, a, b, c, prefix: str, name: str, out_N: int, inner_component: bool = False, one_bit_circuit: bool = False, signed: bool = False, **kwargs):
        super().__init__(prefix, name, out_N, inner_component, inputs=[a, b, c], signed=signed, **kwargs)
        if one_bit_circuit is False:
            if prefix == "":
                self.prefix = name
            else:
                self.prefix = prefix + "_" + name

            self.inner_component = inner_component
            if self.inner_component is True:
                self.a = Bus(prefix=f"{self.prefix}_{a.prefix}", wires_list=a.bus)
                self.b = Bus(prefix=f"{self.prefix}_{b.prefix}", wires_list=b.bus)
                self.c = Bus(prefix=f"{self.prefix}_{c.prefix}", wires_list=c.bus)

                if a.is_output_bus():
                    self.a.connect_bus(connecting_bus=a)
                if b.is_output_bus():
                    self.b.connect_bus(connecting_bus=b)
                if c.is_output_bus():
                    self.c.connect_bus(connecting_bus=c)
            else:
                self.a = Bus(prefix=f"{a.prefix}", wires_list=a.bus)
                self.b = Bus(prefix=f"{b.prefix}", wires_list=b.bus)
                self.c = Bus(prefix=f"{c.prefix}", wires_list=c.bus)

    """ C CODE GENERATION """
    def get_prototype_c(self):
        """Generates C code function header to describe corresponding arithmetic circuit's interface in C code.

        Returns:
            str: Function's name and parameters in C code.
        """
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix}, {self.c_data_type} {self.c.prefix})" + "{" + "\n"

    def get_function_block_c(self):
        """Generates hierarchical C code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical C code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(
            a=Bus("a"), b=Bus("b"), c=Bus("c")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), c=Bus(
            N=self.N, prefix="c"), name=circuit_prefix, **self._parent_kwargs)
        return f"{circuit_block.get_circuit_c()}\n\n"

    def get_declaration_c_hier(self):
        """Generates hierarchical C code declaration of corresponding subcomponent input/output wires inside the upper component.

        Generates wires used to connect input/output values to/from invocation of the corresponding function block into inner wires present
        inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code of subcomponent arithmetic circuit's wires declaration.
        """
        return f"  {self.c_data_type} {self.a.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.b.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.c.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.out.prefix} = 0;\n"

    def get_out_invocation_c(self):
        """Generates hierarchical C code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code of subcomponent's C function invocation and output assignment.
        """
        # Getting name of circuit type for proper C code generation without affecting actual generated composition
        circuit_type = self.__class__(a=Bus("a"), b=Bus("b"), c=Bus("c")).prefix + str(self.N)
        return self.a.return_bus_wires_values_c_hier() + self.b.return_bus_wires_values_c_hier() + self.c.return_bus_wires_values_c_hier() + \
            f"  {self.out.prefix} = {circuit_type}({self.a.prefix}, {self.b.prefix}, {self.c.prefix});\n"

    """ VERILOG CODE GENERATION """
    def get_prototype_v(self):
        """Generates Verilog code module header to describe corresponding arithmetic circuit's interface in Verilog code.

        Returns:
            str: Module's name and parameters in Verilog code.
        """
        return f"module {self.prefix}(input [{self.N-1}:0] {self.a.prefix}, input [{self.N-1}:0] {self.b.prefix}, input [{self.N-1}:0] {self.c.prefix}, output [{self.out.N-1}:0] {self.out.prefix});\n"

    def get_function_block_v(self):
        """Generates hierarchical Verilog code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Verilog code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(
            a=Bus("a"), b=Bus("b"), c=Bus("c")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), c=Bus(N=self.N, prefix="c"), name=circuit_prefix, **self._parent_kwargs)
        return f"{circuit_block.get_circuit_v()}\n\n"

    def get_declaration_v_hier(self):
        """Generates hierarchical Verilog code declaration of corresponding subcomponent input/output wires inside the upper component.

        Generates wires used to connect input/output values to/from invocation of the corresponding function block into inner wires present
        inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent arithmetic circuit's wires declaration.
        """
        return f"  wire [{self.a.N-1}:0] {self.a.prefix};\n" + \
               f"  wire [{self.b.N-1}:0] {self.b.prefix};\n" + \
               f"  wire [{self.c.N-1}:0] {self.c.prefix};\n" + \
               f"  wire [{self.out.N-1}:0] {self.out.prefix};\n"

    def get_out_invocation_v(self):
        """Generates hierarchical Verilog code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent's module invocation and output assignment.
        """
        # Getting name of circuit type and insitu copying out bus for proper Verilog code generation without affecting actual generated composition
        circuit_type = self.__class__(a=Bus("a"), b=Bus("b"), c=Bus("c")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), c=Bus(
            N=self.N, prefix="c"), name=circuit_type)
        return self.a.return_bus_wires_values_v_hier() + self.b.return_bus_wires_values_v_hier() + self.c.return_bus_wires_values_v_hier() + \
            f"  {circuit_type} {circuit_type}_{self.out.prefix}(.{circuit_block.a.prefix}({self.a.prefix}), .{circuit_block.b.prefix}({self.b.prefix}), .{circuit_block.c.prefix}({self.c.prefix}), .{circuit_block.out.prefix}({self.out.prefix}));\n"

    """ BLIF CODE GENERATION """
    def get_declaration_blif(self):
        """Generates flat Blif code declaration of input/output circuit wires.

        Returns:
            str: Flat Blif code containing declaration of circuit's wires.
        """
        if self.N == 1:
            return f".inputs {self.a.prefix} {self.b.prefix} {self.c.prefix}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f".names vdd\n1\n" + \
                   f".names gnd\n0\n"
        else:
            return f".inputs{self.a.get_wire_declaration_blif()}{self.b.get_wire_declaration_blif()}{self.c.get_wire_declaration_blif()}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f".names vdd\n1\n" + \
                   f".names gnd\n0\n"

    def get_invocation_blif_hier(self):
        """Generates hierarchical Blif code invocation of corresponding arithmetic circuit's generated function block.

        Used for multi-bit subcomponent's modul invocation.

        Returns:
            str: Hierarchical Blif code of subcomponent's model invocation and output assignment.
        """
        # Getting name of circuit type for proper Blif code generation without affecting actual generated composition
        circuit_type = self.__class__(a=Bus("a"), b=Bus("b"), c=Bus("c")).prefix + str(self.N)
        return f"{self.a.get_wire_assign_blif(output=True)}" + \
               f"{self.b.get_wire_assign_blif(output=True)}" + \
               f"{self.c.get_wire_assign_blif(output=True)}" + \
               f".subckt {circuit_type}" + \
               "".join([f" a[{self.a.bus.index(w)}]={self.a.prefix}[{self.a.bus.index(w)}]" for w in self.a.bus]) + \
               "".join([f" b[{self.b.bus.index(w)}]={self.b.prefix}[{self.b.bus.index(w)}]" for w in self.b.bus]) + \
               "".join([f" c[{self.c.bus.index(w)}]={self.c.prefix}[{self.c.bus.index(w)}]" for w in self.c.bus]) + \
               "".join(
                   [f" {circuit_type}_out[{self.out.bus.index(o)}]={o.name}" for o in self.out.bus]) + "\n"

    def get_function_block_blif(self):
        """Generates hierarchical Blif code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Blif code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(
            a=Bus("a"), b=Bus("b"), c=Bus("c")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), c=Bus(N=self.N, prefix="c"), name=circuit_prefix, **self._parent_kwargs)
        return f"{circuit_block.get_circuit_blif()}"
