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
        self.gate_type = "not_gate"
        if input_a == 1:
            self.y = 0
        else:
            self.y = 1
    
    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        with open(filename,'w') as f:
            if main_component == True:
                f.write('#include <stdint.h>\n\n')
                f.write('uint8_t not_gate(uint8_t a) {\n')
                f.write('  uint8_t y;\n')
                f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                f.write('  y = ~n1;\n')
                f.write('  return y;\n')
                f.write('}\n')
            else:
                if init_run == True:
                    if line_var_cnt != 0:
                        file_object.write(', ')
                    file_object.write(f'n_{wire_id}=0')
                else:
                    pass


#dvouvstupove
class or_gate():
    def __init__(self, input_a, input_b):
        self.gate_type = "or_gate"
        if (input_a == 1 or input_b == 1):
            self.y = 1
        else:
            self.y = 0

    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        with open(filename,'w') as f:
            if main_component == True:
                f.write('#include <stdint.h>\n\n')
                f.write('uint8_t or_gate(uint8_t a, uint8_t b) {\n')
                f.write('  uint8_t y;\n')
                f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                f.write('  uint8_t n2 = (b >> 0) & 0x1;\n')
                f.write('  y = n1 | n2;\n')
                f.write('  return y;\n')
                f.write('}\n')
            else:
                #todo wtf
                if init_run == True:
                    if line_var_cnt != 0:
                        file_object.write(', ')
                    file_object.write(f'n_{wire_id}=0')
                else:
                    pass  
                
    

class xor_gate(): 
    def __init__(self, input_a, input_b):
        self.gate_type = "xor_gate"
        if (input_a == 1 and input_b == 0) or (input_a == 0 and input_b == 1):
            self.y = 1
        else:
            self.y = 0

    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        with open(filename,'w') as f:
            if main_component == True:
                f.write('#include <stdint.h>\n\n')
                f.write('uint8_t xor_gate(uint8_t a, uint8_t b) {\n')
                f.write('  uint8_t y;\n')
                f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                f.write('  uint8_t n2 = (b >> 0) & 0x1;\n')
                f.write('  y = n1 ^ n2;\n')
                f.write('  return y;\n')
                f.write('}\n')
            else:
                if init_run == True:
                    if line_var_cnt != 0:
                        file_object.write(', ')
                    file_object.write(f'n_{wire_id}=0')
                else:
                    pass

class and_gate():
    def __init__(self, input_a, input_b):
        self.gate_type = "and_gate"
        if input_a == 1 and input_b == 1:
            self.y = 1
        else:
            self.y = 0
    
    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        with open(filename,'w') as f:
            if main_component == True:
                f.write('#include <stdint.h>\n\n')
                f.write('uint8_t and_gate(uint8_t a, uint8_t b) {\n')
                f.write('  uint8_t y;\n')
                f.write('  uint8_t n1 = (a >> 0) & 0x1;\n')
                f.write('  uint8_t n2 = (b >> 0) & 0x1;\n')
                f.write('  y = n1 & n2;\n')
                f.write('  return y;\n')
                f.write('}\n')
            else:
                if init_run == True:
                    if line_var_cnt != 0:
                        file_object.write(', ')
                    file_object.write(f'n_{wire_id}=0')
                else:
                    pass

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
    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        self.line_wires_cnt = 0
        if main_component == True:
            with open(filename,'w') as f:
                f.write('#include <stdint.h>\n\n')

                if self.circuit_type == 'ha':
                    f.write('uint8_t ha(uint8_t a, uint8_t b) {\n')
                    f.write('  uint8_t out = 0;\n')
                elif self.circuit_type == 'fa':
                    f.write('uint8_t fa(uint8_t a, uint8_t b, uint8_t cin) {\n')
                    f.write('  uint8_t out = 0;\n')
                else:
                    f.write(f'uint64_t {self.circuit_type}(uint64_t a, uint64_t b) ')
                    f.write('{\n')
                    f.write('  uint64_t out = 0;\n')

                f.write('uint8_t ')
                for component in self.component_list:
                    component.export_to_C(filename, False)

                f.write(';\n')

                f.write('  return out;\n')
                f.write('}\n')

        

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

    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, init_run=True):
        if main_component == True:
            with open(filename,'w') as f:
                f.write('#include <stdint.h>\n\n')
                f.write('uint8_t ha(uint8_t a, uint8_t b) {\n')
                f.write('  uint8_t out = 0;\n')
                f.write('  uint8_t ')

                #inicializace vstupu
                for component in self.component_list:
                    component.export_to_C(filename, False, file_object=f, wire_id=wire_id, line_var_cnt=line_var_cnt)
                    wire_id +=1
                    line_var_cnt +=1

                    if line_var_cnt == 8:
                        line_var_cnt = 0
                        f.write(';\n')
                
                wire_id=0

                #prirazeni hodnot
                for component in self.component_list:
                    component.export_to_C(filename, False, file_object=f, wire_id=wire_id, init_run=False)
                    wire_id +=1


                f.write(';\n')

                f.write('  return out;\n')
                f.write('}\n')
        else:
            pass
                
                

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
    
    def export_to_C(self, filename, main_component=True, file_object=None, wire_id=0, line_var_cnt=0, mode):
        if main_component == True:
            with open(filename,'w') as f:
                f.write('#include <stdint.h>\n\n')
                f.write('uint8_t fa(uint8_t a, uint8_t b, uint8_t cin) {\n')
                f.write('  uint8_t out = 0;\n')
                f.write('  uint8_t ')
                
                for component in self.component_list:
                    component.export_to_C(filename, False, file_object=f, wire_id=wire_id, line_var_cnt=line_var_cnt)
                    wire_id +=1
                    line_var_cnt +=1
                    
                    if line_var_cnt == 8:
                        f.write(';\n')


                f.write(';\n')

                f.write('  return out;\n')
                f.write('}\n')
        else:
            pass
    

class ripple_carry_adder(arithmetic_circuit):
    def __init__(self, input_bus_a, input_bus_b):
        super().__init__()
        #todo zeptat se
        N = max(input_bus_a.N,input_bus_b.N)
        self.circuit_type = "rca_"+str(N)

        self.out = bus(N+1)

        #postupne pridani jednobitovych scitacek
        for input_index in range(N):
            #prvni je polovicni scitacka
            if input_index == 0:
                obj_ha = half_adder(input_bus_a.get_value(input_index), input_bus_b.get_value(input_index))
                self.add_component(obj_ha)
                self.out.connect(input_index, obj_ha.get_sum_out())
            else:
                obj_fa = full_adder(input_bus_a.get_value(input_index), input_bus_b.get_value(input_index), self.get_previous_component().get_carry_out())
                self.add_component(obj_fa)
                self.out.connect(input_index, obj_fa.get_sum_out())
                if input_index == (N-1):
                    self.out.connect(N, obj_fa.get_carry_out())

    #Export do jinych reprezentaci
    #todo
    