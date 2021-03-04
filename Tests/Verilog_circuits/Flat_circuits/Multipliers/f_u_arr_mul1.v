module f_u_arr_mul1(input [0:0] a, input [0:0] b, output [1:0] out);
  wire a_0;
  wire b_0;
  wire f_u_arr_mul1_and_0_0_a_0;
  wire f_u_arr_mul1_and_0_0_b_0;
  wire f_u_arr_mul1_and_0_0_y0;
  wire f_u_arr_mul1_xor_constant_wire_a_0;
  wire f_u_arr_mul1_xor_constant_wire_b_0;
  wire f_u_arr_mul1_xor_constant_wire_y0;
  wire f_u_arr_mul1_xnor_constant_wire_a_0;
  wire f_u_arr_mul1_xnor_constant_wire_b_0;
  wire f_u_arr_mul1_xnor_constant_wire_y0;
  wire f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xor_constant_wire_y0;
  wire f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xnor_constant_wire_y0;
  wire constant_wire;

  assign a_0 = a[0];
  assign b_0 = b[0];
  assign f_u_arr_mul1_and_0_0_a_0 = a_0;
  assign f_u_arr_mul1_and_0_0_b_0 = b_0;
  assign f_u_arr_mul1_and_0_0_y0 = f_u_arr_mul1_and_0_0_a_0 & f_u_arr_mul1_and_0_0_b_0;
  assign f_u_arr_mul1_xor_constant_wire_a_0 = a_0;
  assign f_u_arr_mul1_xor_constant_wire_b_0 = b_0;
  assign f_u_arr_mul1_xor_constant_wire_y0 = f_u_arr_mul1_xor_constant_wire_a_0 ^ f_u_arr_mul1_xor_constant_wire_b_0;
  assign f_u_arr_mul1_xnor_constant_wire_a_0 = a_0;
  assign f_u_arr_mul1_xnor_constant_wire_b_0 = b_0;
  assign f_u_arr_mul1_xnor_constant_wire_y0 = ~(f_u_arr_mul1_xnor_constant_wire_a_0 ^ f_u_arr_mul1_xnor_constant_wire_b_0);
  assign f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xor_constant_wire_y0 = f_u_arr_mul1_xor_constant_wire_y0;
  assign f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xnor_constant_wire_y0 = f_u_arr_mul1_xnor_constant_wire_y0;
  assign constant_wire = f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xor_constant_wire_y0 & f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xnor_constant_wire_y0;

  assign out[0] = f_u_arr_mul1_and_0_0_y0;
  assign out[1] = constant_wire;
endmodule