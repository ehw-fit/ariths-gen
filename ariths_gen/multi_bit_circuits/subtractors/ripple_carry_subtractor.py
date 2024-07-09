from ariths_gen.wire_components import (
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder
)
from ariths_gen.one_bit_circuits.logic_gates import (
    XorGate, NotGate
)
from ariths_gen.wire_components.wires import ConstantWireValue1


class UnsignedRippleCarrySubtractor(GeneralCircuit):
    """Class representing unsigned ripple carry adder.

    Unsigned ripple carry adder represents N-bit unsigned adder which is composed of
    N one bit fulladders. The first has carry-in set to one and the B input is inverted.
    ```
          ──         ──         ──         ──        
          B3 A3      B2 A2      B1 A1      B0 A0     
          │  │       │  │       │  │       │  │      
        ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐    
        │      │ C3│      │ C2│      │ C1│      │   1
     ┌──┤  FA  │◄──┤  FA  │◄──┤  FA  │◄──┤  HA  │◄── 
     │  │      │   │      │   │      │   │      │    
     │  └──────┘   └──────┘   └──────┘   └──────┘    
     ▼     ▼          ▼          ▼          ▼        
    Cout   S3         S2         S1         S0       
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned rcs. Defaults to "".
        name (str, optional): Name of unsigned rcs. Defaults to "u_rcs".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_rcs", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N + 1, signed_out=True, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            b_not = self.add_component(NotGate(self.b.get_wire(input_index), prefix=self.prefix+"_not"+str(input_index)))
            # First adder is a half adder
            if input_index == 0:
                obj_adder = FullAdder(self.a.get_wire(input_index), b_not.out, ConstantWireValue1(), prefix=self.prefix+"_ha")
            # Rest adders are full adders
            else:
                obj_adder = FullAdder(self.a.get_wire(input_index), b_not.out, obj_adder.get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))

            self.add_component(obj_adder)
            self.out.connect(input_index, obj_adder.get_sum_wire())

        # invert the last carry wire
        self.add_component(NotGate(obj_adder.get_carry_wire(), prefix=self.prefix+"_not_c"+str(self.N-1)))
        self.out.connect(self.N, self.get_previous_component().out)


class SignedRippleCarrySubtractor(GeneralCircuit):
    """Class representing signed ripple carry subtractor.

    Signed ripple carry adder represents N-bit signed adder which is composed of
    N one bit adders, where first is a half adder and rest are full adders.
    At last XOR gates are used to ensure proper sign extension.

    Its downside is its long propagation delay the bigger the circuit is.

    ```
      __         __         __         __         __         __
      B3 A3      B3 A3      B3 A3      B2 A2      B1 A1      B0 A0
      │  │       │  │       │  │       │  │       │  │       │  │
    ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐
    │ SIGN │ C4│ SIGN │ C4│      │ C3│      │ C2│      │ C1│      │
    │Extend│◄──│Extend│◄──┤  FA  │◄──┤  FA  │◄──┤  FA  │◄──┤  HA  │
    │   2  │   │      │   │      │   │      │   │      │   │      │
    └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘
       ▼          ▼          ▼          ▼          ▼          ▼
       S5         S4         S3         S2         S1         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed rca. Defaults to "".
        name (str, optional): Name of signed rca. Defaults to "s_rcs".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_rcs", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N + 2, signed=True, **kwargs)

        assert self.a.N == self.b.N, "Both buses must have the same length" 
        # Bus sign extension in case buses have different lengths - don't know if works
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        

        # Gradual addition of 1-bit adder components
        for input_index in range(self.N):
            b_not = self.add_component(NotGate(self.b.get_wire(input_index), prefix=self.prefix+"_not"+str(input_index)))
            # First adder is a half adder
            if input_index == 0:
                obj_adder = FullAdder(self.a.get_wire(input_index), b_not.out, ConstantWireValue1(), prefix=self.prefix+"_ha")
            # Rest adders are full adders
            else:
                obj_adder = FullAdder(self.a.get_wire(input_index), b_not.out, obj_adder.get_carry_wire(), prefix=self.prefix+"_fa"+str(input_index))

            self.add_component(obj_adder)
            self.out.connect(input_index, obj_adder.get_sum_wire())

        # replicate the last (sign) bit
        obj_adder = FullAdder(self.a.get_wire(self.N - 1), b_not.out, obj_adder.get_carry_wire(), prefix=self.prefix+"_fa_repl_"+str(input_index))
        self.add_component(obj_adder)
        self.out.connect(self.N, self.get_previous_component().get_sum_wire())


        
        obj_adder = FullAdder(self.a.get_wire(self.N - 1), b_not.out, obj_adder.get_carry_wire(), prefix=self.prefix+"_fa_repl2_"+str(input_index))
        self.add_component(obj_adder)

        self.out.connect(self.N+1, self.get_previous_component().get_sum_wire())

        # invert the last carry wire
        #onot = self.add_component(NotGate(obj_adder.get_carry_wire(), prefix=self.prefix+"_not_c"+str(self.N-1)))
        #self.out.connect(self.N + 1, onot.out)