from ariths_gen.wire_components import(
    Wire,
    Bus
)
from ariths_gen.core import(
    ArithmeticCircuit,
    MultiplierCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import(
    HalfAdder,
    PGLogicBlock,
    ConstantWireValue0,
    ConstantWireValue1,
    FullAdder,
    FullAdderPG
)
from ariths_gen.one_bit_circuits.logic_gates import(
    LogicGate,
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)

class UnsignedPGRippleCarryAdder(ArithmeticCircuit):
    def __init__(self, a: Bus, b: Bus, prefix: str = "u_pg_rca"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = Bus(prefix=a.prefix, wires_list=a.bus)
        self.b = Bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for N sum bits and additional cout bit
        self.out = Bus("out", self.N+1)

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            if input_index == 0:
                # Constant wire with value 0 for cin 0
                constant_wire_0 = ConstantWireValue0(self.a.get_wire(), self.b.get_wire())
                self.add_component(constant_wire_0)
                obj_fa_cla = FullAdderPG(self.a.get_wire(input_index), self.b.get_wire(input_index), constant_wire_0.out.get_wire(), prefix=self.prefix+"_fa"+str(input_index))
            else:
                obj_fa_cla = FullAdderPG(self.a.get_wire(input_index), self.b.get_wire(input_index), self.get_previous_component().out, prefix=self.prefix+"_fa"+str(input_index))
            
            self.add_component(obj_fa_cla)
            self.out.connect(input_index, obj_fa_cla.get_sum_wire())

            obj_and = AndGate(self.get_previous_component().c, self.get_previous_component().get_propagate_wire(), prefix=self.prefix+"_and"+str(input_index))
            obj_or = OrGate(obj_and.out, self.get_previous_component().get_generate_wire(), prefix=self.prefix+"_or"+str(input_index))
            self.add_component(obj_and)
            self.add_component(obj_or)
            
            # Connecting last output bit to last cout
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_or.out)


class SignedPGRippleCarryAdder(UnsignedPGRippleCarryAdder, ArithmeticCircuit):
    def __init__(self, a: Bus, b: Bus, prefix: str = "s_pg_rca"):
        super().__init__(a=a, b=b, prefix=prefix)
        self.c_data_type = "int64_t"

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)))
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)))
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)