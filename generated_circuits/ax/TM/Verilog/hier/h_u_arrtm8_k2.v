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

module h_u_arrtm8_k2(input [7:0] a, input [7:0] b, output [15:0] h_u_arrtm8_k2_out);
  wire [0:0] h_u_arrtm8_k2_and2_2;
  wire [0:0] h_u_arrtm8_k2_and3_2;
  wire [0:0] h_u_arrtm8_k2_and4_2;
  wire [0:0] h_u_arrtm8_k2_and5_2;
  wire [0:0] h_u_arrtm8_k2_and6_2;
  wire [0:0] h_u_arrtm8_k2_and7_2;
  wire [0:0] h_u_arrtm8_k2_and2_3;
  wire [0:0] h_u_arrtm8_k2_ha2_3_xor0;
  wire [0:0] h_u_arrtm8_k2_ha2_3_and0;
  wire [0:0] h_u_arrtm8_k2_and3_3;
  wire [0:0] h_u_arrtm8_k2_ha3_3_xor0;
  wire [0:0] h_u_arrtm8_k2_ha3_3_and0;
  wire [0:0] h_u_arrtm8_k2_and4_3;
  wire [0:0] h_u_arrtm8_k2_ha4_3_xor0;
  wire [0:0] h_u_arrtm8_k2_ha4_3_and0;
  wire [0:0] h_u_arrtm8_k2_and5_3;
  wire [0:0] h_u_arrtm8_k2_ha5_3_xor0;
  wire [0:0] h_u_arrtm8_k2_ha5_3_and0;
  wire [0:0] h_u_arrtm8_k2_and6_3;
  wire [0:0] h_u_arrtm8_k2_ha6_3_xor0;
  wire [0:0] h_u_arrtm8_k2_ha6_3_and0;
  wire [0:0] h_u_arrtm8_k2_and7_3;
  wire [0:0] h_u_arrtm8_k2_and2_4;
  wire [0:0] h_u_arrtm8_k2_fa2_4_xor1;
  wire [0:0] h_u_arrtm8_k2_fa2_4_or0;
  wire [0:0] h_u_arrtm8_k2_and3_4;
  wire [0:0] h_u_arrtm8_k2_fa3_4_xor1;
  wire [0:0] h_u_arrtm8_k2_fa3_4_or0;
  wire [0:0] h_u_arrtm8_k2_and4_4;
  wire [0:0] h_u_arrtm8_k2_fa4_4_xor1;
  wire [0:0] h_u_arrtm8_k2_fa4_4_or0;
  wire [0:0] h_u_arrtm8_k2_and5_4;
  wire [0:0] h_u_arrtm8_k2_fa5_4_xor1;
  wire [0:0] h_u_arrtm8_k2_fa5_4_or0;
  wire [0:0] h_u_arrtm8_k2_and6_4;
  wire [0:0] h_u_arrtm8_k2_fa6_4_xor1;
  wire [0:0] h_u_arrtm8_k2_fa6_4_or0;
  wire [0:0] h_u_arrtm8_k2_and7_4;
  wire [0:0] h_u_arrtm8_k2_and2_5;
  wire [0:0] h_u_arrtm8_k2_fa2_5_xor1;
  wire [0:0] h_u_arrtm8_k2_fa2_5_or0;
  wire [0:0] h_u_arrtm8_k2_and3_5;
  wire [0:0] h_u_arrtm8_k2_fa3_5_xor1;
  wire [0:0] h_u_arrtm8_k2_fa3_5_or0;
  wire [0:0] h_u_arrtm8_k2_and4_5;
  wire [0:0] h_u_arrtm8_k2_fa4_5_xor1;
  wire [0:0] h_u_arrtm8_k2_fa4_5_or0;
  wire [0:0] h_u_arrtm8_k2_and5_5;
  wire [0:0] h_u_arrtm8_k2_fa5_5_xor1;
  wire [0:0] h_u_arrtm8_k2_fa5_5_or0;
  wire [0:0] h_u_arrtm8_k2_and6_5;
  wire [0:0] h_u_arrtm8_k2_fa6_5_xor1;
  wire [0:0] h_u_arrtm8_k2_fa6_5_or0;
  wire [0:0] h_u_arrtm8_k2_and7_5;
  wire [0:0] h_u_arrtm8_k2_and2_6;
  wire [0:0] h_u_arrtm8_k2_fa2_6_xor1;
  wire [0:0] h_u_arrtm8_k2_fa2_6_or0;
  wire [0:0] h_u_arrtm8_k2_and3_6;
  wire [0:0] h_u_arrtm8_k2_fa3_6_xor1;
  wire [0:0] h_u_arrtm8_k2_fa3_6_or0;
  wire [0:0] h_u_arrtm8_k2_and4_6;
  wire [0:0] h_u_arrtm8_k2_fa4_6_xor1;
  wire [0:0] h_u_arrtm8_k2_fa4_6_or0;
  wire [0:0] h_u_arrtm8_k2_and5_6;
  wire [0:0] h_u_arrtm8_k2_fa5_6_xor1;
  wire [0:0] h_u_arrtm8_k2_fa5_6_or0;
  wire [0:0] h_u_arrtm8_k2_and6_6;
  wire [0:0] h_u_arrtm8_k2_fa6_6_xor1;
  wire [0:0] h_u_arrtm8_k2_fa6_6_or0;
  wire [0:0] h_u_arrtm8_k2_and7_6;
  wire [0:0] h_u_arrtm8_k2_and2_7;
  wire [0:0] h_u_arrtm8_k2_fa2_7_xor1;
  wire [0:0] h_u_arrtm8_k2_fa2_7_or0;
  wire [0:0] h_u_arrtm8_k2_and3_7;
  wire [0:0] h_u_arrtm8_k2_fa3_7_xor1;
  wire [0:0] h_u_arrtm8_k2_fa3_7_or0;
  wire [0:0] h_u_arrtm8_k2_and4_7;
  wire [0:0] h_u_arrtm8_k2_fa4_7_xor1;
  wire [0:0] h_u_arrtm8_k2_fa4_7_or0;
  wire [0:0] h_u_arrtm8_k2_and5_7;
  wire [0:0] h_u_arrtm8_k2_fa5_7_xor1;
  wire [0:0] h_u_arrtm8_k2_fa5_7_or0;
  wire [0:0] h_u_arrtm8_k2_and6_7;
  wire [0:0] h_u_arrtm8_k2_fa6_7_xor1;
  wire [0:0] h_u_arrtm8_k2_fa6_7_or0;
  wire [0:0] h_u_arrtm8_k2_and7_7;
  wire [5:0] h_u_arrtm8_k2_u_cla6_a;
  wire [5:0] h_u_arrtm8_k2_u_cla6_b;
  wire [6:0] h_u_arrtm8_k2_u_cla6_out;

  and_gate and_gate_h_u_arrtm8_k2_and2_2(.a(a[2]), .b(b[2]), .out(h_u_arrtm8_k2_and2_2));
  and_gate and_gate_h_u_arrtm8_k2_and3_2(.a(a[3]), .b(b[2]), .out(h_u_arrtm8_k2_and3_2));
  and_gate and_gate_h_u_arrtm8_k2_and4_2(.a(a[4]), .b(b[2]), .out(h_u_arrtm8_k2_and4_2));
  and_gate and_gate_h_u_arrtm8_k2_and5_2(.a(a[5]), .b(b[2]), .out(h_u_arrtm8_k2_and5_2));
  and_gate and_gate_h_u_arrtm8_k2_and6_2(.a(a[6]), .b(b[2]), .out(h_u_arrtm8_k2_and6_2));
  and_gate and_gate_h_u_arrtm8_k2_and7_2(.a(a[7]), .b(b[2]), .out(h_u_arrtm8_k2_and7_2));
  and_gate and_gate_h_u_arrtm8_k2_and2_3(.a(a[2]), .b(b[3]), .out(h_u_arrtm8_k2_and2_3));
  ha ha_h_u_arrtm8_k2_ha2_3_out(.a(h_u_arrtm8_k2_and2_3[0]), .b(h_u_arrtm8_k2_and3_2[0]), .ha_xor0(h_u_arrtm8_k2_ha2_3_xor0), .ha_and0(h_u_arrtm8_k2_ha2_3_and0));
  and_gate and_gate_h_u_arrtm8_k2_and3_3(.a(a[3]), .b(b[3]), .out(h_u_arrtm8_k2_and3_3));
  ha ha_h_u_arrtm8_k2_ha3_3_out(.a(h_u_arrtm8_k2_and3_3[0]), .b(h_u_arrtm8_k2_and4_2[0]), .ha_xor0(h_u_arrtm8_k2_ha3_3_xor0), .ha_and0(h_u_arrtm8_k2_ha3_3_and0));
  and_gate and_gate_h_u_arrtm8_k2_and4_3(.a(a[4]), .b(b[3]), .out(h_u_arrtm8_k2_and4_3));
  ha ha_h_u_arrtm8_k2_ha4_3_out(.a(h_u_arrtm8_k2_and4_3[0]), .b(h_u_arrtm8_k2_and5_2[0]), .ha_xor0(h_u_arrtm8_k2_ha4_3_xor0), .ha_and0(h_u_arrtm8_k2_ha4_3_and0));
  and_gate and_gate_h_u_arrtm8_k2_and5_3(.a(a[5]), .b(b[3]), .out(h_u_arrtm8_k2_and5_3));
  ha ha_h_u_arrtm8_k2_ha5_3_out(.a(h_u_arrtm8_k2_and5_3[0]), .b(h_u_arrtm8_k2_and6_2[0]), .ha_xor0(h_u_arrtm8_k2_ha5_3_xor0), .ha_and0(h_u_arrtm8_k2_ha5_3_and0));
  and_gate and_gate_h_u_arrtm8_k2_and6_3(.a(a[6]), .b(b[3]), .out(h_u_arrtm8_k2_and6_3));
  ha ha_h_u_arrtm8_k2_ha6_3_out(.a(h_u_arrtm8_k2_and6_3[0]), .b(h_u_arrtm8_k2_and7_2[0]), .ha_xor0(h_u_arrtm8_k2_ha6_3_xor0), .ha_and0(h_u_arrtm8_k2_ha6_3_and0));
  and_gate and_gate_h_u_arrtm8_k2_and7_3(.a(a[7]), .b(b[3]), .out(h_u_arrtm8_k2_and7_3));
  and_gate and_gate_h_u_arrtm8_k2_and2_4(.a(a[2]), .b(b[4]), .out(h_u_arrtm8_k2_and2_4));
  fa fa_h_u_arrtm8_k2_fa2_4_out(.a(h_u_arrtm8_k2_and2_4[0]), .b(h_u_arrtm8_k2_ha3_3_xor0[0]), .cin(h_u_arrtm8_k2_ha2_3_and0[0]), .fa_xor1(h_u_arrtm8_k2_fa2_4_xor1), .fa_or0(h_u_arrtm8_k2_fa2_4_or0));
  and_gate and_gate_h_u_arrtm8_k2_and3_4(.a(a[3]), .b(b[4]), .out(h_u_arrtm8_k2_and3_4));
  fa fa_h_u_arrtm8_k2_fa3_4_out(.a(h_u_arrtm8_k2_and3_4[0]), .b(h_u_arrtm8_k2_ha4_3_xor0[0]), .cin(h_u_arrtm8_k2_ha3_3_and0[0]), .fa_xor1(h_u_arrtm8_k2_fa3_4_xor1), .fa_or0(h_u_arrtm8_k2_fa3_4_or0));
  and_gate and_gate_h_u_arrtm8_k2_and4_4(.a(a[4]), .b(b[4]), .out(h_u_arrtm8_k2_and4_4));
  fa fa_h_u_arrtm8_k2_fa4_4_out(.a(h_u_arrtm8_k2_and4_4[0]), .b(h_u_arrtm8_k2_ha5_3_xor0[0]), .cin(h_u_arrtm8_k2_ha4_3_and0[0]), .fa_xor1(h_u_arrtm8_k2_fa4_4_xor1), .fa_or0(h_u_arrtm8_k2_fa4_4_or0));
  and_gate and_gate_h_u_arrtm8_k2_and5_4(.a(a[5]), .b(b[4]), .out(h_u_arrtm8_k2_and5_4));
  fa fa_h_u_arrtm8_k2_fa5_4_out(.a(h_u_arrtm8_k2_and5_4[0]), .b(h_u_arrtm8_k2_ha6_3_xor0[0]), .cin(h_u_arrtm8_k2_ha5_3_and0[0]), .fa_xor1(h_u_arrtm8_k2_fa5_4_xor1), .fa_or0(h_u_arrtm8_k2_fa5_4_or0));
  and_gate and_gate_h_u_arrtm8_k2_and6_4(.a(a[6]), .b(b[4]), .out(h_u_arrtm8_k2_and6_4));
  fa fa_h_u_arrtm8_k2_fa6_4_out(.a(h_u_arrtm8_k2_and6_4[0]), .b(h_u_arrtm8_k2_and7_3[0]), .cin(h_u_arrtm8_k2_ha6_3_and0[0]), .fa_xor1(h_u_arrtm8_k2_fa6_4_xor1), .fa_or0(h_u_arrtm8_k2_fa6_4_or0));
  and_gate and_gate_h_u_arrtm8_k2_and7_4(.a(a[7]), .b(b[4]), .out(h_u_arrtm8_k2_and7_4));
  and_gate and_gate_h_u_arrtm8_k2_and2_5(.a(a[2]), .b(b[5]), .out(h_u_arrtm8_k2_and2_5));
  fa fa_h_u_arrtm8_k2_fa2_5_out(.a(h_u_arrtm8_k2_and2_5[0]), .b(h_u_arrtm8_k2_fa3_4_xor1[0]), .cin(h_u_arrtm8_k2_fa2_4_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa2_5_xor1), .fa_or0(h_u_arrtm8_k2_fa2_5_or0));
  and_gate and_gate_h_u_arrtm8_k2_and3_5(.a(a[3]), .b(b[5]), .out(h_u_arrtm8_k2_and3_5));
  fa fa_h_u_arrtm8_k2_fa3_5_out(.a(h_u_arrtm8_k2_and3_5[0]), .b(h_u_arrtm8_k2_fa4_4_xor1[0]), .cin(h_u_arrtm8_k2_fa3_4_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa3_5_xor1), .fa_or0(h_u_arrtm8_k2_fa3_5_or0));
  and_gate and_gate_h_u_arrtm8_k2_and4_5(.a(a[4]), .b(b[5]), .out(h_u_arrtm8_k2_and4_5));
  fa fa_h_u_arrtm8_k2_fa4_5_out(.a(h_u_arrtm8_k2_and4_5[0]), .b(h_u_arrtm8_k2_fa5_4_xor1[0]), .cin(h_u_arrtm8_k2_fa4_4_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa4_5_xor1), .fa_or0(h_u_arrtm8_k2_fa4_5_or0));
  and_gate and_gate_h_u_arrtm8_k2_and5_5(.a(a[5]), .b(b[5]), .out(h_u_arrtm8_k2_and5_5));
  fa fa_h_u_arrtm8_k2_fa5_5_out(.a(h_u_arrtm8_k2_and5_5[0]), .b(h_u_arrtm8_k2_fa6_4_xor1[0]), .cin(h_u_arrtm8_k2_fa5_4_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa5_5_xor1), .fa_or0(h_u_arrtm8_k2_fa5_5_or0));
  and_gate and_gate_h_u_arrtm8_k2_and6_5(.a(a[6]), .b(b[5]), .out(h_u_arrtm8_k2_and6_5));
  fa fa_h_u_arrtm8_k2_fa6_5_out(.a(h_u_arrtm8_k2_and6_5[0]), .b(h_u_arrtm8_k2_and7_4[0]), .cin(h_u_arrtm8_k2_fa6_4_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa6_5_xor1), .fa_or0(h_u_arrtm8_k2_fa6_5_or0));
  and_gate and_gate_h_u_arrtm8_k2_and7_5(.a(a[7]), .b(b[5]), .out(h_u_arrtm8_k2_and7_5));
  and_gate and_gate_h_u_arrtm8_k2_and2_6(.a(a[2]), .b(b[6]), .out(h_u_arrtm8_k2_and2_6));
  fa fa_h_u_arrtm8_k2_fa2_6_out(.a(h_u_arrtm8_k2_and2_6[0]), .b(h_u_arrtm8_k2_fa3_5_xor1[0]), .cin(h_u_arrtm8_k2_fa2_5_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa2_6_xor1), .fa_or0(h_u_arrtm8_k2_fa2_6_or0));
  and_gate and_gate_h_u_arrtm8_k2_and3_6(.a(a[3]), .b(b[6]), .out(h_u_arrtm8_k2_and3_6));
  fa fa_h_u_arrtm8_k2_fa3_6_out(.a(h_u_arrtm8_k2_and3_6[0]), .b(h_u_arrtm8_k2_fa4_5_xor1[0]), .cin(h_u_arrtm8_k2_fa3_5_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa3_6_xor1), .fa_or0(h_u_arrtm8_k2_fa3_6_or0));
  and_gate and_gate_h_u_arrtm8_k2_and4_6(.a(a[4]), .b(b[6]), .out(h_u_arrtm8_k2_and4_6));
  fa fa_h_u_arrtm8_k2_fa4_6_out(.a(h_u_arrtm8_k2_and4_6[0]), .b(h_u_arrtm8_k2_fa5_5_xor1[0]), .cin(h_u_arrtm8_k2_fa4_5_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa4_6_xor1), .fa_or0(h_u_arrtm8_k2_fa4_6_or0));
  and_gate and_gate_h_u_arrtm8_k2_and5_6(.a(a[5]), .b(b[6]), .out(h_u_arrtm8_k2_and5_6));
  fa fa_h_u_arrtm8_k2_fa5_6_out(.a(h_u_arrtm8_k2_and5_6[0]), .b(h_u_arrtm8_k2_fa6_5_xor1[0]), .cin(h_u_arrtm8_k2_fa5_5_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa5_6_xor1), .fa_or0(h_u_arrtm8_k2_fa5_6_or0));
  and_gate and_gate_h_u_arrtm8_k2_and6_6(.a(a[6]), .b(b[6]), .out(h_u_arrtm8_k2_and6_6));
  fa fa_h_u_arrtm8_k2_fa6_6_out(.a(h_u_arrtm8_k2_and6_6[0]), .b(h_u_arrtm8_k2_and7_5[0]), .cin(h_u_arrtm8_k2_fa6_5_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa6_6_xor1), .fa_or0(h_u_arrtm8_k2_fa6_6_or0));
  and_gate and_gate_h_u_arrtm8_k2_and7_6(.a(a[7]), .b(b[6]), .out(h_u_arrtm8_k2_and7_6));
  and_gate and_gate_h_u_arrtm8_k2_and2_7(.a(a[2]), .b(b[7]), .out(h_u_arrtm8_k2_and2_7));
  fa fa_h_u_arrtm8_k2_fa2_7_out(.a(h_u_arrtm8_k2_and2_7[0]), .b(h_u_arrtm8_k2_fa3_6_xor1[0]), .cin(h_u_arrtm8_k2_fa2_6_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa2_7_xor1), .fa_or0(h_u_arrtm8_k2_fa2_7_or0));
  and_gate and_gate_h_u_arrtm8_k2_and3_7(.a(a[3]), .b(b[7]), .out(h_u_arrtm8_k2_and3_7));
  fa fa_h_u_arrtm8_k2_fa3_7_out(.a(h_u_arrtm8_k2_and3_7[0]), .b(h_u_arrtm8_k2_fa4_6_xor1[0]), .cin(h_u_arrtm8_k2_fa3_6_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa3_7_xor1), .fa_or0(h_u_arrtm8_k2_fa3_7_or0));
  and_gate and_gate_h_u_arrtm8_k2_and4_7(.a(a[4]), .b(b[7]), .out(h_u_arrtm8_k2_and4_7));
  fa fa_h_u_arrtm8_k2_fa4_7_out(.a(h_u_arrtm8_k2_and4_7[0]), .b(h_u_arrtm8_k2_fa5_6_xor1[0]), .cin(h_u_arrtm8_k2_fa4_6_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa4_7_xor1), .fa_or0(h_u_arrtm8_k2_fa4_7_or0));
  and_gate and_gate_h_u_arrtm8_k2_and5_7(.a(a[5]), .b(b[7]), .out(h_u_arrtm8_k2_and5_7));
  fa fa_h_u_arrtm8_k2_fa5_7_out(.a(h_u_arrtm8_k2_and5_7[0]), .b(h_u_arrtm8_k2_fa6_6_xor1[0]), .cin(h_u_arrtm8_k2_fa5_6_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa5_7_xor1), .fa_or0(h_u_arrtm8_k2_fa5_7_or0));
  and_gate and_gate_h_u_arrtm8_k2_and6_7(.a(a[6]), .b(b[7]), .out(h_u_arrtm8_k2_and6_7));
  fa fa_h_u_arrtm8_k2_fa6_7_out(.a(h_u_arrtm8_k2_and6_7[0]), .b(h_u_arrtm8_k2_and7_6[0]), .cin(h_u_arrtm8_k2_fa6_6_or0[0]), .fa_xor1(h_u_arrtm8_k2_fa6_7_xor1), .fa_or0(h_u_arrtm8_k2_fa6_7_or0));
  and_gate and_gate_h_u_arrtm8_k2_and7_7(.a(a[7]), .b(b[7]), .out(h_u_arrtm8_k2_and7_7));
  assign h_u_arrtm8_k2_u_cla6_a[0] = h_u_arrtm8_k2_fa3_7_xor1[0];
  assign h_u_arrtm8_k2_u_cla6_a[1] = h_u_arrtm8_k2_fa4_7_xor1[0];
  assign h_u_arrtm8_k2_u_cla6_a[2] = h_u_arrtm8_k2_fa5_7_xor1[0];
  assign h_u_arrtm8_k2_u_cla6_a[3] = h_u_arrtm8_k2_fa6_7_xor1[0];
  assign h_u_arrtm8_k2_u_cla6_a[4] = h_u_arrtm8_k2_and7_7[0];
  assign h_u_arrtm8_k2_u_cla6_a[5] = 1'b0;
  assign h_u_arrtm8_k2_u_cla6_b[0] = h_u_arrtm8_k2_fa2_7_or0[0];
  assign h_u_arrtm8_k2_u_cla6_b[1] = h_u_arrtm8_k2_fa3_7_or0[0];
  assign h_u_arrtm8_k2_u_cla6_b[2] = h_u_arrtm8_k2_fa4_7_or0[0];
  assign h_u_arrtm8_k2_u_cla6_b[3] = h_u_arrtm8_k2_fa5_7_or0[0];
  assign h_u_arrtm8_k2_u_cla6_b[4] = h_u_arrtm8_k2_fa6_7_or0[0];
  assign h_u_arrtm8_k2_u_cla6_b[5] = 1'b0;
  u_cla6 u_cla6_h_u_arrtm8_k2_u_cla6_out(.a(h_u_arrtm8_k2_u_cla6_a), .b(h_u_arrtm8_k2_u_cla6_b), .u_cla6_out(h_u_arrtm8_k2_u_cla6_out));

  assign h_u_arrtm8_k2_out[0] = 1'b0;
  assign h_u_arrtm8_k2_out[1] = 1'b0;
  assign h_u_arrtm8_k2_out[2] = 1'b0;
  assign h_u_arrtm8_k2_out[3] = 1'b0;
  assign h_u_arrtm8_k2_out[4] = h_u_arrtm8_k2_and2_2[0];
  assign h_u_arrtm8_k2_out[5] = h_u_arrtm8_k2_ha2_3_xor0[0];
  assign h_u_arrtm8_k2_out[6] = h_u_arrtm8_k2_fa2_4_xor1[0];
  assign h_u_arrtm8_k2_out[7] = h_u_arrtm8_k2_fa2_5_xor1[0];
  assign h_u_arrtm8_k2_out[8] = h_u_arrtm8_k2_fa2_6_xor1[0];
  assign h_u_arrtm8_k2_out[9] = h_u_arrtm8_k2_fa2_7_xor1[0];
  assign h_u_arrtm8_k2_out[10] = h_u_arrtm8_k2_u_cla6_out[0];
  assign h_u_arrtm8_k2_out[11] = h_u_arrtm8_k2_u_cla6_out[1];
  assign h_u_arrtm8_k2_out[12] = h_u_arrtm8_k2_u_cla6_out[2];
  assign h_u_arrtm8_k2_out[13] = h_u_arrtm8_k2_u_cla6_out[3];
  assign h_u_arrtm8_k2_out[14] = h_u_arrtm8_k2_u_cla6_out[4];
  assign h_u_arrtm8_k2_out[15] = h_u_arrtm8_k2_u_cla6_out[5];
endmodule