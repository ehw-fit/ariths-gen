from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    ArithmeticCircuit,
    MultiplierCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder
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


class UnsignedCarrySaveMultiplier(MultiplierCircuit):
    """Class representing unsigned carry save array multiplier (also known as Braun multiplier).

    Unsigned carry save array multiplier represents N-bit multiplier composed of
    many AND gates and carry save adders to calculate partial products and
    gradually sum them. As opposed to traditional architecture of an array multiplier,
    the individual half/full adders are interconnected in a carry save manner to provide
    smaller propagation delay.

    It is composed of many logic gates and its downside is a rather big area when compared
    to a regular array multiplier.
    The reason for that is because the csa multiplier requires an additional vector merging
    propagate adder to calculate the final product bits.
    ```
                                        A3B0     A2B0     A1B0     A0B0
                                        │ │      │ │      │ │      │ │
                                       ┌▼─▼┐    ┌▼─▼┐    ┌▼─▼┐    ┌▼─▼┐
                                       │AND│    │AND│    │AND│    │AND│
                                       └┬──┘    └┬──┘    └┬──┘    └─┬─┘
                                  A3B1  │  A2B1  │  A1B1  │  A0B1   │
                                 ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │
                                 │AND│  │ │AND│  │ │AND│  │ │AND│   │
                                 └┬──┘  │ └┬──┘  │ └┬──┘  │ └┬──┘   │
                                  │     │  │     │  │     │  │      │
                                  │    ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │
                               ┌──┘    │    │   │    │   │    │     │
                               │     ┌─┤ HA │ ┌─┤ HA │ ┌─┤ HA │     │
                               │     │ │    │ │ │    │ │ │    │     │
                               │     │ └┬───┘ │ └┬───┘ │ └─┬──┘     │
                        A3B2   │ A2B2│  │ A1B2│  │ A0B2│   │        │
                       ┌▼─▼┐   │┌▼─▼┐│  │┌▼─▼┐│  │┌▼─▼┐│   │        │
                       │AND│   ││AND││  ││AND││  ││AND││   │        │
                       └─┬─┘   │└─┬─┘│  │└─┬─┘│  │└─┬─┘│   │        │
                         │     │  │  │  │  │  │  │  │  │   │        │
                         │    ┌▼──▼┐ │ ┌▼──▼┐ │ ┌▼──▼┐ │   │        │
                      ┌──┘    │    │◄┘ │    │◄┘ │    │◄┘   │        │
                      │     ┌─┤ FA │ ┌─┤ FA │ ┌─┤ FA │     │        │
                      │     │ │    │ │ │    │ │ │    │     │        │
                      │     │ └┬───┘ │ └┬───┘ │ └─┬──┘     │        │
               A3B3   │ A2B3│  │ A1B3│  │ A0B3│   │        │        │
              ┌▼─▼┐   │┌▼─▼┐│  │┌▼─▼┐│  │┌▼─▼┐│   │        │        │
              │AND│   ││AND││  ││AND││  ││AND││   │        │        │
              └─┬─┘   │└─┬─┘│  │└─┬─┘│  │└─┬─┘│   │        │        │
                │     │  │  │  │  │  │  │  │  │   │        │        │
                │    ┌▼──▼┐ │ ┌▼──▼┐ │ ┌▼──▼┐ │   │        │        │
              ┌─┘    │    │◄┘ │    │◄┘ │    │◄┘   │        │        │
              │    ┌─┤ FA │ ┌─┤ FA │ ┌─┤ FA │     │        │        │
              │    │ │    │ │ │    │ │ │    │     │        │        │
      0   0   │    │ └─┬──┘ │ └─┬──┘ │ └─┬──┘     │        │        │
      │   │   │S2  │C2 │S1  │C1 │S0  │C0 │        │        │        │
    ┌─▼───▼───▼────▼───▼────▼───▼────▼─┐ │        │        │        │
    │         Carry-propagate          │ │        │        │        │
    │              adder               │ │        │        │        │
    └┬────────┬────────┬────────┬──────┘ │        │        │        │
     │        │        │        │        │        │        │        │
     ▼        ▼        ▼        ▼        ▼        ▼        ▼        ▼
     P7       P6       P5       P4       P3       P2       P1       P0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned carry save array multiplier. Defaults to "".
        name (str, optional): Name of unsigned carry save array multiplier. Defaults to "u_csamul".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used for final vector merging of sums and carries. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_csamul", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND gates generation for calculation of partial products
                obj_and = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                self.add_component(obj_and)

                # First row contains only HAs
                if b_multiplier_index == 1 and a_multiplicand_index != self.N-1:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index].out

                    obj_adder = HalfAdder(a=obj_and.out, b=previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)
                # Rest are composed of FAs
                elif b_multiplier_index > 1 and a_multiplicand_index != self.N-1:
                    previous_sum_wire = self.get_previous_component((self.N-1)*2-1).get_sum_wire() if a_multiplicand_index != self.N-2 else self.get_previous_component((self.N-1)*2).out
                    previous_carry_wire = self.get_previous_component(self.N*2-1).get_carry_wire()

                    obj_adder = FullAdder(a=obj_and.out, b=previous_sum_wire, c=previous_carry_wire, prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_and.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        self.out.connect(a_multiplicand_index+1, ConstantWireValue0())
                        return

                elif a_multiplicand_index == 0:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

        # Final addition of remaining bits using chosen unsigned multi bit adder
        previous_sums = [self.get_previous_component((self.N-2-wire_id)*2).get_sum_wire() if wire_id < self.N-2 else self.get_previous_component().out if wire_id == self.N-2 else ConstantWireValue0() for wire_id in range(self.N)]
        previous_carries = [self.get_previous_component((self.N-2-wire_id)*2+2).get_carry_wire() if wire_id != self.N-1 else ConstantWireValue0() for wire_id in range(self.N)]

        # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
        adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(self.N)
        adder_a = Bus(prefix=f"a", wires_list=previous_sums)
        adder_b = Bus(prefix=f"b", wires_list=previous_carries)

        final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True, **kwargs)
        self.add_component(final_adder)
        [self.out.connect(o, final_adder.out.get_wire(o-self.N), inserted_wire_desired_index=o-self.N) for o in range(self.N, len(self.out.bus))]


class SignedCarrySaveMultiplier(MultiplierCircuit):
    """Class representing signed carry save array multiplier.

    Signed carry save array multiplier represents N-bit multiplier composed of
    many AND/NAND gates and carry save adders to calculate partial products and
    gradually sum them. As opposed to traditional architecture of an array multiplier,
    the individual half/full adders are interconnected in a carry save manner to provide
    smaller propagation delay.

    It is composed of many logic gates and its downside is a rather big area when compared
    to a regular array multiplier.
    The reason for that is because the csa multiplier requires an additional vector merging
    propagate adder to calculate the final product bits.
    ```
                                        A3B0     A2B0     A1B0     A0B0
                                        │ │      │ │      │ │      │ │
                                       ┌▼─▼─┐   ┌▼─▼┐    ┌▼─▼┐    ┌▼─▼┐
                                       │NAND│   │AND│    │AND│    │AND│
                                       └┬───┘   └┬──┘    └┬──┘    └─┬─┘
                                  A3B1  │  A2B1  │  A1B1  │  A0B1   │
                                 ┌▼─▼─┐ │ ┌▼─▼┐  │ ┌▼─▼┐  │ ┌▼─▼┐   │
                                 │NAND│ │ │AND│  │ │AND│  │ │AND│   │
                               1 └┬───┘ │ └┬──┘  │ └┬──┘  │ └┬──┘   │
                               │  │     │  │     │  │     │  │      │
                              ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐   ┌▼──▼┐     │
                              │    │   │    │   │    │   │    │     │
                            ┌─┤ HA │ ┌─┤ HA │ ┌─┤ HA │ ┌─┤ HA │     │
                            │ │    │ │ │    │ │ │    │ │ │    │     │
                            │ └┬───┘ │ └┬───┘ │ └┬───┘ │ └─┬──┘     │
                       A3B2 │  │ A2B2│  │ A1B2│  │ A0B2│   │        │
                      ┌▼─▼─┐│  │┌▼─▼┐│  │┌▼─▼┐│  │┌▼─▼┐│   │        │
                      │NAND││  ││AND││  ││AND││  ││AND││   │        │
                      └──┬─┘│  │└─┬─┘│  │└─┬─┘│  │└─┬─┘│   │        │
                         │  │  │  │  │  │  │  │  │  │  │   │        │
                     ┌───▼┐ │ ┌▼──▼┐ │ ┌▼──▼┐ │ ┌▼──▼┐ │   │        │
                     │    │◄┘ │    │◄┘ │    │◄┘ │    │◄┘   │        │
                   ┌─┤ HA │  ┌┤ FA │  ┌┤ FA │  ┌┤ FA │     │        │
                   │ │    │  ││    │  ││    │  ││    │     │        │
                   │ └┬───┘  │└┬───┘  │└┬───┘  │└─┬──┘     │        │
               A3B3│  │ A3B2 │ │ A3B2 │ │ A3B2 │  │        │        │
              ┌▼─▼┐│  │┌▼─▼─┐│ │┌▼─▼─┐│ │┌▼─▼─┐│  │        │        │
              │AND││  ││NAND││ ││NAND││ ││NAND││  │        │        │
              └─┬─┘│  │└─┬──┘│ │└─┬──┘│ │└─┬──┘│  │        │        │
                │  │  │  │   │ │  │   │ │  │   │  │        │        │
            ┌───▼┐ │ ┌▼──▼┐  │┌▼──▼┐  │┌▼──▼┐  │  │        │        │
            │    │◄┘ │    │◄─┘│    │◄─┘│    │◄─┘  │        │        │
          ┌─┤ HA │ ┌─┤ FA │ ┌─┤ FA │ ┌─┤ FA │     │        │        │
          │ │    │ │ │    │ │ │    │ │ │    │     │        │        │
      1   │ └─┬──┘ │ └─┬──┘ │ └─┬──┘ │ └─┬──┘     │        │        │
      │   │C3 │S2  │C2 │S1  │C1 │S0  │C0 │        │        │        │
    ┌─▼───▼───▼────▼───▼────▼───▼────▼─┐ │        │        │        │
    │         Carry-propagate          │ │        │        │        │
    │              adder               │ │        │        │        │
    └┬────────┬────────┬────────┬──────┘ │        │        │        │
     │        │        │        │        │        │        │        │
     ▼        ▼        ▼        ▼        ▼        ▼        ▼        ▼
     P7       P6       P5       P4       P3       P2       P1       P0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed carry save array multiplier. Defaults to "".
        name (str, optional): Name of signed carry save array multiplier. Defaults to "s_csamul".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used for final vector merging of sums and carries. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_csamul", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, signed=True, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Gradual generation of partial products
        for b_multiplier_index in range(self.N):
            for a_multiplicand_index in range(self.N):
                # AND and NAND gates generation for calculation of partial products and sign extension
                if (b_multiplier_index == self.N-1 and a_multiplicand_index != self.N-1) or (b_multiplier_index != self.N-1 and a_multiplicand_index == self.N-1):
                    obj_gate = NandGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_nand"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_gate)
                else:
                    obj_gate = AndGate(self.a.get_wire(a_multiplicand_index), self.b.get_wire(b_multiplier_index), prefix=self.prefix+"_and"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_gate)

                # First row contains only half adders
                if b_multiplier_index == 1:
                    previous_product = self.components[a_multiplicand_index + b_multiplier_index].out if a_multiplicand_index != self.N-1 else ConstantWireValue1()

                    obj_adder = HalfAdder(a=obj_gate.out, b=previous_product, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)
                # Rest are composed of FAs and a HA
                elif b_multiplier_index > 1:
                    previous_sum_wire = self.get_previous_component((self.N-1)*2).get_sum_wire() if a_multiplicand_index != self.N-1 else None
                    previous_carry_wire = self.get_previous_component(self.N*2).get_carry_wire()

                    # Last function block of each row is a simple HA
                    if a_multiplicand_index == self.N-1:
                        obj_adder = HalfAdder(a=obj_gate.out, b=previous_carry_wire, prefix=self.prefix+"_ha"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    # Rest are all FAs
                    else:
                        obj_adder = FullAdder(a=obj_gate.out, b=previous_sum_wire, c=previous_carry_wire, prefix=self.prefix+"_fa"+str(a_multiplicand_index)+"_"+str(b_multiplier_index))
                    self.add_component(obj_adder)

                # PRODUCT GENERATION
                if a_multiplicand_index == 0 and b_multiplier_index == 0:
                    self.out.connect(a_multiplicand_index, obj_gate.out)

                    # 1 bit multiplier case
                    if a_multiplicand_index == self.N-1:
                        obj_nor = NorGate(a=ConstantWireValue1(), b=self.get_previous_component().out, prefix=self.prefix+"_nor_zero_extend", parent_component=self)
                        self.add_component(obj_nor)

                        self.out.connect(a_multiplicand_index+1, obj_nor.out)
                        return

                elif a_multiplicand_index == 0:
                    self.out.connect(b_multiplier_index + a_multiplicand_index, obj_adder.get_sum_wire())

        # Final addition of remaining bits using chosen unsigned multi bit adder
        previous_sums = [self.get_previous_component((self.N*2)-3-(wire_id*2)).get_sum_wire() if wire_id != self.N-1 else ConstantWireValue1() for wire_id in range(self.N)]
        previous_carries = [self.get_previous_component((self.N*2)-1-(wire_id*2)).get_carry_wire() for wire_id in range(self.N)]

        # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
        adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(self.N)
        adder_a = Bus(prefix=f"a", wires_list=previous_sums)
        adder_b = Bus(prefix=f"b", wires_list=previous_carries)

        final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True, **kwargs)
        self.add_component(final_adder)
        self.out.connect_bus(connecting_bus=final_adder.out, end_connection_pos=final_adder.out.N-1, offset=(-self.N))
