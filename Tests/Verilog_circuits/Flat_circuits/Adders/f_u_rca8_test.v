`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:12:24 02/24/2021
// Design Name:   f_u_rca8
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_adders/f_u_rca8_test.v
// Project Name:  Flat_adders
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_u_rca8
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_u_rca8_test;

    // Inputs
    reg [7:0] a;
    reg [7:0] b;

    // Outputs
    wire [8:0] out;

    // Instantiate the Unit Under Test (UUT)
    f_u_rca8 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 8'd77;
        b = 8'd42;        
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #400 $finish;
endmodule

