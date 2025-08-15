
from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.multi_bit_circuits.adders import (
    UnsignedCarryLookaheadAdder,
    UnsignedPGRippleCarryAdder,
    UnsignedRippleCarryAdder,
    UnsignedCarrySkipAdder,
)

from ariths_gen.multi_bit_circuits.approximate_multipliers import (
    UnsignedTruncatedArrayMultiplier,
    UnsignedTruncatedCarrySaveMultiplier,
    UnsignedBrokenArrayMultiplier,
    UnsignedBrokenCarrySaveMultiplier
)

from ariths_gen.tools.pdk import set_pdk45_library
import os
from itertools import product


def open_file_with_folder(filename, mode):
    d = os.path.dirname(filename)
    if d:
        os.makedirs(d, exist_ok=True)
    return open(filename, mode)


if __name__ == "__main__":
    # Optional use HA and FA technology from pdk45 library
    # set_pdk45_library()

    # 8-bit unsigned BAMs
    root_path = "test_circuits/ax"

    adders = {UnsignedCarryLookaheadAdder: "cla", UnsignedPGRippleCarryAdder: "pg_rca", UnsignedRippleCarryAdder: "rca", UnsignedCarrySkipAdder: "cska"}

    i = 0
    for h in range(0, 8):
        # v <= (8-1) + (8-2)
        for v in range(h, 13):
            i += 1
            N = 8
            a = Bus(prefix="a", N=N)
            b = Bus(prefix="b", N=N)

            for bam in [UnsignedBrokenArrayMultiplier, UnsignedBrokenCarrySaveMultiplier]:
                if bam == UnsignedBrokenCarrySaveMultiplier:
                    for add_type in adders.keys():
                        flat_bam = bam(a, b, name=f"f_u_csabam{N}_{adders[add_type]}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v, unsigned_adder_class_name=add_type)
                        hier_bam = bam(a, b, name=f"h_u_csabam{N}_{adders[add_type]}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v, unsigned_adder_class_name=add_type)

                        flat_bam.get_c_code_flat(open_file_with_folder(os.path.join(root_path, f"BAM/C/flat/f_u_csabam{N}_{adders[add_type]}_h{h}_v{v}.c"), "w"))
                        flat_bam.get_v_code_flat(open_file_with_folder(os.path.join(root_path, f"BAM/Verilog/flat/f_u_csabam{N}_{adders[add_type]}_h{h}_v{v}.v"), "w"))
                        hier_bam.get_c_code_hier(open_file_with_folder(os.path.join(root_path, f"BAM/C/hier/h_u_csabam{N}_{adders[add_type]}_h{h}_v{v}.c"), "w"))
                        hier_bam.get_v_code_hier(open_file_with_folder(os.path.join(root_path, f"BAM/Verilog/hier/h_u_csabam{N}_{adders[add_type]}_h{h}_v{v}.v"), "w"))
                else:
                    flat_bam = bam(a, b, name=f"f_u_arrbam{N}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v)
                    hier_bam = bam(a, b, name=f"h_u_arrbam{N}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v)

                    flat_bam.get_c_code_flat(open_file_with_folder(os.path.join(root_path, f"BAM/C/flat/f_u_arrbam{N}_h{h}_v{v}.c"), "w"))
                    flat_bam.get_v_code_flat(open_file_with_folder(os.path.join(root_path, f"BAM/Verilog/flat/f_u_arrbam{N}_h{h}_v{v}.v"), "w"))
                    hier_bam.get_c_code_hier(open_file_with_folder(os.path.join(root_path, f"BAM/C/hier/h_u_arrbam{N}_h{h}_v{v}.c"), "w"))
                    hier_bam.get_v_code_hier(open_file_with_folder(os.path.join(root_path, f"BAM/Verilog/hier/h_u_arrbam{N}_h{h}_v{v}.v"), "w"))

    # 8-bit unsigned TMs
    for i in range(0, 8):
        N = 8
        a = Bus(prefix="a", N=N)
        b = Bus(prefix="b", N=N)

        for tm in [UnsignedTruncatedArrayMultiplier, UnsignedTruncatedCarrySaveMultiplier]:
            if tm == UnsignedTruncatedCarrySaveMultiplier:
                for add_type in adders.keys():
                    flat_tm = tm(a, b, name=f"f_u_csatm{N}_{adders[add_type]}_k{i}", truncation_cut=i, unsigned_adder_class_name=add_type)
                    hier_tm = tm(a, b, name=f"h_u_csatm{N}_{adders[add_type]}_k{i}", truncation_cut=i, unsigned_adder_class_name=add_type)

                    flat_tm.get_c_code_flat(open_file_with_folder(os.path.join(root_path, f"TM/C/flat/f_u_csatm{N}_{adders[add_type]}_k{i}.c"), "w"))
                    flat_tm.get_v_code_flat(open_file_with_folder(os.path.join(root_path, f"TM/Verilog/flat/f_u_csatm{N}_{adders[add_type]}_k{i}.v"), "w"))
                    hier_tm.get_c_code_hier(open_file_with_folder(os.path.join(root_path, f"TM/C/hier/h_u_csatm{N}_{adders[add_type]}_k{i}.c"), "w"))
                    hier_tm.get_v_code_hier(open_file_with_folder(os.path.join(root_path, f"TM/Verilog/hier/h_u_csatm{N}_{adders[add_type]}_k{i}.v"), "w"))
                else:
                    flat_tm = tm(a, b, name=f"f_u_arrtm{N}_k{i}", truncation_cut=i)
                    hier_tm = tm(a, b, name=f"h_u_arrtm{N}_k{i}", truncation_cut=i)

                    flat_tm.get_c_code_flat(open_file_with_folder(os.path.join(root_path, f"TM/C/flat/f_u_arrtm{N}_k{i}.c"), "w"))
                    flat_tm.get_v_code_flat(open_file_with_folder(os.path.join(root_path, f"TM/Verilog/flat/f_u_arrtm{N}_k{i}.v"), "w"))
                    hier_tm.get_c_code_hier(open_file_with_folder(os.path.join(root_path, f"TM/C/hier/h_u_arrtm{N}_k{i}.c"), "w"))
                    hier_tm.get_v_code_hier(open_file_with_folder(os.path.join(root_path, f"TM/Verilog/hier/h_u_arrtm{N}_k{i}.v"), "w"))
