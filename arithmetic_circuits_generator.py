from wire_components import wire, bus
from logic_gates import logic_gate, and_gate, nand_gate, or_gate, nor_gate, xor_gate, xnor_gate, not_gate
from one_bit_circuits import half_adder, full_adder
from multi_bit_circuits import unsigned_ripple_carry_adder, signed_ripple_carry_adder, unsigned_array_multiplier, signed_array_multiplier
import sys


""" TESTING """
if __name__ == "__main__":
    a = bus(N=10, prefix="a")
    b = bus(N=1, prefix="b")
    rca = unsigned_ripple_carry_adder(a, b, prefix="h_u_rca8")

    # rca.get_v_code_hier(open("h_u_rca8.v", "w"))
    # rca.get_c_code_hier(open("h_u_rca8.c", "w"))

    arrmul = unsigned_array_multiplier(a, b, prefix="f_u_arr_mul10")
    arrmul.get_c_code_flat(open("f_u_arr_mul10.c", "w"))
    arrmul.get_v_code_flat(open("f_u_arr_mul10.v", "w"))

    # arrmul.get_cgp_code_hier(open("s_arr_mul5.chr", "w"))
    # rca.get_cgp_code_hier(open("s_rca5.chr", "w"))

    w1 = wire(name="a")
    w2 = wire(name="b")
    w3 = wire(name="cin")

    ha = half_adder(w1, w2, prefix="f_ha")
    fa = full_adder(w1, w2, w3, prefix="f_fa")

    """
    ha.get_v_code_hier(open("h_ha.v","w"))
    ha.get_v_code_flat(open("f_ha.v","w"))
    ha.get_c_code_hier(open("h_ha.c","w"))
    ha.get_c_code_flat(open("f_ha.c","w"))
    ha.get_cgp_code(open("ha.chr","w"))
    """

    gate = and_gate(w1, w2)
    """
    #gate.get_c_code(open("and_gate.c","w"))
    #gate.get_v_code(open("and_gate.v","w"))
    #gate.get_cgp_code(open("and_gate.chr","w"))
    """
