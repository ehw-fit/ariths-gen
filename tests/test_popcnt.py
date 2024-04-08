import os
import sys
# Add the parent directory to the system path
DIR_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(DIR_PATH, '..'))

from io import StringIO
from ariths_gen.core.cgp_circuit import UnsignedCGPCircuit
from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits import GeneralCircuit

from ariths_gen.multi_bit_circuits.others import (
    UnsignedPopCount
)
import numpy as np


def test_popcount():
    """ Test unsigned adders """
    N = 7

    for N in [3, 7, 8, 9, 16]:
        a = Bus(N=N, prefix="a")
        av = np.arange(2**N)


        popcnt = UnsignedPopCount(a=a)
        #o = StringIO()
        #popcnt.get_v_code_hier(o)
        #print(o.getvalue())


        print(popcnt(av))


        # conv to binary
        r = []
        a_s = av.copy()
        for i in range(N):
            r.append(a_s % 2)
            a_s = a_s // 2
        r = np.dstack(r).reshape(-1, N)
        print("r = ", r)
        expected = np.sum(r, axis=1)

        np.testing.assert_array_equal(popcnt(av), expected)

def test_popcount_cgp():
    """ Test unsigned adders """
    N = 7

    for N in [3, 7, 8, 9, 16]:
        a = Bus(N=N, prefix="a")
        av = np.arange(2**N)


        popcnt = UnsignedPopCount(a=a)
        o = StringIO()
        popcnt.get_cgp_code_flat(o)
        cgp = UnsignedCGPCircuit(o.getvalue(), [N])
        v = cgp(av)


        print(popcnt(av))


        # conv to binary
        r = []
        a_s = av.copy()
        for i in range(N):
            r.append(a_s % 2)
            a_s = a_s // 2
        r = np.dstack(r).reshape(-1, N)
        print("r = ", r)
        expected = np.sum(r, axis=1)

        np.testing.assert_array_equal(v, expected)

