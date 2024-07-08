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
    AndGate,
)
from ariths_gen.multi_bit_circuits.adders import (
    UnsignedCarryLookaheadAdder
)


class UnsignedTruncatedCarrySaveMultiplier(MultiplierCircuit):
    """Class representing unsigned truncated carry save (Braun) multiplier.

    It represents an approximative version of unsigned carry save multiplier with simpler structure.
    It is created by modifying an ordinary N-bit unsigned carry save multiplier by ignoring
    (truncating) some of the partial products.

    The design promises better area and power parameters in exchange for the loss of computation precision.
    ```
                                                                   CUT=1
                                        A3B0       A2B0      A1B0    │    A0B0
                                       ┌───┐      ┌───┐      ┌───┐      ┌───┐
                                       │AND│      │AND│      │AND│   │  │AND│
                                       └───┘      └───┘      └───┘      └───┘
               ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┬─ ─ ┴ ─ ─ ─ ─ ─ ─ CUT=1
                                     A3B1       A2B1       A1B1       A0B1
                                    ┌▼─▼┐      ┌▼─▼┐      ┌▼─▼┐ │    ┌───┐
                                    │AND│      │AND│      │AND│      │AND│
                                    └┬──┘      └┬──┘      └┬──┘ │    └───┘
                                     │          │          │      ┌────┐
                                 ┌───┘          │          │    │ │    │
                                 │            ┌─┘          │      │ HA │
                                 │            │            │    │ │    │
                                 │            │            │      └────┘
                                 │            │       ┌ ─ ─│─ ─ ┘
                       A3B2      │  A2B2      │  A1B2      │ A0B2
                      ┌▼─▼┐      │ ┌▼─▼┐      │ ┌───┐ │    │┌───┐
                      │AND│      │ │AND│      │ │AND│      ││AND│
                      └┬──┘      │ └┬──┘      │ └┬──┘ │    │└───┘
                       │        ┌▼──▼┐       ┌▼──▼┐     ┌──┼─┐
                       │        │    │       │    │   │ │  │ │
                       │      ┌─┤ HA │     ┌─┤ HA │     │FA│ │
                       │      │ │    │     │ │    │   │ │  │ │
                       │      │ └───┬┘     │ └───┬┘     └──┼─┘
                       │      │     │      │     │    │    │
                       │      │     │      │    ┌│─ ─ ┘    │
              A3B3     │  A2B3│     │  A1B3│     │ A0B3    │
             ┌▼─▼┐     │ ┌▼─▼┐│     │ ┌▼─▼┐│    ││┌───┐    │
             │AND│     │ │AND││     │ │AND││     ││AND│    │
             └┬──┘     │ └┬──┘│     │ └┬──┘│ ┌─ ┘│└───┘    │
              │       ┌▼──▼┐  │    ┌▼──▼┐  │ │ ┌─┼──┐      │
              │       │    │  │    │    │  │   │ │  │      │
              │    ┌──┤ FA │◄─┘  ┌─┤ FA │◄─┘ │ │ │FA│      │
              │    │  │    │     │ │    │      │ │  │      │
              │    │  └──┬─┘     │ └──┬─┘    │ └─┼──┘      │
              │    │     │       │    │      │   │         │
              │    │     │       │    │          │         │
              │    │     │       │    │          │         │
      0   0   │    │     │       │    │      │   │         │
      │   │   │S1  │C1   │S0     │C0  │          │         │
    ┌─▼───▼───▼────▼─────▼───────▼─┐  │      │   │         │
    │         Carry-propagate      │  │          │         │
    │              adder           │  │      │   │         │
    └─────┬────────┬─────────┬─────┘  │          │         │
          ▼        ▼         ▼        ▼      │   ▼         ▼         ▼      ▼
          P7       P6        P5       P4         P3        P2       P1=0   P0=0
    ```
    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        truncation_cut (int, optional): Specifies truncation cut level used in the truncated carry save multiplier circuit creation. Note: If equal to 0, the final circuit behaves as an ordinary carry save multiplier. Defaults to 0.
        prefix (str, optional): Prefix name of unsigned truncated carry save multiplier. Defaults to "".
        name (str, optional): Name of unsigned truncated carry save multiplier. Defaults to "u_tm".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used for final vector merging of sums and carries. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, truncation_cut: int = 0, prefix: str = "", name: str = "u_tmcsa", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        # NOTE: If truncation_cut is specified as 0 the final circuit is a simple carry save multiplier
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
            row_pp_ord = 0
            for a_multiplicand_index in range(self.truncation_cut, self.N):
                row_pp_ord += 1
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if a_multiplicand_index == self.truncation_cut:
                    self.out.connect(b_multiplier_index+self.truncation_cut, obj_and.out)

                # HAs generation for first row of adders (the second row in total, first contains just pp generation)
                if b_multiplier_index == self.truncation_cut+1 and a_multiplicand_index != self.N-1:
                    previous_product = self.get_previous_component((self.N-a_multiplicand_index-1)+(row_pp_ord*2-1)).out

                    obj_adder = HalfAdder(a=obj_and.out, b=previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)

                    if (a_multiplicand_index == self.truncation_cut):
                        self.out.connect(b_multiplier_index+self.truncation_cut, obj_adder.get_sum_wire())

                # FAs generation for the remaining rows
                elif b_multiplier_index > self.truncation_cut+1 and a_multiplicand_index != self.N-1:
                    previous_sum = self.get_previous_component((self.N-(truncation_cut+1))*2-1).get_sum_wire() if a_multiplicand_index != self.N-2 else self.get_previous_component((self.N-(truncation_cut+1))*2).out
                    previous_carry = self.get_previous_component((self.N-truncation_cut)*2-1).get_carry_wire()

                    obj_adder = FullAdder(a=obj_and.out, b=previous_sum, c=previous_carry, prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)

                    if (a_multiplicand_index == self.truncation_cut):
                        self.out.connect(b_multiplier_index+self.truncation_cut, obj_adder.get_sum_wire())

                # PRODUCT GENERATION
                # 1 bit multiplier case
                if (a_multiplicand_index == self.truncation_cut and b_multiplier_index == self.truncation_cut) or (self.truncation_cut == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        self.out.connect(a_multiplicand_index+b_multiplier_index+1, ConstantWireValue0())

        # Connecting the output bits generated from ommited cells to ground
        for grounded_out_index in range(0, self.truncation_cut*2):
            self.out.connect(grounded_out_index, ConstantWireValue0())

        # Final addition of remaining bits using chosen unsigned multi bit adder
        if self.truncation_cut != self.N-1:
            final_cpa_N = self.N - self.truncation_cut

            previous_sums = [self.get_previous_component((final_cpa_N-2-wire_id)*2).get_sum_wire() if wire_id < final_cpa_N-2 else self.get_previous_component().out if wire_id == final_cpa_N-2 else ConstantWireValue0() for wire_id in range(final_cpa_N)]
            previous_carries = [self.get_previous_component((final_cpa_N-2-wire_id)*2+2).get_carry_wire() if wire_id != final_cpa_N-1 else ConstantWireValue0() for wire_id in range(final_cpa_N)]

            # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
            adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(final_cpa_N)
            adder_a = Bus(prefix=f"a", wires_list=previous_sums)
            adder_b = Bus(prefix=f"b", wires_list=previous_carries)

            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
            self.add_component(final_adder)
            [self.out.connect(o, final_adder.out.get_wire(o-(self.N+self.truncation_cut)), inserted_wire_desired_index=o-(self.N+self.truncation_cut)) for o in range(self.N+self.truncation_cut, self.out.N)]
