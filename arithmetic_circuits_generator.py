#KOMPONENTY PROPOJU

#todo ??
class wire():
    def __init__(self, value=0):
        #todo nechat inicializaci?
        self.value = value
        self.id=None

    def add_wire_id(self, wire_id):
        self.id = wire_id
    
    def get_wire_id(self):
        return self.id

class bus():
    #inicializace sbernice 
    def __init__(self, N=1):
        self.bus = [wire() for i in range(N)]
        self.N = N

    def get_wire(self, wire_index):
        return self.bus[wire_index]

    def add_wire_id(self, wire_id, wire_index=0):
        self.bus[wire_index].id = wire_id
    
    def get_wire_id(self, wire_index):
        return self.bus[wire_index].id

    #vraci logickou hodnotu vedenou na drate s prislusnym indexem
    def get_wire_value(self, wire_index):
        return self.bus[wire_index].value

    #pripojeni vstupni, vystupni hodnoty komponenty k sbernici
    def connect(self, wire_index, component_output_value):
        self.bus[wire_index].value = component_output_value

#KOMPONENTY HRADEL
class logic_gate():
    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        if main_component == True:
            with open(filename,'w') as f:
                f.write('#include <stdint.h>\n\n')

                if self.gate_type == 'not_gate':
                    f.write('uint8_t not_gate(uint8_t a) {\n')
                    f.write('  uint8_t y = 0;\n')
                    f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                    f.write('  y |= (~n1 & 0x01) << 0;\n')
                elif self.gate_type == 'and_gate':
                    f.write('uint8_t and_gate(uint8_t a, uint8_t b) {\n')
                    f.write('  uint8_t y = 0;\n')
                    f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                    f.write('  uint8_t n2 = (b >> 0) & 0x1;\n')
                    f.write('  y |= ((n1 & n2) & 0x01) << 0;\n')
                elif self.gate_type == 'or_gate':
                    f.write('uint8_t or_gate(uint8_t a, uint8_t b) {\n')
                    f.write('  uint8_t y = 0;\n')
                    f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                    f.write('  uint8_t n2 = (b >> 0) & 0x1;\n')
                    f.write('  y |= ((n1 | n2) & 0x01) << 0;\n')
                elif self.gate_type == 'xor_gate':
                    f.write('uint8_t xor_gate(uint8_t a, uint8_t b) {\n')
                    f.write('  uint8_t y = 0;\n')
                    f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                    f.write('  uint8_t n2 = (b >> 0) & 0x1;\n')
                    f.write('  y |= ((n1 ^ n2) & 0x01) << 0;\n')
                
                f.write('  return y;\n')
                f.write('}\n')
        else:
            if init_run == True:
                if line_var_cnt == 0:
                    file_object.write('  uint8_t ')
                else:
                    file_object.write(', ')
                file_object.write(f'n_{wire_id}=0')

                self.y.add_wire_id(wire_id)
                
            else:
                if self.gate_type == 'not_gate':
                    file_object.write(f'  n_{self.y.get_wire_id()} = ~n_{self.input.get_wire_id(0)};\n')
                else:
                    file_object.write(f'  n_{self.y.get_wire_id()} = n_{self.input.get_wire_id(0)} {self.operator} n_{self.input.get_wire_id(1)};\n')

#jednovstupove
class not_gate(logic_gate):
    def __init__(self, input_wire_a):
        self.gate_type = 'not_gate'
        self.wires_N = 2
        self.input = bus(1)

        self.input.bus[0] = input_wire_a

        if input_wire_a.value == 1:
            self.y = wire(0)
        else:
            self.y = wire(1)
    

#dvouvstupove
class and_gate(logic_gate):
    def __init__(self, input_wire_a, input_wire_b):
        self.gate_type = 'and_gate'
        self.wires_N = 3
        self.operator = '&'
        self.input = bus(2)
        
        self.input.bus[0] = input_wire_a
        self.input.bus[1] = input_wire_b

        if input_wire_a.value == 1 and input_wire_b.value == 1:
            self.y = wire(1)
        else:
            self.y = wire(0)


class or_gate(logic_gate):
    def __init__(self, input_wire_a, input_wire_b):
        self.gate_type = 'or_gate'
        self.wires_N = 3
        self.operator = '|'
        self.input = bus(2)

        self.input.bus[0] = input_wire_a
        self.input.bus[1] = input_wire_b

        if input_wire_a.value == 1 or input_wire_b.value == 1:
            self.y = wire(1)
        else:
            self.y = wire(0)


class xor_gate(logic_gate): 
    def __init__(self, input_wire_a, input_wire_b):
        self.gate_type = 'xor_gate'
        self.wires_N = 3
        self.operator = '^'
        self.input = bus(2)
        
        self.input.bus[0] = input_wire_a
        self.input.bus[1] = input_wire_b

        if (input_wire_a.value == 1 and input_wire_b.value == 0) or (input_wire_a.value == 0 and input_wire_b.value == 1):
            self.y = wire(1)
        else:
            self.y = wire(0)


#ARITMETICKE OBVODY
class arithmetic_circuit():
    def __init__(self):
        self.component_list = []
        self.input_N = 0
        self.carry_out_gate = None
        self.sum_out_gates = []

    def add_component(self, component):
        self.component_list.append(component)

    def get_component_index(self, component):
        return self.component_list.index(component)

    def get_previous_component(self):
        return self.component_list[-1]

    #pomocna funkce
    def wire_index_offset(self, index):
        return index

    def get_carry_out_wire(self):
        return self.carry_out_gate.y

    #todo jinak zpravidla posledni bit ve vystupnim vektoru bitu
    def get_carry_out_val(self):
        return self.carry_out_gate.value
    
    #todo
    def get_sum_out_val(self, index):
        return self.out.get_value(index)

    #Export do jinych reprezentaci
    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        if main_component == True:
            with open(filename,'w') as f:
                f.write('#include <stdint.h>\n\n')

                #DEKLARACE FUNKCE PRO DANY TYP OBVODU
                ##
                if self.circuit_type == 'ha':
                    f.write('uint8_t ha(uint8_t a, uint8_t b) {\n')
                    f.write('  uint8_t out = 0;\n')
                elif self.circuit_type == 'fa':
                    f.write('uint8_t fa(uint8_t a, uint8_t b, uint8_t cin) {\n')
                    f.write('  uint8_t out = 0;\n')
                elif self.circuit_type == 'rca_'+str(int(self.input_N/2)):
                    f.write('uint64_t rca(uint64_t a, uint64_t b) {\n')
                    f.write('  uint64_t out = 0;\n')

                #DEKLARACE DRATU
                ##
                #deklarace vstupu obvodu
                for in_wire_index in range(self.input_N):
                    if line_var_cnt == 0:
                        f.write('  uint8_t ')
                    else:
                        f.write(', ')
                    
                    f.write(f'n_{in_wire_index}=0')
                    self.inputs.add_wire_id(wire_id, in_wire_index)
                    line_var_cnt += 1
                    wire_id += 1

                #deklarace vstupu a vystupu hradel vnitrni logiky obvodu
                if self.circuit_type != 'ha' and self.circuit_type != 'fa':
                    for component in self.component_list:
                        if component.circuit_type == 'ha':
                            component.export_to_C(filename, False, file_object=f, wire_id=wire_id, line_var_cnt=line_var_cnt)    
                            wire_id += 2
                            line_var_cnt += 2
                        elif component.circuit_type == 'fa':
                            component.export_to_C(filename, False, file_object=f, wire_id=wire_id, line_var_cnt=line_var_cnt)    
                            wire_id += 5
                            line_var_cnt += 5
                else:
                    for component in self.component_list:
                        #zapis 8 promennych na radek, odradkovani pro prehlednost
                        if line_var_cnt >= 8:
                            f.write(';\n')
                            line_var_cnt = 0

                        component.export_to_C(filename, False, file_object=f, wire_id=wire_id, line_var_cnt=line_var_cnt)
                        wire_id += 1
                        line_var_cnt += 1
                    
                f.write(';\n')

                #PRIRAZENI VSTUPNICH HODNOT K DRATUM
                if self.circuit_type == 'fa':
                    f.write(f'  n_{self.inputs.get_wire_id(0)} = (a >> 0) & 0x1;\n')
                    f.write(f'  n_{self.inputs.get_wire_id(1)} = (b >> 0) & 0x1;\n')
                    f.write(f'  n_{self.inputs.get_wire_id(2)} = (cin >> 0) & 0x1;\n')
                else:
                    for in_wire_index in range(0, int(self.input_N/2)):
                        f.write(f'  n_{self.inputs.get_wire_id(in_wire_index)} = (a >> {in_wire_index}) & 0x1;\n')
                        
                    for in_wire_index in range(0, int(self.input_N/2)):
                        f.write(f'  n_{self.inputs.get_wire_id(in_wire_index + int(self.input_N/2))} = (b >> {in_wire_index}) & 0x1;\n')      

                #VYPOCTY VYSTUPNICH HODNOT HRADEL
                ##
                for component in self.component_list:
                    component.export_to_C(filename, False, file_object=f, init_run=False)
                    
                #PRIRAZENI VYSTUPU
                ##
                for out_wire_index in range(self.out.N):
                    if self.circuit_type != 'ha' and self.circuit_type != 'fa':
                        if out_wire_index == (self.out.N)-1:
                            out_component_index = self.component_list[out_wire_index-1].get_component_index(self.carry_out_gate)
                            component = self.component_list[out_wire_index-1]

                        else:
                            out_component_index = self.component_list[out_wire_index].get_component_index(self.sum_out_gates[out_wire_index])
                            component = self.component_list[out_wire_index]

                        if component.circuit_type == 'ha':
                            out_component_index = out_component_index * out_wire_index
                        elif component.circuit_type == 'fa':
                            if out_wire_index == (self.out.N)-1:
                                out_component_index += 5 * (out_wire_index-2) + 2
                            else:
                                out_component_index += 5 * (out_wire_index-1) + 2

                        wire_id = self.wire_index_offset(out_component_index+self.input_N)
                        f.write(f'  out |= (n_{wire_id} & 0x01) << {out_wire_index};\n')                    
                    else:
                        #Cout
                        if out_wire_index == (self.out.N)-1:
                            out_component_index = self.get_component_index(self.carry_out_gate)
                        #Sum
                        else:
                            out_component_index = self.get_component_index(self.sum_out_gates[out_wire_index])
                    
                        wire_id = self.wire_index_offset(out_component_index+self.input_N)
                        f.write(f'  out |= (n_{wire_id} & 0x01) << {out_wire_index};\n')                    
                

                f.write('  return out;\n')
                f.write('}\n')
        else:
            if init_run == True:
                for component in self.component_list:

                    #zapis 8 promennych na radek, odradkovani pro prehlednost
                    if line_var_cnt >= 8:
                        file_object.write(';\n')
                        line_var_cnt = 0

                    component.export_to_C(filename, False, file_object=file_object, wire_id=wire_id, line_var_cnt=line_var_cnt)
                    wire_id += 1
                    line_var_cnt += 1
            else:
                for component in self.component_list:
                    component.export_to_C(filename, False, file_object=file_object, init_run=False)


class half_adder(arithmetic_circuit):
    def __init__(self, input_wire_a, input_wire_b):
        super().__init__()
        self.input_N = 2
        self.circuit_type = 'ha'
        self.inputs = bus(self.input_N)
        self.inputs.bus[0] = input_wire_a
        self.inputs.bus[1] = input_wire_b

        #2 draty pro vystupy komponenty (sum, cout)
        self.out = bus(2)

        #Sum
        #XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate = xor_gate(input_wire_a, input_wire_b)
        self.add_component(obj_xor_gate)
        self.out.connect(0,obj_xor_gate.y)
        self.sum_out_gates.append(obj_xor_gate)

        #Cout
        #AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate = and_gate(input_wire_a, input_wire_b)
        self.add_component(obj_and_gate)
        self.out.connect(1,obj_and_gate.y)
        self.carry_out_gate = obj_and_gate

    def get_sum_out_component(self):
        return self.component_list[0]

    def get_sum_out_wire(self):
        return self.out.get_wire(0)
                

class full_adder(arithmetic_circuit):
    def __init__(self, input_wire_a, input_wire_b, carry_in_wire):
        super().__init__()
        self.input_N = 3
        self.circuit_type = 'fa'
        self.inputs = bus(self.input_N)
        self.inputs.bus[0] = input_wire_a
        self.inputs.bus[1] = input_wire_b
        self.inputs.bus[2] = carry_in_wire


        #2 draty pro vystupy komponenty (sum, cout)
        self.out = bus(2)

        #PG logika
        propagate_xor_gate1 = xor_gate(input_wire_a, input_wire_b)
        self.add_component(propagate_xor_gate1)
        generate_and_gate1 = and_gate(input_wire_a, input_wire_b)
        self.add_component(generate_and_gate1)
        
        #Sum
        #XOR hradlo pro vypocet jednobitového souctu (sum)
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.y, carry_in_wire)
        self.add_component(obj_xor_gate2)
        self.out.connect(0,obj_xor_gate2.y)
        self.sum_out_gates.append(obj_xor_gate2)

        #Cout
        #AND hradlo pro vypocet jednobitoveho priznaku prenosu do vyssiho radu (cout)jednobitového souctu (sum)
        obj_and_gate2 = and_gate(propagate_xor_gate1.y, carry_in_wire)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.y, obj_and_gate2.y)
        self.add_component(obj_or_gate)

        self.out.connect(1,obj_or_gate.y)
        self.carry_out_gate = obj_or_gate

        #todo nechat?
        self.propagate = propagate_xor_gate1.y
        self.generate = generate_and_gate1.y
        
    def get_sum_out_component(self):
        return self.component_list[0]

    def get_sum_out_wire(self):
        return self.out.get_wire(0)


class ripple_carry_adder(arithmetic_circuit):
    def __init__(self, input_bus_a, input_bus_b):
        super().__init__()
        N = max(input_bus_a.N,input_bus_b.N)
        self.input_N = N * 2
        self.circuit_type = 'rca_'+str(N)
        self.sum_out_gates= []

        self.inputs = bus(self.input_N)
        for i in range(N):
            self.inputs.bus[i] = input_bus_a.get_wire(i)
        for i in range(N):
            self.inputs.bus[i+N] = input_bus_b.get_wire(i)

        #vystupni draty pro N souctu a vystupni priznak prenosu do vyssiho radu (cout)
        self.out = bus(N+1)

        #postupne pridani jednobitovych scitacek
        for input_index in range(N):
            #prvni je polovicni scitacka
            if input_index == 0:
                obj_ha = half_adder(input_bus_a.get_wire(input_index), input_bus_b.get_wire(input_index))
                self.add_component(obj_ha)
                self.out.connect(input_index, obj_ha)
                self.sum_out_gates.append(obj_ha.sum_out_gates[0])
            else:
                obj_fa = full_adder(input_bus_a.get_wire(input_index), input_bus_b.get_wire(input_index), self.get_previous_component().get_carry_out_wire())
                self.add_component(obj_fa)
                self.out.connect(input_index, obj_fa.get_sum_out_wire())
                
                self.sum_out_gates.append(obj_fa.sum_out_gates[0])
                if input_index == (N-1):
                    self.out.connect(N, obj_fa.get_carry_out_wire())
                    self.carry_out_gate = obj_fa.carry_out_gate