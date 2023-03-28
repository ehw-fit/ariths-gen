from ariths_gen.wire_components.wires import ConstantWireValue0
from ariths_gen.core.one_bit_circuits import ThreeInputOneBitCircuit
from ariths_gen.one_bit_circuits.logic_gates import AndGate, NandGate, OrGate, NorGate, XorGate, XnorGate, NotGate
from ariths_gen.wire_components import Wire, Bus


class FullAdder(ThreeInputOneBitCircuit):
    """Class representing three input one bit full adder.

    ```
        ┌──────┐
    ───►│      ├─► Sum
    ───►│      │
    ───►│      ├─► Cout
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Carry input wire. Defaults to Wire(name="cin").
        prefix (str, optional): Prefix name of full adder. Defaults to "fa".
    """
    use_verilog_instance = False

    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "fa"):
        super().__init__(a, b, c, prefix)
        # 2 wires for component's bus output (sum, cout)
        self.out = Bus(self.prefix+"_out", 2)

        # PG logic
        propagate_xor = XorGate(a, b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(propagate_xor)
        generate_and = AndGate(a, b, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
        self.add_component(generate_and)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor = XorGate(propagate_xor.out, c, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=0, parent_component=self)
        self.add_component(obj_xor)
        self.out.connect(0, obj_xor.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and = AndGate(propagate_xor.out, c, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
        self.add_component(obj_and)

        obj_or = OrGate(generate_and.out, obj_and.out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), outid=1, parent_component=self)
        self.add_component(obj_or)

        self.out.connect(1, obj_or.out)

    def get_sum_wire(self):
        """Get output wire carrying sum value.

        Returns:
           Wire: Return sum wire.
        """
        return self.out.get_wire(0)

    def get_carry_wire(self):
        """Get output wire carrying carry out value.

        Returns:
           Wire: Return carry out wire.
        """
        return self.out.get_wire(1)

    def get_init_v_flat(self):
        """ support of custom PDK """
        if not self.use_verilog_instance:
            return super().get_init_v_flat()

        return "  " + self.use_verilog_instance.format(
            **{
                "unit": self.prefix,
                "wirea": f"1'b{self.a.value}" if self.a.is_const() else self.a.name,
                "wireb": f"1'b{self.b.value}" if self.b.is_const() else self.b.name,
                "wirec": f"1'b{self.c.value}" if self.c.is_const() else self.c.name,
                "wireys": self.get_sum_wire().prefix,
                "wireyc": self.get_carry_wire().prefix,
            }) + ";\n"

    def get_self_init_v_hier(self):
        """ support of custom PDK """
        if not self.use_verilog_instance:
            return super().get_self_init_v_hier()

        unique_out_wires = []
        for o in self.out.bus:
            unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name] else unique_out_wires.append(o.name)

        return "  " + self.use_verilog_instance.format(
            **{
                "unit": self.prefix,
                "wirea": self.a.name,
                "wireb": self.b.name,
                "wirec": self.c.name,
                "wireys": unique_out_wires[0],
                "wireyc": unique_out_wires[1],
            }) + ";\n"

    def get_circuit_v(self):
        """ support of custom PDK """
        if not self.use_verilog_instance:
            return super().get_circuit_v()

        return f"{self.get_prototype_v_hier()}" + \
               f"{self.get_self_init_v_hier()}" + \
               f"endmodule"


class FullAdderP(FullAdder, ThreeInputOneBitCircuit):
    """Class representing three input one bit full adder with additional output wire for P signal.

    ```
        ┌──────┐
    ───►│      ├─► Sum
    ───►│      ├─► Cout
    ───►│      ├─► P
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Carry input wire. Defaults to Wire(name="cin").
        prefix (str, optional): Prefix name of full adder with p logic. Defaults to "fa_p".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "fa_p"):
        super().__init__(a, b, c, prefix)
        # 3 wires for component's bus output (sum, cout, propagate)
        self.out.bus_extend(3)
        self.out.connect(2, self.get_previous_component(5).out)

    def get_propagate_wire(self):
        """Get output wire carrying propagate value.

        Returns:
            Wire: Return propagate wire.
        """
        return self.out.get_wire(2)


class FullAdderPG(FullAdder, ThreeInputOneBitCircuit):
    """Class representing three input one bit full adder with additional output wires for P and G signals.

    ```
        ┌──────┐
    ───►│      ├─► Sum
    ───►│      ├─► Cout
    ───►│      ├─► P
        │      ├─► G
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Carry input wire. Defaults to Wire(name="cin").
        prefix (str, optional): Prefix name of full adder with pg logic. Defaults to "fa_pg".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "fa_pg"):
        super().__init__(a, b, c, prefix)
        # 4 wires for component's bus output (sum, cout, propagate, generate)
        self.out.bus_extend(4)
        self.out.connect(2, self.get_previous_component(5).out)
        self.out.connect(3, self.get_previous_component(4).out)

    def get_propagate_wire(self):
        """Get output wire carrying propagate value.

        Returns:
            Wire: Return propagate wire.
        """
        return self.out.get_wire(2)

    def get_generate_wire(self):
        """Get output wire carrying generate value.

        Returns:
            Wire: Return generate wire.
        """
        return self.out.get_wire(3)


class PGSumLogic(ThreeInputOneBitCircuit):
    """Class represents a three input function block that contains logic for obtaining the propagate/generate/sum signals.

    ```
        ┌──────┐
    ───►│      ├─► P
    ───►│      ├─► G
    ───►│      ├─► Sum
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Carry input wire. Defaults to Wire(name="cin").
        prefix (str, optional): Prefix name of pg sum logic. Defaults to "pg_sum".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="cin"), prefix: str = "pg_sum"):
        super().__init__(a, b, c, prefix)
        # 3 wires for component's bus output (sum, propagate, generate)
        self.out = Bus(self.prefix+"_out", 3)

        # PG logic
        propagate_xor = XorGate(a, b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=0, parent_component=self)
        self.add_component(propagate_xor)
        self.out.connect(0, propagate_xor.out)

        generate_and = AndGate(a, b, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), outid=1, parent_component=self)
        self.add_component(generate_and)
        self.out.connect(1, generate_and.out)

        # Sum output
        sum_xor = XorGate(propagate_xor.out, c, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=2, parent_component=self)
        self.add_component(sum_xor)
        self.out.connect(2, sum_xor.out)

    def get_propagate_wire(self):
        """Get output wire carrying propagate signal value.

        Returns:
           Wire: Return propagate wire.
        """
        return self.out.get_wire(0)

    def get_generate_wire(self):
        """Get output wire carrying generate signal value.

        Returns:
           Wire: Return generate wire.
        """
        return self.out.get_wire(1)

    def get_sum_wire(self):
        """Get output wire carrying sum value.

        Returns:
           Wire: Return sum wire.
        """
        return self.out.get_wire(2)


class TwoOneMultiplexer(ThreeInputOneBitCircuit):
    """Class representing two to one multiplexer (with select signal as its third input).

    ```
        ┌──────┐
    ───►│      │
        │      ├─►
    ───►│      │
        └───▲──┘
    Sel ────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="d0").
        b (Wire, optional): Second input wire. Defaults to Wire(name="d1").
        c (Wire, optional): Select signal. Defaults to Wire(name="sel").
        prefix (str, optional): Prefix name of two to one multiplexer. Defaults to "mux2to1".
    """
    use_verilog_instance = False

    def __init__(self, a: Wire = Wire(name="d0"), b: Wire = Wire(name="d1"), c: Wire = Wire(name="sel"), prefix: str = "mux2to1"):
        super().__init__(a, b, c, prefix)
        # Represents select signal (self.c naming for proper unified generation)
        self.c = c
        # 1 wire for component's output bus
        self.out = Bus(self.prefix+"_out", 1)

        # 2:1MUX logic
        and_obj = AndGate(a=self.b, b=self.c, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
        self.add_component(and_obj)

        not_obj = NotGate(a=self.c, prefix=self.prefix+"_not"+str(self.get_instance_num(cls=NotGate)), parent_component=self)
        self.add_component(not_obj)

        and_obj = AndGate(a=self.a, b=self.get_previous_component().out, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
        self.add_component(and_obj)

        xor_obj = XorGate(a=self.get_previous_component(3).out, b=self.get_previous_component().out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(xor_obj)

        # Connection of MUX output wire
        self.out.connect(0, xor_obj.out)

    def get_mux_out_wire(self):
        """Get multiplexer output wire.

        Returns:
           Wire: Return multiplexer out wire.
        """
        return self.out.get_wire(0)

    def get_init_v_flat(self):
        """ support of custom PDK """
        if not self.use_verilog_instance:
            return super().get_init_v_flat()

        if self.out[0].is_const():
            return ""
        else:
            # TODO - replace by one verilog_instance_format!
            neg_out_w_name = f"neg_{self.out.get_wire(0).name}"
            return f"  wire {neg_out_w_name};\n  " + self.use_verilog_instance.format(
                **{
                    "unit": self.prefix,
                    "wirea": self.a.get_wire_value_v_hier(), # former version:  f"1'b{self.a.value}" if self.a.is_const() else self.a.name,
                    "wireb": self.b.get_wire_value_v_hier(), #f"1'b{self.b.value}" if self.b.is_const() else self.b.name,
                    "wires": self.c.get_wire_value_v_hier(), #f"1'b{self.c.value}" if self.c.is_const() else self.c.name,
                    "wirey": neg_out_w_name,
                }) + ";\n" + f"  assign {self.out.get_wire(0).name} = ~{neg_out_w_name};\n"

    def get_self_init_v_hier(self):
        """ support of custom PDK """
        if not self.use_verilog_instance:
            return super().get_self_init_v_hier()

        unique_out_wires = []
        for o in self.out.bus:
            unique_out_wires.append(o.name+"_outid"+str(self.out.bus.index(o))) if o.is_const() or o.name in [self.a.name, self.b.name] else unique_out_wires.append(o.name)

        neg_out_w_name = f"neg_{unique_out_wires[0]}"
        return f"  wire {neg_out_w_name};\n  " + self.use_verilog_instance.format(
            **{
                "unit": self.prefix,
                "wirea": self.a.name,
                "wireb": self.b.name,
                "wires": self.c.name,
                "wirey": neg_out_w_name
            }) + ";\n" + f"  assign {unique_out_wires[0]} = ~{neg_out_w_name};\n"

    def get_circuit_v(self):
        """ support of custom PDK """
        if not self.use_verilog_instance:
            return super().get_circuit_v()

        return f"{self.get_prototype_v_hier()}" + \
               f"{self.get_self_init_v_hier()}" + \
               f"endmodule"


class FullSubtractor(ThreeInputOneBitCircuit):
    """Class representing three input one bit full subtractor.

    ```
        ┌──────┐
    ───►│      ├─► Difference
    ───►│      │
    ───►│      ├─► Bout
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        c (Wire, optional): Input borrow wire. Defaults to Wire(name="bin").
        prefix (str, optional): Prefix name of full subtractor. Defaults to "fs".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), c: Wire = Wire(name="bin"), prefix: str = "fs"):
        super().__init__(a, b, c, prefix)
        # 2 wires for component's bus output (difference, bout)
        self.out = Bus(self.prefix+"_out", 2)

        # Difference
        xor_obj = XorGate(a=self.a, b=self.b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(xor_obj)

        not_obj = NotGate(a=self.a, prefix=self.prefix+"_not"+str(self.get_instance_num(cls=NotGate)), parent_component=self)
        self.add_component(not_obj)

        and_obj = AndGate(a=not_obj.out, b=self.b, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
        self.add_component(and_obj)

        difference_xor = XorGate(a=self.c, b=xor_obj.out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=0, parent_component=self)
        self.add_component(difference_xor)
        self.out.connect(0, difference_xor.out)

        # Borrow out
        not_obj = NotGate(a=xor_obj.out, prefix=self.prefix+"_not"+str(self.get_instance_num(cls=NotGate)), parent_component=self)
        self.add_component(not_obj)

        and_obj = AndGate(a=not_obj.out, b=self.c, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self)
        self.add_component(and_obj)

        borrow_out_or = OrGate(a=and_obj.out, b=self.get_previous_component(4).out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), outid=1, parent_component=self)
        self.add_component(borrow_out_or)
        self.out.connect(1, borrow_out_or.out)

    def get_difference_wire(self):
        """Get output wire carrying difference value.

        Returns:
           Wire: Return difference wire.
        """
        return self.out.get_wire(0)

    def get_borrow_wire(self):
        """Get output wire carrying borrow out value.

        Returns:
           Wire: Return borrow out wire.
        """
        return self.out.get_wire(1)


class GreyCell(ThreeInputOneBitCircuit):
    """Class representing three input grey cell used in parallel prefix adders inside the PG (parallel prefix computation) logic.

    Grey cell is based on a notation used in the book CMOS VLSI Design (please refer to the book for more details not deducible from the code itself).
    ```
        ┌──────┐
    ───►│      │
    ───►│      ├─► Generate
    ───►│      │
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire, represents generate signal from the current stage. Defaults to Wire(name="g1").
        b (Wire, optional): Second input wire, represents propagate signal from the current stage. Defaults to Wire(name="p1").
        c (Wire, optional): Third input wire, represents generate signal from a preceding stage. Defaults to Wire(name="g0").
        prefix (str, optional): Prefix name of grey cell. Defaults to "gc".
    """
    def __init__(self, a: Wire = Wire(name="g1"), b: Wire = Wire(name="p1"), c: Wire = Wire(name="g0"), prefix: str = "gc"):
        super().__init__(a, b, c, prefix)
        # 1 wire for component's bus output (output generate)
        self.out = Bus(self.prefix+"_out", 1)

        # Create/propagate the generate signal
        self.add_component(AndGate(a=self.b, b=self.c, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self))
        self.add_component(OrGate(a=self.a, b=self.get_previous_component().out, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), parent_component=self))
        # Connection of the generate output wire
        self.out.connect(0, self.get_previous_component().out)

    def get_generate_wire(self):
        """Get output wire carrying generate value.

        Returns:
           Wire: Return generate wire.
        """
        return self.out.get_wire(0)
