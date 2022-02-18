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
    CarrySaveAdderComponent,
    UnsignedCarryLookaheadAdder
)


class UnsignedWallaceCSAMultiplier(MultiplierCircuit):
    """Class representing unsigned wallace multiplier composed of carry save adder components.

    Unsigned wallace multiplier represents fast N-bit multiplier which utilizes
    the functionality of wallace tree reduction algorithm proposed by Chris Wallace.

    First partial products are calculated for each bit pair that form the partial product multiplication rows.
    This implementation uses carry save adder components to efficiently implement reduction of partial products utilizing the parallelism of the carry save adders.
    At last the reduced pairs are inserted into chosen multi bit unsigned adder to execute their summation and obtain the final output bits.

    Wallace tree algorithm is described more in detail here:
    https://en.wikipedia.org/wiki/Wallace_tree

    It presents a faster version of multiplier opposed to the conventional architectures that are composed of interconnected half/full adders.
    ```
           PP7 PP6 PP5 PP4 PP3 PP2 PP1 PP0
            │   │    │  │  │     │  │  │
            │   │   ┌▼──▼──▼┐   ┌▼──▼──▼┐
            │   │   │  CSA  │   │  CSA  │
            │   │   └─┬───┬─┘   └─┬───┬─┘
            │   │     │c1 │s1     │c0 │s0
            └┐  │  ┌──┘   └────┐  │  ┌┘
            ┌▼──▼──▼┐         ┌▼──▼──▼┐
            │  CSA  │         │  CSA  │
            └─┬───┬─┘         └─┬───┬─┘
              │c4 │s4   ┌───────┘c3 │s3
              │   └──┐  │  ┌────────┘
              │     ┌▼──▼──▼┐
              │     │  CSA  │
              │     └─┬───┬─┘
              │  ┌────┘c5 │s5
              │  │  ┌─────┘
             ┌▼──▼──▼┐
             │  CSA  │
             └─┬───┬─┘
               │c6 │s6
             ┌─▼───▼─┐
             │  CPA  │
             └───┬───┘
                 o
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned csa wallace multiplier. Defaults to "".
        name (str, optional): Name of unsigned csa wallace multiplier. Defaults to "u_wallaceCSA_cla".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used to obtain final sums of products. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_wallaceCSA_cla", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Initialize all rows partial products forming AND gates matrix
        self.rows = self.init_row_lengths()

        # Zero extension of partial product rows
        for i in range(0, len(self.rows)):
            self.rows[i] = Bus(prefix=self.rows[i].prefix, wires_list=[ConstantWireValue0() for _ in range(0, i)] + self.rows[i].bus)

        while len(self.rows) > 2:
            # Gradual creation of unsigned csa adder components to reduce the pp rows to the total count of 2
            pp_index = 0
            while pp_index < len(self.rows) and (pp_index+2) < len(self.rows):
                csa_reduction = CarrySaveAdderComponent(a=self.rows[pp_index], b=self.rows[pp_index+1], c=self.rows[pp_index+2], prefix=self.prefix+"_csa"+str(self.get_instance_num(cls=CarrySaveAdderComponent)), inner_component=True)
                self.add_component(csa_reduction)

                # 3 pp rows have been reduced to 2
                [self.rows.pop(pp_index) for i in range(3)]

                # Append rows of sum and carry results from csa calculation
                csa_sums_N = self.out.N if csa_reduction.sum_bits.N > self.out.N-1 else csa_reduction.sum_bits.N
                csa_sums = Bus(prefix=self.prefix+"_csa_s"+str(self.get_instance_num(cls=CarrySaveAdderComponent)), N=csa_sums_N)
                csa_sums.connect_bus(connecting_bus=csa_reduction.out, end_connection_pos=csa_sums_N)

                csa_carries_N = self.out.N if csa_reduction.carry_bits.N > self.out.N-1 else csa_reduction.carry_bits.N
                csa_carries = Bus(prefix=self.prefix+"_csa_c"+str(self.get_instance_num(cls=CarrySaveAdderComponent)), N=csa_carries_N)
                csa_carries.connect_bus(connecting_bus=csa_reduction.out, start_connection_pos=int(csa_reduction.out.N/2), end_connection_pos=int(csa_reduction.out.N/2)+csa_carries.N, offset=int(csa_reduction.out.N/2))

                self.rows.insert(pp_index, csa_carries)
                self.rows.insert(pp_index, csa_sums)

                # Update of the number of pp rows
                pp_index += 2

        # Final addition of remaining bits using chosen unsigned multi bit adder
        # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
        adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(self.rows[0].N)
        adder_a = Bus(prefix="a", N=self.rows[0].N)
        adder_b = Bus(prefix="b", N=self.rows[1].N)
        [adder_a.connect(w, self.rows[0].get_wire(w)) for w in range(0, self.rows[0].N)]
        [adder_b.connect(w, self.rows[1].get_wire(w)) for w in range(0, self.rows[1].N)]
        final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
        self.add_component(final_adder)
        [self.out.connect(o, final_adder.out.get_wire(o), inserted_wire_desired_index=o) for o in range(0, final_adder.out.N-1)]


class SignedWallaceCSAMultiplier(MultiplierCircuit):
    """Class representing signed wallace multiplier composed of carry save adder components.

    Signed wallace multiplier represents fast N-bit multiplier which utilizes
    the functionality of wallace tree reduction algorithm proposed by Chris Wallace and uses Baugh-Wooley algorithm
    to perform signed multiplication.

    First partial products are calculated for each bit pair that form the partial product multiplication rows.
    This implementation uses carry save adder components to efficiently implement reduction of partial products utilizing the parallelism of the carry save adders.
    At last the reduced pairs are inserted into chosen multi bit unsigned adder to execute their summation and obtain the final output bits, additional XOR gate serve the necessary sign extension.

    Wallace tree algorithm is described more in detail here:
    https://en.wikipedia.org/wiki/Wallace_tree

    It presents a faster version of multiplier opposed to the conventional architectures that are composed of interconnected half/full adders.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed csa wallace multiplier. Defaults to "".
        name (str, optional): Name of signed csa wallace multiplier. Defaults to "s_wallaceCSA_cla".
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used to obtain final sums of products. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_wallaceCSA_cla", unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=self.N*2, signed=True, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # Initialize all rows partial products forming AND gates matrix
        self.rows = self.init_row_lengths()

        # Zero extension of partial product rows
        for i in range(0, len(self.rows)):
            self.rows[i] = Bus(prefix=self.rows[i].prefix, wires_list=[ConstantWireValue0() for _ in range(0, i)] + self.rows[i].bus)

        while len(self.rows) > 2:
            # Gradual creation of signed csa adder components to reduce the pp rows to the total count of 2
            pp_index = 0
            while pp_index < len(self.rows) and (pp_index+2) < len(self.rows):
                csa_reduction = CarrySaveAdderComponent(a=self.rows[pp_index], b=self.rows[pp_index+1], c=self.rows[pp_index+2], prefix=self.prefix+"_csa"+str(self.get_instance_num(cls=CarrySaveAdderComponent)), inner_component=True, signed=True)
                self.add_component(csa_reduction)

                # 3 pp rows have been reduced to 2
                [self.rows.pop(pp_index) for i in range(3)]

                # Append rows of sum and carry results from csa calculation
                csa_sums_N = self.out.N if csa_reduction.sum_bits.N > self.out.N-1 else csa_reduction.sum_bits.N
                csa_sums = Bus(prefix=self.prefix+"_csa_s"+str(self.get_instance_num(cls=CarrySaveAdderComponent)), N=csa_sums_N)
                csa_sums.connect_bus(connecting_bus=csa_reduction.out, end_connection_pos=csa_sums_N)

                csa_carries_N = self.out.N if csa_reduction.carry_bits.N > self.out.N-1 else csa_reduction.carry_bits.N
                csa_carries = Bus(prefix=self.prefix+"_csa_c"+str(self.get_instance_num(cls=CarrySaveAdderComponent)), N=csa_carries_N)
                csa_carries.connect_bus(connecting_bus=csa_reduction.out, start_connection_pos=int(csa_reduction.out.N/2), end_connection_pos=int(csa_reduction.out.N/2)+csa_carries.N, offset=int(csa_reduction.out.N/2))

                self.rows.insert(pp_index, csa_carries)
                self.rows.insert(pp_index, csa_sums)

                # Update of the number of pp rows
                pp_index += 2

        # Final addition of remaining bits using chosen unsigned multi bit adder
        # Obtain proper adder name with its bit width (columns bit pairs minus the first alone bit)
        adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(self.rows[0].N)
        adder_a = Bus(prefix="a", N=self.rows[0].N)
        adder_b = Bus(prefix="b", N=self.rows[1].N)
        [adder_a.connect(w, self.rows[0].get_wire(w)) for w in range(0, self.rows[0].N)]
        [adder_b.connect(w, self.rows[1].get_wire(w)) for w in range(0, self.rows[1].N)]
        final_adder = unsigned_adder_class_name(a=adder_a, b=adder_b, prefix=self.prefix, name=adder_name, inner_component=True)
        self.add_component(final_adder)
        [self.out.connect(o, final_adder.out.get_wire(o), inserted_wire_desired_index=o) for o in range(0, final_adder.out.N-1)]

        # Final XOR to ensure proper sign extension
        obj_xor = XorGate(ConstantWireValue1(), self.out.get_wire(self.out.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self)
        self.add_component(obj_xor)
        self.out.connect(self.out.N-1, obj_xor.out)
