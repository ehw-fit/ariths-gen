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

module h_u_rca12(input [11:0] a, input [11:0] b, output [12:0] h_u_rca12_out);
  wire [0:0] h_u_rca12_ha_xor0;
  wire [0:0] h_u_rca12_ha_and0;
  wire [0:0] h_u_rca12_fa1_xor1;
  wire [0:0] h_u_rca12_fa1_or0;
  wire [0:0] h_u_rca12_fa2_xor1;
  wire [0:0] h_u_rca12_fa2_or0;
  wire [0:0] h_u_rca12_fa3_xor1;
  wire [0:0] h_u_rca12_fa3_or0;
  wire [0:0] h_u_rca12_fa4_xor1;
  wire [0:0] h_u_rca12_fa4_or0;
  wire [0:0] h_u_rca12_fa5_xor1;
  wire [0:0] h_u_rca12_fa5_or0;
  wire [0:0] h_u_rca12_fa6_xor1;
  wire [0:0] h_u_rca12_fa6_or0;
  wire [0:0] h_u_rca12_fa7_xor1;
  wire [0:0] h_u_rca12_fa7_or0;
  wire [0:0] h_u_rca12_fa8_xor1;
  wire [0:0] h_u_rca12_fa8_or0;
  wire [0:0] h_u_rca12_fa9_xor1;
  wire [0:0] h_u_rca12_fa9_or0;
  wire [0:0] h_u_rca12_fa10_xor1;
  wire [0:0] h_u_rca12_fa10_or0;
  wire [0:0] h_u_rca12_fa11_xor1;
  wire [0:0] h_u_rca12_fa11_or0;

  ha ha_h_u_rca12_ha_out(a[0], b[0], h_u_rca12_ha_xor0, h_u_rca12_ha_and0);
  fa fa_h_u_rca12_fa1_out(a[1], b[1], h_u_rca12_ha_and0[0], h_u_rca12_fa1_xor1, h_u_rca12_fa1_or0);
  fa fa_h_u_rca12_fa2_out(a[2], b[2], h_u_rca12_fa1_or0[0], h_u_rca12_fa2_xor1, h_u_rca12_fa2_or0);
  fa fa_h_u_rca12_fa3_out(a[3], b[3], h_u_rca12_fa2_or0[0], h_u_rca12_fa3_xor1, h_u_rca12_fa3_or0);
  fa fa_h_u_rca12_fa4_out(a[4], b[4], h_u_rca12_fa3_or0[0], h_u_rca12_fa4_xor1, h_u_rca12_fa4_or0);
  fa fa_h_u_rca12_fa5_out(a[5], b[5], h_u_rca12_fa4_or0[0], h_u_rca12_fa5_xor1, h_u_rca12_fa5_or0);
  fa fa_h_u_rca12_fa6_out(a[6], b[6], h_u_rca12_fa5_or0[0], h_u_rca12_fa6_xor1, h_u_rca12_fa6_or0);
  fa fa_h_u_rca12_fa7_out(a[7], b[7], h_u_rca12_fa6_or0[0], h_u_rca12_fa7_xor1, h_u_rca12_fa7_or0);
  fa fa_h_u_rca12_fa8_out(a[8], b[8], h_u_rca12_fa7_or0[0], h_u_rca12_fa8_xor1, h_u_rca12_fa8_or0);
  fa fa_h_u_rca12_fa9_out(a[9], b[9], h_u_rca12_fa8_or0[0], h_u_rca12_fa9_xor1, h_u_rca12_fa9_or0);
  fa fa_h_u_rca12_fa10_out(a[10], b[10], h_u_rca12_fa9_or0[0], h_u_rca12_fa10_xor1, h_u_rca12_fa10_or0);
  fa fa_h_u_rca12_fa11_out(a[11], b[11], h_u_rca12_fa10_or0[0], h_u_rca12_fa11_xor1, h_u_rca12_fa11_or0);

  assign h_u_rca12_out[0] = h_u_rca12_ha_xor0[0];
  assign h_u_rca12_out[1] = h_u_rca12_fa1_xor1[0];
  assign h_u_rca12_out[2] = h_u_rca12_fa2_xor1[0];
  assign h_u_rca12_out[3] = h_u_rca12_fa3_xor1[0];
  assign h_u_rca12_out[4] = h_u_rca12_fa4_xor1[0];
  assign h_u_rca12_out[5] = h_u_rca12_fa5_xor1[0];
  assign h_u_rca12_out[6] = h_u_rca12_fa6_xor1[0];
  assign h_u_rca12_out[7] = h_u_rca12_fa7_xor1[0];
  assign h_u_rca12_out[8] = h_u_rca12_fa8_xor1[0];
  assign h_u_rca12_out[9] = h_u_rca12_fa9_xor1[0];
  assign h_u_rca12_out[10] = h_u_rca12_fa10_xor1[0];
  assign h_u_rca12_out[11] = h_u_rca12_fa11_xor1[0];
  assign h_u_rca12_out[12] = h_u_rca12_fa11_or0[0];
endmodule