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

module s_rca8(input [7:0] a, input [7:0] b, output [8:0] s_rca8_out);
  wire [0:0] s_rca8_ha_xor0;
  wire [0:0] s_rca8_ha_and0;
  wire [0:0] s_rca8_fa1_xor1;
  wire [0:0] s_rca8_fa1_or0;
  wire [0:0] s_rca8_fa2_xor1;
  wire [0:0] s_rca8_fa2_or0;
  wire [0:0] s_rca8_fa3_xor1;
  wire [0:0] s_rca8_fa3_or0;
  wire [0:0] s_rca8_fa4_xor1;
  wire [0:0] s_rca8_fa4_or0;
  wire [0:0] s_rca8_fa5_xor1;
  wire [0:0] s_rca8_fa5_or0;
  wire [0:0] s_rca8_fa6_xor1;
  wire [0:0] s_rca8_fa6_or0;
  wire [0:0] s_rca8_fa7_xor1;
  wire [0:0] s_rca8_fa7_or0;
  wire [0:0] s_rca8_xor0;
  wire [0:0] s_rca8_xor1;

  ha ha_s_rca8_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(s_rca8_ha_xor0), .ha_and0(s_rca8_ha_and0));
  fa fa_s_rca8_fa1_out(.a(a[1]), .b(b[1]), .cin(s_rca8_ha_and0[0]), .fa_xor1(s_rca8_fa1_xor1), .fa_or0(s_rca8_fa1_or0));
  fa fa_s_rca8_fa2_out(.a(a[2]), .b(b[2]), .cin(s_rca8_fa1_or0[0]), .fa_xor1(s_rca8_fa2_xor1), .fa_or0(s_rca8_fa2_or0));
  fa fa_s_rca8_fa3_out(.a(a[3]), .b(b[3]), .cin(s_rca8_fa2_or0[0]), .fa_xor1(s_rca8_fa3_xor1), .fa_or0(s_rca8_fa3_or0));
  fa fa_s_rca8_fa4_out(.a(a[4]), .b(b[4]), .cin(s_rca8_fa3_or0[0]), .fa_xor1(s_rca8_fa4_xor1), .fa_or0(s_rca8_fa4_or0));
  fa fa_s_rca8_fa5_out(.a(a[5]), .b(b[5]), .cin(s_rca8_fa4_or0[0]), .fa_xor1(s_rca8_fa5_xor1), .fa_or0(s_rca8_fa5_or0));
  fa fa_s_rca8_fa6_out(.a(a[6]), .b(b[6]), .cin(s_rca8_fa5_or0[0]), .fa_xor1(s_rca8_fa6_xor1), .fa_or0(s_rca8_fa6_or0));
  fa fa_s_rca8_fa7_out(.a(a[7]), .b(b[7]), .cin(s_rca8_fa6_or0[0]), .fa_xor1(s_rca8_fa7_xor1), .fa_or0(s_rca8_fa7_or0));
  xor_gate xor_gate_s_rca8_xor0(.a(a[7]), .b(b[7]), .out(s_rca8_xor0));
  xor_gate xor_gate_s_rca8_xor1(.a(s_rca8_xor0[0]), .b(s_rca8_fa7_or0[0]), .out(s_rca8_xor1));

  assign s_rca8_out[0] = s_rca8_ha_xor0[0];
  assign s_rca8_out[1] = s_rca8_fa1_xor1[0];
  assign s_rca8_out[2] = s_rca8_fa2_xor1[0];
  assign s_rca8_out[3] = s_rca8_fa3_xor1[0];
  assign s_rca8_out[4] = s_rca8_fa4_xor1[0];
  assign s_rca8_out[5] = s_rca8_fa5_xor1[0];
  assign s_rca8_out[6] = s_rca8_fa6_xor1[0];
  assign s_rca8_out[7] = s_rca8_fa7_xor1[0];
  assign s_rca8_out[8] = s_rca8_xor1[0];
endmodule