`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:03:48 02/24/2021
// Design Name:   f_u_rca3
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_adders/f_u_rca3_test.v
// Project Name:  Flat_adders
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_u_rca3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_u_rca3_test;

    // Inputs
    reg [2:0] a;
    reg [2:0] b;

    // Outputs
    wire [3:0] out;

    // Instantiate the Unit Under Test (UUT)
    f_u_rca3 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 3'b000;
        b = 3'b010;        
    end

    always #2 a = a + 1;
    always #4 b = b + 1;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

