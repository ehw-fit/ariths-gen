from ariths_gen.core import ThreeInputOneBitCircuit
from ariths_gen.one_bit_circuits.logic_gates import LogicGate, AndGate, NandGate, OrGate, NorGate, XorGate, XnorGate, NotGate
from ariths_gen.wire_components import Wire, Bus


class FullAdder(ThreeInputOneBitCircuit):
    """Class representing three input one bit full adder.

    ```
       ┌──────┐
    ──►│      ├─► Sum
    ──►│      │
    ──►│      ├─► Cout
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Carry input wire. Defaults to Wire(name="cin").
        prefix (str, optional): Prefix name of full adder. Defaults to "fa".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "fa"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 2 wires for component's bus output (sum, cout)
        self.out = Bus("out", self.N+1)

        # PG logic
        propagate_xor = XorGate(a, b, prefix=self.prefix, outid=0)
        self.add_component(propagate_xor)
        generate_and = AndGate(a, b, prefix=self.prefix, outid=1)
        self.add_component(generate_and)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor = XorGate(propagate_xor.out, c, prefix=self.prefix, outid=2)
        self.add_component(obj_xor)
        self.out.connect(0, obj_xor.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and = AndGate(propagate_xor.out, c, prefix=self.prefix, outid=3)
        self.add_component(obj_and)

        obj_or = OrGate(generate_and.out, obj_and.out, prefix=self.prefix, outid=4)
        self.add_component(obj_or)

        self.out.connect(1, obj_or.out)


class FullAdderPG(ThreeInputOneBitCircuit):
    """Class representing modified three input one bit full adder with propagate/generate logic.

    ```
       ┌──────┐
    ──►│      ├─► P
    ──►│      ├─► G
    ──►│      ├─► Sum
       └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Carry input wire. Defaults to Wire(name="cin").
        prefix (str, optional): Prefix name of full adder. Defaults to "fa_cla".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "fa_cla"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 3 wires for component's bus output (sum, propagate, generate)
        self.out = Bus("out", self.N+2)

        # PG logic
        propagate_xor = XorGate(a, b, prefix=self.prefix, outid=0)
        self.add_component(propagate_xor)
        self.out.connect(0, propagate_xor.out)

        generate_and = AndGate(a, b, prefix=self.prefix, outid=1)
        self.add_component(generate_and)
        self.out.connect(1, generate_and.out)

        # Sum output
        sum_xor = XorGate(propagate_xor.out, c, prefix=self.prefix, outid=2)
        self.add_component(sum_xor)
        self.out.connect(2, sum_xor.out)

    def get_propagate_wire(self):
        return self.out.get_wire(0)

    def get_generate_wire(self):
        return self.out.get_wire(1)

    def get_sum_wire(self):
        return self.out.get_wire(2)
