module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module nand_gate(input a, input b, output out);
  assign out = ~(a & b);
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module not_gate(input a, output out);
  assign out = ~a;
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

module u_rca6(input [5:0] a, input [5:0] b, output [6:0] u_rca6_out);
  wire [0:0] u_rca6_ha_xor0;
  wire [0:0] u_rca6_ha_and0;
  wire [0:0] u_rca6_fa1_xor1;
  wire [0:0] u_rca6_fa1_or0;
  wire [0:0] u_rca6_fa2_xor1;
  wire [0:0] u_rca6_fa2_or0;
  wire [0:0] u_rca6_fa3_xor1;
  wire [0:0] u_rca6_fa3_or0;
  wire [0:0] u_rca6_fa4_xor1;
  wire [0:0] u_rca6_fa4_or0;
  wire [0:0] u_rca6_fa5_xor1;
  wire [0:0] u_rca6_fa5_or0;

  ha ha_u_rca6_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(u_rca6_ha_xor0), .ha_and0(u_rca6_ha_and0));
  fa fa_u_rca6_fa1_out(.a(a[1]), .b(b[1]), .cin(u_rca6_ha_and0[0]), .fa_xor1(u_rca6_fa1_xor1), .fa_or0(u_rca6_fa1_or0));
  fa fa_u_rca6_fa2_out(.a(a[2]), .b(b[2]), .cin(u_rca6_fa1_or0[0]), .fa_xor1(u_rca6_fa2_xor1), .fa_or0(u_rca6_fa2_or0));
  fa fa_u_rca6_fa3_out(.a(a[3]), .b(b[3]), .cin(u_rca6_fa2_or0[0]), .fa_xor1(u_rca6_fa3_xor1), .fa_or0(u_rca6_fa3_or0));
  fa fa_u_rca6_fa4_out(.a(a[4]), .b(b[4]), .cin(u_rca6_fa3_or0[0]), .fa_xor1(u_rca6_fa4_xor1), .fa_or0(u_rca6_fa4_or0));
  fa fa_u_rca6_fa5_out(.a(a[5]), .b(b[5]), .cin(u_rca6_fa4_or0[0]), .fa_xor1(u_rca6_fa5_xor1), .fa_or0(u_rca6_fa5_or0));

  assign u_rca6_out[0] = u_rca6_ha_xor0[0];
  assign u_rca6_out[1] = u_rca6_fa1_xor1[0];
  assign u_rca6_out[2] = u_rca6_fa2_xor1[0];
  assign u_rca6_out[3] = u_rca6_fa3_xor1[0];
  assign u_rca6_out[4] = u_rca6_fa4_xor1[0];
  assign u_rca6_out[5] = u_rca6_fa5_xor1[0];
  assign u_rca6_out[6] = u_rca6_fa5_or0[0];
endmodule

module h_s_wallace_rca4(input [3:0] a, input [3:0] b, output [7:0] h_s_wallace_rca4_out);
  wire [0:0] h_s_wallace_rca4_and_2_0;
  wire [0:0] h_s_wallace_rca4_and_1_1;
  wire [0:0] h_s_wallace_rca4_ha0_xor0;
  wire [0:0] h_s_wallace_rca4_ha0_and0;
  wire [0:0] h_s_wallace_rca4_nand_3_0;
  wire [0:0] h_s_wallace_rca4_and_2_1;
  wire [0:0] h_s_wallace_rca4_fa0_xor1;
  wire [0:0] h_s_wallace_rca4_fa0_or0;
  wire [0:0] h_s_wallace_rca4_nand_3_1;
  wire [0:0] h_s_wallace_rca4_fa1_xor1;
  wire [0:0] h_s_wallace_rca4_fa1_or0;
  wire [0:0] h_s_wallace_rca4_and_1_2;
  wire [0:0] h_s_wallace_rca4_nand_0_3;
  wire [0:0] h_s_wallace_rca4_ha1_xor0;
  wire [0:0] h_s_wallace_rca4_ha1_and0;
  wire [0:0] h_s_wallace_rca4_and_2_2;
  wire [0:0] h_s_wallace_rca4_nand_1_3;
  wire [0:0] h_s_wallace_rca4_fa2_xor1;
  wire [0:0] h_s_wallace_rca4_fa2_or0;
  wire [0:0] h_s_wallace_rca4_nand_3_2;
  wire [0:0] h_s_wallace_rca4_fa3_xor1;
  wire [0:0] h_s_wallace_rca4_fa3_or0;
  wire [0:0] h_s_wallace_rca4_and_0_0;
  wire [0:0] h_s_wallace_rca4_and_1_0;
  wire [0:0] h_s_wallace_rca4_and_0_2;
  wire [0:0] h_s_wallace_rca4_nand_2_3;
  wire [0:0] h_s_wallace_rca4_and_0_1;
  wire [0:0] h_s_wallace_rca4_and_3_3;
  wire [5:0] h_s_wallace_rca4_u_rca6_a;
  wire [5:0] h_s_wallace_rca4_u_rca6_b;
  wire [6:0] h_s_wallace_rca4_u_rca6_out;
  wire [0:0] h_s_wallace_rca4_xor0;

  and_gate and_gate_h_s_wallace_rca4_and_2_0(.a(a[2]), .b(b[0]), .out(h_s_wallace_rca4_and_2_0));
  and_gate and_gate_h_s_wallace_rca4_and_1_1(.a(a[1]), .b(b[1]), .out(h_s_wallace_rca4_and_1_1));
  ha ha_h_s_wallace_rca4_ha0_out(.a(h_s_wallace_rca4_and_2_0[0]), .b(h_s_wallace_rca4_and_1_1[0]), .ha_xor0(h_s_wallace_rca4_ha0_xor0), .ha_and0(h_s_wallace_rca4_ha0_and0));
  nand_gate nand_gate_h_s_wallace_rca4_nand_3_0(.a(a[3]), .b(b[0]), .out(h_s_wallace_rca4_nand_3_0));
  and_gate and_gate_h_s_wallace_rca4_and_2_1(.a(a[2]), .b(b[1]), .out(h_s_wallace_rca4_and_2_1));
  fa fa_h_s_wallace_rca4_fa0_out(.a(h_s_wallace_rca4_ha0_and0[0]), .b(h_s_wallace_rca4_nand_3_0[0]), .cin(h_s_wallace_rca4_and_2_1[0]), .fa_xor1(h_s_wallace_rca4_fa0_xor1), .fa_or0(h_s_wallace_rca4_fa0_or0));
  nand_gate nand_gate_h_s_wallace_rca4_nand_3_1(.a(a[3]), .b(b[1]), .out(h_s_wallace_rca4_nand_3_1));
  fa fa_h_s_wallace_rca4_fa1_out(.a(h_s_wallace_rca4_fa0_or0[0]), .b(1'b1), .cin(h_s_wallace_rca4_nand_3_1[0]), .fa_xor1(h_s_wallace_rca4_fa1_xor1), .fa_or0(h_s_wallace_rca4_fa1_or0));
  and_gate and_gate_h_s_wallace_rca4_and_1_2(.a(a[1]), .b(b[2]), .out(h_s_wallace_rca4_and_1_2));
  nand_gate nand_gate_h_s_wallace_rca4_nand_0_3(.a(a[0]), .b(b[3]), .out(h_s_wallace_rca4_nand_0_3));
  ha ha_h_s_wallace_rca4_ha1_out(.a(h_s_wallace_rca4_and_1_2[0]), .b(h_s_wallace_rca4_nand_0_3[0]), .ha_xor0(h_s_wallace_rca4_ha1_xor0), .ha_and0(h_s_wallace_rca4_ha1_and0));
  and_gate and_gate_h_s_wallace_rca4_and_2_2(.a(a[2]), .b(b[2]), .out(h_s_wallace_rca4_and_2_2));
  nand_gate nand_gate_h_s_wallace_rca4_nand_1_3(.a(a[1]), .b(b[3]), .out(h_s_wallace_rca4_nand_1_3));
  fa fa_h_s_wallace_rca4_fa2_out(.a(h_s_wallace_rca4_ha1_and0[0]), .b(h_s_wallace_rca4_and_2_2[0]), .cin(h_s_wallace_rca4_nand_1_3[0]), .fa_xor1(h_s_wallace_rca4_fa2_xor1), .fa_or0(h_s_wallace_rca4_fa2_or0));
  nand_gate nand_gate_h_s_wallace_rca4_nand_3_2(.a(a[3]), .b(b[2]), .out(h_s_wallace_rca4_nand_3_2));
  fa fa_h_s_wallace_rca4_fa3_out(.a(h_s_wallace_rca4_fa2_or0[0]), .b(h_s_wallace_rca4_fa1_or0[0]), .cin(h_s_wallace_rca4_nand_3_2[0]), .fa_xor1(h_s_wallace_rca4_fa3_xor1), .fa_or0(h_s_wallace_rca4_fa3_or0));
  and_gate and_gate_h_s_wallace_rca4_and_0_0(.a(a[0]), .b(b[0]), .out(h_s_wallace_rca4_and_0_0));
  and_gate and_gate_h_s_wallace_rca4_and_1_0(.a(a[1]), .b(b[0]), .out(h_s_wallace_rca4_and_1_0));
  and_gate and_gate_h_s_wallace_rca4_and_0_2(.a(a[0]), .b(b[2]), .out(h_s_wallace_rca4_and_0_2));
  nand_gate nand_gate_h_s_wallace_rca4_nand_2_3(.a(a[2]), .b(b[3]), .out(h_s_wallace_rca4_nand_2_3));
  and_gate and_gate_h_s_wallace_rca4_and_0_1(.a(a[0]), .b(b[1]), .out(h_s_wallace_rca4_and_0_1));
  and_gate and_gate_h_s_wallace_rca4_and_3_3(.a(a[3]), .b(b[3]), .out(h_s_wallace_rca4_and_3_3));
  assign h_s_wallace_rca4_u_rca6_a[0] = h_s_wallace_rca4_and_1_0[0];
  assign h_s_wallace_rca4_u_rca6_a[1] = h_s_wallace_rca4_and_0_2[0];
  assign h_s_wallace_rca4_u_rca6_a[2] = h_s_wallace_rca4_fa0_xor1[0];
  assign h_s_wallace_rca4_u_rca6_a[3] = h_s_wallace_rca4_fa1_xor1[0];
  assign h_s_wallace_rca4_u_rca6_a[4] = h_s_wallace_rca4_nand_2_3[0];
  assign h_s_wallace_rca4_u_rca6_a[5] = h_s_wallace_rca4_fa3_or0[0];
  assign h_s_wallace_rca4_u_rca6_b[0] = h_s_wallace_rca4_and_0_1[0];
  assign h_s_wallace_rca4_u_rca6_b[1] = h_s_wallace_rca4_ha0_xor0[0];
  assign h_s_wallace_rca4_u_rca6_b[2] = h_s_wallace_rca4_ha1_xor0[0];
  assign h_s_wallace_rca4_u_rca6_b[3] = h_s_wallace_rca4_fa2_xor1[0];
  assign h_s_wallace_rca4_u_rca6_b[4] = h_s_wallace_rca4_fa3_xor1[0];
  assign h_s_wallace_rca4_u_rca6_b[5] = h_s_wallace_rca4_and_3_3[0];
  u_rca6 u_rca6_h_s_wallace_rca4_u_rca6_out(.a(h_s_wallace_rca4_u_rca6_a), .b(h_s_wallace_rca4_u_rca6_b), .u_rca6_out(h_s_wallace_rca4_u_rca6_out));
  not_gate not_gate_h_s_wallace_rca4_xor0(.a(h_s_wallace_rca4_u_rca6_out[6]), .out(h_s_wallace_rca4_xor0));

  assign h_s_wallace_rca4_out[0] = h_s_wallace_rca4_and_0_0[0];
  assign h_s_wallace_rca4_out[1] = h_s_wallace_rca4_u_rca6_out[0];
  assign h_s_wallace_rca4_out[2] = h_s_wallace_rca4_u_rca6_out[1];
  assign h_s_wallace_rca4_out[3] = h_s_wallace_rca4_u_rca6_out[2];
  assign h_s_wallace_rca4_out[4] = h_s_wallace_rca4_u_rca6_out[3];
  assign h_s_wallace_rca4_out[5] = h_s_wallace_rca4_u_rca6_out[4];
  assign h_s_wallace_rca4_out[6] = h_s_wallace_rca4_u_rca6_out[5];
  assign h_s_wallace_rca4_out[7] = h_s_wallace_rca4_xor0[0];
endmodule