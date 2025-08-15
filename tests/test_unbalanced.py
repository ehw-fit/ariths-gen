
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

from ariths_gen.multi_bit_circuits.multipliers import (
    SignedArrayMultiplier,
    SignedDaddaMultiplier,
    SignedWallaceMultiplier,
    SignedCarrySaveMultiplier
)

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

def test_unbalanced_signed_multiplier():
    # Example usage

    for mult in [
        SignedDaddaMultiplier,
        SignedArrayMultiplier,
        SignedWallaceMultiplier,
        SignedCarrySaveMultiplier
    ]:
        a = Bus(N=5, prefix="a")
        b = Bus(N=4, prefix="b")
        multiplier = mult(a, b, prefix="sam")

        a_v = np.arange(-15, 16).reshape((-1, 1))
        b_v = np.arange(-7, 8).reshape((1, -1))
        # Test the multiplier circuit
        res = multiplier(a_v, b_v)
        exp = a_v * b_v
        print(res)
        print(res - exp)
        np.testing.assert_allclose(res, exp, rtol=1e-5, atol=1e-5, err_msg=f"Multiplier {mult.__name__} failed for unbalanced inputs a={a_v.shape}, b={b_v.shape}")
    

def test_unbalanced_signed_multiplier2():
    # Example usage

    for mult in [
        SignedDaddaMultiplier,
        SignedArrayMultiplier,
        SignedWallaceMultiplier,
        SignedCarrySaveMultiplier
    ]:
        a = Bus(N=4, prefix="a")
        b = Bus(N=5, prefix="b")
        multiplier = mult(a, b, prefix="sam")

        a_v = np.arange(-7, 8).reshape((-1, 1))
        b_v = np.arange(-15, 16).reshape((1, -1))
        # Test the multiplier circuit
        res = multiplier(a_v, b_v)
        exp = a_v * b_v
        print(res)
        print(res - exp)
        np.testing.assert_allclose(res, exp, rtol=1e-5, atol=1e-5, err_msg=f"Multiplier {mult.__name__} failed for unbalanced inputs a={a_v.shape}, b={b_v.shape}")


def test_unbalanced_signed_adder():
    # Example usage

    for adder in [
        SignedCarryLookaheadAdder,
        SignedPGRippleCarryAdder,
        SignedRippleCarryAdder,
        SignedCarrySkipAdder,
        SignedKoggeStoneAdder,
        SignedBrentKungAdder,
        SignedSklanskyAdder,
        SignedHanCarlsonAdder,
        SignedLadnerFischerAdder,
        SignedKnowlesAdder,
        SignedCarrySelectAdder,
        SignedConditionalSumAdder,
        SignedCarryIncrementAdder
    ]:
        a = Bus(N=5, prefix="a")
        b = Bus(N=4, prefix="b")
        adder_circuit = adder(a, b, prefix="scl")

        a_v = np.arange(-15, 16).reshape((-1, 1))
        b_v = np.arange(-7, 8).reshape((1, -1))
        # Test the adder circuit
        res = adder_circuit(a_v, b_v)
        exp = a_v + b_v
        print(res)
        print(res - exp)
        np.testing.assert_allclose(res, exp, rtol=1e-5, atol=1e-5, err_msg=f"Adder {adder.__name__} failed for unbalanced inputs a={a_v.shape}, b={b_v.shape}")
    
def test_unbalanced_signed_adder2():
    # Example usage

    for adder in [
        SignedCarryLookaheadAdder,
        SignedPGRippleCarryAdder,
        SignedRippleCarryAdder,
        SignedCarrySkipAdder,
        SignedKoggeStoneAdder,
        SignedBrentKungAdder,
        SignedSklanskyAdder,
        SignedHanCarlsonAdder,
        SignedLadnerFischerAdder,
        SignedKnowlesAdder,
        SignedCarrySelectAdder,
        SignedConditionalSumAdder,
        SignedCarryIncrementAdder
    ]:
        a = Bus(N=4, prefix="a")
        b = Bus(N=5, prefix="b")
        adder_circuit = adder(a, b, prefix="scl")

        a_v = np.arange(-7, 8).reshape((-1, 1))
        b_v = np.arange(-15, 16).reshape((1, -1))
        # Test the adder circuit
        res = adder_circuit(a_v, b_v)
        exp = a_v + b_v
        print(res)
        print(res - exp)
        np.testing.assert_allclose(res, exp, rtol=1e-5, atol=1e-5, err_msg=f"Adder {adder.__name__} failed for unbalanced inputs a={a_v.shape}, b={b_v.shape}")