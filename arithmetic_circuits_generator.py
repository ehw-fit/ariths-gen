from wire_components import wire, bus
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from one_bit_circuits import constant_wire_value_1, constant_wire_value_0, half_adder, full_adder
from multi_bit_circuits import unsigned_ripple_carry_adder, signed_ripple_carry_adder, unsigned_pg_ripple_carry_adder, signed_pg_ripple_carry_adder, unsigned_array_multiplier, signed_array_multiplier, unsigned_dadda_multiplier, signed_dadda_multiplier, unsigned_wallace_multiplier, signed_wallace_multiplier, unsigned_carry_lookahead_adder, signed_carry_lookahead_adder
import sys


""" TESTING """
if __name__ == "__main__":
    a = bus(N=8, prefix="a")
    b = bus(N=1, prefix="b")
    pg_rca = signed_pg_ripple_carry_adder(a, b)
    pg_rca.get_c_code_flat(open("cla_test_flat.c", "w"))
    pg_rca.get_c_code_hier(open("cla_test_hier.c", "w"))
    pg_rca.get_cgp_code(open("cla_test.chr", "w"))

    #cla = unsigned_carry_lookahead_adder(a, b)

    #rca = signed_ripple_carry_adder(a, b)
    #rca.get_c_code_flat(open("rca_test.c", "w"))
    #rca.get_v_code_flat(open("rca_test.v", "w"))
    #rca.get_blif_code_hier(open("h_rca2_test.blif", "w"))
    #rca.get_cgp_code(open("rca_test.chr", "w"))

    
    #arrmul = signed_array_multiplier(a, b)
    #arrmul.get_c_code_flat(open("arrmul_test.c", "w"))
    #arrmul.get_cgp_code(open("arrmul_test.chr", "w"))
    #arrmul.get_v_code_flat(open("arrmul_test.v", "w"))
    #arrmul.get_blif_code_flat(open("arrmul_test.blif", "w"))
    
    
    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cin")

    ha = half_adder(w1, w2, prefix="ha")
    fa = full_adder(w1, w2, w3, prefix="fa")

    fa.get_v_code_flat(open("f_fa.v", "w"))
    fa.get_v_code_hier(open("h_fa.v", "w"))
    
    fa.get_c_code_flat(open("f_fa.c", "w"))
    fa.get_c_code_hier(open("h_fa.c", "w"))

    fa.get_blif_code_flat(open("f_fa.blif", "w"))
    fa.get_blif_code_hier(open("h_fa.blif", "w"))

    fa.get_cgp_code(open("fa.chr", "w"))
    
    #fa.get_v_code_hier(open("h_fa.v", "w"))
    #fa.get_blif_code_hier(open("h_fa2.blif", "w"))


    #ha.get_cgp_code(open(f"ha.chr", "w"))
    #fa.get_cgp_code(open(f"fa.chr", "w"))

    #fa.get_c_code_flat(open("f_fa.c","w"))
    #ha.get_v_code_hier(open("h_ha.v","w"))
    #ha.get_blif_code_hier(open("h_ha.blif","w"))
    
    #ha.get_blif_code_hier(open("test_h_ha.blif","w"))
    
    #fa.get_v_code_hier(open("h_fa.v","w"))
    #fa.get_blif_code_hier(open("h_fa.blif","w"))
    
    """
    ha.get_v_code_hier(open("h_ha.v","w"))
    ha.get_v_code_flat(open("f_ha.v","w"))
    ha.get_c_code_hier(open("h_ha.c","w"))
    ha.get_c_code_flat(open("f_ha.c","w"))
    ha.get_cgp_code(open("ha.chr","w"))
    """

    gate = nor_gate(w1, w2)
    #gate.get_cgp_code(open("nor_gate.chr","w"))
    #gate.get_v_code(open("and_gate.v","w"))
    #gate.get_blif_code(open("and_gate.blif","w"))
    #gate.get_v_code(open("not_gate.v","w"))
    #gate.get_blif_code(open("test_not_gate.blif","w"))
    """
    #gate.get_c_code(open("and_gate.c","w"))
    #gate.get_v_code(open("and_gate.v","w"))
    #gate.get_cgp_code(open("and_gate.chr","w"))
    """

    #dadda = unsigned_dadda_multiplier(a, b, prefix="h_u_dadda_mul2")
    #dadda.get_v_code_hier(open("h_u_dadda_mul2.v", "w"))
    #dadda.get_c_code_hier(open("h_u_dadda_mul2.c", "w"))
    #dadda.get_blif_code_hier(open("h_u_dadda_mul2.blif", "w"))
    #dadda.get_cgp_code(open("u_dadda_mul2.chr", "w"))


    s_dadda = signed_dadda_multiplier(a, b, prefix="dadda_s_mul8")
    
    s_dadda.get_v_code_hier(open("dadda_s_mul8.v", "w"))
    s_dadda.get_c_code_hier(open("dadda_s_mul82.c", "w"))
    s_dadda.get_c_code_flat(open("f_dadda_s_mul82.c", "w"))
    s_dadda.get_blif_code_hier(open("dadda_s_mul8.blif", "w"))
    s_dadda.get_cgp_code(open("dadda_s_mul8.chr", "w"))


    #dadda = unsigned_dadda_multiplier(a, b, prefix="h_f_dadda_mul3")
    #dadda.get_c_code_hier(open("test_dadda_mul8.c", "w"))

    test = signed_carry_lookahead_adder(a, b, prefix="test")
    
    test.get_c_code_hier(open("htest.c", "w"))
    test.get_c_code_flat(open("ftest.c", "w"))
    
    test.get_v_code_flat(open("ftest.v", "w"))
    test.get_v_code_hier(open("htest.v", "w"))

    test.get_blif_code_flat(open("ftest.blif", "w"))
    test.get_blif_code_hier(open("htest.blif", "w"))

    test.get_cgp_code(open("test.chr", "w"))
    

