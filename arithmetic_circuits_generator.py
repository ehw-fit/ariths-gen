from wire_components import wire, bus
from logic_gates_generator import not_gate, and_gate, xor_gate, or_gate, nand_gate, xnor_gate, nor_gate
import sys
import itertools


""" ARITHMETIC CIRCUITS """


class arithmetic_circuit():
    def __init__(self):
        self.components = []
        self.circuit_wires = []
        self.c_data_type = "uint64_t"
        self.N = 1

        # TODO delete?
        self.carry_out_gate = None
        self.sum_out_gates = []

    def add_component(self, component):
        self.components.append(component)

    def get_previous_component(self):
        return self.components[-1]

    def get_component_types(self):
        return list({type(c): c for c in self.components}.values())

    def get_unique_types(self):
        hier_components = self.all_gates + self.component_types
        return list({type(c): c for c in hier_components}.values())

    def get_gate_types(self):
        return list({type(g): g for g in self.all_gates}.values())

    def get_sum_wire(self):
        return self.out.get_wire(0)

    def get_carry_wire(self):
        return self.out.get_wire(1)

    def get_circuit_wires(self):
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name))

            if not [item for item in self.circuit_wires if item[1] == component.output.name]:
                self.circuit_wires.append((component.output, component.output.name))

    """ C CODE GENERATION """
    # FLAT C #
    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"uint64_t {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + "\n"

    def get_declaration_c_flat(self):
        return f"".join([c.get_declaration_c_flat() for c in self.components])

    def get_init_c_flat(self):
        return "".join([c.get_init_c_flat() for c in self.components])

    def get_function_sum_c_flat(self):
        return "".join([c.get_function_sum_c_flat(offset=self.components.index(c)) for c in self.components])

    def get_function_carry_c_flat(self):
        return f"{self.get_previous_component().get_function_carry_c_flat(offset=self.out.N-1)}"

    # Generating flat C code representation of circuit
    def get_c_code_flat(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declaration_c_flat()+"\n")
        file_object.write(self.get_init_c_flat()+"\n")
        file_object.write(self.get_function_sum_c_flat())
        file_object.write(self.get_function_carry_c_flat())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()

    # HIERARCHICAL C #
    def get_function_blocks_c(self):
        # Add unique 1-bit adder components (ha, fa)
        self.component_types = self.get_component_types()
        # Add unique logic gates composing subcomponents
        self.all_gates = list(itertools.chain.from_iterable([c.get_component_types() for c in self.component_types]))
        self.component_types = self.get_unique_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_declaration_c_hier(self):
        self.cout = bus(N=self.N-1, prefix="cout")
        return "".join(self.a.get_wire_declaration_c()) + \
               "".join(self.b.get_wire_declaration_c()) + \
               "".join(self.cout.get_wire_declaration_c())

    def get_init_sum_c_hier(self):
        self.in_wires = self.a.bus + self.b.bus
        return ";\n".join([f"  {w.name} = " + w.get_wire_value_c(offset=int(w.name[2:])) for w in self.in_wires])

    def get_init_cout_c_hier(self):
        return "\n".join([c.get_invocation_c(wire_n=self.cout.get_wire(self.components.index(c)).name, offset=self.components.index(c)) for c in self.components[:-1]])

    def get_function_sum_c_hier(self):
        return ";\n".join([c.get_adder_sum(offset=self.components.index(c)) for c in self.components])+";\n"

    def get_function_carry_c_hier(self):
        return f"{self.get_previous_component().get_adder_cout(offset=self.out.N-1)};\n"

    def get_circuit_c(self):
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_declaration_c_hier()}\n" + \
               f"{self.get_init_sum_c_hier()};\n" + \
               f"{self.get_init_cout_c_hier()}\n\n" + \
               f"{self.get_function_sum_c_hier()}" + \
               f"{self.get_function_carry_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    # Generating hierarchical C code representation of circuit
    def get_c_code_hier(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_function_blocks_c())
        file_object.write(self.get_circuit_c())
        file_object.close()

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input [{self.N-1}:0] {self.a.prefix}, input [{self.N-1}:0] {self.b.prefix}, output [{self.N}:0] {self.out.prefix});\n"

    def get_declaration_v_flat(self):
        return f"".join([c.get_declaration_v_flat() for c in self.components])

    def get_init_v_flat(self, offset: int = 0, array: bool = False):
        return "".join([c.get_init_v_flat(offset=self.components.index(c), array=True) for c in self.components])

    def get_function_sum_cout_v_flat(self):
        return "".join([c.get_function_sum_cout_v_flat(offset=self.components.index(c)) for c in self.components])

    def get_function_sum_v_flat(self):
        return "".join([c.get_function_sum_v_flat(offset=self.components.index(c)) for c in self.components])

    def get_function_carry_v_flat(self):
        return f"{self.get_previous_component().get_function_carry_v_flat(offset=self.out.N-1)}"

    # Generating flat V code representation of circuit
    def get_v_code_flat(self, file_object):
        file_object.write(self.get_prototype_v())
        file_object.write(self.get_declaration_v_flat()+"\n")
        file_object.write(self.get_init_v_flat(array=False)+"\n")
        file_object.write(self.get_function_sum_v_flat())
        file_object.write(self.get_function_carry_v_flat())
        file_object.write(f"endmodule")
        file_object.close()


class half_adder(arithmetic_circuit):
    def __init__(self, a: wire, b: wire, prefix: str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", self.N+1)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor_gate = xor_gate(a, b, prefix, outid=0)
        self.add_component(obj_xor_gate)
        self.out.connect(0, obj_xor_gate.output)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and_gate = and_gate(a, b, prefix, outid=1)
        self.add_component(obj_and_gate)
        self.out.connect(1, obj_and_gate.output)

    """ C CODE GENERATION """
    # FLAT C #
    # Half adder function prototype with two inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name})" + "{" + "\n"

    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Half adder wires values initialization
    def get_init_c_flat(self):
        # self.a.prefix = self.a.name if self.a.prefix == "" else self.a.prefix
        # self.b.prefix = self.b.name if self.b.prefix == "" else self.b.prefix
        return f"  {self.components[0].a.name} = {self.a.get_wire_value_c(offset=self.a.index)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value_c(offset=self.b.index)};\n" + \
               f"  {self.components[0].output.name} = {self.components[0].get_init_c_flat()};\n" + \
               f"  {self.components[1].output.name} = {self.components[1].get_init_c_flat()};\n"

    def get_function_sum_c_flat(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.components[0].output.return_wire_value_c(offset=offset)};\n"

    def get_function_carry_c_flat(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.components[1].output.return_wire_value_c(offset=offset)};\n"

    # HIERARCHICAL C #
    def get_function_block_c(self):
        self.component_types = self.get_component_types()
        self.prefix = "ha"
        return f"{self.get_circuit_c()}\n\n"

    def get_function_blocks_c(self):
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_invocation_c(self, wire_n: str, offset: int = 0):
        self.prefix = "ha" if (offset == 0) else "fa"
        return f"  {wire_n} = ({self.prefix}({self.a.name}, {self.b.name}) >> 1) & 0x01;"

    def get_adder_sum(self, offset: int = 0):
        return f"  {self.out.prefix} |= (({self.prefix}({self.a.name}, {self.b.name}) >> 0) & 0x01) << {offset}"

    def get_adder_cout(self, offset: int = 1):
        return f"  {self.out.prefix} |= (({self.prefix}({self.a.name}, {self.b.name}) >> 1) & 0x01) << {offset}"

    def get_function_sum_c_hier(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.component_types[0].get_gate_output_c(a=self.a ,b=self.b, offset=offset)};\n"

    def get_function_carry_c_hier(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.component_types[1].get_gate_output_c(a=self.a ,b=self.b, offset=offset)};\n"

    def get_circuit_c(self):
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}\n" + \
               f"{self.get_function_sum_c_hier()}" + \
               f"{self.get_function_carry_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, output [{self.N}:0]{self.out.prefix});\n"

    def get_declaration_v_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires])

    # Half adder wires values initialization
    def get_init_v_flat(self, offset: int = 0, array: bool = False, ):
        self.a.prefix = self.a.name if self.a.prefix == "" else self.a.prefix
        self.b.prefix = self.b.name if self.b.prefix == "" else self.b.prefix
        return f"  assign {self.components[0].a.name} = {self.a.get_wire_value_v(offset=offset, array=array)};\n" + \
               f"  assign {self.components[0].b.name} = {self.b.get_wire_value_v(offset=offset, array=array)};\n" + \
               f"  assign {self.components[0].output.name} = {self.components[0].get_init_v_flat()};\n" + \
               f"  assign {self.components[1].output.name} = {self.components[1].get_init_v_flat()};\n"

    def get_function_sum_v_flat(self, offset: int = 0):
        return f"  assign {self.out.prefix}[{offset}] = {self.components[0].output.name};\n"

    def get_function_carry_v_flat(self, offset: int = 1):
        return f"  assign {self.out.prefix}[{offset}] = {self.components[1].output.name};\n"


class full_adder(arithmetic_circuit):
    def __init__(self, a: wire, b: wire, c: wire, prefix: str = "fa"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", self.N+1)

        # PG logic
        propagate_xor_gate1 = xor_gate(a, b, prefix, outid=0)
        self.add_component(propagate_xor_gate1)
        generate_and_gate1 = and_gate(a, b, prefix, outid=1)
        self.add_component(generate_and_gate1)

        # Sum
        # XOR gate for calculation of 1-bit sum
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.output, c, prefix, outid=2)
        self.add_component(obj_xor_gate2)
        self.out.connect(0, obj_xor_gate2.output)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and_gate2 = and_gate(propagate_xor_gate1.output, c, prefix, outid=3)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.output, obj_and_gate2.output, prefix, outid=4)
        self.add_component(obj_or_gate)

        self.out.connect(1, obj_or_gate.output)

        # TODO delete or leave?
        self.propagate = propagate_xor_gate1.output
        self.generate = generate_and_gate1.output

    """ C CODE GENERATION """
    # FLAT C #
    # Full adder function prototype with three inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name}, {self.c_data_type} {self.c.name})" + "{" + "\n"

    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Full adder wires values initialization
    def get_init_c_flat(self):
        self.a.prefix = self.a.name if self.a.prefix == "" else self.a.prefix
        self.b.prefix = self.b.name if self.b.prefix == "" else self.b.prefix
        self.c.prefix = self.c.name
        return f"  {self.components[0].a.name} = {self.a.get_wire_value_c(offset=self.a.index)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value_c(offset=self.b.index)};\n" + \
               f"  {self.components[2].b.name} = {self.c.get_wire_value_c()};\n" + \
               f"  {self.components[0].output.name} = {self.components[0].get_init_c_flat()};\n" + \
               f"  {self.components[1].output.name} = {self.components[1].get_init_c_flat()};\n" + \
               f"  {self.components[2].output.name} = {self.components[2].get_init_c_flat()};\n" + \
               f"  {self.components[3].output.name} = {self.components[3].get_init_c_flat()};\n" + \
               f"  {self.components[4].output.name} = {self.components[4].get_init_c_flat()};\n"

    def get_function_sum_c_flat(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.components[2].output.return_wire_value_c(offset=offset)};\n"

    def get_function_carry_c_flat(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.components[4].output.return_wire_value_c(offset=offset)};\n"

    # HIERARCHICAL C #
    def get_function_block_c(self):
        self.component_types = self.get_component_types()
        self.prefix = "fa"
        self.c.name = "cin"
        return f"{self.get_circuit_c()}\n\n"

    def get_function_blocks_c(self):
        self.component_types = self.get_component_types()
        return "".join([c.get_function_block_c() for c in self.component_types])

    def get_declaration_c_hier(self):
        self.component_types[0].a.name = "xor_1"
        self.component_types[2].a.name = "and_1"
        self.component_types[2].b.name = "and_2"
        return f"{self.component_types[0].a.get_declaration_c()}" + \
               f"{self.component_types[2].a.get_declaration_c()}" + \
               f"{self.component_types[2].b.get_declaration_c()}"

    def get_init_c_hier(self):
        return f"  {self.component_types[0].a.name} = {self.component_types[0].get_invocation_c(self.a, self.b)}\n" + \
               f"  {self.component_types[2].a.name} = {self.component_types[1].get_invocation_c(self.a, self.b)}\n" + \
               f"  {self.component_types[2].b.name} = {self.component_types[1].get_invocation_c(self.component_types[0].a, self.c)}\n"

    def get_invocation_c(self, wire_n: str, offset: int = 0):
        self.prefix = "ha" if (offset == 0) else "fa"
        self.c.name = "cout_"+str(offset-1)
        return f"  {wire_n} = ({self.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> 1) & 0x01;"

    def get_adder_sum(self, offset: int = 0):
        self.c.name = "cout_"+str(offset-1)
        return f"  {self.out.prefix} |= (({self.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> 0) & 0x01) << {offset}"

    def get_adder_cout(self, offset: int = 1):
        self.c.name = "cout_"+str(offset-2)
        return f"  {self.out.prefix} |= (({self.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> 1) & 0x01) << {offset}"

    def get_function_sum_c_hier(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.component_types[0].get_gate_output_c(a=self.component_types[0].a, b=self.c, offset=offset)};\n"

    def get_function_carry_c_hier(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.component_types[-1].get_gate_output_c(a=self.component_types[2].a, b=self.component_types[2].b, offset=offset)};\n"

    def get_circuit_c(self):
        self.component_types = self.component_types
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_declaration_c_hier()}\n" + \
               f"{self.get_init_c_hier()}\n" + \
               f"{self.get_function_sum_c_hier()}" + \
               f"{self.get_function_carry_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, input {self.c.name}, output [{self.N}:0]{self.out.prefix});\n"

    def get_declaration_v_flat(self):
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires])

    # Full adder wires values initialization
    def get_init_v_flat(self, offset: int = 0, array: bool = False):
        self.a.prefix = self.a.name if self.a.prefix == "" else self.a.prefix
        self.b.prefix = self.b.name if self.b.prefix == "" else self.b.prefix
        self.c.prefix = self.c.name
        return f"  assign {self.components[0].a.name} = {self.a.get_wire_value_v(offset=offset, array=array)};\n" + \
               f"  assign {self.components[0].b.name} = {self.b.get_wire_value_v(offset=offset, array=array)};\n" + \
               f"  assign {self.components[2].b.name} = {self.c.get_wire_value_v(offset=offset, array=array)};\n" + \
               f"  assign {self.components[0].output.name} = {self.components[0].get_init_v_flat()};\n" + \
               f"  assign {self.components[1].output.name} = {self.components[1].get_init_v_flat()};\n" + \
               f"  assign {self.components[2].output.name} = {self.components[2].get_init_v_flat()};\n" + \
               f"  assign {self.components[3].output.name} = {self.components[3].get_init_v_flat()};\n" + \
               f"  assign {self.components[4].output.name} = {self.components[4].get_init_v_flat()};\n"

    def get_function_sum_v_flat(self, offset: int = 0):
        return f"  assign {self.out.prefix}[{offset}] = {self.components[2].output.name};\n"

    def get_function_carry_v_flat(self, offset: int = 1):
        return f"  assign {self.out.prefix}[{offset}] = {self.components[4].output.name};\n"


class signed_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.c_data_type = "int64_t"
        # Bus sign extension in case buses have different lengths
        a.bus_extend(N=self.N, prefix=a.prefix)
        b.bus_extend(N=self.N, prefix=b.prefix)
        self.a = a
        self.b = b
        if prefix == "s_rca":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            # First one is a half adder
            if input_index == 0:
                obj_ha = half_adder(a.get_wire(input_index), b.get_wire(input_index), prefix=self.prefix+"_ha")
                self.add_component(obj_ha)
                self.out.connect(input_index, obj_ha)
            # Rest are full adders
            else:
                obj_fa = full_adder(a.get_wire(input_index), b.get_wire(input_index), self.get_previous_component().get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))
                self.add_component(obj_fa)
                self.out.connect(input_index, obj_fa.get_sum_wire())

                if input_index == (self.N-1):
                    self.out.connect(self.N, obj_fa.get_carry_wire())

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = xor_gate(self.get_previous_component().a, self.get_previous_component().b, prefix=self.prefix+"_xor_1")
        sign_xor_2 = xor_gate(sign_xor_1.output, self.get_previous_component().get_carry_wire(), prefix=self.prefix+"_xor_2")
        self.add_component(sign_xor_1)
        self.add_component(sign_xor_2)

    """ VERILOG CODE GENERATION """
    # FLAT C #
    # Initialization of 1-bit adders and sign extension XOR gates
    def get_init_c_flat(self):
        self.components[-2].output.prefix = self.components[-2].output.name
        self.components[-3].get_carry_wire().prefix = self.components[-3].get_carry_wire().name
        return f"".join([c.get_init_c_flat() for c in self.components[:-2]]) + \
               f"  {self.components[-2].a.name} = {self.a.get_wire_value_c(offset=self.N-1)};\n" + \
               f"  {self.components[-2].b.name} = {self.b.get_wire_value_c(offset=self.N-1)};\n" + \
               f"  {self.components[-2].output.name} = {self.components[-2].get_init_c_flat()};\n" + \
               f"  {self.components[-1].a.name} = {self.components[-2].output.get_wire_value_c()};\n" + \
               f"  {self.components[-1].b.name} = {self.components[-3].get_carry_wire().get_wire_value_c()};\n" + \
               f"  {self.components[-1].output.name} = {self.components[-1].get_init_c_flat()};\n"

    def get_function_sum_c_flat(self):
        return "".join([c.get_function_sum_c_flat(offset=self.components.index(c)) for c in self.components[:-2]])

    def get_function_carry_c_flat(self):
        return f"  {self.out.prefix} |= {self.get_previous_component().output.return_wire_value_c(offset = self.N)};\n"

    # HIERARCHICAL C #
    def get_declaration_c_hier(self):
        self.cout = bus(N=self.N, prefix="cout")
        return "".join(self.a.get_wire_declaration_c()) + \
               "".join(self.b.get_wire_declaration_c()) + \
               "".join(self.cout.get_wire_declaration_c()) + \
               f"{self.components[-2].output.get_declaration_c()}"

    def get_init_cout_c_hier(self):
        return "\n".join([c.get_invocation_c(wire_n=self.cout.get_wire(self.components.index(c)).name, offset=self.components.index(c)) for c in self.components[:-2]]) + \
              f"\n  {self.components[-2].output.name} = {self.components[-2].get_invocation_c(a=self.a.bus[-1], b=self.b.bus[-1])}"

    def get_function_sum_c_hier(self):
        return ";\n".join([c.get_adder_sum(offset=self.components.index(c)) for c in self.components[:-2]])+";\n"

    def get_function_carry_c_hier(self):
        return f"  {self.out.prefix} |= {self.get_previous_component().get_gate_output_c(a=self.components[-2].output, b=self.cout.bus[-1], offset=self.out.N-1)};\n"

    """ VERILOG CODE GENERATION """
    # FLAT C #
    # Initialization of 1-bit adders and sign extension XOR gates
    def get_init_v_flat(self, offset: int = 0, array: bool = False):
        self.components[-2].output.prefix = self.components[-2].output.name
        self.components[-3].get_carry_wire().prefix = self.components[-3].get_carry_wire().name
        return f"".join([c.get_init_v_flat(offset=self.components.index(c), array=True) for c in self.components[:-2]]) + \
               f"  assign {self.components[-2].a.name} = {self.a.get_wire_value_v(offset=self.N-1, array=True)};\n" + \
               f"  assign {self.components[-2].b.name} = {self.b.get_wire_value_v(offset=self.N-1, array=True)};\n" + \
               f"  assign {self.components[-2].output.name} = {self.components[-2].get_init_v_flat()};\n" + \
               f"  assign {self.components[-1].a.name} = {self.components[-2].output.get_wire_value_v(offset=offset, array=array)};\n" + \
               f"  assign {self.components[-1].b.name} = {self.components[-3].get_carry_wire().get_wire_value_v()};\n" + \
               f"  assign {self.components[-1].output.name} = {self.components[-1].get_init_v_flat()};\n"

    def get_function_sum_v_flat(self, offset: int = 0):
        return "".join([c.get_function_sum_v_flat(offset=self.components.index(c)) for c in self.components[:-2]])

    def get_function_carry_v_flat(self):
        return f"  assign {self.out.prefix}[{self.N}] = {self.get_previous_component().output.return_wire_value_v(offset=self.N)};\n"


class unsigned_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        # Bus sign extension in ase buses have different lengths
        a.bus_extend(N=self.N, prefix=a.prefix)
        b.bus_extend(N=self.N, prefix=b.prefix)
        self.a = a
        self.b = b
        if prefix == "u_rca":
            self.prefix = prefix+str(self.N)
        else:
            self.prefix = prefix

        # Output wires for N sum bits and additional cout bit
        self.out = bus("out", self.N+1)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            # First one is a half adder
            if input_index == 0:
                obj_ha = half_adder(a.get_wire(input_index), b.get_wire(input_index), prefix=self.prefix+"_ha")
                self.add_component(obj_ha)
                self.out.connect(input_index, obj_ha)
            # Rest are full adders
            else:
                obj_fa = full_adder(a.get_wire(input_index), b.get_wire(input_index), self.get_previous_component().get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))
                self.add_component(obj_fa)
                self.out.connect(input_index, obj_fa.get_sum_wire())

                if input_index == (self.N-1):
                    self.out.connect(self.N, obj_fa.get_carry_wire())


if __name__ == "__main__":
    a = bus(N=8, prefix="a")
    b = bus(N=8, prefix="b")
    rca = unsigned_ripple_carry_adder(a, b, prefix="u_rca8")
    # rca.get_c_code_hier(open("h_u_rca4.c", "w"))
    # rca.get_c_code_flat(open("f_u_rca8.c", "w"))
    rca.get_v_code_flat(open("f_u_rca8.v", "w"))

    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cout")
    fa = full_adder(w1, w2, w3, prefix="f_fa")
    ha = half_adder(w1, w2, prefix="f_ha")

    # ha.get_c_code_flat(open("f_ha.c","w"))
    # ha.get_v_code_flat(open("f_ha.v","w"))
    # fa.get_c_code_flat(open("f_fa.c","w"))
    # fa.get_v_code_flat(open("f_fa.v","w"))

    gate = not_gate(w1)
    # gate.get_c_code(open("not_gate.c","w"))
    # gate.get_v_code(open("not_gate.v","w"))
