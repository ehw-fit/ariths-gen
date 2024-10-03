from ariths_gen.wire_components import (
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfSubtractor,
    FullSubtractor
)
from ariths_gen.one_bit_circuits.logic_gates import (
    XorGate
)


class UnsignedRippleBorrowSubtractor(GeneralCircuit):
    """Class representing unsigned ripple borrow subtractor.

    Unsigned ripple borrow subtractor represents N-bit unsigned subtractor which is composed of
    N one bit subtractors, where the first is a half subtractor and rest are full subtractor.
    ```
          B3 A3      B2 A2      B1 A1      B0 A0     
          │  │       │  │       │  │       │  │      
        ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐    
        │      │ B3│      │ B2│      │ B1│      │
     ┌──┤  FS  │◄──┤  FS  │◄──┤  FS  │◄──┤  HS  │
     │  │      │   │      │   │      │   │      │    
     │  └──────┘   └──────┘   └──────┘   └──────┘    
     ▼     ▼          ▼          ▼          ▼        
    Bout   D3         D2         D1         D0       
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned rbs. Defaults to "".
        name (str, optional): Name of unsigned rbs. Defaults to "u_rbs".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_rbs", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N + 1, signed_out=True, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Gradual addition of 1-bit subtractor components
        for input_index in range(self.N):
            # First adder is a half subtractor
            if input_index == 0:
                obj_subtractor = HalfSubtractor(self.a.get_wire(input_index), self.b.get_wire(input_index), prefix=self.prefix+"_hs")
            # Rest adders are full subtractor
            else:
                obj_subtractor = FullSubtractor(self.a.get_wire(input_index), self.b.get_wire(input_index), obj_subtractor.get_borrow_wire(), prefix=self.prefix+"_fs"+str(input_index))

            self.add_component(obj_subtractor)
            self.out.connect(input_index, obj_subtractor.get_difference_wire())
            if input_index == (self.N-1):
                self.out.connect(self.N, obj_subtractor.get_borrow_wire())


class SignedRippleBorrowSubtractor(UnsignedRippleBorrowSubtractor, GeneralCircuit):
    """Class representing signed ripple borrow subtractor.

    Signed ripple borrow subtractor represents N-bit signed subtractor which is composed of
    N one bit subtractor, where the first is a half subtractor and rest are full subtractor.
    At last XOR gates are used to ensure proper sign extension.

    Its downside is its long propagation delay the bigger the circuit is.

    ```
      B3 A3      B3 A3      B2 A2      B1 A1      B0 A0
      │  │       │  │       │  │       │  │       │  │
    ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐   ┌─▼──▼─┐
    │ SIGN │ B4│      │ B3│      │ B2│      │ B1│      │
    │Extend│◄──┤  FS  │◄──┤  FS  │◄──┤  FS  │◄──┤  HS  │
    │      │   │      │   │      │   │      │   │      │
    └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘   └──┬───┘
       ▼          ▼          ▼          ▼          ▼
      Bout        D3         D2         D1         D0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed rbs. Defaults to "".
        name (str, optional): Name of signed rbs. Defaults to "s_rbs".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_rbs", **kwargs):
        super().__init__(a=a, b=b, prefix=prefix, name=name, signed=True, **kwargs)
        
        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.get_previous_component(1).a, self.get_previous_component(1).b, prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).get_borrow_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
