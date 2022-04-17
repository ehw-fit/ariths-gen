from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    ArithmeticCircuit,
    MultiplierCircuit,
)
from ariths_gen.core.logic_gate_circuits import (
    TwoInputLogicGate
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder,
    FullAdderPG
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
from ariths_gen.multi_bit_circuits.adders import (
    UnsignedCarryLookaheadAdder
)


class UnsignedBrokenCarrySaveMultiplier(MultiplierCircuit):
    """Class representing unsigned broken carry save (Braun) multiplier.

    It represents an approximative version of unsigned carry save multiplier with simpler structure.
    It is created by modifying an ordinary N-bit unsigned carry save multiplier by omitting partial product
    stage cells by the specified horizontal and vertical cut levels.

    The design promises better area and power parameters in exchange for the loss of computation precision.
    The BCSM design allows to save more partial product stage adders than truncated multiplier architectures.
    ```
                                                    VERTICAL CUT=3

                                                     │
                                            A3B0       A2B0       A1B0       A0B0
                                           ┌───┐     │┌───┐      ┌───┐      ┌───┐
                                           │AND│      │AND│      │AND│      │AND│
                                           └───┘     │└───┘      └───┘      └───┘

                                                     │
                                      A3B1       A2B1       A1B1       A0B1
                                     ┌───┐      ┌───┐│      ┌───┐      ┌───┐
                                     │AND│      │AND│       │AND│      │AND│
                                     └───┘      └───┘│      └───┘      └───┘

                                             ┌────┐  │  ┌────┐     ┌────┐
                                             │    │     │    │     │    │
                                             │ HA │  │  │ HA │     │ HA │
                                             │    │     │    │     │    │
                                             └────┘  │  └────┘     └────┘

              ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┼─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ HORIZONTAL CUT=2
                      A3B2       A2B2       A1B2          A0B2
                     ┌▼─▼┐      ┌▼─▼┐      ┌▼─▼┐     │   ┌───┐
                     │AND│      │AND│      │AND│         │AND│
                     └┬──┘      └┬──┘      └┬──┘     │   └───┘
                      │          │          │
              A3B3    │  A2B3    │  A1B3    │  A0B3  │  ┌────┐
             ┌▼─▼┐    │ ┌▼─▼┐    │ ┌▼─▼┐    │ ┌▼─▼┐     │    │
             │AND│    │ │AND│    │ │AND│    │ │AND│  │  │ HA │
             └┬──┘    │ └┬──┘    │ └┬──┘    │ └┬──┘     │    │
              │       │  │       │  │       │  │     │  └────┘
              │       │  │       │  │       │  │
              │       │  │       │  │       │  │     │
              │      ┌▼──▼┐     ┌▼──▼┐     ┌▼──▼┐
              │      │    │     │    │     │    │    │
              │    ┌─┤ HA │   ┌─┤ HA │   ┌─┤ HA │
              │    │ │    │   │ │    │   │ │    │    │
       0  0   │    │ └─┬──┘   │ └─┬──┘   │ └──┬─┘
       │  │   │S2  │C2 │S1    │C1 │S0    │C0  │      │
    ┌──▼──▼───▼────▼───▼──────▼───▼──────▼──┐ │
    │            Carry-propagate            │ │      │
    │                adder                  │ │
    └─┬───────┬──────────┬──────────┬───────┘ │      │
      │       │          │          │         │
      │       │          │          │         │      │
      │       │          │          │         │
      │       │          │          │         │      │
      ▼       ▼          ▼          ▼         ▼            ▼         ▼        ▼
      P7      P6         P5         P4        P3     │     P2=0      P1=0     P0=0
    ```
    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        horizontal_cut (int, optional): Specifies horizontal cut used in broken carry save multiplier circuit creation. Defaults to 0.
        vertical_cut (int, optional): Specifies vertical cut used in broken carry save multiplier circuit creation. Defaults to 0.
        prefix (str, optional): Prefix name of unsigned broken carry save multiplier. Defaults to "".
        name (str, optional): Name of unsigned broken carry save multiplier. Defaults to "u_bamcsa".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used for final vector merging of sums and carries. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, horizontal_cut: int = 0, vertical_cut: int = 0, prefix: str = "", name: str = "u_bamcsa", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        # NOTE: If horizontal/vertical cut is specified as 0 the final circuit is a simple carry save multiplier
        self.horizontal_cut = horizontal_cut
        self.vertical_cut = vertical_cut

        self.N = max(a.N, b.N)
        # Horizontal cut level should be: 0 <= horizontal_cut < N
        # Vertical cut level should be: horizontal_cut <= vertical_cut < 2*N
        assert horizontal_cut < self.N
        assert vertical_cut < 2*self.N

        # Vertical cut should be greater or equal to horizontal cut
        assert vertical_cut >= horizontal_cut

        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        self.ommited_rows = self.horizontal_cut
        # Gradual generation of partial products
        for b_multiplier_index in range(self.horizontal_cut, self.N):
            # Number of elements that should be ommited in the current level based on vertical cut
            pp_row_elems_to_skip = self.vertical_cut - b_multiplier_index if self.vertical_cut - b_multiplier_index > 0 else 0
            # Number of pp pairs present in the current row
            pp_row_elems = self.N-pp_row_elems_to_skip if self.N-pp_row_elems_to_skip > 0 else 0
            self.ommited_rows += 1 if pp_row_elems == 0 else 0

            row_pp_ord = 0
            for a_multiplicand_index in range((self.N-pp_row_elems), self.N):
                row_pp_ord += 1
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                if a_multiplicand_index == 0:
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)

                # HAs generation for first row of adders (the second row in total, first contains just pp generation)
                if b_multiplier_index == self.horizontal_cut+1 and a_multiplicand_index != self.N-1:
                    previous_product = self.get_previous_component(self.N-(pp_row_elems_to_skip+1)+row_pp_ord).out
                    obj_adder = HalfAdder(a=obj_and.out, b=previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)

                    if (a_multiplicand_index == 0):
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                # FAs generation for the remaining rows
                elif b_multiplier_index > self.horizontal_cut+1 and a_multiplicand_index != self.N-1:
                    previous_sum = self.get_previous_component((self.N-(pp_row_elems_to_skip+1))*2-1).get_sum_wire() if a_multiplicand_index != self.N-2 else self.get_previous_component((self.N-(pp_row_elems_to_skip+1))*2).out

                    if a_multiplicand_index == self.N-pp_row_elems and b_multiplier_index <= vertical_cut:
                        obj_adder = HalfAdder(a=obj_and.out, b=previous_sum, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))

                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())
                    else:
                        previous_carry = self.get_previous_component((row_pp_ord*2-1)+((self.N-(a_multiplicand_index+1))*2)).get_carry_wire()
                        obj_adder = FullAdder(a=obj_and.out, b=previous_sum, c=previous_carry, prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))

                    self.add_component(obj_adder)
                    if (a_multiplicand_index == 0):
                        self.out.connect(b_multiplier_index, obj_adder.get_sum_wire())

                # PRODUCT GENERATION
                # 1 bit multiplier case
                if (a_multiplicand_index == 0 and b_multiplier_index == self.horizontal_cut) and (self.horizontal_cut + self.ommited_rows == self.N-1):
                    self.out.connect(a_multiplicand_index + b_multiplier_index, obj_and.out)

                    if a_multiplicand_index == self.N-1 and b_multiplier_index == self.N-1:
                        self.out.connect(a_multiplicand_index+b_multiplier_index+1, ConstantWireValue0())

                # If architecture is cut to just a row of AND gates
                elif self.ommited_rows == self.N-1:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_and.out)

                    if a_multiplicand_index == self.N-1:
                        self.out.connect(self.out.N-1, ConstantWireValue0())

        # Connecting the output bits generated from ommited cells to ground
        if self.vertical_cut == 2*self.N-1:
            [self.out.connect(out_id, ConstantWireValue0()) for out_id in range(self.out.N)]
        else:
            for grounded_out_index in range(0, max(self.horizontal_cut, self.vertical_cut)):
                self.out.connect(grounded_out_index, ConstantWireValue0())

        # Final addition of remaining bits using chosen unsigned multi bit adder
        final_cpa_N = self.out.N - max(self.N, self.vertical_cut+1)
        if self.ommited_rows != self.N-1:
            previous_sums = []
            previous_carries = []
            for wire_id in range(final_cpa_N):
                if (wire_id == final_cpa_N-1):
                    previous_sums.append(ConstantWireValue0())
                else:
                    prev_sum_obj = self.get_previous_component((final_cpa_N-2-wire_id)*2) if wire_id < final_cpa_N-2 else self.get_previous_component()
                    if isinstance(prev_sum_obj, TwoInputLogicGate):
                        previous_sums.append(prev_sum_obj.out)
                    else:
                        previous_sums.append(prev_sum_obj.get_sum_wire())
                if (wire_id == final_cpa_N-1 or (self.vertical_cut+1 == self.out.N-final_cpa_N and wire_id == 0)):
                    previous_carries.append(ConstantWireValue0())
                else:
                    prev_carry_obj = self.get_previous_component((final_cpa_N-2-wire_id)*2+2)
                    if isinstance(prev_carry_obj, TwoInputLogicGate):
                        previous_carries.append(prev_carry_obj.out)
                    else:
                        previous_carries.append(prev_carry_obj.get_carry_wire())

            # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
            adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(final_cpa_N)
            adder_a = Bus(prefix=f"a", wires_list=previous_sums)
            adder_b = Bus(prefix=f"b", wires_list=previous_carries)

            final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
            self.add_component(final_adder)
            [self.out.connect(o, final_adder.out.get_wire(o-max(self.N, self.vertical_cut)), inserted_wire_desired_index=o-max(self.N, self.vertical_cut)) for o in range(max(self.N, self.vertical_cut), self.out.N)]
