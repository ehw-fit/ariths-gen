import os
import sys
# Add the parent directory to the system path
DIR_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(DIR_PATH, '..'))

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits import GeneralCircuit

from ariths_gen.multi_bit_circuits.others import (
    PopCountCompare
)

from ariths_gen.core.cgp_circuit import UnsignedCGPCircuit, SignedCGPCircuit


import numpy as np
import math
from io import StringIO

from itertools import product

def test_popcountcompare_same(verbose: bool = False):
    N = 10

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")

    test_cases = list(product(list(range(2**N)), repeat=2))
    all = np.array(test_cases)

    if verbose:
        print(all)

    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))

    if verbose:
        print(cnta)
        print(cntb)

    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)

    if verbose:
        print("ret = ", v)

    expected = np.array(cnta >= cntb).astype(int)

    if verbose:
        print("expected = ", expected)

    #expected = np.sum(r, axis=1)
    np.testing.assert_array_equal(v, expected)


def test_popcountcompare_small(verbose: bool = False):
    N = 10

    a = Bus(N=N, prefix="a")
    b = Bus(N=N // 2, prefix="b")

    test_cases = list(product(range(2**N), range(2**(N//2))))
    all = np.array(test_cases)

    if verbose:
        print(all)

    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))

    if verbose:
        print(cnta)
        print(cntb)

    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)

    if verbose:
        print("ret = ", v)

    expected = np.array(cnta >= cntb).astype(int)

    if verbose:
        print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)
    np.testing.assert_array_equal(v, expected)


def test_popcountcompare_small2(verbose: bool = False):
    N = 10

    a = Bus(N=N // 2, prefix="a")
    b = Bus(N=N, prefix="b")

    test_cases = list(product( range(2**(N//2)), range(2**N)))
    all = np.array(test_cases)

    if verbose:
        print(all)

    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))

    if verbose:
        print(cnta)
        print(cntb)

    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)

    if verbose:
        print("ret = ", v)

    expected = np.array(cnta >= cntb).astype(int)

    if verbose:
        print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)
    np.testing.assert_array_equal(v, expected)


def test_popcountcompare_small2_cgp(verbose: bool = False):
    N = 10

    a = Bus(N=N // 2, prefix="a")
    b = Bus(N=N, prefix="b")

    test_cases = list(product( range(2**(N//2)), range(2**N)))
    all = np.array(test_cases)

    if verbose:
        print(all)

    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))

    if verbose:
        print(cnta)
        print(cntb)

    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))

    o = StringIO()
    cmp.get_cgp_code_flat(o)
    cgp = UnsignedCGPCircuit(o.getvalue(), [N//2, N])

    v = cgp(av, bv)

    if verbose:
        print("ret = ", v)

    expected = np.array(cnta >= cntb).astype(int)

    if verbose:
        print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)
    np.testing.assert_array_equal(v, expected)


if __name__ == "__main__":
    test_popcountcompare_same()
    test_popcountcompare_small()
    test_popcountcompare_small2()
    test_popcountcompare_small2_cgp()
    print("Python popcount_compare tests were successful!")
