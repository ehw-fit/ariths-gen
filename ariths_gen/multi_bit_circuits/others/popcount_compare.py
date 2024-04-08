"""

"""

from ariths_gen.multi_bit_circuits.others import UnsignedPopCount
from ariths_gen.multi_bit_circuits.others.compare import UnsignedCompareGTE
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

class PopCountCompare(GeneralCircuit):
    """Class representing a circiut
      if number of ones in a is larger or equal than number of ones in b

         │ │ │ │         │ │ │ │ │ 
         ▼ ▼ ▼ ▼         ▼ ▼ ▼ ▼ ▼ 
        ┌───────┐       ┌─────────┐
        │ popcnt│       │ popcnt  │
        └──┬────┘       └─────┬───┘
           │                  │    
           └───────┐   ┌──────┘    
                ┌──▼───▼──┐         
                │   <=    │         
                └────┬────┘         
                     │             
                     ▼             
    """

    def __init__(self, a: Bus, b: Bus, prefix : str = "", name : str = "popcnt_cmp", **kwargs):
        self.a = a
        self.b = b
        
        super().__init__(name=name, prefix=prefix, 
                         inputs = [self.a, self.b], out_N=1)

        p1 = self.add_component(UnsignedPopCount(self.a, 
                                                 prefix=f"{prefix}_popcount1",
                                                 inner_component=True)).out
        p2 = self.add_component(UnsignedPopCount(self.b, 
                                                 prefix=f"{prefix}_popcount2",
                                                 inner_component=True)).out

        #N = max(p1.N, p2.N)
        #p1.bus_extend(N)
        #p2.bus_extend(N)

        red = self.add_component(UnsignedCompareGTE(p1, p2, prefix=f"{prefix}_cmp", inner_component = True))
        self.out.connect_bus(red.out)
