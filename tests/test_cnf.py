import os
import sys

# Add the parent directory to the system path
DIR_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(DIR_PATH, '..'))
import re

import numpy as np
import math
from io import StringIO
import tempfile

from ariths_gen.core.cgp_circuit import UnsignedCGPCircuit
from ariths_gen.core.arithmetic_circuits.general_circuit import GeneralCircuit

class minisat_runner:
    def __init__(self, circuit : GeneralCircuit):
        # create tmp name in temporary directory with unique name
        with tempfile.NamedTemporaryFile(delete=True, suffix=".cnf", dir="/tmp") as tmp_file:
            self.cnf_file = tmp_file.name

            # create cnf file
            circuit.get_cnf_code_flat(open(self.cnf_file, "w"))

            self.output = StringIO()
            self.run_minisat()
    
    def run_minisat(self):
        with tempfile.NamedTemporaryFile(delete=True, suffix=".out", dir="/tmp") as tmp_file:
            self.output = tmp_file
            self.retval = os.system(f"minisat {self.cnf_file} > {self.output.name}")
            
            self.output.seek(0)
            self.output = self.output.read().decode()
            return self.retval
    
    def get_output(self):
        return self.output
    
    def get_results(self):
        """ parses results in format
        
============================[ Problem Statistics ]=============================
|                                                                             |
|  Number of variables:             6                                         |
|  Number of clauses:               6                                         |
|  Parse time:                   0.00 s                                       |
|  Eliminated clauses:           0.00 Mb                                      |
|  Simplification time:          0.00 s                                       |
|                                                                             |
============================[ Search Statistics ]==============================
| Conflicts |          ORIGINAL         |          LEARNT          | Progress |
|           |    Vars  Clauses Literals |    Limit  Clauses Lit/Cl |          |
===============================================================================
===============================================================================
restarts              : 1
conflicts             : 0              (0 /sec)
decisions             : 1              (0.00 % random) (545 /sec)
propagations          : 4              (2181 /sec)
conflict literals     : 0              (-nan % deleted)
Memory used           : 11.00 MB
CPU time              : 0.001834 s

SATISFIABLE
        """
        ret = {"simplification": False}
        for line in self.output.split("\n"):
            if "SATISFIABLE" in line:
                ret["SATISFIABLE"] = True
            if "UNSATISFIABLE" in line:
                ret["SATISFIABLE"] = False
            if "Solved by simplification" in line:
                ret["simplification"] = True

            if g := re.match(r".*Number of variables:\s+(\d+)", line):
                ret["variables"] = int(g.groups()[0])
            if g := re.match(r".*Number of clauses:\s+(\d+)", line):
                ret["clauses"] = int(g.groups()[0])
            if g := re.match(r"\s*conflicts\s*:\s*(\d+)", line):
                ret["conflicts"] = int(g.groups()[0])
            if g := re.match(r"\s*decisions\s*:\s*(\d+)", line):
                ret["decisions"] = int(g.groups()[0])

        return ret


def test_cnf_minisat():
    # check optimization
    # a AND (NOT a)
    circ = UnsignedCGPCircuit("{4,1,1,8,2,1,0}([6]2,0,1)([7]2,6,2)([8]2,5,2)([9]8,7,4)([10]8,7,2)([11]3,5,2)([12]11,10,4)([13]11,10,2)(7)", [4])
    #circ = UnsignedCGPCircuit("{4,1,1,8,2,1,0}([6]2,3,2)([7]2,6,2)([8]2,5,2)([9]8,7,4)([10]8,7,2)([11]3,5,2)([12]11,10,4)([13]11,10,2)(7)", [4])
    runner = minisat_runner(circ)
    #print(runner.get_output())
    #print(runner.get_results())
    res = runner.get_results()
    assert res["simplification"]
    assert res["clauses"] == 0
    assert not res["SATISFIABLE"]

    
if __name__ == "__main__":
    test_cnf_minisat()
    print("CNF Python tests were successful!")
