from ariths_gen.wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    MultiplierCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate
)


class UnsignedTruncatedArrayMultiplier(MultiplierCircuit):
    """Class representing unsigned truncated array multiplier.

    It represents an approximative version of unsigned array multiplier with simpler structure.
    It is created by modifying an ordinary N-bit unsigned array multiplier by ignoring
    (truncating) some of the partial products.

    The design promises better area and power parameters in exchange for the loss of computation precision.
    ```
                                                           CUT=2
                                           A3B0    A2B0      │   A1B0    A0B0
                                          ┌───┐   ┌───┐         ┌───┐   ┌───┐
                                          │AND│   │AND│      │  │AND│   │AND│
                                          └───┘   └───┘         └───┘   └───┘
                                                     ┌ ─ ─ ─ ┘
                                     A3B1       A2B1       A1B1       A0B1
                                    ┌───┐      ┌───┐ │    ┌───┐      ┌───┐
                                    │AND│      │AND│      │AND│      │AND│
                                    └───┘      └───┘ │    └───┘      └───┘
                                 ┌────┐     ┌────┐     ┌────┐     ┌────┐
                                 │    │     │    │   │ │    │     │    │
                                 │ HA │     │ FA │     │ FA │     │ HA │
                                 │    │     │    │   │ │    │     │    │
                                 └────┘     └────┘     └────┘     └────┘
              ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┬ ─ ─ ─ ─ ┴─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ CUT=2
                       A3B2         A2B2         A1B2       A0B2
                      ┌▼─▼┐        ┌▼─▼┐   │    ┌───┐      ┌───┐
                      │AND│        │AND│        │AND│      │AND│
                      └┬──┘        └┬──┘   │    └───┘      └───┘
                       │            │        ┌────┐     ┌────┐
                       │            │      │ │    │     │    │
                       │        ┌ ─ ┼─ ─ ─ ┘ │ FA │     │ HA │
                       │            │        │    │     │    │
                       │        │   │        └────┘     └────┘
               A3B3    │  A2B3      │  A1B3      A0B3
              ┌▼─▼┐    │ ┌▼─▼┐  │   │ ┌───┐     ┌───┐
              │AND│    │ │AND│      │ │AND│     │AND│
              └┬──┘    │ └┬──┘  │   │ └───┘     └───┘
           ┌───▼┐     ┌▼──▼┐       ┌┼───┐    ┌────┐
           │    │     │    │    │  ││   │    │    │
    ┌──────┤ HA │◄────┤ HA │       ││FA │    │ HA │
    │      │    │     │    │    │  ││   │    │    │
    │      └──┬─┘     └──┬─┘       └┼───┘    └────┘
    │         │          │      │   │
    ▼         ▼          ▼          ▼           ▼          ▼          ▼          ▼
    P7        P6         P5     │   P4          P3=0       P2=0       P1=0       P0=0
    ```
    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        truncation_cut (int, optional): Specifies truncation cut level used in the truncated array multiplier circuit creation. Note: If equal to 0, the final circuit behaves as an ordinary array multiplier. Defaults to 0.
        prefix (str, optional): Prefix name of unsigned truncated array multiplier. Defaults to "".
        name (str, optional): Name of unsigned truncated array multiplier. Defaults to "u_tm".
    """
    def __init__(self, a: Bus, b: Bus, truncation_cut: int = 0, prefix: str = "", name: str = "u_tm", **kwargs):
        # NOTE: If truncation_cut is specified as 0 the final circuit is a simple array multiplier
        self.truncation_cut = truncation_cut

        self.N = max(a.N, b.N)
        # Cut level should be: 0 <= truncation_cut < N
        assert truncation_cut < self.N

        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Gradual generation of partial products
        for b_multiplier_index in range(self.truncation_cut, self.N):
            for a_multiplicand_index in range(self.truncation_cut, self.N):
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if b_multiplier_index != self.truncation_cut:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index - 2*self.truncation_cut].out if b_multiplier_index == self.truncation_cut + 1 else self.get_previous_partial_product(a_index=a_multiplicand_index, b_index=b_multiplier_index, mult_type="tm")

                    # HA generation for first 1-bit adder in each row starting from the second one
                    if a_multiplicand_index == self.truncation_cut:
                        obj_adder = HalfAdder(self.get_previous_component().out, previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)
                        # Product generation
                        self.out.connect(b_multiplier_index + self.truncation_cut, obj_adder.get_sum_wire())

                    # HA generation, last 1-bit adder in second row
                    elif a_multiplicand_index == self.N-1 and b_multiplier_index == self.truncation_cut+1:
                        obj_adder = HalfAdder(self.get_previous_component().out, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                    # FA generation
                    else:
                        obj_adder = FullAdder(self.get_previous_component().out, previous_product, self.get_previous_component(number=2).get_carry_wire(), prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                        self.add_component(obj_adder)

                # PRODUCT GENERATION
                if (a_multiplicand_index == self.truncation_cut and b_multiplier_index == self.truncation_cut) or (self.truncation_cut == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        self.out.connect(a_multiplicand_index+b_multiplier_index+1, ConstantWireValue0())

                elif b_multiplier_index == self.N-1 and self.truncation_cut != self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, obj_adder.get_carry_wire())

        # Connecting the output bits generated from ommited cells to ground
        for grounded_out_index in range(0, self.truncation_cut*2):
            self.out.connect(grounded_out_index, ConstantWireValue0())
