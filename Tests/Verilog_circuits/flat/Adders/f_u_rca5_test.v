`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:08:50 02/24/2021
// Design Name:   f_u_rca5
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_adders/f_u_rca5_test.v
// Project Name:  Flat_adders
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_u_rca5
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_u_rca5_test;

    // Inputs
    reg [4:0] a;
    reg [4:0] b;

    // Outputs
    wire [5:0] out;

    // Instantiate the Unit Under Test (UUT)
    f_u_rca5 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 5'd4;
        b = 5'd20;        
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

