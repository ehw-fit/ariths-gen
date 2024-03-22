from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

from ariths_gen.core.arithmetic_circuits import GeneralCircuit

from ariths_gen.multi_bit_circuits.others import (
    BitReduce, AndReduce, OrReduce
)

import numpy as np
import math
from io import StringIO


def test_orreduce():
    """ Test unsigned adders """
    N = 7

    for N in [3, 7, 8, 9, 16]:
        a = Bus(N=N, prefix="a")
        av = np.arange(2**N)


        reduce = OrReduce(a=a)
        o = StringIO()
        reduce.get_v_code_hier(o)
        print(o.getvalue())


        #print(reduce(av))

        # conv to binary
        r = []
        a_s = av.copy()
        for i in range(N):
            r.append(a_s % 2)
            a_s = a_s // 2
        r = np.dstack(r).reshape(-1, N)
        print("r = ", r)
        expected = np.bitwise_or.reduce(r, axis=1)

        np.testing.assert_array_equal(reduce(av), expected)


def test_andreduce():
    """ Test unsigned adders """
    N = 7

    for N in [3, 7, 8, 9, 16]:
        a = Bus(N=N, prefix="a")
        av = np.arange(2**N)


        reduce = AndReduce(a=a)
        o = StringIO()
        reduce.get_v_code_hier(o)
        print(o.getvalue())


        #print(reduce(av))

        # conv to binary
        r = []
        a_s = av.copy()
        for i in range(N):
            r.append(a_s % 2)
            a_s = a_s // 2
        r = np.dstack(r).reshape(-1, N)
        print("r = ", r)
        expected = np.bitwise_and.reduce(r, axis=1)

        np.testing.assert_array_equal(reduce(av), expected)

    