module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module nand_gate(input a, input b, output out);
  assign out = ~(a & b);
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module not_gate(input a, output out);
  assign out = ~a;
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

module u_pg_rca4(input [3:0] a, input [3:0] b, output [4:0] u_pg_rca4_out);
  wire [0:0] u_pg_rca4_pg_fa0_xor0;
  wire [0:0] u_pg_rca4_pg_fa0_and0;
  wire [0:0] u_pg_rca4_pg_fa1_xor0;
  wire [0:0] u_pg_rca4_pg_fa1_and0;
  wire [0:0] u_pg_rca4_pg_fa1_xor1;
  wire [0:0] u_pg_rca4_and1;
  wire [0:0] u_pg_rca4_or1;
  wire [0:0] u_pg_rca4_pg_fa2_xor0;
  wire [0:0] u_pg_rca4_pg_fa2_and0;
  wire [0:0] u_pg_rca4_pg_fa2_xor1;
  wire [0:0] u_pg_rca4_and2;
  wire [0:0] u_pg_rca4_or2;
  wire [0:0] u_pg_rca4_pg_fa3_xor0;
  wire [0:0] u_pg_rca4_pg_fa3_and0;
  wire [0:0] u_pg_rca4_pg_fa3_xor1;
  wire [0:0] u_pg_rca4_and3;
  wire [0:0] u_pg_rca4_or3;

  pg_fa pg_fa_u_pg_rca4_pg_fa0_out(.a(a[0]), .b(b[0]), .cin(1'b0), .pg_fa_xor0(u_pg_rca4_pg_fa0_xor0), .pg_fa_and0(u_pg_rca4_pg_fa0_and0), .pg_fa_xor1());
  pg_fa pg_fa_u_pg_rca4_pg_fa1_out(.a(a[1]), .b(b[1]), .cin(u_pg_rca4_pg_fa0_and0[0]), .pg_fa_xor0(u_pg_rca4_pg_fa1_xor0), .pg_fa_and0(u_pg_rca4_pg_fa1_and0), .pg_fa_xor1(u_pg_rca4_pg_fa1_xor1));
  and_gate and_gate_u_pg_rca4_and1(.a(u_pg_rca4_pg_fa0_and0[0]), .b(u_pg_rca4_pg_fa1_xor0[0]), .out(u_pg_rca4_and1));
  or_gate or_gate_u_pg_rca4_or1(.a(u_pg_rca4_and1[0]), .b(u_pg_rca4_pg_fa1_and0[0]), .out(u_pg_rca4_or1));
  pg_fa pg_fa_u_pg_rca4_pg_fa2_out(.a(a[2]), .b(b[2]), .cin(u_pg_rca4_or1[0]), .pg_fa_xor0(u_pg_rca4_pg_fa2_xor0), .pg_fa_and0(u_pg_rca4_pg_fa2_and0), .pg_fa_xor1(u_pg_rca4_pg_fa2_xor1));
  and_gate and_gate_u_pg_rca4_and2(.a(u_pg_rca4_or1[0]), .b(u_pg_rca4_pg_fa2_xor0[0]), .out(u_pg_rca4_and2));
  or_gate or_gate_u_pg_rca4_or2(.a(u_pg_rca4_and2[0]), .b(u_pg_rca4_pg_fa2_and0[0]), .out(u_pg_rca4_or2));
  pg_fa pg_fa_u_pg_rca4_pg_fa3_out(.a(a[3]), .b(b[3]), .cin(u_pg_rca4_or2[0]), .pg_fa_xor0(u_pg_rca4_pg_fa3_xor0), .pg_fa_and0(u_pg_rca4_pg_fa3_and0), .pg_fa_xor1(u_pg_rca4_pg_fa3_xor1));
  and_gate and_gate_u_pg_rca4_and3(.a(u_pg_rca4_or2[0]), .b(u_pg_rca4_pg_fa3_xor0[0]), .out(u_pg_rca4_and3));
  or_gate or_gate_u_pg_rca4_or3(.a(u_pg_rca4_and3[0]), .b(u_pg_rca4_pg_fa3_and0[0]), .out(u_pg_rca4_or3));

  assign u_pg_rca4_out[0] = u_pg_rca4_pg_fa0_xor0[0];
  assign u_pg_rca4_out[1] = u_pg_rca4_pg_fa1_xor1[0];
  assign u_pg_rca4_out[2] = u_pg_rca4_pg_fa2_xor1[0];
  assign u_pg_rca4_out[3] = u_pg_rca4_pg_fa3_xor1[0];
  assign u_pg_rca4_out[4] = u_pg_rca4_or3[0];
endmodule

module s_csamul_pg_rca4(input [3:0] a, input [3:0] b, output [7:0] s_csamul_pg_rca4_out);
  wire [0:0] s_csamul_pg_rca4_and0_0;
  wire [0:0] s_csamul_pg_rca4_and1_0;
  wire [0:0] s_csamul_pg_rca4_and2_0;
  wire [0:0] s_csamul_pg_rca4_nand3_0;
  wire [0:0] s_csamul_pg_rca4_and0_1;
  wire [0:0] s_csamul_pg_rca4_ha0_1_xor0;
  wire [0:0] s_csamul_pg_rca4_ha0_1_and0;
  wire [0:0] s_csamul_pg_rca4_and1_1;
  wire [0:0] s_csamul_pg_rca4_ha1_1_xor0;
  wire [0:0] s_csamul_pg_rca4_ha1_1_and0;
  wire [0:0] s_csamul_pg_rca4_and2_1;
  wire [0:0] s_csamul_pg_rca4_ha2_1_xor0;
  wire [0:0] s_csamul_pg_rca4_ha2_1_and0;
  wire [0:0] s_csamul_pg_rca4_nand3_1;
  wire [0:0] s_csamul_pg_rca4_ha3_1_xor0;
  wire [0:0] s_csamul_pg_rca4_and0_2;
  wire [0:0] s_csamul_pg_rca4_fa0_2_xor1;
  wire [0:0] s_csamul_pg_rca4_fa0_2_or0;
  wire [0:0] s_csamul_pg_rca4_and1_2;
  wire [0:0] s_csamul_pg_rca4_fa1_2_xor1;
  wire [0:0] s_csamul_pg_rca4_fa1_2_or0;
  wire [0:0] s_csamul_pg_rca4_and2_2;
  wire [0:0] s_csamul_pg_rca4_fa2_2_xor1;
  wire [0:0] s_csamul_pg_rca4_fa2_2_or0;
  wire [0:0] s_csamul_pg_rca4_nand3_2;
  wire [0:0] s_csamul_pg_rca4_ha3_2_xor0;
  wire [0:0] s_csamul_pg_rca4_ha3_2_and0;
  wire [0:0] s_csamul_pg_rca4_nand0_3;
  wire [0:0] s_csamul_pg_rca4_fa0_3_xor1;
  wire [0:0] s_csamul_pg_rca4_fa0_3_or0;
  wire [0:0] s_csamul_pg_rca4_nand1_3;
  wire [0:0] s_csamul_pg_rca4_fa1_3_xor1;
  wire [0:0] s_csamul_pg_rca4_fa1_3_or0;
  wire [0:0] s_csamul_pg_rca4_nand2_3;
  wire [0:0] s_csamul_pg_rca4_fa2_3_xor1;
  wire [0:0] s_csamul_pg_rca4_fa2_3_or0;
  wire [0:0] s_csamul_pg_rca4_and3_3;
  wire [0:0] s_csamul_pg_rca4_ha3_3_xor0;
  wire [0:0] s_csamul_pg_rca4_ha3_3_and0;
  wire [3:0] s_csamul_pg_rca4_u_pg_rca4_a;
  wire [3:0] s_csamul_pg_rca4_u_pg_rca4_b;
  wire [4:0] s_csamul_pg_rca4_u_pg_rca4_out;

  and_gate and_gate_s_csamul_pg_rca4_and0_0(.a(a[0]), .b(b[0]), .out(s_csamul_pg_rca4_and0_0));
  and_gate and_gate_s_csamul_pg_rca4_and1_0(.a(a[1]), .b(b[0]), .out(s_csamul_pg_rca4_and1_0));
  and_gate and_gate_s_csamul_pg_rca4_and2_0(.a(a[2]), .b(b[0]), .out(s_csamul_pg_rca4_and2_0));
  nand_gate nand_gate_s_csamul_pg_rca4_nand3_0(.a(a[3]), .b(b[0]), .out(s_csamul_pg_rca4_nand3_0));
  and_gate and_gate_s_csamul_pg_rca4_and0_1(.a(a[0]), .b(b[1]), .out(s_csamul_pg_rca4_and0_1));
  ha ha_s_csamul_pg_rca4_ha0_1_out(.a(s_csamul_pg_rca4_and0_1[0]), .b(s_csamul_pg_rca4_and1_0[0]), .ha_xor0(s_csamul_pg_rca4_ha0_1_xor0), .ha_and0(s_csamul_pg_rca4_ha0_1_and0));
  and_gate and_gate_s_csamul_pg_rca4_and1_1(.a(a[1]), .b(b[1]), .out(s_csamul_pg_rca4_and1_1));
  ha ha_s_csamul_pg_rca4_ha1_1_out(.a(s_csamul_pg_rca4_and1_1[0]), .b(s_csamul_pg_rca4_and2_0[0]), .ha_xor0(s_csamul_pg_rca4_ha1_1_xor0), .ha_and0(s_csamul_pg_rca4_ha1_1_and0));
  and_gate and_gate_s_csamul_pg_rca4_and2_1(.a(a[2]), .b(b[1]), .out(s_csamul_pg_rca4_and2_1));
  ha ha_s_csamul_pg_rca4_ha2_1_out(.a(s_csamul_pg_rca4_and2_1[0]), .b(s_csamul_pg_rca4_nand3_0[0]), .ha_xor0(s_csamul_pg_rca4_ha2_1_xor0), .ha_and0(s_csamul_pg_rca4_ha2_1_and0));
  nand_gate nand_gate_s_csamul_pg_rca4_nand3_1(.a(a[3]), .b(b[1]), .out(s_csamul_pg_rca4_nand3_1));
  ha ha_s_csamul_pg_rca4_ha3_1_out(.a(s_csamul_pg_rca4_nand3_1[0]), .b(1'b1), .ha_xor0(s_csamul_pg_rca4_ha3_1_xor0), .ha_and0(s_csamul_pg_rca4_nand3_1));
  and_gate and_gate_s_csamul_pg_rca4_and0_2(.a(a[0]), .b(b[2]), .out(s_csamul_pg_rca4_and0_2));
  fa fa_s_csamul_pg_rca4_fa0_2_out(.a(s_csamul_pg_rca4_and0_2[0]), .b(s_csamul_pg_rca4_ha1_1_xor0[0]), .cin(s_csamul_pg_rca4_ha0_1_and0[0]), .fa_xor1(s_csamul_pg_rca4_fa0_2_xor1), .fa_or0(s_csamul_pg_rca4_fa0_2_or0));
  and_gate and_gate_s_csamul_pg_rca4_and1_2(.a(a[1]), .b(b[2]), .out(s_csamul_pg_rca4_and1_2));
  fa fa_s_csamul_pg_rca4_fa1_2_out(.a(s_csamul_pg_rca4_and1_2[0]), .b(s_csamul_pg_rca4_ha2_1_xor0[0]), .cin(s_csamul_pg_rca4_ha1_1_and0[0]), .fa_xor1(s_csamul_pg_rca4_fa1_2_xor1), .fa_or0(s_csamul_pg_rca4_fa1_2_or0));
  and_gate and_gate_s_csamul_pg_rca4_and2_2(.a(a[2]), .b(b[2]), .out(s_csamul_pg_rca4_and2_2));
  fa fa_s_csamul_pg_rca4_fa2_2_out(.a(s_csamul_pg_rca4_and2_2[0]), .b(s_csamul_pg_rca4_ha3_1_xor0[0]), .cin(s_csamul_pg_rca4_ha2_1_and0[0]), .fa_xor1(s_csamul_pg_rca4_fa2_2_xor1), .fa_or0(s_csamul_pg_rca4_fa2_2_or0));
  nand_gate nand_gate_s_csamul_pg_rca4_nand3_2(.a(a[3]), .b(b[2]), .out(s_csamul_pg_rca4_nand3_2));
  ha ha_s_csamul_pg_rca4_ha3_2_out(.a(s_csamul_pg_rca4_nand3_2[0]), .b(s_csamul_pg_rca4_nand3_1[0]), .ha_xor0(s_csamul_pg_rca4_ha3_2_xor0), .ha_and0(s_csamul_pg_rca4_ha3_2_and0));
  nand_gate nand_gate_s_csamul_pg_rca4_nand0_3(.a(a[0]), .b(b[3]), .out(s_csamul_pg_rca4_nand0_3));
  fa fa_s_csamul_pg_rca4_fa0_3_out(.a(s_csamul_pg_rca4_nand0_3[0]), .b(s_csamul_pg_rca4_fa1_2_xor1[0]), .cin(s_csamul_pg_rca4_fa0_2_or0[0]), .fa_xor1(s_csamul_pg_rca4_fa0_3_xor1), .fa_or0(s_csamul_pg_rca4_fa0_3_or0));
  nand_gate nand_gate_s_csamul_pg_rca4_nand1_3(.a(a[1]), .b(b[3]), .out(s_csamul_pg_rca4_nand1_3));
  fa fa_s_csamul_pg_rca4_fa1_3_out(.a(s_csamul_pg_rca4_nand1_3[0]), .b(s_csamul_pg_rca4_fa2_2_xor1[0]), .cin(s_csamul_pg_rca4_fa1_2_or0[0]), .fa_xor1(s_csamul_pg_rca4_fa1_3_xor1), .fa_or0(s_csamul_pg_rca4_fa1_3_or0));
  nand_gate nand_gate_s_csamul_pg_rca4_nand2_3(.a(a[2]), .b(b[3]), .out(s_csamul_pg_rca4_nand2_3));
  fa fa_s_csamul_pg_rca4_fa2_3_out(.a(s_csamul_pg_rca4_nand2_3[0]), .b(s_csamul_pg_rca4_ha3_2_xor0[0]), .cin(s_csamul_pg_rca4_fa2_2_or0[0]), .fa_xor1(s_csamul_pg_rca4_fa2_3_xor1), .fa_or0(s_csamul_pg_rca4_fa2_3_or0));
  and_gate and_gate_s_csamul_pg_rca4_and3_3(.a(a[3]), .b(b[3]), .out(s_csamul_pg_rca4_and3_3));
  ha ha_s_csamul_pg_rca4_ha3_3_out(.a(s_csamul_pg_rca4_and3_3[0]), .b(s_csamul_pg_rca4_ha3_2_and0[0]), .ha_xor0(s_csamul_pg_rca4_ha3_3_xor0), .ha_and0(s_csamul_pg_rca4_ha3_3_and0));
  assign s_csamul_pg_rca4_u_pg_rca4_a[0] = s_csamul_pg_rca4_fa1_3_xor1[0];
  assign s_csamul_pg_rca4_u_pg_rca4_a[1] = s_csamul_pg_rca4_fa2_3_xor1[0];
  assign s_csamul_pg_rca4_u_pg_rca4_a[2] = s_csamul_pg_rca4_ha3_3_xor0[0];
  assign s_csamul_pg_rca4_u_pg_rca4_a[3] = 1'b1;
  assign s_csamul_pg_rca4_u_pg_rca4_b[0] = s_csamul_pg_rca4_fa0_3_or0[0];
  assign s_csamul_pg_rca4_u_pg_rca4_b[1] = s_csamul_pg_rca4_fa1_3_or0[0];
  assign s_csamul_pg_rca4_u_pg_rca4_b[2] = s_csamul_pg_rca4_fa2_3_or0[0];
  assign s_csamul_pg_rca4_u_pg_rca4_b[3] = s_csamul_pg_rca4_ha3_3_and0[0];
  u_pg_rca4 u_pg_rca4_s_csamul_pg_rca4_u_pg_rca4_out(.a(s_csamul_pg_rca4_u_pg_rca4_a), .b(s_csamul_pg_rca4_u_pg_rca4_b), .u_pg_rca4_out(s_csamul_pg_rca4_u_pg_rca4_out));

  assign s_csamul_pg_rca4_out[0] = s_csamul_pg_rca4_and0_0[0];
  assign s_csamul_pg_rca4_out[1] = s_csamul_pg_rca4_ha0_1_xor0[0];
  assign s_csamul_pg_rca4_out[2] = s_csamul_pg_rca4_fa0_2_xor1[0];
  assign s_csamul_pg_rca4_out[3] = s_csamul_pg_rca4_fa0_3_xor1[0];
  assign s_csamul_pg_rca4_out[4] = s_csamul_pg_rca4_u_pg_rca4_out[0];
  assign s_csamul_pg_rca4_out[5] = s_csamul_pg_rca4_u_pg_rca4_out[1];
  assign s_csamul_pg_rca4_out[6] = s_csamul_pg_rca4_u_pg_rca4_out[2];
  assign s_csamul_pg_rca4_out[7] = s_csamul_pg_rca4_u_pg_rca4_out[3];
endmodule