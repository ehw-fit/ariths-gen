#KOMPONENTY PROPOJU

#todo ??
class wire():
    def __init__(self, index):
        self.index = index

class bus():
    #inicializace sbernice 
    def __init__(self, N=1):
        self.bus = [wire(index=i) for i in range(N)]
        self.N = len(self.bus)
    
    #vraci drat na prislusnem indexu sbernice
    def get(self, wire_index):
        return self.bus[wire_index]

    #pripojeni vstupni, vystupni hodnoty komponenty k sbernici
    def connect(self, wire_index, component_output_value):
        self.bus[wire_index].value = component_output_value

#KOMPONENTY HRADEL
class not_gate():
    def __init__(self, input_a):
        self.input_a = input_a
        if self.input_a == 1:
            self.y = 0
        else:
            self.y = 1

class two_input_gate():
    def __init__(self, input_a, input_b):
        self.input_a = input_a
        self.input_b = input_b

class or_gate(two_input_gate):
    def __init__(self, input_a, input_b):
        super().__init__(input_a, input_b)
        if (self.input_a == 1 or self.input_b == 1):
            self.y = 1
        else:
            self.y = 0

class xor_gate(two_input_gate): 
    def __init__(self, input_a, input_b):
        if (input_a == 1 and input_b == 0) or (input_a == 0 and input_b == 1):
            self.y = 1
        else:
            self.y = 0

class and_gate(two_input_gate): 
    def __init__(self, input_a, input_b):
        if input_a == 1 and input_b == 1:
            self.y = 1
        else:
            self.y = 0



#ARITMETICKE OBVODY
class arithmetic_circuit():
    def __init__(self):
        self.component_list = []

    def add_component(self, component):
        self.component_list.append(component)

    #Export do jinych reprezentaci
    def to_C():
        pass


class half_adder(arithmetic_circuit):
    def __init__(self, input_a, input_b):
        super().__init__()
        #2 draty pro vystupy komponenty (sum, cout)
        self.out = bus(2)

        #Sum
        #XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate = xor_gate(input_a, input_b)
        self.add_component(obj_xor_gate)
        self.out.connect(0,obj_xor_gate.y)

        #Cout
        #AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate = and_gate(input_a, input_b)
        self.add_component(obj_and_gate)
        self.out.connect(1,obj_and_gate.y)

class full_adder(arithmetic_circuit):
    def __init__(self, input_a, input_b, carry_in):
        super().__init__()

        #2 draty pro vystupy komponenty (sum, cout)
        self.out = bus(2)

        #PG logika
        propagate_xor_gate1 = xor_gate(input_a, input_b)
        self.add_component(propagate_xor_gate1)
        generate_and_gate1 = and_gate(input_a, input_b)
        self.add_component(generate_and_gate1)
        
        #Sum
        #XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.y, carry_in)
        self.add_component(obj_xor_gate2)
        self.out.connect(0,obj_xor_gate2.y)

        #Cout
        #AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate2 = and_gate(propagate_xor_gate1.y, carry_in)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.y, obj_and_gate2.y)
        self.add_component(obj_or_gate)

        self.out.connect(1,obj_or_gate.y)

        #todo nechat?
        self.propagate = propagate_xor_gate1.y
        self.generate = generate_and_gate1.y