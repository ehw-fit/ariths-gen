from ariths_gen.wire_components import (
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)

from ariths_gen.multi_bit_circuits.others import (
    UnsignedPopCount,
    UnsignedCompareGTE
)


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
        super().__init__(name=name, prefix=prefix, inputs=[a, b], out_N=1, **kwargs)

        p1 = self.add_component(UnsignedPopCount(a=Bus(wires_list=self.a.bus, prefix=f"{prefix}_popcount1_a"),
                                                 prefix=f"{prefix}_popcount1",
                                                 inner_component=True)).out
        p2 = self.add_component(UnsignedPopCount(a=Bus(wires_list=self.b.bus, prefix=f"{prefix}_popcount2_a"),
                                                 prefix=f"{prefix}_popcount2",
                                                 inner_component=True)).out
        #N = max(p1.N, p2.N)
        #p1.bus_extend(N)
        #p2.bus_extend(N)
        red = self.add_component(UnsignedCompareGTE(p1, p2, prefix=f"{prefix}_cmp", inner_component = True))
        self.out.connect_bus(red.out)
