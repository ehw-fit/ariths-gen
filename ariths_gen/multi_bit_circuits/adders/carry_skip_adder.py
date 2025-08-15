from ariths_gen.wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.core.logic_gate_circuits import (
    MultipleInputLogicGate
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder,
    TwoOneMultiplexer
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    XorGate
)


class UnsignedCarrySkipAdder(GeneralCircuit):
    """Class representing unsigned carry skip (bypass) adder composed of smaller carry bypass blocks of chosen size to reduce propagation delay.

    Unsigned carry skip (bypass) adder represents faster adder circuit which is composed
    of more complex circuitry but provides much less propagation delay as opposed to rca.

    Each carry bypass block is composed of these logic parts:
    Propagate XOR gates compute propagate signals of corresponding bit pairs, these signals
    are then combined in multiple input AND gate (cascaded two input gates).
    Half/full adder cascade represents basic ripple carry adder design for input carry to ripple through them,
    additionally these adders compute individual output sum bits.
    Finally multiplexer lies at the end of each carry bypass block and is used to propagate block's input carry
    if multiple input AND gate output, which serves as select signal, is 1 or to wait for rippling of cout from the block's adders if it is 0.

    ```
                     ┼   ┼                      ┼   ┼
                 ┌───▼───▼───┐              ┌───▼───▼───┐
            ┌────┤ Propagate │         ┌────┤ Propagate │
            │SEL │  signals  │         │SEL │  signals  │
       ┌────▼─┐  └───────────┘    ┌────▼─┐  └───────────┘
       │      │                   │      │
    ┌──┤2:1MUX│◄────────────────┬─┤2:1MUX│◄────────────────┬─Cin
    │  │      │                 │ │      │                 │
    │  └────▲─┘      ┼   ┼      │ └────▲─┘      ┼   ┼      │
    │       │    ┌───▼───▼───┐  │      │    ┌───▼───▼───┐  │
    │       │    │  Adders   │◄─┘      │    │  Adders   │◄─┘
    │       └────┤           │         └────┤           │
    │            └─────┬─────┘              └─────┬─────┘
    │                  ┼                          ┼
    ▼                  ▼                          ▼
    Cout               Sums                       Sums
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        bypass_block_size (int, optional): Size of each composite bypass adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of unsigned cska. Defaults to "".
        name (str, optional): Name of unsigned cska. Defaults to "u_cska".
    """
    def __init__(self, a: Bus, b: Bus, bypass_block_size: int = 4, prefix: str = "", name: str = "u_cska", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        assert bypass_block_size > 0, "Block size of the individual bypass groups must be greater than 0."

        # To signify current number of blocks and number of bits that remain to be added into function blocks
        block_n = 0
        N_wires = self.N
        cin = ConstantWireValue0()
        while N_wires != 0:
            propagate_wires = []
            block_size = bypass_block_size if N_wires >= bypass_block_size else N_wires
            for i in range(block_size):
                # Generate propagate wires for corresponding bit pairs
                propagate_xor = XorGate(a=self.a.get_wire((block_n*bypass_block_size)+i), b=self.b.get_wire((block_n*bypass_block_size)+i), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
                self.add_component(propagate_xor)
                propagate_wires.append(propagate_xor.out)

                if block_n == 0 and i == 0:
                    obj_adder = HalfAdder(a=self.a.get_wire((block_n*bypass_block_size)+i), b=self.b.get_wire((block_n*bypass_block_size)+i), prefix=self.prefix+"_ha"+str(self.get_instance_num(cls=HalfAdder)))
                else:
                    obj_adder = FullAdder(a=self.a.get_wire((block_n*bypass_block_size)+i), b=self.b.get_wire((block_n*bypass_block_size)+i), c=cout, prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder)))

                cout = obj_adder.get_carry_wire()
                self.add_component(obj_adder)
                # Connecting adder's output sum bit to its proper position within the described circuit's output bus
                self.out.connect(i+(block_n*bypass_block_size), obj_adder.get_sum_wire())

            # ANDing of propagate wires, gate's output serves as select signal into 2:1 multiplexer and signifies whether block's input carry should be propagated (thus reducing delay) or not
            propagation_and = MultipleInputLogicGate(a=Bus(prefix=self.prefix+f"_propagate_signals{block_n}", N=len(propagate_wires), wires_list=propagate_wires), two_input_gate_cls=AndGate, parent_component=self, prefix=self.prefix+f"_and_propagate{block_n}")

            mux = TwoOneMultiplexer(a=cout, b=cin, c=propagation_and.out, prefix=self.prefix+"_mux2to1"+str(self.get_instance_num(cls=TwoOneMultiplexer)))
            self.add_component(mux)

            # Updating cin for the the next bypass block
            # Also updating cout value which is used as cin for the first adder of the next block
            cin = mux.out.get_wire()
            cout = mux.out.get_wire()
            N_wires -= block_size
            block_n += 1

        # Connection of final Cout
        self.out.connect(self.N, cin)


class SignedCarrySkipAdder(UnsignedCarrySkipAdder, GeneralCircuit):
    """Class representing signed carry skip (bypass) adder composed of smaller carry bypass blocks of chosen size to reduce propagation delay.

    Signed carry skip (bypass) adder represents faster adder circuit which is composed
    of more complex circuitry but provides much less propagation delay as opposed to rca.

    Each carry bypass block is composed of these logic parts:
    Propagate XOR gates compute propagate signals of corresponding bit pairs, these signals
    are then combined in multiple input AND gate (cascaded two input gates).
    Half/full adder cascade represents basic ripple carry adder design for input carry to ripple through them,
    additionally these adders compute individual output sum bits.
    Finally multiplexer lies at the end of each carry bypass block and is used to propagate block's input carry
    if multiple input AND gate output, which serves as select signal, is 1 or to wait for rippling of cout from the block's adders if it is 0.

    At last XOR gates are used to ensure proper sign extension.

    ```
                       ┼   ┼                      ┼   ┼
                   ┌───▼───▼───┐              ┌───▼───▼───┐
              ┌────┤ Propagate │         ┌────┤ Propagate │
              │SEL │  signals  │         │SEL │  signals  │
         ┌────▼─┐  └───────────┘    ┌────▼─┐  └───────────┘
         │      │                   │      │
       ┌─┤2:1MUX│◄────────────────┬─┤2:1MUX│◄────────────────┬─Cin
       │ │      │                 │ │      │                 │
       │ └────▲─┘      ┼   ┼      │ └────▲─┘      ┼   ┼      │
    ┌──▼───┐  │    ┌───▼───▼───┐  │      │    ┌───▼───▼───┐  │
    │ SIGN │  │    │  Adders   │◄─┘      │    │  Adders   │◄─┘
    │Extend│  └────┤           │         └────┤           │
    └──┬───┘       └─────┬─────┘              └─────┬─────┘
       │                 ┼                          ┼
       ▼                 ▼                          ▼
      Cout              Sums                       Sums
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        bypass_block_size (int, optional): Size of each composite bypass adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of signed cska. Defaults to "".
        name (str, optional): Name of signed cska. Defaults to "s_cska".
    """
    def __init__(self, a: Bus, b: Bus, bypass_block_size: int = 4, prefix: str = "", name: str = "s_cska", **kwargs):
        # Signed bus length extension
        N = max(a.N, b.N)
        a.bus_extend(N=N, prefix=a.prefix, desired_extension_wire=a.get_wire(a.N-1))
        b.bus_extend(N=N, prefix=b.prefix, desired_extension_wire=b.get_wire(b.N-1))
        
        super().__init__(a=a, b=b, bypass_block_size=bypass_block_size, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        sign_xor_1 = XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self)
        self.add_component(sign_xor_1)
        sign_xor_2 = XorGate(sign_xor_1.out, self.get_previous_component(2).out.get_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self)
        self.add_component(sign_xor_2)
        self.out.connect(self.N, sign_xor_2.out)
