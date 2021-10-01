from ariths_gen.core.logic_gate_circuits.logic_gate_circuit import OneInputLogicGate, TwoInputLogicGate

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits.general_circuit import GeneralCircuit


class ArithmeticCircuit(GeneralCircuit):
    """Class represents a general arithmetic circuit and ensures their generation to various representations.

    The __init__ method fills some mandatory attributes concerning arithmetic circuit
    that are later used for generation into various representations.
    """

    def __init__(self, a, b, prefix: str, name: str, out_N: int, inner_component: bool = False, one_bit_circuit: bool = False):

        super().__init__(prefix, name, out_N, inner_component, inputs=[a, b])
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

            # N output wires for given circuit
            self.out = Bus(self.prefix+"_out", out_N, out_bus=True)

    """ C CODE GENERATION """
    def get_prototype_c(self):
        """Generates C code function header to describe corresponding arithmetic circuit's interface in C code.

        Returns:
            str: Function's name and parameters in C code.
        """
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + "\n"

    def get_function_block_c(self):
        """Generates hierarchical C code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical C code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(
            a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), name=circuit_prefix)
        return f"{circuit_block.get_circuit_c()}\n\n"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #

    def get_prototype_v(self):
        """Generates Verilog code module header to describe corresponding arithmetic circuit's interface in Verilog code.

        Returns:
            str: Module's name and parameters in Verilog code.
        """
        return f"module {self.prefix}(input [{self.N-1}:0] {self.a.prefix}, input [{self.N-1}:0] {self.b.prefix}, output [{self.out.N-1}:0] {self.out.prefix});\n"
    # HIERARCHICAL VERILOG #
    def get_function_block_v(self):
        """Generates hierarchical Verilog code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Verilog code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(
            a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), name=circuit_prefix)
        return f"{circuit_block.get_circuit_v()}\n\n"
    def get_out_invocation_v(self, circuit_prefix: str):
        """Generates hierarchical Verilog code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent's module invocation and output assignment.
        """
        # Getting name of circuit type and insitu copying out bus for proper Verilog code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")

        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(
            a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"), name=circuit_prefix)
        return self.a.return_bus_wires_values_v_hier() + self.b.return_bus_wires_values_v_hier() + \
            f"  {circuit_type} {circuit_type}_{self.out.prefix}(.{circuit_block.a.prefix}({self.a.prefix}), .{circuit_block.b.prefix}({self.b.prefix}), .{circuit_block.out.prefix}({self.out.prefix}));\n"

    def get_function_block_blif(self):
        """Generates hierarchical Blif code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Blif code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(
            N=self.N, prefix="b"))
        return f"{circuit_block.get_circuit_blif()}"
