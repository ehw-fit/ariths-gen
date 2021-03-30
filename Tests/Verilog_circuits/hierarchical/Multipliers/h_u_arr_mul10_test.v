`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:52:56 03/04/2021
// Design Name:   h_u_arr_mul10
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_multipliers/Unsigned_arr_mul_10/h_u_arr_mul10_test.v
// Project Name:  Unsigned_arr_mul_10
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_u_arr_mul10
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_u_arr_mul10_test;

    // Inputs
    reg [9:0] a;
    reg [9:0] b;

    // Outputs
    wire [19:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_u_arr_mul10 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 10'b1010001010;
        b = 10'b0000010110;        
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #700 $finish;
endmodule

