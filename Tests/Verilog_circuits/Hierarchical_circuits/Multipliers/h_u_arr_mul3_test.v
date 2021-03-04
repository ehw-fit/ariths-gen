`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:48:23 03/04/2021
// Design Name:   h_u_arr_mul3
// Module Name:   C:/Xilinx_projects/Verilog_generated_circuits/Hierarchical_multipliers/Unsigned_arr_mul3/h_u_arr_mul3_test.v
// Project Name:  Unsigned_arr_mul3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: h_u_arr_mul3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module h_u_arr_mul3_test;

    // Inputs
    reg [2:0] a;
    reg [2:0] b;

    // Outputs
    wire [5:0] out;

    // Instantiate the Unit Under Test (UUT)
    h_u_arr_mul3 uut (
        .a(a), 
        .b(b), 
        .out(out)
    );

    initial begin
        // Initialize Inputs
        a = 3'b010;
        b = 3'b110;        
    end

    always #2 a = a + 1;
    always #4 b = b + 1;
    initial $monitor("Time:",$time," ns   ", "a=%d, b=%d, result=%d", a, b, out);
    initial #200 $finish;
endmodule

