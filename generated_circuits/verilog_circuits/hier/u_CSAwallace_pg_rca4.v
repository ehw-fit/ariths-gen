module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
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

module csa_component6(input [5:0] a, input [5:0] b, input [5:0] c, output [13:0] csa_component6_out);
  wire [0:0] csa_component6_fa0_xor1;
  wire [0:0] csa_component6_fa0_or0;
  wire [0:0] csa_component6_fa1_xor1;
  wire [0:0] csa_component6_fa1_or0;
  wire [0:0] csa_component6_fa2_xor1;
  wire [0:0] csa_component6_fa2_or0;
  wire [0:0] csa_component6_fa3_xor1;
  wire [0:0] csa_component6_fa3_or0;
  wire [0:0] csa_component6_fa4_xor1;
  wire [0:0] csa_component6_fa4_or0;
  wire [0:0] csa_component6_fa5_xor1;
  wire [0:0] csa_component6_fa5_or0;

  fa fa_csa_component6_fa0_out(.a(a[0]), .b(b[0]), .cin(c[0]), .fa_xor1(csa_component6_fa0_xor1), .fa_or0(csa_component6_fa0_or0));
  fa fa_csa_component6_fa1_out(.a(a[1]), .b(b[1]), .cin(c[1]), .fa_xor1(csa_component6_fa1_xor1), .fa_or0(csa_component6_fa1_or0));
  fa fa_csa_component6_fa2_out(.a(a[2]), .b(b[2]), .cin(c[2]), .fa_xor1(csa_component6_fa2_xor1), .fa_or0(csa_component6_fa2_or0));
  fa fa_csa_component6_fa3_out(.a(a[3]), .b(b[3]), .cin(c[3]), .fa_xor1(csa_component6_fa3_xor1), .fa_or0(csa_component6_fa3_or0));
  fa fa_csa_component6_fa4_out(.a(a[4]), .b(b[4]), .cin(c[4]), .fa_xor1(csa_component6_fa4_xor1), .fa_or0(csa_component6_fa4_or0));
  fa fa_csa_component6_fa5_out(.a(a[5]), .b(b[5]), .cin(c[5]), .fa_xor1(csa_component6_fa5_xor1), .fa_or0(csa_component6_fa5_or0));

  assign csa_component6_out[0] = csa_component6_fa0_xor1[0];
  assign csa_component6_out[1] = csa_component6_fa1_xor1[0];
  assign csa_component6_out[2] = csa_component6_fa2_xor1[0];
  assign csa_component6_out[3] = csa_component6_fa3_xor1[0];
  assign csa_component6_out[4] = csa_component6_fa4_xor1[0];
  assign csa_component6_out[5] = csa_component6_fa5_xor1[0];
  assign csa_component6_out[6] = 1'b0;
  assign csa_component6_out[7] = 1'b0;
  assign csa_component6_out[8] = csa_component6_fa0_or0[0];
  assign csa_component6_out[9] = csa_component6_fa1_or0[0];
  assign csa_component6_out[10] = csa_component6_fa2_or0[0];
  assign csa_component6_out[11] = csa_component6_fa3_or0[0];
  assign csa_component6_out[12] = csa_component6_fa4_or0[0];
  assign csa_component6_out[13] = csa_component6_fa5_or0[0];
endmodule

module csa_component7(input [6:0] a, input [6:0] b, input [6:0] c, output [15:0] csa_component7_out);
  wire [0:0] csa_component7_fa0_xor1;
  wire [0:0] csa_component7_fa0_or0;
  wire [0:0] csa_component7_fa1_xor1;
  wire [0:0] csa_component7_fa1_or0;
  wire [0:0] csa_component7_fa2_xor1;
  wire [0:0] csa_component7_fa2_or0;
  wire [0:0] csa_component7_fa3_xor1;
  wire [0:0] csa_component7_fa3_or0;
  wire [0:0] csa_component7_fa4_xor1;
  wire [0:0] csa_component7_fa4_or0;
  wire [0:0] csa_component7_fa5_xor1;
  wire [0:0] csa_component7_fa5_or0;
  wire [0:0] csa_component7_fa6_xor1;
  wire [0:0] csa_component7_fa6_or0;

  fa fa_csa_component7_fa0_out(.a(a[0]), .b(b[0]), .cin(c[0]), .fa_xor1(csa_component7_fa0_xor1), .fa_or0(csa_component7_fa0_or0));
  fa fa_csa_component7_fa1_out(.a(a[1]), .b(b[1]), .cin(c[1]), .fa_xor1(csa_component7_fa1_xor1), .fa_or0(csa_component7_fa1_or0));
  fa fa_csa_component7_fa2_out(.a(a[2]), .b(b[2]), .cin(c[2]), .fa_xor1(csa_component7_fa2_xor1), .fa_or0(csa_component7_fa2_or0));
  fa fa_csa_component7_fa3_out(.a(a[3]), .b(b[3]), .cin(c[3]), .fa_xor1(csa_component7_fa3_xor1), .fa_or0(csa_component7_fa3_or0));
  fa fa_csa_component7_fa4_out(.a(a[4]), .b(b[4]), .cin(c[4]), .fa_xor1(csa_component7_fa4_xor1), .fa_or0(csa_component7_fa4_or0));
  fa fa_csa_component7_fa5_out(.a(a[5]), .b(b[5]), .cin(c[5]), .fa_xor1(csa_component7_fa5_xor1), .fa_or0(csa_component7_fa5_or0));
  fa fa_csa_component7_fa6_out(.a(a[6]), .b(b[6]), .cin(c[6]), .fa_xor1(csa_component7_fa6_xor1), .fa_or0(csa_component7_fa6_or0));

  assign csa_component7_out[0] = csa_component7_fa0_xor1[0];
  assign csa_component7_out[1] = csa_component7_fa1_xor1[0];
  assign csa_component7_out[2] = csa_component7_fa2_xor1[0];
  assign csa_component7_out[3] = csa_component7_fa3_xor1[0];
  assign csa_component7_out[4] = csa_component7_fa4_xor1[0];
  assign csa_component7_out[5] = csa_component7_fa5_xor1[0];
  assign csa_component7_out[6] = csa_component7_fa6_xor1[0];
  assign csa_component7_out[7] = 1'b0;
  assign csa_component7_out[8] = 1'b0;
  assign csa_component7_out[9] = csa_component7_fa0_or0[0];
  assign csa_component7_out[10] = csa_component7_fa1_or0[0];
  assign csa_component7_out[11] = csa_component7_fa2_or0[0];
  assign csa_component7_out[12] = csa_component7_fa3_or0[0];
  assign csa_component7_out[13] = csa_component7_fa4_or0[0];
  assign csa_component7_out[14] = csa_component7_fa5_or0[0];
  assign csa_component7_out[15] = csa_component7_fa6_or0[0];
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

module u_CSAwallace_pg_rca4(input [3:0] a, input [3:0] b, output [7:0] u_CSAwallace_pg_rca4_out);
  wire [0:0] u_CSAwallace_pg_rca4_and_0_0;
  wire [0:0] u_CSAwallace_pg_rca4_and_1_0;
  wire [0:0] u_CSAwallace_pg_rca4_and_2_0;
  wire [0:0] u_CSAwallace_pg_rca4_and_3_0;
  wire [0:0] u_CSAwallace_pg_rca4_and_0_1;
  wire [0:0] u_CSAwallace_pg_rca4_and_1_1;
  wire [0:0] u_CSAwallace_pg_rca4_and_2_1;
  wire [0:0] u_CSAwallace_pg_rca4_and_3_1;
  wire [0:0] u_CSAwallace_pg_rca4_and_0_2;
  wire [0:0] u_CSAwallace_pg_rca4_and_1_2;
  wire [0:0] u_CSAwallace_pg_rca4_and_2_2;
  wire [0:0] u_CSAwallace_pg_rca4_and_3_2;
  wire [0:0] u_CSAwallace_pg_rca4_and_0_3;
  wire [0:0] u_CSAwallace_pg_rca4_and_1_3;
  wire [0:0] u_CSAwallace_pg_rca4_and_2_3;
  wire [0:0] u_CSAwallace_pg_rca4_and_3_3;
  wire [5:0] u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0;
  wire [5:0] u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1;
  wire [5:0] u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2;
  wire [13:0] u_CSAwallace_pg_rca4_csa0_csa_component_out;
  wire [6:0] u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1;
  wire [6:0] u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1;
  wire [6:0] u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3;
  wire [15:0] u_CSAwallace_pg_rca4_csa1_csa_component_out;
  wire [7:0] u_CSAwallace_pg_rca4_u_pg_rca8_a;
  wire [7:0] u_CSAwallace_pg_rca4_u_pg_rca8_b;
  wire [8:0] u_CSAwallace_pg_rca4_u_pg_rca8_out;

  and_gate and_gate_u_CSAwallace_pg_rca4_and_0_0(.a(a[0]), .b(b[0]), .out(u_CSAwallace_pg_rca4_and_0_0));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_1_0(.a(a[1]), .b(b[0]), .out(u_CSAwallace_pg_rca4_and_1_0));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_2_0(.a(a[2]), .b(b[0]), .out(u_CSAwallace_pg_rca4_and_2_0));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_3_0(.a(a[3]), .b(b[0]), .out(u_CSAwallace_pg_rca4_and_3_0));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_0_1(.a(a[0]), .b(b[1]), .out(u_CSAwallace_pg_rca4_and_0_1));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_1_1(.a(a[1]), .b(b[1]), .out(u_CSAwallace_pg_rca4_and_1_1));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_2_1(.a(a[2]), .b(b[1]), .out(u_CSAwallace_pg_rca4_and_2_1));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_3_1(.a(a[3]), .b(b[1]), .out(u_CSAwallace_pg_rca4_and_3_1));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_0_2(.a(a[0]), .b(b[2]), .out(u_CSAwallace_pg_rca4_and_0_2));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_1_2(.a(a[1]), .b(b[2]), .out(u_CSAwallace_pg_rca4_and_1_2));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_2_2(.a(a[2]), .b(b[2]), .out(u_CSAwallace_pg_rca4_and_2_2));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_3_2(.a(a[3]), .b(b[2]), .out(u_CSAwallace_pg_rca4_and_3_2));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_0_3(.a(a[0]), .b(b[3]), .out(u_CSAwallace_pg_rca4_and_0_3));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_1_3(.a(a[1]), .b(b[3]), .out(u_CSAwallace_pg_rca4_and_1_3));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_2_3(.a(a[2]), .b(b[3]), .out(u_CSAwallace_pg_rca4_and_2_3));
  and_gate and_gate_u_CSAwallace_pg_rca4_and_3_3(.a(a[3]), .b(b[3]), .out(u_CSAwallace_pg_rca4_and_3_3));
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0[0] = u_CSAwallace_pg_rca4_and_0_0[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0[1] = u_CSAwallace_pg_rca4_and_1_0[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0[2] = u_CSAwallace_pg_rca4_and_2_0[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0[3] = u_CSAwallace_pg_rca4_and_3_0[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0[4] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0[5] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1[0] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1[1] = u_CSAwallace_pg_rca4_and_0_1[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1[2] = u_CSAwallace_pg_rca4_and_1_1[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1[3] = u_CSAwallace_pg_rca4_and_2_1[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1[4] = u_CSAwallace_pg_rca4_and_3_1[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1[5] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2[0] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2[1] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2[2] = u_CSAwallace_pg_rca4_and_0_2[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2[3] = u_CSAwallace_pg_rca4_and_1_2[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2[4] = u_CSAwallace_pg_rca4_and_2_2[0];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2[5] = u_CSAwallace_pg_rca4_and_3_2[0];
  csa_component6 csa_component6_u_CSAwallace_pg_rca4_csa0_csa_component_out(.a(u_CSAwallace_pg_rca4_csa0_csa_component_pp_row0), .b(u_CSAwallace_pg_rca4_csa0_csa_component_pp_row1), .c(u_CSAwallace_pg_rca4_csa0_csa_component_pp_row2), .csa_component6_out(u_CSAwallace_pg_rca4_csa0_csa_component_out));
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[0] = u_CSAwallace_pg_rca4_csa0_csa_component_out[0];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[1] = u_CSAwallace_pg_rca4_csa0_csa_component_out[1];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[2] = u_CSAwallace_pg_rca4_csa0_csa_component_out[2];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[3] = u_CSAwallace_pg_rca4_csa0_csa_component_out[3];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[4] = u_CSAwallace_pg_rca4_csa0_csa_component_out[4];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[5] = u_CSAwallace_pg_rca4_csa0_csa_component_out[5];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1[6] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[0] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[1] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[2] = u_CSAwallace_pg_rca4_csa0_csa_component_out[9];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[3] = u_CSAwallace_pg_rca4_csa0_csa_component_out[10];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[4] = u_CSAwallace_pg_rca4_csa0_csa_component_out[11];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[5] = u_CSAwallace_pg_rca4_csa0_csa_component_out[12];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1[6] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[0] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[1] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[2] = 1'b0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[3] = u_CSAwallace_pg_rca4_and_0_3[0];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[4] = u_CSAwallace_pg_rca4_and_1_3[0];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[5] = u_CSAwallace_pg_rca4_and_2_3[0];
  assign u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3[6] = u_CSAwallace_pg_rca4_and_3_3[0];
  csa_component7 csa_component7_u_CSAwallace_pg_rca4_csa1_csa_component_out(.a(u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_s1), .b(u_CSAwallace_pg_rca4_csa1_csa_component_u_CSAwallace_pg_rca4_csa_c1), .c(u_CSAwallace_pg_rca4_csa1_csa_component_pp_row3), .csa_component7_out(u_CSAwallace_pg_rca4_csa1_csa_component_out));
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[0] = u_CSAwallace_pg_rca4_csa1_csa_component_out[0];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[1] = u_CSAwallace_pg_rca4_csa1_csa_component_out[1];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[2] = u_CSAwallace_pg_rca4_csa1_csa_component_out[2];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[3] = u_CSAwallace_pg_rca4_csa1_csa_component_out[3];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[4] = u_CSAwallace_pg_rca4_csa1_csa_component_out[4];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[5] = u_CSAwallace_pg_rca4_csa1_csa_component_out[5];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[6] = u_CSAwallace_pg_rca4_csa1_csa_component_out[6];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_a[7] = 1'b0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[0] = 1'b0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[1] = 1'b0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[2] = 1'b0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[3] = u_CSAwallace_pg_rca4_csa1_csa_component_out[11];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[4] = u_CSAwallace_pg_rca4_csa1_csa_component_out[12];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[5] = u_CSAwallace_pg_rca4_csa1_csa_component_out[13];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[6] = u_CSAwallace_pg_rca4_csa1_csa_component_out[14];
  assign u_CSAwallace_pg_rca4_u_pg_rca8_b[7] = 1'b0;
  u_pg_rca8 u_pg_rca8_u_CSAwallace_pg_rca4_u_pg_rca8_out(.a(u_CSAwallace_pg_rca4_u_pg_rca8_a), .b(u_CSAwallace_pg_rca4_u_pg_rca8_b), .u_pg_rca8_out(u_CSAwallace_pg_rca4_u_pg_rca8_out));

  assign u_CSAwallace_pg_rca4_out[0] = u_CSAwallace_pg_rca4_u_pg_rca8_out[0];
  assign u_CSAwallace_pg_rca4_out[1] = u_CSAwallace_pg_rca4_u_pg_rca8_out[1];
  assign u_CSAwallace_pg_rca4_out[2] = u_CSAwallace_pg_rca4_u_pg_rca8_out[2];
  assign u_CSAwallace_pg_rca4_out[3] = u_CSAwallace_pg_rca4_u_pg_rca8_out[3];
  assign u_CSAwallace_pg_rca4_out[4] = u_CSAwallace_pg_rca4_u_pg_rca8_out[4];
  assign u_CSAwallace_pg_rca4_out[5] = u_CSAwallace_pg_rca4_u_pg_rca8_out[5];
  assign u_CSAwallace_pg_rca4_out[6] = u_CSAwallace_pg_rca4_u_pg_rca8_out[6];
  assign u_CSAwallace_pg_rca4_out[7] = u_CSAwallace_pg_rca4_u_pg_rca8_out[7];
endmodule