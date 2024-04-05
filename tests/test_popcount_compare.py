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

def test_popcountcompare_same():
    N = 10

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")

    test_cases = list(product(list(range(2**N)), repeat=2))
    all = np.array(test_cases)

    print(all)
    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))
    print(cnta)
    print(cntb)



    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)


    expected = np.array(cnta >= cntb).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


def test_popcountcompare_small():
    N = 10

    a = Bus(N=N, prefix="a")
    b = Bus(N=N // 2, prefix="b")

    test_cases = list(product(range(2**N), range(2**(N//2))))
    all = np.array(test_cases)

    print(all)
    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))


    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)


    expected = np.array(cnta >= cntb).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


def test_popcountcompare_small2():
    N = 10

    a = Bus(N=N // 2, prefix="a")
    b = Bus(N=N, prefix="b")

    test_cases = list(product( range(2**(N//2)), range(2**N)))
    all = np.array(test_cases)

    print(all)
    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))


    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)


    expected = np.array(cnta >= cntb).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)



def test_popcountcompare_small2_cgp():
    N = 10

    a = Bus(N=N // 2, prefix="a")
    b = Bus(N=N, prefix="b")

    test_cases = list(product( range(2**(N//2)), range(2**N)))
    all = np.array(test_cases)

    print(all)
    av = all[:, 0]
    bv = all[:, 1]
    def popcnt(x):
        mask = x & (2**np.arange(N)).reshape(-1, 1)
        return np.sum(mask > 0, axis=0)
    cnta = (popcnt(av))
    cntb = (popcnt(bv))


    cmp = PopCountCompare(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))

    o = StringIO()
    cmp.get_cgp_code_flat(o)
    cgp = UnsignedCGPCircuit(o.getvalue(), [N//2, N])

    v = cgp(av, bv)
    print("ret = ", v)


    expected = np.array(cnta >= cntb).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)
