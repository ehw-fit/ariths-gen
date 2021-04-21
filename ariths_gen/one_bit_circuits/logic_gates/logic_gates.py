from ariths_gen.core.logic_gate_circuits import TwoInputLogicGate, TwoInputInvertedLogicGate, OneInputLogicGate
from ariths_gen.wire_components import Wire, ConstantWireValue0, ConstantWireValue1


# Two-input #
class AndGate(TwoInputLogicGate):
    """Class representing two input AND gate.

    ```
        ┌──────┐
    ───►│  &   │
        │      ├─►
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of AND gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which AND gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0, parent_component: object = None):
        super().__init__(a, b, prefix, outid, parent_component)
        self.gate_type = "and_gate"
        self.cgp_function = 2
        self.operator = "&"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            self.out = b
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = ConstantWireValue0()
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            self.out = a
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            self.out = ConstantWireValue0()
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing AND gate Boolean function using its truth table.

        Returns:
            str: Blif description of AND gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"11 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"11 1\n"


class NandGate(TwoInputInvertedLogicGate):
    """Class representing two input NAND gate.

    ```
        ┌──────┐
    ───►│ &    │
        │      │O──►
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of NAND gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which NAND gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0, parent_component: object = None):
        super().__init__(a, b, prefix, outid, parent_component)
        self.gate_type = "nand_gate"
        self.cgp_function = 5
        self.operator = "&"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            output = NotGate(a=b, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = ConstantWireValue1()
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            output = NotGate(a=a, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            self.out = ConstantWireValue1()
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing NAND gate Boolean function using its truth table.

        Returns:
            str: Blif description of NAND gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"0- 1\n-0 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"0- 1\n-0 1\n"


class OrGate(TwoInputLogicGate):
    """Class representing two input OR gate.

    ```
        ┌──────┐
    ───►│ ≥1   │
        │      ├─►
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of OR gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which OR gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0, parent_component: object = None):
        super().__init__(a, b, prefix, outid, parent_component)
        self.gate_type = "or_gate"
        self.cgp_function = 3
        self.operator = "|"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            self.out = ConstantWireValue1()
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = b
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            self.out = ConstantWireValue1()
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            self.out = a
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing OR gate Boolean function using its truth table.

        Returns:
            str: Blif description of OR gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"1- 1\n-1 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"1- 1\n-1 1\n"


class NorGate(TwoInputInvertedLogicGate):
    """Class representing two input NOR gate.

    ```
        ┌──────┐
    ───►│ ≥1   │
        │      │O──►
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of NOR gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which NOR gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0, parent_component: object = None):
        super().__init__(a, b, prefix, outid, parent_component)
        self.gate_type = "nor_gate"
        self.cgp_function = 6
        self.operator = "|"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            self.out = ConstantWireValue0()
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            output = NotGate(a=b, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            self.out = ConstantWireValue0()
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            output = NotGate(a=a, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing NOR gate Boolean function using its truth table.

        Returns:
            str: Blif description of NOR gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"00 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"00 1\n"


class XorGate(TwoInputLogicGate):
    """Class representing two input XOR gate.

    ```
        ┌──────┐
    ───►│ =1   │
        │      ├─►
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of XOR gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which XOR gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0, parent_component: object = None):
        super().__init__(a, b, prefix, outid, parent_component)
        self.gate_type = "xor_gate"
        self.cgp_function = 4
        self.operator = "^"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            output = NotGate(a=b, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = b
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            output = NotGate(a=a, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            self.out = a
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing XOR gate Boolean function using its truth table.

        Returns:
            str: Blif description of XOR gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"01 1\n10 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"01 1\n10 1\n"


class XnorGate(TwoInputInvertedLogicGate):
    """Class representing two input XNOR gate.

    ```
        ┌──────┐
    ───►│ =1   │
        │      │O──►
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of XNOR gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which XNOR gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid:  int = 0, parent_component: object = None):
        super().__init__(a, b, prefix, outid, parent_component)
        self.gate_type = "xnor_gate"
        self.cgp_function = 7
        self.operator = "^"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            self.out = b
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            output = NotGate(a=b, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            self.out = a
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            output = NotGate(a=a, prefix=prefix, outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing XNOR gate Boolean function using its truth table.

        Returns:
            str: Blif description of XNOR gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"00 1\n11 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.b.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"00 1\n11 1\n"


# Single-input #
class NotGate(OneInputLogicGate):
    """Class representing one input NOT gate.

    ```
        ┌──────┐
        │  1   │
    ───►│      │O─►
        │      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): Input wire.
        prefix (str, optional): Prefix name of NOT gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
        parent_component (object, optional) Object of upper component of which NOT gate is a subcomponent. Defaults to None.
    """
    def __init__(self, a: Wire, prefix: str = "", outid: int = 0, parent_component: object = None):
        super().__init__(a, prefix, outid, parent_component)
        self.gate_type = "not_gate"
        self.cgp_function = 1
        self.operator = "~"

        # Logic gate output wire generation based on input values
        # If constant input is present, logic gate is not generated and corresponding
        # input value is propagated to the output to connect to other components
        if a.is_const() and a.value == 1:
            self.out = ConstantWireValue0()
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = ConstantWireValue1()
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)

    """ BLIF CODE GENERATION """
    def get_function_blif(self):
        """Generates Blif code representing NOT gate Boolean function using its truth table.

        Returns:
            str: Blif description of NOT gate's Boolean function.
        """
        if self.disable_generation:
            return f".names {self.a.get_wire_value_blif()} {self.out.name}_out\n" + \
                   f"0 1\n"
        else:
            return f".names {self.a.get_wire_value_blif()} {self.out.get_wire_value_blif()}\n" + \
                   f"0 1\n"
