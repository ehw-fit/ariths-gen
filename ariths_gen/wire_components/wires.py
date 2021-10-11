class Wire():
    """Class representing basic wire used to interconnect components.

    Description of the __init__ method.

    Args:
        name (str): Name of the wire.
        prefix (str, optional): Prefix of the wire. Defaultly the same as its name. Defaults to "".
        value (int, optional): Value the wire carries (0,1). Defaults to 0.
        index (int, optional): Index position of wire (mainly used for indexing within a bus). Defaults to 0.
        parent_bus (object, optional): Bus object of which a Wire is a part of (used mainly for proper generation of wire names). Defaults to None.
    """
    def __init__(self, name: str, prefix: str = "", value: int = 0, index: int = 0, parent_bus: object = None):
        self.name = name
        self.value = value
        self.index = index
        self.prefix = name if prefix == "" else prefix
        self.parent_bus = parent_bus

    @staticmethod
    def is_const():
        """Information whether wire carries constant value.

        Returns:
            bool: False, because basic wire doesn't represent a wire with constant value.
        """
        return False

    """ PYTHON CODE GENERATION """
    def return_wire_value_python_flat(self, offset: int = 0):
        """Retrieves desired bit value from wire represented in Python code variable (object) and bitwise shifts it to desired position for storing it within a bus for flat generation.

        Args:
            offset (int, optional): Used to shift wire value in order to be stored in proper location inside a bus. Defaults to 0.

        Returns:
            str: Python code bitwise shift for storing (constant/variable) wire value at desired offset position.
        """
        if self.is_const():
            return f"({self.c_const}) << {offset}\n"
        else:
            return f"(({self.name} >> 0) & 0x01) << {offset}\n"

    """ C CODE GENERATION """
    def get_declaration_c(self):
        """Wire declaration in C code.

        Returns:
            str: Empty string if C code wire is carrying constant value (constant value is used in situ) or returns C code for declaration and initialization of wire's name.
        """
        if self.is_const():
            return ""
        else:
            return f"  uint8_t {self.name} = {self.value};\n"

    def get_wire_value_c_flat(self):
        """Accesses desired bit value from wire represented in C code variable used for flat generation.

        Returns:
            str: C code bitwise shift to get desired bit value from this wire or wire variable's constant bit value 0/1.
        """
        if self.is_const():
            return f"({self.c_const})"
        else:
            # If wire is part of an input bus (where wire names are concatenated from bus prefix and their index position inside the bus in square brackets)
            # then the wire value is obtained from bitwise shifting the required wire from the parent bus ('parent_bus.prefix' is the same value as 'self.prefix')
            if self.name.endswith("["+str(self.index)+"]") and self.parent_bus is not None:
                return f"(({self.prefix} >> {self.index}) & 0x01)"
            else:
                return f"(({self.name} >> 0) & 0x01)"

    def get_wire_value_c_hier(self):
        """Accesses desired bit value from wire represented in C code variable used for hierarchical generation.

        Returns:
            str: C code bitwise shift to get desired bit value position from this wire or wire variable's constant bit value 0/1.
        """
        if self.is_const():
            return f"({self.c_const})"
        else:
            return f"(({self.prefix} >> {self.index}) & 0x01)"

    def return_wire_value_c_flat(self, offset: int = 0):
        """Retrieves desired bit value from wire represented in C code variable and bitwise shifts it to desired position for storing it within a bus for flat generation.

        Args:
            offset (int, optional): Used to shift wire value in order to be stored in proper location inside a bus. Defaults to 0.

        Returns:
            str: C code bitwise shift for storing (constant/variable) wire value at desired offset position.
        """
        if self.is_const():
            return f"({self.c_const}) << {offset};\n"
        else:
            return f"(({self.name} >> 0) & 0x01ull) << {offset};\n"

    def return_wire_value_c_hier(self, offset: int = 0):
        """Retrieves desired bit value from wire represented in C code variable and bitwise shifts it to desired position for storing it within a bus for hierarchical generation.

        Args:
            offset (int, optional): Used to shift wire value in order to be stored in proper location inside a bus. Defaults to 0.

        Returns:
            str: C code bitwise shift for storing (constant/variable) wire value at desired offset position.
        """
        if self.is_const():
            return f"({self.c_const}) << {offset};\n"
        else:
            return f"(({self.prefix} >> {self.index}) & 0x01ull) << {offset};\n"

    """ VERILOG CODE GENERATION """
    def get_declaration_v_flat(self):
        """Wire declaration for flat Verilog code.

        Returns:
            str: Empty string if Verilog code wire is carrying constant value (constant value is used in situ) or returns Verilog code for declaration and initialization of wire's name.
        """
        if self.is_const():
            return ""
        else:
            return f"  wire {self.name};\n"

    def get_declaration_v_hier(self):
        """Wire declaration for hierarchical Verilog code.

        Returns:
            str: Empty string if Verilog code wire is carrying constant value (constant value is used in situ) or returns Verilog code for declaration and initialization of wire's name.
        """
        if self.is_const():
            return ""
        else:
            return f"  wire [0:0] {self.name};\n"

    def get_wire_value_v_flat(self):
        """Accesses bit value from wire represented in Verilog code variable used for flat generation.

        Returns:
            str: Verilog code to get bit value from this wire or to get constant wire's bit value 0/1.
        """
        if self.is_const():
            return self.v_const
        else:
            return self.name

    def get_wire_value_v_hier(self):
        """Accesses bit value from wire represented in Verilog code variable used for hierarchical generation.

        Returns:
            str: Verilog code to get bit value from this wire or to get constant wire's bit value 0/1.
        """
        if self.is_const():
            return self.v_const
        else:
            return f"{self.prefix}[{self.index}]"

    def return_wire_value_v_flat(self):
        """Retrieves bit value from wire represented in Verilog code variable for storing it within a bus for flat generation.

        Returns:
            str: Verilog code for retrieving (constant/variable) wire value (and assign it at desired bus offset position).
        """
        if self.is_const():
            return f"{self.v_const};\n"
        else:
            return f"{self.name};\n"

    def return_wire_value_v_hier(self):
        """Retrieves bit value from bus's wires and stores them in bus's corresponding Verilog variable at proper offset bit position in the bus for hierarchical generation.

        Returns:
            str: Verilog code for retrieving (constant/variable) wire value used for assigning it into bus represented in Verilog code variable.
        """
        if self.is_const():
            return f"{self.v_const};\n"
        else:
            return f"{self.prefix}[{self.index}];\n"

    """ BLIF CODE GENERATION """
    def get_declaration_blif(self, prefix: str = "", offset: int = 0, array: bool = False):
        """Wire declaration in Blif code.

        Declares basic wire name if wire is not part of a bus
        or declares wire by an offset of its position within the bus.

        Args:
            prefix (str, optional): Bus prefix of which this wire is a part off. Defaults to "".
            offset (int, optional): Offset wire location within a bus. Defaults to 0.
            array (bool, optional): Tells whether a basic wire or a wire from within a bus is to be declared. Defaults to False.

        Returns:
            str: Blif code for declaration of a wire.
        """
        if array is True:
            return f"{prefix}[{offset}]"
        else:
            return f"{self.name}"

    def get_assign_blif(self, prefix: str, output: bool = False):
        """Assignment of wire value to another desired wire in Blif code.

        This wire's value is either assigned to desired output bus wire (represented by `prefix` name) when `output`=True.
        Otherwise the wire value at desired bus position (represented by `prefix` name) is assigned to this wire when `output`=False.

        Args:
            prefix (str): Name of the source/destination bus wire to be assigned from/to.
            output (bool, optional): Whether `prefix` represents the destination or the source wire in the assignment. Defaultly it symbolizes the source. Defaults to False.

        Returns:
            str: Blif code for assignment of one wire to another.
        """
        if output is True:
            if self.is_const():
                return f".names {self.blif_const} {prefix}\n" + \
                       f"1 1\n"
            else:
                return f".names {self.name} {prefix}\n" + \
                       f"1 1\n"
        else:
            if self.is_const():
                return "\n"
            else:
                return f".names {prefix} {self.name}\n" + \
                       f"1 1\n"

    def get_wire_value_blif(self):
        """Accesses bit value from wire represented in Blif code.

        Used for assignment of specific one bit circuit/gate values to their respective parameters
        in hierarchical Blif subcomponents generation.

        Returns:
            str: Blif code to get bit value from this wire or to get constant wire's bit value 0/1.
        """
        if self.is_const():
            return self.blif_const
        elif self.parent_bus is not None and self.parent_bus.N > 1:
            return self.name
        else:
            return self.prefix


# Wires with constant values #
class ConstantWireValue0(Wire):
    """Class representing wire carrying constant value 0 used to interconnect components.

    Description of the __init__ method.

    Method fills in desired constant wire's attributes regarding its values for individual representations.

    Args:
        name (str, optional): Custom constant wire name and prefix (used for generation of circuits that use constants as inputs). Defaults to "".
    """
    def __init__(self, name: str = ""):
        self.name = "constant_value_0" if name == "" else name
        self.prefix = "constant_value_0" if name == "" else name
        self.index = 0
        self.value = 0
        self.parent_bus = None

        self.c_const = "0x00"
        self.v_const = "1'b0"
        self.blif_const = "gnd"
        # Constant wire id for CGP generation
        self.cgp_const = 0

    @staticmethod
    def is_const():
        """Information whether wire carries constant value.

        Returns:
            bool: True, because constant wire carries a constant value 0.
        """
        return True


class ConstantWireValue1(Wire):
    """Class representing wire carrying constant value 1 used to interconnect components.

    Description of the __init__ method.

    Method fills in desired constant wire's attributes regarding its values for individual representations.

    Args:
        name (str, optional): Custom constant wire name and prefix (used for generation of circuits that use constants as inputs). Defaults to "".
    """
    def __init__(self, name: str = ""):
        self.name = "constant_value_1" if name == "" else name
        self.prefix = "constant_value_1" if name == "" else name
        self.index = 0
        self.value = 1
        self.parent_bus = None

        self.c_const = "0x01"
        self.v_const = "1'b1"
        self.blif_const = "vdd"
        # Constant wire id for CGP generation
        self.cgp_const = 1

    @staticmethod
    def is_const():
        """Information whether wire carries constant value.

        Returns:
            bool: True, because constant wire carries a constant value 1.
        """
        return True
