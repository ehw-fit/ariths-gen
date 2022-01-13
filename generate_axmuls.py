
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


if __name__ == "__main__":
    # Use HA and FA technology from pdk45 library
    set_pdk45_library()
    
    # 8-bit unsigned BAMs
    paths = ["BrokenArrayMultiplier/C/flat", "BrokenArrayMultiplier/C/hier", "BrokenArrayMultiplier/Verilog/flat", "BrokenArrayMultiplier/Verilog/hier"]
    for path in paths:
        if not os.path.exists(path):
            os.makedirs(path)

    i = 0
    for h in range(0, 8):
        # v <= (8-1) + (8-2)
        for v in range(h, 13):
            i += 1
            N=8
            a = Bus(prefix="a", N=N)
            b = Bus(prefix="b", N=N)
        
            u_bam = UnsignedBrokenArrayMultiplier(a, b, name=f"f_u_bam{N}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v)
            u_bam.get_c_code_flat(file_object=open(f"BrokenArrayMultiplier/C/flat/f_u_bam{N}_h{h}_v{v}.c", "w"))
            u_bam.get_v_code_flat(file_object=open(f"BrokenArrayMultiplier/Verilog/flat/f_u_bam{N}_h{h}_v{v}.v", "w"))

            u_bam = UnsignedBrokenArrayMultiplier(a, b, name=f"h_u_bam{N}_h{h}_v{v}", horizontal_cut=h, vertical_cut=v)
            u_bam.get_c_code_hier(file_object=open(f"BrokenArrayMultiplier/C/hier/h_u_bam{N}_h{h}_v{v}.c", "w"))
            u_bam.get_v_code_hier(file_object=open(f"BrokenArrayMultiplier/Verilog/hier/h_u_bam{N}_h{h}_v{v}.v", "w"))

    # 8-bit unsigned TMs
    paths = ["TruncatedMultiplier/C/flat", "TruncatedMultiplier/C/hier", "TruncatedMultiplier/Verilog/flat", "TruncatedMultiplier/Verilog/hier"]
    for path in paths:
        if not os.path.exists(path):
            os.makedirs(path)
    
    for i in range(0, 8):
        N=8
        a = Bus(prefix="a", N=N)
        b = Bus(prefix="b", N=N)
    
        u_tm = UnsignedTruncatedMultiplier(a, b, name=f"f_u_tm{N}_k{i}", truncation_cut=i)
        u_tm.get_c_code_flat(file_object=open(f"TruncatedMultiplier/C/flat/f_u_tm{N}_k{i}.c", "w"))
        u_tm.get_v_code_flat(file_object=open(f"TruncatedMultiplier/Verilog/flat/f_u_tm{N}_k{i}.v", "w"))

        u_tm = UnsignedTruncatedMultiplier(a, b, name=f"h_u_tm{N}_k{i}", truncation_cut=i)
        u_tm.get_c_code_hier(file_object=open(f"TruncatedMultiplier/C/hier/h_u_tm{N}_k{i}.c", "w"))
        u_tm.get_v_code_hier(file_object=open(f"TruncatedMultiplier/Verilog/hier/h_u_tm{N}_k{i}.v", "w"))
