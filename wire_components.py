""" WIRE COMPONENTS """


class wire():
    def __init__(self, name: str, value: int = 0, index: int = 0):
        self.name = name
        if self.name.endswith("_"+str(index)):
            self.prefix = name[0:int(name.rfind(str(index))-1)]
        else:
            self.prefix = name
        self.value = value
        self.index = index

    # C CODE GENERATION #
    def get_declaration_c(self):
        return f"  uint8_t {self.name} = {self.value};\n"

    def get_wire_value_c(self, offset: int = 0, prefix: str = ""):
        name = self.name if prefix == "" else prefix
        return f"(({name} >> {offset}) & 0x01)"

    def return_wire_value_c(self, offset: int = 0):
        return f"({self.name} & 0x01) << {offset}"

    # VERILOG CODE GENERATION #
    def get_declaration_v(self):
        return f"  wire {self.name};\n"

    def get_declaration_init_v(self):
        return f"  wire {self.name} = {self.value};\n"

    def get_wire_value_v(self, offset: int = 0, prefix: str = "", array: bool = False):
        name = self.name if prefix == "" else prefix
        if array is True:
            return f"{name}[{offset}]"
        else:
            return f"{name}"

    def return_wire_value_v(self):
        return f"{self.name}"


class bus():
    def __init__(self, prefix: str, N: int = 1):
        self.bus = [wire(name=prefix+"_"+str(i), index=i) for i in range(N)]
        self.prefix = prefix
        self.N = N

    def __index__(self, wire):
        return self.bus.index(wire)

    # Connecting output wire of the inner circuit component to the input of another component
    # (or to the wire of the circuit's output bus)
    def connect(self, out_wire_index: int, inner_component_out_wire: wire):
        self.bus[out_wire_index] = inner_component_out_wire

    def get_wire(self, wire_index: int = 0):
        return self.bus[wire_index]

    def bus_extend(self, N: int, prefix: str = "bus"):
        self.bus = [wire(name=prefix+"_"+str(i), index=i) for i in range(N)]
        self.N = N

    # C CODE GENERATION #
    def get_wire_value_c(self, offset: int = 0, prefix: str = ""):
        return self.get_wire(wire_index=offset).get_wire_value_c(offset=offset, prefix=prefix)

    def get_wire_declaration_c(self):
        return "".join([w.get_declaration_c() for w in self.bus])

    def get_declaration_c(self):
        if self.N > 8:
            return f"  uint64_t {self.prefix} = 0;\n"
        else:
            return f"  uint8_t {self.prefix} = 0;\n"

    def return_wire_value_c(self, offset: int = 0):
        self.get_wire(wire_index=offset).return_wire_value_c(offset=offset)

    # VERILOG CODE GENERATION #
    def get_wire_value_v(self, offset: int = 0, prefix: str = "", array: bool = False):
        return self.get_wire(wire_index=offset).get_wire_value_v(offset=offset, prefix=prefix, array=array)

    def get_wire_declaration_v(self):
        return "".join([w.get_declaration_v() for w in self.bus])
