`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:44:01 02/24/2021
// Design Name:   h_s_rca4
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_adders/Signed_rca4/h_s_rca4_test.v
// Project Name:  Signed_rca4
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_s_rca4
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_s_rca4_test;

    // Inputs
    reg signed [3:0] a;
    reg signed [3:0] b;

    // Outputs
    wire signed [4:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_s_rca4 uut (
        .a(a),
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 4'b1000;
        b = 4'b0110;        
    end

    always #2 a = a + 1;
    always #4 b = b + 2;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

