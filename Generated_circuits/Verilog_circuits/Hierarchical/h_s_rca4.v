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
  wire fa_y0;
  wire fa_y1;
  wire fa_cin;
  wire fa_y3;

  assign fa_a = a;
  assign fa_b = b;
  assign fa_cin = cin;

  xor_gate xor_gate_fa_y0(fa_a, fa_b, fa_y0);
  and_gate and_gate_fa_y1(fa_a, fa_b, fa_y1);
  xor_gate xor_gate_fa_y2(fa_y0, fa_cin, fa_y2);
  and_gate and_gate_fa_y3(fa_y0, fa_cin, fa_y3);
  or_gate or_gate_fa_y4(fa_y1, fa_y3, fa_y4);
endmodule

module h_s_rca4(input [3:0] a, input [3:0] b, output [4:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire h_s_rca4_ha_y0;
  wire h_s_rca4_ha_y1;
  wire h_s_rca4_fa1_y2;
  wire h_s_rca4_fa1_y4;
  wire h_s_rca4_fa2_y2;
  wire h_s_rca4_fa2_y4;
  wire h_s_rca4_fa3_y2;
  wire h_s_rca4_fa3_y4;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  ha ha_h_s_rca4_ha_y0(a_0, b_0, h_s_rca4_ha_y0, h_s_rca4_ha_y1);
  fa fa_h_s_rca4_fa1_y2(a_1, b_1, h_s_rca4_ha_y1, h_s_rca4_fa1_y2, h_s_rca4_fa1_y4);
  fa fa_h_s_rca4_fa2_y2(a_2, b_2, h_s_rca4_fa1_y4, h_s_rca4_fa2_y2, h_s_rca4_fa2_y4);
  fa fa_h_s_rca4_fa3_y2(a_3, b_3, h_s_rca4_fa2_y4, h_s_rca4_fa3_y2, h_s_rca4_fa3_y4);

  assign out[0] = h_s_rca4_ha_y0;
  assign out[1] = h_s_rca4_fa1_y2;
  assign out[2] = h_s_rca4_fa2_y2;
  assign out[3] = h_s_rca4_fa3_y2;
  assign out[4] = h_s_rca4_fa3_y4;
endmodule