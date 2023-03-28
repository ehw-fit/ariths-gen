"""
Testing the QuAdder
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

def test_quadder():
    c = QuAdder(Bus("a", 8), Bus("b", 8), R = [4, 2, 2], P=[0, 2, 2], prefix="quad")
    c.get_v_code_hier(file_object=sys.stdout)
    
    x = np.arange(0, 256).reshape(-1, 1)
    y = np.arange(0, 256).reshape(1, -1)

    r = c(x, y)
    r2 = x + y

    assert np.abs(r - r2).max() == 64
    np.testing.assert_equal(np.abs(r - r2).mean(), 7.5)