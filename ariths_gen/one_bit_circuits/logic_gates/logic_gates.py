from ariths_gen.wire_components import Wire


# Two-input #
class LogicGate():
    """Class representing two input logic gates.

    ```
       ┌──────┐
    ──►│ FUNC │
       │      ├─►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "gate".
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "gate"):
        self.a = Wire(name=prefix+"_"+a.name.replace(prefix+"_", ""), value=a.value)
        self.b = Wire(name=prefix+"_"+b.name.replace(prefix+"_", ""), value=b.value)
        self.prefix = prefix

    """ C CODE GENERATION """
    # FLAT C #
    @staticmethod
    def get_includes_c():
        """Generates necessary C library includes for output representation.

        Returns:
            str: C code library includes.
        """
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        """Generates C code function header to describe corresponding two input logic gate's interface in C code.

        Returns:
            str: Function's name and parameters in C code.
        """
        return f"uint8_t {self.gate_type}(uint8_t {self.a.name}, uint8_t {self.b.name})" + "{" + "\n"

    def get_function_c(self):
        """Generates C code representing corresponding two input logic gate's Boolean function using bitwise operators between its bitwise shifted inputs.

        Returns:
            str: C code description of logic gate's Boolean function (with bitwise shifted inputs).
        """
        return f"{self.a.get_wire_value_c()} {self.operator} {self.b.get_wire_value_c()}"

    def get_declaration_c_flat(self):
        """Generates C code declaration of input/output wires.

        Returns:
            str: C code logic gate's wires declaration.
        """
        return f"{self.a.get_declaration_c()}{self.b.get_declaration_c()}{self.out.get_declaration_c()}"

    def get_init_c_flat(self):
        """Generates C code representing corresponding two input logic gate's Boolean function using bitwise operators between its inputs.

        Returns:
            str: C code description of logic gate's Boolean function.
        """
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_assign_c_flat(self):
        """Generates C code for assigning initial values into logic gate's wires.

        Returns:
            str: C code initialization of wires values.
        """
        return f"{self.a.get_assign_c(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.b.get_assign_c(name=self.b.name.replace(self.prefix+'_', ''))}" + \
               f"  {self.out.prefix} = {self.get_init_c_flat()};\n"

    # Generating flat C code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_c_code(self, file_object):
        """Generates flat C code representation of corresponding logic gate itself.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write("  return "+(self.get_function_c())+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_block_c(self):
        """Generates C code representation of corresponding logic gate used as function block in hierarchical circuit description.

        Returns:
            str: C code logic gate's function block description.
        """
        gate_block = NotGate(a=Wire(name="a")) if isinstance(self, NotGate) else type(self)(a=Wire(name="a"), b=Wire(name="b"))
        return f"{gate_block.get_prototype_c()}" + \
               f"  return "+(gate_block.get_function_c())+";\n}\n\n"

    def get_gate_invocation_c(self, remove_prefix: bool = True):
        """Generates C code invocation of corresponding logic gate's generated function block.

        Args:
            remove_prefix (bool, optional): Specifies whether function block's input parameter names should contain also its prefix (parent circuit name) or not. Defaults to True.

        Returns:
            str: C code logic gate's function block invocation.
        """
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        b_name = self.b.name.replace(self.prefix+"_", "") if remove_prefix is True else self.b.name
        return f"{self.gate_type}({a_name}, {b_name});\n"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        """Generates Verilog module header to describe corresponding two input logic gate's interface in Verilog.

        Returns:
            str: Module's name and parameters in Verilog.
        """
        return f"module {self.gate_type}(input {self.a.name}, input {self.b.name}, output {self.out.name});\n"

    def get_declaration_v_flat(self):
        """Generates Verilog code declaration of input/output wires.

        Returns:
            str: Verilog code logic gate's wires declaration.
        """
        return f"{self.a.get_declaration_v()}{self.b.get_declaration_v()}{self.out.get_declaration_v()}"

    def get_init_v_flat(self):
        """Generates Verilog code representing corresponding two input logic gate's Boolean function using bitwise operators between its inputs.

        Returns:
            str: Verilog description of logic gate's Boolean function.
        """
        return f"{self.a.name} {self.operator} {self.b.name}"

    def get_assign_v_flat(self):
        """Generates Verilog code for assigning initial values into logic gate's wires.

        Returns:
            str: Verilog code initialization of wires values.
        """
        return f"{self.a.get_assign_v(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.b.get_assign_v(name=self.b.name.replace(self.prefix+'_', ''))}" + \
               f"  assign {self.out.prefix} = {self.get_init_v_flat()};\n"

    # Generating flat Verilog code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_v_code(self, file_object):
        """Generates flat Verilog code representation of corresponding logic gate itself.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_v())
        file_object.write(f"  assign {self.out.name} = {self.get_init_v_flat()};\n")
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    def get_function_block_v(self):
        """Generates Verilog code representation of corresponding logic gate used as function block in hierarchical circuit description.

        Returns:
            str: Verilog logic gate's function block description.
        """
        gate_block = NotGate(a=Wire(name="a")) if isinstance(self, NotGate) else type(self)(a=Wire(name="a"), b=Wire(name="b"))
        return f"{gate_block.get_prototype_v()}" + \
               f"  assign {gate_block.out.name} = {gate_block.get_init_v_flat()};\n" + \
               f"endmodule\n\n"

    def get_gate_invocation_v(self, remove_prefix: bool = True):
        """Generates Verilog code invocation of corresponding logic gate's generated function block.

        Args:
            remove_prefix (bool, optional): Specifies whether function block's input parameter names contain also its prefix (parent circuit name) or not. Defaults to True.

        Returns:
            str: Verilog code logic gate's function block invocation.
        """
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        b_name = self.b.name.replace(self.prefix+"_", "") if remove_prefix is True else self.b.name
        return f"  {self.gate_type} {self.gate_type}_{self.out.name}({a_name}, {b_name}, {self.out.name});\n"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_prototype_blif(self):
        """Generates Blif model header to describe corresponding logic gate's interface in Blif.

        Returns:
            str: Model's name and parameters in Blif.
        """
        return f".model {self.gate_type}\n"

    def get_declaration_blif(self):
        """Generates Blif code declaration of input/output wires.

        Returns:
            str: Blif logic gate's wires declaration.
        """
        return f".inputs {self.a.name} {self.b.name}\n" + \
               f".outputs {self.out.name}\n"

    def get_init_function_blif_flat(self):
        """Generates Blif code representing corresponding two input logic gate's Boolean function between its inputs.

        Returns:
            str: Blif description of logic gate's Boolean function.
        """
        return f"{self.a.get_assign_blif(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.b.get_assign_blif(name=self.b.name.replace(self.prefix+'_', ''))}" + \
               f"{self.get_function_blif_flat()}"

    # Generating flat BLIF code representation of the logic gate itself
    # (i.e. not as a component of bigger circuit)
    def get_blif_code(self, file_object):
        """Generates flat Blif code representation of corresponding logic gate itself.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_blif())
        file_object.write(self.get_declaration_blif())
        file_object.write(self.get_function_blif_flat())
        file_object.write(f".end\n")
        file_object.close()

    # HIERARCHICAL BLIF #
    def get_function_block_blif(self):
        """Generates Blif code representation of corresponding logic gate used as subcomponent in hierarchical circuit description.

        Returns:
            str: Blif logic gate subcomponent description.
        """
        gate_block = NotGate(a=Wire(name="a")) if isinstance(self, NotGate) else type(self)(a=Wire(name="a"), b=Wire(name="b"))
        return f"{gate_block.get_prototype_blif()}" + \
               f"{gate_block.get_declaration_blif()}" + \
               f"{gate_block.get_function_blif_flat()}" + \
               f".end\n"

    def get_invocation_blif_hier(self, init: bool = False):
        """Generates Blif code invocation of corresponding logic gate's generated subcomponent.

        Args:
            init (bool, optional): Specifies whether subcomponent's input wires initializiation is neccessary before its invocation. Defaults to False.

        Returns:
            str: Blif logic gate subcomponent invocation.
        """
        if init is True:
            return f"{self.a.get_assign_blif(name=self.a.name.replace(self.prefix+'_', ''))}" + \
                   f"{self.b.get_assign_blif(name=self.b.name.replace(self.prefix+'_', ''))}" + \
                   f".subckt {self.gate_type} _a={self.a.name} _b={self.b.name} _y0={self.out.name}\n"
        else:
            return f".subckt {self.gate_type} _a={self.a.name} _b={self.b.name} _y0={self.out.name}\n"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    @staticmethod
    def get_parameters_cgp():
        """Generates CGP chromosome parameters of corresponding logic gate.
           In total seven parameters represent: total inputs, total outputs, number of rows, number of columns (gates),
           number of each gate's inputs, number of each gate's outputs, quality constant value.

        Returns:
            str: CGP chromosome parameters of described logic gate.
        """
        return "{2,1,1,1,2,1,0}"

    def get_triplet_cgp(self, a_index: int = 0, b_index: int = 1):
        """Generates logic gate triplet (2 input wires, logic gate function) using wires unique position indexes within the described circuit.
           Each triplet represents unique logic gate within the described circuit. Besides the contained input wires indexes and gate's inner logic function, an output wire
           with incremented index position is also created and remembered to be appropriately driven as an input to another logic gate or as the circuit's output.

        Args:
            a_index (int, optional): First input wire index position. Defaults to 0.
            b_index (int, optional): Second input wire index position. Defaults to 1.

        Returns:
            str: Triplet describing function of corresponding two input logic gate.
        """
        return f"({a_index},{b_index},{self.cgp_function})"

    @staticmethod
    def get_output_cgp(out_index: int = 2):
        """Generates list of output wires indexes of described two input logic gate from MSB to LSB.

        Args:
            out_index (int, optional): Output wire index. Defaults to 2.

        Returns:
            str: List of logic gate's output wire indexes.
        """
        return f"({out_index})"

    def get_cgp_code(self, file_object):
        """Generates flat CGP chromosome representation of corresponding logic gate itself.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_parameters_cgp())
        file_object.write(self.get_triplet_cgp())
        file_object.write(self.get_output_cgp())
        file_object.close()


class InvertedLogicGate(LogicGate):
    """Class representing two input inverted logic gates.

    ```
       ┌──────┐
    ──►│ FUNC │
       │      │O──►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "gate".
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "gate"):
        super().__init__(a, b, prefix)

    """ C CODE GENERATION """
    # FLAT C #
    def get_function_c(self):
        """Generates C code representing corresponding negated two input logic gate's Boolean function using bitwise operators between its bitwise shifted inputs.

        Returns:
            str: C code description of negated logic gate's Boolean function (with bitwise shifted inputs).
        """
        return "~("+(super().get_function_c())+") & 0x01 << 0"

    def get_init_c_flat(self):
        """Generates C code representing corresponding negated two input logic gate's Boolean function using bitwise operators between its inputs.

        Returns:
            str: C code description of negated logic gate's Boolean function.
        """
        return "~("+(super().get_init_c_flat())+")"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_init_v_flat(self):
        """Generates Verilog code representing corresponding negated two input logic gate's Boolean function using bitwise operators between its inputs.

        Returns:
            str: Verilog description of negated logic gate's Boolean function.
        """
        return "~("+(super().get_init_v_flat())+")"


class AndGate(LogicGate):
    """Class representing two input and gate.

    ```
       ┌──────┐
    ──►│  &   │
       │      ├─►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "and_gate"
        self.cgp_function = 2
        self.operator = "&"
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ BLIF CODE GENERATION """
    def get_function_blif_flat(self):
        """Generates Blif code representing AND gate Boolean function using its truth table.

        Returns:
            str: Blif description of AND gate's Boolean function.
        """
        return f".names {self.a.name} {self.b.name} {self.out.name}\n" + \
               f"11 1\n"


class NandGate(InvertedLogicGate):
    """Class representing two input nand gate.

    ```
       ┌──────┐
    ──►│ &    │
       │      │O──►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nand_gate"
        self.cgp_function = 5
        self.operator = "&"
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ BLIF CODE GENERATION """
    def get_function_blif_flat(self):
        """Generates Blif code representing NAND gate Boolean function using its truth table.

        Returns:
            str: Blif description of NAND gate's Boolean function.
        """
        return f".names {self.a.name} {self.b.name} {self.out.name}\n" + \
               f"0- 1\n-0 1\n"


class OrGate(LogicGate):
    """Class representing two input or gate.

    ```
       ┌──────┐
    ──►│ ≥1   │
       │      ├─►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "or_gate"
        self.cgp_function = 3
        self.operator = "|"
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ BLIF CODE GENERATION """
    def get_function_blif_flat(self):
        """Generates Blif code representing OR gate Boolean function using its truth table.

        Returns:
            str: Blif description of OR gate's Boolean function.
        """
        return f".names {self.a.name} {self.b.name} {self.out.name}\n" + \
               f"1- 1\n-1 1\n"


class NorGate(InvertedLogicGate):
    """Class representing two input nor gate.

    ```
       ┌──────┐
    ──►│ ≥1   │
       │      │O──►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "nor_gate"
        self.cgp_function = 6
        self.operator = "|"
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ BLIF CODE GENERATION """
    def get_function_blif_flat(self):
        """Generates Blif code representing NOR gate Boolean function using its truth table.

        Returns:
            str: Blif description of NOR gate's Boolean function.
        """
        return f".names {self.a.name} {self.b.name} {self.out.name}\n" + \
               f"00 1\n"


class XorGate(LogicGate):
    """Class representing two input xor gate.

    ```
       ┌──────┐
    ──►│ =1   │
       │      ├─►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid: int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "xor_gate"
        self.cgp_function = 4
        self.operator = "^"
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ BLIF CODE GENERATION """
    def get_function_blif_flat(self):
        """Generates Blif code representing XOR gate Boolean function using its truth table.

        Returns:
            str: Blif description of XOR gate's Boolean function.
        """
        return f".names {self.a.name} {self.b.name} {self.out.name}\n" + \
               f"01 1\n10 1\n"


class XnorGate(InvertedLogicGate):
    """Class representing two input xnor gate.

    ```
       ┌──────┐
    ──►│ =1   │
       │      │O──►
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): First input wire.
        b (Wire): Second input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, b: Wire, prefix: str = "", outid:  int = 0):
        super().__init__(a, b, prefix)
        self.gate_type = "xnor_gate"
        self.cgp_function = 7
        self.operator = "^"
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ BLIF CODE GENERATION """
    def get_function_blif_flat(self):
        """Generates Blif code representing XNOR gate Boolean function using its truth table.

        Returns:
            str: Blif description of XNOR gate's Boolean function.
        """
        return f".names {self.a.name} {self.b.name} {self.out.name}\n" + \
               f"00 1\n11 1\n"


# Single-input #
class NotGate(InvertedLogicGate):
    """Class representing one input not gate.

    ```
       ┌──────┐
       │  1   │
    ──►│      │O─►
       │      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire): Input wire.
        prefix (str, optional): Prefix name of logic gate. Defaults to "".
        outid (int, optional): Index of output wire. Defaults to 0.
    """
    def __init__(self, a: Wire, prefix: str = "", outid: int = 0):
        self.gate_type = "not_gate"
        self.cgp_function = 1
        self.operator = "~"
        self.a = Wire(name=prefix+"_"+a.name.replace(prefix+"_", ""), value=a.value)
        self.prefix = prefix
        self.out = Wire(name=prefix+"_y"+str(outid))

    """ C CODE GENERATION """
    # FLAT C #
    def get_prototype_c(self):
        """Generates C code function header to describe corresponding one input logic gate's interface in C code.

        Returns:
            str: Function's name and parameter in C code.
        """
        return f"uint8_t {self.gate_type}(uint8_t {self.a.name})" + "{" + "\n"

    def get_function_c(self):
        """Generates C code representing corresponding one input logic gate's Boolean function using bitwise operators between its bitwise shifted input.

        Returns:
            str: C code description of logic gate's Boolean function (with bitwise shifted input).
        """
        return f"{self.operator}{self.a.get_wire_value_c()} & 0x01 << 0"

    def get_declaration_c_flat(self):
        """Generates C code declaration of input/output wires.

        Returns:
            str: C code logic gate's wires declaration.
        """
        return f"{self.a.get_declaration_c()}{self.out.get_declaration_c()}"

    def get_init_c_flat(self):
        """Generates C code representing corresponding one input logic gate's Boolean function using bitwise operators between its input.

        Returns:
            str: C code description of logic gate's Boolean function.
        """
        return f"{self.operator}{self.a.name}"

    def get_assign_c_flat(self):
        """Generates C code for assigning initial values into logic gate's wires.

        Returns:
            str: C code initialization of wires values.
        """
        return f"{self.a.get_assign_c(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"  {self.out.prefix} = {self.get_init_c_flat()};\n"

    # HIERARCHICAL C #
    def get_gate_invocation_c(self, remove_prefix: bool = True):
        """Generates C code invocation of corresponding logic gate's generated function block.

        Args:
            remove_prefix (bool, optional): Specifies whether function block's input parameter name should contain also its prefix (parent circuit name) or not. Defaults to True.

        Returns:
            str: C code logic gate's function block invocation.
        """
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        return f"{self.gate_type}({a_name});"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        """Generates Verilog module header to describe corresponding one input logic gate's interface in Verilog.

        Returns:
            str: Module's name and parameter in Verilog.
        """
        return f"module {self.gate_type}(input {self.a.name}, output {self.out.name});\n"

    def get_declaration_v_flat(self):
        """Generates Verilog code declaration of input/output wires.

        Returns:
            str: Verilog code logic gate's wires declaration.
        """
        return f"{self.a.get_declaration_v()}{self.out.get_declaration_v()}"

    def get_init_v_flat(self):
        """Generates Verilog code representing corresponding one input logic gate's Boolean function using bitwise operators between its input.

        Returns:
            str: Verilog description of logic gate's Boolean function.
        """
        return f"{self.operator}{self.a.name}"

    def get_assign_v_flat(self):
        """Generates Verilog code for assigning initial values into logic gate's wires.

        Returns:
            str: Verilog code initialization of wires values.
        """
        return f"{self.a.get_assign_v(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"  assign {self.out.prefix} = {self.get_init_v_flat()};\n"

    # HIERARCHICAL VERILOG #
    def get_gate_invocation_v(self, remove_prefix: bool = True):
        """Generates Verilog code invocation of corresponding logic gate's generated function block.

        Args:
            remove_prefix (bool, optional): Specifies whether function block's input parameter name should contain also its prefix (parent circuit name) or not. Defaults to True.

        Returns:
            str: Verilog code logic gate's function block invocation.
        """
        a_name = self.a.name.replace(self.prefix+"_", "") if remove_prefix is True else self.a.name
        return f"  {self.gate_type} {self.gate_type}_{self.out.name}({a_name}, {self.out.name});\n"

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_declaration_blif(self):
        """Generates Blif model header to describe corresponding logic gate's interface in Blif.

        Returns:
            str: Model's name and parameter in Blif.
        """
        return f".inputs {self.a.name}\n" + \
               f".outputs {self.out.name}\n"

    def get_function_blif_flat(self):
        """Generates Blif code representing NOT gate Boolean function using its truth table.

        Returns:
            str: Blif description of NOT gate's Boolean function.
        """
        return f".names {self.a.name} {self.out.name}\n" + \
               f"0 1\n"

    def get_init_function_blif_flat(self):
        """Generates Blif code representing corresponding one input logic gate's Boolean function between its input.

        Returns:
            str: Blif description of logic gate's Boolean function.
        """
        return f"{self.a.get_assign_blif(name=self.a.name.replace(self.prefix+'_', ''))}" + \
               f"{self.get_function_blif_flat()}"

    # HIERARCHICAL BLIF #
    def get_invocation_blif_hier(self, init: bool = False):
        """Generates Blif code invocation of corresponding logic gate's generated subcomponent.

        Args:
            init (bool, optional): Specifies whether subcomponent's input wire initializiation is neccessary before its invocation. Defaults to False.

        Returns:
            str: Blif logic gate subcomponent invocation.
        """
        if init is True:
            return f"{self.a.get_assign_blif(name=self.a.name.replace(self.prefix+'_', ''))}" + \
                   f".subckt {self.gate_type} _a={self.a.name} _y0={self.out.name}\n"
        else:
            return f".subckt {self.gate_type} _a={self.a.name} _y0={self.out.name}\n"

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_triplet_cgp(self, a_index: int = 0):
        """Generates logic gate triplet (2 input wires, logic gate function) using wires unique position indexes within the described circuit.
           Each triplet represents unique logic gate within the described circuit. In this case of one input logic gate, the same input wire index is driven to both inputs.
           Besides the contained input wires indexes and gate's inner logic function, an output wire with incremented index position is also created and remembered to be
           appropriately driven as an input to another logic gate or as the circuit's output.

        Args:
            a_index (int, optional): First (used also as the second) input wire index position. Defaults to 0.

        Returns:
            str: Triplet describing function of corresponding one input logic gate.
        """
        return f"({a_index},{a_index},{self.cgp_function})"

    @staticmethod
    def get_output_cgp(out_index: int = 1):
        """Generates list of output wires indexes of described one input logic gate from MSB to LSB.

        Args:
            out_index (int, optional): Output wire index. Defaults to 1.

        Returns:
            str: List of logic gate's output wire indexes.
        """
        return f"({out_index})"
