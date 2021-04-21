from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    ArithmeticCircuit,
    MultiplierCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder,
    FullAdderPG,
    TwoOneMultiplexer,
    FullSubtractor
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


class ArrayDivider(ArithmeticCircuit):
    """Class representing array divider.

    Array divider performs division between two N bit numbers and stores their
    quotient in the output bus (remainder bits are not returned).

    Design is based on series of iterative subtractions.

    ```
           0  B3     0  B2     0  B1     A3 B0
           │  │      │  │      │  │      │  │
           │  │      │  │      │  │      │  │
         ┌─▼──▼─┐  ┌─▼──▼─┐  ┌─▼──▼─┐  ┌─▼──▼─┐
         │      │  │      │  │      │  │      │
       ┌─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─ 0
       │ │      │  │      │  │      │  │      │
       │ └──────┘  └───┬──┘  └───┬──┘  └───┬──┘
       │               │   │0    │   │0    │   │A3
       │             ┌─▼───▼┐  ┌─▼───▼┐  ┌─▼───▼┐
       ├────────────►│2:1MUX├─►│2:1MUX├─►│2:1MUX│
       │             └───┬──┘  └───┬──┘  └───┬──┘
       │              MX0│ B3   MX1│ B2   MX2│  B1     A2 B0
       │                 │ │       │ │       │  │      │  │
       │               ┌─▼─▼──┐  ┌─▼─▼──┐  ┌─▼──▼─┐  ┌─▼──▼─┐
       │               │      │  │      │  │      │  │      │
       │             ┌─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─ 0
       │             │ │      │  │      │  │      │  │      │
       │             │ └──────┘  └───┬──┘  └───┬──┘  └───┬──┘
       │             │               │   │MX1  │   │MX2  │   │A2
       │             │             ┌─▼───▼┐  ┌─▼───▼┐  ┌─▼───▼┐
       │             ├────────────►│2:1MUX├─►│2:1MUX│─►│2:1MUX│
       │             │             └───┬──┘  └───┬──┘  └───┬──┘
       │             │              MX3│ B3   MX4│ B2   MX5│  B1     A1 B0
       │             │                 │ │       │ │       │  │      │  │
       │             │               ┌─▼─▼──┐  ┌─▼─▼──┐  ┌─▼──▼─┐  ┌─▼──▼─┐
       │             │               │      │  │      │  │      │  │      │
       │             │             ┌─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─ 0
       │             │             │ │      │  │      │  │      │  │      │
       │             │             │ └──────┘  └───┬──┘  └───┬──┘  └───┬──┘
       │             │             │               │   │MX4  │   │MX5  │   │A1
       │             │             │             ┌─▼───▼┐  ┌─▼───▼┐  ┌─▼───▼┐
       │             │             │────────────►│2:1MUX├─►│2:1MUX│─►│2:1MUX│
       │             │             │             └───┬──┘  └───┬──┘  └───┬──┘
       │             │             │              MX6│ B3   MX7│ B2   MX8│  B1     A0 B0
       │             │             │                 │ │       │ │       │  │      │  │
       │             │             │               ┌─▼─▼──┐  ┌─▼─▼──┐  ┌─▼──▼─┐  ┌─▼──▼─┐
       │             │             │               │      │  │      │  │      │  │      │
       │             │             │             ┌─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─┤  FS  │◄─ 0
       │             │             │             │ │      │  │      │  │      │  │      │
       │             │             │             │ └──────┘  └──────┘  └──────┘  └──────┘
       │             │             │             │
       │             │             │             │
    ┌──▼──┐       ┌──▼──┐       ┌──▼──┐       ┌──▼──┐
    │     │       │     │       │     │       │     │
    │ NOT │       │ NOT │       │ NOT │       │ NOT │
    │     │       │     │       │     │       │     │
    └──┬──┘       └──┬──┘       └──┬──┘       └──┬──┘
       ▼             ▼             ▼             ▼
       Q3            Q2            Q1            Q0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of array divider. Defaults to "arrdiv".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "arrdiv"):
        super().__init__()
        self.N = max(a.N, b.N)
        self.prefix = prefix
        self.a = Bus(prefix=a.prefix, wires_list=a.bus)
        self.b = Bus(prefix=b.prefix, wires_list=b.bus)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Output wires for quotient result
        self.out = Bus(self.prefix+"_out", self.N)

        # Performing series of iterative subtractions
        # Gradually shifting the divisor
        for a_index in reversed(range(self.N)):
            # Series of subtractions to obtain quotient bit
            for b_index in range(self.N):
                # First full subtractor is formed from divisor's LSB bit (b_index) and divident's MSB bit (a_index)
                if b_index == 0:
                    adder_object = FullSubtractor(a=self.a.get_wire(a_index), b=self.b.get_wire(b_index), c=ConstantWireValue0(), prefix=self.prefix+"_fs"+str(self.get_instance_num(cls=FullSubtractor)))
                elif a_index == self.N-1:
                    adder_object = FullSubtractor(a=ConstantWireValue0(), b=self.b.get_wire(b_index), c=self.get_previous_component().get_borrow_wire(), prefix=self.prefix+"_fs"+str(self.get_instance_num(cls=FullSubtractor)))
                else:
                    adder_object = FullSubtractor(a=self.get_previous_component(self.N+1).out.get_wire(), b=self.b.get_wire(b_index), c=self.get_previous_component().get_borrow_wire(), prefix=self.prefix+"_fs"+str(self.get_instance_num(cls=FullSubtractor)))
                self.add_component(adder_object)

            # Don't generate multiplexers for divison remainders
            if a_index != 0:
                for mux_index in range(self.N-1):
                    mux_object = TwoOneMultiplexer(a=self.get_previous_component(self.N).get_difference_wire(), b=self.get_previous_component(self.N).a, c=self.get_previous_component(1+mux_index).get_borrow_wire(), prefix=self.prefix+"_mux2to1"+str(self.get_instance_num(cls=TwoOneMultiplexer)))
                    self.add_component(mux_object)

            # Every borrow out obtained from each iteration of subtractions needs to be negated to represent the quotient output bit
            quotient = NotGate(a=adder_object.get_borrow_wire(), prefix=self.prefix+"_not"+str(self.get_instance_num(cls=NotGate)), parent_component=self)
            self.add_component(quotient)
            self.out.connect(a_index, quotient.out)
