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


class bus():
    def __init__(self, prefix: str, N: int = 1, wires_list: list = None):
        if wires_list is None:
            self.bus = [wire(name=prefix+"_"+str(i), index=i) for i in range(N)]
            self.prefix = prefix
            self.N = N
        else:
            self.bus = wires_list
            self.prefix = prefix
            self.N = len(self.bus)

    # Connecting output wire of the inner circuit component to the input of another component
    # (or to the wire of the circuit's output bus)
    def connect(self, out_wire_index: int, inner_component_out_wire: wire):
        self.bus[out_wire_index] = inner_component_out_wire

    def get_wire(self, wire_index: int = 0):
        return self.bus[wire_index]

    def bus_extend(self, N: int, prefix: str = "bus"):
        if self.N < N:
            self.bus += [wire(name=prefix+"_"+str(i), index=i) for i in range(self.N, N)]
            self.N = N

    """ C CODE GENERATION """
    def get_declaration_c(self):
        if self.N > 8:
            return f"  uint64_t {self.prefix} = 0;\n"
        else:
            return f"  uint8_t {self.prefix} = 0;\n"

    def get_wire_declaration_c(self):
        return "".join([w.get_declaration_c() for w in self.bus])

    def get_wire_assign_c(self, bus_prefix: str = ""):
        bus_prefix = self.prefix if bus_prefix == "" else bus_prefix
        return "".join([w.get_assign_c(name=w.get_wire_value_c(name=bus_prefix, offset=self.bus.index(w))) for w in self.bus])

    def return_wire_value_c(self, offset: int = 0):
        self.get_wire(wire_index=offset).return_wire_value_c(offset=offset)

    """ VERILOG CODE GENERATION """
    def get_wire_declaration_v(self):
        return "".join([w.get_declaration_v() for w in self.bus])

    def get_wire_assign_v(self, bus_prefix: str = ""):
        bus_prefix = self.prefix if bus_prefix == "" else bus_prefix
        return "".join([w.get_assign_v(name=self.prefix, offset=self.bus.index(w), array=True) for w in self.bus])

    """ BLIF CODE GENERATION """
    def get_wire_declaration_blif(self):
        return "".join([w.get_declaration_blif(name=self.prefix, offset=self.bus.index(w), array=True) for w in self.bus])

    def get_wire_assign_blif(self, output: bool = False):
        return "".join([w.get_assign_blif(name=self.prefix+f"[{self.bus.index(w)}]", output=output) for w in self.bus])
