`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:06:05 02/24/2021
// Design Name:   f_ha
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Flat_adders/f_ha_test.v
// Project Name:  Flat_adders
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: f_ha
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module f_ha_test;

	// Inputs
	reg a;
	reg b;

	// Outputs
	wire f_ha_y0;
	wire f_ha_y1;

	// Instantiate the Unit Under Test (UUT)
	f_ha uut (
		.a(a), 
		.b(b), 
		.f_ha_y0(f_ha_y0), 
		.f_ha_y1(f_ha_y1)
	);

	initial begin
        // Initialize Inputs
        a = 1'b0;
        b = 1'b1;
    end

    always #2 a = ~a;
    always #4 b = ~b;
    initial $monitor("Time:",$time," ns   ", "a=%b, b=%b, sum=%b, cout=%b", a, b, f_ha_y0, f_ha_y1);
    initial #50 $finish;
endmodule

