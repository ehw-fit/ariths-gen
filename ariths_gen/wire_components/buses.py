from .wires import Wire


class Bus():
    """Class representing bus of wires used as inputs/outputs of bigger circuits.

    Description of the __init__ method.

    Args:
        prefix (str, optional): Prefix name of the bus. Defaults to "bus".
        N (int, optional): Number of wires in the bus. Defaults to 1.
        wires_list (list, optional): List of Wire objects used to clone one bus to another. Defaults to 0.
    """
    def __init__(self, prefix: str = "bus", N: int = 1, wires_list: list = None):
        if wires_list is None:
            self.bus = [Wire(name=prefix+"_"+str(i), index=i) for i in range(N)]
            self.prefix = prefix
            self.N = N
        else:
            self.bus = wires_list
            self.prefix = prefix
            self.N = len(self.bus)

    # Connecting output wire of the inner circuit component to the input of another component
    # (or to the wire of the circuit's output bus)
    def connect(self, bus_wire_index: int, inner_component_out_wire: Wire):
        """Connects given 'Wire' object to a 'bus_wire_index' within this bus.

        Args:
            bus_wire_index (int): Index in bus to store given wire in.
            inner_component_out_wire (Wire): Wire of some other component (mostly its output) to store in the bus.
        """
        self.bus[bus_wire_index] = inner_component_out_wire

    def get_wire(self, wire_index: int = 0):
        """Retrieves a wire from the bus by a given index.

        Args:
            wire_index (int, optional): Index of wire to retrieve from the bus. Defaults to 0.

        Returns:
            Wire: Return wire from the bus.
        """
        return self.bus[wire_index]

    def bus_extend(self, N: int, prefix: str = "bus"):
        """Provides bus extension to contain more wires.

        Args:
            N (int): Number of wires in the bus. Defaults to 1.
            prefix (str, optional): Prefix name of the bus. Defaults to "bus".
        """
        if self.N < N:
            self.bus += [Wire(name=prefix+"_"+str(i), index=i) for i in range(self.N, N)]
            self.N = N

    """ C CODE GENERATION """
    def get_declaration_c(self):
        """Bus declaration in C code.

        Returns:
            str: C code for declaration and initialization of bus name.
        """
        if self.N > 8:
            return f"  uint64_t {self.prefix} = 0;\n"
        else:
            return f"  uint8_t {self.prefix} = 0;\n"

    def get_wire_declaration_c(self):
        """Declare each wire from the bus independently.

        Returns:
            str: C code for declaration and initialization of bus wires.
        """
        return "".join([w.get_declaration_c() for w in self.bus])

    def get_wire_assign_c(self, bus_prefix: str = ""):
        """Assign all bits from the bus to each individual wires in C code.

        Args:
            bus_prefix (str, optional): Custom bus prefix to use for assignment. Defaults to "".

        Returns:
            str: C code for bus wires assignments.
        """
        bus_prefix = self.prefix if bus_prefix == "" else bus_prefix
        return "".join([w.get_assign_c(name=w.get_wire_value_c(name=bus_prefix, offset=self.bus.index(w))) for w in self.bus])

    def return_wire_value_c(self, offset: int = 0):
        """Retrieve wire value from desired index position in the bus.

        Args:
            offset (int, optional): Offset position of the wire to be retrieved. Defaults to 0.
        """
        self.get_wire(wire_index=offset).return_wire_value_c(offset=offset)

    """ VERILOG CODE GENERATION """
    def get_wire_declaration_v(self):
        """Declare each wire from the bus independently.

        Returns:
            str: Verilog code for declaration of bus wires.
        """
        return "".join([w.get_declaration_v() for w in self.bus])

    def get_wire_assign_v(self, bus_prefix: str = ""):
        """Assign all bits from the bus to each individual wires in Verilog code.

        Args:
            bus_prefix (str, optional): Custom bus prefix to use for assignment. Defaults to "".

        Returns:
            str: Verilog code for bus wires assignments.
        """
        bus_prefix = self.prefix if bus_prefix == "" else bus_prefix
        return "".join([w.get_assign_v(name=self.prefix, offset=self.bus.index(w), array=True) for w in self.bus])

    """ BLIF CODE GENERATION """
    def get_wire_declaration_blif(self, array: bool = True):
        """Declare each wire from the bus independently.

        Argument `array` specifies whether to declare wires from bus by their offset e.g. out[0]
        or by their wire name e.g. out_0.
        Args:
            array (bool, optional): Determines in which manner bus wire names are declared. Defaults to True.

        Returns:
            str: Blif code for declaration of bus wires.
        """
        return "".join([w.get_declaration_blif(name=self.prefix, offset=self.bus.index(w), array=array) for w in self.bus])

    def get_wire_assign_blif(self, output: bool = False):
        """Assign all bits from the bus as each individual wires in Blif code.

        Args:
            output (bool, optional): Specifies whether bus wires are used as outputs (assigned to) or as inputs (assigned from). Defaults to False.

        Returns:
            str: Blif code for bus wires assignments.
        """
        return "".join([w.get_assign_blif(name=self.prefix+f"[{self.bus.index(w)}]", output=output) for w in self.bus])
