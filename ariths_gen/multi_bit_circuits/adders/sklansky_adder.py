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


class UnsignedSklanskyAdder(GeneralCircuit):
    """Class representing unsigned Sklansky (or divide-and-conquer) adder (using valency-2 logic gates).

    The Sklansky adder belongs to a type of tree (parallel-prefix) adders.
    Tree adder structure consists of three parts of logic: 1) PG logic generation, 2) Parallel PG logic computation, 3) Final sum and cout computation
    The main difference between each tree adder lies in the implementation of the part 2).

    Along with Kogge-Stone and Brent-Kung it is considered to be a fundamental tree adder architecture.

    Sklansky achieves log2(N) stages by computing intermediate prefixes along with the large group prefixes. This comes at the expense
    of fanouts that double at each level.

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
        prefix (str, optional): Prefix name of unsigned sa. Defaults to "".
        name (str, optional): Name of unsigned sa. Defaults to "u_sa".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "u_sa", **kwargs):
        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)
        cin = ConstantWireValue0()

        # Lists of list containing all propagate/generate wires
        self.propagate_sig = []
        self.generate_sig = []
        # Cin0 used as a first generate wire for obtaining next carry bits
        self.generate_sig.append([cin])

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


class SignedSklanskyAdder(UnsignedSklanskyAdder, GeneralCircuit):
    """Class representing signed Sklansky (or divide-and-conquer) adder (using valency-2 logic gates).

    The Sklansky adder belongs to a type of tree (parallel-prefix) adders.
    Tree adder structure consists of three parts of logic: 1) PG logic generation, 2) Parallel PG logic computation, 3) Final sum and cout computation
    The main difference between each tree adder lies in the implementation of the part 2).

    Along with Kogge-Stone and Brent-Kung it is considered to be a fundamental tree adder architecture.

    Sklansky achieves log2(N) stages by computing intermediate prefixes along with the large group prefixes. This comes at the expense
    of fanouts that double at each level.

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
        prefix (str, optional): Prefix name of signed sa. Defaults to "".
        name (str, optional): Name of signed sa. Defaults to "s_sa".
    """
    def __init__(self, a: Bus, b: Bus, prefix: str = "", name: str = "s_sa", **kwargs):
        # Signed bus length extension
        N = max(a.N, b.N)
        a.bus_extend(N=N, prefix=a.prefix, desired_extension_wire=a.get_wire(a.N-1))
        b.bus_extend(N=N, prefix=b.prefix, desired_extension_wire=b.get_wire(b.N-1))
        
        super().__init__(a=a, b=b, prefix=prefix, name=name, signed=True, **kwargs)

        # Additional XOR gates to ensure correct sign extension in case of sign addition
        self.add_component(XorGate(self.a.get_wire(self.N-1), self.b.get_wire(self.N-1), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self))
        self.add_component(XorGate(self.get_previous_component().out, self.get_previous_component(2).get_generate_wire(), prefix=self.prefix+"_xor"+str(self.get_instance_num(cls=XorGate)), parent_component=self))
        self.out.connect(self.N, self.get_previous_component().out)
