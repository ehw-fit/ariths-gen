from wire_components import wire, bus
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from one_bit_circuits import constant_wire_value_1, constant_wire_value_0, half_adder, full_adder
from multi_bit_circuits import unsigned_ripple_carry_adder, signed_ripple_carry_adder, unsigned_pg_ripple_carry_adder, signed_pg_ripple_carry_adder, unsigned_array_multiplier, signed_array_multiplier, unsigned_dadda_multiplier, signed_dadda_multiplier, unsigned_wallace_multiplier, signed_wallace_multiplier, unsigned_carry_lookahead_adder, signed_carry_lookahead_adder
import sys


""" TESTING """
if __name__ == "__main__":
    N = 4

    a = bus(N=N, prefix="a")
    b = bus(N=1, prefix="b")

    """
    # RCA
    name = f"u_rca{N}"
    circuit = unsigned_ripple_carry_adder(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_rca{N}"
    circuit = unsigned_ripple_carry_adder(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    #RCA with PG
    name = f"u_pg_rca{N}"
    circuit = unsigned_pg_ripple_carry_adder(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_pg_rca{N}"
    circuit = signed_pg_ripple_carry_adder(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    #CLA with PG
    name = f"u_cla{N}"
    circuit = unsigned_carry_lookahead_adder(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_cla{N}"
    circuit = signed_carry_lookahead_adder(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    
    # Arrmul
    name = f"u_arrmul{N}"
    circuit = unsigned_array_multiplier(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_arrmul{N}"
    circuit = signed_array_multiplier(a, b, prefix=name)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    # Wallace
    name = f"u_wallace_rca{N}"
    circuit = unsigned_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_wallace_rca{N}"
    circuit = signed_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))



    name = f"u_wallace_pg_rca{N}"
    circuit = unsigned_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_wallace_pg_rca{N}"
    circuit = signed_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))
    
    # Dadda
    name = f"u_dadda_rca{N}"
    circuit = unsigned_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_dadda_rca{N}"
    circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))


    name = f"u_dadda_pg_rca{N}"
    circuit = unsigned_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))

    name = f"s_dadda_pg_rca{N}"
    circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_cgp_code_flat(open(f"{name}.chr", "w"))
    """

    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cin")

    """
    ha = half_adder(w1, w2, prefix="h_ha")
    ha.get_c_code_hier(open(f"h_ha.c", "w"))
    fa = full_adder(w1, w2, w3, prefix="f_fa")
    fa.get_c_code_hier(open(f"h_fa.c", "w"))

    gate = and_gate(w1, w2)
    """