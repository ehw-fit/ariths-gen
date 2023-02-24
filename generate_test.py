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

from ariths_gen.multi_bit_circuits.multipliers import (
    UnsignedDaddaMultiplier,
    UnsignedArrayMultiplier,
    UnsignedWallaceMultiplier,
    UnsignedCarrySaveMultiplier,
    SignedArrayMultiplier,
    SignedDaddaMultiplier,
    SignedWallaceMultiplier,
    SignedCarrySaveMultiplier
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

        """ ADDERS """
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

        # COSA
        name = f"u_cosa{N}"
        circuit = UnsignedConditionalSumAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_cosa{N}"
        circuit = SignedConditionalSumAdder(a, b, name=name)
        export_circuit(circuit, name)

        # CSKA with 4 bit CSKA blocks (default)
        name = f"u_cska{N}"
        circuit = UnsignedCarrySkipAdder(a, b, name=name, bypass_block_size=4)
        export_circuit(circuit, name)

        name = f"s_cska{N}"
        circuit = SignedCarrySkipAdder(a, b, name=name, bypass_block_size=4)
        export_circuit(circuit, name)

        # CLA with 4 bit CLA blocks (default)
        name = f"u_cla{N}"
        circuit = UnsignedCarryLookaheadAdder(a, b, name=name, cla_block_size=4)
        export_circuit(circuit, name)

        name = f"s_cla{N}"
        circuit = SignedCarryLookaheadAdder(a, b, name=name, cla_block_size=4)
        export_circuit(circuit, name)

        # CIA with 4 bit CIA blocks (default)
        name = f"u_cia{N}"
        circuit = UnsignedCarryIncrementAdder(a, b, name=name, increment_block_size=4)
        export_circuit(circuit, name)

        name = f"s_cia{N}"
        circuit = SignedCarryIncrementAdder(a, b, name=name, increment_block_size=4)
        export_circuit(circuit, name)

        # CSLA with 4 bit CIA blocks (default)
        name = f"u_csla{N}"
        circuit = UnsignedCarrySelectAdder(a, b, name=name, select_block_size=4)
        export_circuit(circuit, name)

        name = f"s_csla{N}"
        circuit = SignedCarrySelectAdder(a, b, name=name, select_block_size=4)
        export_circuit(circuit, name)

        # KSA
        name = f"u_ksa{N}"
        circuit = UnsignedKoggeStoneAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_ksa{N}"
        circuit = SignedKoggeStoneAdder(a, b, name=name)
        export_circuit(circuit, name)

        # BKA
        name = f"u_bka{N}"
        circuit = UnsignedBrentKungAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_bka{N}"
        circuit = SignedBrentKungAdder(a, b, name=name)
        export_circuit(circuit, name)

        # SA
        name = f"u_sa{N}"
        circuit = UnsignedSklanskyAdder(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_sa{N}"
        circuit = SignedSklanskyAdder(a, b, name=name)
        export_circuit(circuit, name)

        # HCA with config set to 1 (default)
        name = f"u_hca{N}"
        circuit = UnsignedHanCarlsonAdder(a, b, name=name, config_choice=1)
        export_circuit(circuit, name)

        name = f"s_hca{N}"
        circuit = SignedHanCarlsonAdder(a, b, name=name, config_choice=1)
        export_circuit(circuit, name)

        # KA with config set to 1 (default)
        name = f"u_ka{N}"
        circuit = UnsignedKnowlesAdder(a, b, name=name, config_choice=1)
        export_circuit(circuit, name)

        name = f"s_ka{N}"
        circuit = SignedKnowlesAdder(a, b, name=name, config_choice=1)
        export_circuit(circuit, name)

        # LFA with config set to 1 (default)
        name = f"u_lfa{N}"
        circuit = UnsignedLadnerFischerAdder(a, b, name=name, config_choice=1)
        export_circuit(circuit, name)

        name = f"s_lfa{N}"
        circuit = SignedLadnerFischerAdder(a, b, name=name, config_choice=1)
        export_circuit(circuit, name)

        """ MULTIPLIERS """
        # Arrmul
        name = f"u_arrmul{N}"
        circuit = UnsignedArrayMultiplier(a, b, name=name)
        export_circuit(circuit, name)

        name = f"s_arrmul{N}"
        circuit = SignedArrayMultiplier(a, b, name=name)
        export_circuit(circuit, name)

        # Csamul (Braun multiplier) – the ppa adders are also configurable as above if desirable
        name = f"u_csamul_cla{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_cla{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_rca{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_rca{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_pg_rca{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_pg_rca{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_cska{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_cska{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_cosa{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_cosa{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_cia{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_cia{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_csla{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_csla{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_ksa{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_ksa{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_bka{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_bka{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_sa{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_sa{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_hca{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_hca{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_ka{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_ka{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"u_csamul_lfa{N}"
        circuit = UnsignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        name = f"s_csamul_lfa{N}"
        circuit = SignedCarrySaveMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        # Wallace implemented with interconnected HAs/FAs – the ppa adders are also configurable as above if desirable
        name = f"u_wallace_cla{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_cla{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_rca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_rca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_pg_rca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_pg_rca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_cska{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_cska{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_cosa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_cosa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_cia{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_cia{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_csla{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_csla{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_ksa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_ksa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_bka{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_bka{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_sa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_sa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_hca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_hca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_ka{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_ka{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"u_wallace_lfa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        name = f"s_wallace_lfa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, use_csa=False, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        # Wallace implemented with interconnected CSAs (default choice) – the ppa adders are also configurable as above if desirable
        name = f"u_CSAwallace_cla{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_cla{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryLookaheadAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_rca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_rca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_pg_rca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_pg_rca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedPGRippleCarryAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_cska{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_cska{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySkipAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_cosa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_cosa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_cia{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_cia{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_csla{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_csla{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_ksa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_ksa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_bka{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_bka{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_sa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_sa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_hca{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_hca{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_ka{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_ka{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"u_CSAwallace_lfa{N}"
        circuit = UnsignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        name = f"s_CSAwallace_lfa{N}"
        circuit = SignedWallaceMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        # Dadda with interconnected HAs/FAs – the ppa adders are also configurable as above if desirable
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

        name = f"u_dadda_cosa{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_cosa{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedConditionalSumAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_cia{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_cia{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarryIncrementAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_csla{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_csla{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedCarrySelectAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_ksa{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_ksa{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKoggeStoneAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_bka{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_bka{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedBrentKungAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_sa{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_sa{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedSklanskyAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_hca{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_hca{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedHanCarlsonAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_ka{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_ka{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedKnowlesAdder)
        export_circuit(circuit, name)

        name = f"u_dadda_lfa{N}"
        circuit = UnsignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        name = f"s_dadda_lfa{N}"
        circuit = SignedDaddaMultiplier(a, b, name=name, unsigned_adder_class_name=UnsignedLadnerFischerAdder)
        export_circuit(circuit, name)

        """ DIVIDERS """
        # Arrdiv
        name = f"arrdiv{N}"
        circuit = ArrayDivider(a, b, name=name)
        export_circuit(circuit, name)
