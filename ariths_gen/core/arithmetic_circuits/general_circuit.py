from ariths_gen.core.logic_gate_circuits.logic_gate_circuit import (
    OneInputLogicGate,
    TwoInputLogicGate
)
from ariths_gen.wire_components import (
    Wire,
    Bus
)
from typing import Dict
import inspect
import copy
from io import StringIO


class GeneralCircuit():
    """Class represents a general circuit and ensures its generation to various representations.

    The __init__ method fills some mandatory attributes concerning arithmetic circuit
    that are later used for generation into various representations.
    """
    def __init__(self, prefix: str, name: str, out_N: int, inner_component: bool = False, inputs: list = [], one_bit_circuit: bool = False, signed: bool = False, signed_out = None, outname=None, **kwargs):
        if prefix == "":
            self.prefix = name
        else:
            self.prefix = prefix + "_" + name
        self.inner_component = inner_component

        # Dynamic input bus assignment
        self.inputs = []
        for i, input in enumerate(inputs):
            attr_name = chr(97+i)
            full_prefix = f"{self.prefix}_{input.prefix}" if self.inner_component else f"{input.prefix}"
            if isinstance(input, Bus) or isinstance(input, Wire):
                circuit_input = input
                circuit_input.prefix = full_prefix
            setattr(self, attr_name, circuit_input)
            self.inputs.append(circuit_input)
            # If the input bus is an output bus, connect it
            if isinstance(input, Bus) and input.is_output_bus():
                getattr(self, attr_name).connect_bus(connecting_bus=input)

        if not outname:
            outname = self.prefix+"_out"

        if signed_out is None:
            signed_out = signed
        self.out = Bus(outname, out_N, out_bus=True, signed=signed_out)

        self.components = []
        self._prefixes = [] # TODO rename to fullname and add distinct attr for prefix, name, suffix
        self.circuit_gates = []
        self.circuit_wires = []
        self.signed = signed
        self.signed_out = signed_out
        self.c_data_type = "int64_t" if self.signed is True else "uint64_t"
        self.pyc = None  # Python compiled function
        self.kwargs = kwargs

    def __call__(self, *args):
        if not self.pyc:
            buf = StringIO()
            self.get_python_code_flat(buf)

            globs, locs = {}, {}
            exec(buf.getvalue(), globs, locs)
            self.pyc = locs[self.prefix]

        return self.pyc(*args)

    def __str__(self):
        return f"<{type(self).__name__} prefix={self.prefix} " + (", ".join([f"input={i}" for i in self.inputs])) + ">"
        # super().__init__(prefix, name, out_N, inner_component, inputs=[a, b], signed=signed, **kwargs)

    def get_hier_subcomponent_def(self, parent_kwargs: dict = {}):
        """ Creates and returns a new instance of the current circuit block used for definition of a subcomponent in a hierarchical circuit.

        Args:
            parent_kwargs (dict): Dictionary containing all the configuration settings of the parent circuit block.

        Returns:
            GeneralCircuit: A new instance of the current circuit block with proper prefix and input wires.
        """
        # Obtain proper circuit name with its input bit widths
        init_signature = inspect.signature(self.__class__.__init__)
        init_params = list(init_signature.parameters.keys())
        default_circuit_name = init_signature.parameters['name'].default
        circuit_type = default_circuit_name + "x".join(str(getattr(self, chr(97+i)).N) for i, _ in enumerate(self.inputs))
        # Initialize and fill args for the new instance based on the current instance
        init_args = {}

        for param in init_params[1:]:  # Skip 'self'
            attr = getattr(self, param, None)  # Get the attribute from the current instance

            if attr is not None:  # If attribute does not exist, it will use default value from the signature
                if isinstance(attr, Bus):  # If the input is a Bus, create a copy of the Bus object with same length, but proper prefix
                    init_args[param] = Bus(N=attr.N, prefix=param)
                elif isinstance(attr, Wire):  # If the input is a Wire, create a copy of the Wire object with proper prefix
                    init_args[param] = Wire(name=param)
                else:  # Copy other types of attributes
                    init_args[param] = copy.deepcopy(attr)

        init_args['name'] = circuit_type
        init_args['prefix'] = ""

        circuit_block = self.__class__(**init_args, **parent_kwargs)
        return circuit_block

    def get_circuit_def(self) -> Dict[str, Wire]:
        """ returns IDs and wires of the inputs and output"""
        # TODO delete? (probably replaced by get_hier_subcomponent_def)
        #.{circuit_block.a.prefix}({self.a.prefix}), .{circuit_block.b.prefix}({self.b.prefix}), .{circuit_block.out.prefix}({self.out.prefix}));\n"
        r = {chr(97 + i): self.inputs[i] for i in range(len(self.inputs))}
        r['out'] = self.get_global_prefix() + "_out"
        return r

    def add_component(self, component):
        """Adds a component into list of circuit's inner subcomponents.
        
        Additionally it adds all the gates of the component to the circuit's list of gates and all
        sbcomponents prefixes to check for naming duplicates which could cause issues in the circuit generation.

        Args:
            component: Subcomponent to be added into list of components composing described circuit.
        """
        # TODO should be refactored in ArithsGen rework
        # We should probably check also wire names for especially hierarchical generation
        if isinstance(component, TwoInputLogicGate):
            if component.disable_generation is False:
                self.circuit_gates.append(component)
        else:
            self.circuit_gates.extend(component.get_circuit_gates())
            for prefix in component._prefixes:
                assert prefix not in self._prefixes, f"Component with prefix {prefix} already exists in the circuit."
            self._prefixes.extend(component._prefixes)

        assert component.prefix not in self._prefixes, f"Component with prefix {component.prefix} already exists in the circuit."
        self._prefixes.append(component.prefix)
        self.components.append(component)
        return component

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
        
    def get_circuit_gates(self, verilog_output: bool = False):
        """Gets a list of all the logic gates in circuit that should be generated.

        Args:            
            verilog_output (bool): Specifies whether the call has been invoked by a verilog output generation method.
        Returns:
            list: List of composite logic gates.
        """
        gates = []
        for c in self.components:
            if isinstance(c, TwoInputLogicGate):
                if (c.disable_generation is False) and (verilog_output is False or getattr(c, "use_verilog_instance", False) is False):
                    gates.append(c)
            else:
                # Check whether it is necessary to use gates for the Verilog component
                # description (ArithsGen internally defined comp) or not (technology specific instance)
                if verilog_output is False or ((hasattr(c, "use_verilog_instance") and c.use_verilog_instance is False) or hasattr(c, "use_verilog_instance") is False):
                    gates.extend(c.get_circuit_gates(verilog_output))
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
            elif all(isinstance(i, Wire) for i in self.inputs):
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
            elif all(isinstance(i, Wire) for i in self.inputs):
                continue
            else:
                multi_bit_comps.append(c)
                multi_bit_comps.extend(c.get_multi_bit_components())
        return multi_bit_comps

    @staticmethod
    def get_unique_types(components: list, multi_bit: bool = False):
        """Retrieves just the unique representatives of class types present inside the provided components list.

        Args:
            components (list): List of components to be filtered.
            multi_bit (bool): Specifies whether the provided components list is composed of multi bit type circuits. Defaults to False.

        Returns:
            list: List of unique composite class types.
        """
        if multi_bit is True:
            return list({(type(c), tuple(i.N for i in c.inputs)): c for c in components[::-1]}.values())
        else:
            return list({type(c): c for c in components}.values())

    def get_component_types(self, verilog_output: bool = False):
        """Retrieves a list of all the unique types of subcomponents composing the circuit.

        Returning list consists of only the unique types of logic gates, one bit circuits and multi bit circuits.

        Args:
            verilog_output (bool): Specifies whether the call has been invoked by a verilog output generation method.
        Returns:
            list: List of unique component types describing the circuit.
        """
        gate_comps = self.get_unique_types(components=self.get_circuit_gates(verilog_output))
        one_bit_comps = self.get_unique_types(
            components=self.get_one_bit_components())
        multi_bit_comps = self.get_unique_types(components=self.get_multi_bit_components(),
                                                multi_bit=True)

        all_components = gate_comps + one_bit_comps + multi_bit_comps
        return all_components

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
            return len(self.circuit_wires)+2

    def get_circuit_wires(self):
        """Gets a list of all wires in circuit along with their index position for cgp chromosome generation and stores them inside `self.circuit_wires` list.

        Constant wire with value 0 has constant index of 0.
        Constant wire with value 1 has constant index of 1.
        Other wires indexes start counting from 2 and up.
        """
        circuit_wires_names = []

        for input in self.inputs:
            if isinstance(input, Bus):
                [self.circuit_wires.append(
                    (w, f"{w.name}", self.save_wire_id(wire=w))) for w in input.bus]
                [circuit_wires_names.append(w.name) for w in input.bus]
            else:
                self.circuit_wires.append(
                    (input, f"{input.name}", self.save_wire_id(wire=input)))
                circuit_wires_names.append(input.name)

        for gate in self.circuit_gates:
            if gate.a.name not in circuit_wires_names:
                self.circuit_wires.append(
                    (gate.a, gate.a.name, self.save_wire_id(wire=gate.a)))
                circuit_wires_names.append(gate.a.name)

            if hasattr(gate, 'b') and gate.b.name not in circuit_wires_names:
                self.circuit_wires.append(
                    (gate.b, gate.b.name, self.save_wire_id(wire=gate.b)))
                circuit_wires_names.append(gate.b.name)

            if gate.out.name not in circuit_wires_names:
                self.circuit_wires.append(
                    (gate.out, gate.out.name, self.save_wire_id(wire=gate.out)))
                circuit_wires_names.append(gate.out.name)
                

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

    """ PYTHON CODE GENERATION """
    # FLAT PYTHON #
    def get_prototype_python(self):
        """Generates Python code function header to describe corresponding arithmetic circuit's interface in Python code.

        Returns:
            str: Function's name and parameters in Python code.
        """
        return f"def {self.prefix}(" + ", ".join([f"{x.prefix}" for x in self.inputs]) + ")" + ":" + "\n"

    def get_init_python_flat(self):
        """Generates flat Python code initialization and assignment of corresponding arithmetic circuit's input/output wires.

        Returns:
            str: Flat Python code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_assign_python_flat() if isinstance(c, TwoInputLogicGate) else c.get_init_python_flat() for c in self.components])

    def get_function_out_python_flat(self):
        """Generates flat Python code assignment of corresponding arithmetic circuit's output bus wires.

        Returns:
            str: Flat Python code containing output bus wires assignment.
        """
        return self.out.return_bus_wires_values_python_flat()

    # Generating flat Python code representation of circuit

    def get_python_code_flat(self, file_object, retype=True):
        """Generates flat Python code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
            retype (bool) specifies if signed output should return int64_t
        """
        file_object.write(self.get_prototype_python())
        file_object.write(self.get_init_python_flat()+"\n")
        file_object.write(self.get_function_out_python_flat())
        file_object.write(self.out.return_bus_wires_sign_extend_python_flat(retype=True))
        file_object.write(f"  return {self.out.prefix}"+"\n")

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
        return f"{self.c_data_type} {self.prefix}(" + ",".join([f"{self.c_data_type} {x.prefix}" for x in self.inputs]) + ")" + "{" + "\n"

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
        file_object.write(self.out.return_bus_wires_sign_extend_c_flat())
        file_object.write(f"  return {self.out.prefix}"+";\n}")

    # HIERARCHICAL C #
    def get_function_blocks_c(self):
        """Generates hierarchical C code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical C code of all subcomponents function blocks description.
        """
        # Retrieve all unique component types composing this circuit and add them kwargs from the parent circuit to allow propagatation of config settings for subcomponents
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_function_block_c(self):
        """Generates hierarchical C code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical C code of multi-bit arithmetic circuit's function block description.
        """
        return f"{self.get_hier_subcomponent_def(parent_kwargs=self.kwargs).get_circuit_c()}\n\n"

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
        return "".join([f"  {self.c_data_type} {i.prefix} = 0;\n" for i in self.inputs if ((isinstance(i, Wire)) or (not all((w.is_const()) or (w.parent_bus is not None and w.prefix == i.prefix) for w in i.bus)))]) + \
               f"  {self.c_data_type} {self.out.prefix} = 0;\n"

    def get_init_c_hier(self):
        """Generates hierarchical C code initialization and assignment of corresponding arithmetic circuit's input/output wires.

        Returns:
            str: Hierarchical C code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_gate_invocation_c() if isinstance(c, TwoInputLogicGate) else c.get_out_invocation_c() for c in self.components])

    def get_out_invocation_c(self):
        """Generates hierarchical C code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical C code of subcomponent's C function invocation and output assignment.
        """
        # Getting name of circuit type for proper C code generation without affecting actual generated composition
        init_signature = inspect.signature(self.__class__.__init__)
        default_circuit_name = init_signature.parameters['name'].default
        circuit_type = default_circuit_name + "x".join(str(getattr(self, chr(97+i)).N) for i, _ in enumerate(self.inputs))
        # TODO .. now only works for input buses
        return "".join(w.return_bus_wires_values_c_hier() for w in self.inputs) + \
               f"  {self.out.prefix} = {circuit_type}({', '.join(w.prefix if isinstance(w, Bus) else w.get_wire_value_c_hier() for w in self.inputs)});\n"

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
               f"{self.out.return_bus_wires_sign_extend_c_hier()}" + \
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

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        """Generates Verilog code module header to describe corresponding arithmetic circuit's interface in Verilog code.

        Returns:
            str: Module's name and parameters in Verilog code.
        """
        return f"module {self.prefix}(" + ", ".join(f"input [{x.N-1}:0] {x.prefix}" for x in self.inputs) + f", output [{self.out.N-1}:0] {self.out.prefix});\n"

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

    # HIERARCHICAL VERILOG #
    def get_function_blocks_v(self):
        """Generates hierarchical Verilog code representation of all subcomponents function blocks present in corresponding arithmetic circuit.

        Returns:
            str: Hierarchical Verilog code of all subcomponents function blocks description.
        """
        # Retrieve all unique component types composing this circuit and add them kwargs from the parent circuit to allow propagatation of config settings for subcomponents
        self.component_types = self.get_component_types(verilog_output=True)
        return "".join([c.get_function_block_v() for c in self.component_types])

    def get_function_block_v(self):
        """Generates hierarchical Verilog code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Verilog code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        return f"{self.get_hier_subcomponent_def(parent_kwargs=self.kwargs).get_circuit_v()}\n\n"

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
        return "".join(b.get_wire_declaration_v() for b in self.inputs + [self.out] if (b == self.out) or (not all((w.is_const()) or (w.parent_bus is not None and w.prefix == b.prefix) for w in b.bus)))

    def get_init_v_hier(self):
        """Generates hierarchical Verilog code initialization and assignment of corresponding arithmetic circuit's input/output wires.

        Returns:
            str: Hierarchical Verilog code initialization of arithmetic circuit wires.
        """
        return "".join([c.get_gate_invocation_v() if isinstance(c, TwoInputLogicGate) else c.get_out_invocation_v() for c in self.components])

    def get_out_invocation_v(self):
        """Generates hierarchical Verilog code invocation of corresponding arithmetic circuit's generated function block.

        Assigns input values from other subcomponents into multi-bit input buses used as inputs for function block invocation.
        Assigns output values from invocation of the corresponding function block into inner wires present inside
        the upper component from which function block has been invoked.

        Returns:
            str: Hierarchical Verilog code of subcomponent's module invocation and output assignment.
        """
        # Getting name of circuit type and insitu copying out bus for proper Verilog code generation without affecting actual generated composition
        init_signature = inspect.signature(self.__class__.__init__)
        default_circuit_name = init_signature.parameters['name'].default
        circuit_type = default_circuit_name + "x".join(str(getattr(self, chr(97+i)).N) for i, _ in enumerate(self.inputs))
        circuit_block = self.get_hier_subcomponent_def(parent_kwargs=self.kwargs)
        # TODO .. now only works for input buses
        return "".join([c.return_bus_wires_values_v_hier() for c in self.inputs]) + \
               f"  {circuit_type} {circuit_type}_{self.out.prefix}(" + ",".join([f".{a.prefix}({b.prefix})" for a, b in zip(circuit_block.inputs, self.inputs)]) + f", .{circuit_block.out.prefix}({self.out.prefix}));\n"

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
        return f".inputs {''.join([w.get_wire_declaration_blif() for w in self.inputs])}\n" + \
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









    # HIERARCHICAL BLIF #
    def get_invocations_blif_hier(self):
        """Generates hierarchical Blif code with invocations of subcomponents function blocks.

        Returns:
            str: Hierarchical Blif code containing invocations of inner subcomponents function blocks.
        """
        return "".join(c.get_invocation_blif_hier() for c in self.components)

    def get_invocation_blif_hier(self):
        """Generates hierarchical Blif code invocation of corresponding arithmetic circuit's generated function block.

        Used for multi-bit subcomponent's modul invocation.

        Returns:
            str: Hierarchical Blif code of subcomponent's model invocation and output assignment.
        """
        # Getting name of circuit type for proper Blif code generation without affecting actual generated composition
        init_signature = inspect.signature(self.__class__.__init__)
        default_circuit_name = init_signature.parameters['name'].default
        circuit_type = default_circuit_name + "x".join(str(getattr(self, chr(97+i)).N) for i, _ in enumerate(self.inputs))
        if self.out.N > 1:
            return "".join([w.get_wire_assign_blif(output=True) for w in self.inputs]) + \
                   f".subckt {circuit_type}" + \
                   "".join([f" {chr(97+i)}[{b.bus.index(w)}]={b.prefix}[{b.bus.index(w)}]" if b.N > 1 else f" {chr(97+i)}={b.prefix}" for i, b in enumerate(self.inputs) for w in b.bus]) + \
                   "".join([f" {circuit_type}_out[{self.out.bus.index(o)}]={o.name}" for o in self.out.bus if not o.is_const()]) + "\n"
        else:
            return "".join([w.get_wire_assign_blif(output=True) for w in self.inputs]) + \
                   f".subckt {circuit_type}" + \
                   "".join([f" {chr(97+i)}[{b.bus.index(w)}]={b.prefix}[{b.bus.index(w)}]" if b.N > 1 else f" {chr(97+i)}={b.prefix}" for i, b in enumerate(self.inputs) for w in b.bus]) + \
                   "".join([f" {circuit_type}_out={o.name}" for o in self.out.bus if not o.is_const()]) + "\n"
            
        # TODO delete
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
        # Retrieve all unique component types composing this circuit and add them kwargs from the parent circuit to allow propagatation of config settings for subcomponents
        # (iterating backwards as opposed to other representations so the top modul is always above its subcomponents)
        self.component_types = self.get_component_types()
        return "\n".join([c.get_function_block_blif() for c in self.component_types[::-1]])

    def get_function_block_blif(self):
        """Generates hierarchical Blif code representation of corresponding multi-bit arithmetic circuit used as function block in hierarchical circuit description.

        Returns:
            str: Hierarchical Blif code of multi-bit arithmetic circuit's function block description.
        """
        # Obtain proper circuit name with its bit width
        return f"{self.get_hier_subcomponent_def(parent_kwargs=self.kwargs).get_circuit_blif()}"

    # Generating hierarchical BLIF code representation of circuit
    def get_blif_code_hier(self, file_object):
        """Generates hierarchical Blif code representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_circuit_blif()+"\n")
        file_object.write(self.get_function_blocks_blif())

    """ CGP CODE GENERATION """
    # FLAT CGP #

    def get_parameters_cgp(self):
        """Generates CGP chromosome parameters of corresponding arithmetic circuit.

        In total seven parameters represent: total inputs, total outputs, number of rows, number of columns (gates),
        number of each gate's inputs, number of each gate's outputs, quality constant value.

        Returns:
            str: CGP chromosome parameters of described arithmetic circuit.
        """
        # self.circuit_gates = self.get_circuit_gates() TODO delete
        return f"{{{sum(input_bus.N for input_bus in self.inputs)},{self.out.N},1,{len(self.circuit_gates)},2,1,0}}"

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
        self.get_circuit_wires()
        return "".join([g.get_triplet_cgp(a_id=self.get_circuit_wire_index(g.a), out_id=self.get_circuit_wire_index(g.out)) if isinstance(g, OneInputLogicGate) else
                       g.get_triplet_cgp(a_id=self.get_circuit_wire_index(g.a), b_id=self.get_circuit_wire_index(g.b), out_id=self.get_circuit_wire_index(g.out)) for g in self.circuit_gates])

    def get_outputs_cgp(self):
        """Generates list of output wires indexes of described arithmetic circuit from MSB to LSB.

        Returns:
            str: List of arithmetic circuit's output wire indexes.
        """
        return "(" + ",".join([str(self.get_circuit_wire_index(o)) for o in self.out.bus]) + ")"

    # Generating flat CGP chromosome representation of circuit
    def get_cgp_code_flat(self, file_object):
        """Generates flat CGP chromosome representation of corresponding arithmetic circuit.

        Args:
            file_object (TextIOWrapper): Destination file object where circuit's representation will be written to.
        """
        file_object.write(self.get_parameters_cgp())
        file_object.write(self.get_triplets_cgp())
        file_object.write(self.get_outputs_cgp())
