from ariths_gen.wire_components import(
    Wire,
    Bus
)

from ariths_gen.one_bit_circuits.logic_gates import(
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)

from ariths_gen.one_bit_circuits.one_bit_components import(
    HalfAdder,
    FullAdder
)

from ariths_gen.multi_bit_circuits.adders import(
    UnsignedCarryLookaheadAdder,
    UnsignedPGRippleCarryAdder,
    UnsignedRippleCarryAdder,
    SignedCarryLookaheadAdder,
    SignedPGRippleCarryAdder,
    SignedRippleCarryAdder
)

from ariths_gen.multi_bit_circuits.multipliers import(
    UnsignedDaddaMultiplier,
    UnsignedArrayMultiplier,
    UnsignedWallaceMultiplier,
    SignedArrayMultiplier,
    SignedDaddaMultiplier,
    SignedWallaceMultiplier
)
import sys
import os


""" Generation of circuits """
if __name__ == "__main__":
    N = 8
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    directory = "build"
    os.makedirs(directory, exist_ok = True)

    representation = "h"

    # RCA
    name = f"{representation}_u_rca{N}"
    circuit = UnsignedRippleCarryAdder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_rca{N}"
    circuit = SignedRippleCarryAdder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    #RCA with PG
    name = f"{representation}_u_pg_rca{N}"
    circuit = UnsignedPGRippleCarryAdder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_pg_rca{N}"
    circuit = SignedPGRippleCarryAdder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    #CLA with PG
    name = f"{representation}_u_cla{N}"
    circuit = UnsignedCarryLookaheadAdder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_cla{N}"
    circuit = SignedCarryLookaheadAdder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    
    # Arrmul
    name = f"{representation}_u_arrmul{N}"
    circuit = UnsignedArrayMultiplier(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_arrmul{N}"
    circuit = SignedArrayMultiplier(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    # Wallace
    name = f"{representation}_u_wallace_rca{N}"
    circuit = UnsignedWallaceMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_wallace_rca{N}"
    circuit = SignedWallaceMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_u_wallace_pg_rca{N}"
    circuit = UnsignedWallaceMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_wallace_pg_rca{N}"
    circuit = SignedWallaceMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))
    
    # Dadda
    name = f"{representation}_u_dadda_rca{N}"
    circuit = UnsignedDaddaMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_dadda_rca{N}"
    circuit = SignedDaddaMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))


    name = f"{representation}_u_dadda_pg_rca{N}"
    circuit = UnsignedDaddaMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))

    name = f"{representation}_s_dadda_pg_rca{N}"
    circuit = SignedDaddaMultiplier(a, b, prefix=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
    circuit.get_v_code_hier(open(f"{directory}/{name}.v", "w"))
