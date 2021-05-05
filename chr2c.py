# Simple script for conversion of input CGP chromosome into output C code
# Script originally written by Vojtech Mrazek
# Modifications to suite the appropriate needs of ArithsGen made by Jan Klhufek
# Requires python2!
import sys
import re
import numpy as np


# Parse all nodes present in input CGP
def parse_node(n):
    return map(int, re.match(r"(\d+),(\d+),(\d+)", n).groups())


# Recursively detect wires required to get the result wire with id 'id' and activate them (will be generated)
def activate(id, act, c_in, cdata_dict):
    if act[id]:
        return 0

    act[id] = True

    conf = cdata_dict[id-(c_in+2)]
    if conf:
        _, a, b, f = conf
        activate(a, act, c_in, cdata_dict)
        if f != 0 and f != 1:  # Identity, NOT
            activate(b, act, c_in, cdata_dict)


# Declare new output logic gate's wire if it has not been declared yet (and then assign it the result of corresponding logical function)
# Or return previously declared wire (which is used as an input into corresponding logical function)
def get_sig(name, trans, create=False):
    if create is True and int(name) not in trans.keys():
        trans[name] = "sig_%d" % name
    return trans[name]


# Parse and convert the input CGP chromosome to output C code representation
if __name__ == "__main__":
    # Load input CGP
    f = open(sys.argv[1], "r")
    chrom = "\n".join([x for x in f])
    f.close()

    print "// ", sys.argv[1]

    # Splitting input representation into three parts
    preamble, data, outputs = re.match(r"\{(.*)\}\((.*)\)\(([^\)]+)\)", chrom).groups()
    # Parsing CGP preamble parameters
    c_in, c_out, c_rows, c_cols, c_ni, c_no, c_lback = map(int, preamble.split(","))
    # Parsing all present nodes
    cdata = map(parse_node, data.split(")("))

    # Parse position and corresponding information regarding each chromosome
    cdata_dict = [None for i in range(0, c_cols * c_rows)]

    for id, chromosome in enumerate(cdata):
        a = chromosome[0]
        b = chromosome[1]
        f = chromosome[2]

        cdata_dict[id] = (id + 2 + c_in, a, b, f)

    # Reserve position for all wires present in the genotype
    # Later used to detect if they need to be activated for obtaining the result
    act = [False for i in range(0, (2 + c_in + c_cols * c_rows))]
    # Reserved constant wires indexes
    act[0] = True
    act[1] = True

    # Obtaining all output wires (MSB to LSB)
    outs = map(int, outputs.split(","))
    # Recursively activate all (node) wires needed to obtain the corresponding result wire
    for o in outs:
        activate(o, act, c_in, cdata_dict)

    # Export converted input declarations into C code function header / body start
    print "#include <stdint.h>"
    print "uint64_t circuit%d(uint64_t a, uint64_t b) {" % (c_in / 2)
    print "  int wa[%d];" % (c_in/2)
    print "  int wb[%d];" % (c_in/2)
    print "  uint64_t y = 0;"

    # Export converted input assignments into C code function body
    trans = {}
    trans[0] = "0x00"
    trans[1] = "0x01"
    for i in range(0, (c_in/2)):
        trans[i+2] = "wa[%d]" % i
        print "  wa[%d] = (a >> %d) & 0x01;" % (i, i)
        trans[i + (c_in/2)+2] = "wb[%d]" % i
        print "  wb[%d] = (b >> %d) & 0x01;" % (i, i)

    # Lists representing individual nodes (lines), output wires (lines_end)
    lines = []
    lines_end = []

    # Export converted nodes into C code function body
    for dat, a in zip(cdata_dict, act):
        id, a, b, f = dat

        if f == 0:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = " + get_sig(a, trans) + ";")
        elif f == 1:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = !" + get_sig(a, trans) + ";")
        elif f == 2:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = " + get_sig(a, trans) + " & " + get_sig(b, trans) + ";")
        elif f == 3:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = " + get_sig(a, trans) + " | " + get_sig(b, trans) + ";")
        elif f == 4:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = " + get_sig(a, trans) + " ^ " + get_sig(b, trans) + ";")
        elif f == 5:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = ~(" + get_sig(a, trans) + " & " + get_sig(b, trans) + ") & 0x01;")
        elif f == 6:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = ~(" + get_sig(a, trans) + " | " + get_sig(b, trans) + ") & 0x01;")
        elif f == 7:
            lines.append("  uint8_t " + get_sig(id, trans, True) + " = ~(" + get_sig(a, trans) + " ^ " + get_sig(b, trans) + ") & 0x01;")

    # Export converted outputs into C code function body
    for i in range(0, c_out):
        if outs[i] in trans:
            lines_end.append("  y |=  (%s & 0x01) << %d; // default output" % (trans[outs[i]], (len(outs)-1) - i))
        else:
            assert False

    # Print final result return in C code function body and close it
    lines_end.append("   return y;")
    print "\n".join(lines + lines_end)
    print "}"
