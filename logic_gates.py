from wire_components import wire

""" LOGIC GATE COMPONENTS """


# Two-input #
class logic_gate():
    def __init__(self, a: wire, b: wire, prefix: str = "gate"):
        self.a = wire(name=prefix+"_"+a.name.replace(prefix+"_", ""), value=a.value)
        self.b = wire(name=prefix+"_"+b.name.replace(prefix+"_", ""), value=b.value)
        self.prefix = prefix

    def get_component_types(self):
        return list([self])

    """ C CODE GENERATION """
    # FLAT C #
    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"uint8_t {self.gate_type}(uint8_t {self.a.name}, uint8_t {self.b.name})" + "{" + "\n"

    def get_function_c(self):
        return f"{self.a.get_wire_value_c()} {self.operator} {self.b.get_wire_value_c()}"

    def get_declaration_c_flat(self):
        return f"{self.a.get_declaration_c()}{self.b.get_declaration_c()}{self.out.get_declaration_c()}"

    def get_init_c_flat(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_assign_c_flat(self, prefix_a: str = "a", prefix_b: str = "b", offset: int = 0):
        return f"  {self.a.name} = {self.a.get_wire_value_c(prefix=prefix_a, offset=offset)};\n" + \
               f"  {self.b.name} = {self.b.get_wire_value_c(prefix=prefix_b, offset=offset)};\n" + \
               f"  {self.out.prefix} = {self.a.name} {self.operator} {self.b.name};\n"

    # Generating flat C code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write("  return "+(self.get_function_c())+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_block_c(self):
        return f"{self.get_prototype_c()}" + \
               f"  return "+(self.get_function_c())+";\n}\n\n"

    def get_gate_invocation_c(self, a: wire, b: wire, sign: bool = False, get_index: bool = False):
        a_name = a.prefix if sign is False else a.name
        b_name = b.prefix if sign is False else b.name
        a_name = a_name if get_index is False else "a" + a.name[a.name.rfind("_"):]
        b_name = b_name if get_index is False else "b" + b.name[b.name.rfind("_"):]
        return f"{self.gate_type}({a_name}, {b_name});"

    def get_gate_output_c(self, a: wire, b: wire, offset: int = 0, sign: bool = False):
        a_name = a.prefix if sign is False else a.name
        b_name = b.prefix if sign is False else b.name
        return f"({self.gate_type}({a_name}, {b_name}) & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.gate_type}(input {self.a.name}, input {self.b.name}, output {self.out.name});\n"

    def get_declaration_v_flat(self):
        return f"{self.a.get_declaration_v()}{self.b.get_declaration_v()}{self.out.get_declaration_v()}"

    def get_init_v_flat(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_assign_v_flat(self, prefix_a: str = "a", prefix_b: str = "b", offset: int = 0, array: bool = False):
        return f"  assign {self.a.name} = {self.a.get_wire_value_v(prefix=prefix_a, offset=offset, array=array)};\n" + \
               f"  assign {self.b.name} = {self.b.get_wire_value_v(prefix=prefix_b, offset=offset, array=array)};\n" + \
               f"  assign {self.out.prefix} = {self.a.name} {self.operator} {self.b.name};"

    # Generating flat Verilog code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_v_code(self, file_object):
        file_object.write(self.get_prototype_v())
        file_object.write(f"  assign {self.out.name} = {self.get_init_v_flat()};\n")
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    def get_function_block_v(self):
        return f"{self.get_prototype_v()}" + \
               f"  assign {self.out.name} = {self.get_init_v_flat()};\n" + \
               f"endmodule\n\n"

    def get_gate_invocation_v(self, a: wire, b: wire, out: wire, sign: bool = False, get_index: bool = False, out_array: bool = False, offset: int = 0):
        a_name = a.prefix if sign is False else a.name
        b_name = b.prefix if sign is False else b.name
        a_name = a_name if get_index is False else "a" + a.name[a.name.rfind("_"):]
        b_name = b_name if get_index is False else "b" + b.name[b.name.rfind("_"):]
        return f"  {self.gate_type} {self.gate_type}_{out.name}({a_name}, {b_name}, {out.get_wire_value_v(offset=offset, array=out_array)});"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    @staticmethod
    def get_parameters_cgp():
        return "{1,1,2,1,0}"

    def get_triplet_cgp(self, a_index: int = 0, b_index: int = 1):
        return f"({a_index},{b_index},{self.cgp_function})"

    @staticmethod
    def get_output_cgp(out_index: int = 2):
        return f"({out_index})"

    def get_cgp_code(self, file_object):
        file_object.write(self.get_parameters_cgp())
        file_object.write(self.get_triplet_cgp())
        file_object.write(self.get_output_cgp())
        file_object.close()


class inverted_logic_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "gate"):
        super().__init__(a, b, prefix)

    """ C CODE GENERATION """
    # FLAT C #
    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_init_v_flat(self):
        return "~("+(super().get_init_v_flat())+")"


class and_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "and_gate"
        self.cgp_function = 2
        self.operator = "&"
        self.out = wire(name=prefix+"_y"+str(outid))

    """ C CODE GENERATION """
    # FLAT C #
    def get_assign_c_flat(self, prefix_a: str = "a", prefix_b: str = "b"):
        indexes = self.prefix[self.prefix.rfind("_", 0, self.prefix.rfind("_"))+1:]
        offset_a = indexes[:indexes.rfind("_")]
        offset_b = indexes[indexes.rfind("_")+1:]
        return f"  {self.a.name} = {self.a.get_wire_value_c(prefix=prefix_a, offset=offset_a)};\n" + \
               f"  {self.b.name} = {self.b.get_wire_value_c(prefix=prefix_b, offset=offset_b)};\n" + \
               f"  {self.out.prefix} = {self.a.name} {self.operator} {self.b.name};\n"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_assign_v_flat(self, prefix_a: str = "a", prefix_b: str = "b", offset: int = 0, array: bool = False):
        indexes = self.prefix[self.prefix.rfind("_", 0, self.prefix.rfind("_"))+1:]
        offset_a = indexes[:indexes.rfind("_")]
        offset_b = indexes[indexes.rfind("_")+1:]
        return f"  assign {self.a.name} = {self.a.get_wire_value_v(prefix=prefix_a, offset=offset_a, array=array)};\n" + \
               f"  assign {self.b.name} = {self.b.get_wire_value_v(prefix=prefix_b, offset=offset_b, array=array)};\n" + \
               f"  assign {self.out.prefix} = {self.a.name} {self.operator} {self.b.name};"


class nand_gate(inverted_logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nand_gate"
        self.cgp_function = 5
        self.operator = "&"
        self.out = wire(name=prefix+"_y"+str(outid))

    """ C CODE GENERATION """
    # FLAT C #
    def get_assign_c_flat(self, prefix_a: str = "a", prefix_b: str = "b"):
        indexes = self.prefix[self.prefix.rfind("_", 0, self.prefix.rfind("_"))+1:]
        offset_a = indexes[:indexes.rfind("_")]
        offset_b = indexes[indexes.rfind("_")+1:]
        return f"  {self.a.name} = {self.a.get_wire_value_c(prefix=prefix_a, offset=offset_a)};\n" + \
               f"  {self.b.name} = {self.b.get_wire_value_c(prefix=prefix_b, offset=offset_b)};\n" + \
               f"  {self.out.prefix} = ~({self.a.name} {self.operator} {self.b.name});\n"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_assign_v_flat(self, prefix_a: str = "a", prefix_b: str = "b", offset: int = 0, array: bool = False):
        indexes = self.prefix[self.prefix.rfind("_", 0, self.prefix.rfind("_"))+1:]
        offset_a = indexes[:indexes.rfind("_")]
        offset_b = indexes[indexes.rfind("_")+1:]
        return f"  assign {self.a.name} = {self.a.get_wire_value_v(prefix=prefix_a, offset=offset_a, array=array)};\n" + \
               f"  assign {self.b.name} = {self.b.get_wire_value_v(prefix=prefix_b, offset=offset_b, array=array)};\n" + \
               f"  assign {self.out.prefix} = ~({self.a.name} {self.operator} {self.b.name});"


class or_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "or_gate"
        self.cgp_function = 3
        self.operator = "|"
        self.out = wire(name=prefix+"_y"+str(outid))


class nor_gate(inverted_logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nor_gate"
        self.cgp_function = 6
        self.operator = "|"
        self.out = wire(name=prefix+"_y"+str(outid))


class xor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "xor_gate"
        self.cgp_function = 4
        self.operator = "^"
        self.out = wire(name=prefix+"_y"+str(outid))


class xnor_gate(inverted_logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid:  int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "xnor_gate"
        self.cgp_function = 7
        self.operator = "^"
        self.out = wire(name=prefix+"_y"+str(outid))


# Single-input #
class not_gate(inverted_logic_gate):
    def __init__(self, a: wire, prefix: str = "", outid: int = 0):
        self.gate_type = "not_gate"
        self.cgp_function = 1
        self.operator = "~"
        self.a = wire(name=prefix+"_"+a.name.replace(prefix+"_", ""), value=a.value)
        self.prefix = prefix
        self.out = wire(name=prefix+"_y"+str(outid))

    """ C CODE GENERATION """
    # FLAT C #
    def get_prototype_c(self):
        return f"uint8_t {self.gate_type}(uint8_t {self.a.name})" + "{" + "\n"

    def get_function_c(self):
        return f"{self.operator}{self.a.get_wire_value_c()} & 0x01 << 0"

    def get_declaration_c(self):
        return f"{self.a.get_declaration_c()}{self.out.get_declaration_c()}"

    def get_init_c_flat(self):
        return f"{self.operator}{self.a.name}"

    def get_assign_c_flat(self, prefix_a: str = "a", offset: int = 0):
        return f"  {self.a.name} = {self.a.get_wire_value_c(prefix=prefix_a, offset=offset)};\n" + \
               f"  {self.out.prefix} = {self.operator}{self.a.name};\n"

    # HIERARCHICAL C #
    def get_gate_invocation_c(self, a: wire, sign: bool = False, get_index: bool = False):
        a_name = a.prefix if sign is False else a.name
        a_name = a_name if get_index is False else "a" + a.name[a.name.rfind("_"):]
        return f"{self.gate_type}({a_name});"

    def get_gate_output_c(self, a: wire, offset: int = 0, sign: bool = False):
        a_name = a.prefix if sign is False else a.name
        return f"({self.gate_type}({a_name}) & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.gate_type}(input {self.a.name}, output {self.out.name});\n"

    def get_declaration_v_flat(self):
        return f"{self.a.get_declaration_v()}{self.out.get_declaration_v()}"

    def get_init_v_flat(self):
        return f"{self.operator}{self.a.name}"

    def get_assign_v_flat(self, prefix_a: str = "a", offset: int = 0, array: bool = False):
        return f"  assign {self.a.name} = {self.a.get_wire_value_v(prefix=prefix_a, offset=offset, array=array)};\n" + \
               f"  assign {self.out.prefix} = {self.operator}{self.a.name};"

    # HIERARCHICAL VERILOG #
    def get_gate_invocation_v(self, a: wire, out: wire, sign: bool = False, get_index: bool = False, out_array: bool = False, offset: int = 0):
        a_name = a.prefix if sign is False else a.name
        a_name = a_name if get_index is False else "a" + a.name[a.name.rfind("_"):]
        return f"  {self.gate_type} {self.gate_type}_{out.name}({a_name}, {out.get_wire_value_v(offset=offset, array=out_array)});"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    @staticmethod
    def get_parameters_cgp():
        return "{1,1,1,1,0}"

    def get_triplet_cgp(self, a_index: int = 0):
        return f"({a_index},{self.cgp_function})"

    @staticmethod
    def get_output_cgp(out_index: int = 1):
        return f"({out_index})"
