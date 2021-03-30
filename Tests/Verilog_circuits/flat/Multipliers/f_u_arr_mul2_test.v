`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:59:42 03/04/2021
// Design Name:   f_u_arr_mul2
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_multipliers/f_u_arr_mul2_test.v
// Project Name:  Flat_multipliers
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_u_arr_mul2
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_u_arr_mul2_test;

    // Inputs
    reg [1:0] a;
    reg [1:0] b;

    // Outputs
    wire [3:0] out;

    // Instantiate the Unit Under Test (UUT)
    f_u_arr_mul2 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 2'b00;
        b = 2'b10;        
    end

    always #2 a = a + 2;
    always #4 b = b + 1;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

