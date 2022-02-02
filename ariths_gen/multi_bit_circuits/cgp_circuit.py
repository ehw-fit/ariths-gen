
from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)

from ariths_gen.core.logic_gate_circuits import (
    MultipleInputLogicGate
)
from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    PGLogicBlock,
    FullAdder,
    FullAdderPG
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
    """ Circuit that loads CGP code and is able to export it to C/verilog/Blif/CGP """

    def __init__(self, code: str, input_widths: list, prefix: str = "", name: str = "cgp", **kwargs):

        cgp_prefix, cgp_core, cgp_outputs = re.match(
            r"{(.*)}(.*)\(([^()]+)\)", code).groups()

        c_in, c_out, c_rows, c_cols, c_ni, c_no, c_lback = map(
            int, cgp_prefix.split(","))
        print(cgp_core)
        print(cgp_outputs)

        assert sum(
            input_widths) == c_in, f"CGP input widht {c_in} doesn't match input_widhts {input_widths}"
        #assert c_rows == 1, f"Only one-row CGP is supported {c_rows}x{c_cols}"

        inputs = [Bus(N=bw, prefix=f"input_{chr(i)}")
                  for i, bw in enumerate(input_widths, start=0x61)]
        #vals = Bus(N=c_rows * c_cols, prefix=f"{prefix}_data")

        # adding values to the list
        self.vals = {}
        j = 2 # start from two, 0=false, 1 = true
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

            assert in_a < i
            assert in_b < i
            comp_set = dict(prefix=f"{self.prefix}_core_{i:03d}", parent_component=self)

            a, b = self._get_wire(in_a), self._get_wire(in_b)
            if fn == 0: # identity
                o = a
            elif fn == 1: # not
                o = self.add_component(NotGate(a, **comp_set)).out
            elif fn == 2: # and
                o = self.add_component(AndGate(a, b, **comp_set)).out
            elif fn == 3: # or
                o = self.add_component(OrGate(a, b, **comp_set)).out
            elif fn == 4: # xor
                o = self.add_component(XorGate(a, b, **comp_set)).out
            elif fn == 5: # nand
                o = self.add_component(NandGate(a, b, **comp_set)).out
            elif fn == 6: # nor
                o = self.add_component(NorGate(a, b, **comp_set)).out
            elif fn == 7: # xnor
                o = self.add_component(XnorGate(a, b, **comp_set)).out
            elif fn == 8: # true
                o = ConstantWireValue1()
            elif fn == 9: # false
                o = ConstantWireValue0()

            assert i not in self.vals
            self.vals[i] = o

        # output connection
        for i, o in enumerate(map(int, cgp_outputs.split(","))):
            w = self._get_wire(o)
            #print(i, o, w, w.name)
            self.out.connect(i, w)

    def _get_wire(self, i):
        if i == 0:
            return ConstantWireValue0()
        if i == 1:
            return ConstantWireValue1()
        return self.vals[i]

        #self.mul = self.add_component(UnsignedArrayMultiplier(a=a, b=b, prefix=self.prefix, name=f"u_arrmul{a.N}", inner_component=True))
        #self.add = self.add_component(UnsignedRippleCarryAdder(a=r, b=self.mul.out, prefix=self.prefix, name=f"u_rca{r.N}", inner_component=True))
        # self.out.connect_bus(connecting_bus=self.add.out)

class SignedCGPCircuit(UnsignedCGPCircuit):
    def __init__(self, code: str, input_widths: list, prefix: str = "", name: str = "cgp", **kwargs):
        super().__init__(code=code, input_widths=input_widths, prefix=prefix, name=name, signed=True, **kwargs)
        self.c_data_type = "int64_t"