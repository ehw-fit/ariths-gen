from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
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

from ariths_gen.one_bit_circuits.one_bit_components import (
    HalfAdder,
    FullAdder,
    PGLogicBlock,
    FullAdderPG,
    TwoOneMultiplexer,
    HalfSubtractor,
    FullSubtractor
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
)

from ariths_gen.multi_bit_circuits.multipliers import (
    UnsignedDaddaMultiplier,
    UnsignedArrayMultiplier,
    UnsignedWallaceMultiplier,
    SignedArrayMultiplier,
    SignedDaddaMultiplier,
    SignedWallaceMultiplier,
)

from ariths_gen.multi_bit_circuits.dividers import (
    ArrayDivider
)
import sys
import os


def prepare_directory(path):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    return open(path, "w")

def export_circuit(circuit, name):
    directory = "test_circuits"

    print(f"# exporting {name}")

    circuit.get_v_code_flat(prepare_directory(f"{directory}/verilog_circuits/flat/{name}.v"))
    circuit.get_v_code_hier(prepare_directory(f"{directory}/verilog_circuits/hier/{name}.v"))
    circuit.get_c_code_hier(prepare_directory(f"{directory}/c_circuits/hier/{name}.c"))
    circuit.get_c_code_flat(prepare_directory(f"{directory}/c_circuits/flat/{name}.c"))
    circuit.get_blif_code_hier(prepare_directory(f"{directory}/blif_circuits/hier/{name}.blif"))
    circuit.get_blif_code_flat(prepare_directory(f"{directory}/blif_circuits/flat/{name}.blif"))
    circuit.get_cgp_code_flat(prepare_directory(f"{directory}/cgp_circuits/flat/{name}.cgp"))


""" Generation of circuits """
if __name__ == "__main__":
    for N in [8]:
        a = Bus(N=N, prefix="a")
        b = Bus(N=N, prefix="b")

        representation = "h"

        # RCA
        name = f"u_rca{N}"
        circuit = UnsignedRippleCarryAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_rca{N}"
        circuit = SignedRippleCarryAdder(a, b, name=name)
        export_circuit(circuit, name)

        # RCA with PG
        name = f"u_pg_rca{N}"
        circuit = UnsignedPGRippleCarryAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_pg_rca{N}"
        circuit = SignedPGRippleCarryAdder(a, b, name=name)
        export_circuit(circuit, name)

        # CSKA with 4 bit CSKA blocks (default)
        name = f"u_cska{N}"
        circuit = UnsignedCarrySkipAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_cska{N}"
        circuit = SignedCarrySkipAdder(a, b, name=name)
        export_circuit(circuit, name)

        # CLA with 4 bit CLA blocks (default)
        name = f"u_cla{N}"
        circuit = UnsignedCarryLookaheadAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_cla{N}"
        circuit = SignedCarryLookaheadAdder(a, b, name=name)
        export_circuit(circuit, name)

        # Arrmul
        name = f"u_arrmul{N}"
        circuit = UnsignedArrayMultiplier(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_arrmul{N}"
        circuit = SignedArrayMultiplier(a, b, name=name)
        export_circuit(circuit, name)

        # Wallace
        name = f"u_wallace_cla{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_cla{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_rca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_rca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_pg_rca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_pg_rca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_cska{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_cska{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        # Dadda
        name = f"u_dadda_cla{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_cla{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_rca{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_rca{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_pg_rca{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_pg_rca{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_cska{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_cska{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        # Arrdiv
        name = f"arrdiv{N}"
        circuit = ArrayDivider(a, b, name=name)
        export_circuit(circuit, name)
