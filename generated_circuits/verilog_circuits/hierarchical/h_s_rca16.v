module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module ha(input [0:0] a, input [0:0] b, output [0:0] ha_xor0, output [0:0] ha_and0);
  xor_gate xor_gate_ha_xor0(a[0], b[0], ha_xor0);
  and_gate and_gate_ha_and0(a[0], b[0], ha_and0);
endmodule

module fa(input [0:0] a, input [0:0] b, input [0:0] cin, output [0:0] fa_xor1, output [0:0] fa_or0);
  wire [0:0] fa_xor0;
  wire [0:0] fa_and0;
  wire [0:0] fa_and1;
  xor_gate xor_gate_fa_xor0(a[0], b[0], fa_xor0);
  and_gate and_gate_fa_and0(a[0], b[0], fa_and0);
  xor_gate xor_gate_fa_xor1(fa_xor0[0], cin[0], fa_xor1);
  and_gate and_gate_fa_and1(fa_xor0[0], cin[0], fa_and1);
  or_gate or_gate_fa_or0(fa_and0[0], fa_and1[0], fa_or0);
endmodule

module h_s_rca16(input [15:0] a, input [15:0] b, output [16:0] h_s_rca16_out);
  wire [0:0] h_s_rca16_ha_xor0;
  wire [0:0] h_s_rca16_ha_and0;
  wire [0:0] h_s_rca16_fa1_xor1;
  wire [0:0] h_s_rca16_fa1_or0;
  wire [0:0] h_s_rca16_fa2_xor1;
  wire [0:0] h_s_rca16_fa2_or0;
  wire [0:0] h_s_rca16_fa3_xor1;
  wire [0:0] h_s_rca16_fa3_or0;
  wire [0:0] h_s_rca16_fa4_xor1;
  wire [0:0] h_s_rca16_fa4_or0;
  wire [0:0] h_s_rca16_fa5_xor1;
  wire [0:0] h_s_rca16_fa5_or0;
  wire [0:0] h_s_rca16_fa6_xor1;
  wire [0:0] h_s_rca16_fa6_or0;
  wire [0:0] h_s_rca16_fa7_xor1;
  wire [0:0] h_s_rca16_fa7_or0;
  wire [0:0] h_s_rca16_fa8_xor1;
  wire [0:0] h_s_rca16_fa8_or0;
  wire [0:0] h_s_rca16_fa9_xor1;
  wire [0:0] h_s_rca16_fa9_or0;
  wire [0:0] h_s_rca16_fa10_xor1;
  wire [0:0] h_s_rca16_fa10_or0;
  wire [0:0] h_s_rca16_fa11_xor1;
  wire [0:0] h_s_rca16_fa11_or0;
  wire [0:0] h_s_rca16_fa12_xor1;
  wire [0:0] h_s_rca16_fa12_or0;
  wire [0:0] h_s_rca16_fa13_xor1;
  wire [0:0] h_s_rca16_fa13_or0;
  wire [0:0] h_s_rca16_fa14_xor1;
  wire [0:0] h_s_rca16_fa14_or0;
  wire [0:0] h_s_rca16_fa15_xor1;
  wire [0:0] h_s_rca16_fa15_or0;
  wire [0:0] h_s_rca16_xor0;
  wire [0:0] h_s_rca16_xor1;

  ha ha_h_s_rca16_ha_out(a[0], b[0], h_s_rca16_ha_xor0, h_s_rca16_ha_and0);
  fa fa_h_s_rca16_fa1_out(a[1], b[1], h_s_rca16_ha_and0[0], h_s_rca16_fa1_xor1, h_s_rca16_fa1_or0);
  fa fa_h_s_rca16_fa2_out(a[2], b[2], h_s_rca16_fa1_or0[0], h_s_rca16_fa2_xor1, h_s_rca16_fa2_or0);
  fa fa_h_s_rca16_fa3_out(a[3], b[3], h_s_rca16_fa2_or0[0], h_s_rca16_fa3_xor1, h_s_rca16_fa3_or0);
  fa fa_h_s_rca16_fa4_out(a[4], b[4], h_s_rca16_fa3_or0[0], h_s_rca16_fa4_xor1, h_s_rca16_fa4_or0);
  fa fa_h_s_rca16_fa5_out(a[5], b[5], h_s_rca16_fa4_or0[0], h_s_rca16_fa5_xor1, h_s_rca16_fa5_or0);
  fa fa_h_s_rca16_fa6_out(a[6], b[6], h_s_rca16_fa5_or0[0], h_s_rca16_fa6_xor1, h_s_rca16_fa6_or0);
  fa fa_h_s_rca16_fa7_out(a[7], b[7], h_s_rca16_fa6_or0[0], h_s_rca16_fa7_xor1, h_s_rca16_fa7_or0);
  fa fa_h_s_rca16_fa8_out(a[8], b[8], h_s_rca16_fa7_or0[0], h_s_rca16_fa8_xor1, h_s_rca16_fa8_or0);
  fa fa_h_s_rca16_fa9_out(a[9], b[9], h_s_rca16_fa8_or0[0], h_s_rca16_fa9_xor1, h_s_rca16_fa9_or0);
  fa fa_h_s_rca16_fa10_out(a[10], b[10], h_s_rca16_fa9_or0[0], h_s_rca16_fa10_xor1, h_s_rca16_fa10_or0);
  fa fa_h_s_rca16_fa11_out(a[11], b[11], h_s_rca16_fa10_or0[0], h_s_rca16_fa11_xor1, h_s_rca16_fa11_or0);
  fa fa_h_s_rca16_fa12_out(a[12], b[12], h_s_rca16_fa11_or0[0], h_s_rca16_fa12_xor1, h_s_rca16_fa12_or0);
  fa fa_h_s_rca16_fa13_out(a[13], b[13], h_s_rca16_fa12_or0[0], h_s_rca16_fa13_xor1, h_s_rca16_fa13_or0);
  fa fa_h_s_rca16_fa14_out(a[14], b[14], h_s_rca16_fa13_or0[0], h_s_rca16_fa14_xor1, h_s_rca16_fa14_or0);
  fa fa_h_s_rca16_fa15_out(a[15], b[15], h_s_rca16_fa14_or0[0], h_s_rca16_fa15_xor1, h_s_rca16_fa15_or0);
  xor_gate xor_gate_h_s_rca16_xor0(a[15], b[15], h_s_rca16_xor0);
  xor_gate xor_gate_h_s_rca16_xor1(h_s_rca16_xor0[0], h_s_rca16_fa15_or0[0], h_s_rca16_xor1);

  assign h_s_rca16_out[0] = h_s_rca16_ha_xor0[0];
  assign h_s_rca16_out[1] = h_s_rca16_fa1_xor1[0];
  assign h_s_rca16_out[2] = h_s_rca16_fa2_xor1[0];
  assign h_s_rca16_out[3] = h_s_rca16_fa3_xor1[0];
  assign h_s_rca16_out[4] = h_s_rca16_fa4_xor1[0];
  assign h_s_rca16_out[5] = h_s_rca16_fa5_xor1[0];
  assign h_s_rca16_out[6] = h_s_rca16_fa6_xor1[0];
  assign h_s_rca16_out[7] = h_s_rca16_fa7_xor1[0];
  assign h_s_rca16_out[8] = h_s_rca16_fa8_xor1[0];
  assign h_s_rca16_out[9] = h_s_rca16_fa9_xor1[0];
  assign h_s_rca16_out[10] = h_s_rca16_fa10_xor1[0];
  assign h_s_rca16_out[11] = h_s_rca16_fa11_xor1[0];
  assign h_s_rca16_out[12] = h_s_rca16_fa12_xor1[0];
  assign h_s_rca16_out[13] = h_s_rca16_fa13_xor1[0];
  assign h_s_rca16_out[14] = h_s_rca16_fa14_xor1[0];
  assign h_s_rca16_out[15] = h_s_rca16_fa15_xor1[0];
  assign h_s_rca16_out[16] = h_s_rca16_xor1[0];
endmodule