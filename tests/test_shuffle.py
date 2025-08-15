
from ariths_gen.multi_bit_circuits.multipliers import UnsignedArrayMultiplier
import numpy as np

from ariths_gen.tools.shuffle_circuit import ShuffleCircuit
from ariths_gen.wire_components import Bus
from io import StringIO


def test_shuffle_circuit():
    a = Bus(N=4, prefix="a")
    b = Bus(N=4, prefix="b")
    m = UnsignedArrayMultiplier(a, b, prefix="m")

    na = np.arange(0, 2**4).reshape(-1, 1)
    nb = np.arange(0, 2**4).reshape(1, -1)

    assert(np.all(m(na, nb) == na * nb))

    o = StringIO()
    m.get_cgp_code_flat(o)

    shuffled = ShuffleCircuit.from_circuit(m, strategy="random")
    assert(np.all(shuffled(na, nb) == na * nb))
    

def test_shuffle_cgp():
    a = Bus(N=4, prefix="a")
    b = Bus(N=4, prefix="b")
    m = UnsignedArrayMultiplier(a, b, prefix="m")

    na = np.arange(0, 2**4).reshape(-1, 1)
    nb = np.arange(0, 2**4).reshape(1, -1)

    assert(np.all(m(na, nb) == na * nb))

    o = StringIO()
    m.get_cgp_code_flat(o)

    cgp = o.getvalue()

    shuffled = ShuffleCircuit(code=cgp.strip(), input_widths=[4, 4])
    assert(np.all(shuffled(na, nb) == na * nb))

def test_shuffle_strategies():
    a = Bus(N=4, prefix="a")
    b = Bus(N=4, prefix="b")
    m = UnsignedArrayMultiplier(a, b, prefix="m")

    na = np.arange(0, 2**4).reshape(-1, 1)
    nb = np.arange(0, 2**4).reshape(1, -1)

    assert(np.all(m(na, nb) == na * nb))

    o = StringIO()
    m.get_cgp_code_flat(o)

    cgp = o.getvalue()

    shuffled = ShuffleCircuit(code=cgp.strip(), input_widths=[4, 4], strategy="min")
    assert(np.all(shuffled(na, nb) == na * nb))

    shuffled = ShuffleCircuit(code=cgp.strip(), input_widths=[4, 4], strategy="max")
    assert(np.all(shuffled(na, nb) == na * nb))

    shuffled = ShuffleCircuit(code=cgp.strip(), input_widths=[4, 4], strategy="random")
    assert(np.all(shuffled(na, nb) == na * nb))


if __name__ == "__main__":
    test_shuffle_cgp()
    test_shuffle_circuit()
    test_shuffle_strategies()