from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus,
    wires
)
from ariths_gen.core.arithmetic_circuits import (
    ArithmeticCircuit,
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


class UnsignedCarryIncrementAdder(ArithmeticCircuit):
    """Class representing unsigned carry increment adder.

    Carry increment adder represents a modified carry select adder that achieves about the same critical delay
    while containing less circuitry. It achieves this by factoring out the common logic from the two
    chains of full adders (one with cin of 0, the other with 1) present in a classical carry select adder and
    by replacing multiplexers with HAs.

    Each carry increment block is composed of these logic parts:
    Full adder chain with cin 0 is used to obtain intermediate sum, propagate and cout signals. (In case of first block actual sum bits are obtained)
    From second block onward the blocks also contain a chain of half adders to calculate the final sum bits.
    Finally the intermediate propagate signals are ANDed with the cout of the half adder chain and ORed with the intermediate
    full adder cout to determine the carry bit for the next increment block.

    ```
                           ┼   ┼                ┼   ┼
                   Cout┌───▼───▼───┐            │   │
       ┌───────────────┤    FAs    │◄─0         │   │
       │               └┬────────┬─┘            │   │
       │    ┌─────┐     ┼ P sigs ┼ Sums         │   │
       │    │ ANDs│◄────┘        │              │   │
       │    └───┬─┘              │              │   │
    ┌──▼─┐  ┌───▼─┐Cout┌─────────▼─┐    Cout┌───▼───▼───┐
    │ OR │◄─┤ AND │◄───┤    HAs    │◄───────┤    FAs    │◄─Cin
    └─┬──┘  └─────┘    └─────┬─────┘        └─────┬─────┘
      │                      ┼                    ┼
      │                      │                    │
      ▼                      ▼                    ▼
     Cout                   Sums                 Sums
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        increment_block_size (int, optional): Size of each composite select adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of unsigned cia. Defaults to "".
        name (str, optional): Name of unsigned cia. Defaults to "u_cia".
    """
    def __init__(self, a: Bus, b: Bus, increment_block_size: int = 4, prefix: str = "", name: str = "u_cia", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        assert increment_block_size > 0, "Block size of the individual increment groups must be greater than 0."

        # To signify current number of blocks and number of bits that remain to be added into function blocks
        block_n = 0
        N_wires = self.N
        cin = ConstantWireValue0()
        while N_wires != 0:
            propagate_wires = []
            block_size = increment_block_size if N_wires >= increment_block_size else N_wires
            for i in range(block_size):
                if block_n == 0:  # First block contains one chain of full adders (with Cin) directly connected to output wires
                    self.add_component(FullAdder(a=self.a.get_wire((block_n*increment_block_size)+i), b=self.b.get_wire((block_n*increment_block_size)+i), c=cin, prefix=self.prefix+f"_cin_block{block_n}_fa{i}"))
                else:  # Other blocks contain one chain of full adders accepting input Cin of 0 to calculate intermediate sum/carry/propagate signals in parallel and other chain of half adders to calculate final sum bits and finally AND OR logic to propagate carry into the next increment block
                    inter_cin = ConstantWireValue0() if i == 0 else inter_cin
                    self.add_component(FullAdderP(a=self.a.get_wire((block_n*increment_block_size)+i), b=self.b.get_wire((block_n*increment_block_size)+i), c=inter_cin, prefix=self.prefix+f"_block{block_n}_fa_p{i}"))
                    propagate_wires.append(self.get_previous_component().get_propagate_wire())
                    inter_cin = self.get_previous_component().get_carry_wire()

                    # Chain of HA to obtain final sum bits
                    self.add_component(HalfAdder(a=self.get_previous_component().get_sum_wire(), b=cin, prefix=self.prefix+f"_block{block_n}_ha{i}"))
                # Updating cin for the the next adder
                cin = self.get_previous_component().get_carry_wire()
                # Connecting adder's output sum bit to its proper position within the described circuit's output bus
                self.out.connect(i+(block_n*increment_block_size), self.get_previous_component().get_sum_wire())

            # ANDing of propagate wires, gate's output serves as an input into another AND gate that is used along with the other input (carry from the current increment block) to determine the propagate signal value; next the propagate signal with the carry output from the intermediate FA carry chain is driven to an OR gate to obtain the carry bit for the next increment block
            if block_n != 0:
                propagation_and = MultipleInputLogicGate(a=Bus(prefix=self.prefix+f"_propagate_signal{block_n}", N=len(propagate_wires), wires_list=propagate_wires), two_input_gate_cls=AndGate, parent_component=self, prefix=self.prefix+f"_and_propagate{block_n}")
                self.add_component(AndGate(a=propagation_and.out, b=cin, prefix=self.prefix+"_and"+str(self.get_instance_num(cls=AndGate)), parent_component=self))
                self.add_component(OrGate(a=self.get_previous_component().out, b=inter_cin, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), parent_component=self))
                cin = self.get_previous_component().out

            N_wires -= block_size
            block_n += 1
        # Connection of final Cout
        self.out.connect(self.N, cin)


class SignedCarryIncrementAdder(UnsignedCarryIncrementAdder, ArithmeticCircuit):
    """Class representing signed carry increment adder.

    Carry increment adder represents a modified carry select adder that achieves about the same critical delay
    while containing less circuitry. It achieves this by factoring out the common logic from the two
    chains of full adders (one with cin of 0, the other with 1) present in a classical carry select adder and
    by replacing multiplexers with HAs.

    Each carry increment block is composed of these logic parts:
    Full adder chain with cin 0 is used to obtain intermediate sum, propagate and cout signals. (In case of first block actual sum bits are obtained)
    From second block onward the blocks also contain a chain of half adders to calculate the final sum bits.
    Finally the intermediate propagate signals are ANDed with the cout of the half adder chain and ORed with the intermediate
    full adder cout to determine the carry bit for the next increment block.
    At last XOR gates are used to ensure proper sign extension.

    ```
                            ┼   ┼                ┼   ┼
                    Cout┌───▼───▼───┐            │   │
        ┌───────────────┤    FAs    │◄─0         │   │
        │               └┬────────┬─┘            │   │
        │    ┌─────┐     ┼ P sigs ┼ Sums         │   │
        │    │ ANDs│◄────┘        │              │   │
        │    └───┬─┘              │              │   │
     ┌──▼─┐  ┌───▼─┐Cout┌─────────▼─┐    Cout┌───▼───▼───┐
     │ OR │◄─┤ AND │◄───┤    HAs    │◄───────┤    FAs    │◄─Cin
     └─┬──┘  └─────┘    └─────┬─────┘        └─────┬─────┘
    ┌──▼───┐                  ┼                    ┼
    │ SIGN │                  │                    │
    │Extend│                  │                    │
    └──┬───┘                  │                    │
       │                      │                    │
       │                      │                    │
       ▼                      ▼                    ▼
      Cout                   Sums                 Sums
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        increment_block_size (int, optional): Size of each composite select adder block size. Defaults to 4.
        prefix (str, optional): Prefix name of signed cia. Defaults to "".
        name (str, optional): Name of signed cia. Defaults to "s_cia".
    """
    def __init__(self, a: Bus, b: Bus, increment_block_size: int = 4, prefix: str = "", name: str = "s_cia", **kwargs):
        super().__init__(a=a, b=b, increment_block_size=increment_block_size, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        self.add_component(XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self))
        self.add_component(XorGate(self.get_previous_component().out, self.out.get_wire(-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self))
        self.out.connect(self.N, self.get_previous_component().out)
