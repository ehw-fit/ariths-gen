"""
Support of custom PDK

This file defines functions for generating full and half adders
directly on the CMOS modules level.

You may add your own modules as defined in the example below
(inside `set_pdk45_library()`)

NOTE: Please call this function before calling `get_v_code_XXX()` to allow the
Verilog generation process to take into account the library's specific definitions.
"""
from .one_bit_circuits import (
    one_bit_components
)


def set_pdk45_library():
    one_bit_components.FullAdder.use_verilog_instance = "FAX1 {unit} (.A({wirea}), .B({wireb}), .C({wirec}), .YS({wireys}), .YC({wireyc}))"
    one_bit_components.HalfAdder.use_verilog_instance = "HAX1 {unit} (.A({wirea}), .B({wireb}), .YS({wireys}), .YC({wireyc}))"
