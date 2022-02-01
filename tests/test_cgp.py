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