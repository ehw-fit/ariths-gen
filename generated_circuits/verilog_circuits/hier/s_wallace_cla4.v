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

module pg_logic(input [0:0] a, input [0:0] b, output [0:0] pg_logic_or0, output [0:0] pg_logic_and0, output [0:0] pg_logic_xor0);
  or_gate or_gate_pg_logic_or0(.a(a[0]), .b(b[0]), .out(pg_logic_or0));
  and_gate and_gate_pg_logic_and0(.a(a[0]), .b(b[0]), .out(pg_logic_and0));
  xor_gate xor_gate_pg_logic_xor0(.a(a[0]), .b(b[0]), .out(pg_logic_xor0));
endmodule

module u_cla6(input [5:0] a, input [5:0] b, output [6:0] u_cla6_out);
  wire [0:0] u_cla6_pg_logic0_or0;
  wire [0:0] u_cla6_pg_logic0_and0;
  wire [0:0] u_cla6_pg_logic0_xor0;
  wire [0:0] u_cla6_pg_logic1_or0;
  wire [0:0] u_cla6_pg_logic1_and0;
  wire [0:0] u_cla6_pg_logic1_xor0;
  wire [0:0] u_cla6_xor1;
  wire [0:0] u_cla6_and0;
  wire [0:0] u_cla6_or0;
  wire [0:0] u_cla6_pg_logic2_or0;
  wire [0:0] u_cla6_pg_logic2_and0;
  wire [0:0] u_cla6_pg_logic2_xor0;
  wire [0:0] u_cla6_xor2;
  wire [0:0] u_cla6_and1;
  wire [0:0] u_cla6_and2;
  wire [0:0] u_cla6_and3;
  wire [0:0] u_cla6_and4;
  wire [0:0] u_cla6_or1;
  wire [0:0] u_cla6_or2;
  wire [0:0] u_cla6_pg_logic3_or0;
  wire [0:0] u_cla6_pg_logic3_and0;
  wire [0:0] u_cla6_pg_logic3_xor0;
  wire [0:0] u_cla6_xor3;
  wire [0:0] u_cla6_and5;
  wire [0:0] u_cla6_and6;
  wire [0:0] u_cla6_and7;
  wire [0:0] u_cla6_and8;
  wire [0:0] u_cla6_and9;
  wire [0:0] u_cla6_and10;
  wire [0:0] u_cla6_and11;
  wire [0:0] u_cla6_or3;
  wire [0:0] u_cla6_or4;
  wire [0:0] u_cla6_or5;
  wire [0:0] u_cla6_pg_logic4_or0;
  wire [0:0] u_cla6_pg_logic4_and0;
  wire [0:0] u_cla6_pg_logic4_xor0;
  wire [0:0] u_cla6_xor4;
  wire [0:0] u_cla6_and12;
  wire [0:0] u_cla6_or6;
  wire [0:0] u_cla6_pg_logic5_or0;
  wire [0:0] u_cla6_pg_logic5_and0;
  wire [0:0] u_cla6_pg_logic5_xor0;
  wire [0:0] u_cla6_xor5;
  wire [0:0] u_cla6_and13;
  wire [0:0] u_cla6_and14;
  wire [0:0] u_cla6_and15;
  wire [0:0] u_cla6_or7;
  wire [0:0] u_cla6_or8;

  pg_logic pg_logic_u_cla6_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(u_cla6_pg_logic0_or0), .pg_logic_and0(u_cla6_pg_logic0_and0), .pg_logic_xor0(u_cla6_pg_logic0_xor0));
  pg_logic pg_logic_u_cla6_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(u_cla6_pg_logic1_or0), .pg_logic_and0(u_cla6_pg_logic1_and0), .pg_logic_xor0(u_cla6_pg_logic1_xor0));
  xor_gate xor_gate_u_cla6_xor1(.a(u_cla6_pg_logic1_xor0[0]), .b(u_cla6_pg_logic0_and0[0]), .out(u_cla6_xor1));
  and_gate and_gate_u_cla6_and0(.a(u_cla6_pg_logic0_and0[0]), .b(u_cla6_pg_logic1_or0[0]), .out(u_cla6_and0));
  or_gate or_gate_u_cla6_or0(.a(u_cla6_pg_logic1_and0[0]), .b(u_cla6_and0[0]), .out(u_cla6_or0));
  pg_logic pg_logic_u_cla6_pg_logic2_out(.a(a[2]), .b(b[2]), .pg_logic_or0(u_cla6_pg_logic2_or0), .pg_logic_and0(u_cla6_pg_logic2_and0), .pg_logic_xor0(u_cla6_pg_logic2_xor0));
  xor_gate xor_gate_u_cla6_xor2(.a(u_cla6_pg_logic2_xor0[0]), .b(u_cla6_or0[0]), .out(u_cla6_xor2));
  and_gate and_gate_u_cla6_and1(.a(u_cla6_pg_logic2_or0[0]), .b(u_cla6_pg_logic0_or0[0]), .out(u_cla6_and1));
  and_gate and_gate_u_cla6_and2(.a(u_cla6_pg_logic0_and0[0]), .b(u_cla6_pg_logic2_or0[0]), .out(u_cla6_and2));
  and_gate and_gate_u_cla6_and3(.a(u_cla6_and2[0]), .b(u_cla6_pg_logic1_or0[0]), .out(u_cla6_and3));
  and_gate and_gate_u_cla6_and4(.a(u_cla6_pg_logic1_and0[0]), .b(u_cla6_pg_logic2_or0[0]), .out(u_cla6_and4));
  or_gate or_gate_u_cla6_or1(.a(u_cla6_and3[0]), .b(u_cla6_and4[0]), .out(u_cla6_or1));
  or_gate or_gate_u_cla6_or2(.a(u_cla6_pg_logic2_and0[0]), .b(u_cla6_or1[0]), .out(u_cla6_or2));
  pg_logic pg_logic_u_cla6_pg_logic3_out(.a(a[3]), .b(b[3]), .pg_logic_or0(u_cla6_pg_logic3_or0), .pg_logic_and0(u_cla6_pg_logic3_and0), .pg_logic_xor0(u_cla6_pg_logic3_xor0));
  xor_gate xor_gate_u_cla6_xor3(.a(u_cla6_pg_logic3_xor0[0]), .b(u_cla6_or2[0]), .out(u_cla6_xor3));
  and_gate and_gate_u_cla6_and5(.a(u_cla6_pg_logic3_or0[0]), .b(u_cla6_pg_logic1_or0[0]), .out(u_cla6_and5));
  and_gate and_gate_u_cla6_and6(.a(u_cla6_pg_logic0_and0[0]), .b(u_cla6_pg_logic2_or0[0]), .out(u_cla6_and6));
  and_gate and_gate_u_cla6_and7(.a(u_cla6_pg_logic3_or0[0]), .b(u_cla6_pg_logic1_or0[0]), .out(u_cla6_and7));
  and_gate and_gate_u_cla6_and8(.a(u_cla6_and6[0]), .b(u_cla6_and7[0]), .out(u_cla6_and8));
  and_gate and_gate_u_cla6_and9(.a(u_cla6_pg_logic1_and0[0]), .b(u_cla6_pg_logic3_or0[0]), .out(u_cla6_and9));
  and_gate and_gate_u_cla6_and10(.a(u_cla6_and9[0]), .b(u_cla6_pg_logic2_or0[0]), .out(u_cla6_and10));
  and_gate and_gate_u_cla6_and11(.a(u_cla6_pg_logic2_and0[0]), .b(u_cla6_pg_logic3_or0[0]), .out(u_cla6_and11));
  or_gate or_gate_u_cla6_or3(.a(u_cla6_and8[0]), .b(u_cla6_and11[0]), .out(u_cla6_or3));
  or_gate or_gate_u_cla6_or4(.a(u_cla6_and10[0]), .b(u_cla6_or3[0]), .out(u_cla6_or4));
  or_gate or_gate_u_cla6_or5(.a(u_cla6_pg_logic3_and0[0]), .b(u_cla6_or4[0]), .out(u_cla6_or5));
  pg_logic pg_logic_u_cla6_pg_logic4_out(.a(a[4]), .b(b[4]), .pg_logic_or0(u_cla6_pg_logic4_or0), .pg_logic_and0(u_cla6_pg_logic4_and0), .pg_logic_xor0(u_cla6_pg_logic4_xor0));
  xor_gate xor_gate_u_cla6_xor4(.a(u_cla6_pg_logic4_xor0[0]), .b(u_cla6_or5[0]), .out(u_cla6_xor4));
  and_gate and_gate_u_cla6_and12(.a(u_cla6_or5[0]), .b(u_cla6_pg_logic4_or0[0]), .out(u_cla6_and12));
  or_gate or_gate_u_cla6_or6(.a(u_cla6_pg_logic4_and0[0]), .b(u_cla6_and12[0]), .out(u_cla6_or6));
  pg_logic pg_logic_u_cla6_pg_logic5_out(.a(a[5]), .b(b[5]), .pg_logic_or0(u_cla6_pg_logic5_or0), .pg_logic_and0(u_cla6_pg_logic5_and0), .pg_logic_xor0(u_cla6_pg_logic5_xor0));
  xor_gate xor_gate_u_cla6_xor5(.a(u_cla6_pg_logic5_xor0[0]), .b(u_cla6_or6[0]), .out(u_cla6_xor5));
  and_gate and_gate_u_cla6_and13(.a(u_cla6_or5[0]), .b(u_cla6_pg_logic5_or0[0]), .out(u_cla6_and13));
  and_gate and_gate_u_cla6_and14(.a(u_cla6_and13[0]), .b(u_cla6_pg_logic4_or0[0]), .out(u_cla6_and14));
  and_gate and_gate_u_cla6_and15(.a(u_cla6_pg_logic4_and0[0]), .b(u_cla6_pg_logic5_or0[0]), .out(u_cla6_and15));
  or_gate or_gate_u_cla6_or7(.a(u_cla6_and14[0]), .b(u_cla6_and15[0]), .out(u_cla6_or7));
  or_gate or_gate_u_cla6_or8(.a(u_cla6_pg_logic5_and0[0]), .b(u_cla6_or7[0]), .out(u_cla6_or8));

  assign u_cla6_out[0] = u_cla6_pg_logic0_xor0[0];
  assign u_cla6_out[1] = u_cla6_xor1[0];
  assign u_cla6_out[2] = u_cla6_xor2[0];
  assign u_cla6_out[3] = u_cla6_xor3[0];
  assign u_cla6_out[4] = u_cla6_xor4[0];
  assign u_cla6_out[5] = u_cla6_xor5[0];
  assign u_cla6_out[6] = u_cla6_or8[0];
endmodule

module h_s_wallace_cla4(input [3:0] a, input [3:0] b, output [7:0] h_s_wallace_cla4_out);
  wire [0:0] h_s_wallace_cla4_and_2_0;
  wire [0:0] h_s_wallace_cla4_and_1_1;
  wire [0:0] h_s_wallace_cla4_ha0_xor0;
  wire [0:0] h_s_wallace_cla4_ha0_and0;
  wire [0:0] h_s_wallace_cla4_nand_3_0;
  wire [0:0] h_s_wallace_cla4_and_2_1;
  wire [0:0] h_s_wallace_cla4_fa0_xor1;
  wire [0:0] h_s_wallace_cla4_fa0_or0;
  wire [0:0] h_s_wallace_cla4_nand_3_1;
  wire [0:0] h_s_wallace_cla4_fa1_xor1;
  wire [0:0] h_s_wallace_cla4_fa1_or0;
  wire [0:0] h_s_wallace_cla4_and_1_2;
  wire [0:0] h_s_wallace_cla4_nand_0_3;
  wire [0:0] h_s_wallace_cla4_ha1_xor0;
  wire [0:0] h_s_wallace_cla4_ha1_and0;
  wire [0:0] h_s_wallace_cla4_and_2_2;
  wire [0:0] h_s_wallace_cla4_nand_1_3;
  wire [0:0] h_s_wallace_cla4_fa2_xor1;
  wire [0:0] h_s_wallace_cla4_fa2_or0;
  wire [0:0] h_s_wallace_cla4_nand_3_2;
  wire [0:0] h_s_wallace_cla4_fa3_xor1;
  wire [0:0] h_s_wallace_cla4_fa3_or0;
  wire [0:0] h_s_wallace_cla4_and_0_0;
  wire [0:0] h_s_wallace_cla4_and_1_0;
  wire [0:0] h_s_wallace_cla4_and_0_2;
  wire [0:0] h_s_wallace_cla4_nand_2_3;
  wire [0:0] h_s_wallace_cla4_and_0_1;
  wire [0:0] h_s_wallace_cla4_and_3_3;
  wire [5:0] h_s_wallace_cla4_u_cla6_a;
  wire [5:0] h_s_wallace_cla4_u_cla6_b;
  wire [6:0] h_s_wallace_cla4_u_cla6_out;
  wire [0:0] h_s_wallace_cla4_xor0;

  and_gate and_gate_h_s_wallace_cla4_and_2_0(.a(a[2]), .b(b[0]), .out(h_s_wallace_cla4_and_2_0));
  and_gate and_gate_h_s_wallace_cla4_and_1_1(.a(a[1]), .b(b[1]), .out(h_s_wallace_cla4_and_1_1));
  ha ha_h_s_wallace_cla4_ha0_out(.a(h_s_wallace_cla4_and_2_0[0]), .b(h_s_wallace_cla4_and_1_1[0]), .ha_xor0(h_s_wallace_cla4_ha0_xor0), .ha_and0(h_s_wallace_cla4_ha0_and0));
  nand_gate nand_gate_h_s_wallace_cla4_nand_3_0(.a(a[3]), .b(b[0]), .out(h_s_wallace_cla4_nand_3_0));
  and_gate and_gate_h_s_wallace_cla4_and_2_1(.a(a[2]), .b(b[1]), .out(h_s_wallace_cla4_and_2_1));
  fa fa_h_s_wallace_cla4_fa0_out(.a(h_s_wallace_cla4_ha0_and0[0]), .b(h_s_wallace_cla4_nand_3_0[0]), .cin(h_s_wallace_cla4_and_2_1[0]), .fa_xor1(h_s_wallace_cla4_fa0_xor1), .fa_or0(h_s_wallace_cla4_fa0_or0));
  nand_gate nand_gate_h_s_wallace_cla4_nand_3_1(.a(a[3]), .b(b[1]), .out(h_s_wallace_cla4_nand_3_1));
  fa fa_h_s_wallace_cla4_fa1_out(.a(h_s_wallace_cla4_fa0_or0[0]), .b(1'b1), .cin(h_s_wallace_cla4_nand_3_1[0]), .fa_xor1(h_s_wallace_cla4_fa1_xor1), .fa_or0(h_s_wallace_cla4_fa1_or0));
  and_gate and_gate_h_s_wallace_cla4_and_1_2(.a(a[1]), .b(b[2]), .out(h_s_wallace_cla4_and_1_2));
  nand_gate nand_gate_h_s_wallace_cla4_nand_0_3(.a(a[0]), .b(b[3]), .out(h_s_wallace_cla4_nand_0_3));
  ha ha_h_s_wallace_cla4_ha1_out(.a(h_s_wallace_cla4_and_1_2[0]), .b(h_s_wallace_cla4_nand_0_3[0]), .ha_xor0(h_s_wallace_cla4_ha1_xor0), .ha_and0(h_s_wallace_cla4_ha1_and0));
  and_gate and_gate_h_s_wallace_cla4_and_2_2(.a(a[2]), .b(b[2]), .out(h_s_wallace_cla4_and_2_2));
  nand_gate nand_gate_h_s_wallace_cla4_nand_1_3(.a(a[1]), .b(b[3]), .out(h_s_wallace_cla4_nand_1_3));
  fa fa_h_s_wallace_cla4_fa2_out(.a(h_s_wallace_cla4_ha1_and0[0]), .b(h_s_wallace_cla4_and_2_2[0]), .cin(h_s_wallace_cla4_nand_1_3[0]), .fa_xor1(h_s_wallace_cla4_fa2_xor1), .fa_or0(h_s_wallace_cla4_fa2_or0));
  nand_gate nand_gate_h_s_wallace_cla4_nand_3_2(.a(a[3]), .b(b[2]), .out(h_s_wallace_cla4_nand_3_2));
  fa fa_h_s_wallace_cla4_fa3_out(.a(h_s_wallace_cla4_fa2_or0[0]), .b(h_s_wallace_cla4_fa1_or0[0]), .cin(h_s_wallace_cla4_nand_3_2[0]), .fa_xor1(h_s_wallace_cla4_fa3_xor1), .fa_or0(h_s_wallace_cla4_fa3_or0));
  and_gate and_gate_h_s_wallace_cla4_and_0_0(.a(a[0]), .b(b[0]), .out(h_s_wallace_cla4_and_0_0));
  and_gate and_gate_h_s_wallace_cla4_and_1_0(.a(a[1]), .b(b[0]), .out(h_s_wallace_cla4_and_1_0));
  and_gate and_gate_h_s_wallace_cla4_and_0_2(.a(a[0]), .b(b[2]), .out(h_s_wallace_cla4_and_0_2));
  nand_gate nand_gate_h_s_wallace_cla4_nand_2_3(.a(a[2]), .b(b[3]), .out(h_s_wallace_cla4_nand_2_3));
  and_gate and_gate_h_s_wallace_cla4_and_0_1(.a(a[0]), .b(b[1]), .out(h_s_wallace_cla4_and_0_1));
  and_gate and_gate_h_s_wallace_cla4_and_3_3(.a(a[3]), .b(b[3]), .out(h_s_wallace_cla4_and_3_3));
  assign h_s_wallace_cla4_u_cla6_a[0] = h_s_wallace_cla4_and_1_0[0];
  assign h_s_wallace_cla4_u_cla6_a[1] = h_s_wallace_cla4_and_0_2[0];
  assign h_s_wallace_cla4_u_cla6_a[2] = h_s_wallace_cla4_fa0_xor1[0];
  assign h_s_wallace_cla4_u_cla6_a[3] = h_s_wallace_cla4_fa1_xor1[0];
  assign h_s_wallace_cla4_u_cla6_a[4] = h_s_wallace_cla4_nand_2_3[0];
  assign h_s_wallace_cla4_u_cla6_a[5] = h_s_wallace_cla4_fa3_or0[0];
  assign h_s_wallace_cla4_u_cla6_b[0] = h_s_wallace_cla4_and_0_1[0];
  assign h_s_wallace_cla4_u_cla6_b[1] = h_s_wallace_cla4_ha0_xor0[0];
  assign h_s_wallace_cla4_u_cla6_b[2] = h_s_wallace_cla4_ha1_xor0[0];
  assign h_s_wallace_cla4_u_cla6_b[3] = h_s_wallace_cla4_fa2_xor1[0];
  assign h_s_wallace_cla4_u_cla6_b[4] = h_s_wallace_cla4_fa3_xor1[0];
  assign h_s_wallace_cla4_u_cla6_b[5] = h_s_wallace_cla4_and_3_3[0];
  u_cla6 u_cla6_h_s_wallace_cla4_u_cla6_out(.a(h_s_wallace_cla4_u_cla6_a), .b(h_s_wallace_cla4_u_cla6_b), .u_cla6_out(h_s_wallace_cla4_u_cla6_out));
  not_gate not_gate_h_s_wallace_cla4_xor0(.a(h_s_wallace_cla4_u_cla6_out[6]), .out(h_s_wallace_cla4_xor0));

  assign h_s_wallace_cla4_out[0] = h_s_wallace_cla4_and_0_0[0];
  assign h_s_wallace_cla4_out[1] = h_s_wallace_cla4_u_cla6_out[0];
  assign h_s_wallace_cla4_out[2] = h_s_wallace_cla4_u_cla6_out[1];
  assign h_s_wallace_cla4_out[3] = h_s_wallace_cla4_u_cla6_out[2];
  assign h_s_wallace_cla4_out[4] = h_s_wallace_cla4_u_cla6_out[3];
  assign h_s_wallace_cla4_out[5] = h_s_wallace_cla4_u_cla6_out[4];
  assign h_s_wallace_cla4_out[6] = h_s_wallace_cla4_u_cla6_out[5];
  assign h_s_wallace_cla4_out[7] = h_s_wallace_cla4_xor0[0];
endmodule