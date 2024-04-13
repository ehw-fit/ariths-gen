from ariths_gen.wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    MultiplierCircuit
)
from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    OrGate,
    XorGate,
    NotGate
)
from ariths_gen.multi_bit_circuits.adders import (
    UnsignedCarryLookaheadAdder
)
import math


class UnsignedAccurateTwoBitMultiplier(MultiplierCircuit):
    """Class representing unsigned two-bit accurate multiplier.

    ```
         A1B1   A1B0   A0B1   A0B0
         │ │    │ │    │ │    │ │
        ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐
        │AND│  │AND│  │AND│  │AND│
        └─┬─┘  └─┬─┘  └─┬─┘  └─┬─┘
          │      └──┬──┐└┬─┐   │
          │         │  │ │ │   │
          │         │  │ │ │   │
          │         │ ┌▼─▼┐│   │
          │         │ │AND││   │
          │         │ └─┬─┘│   │
          └─────┐ ┌─┼───┘┌─┘   │
                │ │ └──┐ │     │
        ┌◄─►┐  ┌▼─▼┐  ┌▼─▼┐    │
        │AND│  │XOR│  │XOR│    │
        └─┬─┘  └─┬─┘  └─┬─┘    │
          │      │      │      │
          ▼      ▼      ▼      ▼
          O3     O2     O1     O0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned two-bit accurate multiplier. Defaults to "".
        name (str, optional): Name of unsigned two-bit accurate multiplier. Defaults to "u_2bit_accm".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_2bit_accm", **kwargs):
        self.N = max(a.N, b.N)
        assert self.N == 2
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        and_obj1 = AndGate(self.a.get_wire(0), self.b.get_wire(0), prefix=self.prefix+"_and0")
        and_obj2 = AndGate(self.a.get_wire(0), self.b.get_wire(1), prefix=self.prefix+"_and1")
        and_obj3 = AndGate(self.a.get_wire(1), self.b.get_wire(0), prefix=self.prefix+"_and2")
        and_obj4 = AndGate(self.a.get_wire(1), self.b.get_wire(1), prefix=self.prefix+"_and3")

        xor_obj1 = XorGate(and_obj2.out, and_obj3.out, prefix=self.prefix+"_xor0")
        and_obj5 = AndGate(and_obj2.out, and_obj3.out, prefix=self.prefix+"_and4")
        xor_obj2 = XorGate(and_obj5.out, and_obj4.out, prefix=self.prefix+"_xor1")
        and_obj6 = AndGate(and_obj5.out, and_obj4.out, prefix=self.prefix+"_and5")
        [self.add_component(obj) for obj in [and_obj1, and_obj2, and_obj3, and_obj4, xor_obj1, and_obj5, xor_obj2, and_obj6]]

        self.out.connect(0, and_obj1.out)
        self.out.connect(1, xor_obj1.out)
        self.out.connect(2, xor_obj2.out)
        self.out.connect(3, and_obj6.out)


class SignedAccurateTwoBitMultiplier(MultiplierCircuit):
    """Class representing signed two-bit accurate multiplier.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed two-bit accurate multiplier. Defaults to "".
        name (str, optional): Name of signed two-bit accurate multiplier. Defaults to "s_2bit_accm".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_2bit_accm", **kwargs):
        self.N = max(a.N, b.N)
        raise NotImplementedError("SignedAccurateTwoBitMultiplier is not implemented yet.")


class UnsignedApproximateTwoBitMultiplierM1(MultiplierCircuit):
    """Class representing unsigned two-bit approximate multiplier variant M1.

    M1 ax variant defined here: https://ieeexplore.ieee.org/document/8727537

    ```
         A1B1   A1B0   A0B1   A0B0
         │ │    │ │    │ │    │ │
        ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐
        │AND│  │AND│  │AND│  │AND│
        └─┬─┘  └─┬─┘  └─┬─┘  └─┬─┘
          │      │      └┐     │
          │      └─────┐ │     │
          └──────┐    ┌▼─▼┐    │
                 │    │ OR│    │
                 │    └─┬─┘    │
                 │      │      │
          ▼      ▼      ▼      ▼
        O3=0     O2     O1     O0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned two-bit approximate multiplier m1. Defaults to "".
        name (str, optional): Name of unsigned two-bit approximate multiplier m1. Defaults to "u_2bit_axm1".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_2bit_axm1", **kwargs):
        self.N = max(a.N, b.N)
        assert self.N == 2
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        and_obj1 = AndGate(self.a.get_wire(0), self.b.get_wire(0), prefix=self.prefix+"_and0")
        and_obj2 = AndGate(self.a.get_wire(0), self.b.get_wire(1), prefix=self.prefix+"_and1")
        and_obj3 = AndGate(self.a.get_wire(1), self.b.get_wire(0), prefix=self.prefix+"_and2")
        and_obj4 = AndGate(self.a.get_wire(1), self.b.get_wire(1), prefix=self.prefix+"_and3")

        or_obj1 = OrGate(and_obj2.out, and_obj3.out, prefix=self.prefix+"_or0")
        [self.add_component(obj) for obj in [and_obj1, and_obj2, and_obj3, and_obj4, or_obj1]]

        self.out.connect(0, and_obj1.out)
        self.out.connect(1, or_obj1.out)
        self.out.connect(2, and_obj4.out)
        self.out.connect(3, ConstantWireValue0())


class SignedApproximateTwoBitMultiplierM1(MultiplierCircuit):
    """Class representing signed two-bit approximate multiplier variant M1.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed two-bit approximate multiplier m1. Defaults to "".
        name (str, optional): Name of signed two-bit approximate multiplier m1. Defaults to "s_2bit_axm1".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_2bit_axm1", **kwargs):
        raise NotImplementedError("SignedApproximateTwoBitMultiplierM1 is not implemented yet.")


class UnsignedApproximateTwoBitMultiplierM2(MultiplierCircuit):
    """Class representing unsigned two-bit approximate multiplier variant M2.

    M2 ax variant defined here: https://ieeexplore.ieee.org/document/8727537

    ```
         A1B1          A1B0   A0B1
         │ │           │ │    │ │
        ┌▼─▼┐         ┌▼─▼┐  ┌▼─▼┐
        │AND│         │AND│  │AND│
        └─┬─┘         └─┬─┘  └─┬─┘
          │             │┌─────┴┐
          │            ┌┴┼────┐ │
          │            │ │    │ │
          │           ┌▼─▼┐  ┌▼─▼┐
          │           │XOR│  │AND│
          │           └─┬─┘  └─┬─┘
          └─────┐ ┌─────┼──────┤
                │ │     │      │
               ┌▼─▼┐    │      │
               │XOR│    │      │
               └─┬─┘    │      │
          ┌──────┼──────┼──────┤
          │      │      │      │
          ▼      ▼      ▼      ▼
          O3     O2     O1     O0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned two-bit approximate multiplier m1. Defaults to "".
        name (str, optional): Name of unsigned two-bit approximate multiplier m1. Defaults to "u_2bit_axm1".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_2bit_axm1", **kwargs):
        self.N = max(a.N, b.N)
        assert self.N == 2
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        and_obj1 = AndGate(self.a.get_wire(0), self.b.get_wire(1), prefix=self.prefix+"_and0")
        and_obj2 = AndGate(self.a.get_wire(1), self.b.get_wire(0), prefix=self.prefix+"_and1")
        and_obj3 = AndGate(self.a.get_wire(1), self.b.get_wire(1), prefix=self.prefix+"_and2")

        and_obj4 = AndGate(and_obj1.out, and_obj2.out, prefix=self.prefix+"_and3")
        xor_obj1 = XorGate(and_obj1.out, and_obj2.out, prefix=self.prefix+"_xor0")

        xor_obj2 = XorGate(and_obj4.out, and_obj3.out, prefix=self.prefix+"_xor1")
        [self.add_component(obj) for obj in [and_obj1, and_obj2, and_obj3, and_obj4, xor_obj1, xor_obj2]]

        self.out.connect(0, and_obj4.out)
        self.out.connect(1, xor_obj1.out)
        self.out.connect(2, xor_obj2.out)
        self.out.connect(3, and_obj4.out)


class SignedApproximateTwoBitMultiplierM2(MultiplierCircuit):
    """Class representing signed two-bit approximate multiplier variant M2.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed two-bit approximate multiplier m2. Defaults to "".
        name (str, optional): Name of signed two-bit approximate multiplier m2. Defaults to "s_2bit_axm2".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_2bit_axm2", **kwargs):
        raise NotImplementedError("SignedApproximateTwoBitMultiplierM2 is not implemented yet.")


class UnsignedApproximateTwoBitMultiplierM3(MultiplierCircuit):
    """Class representing unsigned two-bit approximate multiplier variant M3.

    M3 ax variant defined here: https://ieeexplore.ieee.org/document/8727537

    ```
         A1B1   A1B0   A0B1   A0B0
         │ │    │ │    │ │    │ │
        ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐
        │AND│  │AND│  │AND│  │AND│
        └─┬─┘  └─┬─┘  └─┬─┘  └─┬─┘
          │      │      └┐     │
          │      │       │     │
          │      └─────┐ │     │
          │           ┌▼─▼┐    │
          │           │ OR│    │
          │           └─┬─┘    │
          │┌─────┬──────┼──────┤
          ││     │      │      │
          ││   ┌─▼─┐    │      │
          ││   │NOT│    │      │
          ││   └─┬─┘    │      │
         ┌┴┼────┐└┐     │      │
         │ │    │ │     │      │
        ┌▼─▼┐  ┌▼─▼┐    │      │
        │AND│  │AND│    │      │
        └─┬─┘  └─┬─┘    │      │
          │      │      │      │
          ▼      ▼      ▼      ▼
          O3     O2     O1     O0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned two-bit approximate multiplier m3. Defaults to "".
        name (str, optional): Name of unsigned two-bit approximate multiplier m3. Defaults to "u_2bit_axm3".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_2bit_axm3", **kwargs):
        self.N = max(a.N, b.N)
        assert self.N == 2
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        and_obj1 = AndGate(self.a.get_wire(0), self.b.get_wire(0), prefix=self.prefix+"_and0")
        and_obj2 = AndGate(self.a.get_wire(0), self.b.get_wire(1), prefix=self.prefix+"_and1")
        and_obj3 = AndGate(self.a.get_wire(1), self.b.get_wire(0), prefix=self.prefix+"_and2")
        and_obj4 = AndGate(self.a.get_wire(1), self.b.get_wire(1), prefix=self.prefix+"_and3")

        or_obj1 = OrGate(and_obj2.out, and_obj3.out, prefix=self.prefix+"_xor0")
        not_obj1 = NotGate(and_obj1.out, prefix=self.prefix+"_not0")

        and_obj5 = AndGate(not_obj1.out, and_obj4.out, prefix=self.prefix+"_and4")
        and_obj6 = AndGate(and_obj1.out, and_obj4.out, prefix=self.prefix+"_and5")
        [self.add_component(obj) for obj in [and_obj1, and_obj2, and_obj3, and_obj4, or_obj1, not_obj1, and_obj5, and_obj6]]

        self.out.connect(0, and_obj1.out)
        self.out.connect(1, or_obj1.out)
        self.out.connect(2, and_obj5.out)
        self.out.connect(3, and_obj6.out)


class SignedApproximateTwoBitMultiplierM3(MultiplierCircuit):
    """Class representing signed two-bit approximate multiplier variant M3.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed two-bit approximate multiplier m3. Defaults to "".
        name (str, optional): Name of signed two-bit approximate multiplier m3. Defaults to "s_2bit_axm3".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_2bit_axm3", **kwargs):
        raise NotImplementedError("SignedApproximateTwoBitMultiplierM3 is not implemented yet.")


class UnsignedApproximateTwoBitMultiplierM4(MultiplierCircuit):
    """Class representing unsigned two-bit approximate multiplier variant M4.

    M4 ax variant defined here: https://ieeexplore.ieee.org/document/8727537

    ```
         A1B1   A1B0   A0B1   A0B0
         │ │    │ │    │ │    │ │
        ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐  ┌▼─▼┐
        │AND│  │AND│  │AND│  │AND│
        └─┬─┘  └─┬─┘  └─┬─┘  └─┬─┘
          │      │      └┐     │
          │      └─────┐ │     │
          └──────┐    ┌▼─▼┐    │
                 │    │XOR│    │
                 │    └─┬─┘    │
                 │      │      │
          ▼      ▼      ▼      ▼
        O3=0     O2     O1     O0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned two-bit approximate multiplier m4. Defaults to "".
        name (str, optional): Name of unsigned two-bit approximate multiplier m4. Defaults to "u_2bit_axm4".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_2bit_axm4", **kwargs):
        self.N = max(a.N, b.N)
        assert self.N == 2
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        and_obj1 = AndGate(self.a.get_wire(0), self.b.get_wire(0), prefix=self.prefix+"_and0")
        and_obj2 = AndGate(self.a.get_wire(0), self.b.get_wire(1), prefix=self.prefix+"_and1")
        and_obj3 = AndGate(self.a.get_wire(1), self.b.get_wire(0), prefix=self.prefix+"_and2")
        and_obj4 = AndGate(self.a.get_wire(1), self.b.get_wire(1), prefix=self.prefix+"_and3")

        xor_obj1 = XorGate(and_obj2.out, and_obj3.out, prefix=self.prefix+"_xor0")
        [self.add_component(obj) for obj in [and_obj1, and_obj2, and_obj3, and_obj4, xor_obj1]]

        self.out.connect(0, and_obj1.out)
        self.out.connect(1, xor_obj1.out)
        self.out.connect(2, and_obj4.out)
        self.out.connect(3, ConstantWireValue0())


class SignedApproximateTwoBitMultiplierM4(MultiplierCircuit):
    """Class representing signed two-bit approximate multiplier variant M4.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed two-bit approximate multiplier m4. Defaults to "".
        name (str, optional): Name of signed two-bit approximate multiplier m4. Defaults to "s_2bit_axm4".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_2bit_axm4", **kwargs):
        raise NotImplementedError("SignedApproximateTwoBitMultiplierM4 is not implemented yet.")


class UnsignedRecursiveMultiplier(MultiplierCircuit):
    """Class representing unsigned recursive multiplier.

    Input bit-vector length N can be any power of two greater than 1 (e.g. 2, 4, 8, ...).

    The internal structure of the recursive multiplier is composed of subsequent two-bit submultipliers provided in the input `submultipliers` list.
    The `submultipliers` list should contain the classes of the two-bit submultipliers that will be used for instantiation. If None are provided, accurate two-bit submultipliers are assumed.

    The number of submultipliers required is equal to (N/2)² for N > 2. For N = 2, only one two-bit submultiplier is required.

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned recursive multiplier. Defaults to "".
        name (str, optional): Name of unsigned recursive multiplier. Defaults to "u_rm".
        submultipliers (list, optional): List of composite two bit submultiplier classes for instantiation. If None are provided, accurate submultipliers are assumed. Defaults to None.
                        Defaults (if None) to the required number of UnsignedAccurateTwoBitMultiplier instances.
        unsigned_adder_class_name (str, optional): Unsigned multi bit adder used to obtain final sums of products. Defaults to UnsignedCarryLookaheadAdder.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_rm", submultipliers: list = None, unsigned_adder_class_name: str = UnsignedCarryLookaheadAdder, **kwargs):
        self.N = max(a.N, b.N)
        assert self.N > 1 and self.N & (self.N-1) == 0  # assure that N is a power of two greater than 1 (So allowed N is 2, 4, 8, ..)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N*2, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        if submultipliers is None:  # By default, we assume composition from accurate two bit submultipliers
            if self.N == 2:
                submultipliers = [UnsignedAccurateTwoBitMultiplier]
            else:
                submultipliers = [UnsignedAccurateTwoBitMultiplier for _ in range((self.N//2)**2)]

        assert (self.N > 2 and len(submultipliers) == (self.N//2)**2) or (self.N == 2 and len(submultipliers) == 1)

        if self.N == 2:  # Base case for just one two-bit multiplier
            # TODO add suffix in ariths_gen rework
            mult = submultipliers[0](Bus(prefix=self.prefix + "_a", wires_list=self.a.bus), Bus(prefix=self.prefix + "_b", wires_list=self.b.bus), prefix=self.prefix + "_" + str(self.get_instance_num(cls=submultipliers[0])), **kwargs)
            self.add_component(mult)
            self.out.connect_bus(mult.out)
        else:
            # Levels of construction of the recursive multiplier
            # recursive_levels = int(math.log2(self.N)-1)  # Number of recursive levels based on the power ith power of 2 (e.g. for N=8, we have 2 recursive levels)
            block_level = 1
            partial_products = []

            for m in range(len(submultipliers)):  # Iterate over all 2-bit submultipliers (equals range(0, 4**recursive_levels))
                a_bus_offset = 0
                b_bus_offset = 0
                curr_level = block_level
                curr_id = m

                # Determine the wires offsets from MSB (for input bus `a` and `b`) for the current 2-bit submultiplier
                # There is a pattern, for example for N=8, we have 16 two-bit submultipliers with offsets:
                #       Mult ID:  1  2  3  4   5  6  7  8   9 10 11 12   13 14 15 16
                # MSB a_offsets:  0  0  2  2   0  0  2  2   4  4  6  6    4  4  6  6
                # MSB b_offsets:  0  2  0  2   4  6  4  6   0  2  0  2    4  6  4  6
                while curr_level != 0:
                    # A offset
                    if curr_id // ((4**curr_level)//2) != 0:
                        a_bus_offset += 2**curr_level

                    # B offset
                    if (curr_id // ((4**curr_level)//4)) % 2 != 0:
                        b_bus_offset += 2**curr_level

                    curr_level -= 1
                    curr_id -= (4**curr_level)*((curr_id // (4**curr_level)))

                # Create 2-bit submultiplier with the corresponding input bits
                # TODO add suffix in ariths_gen rework
                submult_a_bus = Bus(prefix=f"mult{m}_a", wires_list=self.a.bus[::-1][0+a_bus_offset:0+a_bus_offset+2][::-1], N=2)
                submult_b_bus = Bus(prefix=f"mult{m}_b", wires_list=self.b.bus[::-1][0+b_bus_offset:0+b_bus_offset+2][::-1], N=2)
                submult = submultipliers[m](submult_a_bus, submult_b_bus, prefix=self.prefix + "_" + str(self.get_instance_num(cls=submultipliers[m])))
                self.add_component(submult)

                # Create wire vectors holding partial products for final summation
                pp = Bus(prefix=f"pp_{m}", N=self.out.N, wires_list=[ConstantWireValue0() for _ in range(self.out.N)])
                # [pp.connect_bus(submult.out, offset=(self.out.N-4)-(a_bus_offset+b_bus_offset))]
                [pp.connect((self.out.N-1)-(a_bus_offset+b_bus_offset)-i, submult.out[3-i], inserted_wire_desired_index=3-i) for i in range(4)]
                partial_products.append(pp)

                # Distinction of levels of blocks to properly instantiate and connect 2-bit submultipliers
                # For example, for N=8, we have 4 two-bit submultipliers in the first level, but then we have 4 times the
                # same structure (4 two-bit mults) as the base component for the second level, similarly for N=16, but
                # with additional third layer (consisting of 16 two-bit submultipliers)
                if (m+1) % (4**block_level) == 0:
                    block_level += 1  # Increase the block level

            # Create tree of partial product adders
            while len(partial_products) != 1:
                N = len(partial_products)//2
                # Creation of composite unsigned multi bit adders from set of partial product vectors and addition of generated blocks outputs for next iteration
                for bus_index in range(0, N):
                    # TODO arithsgen_rework: update check for bus declaration and assignment (if true do declare/assign again - here we would not create new bus, just assign the existing one); it should create cleaner outcode with unncecessary new bus declarations
                    adder_name = unsigned_adder_class_name(a=a, b=b).prefix + str(self.get_instance_num(cls=unsigned_adder_class_name))
                    # TODO rework the buses
                    bus_a = Bus(prefix=f"{adder_name}_a", wires_list=partial_products[bus_index].bus, out_bus=True) if partial_products[bus_index].out_bus else partial_products[bus_index]
                    bus_b = Bus(prefix=f"{adder_name}_b", wires_list=partial_products[bus_index+N].bus, out_bus=True) if partial_products[bus_index+N].out_bus else partial_products[bus_index+N]
                    adder = unsigned_adder_class_name(a=bus_a, b=bus_b, prefix=self.prefix, name=adder_name, inner_component=True, **kwargs)
                    self.add_component(adder)
                    partial_products.append(adder.out)

                # Update partial products list for next iteration until it contains only one output vector
                partial_products = partial_products[2*N:]
            # Connect the final output of the recursive multiplier
            self.out.connect_bus(partial_products[0])


class SignedRecursiveMultiplier(MultiplierCircuit):
    """Class representing signed recursive multiplier.

    TODO
    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed recursive multiplier. Defaults to "".
        name (str, optional): Name of signed recursive multiplier. Defaults to "s_rm".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_rm", **kwargs):
        raise NotImplementedError("SignedRecursiveMultiplier is not implemented yet.")
