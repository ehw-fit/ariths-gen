`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:22:11 02/24/2021
// Design Name:   h_u_rca3
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_adders/Unsigned_rca3/h_u_rca3_test.v
// Project Name:  Unsigned_rca3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_u_rca3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_u_rca3_test;

    // Inputs
    reg [2:0] a;
    reg [2:0] b;

    // Outputs
    wire [3:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_u_rca3 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 3'd5;
        b = 3'd1;
    end

    always #2 a = a + 2;
    always #4 b = b + 3;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

