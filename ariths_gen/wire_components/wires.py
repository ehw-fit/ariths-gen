class Wire():
    def __init__(self, name: str, value: int = 0, index: int = 0):
        self.name = name
        if self.name.endswith("_"+str(index)):
            self.prefix = name[0:int(name.rfind(str(index))-1)]
        else:
            self.prefix = name
        self.value = value
        self.index = index

    """ C CODE GENERATION """
    def get_declaration_c(self):
        return f"  uint8_t {self.name} = {self.value};\n"

    def get_wire_value_c(self, name: str = "", offset: int = 0):
        w_name = self.name if name == "" else name
        return f"(({w_name} >> {offset}) & 0x01)"

    def get_assign_c(self, name: str):
        return f"  {self.name} = {name};\n"

    def return_wire_value_c(self, offset: int = 0):
        return f"({self.name} & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    def get_declaration_v(self):
        return f"  wire {self.name};\n"

    def get_assign_v(self, name: str, offset: int = 0, array: bool = False):
        if array is True:
            return f"  assign {self.name} = {name}[{offset}];\n"
        else:
            return f"  assign {self.name} = {name};\n"

    """ BLIF CODE GENERATION """
    def get_declaration_blif(self, name: str = "", offset: int = 0, array: bool = False):
        if array is True:
            return f" {name}[{offset}]"
        else:
            return f" {self.name}"

    def get_assign_blif(self, name: str, output: bool = False):
        if output is True:
            return f".names {self.name} {name}\n" + \
                   f"1 1\n"
        else:
            return f".names {name} {self.name}\n" + \
                   f"1 1\n"