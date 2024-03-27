import os
import sys
# Add the parent directory to the system path
DIR_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(DIR_PATH, '..'))
import numpy as np
import math

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
    UnsignedKoggeStoneAdder,
    SignedKoggeStoneAdder,
    UnsignedBrentKungAdder,
    SignedBrentKungAdder,
    UnsignedSklanskyAdder,
    SignedSklanskyAdder,
    UnsignedHanCarlsonAdder,
    SignedHanCarlsonAdder,
    UnsignedLadnerFischerAdder,
    SignedLadnerFischerAdder,
    UnsignedKnowlesAdder,
    SignedKnowlesAdder,
    UnsignedCarrySelectAdder,
    SignedCarrySelectAdder,
    UnsignedConditionalSumAdder,
    SignedConditionalSumAdder,
    UnsignedCarryIncrementAdder,
    SignedCarryIncrementAdder
)

from ariths_gen.multi_bit_circuits.multipliers import (
    UnsignedDaddaMultiplier,
    UnsignedArrayMultiplier,
    UnsignedWallaceMultiplier,
    UnsignedCarrySaveMultiplier,
    SignedArrayMultiplier,
    SignedDaddaMultiplier,
    SignedWallaceMultiplier,
    SignedCarrySaveMultiplier
)

from ariths_gen.multi_bit_circuits.approximate_multipliers import (
    UnsignedTruncatedArrayMultiplier,
    UnsignedTruncatedCarrySaveMultiplier,
    UnsignedBrokenArrayMultiplier,
    UnsignedBrokenCarrySaveMultiplier,
    UnsignedRecursiveMultiplier,
    UnsignedAccurateTwoBitMultiplier
)

from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)


def test_unsigned_approxmul(values=False):
    """ Test unsigned approximate multipliers """
    N = 7
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N)
    bv = av.reshape(-1, 1)
    expected = av * bv

    for c in [UnsignedBrokenArrayMultiplier, UnsignedBrokenCarrySaveMultiplier, UnsignedTruncatedArrayMultiplier, UnsignedTruncatedCarrySaveMultiplier]:
        if c == UnsignedTruncatedArrayMultiplier or c == UnsignedTruncatedCarrySaveMultiplier:
            mul = c(a=a, b=b, truncation_cut=2)
        elif c == UnsignedBrokenArrayMultiplier or c == UnsignedBrokenCarrySaveMultiplier:
            mul = c(a=a, b=b, horizontal_cut=1, vertical_cut=2)
    r = mul(av, bv)

    # WCE – worst case error; used for approximate multiplier error measurement
    WCE = np.amax(abs(np.subtract(r, expected)))

    # WCRE – worst case relative error; used for approximate multiplier error measurement
    np.seterr(divide='ignore', invalid='ignore')
    WCRE = np.max(np.nan_to_num(abs(np.subtract(r, expected)) / expected))

    if isinstance(mul, UnsignedTruncatedArrayMultiplier) or isinstance(mul, UnsignedTruncatedCarrySaveMultiplier):
        # WCE_TM(n,k) = (2^k - 1) * (2^(n+1) - 2^k - 1)
        expected_WCE = (2 ** mul.truncation_cut - 1) * (2 ** (mul.a.N+1) - 2 ** mul.truncation_cut - 1)
    elif isinstance(mul, UnsignedBrokenArrayMultiplier) or isinstance(mul, UnsignedBrokenCarrySaveMultiplier):
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

    # No configurability
    for c in [UnsignedArrayMultiplier]:
        mul = c(a, b)
        assert mul(0, 0) == 0
        r = mul(av, bv)
        np.testing.assert_array_equal(expected, r)
    
    # Accurate variant of recursive multiplier
    for c in [UnsignedRecursiveMultiplier]:
        N_rec = 8
        a_rec = Bus(N=N_rec, prefix="a")
        b_rec = Bus(N=N_rec, prefix="b")
        av_rec = np.arange(2**N_rec)
        bv_rec = av_rec.reshape(-1, 1)
        expected_rec = av_rec * bv_rec
        mul = c(a_rec, b_rec, submultipliers=[UnsignedAccurateTwoBitMultiplier for _ in range((N_rec//2)**2)])
        assert mul(0, 0) == 0
        r = mul(av_rec, bv_rec)
        np.testing.assert_array_equal(expected_rec, r)

    # Configurable PPA
    for c in [UnsignedDaddaMultiplier, UnsignedCarrySaveMultiplier, UnsignedWallaceMultiplier]:
        # Non configurable multi-bit adders
        for ppa in [UnsignedPGRippleCarryAdder, UnsignedRippleCarryAdder, UnsignedConditionalSumAdder, UnsignedKoggeStoneAdder, UnsignedBrentKungAdder, UnsignedSklanskyAdder]:
            # Test first the array wallace tree implementation (using more HAs/FAs than CSA implementation)
            if c == UnsignedWallaceMultiplier:
                mul = c(a, b, unsigned_adder_class_name=ppa, use_csa=False)
                assert mul(0, 0) == 0
                r = mul(av, bv)
                np.testing.assert_array_equal(expected, r)

            mul = c(a, b, unsigned_adder_class_name=ppa)
            assert mul(0, 0) == 0
            r = mul(av, bv)
            np.testing.assert_array_equal(expected, r)

        # Multi-bit adders with configurable (uniform) logic blocks for parallel prefix computation (the ppa will use the block_size argument it recognizes, others are ignored)
        for ppa in [UnsignedCarryLookaheadAdder, UnsignedCarrySkipAdder, UnsignedCarrySelectAdder, UnsignedCarryIncrementAdder]:
            for i in range(1, N+1):
                # Test first the array wallace tree implementation (using more HAs/FAs than CSA implementation)
                if c == UnsignedWallaceMultiplier:
                    mul = c(a, b, unsigned_adder_class_name=ppa, use_csa=False, cla_block_size=i, bypass_block_size=i, select_block_size=i, increment_block_size=i)
                    assert mul(0, 0) == 0
                    r = mul(av, bv)
                    np.testing.assert_array_equal(expected, r)

                mul = c(a, b, unsigned_adder_class_name=ppa, cla_block_size=i, bypass_block_size=i, select_block_size=i, increment_block_size=i)
                assert mul(0, 0) == 0
                r = mul(av, bv)
                np.testing.assert_array_equal(expected, r)

        # Multi-bit tree adders with configurable structure based on input bit width (NOTE for showcase here, the second config would be applicable from bit width 9 onward; not tested here for the sake of saving deployment testing time)
        for adder in [UnsignedHanCarlsonAdder, UnsignedKnowlesAdder, UnsignedLadnerFischerAdder]:
            for i in range(1, N+1):
                # Test first the array wallace tree implementation (using more HAs/FAs than CSA implementation)
                if c == UnsignedWallaceMultiplier:
                    mul = c(a, b, unsigned_adder_class_name=ppa, use_csa=False, config_choice=1)
                    assert mul(0, 0) == 0
                    r = mul(av, bv)
                    np.testing.assert_array_equal(expected, r)

                mul = c(a, b, unsigned_adder_class_name=ppa, config_choice=1)
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

    # No configurability
    for c in [SignedArrayMultiplier]:
        mul = c(a, b)
        assert mul(0, 0) == 0
        r = mul(av, bv)
        np.testing.assert_array_equal(expected, r)

    # Configurable PPA
    for c in [SignedDaddaMultiplier, SignedCarrySaveMultiplier, SignedWallaceMultiplier]:
        # Non configurable multi-bit adders
        for ppa in [UnsignedPGRippleCarryAdder, UnsignedRippleCarryAdder, UnsignedConditionalSumAdder, UnsignedKoggeStoneAdder, UnsignedBrentKungAdder, UnsignedSklanskyAdder]:
            # Test first the array wallace tree implementation (using more HAs/FAs than CSA implementation)
            if c == UnsignedWallaceMultiplier:
                mul = c(a, b, unsigned_adder_class_name=ppa, use_csa=False)
                assert mul(0, 0) == 0
                r = mul(av, bv)
                np.testing.assert_array_equal(expected, r)

            mul = c(a, b, unsigned_adder_class_name=ppa)
            assert mul(0, 0) == 0
            r = mul(av, bv)
            np.testing.assert_array_equal(expected, r)

        # Multi-bit adders with configurable (uniform) logic blocks for parallel prefix computation (the ppa will use the block_size argument it recognizes, others are ignored)
        for ppa in [UnsignedCarryLookaheadAdder, UnsignedCarrySkipAdder, UnsignedCarrySelectAdder, UnsignedCarryIncrementAdder]:
            for bs in range(1, N+1):
                # Test first the array wallace tree implementation (using more HAs/FAs than CSA implementation)
                if c == UnsignedWallaceMultiplier:
                    mul = c(a, b, unsigned_adder_class_name=ppa, use_csa=False, cla_block_size=bs, bypass_block_size=bs, select_block_size=bs, increment_block_size=bs)
                    assert mul(0, 0) == 0
                    r = mul(av, bv)
                    np.testing.assert_array_equal(expected, r)

                mul = c(a, b, unsigned_adder_class_name=ppa, cla_block_size=bs, bypass_block_size=bs, select_block_size=bs, increment_block_size=bs)
                assert mul(0, 0) == 0
                r = mul(av, bv)
                np.testing.assert_array_equal(expected, r)

        # Multi-bit tree adders with configurable structure based on input bit width (NOTE for showcase here, the second config would be applicable from bit width 9 onward; not tested here for the sake of saving deployment testing time)
        for adder in [UnsignedHanCarlsonAdder, UnsignedKnowlesAdder, UnsignedLadnerFischerAdder]:
            for i in range(1, N+1):
                # Test first the array wallace tree implementation (using more HAs/FAs than CSA implementation)
                if c == UnsignedWallaceMultiplier:
                    mul = c(a, b, unsigned_adder_class_name=ppa, use_csa=False, config_choice=1)
                    assert mul(0, 0) == 0
                    r = mul(av, bv)
                    np.testing.assert_array_equal(expected, r)

                mul = c(a, b, unsigned_adder_class_name=ppa, config_choice=1)
                assert mul(0, 0) == 0
                r = mul(av, bv)
                np.testing.assert_array_equal(expected, r)


def test_unsigned_add():
    """ Test unsigned adders """
    N = 9
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(2**N)
    bv = av.reshape(-1, 1)
    expected = av + bv

    # Non configurable multi-bit adders
    for c in [UnsignedPGRippleCarryAdder, UnsignedRippleCarryAdder, UnsignedConditionalSumAdder, UnsignedKoggeStoneAdder, UnsignedBrentKungAdder, UnsignedSklanskyAdder]:
        add = c(a, b)
        r = add(av, bv)
        np.testing.assert_array_equal(expected, r)

    # Multi-bit adders with configurable (uniform) logic blocks for parallel prefix computation (the adder will use the block_size argument it recognizes, others are ignored)
    for c in [UnsignedCarryLookaheadAdder, UnsignedCarrySkipAdder, UnsignedCarrySelectAdder, UnsignedCarryIncrementAdder]:
        for bs in range(1, N+1):
            add = c(a, b, cla_block_size=bs, bypass_block_size=bs, select_block_size=bs, increment_block_size=bs)
            r = add(av, bv)
            np.testing.assert_array_equal(expected, r)

    # Multi-bit tree adders with configurable structure based on input bit width (2 configs tested here for the 9-bitwidth input)
    for c in [UnsignedHanCarlsonAdder, UnsignedKnowlesAdder, UnsignedLadnerFischerAdder]:
        for config in range(1, (math.ceil(math.log(N, 2))-2)+1):
            add = c(a, b, config_choice=config)
            r = add(av, bv)
            np.testing.assert_array_equal(expected, r)


def test_signed_add():
    """ Test signed adders """
    N = 9
    a = Bus(N=N, prefix="a")
    b = Bus(N=N, prefix="b")
    av = np.arange(-(2**(N-1)), 2**(N-1))
    bv = av.reshape(-1, 1)
    expected = av + bv

    # Non configurable multi-bit adders
    for c in [SignedPGRippleCarryAdder, SignedRippleCarryAdder, SignedConditionalSumAdder, SignedKoggeStoneAdder, SignedBrentKungAdder, SignedSklanskyAdder]:
        add = c(a, b)
        r = add(av, bv)
        np.testing.assert_array_equal(expected, r)

    # Multi-bit adders with configurable (uniform) logic blocks for parallel prefix computation (the adder will use the block_size argument it recognizes, others are ignored)
    for c in [SignedCarryLookaheadAdder, SignedCarrySkipAdder, SignedCarrySelectAdder, SignedCarryIncrementAdder]:
        for bs in range(1, N+1):
            add = c(a, b, cla_block_size=bs, bypass_block_size=bs, select_block_size=bs, increment_block_size=bs)
            r = add(av, bv)
            np.testing.assert_array_equal(expected, r)

    # Multi-bit tree adders with configurable structure based on input bit width (2 configs tested here for the 9-bitwidth input)
    for c in [SignedHanCarlsonAdder, SignedKnowlesAdder, SignedLadnerFischerAdder]:
        for config in range(1, (math.ceil(math.log(N, 2))-2)+1):
            add = c(a, b, config_choice=config)
            r = add(av, bv)
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


def test_direct():
    class err_circuit(GeneralCircuit):
        def __init__(self, a: Bus = Bus(), b: Bus = Bus(), prefix: str = "", name: str = "adder", inner_component: bool = False):
            super().__init__(prefix=prefix, name=name, out_N=(a.N + 1), inner_component=inner_component, inputs=[a, b])
            self.N = 1
            self.prefix = prefix
            self.a = Bus(prefix=a.prefix, wires_list=a.bus)
            self.b = Bus(prefix=b.prefix, wires_list=b.bus)
            self.out = Bus(self.prefix+"_out", self.N+1)

            a_0 = self.a[0]
            b_0 = self.b.get_wire(0)

            or_1 = OrGate(a_0, b_0, prefix=self.prefix+"_or"+str(self.get_instance_num(cls=OrGate)), parent_component=self)
            self.add_component(or_1)

            self.out.connect(0, a_0)
            self.out.connect(1, or_1.out)

    av = np.arange(0, 4).reshape(1, -1)
    bv = np.arange(0, 4).reshape(-1, 1)
    example = err_circuit(prefix="err_circuit", a=Bus("a", 2), b=Bus("b", 2))

    r = example(av, bv)
    expected = np.array([[0, 3, 0, 3], [2, 3, 2, 3], [0, 3, 0, 3], [2, 3, 2, 3]])
    np.testing.assert_equal(r, expected)
    print(r)


def test_wire_as_bus():
    """ accept a wire as a bus """
    class test_circuit(GeneralCircuit):
        def __init__(self, a: Wire, b: Wire, c: Bus, prefix="test_circuit", **kwargs):
            super().__init__(prefix=prefix, name="test_circuit", inputs=[a, b, c], out_N=1, **kwargs)
            g = self.add_component(AndGate(a, b, prefix="g2"))
            g2 = self.add_component(AndGate(g.out, c[0], prefix="g2"))
            g3 = self.add_component(AndGate(g2.out, c[1], prefix="g2"))
            self.out[0] = g3.out

    circ = test_circuit(Wire("a"), Wire("b"), Bus("c", 2), "c1")
    r = circ(np.array([0, 1]),
             np.array([0, 1]).reshape(-1, 1),
             np.arange(4).reshape(-1, 1, 1))
    assert r.sum() == 1
    assert r[-1, -1, -1] == 1


if __name__ == "__main__":
    test_unsigned_approxmul()
    test_unsigned_mul()
    test_signed_mul()
    test_unsigned_add()
    test_signed_add()
    test_mac()
    test_direct()
    test_wire_as_bus()
    print("Python tests were successful!")
