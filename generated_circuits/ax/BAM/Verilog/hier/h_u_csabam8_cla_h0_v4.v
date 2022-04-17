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

module u_cla8(input [7:0] a, input [7:0] b, output [8:0] u_cla8_out);
  wire [0:0] u_cla8_pg_logic0_or0;
  wire [0:0] u_cla8_pg_logic0_and0;
  wire [0:0] u_cla8_pg_logic0_xor0;
  wire [0:0] u_cla8_pg_logic1_or0;
  wire [0:0] u_cla8_pg_logic1_and0;
  wire [0:0] u_cla8_pg_logic1_xor0;
  wire [0:0] u_cla8_xor1;
  wire [0:0] u_cla8_and0;
  wire [0:0] u_cla8_or0;
  wire [0:0] u_cla8_pg_logic2_or0;
  wire [0:0] u_cla8_pg_logic2_and0;
  wire [0:0] u_cla8_pg_logic2_xor0;
  wire [0:0] u_cla8_xor2;
  wire [0:0] u_cla8_and1;
  wire [0:0] u_cla8_and2;
  wire [0:0] u_cla8_and3;
  wire [0:0] u_cla8_and4;
  wire [0:0] u_cla8_or1;
  wire [0:0] u_cla8_or2;
  wire [0:0] u_cla8_pg_logic3_or0;
  wire [0:0] u_cla8_pg_logic3_and0;
  wire [0:0] u_cla8_pg_logic3_xor0;
  wire [0:0] u_cla8_xor3;
  wire [0:0] u_cla8_and5;
  wire [0:0] u_cla8_and6;
  wire [0:0] u_cla8_and7;
  wire [0:0] u_cla8_and8;
  wire [0:0] u_cla8_and9;
  wire [0:0] u_cla8_and10;
  wire [0:0] u_cla8_and11;
  wire [0:0] u_cla8_or3;
  wire [0:0] u_cla8_or4;
  wire [0:0] u_cla8_or5;
  wire [0:0] u_cla8_pg_logic4_or0;
  wire [0:0] u_cla8_pg_logic4_and0;
  wire [0:0] u_cla8_pg_logic4_xor0;
  wire [0:0] u_cla8_xor4;
  wire [0:0] u_cla8_and12;
  wire [0:0] u_cla8_or6;
  wire [0:0] u_cla8_pg_logic5_or0;
  wire [0:0] u_cla8_pg_logic5_and0;
  wire [0:0] u_cla8_pg_logic5_xor0;
  wire [0:0] u_cla8_xor5;
  wire [0:0] u_cla8_and13;
  wire [0:0] u_cla8_and14;
  wire [0:0] u_cla8_and15;
  wire [0:0] u_cla8_or7;
  wire [0:0] u_cla8_or8;
  wire [0:0] u_cla8_pg_logic6_or0;
  wire [0:0] u_cla8_pg_logic6_and0;
  wire [0:0] u_cla8_pg_logic6_xor0;
  wire [0:0] u_cla8_xor6;
  wire [0:0] u_cla8_and16;
  wire [0:0] u_cla8_and17;
  wire [0:0] u_cla8_and18;
  wire [0:0] u_cla8_and19;
  wire [0:0] u_cla8_and20;
  wire [0:0] u_cla8_and21;
  wire [0:0] u_cla8_or9;
  wire [0:0] u_cla8_or10;
  wire [0:0] u_cla8_or11;
  wire [0:0] u_cla8_pg_logic7_or0;
  wire [0:0] u_cla8_pg_logic7_and0;
  wire [0:0] u_cla8_pg_logic7_xor0;
  wire [0:0] u_cla8_xor7;
  wire [0:0] u_cla8_and22;
  wire [0:0] u_cla8_and23;
  wire [0:0] u_cla8_and24;
  wire [0:0] u_cla8_and25;
  wire [0:0] u_cla8_and26;
  wire [0:0] u_cla8_and27;
  wire [0:0] u_cla8_and28;
  wire [0:0] u_cla8_and29;
  wire [0:0] u_cla8_and30;
  wire [0:0] u_cla8_and31;
  wire [0:0] u_cla8_or12;
  wire [0:0] u_cla8_or13;
  wire [0:0] u_cla8_or14;
  wire [0:0] u_cla8_or15;

  pg_logic pg_logic_u_cla8_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(u_cla8_pg_logic0_or0), .pg_logic_and0(u_cla8_pg_logic0_and0), .pg_logic_xor0(u_cla8_pg_logic0_xor0));
  pg_logic pg_logic_u_cla8_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(u_cla8_pg_logic1_or0), .pg_logic_and0(u_cla8_pg_logic1_and0), .pg_logic_xor0(u_cla8_pg_logic1_xor0));
  xor_gate xor_gate_u_cla8_xor1(.a(u_cla8_pg_logic1_xor0[0]), .b(u_cla8_pg_logic0_and0[0]), .out(u_cla8_xor1));
  and_gate and_gate_u_cla8_and0(.a(u_cla8_pg_logic0_and0[0]), .b(u_cla8_pg_logic1_or0[0]), .out(u_cla8_and0));
  or_gate or_gate_u_cla8_or0(.a(u_cla8_pg_logic1_and0[0]), .b(u_cla8_and0[0]), .out(u_cla8_or0));
  pg_logic pg_logic_u_cla8_pg_logic2_out(.a(a[2]), .b(b[2]), .pg_logic_or0(u_cla8_pg_logic2_or0), .pg_logic_and0(u_cla8_pg_logic2_and0), .pg_logic_xor0(u_cla8_pg_logic2_xor0));
  xor_gate xor_gate_u_cla8_xor2(.a(u_cla8_pg_logic2_xor0[0]), .b(u_cla8_or0[0]), .out(u_cla8_xor2));
  and_gate and_gate_u_cla8_and1(.a(u_cla8_pg_logic2_or0[0]), .b(u_cla8_pg_logic0_or0[0]), .out(u_cla8_and1));
  and_gate and_gate_u_cla8_and2(.a(u_cla8_pg_logic0_and0[0]), .b(u_cla8_pg_logic2_or0[0]), .out(u_cla8_and2));
  and_gate and_gate_u_cla8_and3(.a(u_cla8_and2[0]), .b(u_cla8_pg_logic1_or0[0]), .out(u_cla8_and3));
  and_gate and_gate_u_cla8_and4(.a(u_cla8_pg_logic1_and0[0]), .b(u_cla8_pg_logic2_or0[0]), .out(u_cla8_and4));
  or_gate or_gate_u_cla8_or1(.a(u_cla8_and3[0]), .b(u_cla8_and4[0]), .out(u_cla8_or1));
  or_gate or_gate_u_cla8_or2(.a(u_cla8_pg_logic2_and0[0]), .b(u_cla8_or1[0]), .out(u_cla8_or2));
  pg_logic pg_logic_u_cla8_pg_logic3_out(.a(a[3]), .b(b[3]), .pg_logic_or0(u_cla8_pg_logic3_or0), .pg_logic_and0(u_cla8_pg_logic3_and0), .pg_logic_xor0(u_cla8_pg_logic3_xor0));
  xor_gate xor_gate_u_cla8_xor3(.a(u_cla8_pg_logic3_xor0[0]), .b(u_cla8_or2[0]), .out(u_cla8_xor3));
  and_gate and_gate_u_cla8_and5(.a(u_cla8_pg_logic3_or0[0]), .b(u_cla8_pg_logic1_or0[0]), .out(u_cla8_and5));
  and_gate and_gate_u_cla8_and6(.a(u_cla8_pg_logic0_and0[0]), .b(u_cla8_pg_logic2_or0[0]), .out(u_cla8_and6));
  and_gate and_gate_u_cla8_and7(.a(u_cla8_pg_logic3_or0[0]), .b(u_cla8_pg_logic1_or0[0]), .out(u_cla8_and7));
  and_gate and_gate_u_cla8_and8(.a(u_cla8_and6[0]), .b(u_cla8_and7[0]), .out(u_cla8_and8));
  and_gate and_gate_u_cla8_and9(.a(u_cla8_pg_logic1_and0[0]), .b(u_cla8_pg_logic3_or0[0]), .out(u_cla8_and9));
  and_gate and_gate_u_cla8_and10(.a(u_cla8_and9[0]), .b(u_cla8_pg_logic2_or0[0]), .out(u_cla8_and10));
  and_gate and_gate_u_cla8_and11(.a(u_cla8_pg_logic2_and0[0]), .b(u_cla8_pg_logic3_or0[0]), .out(u_cla8_and11));
  or_gate or_gate_u_cla8_or3(.a(u_cla8_and8[0]), .b(u_cla8_and11[0]), .out(u_cla8_or3));
  or_gate or_gate_u_cla8_or4(.a(u_cla8_and10[0]), .b(u_cla8_or3[0]), .out(u_cla8_or4));
  or_gate or_gate_u_cla8_or5(.a(u_cla8_pg_logic3_and0[0]), .b(u_cla8_or4[0]), .out(u_cla8_or5));
  pg_logic pg_logic_u_cla8_pg_logic4_out(.a(a[4]), .b(b[4]), .pg_logic_or0(u_cla8_pg_logic4_or0), .pg_logic_and0(u_cla8_pg_logic4_and0), .pg_logic_xor0(u_cla8_pg_logic4_xor0));
  xor_gate xor_gate_u_cla8_xor4(.a(u_cla8_pg_logic4_xor0[0]), .b(u_cla8_or5[0]), .out(u_cla8_xor4));
  and_gate and_gate_u_cla8_and12(.a(u_cla8_or5[0]), .b(u_cla8_pg_logic4_or0[0]), .out(u_cla8_and12));
  or_gate or_gate_u_cla8_or6(.a(u_cla8_pg_logic4_and0[0]), .b(u_cla8_and12[0]), .out(u_cla8_or6));
  pg_logic pg_logic_u_cla8_pg_logic5_out(.a(a[5]), .b(b[5]), .pg_logic_or0(u_cla8_pg_logic5_or0), .pg_logic_and0(u_cla8_pg_logic5_and0), .pg_logic_xor0(u_cla8_pg_logic5_xor0));
  xor_gate xor_gate_u_cla8_xor5(.a(u_cla8_pg_logic5_xor0[0]), .b(u_cla8_or6[0]), .out(u_cla8_xor5));
  and_gate and_gate_u_cla8_and13(.a(u_cla8_or5[0]), .b(u_cla8_pg_logic5_or0[0]), .out(u_cla8_and13));
  and_gate and_gate_u_cla8_and14(.a(u_cla8_and13[0]), .b(u_cla8_pg_logic4_or0[0]), .out(u_cla8_and14));
  and_gate and_gate_u_cla8_and15(.a(u_cla8_pg_logic4_and0[0]), .b(u_cla8_pg_logic5_or0[0]), .out(u_cla8_and15));
  or_gate or_gate_u_cla8_or7(.a(u_cla8_and14[0]), .b(u_cla8_and15[0]), .out(u_cla8_or7));
  or_gate or_gate_u_cla8_or8(.a(u_cla8_pg_logic5_and0[0]), .b(u_cla8_or7[0]), .out(u_cla8_or8));
  pg_logic pg_logic_u_cla8_pg_logic6_out(.a(a[6]), .b(b[6]), .pg_logic_or0(u_cla8_pg_logic6_or0), .pg_logic_and0(u_cla8_pg_logic6_and0), .pg_logic_xor0(u_cla8_pg_logic6_xor0));
  xor_gate xor_gate_u_cla8_xor6(.a(u_cla8_pg_logic6_xor0[0]), .b(u_cla8_or8[0]), .out(u_cla8_xor6));
  and_gate and_gate_u_cla8_and16(.a(u_cla8_or5[0]), .b(u_cla8_pg_logic5_or0[0]), .out(u_cla8_and16));
  and_gate and_gate_u_cla8_and17(.a(u_cla8_pg_logic6_or0[0]), .b(u_cla8_pg_logic4_or0[0]), .out(u_cla8_and17));
  and_gate and_gate_u_cla8_and18(.a(u_cla8_and16[0]), .b(u_cla8_and17[0]), .out(u_cla8_and18));
  and_gate and_gate_u_cla8_and19(.a(u_cla8_pg_logic4_and0[0]), .b(u_cla8_pg_logic6_or0[0]), .out(u_cla8_and19));
  and_gate and_gate_u_cla8_and20(.a(u_cla8_and19[0]), .b(u_cla8_pg_logic5_or0[0]), .out(u_cla8_and20));
  and_gate and_gate_u_cla8_and21(.a(u_cla8_pg_logic5_and0[0]), .b(u_cla8_pg_logic6_or0[0]), .out(u_cla8_and21));
  or_gate or_gate_u_cla8_or9(.a(u_cla8_and18[0]), .b(u_cla8_and20[0]), .out(u_cla8_or9));
  or_gate or_gate_u_cla8_or10(.a(u_cla8_or9[0]), .b(u_cla8_and21[0]), .out(u_cla8_or10));
  or_gate or_gate_u_cla8_or11(.a(u_cla8_pg_logic6_and0[0]), .b(u_cla8_or10[0]), .out(u_cla8_or11));
  pg_logic pg_logic_u_cla8_pg_logic7_out(.a(a[7]), .b(b[7]), .pg_logic_or0(u_cla8_pg_logic7_or0), .pg_logic_and0(u_cla8_pg_logic7_and0), .pg_logic_xor0(u_cla8_pg_logic7_xor0));
  xor_gate xor_gate_u_cla8_xor7(.a(u_cla8_pg_logic7_xor0[0]), .b(u_cla8_or11[0]), .out(u_cla8_xor7));
  and_gate and_gate_u_cla8_and22(.a(u_cla8_or5[0]), .b(u_cla8_pg_logic6_or0[0]), .out(u_cla8_and22));
  and_gate and_gate_u_cla8_and23(.a(u_cla8_pg_logic7_or0[0]), .b(u_cla8_pg_logic5_or0[0]), .out(u_cla8_and23));
  and_gate and_gate_u_cla8_and24(.a(u_cla8_and22[0]), .b(u_cla8_and23[0]), .out(u_cla8_and24));
  and_gate and_gate_u_cla8_and25(.a(u_cla8_and24[0]), .b(u_cla8_pg_logic4_or0[0]), .out(u_cla8_and25));
  and_gate and_gate_u_cla8_and26(.a(u_cla8_pg_logic4_and0[0]), .b(u_cla8_pg_logic6_or0[0]), .out(u_cla8_and26));
  and_gate and_gate_u_cla8_and27(.a(u_cla8_pg_logic7_or0[0]), .b(u_cla8_pg_logic5_or0[0]), .out(u_cla8_and27));
  and_gate and_gate_u_cla8_and28(.a(u_cla8_and26[0]), .b(u_cla8_and27[0]), .out(u_cla8_and28));
  and_gate and_gate_u_cla8_and29(.a(u_cla8_pg_logic5_and0[0]), .b(u_cla8_pg_logic7_or0[0]), .out(u_cla8_and29));
  and_gate and_gate_u_cla8_and30(.a(u_cla8_and29[0]), .b(u_cla8_pg_logic6_or0[0]), .out(u_cla8_and30));
  and_gate and_gate_u_cla8_and31(.a(u_cla8_pg_logic6_and0[0]), .b(u_cla8_pg_logic7_or0[0]), .out(u_cla8_and31));
  or_gate or_gate_u_cla8_or12(.a(u_cla8_and25[0]), .b(u_cla8_and30[0]), .out(u_cla8_or12));
  or_gate or_gate_u_cla8_or13(.a(u_cla8_and28[0]), .b(u_cla8_and31[0]), .out(u_cla8_or13));
  or_gate or_gate_u_cla8_or14(.a(u_cla8_or12[0]), .b(u_cla8_or13[0]), .out(u_cla8_or14));
  or_gate or_gate_u_cla8_or15(.a(u_cla8_pg_logic7_and0[0]), .b(u_cla8_or14[0]), .out(u_cla8_or15));

  assign u_cla8_out[0] = u_cla8_pg_logic0_xor0[0];
  assign u_cla8_out[1] = u_cla8_xor1[0];
  assign u_cla8_out[2] = u_cla8_xor2[0];
  assign u_cla8_out[3] = u_cla8_xor3[0];
  assign u_cla8_out[4] = u_cla8_xor4[0];
  assign u_cla8_out[5] = u_cla8_xor5[0];
  assign u_cla8_out[6] = u_cla8_xor6[0];
  assign u_cla8_out[7] = u_cla8_xor7[0];
  assign u_cla8_out[8] = u_cla8_or15[0];
endmodule

module h_u_csabam8_cla_h0_v4(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_cla_h0_v4_out);
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_1;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha3_1_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha3_1_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_1;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha4_1_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha4_1_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_1;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha5_1_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha5_1_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_1;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha6_1_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha6_1_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_1;
  wire [0:0] h_u_csabam8_cla_h0_v4_and2_2;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha2_2_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha2_2_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_2;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_2_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_2_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_2;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_2_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_2_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_2;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_2_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_2_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_2;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_2_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_2_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_2;
  wire [0:0] h_u_csabam8_cla_h0_v4_and1_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha1_3_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha1_3_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and2_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_3_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_3_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_3_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_3_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_3_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_3_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_3_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_3_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_3_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_3_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_3;
  wire [0:0] h_u_csabam8_cla_h0_v4_and0_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha0_4_xor0;
  wire [0:0] h_u_csabam8_cla_h0_v4_ha0_4_and0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and1_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_4_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_4_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and2_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_4_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_4_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_4_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_4_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_4_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_4_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_4_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_4_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_4_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_4_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_4;
  wire [0:0] h_u_csabam8_cla_h0_v4_and0_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa0_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa0_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and1_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and2_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_5_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_5_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_5;
  wire [0:0] h_u_csabam8_cla_h0_v4_and0_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa0_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa0_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and1_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and2_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_6_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_6_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_6;
  wire [0:0] h_u_csabam8_cla_h0_v4_and0_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa0_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa0_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and1_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa1_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and2_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa2_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and3_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa3_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and4_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa4_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and5_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa5_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and6_7;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_7_xor1;
  wire [0:0] h_u_csabam8_cla_h0_v4_fa6_7_or0;
  wire [0:0] h_u_csabam8_cla_h0_v4_and7_7;
  wire [7:0] h_u_csabam8_cla_h0_v4_u_cla8_a;
  wire [7:0] h_u_csabam8_cla_h0_v4_u_cla8_b;
  wire [8:0] h_u_csabam8_cla_h0_v4_u_cla8_out;

  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_0(.a(a[4]), .b(b[0]), .out(h_u_csabam8_cla_h0_v4_and4_0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_0(.a(a[5]), .b(b[0]), .out(h_u_csabam8_cla_h0_v4_and5_0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_0(.a(a[6]), .b(b[0]), .out(h_u_csabam8_cla_h0_v4_and6_0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_0(.a(a[7]), .b(b[0]), .out(h_u_csabam8_cla_h0_v4_and7_0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_1(.a(a[3]), .b(b[1]), .out(h_u_csabam8_cla_h0_v4_and3_1));
  ha ha_h_u_csabam8_cla_h0_v4_ha3_1_out(.a(h_u_csabam8_cla_h0_v4_and3_1[0]), .b(h_u_csabam8_cla_h0_v4_and4_0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha3_1_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha3_1_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_1(.a(a[4]), .b(b[1]), .out(h_u_csabam8_cla_h0_v4_and4_1));
  ha ha_h_u_csabam8_cla_h0_v4_ha4_1_out(.a(h_u_csabam8_cla_h0_v4_and4_1[0]), .b(h_u_csabam8_cla_h0_v4_and5_0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha4_1_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha4_1_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_1(.a(a[5]), .b(b[1]), .out(h_u_csabam8_cla_h0_v4_and5_1));
  ha ha_h_u_csabam8_cla_h0_v4_ha5_1_out(.a(h_u_csabam8_cla_h0_v4_and5_1[0]), .b(h_u_csabam8_cla_h0_v4_and6_0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha5_1_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha5_1_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_1(.a(a[6]), .b(b[1]), .out(h_u_csabam8_cla_h0_v4_and6_1));
  ha ha_h_u_csabam8_cla_h0_v4_ha6_1_out(.a(h_u_csabam8_cla_h0_v4_and6_1[0]), .b(h_u_csabam8_cla_h0_v4_and7_0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha6_1_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha6_1_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_1(.a(a[7]), .b(b[1]), .out(h_u_csabam8_cla_h0_v4_and7_1));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and2_2(.a(a[2]), .b(b[2]), .out(h_u_csabam8_cla_h0_v4_and2_2));
  ha ha_h_u_csabam8_cla_h0_v4_ha2_2_out(.a(h_u_csabam8_cla_h0_v4_and2_2[0]), .b(h_u_csabam8_cla_h0_v4_ha3_1_xor0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha2_2_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha2_2_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_2(.a(a[3]), .b(b[2]), .out(h_u_csabam8_cla_h0_v4_and3_2));
  fa fa_h_u_csabam8_cla_h0_v4_fa3_2_out(.a(h_u_csabam8_cla_h0_v4_and3_2[0]), .b(h_u_csabam8_cla_h0_v4_ha4_1_xor0[0]), .cin(h_u_csabam8_cla_h0_v4_ha3_1_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa3_2_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa3_2_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_2(.a(a[4]), .b(b[2]), .out(h_u_csabam8_cla_h0_v4_and4_2));
  fa fa_h_u_csabam8_cla_h0_v4_fa4_2_out(.a(h_u_csabam8_cla_h0_v4_and4_2[0]), .b(h_u_csabam8_cla_h0_v4_ha5_1_xor0[0]), .cin(h_u_csabam8_cla_h0_v4_ha4_1_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa4_2_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa4_2_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_2(.a(a[5]), .b(b[2]), .out(h_u_csabam8_cla_h0_v4_and5_2));
  fa fa_h_u_csabam8_cla_h0_v4_fa5_2_out(.a(h_u_csabam8_cla_h0_v4_and5_2[0]), .b(h_u_csabam8_cla_h0_v4_ha6_1_xor0[0]), .cin(h_u_csabam8_cla_h0_v4_ha5_1_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa5_2_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa5_2_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_2(.a(a[6]), .b(b[2]), .out(h_u_csabam8_cla_h0_v4_and6_2));
  fa fa_h_u_csabam8_cla_h0_v4_fa6_2_out(.a(h_u_csabam8_cla_h0_v4_and6_2[0]), .b(h_u_csabam8_cla_h0_v4_and7_1[0]), .cin(h_u_csabam8_cla_h0_v4_ha6_1_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa6_2_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa6_2_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_2(.a(a[7]), .b(b[2]), .out(h_u_csabam8_cla_h0_v4_and7_2));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and1_3(.a(a[1]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and1_3));
  ha ha_h_u_csabam8_cla_h0_v4_ha1_3_out(.a(h_u_csabam8_cla_h0_v4_and1_3[0]), .b(h_u_csabam8_cla_h0_v4_ha2_2_xor0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha1_3_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha1_3_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and2_3(.a(a[2]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and2_3));
  fa fa_h_u_csabam8_cla_h0_v4_fa2_3_out(.a(h_u_csabam8_cla_h0_v4_and2_3[0]), .b(h_u_csabam8_cla_h0_v4_fa3_2_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_ha2_2_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa2_3_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa2_3_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_3(.a(a[3]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and3_3));
  fa fa_h_u_csabam8_cla_h0_v4_fa3_3_out(.a(h_u_csabam8_cla_h0_v4_and3_3[0]), .b(h_u_csabam8_cla_h0_v4_fa4_2_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa3_2_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa3_3_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa3_3_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_3(.a(a[4]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and4_3));
  fa fa_h_u_csabam8_cla_h0_v4_fa4_3_out(.a(h_u_csabam8_cla_h0_v4_and4_3[0]), .b(h_u_csabam8_cla_h0_v4_fa5_2_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa4_2_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa4_3_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa4_3_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_3(.a(a[5]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and5_3));
  fa fa_h_u_csabam8_cla_h0_v4_fa5_3_out(.a(h_u_csabam8_cla_h0_v4_and5_3[0]), .b(h_u_csabam8_cla_h0_v4_fa6_2_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa5_2_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa5_3_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa5_3_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_3(.a(a[6]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and6_3));
  fa fa_h_u_csabam8_cla_h0_v4_fa6_3_out(.a(h_u_csabam8_cla_h0_v4_and6_3[0]), .b(h_u_csabam8_cla_h0_v4_and7_2[0]), .cin(h_u_csabam8_cla_h0_v4_fa6_2_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa6_3_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa6_3_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_3(.a(a[7]), .b(b[3]), .out(h_u_csabam8_cla_h0_v4_and7_3));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and0_4(.a(a[0]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and0_4));
  ha ha_h_u_csabam8_cla_h0_v4_ha0_4_out(.a(h_u_csabam8_cla_h0_v4_and0_4[0]), .b(h_u_csabam8_cla_h0_v4_ha1_3_xor0[0]), .ha_xor0(h_u_csabam8_cla_h0_v4_ha0_4_xor0), .ha_and0(h_u_csabam8_cla_h0_v4_ha0_4_and0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and1_4(.a(a[1]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and1_4));
  fa fa_h_u_csabam8_cla_h0_v4_fa1_4_out(.a(h_u_csabam8_cla_h0_v4_and1_4[0]), .b(h_u_csabam8_cla_h0_v4_fa2_3_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_ha1_3_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa1_4_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa1_4_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and2_4(.a(a[2]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and2_4));
  fa fa_h_u_csabam8_cla_h0_v4_fa2_4_out(.a(h_u_csabam8_cla_h0_v4_and2_4[0]), .b(h_u_csabam8_cla_h0_v4_fa3_3_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa2_3_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa2_4_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa2_4_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_4(.a(a[3]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and3_4));
  fa fa_h_u_csabam8_cla_h0_v4_fa3_4_out(.a(h_u_csabam8_cla_h0_v4_and3_4[0]), .b(h_u_csabam8_cla_h0_v4_fa4_3_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa3_3_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa3_4_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa3_4_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_4(.a(a[4]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and4_4));
  fa fa_h_u_csabam8_cla_h0_v4_fa4_4_out(.a(h_u_csabam8_cla_h0_v4_and4_4[0]), .b(h_u_csabam8_cla_h0_v4_fa5_3_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa4_3_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa4_4_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa4_4_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_4(.a(a[5]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and5_4));
  fa fa_h_u_csabam8_cla_h0_v4_fa5_4_out(.a(h_u_csabam8_cla_h0_v4_and5_4[0]), .b(h_u_csabam8_cla_h0_v4_fa6_3_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa5_3_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa5_4_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa5_4_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_4(.a(a[6]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and6_4));
  fa fa_h_u_csabam8_cla_h0_v4_fa6_4_out(.a(h_u_csabam8_cla_h0_v4_and6_4[0]), .b(h_u_csabam8_cla_h0_v4_and7_3[0]), .cin(h_u_csabam8_cla_h0_v4_fa6_3_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa6_4_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa6_4_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_4(.a(a[7]), .b(b[4]), .out(h_u_csabam8_cla_h0_v4_and7_4));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and0_5(.a(a[0]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and0_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa0_5_out(.a(h_u_csabam8_cla_h0_v4_and0_5[0]), .b(h_u_csabam8_cla_h0_v4_fa1_4_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_ha0_4_and0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa0_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa0_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and1_5(.a(a[1]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and1_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa1_5_out(.a(h_u_csabam8_cla_h0_v4_and1_5[0]), .b(h_u_csabam8_cla_h0_v4_fa2_4_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa1_4_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa1_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa1_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and2_5(.a(a[2]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and2_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa2_5_out(.a(h_u_csabam8_cla_h0_v4_and2_5[0]), .b(h_u_csabam8_cla_h0_v4_fa3_4_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa2_4_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa2_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa2_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_5(.a(a[3]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and3_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa3_5_out(.a(h_u_csabam8_cla_h0_v4_and3_5[0]), .b(h_u_csabam8_cla_h0_v4_fa4_4_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa3_4_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa3_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa3_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_5(.a(a[4]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and4_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa4_5_out(.a(h_u_csabam8_cla_h0_v4_and4_5[0]), .b(h_u_csabam8_cla_h0_v4_fa5_4_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa4_4_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa4_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa4_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_5(.a(a[5]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and5_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa5_5_out(.a(h_u_csabam8_cla_h0_v4_and5_5[0]), .b(h_u_csabam8_cla_h0_v4_fa6_4_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa5_4_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa5_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa5_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_5(.a(a[6]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and6_5));
  fa fa_h_u_csabam8_cla_h0_v4_fa6_5_out(.a(h_u_csabam8_cla_h0_v4_and6_5[0]), .b(h_u_csabam8_cla_h0_v4_and7_4[0]), .cin(h_u_csabam8_cla_h0_v4_fa6_4_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa6_5_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa6_5_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_5(.a(a[7]), .b(b[5]), .out(h_u_csabam8_cla_h0_v4_and7_5));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and0_6(.a(a[0]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and0_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa0_6_out(.a(h_u_csabam8_cla_h0_v4_and0_6[0]), .b(h_u_csabam8_cla_h0_v4_fa1_5_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa0_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa0_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa0_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and1_6(.a(a[1]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and1_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa1_6_out(.a(h_u_csabam8_cla_h0_v4_and1_6[0]), .b(h_u_csabam8_cla_h0_v4_fa2_5_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa1_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa1_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa1_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and2_6(.a(a[2]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and2_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa2_6_out(.a(h_u_csabam8_cla_h0_v4_and2_6[0]), .b(h_u_csabam8_cla_h0_v4_fa3_5_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa2_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa2_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa2_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_6(.a(a[3]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and3_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa3_6_out(.a(h_u_csabam8_cla_h0_v4_and3_6[0]), .b(h_u_csabam8_cla_h0_v4_fa4_5_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa3_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa3_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa3_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_6(.a(a[4]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and4_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa4_6_out(.a(h_u_csabam8_cla_h0_v4_and4_6[0]), .b(h_u_csabam8_cla_h0_v4_fa5_5_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa4_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa4_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa4_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_6(.a(a[5]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and5_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa5_6_out(.a(h_u_csabam8_cla_h0_v4_and5_6[0]), .b(h_u_csabam8_cla_h0_v4_fa6_5_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa5_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa5_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa5_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and6_6));
  fa fa_h_u_csabam8_cla_h0_v4_fa6_6_out(.a(h_u_csabam8_cla_h0_v4_and6_6[0]), .b(h_u_csabam8_cla_h0_v4_and7_5[0]), .cin(h_u_csabam8_cla_h0_v4_fa6_5_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa6_6_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa6_6_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csabam8_cla_h0_v4_and7_6));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and0_7(.a(a[0]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and0_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa0_7_out(.a(h_u_csabam8_cla_h0_v4_and0_7[0]), .b(h_u_csabam8_cla_h0_v4_fa1_6_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa0_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa0_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa0_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and1_7(.a(a[1]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and1_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa1_7_out(.a(h_u_csabam8_cla_h0_v4_and1_7[0]), .b(h_u_csabam8_cla_h0_v4_fa2_6_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa1_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa1_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa1_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and2_7(.a(a[2]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and2_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa2_7_out(.a(h_u_csabam8_cla_h0_v4_and2_7[0]), .b(h_u_csabam8_cla_h0_v4_fa3_6_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa2_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa2_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa2_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and3_7(.a(a[3]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and3_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa3_7_out(.a(h_u_csabam8_cla_h0_v4_and3_7[0]), .b(h_u_csabam8_cla_h0_v4_fa4_6_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa3_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa3_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa3_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and4_7(.a(a[4]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and4_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa4_7_out(.a(h_u_csabam8_cla_h0_v4_and4_7[0]), .b(h_u_csabam8_cla_h0_v4_fa5_6_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa4_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa4_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa4_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and5_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa5_7_out(.a(h_u_csabam8_cla_h0_v4_and5_7[0]), .b(h_u_csabam8_cla_h0_v4_fa6_6_xor1[0]), .cin(h_u_csabam8_cla_h0_v4_fa5_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa5_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa5_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and6_7));
  fa fa_h_u_csabam8_cla_h0_v4_fa6_7_out(.a(h_u_csabam8_cla_h0_v4_and6_7[0]), .b(h_u_csabam8_cla_h0_v4_and7_6[0]), .cin(h_u_csabam8_cla_h0_v4_fa6_6_or0[0]), .fa_xor1(h_u_csabam8_cla_h0_v4_fa6_7_xor1), .fa_or0(h_u_csabam8_cla_h0_v4_fa6_7_or0));
  and_gate and_gate_h_u_csabam8_cla_h0_v4_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_cla_h0_v4_and7_7));
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[0] = h_u_csabam8_cla_h0_v4_fa1_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[1] = h_u_csabam8_cla_h0_v4_fa2_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[2] = h_u_csabam8_cla_h0_v4_fa3_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[3] = h_u_csabam8_cla_h0_v4_fa4_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[4] = h_u_csabam8_cla_h0_v4_fa5_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[5] = h_u_csabam8_cla_h0_v4_fa6_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[6] = h_u_csabam8_cla_h0_v4_and7_7[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_a[7] = 1'b0;
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[0] = h_u_csabam8_cla_h0_v4_fa0_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[1] = h_u_csabam8_cla_h0_v4_fa1_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[2] = h_u_csabam8_cla_h0_v4_fa2_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[3] = h_u_csabam8_cla_h0_v4_fa3_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[4] = h_u_csabam8_cla_h0_v4_fa4_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[5] = h_u_csabam8_cla_h0_v4_fa5_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[6] = h_u_csabam8_cla_h0_v4_fa6_7_or0[0];
  assign h_u_csabam8_cla_h0_v4_u_cla8_b[7] = 1'b0;
  u_cla8 u_cla8_h_u_csabam8_cla_h0_v4_u_cla8_out(.a(h_u_csabam8_cla_h0_v4_u_cla8_a), .b(h_u_csabam8_cla_h0_v4_u_cla8_b), .u_cla8_out(h_u_csabam8_cla_h0_v4_u_cla8_out));

  assign h_u_csabam8_cla_h0_v4_out[0] = 1'b0;
  assign h_u_csabam8_cla_h0_v4_out[1] = 1'b0;
  assign h_u_csabam8_cla_h0_v4_out[2] = 1'b0;
  assign h_u_csabam8_cla_h0_v4_out[3] = 1'b0;
  assign h_u_csabam8_cla_h0_v4_out[4] = h_u_csabam8_cla_h0_v4_ha0_4_xor0[0];
  assign h_u_csabam8_cla_h0_v4_out[5] = h_u_csabam8_cla_h0_v4_fa0_5_xor1[0];
  assign h_u_csabam8_cla_h0_v4_out[6] = h_u_csabam8_cla_h0_v4_fa0_6_xor1[0];
  assign h_u_csabam8_cla_h0_v4_out[7] = h_u_csabam8_cla_h0_v4_fa0_7_xor1[0];
  assign h_u_csabam8_cla_h0_v4_out[8] = h_u_csabam8_cla_h0_v4_u_cla8_out[0];
  assign h_u_csabam8_cla_h0_v4_out[9] = h_u_csabam8_cla_h0_v4_u_cla8_out[1];
  assign h_u_csabam8_cla_h0_v4_out[10] = h_u_csabam8_cla_h0_v4_u_cla8_out[2];
  assign h_u_csabam8_cla_h0_v4_out[11] = h_u_csabam8_cla_h0_v4_u_cla8_out[3];
  assign h_u_csabam8_cla_h0_v4_out[12] = h_u_csabam8_cla_h0_v4_u_cla8_out[4];
  assign h_u_csabam8_cla_h0_v4_out[13] = h_u_csabam8_cla_h0_v4_u_cla8_out[5];
  assign h_u_csabam8_cla_h0_v4_out[14] = h_u_csabam8_cla_h0_v4_u_cla8_out[6];
  assign h_u_csabam8_cla_h0_v4_out[15] = h_u_csabam8_cla_h0_v4_u_cla8_out[7];
endmodule