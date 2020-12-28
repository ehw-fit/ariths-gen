#KOMPONENTY PROPOJU
class wire():
    def __init__(self, name : str, value : int = 0, index : int = 0):
        self.name = name
        self.value = value
        self.index = index
    
    def get_declaration_c(self):
        return f"  uint8_t {self.name} = 0;\n"

    def get_wire_value(self, offset : int = 0):
        return f"(({self.name} >> {offset}) & 0x01)"
            
    def return_wire_value(self, offset : int = 0):
        return f"({self.name} & 0x01) << {offset}"

class bus():
    #inicializace sbernice 
    def __init__(self, prefix : str = "bus", N : int = 1):
        self.bus = [wire(name=prefix, index= i) for i in range(N)]
        self.prefix = prefix
        self.N = N

    def __index__(self, wire):
        return self.bus.index(wire)
    
    #pripojeni vystupniho vodice vnitrni komponenty na vstup jine komponenty (nebo drat vystupni sbernice obvodu)
    def connect(self, out_wire_index : int, inner_component_out_wire : wire):
        self.bus[out_wire_index] = inner_component_out_wire

    def get_wire_value(self, offset : int = 0):
        self.bus[offset].get_wire_value(offset)

    def return_wire_value(self, offset : int = 0):
        self.bus[offset].return_wire_value(offset)

    def get_declaration_c(self):
        if self.N > 8:
            return f"  uint64_t {self.prefix} = 0;\n"
        else:
            return f"  uint8_t {self.prefix} = 0;\n"

    def get_wire(self, wire_index : int):
        return self.bus[wire_index]
    

#KOMPONENTY HRADEL
class logic_gate():
    @staticmethod
    def get_includes_c():
        return f"#include <stdio.h>\n#include <stdint.h>\n\n"

    def get_prototype_c(self):
        return f"uint8_t {self.gate_type}(uint8_t a, uint8_t b)" + "{" + '\n'

    def get_declaration_c(self):
        return f"{self.a.get_declaration_c()}{self.b.get_declaration_c()}{self.output.get_declaration_c()}"

    def get_initialization_c(self):
        return f"{self.a.name} {self.operator} {self.b.name}"
    
    def get_function_c(self):
        return f"{self.a.get_wire_value()} {self.operator} {self.b.get_wire_value(0)}"
    
    #generovani samostatneho obvodu logickeho hradla do jazyka C
    def get_c_code(self, file_object):
        file_object.write(self.get_includes_c())
        file_object.write(self.get_prototype_c())
        file_object.write("  return "+(self.get_function_c())+";\n}")
        file_object.close()

#jednovstupove
class not_gate(logic_gate):
    def __init__(self, a : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'not_gate'
        self.operator = '~'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)

        if self.a.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid),value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=1)

    def get_prototype_c(self):
        return f"uint8_t {self.gate_type}(uint8_t a)" + "{" + '\n'
    
    def get_declaration_c(self):
        return f"{self.a.get_declaration_c()}{self.output.get_declaration_c()}"

    def get_initialization_c(self):
        return f"{self.operator}{self.a.name}"

    def get_function_c(self):
        return f"{self.operator}{self.a.get_wire_value()} & 0x01 << 0"

#dvouvstupove
class and_gate(logic_gate):
    def __init__(self, a : wire, b : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'and_gate'
        self.operator = '&'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''),a.value)

        if a.value == 1 and b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid),value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=0)

class nand_gate(logic_gate):
    def __init__(self, a : wire, b : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'nand_gate'
        self.operator = '&'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''),a.value)

        if self.a.value == 1 and self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid),value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=1)
    
    def get_function_c(self):
        return "~("+(super().get_function_c())+f") & 0x01 << 0"


class or_gate(logic_gate):
    def __init__(self, a : wire, b : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'or_gate'
        self.operator = '|'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''),a.value)

        if self.a.value == 1 or self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid),value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=0)

class nor_gate(logic_gate):
    def __init__(self, a : wire, b : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'nor_gate'
        self.operator = '|'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''),a.value)

        if self.a.value == 1 or self.b.value == 1:
            self.output = wire(name=prefix+"_y"+str(outid),value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=1)
    
    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"


class xor_gate(logic_gate): 
    def __init__(self, a : wire, b : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'xor_gate'
        self.operator = '^'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''),a.value)
        
        if (a.value == 1 and b.value == 0) or (a.value == 0 and b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid),value=1)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=0)

class xnor_gate(logic_gate): 
    def __init__(self, a : wire, b : wire, prefix : str = "w", outid : int = 0):
        self.gate_type = 'xnor_gate'
        self.operator = '^'
        self.a = wire(prefix+"_"+a.name.replace(prefix+"_", ''),a.value)
        self.b = wire(prefix+"_"+b.name.replace(prefix+"_", ''),a.value)
        
        if (self.a.value == 1 and self.b.value == 0) or (self.a.value == 0 and self.b.value == 1):
            self.output = wire(name=prefix+"_y"+str(outid),value=0)
        else:
            self.output = wire(name=prefix+"_y"+str(outid),value=1)

    def get_function_c(self):
        return "~("+(super().get_function_c())+") & 0x01 << 0"


#ARITMETICKE OBVODY
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

    #generovani aritmetickeho obvodu do jazyka C
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
    def __init__(self, a : wire, b : wire, prefix : str = "ha"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        #2 draty pro vystupy komponenty (sum, cout)
        self.out = bus("out",2)
                
        #Sum
        #XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate = xor_gate(a, b, prefix, outid=0)
        self.add_component(obj_xor_gate)
        self.out.connect(0,obj_xor_gate.output)

        #Cout
        #AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate = and_gate(a, b, prefix, outid=1)
        self.add_component(obj_and_gate)
        self.out.connect(1,obj_and_gate.output)
    
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.name}, {self.c_data_type} {self.b.name})" + "{" + '\n'

    # ziskani vsech unikatnich vodicu obvodu ze vsech hradel k zajisteni neopakujicich se deklaraci stejnych vodicu
    def get_declaration_c(self):        
        for component in self.components:
            if not [item for item in self.circuit_wires if item[1] == component.a.name]:
                self.circuit_wires.append((component.a, component.a.name))
            
            if not [item for item in self.circuit_wires if item[1] == component.b.name]:
                self.circuit_wires.append((component.b, component.b.name))

            if not [item for item in self.circuit_wires if item[1] == component.output.name]:
                self.circuit_wires.append((component.output, component.output.name))

        #unikatni deklarace vsech propoju obvodu
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    #inicializace hodnot vodicu polovicni scitacky
    def get_initialization_c(self):
        return f"  {self.components[0].a.name} = {self.a.get_wire_value(offset=self.a.index)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value(offset=self.b.index)};\n" + \
               f"  {self.components[0].output.name} = {self.components[0].get_initialization_c()};\n" + \
               f"  {self.components[1].output.name} = {self.components[1].get_initialization_c()};\n"     
    
    def get_function_sum_c(self, offset : int = 0):
        return f"  {self.out.prefix} |= {self.components[0].output.return_wire_value(offset = offset)};\n"
    
    def get_function_carry_c(self, offset : int = 1):
        return f"  {self.out.prefix} |= {self.components[1].output.return_wire_value(offset = offset)};\n"


class full_adder(arithmetic_circuit):
    def __init__(self, a : wire, b : wire, c : wire, prefix : str = "fa"):
        super().__init__()
        self.c_data_type = "uint8_t"
        self.prefix = prefix
        self.a = a
        self.b = b
        self.c = c
        #2 draty pro vystupy komponenty (sum, cout)
        self.out = bus("out",2)

        #PG logika
        propagate_xor_gate1 = xor_gate(a, b, prefix, outid=0)
        self.add_component(propagate_xor_gate1)
        generate_and_gate1 = and_gate(a, b, prefix, outid=1)
        self.add_component(generate_and_gate1)
        
        #Sum
        #XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.output, c, prefix, outid=2)
        self.add_component(obj_xor_gate2)
        self.out.connect(0,obj_xor_gate2.output)

        #Cout
        #AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate2 = and_gate(propagate_xor_gate1.output, c, prefix, outid=3)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.output, obj_and_gate2.output, prefix, outid=4)
        self.add_component(obj_or_gate)

        self.out.connect(1,obj_or_gate.output)
        
        #todo nechat do budoucna?
        self.propagate = propagate_xor_gate1.output
        self.generate = generate_and_gate1.output
        
    #3 vstupy spolu s carry in
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

        #unikatni deklarace vsech propoju obvodu
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])
    
    #inicializace hodnot vodicu uplne scitacky
    def get_initialization_c(self):
        return f"  {self.components[0].a.name} = {self.a.get_wire_value(offset=self.a.index)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value(offset=self.b.index)};\n" + \
               f"  {self.components[2].b.name} = {self.c.get_wire_value()};\n" + \
               f"  {self.components[0].output.name} = {self.components[0].get_initialization_c()};\n" + \
               f"  {self.components[1].output.name} = {self.components[1].get_initialization_c()};\n" + \
               f"  {self.components[2].output.name} = {self.components[2].get_initialization_c()};\n" + \
               f"  {self.components[3].output.name} = {self.components[3].get_initialization_c()};\n" + \
               f"  {self.components[4].output.name} = {self.components[4].get_initialization_c()};\n"
    
    def get_function_sum_c(self, offset : int = 0):
        return f"  {self.out.prefix} |= {self.components[2].output.return_wire_value(offset = offset)};\n"

    def get_function_carry_c(self, offset : int = 1):
        return f"  {self.out.prefix} |= {self.components[4].output.return_wire_value(offset = offset)};\n"


class ripple_carry_adder(arithmetic_circuit):
    def __init__(self, a : bus, b : bus, prefix : str = "rca"):
        super().__init__()
        N = max(a.N,b.N)
        self.prefix = prefix+str(N)
        self.a = a
        self.b = b

        #vystupni draty pro N souctu a vystupni priznak prenosu do vyssiho radu (cout)
        self.out = bus("out", N+1)

        #postupne pridani jednobitovych scitacek
        for input_index in range(N):
            #prvni je polovicni scitacka
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