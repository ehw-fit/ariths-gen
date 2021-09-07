
from ariths_gen.core.arithmetic_circuits.arithmetic_circuit import ArithmeticCircuit
from ariths_gen.core.arithmetic_circuits import GeneralCircuit
from ariths_gen.wire_components import Bus, Wire
from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder
from ariths_gen.multi_bit_circuits.multipliers import UnsignedArrayMultiplier
import os

class MAC(GeneralCircuit):
    def __init__(self, A:Bus, B:Bus, R:Bus, prefix= "mac", **kwargs):
        super().__init__(prefix=prefix, out_N=2*A.N+1, inputs=[A, B, R], **kwargs)
        assert A.N == B.N
        assert R.N == 2 * A.N

        self.mul = self.add_component(UnsignedArrayMultiplier(a=A, b=B, prefix=self.prefix, inner_component=True))
        self.add = self.add_component(UnsignedRippleCarryAdder(a=R, b=self.mul.out, prefix=self.prefix, inner_component=True))
        self.out.connect_bus(connecting_bus=self.add.out)

# usage
os.makedirs("test_circuits/mac", exist_ok=True)
mymac = MAC(Bus("a",8), Bus("b", 8), Bus("acc", 16))
mymac.get_v_code_hier(open("test_circuits/mac/mac_hier.v", "w"))
mymac.get_c_code_hier(open("test_circuits/mac/mac_hier.c", "w"))
mymac.get_c_code_flat(open("test_circuits/mac/mac_flat.c", "w"))

test = UnsignedRippleCarryAdder(Bus("a",8), Bus("b", 8))
test.get_v_code_hier(open("test_circuits/urca_hier.v", "w"))

