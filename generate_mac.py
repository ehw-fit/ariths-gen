
from ariths_gen.core.arithmetic_circuits.arithmetic_circuit import ArithmeticCircuit
from ariths_gen.core.arithmetic_circuits import GeneralCircuit
from ariths_gen.wire_components import Bus, Wire
from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder
from ariths_gen.multi_bit_circuits.multipliers import UnsignedArrayMultiplier, UnsignedDaddaMultiplier
import os


class MAC(GeneralCircuit):
    def __init__(self, a: Bus, b: Bus, r: Bus, prefix: str = "", name: str = "mac", **kwargs):
        super().__init__(prefix=prefix, name=name, out_N=2*a.N+1, inputs=[a, b, r], **kwargs)
        assert a.N == b.N
        assert r.N == 2 * a.N

        self.mul = self.add_component(UnsignedArrayMultiplier(a=a, b=b, prefix=self.prefix, name=f"u_arrmul{a.N}", inner_component=True))
        self.add = self.add_component(UnsignedRippleCarryAdder(a=r, b=self.mul.out, prefix=self.prefix, name=f"u_rca{r.N}", inner_component=True))
        self.out.connect_bus(connecting_bus=self.add.out)


# usage
if __name__ == "__main__":
    os.makedirs("test_circuits/mac", exist_ok=True)
    mymac = MAC(Bus("a", 8), Bus("b", 8), Bus("acc", 16), outname="mac_output")
    mymac.get_v_code_hier(open("test_circuits/mac/mac_hier.v", "w"))
    mymac.get_c_code_hier(open("test_circuits/mac/mac_hier.c", "w"))
    mymac.get_c_code_flat(open("test_circuits/mac/mac_flat.c", "w"))
