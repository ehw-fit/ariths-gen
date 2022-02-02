from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits import GeneralCircuit

from ariths_gen.multi_bit_circuits.adders import (
    UnsignedCarryLookaheadAdder,
    UnsignedPGRippleCarryAdder,
    UnsignedRippleCarryAdder,
    SignedCarryLookaheadAdder,
    SignedPGRippleCarryAdder,
    SignedRippleCarryAdder,
    UnsignedCarrySkipAdder,
    SignedCarrySkipAdder,
)

from ariths_gen.multi_bit_circuits.multipliers import (
    UnsignedDaddaMultiplier,
    UnsignedArrayMultiplier,
    UnsignedWallaceMultiplier,
    SignedArrayMultiplier,
    SignedDaddaMultiplier,
    SignedWallaceMultiplier,
)


from ariths_gen.multi_bit_circuits.approximate_multipliers import (
    UnsignedTruncatedMultiplier,
    SignedTruncatedMultiplier,
    UnsignedBrokenArrayMultiplier,
    SignedBrokenArrayMultiplier
)

from ariths_gen.multi_bit_circuits.cgp_circuit import UnsignedCGPCircuit, SignedCGPCircuit

import numpy as np
from io import StringIO

def test_cgp_unsigned_add():
    """ Test unsigned adders """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N)
    bv = av.reshape(-1, 1)
    expected = av + bv

    for c in [UnsignedCarryLookaheadAdder, UnsignedPGRippleCarryAdder, UnsignedRippleCarryAdder, UnsignedCarrySkipAdder]:
        add = c(a, b)
        code = StringIO()
        add.get_cgp_code_flat(code)
        cgp_code = code.getvalue()
        print(cgp_code)
        
        add2 = UnsignedCGPCircuit(cgp_code, [N, N])

        o = StringIO()
        add2.get_v_code_flat(o)
        print(o.getvalue())

        r = add2(av, bv)


        assert add(0, 0) == 0
        assert add2(0, 0) == 0

        np.testing.assert_array_equal(expected, r)


def test_cgp_signed_add():
    """ Test signed adders """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(-(2**(N-1)), 2**(N-1))
    bv = av.reshape(-1, 1)
    expected = av + bv

    for c in [SignedCarryLookaheadAdder, SignedPGRippleCarryAdder, SignedRippleCarryAdder, SignedCarrySkipAdder]:
        add = c(a, b)

        code = StringIO()
        add.get_cgp_code_flat(code)
        cgp_code = code.getvalue()
        print(cgp_code)

        add2 = SignedCGPCircuit(cgp_code, [N, N])
        r = add2(av, bv)

        assert add(0, 0) == 0
        assert add2(0, 0) == 0

        # r[r >= 2**(N)] -= 2**(N+1)   # hack!!! two's complement not implemented yet
        np.testing.assert_array_equal(expected, r)


def test_unsigned_mul():
    """ Test unsigned multipliers """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N)
    bv = av.reshape(-1, 1)
    expected = av * bv

    for c in [ UnsignedDaddaMultiplier, UnsignedArrayMultiplier, UnsignedWallaceMultiplier]:
        mul = c(a, b)
        code = StringIO()
        mul.get_cgp_code_flat(code)
        cgp_code = code.getvalue()

        mul2 = UnsignedCGPCircuit(cgp_code, [N, N])
        r = mul2(av, bv)

        np.testing.assert_array_equal(expected, r)

def test_signed_mul():
    """ Test signed multipliers """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(-(2**(N-1)), 2**(N-1))
    bv = av.reshape(-1, 1)
    expected = av * bv

    for c in [ SignedDaddaMultiplier, SignedArrayMultiplier, SignedWallaceMultiplier]:
        mul = c(a, b)
        code = StringIO()
        mul.get_cgp_code_flat(code)
        cgp_code = code.getvalue()

        mul2 = SignedCGPCircuit(cgp_code, [N, N])
        r = mul2(av, bv)

        np.testing.assert_array_equal(expected, r)

def test_cgp_variant1():
    # one input is connected to the output (first bit)
    cgp = "{16,9,37,1,2,1,0}([18]15,12,1)([19]7,7,4)([20]3,12,5)([21]17,3,0)([22]8,14,3)([23]15,3,6)([24]14,0,2)([25]9,9,5)([26]17,13,1)([27]12,13,0)([28]7,16,8)([29]12,11,0)([30]5,13,3)([31]5,13,2)([32]30,12,5)([33]30,29,2)([34]31,33,3)([35]6,14,4)([36]6,14,2)([37]35,34,4)([38]35,34,2)([39]36,38,3)([40]7,15,4)([41]7,15,2)([42]40,39,4)([43]40,39,2)([44]41,43,3)([45]8,16,4)([46]8,16,2)([47]45,44,4)([48]45,44,2)([49]46,48,3)([50]9,17,4)([51]9,17,2)([52]50,49,4)([53]50,49,2)([54]51,53,3)(11,40,33,32,37,42,47,52,54)"

    c = UnsignedCGPCircuit(cgp, [8, 8], name="cgp_circuit")
    assert c(0, 0) == 8 #  TypeError: 'int' object is not subscriptable