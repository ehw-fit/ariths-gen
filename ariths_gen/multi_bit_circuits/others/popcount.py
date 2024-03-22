"""

"""

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus,
    wires
)
from ariths_gen.core.arithmetic_circuits import (
    ArithmeticCircuit,
    GeneralCircuit,
    MultiplierCircuit
)
from ariths_gen.core.logic_gate_circuits import (
    MultipleInputLogicGate
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder,
    FullAdderP,
    TwoOneMultiplexer
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)

from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder

from math import log2, ceil

class UnsignedPopCount(GeneralCircuit):
    """Class representing unsigned popcount circuit.

    Popcount circuit is a circuit that counts the number of 1s in a binary number.

    """

    def __init__(self, a: Bus, adder : ArithmeticCircuit|None = None, prefix : str = "", name : str = "popcnt", **kwargs):
        self.N = a.N
        self.a = a

        outc = ceil(log2(self.N + 1))
        #print("outc", outc)
        super().__init__(name=name, prefix=prefix, inputs = [self.a], out_N=outc)


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
                b_in = Bus(N=half, prefix=f"b_inn{depth}A")
                c_in = Bus(N=a.N - half, prefix=f"b_inn{depth}B")
                #print(a, half, a.N)


                for i, j in enumerate(range(half)):
                    b_in[i] = a[j]
                
                for i, j in enumerate(range(half, a.N)):
                    c_in[i] = a[j]

                b = create_tree(b_in, depth=depth + 1, branch = "A")
                c = create_tree(c_in, depth= depth + 1, branch = "B")
                d = self.adder(a=b, b=c, prefix = f"{self.prefix}_add{branch}_{depth}")
                self.add_component(d)
                return d.out
            
        sumbus = create_tree(self.a,0, "X")
        #print(sumbus)
        self.out.connect_bus(sumbus  )