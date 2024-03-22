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

from ariths_gen.multi_bit_circuits.others import OrReduce


from math import log2, ceil

class UnsignedCompareLT(GeneralCircuit):
    """Class representing unsigned compare

    
    Returns true if a < b

    """

    def __init__(self, a: Bus, b: Bus, prefix : str = "", name : str = "cmp_lt", **kwargs):
        self.a = a
        self.b = b
        self.N = max(a.N, b.N)

        #print("outc", outc)
        super().__init__(name=name, prefix=prefix, 
                         inputs = [self.a, self.b], out_N=1)


        self.a.bus_extend(self.N, prefix=a.prefix)
        self.b.bus_extend(self.N, prefix=b.prefix)
        

        # create wires
        psum = ConstantWireValue1()

        res = Bus(N = self.N, prefix=self.prefix + "res")
        

        for i in reversed(range(self.N)):

            i1 = self.add_component(NotGate(self.a[i], f"{self.prefix}_i1_{i}")).out
            i2 = self.b[i]

            and1 = self.add_component(AndGate(i1, i2, f"{self.prefix}_and1_{i}")).out
            res[i] = self.add_component(AndGate(and1, psum, f"{self.prefix}_and2_{i}")).out

            pi = self.add_component(XnorGate(self.a[i], self.b[i], f"{self.prefix}_pi_{i}")).out
            psum = self.add_component(AndGate(pi, psum, f"{self.prefix}_psum_{i}")).out


        self.out = self.add_component(OrReduce(res, prefix=f"{self.prefix}_orred")).out
        #self.out.connect_bus(sumbus  )