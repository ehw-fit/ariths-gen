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
import math


class UnsignedConditionalSumAdder(ArithmeticCircuit):
    """Class representing unsigned conditional sum adder.

    Conditional sum adder performs carry-select addition starting with
    groups of 1 bit and recursively doubling to N/2 bits.

    The individual input bit pairs are first added in a carry-select fashion (cin of 0 and 1) with block size of 1.
    Then in the subsequent two rows multiplexer pairs are used to properly select the sum and carry-out
    of the upper bit of each block of size 2 (higher bit of the previous 2-bits from the previous level).
    The next two rows follow the principle for blocks of size 4 and so on.

    The conditional sum adder shares the same structural characteristics as Sklansky tree adder.
    Because of using many multiplexers, the number of gates is significant when compared to other architectures.

    Another way on how to look at (and determine the number of) the multiplexers in the subsequent stages
    can be done by converting the input bit index (counting from 0) into its binary form. Each bit position with value 1
    signifies the stage position that contains multiplexers
    (which ones and how many of them depends on other input bit index characteristics deducible from the code below).

    ```
                B3A3            B2A2            B1A1            B0A0
                 ││              ││              ││              ││
              C4┌▼▼┐          C3┌▼▼┐          C2┌▼▼┐          C1┌▼▼┐
               ┌┤FA│◄─0      ┌──┤FA│◄─0        ┌┤FA│◄─0      ┌──┤FA│◄─Cin
               │└┬─┘         │  └┬─┘           │└┬─┘         │  └┬─┘
               │ │S3         │   │S2           │ │S1         │   │
               │ └───────┐   │   └───────┐     │ └───────┐   │   │
               └────────┐│   │           │     └────────┐│   │   │
                B3A3    ││   │  B2A2     │      B1A1    ││   │   │
                 ││     ││   │   ││      │       ││     ││   │   │
              C4┌▼▼┐    ││   │C3┌▼▼┐     │    C2┌▼▼┐    ││   │   │
               ┌┤FA│◄─1 ││   │┌─┤FA│◄─1  │     ┌┤FA│◄─1 ││   │   │
               │└┬─┘    ││   ││ └┬─┘     │     │└┬─┘    ││   │   │
               │ │S3    ││   ││  │S2     │     │ │S1    ││   │   │
              ┌┼─┴┐ ┌───┤│   ││  │       │     │ └┐ ┌───┘│   │   │
              │├─┐│ │┌──┼┤   ││  │   ┌───┘     └─┐│ │┌───┘   │   │
              ││ ││ ││  ││   ││  │   │           ││ ││       │   │
              ││┌▼▼─▼▼┐ ││   ││  │   │          ┌▼▼─▼▼┐      │   │
              │││ 2:1 │ ││SEL││  │   │          │ 2:1 │   SEL│   │
    Stage 0:  │││MUXes│◄┼┼───┘│  │   │          │MUXes│◄─────┘   │
              │││ CS  │ ││    │  │   │          │ CS  │          │
              ││└┬───┬┘ ││    │  │   │          └┬───┬┘          │
              ││ │C4 │S3││    │  │   │           │C2 │           │
              ││ └───┼──┼┼────┼┐ │   │           │   │           │
              ││     └──┼┼────┼┼┐│   │           │   │           │
              └┼──┐ ┌───┘│    ││││   │           │   │           │
               └─┐│ │┌───┘    ││││   │           │   │           │
                 ││ ││        ││││   │           │   │           │
                ┌▼▼─▼▼┐       ││││   │           │   │           │
                │ 2:1 │   SEL ││││   │           │   │           │
    Stage 0:    │MUXes│◄──────┘│││   │           │   │           │
                │ CS  │        │││   │           │   │           │
                └┬───┬┘        │││   │           │   │           │
                 │C4 │S3       │││   │           │   │           │
                 │┌──┘         │││   │           │   │           │
                 ││ ┌──────────┘││   │           │   │           │
                 ││ │┌──────────┘│   │           │   │           │
                 ││ ││       ┌───┼───┼───────────┤   │           │
                ┌▼▼─▼▼┐      │  ┌▼───▼┐          │   │           │
                │ 2:1 │   SEL│  │ 2:1 │   SEL    │   │           │
    Stage 1:    │MUXes│◄─────┘  │MUXes│◄─────────┘   │           │
                │ CS  │         │ S   │              │           │
                └┬───┬┘         └────┬┘              │           │
                 │C4 │               │               │           │
                 │   │               │               │           │
                 ▼   ▼               ▼               ▼           ▼
                Cout S3              S2              S1          S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned cosa. Defaults to "".
        name (str, optional): Name of unsigned cosa. Defaults to "u_cosa".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_cosa", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)
        cin = ConstantWireValue0()

        # Lists of lists containing all sum/carry wires
        self.sum_sig = [([], []) for i in range(self.N)]
        self.carry_sig = [([], []) for i in range(self.N+1)]  # +1 because of cin
        self.carry_sig[0][0].append(cin)

        for i_wire in range(self.N):
            if i_wire == 0:
                self.add_component(FullAdder(a=self.a.get_wire(i_wire), b=self.b.get_wire(i_wire), c=cin, prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder))))
                self.sum_sig[i_wire][0].append(self.get_previous_component().get_sum_wire())
                self.carry_sig[i_wire+1][0].append(self.get_previous_component().get_carry_wire())

                self.out.connect(i_wire, self.get_previous_component().get_sum_wire())
            else:
                # Create FA with cin set to ConstantValue0 (and ConstantValue1 respectively) and save the generated sum and carry wires to the appropriate positions within the sum_sig and carry_sig lists to allow easier access when doing interconnections between muxes
                self.add_component(FullAdder(a=self.a.get_wire(i_wire), b=self.b.get_wire(i_wire), c=ConstantWireValue0(), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder))))
                self.sum_sig[i_wire][0].append(self.get_previous_component().get_sum_wire())
                self.carry_sig[i_wire+1][0].append(self.get_previous_component().get_carry_wire())
                self.add_component(FullAdder(a=self.a.get_wire(i_wire), b=self.b.get_wire(i_wire), c=ConstantWireValue1(), prefix=self.prefix+"_fa"+str(self.get_instance_num(cls=FullAdder))))
                self.sum_sig[i_wire][1].append(self.get_previous_component().get_sum_wire())
                self.carry_sig[i_wire+1][1].append(self.get_previous_component().get_carry_wire())

                # Determine the number of 2:1 muxes stages to choose which of the fa sum and carry bit to propagate further
                binary_form = bin(i_wire)[2:][::-1]
                index_stages = len(binary_form)
                prev_stage_int_value = 0
                # Create approprite structure of muxes and interconnect wires according to the bit index and stage
                for stage, value in enumerate(binary_form):
                    if value == '1':
                        # Both sum and carry muxes in stages
                        if i_wire % 2 != 0 or i_wire == self.N-1:  # Odd-numbered bit indexes
                            if stage == index_stages-1 and (math.log(i_wire+1, 2).is_integer() or i_wire == self.N-1):  # Stage with only one pair of sum and carry multiplexers
                                # Sum
                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.sum_sig[i_wire][0].append(self.get_previous_component().out.get_wire())
                                # Carry
                                self.add_component(TwoOneMultiplexer(a=self.carry_sig[i_wire+1][0][-1], b=self.carry_sig[i_wire+1][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.carry_sig[i_wire+1][0].append(self.get_previous_component().out.get_wire())

                                self.out.connect(i_wire, self.sum_sig[i_wire][0][-1])
                            elif stage == index_stages-1:  # Stage with only one sum multiplexer
                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.sum_sig[i_wire][0].append(self.get_previous_component().out.get_wire())

                                self.out.connect(i_wire, self.sum_sig[i_wire][0][-1])
                            else:  # Stage with two pairs of sum and carry multiplexers
                                # Sum
                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][1][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))

                                self.sum_sig[i_wire][0].append(self.get_previous_component(2).out.get_wire())
                                self.sum_sig[i_wire][1].append(self.get_previous_component().out.get_wire())
                                # Carry
                                self.add_component(TwoOneMultiplexer(a=self.carry_sig[i_wire+1][0][-1], b=self.carry_sig[i_wire+1][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.add_component(TwoOneMultiplexer(a=self.carry_sig[i_wire+1][0][-1], b=self.carry_sig[i_wire+1][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][1][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))

                                self.carry_sig[i_wire+1][0].append(self.get_previous_component(2).out.get_wire())
                                self.carry_sig[i_wire+1][1].append(self.get_previous_component().out.get_wire())

                        # Only sum muxes in all stages
                        else:  # Even-numbered bit indexes
                            if stage == index_stages-1:  # Stage with only one sum multiplexer
                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][-1], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.sum_sig[i_wire][0].append(self.get_previous_component().out.get_wire())
                                self.out.connect(i_wire, self.sum_sig[i_wire][0][-1])
                            else:  # Stage with two sum multiplexers
                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][0][stage], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.sum_sig[i_wire][0].append(self.get_previous_component().out.get_wire())

                                self.add_component(TwoOneMultiplexer(a=self.sum_sig[i_wire][0][-1], b=self.sum_sig[i_wire][1][-1], c=self.carry_sig[i_wire-prev_stage_int_value][1][stage], prefix=self.prefix+"_mux2to1_"+str(self.get_instance_num(cls=TwoOneMultiplexer))))
                                self.sum_sig[i_wire][1].append(self.get_previous_component().out.get_wire())

                        prev_stage_int_value += 2**stage
            if i_wire == self.N-1:
                self.out.connect(self.N, self.carry_sig[i_wire+1][0][-1])


class SignedConditionalSumAdder(UnsignedConditionalSumAdder, ArithmeticCircuit):
    """Class representing signed conditional sum adder.

    Conditional sum adder performs carry-select addition starting with
    groups of 1 bit and recursively doubling to N/2 bits.

    The individual input bit pairs are first added in a carry-select fashion (cin of 0 and 1) with block size of 1.
    Then in the subsequent two rows multiplexer pairs are used to properly select the sum and carry-out
    of the upper bit of each block of size 2 (higher bit of the previous 2-bits from the previous level).
    The next two rows follow the principle for blocks of size 4 and so on.
    At last XOR gates are used to ensure proper sign extension.

    The conditional sum adder shares the same structural characteristics as Sklansky tree adder.
    Because of using many multiplexers, the number of gates is significant when compared to other architectures.

    Another way on how to look at (and determine the number of) the multiplexers in the subsequent stages
    can be done by converting the input bit index (counting from 0) into its binary form. Each bit position with value 1
    signifies the stage position that contains multiplexers
    (which ones and how many of them depends on other input bit index characteristics deducible from the code below).

        ```
                B3A3            B2A2            B1A1            B0A0
                 ││              ││              ││              ││
              C4┌▼▼┐          C3┌▼▼┐          C2┌▼▼┐          C1┌▼▼┐
               ┌┤FA│◄─0      ┌──┤FA│◄─0        ┌┤FA│◄─0      ┌──┤FA│◄─Cin
               │└┬─┘         │  └┬─┘           │└┬─┘         │  └┬─┘
               │ │S3         │   │S2           │ │S1         │   │
               │ └───────┐   │   └───────┐     │ └───────┐   │   │
               └────────┐│   │           │     └────────┐│   │   │
                B3A3    ││   │  B2A2     │      B1A1    ││   │   │
                 ││     ││   │   ││      │       ││     ││   │   │
              C4┌▼▼┐    ││   │C3┌▼▼┐     │    C2┌▼▼┐    ││   │   │
               ┌┤FA│◄─1 ││   │┌─┤FA│◄─1  │     ┌┤FA│◄─1 ││   │   │
               │└┬─┘    ││   ││ └┬─┘     │     │└┬─┘    ││   │   │
               │ │S3    ││   ││  │S2     │     │ │S1    ││   │   │
              ┌┼─┴┐ ┌───┤│   ││  │       │     │ └┐ ┌───┘│   │   │
              │├─┐│ │┌──┼┤   ││  │   ┌───┘     └─┐│ │┌───┘   │   │
              ││ ││ ││  ││   ││  │   │           ││ ││       │   │
              ││┌▼▼─▼▼┐ ││   ││  │   │          ┌▼▼─▼▼┐      │   │
              │││ 2:1 │ ││SEL││  │   │          │ 2:1 │   SEL│   │
    Stage 0:  │││MUXes│◄┼┼───┘│  │   │          │MUXes│◄─────┘   │
              │││ CS  │ ││    │  │   │          │ CS  │          │
              ││└┬───┬┘ ││    │  │   │          └┬───┬┘          │
              ││ │C4 │S3││    │  │   │           │C2 │           │
              ││ └───┼──┼┼────┼┐ │   │           │   │           │
              ││     └──┼┼────┼┼┐│   │           │   │           │
              └┼──┐ ┌───┘│    ││││   │           │   │           │
               └─┐│ │┌───┘    ││││   │           │   │           │
                 ││ ││        ││││   │           │   │           │
                ┌▼▼─▼▼┐       ││││   │           │   │           │
                │ 2:1 │   SEL ││││   │           │   │           │
    Stage 0:    │MUXes│◄──────┘│││   │           │   │           │
                │ CS  │        │││   │           │   │           │
                └┬───┬┘        │││   │           │   │           │
                 │C4 │S3       │││   │           │   │           │
                 │┌──┘         │││   │           │   │           │
                 ││ ┌──────────┘││   │           │   │           │
                 ││ │┌──────────┘│   │           │   │           │
                 ││ ││       ┌───┼───┼───────────┤   │           │
                ┌▼▼─▼▼┐      │  ┌▼───▼┐          │   │           │
                │ 2:1 │   SEL│  │ 2:1 │   SEL    │   │           │
    Stage 1:    │MUXes│◄─────┘  │MUXes│◄─────────┘   │           │
                │ CS  │         │ S   │              │           │
                └┬───┬┘         └────┬┘              │           │
                 │C4 │               │               │           │
             ┌───▼──┐│               │               │           │
             │ SIGN ││               │               │           │
             │Extend││               │               │           │
             └───┬──┘│               │               │           │
                 │   │               │               │           │
                 ▼   ▼               ▼               ▼           ▼
                Cout S3              S2              S1          S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed cosa. Defaults to "".
        name (str, optional): Name of signed cosa. Defaults to "s_cosa".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_cosa", **kwargs):
        super().__init__(a=a, b=b, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        self.add_component(XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self))
        self.add_component(XorGate(self.get_previous_component().out, self.out.get_wire(-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate, count_disabled_gates=False)), parent_component=self))
        self.out.connect(self.N, self.get_previous_component().out)
