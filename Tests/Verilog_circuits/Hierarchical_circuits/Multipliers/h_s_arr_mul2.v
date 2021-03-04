module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module xnor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a ^ _b);
endmodule

module or_gate(input _a, input _b, output _y0);
  assign _y0 = _a | _b;
endmodule

module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module nand_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a & _b);
endmodule

module ha(input a, input b, output ha_y0, output ha_y1);
  xor_gate xor_gate_ha_y0(a, b, ha_y0);
  and_gate and_gate_ha_y1(a, b, ha_y1);
endmodule

module fa(input a, input b, input cin, output fa_y2, output fa_y4);
  wire fa_y0;
  wire fa_y1;
  wire fa_y3;

  xor_gate xor_gate_fa_y0(a, b, fa_y0);
  and_gate and_gate_fa_y1(a, b, fa_y1);
  and_gate and_gate_fa_y3(fa_y0, cin, fa_y3);

  xor_gate xor_gate_fa_y2(fa_y0, cin, fa_y2);
  or_gate or_gate_fa_y4(fa_y1, fa_y3, fa_y4);
endmodule

module h_s_arr_mul2(input [1:0] a, input [1:0] b, output [3:0] out);
  wire a_0;
  wire a_1;
  wire b_0;
  wire b_1;
  wire h_s_arr_mul2_xor_constant_wire_y0;
  wire h_s_arr_mul2_xnor_constant_wire_y0;
  wire constant_wire;
  wire h_s_arr_mul2_and_0_0_y0;
  wire h_s_arr_mul2_nand_1_0_y0;
  wire h_s_arr_mul2_nand_0_1_y0;
  wire h_s_arr_mul2_ha_0_1_y0;
  wire h_s_arr_mul2_ha_0_1_y1;
  wire h_s_arr_mul2_and_1_1_y0;
  wire h_s_arr_mul2_fa_1_1_y2;
  wire h_s_arr_mul2_fa_1_1_y4;
  wire h_s_arr_mul2_xor_2_1_y0;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign b_0 = b[0];
  assign b_1 = b[1];
  xor_gate xor_gate_h_s_arr_mul2_xor_constant_wire_y0(a_0, b_0, h_s_arr_mul2_xor_constant_wire_y0);
  xnor_gate xnor_gate_h_s_arr_mul2_xnor_constant_wire_y0(a_0, b_0, h_s_arr_mul2_xnor_constant_wire_y0);
  or_gate or_gate_constant_wire(h_s_arr_mul2_xor_constant_wire_y0, h_s_arr_mul2_xnor_constant_wire_y0, constant_wire);
  and_gate and_gate_h_s_arr_mul2_and_0_0_y0(a_0, b_0, h_s_arr_mul2_and_0_0_y0);
  nand_gate nand_gate_h_s_arr_mul2_nand_1_0_y0(a_1, b_0, h_s_arr_mul2_nand_1_0_y0);
  nand_gate nand_gate_h_s_arr_mul2_nand_0_1_y0(a_0, b_1, h_s_arr_mul2_nand_0_1_y0);
  ha ha_h_s_arr_mul2_ha_0_1_y1(h_s_arr_mul2_nand_0_1_y0, h_s_arr_mul2_nand_1_0_y0, h_s_arr_mul2_ha_0_1_y0, h_s_arr_mul2_ha_0_1_y1);
  and_gate and_gate_h_s_arr_mul2_and_1_1_y0(a_1, b_1, h_s_arr_mul2_and_1_1_y0);
  fa fa_h_s_arr_mul2_fa_1_1_y4(h_s_arr_mul2_and_1_1_y0, constant_wire, h_s_arr_mul2_ha_0_1_y1, h_s_arr_mul2_fa_1_1_y2, h_s_arr_mul2_fa_1_1_y4);
  xor_gate xor_gate_h_s_arr_mul2_xor_2_1_y0(h_s_arr_mul2_fa_1_1_y4, constant_wire, h_s_arr_mul2_xor_2_1_y0);

  assign out[0] = h_s_arr_mul2_and_0_0_y0;
  assign out[1] = h_s_arr_mul2_ha_0_1_y0;
  assign out[2] = h_s_arr_mul2_fa_1_1_y2;
  assign out[3] = h_s_arr_mul2_xor_2_1_y0;
endmodule