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
  xor_gate xor_gate_ha_xor0(.a(a[0]), .b(b[0]), .out(ha_xor0));
  and_gate and_gate_ha_and0(.a(a[0]), .b(b[0]), .out(ha_and0));
endmodule

module fa(input [0:0] a, input [0:0] b, input [0:0] cin, output [0:0] fa_xor1, output [0:0] fa_or0);
  wire [0:0] fa_xor0;
  wire [0:0] fa_and0;
  wire [0:0] fa_and1;
  xor_gate xor_gate_fa_xor0(.a(a[0]), .b(b[0]), .out(fa_xor0));
  and_gate and_gate_fa_and0(.a(a[0]), .b(b[0]), .out(fa_and0));
  xor_gate xor_gate_fa_xor1(.a(fa_xor0[0]), .b(cin[0]), .out(fa_xor1));
  and_gate and_gate_fa_and1(.a(fa_xor0[0]), .b(cin[0]), .out(fa_and1));
  or_gate or_gate_fa_or0(.a(fa_and0[0]), .b(fa_and1[0]), .out(fa_or0));
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

  ha ha_h_s_rca16_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(h_s_rca16_ha_xor0), .ha_and0(h_s_rca16_ha_and0));
  fa fa_h_s_rca16_fa1_out(.a(a[1]), .b(b[1]), .cin(h_s_rca16_ha_and0[0]), .fa_xor1(h_s_rca16_fa1_xor1), .fa_or0(h_s_rca16_fa1_or0));
  fa fa_h_s_rca16_fa2_out(.a(a[2]), .b(b[2]), .cin(h_s_rca16_fa1_or0[0]), .fa_xor1(h_s_rca16_fa2_xor1), .fa_or0(h_s_rca16_fa2_or0));
  fa fa_h_s_rca16_fa3_out(.a(a[3]), .b(b[3]), .cin(h_s_rca16_fa2_or0[0]), .fa_xor1(h_s_rca16_fa3_xor1), .fa_or0(h_s_rca16_fa3_or0));
  fa fa_h_s_rca16_fa4_out(.a(a[4]), .b(b[4]), .cin(h_s_rca16_fa3_or0[0]), .fa_xor1(h_s_rca16_fa4_xor1), .fa_or0(h_s_rca16_fa4_or0));
  fa fa_h_s_rca16_fa5_out(.a(a[5]), .b(b[5]), .cin(h_s_rca16_fa4_or0[0]), .fa_xor1(h_s_rca16_fa5_xor1), .fa_or0(h_s_rca16_fa5_or0));
  fa fa_h_s_rca16_fa6_out(.a(a[6]), .b(b[6]), .cin(h_s_rca16_fa5_or0[0]), .fa_xor1(h_s_rca16_fa6_xor1), .fa_or0(h_s_rca16_fa6_or0));
  fa fa_h_s_rca16_fa7_out(.a(a[7]), .b(b[7]), .cin(h_s_rca16_fa6_or0[0]), .fa_xor1(h_s_rca16_fa7_xor1), .fa_or0(h_s_rca16_fa7_or0));
  fa fa_h_s_rca16_fa8_out(.a(a[8]), .b(b[8]), .cin(h_s_rca16_fa7_or0[0]), .fa_xor1(h_s_rca16_fa8_xor1), .fa_or0(h_s_rca16_fa8_or0));
  fa fa_h_s_rca16_fa9_out(.a(a[9]), .b(b[9]), .cin(h_s_rca16_fa8_or0[0]), .fa_xor1(h_s_rca16_fa9_xor1), .fa_or0(h_s_rca16_fa9_or0));
  fa fa_h_s_rca16_fa10_out(.a(a[10]), .b(b[10]), .cin(h_s_rca16_fa9_or0[0]), .fa_xor1(h_s_rca16_fa10_xor1), .fa_or0(h_s_rca16_fa10_or0));
  fa fa_h_s_rca16_fa11_out(.a(a[11]), .b(b[11]), .cin(h_s_rca16_fa10_or0[0]), .fa_xor1(h_s_rca16_fa11_xor1), .fa_or0(h_s_rca16_fa11_or0));
  fa fa_h_s_rca16_fa12_out(.a(a[12]), .b(b[12]), .cin(h_s_rca16_fa11_or0[0]), .fa_xor1(h_s_rca16_fa12_xor1), .fa_or0(h_s_rca16_fa12_or0));
  fa fa_h_s_rca16_fa13_out(.a(a[13]), .b(b[13]), .cin(h_s_rca16_fa12_or0[0]), .fa_xor1(h_s_rca16_fa13_xor1), .fa_or0(h_s_rca16_fa13_or0));
  fa fa_h_s_rca16_fa14_out(.a(a[14]), .b(b[14]), .cin(h_s_rca16_fa13_or0[0]), .fa_xor1(h_s_rca16_fa14_xor1), .fa_or0(h_s_rca16_fa14_or0));
  fa fa_h_s_rca16_fa15_out(.a(a[15]), .b(b[15]), .cin(h_s_rca16_fa14_or0[0]), .fa_xor1(h_s_rca16_fa15_xor1), .fa_or0(h_s_rca16_fa15_or0));
  xor_gate xor_gate_h_s_rca16_xor0(.a(a[15]), .b(b[15]), .out(h_s_rca16_xor0));
  xor_gate xor_gate_h_s_rca16_xor1(.a(h_s_rca16_xor0[0]), .b(h_s_rca16_fa15_or0[0]), .out(h_s_rca16_xor1));

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