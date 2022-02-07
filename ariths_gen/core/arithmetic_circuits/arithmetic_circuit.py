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

            # N output wires for given circuit
            self.out = Bus(self.prefix+"_out", out_N, out_bus=True, signed=self.signed)

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
