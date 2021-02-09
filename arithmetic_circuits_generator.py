from wire_components import wire, bus
from logic_gates_generator import and_gate, xor_gate, or_gate
import sys


""" ARITHMETIC CIRCUITS """


class arithmetic_circuit():
    def __init__(self):
        self.components = []
        self.circuit_wires = []
        self.c_data_type = "uint64_t"

        # TODO delete?
        self.input_N = 0
        self.carry_out_gate = None
        self.sum_out_gates = []

    def add_component(self, component):
        self.components.append(component)

    def get_previous_component(self):
        return self.components[-1]

    def get_sum_wire(self):
        return self.out.get_wire(0)

    def get_carry_wire(self):
        return self.out.get_wire(1)

    # FLAT C GENERATION #
    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"uint64_t {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + '\n'

    def get_declaration_c(self):
        return f"".join([c.get_declaration_c() for c in self.components])

    def get_initialization_c(self):
        return "".join([c.get_initialization_c() for c in self.components])

    def get_function_sum_c(self):
        return "".join([c.get_function_sum_c(self.components.index(c)) for c in self.components])

    def get_function_carry_c(self):
        return f"{self.get_previous_component().get_function_carry_c(offset=self.out.N-1)}"

    # Generating flat C code representation of circuit
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declaration_c()+"\n")
        file_object.write(self.get_initialization_c()+"\n")
        file_object.write(self.get_function_sum_c())
        file_object.write(self.get_function_carry_c())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()

    # HIERARCHICAL C GENERATION #
    # TODO


class half_adder(arithmetic_circuit):
    def __init__(self, a: wire, b: wire, prefix: str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", 2)

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

    # FLAT C GENERATION #
    # Half adder function prototype with two inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name})" + "{" + '\n'

    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c(self):
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name))

            if not [item for item in self.circuit_wires if item[1] == component.output.name]:
                self.circuit_wires.append((component.output, component.output.name))

        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Half adder wires values initialization
    def get_initialization_c(self):
        return f"  {self.components[0].a.name} = {self.a.get_wire_value_c(offset=self.a.index)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value_c(offset=self.b.index)};\n" + \
               f"  {self.components[0].output.name} = {self.components[0].get_initialization_c()};\n" + \
               f"  {self.components[1].output.name} = {self.components[1].get_initialization_c()};\n"

    def get_function_sum_c(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.components[0].output.return_wire_value_c(offset = offset)};\n"

    def get_function_carry_c(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.components[1].output.return_wire_value_c(offset = offset)};\n"


class full_adder(arithmetic_circuit):
    def __init__(self, a: wire, b: wire, c: wire, prefix: str = "fa"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        # 2 wires for component's bus output (sum, cout)
        self.out = bus("out", 2)

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

    # FLAT C GENERATION #
    # Full adder function prototype with three inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name}, {self.c_data_type} {self.c.name})" + "{" + '\n'

    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c(self):
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name))

            if not [item for item in self.circuit_wires if item[1] == component.output.name]:
                self.circuit_wires.append((component.output, component.output.name))

        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Full adder wires values initialization
    def get_initialization_c(self):
        return f"  {self.components[0].a.name} = {self.a.get_wire_value_c(offset=self.a.index)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value_c(offset=self.b.index)};\n" + \
               f"  {self.components[2].b.name} = {self.c.get_wire_value_c()};\n" + \
               f"  {self.components[0].output.name} = {self.components[0].get_initialization_c()};\n" + \
               f"  {self.components[1].output.name} = {self.components[1].get_initialization_c()};\n" + \
               f"  {self.components[2].output.name} = {self.components[2].get_initialization_c()};\n" + \
               f"  {self.components[3].output.name} = {self.components[3].get_initialization_c()};\n" + \
               f"  {self.components[4].output.name} = {self.components[4].get_initialization_c()};\n"

    def get_function_sum_c(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.components[2].output.return_wire_value_c(offset = offset)};\n"

    def get_function_carry_c(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.components[4].output.return_wire_value_c(offset = offset)};\n"


class signed_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "s_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.c_data_type = "int64_t"
        # Bus sign extension in case buses have different lengths
        a.sign_extend(self.N)
        b.sign_extend(self.N)
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

    # FLAT C GENERATION #
    # Initialization of 1-bit adders and sign extension XOR gates
    def get_initialization_c(self):
        return f"".join([c.get_initialization_c() for c in self.components[:-2]]) + \
               f"  {self.components[-2].a.name} = {self.a.get_wire_value_c(offset=self.N-1)};\n" + \
               f"  {self.components[-2].b.name} = {self.b.get_wire_value_c(offset=self.N-1)};\n" + \
               f"  {self.components[-2].output.name} = {self.components[-2].get_initialization_c()};\n" + \
               f"  {self.components[-1].a.name} = {self.components[-2].output.get_wire_value_c()};\n" + \
               f"  {self.components[-1].b.name} = {self.components[-3].get_carry_wire().get_wire_value_c()};\n" + \
               f"  {self.components[-1].output.name} = {self.components[-1].get_initialization_c()};\n"

    def get_function_sum_c(self):
        return "".join([c.get_function_sum_c(self.components.index(c)) for c in self.components[:-2]])

    def get_function_carry_c(self):
        return f"  {self.out.prefix} |= {self.get_previous_component().output.return_wire_value_c(offset = self.N)};\n"


class unsigned_ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "u_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        # Bus sign extension in case buses have different lengths
        a.sign_extend(self.N)
        b.sign_extend(self.N)
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
    rca = signed_ripple_carry_adder(a, b)
    rca.get_c_code(open("s_rca8.c", "w"))

    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cin")
    fa = full_adder(w1, w2, w3)
    fa.get_c_code(open("fa.c", "w"))

    """
    # Generation of 8-bit rca
    a = bus(N=8, prefix="a")
    b = bus(N=8, prefix="b")
    rca = ripple_carry_adder(a, b)
    # Export to C code (flat) and save to file
    rca.get_c_code(open("rca_8.c", "w"))

    # Generation of OR logic gate
    # Values just for testing functionality within Python
    a1 = wire(name="a", value=1)
    b1 = wire(name="b", value=0)
    xor = xor_gate(a1, b1)
    # Export to C code (flat) and display to stdout
    xor.get_c_code(sys.stdout)
    """
