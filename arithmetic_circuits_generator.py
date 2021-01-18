from wire_components import wire, bus
from logic_gates_generator import and_gate, xor_gate, or_gate
import sys


# ARITMETICKE OBVODY
class arithmetic_circuit():
    def __init__(self):
        self.components = []
        self.circuit_wires = []
        self.c_data_type = "uint64_t"

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

    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix})" + "{" + '\n'

    def get_declaration_c(self):
        return f"".join([c.get_declaration_c() for c in self.components])

    def get_initialization_c(self):
        return "".join([c.get_initialization_c() for c in self.components])

    def get_function_sum_c(self):
        return "".join([c.get_function_sum_c(self.components.index(c)) for c in self.components])

    def get_function_carry_c(self):
        return f"{self.get_previous_component().get_function_carry_c(offset=self.out.N-1)}"

    # Generovani aritmetickeho obvodu do jazyka C
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write(self.out.get_declaration_c())
        file_object.write(self.get_declaration_c())
        file_object.write(self.get_initialization_c())
        file_object.write(self.get_function_sum_c())
        file_object.write(self.get_function_carry_c())
        file_object.write(f"  return {self.out.prefix}"+";\n}")
        file_object.close()


class half_adder(arithmetic_circuit):
    def __init__(self, a: wire, b: wire, prefix: str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        # 2 draty pro vystupy komponenty (sum, cout)
        self.out = bus("out", 2)

        # Sum
        # XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate = xor_gate(a, b, prefix, outid=0)
        self.add_component(obj_xor_gate)
        self.out.connect(0, obj_xor_gate.output)

        # Cout
        # AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate = and_gate(a, b, prefix, outid=1)
        self.add_component(obj_and_gate)
        self.out.connect(1, obj_and_gate.output)

    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name})" + "{" + '\n'

    # Ziskani vsech unikatnich vodicu obvodu ze vsech hradel k zajisteni neopakujicich se deklaraci stejnych vodicu
    def get_declaration_c(self):
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name))

            if not [item for item in self.circuit_wires if item[1] == component.output.name]:
                self.circuit_wires.append((component.output, component.output.name))

        # Unikatni deklarace vsech propoju obvodu
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Inicializace hodnot vodicu polovicni scitacky
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
        # 2 draty pro vystupy komponenty (sum, cout)
        self.out = bus("out", 2)

        # PG logika
        propagate_xor_gate1 = xor_gate(a, b, prefix, outid=0)
        self.add_component(propagate_xor_gate1)
        generate_and_gate1 = and_gate(a, b, prefix, outid=1)
        self.add_component(generate_and_gate1)

        # Sum
        # XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.output, c, prefix, outid=2)
        self.add_component(obj_xor_gate2)
        self.out.connect(0, obj_xor_gate2.output)

        # Cout
        # AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate2 = and_gate(propagate_xor_gate1.output, c, prefix, outid=3)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.output, obj_and_gate2.output, prefix, outid=4)
        self.add_component(obj_or_gate)

        self.out.connect(1, obj_or_gate.output)

        # TODO nechat do budoucna?
        self.propagate = propagate_xor_gate1.output
        self.generate = generate_and_gate1.output

    # 3 vstupy spolu s carry in
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name}, {self.c_data_type} {self.c.name})" + "{" + '\n'

    def get_declaration_c(self):
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name))

            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name))

            if not [item for item in self.circuit_wires if item[1] == component.output.name]:
                self.circuit_wires.append((component.output, component.output.name))

        # Unikatni deklarace vsech propoju obvodu
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # Inicializace hodnot vodicu uplne scitacky
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


class ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a: bus, b: bus, prefix: str = "rca"):
        super().__init__()
        N = max(a.N, b.N)
        self.prefix = prefix+str(N)
        self.a = a
        self.b = b

        # Vystupni draty pro N souctu a vystupni priznak prenosu do vyssiho radu (cout)
        self.out = bus("out", N+1)

        # Postupne pridani jednobitovych scitacek
        for input_index in range(N):
            # Prvni je polovicni scitacka
            if input_index == 0:
                obj_ha = half_adder(a.get_wire(input_index), b.get_wire(input_index), prefix=self.prefix+"_ha")
                self.add_component(obj_ha)
                self.out.connect(input_index, obj_ha)
            else:
                obj_fa = full_adder(a.get_wire(input_index), b.get_wire(input_index), self.get_previous_component().get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))
                self.add_component(obj_fa)
                self.out.connect(input_index, obj_fa.get_sum_wire())

                if input_index == (N-1):
                    self.out.connect(N, obj_fa.get_carry_wire())

if __name__ == "__main__":
    # Vytvoreni obvodu 8 bitove postupne scitacky
    a = bus(N=8, prefix="a")
    b = bus(N=8, prefix="b")
    rca = ripple_carry_adder(a, b)
    # Export do jazyka C (flat)
    rca.get_c_code(open("rca_8.c", "w"))

    # Vytvoreni logickeho hradla OR
    a1 = wire("a", 1)
    b1 = wire("b", 0)
    xor_gate = xor_gate(a1, b1)
    # Export do jazyka C (flat)
    xor_gate.get_c_code(sys.stdout)
