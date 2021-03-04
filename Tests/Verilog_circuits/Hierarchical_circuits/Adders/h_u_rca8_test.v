`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:35:11 02/24/2021
// Design Name:   h_u_rca8
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_adders/Unsigned_rca8/h_u_rca8_test.v
// Project Name:  Unsigned_rca8
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_u_rca8
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_u_rca8_test;

    // Inputs
    reg [7:0] a;
    reg [7:0] b;

    // Outputs
    wire [8:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_u_rca8 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

     initial begin
        // Initialize Inputs
        a = 8'd140;
        b = 8'd39;
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #400 $finish;  
endmodule

