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

module u_rca12(input [11:0] a, input [11:0] b, output [12:0] u_rca12_out);
  wire [0:0] u_rca12_ha_xor0;
  wire [0:0] u_rca12_ha_and0;
  wire [0:0] u_rca12_fa1_xor1;
  wire [0:0] u_rca12_fa1_or0;
  wire [0:0] u_rca12_fa2_xor1;
  wire [0:0] u_rca12_fa2_or0;
  wire [0:0] u_rca12_fa3_xor1;
  wire [0:0] u_rca12_fa3_or0;
  wire [0:0] u_rca12_fa4_xor1;
  wire [0:0] u_rca12_fa4_or0;
  wire [0:0] u_rca12_fa5_xor1;
  wire [0:0] u_rca12_fa5_or0;
  wire [0:0] u_rca12_fa6_xor1;
  wire [0:0] u_rca12_fa6_or0;
  wire [0:0] u_rca12_fa7_xor1;
  wire [0:0] u_rca12_fa7_or0;
  wire [0:0] u_rca12_fa8_xor1;
  wire [0:0] u_rca12_fa8_or0;
  wire [0:0] u_rca12_fa9_xor1;
  wire [0:0] u_rca12_fa9_or0;
  wire [0:0] u_rca12_fa10_xor1;
  wire [0:0] u_rca12_fa10_or0;
  wire [0:0] u_rca12_fa11_xor1;
  wire [0:0] u_rca12_fa11_or0;

  ha ha_u_rca12_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(u_rca12_ha_xor0), .ha_and0(u_rca12_ha_and0));
  fa fa_u_rca12_fa1_out(.a(a[1]), .b(b[1]), .cin(u_rca12_ha_and0[0]), .fa_xor1(u_rca12_fa1_xor1), .fa_or0(u_rca12_fa1_or0));
  fa fa_u_rca12_fa2_out(.a(a[2]), .b(b[2]), .cin(u_rca12_fa1_or0[0]), .fa_xor1(u_rca12_fa2_xor1), .fa_or0(u_rca12_fa2_or0));
  fa fa_u_rca12_fa3_out(.a(a[3]), .b(b[3]), .cin(u_rca12_fa2_or0[0]), .fa_xor1(u_rca12_fa3_xor1), .fa_or0(u_rca12_fa3_or0));
  fa fa_u_rca12_fa4_out(.a(a[4]), .b(b[4]), .cin(u_rca12_fa3_or0[0]), .fa_xor1(u_rca12_fa4_xor1), .fa_or0(u_rca12_fa4_or0));
  fa fa_u_rca12_fa5_out(.a(a[5]), .b(b[5]), .cin(u_rca12_fa4_or0[0]), .fa_xor1(u_rca12_fa5_xor1), .fa_or0(u_rca12_fa5_or0));
  fa fa_u_rca12_fa6_out(.a(a[6]), .b(b[6]), .cin(u_rca12_fa5_or0[0]), .fa_xor1(u_rca12_fa6_xor1), .fa_or0(u_rca12_fa6_or0));
  fa fa_u_rca12_fa7_out(.a(a[7]), .b(b[7]), .cin(u_rca12_fa6_or0[0]), .fa_xor1(u_rca12_fa7_xor1), .fa_or0(u_rca12_fa7_or0));
  fa fa_u_rca12_fa8_out(.a(a[8]), .b(b[8]), .cin(u_rca12_fa7_or0[0]), .fa_xor1(u_rca12_fa8_xor1), .fa_or0(u_rca12_fa8_or0));
  fa fa_u_rca12_fa9_out(.a(a[9]), .b(b[9]), .cin(u_rca12_fa8_or0[0]), .fa_xor1(u_rca12_fa9_xor1), .fa_or0(u_rca12_fa9_or0));
  fa fa_u_rca12_fa10_out(.a(a[10]), .b(b[10]), .cin(u_rca12_fa9_or0[0]), .fa_xor1(u_rca12_fa10_xor1), .fa_or0(u_rca12_fa10_or0));
  fa fa_u_rca12_fa11_out(.a(a[11]), .b(b[11]), .cin(u_rca12_fa10_or0[0]), .fa_xor1(u_rca12_fa11_xor1), .fa_or0(u_rca12_fa11_or0));

  assign u_rca12_out[0] = u_rca12_ha_xor0[0];
  assign u_rca12_out[1] = u_rca12_fa1_xor1[0];
  assign u_rca12_out[2] = u_rca12_fa2_xor1[0];
  assign u_rca12_out[3] = u_rca12_fa3_xor1[0];
  assign u_rca12_out[4] = u_rca12_fa4_xor1[0];
  assign u_rca12_out[5] = u_rca12_fa5_xor1[0];
  assign u_rca12_out[6] = u_rca12_fa6_xor1[0];
  assign u_rca12_out[7] = u_rca12_fa7_xor1[0];
  assign u_rca12_out[8] = u_rca12_fa8_xor1[0];
  assign u_rca12_out[9] = u_rca12_fa9_xor1[0];
  assign u_rca12_out[10] = u_rca12_fa10_xor1[0];
  assign u_rca12_out[11] = u_rca12_fa11_xor1[0];
  assign u_rca12_out[12] = u_rca12_fa11_or0[0];
endmodule