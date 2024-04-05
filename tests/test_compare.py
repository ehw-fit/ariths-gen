from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits import GeneralCircuit

from ariths_gen.multi_bit_circuits.others import (
    UnsignedCompareLT, UnsignedCompareLTE, UnsignedCompareGT, UnsignedCompareGTE
)

from ariths_gen.core.cgp_circuit import UnsignedCGPCircuit, SignedCGPCircuit


import numpy as np
import math
from io import StringIO


def test_compare_lt_same():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**N).reshape(-1, 1)


    cmp = UnsignedCompareLT(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av < bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    

def test_compare_lt_small():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N//2, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**(N //2)).reshape(-1, 1)


    cmp = UnsignedCompareLT(a=a, b=b)
    #o = StringIO()
    cmp.get_python_code_flat(open("tmp.py", "w"))
    cmp.get_c_code_flat(open("tmp.c", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))
    #cmp.get_v_code_hier(open("tmp.verilog", "w"))
    #print(o.getvalue())

#    av = 0
 #   bv = 5


    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av < bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    
def test_compare_lte_same():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**N).reshape(-1, 1)


    cmp = UnsignedCompareLTE(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av <= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    

def test_compare_lte_small():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N//2, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**(N //2)).reshape(-1, 1)


    cmp = UnsignedCompareLTE(a=a, b=b)
    #o = StringIO()
    cmp.get_python_code_flat(open("tmp.py", "w"))
    cmp.get_c_code_flat(open("tmp.c", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))
    #cmp.get_v_code_hier(open("tmp.verilog", "w"))
    #print(o.getvalue())

#    av = 0
 #   bv = 5


    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av <= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


def test_compare_lte_small2():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N//2, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**(N // 2)).reshape(1, -1)
    bv = np.arange(2**(N)).reshape(-1, 1)


    cmp = UnsignedCompareLTE(a=a, b=b)
    #o = StringIO()
    cmp.get_python_code_flat(open("tmp.py", "w"))
    cmp.get_c_code_flat(open("tmp.c", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))
    #cmp.get_v_code_hier(open("tmp.verilog", "w"))
    #print(o.getvalue())

#    av = 0
 #   bv = 5


    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av <= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


def test_compare_gt_same():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**N).reshape(-1, 1)


    cmp = UnsignedCompareGT(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av > bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    

def test_compare_gt_small():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N//2, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**(N //2)).reshape(-1, 1)


    cmp = UnsignedCompareGT(a=a, b=b)
    #o = StringIO()
    cmp.get_python_code_flat(open("tmp.py", "w"))
    cmp.get_c_code_flat(open("tmp.c", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))
    #cmp.get_v_code_hier(open("tmp.verilog", "w"))
    #print(o.getvalue())

#    av = 0
 #   bv = 5


    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av > bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    
def test_compare_gte_same():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**N).reshape(-1, 1)


    cmp = UnsignedCompareGTE(a=a, b=b)
    cmp.get_v_code_hier(open("tmp.verilog", "w"))

    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av >= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    

def test_compare_gte_small():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N//2, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**(N //2)).reshape(-1, 1)


    cmp = UnsignedCompareGTE(a=a, b=b)
    #o = StringIO()
    cmp.get_python_code_flat(open("tmp.py", "w"))
    cmp.get_c_code_flat(open("tmp.c", "w"))
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))
    #cmp.get_v_code_hier(open("tmp.verilog", "w"))
    #print(o.getvalue())

#    av = 0
 #   bv = 5


    v = cmp(av, bv)
    print("ret = ", v)

    expected = np.array(av >= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)



def test_compare_gte_cgp_same():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**N).reshape(-1, 1)


    cmp = UnsignedCompareGTE(a=a, b=b)
    o = StringIO()
    cmp.get_v_code_hier(open("tmp.verilog", "w"))
    cmp.get_cgp_code_flat(o)
    
    cgp = UnsignedCGPCircuit(o.getvalue(), [N, N])

    v = cgp(av, bv)
    print("ret = ", v)

    expected = np.array(av >= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)


    

def test_compare_gte_cgp_small():
    """ Test unsigned comparator """
    N = 8

    a = Bus(N=N, prefix="a")
    b = Bus(N=N//2, prefix="b")
    av = np.arange(2**N).reshape(1, -1)
    bv = np.arange(2**(N //2)).reshape(-1, 1)


    cmp = UnsignedCompareGTE(a=a, b=b)
    o = StringIO()
    cmp.get_v_code_flat(open("tmp.verilog", "w"))
    cmp.get_cgp_code_flat(o)
    cmp.get_cgp_code_flat(open("tmp.cgp", "w"))
    
    cgp = UnsignedCGPCircuit(o.getvalue(), [N, N // 2])

    v = cgp(av, bv)
    #cmp.get_v_code_hier(open("tmp.verilog", "w"))
    #print(o.getvalue())

#    av = 0
 #   bv = 5


    print("ret = ", v)

    expected = np.array(av >= bv).astype(int)

    print("expected = ", expected)
        
    #expected = np.sum(r, axis=1)

    np.testing.assert_array_equal(v, expected)