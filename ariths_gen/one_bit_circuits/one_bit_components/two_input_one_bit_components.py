from ariths_gen.core import TwoInputOneBitCircuit
from ariths_gen.one_bit_circuits.logic_gates import LogicGate, AndGate, NandGate, OrGate, NorGate, XorGate, XnorGate, NotGate
from ariths_gen.wire_components import Wire, Bus


class HalfAdder(TwoInputOneBitCircuit):
    """Class representing two input one bit half adder.

    ```
       ┌──────┐
    ──►│      ├─► Sum
       │      │
    ──►│      ├─► Cout
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of full adder. Defaults to "ha".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 2 wires for component's bus output (sum, cout)
        self.out = Bus("out", self.N+1)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor = XorGate(a, b, prefix=self.prefix, outid=0)
        self.add_component(obj_xor)
        self.out.connect(0, obj_xor.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and = AndGate(a, b, prefix=self.prefix, outid=1)
        self.add_component(obj_and)
        self.out.connect(1, obj_and.out)


class PGLogicBlock(TwoInputOneBitCircuit):
    """Class representing two input one bit propagate/generate logic block.

    ```
       ┌──────┐
    ──►│      ├─► P
       │      │
    ──►│      ├─► G
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of full adder. Defaults to "pg_logic".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "pg_logic"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 3 wires for component's bus output (propagate, generate, sum)
        self.out = Bus("out", self.N+2)

        # PG logic
        propagate_or = OrGate(a, b, prefix=self.prefix, outid=0)
        self.add_component(propagate_or)
        generate_and = AndGate(a, b, prefix=self.prefix, outid=1)
        self.add_component(generate_and)
        sum_xor = XorGate(a, b, prefix=self.prefix, outid=2)
        self.add_component(sum_xor)

        self.out.connect(0, propagate_or.out)
        self.out.connect(1, generate_and.out)
        self.out.connect(2, sum_xor.out)

    def get_propagate_wire(self):
        return self.out.get_wire(0)

    def get_generate_wire(self):
        return self.out.get_wire(1)

    def get_sum_wire(self):
        return self.out.get_wire(2)


class ConstantWireValue0(TwoInputOneBitCircuit):
    """Class representing two input one bit constant wire with value 0 generation block.

    ```
       ┌──────┐
    ──►│      │
       │      ├─►0
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of full adder. Defaults to "constant_wire_value_0".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "constant_wire_value_0"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 1 wire for component's bus output (constant wire)
        self.out = Bus("out", self.N)

        # Generation of wire with constant value 0
        obj_xor = XorGate(self.a, self.b, prefix=self.prefix, outid=0)
        obj_xnor = XnorGate(self.a, self.b, prefix=self.prefix, outid=1)
        obj_nor = NorGate(obj_xor.out, obj_xnor.out, prefix=self.prefix, outid=2)
        obj_nor.out.name = "constant_wire_0"
        obj_nor.out.prefix = "constant_wire_0"

        self.add_component(obj_xor)
        self.add_component(obj_xnor)
        self.add_component(obj_nor)

        # Constant wire output
        self.out.connect(0, obj_nor.out)


class ConstantWireValue1(TwoInputOneBitCircuit):
    """Class representing two input one bit constant wire with value 1 generation block.

    ```
       ┌──────┐
    ──►│      │
       │      ├─►1
    ──►│      │
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of full adder. Defaults to "constant_wire_value_1".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "constant_wire_value_1"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 1 wire for component's bus output (constant wire)
        self.out = Bus("out", self.N)

        # Generation of wire with constant value 1
        obj_xor = XorGate(self.a, self.b, prefix=self.prefix, outid=0)
        obj_xnor = XnorGate(self.a, self.b, prefix=self.prefix, outid=1)
        obj_or = OrGate(obj_xor.out, obj_xnor.out, prefix=self.prefix, outid=2)
        obj_or.out.name = "constant_wire_1"
        obj_or.out.prefix = "constant_wire_1"
        self.add_component(obj_xor)
        self.add_component(obj_xnor)
        self.add_component(obj_or)

        # Constant wire output
        self.out.connect(0, obj_or.out)
