from ariths_gen.wire_components.wires import ConstantWireValue0
from ariths_gen.core.one_bit_circuits import FourInputOneBitCircuit
from ariths_gen.one_bit_circuits.logic_gates import AndGate, NandGate, OrGate, NorGate, XorGate, XnorGate, NotGate
from ariths_gen.wire_components import Wire, Bus


class BlackCell(FourInputOneBitCircuit):
    """Class representing four input black cell used in parallel prefix adders inside the PG (parallel prefix computation) logic.

    Black cell is based on a notation used in the book CMOS VLSI Design (please refer to the book for more details not deducible from the code itself).
    ```
        ┌──────┐
    ───►│      ├─► Generate
    ───►│      │
    ───►│      │
    ───►│      ├─► Propagate
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire, represents generate signal from the current stage. Defaults to Wire(name="g1").
        b (Wire, optional): Second input wire, represents propagate signal from the current stage. Defaults to Wire(name="p1").
        c (Wire, optional): Third input wire, represents generate signal from a preceding stage. Defaults to Wire(name="g0").
        d (Wire, optional): Fourth input wire, represents propagate signal from a preceding stage. Defaults to Wire(name="p0").
        prefix (str, optional): Prefix name of grey cell. Defaults to "".
        name (str, optional): Name of grey cell. Defaults to "gc".
    """
    def __init__(self, a: Wire = Wire(name="g1"), b: Wire = Wire(name="p1"), c: Wire = Wire(name="g0"), d: Wire = Wire(name="p0"), prefix: str = "", name: str = "bc"):
        super().__init__(a, b, c, d, prefix=prefix, name=name)
        # 2 wires for component's bus output (generate, propagate)
        self.out = Bus(self.prefix+"_out", 2)

        # Create/propagate the generate signal
        self.add_component(AndGate(a=self.b, b=self.c, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self))
        self.add_component(OrGate(a=self.a, b=self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), parent_component=self))
        # Connection of the generate output wire
        self.out.connect(0, self.get_previous_component().out)

        # Create/propagate the propagate signal
        self.add_component(AndGate(a=self.b, b=self.d, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self))
        # Connection of the propagate output wire
        self.out.connect(1, self.get_previous_component().out)

    def get_generate_wire(self):
        """Get output wire carrying generate signal value.

        Returns:
           Wire: Return generate wire.
        """
        return self.out.get_wire(0)

    def get_propagate_wire(self):
        """Get output wire carrying propagate signal value.

        Returns:
           Wire: Return propagate wire.
        """
        return self.out.get_wire(1)
