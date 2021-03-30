`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:35:48 03/04/2021
// Design Name:   h_s_arr_mul3
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_multipliers/Signed_arr_mul3/h_s_arr_mul3_test.v
// Project Name:  Signed_arr_mul3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_s_arr_mul3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_s_arr_mul3_test;

    // Inputs
    reg signed [2:0] a;
    reg signed [2:0] b;

    // Outputs
    wire signed [5:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_s_arr_mul3 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 3'b010;
        b = 3'b110;        
    end

    always #2 a = a + 1;
    always #4 b = b + 1;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

