`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:06:29 02/24/2021
// Design Name:   or_gate
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Logic_gates/or_gate_test.v
// Project Name:  Logic_gates
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: or_gate
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module or_gate_test;

    // Inputs
    reg _a;
    reg _b;

    // Outputs
    wire _y0;

    // Instantiate the Unit Under Test (UUT)
    or_gate uut (
        ._a(_a), 
        ._b(_b), 
        ._y0(_y0)
    );

    initial begin
        // Initialize Inputs
        _a = 1'b0;
        _b = 1'b1;
    end

    always #2 _a = ~_a;
    always #4 _b = ~_b;
    initial $monitor("Time:",$time," ns   ", "a=%b, b=%b, y=%b",_a,_b,_y0);
    initial #50 $finish;
endmodule

