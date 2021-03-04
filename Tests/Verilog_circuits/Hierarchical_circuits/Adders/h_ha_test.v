`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:50:05 02/24/2021
// Design Name:   h_ha
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_adders/Half_adder/h_ha_test.v
// Project Name:  Half_adder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_ha
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_ha_test;

    // Inputs
    reg a;
    reg b;

    // Outputs
    wire h_ha_y0;
    wire h_ha_y1;

    // Instantiate the Unit Under Test (UUT)
    h_ha uut (
        .a(a), 
        .b(b), 
        .h_ha_y0(h_ha_y0), 
        .h_ha_y1(h_ha_y1)
    );

    initial begin
        // Initialize Inputs
        a = 1'b0;
        b = 1'b1;
    end

    always #2 a = ~a;
    always #4 b = ~b;
    initial $monitor("Time:",$time," ns   ", "a=%b, b=%b, sum=%b, cout=%b", a, b, h_ha_y0, h_ha_y1);
    initial #50 $finish;
endmodule

