from wire_components import wire


# KOMPONENTY HRADEL
class logic_gate():
    def __init__(self, a: wire, b: wire, prefix: str = "w"):
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''), a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''), b.value)
        self.prefix = prefix

    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"uint8_t {self.gate_type}(uint8_t a, uint8_t b)" + "{" + '\n'

    def get_declaration_c(self):
        return f"{self.a.get_declaration_c()}{self.b.get_declaration_c()}{self.output.get_declaration_c()}"

    def get_initialization_c(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_function_c(self):
        self.a.name = self.a.name.replace(self.prefix+"_", '')
        self.b.name = self.b.name.replace(self.prefix+"_", '')
        return f"{self.a.get_wire_value_c()} {self.operator} {self.b.get_wire_value_c(0)}"

    # Generovani samostatneho obvodu logickeho hradla do jazyka C
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write("  return "+(self.get_function_c())+";\n}")
        file_object.close()


# Jednovstupa
class not_gate(logic_gate):
    def __init__(self, a: wire, prefix: str = "w", outid: int = 0):
        self.gate_type = 'not_gate'
        self.operator = '~'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''), a.value)
        self.prefix = prefix

        if self.a.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    def get_prototype_c(self):
        return f"uint8_t {self.gate_type}(uint8_t a)" + "{" + '\n'

    def get_declaration_c(self):
        return f"{self.a.get_declaration_c()}{self.output.get_declaration_c()}"

    def get_initialization_c(self):
        return f"{self.operator}{self.a.name}"

    def get_function_c(self):
        self.a.name = self.a.name.replace(self.prefix+"_", '')
        return f"{self.operator}{self.a.get_wire_value_c()} & 0x01 << 0"


# Dvouvstupa
class and_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "w", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = 'and_gate'
        self.operator = '&'

        if a.value == 1 and b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)


class nand_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "w", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = 'nand_gate'
        self.operator = '&'

        if (self.a.value == 1 and self.b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    def get_function_c(self):
        return "~("+(super().get_function_c())+f") & 0x01 << 0"


class or_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "w", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = 'or_gate'
        self.operator = '|'

        if self.a.value == 1 or self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)


class nor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "w", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = 'nor_gate'
        self.operator = '|'

        if self.a.value == 1 or self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"


class xor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "w", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = 'xor_gate'
        self.operator = '^'

        if (a.value == 1 and b.value == 0) or (a.value == 0 and b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid), value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=0)


class xnor_gate(logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "w", outid:  int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = 'xnor_gate'
        self.operator = '^'

        if (self.a.value == 1 and self.b.value == 0) or (self.a.value == 0 and self.b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid), value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid), value=1)

    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"
