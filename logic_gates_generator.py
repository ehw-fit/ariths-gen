from wire_components import wire


""" LOGIC GATE COMPONENTS """


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
        self.a.name = self.a.name.replace(self.prefix, "", 1)
        self.b.name = self.b.name.replace(self.prefix, "", 1)
        return f"uint8_t {self.prefix}_{self.gate_type}(uint8_t {self.a.name}, uint8_t {self.b.name})" + "{" + "\n"

    def get_function_c(self):
        return f"{self.a.get_wire_value_c()} {self.operator} {self.b.get_wire_value_c()}"

    def get_declaration_c_flat(self):
        return f"{self.a.get_declaration_c()}{self.b.get_declaration_c()}{self.output.get_declaration_c()}"

    def get_init_c_flat(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    # Generating flat C code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write("  return "+(self.get_function_c())+";\n}")
        file_object.close()

    # HIERARCHICAL C GENERATION #
    def get_function_block_c(self):
        self.a.name = "a"
        self.b.name = "b"
        return f"{self.get_prototype_c()}" + \
               f"  return "+(self.get_function_c())+";\n}\n\n"

    def get_invocation_c(self, a: wire, b: wire):
        return f"{self.gate_type}({a.name}, {b.name});"

    def get_gate_output_c(self, a: wire, b: wire, offset: int = 0):
        return f"({self.gate_type}({a.name}, {b.name}) & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        self.a.name = self.a.name.replace(self.prefix, "", 1)
        self.b.name = self.b.name.replace(self.prefix, "", 1)
        self.output.name = self.output.name.replace(self.prefix, "", 1)
        return f"module {self.prefix}_{self.gate_type}(input {self.a.name}, input {self.b.name}, output {self.output.name});\n"

    def get_declaration_v_flat(self):
        return f"{self.a.get_declaration_v()}{self.b.get_declaration_v()}{self.output.get_declaration_v()}"

    def get_function_v(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_init_v_flat(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    # Generating flat Verilog code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_v_code(self, file_object):
        file_object.write(self.get_prototype_v())
        file_object.write(f"  assign {self.output.name} = {self.get_function_v()};\n")
        file_object.write(f"endmodule")
        file_object.close()


# Single-input
class not_gate(logic_gate):
    def __init__(self, a: wire, prefix: str = "", outid: int = 0):
        self.gate_type = "not_gate"
        self.operator = "~"
        self.a = wire(name=prefix+"_"+a.name.replace(prefix+"_", ""), value=a.value)
        self.prefix = prefix

        if self.a.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    """ C CODE GENERATION """
    # FLAT C #
    def get_prototype_c(self):
        self.a.name = self.a.name.replace(self.prefix, "", 1)
        return f"uint8_t {self.prefix}_{self.gate_type}(uint8_t {self.a.name})" + "{" + "\n"

    def get_function_c(self):
        return f"{self.operator}{self.a.get_wire_value_c()} & 0x01 << 0"

    def get_declaration_c(self):
        return f"{self.a.get_declaration_c()}{self.output.get_declaration_c()}"

    def get_init_c_flat(self):
        return f"{self.operator}{self.a.name}"

    # HIERARCHICAL C #
    def get_function_block_c(self):
        self.a.name = "a"
        return f"{self.get_prototype_c()}" + \
               f"  return "+(self.get_function_c())+";\n}\n\n"

    def get_invocation_c(self, a: wire):
        return f"{self.gate_type}({a.name});"

    def get_gate_output_c(self, a: wire, offset: int = 0):
        return f"({self.gate_type}({a.name}) & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        self.a.name = self.a.name.replace(self.prefix, "", 1)
        self.output.name = self.output.name.replace(self.prefix, "", 1)
        return f"module {self.prefix}_{self.gate_type}(input {self.a.name}, output {self.output.name});\n"

    def get_declaration_v_flat(self):
        return f"{self.a.get_declaration_v()}{self.output.get_declaration_v()}"

    def get_function_v(self):
        # self.a.name = self.a.name.replace(self.prefix+"_", "")
        return f" {self.operator}{self.a.name}"

    def get_init_v_flat(self):
        return f"{self.a.name} {self.operator} {self.b.name}"


# Two-input
class and_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "and_gate"
        self.operator = "&"

        if a.value == 1 and b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)


class nand_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nand_gate"
        self.operator = "&"

        if (self.a.value == 1 and self.b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    """ C CODE GENERATION """
    def get_function_c(self):
        return "~("+(super().get_function_c())+f") & 0x01 << 0"

    """ VERILOG CODE GENERATION """
    def get_function_v(self):
        return "~("+(super().get_function_v())+f")"


class or_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "or_gate"
        self.operator = "|"

        if self.a.value == 1 or self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)


class nor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nor_gate"
        self.operator = "|"

        if self.a.value == 1 or self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    """ C CODE GENERATION """
    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"

    """ VERILOG CODE GENERATION """
    def get_function_v(self):
        return "~("+(super().get_function_v())+f")"


class xor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "xor_gate"
        self.operator = "^"

        if (a.value == 1 and b.value == 0) or (a.value == 0 and b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid), value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)


class xnor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid:  int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "xnor_gate"
        self.operator = "^"

        if (self.a.value == 1 and self.b.value == 0) or (self.a.value == 0 and self.b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    """ C CODE GENERATION """
    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"

    """ VERILOG CODE GENERATION """
    def get_function_v(self):
        return "~("+(super().get_function_v())+f")"
