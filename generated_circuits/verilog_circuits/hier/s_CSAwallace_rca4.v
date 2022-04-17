module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module nand_gate(input a, input b, output out);
  assign out = ~(a & b);
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module not_gate(input a, output out);
  assign out = ~a;
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

module ha(input [0:0] a, input [0:0] b, output [0:0] ha_xor0, output [0:0] ha_and0);
  xor_gate xor_gate_ha_xor0(.a(a[0]), .b(b[0]), .out(ha_xor0));
  and_gate and_gate_ha_and0(.a(a[0]), .b(b[0]), .out(ha_and0));
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

module u_rca8(input [7:0] a, input [7:0] b, output [8:0] u_rca8_out);
  wire [0:0] u_rca8_ha_xor0;
  wire [0:0] u_rca8_ha_and0;
  wire [0:0] u_rca8_fa1_xor1;
  wire [0:0] u_rca8_fa1_or0;
  wire [0:0] u_rca8_fa2_xor1;
  wire [0:0] u_rca8_fa2_or0;
  wire [0:0] u_rca8_fa3_xor1;
  wire [0:0] u_rca8_fa3_or0;
  wire [0:0] u_rca8_fa4_xor1;
  wire [0:0] u_rca8_fa4_or0;
  wire [0:0] u_rca8_fa5_xor1;
  wire [0:0] u_rca8_fa5_or0;
  wire [0:0] u_rca8_fa6_xor1;
  wire [0:0] u_rca8_fa6_or0;
  wire [0:0] u_rca8_fa7_xor1;
  wire [0:0] u_rca8_fa7_or0;

  ha ha_u_rca8_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(u_rca8_ha_xor0), .ha_and0(u_rca8_ha_and0));
  fa fa_u_rca8_fa1_out(.a(a[1]), .b(b[1]), .cin(u_rca8_ha_and0[0]), .fa_xor1(u_rca8_fa1_xor1), .fa_or0(u_rca8_fa1_or0));
  fa fa_u_rca8_fa2_out(.a(a[2]), .b(b[2]), .cin(u_rca8_fa1_or0[0]), .fa_xor1(u_rca8_fa2_xor1), .fa_or0(u_rca8_fa2_or0));
  fa fa_u_rca8_fa3_out(.a(a[3]), .b(b[3]), .cin(u_rca8_fa2_or0[0]), .fa_xor1(u_rca8_fa3_xor1), .fa_or0(u_rca8_fa3_or0));
  fa fa_u_rca8_fa4_out(.a(a[4]), .b(b[4]), .cin(u_rca8_fa3_or0[0]), .fa_xor1(u_rca8_fa4_xor1), .fa_or0(u_rca8_fa4_or0));
  fa fa_u_rca8_fa5_out(.a(a[5]), .b(b[5]), .cin(u_rca8_fa4_or0[0]), .fa_xor1(u_rca8_fa5_xor1), .fa_or0(u_rca8_fa5_or0));
  fa fa_u_rca8_fa6_out(.a(a[6]), .b(b[6]), .cin(u_rca8_fa5_or0[0]), .fa_xor1(u_rca8_fa6_xor1), .fa_or0(u_rca8_fa6_or0));
  fa fa_u_rca8_fa7_out(.a(a[7]), .b(b[7]), .cin(u_rca8_fa6_or0[0]), .fa_xor1(u_rca8_fa7_xor1), .fa_or0(u_rca8_fa7_or0));

  assign u_rca8_out[0] = u_rca8_ha_xor0[0];
  assign u_rca8_out[1] = u_rca8_fa1_xor1[0];
  assign u_rca8_out[2] = u_rca8_fa2_xor1[0];
  assign u_rca8_out[3] = u_rca8_fa3_xor1[0];
  assign u_rca8_out[4] = u_rca8_fa4_xor1[0];
  assign u_rca8_out[5] = u_rca8_fa5_xor1[0];
  assign u_rca8_out[6] = u_rca8_fa6_xor1[0];
  assign u_rca8_out[7] = u_rca8_fa7_xor1[0];
  assign u_rca8_out[8] = u_rca8_fa7_or0[0];
endmodule

module s_CSAwallace_rca4(input [3:0] a, input [3:0] b, output [7:0] s_CSAwallace_rca4_out);
  wire [0:0] s_CSAwallace_rca4_and_0_0;
  wire [0:0] s_CSAwallace_rca4_and_1_0;
  wire [0:0] s_CSAwallace_rca4_and_2_0;
  wire [0:0] s_CSAwallace_rca4_nand_3_0;
  wire [0:0] s_CSAwallace_rca4_and_0_1;
  wire [0:0] s_CSAwallace_rca4_and_1_1;
  wire [0:0] s_CSAwallace_rca4_and_2_1;
  wire [0:0] s_CSAwallace_rca4_nand_3_1;
  wire [0:0] s_CSAwallace_rca4_and_0_2;
  wire [0:0] s_CSAwallace_rca4_and_1_2;
  wire [0:0] s_CSAwallace_rca4_and_2_2;
  wire [0:0] s_CSAwallace_rca4_nand_3_2;
  wire [0:0] s_CSAwallace_rca4_nand_0_3;
  wire [0:0] s_CSAwallace_rca4_nand_1_3;
  wire [0:0] s_CSAwallace_rca4_nand_2_3;
  wire [0:0] s_CSAwallace_rca4_and_3_3;
  wire [5:0] s_CSAwallace_rca4_csa0_csa_component_pp_row0;
  wire [5:0] s_CSAwallace_rca4_csa0_csa_component_pp_row1;
  wire [5:0] s_CSAwallace_rca4_csa0_csa_component_pp_row2;
  wire [13:0] s_CSAwallace_rca4_csa0_csa_component_out;
  wire [6:0] s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1;
  wire [6:0] s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1;
  wire [6:0] s_CSAwallace_rca4_csa1_csa_component_pp_row3;
  wire [15:0] s_CSAwallace_rca4_csa1_csa_component_out;
  wire [7:0] s_CSAwallace_rca4_u_rca8_a;
  wire [7:0] s_CSAwallace_rca4_u_rca8_b;
  wire [8:0] s_CSAwallace_rca4_u_rca8_out;
  wire [0:0] s_CSAwallace_rca4_xor0;

  and_gate and_gate_s_CSAwallace_rca4_and_0_0(.a(a[0]), .b(b[0]), .out(s_CSAwallace_rca4_and_0_0));
  and_gate and_gate_s_CSAwallace_rca4_and_1_0(.a(a[1]), .b(b[0]), .out(s_CSAwallace_rca4_and_1_0));
  and_gate and_gate_s_CSAwallace_rca4_and_2_0(.a(a[2]), .b(b[0]), .out(s_CSAwallace_rca4_and_2_0));
  nand_gate nand_gate_s_CSAwallace_rca4_nand_3_0(.a(a[3]), .b(b[0]), .out(s_CSAwallace_rca4_nand_3_0));
  and_gate and_gate_s_CSAwallace_rca4_and_0_1(.a(a[0]), .b(b[1]), .out(s_CSAwallace_rca4_and_0_1));
  and_gate and_gate_s_CSAwallace_rca4_and_1_1(.a(a[1]), .b(b[1]), .out(s_CSAwallace_rca4_and_1_1));
  and_gate and_gate_s_CSAwallace_rca4_and_2_1(.a(a[2]), .b(b[1]), .out(s_CSAwallace_rca4_and_2_1));
  nand_gate nand_gate_s_CSAwallace_rca4_nand_3_1(.a(a[3]), .b(b[1]), .out(s_CSAwallace_rca4_nand_3_1));
  and_gate and_gate_s_CSAwallace_rca4_and_0_2(.a(a[0]), .b(b[2]), .out(s_CSAwallace_rca4_and_0_2));
  and_gate and_gate_s_CSAwallace_rca4_and_1_2(.a(a[1]), .b(b[2]), .out(s_CSAwallace_rca4_and_1_2));
  and_gate and_gate_s_CSAwallace_rca4_and_2_2(.a(a[2]), .b(b[2]), .out(s_CSAwallace_rca4_and_2_2));
  nand_gate nand_gate_s_CSAwallace_rca4_nand_3_2(.a(a[3]), .b(b[2]), .out(s_CSAwallace_rca4_nand_3_2));
  nand_gate nand_gate_s_CSAwallace_rca4_nand_0_3(.a(a[0]), .b(b[3]), .out(s_CSAwallace_rca4_nand_0_3));
  nand_gate nand_gate_s_CSAwallace_rca4_nand_1_3(.a(a[1]), .b(b[3]), .out(s_CSAwallace_rca4_nand_1_3));
  nand_gate nand_gate_s_CSAwallace_rca4_nand_2_3(.a(a[2]), .b(b[3]), .out(s_CSAwallace_rca4_nand_2_3));
  and_gate and_gate_s_CSAwallace_rca4_and_3_3(.a(a[3]), .b(b[3]), .out(s_CSAwallace_rca4_and_3_3));
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row0[0] = s_CSAwallace_rca4_and_0_0[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row0[1] = s_CSAwallace_rca4_and_1_0[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row0[2] = s_CSAwallace_rca4_and_2_0[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row0[3] = s_CSAwallace_rca4_nand_3_0[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row0[4] = 1'b1;
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row0[5] = 1'b1;
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row1[0] = 1'b0;
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row1[1] = s_CSAwallace_rca4_and_0_1[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row1[2] = s_CSAwallace_rca4_and_1_1[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row1[3] = s_CSAwallace_rca4_and_2_1[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row1[4] = s_CSAwallace_rca4_nand_3_1[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row1[5] = 1'b1;
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row2[0] = 1'b0;
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row2[1] = 1'b0;
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row2[2] = s_CSAwallace_rca4_and_0_2[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row2[3] = s_CSAwallace_rca4_and_1_2[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row2[4] = s_CSAwallace_rca4_and_2_2[0];
  assign s_CSAwallace_rca4_csa0_csa_component_pp_row2[5] = s_CSAwallace_rca4_nand_3_2[0];
  csa_component6 csa_component6_s_CSAwallace_rca4_csa0_csa_component_out(.a(s_CSAwallace_rca4_csa0_csa_component_pp_row0), .b(s_CSAwallace_rca4_csa0_csa_component_pp_row1), .c(s_CSAwallace_rca4_csa0_csa_component_pp_row2), .csa_component6_out(s_CSAwallace_rca4_csa0_csa_component_out));
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[0] = s_CSAwallace_rca4_csa0_csa_component_out[0];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[1] = s_CSAwallace_rca4_csa0_csa_component_out[1];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[2] = s_CSAwallace_rca4_csa0_csa_component_out[2];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[3] = s_CSAwallace_rca4_csa0_csa_component_out[3];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[4] = s_CSAwallace_rca4_csa0_csa_component_out[4];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[5] = s_CSAwallace_rca4_csa0_csa_component_out[5];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1[6] = 1'b1;
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[0] = 1'b0;
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[1] = 1'b0;
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[2] = s_CSAwallace_rca4_csa0_csa_component_out[9];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[3] = s_CSAwallace_rca4_csa0_csa_component_out[10];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[4] = s_CSAwallace_rca4_csa0_csa_component_out[11];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[5] = s_CSAwallace_rca4_csa0_csa_component_out[12];
  assign s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1[6] = 1'b1;
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[0] = 1'b0;
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[1] = 1'b0;
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[2] = 1'b0;
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[3] = s_CSAwallace_rca4_nand_0_3[0];
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[4] = s_CSAwallace_rca4_nand_1_3[0];
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[5] = s_CSAwallace_rca4_nand_2_3[0];
  assign s_CSAwallace_rca4_csa1_csa_component_pp_row3[6] = s_CSAwallace_rca4_and_3_3[0];
  csa_component7 csa_component7_s_CSAwallace_rca4_csa1_csa_component_out(.a(s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1), .b(s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1), .c(s_CSAwallace_rca4_csa1_csa_component_pp_row3), .csa_component7_out(s_CSAwallace_rca4_csa1_csa_component_out));
  assign s_CSAwallace_rca4_u_rca8_a[0] = s_CSAwallace_rca4_csa1_csa_component_out[0];
  assign s_CSAwallace_rca4_u_rca8_a[1] = s_CSAwallace_rca4_csa1_csa_component_out[1];
  assign s_CSAwallace_rca4_u_rca8_a[2] = s_CSAwallace_rca4_csa1_csa_component_out[2];
  assign s_CSAwallace_rca4_u_rca8_a[3] = s_CSAwallace_rca4_csa1_csa_component_out[3];
  assign s_CSAwallace_rca4_u_rca8_a[4] = s_CSAwallace_rca4_csa1_csa_component_out[4];
  assign s_CSAwallace_rca4_u_rca8_a[5] = s_CSAwallace_rca4_csa1_csa_component_out[5];
  assign s_CSAwallace_rca4_u_rca8_a[6] = s_CSAwallace_rca4_csa1_csa_component_out[6];
  assign s_CSAwallace_rca4_u_rca8_a[7] = 1'b1;
  assign s_CSAwallace_rca4_u_rca8_b[0] = 1'b0;
  assign s_CSAwallace_rca4_u_rca8_b[1] = 1'b0;
  assign s_CSAwallace_rca4_u_rca8_b[2] = 1'b0;
  assign s_CSAwallace_rca4_u_rca8_b[3] = s_CSAwallace_rca4_csa1_csa_component_out[11];
  assign s_CSAwallace_rca4_u_rca8_b[4] = s_CSAwallace_rca4_csa1_csa_component_out[12];
  assign s_CSAwallace_rca4_u_rca8_b[5] = s_CSAwallace_rca4_csa1_csa_component_out[13];
  assign s_CSAwallace_rca4_u_rca8_b[6] = s_CSAwallace_rca4_csa1_csa_component_out[14];
  assign s_CSAwallace_rca4_u_rca8_b[7] = 1'b1;
  u_rca8 u_rca8_s_CSAwallace_rca4_u_rca8_out(.a(s_CSAwallace_rca4_u_rca8_a), .b(s_CSAwallace_rca4_u_rca8_b), .u_rca8_out(s_CSAwallace_rca4_u_rca8_out));
  not_gate not_gate_s_CSAwallace_rca4_xor0(.a(s_CSAwallace_rca4_u_rca8_out[7]), .out(s_CSAwallace_rca4_xor0));

  assign s_CSAwallace_rca4_out[0] = s_CSAwallace_rca4_u_rca8_out[0];
  assign s_CSAwallace_rca4_out[1] = s_CSAwallace_rca4_u_rca8_out[1];
  assign s_CSAwallace_rca4_out[2] = s_CSAwallace_rca4_u_rca8_out[2];
  assign s_CSAwallace_rca4_out[3] = s_CSAwallace_rca4_u_rca8_out[3];
  assign s_CSAwallace_rca4_out[4] = s_CSAwallace_rca4_u_rca8_out[4];
  assign s_CSAwallace_rca4_out[5] = s_CSAwallace_rca4_u_rca8_out[5];
  assign s_CSAwallace_rca4_out[6] = s_CSAwallace_rca4_u_rca8_out[6];
  assign s_CSAwallace_rca4_out[7] = s_CSAwallace_rca4_xor0[0];
endmodule