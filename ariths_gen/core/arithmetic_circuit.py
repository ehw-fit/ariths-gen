from ariths_gen.one_bit_circuits.logic_gates import (
    LogicGate,
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)

from ariths_gen.wire_components import (
    Wire,
    Bus
)


class ArithmeticCircuit():
    """Class represents a general arithmetic circuit and ensures their generation to various representations.
    """
    def __init__(self):
        self.components = []
        self.circuit_wires = []
        self.inputs = []
        self.circuit_gates = []
        self.c_data_type = "uint64_t"
        self.N = 1

    def add_component(self, component):
        """Adds component into a list of circuit's inner subcomponents.

        Args:
            component: Subcomponent to be added into list of components composing described circuit.
        """
        self.components.append(component)

    def get_previous_component(self, number: int = 1):
        """Retrieves previously added composite subcomponent from circuit's list of components.

        Args:
            number (int, optional): Offset indicating which lastly added component will be retrieved. Defaults to 1.

        Returns:
            component: Desired previously added composite component.
        """
        return self.components[-number]

    def get_instance_num(self, cls):
        """Informs how many instances of the same type are already present inside circuit's components list.

        Args:
            cls (type): Class type of which to search for instances.

        Returns:
            int: Number of instances of the same class type.
        """
        return sum(isinstance(c, cls) for c in self.components)

    def get_one_bit_components(self):
        """Retrieves list of all one bit circuits (besides logic gates) present as subcomponents inside the circuit.

        Returns:
            list: List of composite one bit circuits.
        """
        one_bit_comps = []
        for c in self.components:
            if isinstance(c, LogicGate):
                continue
            elif type(getattr(c, 'a')) == Wire:
                one_bit_comps.append(c)
            else:
                one_bit_comps.extend(c.get_one_bit_components())

        return one_bit_comps

    def get_multi_bit_components(self):
        """Retrieves list of all multi bit circuits present as subcomponents inside the circuit.

        Returns:
            list: List of composite multi bit circuits.
        """
        multi_bit_comps = []
        for c in self.components:
            if isinstance(c, LogicGate):
                continue
            elif type(getattr(c, 'a')) == Wire:
                continue
            else:
                multi_bit_comps.append(c)
        return multi_bit_comps

    @staticmethod
    def get_unique_types(components: list):
        """Retrieves just the unique representatives of class types present inside the provided components list.

        Args:
            components (list): List of components to be filtered.

        Returns:
            list: List of unique composite class types.
        """
        return list({type(c): c for c in components}.values())

    def get_component_types(self):
        """Retrieves list of all unique types of subcomponents composing the circuit.

           Returning list consists of unique types of logic gates, one bit circuits and multi bit circuits.

        Returns:
            list: List of unique component types describing the circuit.
        """
        gate_comps = self.get_unique_types(components=self.get_circuit_gates())
        one_bit_comps = self.get_unique_types(components=self.get_one_bit_components())
        multi_bit_comps = self.get_unique_types(components=self.get_multi_bit_components())

        all_components = gate_comps + one_bit_comps + multi_bit_comps
        return all_components

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

    def get_circuit_wires(self):
        """Retrieves all the unique wires used for interconnecting subcomponents inside the circuit and stores them inside `self.circuit_wires` list.
           Additionally stores all unique names of just the inner input wires inside `self.inputs` list.
        """
        self.circuit_wires = []
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if item[1] == component.out.name]:
                self.circuit_wires.append((component.out, component.out.name, len(self.circuit_wires)))

        # Get unique names of all inner input circuits (mainly used in one bit circuits)
        self.inputs = [i[0] for i in self.circuit_wires if i[0] not in [o.out for o in self.components]]

    def get_circuit_wire_index(self, wire: Wire):
        """Searches for circuit's wire unique index position within the circuit. Used for cgp chromosome generation.

        Args:
            wire (Wire): Wire to retrieve index position of.

        Returns:
            int: Wire's index position number within the circuit.
        """
        for w in self.circuit_wires:
            if wire.name.endswith(w[1]):
                return w[2]

    def get_circuit_gates(self):
        """Gets list of all logic gates present in circuit.

        Returns:
            list: List of composite logic gates.
        """
        gates = []
        for c in self.components:
            if isinstance(c, LogicGate):
                gates.append(c)
            else:
                gates.extend((c.get_circuit_gates()))
        return gates

    def get_cgp_wires(self):
        """Gets list of all wires in circuit along with their index position for cgp chromosome generation and stores them inside `self.circuit_wires` list.
        """
        self.circuit_wires = []
        if isinstance(self.a, Bus):
            [self.circuit_wires.append((w, f"_{w.name}", len(self.circuit_wires))) for w in self.a.bus]
            [self.circuit_wires.append((w, f"_{w.name}", len(self.circuit_wires))) for w in self.b.bus]
        else:
            self.circuit_wires.append((self.a, f"_{self.a.name}", len(self.circuit_wires)))
            self.circuit_wires.append((self.b, f"_{self.b.name}", len(self.circuit_wires)))
            if hasattr(self, 'c'):
                self.circuit_wires.append((self.c, f"_{self.c.name}", len(self.circuit_wires)))

        for gate in self.circuit_gates:
            if not [item for item in self.circuit_wires if gate.a.name.endswith(item[1])]:
                self.circuit_wires.append((gate.a, gate.a.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if gate.b.name.endswith(item[1])]:
                self.circuit_wires.append((gate.b, gate.b.name, len(self.circuit_wires)))

            if not [item for item in self.circuit_wires if gate.out.name.endswith(item[1])]:
                self.circuit_wires.append((gate.out, gate.out.name, len(self.circuit_wires)))

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
        """Generates C code function header to describe corresponding arithmetic circuit's interface in C code.

        Returns:
            str: Function's name and parameters in C code.
        """
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + "\n"

    def get_declarations_c_flat(self):
        """Generates flat C code declaration of input/output buses wires.

        Returns:
            str: Flattened C code arithmetic circuit's wires declaration.
        """
        return f"{self.a.get_wire_declaration_c()}" + \
               f"{self.b.get_wire_declaration_c()}" + \
               f"".join([c.get_declaration_c_flat() for c in self.components])

    # For multi-bit circuit wires declaration
    def get_declaration_c_flat(self):
        """Generates flat C code declaration of input/output buses wires of multi-bit arithmetic circuit present as subcomponent in the circuit.

        Returns:
            str: Flattened C code multi-bit arithmetic circuit subcomponent wires declaration.
        """
        return f"".join([c.get_declaration_c_flat() for c in self.components])

    def get_inits_c_flat(self):
        """Generates flat C code initialization and assignment of corresponding arithmetic circuit's input/output buses wires.

        Returns:
            str: Flattened C code initialization of arithmetic circuit wires.
        """
        return f"{self.a.get_wire_assign_c()}" + \
               f"{self.b.get_wire_assign_c()}" + \
               "".join([c.get_assign_c_flat() if isinstance(c, LogicGate) else c.get_init_c_flat() for c in self.components])

    # For multi-bit circuit wires initialization
    def get_init_c_flat(self):
        """Generates flat C code initialization and assignment of input/output buses wires of multi-bit arithmetic circuit present as subcomponent in the circuit.

        Returns:
            str: Flattened C code multi-bit arithmetic circuit subcomponent wires initialization.
        """
        return "".join([c.get_assign_c_flat() if isinstance(c, LogicGate) else c.get_init_c_flat() for c in self.components])

    def get_function_out_c_flat(self):
        """Generates flat C code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flattened C code containing output bus wires assignment.
        """
        return "".join([f"  {self.out.prefix} |= {o.return_wire_value_c(offset=self.out.bus.index(o))};\n" for o in self.out.bus])

    # Generating flat C code representation of circuit
    def get_c_code_flat(self, file_object):
        """Generates flat C code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declarations_c_flat()+"\n")
        file_object.write(self.get_inits_c_flat()+"\n")
        file_object.write(self.get_function_out_c_flat())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_blocks_c(self):
        """Generates hierarchical C code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical C code of all subcomponents function blocks description.
        """
        # Add unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_function_block_c(self):
        """Generates hierarchical C code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical C code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper adder name with its bit width
        adder_prefix = self.__class__(a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        adder_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(N=self.N, prefix="b"), prefix=adder_prefix)
        return f"{adder_block.get_circuit_c()}\n\n"

    def get_declaration_c_hier(self):
        """Generates hierarchical C code declaration of input/output buses wires.

        Returns:
            str: Hierarchical C code containing unique declaration of arithmetic circuit wires.
        """
        return "".join(self.a.get_wire_declaration_c()) + \
               "".join(self.b.get_wire_declaration_c()) + \
               "".join([c.out.get_declaration_c() if isinstance(c, LogicGate) else c.get_wire_declaration_c_hier() for c in self.components])

    def get_wire_declaration_c_hier(self):
        """Generates hierarchical C code declaration of corresponding subcomponent input/output buses wires inside the upper component.

           Generates wires used to connect input/output values to/from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code of subcomponent arithmetic circuit's wires declaration.
        """
        return f"  {self.c_data_type} {self.prefix}_{self.a.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.prefix}_{self.b.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.prefix}_{self.out.prefix} = 0;\n" + \
               f"{self.out.get_wire_declaration_c()}"

    def get_init_c_hier(self):
        """Generates hierarchical C code initialization and assignment of corresponding arithmetic circuit's input/output buses wires.

        Returns:
            str: Hierarchical C code initialization of arithmetic circuit wires.
        """
        return f"{self.a.get_wire_assign_c()}" + \
               f"{self.b.get_wire_assign_c()}" + \
               "".join([f"  {c.out.name} = {c.get_gate_invocation_c()}" if isinstance(c, LogicGate) else c.get_out_invocation_c(circuit_prefix=self.prefix) for c in self.components])

    def get_out_invocation_c(self, circuit_prefix: str):
        """Generates hierarchical C code invocation of corresponding arithmetic circuit's generated function block.

           Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
           Assigns output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical C code of subcomponent's C function invocation and output assignment.
        """
        # Getting name of circuit type and insitu copying out bus for proper C code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        out = Bus(prefix=self.prefix+"_"+self.out.prefix, wires_list=self.out.bus)
        return "".join([f"  {self.prefix}_{self.a.prefix} |= {w.return_wire_value_c(offset=self.a.bus.index(w))};\n" for w in self.a.bus]) + \
               "".join([f"  {self.prefix}_{self.b.prefix} |= {w.return_wire_value_c(offset=self.b.bus.index(w))};\n" for w in self.b.bus]) + \
               f"  {out.prefix} = {circuit_type}({self.prefix}_{self.a.prefix}, {self.prefix}_{self.b.prefix});\n" + \
               f"{out.get_wire_assign_c()}"

    def get_function_out_c_hier(self):
        """Generates hierarchical C code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Hierarchical C code containing output bus wires assignment.
        """
        return "".join([f"  {self.out.prefix} |= {o.return_wire_value_c(offset=self.out.bus.index(o))};\n" for o in self.out.bus])

    def get_circuit_c(self):
        """Generates hierarchical C code subcomponent's function block.

        Returns:
            str: Hierarchical C code of subcomponent's function block.
        """
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_declaration_c_hier()}\n" + \
               f"{self.get_init_c_hier()}\n" + \
               f"{self.get_function_out_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    # Generating hierarchical C code representation of circuit
    def get_c_code_hier(self, file_object):
        """Generates hierarchical C code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_includes_c())
        file_object.write(self.get_function_blocks_c())
        file_object.write(self.get_circuit_c())
        file_object.close()

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        """Generates Verilog code module header to describe corresponding arithmetic circuit's interface in Verilog code.

        Returns:
            str: Module's name and parameters in Verilog code.
        """
        return f"module {self.prefix}(input [{self.N-1}:0] {self.a.prefix}, input [{self.N-1}:0] {self.b.prefix}, output [{self.out.N-1}:0] {self.out.prefix});\n"

    def get_declarations_v_flat(self):
        """Generates flat Verilog code declaration of input/output buses wires.

        Returns:
            str: Flattened Verilog code arithmetic circuit's wires declaration.
        """
        return f"{self.a.get_wire_declaration_v()}" + \
               f"{self.b.get_wire_declaration_v()}" + \
               f"".join([c.get_declaration_v_flat() for c in self.components])

    # For multi-bit circuit wires declaration
    def get_declaration_v_flat(self):
        """Generates flat Verilog code declaration of input/output buses wires of multi-bit arithmetic circuit present as subcomponent in the circuit.

        Returns:
            str: Flattened Verilog code multi-bit arithmetic circuit subcomponent wires declaration.
        """
        return f"".join([c.get_declaration_v_flat() for c in self.components])

    def get_inits_v_flat(self):
        """Generates flat Verilog code initialization and assignment of corresponding arithmetic circuit's input/output buses wires.

        Returns:
            str: Flattened Verilog code initialization of arithmetic circuit wires.
        """
        return f"{self.a.get_wire_assign_v()}" + \
               f"{self.b.get_wire_assign_v()}" + \
               "".join([c.get_assign_v_flat() if isinstance(c, LogicGate) else c.get_init_v_flat() for c in self.components])

    # For multi-bit circuit wires initialization
    def get_init_v_flat(self):
        """Generates flat Verilog code initialization and assignment of input/output buses wires of multi-bit arithmetic circuit present as subcomponent in the circuit.

        Returns:
            str: Flattened Verilog code multi-bit arithmetic circuit subcomponent wires initialization.
        """
        return "".join([c.get_assign_v_flat() if isinstance(c, LogicGate) else c.get_init_v_flat() for c in self.components])

    def get_function_out_v_flat(self):
        """Generates flat Verilog code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flattened Verilog code containing output bus wires assignment.
        """
        return "".join([f"  assign {self.out.prefix}[{self.out.bus.index(o)}] = {o.prefix};\n" for o in self.out.bus])

    # Generating flat Verilog code representation of circuit
    def get_v_code_flat(self, file_object):
        """Generates flat Verilog code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_v())
        file_object.write(self.get_declarations_v_flat()+"\n")
        file_object.write(self.get_inits_v_flat() + "\n")
        file_object.write(self.get_function_out_v_flat())
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    def get_function_blocks_v(self):
        """Generates hierarchical Verilog code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical Verilog code of all subcomponents function blocks description.
        """
        # Add unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_v() for c in self.component_types])

    def get_function_block_v(self):
        """Generates hierarchical Verilog code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Verilog code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper adder name with its bit width
        adder_prefix = self.__class__(a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        adder_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(N=self.N, prefix="b"), prefix=adder_prefix)
        return f"{adder_block.get_circuit_v()}\n\n"

    def get_declaration_v_hier(self):
        """Generates hierarchical Verilog code declaration of input/output buses wires.

        Returns:
            str: Hierarchical Verilog code containing unique declaration of arithmetic circuit wires.
        """
        return "".join(self.a.get_wire_declaration_v()) + \
               "".join(self.b.get_wire_declaration_v()) + \
               "".join([c.out.get_declaration_v() if isinstance(c, LogicGate) else c.get_wire_declaration_v_hier() for c in self.components])

    def get_wire_declaration_v_hier(self):
        """Generates hierarchical Verilog code declaration of corresponding subcomponent input/output buses wires inside the upper component.

           Generates wires used to connect input/output values to/from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent arithmetic circuit's wires declaration.
        """
        return f"  wire [{self.a.N-1}:0] {self.prefix}_{self.a.prefix};\n" + \
               f"  wire [{self.b.N-1}:0] {self.prefix}_{self.b.prefix};\n" + \
               f"  wire [{self.out.N-1}:0] {self.prefix}_{self.out.prefix};\n" + \
               f"{self.out.get_wire_declaration_v()}"

    def get_init_v_hier(self):
        """Generates hierarchical Verilog code initialization and assignment of corresponding arithmetic circuit's input/output buses wires.

        Returns:
            str: Hierarchical Verilog code initialization of arithmetic circuit wires.
        """
        return f"{self.a.get_wire_assign_v()}" + \
               f"{self.b.get_wire_assign_v()}" + \
               "".join([c.get_gate_invocation_v() if isinstance(c, LogicGate) else c.get_invocation_v(circuit_prefix=self.prefix) for c in self.components])

    def get_invocation_v(self, circuit_prefix: str):
        """Generates hierarchical Verilog code invocation of corresponding arithmetic circuit's generated function block.

           Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
           Assigns output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent's module invocation and output assignment.
        """
        # Getting name of circuit type and insitu copying out bus for proper Verilog code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        out = Bus(prefix=self.prefix+"_"+self.out.prefix, wires_list=self.out.bus)
        return "".join([f"  assign {self.prefix}_{self.a.prefix}[{self.a.bus.index(w)}] = {w.name};\n" for w in self.a.bus]) + \
               "".join([f"  assign {self.prefix}_{self.b.prefix}[{self.b.bus.index(w)}] = {w.name};\n" for w in self.b.bus]) + \
               f"  {circuit_type} {circuit_type}_{self.out.prefix}({self.prefix}_{self.a.prefix}, {self.prefix}_{self.b.prefix}, {out.prefix});\n" + \
               f"{out.get_wire_assign_v()}"

    def get_function_out_v_hier(self):
        """Generates hierarchical Verilog code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Hierarchical Verilog code containing output bus wires assignment.
        """
        return "".join([f"  assign {self.out.prefix}[{self.out.bus.index(o)}] = {o.name};\n" for o in self.out.bus])

    def get_circuit_v(self):
        """Generates hierarchical Verilog code subcomponent's function block.

        Returns:
            str: Hierarchical Verilog code of subcomponent's function block.
        """
        return f"{self.get_prototype_v()}" + \
               f"{self.get_declaration_v_hier()}\n" + \
               f"{self.get_init_v_hier()}\n" + \
               f"{self.get_function_out_v_hier()}" + \
               f"endmodule"

    # Generating hierarchical Verilog code representation of circuit
    def get_v_code_hier(self, file_object):
        """Generates hierarchical Verilog code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_function_blocks_v())
        file_object.write(self.get_circuit_v())
        file_object.close()

    """ BLIF CODE GENERATION """
    # FLAT BLIF #
    def get_prototype_blif(self):
        """Generates Blif code model name of described arithmetic circuit.

        Returns:
            str: Model's name in Blif code.
        """
        return f".model {self.prefix}\n"

    def get_declaration_blif(self):
        """Generates flat Blif code declaration of arithmetic circuit's input/output buses wires.

        Returns:
            str: Flattened Blif code containing declaration of circuit's interface wires.
        """
        if self.N == 1:
            return f".inputs {self.a.prefix} {self.b.prefix}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f"{self.a.get_wire().get_assign_blif(name=self.a.prefix)}" + \
                   f"{self.b.get_wire().get_assign_blif(name=self.b.prefix)}"
        else:
            return f".inputs {self.a.get_wire_declaration_blif()}{self.b.get_wire_declaration_blif()}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f"{self.a.get_wire_assign_blif()}" + \
                   f"{self.b.get_wire_assign_blif()}"

    def get_function_blif_flat(self):
        """Generates flat Blif code with unique input wire mapping and invocation of subcomponents functions via their corresponding truth tables.

        Returns:
            str: Flattened Blif code containing input wires mapping and inner subcomponents Boolean functions invocation.
        """
        return "".join(c.get_init_function_blif_flat() if isinstance(c, LogicGate) else c.get_function_blif_flat() for c in self.components)

    def get_function_out_blif(self):
        """Generates flat Blif code mapping of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flattened Blif code containing output bus wires assignment mapping.
        """
        return f"{self.out.get_wire_assign_blif(output=True)}"

    # Generating flat BLIF code representation of circuit
    def get_blif_code_flat(self, file_object):
        """Generates flat Blif code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_blif())
        file_object.write(self.get_declaration_blif())
        file_object.write(self.get_function_blif_flat())
        file_object.write(self.get_function_out_blif())
        file_object.write(f".end\n")
        file_object.close()

    # HIERARCHICAL BLIF #
    def get_function_blif_hier(self):
        """Generates hierarchical Blif code with unique input wire mapping and invocation of subcomponents function blocks.

        Returns:
            str: Hierarchical Blif code containing input wires mapping and inner subcomponents function blocks invocation.
        """
        return "".join(c.get_invocation_blif_hier(init=True) if isinstance(c, LogicGate) else c.get_invocation_blif_hier(circuit_prefix=self.prefix) for c in self.components)

    def get_invocation_blif_hier(self, circuit_prefix: str):
        """Generates hierarchical Blif code invocation of corresponding arithmetic circuit's generated function block.

           Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
           Assigns output values from invocation of the correspoding function block into inner wires present inside the upper component from which function block has been invoked.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical Blif code of subcomponent's model invocation and output assignment.
        """
        # Getting name of circuit type for proper Blif code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        return "".join([w.get_assign_blif(name=self.prefix+'_'+self.a.prefix+f'[{self.a.bus.index(w)}]', output=True)for w in self.a.bus]) + \
               "".join([w.get_assign_blif(name=self.prefix+'_'+self.b.prefix+f'[{self.b.bus.index(w)}]', output=True)for w in self.b.bus]) + \
               f".subckt {circuit_type}" + \
               "".join([f" a[{self.a.bus.index(w)}]={self.prefix}_{self.a.prefix}[{self.a.bus.index(w)}]" for w in self.a.bus]) + \
               "".join([f" b[{self.b.bus.index(w)}]={self.prefix}_{self.b.prefix}[{self.b.bus.index(w)}]" for w in self.b.bus]) + \
               "".join([f" out[{self.out.bus.index(o)}]={o.name}" for o in self.out.bus]) + "\n"

    def get_circuit_blif(self):
        """Generates hierarchical Blif code subcomponent's function block.

        Returns:
            str: Hierarchical Blif code of subcomponent's function block.
        """
        return f"{self.get_prototype_blif()}" + \
               f"{self.get_declaration_blif()}" + \
               f"{self.get_function_blif_hier()}" + \
               f"{self.get_function_out_blif()}" + \
               f".end\n"

    def get_function_blocks_blif(self):
        """Generates hierarchical Blif code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical Blif code of all subcomponents function blocks description.
        """
        # Add unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "\n".join([c.get_function_block_blif() for c in self.component_types[::-1]])

    def get_function_block_blif(self):
        """Generates hierarchical Blif code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Blif code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper adder name with its bit width
        adder_prefix = self.__class__(a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        adder_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(N=self.N, prefix="b"), prefix=adder_prefix)
        return f"{adder_block.get_circuit_blif()}"

    # Generating hierarchical BLIF code representation of circuit
    def get_blif_code_hier(self, file_object):
        """Generates hierarchical Blif code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_circuit_blif()+"\n")
        file_object.write(self.get_function_blocks_blif())
        file_object.close()

    """ CGP CODE GENERATION """
    # FLAT CGP #
    def get_parameters_cgp(self):
        """Generates CGP chromosome parameters of corresponding arithmetic circuit.
           In total seven parameters represent: total inputs, total outputs, number of rows, number of columns (gates),
           number of each gate's inputs, number of each gate's outputs, quality constant value.

        Returns:
            str: CGP chromosome parameters of described arithmetic circuit.
        """
        self.circuit_gates = self.get_circuit_gates()
        return f"{{{self.a.N+self.a.N},{self.out.N},1,{len(self.circuit_gates)},2,1,0}}"

    def get_triplet_cgp(self):
        """Generates list of logic gate triplets (2 input wires, logic gate function) using wires unique position indexes within the described circuit.
           Each triplet represents unique logic gate within the described arithmetic circuit. Besides the contained input wires indexes and gate's inner logic function, an output wire
           with incremented index position is also created and remembered to be appropriately driven as an input to another logic gate or as the circuit's output.

        Returns:
            str: List of triplets each describing logic function of corresponding two input logic gate and as a whole describe the arithmetic circuit.
        """
        self.get_cgp_wires()
        return "".join([g.get_triplet_cgp(a_index=self.get_circuit_wire_index(g.a), b_index=self.get_circuit_wire_index(g.b)) for g in self.circuit_gates])

    def get_output_cgp(self):
        """Generates list of output wires indexes of described arithmetic circuit from MSB to LSB.

        Returns:
            str: List of arithmetic circuit's output wire indexes.
        """
        return "(" + ",".join([str(self.get_circuit_wire_index(o)) for o in self.out.bus[::-1]]) + ")"

    # Generating flat CGP chromosome representation of circuit
    def get_cgp_code_flat(self, file_object):
        """Generates flat CGP chromosome representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_parameters_cgp())
        file_object.write(self.get_triplet_cgp())
        file_object.write(self.get_output_cgp())
        file_object.close()
