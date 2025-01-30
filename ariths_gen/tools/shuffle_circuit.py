



from io import StringIO
from ..wire_components import (

    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ..core.arithmetic_circuits import GeneralCircuit
from ..core.cgp_circuit import UnsignedCGPCircuit

from ..one_bit_circuits.logic_gates import (
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)
import re
import random

class ShuffleCircuit(UnsignedCGPCircuit):

    @staticmethod
    def from_circuit(circuit: GeneralCircuit, strategy = "random"):
        o = StringIO()
        circuit.get_cgp_code_flat(o)

        cgp = o.getvalue()
        return ShuffleCircuit(code=cgp.strip(), strategy=strategy, input_widths=[i.N for i in circuit.inputs])
    

    def __init__(self, code: str = "", strategy = "random", input_widths: list = None, inputs: list = None, prefix: str = "", name: str = "cgp", **kwargs):
        """
        Initializes the CGP (Cartesian Genetic Programming) circuit by parsing the provided code and setting up the inputs, 
        internal nodes, and outputs. The circuit is shuffled and maintained as an acyclic forward graph.
        Args:
            code (str): The CGP code string defining the circuit structure.
            input_widths (list): List of widths for each input bus.
            strategy: random, min or max
            inputs (list): List of input Bus objects.
            prefix (str): Prefix for naming components.
            name (str): Name of the circuit.
            **kwargs: Additional keyword arguments for the GeneralCircuit initialization.
        Raises:
            AssertionError: If neither inputs nor input_widths are provided, or if both are provided.
            ValueError: If there are backward or loop connections in the CGP genes, or if output connections are out of range.
        """

        cgp_prefix, cgp_core, cgp_outputs = re.match(
            r"{(.*)}(.*)\(([^()]+)\)", code).groups()

        c_in, c_out, c_rows, c_cols, c_ni, c_no, c_lback = map(
            int, cgp_prefix.split(","))
        
        assert inputs is not None or input_widths is not None, "Either inputs or input_widths must be provided"

        if inputs:
            assert input_widths is None, "Only one of inputs or input_widths must be provided"

            input_widths =[i.N for i in inputs]
            assert sum(input_widths) == c_in, f"CGP input width {c_in} doesn't match inputs {inputs_widths}"



        else:

            assert sum(
                input_widths) == c_in, f"CGP input width {c_in} doesn't match input_widths {input_widths}"
            
            def get_name(i):
                if i < 26:
                    return chr(i + 0x61)
                assert i < 26 * 26
                return chr(i // 26 + 0x60) + chr(i % 26 + 0x61)

            inputs = [Bus(N=bw, prefix=f"input_{get_name(i)}")
                    for i, bw in enumerate(input_widths)]

            # Assign each Bus object in self.inputs to a named attribute of self
            for bus in inputs:
                # Here, bus.prefix is 'input_a', 'input_b', etc.
                # We strip 'input_' and use the remaining part (e.g., 'a', 'b') to create the attribute name
                attr_name = bus.prefix.replace('input_', '')
                setattr(self, attr_name, bus)

        # Adding values to the list
        self.vals = {}
        j = 2  # Start from two, 0=False, 1=True
        for iid, bw in enumerate(input_widths):
            for i in range(bw):
                assert j not in self.vals
                self.vals[j] = inputs[iid].get_wire(i)
                j += 1

        GeneralCircuit.__init__(self, prefix=prefix, name=name, out_N=c_out, inputs=inputs, **kwargs)

        if not code:
            return # only for getting the name
        
        cgp_core = cgp_core.split(")(")



        i = 0

        values = []
        for definition in cgp_core:
            i, in_a, in_b, fn = map(int, re.match(
                r"\(?\[(\d+)\](\d+),(\d+),(\d+)\)?", definition).groups())

            if in_a > i or in_b > i:
                raise ValueError(f"Backward connection in CGP gene \"{definition}\", maxid = {i}")

            if in_a == i or in_b == i:
                raise ValueError(f"Loop connection in CGP gene: \"{definition}\", maxid = {i}")
            
            values.append((i, in_a, in_b, fn))

        connected = []
        disconnected = values.copy()

        to_connect = []

        while disconnected or to_connect:
            
            # get the values that can be connected
            disconnected2 = []
            for i, in_a, in_b, fn in disconnected:
                # pick the nodes that can be connected
                if fn in [8, 9] or (in_a in self.vals and fn in [0, 1]) or (in_a in self.vals and in_b in self.vals):
                    to_connect.append((i, in_a, in_b, fn))
                else:
                    disconnected2.append((i, in_a, in_b, fn))
            
            disconnected = disconnected2

            # print("To connect: ", to_connect)
            # print("Disconnected: ", disconnected)
            # print("Vals", self.vals.keys())
            # print("")


            if strategy == "random":
                # randomly pick one value from to_connect
                picked = random.choice(to_connect)
            elif strategy == "max":
                # select the value with the highest i
                picked = max(to_connect, key=lambda x: x[0])
            elif strategy == "min":
                # select the value with the lowest i
                picked = min(to_connect, key=lambda x: x[0])
            else:
                raise ValueError(f"Unknown strategy {strategy}, can be random, min or max")

            i, in_a, in_b, fn = picked

            to_connect.remove(picked)

            # remove the picked value from disconnected
            comp_set = dict(prefix=f"{self.prefix}_core_{i:03d}", parent_component=self)

            a = b = None

            if fn not in [8, 9]:
                a = self._get_wire(in_a)

                if fn not in [0, 1]:
                    b = self._get_wire(in_b)

            if fn == 0:  # IDENTITY
                o = a
            elif fn == 1:  # NOT
                o = self.add_component(NotGate(a, **comp_set)).out
            elif fn == 2:  # AND
                o = self.add_component(AndGate(a, b, **comp_set)).out
            elif fn == 3:  # OR
                o = self.add_component(OrGate(a, b, **comp_set)).out
            elif fn == 4:  # XOR
                o = self.add_component(XorGate(a, b, **comp_set)).out
            elif fn == 5:  # NAND
                o = self.add_component(NandGate(a, b, **comp_set)).out
            elif fn == 6:  # NOR
                o = self.add_component(NorGate(a, b, **comp_set)).out
            elif fn == 7:  # XNOR
                o = self.add_component(XnorGate(a, b, **comp_set)).out
            elif fn == 8:  # TRUE
                o = ConstantWireValue1()
            elif fn == 9:  # FALSE
                o = ConstantWireValue0()

            assert i not in self.vals
            self.vals[i] = o

        # print("Disconnected: ", disconnected)
        # print("vals: ", self.vals.keys())
        # Output connection
        for i, o in enumerate(map(int, cgp_outputs.split(","))):
            if o >= c_in + c_rows * c_cols + 2:
                raise ValueError(
                    f"Output {i} is connected to wire {o} which is not in the range of CGP wires ({c_in + c_rows * c_cols + 2})")
            w = self._get_wire(o)
            self.out.connect(i, w)

