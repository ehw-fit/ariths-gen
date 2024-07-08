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

        super().__init__(name=name, prefix=prefix, 
                         inputs = [self.a, self.b], out_N=1)

        # create wires
        psum = ConstantWireValue1()

        res = Bus(N = self.N, prefix=self.prefix + "res")

        for i in reversed(range(self.N)):
            iA = self.a[i] if i < self.a.N else ConstantWireValue0()
            iB = self.b[i] if i < self.b.N else ConstantWireValue0()
            
            i1 = self.add_component(NotGate(iA, f"{self.prefix}_i1_{i}")).out
            i2 = iB

            and1 = self.add_component(AndGate(i1, i2, f"{self.prefix}_and1_{i}")).out
            res[i] = self.add_component(AndGate(and1, psum, f"{self.prefix}_and2_{i}")).out

            pi = self.add_component(XnorGate(iA, iB, f"{self.prefix}_pi_{i}", parent_component=self)).out
            psum = self.add_component(AndGate(pi, psum, f"{self.prefix}_psum_{i}")).out


        red = self.add_component(OrReduce(res, prefix=f"{self.prefix}_orred", inner_component=True))
        self.out.connect_bus(red.out)


class UnsignedCompareLTE(GeneralCircuit):
    """Class representing unsigned compare
    
    Returns true if a <= b
    """

    def __init__(self, a: Bus, b: Bus, prefix : str = "", name : str = "cmp_lt", **kwargs):
        self.a = a
        self.b = b
        self.N = max(a.N, b.N)

        super().__init__(name=name, prefix=prefix, 
                         inputs = [self.a, self.b], out_N=1)

        # create wires
        psum = ConstantWireValue1()

        res = Bus(N = self.N + 1, prefix=self.prefix + "res")

        for i in reversed(range(self.N)):
            iA = self.a[i] if i < self.a.N else ConstantWireValue0()
            iB = self.b[i] if i < self.b.N else ConstantWireValue0()
            
            i1 = self.add_component(NotGate(iA, f"{self.prefix}_i1_{i}")).out
            i2 = iB

            and1 = self.add_component(AndGate(i1, i2, f"{self.prefix}_and1_{i}")).out
            res[i] = self.add_component(AndGate(and1, psum, f"{self.prefix}_and2_{i}")).out

            pi = self.add_component(XnorGate(iA, iB, f"{self.prefix}_pi_{i}", parent_component=self)).out
            psum = self.add_component(AndGate(pi, psum, f"{self.prefix}_psum_{i}")).out

        res[self.N] = psum # or all equal (xor)

        red = self.add_component(OrReduce(res, prefix=f"{self.prefix}_orred", inner_component=True))

        self.out.connect_bus(red.out)



class UnsignedCompareGT(GeneralCircuit):
    """Class representing unsigned compare

    
    Returns true if a < b
    """

    def __init__(self, a: Bus, b: Bus, prefix : str = "", name : str = "cmp_gt", **kwargs):
        self.a = a
        self.b = b
        self.N = max(a.N, b.N)

        super().__init__(name=name, prefix=prefix, 
                         inputs = [self.a, self.b], out_N=1)

        # create wires
        psum = ConstantWireValue1()

        res = Bus(N = self.N, prefix=self.prefix + "res")

        for i in reversed(range(self.N)):
            iA = self.a[i] if i < self.a.N else ConstantWireValue0()
            iB = self.b[i] if i < self.b.N else ConstantWireValue0()
            
            i1 = iA
            i2 = self.add_component(NotGate(iB, f"{self.prefix}_i2_{i}")).out

            and1 = self.add_component(AndGate(i1, i2, f"{self.prefix}_and1_{i}")).out
            res[i] = self.add_component(AndGate(and1, psum, f"{self.prefix}_and2_{i}")).out

            pi = self.add_component(XnorGate(iA, iB, f"{self.prefix}_pi_{i}", parent_component=self)).out
            psum = self.add_component(AndGate(pi, psum, f"{self.prefix}_psum_{i}")).out


        red = self.add_component(OrReduce(res, prefix=f"{self.prefix}_orred", inner_component=True))
        self.out.connect_bus(red.out)


class UnsignedCompareGTE(GeneralCircuit):
    """Class representing unsigned compare
    
    Returns true if a <= b
    """

    def __init__(self, a: Bus, b: Bus, prefix : str = "", name : str = "cmp_gte", **kwargs):
        self.a = a
        self.b = b
        self.N = max(a.N, b.N)

        super().__init__(name=name, prefix=prefix, 
                         inputs = [self.a, self.b], out_N=1)

        # create wires
        psum = ConstantWireValue1()

        res = Bus(N = self.N + 1, prefix=self.prefix + "res")

        for i in reversed(range(self.N)):
            iA = self.a[i] if i < self.a.N else ConstantWireValue0()
            iB = self.b[i] if i < self.b.N else ConstantWireValue0()
            
            i1 = iA
            i2 = self.add_component(NotGate(iB, f"{self.prefix}_i1_{i}", parent_component=self)).out

            and1 = self.add_component(AndGate(i1, i2, f"{self.prefix}_and1_{i}", parent_component=self)).out
            res[i] = self.add_component(AndGate(and1, psum, f"{self.prefix}_and2_{i}", parent_component=self)).out

            pi = self.add_component(XnorGate(iA, iB, f"{self.prefix}_pi_{i}", parent_component=self)).out
            psum = self.add_component(AndGate(pi, psum, f"{self.prefix}_psum_{i}", parent_component=self)).out

        res[self.N] = psum # or all equal (xor)
        
        red = self.add_component(OrReduce(res, prefix=f"{self.prefix}_orred", inner_component=True, parent_component=self))

        self.out.connect_bus(red.out)