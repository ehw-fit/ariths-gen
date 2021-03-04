`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:53:34 02/24/2021
// Design Name:   h_fa
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_adders/Full_adder/h_fa_test.v
// Project Name:  Full_adder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_fa
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_fa_test;

    // Inputs
    reg a;
    reg b;
    reg cin;

    // Outputs
    wire h_fa_y2;
    wire h_fa_y4;

    // Instantiate the Unit Under Test (UUT)
    h_fa uut (
        .a(a), 
        .b(b), 
        .cin(cin), 
        .h_fa_y2(h_fa_y2), 
        .h_fa_y4(h_fa_y4)
    );

    initial begin
        // Initialize Inputs
        a = 1'b0;
        b = 1'b1;
        cin = 1'b0;
    end

    always #2 a = ~a;
    always #4 b = ~b;
    always #6 cin = ~cin;
    initial $monitor("Time:",$time," ns   ", "a=%b, b=%b, cin=%b, sum=%b, cout=%b", a, b, cin, h_fa_y2, h_fa_y4);
    initial #100 $finish;
endmodule

