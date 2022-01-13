
from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.multi_bit_circuits.approximate_multipliers import (
    UnsignedTruncatedMultiplier,
    UnsignedBrokenArrayMultiplier
)

from ariths_gen.pdk import *
import os
from itertools import product

def open_file_with_folder(filename, mode):
    d = os.path.dirname(filename)
    if d:
        os.makedirs(d, exist_ok = True)
    return open(filename, mode)

if __name__ == "__main__":
    # Optional use HA and FA technology from pdk45 library
    #set_pdk45_library()
    
    # 8-bit unsigned BAMs
    root_path = "test_circuits/ax"

    i = 0
    for h in range(0, 8):
        # v <= (8-1) + (8-2)
        for v in range(h, 13):
            i += 1
            N=8
            a = Bus(prefix="a", N=N)
            b = Bus(prefix="b", N=N)
        
            u_bam = UnsignedBrokenArrayMultiplier(a, b, name=f"f_u_bam{N}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v)
            u_bam.get_c_code_flat(open_file_with_folder(os.path.join(root_path, f"BAM/C/flat/f_u_bam{N}_h{h}_v{v}.c"), "w"))
            u_bam.get_v_code_flat(open_file_with_folder(os.path.join(root_path, f"BAM/Verilog/flat/f_u_bam{N}_h{h}_v{v}.v"), "w"))

            u_bam = UnsignedBrokenArrayMultiplier(a, b, name=f"h_u_bam{N}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v)
            u_bam.get_c_code_hier(open_file_with_folder(os.path.join(root_path, f"BAM/C/hier/h_u_bam{N}_h{h}_v{v}.c"), "w"))
            u_bam.get_v_code_hier(open_file_with_folder(os.path.join(root_path, f"BAM/Verilog/hier/h_u_bam{N}_h{h}_v{v}.v"), "w"))

    # 8-bit unsigned TMs  
    for i in range(0, 8):
        N=8
        a = Bus(prefix="a", N=N)
        b = Bus(prefix="b", N=N)
    
        u_tm = UnsignedTruncatedMultiplier(a, b, name=f"f_u_tm{N}_k{i}", truncation_cut=i)
        u_tm.get_c_code_flat(open_file_with_folder(os.path.join(root_path, f"TM/C/flat/f_u_tm{N}_k{i}.c"), "w"))
        u_tm.get_v_code_flat(open_file_with_folder(os.path.join(root_path, f"TM/Verilog/flat/f_u_tm{N}_k{i}.v"), "w"))

        u_tm = UnsignedTruncatedMultiplier(a, b, name=f"h_u_tm{N}_k{i}", truncation_cut=i)
        u_tm.get_c_code_hier(open_file_with_folder(os.path.join(root_path, f"TM/C/hier/h_u_tm{N}_k{i}.c"), "w"))
        u_tm.get_v_code_hier(open_file_with_folder(os.path.join(root_path, f"TM/Verilog/hier/h_u_tm{N}_k{i}.v"), "w"))
