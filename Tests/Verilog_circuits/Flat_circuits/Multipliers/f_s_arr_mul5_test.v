`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:52:14 03/04/2021
// Design Name:   f_s_arr_mul5
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_multipliers/f_s_arr_mul5_test.v
// Project Name:  Flat_multipliers
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_s_arr_mul5
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_s_arr_mul5_test;

    // Inputs
    reg signed [4:0] a;
    reg signed [4:0] b;

    // Outputs
    wire signed [9:0] out;

    // Instantiate the Unit Under Test (UUT)
    f_s_arr_mul5 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 5'b01010;
        b = 5'b10110;        
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #300 $finish;
endmodule

