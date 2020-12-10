#KOMPONENTY PROPOJU

#todo ??
class wire():
    def __init__(self, index):
        self.index = index
        self.value = 0

class bus():
    #inicializace sbernice 
    def __init__(self, N=1):
        self.bus = [wire(index=i) for i in range(N)]
        self.N = N
    
    #vraci drat na prislusnem indexu sbernice
    def get(self, wire_index):
        return self.bus[wire_index]

    #vraci logickou hodnotu vedenou na drate s prislusnym indexem
    def get_value(self, wire_index):
        return self.bus[wire_index].value

    #pripojeni vstupni, vystupni hodnoty komponenty k sbernici
    def connect(self, wire_index, component_output_value):
        self.bus[wire_index].value = component_output_value

#KOMPONENTY HRADEL
#jednovstupove
class not_gate():
    def __init__(self, input_a):
        if input_a == 1:
            self.y = 0
        else:
            self.y = 1

#dvouvstupove
class or_gate():
    def __init__(self, input_a, input_b):
        if (input_a == 1 or input_b == 1):
            self.y = 1
        else:
            self.y = 0

class xor_gate(): 
    def __init__(self, input_a, input_b):
        if (input_a == 1 and input_b == 0) or (input_a == 0 and input_b == 1):
            self.y = 1
        else:
            self.y = 0

class and_gate(): 
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

    def get_previous_component(self):
        return self.component_list[-1]

    #zpravidla posledni bit ve vystupnim vektoru bitu
    def get_carry_out(self):
        return self.out.get(-1).value
    
    def get_sum_out(self, index):
        return self.out.get_value(index)

    #Export do jinych reprezentaci
    def to_C(self, filename):

        with open(filename,'w') as f:
            f.write('#include <stdint.h>\n\n')
            f.write(f'uint64_t {self.circuit_type} () \n')
            for component in self.component_list:
                print (component)
            
        

class half_adder(arithmetic_circuit):
    def __init__(self, input_a, input_b):
        super().__init__()
        self.circuit_type = "ha"
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
    
    def get_sum_out(self):
        return self.out.get(0).value

class full_adder(arithmetic_circuit):
    def __init__(self, input_a, input_b, carry_in):
        super().__init__()
        self.circuit_type = "fa"

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
    
    def get_sum_out(self):
        return self.out.get(0).value

class ripple_carry_adder(arithmetic_circuit):
    def __init__(self, input_bus_a, input_bus_b):
        super().__init__()
        #todo zeptat se
        N = max(input_bus_a.N,input_bus_b.N)
        self.circuit_type = "rca_"+str(N)

        self.out = bus(N+1)

        #postupne pridani jednobitovych scitacek
        for i in range(N):
            #prvni je polovicni scitacka
            if i == 0:
                obj_ha = half_adder(input_bus_a.get_value(i), input_bus_b.get_value(i))
                self.add_component(obj_ha)
                self.out.connect(i, obj_ha.get_sum_out())
            else:
                obj_fa = full_adder(input_bus_a.get_value(i), input_bus_b.get_value(i), self.get_previous_component().get_carry_out())
                self.add_component(obj_fa)
                self.out.connect(i, obj_fa.get_sum_out())
                if i == (N-1):
                    self.out.connect(N, obj_fa.get_carry_out())

    def to_C(self, filename):
        super().to_C(filename)
            #todo