module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module or_gate(input _a, input _b, output _y0);
  assign _y0 = _a | _b;
endmodule

module ha(input a, input b, output ha_y0, output ha_y1);
  wire ha_a;
  wire ha_b;

  assign ha_a = a;
  assign ha_b = b;

  xor_gate xor_gate_ha_y0(ha_a, ha_b, ha_y0);
  and_gate and_gate_ha_y1(ha_a, ha_b, ha_y1);
endmodule

module fa(input a, input b, input cin, output fa_y2, output fa_y4);
  wire fa_a;
  wire fa_b;
  wire fa_cin;

  assign fa_a = a;
  assign fa_b = b;
  assign fa_cin = cin;

  xor_gate xor_gate_fa_y0(fa_a, fa_b, fa_y0);
  and_gate and_gate_fa_y1(fa_a, fa_b, fa_y1);
  xor_gate xor_gate_fa_y2(fa_y0, fa_cin, fa_y2);
  and_gate and_gate_fa_y3(fa_y0, fa_cin, fa_y3);
  or_gate or_gate_fa_y4(fa_y1, fa_y3, fa_y4);
endmodule

module h_u_rca12(input [11:0] a, input [11:0] b, output [12:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire a_4;
  wire a_5;
  wire a_6;
  wire a_7;
  wire a_8;
  wire a_9;
  wire a_10;
  wire a_11;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire b_4;
  wire b_5;
  wire b_6;
  wire b_7;
  wire b_8;
  wire b_9;
  wire b_10;
  wire b_11;
  wire h_u_rca12_ha_y0;
  wire h_u_rca12_ha_y1;
  wire h_u_rca12_fa1_y2;
  wire h_u_rca12_fa1_y4;
  wire h_u_rca12_fa2_y2;
  wire h_u_rca12_fa2_y4;
  wire h_u_rca12_fa3_y2;
  wire h_u_rca12_fa3_y4;
  wire h_u_rca12_fa4_y2;
  wire h_u_rca12_fa4_y4;
  wire h_u_rca12_fa5_y2;
  wire h_u_rca12_fa5_y4;
  wire h_u_rca12_fa6_y2;
  wire h_u_rca12_fa6_y4;
  wire h_u_rca12_fa7_y2;
  wire h_u_rca12_fa7_y4;
  wire h_u_rca12_fa8_y2;
  wire h_u_rca12_fa8_y4;
  wire h_u_rca12_fa9_y2;
  wire h_u_rca12_fa9_y4;
  wire h_u_rca12_fa10_y2;
  wire h_u_rca12_fa10_y4;
  wire h_u_rca12_fa11_y2;
  wire h_u_rca12_fa11_y4;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign a_4 = a[4];
  assign a_5 = a[5];
  assign a_6 = a[6];
  assign a_7 = a[7];
  assign a_8 = a[8];
  assign a_9 = a[9];
  assign a_10 = a[10];
  assign a_11 = a[11];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  assign b_4 = b[4];
  assign b_5 = b[5];
  assign b_6 = b[6];
  assign b_7 = b[7];
  assign b_8 = b[8];
  assign b_9 = b[9];
  assign b_10 = b[10];
  assign b_11 = b[11];
  ha ha_h_u_rca12_ha_y0(a_0, b_0, h_u_rca12_ha_y0, h_u_rca12_ha_y1);
  fa fa_h_u_rca12_fa1_y2(a_1, b_1, h_u_rca12_ha_y1, h_u_rca12_fa1_y2, h_u_rca12_fa1_y4);
  fa fa_h_u_rca12_fa2_y2(a_2, b_2, h_u_rca12_fa1_y4, h_u_rca12_fa2_y2, h_u_rca12_fa2_y4);
  fa fa_h_u_rca12_fa3_y2(a_3, b_3, h_u_rca12_fa2_y4, h_u_rca12_fa3_y2, h_u_rca12_fa3_y4);
  fa fa_h_u_rca12_fa4_y2(a_4, b_4, h_u_rca12_fa3_y4, h_u_rca12_fa4_y2, h_u_rca12_fa4_y4);
  fa fa_h_u_rca12_fa5_y2(a_5, b_5, h_u_rca12_fa4_y4, h_u_rca12_fa5_y2, h_u_rca12_fa5_y4);
  fa fa_h_u_rca12_fa6_y2(a_6, b_6, h_u_rca12_fa5_y4, h_u_rca12_fa6_y2, h_u_rca12_fa6_y4);
  fa fa_h_u_rca12_fa7_y2(a_7, b_7, h_u_rca12_fa6_y4, h_u_rca12_fa7_y2, h_u_rca12_fa7_y4);
  fa fa_h_u_rca12_fa8_y2(a_8, b_8, h_u_rca12_fa7_y4, h_u_rca12_fa8_y2, h_u_rca12_fa8_y4);
  fa fa_h_u_rca12_fa9_y2(a_9, b_9, h_u_rca12_fa8_y4, h_u_rca12_fa9_y2, h_u_rca12_fa9_y4);
  fa fa_h_u_rca12_fa10_y2(a_10, b_10, h_u_rca12_fa9_y4, h_u_rca12_fa10_y2, h_u_rca12_fa10_y4);
  fa fa_h_u_rca12_fa11_y2(a_11, b_11, h_u_rca12_fa10_y4, h_u_rca12_fa11_y2, h_u_rca12_fa11_y4);

  assign out[0] = h_u_rca12_ha_y0;
  assign out[1] = h_u_rca12_fa1_y2;
  assign out[2] = h_u_rca12_fa2_y2;
  assign out[3] = h_u_rca12_fa3_y2;
  assign out[4] = h_u_rca12_fa4_y2;
  assign out[5] = h_u_rca12_fa5_y2;
  assign out[6] = h_u_rca12_fa6_y2;
  assign out[7] = h_u_rca12_fa7_y2;
  assign out[8] = h_u_rca12_fa8_y2;
  assign out[9] = h_u_rca12_fa9_y2;
  assign out[10] = h_u_rca12_fa10_y2;
  assign out[11] = h_u_rca12_fa11_y2;
  assign out[12] = h_u_rca12_fa11_y4;
endmodule