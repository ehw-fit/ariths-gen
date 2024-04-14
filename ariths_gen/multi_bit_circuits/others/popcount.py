from ariths_gen.wire_components import (
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit,
    GeneralCircuit
)
from ariths_gen.multi_bit_circuits.adders import (
    UnsignedRippleCarryAdder
)
from typing import Optional
from math import log2, ceil


class UnsignedPopCount(GeneralCircuit):
    """Class representing unsigned popcount circuit.

    Popcount circuit is a circuit that counts the number of 1s in a binary number.

    """

    def __init__(self, a: Bus, adder : Optional[GeneralCircuit] = None, prefix : str = "", name : str = "popcnt", **kwargs):
        self.N = a.N
        outc = ceil(log2(self.N + 1))
        #print("outc", outc)
        super().__init__(name=name, prefix=prefix, inputs=[a], out_N=outc)

        self.a.bus_extend(2**(outc - 1), prefix=a.prefix)
        #print(self.a)
        self.adder = adder
        if not self.adder:
            self.adder = UnsignedRippleCarryAdder

        # tree reduction
        def create_tree(a: Bus, depth: int, branch="A"):
            #print(a)
            if a.N == 1:
                return a
            else:
                half = a.N // 2
                b_in = Bus(N=half, prefix=f"b_inn_{branch}_{depth}A")
                c_in = Bus(N=a.N - half, prefix=f"b_inn_{branch}_{depth}B")
                #print(b_in.prefix)
                #print(a, half, a.N)
                for i, j in enumerate(range(half)):
                    b_in.connect(i, a.get_wire(j))
                for i, j in enumerate(range(half, a.N)):
                    c_in.connect(i, a.get_wire(j))

                b = create_tree(b_in, depth=depth + 1, branch = branch + "A")
                c = create_tree(c_in, depth=depth + 1, branch = branch + "B")

                d = self.adder(a=b, b=c, prefix = f"{self.prefix}_add{branch}_{depth}")
                self.add_component(d)
                return d.out

        sumbus = create_tree(self.a,0, "X")
        #print(sumbus)
        self.out.connect_bus(sumbus)
