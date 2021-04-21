from ariths_gen.core.logic_gate_circuits.logic_gate_circuit import OneInputLogicGate, TwoInputLogicGate

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)


class ArithmeticCircuit():
    """Class represents a general arithmetic circuit and ensures their generation to various representations.

    The __init__ method fills some mandatory attributes concerning arithmetic circuit
    that are later used for generation into various representations.
    """
    def __init__(self):
        self.components = []
        self.circuit_wires = []
        self.circuit_gates = []
        self.c_data_type = "uint64_t"
        self.N = 1

    def add_component(self, component):
        """Adds a component into list of circuit's inner subcomponents.

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

    def get_instance_num(self, cls, count_disabled_gates: bool = True):
        """Informs how many instances of the same type are already present inside circuit's components list.

        Args:
            cls (type): Class type for which to count the number of instances in the components list.
            count_disabled_gates (bool, optional): Indicates whether logic gates that aren't generated should be also counted. Defaults to True.
        Returns:
            int: Number of instances of the same class type.
        """
        if issubclass(cls, TwoInputLogicGate) and count_disabled_gates is False:
            return sum(isinstance(c, cls) for c in self.components if isinstance(c, cls) and c.disable_generation is False)
        else:
            return sum(isinstance(c, cls) for c in self.components)

    def get_circuit_gates(self):
        """Gets a list of all the logic gates in circuit that should be generated.

        Returns:
            list: List of composite logic gates.
        """
        gates = []
        for c in self.components:
            if isinstance(c, TwoInputLogicGate):
                if c.disable_generation is False:
                    gates.append(c)
            else:
                gates.extend((c.get_circuit_gates()))
        return gates

    def get_one_bit_components(self):
        """Retrieves a list of all the one bit circuits (besides logic gates) present as subcomponents inside the circuit.

        Returns:
            list: List of composite one bit circuits.
        """
        one_bit_comps = []
        for c in self.components:
            if isinstance(c, TwoInputLogicGate):
                continue
            elif isinstance(getattr(c, 'a'), Wire):
                one_bit_comps.append(c)
            else:
                one_bit_comps.extend(c.get_one_bit_components())

        return one_bit_comps

    def get_multi_bit_components(self):
        """Retrieves a list of all the multi bit circuits present as subcomponents inside the circuit.

        Returns:
            list: List of composite multi bit circuits.
        """
        multi_bit_comps = []
        for c in self.components:
            if isinstance(c, TwoInputLogicGate):
                continue
            elif isinstance(getattr(c, 'a'), Wire):
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
        """Retrieves a list of all the unique types of subcomponents composing the circuit.

        Returning list consists of only the unique types of logic gates, one bit circuits and multi bit circuits.

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

    def save_wire_id(self, wire: Wire):
        """Returns appropriate wire index position within the circuit.

        Constant wire with value 0 has constant index of 0.
        Constant wire with value 1 has constant index of 1.
        Other wires indexes start counting from 2 and up.

        Args:
            wire (Wire): Wire that will be stored at this circuit index position.

        Returns:
            int: Wire's index position within circuit.
        """
        if wire.is_const():
            return wire.cgp_const
        else:
            return len([w[0] for w in self.circuit_wires if w[0].is_const() is False]) + 2

    def get_cgp_wires(self):
        """Gets a list of all wires in circuit along with their index position for cgp chromosome generation and stores them inside `self.circuit_wires` list.

        Constant wire with value 0 has constant index of 0.
        Constant wire with value 1 has constant index of 1.
        Other wires indexes start counting from 2 and up.
        """
        self.circuit_wires = []
        if isinstance(self.a, Bus):
            [self.circuit_wires.append((w, f"{w.name}", self.save_wire_id(wire=w))) for w in self.a.bus]
            [self.circuit_wires.append((w, f"{w.name}", self.save_wire_id(wire=w))) for w in self.b.bus]
        else:
            self.circuit_wires.append((self.a, f"{self.a.name}", self.save_wire_id(wire=self.a)))
            self.circuit_wires.append((self.b, f"{self.b.name}", self.save_wire_id(wire=self.b)))
            if hasattr(self, 'c'):
                self.circuit_wires.append((self.c, f"{self.c.name}", self.save_wire_id(wire=self.c)))

        for gate in self.circuit_gates:
            if not [item for item in self.circuit_wires if gate.a.name == item[1]]:
                self.circuit_wires.append((gate.a, gate.a.name, self.save_wire_id(wire=gate.a)))

            if hasattr(gate, 'b') and not [item for item in self.circuit_wires if gate.b.name == item[1]]:
                self.circuit_wires.append((gate.b, gate.b.name, self.save_wire_id(wire=gate.b)))

            if not [item for item in self.circuit_wires if gate.out.name == item[1]]:
                self.circuit_wires.append((gate.out, gate.out.name, self.save_wire_id(wire=gate.out)))

    def get_circuit_wire_index(self, wire: Wire):
        """Searches for circuit's wire unique index position within the circuit. Used for cgp chromosome generation.

        Args:
            wire (Wire): Wire to retrieve index position of.

        Returns:
            int: Wire's index position number within the circuit.
        """
        if wire.is_const():
            return wire.cgp_const
        else:
            for w in self.circuit_wires:
                if wire.name == w[1]:
                    return w[2]

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

    def get_declaration_c_flat(self):
        """Generates flat C code declaration of input/output circuit wires.

        Returns:
            str: Flat C code arithmetic circuit's wires declaration.
        """
        return f"".join([c.get_declaration_c_flat() for c in self.components])

    def get_init_c_flat(self):
        """Generates flat C code initialization and assignment of corresponding arithmetic circuit's input/output wires.

        Returns:
            str: Flat C code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_assign_c_flat() if isinstance(c, TwoInputLogicGate) else c.get_init_c_flat() for c in self.components])

    def get_function_out_c_flat(self):
        """Generates flat C code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flat C code containing output bus wires assignment.
        """
        return self.out.return_bus_wires_values_c_flat()

    # Generating flat C code representation of circuit
    def get_c_code_flat(self, file_object):
        """Generates flat C code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declaration_c_flat()+"\n")
        file_object.write(self.get_init_c_flat()+"\n")
        file_object.write(self.get_function_out_c_flat())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_blocks_c(self):
        """Generates hierarchical C code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical C code of all subcomponents function blocks description.
        """
        # Retrieve all unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_function_block_c(self):
        """Generates hierarchical C code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical C code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(N=self.N, prefix="b"), prefix=circuit_prefix)
        return f"{circuit_block.get_circuit_c()}\n\n"

    def get_declarations_c_hier(self):
        """Generates hierarchical C code declaration of input/output circuit wires.

        Returns:
            str: Hierarchical C code containing unique declaration of arithmetic circuit wires.
        """
        return "".join([c.get_declaration_c_hier() for c in self.components])

    def get_declaration_c_hier(self):
        """Generates hierarchical C code declaration of corresponding subcomponent input/output wires inside the upper component.

        Generates wires used to connect input/output values to/from invocation of the corresponding function block into inner wires present
        inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code of subcomponent arithmetic circuit's wires declaration.
        """
        return f"  {self.c_data_type} {self.a.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.b.prefix} = 0;\n" + \
               f"  {self.c_data_type} {self.out.prefix} = 0;\n"

    def get_init_c_hier(self):
        """Generates hierarchical C code initialization and assignment of corresponding arithmetic circuit's input/output wires.

        Returns:
            str: Hierarchical C code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_gate_invocation_c() if isinstance(c, TwoInputLogicGate) else c.get_out_invocation_c(circuit_prefix=self.prefix) for c in self.components])

    def get_out_invocation_c(self, circuit_prefix: str):
        """Generates hierarchical C code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical C code of subcomponent's C function invocation and output assignment.
        """
        # Getting name of circuit type for proper C code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        return self.a.return_bus_wires_values_c_hier() + self.b.return_bus_wires_values_c_hier() + \
            f"  {self.out.prefix} = {circuit_type}({self.a.prefix}, {self.b.prefix});\n"

    def get_function_out_c_hier(self):
        """Generates hierarchical C code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Hierarchical C code containing output bus wires assignment.
        """
        return self.out.return_bus_wires_values_c_hier()

    def get_circuit_c(self):
        """Generates hierarchical C code subcomponent's function block.

        Returns:
            str: Hierarchical C code of subcomponent's function block.
        """
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_declarations_c_hier()}\n" + \
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

    def get_declaration_v_flat(self):
        """Generates flat Verilog code declaration of input/output circuit wires.

        Returns:
            str: Flat Verilog code arithmetic circuit's wires declaration.
        """
        return f"".join([c.get_declaration_v_flat() for c in self.components])

    def get_init_v_flat(self):
        """Generates flat Verilog code initialization and assignment of corresponding arithmetic circuit's input/output buses wires.

        Returns:
            str: Flat Verilog code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_assign_v_flat() if isinstance(c, TwoInputLogicGate) else c.get_init_v_flat() for c in self.components])

    def get_function_out_v_flat(self):
        """Generates flat Verilog code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flat Verilog code containing output bus wires assignment.
        """
        return self.out.return_bus_wires_values_v_flat()

    # Generating flat Verilog code representation of circuit
    def get_v_code_flat(self, file_object):
        """Generates flat Verilog code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_prototype_v())
        file_object.write(self.get_declaration_v_flat()+"\n")
        file_object.write(self.get_init_v_flat() + "\n")
        file_object.write(self.get_function_out_v_flat())
        file_object.write(f"endmodule")
        file_object.close()

    # HIERARCHICAL VERILOG #
    def get_function_blocks_v(self):
        """Generates hierarchical Verilog code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical Verilog code of all subcomponents function blocks description.
        """
        # Retrieve all unique component types composing this circuit
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_v() for c in self.component_types])

    def get_function_block_v(self):
        """Generates hierarchical Verilog code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Verilog code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(N=self.N, prefix="b"), prefix=circuit_prefix)
        return f"{circuit_block.get_circuit_v()}\n\n"

    def get_declarations_v_hier(self):
        """Generates hierarchical Verilog code declaration of input/output circuit wires.

        Returns:
            str: Hierarchical Verilog code containing unique declaration of arithmetic circuit wires.
        """
        return "".join([c.get_declaration_v_hier() for c in self.components])

    def get_declaration_v_hier(self):
        """Generates hierarchical Verilog code declaration of corresponding subcomponent input/output wires inside the upper component.

        Generates wires used to connect input/output values to/from invocation of the corresponding function block into inner wires present
        inside the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent arithmetic circuit's wires declaration.
        """
        return f"  wire [{self.a.N-1}:0] {self.a.prefix};\n" + \
               f"  wire [{self.b.N-1}:0] {self.b.prefix};\n" + \
               f"  wire [{self.out.N-1}:0] {self.out.prefix};\n"

    def get_init_v_hier(self):
        """Generates hierarchical Verilog code initialization and assignment of corresponding arithmetic circuit's input/output wires.

        Returns:
            str: Hierarchical Verilog code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_gate_invocation_v() if isinstance(c, TwoInputLogicGate) else c.get_out_invocation_v(circuit_prefix=self.prefix) for c in self.components])

    def get_out_invocation_v(self, circuit_prefix: str):
        """Generates hierarchical Verilog code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent's module invocation and output assignment.
        """
        # Getting name of circuit type and insitu copying out bus for proper Verilog code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        return self.a.return_bus_wires_values_v_hier() + self.b.return_bus_wires_values_v_hier() + \
            f"  {circuit_type} {circuit_type}_{self.out.prefix}({self.a.prefix}, {self.b.prefix}, {self.out.prefix});\n"

    def get_function_out_v_hier(self):
        """Generates hierarchical Verilog code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Hierarchical Verilog code containing output bus wires assignment.
        """
        return self.out.return_bus_wires_values_v_hier()

    def get_circuit_v(self):
        """Generates hierarchical Verilog code subcomponent's function block.

        Returns:
            str: Hierarchical Verilog code of subcomponent's function block.
        """
        return f"{self.get_prototype_v()}" + \
               f"{self.get_declarations_v_hier()}\n" + \
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
        """Generates flat Blif code declaration of input/output circuit wires.

        Returns:
            str: Flat Blif code containing declaration of circuit's wires.
        """
        if self.N == 1:
            return f".inputs {self.a.prefix} {self.b.prefix}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f".names vdd\n1\n" + \
                   f".names gnd\n0\n"
        else:
            return f".inputs{self.a.get_wire_declaration_blif()}{self.b.get_wire_declaration_blif()}\n" + \
                   f".outputs{self.out.get_wire_declaration_blif()}\n" + \
                   f".names vdd\n1\n" + \
                   f".names gnd\n0\n"

    def get_function_blif_flat(self):
        """Generates flat Blif code with invocation of subcomponents logic gates functions via their corresponding truth tables.

        Returns:
            str: Flat Blif code containing invocation of inner subcomponents logic gates Boolean functions.
        """
        return "".join(c.get_function_blif_flat() for c in self.components)

    def get_function_out_blif(self):
        """Generates flat Blif code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flat Blif code containing output bus wires assignment.
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
    def get_invocations_blif_hier(self):
        """Generates hierarchical Blif code with invocations of subcomponents function blocks.

        Returns:
            str: Hierarchical Blif code containing invocations of inner subcomponents function blocks.
        """
        return "".join(c.get_invocation_blif_hier(circuit_prefix=self.prefix) for c in self.components)

    def get_invocation_blif_hier(self, circuit_prefix: str):
        """Generates hierarchical Blif code invocation of corresponding arithmetic circuit's generated function block.

        Used for multi-bit subcomponent's modul invocation.

        Args:
            circuit_prefix (str): Prefix name of the upper component from which function block is being invoked.

        Returns:
            str: Hierarchical Blif code of subcomponent's model invocation and output assignment.
        """
        # Getting name of circuit type for proper Blif code generation without affecting actual generated composition
        circuit_type = self.prefix.replace(circuit_prefix+"_", "")
        return f"{self.a.get_wire_assign_blif(output=True)}" + \
               f"{self.b.get_wire_assign_blif(output=True)}" + \
               f".subckt {circuit_type}" + \
               "".join([f" a[{self.a.bus.index(w)}]={self.a.prefix}[{self.a.bus.index(w)}]" for w in self.a.bus]) + \
               "".join([f" b[{self.b.bus.index(w)}]={self.b.prefix}[{self.b.bus.index(w)}]" for w in self.b.bus]) + \
               "".join([f" {circuit_type}_out[{self.out.bus.index(o)}]={o.name}" for o in self.out.bus]) + "\n"

    def get_circuit_blif(self):
        """Generates hierarchical Blif code subcomponent's function block.

        Returns:
            str: Hierarchical Blif code of subcomponent's function block.
        """
        return f"{self.get_prototype_blif()}" + \
               f"{self.get_declaration_blif()}" + \
               f"{self.get_invocations_blif_hier()}" + \
               f"{self.get_function_out_blif()}" + \
               f".end\n"

    def get_function_blocks_blif(self):
        """Generates hierarchical Blif code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical Blif code of all subcomponents function blocks description.
        """
        # Retrieve all unique component types composing this circuit
        # (iterating backwards as opposed to other representations so the top modul is always above its subcomponents)
        self.component_types = self.get_component_types()
        return "\n".join([c.get_function_block_blif() for c in self.component_types[::-1]])

    def get_function_block_blif(self):
        """Generates hierarchical Blif code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Blif code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        circuit_prefix = self.__class__(a=Bus("a"), b=Bus("b")).prefix + str(self.N)
        circuit_block = self.__class__(a=Bus(N=self.N, prefix="a"), b=Bus(N=self.N, prefix="b"), prefix=circuit_prefix)
        return f"{circuit_block.get_circuit_blif()}"

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

    def get_triplets_cgp(self):
        """Generates list of logic gate triplets (first input wire, second input wire, logic gate function) using wires unique position indexes within the described circuit.

        Each triplet represents unique logic gate within the described arithmetic circuit. Besides the contained input wires indexes and gate's inner logic function, an output wire
        with incremented index position is also created and remembered to be appropriately driven as an input to another logic gate or as the circuit's output.

        Constant wire with value 0 has constant index of 0.
        Constant wire with value 1 has constant index of 1.
        Other wires indexes start counting from 2 and up.

        Returns:
            str: List of triplets each describing logic function of corresponding two input logic gate and as a whole describe the arithmetic circuit.
        """
        self.get_cgp_wires()
        return "".join([g.get_triplet_cgp(a_id=self.get_circuit_wire_index(g.a)) if isinstance(g, OneInputLogicGate) else
                       g.get_triplet_cgp(a_id=self.get_circuit_wire_index(g.a), b_id=self.get_circuit_wire_index(g.b)) for g in self.circuit_gates])

    def get_outputs_cgp(self):
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
        file_object.write(self.get_triplets_cgp())
        file_object.write(self.get_outputs_cgp())
        file_object.close()
