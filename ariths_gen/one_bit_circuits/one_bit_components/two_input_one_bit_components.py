from ariths_gen.core.one_bit_circuits import TwoInputOneBitCircuit
from ariths_gen.one_bit_circuits.logic_gates import AndGate, NandGate, OrGate, NorGate, XorGate, XnorGate, NotGate
from ariths_gen.wire_components import Wire, Bus


class HalfAdder(TwoInputOneBitCircuit):
    """Class representing two input one bit half adder.

    ```
        ┌──────┐
    ───►│      ├─► Sum
        │      │
    ───►│      ├─► Cout
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of half adder. Defaults to "ha".
    """
    use_verilog_instance = False

    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "ha"):
        super().__init__(a, b, prefix)
        # 2 wires for component's bus output (sum, cout)
        self.out = Bus(self.prefix+"_out", 2)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor = XorGate(a, b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=0, parent_component=self)
        self.add_component(obj_xor)
        self.out.connect(0, obj_xor.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and = AndGate(a, b, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), outid=1, parent_component=self)
        self.add_component(obj_and)
        self.out.connect(1, obj_and.out)

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


class PGLogicBlock(TwoInputOneBitCircuit):
    """Class representing two input one bit propagate/generate logic block.

    ```
        ┌──────┐
    ───►│      ├─► P
        │      ├─► G
    ───►│      ├─► S
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of pg logic block. Defaults to "pg_logic".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "pg_logic"):
        super().__init__(a, b, prefix)
        # 3 wires for component's bus output (propagate, generate, sum)
        self.out = Bus(self.prefix+"_out", 3)

        # PG logic
        propagate_or = OrGate(a, b, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), outid=0, parent_component=self)
        self.add_component(propagate_or)
        generate_and = AndGate(a, b, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), outid=1, parent_component=self)
        self.add_component(generate_and)
        sum_xor = XorGate(a, b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=2, parent_component=self)
        self.add_component(sum_xor)

        self.out.connect(0, propagate_or.out)
        self.out.connect(1, generate_and.out)
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


class HalfSubtractor(TwoInputOneBitCircuit):
    """Class representing two input one bit half subtractor.

    ```
        ┌──────┐
    ───►│      ├─► Difference
        │      │
    ───►│      ├─► Bout
        └──────┘
    ```

    Description of the __init__ method.

    Args:
        a (Wire, optional): First input wire. Defaults to Wire(name="a").
        b (Wire, optional): Second input wire. Defaults to Wire(name="b").
        prefix (str, optional): Prefix name of half subtractor adder. Defaults to "hs".
    """
    def __init__(self, a: Wire = Wire(name="a"), b: Wire = Wire(name="b"), prefix: str = "hs"):
        super().__init__(a, b, prefix)
        # 2 wires for component's bus output (difference, bout)
        self.out = Bus(self.prefix+"_out", 2)

        # Difference
        # XOR gate for calculation of 1-bit difference
        difference_xor = XorGate(a=self.a, b=self.b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=0, parent_component=self)
        self.add_component(difference_xor)
        self.out.connect(0, difference_xor.out)

        # Bout
        # NOT and AND gates for calculation of 1-bit borrow out
        not_obj = NotGate(a=self.a, prefix=self.prefix+"_not"+str(self.get_instance_num(cls=NotGate)), parent_component=self)
        self.add_component(not_obj)

        borrow_and = AndGate(a=not_obj.out, b=self.b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), outid=1, parent_component=self)
        self.add_component(borrow_and)
        self.out.connect(1, borrow_and.out)

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
