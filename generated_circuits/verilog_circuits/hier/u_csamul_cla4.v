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

module pg_logic(input [0:0] a, input [0:0] b, output [0:0] pg_logic_or0, output [0:0] pg_logic_and0, output [0:0] pg_logic_xor0);
  or_gate or_gate_pg_logic_or0(.a(a[0]), .b(b[0]), .out(pg_logic_or0));
  and_gate and_gate_pg_logic_and0(.a(a[0]), .b(b[0]), .out(pg_logic_and0));
  xor_gate xor_gate_pg_logic_xor0(.a(a[0]), .b(b[0]), .out(pg_logic_xor0));
endmodule

module u_cla4(input [3:0] a, input [3:0] b, output [4:0] u_cla4_out);
  wire [0:0] u_cla4_pg_logic0_or0;
  wire [0:0] u_cla4_pg_logic0_and0;
  wire [0:0] u_cla4_pg_logic0_xor0;
  wire [0:0] u_cla4_pg_logic1_or0;
  wire [0:0] u_cla4_pg_logic1_and0;
  wire [0:0] u_cla4_pg_logic1_xor0;
  wire [0:0] u_cla4_xor1;
  wire [0:0] u_cla4_and0;
  wire [0:0] u_cla4_or0;
  wire [0:0] u_cla4_pg_logic2_or0;
  wire [0:0] u_cla4_pg_logic2_and0;
  wire [0:0] u_cla4_pg_logic2_xor0;
  wire [0:0] u_cla4_xor2;
  wire [0:0] u_cla4_and1;
  wire [0:0] u_cla4_and2;
  wire [0:0] u_cla4_and3;
  wire [0:0] u_cla4_and4;
  wire [0:0] u_cla4_or1;
  wire [0:0] u_cla4_or2;
  wire [0:0] u_cla4_pg_logic3_or0;
  wire [0:0] u_cla4_pg_logic3_and0;
  wire [0:0] u_cla4_pg_logic3_xor0;
  wire [0:0] u_cla4_xor3;
  wire [0:0] u_cla4_and5;
  wire [0:0] u_cla4_and6;
  wire [0:0] u_cla4_and7;
  wire [0:0] u_cla4_and8;
  wire [0:0] u_cla4_and9;
  wire [0:0] u_cla4_and10;
  wire [0:0] u_cla4_and11;
  wire [0:0] u_cla4_or3;
  wire [0:0] u_cla4_or4;
  wire [0:0] u_cla4_or5;

  pg_logic pg_logic_u_cla4_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(u_cla4_pg_logic0_or0), .pg_logic_and0(u_cla4_pg_logic0_and0), .pg_logic_xor0(u_cla4_pg_logic0_xor0));
  pg_logic pg_logic_u_cla4_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(u_cla4_pg_logic1_or0), .pg_logic_and0(u_cla4_pg_logic1_and0), .pg_logic_xor0(u_cla4_pg_logic1_xor0));
  xor_gate xor_gate_u_cla4_xor1(.a(u_cla4_pg_logic1_xor0[0]), .b(u_cla4_pg_logic0_and0[0]), .out(u_cla4_xor1));
  and_gate and_gate_u_cla4_and0(.a(u_cla4_pg_logic0_and0[0]), .b(u_cla4_pg_logic1_or0[0]), .out(u_cla4_and0));
  or_gate or_gate_u_cla4_or0(.a(u_cla4_pg_logic1_and0[0]), .b(u_cla4_and0[0]), .out(u_cla4_or0));
  pg_logic pg_logic_u_cla4_pg_logic2_out(.a(a[2]), .b(b[2]), .pg_logic_or0(u_cla4_pg_logic2_or0), .pg_logic_and0(u_cla4_pg_logic2_and0), .pg_logic_xor0(u_cla4_pg_logic2_xor0));
  xor_gate xor_gate_u_cla4_xor2(.a(u_cla4_pg_logic2_xor0[0]), .b(u_cla4_or0[0]), .out(u_cla4_xor2));
  and_gate and_gate_u_cla4_and1(.a(u_cla4_pg_logic2_or0[0]), .b(u_cla4_pg_logic0_or0[0]), .out(u_cla4_and1));
  and_gate and_gate_u_cla4_and2(.a(u_cla4_pg_logic0_and0[0]), .b(u_cla4_pg_logic2_or0[0]), .out(u_cla4_and2));
  and_gate and_gate_u_cla4_and3(.a(u_cla4_and2[0]), .b(u_cla4_pg_logic1_or0[0]), .out(u_cla4_and3));
  and_gate and_gate_u_cla4_and4(.a(u_cla4_pg_logic1_and0[0]), .b(u_cla4_pg_logic2_or0[0]), .out(u_cla4_and4));
  or_gate or_gate_u_cla4_or1(.a(u_cla4_and3[0]), .b(u_cla4_and4[0]), .out(u_cla4_or1));
  or_gate or_gate_u_cla4_or2(.a(u_cla4_pg_logic2_and0[0]), .b(u_cla4_or1[0]), .out(u_cla4_or2));
  pg_logic pg_logic_u_cla4_pg_logic3_out(.a(a[3]), .b(b[3]), .pg_logic_or0(u_cla4_pg_logic3_or0), .pg_logic_and0(u_cla4_pg_logic3_and0), .pg_logic_xor0(u_cla4_pg_logic3_xor0));
  xor_gate xor_gate_u_cla4_xor3(.a(u_cla4_pg_logic3_xor0[0]), .b(u_cla4_or2[0]), .out(u_cla4_xor3));
  and_gate and_gate_u_cla4_and5(.a(u_cla4_pg_logic3_or0[0]), .b(u_cla4_pg_logic1_or0[0]), .out(u_cla4_and5));
  and_gate and_gate_u_cla4_and6(.a(u_cla4_pg_logic0_and0[0]), .b(u_cla4_pg_logic2_or0[0]), .out(u_cla4_and6));
  and_gate and_gate_u_cla4_and7(.a(u_cla4_pg_logic3_or0[0]), .b(u_cla4_pg_logic1_or0[0]), .out(u_cla4_and7));
  and_gate and_gate_u_cla4_and8(.a(u_cla4_and6[0]), .b(u_cla4_and7[0]), .out(u_cla4_and8));
  and_gate and_gate_u_cla4_and9(.a(u_cla4_pg_logic1_and0[0]), .b(u_cla4_pg_logic3_or0[0]), .out(u_cla4_and9));
  and_gate and_gate_u_cla4_and10(.a(u_cla4_and9[0]), .b(u_cla4_pg_logic2_or0[0]), .out(u_cla4_and10));
  and_gate and_gate_u_cla4_and11(.a(u_cla4_pg_logic2_and0[0]), .b(u_cla4_pg_logic3_or0[0]), .out(u_cla4_and11));
  or_gate or_gate_u_cla4_or3(.a(u_cla4_and8[0]), .b(u_cla4_and11[0]), .out(u_cla4_or3));
  or_gate or_gate_u_cla4_or4(.a(u_cla4_and10[0]), .b(u_cla4_or3[0]), .out(u_cla4_or4));
  or_gate or_gate_u_cla4_or5(.a(u_cla4_pg_logic3_and0[0]), .b(u_cla4_or4[0]), .out(u_cla4_or5));

  assign u_cla4_out[0] = u_cla4_pg_logic0_xor0[0];
  assign u_cla4_out[1] = u_cla4_xor1[0];
  assign u_cla4_out[2] = u_cla4_xor2[0];
  assign u_cla4_out[3] = u_cla4_xor3[0];
  assign u_cla4_out[4] = u_cla4_or5[0];
endmodule

module u_csamul_cla4(input [3:0] a, input [3:0] b, output [7:0] u_csamul_cla4_out);
  wire [0:0] u_csamul_cla4_and0_0;
  wire [0:0] u_csamul_cla4_and1_0;
  wire [0:0] u_csamul_cla4_and2_0;
  wire [0:0] u_csamul_cla4_and3_0;
  wire [0:0] u_csamul_cla4_and0_1;
  wire [0:0] u_csamul_cla4_ha0_1_xor0;
  wire [0:0] u_csamul_cla4_ha0_1_and0;
  wire [0:0] u_csamul_cla4_and1_1;
  wire [0:0] u_csamul_cla4_ha1_1_xor0;
  wire [0:0] u_csamul_cla4_ha1_1_and0;
  wire [0:0] u_csamul_cla4_and2_1;
  wire [0:0] u_csamul_cla4_ha2_1_xor0;
  wire [0:0] u_csamul_cla4_ha2_1_and0;
  wire [0:0] u_csamul_cla4_and3_1;
  wire [0:0] u_csamul_cla4_and0_2;
  wire [0:0] u_csamul_cla4_fa0_2_xor1;
  wire [0:0] u_csamul_cla4_fa0_2_or0;
  wire [0:0] u_csamul_cla4_and1_2;
  wire [0:0] u_csamul_cla4_fa1_2_xor1;
  wire [0:0] u_csamul_cla4_fa1_2_or0;
  wire [0:0] u_csamul_cla4_and2_2;
  wire [0:0] u_csamul_cla4_fa2_2_xor1;
  wire [0:0] u_csamul_cla4_fa2_2_or0;
  wire [0:0] u_csamul_cla4_and3_2;
  wire [0:0] u_csamul_cla4_and0_3;
  wire [0:0] u_csamul_cla4_fa0_3_xor1;
  wire [0:0] u_csamul_cla4_fa0_3_or0;
  wire [0:0] u_csamul_cla4_and1_3;
  wire [0:0] u_csamul_cla4_fa1_3_xor1;
  wire [0:0] u_csamul_cla4_fa1_3_or0;
  wire [0:0] u_csamul_cla4_and2_3;
  wire [0:0] u_csamul_cla4_fa2_3_xor1;
  wire [0:0] u_csamul_cla4_fa2_3_or0;
  wire [0:0] u_csamul_cla4_and3_3;
  wire [3:0] u_csamul_cla4_u_cla4_a;
  wire [3:0] u_csamul_cla4_u_cla4_b;
  wire [4:0] u_csamul_cla4_u_cla4_out;

  and_gate and_gate_u_csamul_cla4_and0_0(.a(a[0]), .b(b[0]), .out(u_csamul_cla4_and0_0));
  and_gate and_gate_u_csamul_cla4_and1_0(.a(a[1]), .b(b[0]), .out(u_csamul_cla4_and1_0));
  and_gate and_gate_u_csamul_cla4_and2_0(.a(a[2]), .b(b[0]), .out(u_csamul_cla4_and2_0));
  and_gate and_gate_u_csamul_cla4_and3_0(.a(a[3]), .b(b[0]), .out(u_csamul_cla4_and3_0));
  and_gate and_gate_u_csamul_cla4_and0_1(.a(a[0]), .b(b[1]), .out(u_csamul_cla4_and0_1));
  ha ha_u_csamul_cla4_ha0_1_out(.a(u_csamul_cla4_and0_1[0]), .b(u_csamul_cla4_and1_0[0]), .ha_xor0(u_csamul_cla4_ha0_1_xor0), .ha_and0(u_csamul_cla4_ha0_1_and0));
  and_gate and_gate_u_csamul_cla4_and1_1(.a(a[1]), .b(b[1]), .out(u_csamul_cla4_and1_1));
  ha ha_u_csamul_cla4_ha1_1_out(.a(u_csamul_cla4_and1_1[0]), .b(u_csamul_cla4_and2_0[0]), .ha_xor0(u_csamul_cla4_ha1_1_xor0), .ha_and0(u_csamul_cla4_ha1_1_and0));
  and_gate and_gate_u_csamul_cla4_and2_1(.a(a[2]), .b(b[1]), .out(u_csamul_cla4_and2_1));
  ha ha_u_csamul_cla4_ha2_1_out(.a(u_csamul_cla4_and2_1[0]), .b(u_csamul_cla4_and3_0[0]), .ha_xor0(u_csamul_cla4_ha2_1_xor0), .ha_and0(u_csamul_cla4_ha2_1_and0));
  and_gate and_gate_u_csamul_cla4_and3_1(.a(a[3]), .b(b[1]), .out(u_csamul_cla4_and3_1));
  and_gate and_gate_u_csamul_cla4_and0_2(.a(a[0]), .b(b[2]), .out(u_csamul_cla4_and0_2));
  fa fa_u_csamul_cla4_fa0_2_out(.a(u_csamul_cla4_and0_2[0]), .b(u_csamul_cla4_ha1_1_xor0[0]), .cin(u_csamul_cla4_ha0_1_and0[0]), .fa_xor1(u_csamul_cla4_fa0_2_xor1), .fa_or0(u_csamul_cla4_fa0_2_or0));
  and_gate and_gate_u_csamul_cla4_and1_2(.a(a[1]), .b(b[2]), .out(u_csamul_cla4_and1_2));
  fa fa_u_csamul_cla4_fa1_2_out(.a(u_csamul_cla4_and1_2[0]), .b(u_csamul_cla4_ha2_1_xor0[0]), .cin(u_csamul_cla4_ha1_1_and0[0]), .fa_xor1(u_csamul_cla4_fa1_2_xor1), .fa_or0(u_csamul_cla4_fa1_2_or0));
  and_gate and_gate_u_csamul_cla4_and2_2(.a(a[2]), .b(b[2]), .out(u_csamul_cla4_and2_2));
  fa fa_u_csamul_cla4_fa2_2_out(.a(u_csamul_cla4_and2_2[0]), .b(u_csamul_cla4_and3_1[0]), .cin(u_csamul_cla4_ha2_1_and0[0]), .fa_xor1(u_csamul_cla4_fa2_2_xor1), .fa_or0(u_csamul_cla4_fa2_2_or0));
  and_gate and_gate_u_csamul_cla4_and3_2(.a(a[3]), .b(b[2]), .out(u_csamul_cla4_and3_2));
  and_gate and_gate_u_csamul_cla4_and0_3(.a(a[0]), .b(b[3]), .out(u_csamul_cla4_and0_3));
  fa fa_u_csamul_cla4_fa0_3_out(.a(u_csamul_cla4_and0_3[0]), .b(u_csamul_cla4_fa1_2_xor1[0]), .cin(u_csamul_cla4_fa0_2_or0[0]), .fa_xor1(u_csamul_cla4_fa0_3_xor1), .fa_or0(u_csamul_cla4_fa0_3_or0));
  and_gate and_gate_u_csamul_cla4_and1_3(.a(a[1]), .b(b[3]), .out(u_csamul_cla4_and1_3));
  fa fa_u_csamul_cla4_fa1_3_out(.a(u_csamul_cla4_and1_3[0]), .b(u_csamul_cla4_fa2_2_xor1[0]), .cin(u_csamul_cla4_fa1_2_or0[0]), .fa_xor1(u_csamul_cla4_fa1_3_xor1), .fa_or0(u_csamul_cla4_fa1_3_or0));
  and_gate and_gate_u_csamul_cla4_and2_3(.a(a[2]), .b(b[3]), .out(u_csamul_cla4_and2_3));
  fa fa_u_csamul_cla4_fa2_3_out(.a(u_csamul_cla4_and2_3[0]), .b(u_csamul_cla4_and3_2[0]), .cin(u_csamul_cla4_fa2_2_or0[0]), .fa_xor1(u_csamul_cla4_fa2_3_xor1), .fa_or0(u_csamul_cla4_fa2_3_or0));
  and_gate and_gate_u_csamul_cla4_and3_3(.a(a[3]), .b(b[3]), .out(u_csamul_cla4_and3_3));
  assign u_csamul_cla4_u_cla4_a[0] = u_csamul_cla4_fa1_3_xor1[0];
  assign u_csamul_cla4_u_cla4_a[1] = u_csamul_cla4_fa2_3_xor1[0];
  assign u_csamul_cla4_u_cla4_a[2] = u_csamul_cla4_and3_3[0];
  assign u_csamul_cla4_u_cla4_a[3] = 1'b0;
  assign u_csamul_cla4_u_cla4_b[0] = u_csamul_cla4_fa0_3_or0[0];
  assign u_csamul_cla4_u_cla4_b[1] = u_csamul_cla4_fa1_3_or0[0];
  assign u_csamul_cla4_u_cla4_b[2] = u_csamul_cla4_fa2_3_or0[0];
  assign u_csamul_cla4_u_cla4_b[3] = 1'b0;
  u_cla4 u_cla4_u_csamul_cla4_u_cla4_out(.a(u_csamul_cla4_u_cla4_a), .b(u_csamul_cla4_u_cla4_b), .u_cla4_out(u_csamul_cla4_u_cla4_out));

  assign u_csamul_cla4_out[0] = u_csamul_cla4_and0_0[0];
  assign u_csamul_cla4_out[1] = u_csamul_cla4_ha0_1_xor0[0];
  assign u_csamul_cla4_out[2] = u_csamul_cla4_fa0_2_xor1[0];
  assign u_csamul_cla4_out[3] = u_csamul_cla4_fa0_3_xor1[0];
  assign u_csamul_cla4_out[4] = u_csamul_cla4_u_cla4_out[0];
  assign u_csamul_cla4_out[5] = u_csamul_cla4_u_cla4_out[1];
  assign u_csamul_cla4_out[6] = u_csamul_cla4_u_cla4_out[2];
  assign u_csamul_cla4_out[7] = u_csamul_cla4_u_cla4_out[3];
endmodule