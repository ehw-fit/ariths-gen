class Wire():
    """Class representing basic wire used to interconnect components.

    Description of the __init__ method.

    Args:
        name (str): Name of the wire.
        value (int, optional): Value it carries (0,1). Defaults to 0.
        index (int, optional): Index position of wire (mainly used for indexing within a bus). Defaults to 0.
    """

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
        """Wire declaration in C code.

        Returns:
            str: C code for declaration and initialization of wire's name.
        """
        return f"  uint8_t {self.name} = {self.value};\n"

    def get_wire_value_c(self, name: str = "", offset: int = 0):
        """Access desired bit from wire represented in C code variable.

        Args:
            name (str, optional): Name representing a wire. Defaults to "".
            offset (int, optional): Access desired wire bit from C code variable (used to access wire bits from buses). Defaults to 0.

        Returns:
            str: C code bitwise shift to get bit from `offset` position in `w_name`.
        """
        w_name = self.name if name == "" else name
        return f"(({w_name} >> {offset}) & 0x01)"

    def get_assign_c(self, name: str):
        """Assign (connect) the value of wire to another wire.

        Args:
            name (str): Name of wire to assign value from.

        Returns:
            str: C code for assignment of one wire to another.
        """
        return f"  {self.name} = {name};\n"

    def return_wire_value_c(self, offset: int = 0):
        """Retrieve bit value from wire and shift it to desired position for storing it within a bus.

        Args:
            offset (int, optional): Used to shift wire value in order to be stored in proper location in bus. Defaults to 0.

        Returns:
            str: C code bitwise shift of retrieved wire value.
        """
        return f"({self.name} & 0x01) << {offset}"

    """ VERILOG CODE GENERATION """
    def get_declaration_v(self):
        """Wire declaration in Verilog code.

        Returns:
            str: Verilog code for declaration of wire's name.
        """
        return f"  wire {self.name};\n"

    def get_assign_v(self, name: str, offset: int = 0, array: bool = False):
        """Assignment of wire value to another desired wire in Verilog.

        Args:
            name (str): Name of wire/bus to assign value from.
            offset (int, optional): Used to retrieve desired wire from a bus. Defaults to 0.
            array (bool, optional): Tells whether wire value is assigned from within a bus or from basic wire. Defaults to False.

        Returns:
            str: Verilog code for wire assignment.
        """
        if array is True:
            return f"  assign {self.name} = {name}[{offset}];\n"
        else:
            return f"  assign {self.name} = {name};\n"

    """ BLIF CODE GENERATION """
    def get_declaration_blif(self, name: str = "", offset: int = 0, array: bool = False):
        """Wire declaration in Blif code.

        Declares basic wire name if wire is not a part of a bus,
        or declares wire by an offset of its position within the input bus.

        Args:
            name (str, optional): Name of a bus to be declared (if array is True). Defaults to "".
            offset (int, optional): Offset wire location within a bus. Defaults to 0.
            array (bool, optional): Tells whether a basic wire or a wire from within a bus is to be declared. Defaults to False.

        Returns:
            str: Blif code for declaration of a wire.
        """
        if array is True:
            return f" {name}[{offset}]"
        else:
            return f" {self.name}"

    def get_assign_blif(self, name: str, output: bool = False):
        """Assignment of wire value to another desired wire in Blif.

        Args:
            name (str): Name of the source/destination wire to be assigned to.
            output (bool, optional): Whether 'name' represents the destination or the source wire in the assignment. Defaults to False.

        Returns:
            str: Blif code for assignment of one wire to another.
        """
        if output is True:
            return f".names {self.name} {name}\n" + \
                   f"1 1\n"
        else:
            return f".names {name} {self.name}\n" + \
                   f"1 1\n"
