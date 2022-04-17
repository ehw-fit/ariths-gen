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

module u_pg_rca8(input [7:0] a, input [7:0] b, output [8:0] u_pg_rca8_out);
  wire [0:0] u_pg_rca8_pg_fa0_xor0;
  wire [0:0] u_pg_rca8_pg_fa0_and0;
  wire [0:0] u_pg_rca8_pg_fa1_xor0;
  wire [0:0] u_pg_rca8_pg_fa1_and0;
  wire [0:0] u_pg_rca8_pg_fa1_xor1;
  wire [0:0] u_pg_rca8_and1;
  wire [0:0] u_pg_rca8_or1;
  wire [0:0] u_pg_rca8_pg_fa2_xor0;
  wire [0:0] u_pg_rca8_pg_fa2_and0;
  wire [0:0] u_pg_rca8_pg_fa2_xor1;
  wire [0:0] u_pg_rca8_and2;
  wire [0:0] u_pg_rca8_or2;
  wire [0:0] u_pg_rca8_pg_fa3_xor0;
  wire [0:0] u_pg_rca8_pg_fa3_and0;
  wire [0:0] u_pg_rca8_pg_fa3_xor1;
  wire [0:0] u_pg_rca8_and3;
  wire [0:0] u_pg_rca8_or3;
  wire [0:0] u_pg_rca8_pg_fa4_xor0;
  wire [0:0] u_pg_rca8_pg_fa4_and0;
  wire [0:0] u_pg_rca8_pg_fa4_xor1;
  wire [0:0] u_pg_rca8_and4;
  wire [0:0] u_pg_rca8_or4;
  wire [0:0] u_pg_rca8_pg_fa5_xor0;
  wire [0:0] u_pg_rca8_pg_fa5_and0;
  wire [0:0] u_pg_rca8_pg_fa5_xor1;
  wire [0:0] u_pg_rca8_and5;
  wire [0:0] u_pg_rca8_or5;
  wire [0:0] u_pg_rca8_pg_fa6_xor0;
  wire [0:0] u_pg_rca8_pg_fa6_and0;
  wire [0:0] u_pg_rca8_pg_fa6_xor1;
  wire [0:0] u_pg_rca8_and6;
  wire [0:0] u_pg_rca8_or6;
  wire [0:0] u_pg_rca8_pg_fa7_xor0;
  wire [0:0] u_pg_rca8_pg_fa7_and0;
  wire [0:0] u_pg_rca8_pg_fa7_xor1;
  wire [0:0] u_pg_rca8_and7;
  wire [0:0] u_pg_rca8_or7;

  pg_fa pg_fa_u_pg_rca8_pg_fa0_out(.a(a[0]), .b(b[0]), .cin(1'b0), .pg_fa_xor0(u_pg_rca8_pg_fa0_xor0), .pg_fa_and0(u_pg_rca8_pg_fa0_and0), .pg_fa_xor1());
  pg_fa pg_fa_u_pg_rca8_pg_fa1_out(.a(a[1]), .b(b[1]), .cin(u_pg_rca8_pg_fa0_and0[0]), .pg_fa_xor0(u_pg_rca8_pg_fa1_xor0), .pg_fa_and0(u_pg_rca8_pg_fa1_and0), .pg_fa_xor1(u_pg_rca8_pg_fa1_xor1));
  and_gate and_gate_u_pg_rca8_and1(.a(u_pg_rca8_pg_fa0_and0[0]), .b(u_pg_rca8_pg_fa1_xor0[0]), .out(u_pg_rca8_and1));
  or_gate or_gate_u_pg_rca8_or1(.a(u_pg_rca8_and1[0]), .b(u_pg_rca8_pg_fa1_and0[0]), .out(u_pg_rca8_or1));
  pg_fa pg_fa_u_pg_rca8_pg_fa2_out(.a(a[2]), .b(b[2]), .cin(u_pg_rca8_or1[0]), .pg_fa_xor0(u_pg_rca8_pg_fa2_xor0), .pg_fa_and0(u_pg_rca8_pg_fa2_and0), .pg_fa_xor1(u_pg_rca8_pg_fa2_xor1));
  and_gate and_gate_u_pg_rca8_and2(.a(u_pg_rca8_or1[0]), .b(u_pg_rca8_pg_fa2_xor0[0]), .out(u_pg_rca8_and2));
  or_gate or_gate_u_pg_rca8_or2(.a(u_pg_rca8_and2[0]), .b(u_pg_rca8_pg_fa2_and0[0]), .out(u_pg_rca8_or2));
  pg_fa pg_fa_u_pg_rca8_pg_fa3_out(.a(a[3]), .b(b[3]), .cin(u_pg_rca8_or2[0]), .pg_fa_xor0(u_pg_rca8_pg_fa3_xor0), .pg_fa_and0(u_pg_rca8_pg_fa3_and0), .pg_fa_xor1(u_pg_rca8_pg_fa3_xor1));
  and_gate and_gate_u_pg_rca8_and3(.a(u_pg_rca8_or2[0]), .b(u_pg_rca8_pg_fa3_xor0[0]), .out(u_pg_rca8_and3));
  or_gate or_gate_u_pg_rca8_or3(.a(u_pg_rca8_and3[0]), .b(u_pg_rca8_pg_fa3_and0[0]), .out(u_pg_rca8_or3));
  pg_fa pg_fa_u_pg_rca8_pg_fa4_out(.a(a[4]), .b(b[4]), .cin(u_pg_rca8_or3[0]), .pg_fa_xor0(u_pg_rca8_pg_fa4_xor0), .pg_fa_and0(u_pg_rca8_pg_fa4_and0), .pg_fa_xor1(u_pg_rca8_pg_fa4_xor1));
  and_gate and_gate_u_pg_rca8_and4(.a(u_pg_rca8_or3[0]), .b(u_pg_rca8_pg_fa4_xor0[0]), .out(u_pg_rca8_and4));
  or_gate or_gate_u_pg_rca8_or4(.a(u_pg_rca8_and4[0]), .b(u_pg_rca8_pg_fa4_and0[0]), .out(u_pg_rca8_or4));
  pg_fa pg_fa_u_pg_rca8_pg_fa5_out(.a(a[5]), .b(b[5]), .cin(u_pg_rca8_or4[0]), .pg_fa_xor0(u_pg_rca8_pg_fa5_xor0), .pg_fa_and0(u_pg_rca8_pg_fa5_and0), .pg_fa_xor1(u_pg_rca8_pg_fa5_xor1));
  and_gate and_gate_u_pg_rca8_and5(.a(u_pg_rca8_or4[0]), .b(u_pg_rca8_pg_fa5_xor0[0]), .out(u_pg_rca8_and5));
  or_gate or_gate_u_pg_rca8_or5(.a(u_pg_rca8_and5[0]), .b(u_pg_rca8_pg_fa5_and0[0]), .out(u_pg_rca8_or5));
  pg_fa pg_fa_u_pg_rca8_pg_fa6_out(.a(a[6]), .b(b[6]), .cin(u_pg_rca8_or5[0]), .pg_fa_xor0(u_pg_rca8_pg_fa6_xor0), .pg_fa_and0(u_pg_rca8_pg_fa6_and0), .pg_fa_xor1(u_pg_rca8_pg_fa6_xor1));
  and_gate and_gate_u_pg_rca8_and6(.a(u_pg_rca8_or5[0]), .b(u_pg_rca8_pg_fa6_xor0[0]), .out(u_pg_rca8_and6));
  or_gate or_gate_u_pg_rca8_or6(.a(u_pg_rca8_and6[0]), .b(u_pg_rca8_pg_fa6_and0[0]), .out(u_pg_rca8_or6));
  pg_fa pg_fa_u_pg_rca8_pg_fa7_out(.a(a[7]), .b(b[7]), .cin(u_pg_rca8_or6[0]), .pg_fa_xor0(u_pg_rca8_pg_fa7_xor0), .pg_fa_and0(u_pg_rca8_pg_fa7_and0), .pg_fa_xor1(u_pg_rca8_pg_fa7_xor1));
  and_gate and_gate_u_pg_rca8_and7(.a(u_pg_rca8_or6[0]), .b(u_pg_rca8_pg_fa7_xor0[0]), .out(u_pg_rca8_and7));
  or_gate or_gate_u_pg_rca8_or7(.a(u_pg_rca8_and7[0]), .b(u_pg_rca8_pg_fa7_and0[0]), .out(u_pg_rca8_or7));

  assign u_pg_rca8_out[0] = u_pg_rca8_pg_fa0_xor0[0];
  assign u_pg_rca8_out[1] = u_pg_rca8_pg_fa1_xor1[0];
  assign u_pg_rca8_out[2] = u_pg_rca8_pg_fa2_xor1[0];
  assign u_pg_rca8_out[3] = u_pg_rca8_pg_fa3_xor1[0];
  assign u_pg_rca8_out[4] = u_pg_rca8_pg_fa4_xor1[0];
  assign u_pg_rca8_out[5] = u_pg_rca8_pg_fa5_xor1[0];
  assign u_pg_rca8_out[6] = u_pg_rca8_pg_fa6_xor1[0];
  assign u_pg_rca8_out[7] = u_pg_rca8_pg_fa7_xor1[0];
  assign u_pg_rca8_out[8] = u_pg_rca8_or7[0];
endmodule

module h_u_csabam8_pg_rca_h4_v7(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_pg_rca_h4_v7_out);
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and3_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and4_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and5_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and6_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and7_4;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and2_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha2_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha2_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and3_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha3_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha3_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and4_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha4_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha4_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and5_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha5_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha5_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and6_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha6_5_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha6_5_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and7_5;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and1_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha1_6_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha1_6_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and2_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa2_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa2_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and3_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa3_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa3_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and4_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa4_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa4_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and5_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa5_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa5_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and6_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa6_6_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa6_6_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and7_6;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and0_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha0_7_xor0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_ha0_7_and0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and1_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa1_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa1_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and2_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa2_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa2_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and3_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa3_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa3_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and4_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa4_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa4_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and5_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa5_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa5_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and6_7;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa6_7_xor1;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_fa6_7_or0;
  wire [0:0] h_u_csabam8_pg_rca_h4_v7_and7_7;
  wire [7:0] h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a;
  wire [7:0] h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b;
  wire [8:0] h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out;

  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and3_4(.a(a[3]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v7_and3_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and4_4(.a(a[4]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v7_and4_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and5_4(.a(a[5]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v7_and5_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and6_4(.a(a[6]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v7_and6_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and7_4(.a(a[7]), .b(b[4]), .out(h_u_csabam8_pg_rca_h4_v7_and7_4));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and2_5(.a(a[2]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v7_and2_5));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha2_5_out(.a(h_u_csabam8_pg_rca_h4_v7_and2_5[0]), .b(h_u_csabam8_pg_rca_h4_v7_and3_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha2_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha2_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and3_5(.a(a[3]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v7_and3_5));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha3_5_out(.a(h_u_csabam8_pg_rca_h4_v7_and3_5[0]), .b(h_u_csabam8_pg_rca_h4_v7_and4_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha3_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha3_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and4_5(.a(a[4]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v7_and4_5));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha4_5_out(.a(h_u_csabam8_pg_rca_h4_v7_and4_5[0]), .b(h_u_csabam8_pg_rca_h4_v7_and5_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha4_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha4_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and5_5(.a(a[5]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v7_and5_5));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha5_5_out(.a(h_u_csabam8_pg_rca_h4_v7_and5_5[0]), .b(h_u_csabam8_pg_rca_h4_v7_and6_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha5_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha5_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and6_5(.a(a[6]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v7_and6_5));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha6_5_out(.a(h_u_csabam8_pg_rca_h4_v7_and6_5[0]), .b(h_u_csabam8_pg_rca_h4_v7_and7_4[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha6_5_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha6_5_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and7_5(.a(a[7]), .b(b[5]), .out(h_u_csabam8_pg_rca_h4_v7_and7_5));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and1_6(.a(a[1]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and1_6));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha1_6_out(.a(h_u_csabam8_pg_rca_h4_v7_and1_6[0]), .b(h_u_csabam8_pg_rca_h4_v7_ha2_5_xor0[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha1_6_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha1_6_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and2_6(.a(a[2]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and2_6));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa2_6_out(.a(h_u_csabam8_pg_rca_h4_v7_and2_6[0]), .b(h_u_csabam8_pg_rca_h4_v7_ha3_5_xor0[0]), .cin(h_u_csabam8_pg_rca_h4_v7_ha2_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa2_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa2_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and3_6(.a(a[3]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and3_6));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa3_6_out(.a(h_u_csabam8_pg_rca_h4_v7_and3_6[0]), .b(h_u_csabam8_pg_rca_h4_v7_ha4_5_xor0[0]), .cin(h_u_csabam8_pg_rca_h4_v7_ha3_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa3_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa3_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and4_6(.a(a[4]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and4_6));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa4_6_out(.a(h_u_csabam8_pg_rca_h4_v7_and4_6[0]), .b(h_u_csabam8_pg_rca_h4_v7_ha5_5_xor0[0]), .cin(h_u_csabam8_pg_rca_h4_v7_ha4_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa4_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa4_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and5_6(.a(a[5]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and5_6));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa5_6_out(.a(h_u_csabam8_pg_rca_h4_v7_and5_6[0]), .b(h_u_csabam8_pg_rca_h4_v7_ha6_5_xor0[0]), .cin(h_u_csabam8_pg_rca_h4_v7_ha5_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa5_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa5_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and6_6));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa6_6_out(.a(h_u_csabam8_pg_rca_h4_v7_and6_6[0]), .b(h_u_csabam8_pg_rca_h4_v7_and7_5[0]), .cin(h_u_csabam8_pg_rca_h4_v7_ha6_5_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa6_6_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa6_6_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csabam8_pg_rca_h4_v7_and7_6));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and0_7(.a(a[0]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and0_7));
  ha ha_h_u_csabam8_pg_rca_h4_v7_ha0_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and0_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_ha1_6_xor0[0]), .ha_xor0(h_u_csabam8_pg_rca_h4_v7_ha0_7_xor0), .ha_and0(h_u_csabam8_pg_rca_h4_v7_ha0_7_and0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and1_7(.a(a[1]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and1_7));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa1_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and1_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_fa2_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v7_ha1_6_and0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa1_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa1_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and2_7(.a(a[2]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and2_7));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa2_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and2_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_fa3_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v7_fa2_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa2_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa2_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and3_7(.a(a[3]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and3_7));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa3_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and3_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_fa4_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v7_fa3_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa3_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa3_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and4_7(.a(a[4]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and4_7));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa4_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and4_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_fa5_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v7_fa4_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa4_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa4_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and5_7));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa5_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and5_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_fa6_6_xor1[0]), .cin(h_u_csabam8_pg_rca_h4_v7_fa5_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa5_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa5_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and6_7));
  fa fa_h_u_csabam8_pg_rca_h4_v7_fa6_7_out(.a(h_u_csabam8_pg_rca_h4_v7_and6_7[0]), .b(h_u_csabam8_pg_rca_h4_v7_and7_6[0]), .cin(h_u_csabam8_pg_rca_h4_v7_fa6_6_or0[0]), .fa_xor1(h_u_csabam8_pg_rca_h4_v7_fa6_7_xor1), .fa_or0(h_u_csabam8_pg_rca_h4_v7_fa6_7_or0));
  and_gate and_gate_h_u_csabam8_pg_rca_h4_v7_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_pg_rca_h4_v7_and7_7));
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[0] = h_u_csabam8_pg_rca_h4_v7_fa1_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[1] = h_u_csabam8_pg_rca_h4_v7_fa2_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[2] = h_u_csabam8_pg_rca_h4_v7_fa3_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[3] = h_u_csabam8_pg_rca_h4_v7_fa4_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[4] = h_u_csabam8_pg_rca_h4_v7_fa5_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[5] = h_u_csabam8_pg_rca_h4_v7_fa6_7_xor1[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[6] = h_u_csabam8_pg_rca_h4_v7_and7_7[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a[7] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[0] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[1] = h_u_csabam8_pg_rca_h4_v7_fa1_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[2] = h_u_csabam8_pg_rca_h4_v7_fa2_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[3] = h_u_csabam8_pg_rca_h4_v7_fa3_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[4] = h_u_csabam8_pg_rca_h4_v7_fa4_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[5] = h_u_csabam8_pg_rca_h4_v7_fa5_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[6] = h_u_csabam8_pg_rca_h4_v7_fa6_7_or0[0];
  assign h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b[7] = 1'b0;
  u_pg_rca8 u_pg_rca8_h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out(.a(h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_a), .b(h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_b), .u_pg_rca8_out(h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out));

  assign h_u_csabam8_pg_rca_h4_v7_out[0] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[1] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[2] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[3] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[4] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[5] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[6] = 1'b0;
  assign h_u_csabam8_pg_rca_h4_v7_out[7] = h_u_csabam8_pg_rca_h4_v7_ha0_7_xor0[0];
  assign h_u_csabam8_pg_rca_h4_v7_out[8] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[0];
  assign h_u_csabam8_pg_rca_h4_v7_out[9] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[1];
  assign h_u_csabam8_pg_rca_h4_v7_out[10] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[2];
  assign h_u_csabam8_pg_rca_h4_v7_out[11] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[3];
  assign h_u_csabam8_pg_rca_h4_v7_out[12] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[4];
  assign h_u_csabam8_pg_rca_h4_v7_out[13] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[5];
  assign h_u_csabam8_pg_rca_h4_v7_out[14] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[6];
  assign h_u_csabam8_pg_rca_h4_v7_out[15] = h_u_csabam8_pg_rca_h4_v7_u_pg_rca8_out[7];
endmodule