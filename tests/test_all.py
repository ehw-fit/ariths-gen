
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

import numpy as np


def test_unsigned_approxmul(values = False):
    """ Test unsigned approximate multipliers """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N)
    bv = av.reshape(-1, 1)
    expected = av * bv
    
    for c in [UnsignedBrokenArrayMultiplier, UnsignedTruncatedMultiplier]:    
        if c == UnsignedTruncatedMultiplier:
            mul = c(a=a, b=b, truncation_cut=2)
        elif c == UnsignedBrokenArrayMultiplier:
            mul = c(a=a, b=b, horizontal_cut=1, vertical_cut=2)
    r = mul(av, bv)
    
    # WCE – worst case error; used for approximate multiplier error measurement
    WCE = np.amax(abs(np.subtract(r, expected)))
    
    # WCRE – worst case relative error; used for approximate multiplier error measurement
    np.seterr(divide='ignore', invalid='ignore')
    WCRE = np.max(np.nan_to_num(abs(np.subtract(r, expected)) / expected))
    
    if isinstance(mul, UnsignedTruncatedMultiplier):
        # WCE_TM(n,k) = (2^k - 1) * (2^(n+1) - 2^k - 1)
        expected_WCE = (2 ** mul.truncation_cut - 1) * (2 ** (mul.a.N+1) - 2 ** mul.truncation_cut - 1)
    elif isinstance(mul, UnsignedBrokenArrayMultiplier):
        # WCE_BAM(n,h,v) = (2^n - 1) * {SUM_i0_to_h-1}(2^i) + 2^h * {SUM_i0_to_v-h-1}(2^(v-h) - 2^i)
        sum_1 = sum([2**i for i in range(0, mul.horizontal_cut)])
        sum_2 = sum([2**(mul.vertical_cut-mul.horizontal_cut) - 2**i for i in range(0, mul.vertical_cut-mul.horizontal_cut)])
        expected_WCE = (2 ** mul.N - 1) * sum_1 + 2 ** mul.horizontal_cut * sum_2

    # Test expected result
    assert expected_WCE == WCE
    if values is True:
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
        assert mul(0, 0) == 0
        r = mul(av, bv)
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
        r = mul(av, bv)
        assert mul(0, 0) == 0

        # r[r >= 2**(2*N-1)] -= 2**(2*N)  # hack!!! two's complement not implemented yet
        np.testing.assert_array_equal(expected, r)



def test_unsigned_add():
    """ Test unsigned adders """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N)
    bv = av.reshape(-1, 1)
    expected = av + bv

    for c in [UnsignedCarryLookaheadAdder, UnsignedPGRippleCarryAdder, UnsignedRippleCarryAdder, UnsignedCarrySkipAdder]:
        mul = c(a, b)
        r = mul(av, bv)
        np.testing.assert_array_equal(expected, r)



def test_signed_add():
    """ Test signed adders """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(-(2**(N-1)), 2**(N-1))
    bv = av.reshape(-1, 1)
    expected = av + bv

    for c in [SignedCarryLookaheadAdder, SignedPGRippleCarryAdder, SignedRippleCarryAdder, SignedCarrySkipAdder]:
        mul = c(a, b)
        r = mul(av, bv)
        # r[r >= 2**(N)] -= 2**(N+1)   # hack!!! two's complement not implemented yet
        np.testing.assert_array_equal(expected, r)


def test_mac():
    class MAC(GeneralCircuit):
        def __init__(self, a: Bus, b: Bus, r: Bus, prefix: str = "", name: str = "mac", **kwargs):
            super().__init__(prefix=prefix, name=name, out_N=2*a.N+1, inputs=[a, b, r], **kwargs)
            assert a.N == b.N
            assert r.N == 2 * a.N

            self.mul = self.add_component(UnsignedArrayMultiplier(a=a, b=b, prefix=self.prefix, name=f"u_arrmul{a.N}", inner_component=True))
            self.add = self.add_component(UnsignedRippleCarryAdder(a=r, b=self.mul.out, prefix=self.prefix, name=f"u_rca{r.N}", inner_component=True))
            self.out.connect_bus(connecting_bus=self.add.out)

    # usage
    mymac = MAC(Bus("a", 4), Bus("b", 4), Bus("acc", 8))

    av = np.arange(2**4)
    bv = np.arange(2**4).reshape(-1, 1)
    cv = np.arange(2**8).reshape(-1, 1, 1)

    r = mymac(av, bv, cv)
    expected = (av * bv) + cv
    np.testing.assert_array_equal(r, expected)