from arithmetic_circuits import arithmetic_circuit
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from wire_components import wire, bus

""" ONE BIT CIRCUITS """


class one_bit_circuit(arithmetic_circuit):
    def __init__(self):
        super().__init__()

    """ C CODE GENERATION """
    # FLAT C #
    # Obtaining list of all the unique circuit wires from all contained logic gates
    # to ensure non-recurring declaration of same wires
    def get_declaration_c_flat(self):
        self.circuit_wires = []
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_c() for c in self.circuit_wires])

    # 2 bit input adder wire values initialization
    def get_init_c_flat(self):
        return f"{self.components[0].get_assign_c_flat(prefix_a=self.a.prefix, prefix_b=self.b.prefix)}" + \
               f"  {self.components[1].out.name} = {self.components[1].get_init_c_flat()};\n"

    # HIERARCHICAL C #
    def get_function_block_c(self):
        self.component_types = self.get_component_types()
        self.prefix = "ha" if isinstance(self, half_adder) else "fa"
        return f"{self.get_circuit_c()}\n\n"

    def get_declaration_c_hier(self):
        return f"{self.component_types[0].a.get_declaration_c()}" + \
               f"{self.component_types[2].a.get_declaration_c()}" + \
               f"{self.component_types[2].b.get_declaration_c()}"

    def get_init_c_hier(self):
        return f"  {self.component_types[0].a.name} = {self.component_types[0].get_gate_invocation_c(self.a, self.b)}\n" + \
               f"  {self.component_types[2].a.name} = {self.component_types[1].get_gate_invocation_c(self.a, self.b)}\n" + \
               f"  {self.component_types[2].b.name} = {self.component_types[1].get_gate_invocation_c(self.component_types[0].a, self.c)}\n"

    def get_out_invocation_c(self):
        return self.get_sum_invocation_c()+"\n" + \
               self.get_cout_invocation_c()

    def get_sum_invocation_c(self):
        return f"  {self.get_sum_wire().name} = ({self.prefix}({self.a.name}, {self.b.name}) >> 0) & 0x01;"

    def get_cout_invocation_c(self):
        return f"  {self.get_carry_wire().name} = ({self.prefix}({self.a.name}, {self.b.name}) >> 1) & 0x01;"

    def get_function_sum_c_hier(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.component_types[0].get_gate_output_c(a=self.a ,b=self.b, offset=offset)};\n"

    def get_function_carry_c_hier(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.component_types[1].get_gate_output_c(a=self.a ,b=self.b, offset=offset)};\n"

    def get_circuit_c(self):
        return f"{self.get_prototype_c()}" + \
               f"{self.out.get_declaration_c()}" + \
               f"{self.get_function_sum_c_hier()}" + \
               f"{self.get_function_carry_c_hier()}" + \
               f"  return {self.out.prefix}"+";\n}"

    """ VERILOG CODE GENERATION """
    # FLAT VERILOG #
    def get_prototype_v(self):
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, output {self.out.get_wire(0).name}, output {self.out.get_wire(1).name});\n"

    def get_declaration_v_flat(self):
        self.circuit_wires = []
        self.get_circuit_wires()
        # Unique declaration of all circuit's interconnections
        return "".join([c[0].get_declaration_v() for c in self.circuit_wires])

    # Half adder wires values initialization
    def get_init_v_flat(self, offset: int = 0, array: bool = False):
        return f"{self.components[0].get_assign_v_flat(prefix_a=self.a.prefix, prefix_b=self.b.prefix, offset=offset, array=array)}\n" + \
               f"  assign {self.components[1].out.name} = {self.components[1].get_init_v_flat()};"

    def get_function_out_v_flat(self):
        return ""

    # HIERARCHICAL VERILOG #
    def get_function_block_v(self):
        self.component_types = self.get_component_types()
        self.prefix = "ha" if isinstance(self, half_adder) else "fa"
        return f"{self.get_circuit_v()}\n\n"

    def get_declaration_v_hier(self):
        return f"{self.component_types[0].a.get_declaration_v()}" + \
               f"{self.component_types[2].a.get_declaration_v()}" + \
               f"{self.component_types[2].b.get_declaration_v()}"

    def get_init_v_hier(self):
        return f"  {self.component_types[0].gate_type} {self.component_types[0].gate_type}_{self.component_types[0].a.name}({self.a.name}, {self.b.name}, {self.component_types[0].a.name});\n" + \
               f"  {self.component_types[1].gate_type} {self.component_types[1].gate_type}_{self.component_types[2].a.name}({self.a.name}, {self.b.name}, {self.component_types[2].a.name});\n" + \
               f"  {self.component_types[1].gate_type} {self.component_types[1].gate_type}_{self.component_types[2].b.name}({self.component_types[0].a.name}, {self.c.name}, {self.component_types[2].b.name});\n"

    def get_invocation_v(self):
        return f"  ha ha_{self.get_carry_wire().name}({self.a.name}, {self.b.name}, {self.get_sum_wire().name}, {self.get_carry_wire().name});"

    def get_function_sum_v_hier(self):
        return f"{self.components[0].get_gate_invocation_v(a=self.a, b=self.b, out=self.components[0].out, sign=True)}\n"

    def get_function_carry_v_hier(self):
        return f"{self.components[1].get_gate_invocation_v(a=self.a, b=self.b, out=self.components[1].out, sign=True)}\n"

    def get_circuit_v(self):
        return f"{self.get_prototype_v()}" + \
               f"{self.get_function_sum_v_hier()}" + \
               f"{self.get_function_carry_v_hier()}" + \
               f"endmodule"


class half_adder(one_bit_circuit):
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
        self.out.connect(0, obj_xor_gate.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and_gate = and_gate(a, b, prefix, outid=1)
        self.add_component(obj_and_gate)
        self.out.connect(1, obj_and_gate.out)


class full_adder(one_bit_circuit):
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
        obj_xor_gate2 = xor_gate(propagate_xor_gate1.out, c, prefix, outid=2)
        self.add_component(obj_xor_gate2)
        self.out.connect(0, obj_xor_gate2.out)

        # Cout
        # AND gate for calculation of 1-bit cout
        obj_and_gate2 = and_gate(propagate_xor_gate1.out, c, prefix, outid=3)
        self.add_component(obj_and_gate2)

        obj_or_gate = or_gate(generate_and_gate1.out, obj_and_gate2.out, prefix, outid=4)
        self.add_component(obj_or_gate)

        self.out.connect(1, obj_or_gate.out)

        # TODO delete or leave?
        self.propagate = propagate_xor_gate1.out
        self.generate = generate_and_gate1.out

    """ C CODE GENERATION """
    # FLAT C #
    # Full adder function prototype with three inputs
    def get_prototype_c(self):
        return f"{self.c_data_type} {self.prefix}({self.c_data_type} {self.a.prefix}, {self.c_data_type} {self.b.prefix}, {self.c_data_type} {self.c.prefix})" + "{" + "\n"

    # Full adder wires values initialization
    def get_init_c_flat(self):
        return f"  {self.components[0].a.name} = {self.a.get_wire_value_c(offset=self.a.index, prefix=self.a.prefix)};\n" + \
               f"  {self.components[0].b.name} = {self.b.get_wire_value_c(offset=self.b.index, prefix=self.b.prefix)};\n" + \
               f"  {self.components[2].b.name} = {self.c.get_wire_value_c()};\n" + \
               f"  {self.components[0].out.name} = {self.components[0].get_init_c_flat()};\n" + \
               f"  {self.components[1].out.name} = {self.components[1].get_init_c_flat()};\n" + \
               f"  {self.components[2].out.name} = {self.components[2].get_init_c_flat()};\n" + \
               f"  {self.components[3].out.name} = {self.components[3].get_init_c_flat()};\n" + \
               f"  {self.components[4].out.name} = {self.components[4].get_init_c_flat()};\n"

    # HIERARCHICAL C #
    def get_sum_invocation_c(self):
        return f"  {self.get_sum_wire().name} = ({self.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> 0) & 0x01;"

    def get_cout_invocation_c(self):
        return f"  {self.get_carry_wire().name} = ({self.prefix}({self.a.name}, {self.b.name}, {self.c.name}) >> 1) & 0x01;"

    def get_function_sum_c_hier(self, offset: int = 0):
        return f"  {self.out.prefix} |= {self.component_types[0].get_gate_output_c(a=self.component_types[0].a, b=self.c, offset=offset)};\n"

    def get_function_carry_c_hier(self, offset: int = 1):
        return f"  {self.out.prefix} |= {self.get_previous_component().get_gate_output_c(a=self.component_types[2].a, b=self.component_types[2].b, offset=offset)};\n"

    def get_circuit_c(self):
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
        return f"module {self.prefix}(input {self.a.name}, input {self.b.name}, input {self.c.name}, output {self.out.get_wire(0).name}, output {self.out.get_wire(1).name});\n"

    # Full adder wires values initialization
    def get_init_v_flat(self, offset: int = 0, array: bool = False):
        return f"  assign {self.components[0].a.name} = {self.a.get_wire_value_v(offset=offset, prefix=self.a.prefix, array=array)};\n" + \
               f"  assign {self.components[0].b.name} = {self.b.get_wire_value_v(offset=offset, prefix=self.b.prefix, array=array)};\n" + \
               f"  assign {self.components[2].b.name} = {self.c.get_wire_value_v(offset=offset)};\n" + \
               f"  assign {self.components[0].out.name} = {self.components[0].get_init_v_flat()};\n" + \
               f"  assign {self.components[1].out.name} = {self.components[1].get_init_v_flat()};\n" + \
               f"  assign {self.components[2].out.name} = {self.components[2].get_init_v_flat()};\n" + \
               f"  assign {self.components[3].out.name} = {self.components[3].get_init_v_flat()};\n" + \
               f"  assign {self.components[4].out.name} = {self.components[4].get_init_v_flat()};\n"

    # HIERARCHICAL VERILOG #
    def get_invocation_v(self):
        return f"  fa fa_{self.get_carry_wire().name}({self.a.name}, {self.b.name}, {self.c.name}, {self.get_sum_wire().name}, {self.get_carry_wire().name});"

    def get_function_sum_v_hier(self):
        return f"{self.components[0].get_gate_invocation_v(a=self.component_types[0].a, b=self.c, out=self.out.get_wire(0))}\n"

    def get_function_carry_v_hier(self):
        return f"{self.components[-1].get_gate_invocation_v(a=self.component_types[2].a, b=self.component_types[2].b, out=self.out.get_wire(1))}\n"

    def get_circuit_v(self):
        return f"{self.get_prototype_v()}" + \
               f"{self.get_declaration_v_hier()}\n" + \
               f"{self.get_init_v_hier()}\n" + \
               f"{self.get_function_sum_v_hier()}" + \
               f"{self.get_function_carry_v_hier()}" + \
               f"endmodule"
