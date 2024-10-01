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
    """Class representing unsigned ripple carry subtractor.

    Unsigned ripple carry subtractor represents N-bit unsigned subtractor which is composed of
    N one bit fulladders. The first FA has carry-in set to one and the B inputs of all FAs are inverted.
    ```
          ──         ──         ──         ──        
          B3 A3      B2 A2      B1 A1      B0 A0     
          │  │       │  │       │  │       │  │      
        ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐    
        │      │ C3│      │ C2│      │ C1│      │  1
     ┌──┤  FA  │◄──┤  FA  │◄──┤  FA  │◄──┤  FA  │◄── 
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


class SignedRippleCarrySubtractor(UnsignedRippleCarrySubtractor, GeneralCircuit):
    """Class representing signed ripple carry subtractor.

    Signed ripple carry subtractor represents N-bit signed subtractor which is composed of
    N one bit fulladders. The first FA has carry-in set to one and the B inputs of all FAs are inverted.
    At last XOR gates are used to ensure proper sign extension.

    Its downside is its long propagation delay the bigger the circuit is.

    ```
      __         __         __         __         __
      B3 A3      B3 A3      B2 A2      B1 A1      B0 A0
      │  │       │  │       │  │       │  │       │  │
    ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐
    │ SIGN │ C4│      │ C3│      │ C2│      │ C1│      │  1
    │Extend│◄──┤  FA  │◄──┤  FA  │◄──┤  FA  │◄──┤  FA  │◄──
    │      │   │      │   │      │   │      │   │      │
    └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘
       ▼          ▼          ▼          ▼          ▼
      Cout        S3         S2         S1         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed rcs. Defaults to "".
        name (str, optional): Name of signed rcs. Defaults to "s_rcs".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_rcs", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.get_previous_component(2).a, self.get_previous_component(2).b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(3).get_carry_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
