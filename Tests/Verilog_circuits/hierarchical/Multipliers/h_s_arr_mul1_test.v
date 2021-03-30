`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:28:27 03/04/2021
// Design Name:   h_s_arr_mul1
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_multipliers/Signed_arr_mul1/h_s_arr_mul1_test.v
// Project Name:  Signed_arr_mul1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_s_arr_mul1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_s_arr_mul1_test;

    // Inputs
    reg signed [0:0] a;
    reg signed [0:0] b;

    // Outputs
    wire signed [1:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_s_arr_mul1 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 1'b0;
        b = 1'b1;        
    end

    always #2 a = a + 1;
    always #4 b = b + 1;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #100 $finish;
endmodule

