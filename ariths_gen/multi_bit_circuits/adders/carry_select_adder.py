from ariths_gen.wire_components import (
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    FullAdder,
    TwoOneMultiplexer
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    OrGate,
    XorGate
)


class UnsignedCarrySelectAdder(GeneralCircuit):
    """Class representing unsigned carry select adder.

    Carry select adder's logic is divided into a number of carry select blocks.
    Each block precomputes the outputs for both possible carry bit inputs for the
    given block of input indexes.

    Each carry select block is composed of these logic parts:
    Two full adder chains where the first accepts input Cin of 1 and the second accepts Cin of 0.
    (In case of first block only one chain is used and actual sum bits are obtained)
    From second block onward the blocks also contain multiplexers to choose the appropriate precomputed sum based
    on the carry out signal from the previous block (which serves as a select signal for the multiplexers).
    Finally the block also contains AND and OR gate to determine the carry out of the current block.

    ```
                           ┼   ┼                ┼   ┼
                   Cout┌───▼───▼───┐            │   │
                   ┌───┤    FAs    │◄─0         │   │
                   │   └─────┬─────┘            │   │
                   │         ┼ Sums             │   │
       ┌───────────┘         └─────────┐        │   │
       │                   ┼   ┼       │        │   │
    ┌──▼─┐  ┌─────┐Cout┌───▼───▼───┐   │Cout┌───▼───▼───┐
    │ OR │◄─┤ AND │◄───┤    FAs    │◄─1│  ┌─┤    FAs    │◄─Cin
    └─┬──┘  └───▲─┘    └─────┬─────┘   │  │ └─────┬─────┘
      │         │            ┼ Sums    │  │       ┼
      │         │          ┌─┘ ┌───────┘  │       │
      │         └──────────┼───┼───────┬──┘       │
      │                ┌───▼───▼───┐SEL│          │
      │                │ 2:1 MUXes │◄──┘          │
      │                └─────┬─────┘              │
      │                      ┼                    │
      ▼                      ▼                    ▼
     Cout                   Sums                 Sums
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        select_block_size (int, optional): Size of each composite select adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of unsigned csla. Defaults to "".
        name (str, optional): Name of unsigned csla. Defaults to "u_csla".
    """
    def __init__(self, a: Bus, b: Bus, select_block_size: int = 4, prefix: str = "", name: str = "u_csla", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        assert select_block_size > 0, "Block size of the individual select groups must be greater than 0."

        # To signify current number of blocks and number of bits that remain to be added into function blocks
        block_n = 0
        N_wires = self.N
        cin = ConstantWireValue0()
        while N_wires != 0:
            block_size = select_block_size if N_wires >= select_block_size else N_wires
            for i in range(block_size):
                if block_n == 0:  # First block contains just one chain of full adders (with Cin)
                    obj_adder = FullAdder(a=self.a.get_wire((block_n*select_block_size)+i), b=self.b.get_wire((block_n*select_block_size)+i), c=cin, prefix=self.prefix+f"_cin_block{block_n}_fa{i}")
                    self.add_component(obj_adder)
                    # Connecting adder's output sum bit to its proper position within the described circuit's output bus
                    self.out.connect(i, obj_adder.get_sum_wire())
                    # Updating cin for the the next adder/select block
                    cin = obj_adder.get_carry_wire()
                else:  # Other blocks contain two full adder chains where the first accepts input Cin of 1 and the second accepts Cin of 0; then 2-1 MUXes choose the proper output sum bit and finally the AND OR logic propagates carry signal into the next select block
                    if i == 0:
                        obj_adder0 = FullAdder(a=self.a.get_wire((block_n*select_block_size)+i), b=self.b.get_wire((block_n*select_block_size)+i), c=ConstantWireValue0(), prefix=self.prefix+f"_0block{block_n}_fa{i}")
                        obj_adder1 = FullAdder(a=self.a.get_wire((block_n*select_block_size)+i), b=self.b.get_wire((block_n*select_block_size)+i), c=ConstantWireValue1(), prefix=self.prefix+f"_1block{block_n}_fa{i}")
                    else:
                        obj_adder0 = FullAdder(a=self.a.get_wire((block_n*select_block_size)+i), b=self.b.get_wire((block_n*select_block_size)+i), c=self.get_previous_component(3).get_carry_wire(), prefix=self.prefix+f"_0block{block_n}_fa{i}")
                        obj_adder1 = FullAdder(a=self.a.get_wire((block_n*select_block_size)+i), b=self.b.get_wire((block_n*select_block_size)+i), c=self.get_previous_component(2).get_carry_wire(), prefix=self.prefix+f"_1block{block_n}_fa{i}")
                    self.add_component(obj_adder0)
                    self.add_component(obj_adder1)

                    self.add_component(TwoOneMultiplexer(a=obj_adder0.get_sum_wire(), b=obj_adder1.get_sum_wire(), c=cin, prefix=self.prefix+f"_block{block_n}_mux2to1_{i}"))
                    # Connecting the selected adder's output sum bit to its proper position within the described circuit's output bus
                    self.out.connect(i+(block_n*select_block_size), self.get_previous_component().out.get_wire())

                    if i == block_size-1:
                        # Updating cin for the the next select block
                        cout0 = obj_adder0.get_carry_wire()
                        cout1 = obj_adder1.get_carry_wire()
                        self.add_component(AndGate(a=cout1, b=cin, prefix=self.prefix+f"_block{block_n}_and{i}", parent_component=self))
                        self.add_component(OrGate(a=cout0, b=self.get_previous_component().out, prefix=self.prefix+f"_block{block_n}_or{i}", parent_component=self))
                        cin = self.get_previous_component().out

            N_wires -= block_size
            block_n += 1
        # Connection of final Cout
        self.out.connect(self.N, cin)


class SignedCarrySelectAdder(UnsignedCarrySelectAdder, GeneralCircuit):
    """Class representing signed carry select adder.

    Carry select adder's logic is divided into a number of carry select blocks.
    Each block precomputes the outputs for both possible carry bit inputs for the
    given block of input indexes.

    Each carry select block is composed of these logic parts:
    Two full adder chains where the first accepts input Cin of 1 and the second accepts Cin of 0.
    (In case of first block only one chain is used and actual sum bits are obtained)
    From second block onward the blocks also contain multiplexers to choose the appropriate precomputed sum based
    on the carry out signal from the previous block (which serves as a select signal for the multiplexers).
    Finally the block also contains AND and OR gate to determine the carry out of the current block.
    At last XOR gates are used to ensure proper sign extension.

    ```
                            ┼   ┼                ┼   ┼
                    Cout┌───▼───▼───┐            │   │
                    ┌───┤    FAs    │◄─0         │   │
                    │   └─────┬─────┘            │   │
                    │         ┼ Sums             │   │
        ┌───────────┘         └─────────┐        │   │
        │                   ┼   ┼       │        │   │
     ┌──▼─┐  ┌─────┐Cout┌───▼───▼───┐   │Cout┌───▼───▼───┐
     │ OR │◄─┤ AND │◄───┤    FAs    │◄─1│  ┌─┤    FAs    │◄─Cin
     └─┬──┘  └───▲─┘    └─────┬─────┘   │  │ └─────┬─────┘
       │         │            ┼ Sums    │  │       ┼
    ┌──▼───┐     │          ┌─┘ ┌───────┘  │       │
    │ SIGN │     └──────────┼───┼───────┬──┘       │
    │Extend│            ┌───▼───▼───┐SEL│          │
    └──┬───┘            │ 2:1 MUXes │◄──┘          │
       │                └─────┬─────┘              │
       │                      ┼                    │
       ▼                      ▼                    ▼
      Cout                   Sums                 Sums
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        select_block_size (int, optional): Size of each composite select adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of signed csla. Defaults to "".
        name (str, optional): Name of signed csla. Defaults to "s_csla".
    """
    def __init__(self, a: Bus, b: Bus, select_block_size: int = 4, prefix: str = "", name: str = "s_csla", **kwargs):
        super().__init__(a=a, b=b, select_block_size=select_block_size, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        self.add_component(XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self))
        self.add_component(XorGate(self.get_previous_component().out, self.out.get_wire(-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self))
        self.out.connect(self.N, self.get_previous_component().out)
