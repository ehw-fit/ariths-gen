module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
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

module pg_fa(input [0:0] a, input [0:0] b, input [0:0] cin, output [0:0] pg_fa_xor0, output [0:0] pg_fa_and0, output [0:0] pg_fa_xor1);
  xor_gate xor_gate_pg_fa_xor0(.a(a[0]), .b(b[0]), .out(pg_fa_xor0));
  and_gate and_gate_pg_fa_and0(.a(a[0]), .b(b[0]), .out(pg_fa_and0));
  xor_gate xor_gate_pg_fa_xor1(.a(pg_fa_xor0[0]), .b(cin[0]), .out(pg_fa_xor1));
endmodule

module u_pg_rca5(input [4:0] a, input [4:0] b, output [5:0] u_pg_rca5_out);
  wire [0:0] u_pg_rca5_pg_fa0_xor0;
  wire [0:0] u_pg_rca5_pg_fa0_and0;
  wire [0:0] u_pg_rca5_pg_fa1_xor0;
  wire [0:0] u_pg_rca5_pg_fa1_and0;
  wire [0:0] u_pg_rca5_pg_fa1_xor1;
  wire [0:0] u_pg_rca5_and1;
  wire [0:0] u_pg_rca5_or1;
  wire [0:0] u_pg_rca5_pg_fa2_xor0;
  wire [0:0] u_pg_rca5_pg_fa2_and0;
  wire [0:0] u_pg_rca5_pg_fa2_xor1;
  wire [0:0] u_pg_rca5_and2;
  wire [0:0] u_pg_rca5_or2;
  wire [0:0] u_pg_rca5_pg_fa3_xor0;
  wire [0:0] u_pg_rca5_pg_fa3_and0;
  wire [0:0] u_pg_rca5_pg_fa3_xor1;
  wire [0:0] u_pg_rca5_and3;
  wire [0:0] u_pg_rca5_or3;
  wire [0:0] u_pg_rca5_pg_fa4_xor0;
  wire [0:0] u_pg_rca5_pg_fa4_and0;
  wire [0:0] u_pg_rca5_pg_fa4_xor1;
  wire [0:0] u_pg_rca5_and4;
  wire [0:0] u_pg_rca5_or4;

  pg_fa pg_fa_u_pg_rca5_pg_fa0_out(.a(a[0]), .b(b[0]), .cin(1'b0), .pg_fa_xor0(u_pg_rca5_pg_fa0_xor0), .pg_fa_and0(u_pg_rca5_pg_fa0_and0), .pg_fa_xor1());
  pg_fa pg_fa_u_pg_rca5_pg_fa1_out(.a(a[1]), .b(b[1]), .cin(u_pg_rca5_pg_fa0_and0[0]), .pg_fa_xor0(u_pg_rca5_pg_fa1_xor0), .pg_fa_and0(u_pg_rca5_pg_fa1_and0), .pg_fa_xor1(u_pg_rca5_pg_fa1_xor1));
  and_gate and_gate_u_pg_rca5_and1(.a(u_pg_rca5_pg_fa0_and0[0]), .b(u_pg_rca5_pg_fa1_xor0[0]), .out(u_pg_rca5_and1));
  or_gate or_gate_u_pg_rca5_or1(.a(u_pg_rca5_and1[0]), .b(u_pg_rca5_pg_fa1_and0[0]), .out(u_pg_rca5_or1));
  pg_fa pg_fa_u_pg_rca5_pg_fa2_out(.a(a[2]), .b(b[2]), .cin(u_pg_rca5_or1[0]), .pg_fa_xor0(u_pg_rca5_pg_fa2_xor0), .pg_fa_and0(u_pg_rca5_pg_fa2_and0), .pg_fa_xor1(u_pg_rca5_pg_fa2_xor1));
  and_gate and_gate_u_pg_rca5_and2(.a(u_pg_rca5_or1[0]), .b(u_pg_rca5_pg_fa2_xor0[0]), .out(u_pg_rca5_and2));
  or_gate or_gate_u_pg_rca5_or2(.a(u_pg_rca5_and2[0]), .b(u_pg_rca5_pg_fa2_and0[0]), .out(u_pg_rca5_or2));
  pg_fa pg_fa_u_pg_rca5_pg_fa3_out(.a(a[3]), .b(b[3]), .cin(u_pg_rca5_or2[0]), .pg_fa_xor0(u_pg_rca5_pg_fa3_xor0), .pg_fa_and0(u_pg_rca5_pg_fa3_and0), .pg_fa_xor1(u_pg_rca5_pg_fa3_xor1));
  and_gate and_gate_u_pg_rca5_and3(.a(u_pg_rca5_or2[0]), .b(u_pg_rca5_pg_fa3_xor0[0]), .out(u_pg_rca5_and3));
  or_gate or_gate_u_pg_rca5_or3(.a(u_pg_rca5_and3[0]), .b(u_pg_rca5_pg_fa3_and0[0]), .out(u_pg_rca5_or3));
  pg_fa pg_fa_u_pg_rca5_pg_fa4_out(.a(a[4]), .b(b[4]), .cin(u_pg_rca5_or3[0]), .pg_fa_xor0(u_pg_rca5_pg_fa4_xor0), .pg_fa_and0(u_pg_rca5_pg_fa4_and0), .pg_fa_xor1(u_pg_rca5_pg_fa4_xor1));
  and_gate and_gate_u_pg_rca5_and4(.a(u_pg_rca5_or3[0]), .b(u_pg_rca5_pg_fa4_xor0[0]), .out(u_pg_rca5_and4));
  or_gate or_gate_u_pg_rca5_or4(.a(u_pg_rca5_and4[0]), .b(u_pg_rca5_pg_fa4_and0[0]), .out(u_pg_rca5_or4));

  assign u_pg_rca5_out[0] = u_pg_rca5_pg_fa0_xor0[0];
  assign u_pg_rca5_out[1] = u_pg_rca5_pg_fa1_xor1[0];
  assign u_pg_rca5_out[2] = u_pg_rca5_pg_fa2_xor1[0];
  assign u_pg_rca5_out[3] = u_pg_rca5_pg_fa3_xor1[0];
  assign u_pg_rca5_out[4] = u_pg_rca5_pg_fa4_xor1[0];
  assign u_pg_rca5_out[5] = u_pg_rca5_or4[0];
endmodule

module h_u_csabam8_pg_rca_h4_v10(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_pg_rca_h4_v10_out);
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and6_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and7_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and5_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha5_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha5_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and6_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha6_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha6_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and7_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and4_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha4_6_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha4_6_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and5_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa5_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa5_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and6_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa6_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa6_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and7_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and3_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha3_7_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_ha3_7_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and4_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa4_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa4_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and5_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa5_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa5_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and6_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa6_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_fa6_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v10_and7_7;
  wire [4:0] h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a;
  wire [4:0] h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b;
  wire [5:0] h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out;

  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and6_4(.a(a[6]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v10_and6_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and7_4(.a(a[7]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v10_and7_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and5_5(.a(a[5]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v10_and5_5));
  ha ha_h_u_csabam8_pg_rca_h4_v10_ha5_5_out(.a(h_u_csabam8_pg_rca_h4_v10_and5_5[0]), .b(h_u_csabam8_pg_rca_h4_v10_and6_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v10_ha5_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v10_ha5_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and6_5(.a(a[6]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v10_and6_5));
  ha ha_h_u_csabam8_pg_rca_h4_v10_ha6_5_out(.a(h_u_csabam8_pg_rca_h4_v10_and6_5[0]), .b(h_u_csabam8_pg_rca_h4_v10_and7_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v10_ha6_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v10_ha6_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and7_5(.a(a[7]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v10_and7_5));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and4_6(.a(a[4]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v10_and4_6));
  ha ha_h_u_csabam8_pg_rca_h4_v10_ha4_6_out(.a(h_u_csabam8_pg_rca_h4_v10_and4_6[0]), .b(h_u_csabam8_pg_rca_h4_v10_ha5_5_xor0[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v10_ha4_6_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v10_ha4_6_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and5_6(.a(a[5]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v10_and5_6));
  fa fa_h_u_csabam8_pg_rca_h4_v10_fa5_6_out(.a(h_u_csabam8_pg_rca_h4_v10_and5_6[0]), .b(h_u_csabam8_pg_rca_h4_v10_ha6_5_xor0[0]), .cin(h_u_csabam8_pg_rca_h4_v10_ha5_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v10_fa5_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v10_fa5_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v10_and6_6));
  fa fa_h_u_csabam8_pg_rca_h4_v10_fa6_6_out(.a(h_u_csabam8_pg_rca_h4_v10_and6_6[0]), .b(h_u_csabam8_pg_rca_h4_v10_and7_5[0]), .cin(h_u_csabam8_pg_rca_h4_v10_ha6_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v10_fa6_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v10_fa6_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v10_and7_6));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and3_7(.a(a[3]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v10_and3_7));
  ha ha_h_u_csabam8_pg_rca_h4_v10_ha3_7_out(.a(h_u_csabam8_pg_rca_h4_v10_and3_7[0]), .b(h_u_csabam8_pg_rca_h4_v10_ha4_6_xor0[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v10_ha3_7_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v10_ha3_7_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and4_7(.a(a[4]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v10_and4_7));
  fa fa_h_u_csabam8_pg_rca_h4_v10_fa4_7_out(.a(h_u_csabam8_pg_rca_h4_v10_and4_7[0]), .b(h_u_csabam8_pg_rca_h4_v10_fa5_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v10_ha4_6_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v10_fa4_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v10_fa4_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v10_and5_7));
  fa fa_h_u_csabam8_pg_rca_h4_v10_fa5_7_out(.a(h_u_csabam8_pg_rca_h4_v10_and5_7[0]), .b(h_u_csabam8_pg_rca_h4_v10_fa6_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v10_fa5_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v10_fa5_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v10_fa5_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v10_and6_7));
  fa fa_h_u_csabam8_pg_rca_h4_v10_fa6_7_out(.a(h_u_csabam8_pg_rca_h4_v10_and6_7[0]), .b(h_u_csabam8_pg_rca_h4_v10_and7_6[0]), .cin(h_u_csabam8_pg_rca_h4_v10_fa6_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v10_fa6_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v10_fa6_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v10_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v10_and7_7));
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a[0] = h_u_csabam8_pg_rca_h4_v10_fa4_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a[1] = h_u_csabam8_pg_rca_h4_v10_fa5_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a[2] = h_u_csabam8_pg_rca_h4_v10_fa6_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a[3] = h_u_csabam8_pg_rca_h4_v10_and7_7[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a[4] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b[0] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b[1] = h_u_csabam8_pg_rca_h4_v10_fa4_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b[2] = h_u_csabam8_pg_rca_h4_v10_fa5_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b[3] = h_u_csabam8_pg_rca_h4_v10_fa6_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b[4] = 1'b0;
  u_pg_rca5 u_pg_rca5_h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out(.a(h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_a), .b(h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_b), .u_pg_rca5_out(h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out));

  assign h_u_csabam8_pg_rca_h4_v10_out[0] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[1] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[2] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[3] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[4] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[5] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[6] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[7] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[8] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[9] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v10_out[10] = h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out[0];
  assign h_u_csabam8_pg_rca_h4_v10_out[11] = h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out[1];
  assign h_u_csabam8_pg_rca_h4_v10_out[12] = h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out[2];
  assign h_u_csabam8_pg_rca_h4_v10_out[13] = h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out[3];
  assign h_u_csabam8_pg_rca_h4_v10_out[14] = h_u_csabam8_pg_rca_h4_v10_u_pg_rca5_out[4];
  assign h_u_csabam8_pg_rca_h4_v10_out[15] = 1'b0;
endmodule