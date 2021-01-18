# KOMPONENTY PROPOJU


class wire():
    def __init__(self, name: str, value: int = 0, index: int = 0):
        self.name = name
        self.value = value
        self.index = index

    def get_declaration_c(self):
        return f"  uint8_t {self.name} = 0;\n"

    def get_wire_value_c(self, offset: int = 0):
        return f"(({self.name} >> {offset}) & 0x01)"

    def return_wire_value_c(self, offset: int = 0):
        return f"({self.name} & 0x01) << {offset}"


class bus():
    # Inicializace sbernice
    def __init__(self, prefix: str = "bus", N: int = 1):
        self.bus = [wire(name=prefix, index=i) for i in range(N)]
        self.prefix = prefix
        self.N = N

    def __index__(self, wire):
        return self.bus.index(wire)

    # Pripojeni vystupniho vodice vnitrni komponenty na vstup jine komponenty
    # (nebo drat vystupni sbernice obvodu)
    def connect(self, out_wire_index: int, inner_component_out_wire: wire):
        self.bus[out_wire_index] = inner_component_out_wire

    def get_wire_value_c(self, offset: int = 0):
        self.bus[offset].get_wire_value_c(offset)

    def return_wire_value_c(self, offset: int = 0):
        self.bus[offset].return_wire_value_c(offset)

    def get_declaration_c(self):
        if self.N > 8:
            return f"  uint64_t {self.prefix} = 0;\n"
        else:
            return f"  uint8_t {self.prefix} = 0;\n"

    def get_wire(self, wire_index: int):
        return self.bus[wire_index]
