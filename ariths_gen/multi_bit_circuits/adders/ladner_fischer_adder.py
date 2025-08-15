from ariths_gen.wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    PGSumLogic,
    GreyCell,
    BlackCell
)
from ariths_gen.one_bit_circuits.logic_gates import (
    XorGate
)
import math


class UnsignedLadnerFischerAdder(GeneralCircuit):
    """Class representing unsigned Ladner-Fischer adder (using valency-2 logic gates).

    The Ladner-Fischer adder belongs to a type of tree (parallel-prefix) adders.
    Tree adder structure consists of three parts of logic: 1) PG logic generation, 2) Parallel PG logic computation, 3) Final sum and cout computation
    The main difference between each tree adder lies in the implementation of the part 2).

    Ladner-Fischer adders are a family of tree adders that represent a tradeoff between Brent-Kung and Sklansky implementations.
    Depending on the input bitwidth, there are many possible implementation configurations, precisely: [1, ⌈log2(N)⌉-2] number for N > 4 (otherwise just 1).
    The structures of the individual configurations shift from inclination more towards one or the other original implementation.

    Ladner-Fischer networks provide tradeoff between the number of stages in the PG logic and fanout load on wires.

    Main building components are GreyCells and BlackCells that appropriately encapsulate the essential logic used for PG computation.
    For further circuit characteristics see the book CMOS VLSI Design.

    The implementation performs the 1) and 3) (sum XORs) parts using one bit three input P/G/Sum logic function blocks.
    The 2) part is then composed according to the parallel-prefix adder characteristics.

    ```
      B3 A3         B2 A2       B1 A1       B0 A0
      │  │          │  │        │  │        │  │
    ┌─▼──▼─┐      ┌─▼──▼─┐    ┌─▼──▼─┐    ┌─▼──▼─┐
    │  PG  │  C3  │  PG  │ C2 │  PG  │ C1 │  PG  │
    │  SUM │◄────┐│  SUM │◄──┐│  SUM │◄──┐│  SUM │◄──0
    │      │     ││      │   ││      │   ││      │
    └─┬──┬┬┘     │└─┬┬┬──┘   │└─┬┬┬──┘   │└─┬┬┬──┘
      │  ││G3P3S3│  │││G2P2S2│  │││G1P1S1│  │││G0P0S0
      │ ┌▼▼──────┴──▼▼▼──────┴──▼▼▼──────┴──▼▼▼──┐
      │ │            Parallel-prefix             │
      │ │               PG logic                 │
      │ └─┬───────┬──────────┬──────────┬────────┘
      │   │S3     │S2        │S1        │S0
    ┌─▼───▼───────▼──────────▼──────────▼────────┐
    │                Sum + Cout                  │
    │                   logic                    │
    └┬────┬───────┬──────────┬──────────┬────────┘
     │    │       │          │          │
     ▼    ▼       ▼          ▼          ▼
    Cout  S3      S1         S0         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of unsigned lfa. Defaults to "".
        name (str, optional): Name of unsigned lfa. Defaults to "u_lfa".
        config_choice (int, optional): Tradeoff implementation choice concerning the number of stages in the PG logic and fanout load on wires. The number of choices goes from 1 up to ⌈log2(N)⌉-2 for N > 4, otherwise the choice is 1. Defaults to 1.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_lfa", config_choice: int = 1, **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)
        cin = ConstantWireValue0()

        # Configuration setting
        self.config_choice = config_choice
        if self.N > 4:
            assert self.config_choice > 0 and self.config_choice <= math.ceil(math.log(self.N, 2))-2, "The configuration choice must fall in a range [1, ⌈log2(N)⌉-2] for N > 4."
        else:
            assert self.config_choice == 1, "The configuration choice for N <= 4 is only 1."

        # Lists of list containing all propagate/generate wires
        self.propagate_sig = []
        self.generate_sig = []
        # Cin0 used as a first generate wire for obtaining next carry bits
        self.generate_sig.append([cin])
        # The configuration choice offset used to appropriately interconnect PG logic cells in each stage and to determine the number of stages for a given bit index
        config_offset = 2**self.config_choice

        # For each bit pair proceed with three stages of PPAs (Generate PG signals, Prefix computation (PG logic), Computation and connection of outputs)
        # NOTE In the implementation below, both the first and third stages are handled by the PG FAs
        for i_wire in range(self.N):
            # 1st + 3rd stage: Generate PG signals + Computation and connection of outputs
            self.add_component(PGSumLogic(self.a.get_wire(i_wire), self.b.get_wire(i_wire), self.generate_sig[i_wire][-1], prefix=self.prefix+"_pg_sum"+str(self.get_instance_num(cls=PGSumLogic))))
            self.generate_sig.append([self.get_previous_component().get_generate_wire()])
            self.propagate_sig.append([self.get_previous_component().get_propagate_wire()])

            self.out.connect(i_wire, self.get_previous_component().get_sum_wire())
            if i_wire == self.N-1:
                self.add_component(GreyCell(self.generate_sig[i_wire+1][-1], self.propagate_sig[i_wire][0], self.generate_sig[i_wire][-1], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                self.out.connect(self.N, self.get_previous_component().get_generate_wire())
            # 2nd stage: Prefix Computation (PG logic)
            # For all bit indexes expect for the last one, proceed with the parralel prefix PG logic
            else:
                if (i_wire+2) % config_offset == 0 or (i_wire < 4 and i_wire % 2 == 0):  # These input bits form a Sklansky adder structure
                    binary_form = bin(i_wire+1)[2:][::-1]  # +1 to obtain proper carry bit index (index 0 corresponds to Cin)
                    index_stages = len(binary_form)
                    prev_stage_int_value = 0
                    for stage, value in enumerate(binary_form):
                        if value == '1':
                            # Grey cell
                            if stage == index_stages-1:
                                if index_stages == 1:  # Bit index with only one stage
                                    self.add_component(GreyCell(self.generate_sig[i_wire+1][0], self.propagate_sig[i_wire][0], self.generate_sig[i_wire][-1], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                                else:  # Bit index contains multiple stages, GC is its last stage
                                    self.add_component(GreyCell(self.get_previous_component().get_generate_wire(), self.get_previous_component().get_propagate_wire(), self.generate_sig[i_wire-prev_stage_int_value][-1], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                            # Black cell
                            else:  # If bit index contains more than one stage, every stage except for the last one contains a Black cell
                                self.add_component(BlackCell(self.generate_sig[i_wire+1][-1], self.propagate_sig[i_wire][-1], self.generate_sig[i_wire-prev_stage_int_value][stage], self.propagate_sig[i_wire-1-prev_stage_int_value][stage], prefix=self.prefix+"_bc"+str(self.get_instance_num(cls=BlackCell))))
                                self.propagate_sig[i_wire].append(self.get_previous_component().get_propagate_wire())
                            self.generate_sig[i_wire+1].append(self.get_previous_component().get_generate_wire())
                            prev_stage_int_value += 2**stage
                else:  # Other input bits are implemented in the same fasion as in the Brent-Kung adder structure
                    index_stages = math.log(i_wire+2, 2)  # +1 because indexes start from 0 and additional +1 because the first generated carry is actually the second carry after cin (the previous cin has 0 stages)
                    if int(index_stages) == index_stages:  # Bit indexes that are powers of 2
                        for stage in range(int(index_stages)):
                            # Grey cell
                            if stage == index_stages-1:
                                if stage == 0:  # Bit index with only one stage
                                    self.add_component(GreyCell(self.generate_sig[i_wire+1][0], self.propagate_sig[i_wire][0], self.generate_sig[i_wire][0], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                                else:  # Bit index contains multiple stages, GC is its last stage
                                    self.add_component(GreyCell(self.get_previous_component().get_generate_wire(), self.get_previous_component().get_propagate_wire(), self.generate_sig[(i_wire+1)-(2**stage)][-1], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                            # Black cell
                            else:  # If bit index contains more than one stage, every stage except for the last one contains a Black cell
                                self.add_component(BlackCell(self.generate_sig[i_wire+1][-1], self.propagate_sig[i_wire][-1], self.generate_sig[(i_wire+1)-(2**stage)][stage], self.propagate_sig[i_wire-(2**stage)][stage], prefix=self.prefix+"_bc"+str(self.get_instance_num(cls=BlackCell))))
                                self.propagate_sig[i_wire].append(self.get_previous_component().get_propagate_wire())
                            self.generate_sig[i_wire+1].append(self.get_previous_component().get_generate_wire())
                    elif i_wire % 2 == 0:  # Even-numbered input indexes
                        # Different handling based on the chosen configuration and the corresponding PG logic structure
                        if i_wire+2 <= config_offset:  # Same behaviour as in the case of a regular Brent-Kung
                            lower_closest_power_of_two = 2**math.floor(math.log(i_wire+2, 2))  # i.e. 2^3 = 8
                            higher_closest_power_of_two = 2**math.ceil(math.log(i_wire+2, 2))  # i.e. 2^4 = 16
                            down_diff = (i_wire+2) - lower_closest_power_of_two
                            up_diff = higher_closest_power_of_two - (i_wire+2)
                        else:  # The number of stages for these indexes is different as opposed to a regular Brent-Kung implementation
                            # Determine the closest lower and higher multiples of the input config offset
                            lower_closest_multiple = ((i_wire+2) // config_offset) * config_offset
                            higher_closest_multiple = lower_closest_multiple + config_offset
                            down_diff = abs((i_wire+2) - lower_closest_multiple)
                            up_diff = abs(higher_closest_multiple - (i_wire+2))

                        diff_power = up_diff if up_diff < down_diff else down_diff
                        index_stages = math.floor(math.log(diff_power, 2))+1
                        for stage in range(index_stages):
                            # Black cell
                            if stage != index_stages-1:  # Bit index contains more than one stage, every stage except for the last one contains a Black cell
                                self.add_component(BlackCell(self.generate_sig[i_wire+1][-1], self.propagate_sig[i_wire][-1], self.generate_sig[(i_wire+1)-(2**stage)][stage], self.propagate_sig[i_wire-(2**stage)][stage], prefix=self.prefix+"_bc"+str(self.get_instance_num(cls=BlackCell))))
                                self.propagate_sig[i_wire].append(self.get_previous_component().get_propagate_wire())
                            # Grey cell
                            else:  # Bit index contains multiple stages, GC is its last stage
                                self.add_component(GreyCell(self.get_previous_component().get_generate_wire(), self.get_previous_component().get_propagate_wire(), self.generate_sig[(i_wire+1)-(2**stage)][-1], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                            self.generate_sig[i_wire+1].append(self.get_previous_component().get_generate_wire())
                    else:  # Odd-numbered input indexes
                        self.add_component(GreyCell(self.generate_sig[i_wire+1][-1], self.propagate_sig[i_wire][0], self.generate_sig[i_wire][-1], prefix=self.prefix+"_gc"+str(self.get_instance_num(cls=GreyCell))))
                        self.generate_sig[i_wire+1].append(self.get_previous_component().get_generate_wire())


class SignedLadnerFischerAdder(UnsignedLadnerFischerAdder, GeneralCircuit):
    """Class representing signed Ladner-Fischer adder (using valency-2 logic gates).

    The Ladner-Fischer adder belongs to a type of tree (parallel-prefix) adders.
    Tree adder structure consists of three parts of logic: 1) PG logic generation, 2) Parallel PG logic computation, 3) Final sum and cout computation
    The main difference between each tree adder lies in the implementation of the part 2).

    Ladner-Fischer adders are a family of tree adders that represent a tradeoff between Brent-Kung and Sklansky implementations.
    Depending on the input bitwidth, there are many possible implementation configurations, precisely: [1, ⌈log2(N)⌉-2] number for N > 4 (otherwise just 1).
    The structures of the individual configurations shift from inclination more towards one or the other original implementation.

    Ladner-Fischer networks provide tradeoff between the number of stages in the PG logic and fanout load on wires.

    Main building components are GreyCells and BlackCells that appropriately encapsulate the essential logic used for PG computation.
    For further circuit characteristics see the book CMOS VLSI Design.

    The implementation performs the 1) and 3) (sum XORs) parts using one bit three input P/G/Sum logic function blocks.
    The 2) part is then composed according to the parallel-prefix adder characteristics.
    At last XOR gates are used to ensure proper sign extension.

    ```
      B3 A3         B2 A2       B1 A1       B0 A0
      │  │          │  │        │  │        │  │
    ┌─▼──▼─┐      ┌─▼──▼─┐    ┌─▼──▼─┐    ┌─▼──▼─┐
    │  PG  │  C3  │  PG  │ C2 │  PG  │ C1 │  PG  │
    │  SUM │◄────┐│  SUM │◄──┐│  SUM │◄──┐│  SUM │◄──0
    │      │     ││      │   ││      │   ││      │
    └─┬──┬┬┘     │└─┬┬┬──┘   │└─┬┬┬──┘   │└─┬┬┬──┘
      │  ││G3P3S3│  │││G2P2S2│  │││G1P1S1│  │││G0P0S0
      │ ┌▼▼──────┴──▼▼▼──────┴──▼▼▼──────┴──▼▼▼──┐
      │ │            Parallel-prefix             │
      │ │               PG logic                 │
      │ └─┬───────┬──────────┬──────────┬────────┘
      │   │S3     │S2        │S1        │S0
    ┌─▼───▼───────▼──────────▼──────────▼────────┐
    │                Sum + Cout                  │
    │           with sign extension              │
    └┬────┬───────┬──────────┬──────────┬────────┘
     │    │       │          │          │
     ▼    ▼       ▼          ▼          ▼
    Cout  S3      S1         S0         S0
    ```

    Description of the __init__ method.

    Args:
        a (Bus): First input bus.
        b (Bus): Second input bus.
        prefix (str, optional): Prefix name of signed lfa. Defaults to "".
        name (str, optional): Name of signed lfa. Defaults to "s_lfa".
        config_choice (int, optional): Tradeoff implementation choice concerning the number of stages in the PG logic and fanout load on wires. The number of choices goes from 1 up to ⌈log2(N)⌉-2 for N > 4, otherwise the choice is 1. Defaults to 1.
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_lfa", config_choice: int = 1, **kwargs):
        # Signed bus length extension
        N = max(a.N, b.N)
        a.bus_extend(N=N, prefix=a.prefix, desired_extension_wire=a.get_wire(a.N-1))
        b.bus_extend(N=N, prefix=b.prefix, desired_extension_wire=b.get_wire(b.N-1))
        
        super().__init__(a=a, b=b, prefix=prefix, name=name, config_choice=config_choice, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        self.add_component(XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self))
        self.add_component(XorGate(self.get_previous_component().out, self.get_previous_component(2).get_generate_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self))
        self.out.connect(self.N, self.get_previous_component().out)
