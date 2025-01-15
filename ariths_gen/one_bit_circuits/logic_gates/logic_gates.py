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
        
    def get_cnf_clause(self, parent):
        """Generates CNF clause representing AND gate Boolean function using its truth table."""


        x = parent.get_cnfvar(self.a)
        y = parent.get_cnfvar(self.b)

        if x == -y: # a AND ~a
            z = parent.get_cnfvar(ConstantWireValue0())
            parent.set_cnfvar(self.out, z)
            return []

        if x == y: # a AND a
            parent.set_cnfvar(self.out, x)
            return []

        z = parent.get_cnfvar(self.out, create = True)
    
        return [[x,-z],[y,-z],[-x,-y,z]]


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
            assert self.parent_component, "Parent component for gate {self} is not defined"
            output = NotGate(a=b, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = ConstantWireValue1()
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            assert self.parent_component, "Parent component for gate {self} is not defined"
            output = NotGate(a=a, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
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

    def get_cnf_clause(self, parent):
        """Generates CNF clause representing AND gate Boolean function using its truth table."""


        x = parent.get_cnfvar(self.a)
        y = parent.get_cnfvar(self.b)

        if x == -y: # a NAND ~a
            z = parent.get_cnfvar(ConstantWireValue1())
            parent.set_cnfvar(self.out, z)
            return []

        if x == y: # a AND a
            parent.set_cnfvar(self.out, -x)
            return []

        z = parent.get_cnfvar(self.out, create = True)
    
        return [[x,z],[y,z],[-x,-y,-z]]

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

    def get_cnf_clause(self, parent):
        """Generates CNF clause representing AND gate Boolean function using its truth table."""


        x = parent.get_cnfvar(self.a)
        y = parent.get_cnfvar(self.b)

        if x == -y: # a OR ~a
            z = parent.get_cnfvar(ConstantWireValue1())
            parent.set_cnfvar(self.out, z)
            return []

        if x == y: # a OR a
            parent.set_cnfvar(self.out, x)
            return []

        z = parent.get_cnfvar(self.out, create = True)
    
        return [[-x,z],[-y,z],[x,y,-z]]

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
            assert self.parent_component, "Parent component for gate {self} is not defined"
            output = NotGate(a=b, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            self.out = ConstantWireValue0()
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            assert self.parent_component, "Parent component for gate {self} is not defined"
            output = NotGate(a=a, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
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

    def get_cnf_clause(self, parent):
        """Generates CNF clause representing AND gate Boolean function using its truth table."""


        x = parent.get_cnfvar(self.a)
        y = parent.get_cnfvar(self.b)

        if x == -y: # a NOR ~a
            z = parent.get_cnfvar(ConstantWireValue0())
            parent.set_cnfvar(self.out, z)
            return []

        if x == y: # a NOR a
            parent.set_cnfvar(self.out, -x)
            return []

        z = parent.get_cnfvar(self.out, create = True)
    
        return [[-x,-z],[-y,-z],[x,y,z]]

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
            assert self.parent_component, f"Parent component for gate {self} is not defined"
            output = NotGate(a=b, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif a.is_const() and a.value == 0:
            self.out = b
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            assert self.parent_component, f"Parent component for gate {self} is not defined"
            output = NotGate(a=a, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            self.out = a
            self.disable_generation = True
        else:
            self.out = Wire(name=prefix)
            
    def get_cnf_clause(self, parent):
        z = parent.get_cnfvar(self.out, create = True)
        x = parent.get_cnfvar(self.a)
        y = parent.get_cnfvar(self.b)

        if x == -y: # a XOR ~a
            z = parent.get_cnfvar(ConstantWireValue1())
            parent.set_cnfvar(self.out, z)
            return []

        if x == y: # a XOR a
            z = parent.get_cnfvar(ConstantWireValue0())
            parent.set_cnfvar(self.out, z)
            return []

        return [[ -x, y, z], [x,-y,z], [x,y,-z], [-x,-y,-z]]


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
            assert self.parent_component, "Parent component for gate {self} is not defined"
            output = NotGate(a=b, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
            self.parent_component.add_component(output) if parent_component is not None else None
            self.out = output.out
            self.disable_generation = True
        elif b.is_const() and b.value == 1:
            self.out = a
            self.disable_generation = True
        elif b.is_const() and b.value == 0:
            assert self.parent_component, "Parent component for gate {self} is not defined"
            output = NotGate(a=a, prefix=prefix + "_not", outid=outid, parent_component=parent_component)
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

    def get_cnf_clause(self, parent):
        z = parent.get_cnfvar(self.out, create = True)
        x = parent.get_cnfvar(self.a)
        y = parent.get_cnfvar(self.b)

        if x == -y: # a XNOR ~a
            z = parent.get_cnfvar(ConstantWireValue0())
            parent.set_cnfvar(self.out, z)
            return []
            
        if x == y: # a XNOR a
            z = parent.get_cnfvar(ConstantWireValue1())
            parent.set_cnfvar(self.out, z)
            return []

        return [[ -x, y, -z], [x,-y,-z], [x,y,z], [-x,-y,z]]


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

    def get_cnf_clause(self, parent):
        x = parent.get_cnfvar(self.a)
        parent.set_cnfvar(self.out, -x)
        return []
