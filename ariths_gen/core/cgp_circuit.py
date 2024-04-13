from ariths_gen.wire_components import (
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
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
import re


class UnsignedCGPCircuit(GeneralCircuit):
    """Unsigned circuit variant that loads CGP code and is able to export it to C/verilog/Blif/CGP."""

    def __init__(self, code: str, input_widths: list, prefix: str = "", name: str = "cgp", **kwargs):
        cgp_prefix, cgp_core, cgp_outputs = re.match(
            r"{(.*)}(.*)\(([^()]+)\)", code).groups()

        c_in, c_out, c_rows, c_cols, c_ni, c_no, c_lback = map(
            int, cgp_prefix.split(","))

        assert sum(
            input_widths) == c_in, f"CGP input width {c_in} doesn't match input_widths {input_widths}"

        inputs = [Bus(N=bw, prefix=f"input_{chr(i)}")
                  for i, bw in enumerate(input_widths, start=0x61)]

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

        super().__init__(prefix=prefix, name=name, out_N=c_out, inputs=inputs, **kwargs)
        cgp_core = cgp_core.split(")(")

        i = 0
        for definition in cgp_core:
            i, in_a, in_b, fn = map(int, re.match(
                r"\(?\[(\d+)\](\d+),(\d+),(\d+)\)?", definition).groups())

            if in_a > i or in_b > i:
                raise ValueError(f"Backward connection in CGP gene \"{definition}\", maxid = {i}")

            if in_a == i or in_b == i:
                raise ValueError(f"Loop connection in CGP gene: \"{definition}\", maxid = {i}")

            comp_set = dict(prefix=f"{self.prefix}_core_{i:03d}", parent_component=self)

            a, b = self._get_wire(in_a), self._get_wire(in_b)
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

        # Output connection
        for i, o in enumerate(map(int, cgp_outputs.split(","))):
            if o >= c_in + c_rows * c_cols + 2:
                raise ValueError(
                    f"Output {i} is connected to wire {o} which is not in the range of CGP wires ({c_in + c_rows * c_cols + 2})")
            w = self._get_wire(o)
            self.out.connect(i, w)

    @staticmethod
    def get_inputs_outputs(code: str):
        cgp_prefix, cgp_core, cgp_outputs = re.match(
            r"{(.*)}(.*)\(([^()]+)\)", code).groups()

        c_in, c_out, c_rows, c_cols, c_ni, c_no, c_lback = map(
            int, cgp_prefix.split(","))

        return c_in, c_out

    def _get_wire(self, i):
        if i == 0:
            return ConstantWireValue0()
        if i == 1:
            return ConstantWireValue1()
        try:
            return self.vals[i]
        except KeyError:

            raise KeyError(f"Key {i} not found in " + ", ".join(
                [f"{i}: {v}" for i, v in self.vals.items()]
            ))


class SignedCGPCircuit(UnsignedCGPCircuit):
    """Signed circuit variant that loads CGP code and is able to export it to C/verilog/Blif/CGP."""
    def __init__(self, code: str, input_widths: list, prefix: str = "", name: str = "cgp", **kwargs):
        super().__init__(code=code, input_widths=input_widths, prefix=prefix, name=name, signed=True, **kwargs)
        self.c_data_type = "int64_t"
