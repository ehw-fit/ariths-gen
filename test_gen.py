
from ariths_gen.core.arithmetic_circuits import GeneralCircuit
from ariths_gen.wire_components import Bus
from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder
from ariths_gen.multi_bit_circuits.multipliers import UnsignedArrayMultiplier

class MAC(GeneralCircuit):
    def __init__(self, A:Bus, B:Bus, R:Bus):
        self.prefix = "ma"
        super().__init__([A, B, R])
        assert A.N == B.N
        assert R.N == 2 * A.N
        self.mul = self.add_component(UnsignedArrayMultiplier(A, B))
        self.add = self.add_component(UnsignedRippleCarryAdder(R, self.mul.out))

        self.out = self.add.out

# usage
mymac = MAC(Bus("a",8), Bus("b", 8), Bus("acc", 16))
mymac.get_v_code_hier(open("out.v", "w"))
mymac.get_c_code_hier(open("out.c", "w"))