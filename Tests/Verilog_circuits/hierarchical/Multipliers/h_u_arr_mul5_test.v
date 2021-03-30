`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:49:25 03/04/2021
// Design Name:   h_u_arr_mul5
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_multipliers/Unsigned_arr_mul5/h_u_arr_mul5_test.v
// Project Name:  Unsigned_arr_mul5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_u_arr_mul5
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_u_arr_mul5_test;

    // Inputs
    reg [4:0] a;
    reg [4:0] b;

    // Outputs
    wire [9:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_u_arr_mul5 uut (
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

