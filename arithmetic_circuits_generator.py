from wire_components import wire, bus
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from one_bit_circuits import constant_wire_value_1, constant_wire_value_0, half_adder, full_adder
from multi_bit_circuits import unsigned_ripple_carry_adder, signed_ripple_carry_adder, unsigned_pg_ripple_carry_adder, signed_pg_ripple_carry_adder, unsigned_array_multiplier, signed_array_multiplier, unsigned_dadda_multiplier, signed_dadda_multiplier, unsigned_wallace_multiplier, signed_wallace_multiplier, unsigned_carry_lookahead_adder, signed_carry_lookahead_adder
import sys


""" TESTING """
if __name__ == "__main__":
    N = 8

    a = bus(N=N, prefix="a")
    b = bus(N=1, prefix="b")

    name = f"test"
    circuit = unsigned_ripple_carry_adder(a,b, prefix=name)
    circuit.get_c_code_flat(open(f'{name}.c', 'w'))
    #circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    #circuit.get_v_code_hier(open(f"{name}.v", "w"))
    #circuit.get_blif_code_hier(open(f"{name}.blif", "w"))

    """
    name = f"h_u_wallace_cla{N}"
    circuit = unsigned_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_wallace_cla{N}"
    circuit = signed_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))


    name = f"h_u_dadda_cla{N}"
    circuit = unsigned_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_dadda_cla{N}"
    circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))
    """
    
    """
    # RCA
    name = f"h_u_rca{N}"
    circuit = unsigned_ripple_carry_adder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_rca{N}"
    circuit = unsigned_ripple_carry_adder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    #RCA with PG
    name = f"h_u_pg_rca{N}"
    circuit = unsigned_pg_ripple_carry_adder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_pg_rca{N}"
    circuit = signed_pg_ripple_carry_adder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    #CLA with PG
    name = f"h_u_cla{N}"
    circuit = unsigned_carry_lookahead_adder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_cla{N}"
    circuit = signed_carry_lookahead_adder(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    
    # Arrmul
    name = f"h_u_arrmul{N}"
    circuit = unsigned_array_multiplier(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_arrmul{N}"
    circuit = signed_array_multiplier(a, b, prefix=name)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    # Wallace
    name = f"h_u_wallace_rca{N}"
    circuit = unsigned_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_wallace_rca{N}"
    circuit = signed_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))



    name = f"h_u_wallace_pg_rca{N}"
    circuit = unsigned_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_wallace_pg_rca{N}"
    circuit = signed_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))



    name = f"h_u_wallace_cla{N}"
    circuit = unsigned_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_wallace_cla{N}"
    circuit = signed_wallace_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    # Dadda
    name = f"h_u_dadda_rca{N}"
    circuit = unsigned_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_dadda_rca{N}"
    circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))


    name = f"h_u_dadda_pg_rca{N}"
    circuit = unsigned_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_dadda_pg_rca{N}"
    circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_pg_ripple_carry_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_u_dadda_cla{N}"
    circuit = unsigned_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))

    name = f"h_s_dadda_cla{N}"
    circuit = signed_dadda_multiplier(a, b, prefix=name, unsigned_adder_class_name=unsigned_carry_lookahead_adder)
    circuit.get_v_code_hier(open(f"{name}.v", "w"))
    """

    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cin")

    #ha = half_adder(w1, w2, prefix="ha")
    #fa = full_adder(w1, w2, w3, prefix="fa")

    #gate = nor_gate(w1, w2)
    
    """
    test = signed_carry_lookahead_adder(a, b, prefix="test")
    
    test.get_c_code_hier(open("htest.c", "w"))
    test.get_c_code_flat(open("ftest.c", "w"))
    
    test.get_v_code_flat(open("ftest.v", "w"))
    test.get_v_code_hier(open("htest.v", "w"))

    test.get_blif_code_flat(open("ftest.blif", "w"))
    test.get_blif_code_hier(open("htest.blif", "w"))

    test.get_cgp_code(open("test.chr", "w"))
    """
