"""
Support of custom PDK

This file defines functions for generating of full and half adders
directly on the level of CMOS modules. 

You may add your own modules as in example in set_pdk45_library()

Please call this function before calling get_verilog_code_XXX()
"""
from .one_bit_circuits import (
    one_bit_components
)


def set_pdk45_library():
    one_bit_components.FullAdder.use_verilog_instance = "FAX1 {unit} (.A({wirea}), .B({wireb}), .C({wirec}), .YS({wireys}), .YC({wireyc}))"
    one_bit_components.HalfAdder.use_verilog_instance = "HAX1 {unit} (.A({wirea}), .B({wireb}), .YS({wireys}), .YC({wireyc}))"