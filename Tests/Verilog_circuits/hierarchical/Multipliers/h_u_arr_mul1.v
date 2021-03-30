module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module xnor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a ^ _b);
endmodule

module h_u_arr_mul1(input [0:0] a, input [0:0] b, output [1:0] out);
  wire a_0;
  wire b_0;
  wire h_u_arr_mul1_and_0_0_y0;
  wire h_u_arr_mul1_xor_constant_wire_y0;
  wire h_u_arr_mul1_xnor_constant_wire_y0;
  wire constant_wire;

  assign a_0 = a[0];
  assign b_0 = b[0];
  and_gate and_gate_h_u_arr_mul1_and_0_0_y0(a_0, b_0, h_u_arr_mul1_and_0_0_y0);
  xor_gate xor_gate_h_u_arr_mul1_xor_constant_wire_y0(a_0, b_0, h_u_arr_mul1_xor_constant_wire_y0);
  xnor_gate xnor_gate_h_u_arr_mul1_xnor_constant_wire_y0(a_0, b_0, h_u_arr_mul1_xnor_constant_wire_y0);
  and_gate and_gate_constant_wire(h_u_arr_mul1_xor_constant_wire_y0, h_u_arr_mul1_xnor_constant_wire_y0, constant_wire);

  assign out[0] = h_u_arr_mul1_and_0_0_y0;
  assign out[1] = constant_wire;
endmodule