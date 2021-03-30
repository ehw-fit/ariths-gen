`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:58:21 03/04/2021
// Design Name:   f_u_arr_mul8
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_multipliers/f_u_arr_mul8_test.v
// Project Name:  Flat_multipliers
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_u_arr_mul8
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_u_arr_mul8_test;

    // Inputs
    reg [7:0] a;
    reg [7:0] b;

    // Outputs
    wire [15:0] out;

    // Instantiate the Unit Under Test (UUT)
    f_u_arr_mul8 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 8'b10001010;
        b = 8'b00010110;        
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #500 $finish;
endmodule

