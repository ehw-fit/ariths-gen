"""
This script generate the library of all possible QuAdders with N bits.
Note that the adders are not Pareto-optimal.
"""

from ariths_gen.core.arithmetic_circuits.arithmetic_circuit import ArithmeticCircuit
from ariths_gen.core.arithmetic_circuits import GeneralCircuit
from ariths_gen.wire_components import Bus, Wire
from ariths_gen.multi_bit_circuits.adders import UnsignedRippleCarryAdder
from ariths_gen.multi_bit_circuits.approximate_adders import QuAdder
from ariths_gen.multi_bit_circuits.multipliers import UnsignedArrayMultiplier, UnsignedDaddaMultiplier
import os, sys

import numpy as np
import itertools

if __name__ == "__main__":

    N = 8
    directory = f"lib_quad/lib_quad{N}"
    os.makedirs(directory, exist_ok=True)

    # generate the C code
    cfile = open(f"{directory}/lib_quad_{N}.c", "w")
    hfile = open(f"{directory}/lib_quad_{N}.h", "w")
    hfile.write("#include <stdint.h>\n")

    data = {}

    # verilog code is zipped
    import zipfile
    vfile = zipfile.ZipFile(file=f"{directory}/lib_quad_{N}.zip", mode="w", compression=zipfile.ZIP_DEFLATED)
    cnt = 0

    # up to 3 stages
    for n in [1, 2, 3]:
        Rall = list(itertools.product(range(1, N + 1), repeat=n))
        for R in Rall:
            # skip invalid R 
            if sum(R) != N:
                continue

            for P in itertools.product(range(0, N + 1), repeat=n):
                # test the condition from the paper
                if not all([P[i] < P[i-1] + R[i-1] for i in range(1, len(P))]):
                    continue
                print(cnt, R, P) # print the current configuration

                prefix = f"quad_{N}"
                name = "r_{}_p_{}".format("_".join([str(r) for r in R]), "_".join([str(p) for p in P]))
                
                try:
                    c = QuAdder(Bus("a", N), Bus("b", N), R = R, P=P, name=name, prefix=prefix, use_log=False)
                    c.get_c_code_flat(file_object=cfile)
                    vf = vfile.open(f"{prefix}_{name}.v", "w")
                    # convert byte file vf to text file
                    import io
                    vt = io.TextIOWrapper(vf, encoding="utf-8")
                    c.get_v_code_flat(file_object=vt)
                    vt.close()

                    cfile.write("\n\n")
                    hfile.write(f"uint64_t {prefix}_{name}(uint64_t a, uint64_t b);")

                    data[f"{name}_{prefix}"] = {
                        "bw": N,
                        "cfun": f"{prefix}_{name}",
                        "verilog": f"{prefix}_{name}.v",
                        "verilog_entity": f"{prefix}_{name}",
                        "quad_r" : R,
                        "quad_p" : P,
                    }
                    cnt += 1
                except IOError as e:
                    print(R, P, e)

# store the metadata
import json, gzip
json.dump(data, gzip.open(f"{directory}/lib_quad_{N}.json.gz", "wt"), indent=4)