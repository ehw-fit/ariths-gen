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

from ariths_gen.core.logic_gate_circuits import TwoInputLogicGate, TwoInputInvertedLogicGate, OneInputLogicGate
from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder

from math import log2, ceil

class BitReduce(GeneralCircuit):
    """Class representing tree reducer circuit. Doent work for NAND gate!
    """

    def __init__(self, a: Bus, gate : TwoInputLogicGate, prefix : str = "", name : str = "bitreduce", **kwargs):
        self.N = a.N
        self.a = a

        outc = 1
        super().__init__(name=name, prefix=prefix, inputs = [self.a], out_N=outc)

        # tree reduction
        def create_tree(a: Bus, depth: int, branch="A"):

            #print(a)
            if a.N == 1:
                return a[0]
            else:
                half = a.N // 2
                b_in = Bus(N=half, prefix=f"b_inn{depth}A")
                c_in = Bus(N=a.N - half, prefix=f"b_inn{depth}B")
                #print(a, half, a.N)


                for i, j in enumerate(range(half)):
                    b_in[i] = a[j]
                
                for i, j in enumerate(range(half, a.N)):
                    c_in[i] = a[j]

                b = create_tree(b_in, depth=depth + 1, branch = branch + "A")
                c = create_tree(c_in, depth= depth + 1, branch = branch + "B")
                d = gate(a=b, b=c, prefix = f"{self.prefix}_red_{branch}_{depth}")
                self.add_component(d)
                return d.out
            
        sumwire = create_tree(self.a, 0, "X")
        #print(sumbus)
        self.out[0] = sumwire


class OrReduce(BitReduce):
    def __init__(self, a: Bus, prefix: str = "", name: str = "orreduce", **kwargs):
        super().__init__(a=a, gate=OrGate, prefix=prefix, name=name, **kwargs)


class AndReduce(BitReduce):
    def __init__(self, a: Bus, prefix: str = "", name: str = "andreduce", **kwargs):
        super().__init__(a=a, gate=AndGate, prefix=prefix, name=name, **kwargs)
