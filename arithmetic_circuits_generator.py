from wire_components import wire, bus
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from one_bit_circuits import half_adder, full_adder
from multi_bit_circuits import unsigned_ripple_carry_adder, signed_ripple_carry_adder, unsigned_array_multiplier, signed_array_multiplier
import sys


""" TESTING """
if __name__ == "__main__":
    
    a = bus(N=20, prefix="a")
    b = bus(N=1, prefix="b")
    rca = signed_ripple_carry_adder(a, b, prefix="f_s_rca2")

    rca.get_cgp_code(open("s_rca2.chr","w"))
    #rca.get_v_code_hier(open("h_s_rca6.v", "w"))
    #rca.get_v_code_flat(open("FLATTEST_u_rca3.v", "w"))
    """
    rca.get_c_code_hier(open("h_s_rca8.c", "w"))
    rca.get_c_code_flat(open("f_s_rca8.c", "w"))
    rca.get_c_code_hier(open("h_s_rca8.c", "w"))
    rca.get_c_code_flat(open("f_s_rca8.c", "w"))
    

    rca.get_c_code_hier(open("h_s_rca8.c", "w"))
    rca.get_v_code_hier(open("h_s_rca8.v", "w"))
    rca.get_c_code_flat(open("f_s_rca8.c", "w"))
    rca.get_v_code_flat(open("f_s_rca8.v", "w"))
    """

    #arrmul = signed_array_multiplier(a, b, prefix="f_s_arr_mul3")
    u_arrmul = unsigned_array_multiplier(a, b, prefix="h_u_arr_mul5")
    #u_arrmul.get_cgp_code(open("u_arr_mul5.chr","w"))

    s_arrmul = signed_array_multiplier(a, b)
    s_arrmul.get_v_code_hier(open("testhier4.v","w"))
    s_arrmul.get_v_code_flat(open("testflat4.v","w"))

    s_arrmul.get_cgp_code(open("s_arr_mul20.chr","w"))
    #s_arrmul.get_v_code_hier(open("h_s_arr_mul3.v","w"))

    
    s_arrmul.get_c_code_hier(open("h_s_arr_mul5.c","w"))
    s_arrmul.get_c_code_flat(open("f_s_arr_mul5.c","w"))
    s_arrmul.get_v_code_hier(open("h_s_arr_mul5.v","w"))
    s_arrmul.get_v_code_flat(open("f_s_arr_mul5.v","w"))
    s_arrmul.get_c_code_hier(open("h_s_arr_mul5.c","w"))
    s_arrmul.get_c_code_flat(open("f_s_arr_mul5.c","w"))
    s_arrmul.get_v_code_hier(open("h_s_arr_mul5.v","w"))
    s_arrmul.get_v_code_flat(open("f_s_arr_mul5.v","w"))
    

    #u_arrmul.get_v_code_hier(open("h_u_arr_mul3.v","w"))
    #s_arrmul.get_v_code_hier(open("h_s_arr_mul3.v","w"))

    """
    arrmul.get_c_code_hier(open("h_s_arr_mul6.c","w"))
    arrmul.get_c_code_flat(open("ff_s_arr_mul6.c","w"))
    arrmul.get_c_code_hier(open("h_s_arr_mul6.c","w"))
    arrmul.get_c_code_flat(open("ff_s_arr_mul6.c","w"))
    """


    """
    rca.get_v_code_hier(open("h_s_rca8.v", "w"))
    rca.get_v_code_flat(open("f_s_rca8.v", "w"))    

    rca.get_c_code_hier(open("h_s_rca2.c", "w"))
    rca.get_v_code_hier(open("h_s_rca2.v", "w"))
    rca.get_c_code_flat(open("f_s_rca2.c", "w"))
    rca.get_v_code_flat(open("f_s_rca2.v", "w"))
    """
    #rca.get_v_code_hier(open("h_u_rca3.v", "w"))
    #rca.get_c_code_flat(open("f_u_rca3.c", "w"))
    
    
    #rca.get_c_code_hier(open("hier_srca8.c", "w"))
    #rca.get_c_code_flat(open("flat_srca8.c", "w"))

    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cin")
    ha = half_adder(w1, w2, prefix="f_ha")
    fa = full_adder(w1, w2, w3, prefix="f_fa")

    #ha.get_cgp_code(open("ha.chr","w"))
    #fa.get_cgp_code(open("fa.chr","w"))

    """
    ha.get_c_code_flat(open("f_ha.c","w"))
    ha.get_v_code_flat(open("f_ha.v","w"))
    fa.get_c_code_flat(open("f_fa.c","w"))
    fa.get_v_code_hier(open("f_fa.v","w"))
    """

    ha.get_v_code_hier(open("h_ha.v","w"))
    fa.get_v_code_hier(open("h_fa.v","w"))

    """
    ha.get_c_code_hier(open("h_ha.c","w"))
    ha.get_c_code_flat(open("f_ha.c","w"))
    ha.get_c_code_hier(open("h_ha.c","w"))
    ha.get_c_code_flat(open("f_ha.c","w"))

    fa.get_c_code_hier(open("h_fa.c","w"))
    fa.get_c_code_flat(open("f_fa.c","w"))
    fa.get_c_code_hier(open("h_fa.c","w"))
    fa.get_c_code_flat(open("f_fa.c","w"))
    
    ha.get_v_code_hier(open("h_ha.v","w"))
    ha.get_v_code_flat(open("f_ha.v","w"))
    ha.get_v_code_hier(open("h_ha.v","w"))
    ha.get_v_code_flat(open("f_ha.v","w"))

    fa.get_v_code_hier(open("h_fa.v","w"))
    fa.get_v_code_flat(open("f_fa.v","w"))
    fa.get_v_code_hier(open("h_fa.v","w"))
    fa.get_v_code_flat(open("f_fa.v","w"))
    """

    gate = and_gate(w1, w2)
    #gate.get_cgp_code(open("and_gate.chr","w"))
    #gate.get_c_code(open("and_gate.c","w"))
    #gate.get_v_code(open("and_gate.v","w"))
    