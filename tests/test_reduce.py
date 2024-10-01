import os
import sys
# Add the parent directory to the system path
DIR_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(DIR_PATH, '..'))

import numpy as np
import math
from io import StringIO

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits import GeneralCircuit

from ariths_gen.multi_bit_circuits.others import (
    BitReduce,
    AndReduce,
    OrReduce
)


def test_orreduce(verbose: bool = False):
    """ Test unsigned adders """
    N = 7

    for N in [3, 7, 8, 9, 16]:
        a = Bus(N=N, prefix="a")
        av = np.arange(2**N)

        reduce = OrReduce(a=a)
        o = StringIO()
        reduce.get_v_code_hier(o)

        if verbose:
            print(o.getvalue())

        #print(reduce(av))

        # conv to binary
        r = []
        a_s = av.copy()
        for i in range(N):
            r.append(a_s % 2)
            a_s = a_s // 2
        r = np.dstack(r).reshape(-1, N)

        if verbose:
            print("r = ", r)

        expected = np.bitwise_or.reduce(r, axis=1)
        
        if verbose:
            print("expected = ", expected)

        np.testing.assert_array_equal(reduce(av), expected)


def test_andreduce(verbose: bool = False):
    """ Test unsigned adders """
    N = 7

    for N in [3, 7, 8, 9, 16]:
        a = Bus(N=N, prefix="a")
        av = np.arange(2**N)

        reduce = AndReduce(a=a)
        o = StringIO()
        reduce.get_v_code_hier(o)

        if verbose:
            print(o.getvalue())

        #print(reduce(av))

        # conv to binary
        r = []
        a_s = av.copy()
        for i in range(N):
            r.append(a_s % 2)
            a_s = a_s // 2
        r = np.dstack(r).reshape(-1, N)

        if verbose:
            print("r = ", r)

        expected = np.bitwise_and.reduce(r, axis=1)

        if verbose:
            print("expected = ", expected)

        np.testing.assert_array_equal(reduce(av), expected)


if __name__ == "__main__":
    test_andreduce()
    test_orreduce()
    print("Python reduce tests were successful!")
