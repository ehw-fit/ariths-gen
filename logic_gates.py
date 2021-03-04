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

    def get_assign_c_flat(self):
        return f"{self.a.get_assign_c(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.b.get_assign_c(name=self.b.name.replace(self.prefix+'_', ''))}" + \
               f"  {self.out.prefix} = {self.get_init_c_flat()};\n"

    # Generating flat C code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write("  return "+(self.get_function_c())+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_block_c(self):
        gate_block = not_gate(a=wire(name="a")) if isinstance(self, not_gate) else type(self)(a=wire(name="a"), b=wire(name="b"))
        return f"{gate_block.get_prototype_c()}" + \
               f"  return "+(gate_block.get_function_c())+";\n}\n\n"

    def get_gate_invocation_c(self, remove_prefix: bool = True):
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        b_name = self.b.name.replace(self.prefix+"_", "") if remove_prefix is True else self.b.name
        return f"{self.gate_type}({a_name}, {b_name});\n"

    def get_gate_output_c(self, a: wire, b: wire, offset: int = 0):
        return f"({self.gate_type}({a.name}, {b.name}) & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.gate_type}(input {self.a.name}, input {self.b.name}, output {self.out.name});\n"

    def get_declaration_v_flat(self):
        return f"{self.a.get_declaration_v()}{self.b.get_declaration_v()}{self.out.get_declaration_v()}"

    def get_init_v_flat(self):
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_assign_v_flat(self):
        return f"{self.a.get_assign_v(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.b.get_assign_v(name=self.b.name.replace(self.prefix+'_', ''))}" + \
               f"  assign {self.out.prefix} = {self.get_init_v_flat()};\n"

    # Generating flat Verilog code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_v_code(self, file_object):
        file_object.write(self.get_prototype_v())
        file_object.write(f"  assign {self.out.name} = {self.get_init_v_flat()};\n")
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    def get_function_block_v(self):
        gate_block = not_gate(a=wire(name="a")) if isinstance(self, not_gate) else type(self)(a=wire(name="a"), b=wire(name="b"))
        return f"{gate_block.get_prototype_v()}" + \
               f"  assign {gate_block.out.name} = {gate_block.get_init_v_flat()};\n" + \
               f"endmodule\n\n"

    def get_gate_invocation_v(self, remove_prefix: bool = True):
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        b_name = self.b.name.replace(self.prefix+"_", "") if remove_prefix is True else self.b.name
        return f"  {self.gate_type} {self.gate_type}_{self.out.name}({a_name}, {b_name}, {self.out.name});\n"

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

    def get_init_c_flat(self):
        return "~("+(super().get_init_c_flat())+")"

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


class nand_gate(inverted_logic_gate):
    def __init__(self, a: wire, b: wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nand_gate"
        self.cgp_function = 5
        self.operator = "&"
        self.out = wire(name=prefix+"_y"+str(outid))


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

    def get_declaration_c_flat(self):
        return f"{self.a.get_declaration_c()}{self.out.get_declaration_c()}"

    def get_init_c_flat(self):
        return f"{self.operator}{self.a.name}"

    def get_assign_c_flat(self):
        return f"{self.a.get_assign_c(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"  {self.out.prefix} = {self.get_init_c_flat()};\n"

    # HIERARCHICAL C #
    def get_gate_invocation_c(self, remove_prefix: bool = True):
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        return f"{self.gate_type}({a_name});"

    def get_gate_output_c(self, a: wire, offset: int = 0):
        return f"({self.gate_type}({a.name}) & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.gate_type}(input {self.a.name}, output {self.out.name});\n"

    def get_declaration_v_flat(self):
        return f"{self.a.get_declaration_v()}{self.out.get_declaration_v()}"

    def get_init_v_flat(self):
        return f"{self.operator}{self.a.name}"

    def get_assign_v_flat(self):
        return f"{self.a.get_assign_v(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"  assign {self.out.prefix} = {self.get_init_v_flat()};\n"

    # HIERARCHICAL VERILOG #
    def get_gate_invocation_v(self, remove_prefix: bool = True):
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        return f"  {self.gate_type} {self.gate_type}_{self.out.name}({a_name}, {self.out.name});\n"

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
