from .wires import Wire


class Bus():
    """Class representing bus of wires used as inputs/outputs of bigger circuits.

    Description of the __init__ method.

    Args:
        prefix (str, optional): Prefix name of the bus. Defaults to "bus".
        N (int, optional): Number of wires in the bus. Defaults to 1.
        wires_list (list, optional): List of Wire objects used to clone one bus to another. Defaults to 0.
        out_bus (bool, optional): Specifies whether this Bus is an output bus of some previous component. Defaults to False.
        signed (bool, optional): Specifies whether this Bus should consider signed numbers or not (used for C code generation). Defaults to False.
    """
    def __init__(self, prefix: str = "bus", N: int = 1, wires_list: list = None, out_bus: bool = False, signed: bool = False):
        self.out_bus = out_bus
        if wires_list is None:
            self.prefix = prefix
            # Adding wires into current bus's wires list (wire names are concatenated from bus prefix and their index position inside the bus in square brackets)
            self.bus = [Wire(name=prefix+f"[{i}]", prefix=prefix, index=i, parent_bus=self) for i in range(N)]
            self.N = N
        else:
            self.prefix = prefix
            self.bus = wires_list
            self.N = len(self.bus)
        
        # Determine C code signedness
        self.signed = signed
        if self.N > 8:
            self.c_var_size = 64
            if signed is True:
                self.c_type = "int64_t"
            else:
                self.c_type = "uint64_t"
        else:
            self.c_var_size = 8
            if signed is True:
                self.c_type = "int8_t"
            else:
                self.c_type = "uint8_t"

    def is_output_bus(self):
        """Tells whether this Bus is an output bus.

        Returns:
            bool: Returns True if it is an output bus of some component.
        """
        return self.out_bus

    def bus_extend(self, N: int, prefix: str = "bus"):
        """Provides bus extension to contain more wires.

        Args:
            N (int): Number of wires in the bus. Defaults to 1.
            prefix (str, optional): Prefix name of the bus. Defaults to "bus".
        """
        # Checks if any extension is neccesarry and if so, proceeds to wire extend the bus
        if self.N < N:
            # Adding wires into current bus's wires list (wire names are concatenated from bus prefix and their index position inside the bus in square brackets)
            self.bus += [Wire(name=prefix+f"[{i}]", prefix=prefix, index=i, parent_bus=self) for i in range(self.N, N)]
            self.N = N

    def get_wire(self, wire_index: int = 0):
        """Retrieves a wire from the bus by a given index.

        Args:
            wire_index (int, optional): Index of wire to be retrieved from the bus. Defaults to 0.

        Returns:
            Wire: Returning wire from the bus.
        """
        return self.bus[wire_index]

    # Connecting output wire of the inner circuit component to desired position in the described circuit's output bus
    def connect(self, bus_wire_index: int, inner_component_out_wire: Wire, inserted_wire_desired_index: int = -1):
        """Connects given 'Wire' object to a 'bus_wire_index' within this bus.

        Used for connection of output wire of the inner circuit component
        to the appropriate wire of the circuit's output bus.

        Args:
            bus_wire_index (int): Index in bus to store given wire in.
            inner_component_out_wire (Wire): Wire of some other component (mostly its output) to store in the bus.
            inserted_wire_desired_index(int, optional): Optional desired explicit index, where 'inner_component_out_wire' value resides in the inner components's output bus. Otherwise 'inner_component_out_wire' self index value is used. Defaults to -1.
        """
        inserted_wire_index = inserted_wire_desired_index if inserted_wire_desired_index != -1 else inner_component_out_wire.index
        # Used for connection of constant wire value into a bus
        if inner_component_out_wire.is_const():
            self.bus[bus_wire_index] = inner_component_out_wire
        # Proper connection of wires that themselves are not yet a member of any other bus and also those that could be part of some bus but do not have `inserted_wire_desired_index` defined
        elif inner_component_out_wire.parent_bus is None or inserted_wire_desired_index == -1:
            self.bus[bus_wire_index] = Wire(name=inner_component_out_wire.name, prefix=inner_component_out_wire.prefix, index=inserted_wire_index, value=inner_component_out_wire.value, parent_bus=self)
        # Proper connection of wires that are already a member of some other bus and are desired to connect value from their previous bus to this one at desired index position
        elif inserted_wire_desired_index != -1:
            self.bus[bus_wire_index] = Wire(name=inner_component_out_wire.name, prefix=inner_component_out_wire.parent_bus.prefix, index=inserted_wire_index, value=inner_component_out_wire.value, parent_bus=self)

    def connect_bus(self, connecting_bus: object, start_connection_pos: int = 0, end_connection_pos: int = -1):
        """Ensures connection of specified bus wires to this bus wires.

        Used for connection of some inner circuit component's output bus (`connecting_bus`) wires
        to the appropriate input bus (this `self` bus) wires of some other circuit.

        Args:
            connecting_bus (object): Specifies the connecting bus.
            start_connection_pos (int, optional): Specifies the position from which to start interconnecting wires from the `connecting_bus` to this `self` bus. Defaults to 0.
            end_connection_pos (int, optional): Specifies the position from which to end interconnecting wires from the `connecting_bus` to this `self` bus. Defaults to -1.
        """
        if end_connection_pos == -1:
            end_connection_pos = self.N

        [self.connect(o, connecting_bus.get_wire(o), inserted_wire_desired_index=o) for o in range(start_connection_pos, end_connection_pos)]

    """ PYTHON CODE GENERATION """
    def return_bus_wires_values_python_flat(self):
        """Retrieves values from bus's wires and stores them in bus's corresponding Python variable (object) at proper offset bit position in the bus for flat generation.

        Returns:
            str: Python code for assigning wire values into bus represented in Python code variable.
        """
        return "".join([f"  {self.prefix} = 0\n"] + [f"  {self.prefix} |= {w.return_wire_value_python_flat(offset=self.bus.index(w))}" for w in self.bus])
    
    def return_bus_wires_sign_extend_python(self):
        """Sign extends the bus's corresponding Python variable (object) to ensure proper Python code variable signedness.

        Returns:
            str: Python code for sign extending the bus variable wire values.
        """
        if self.signed is True:
            last_bus_wire = self.bus[-1]
            return "".join([f"  {self.prefix} |= {last_bus_wire.return_wire_value_python_flat(offset=i)}" for i in range(len(self.bus), 64)])
        else:
            return ""

    """ C CODE GENERATION """
    def get_declaration_c(self):
        """Bus declaration in C code.

        Returns:
            str: C code for declaration and initialization of bus name.
        """
        return f"  {self.c_type} {self.prefix} = 0;\n"
        

    def return_bus_wires_values_c_flat(self):
        """Retrieves values from bus's wires and stores them in bus's corresponding C variable at proper offset bit position in the bus for flat generation.

        Returns:
            str: C code for assigning wire values into bus represented in C code variable.
        """
        return "".join([f"  {self.prefix} |= {w.return_wire_value_c_flat(offset=self.bus.index(w))}" for w in self.bus])

    def return_bus_wires_values_c_hier(self):
        """Retrieves values from bus's wires and stores them in bus's corresponding C variable at proper offset bit position in the bus for hierarchical generation.

        Returns:
            str: C code for assigning wire values into bus represented in C code variable.
        """
        return "".join([f"  {self.prefix} |= {w.return_wire_value_c_hier(offset=self.bus.index(w))}" for w in self.bus])

    def return_bus_wires_sign_extend_c(self):
        """Sign extends the bus's corresponding C variable to ensure proper C code variable signedness.

        Returns:
            str: C code for sign extending the bus variable wire values.
        """
        if self.signed is True:
            last_bus_wire = self.bus[-1]
            return "".join([f"  {self.prefix} |= {last_bus_wire.return_wire_value_c_flat(offset=i)}" for i in range(len(self.bus), self.c_var_size)])
        else:
            return ""

    """ VERILOG CODE GENERATION """
    def return_bus_wires_values_v_flat(self):
        """Retrieves values from bus's wires and stores them in bus's corresponding Verilog variable at proper offset bit position in the bus for flat generation.

        Returns:
            str: Verilog code for assigning wire values into bus represented in Verilog code bus variable.
        """
        return "".join([f"  assign {self.prefix}[{self.bus.index(w)}] = {w.return_wire_value_v_flat()}" for w in self.bus])

    def return_bus_wires_values_v_hier(self):
        """Retrieves values from bus's wires and stores them in bus's corresponding Verilog variable at proper offset bit position in the bus for hierarchical generation.

        Returns:
            str: Verilog code for assigning wire values into bus represented in Verilog code variable.
        """
        return "".join([f"  assign {self.prefix}[{self.bus.index(w)}] = {w.return_wire_value_v_hier()}" for w in self.bus])

    def get_unique_assign_out_wires_v(self, circuit_block: object):
        """Returns bus's wires used for hierarchical one bit subcomponent's function block invocation and output wires assignments.

        Args:
            circuit_block (object): Object describing corresponding function block that is being invoked for proper output wires assignment during instantiation.

        Returns:
            str: Verilog code unique bus wires for proper subcomponent's function block invocation.
        """
        unique_out_wires = []
        [unique_out_wires.append(w.prefix) if w.prefix not in unique_out_wires else None for w in self.bus]
        return "".join([f", .{circuit_block.out.get_wire(self.bus.index(o)).prefix}({unique_out_wires.pop(unique_out_wires.index(o.prefix))})" if o.prefix in unique_out_wires else f", .{circuit_block.out.get_wire(self.bus.index(o)).prefix}()" for o in self.bus])

    """ BLIF CODE GENERATION """
    def get_wire_declaration_blif(self, array: bool = True):
        """Declare each wire from the bus independently in Blif code representation.

        Args:
            array (bool, optional): Specifies whether to declare wires from bus by their offset e.g. out[0] or by their wire name e.g. out_0. Defaults to True.

        Returns:
            str: Blif code for declaration of individual bus wires.
        """
        return "".join([f" {w.get_declaration_blif(prefix=self.prefix, offset=self.bus.index(w), array=array)}" for w in self.bus])

    def get_wire_assign_blif(self, output: bool = False):
        """Assign all bits from the bus as each individual wires or assign wires into the corresponding output bus position in Blif code representation.

        Args:
            output (bool, optional): Specifies whether bus wires are used as outputs (True, assigned to) or as inputs (False, assigned from). Defaults to False.

        Returns:
            str: Blif code for bus wires assignments.
        """
        return "".join([w.get_assign_blif(prefix=self.prefix+f"[{self.bus.index(w)}]", output=output) for w in self.bus])

    def get_unique_assign_out_wires_blif(self, function_block_out_bus: object):
        """Assigns unique output wires to their respective outputs of subcomponent's function block modul in hierarchical Blif subcomponent's invocation.

        Args:
            function_block_out_bus (object): Specifies output bus of corresponding function block's outputs for proper subcomponent modul invocation.

        Returns:
            str: Blif code for proper subcomponent's function block invocation with respective output wires assignment.
        """
        unique_out_wires = []
        [unique_out_wires.append(w.prefix) if w.prefix not in unique_out_wires else None for w in self.bus]
        return "".join([f" {function_block_out_bus.get_wire(self.bus.index(o)).name}={unique_out_wires.pop(unique_out_wires.index(o.prefix))}" if o.prefix in unique_out_wires else "" for o in self.bus])
