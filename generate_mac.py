
from ariths_gen.core.arithmetic_circuits import GeneralCircuit
from ariths_gen.wire_components import Bus, Wire
from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder
from ariths_gen.multi_bit_circuits.multipliers import UnsignedArrayMultiplier
import os

class MAC(GeneralCircuit):
    def __init__(self, A:Bus, B:Bus, R:Bus):
        self.prefix = "mac"
        super().__init__([A, B, R])
        assert A.N == B.N
        assert R.N == 2 * A.N


        if False:
            # Je zapotřebí zajistit ještě unikátnost jmen podkomponent a jejich vodičů pro správné generování
            mul_a = Bus(prefix=f"{self.prefix}_mul_a", wires_list=A.bus)
            mul_b = Bus(prefix=f"{self.prefix}_mul_b", wires_list=B.bus)
            self.mul = self.add_component(UnsignedArrayMultiplier(a=mul_a, b=mul_b, prefix=f"{self.prefix}_mul"))

            add_a = Bus(prefix=f"{self.prefix}_add_a", N=self.mul.out.N)
            add_b = Bus(prefix=f"{self.prefix}_add_b", wires_list=R.bus)
            # Kvůli správnému generování je potřeba správně napojit vodiče mezi mul a add
            [add_a.connect(o, self.mul.out.get_wire(o), inserted_wire_desired_index=o) for o in range(0, self.mul.out.N)]

            self.add = self.add_component(UnsignedRippleCarryAdder(a=add_a, b=add_b, prefix=f"{self.prefix}_add"))

            # Bylo potřeba upravit definici pro výstupní sběrnici (vázanou na název top level obvodu ("ma") a mající délku jako výstup z adderu)
            self.out = Bus(self.prefix+"_out", self.add.out.N)
            
            # Nakonec je potřeba napojit výstup adderu na výstup mac
            [self.out.connect(o, self.add.out.get_wire(o), inserted_wire_desired_index=o) for o in range(0, self.out.N)]

        else:
            # Je zapotřebí zajistit ještě unikátnost jmen podkomponent a jejich vodičů pro správné generování
            mul_prefix = self.prefix + "_" + UnsignedArrayMultiplier(a=A, b=B).prefix + str(A.N)
            mul_a = Bus(prefix=f"{mul_prefix}_a", wires_list=A.bus)
            mul_b = Bus(prefix=f"{mul_prefix}_b", wires_list=B.bus)
            self.mul = self.add_component(UnsignedArrayMultiplier(a=mul_a, b=mul_b, prefix=mul_prefix))

            add_prefix = self.prefix + "_" + UnsignedRippleCarryAdder(a=R, b=self.mul.out).prefix + str(R.N)
            add_a = Bus(prefix=f"{add_prefix}_a", N=self.mul.out.N)
            add_b = Bus(prefix=f"{add_prefix}_b", wires_list=R.bus)
            # Kvůli správnému generování je potřeba správně napojit vodiče mezi mul a add
            [add_a.connect(o, self.mul.out.get_wire(o), inserted_wire_desired_index=o) for o in range(0, self.mul.out.N)]

            self.add = self.add_component(UnsignedRippleCarryAdder(a=add_a, b=add_b, prefix=add_prefix))

            # Bylo potřeba upravit definici pro výstupní sběrnici (vázanou na název top level obvodu ("ma") a mající délku jako výstup z adderu)
            self.out = Bus(self.prefix+"_out", self.add.out.N)
            
            # Nakonec je potřeba napojit výstup adderu na výstup mac
            [self.out.connect(o, self.add.out.get_wire(o), inserted_wire_desired_index=o) for o in range(0, self.out.N)]
# usage
os.makedirs("test_circuits/mac", exist_ok=True)
mymac = MAC(Bus("a",8), Bus("b", 8), Bus("acc", 16))
mymac.get_v_code_hier(open("test_circuits/mac/mac_hier.v", "w"))
mymac.get_c_code_hier(open("test_circuits/mac/mac_hier.c", "w"))
mymac.get_c_code_flat(open("test_circuits/mac/mac_flat.c", "w"))
