module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
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

module mux2to1(input [0:0] d0, input [0:0] d1, input [0:0] sel, output [0:0] mux2to1_xor0);
  wire [0:0] mux2to1_and0;
  wire [0:0] mux2to1_not0;
  wire [0:0] mux2to1_and1;
  and_gate and_gate_mux2to1_and0(.a(d1[0]), .b(sel[0]), .out(mux2to1_and0));
  not_gate not_gate_mux2to1_not0(.a(sel[0]), .out(mux2to1_not0));
  and_gate and_gate_mux2to1_and1(.a(d0[0]), .b(mux2to1_not0[0]), .out(mux2to1_and1));
  xor_gate xor_gate_mux2to1_xor0(.a(mux2to1_and0[0]), .b(mux2to1_and1[0]), .out(mux2to1_xor0));
endmodule

module h_u_cska32(input [31:0] a, input [31:0] b, output [32:0] h_u_cska32_out);
  wire [0:0] h_u_cska32_xor0;
  wire [0:0] h_u_cska32_ha0_xor0;
  wire [0:0] h_u_cska32_ha0_and0;
  wire [0:0] h_u_cska32_xor1;
  wire [0:0] h_u_cska32_fa0_xor1;
  wire [0:0] h_u_cska32_fa0_or0;
  wire [0:0] h_u_cska32_xor2;
  wire [0:0] h_u_cska32_fa1_xor1;
  wire [0:0] h_u_cska32_fa1_or0;
  wire [0:0] h_u_cska32_xor3;
  wire [0:0] h_u_cska32_fa2_xor1;
  wire [0:0] h_u_cska32_fa2_or0;
  wire [0:0] h_u_cska32_and_propagate00;
  wire [0:0] h_u_cska32_and_propagate01;
  wire [0:0] h_u_cska32_and_propagate02;
  wire [0:0] h_u_cska32_mux2to10_and1;
  wire [0:0] h_u_cska32_xor4;
  wire [0:0] h_u_cska32_fa3_xor1;
  wire [0:0] h_u_cska32_fa3_or0;
  wire [0:0] h_u_cska32_xor5;
  wire [0:0] h_u_cska32_fa4_xor1;
  wire [0:0] h_u_cska32_fa4_or0;
  wire [0:0] h_u_cska32_xor6;
  wire [0:0] h_u_cska32_fa5_xor1;
  wire [0:0] h_u_cska32_fa5_or0;
  wire [0:0] h_u_cska32_xor7;
  wire [0:0] h_u_cska32_fa6_xor1;
  wire [0:0] h_u_cska32_fa6_or0;
  wire [0:0] h_u_cska32_and_propagate13;
  wire [0:0] h_u_cska32_and_propagate14;
  wire [0:0] h_u_cska32_and_propagate15;
  wire [0:0] h_u_cska32_mux2to11_xor0;
  wire [0:0] h_u_cska32_xor8;
  wire [0:0] h_u_cska32_fa7_xor1;
  wire [0:0] h_u_cska32_fa7_or0;
  wire [0:0] h_u_cska32_xor9;
  wire [0:0] h_u_cska32_fa8_xor1;
  wire [0:0] h_u_cska32_fa8_or0;
  wire [0:0] h_u_cska32_xor10;
  wire [0:0] h_u_cska32_fa9_xor1;
  wire [0:0] h_u_cska32_fa9_or0;
  wire [0:0] h_u_cska32_xor11;
  wire [0:0] h_u_cska32_fa10_xor1;
  wire [0:0] h_u_cska32_fa10_or0;
  wire [0:0] h_u_cska32_and_propagate26;
  wire [0:0] h_u_cska32_and_propagate27;
  wire [0:0] h_u_cska32_and_propagate28;
  wire [0:0] h_u_cska32_mux2to12_xor0;
  wire [0:0] h_u_cska32_xor12;
  wire [0:0] h_u_cska32_fa11_xor1;
  wire [0:0] h_u_cska32_fa11_or0;
  wire [0:0] h_u_cska32_xor13;
  wire [0:0] h_u_cska32_fa12_xor1;
  wire [0:0] h_u_cska32_fa12_or0;
  wire [0:0] h_u_cska32_xor14;
  wire [0:0] h_u_cska32_fa13_xor1;
  wire [0:0] h_u_cska32_fa13_or0;
  wire [0:0] h_u_cska32_xor15;
  wire [0:0] h_u_cska32_fa14_xor1;
  wire [0:0] h_u_cska32_fa14_or0;
  wire [0:0] h_u_cska32_and_propagate39;
  wire [0:0] h_u_cska32_and_propagate310;
  wire [0:0] h_u_cska32_and_propagate311;
  wire [0:0] h_u_cska32_mux2to13_xor0;
  wire [0:0] h_u_cska32_xor16;
  wire [0:0] h_u_cska32_fa15_xor1;
  wire [0:0] h_u_cska32_fa15_or0;
  wire [0:0] h_u_cska32_xor17;
  wire [0:0] h_u_cska32_fa16_xor1;
  wire [0:0] h_u_cska32_fa16_or0;
  wire [0:0] h_u_cska32_xor18;
  wire [0:0] h_u_cska32_fa17_xor1;
  wire [0:0] h_u_cska32_fa17_or0;
  wire [0:0] h_u_cska32_xor19;
  wire [0:0] h_u_cska32_fa18_xor1;
  wire [0:0] h_u_cska32_fa18_or0;
  wire [0:0] h_u_cska32_and_propagate412;
  wire [0:0] h_u_cska32_and_propagate413;
  wire [0:0] h_u_cska32_and_propagate414;
  wire [0:0] h_u_cska32_mux2to14_xor0;
  wire [0:0] h_u_cska32_xor20;
  wire [0:0] h_u_cska32_fa19_xor1;
  wire [0:0] h_u_cska32_fa19_or0;
  wire [0:0] h_u_cska32_xor21;
  wire [0:0] h_u_cska32_fa20_xor1;
  wire [0:0] h_u_cska32_fa20_or0;
  wire [0:0] h_u_cska32_xor22;
  wire [0:0] h_u_cska32_fa21_xor1;
  wire [0:0] h_u_cska32_fa21_or0;
  wire [0:0] h_u_cska32_xor23;
  wire [0:0] h_u_cska32_fa22_xor1;
  wire [0:0] h_u_cska32_fa22_or0;
  wire [0:0] h_u_cska32_and_propagate515;
  wire [0:0] h_u_cska32_and_propagate516;
  wire [0:0] h_u_cska32_and_propagate517;
  wire [0:0] h_u_cska32_mux2to15_xor0;
  wire [0:0] h_u_cska32_xor24;
  wire [0:0] h_u_cska32_fa23_xor1;
  wire [0:0] h_u_cska32_fa23_or0;
  wire [0:0] h_u_cska32_xor25;
  wire [0:0] h_u_cska32_fa24_xor1;
  wire [0:0] h_u_cska32_fa24_or0;
  wire [0:0] h_u_cska32_xor26;
  wire [0:0] h_u_cska32_fa25_xor1;
  wire [0:0] h_u_cska32_fa25_or0;
  wire [0:0] h_u_cska32_xor27;
  wire [0:0] h_u_cska32_fa26_xor1;
  wire [0:0] h_u_cska32_fa26_or0;
  wire [0:0] h_u_cska32_and_propagate618;
  wire [0:0] h_u_cska32_and_propagate619;
  wire [0:0] h_u_cska32_and_propagate620;
  wire [0:0] h_u_cska32_mux2to16_xor0;
  wire [0:0] h_u_cska32_xor28;
  wire [0:0] h_u_cska32_fa27_xor1;
  wire [0:0] h_u_cska32_fa27_or0;
  wire [0:0] h_u_cska32_xor29;
  wire [0:0] h_u_cska32_fa28_xor1;
  wire [0:0] h_u_cska32_fa28_or0;
  wire [0:0] h_u_cska32_xor30;
  wire [0:0] h_u_cska32_fa29_xor1;
  wire [0:0] h_u_cska32_fa29_or0;
  wire [0:0] h_u_cska32_xor31;
  wire [0:0] h_u_cska32_fa30_xor1;
  wire [0:0] h_u_cska32_fa30_or0;
  wire [0:0] h_u_cska32_and_propagate721;
  wire [0:0] h_u_cska32_and_propagate722;
  wire [0:0] h_u_cska32_and_propagate723;
  wire [0:0] h_u_cska32_mux2to17_xor0;

  xor_gate xor_gate_h_u_cska32_xor0(.a(a[0]), .b(b[0]), .out(h_u_cska32_xor0));
  ha ha_h_u_cska32_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(h_u_cska32_ha0_xor0), .ha_and0(h_u_cska32_ha0_and0));
  xor_gate xor_gate_h_u_cska32_xor1(.a(a[1]), .b(b[1]), .out(h_u_cska32_xor1));
  fa fa_h_u_cska32_fa0_out(.a(a[1]), .b(b[1]), .cin(h_u_cska32_ha0_and0[0]), .fa_xor1(h_u_cska32_fa0_xor1), .fa_or0(h_u_cska32_fa0_or0));
  xor_gate xor_gate_h_u_cska32_xor2(.a(a[2]), .b(b[2]), .out(h_u_cska32_xor2));
  fa fa_h_u_cska32_fa1_out(.a(a[2]), .b(b[2]), .cin(h_u_cska32_fa0_or0[0]), .fa_xor1(h_u_cska32_fa1_xor1), .fa_or0(h_u_cska32_fa1_or0));
  xor_gate xor_gate_h_u_cska32_xor3(.a(a[3]), .b(b[3]), .out(h_u_cska32_xor3));
  fa fa_h_u_cska32_fa2_out(.a(a[3]), .b(b[3]), .cin(h_u_cska32_fa1_or0[0]), .fa_xor1(h_u_cska32_fa2_xor1), .fa_or0(h_u_cska32_fa2_or0));
  and_gate and_gate_h_u_cska32_and_propagate00(.a(h_u_cska32_xor0[0]), .b(h_u_cska32_xor2[0]), .out(h_u_cska32_and_propagate00));
  and_gate and_gate_h_u_cska32_and_propagate01(.a(h_u_cska32_xor1[0]), .b(h_u_cska32_xor3[0]), .out(h_u_cska32_and_propagate01));
  and_gate and_gate_h_u_cska32_and_propagate02(.a(h_u_cska32_and_propagate00[0]), .b(h_u_cska32_and_propagate01[0]), .out(h_u_cska32_and_propagate02));
  mux2to1 mux2to1_h_u_cska32_mux2to10_out(.d0(h_u_cska32_fa2_or0[0]), .d1(1'b0), .sel(h_u_cska32_and_propagate02[0]), .mux2to1_xor0(h_u_cska32_mux2to10_and1));
  xor_gate xor_gate_h_u_cska32_xor4(.a(a[4]), .b(b[4]), .out(h_u_cska32_xor4));
  fa fa_h_u_cska32_fa3_out(.a(a[4]), .b(b[4]), .cin(h_u_cska32_mux2to10_and1[0]), .fa_xor1(h_u_cska32_fa3_xor1), .fa_or0(h_u_cska32_fa3_or0));
  xor_gate xor_gate_h_u_cska32_xor5(.a(a[5]), .b(b[5]), .out(h_u_cska32_xor5));
  fa fa_h_u_cska32_fa4_out(.a(a[5]), .b(b[5]), .cin(h_u_cska32_fa3_or0[0]), .fa_xor1(h_u_cska32_fa4_xor1), .fa_or0(h_u_cska32_fa4_or0));
  xor_gate xor_gate_h_u_cska32_xor6(.a(a[6]), .b(b[6]), .out(h_u_cska32_xor6));
  fa fa_h_u_cska32_fa5_out(.a(a[6]), .b(b[6]), .cin(h_u_cska32_fa4_or0[0]), .fa_xor1(h_u_cska32_fa5_xor1), .fa_or0(h_u_cska32_fa5_or0));
  xor_gate xor_gate_h_u_cska32_xor7(.a(a[7]), .b(b[7]), .out(h_u_cska32_xor7));
  fa fa_h_u_cska32_fa6_out(.a(a[7]), .b(b[7]), .cin(h_u_cska32_fa5_or0[0]), .fa_xor1(h_u_cska32_fa6_xor1), .fa_or0(h_u_cska32_fa6_or0));
  and_gate and_gate_h_u_cska32_and_propagate13(.a(h_u_cska32_xor4[0]), .b(h_u_cska32_xor6[0]), .out(h_u_cska32_and_propagate13));
  and_gate and_gate_h_u_cska32_and_propagate14(.a(h_u_cska32_xor5[0]), .b(h_u_cska32_xor7[0]), .out(h_u_cska32_and_propagate14));
  and_gate and_gate_h_u_cska32_and_propagate15(.a(h_u_cska32_and_propagate13[0]), .b(h_u_cska32_and_propagate14[0]), .out(h_u_cska32_and_propagate15));
  mux2to1 mux2to1_h_u_cska32_mux2to11_out(.d0(h_u_cska32_fa6_or0[0]), .d1(h_u_cska32_mux2to10_and1[0]), .sel(h_u_cska32_and_propagate15[0]), .mux2to1_xor0(h_u_cska32_mux2to11_xor0));
  xor_gate xor_gate_h_u_cska32_xor8(.a(a[8]), .b(b[8]), .out(h_u_cska32_xor8));
  fa fa_h_u_cska32_fa7_out(.a(a[8]), .b(b[8]), .cin(h_u_cska32_mux2to11_xor0[0]), .fa_xor1(h_u_cska32_fa7_xor1), .fa_or0(h_u_cska32_fa7_or0));
  xor_gate xor_gate_h_u_cska32_xor9(.a(a[9]), .b(b[9]), .out(h_u_cska32_xor9));
  fa fa_h_u_cska32_fa8_out(.a(a[9]), .b(b[9]), .cin(h_u_cska32_fa7_or0[0]), .fa_xor1(h_u_cska32_fa8_xor1), .fa_or0(h_u_cska32_fa8_or0));
  xor_gate xor_gate_h_u_cska32_xor10(.a(a[10]), .b(b[10]), .out(h_u_cska32_xor10));
  fa fa_h_u_cska32_fa9_out(.a(a[10]), .b(b[10]), .cin(h_u_cska32_fa8_or0[0]), .fa_xor1(h_u_cska32_fa9_xor1), .fa_or0(h_u_cska32_fa9_or0));
  xor_gate xor_gate_h_u_cska32_xor11(.a(a[11]), .b(b[11]), .out(h_u_cska32_xor11));
  fa fa_h_u_cska32_fa10_out(.a(a[11]), .b(b[11]), .cin(h_u_cska32_fa9_or0[0]), .fa_xor1(h_u_cska32_fa10_xor1), .fa_or0(h_u_cska32_fa10_or0));
  and_gate and_gate_h_u_cska32_and_propagate26(.a(h_u_cska32_xor8[0]), .b(h_u_cska32_xor10[0]), .out(h_u_cska32_and_propagate26));
  and_gate and_gate_h_u_cska32_and_propagate27(.a(h_u_cska32_xor9[0]), .b(h_u_cska32_xor11[0]), .out(h_u_cska32_and_propagate27));
  and_gate and_gate_h_u_cska32_and_propagate28(.a(h_u_cska32_and_propagate26[0]), .b(h_u_cska32_and_propagate27[0]), .out(h_u_cska32_and_propagate28));
  mux2to1 mux2to1_h_u_cska32_mux2to12_out(.d0(h_u_cska32_fa10_or0[0]), .d1(h_u_cska32_mux2to11_xor0[0]), .sel(h_u_cska32_and_propagate28[0]), .mux2to1_xor0(h_u_cska32_mux2to12_xor0));
  xor_gate xor_gate_h_u_cska32_xor12(.a(a[12]), .b(b[12]), .out(h_u_cska32_xor12));
  fa fa_h_u_cska32_fa11_out(.a(a[12]), .b(b[12]), .cin(h_u_cska32_mux2to12_xor0[0]), .fa_xor1(h_u_cska32_fa11_xor1), .fa_or0(h_u_cska32_fa11_or0));
  xor_gate xor_gate_h_u_cska32_xor13(.a(a[13]), .b(b[13]), .out(h_u_cska32_xor13));
  fa fa_h_u_cska32_fa12_out(.a(a[13]), .b(b[13]), .cin(h_u_cska32_fa11_or0[0]), .fa_xor1(h_u_cska32_fa12_xor1), .fa_or0(h_u_cska32_fa12_or0));
  xor_gate xor_gate_h_u_cska32_xor14(.a(a[14]), .b(b[14]), .out(h_u_cska32_xor14));
  fa fa_h_u_cska32_fa13_out(.a(a[14]), .b(b[14]), .cin(h_u_cska32_fa12_or0[0]), .fa_xor1(h_u_cska32_fa13_xor1), .fa_or0(h_u_cska32_fa13_or0));
  xor_gate xor_gate_h_u_cska32_xor15(.a(a[15]), .b(b[15]), .out(h_u_cska32_xor15));
  fa fa_h_u_cska32_fa14_out(.a(a[15]), .b(b[15]), .cin(h_u_cska32_fa13_or0[0]), .fa_xor1(h_u_cska32_fa14_xor1), .fa_or0(h_u_cska32_fa14_or0));
  and_gate and_gate_h_u_cska32_and_propagate39(.a(h_u_cska32_xor12[0]), .b(h_u_cska32_xor14[0]), .out(h_u_cska32_and_propagate39));
  and_gate and_gate_h_u_cska32_and_propagate310(.a(h_u_cska32_xor13[0]), .b(h_u_cska32_xor15[0]), .out(h_u_cska32_and_propagate310));
  and_gate and_gate_h_u_cska32_and_propagate311(.a(h_u_cska32_and_propagate39[0]), .b(h_u_cska32_and_propagate310[0]), .out(h_u_cska32_and_propagate311));
  mux2to1 mux2to1_h_u_cska32_mux2to13_out(.d0(h_u_cska32_fa14_or0[0]), .d1(h_u_cska32_mux2to12_xor0[0]), .sel(h_u_cska32_and_propagate311[0]), .mux2to1_xor0(h_u_cska32_mux2to13_xor0));
  xor_gate xor_gate_h_u_cska32_xor16(.a(a[16]), .b(b[16]), .out(h_u_cska32_xor16));
  fa fa_h_u_cska32_fa15_out(.a(a[16]), .b(b[16]), .cin(h_u_cska32_mux2to13_xor0[0]), .fa_xor1(h_u_cska32_fa15_xor1), .fa_or0(h_u_cska32_fa15_or0));
  xor_gate xor_gate_h_u_cska32_xor17(.a(a[17]), .b(b[17]), .out(h_u_cska32_xor17));
  fa fa_h_u_cska32_fa16_out(.a(a[17]), .b(b[17]), .cin(h_u_cska32_fa15_or0[0]), .fa_xor1(h_u_cska32_fa16_xor1), .fa_or0(h_u_cska32_fa16_or0));
  xor_gate xor_gate_h_u_cska32_xor18(.a(a[18]), .b(b[18]), .out(h_u_cska32_xor18));
  fa fa_h_u_cska32_fa17_out(.a(a[18]), .b(b[18]), .cin(h_u_cska32_fa16_or0[0]), .fa_xor1(h_u_cska32_fa17_xor1), .fa_or0(h_u_cska32_fa17_or0));
  xor_gate xor_gate_h_u_cska32_xor19(.a(a[19]), .b(b[19]), .out(h_u_cska32_xor19));
  fa fa_h_u_cska32_fa18_out(.a(a[19]), .b(b[19]), .cin(h_u_cska32_fa17_or0[0]), .fa_xor1(h_u_cska32_fa18_xor1), .fa_or0(h_u_cska32_fa18_or0));
  and_gate and_gate_h_u_cska32_and_propagate412(.a(h_u_cska32_xor16[0]), .b(h_u_cska32_xor18[0]), .out(h_u_cska32_and_propagate412));
  and_gate and_gate_h_u_cska32_and_propagate413(.a(h_u_cska32_xor17[0]), .b(h_u_cska32_xor19[0]), .out(h_u_cska32_and_propagate413));
  and_gate and_gate_h_u_cska32_and_propagate414(.a(h_u_cska32_and_propagate412[0]), .b(h_u_cska32_and_propagate413[0]), .out(h_u_cska32_and_propagate414));
  mux2to1 mux2to1_h_u_cska32_mux2to14_out(.d0(h_u_cska32_fa18_or0[0]), .d1(h_u_cska32_mux2to13_xor0[0]), .sel(h_u_cska32_and_propagate414[0]), .mux2to1_xor0(h_u_cska32_mux2to14_xor0));
  xor_gate xor_gate_h_u_cska32_xor20(.a(a[20]), .b(b[20]), .out(h_u_cska32_xor20));
  fa fa_h_u_cska32_fa19_out(.a(a[20]), .b(b[20]), .cin(h_u_cska32_mux2to14_xor0[0]), .fa_xor1(h_u_cska32_fa19_xor1), .fa_or0(h_u_cska32_fa19_or0));
  xor_gate xor_gate_h_u_cska32_xor21(.a(a[21]), .b(b[21]), .out(h_u_cska32_xor21));
  fa fa_h_u_cska32_fa20_out(.a(a[21]), .b(b[21]), .cin(h_u_cska32_fa19_or0[0]), .fa_xor1(h_u_cska32_fa20_xor1), .fa_or0(h_u_cska32_fa20_or0));
  xor_gate xor_gate_h_u_cska32_xor22(.a(a[22]), .b(b[22]), .out(h_u_cska32_xor22));
  fa fa_h_u_cska32_fa21_out(.a(a[22]), .b(b[22]), .cin(h_u_cska32_fa20_or0[0]), .fa_xor1(h_u_cska32_fa21_xor1), .fa_or0(h_u_cska32_fa21_or0));
  xor_gate xor_gate_h_u_cska32_xor23(.a(a[23]), .b(b[23]), .out(h_u_cska32_xor23));
  fa fa_h_u_cska32_fa22_out(.a(a[23]), .b(b[23]), .cin(h_u_cska32_fa21_or0[0]), .fa_xor1(h_u_cska32_fa22_xor1), .fa_or0(h_u_cska32_fa22_or0));
  and_gate and_gate_h_u_cska32_and_propagate515(.a(h_u_cska32_xor20[0]), .b(h_u_cska32_xor22[0]), .out(h_u_cska32_and_propagate515));
  and_gate and_gate_h_u_cska32_and_propagate516(.a(h_u_cska32_xor21[0]), .b(h_u_cska32_xor23[0]), .out(h_u_cska32_and_propagate516));
  and_gate and_gate_h_u_cska32_and_propagate517(.a(h_u_cska32_and_propagate515[0]), .b(h_u_cska32_and_propagate516[0]), .out(h_u_cska32_and_propagate517));
  mux2to1 mux2to1_h_u_cska32_mux2to15_out(.d0(h_u_cska32_fa22_or0[0]), .d1(h_u_cska32_mux2to14_xor0[0]), .sel(h_u_cska32_and_propagate517[0]), .mux2to1_xor0(h_u_cska32_mux2to15_xor0));
  xor_gate xor_gate_h_u_cska32_xor24(.a(a[24]), .b(b[24]), .out(h_u_cska32_xor24));
  fa fa_h_u_cska32_fa23_out(.a(a[24]), .b(b[24]), .cin(h_u_cska32_mux2to15_xor0[0]), .fa_xor1(h_u_cska32_fa23_xor1), .fa_or0(h_u_cska32_fa23_or0));
  xor_gate xor_gate_h_u_cska32_xor25(.a(a[25]), .b(b[25]), .out(h_u_cska32_xor25));
  fa fa_h_u_cska32_fa24_out(.a(a[25]), .b(b[25]), .cin(h_u_cska32_fa23_or0[0]), .fa_xor1(h_u_cska32_fa24_xor1), .fa_or0(h_u_cska32_fa24_or0));
  xor_gate xor_gate_h_u_cska32_xor26(.a(a[26]), .b(b[26]), .out(h_u_cska32_xor26));
  fa fa_h_u_cska32_fa25_out(.a(a[26]), .b(b[26]), .cin(h_u_cska32_fa24_or0[0]), .fa_xor1(h_u_cska32_fa25_xor1), .fa_or0(h_u_cska32_fa25_or0));
  xor_gate xor_gate_h_u_cska32_xor27(.a(a[27]), .b(b[27]), .out(h_u_cska32_xor27));
  fa fa_h_u_cska32_fa26_out(.a(a[27]), .b(b[27]), .cin(h_u_cska32_fa25_or0[0]), .fa_xor1(h_u_cska32_fa26_xor1), .fa_or0(h_u_cska32_fa26_or0));
  and_gate and_gate_h_u_cska32_and_propagate618(.a(h_u_cska32_xor24[0]), .b(h_u_cska32_xor26[0]), .out(h_u_cska32_and_propagate618));
  and_gate and_gate_h_u_cska32_and_propagate619(.a(h_u_cska32_xor25[0]), .b(h_u_cska32_xor27[0]), .out(h_u_cska32_and_propagate619));
  and_gate and_gate_h_u_cska32_and_propagate620(.a(h_u_cska32_and_propagate618[0]), .b(h_u_cska32_and_propagate619[0]), .out(h_u_cska32_and_propagate620));
  mux2to1 mux2to1_h_u_cska32_mux2to16_out(.d0(h_u_cska32_fa26_or0[0]), .d1(h_u_cska32_mux2to15_xor0[0]), .sel(h_u_cska32_and_propagate620[0]), .mux2to1_xor0(h_u_cska32_mux2to16_xor0));
  xor_gate xor_gate_h_u_cska32_xor28(.a(a[28]), .b(b[28]), .out(h_u_cska32_xor28));
  fa fa_h_u_cska32_fa27_out(.a(a[28]), .b(b[28]), .cin(h_u_cska32_mux2to16_xor0[0]), .fa_xor1(h_u_cska32_fa27_xor1), .fa_or0(h_u_cska32_fa27_or0));
  xor_gate xor_gate_h_u_cska32_xor29(.a(a[29]), .b(b[29]), .out(h_u_cska32_xor29));
  fa fa_h_u_cska32_fa28_out(.a(a[29]), .b(b[29]), .cin(h_u_cska32_fa27_or0[0]), .fa_xor1(h_u_cska32_fa28_xor1), .fa_or0(h_u_cska32_fa28_or0));
  xor_gate xor_gate_h_u_cska32_xor30(.a(a[30]), .b(b[30]), .out(h_u_cska32_xor30));
  fa fa_h_u_cska32_fa29_out(.a(a[30]), .b(b[30]), .cin(h_u_cska32_fa28_or0[0]), .fa_xor1(h_u_cska32_fa29_xor1), .fa_or0(h_u_cska32_fa29_or0));
  xor_gate xor_gate_h_u_cska32_xor31(.a(a[31]), .b(b[31]), .out(h_u_cska32_xor31));
  fa fa_h_u_cska32_fa30_out(.a(a[31]), .b(b[31]), .cin(h_u_cska32_fa29_or0[0]), .fa_xor1(h_u_cska32_fa30_xor1), .fa_or0(h_u_cska32_fa30_or0));
  and_gate and_gate_h_u_cska32_and_propagate721(.a(h_u_cska32_xor28[0]), .b(h_u_cska32_xor30[0]), .out(h_u_cska32_and_propagate721));
  and_gate and_gate_h_u_cska32_and_propagate722(.a(h_u_cska32_xor29[0]), .b(h_u_cska32_xor31[0]), .out(h_u_cska32_and_propagate722));
  and_gate and_gate_h_u_cska32_and_propagate723(.a(h_u_cska32_and_propagate721[0]), .b(h_u_cska32_and_propagate722[0]), .out(h_u_cska32_and_propagate723));
  mux2to1 mux2to1_h_u_cska32_mux2to17_out(.d0(h_u_cska32_fa30_or0[0]), .d1(h_u_cska32_mux2to16_xor0[0]), .sel(h_u_cska32_and_propagate723[0]), .mux2to1_xor0(h_u_cska32_mux2to17_xor0));

  assign h_u_cska32_out[0] = h_u_cska32_ha0_xor0[0];
  assign h_u_cska32_out[1] = h_u_cska32_fa0_xor1[0];
  assign h_u_cska32_out[2] = h_u_cska32_fa1_xor1[0];
  assign h_u_cska32_out[3] = h_u_cska32_fa2_xor1[0];
  assign h_u_cska32_out[4] = h_u_cska32_fa3_xor1[0];
  assign h_u_cska32_out[5] = h_u_cska32_fa4_xor1[0];
  assign h_u_cska32_out[6] = h_u_cska32_fa5_xor1[0];
  assign h_u_cska32_out[7] = h_u_cska32_fa6_xor1[0];
  assign h_u_cska32_out[8] = h_u_cska32_fa7_xor1[0];
  assign h_u_cska32_out[9] = h_u_cska32_fa8_xor1[0];
  assign h_u_cska32_out[10] = h_u_cska32_fa9_xor1[0];
  assign h_u_cska32_out[11] = h_u_cska32_fa10_xor1[0];
  assign h_u_cska32_out[12] = h_u_cska32_fa11_xor1[0];
  assign h_u_cska32_out[13] = h_u_cska32_fa12_xor1[0];
  assign h_u_cska32_out[14] = h_u_cska32_fa13_xor1[0];
  assign h_u_cska32_out[15] = h_u_cska32_fa14_xor1[0];
  assign h_u_cska32_out[16] = h_u_cska32_fa15_xor1[0];
  assign h_u_cska32_out[17] = h_u_cska32_fa16_xor1[0];
  assign h_u_cska32_out[18] = h_u_cska32_fa17_xor1[0];
  assign h_u_cska32_out[19] = h_u_cska32_fa18_xor1[0];
  assign h_u_cska32_out[20] = h_u_cska32_fa19_xor1[0];
  assign h_u_cska32_out[21] = h_u_cska32_fa20_xor1[0];
  assign h_u_cska32_out[22] = h_u_cska32_fa21_xor1[0];
  assign h_u_cska32_out[23] = h_u_cska32_fa22_xor1[0];
  assign h_u_cska32_out[24] = h_u_cska32_fa23_xor1[0];
  assign h_u_cska32_out[25] = h_u_cska32_fa24_xor1[0];
  assign h_u_cska32_out[26] = h_u_cska32_fa25_xor1[0];
  assign h_u_cska32_out[27] = h_u_cska32_fa26_xor1[0];
  assign h_u_cska32_out[28] = h_u_cska32_fa27_xor1[0];
  assign h_u_cska32_out[29] = h_u_cska32_fa28_xor1[0];
  assign h_u_cska32_out[30] = h_u_cska32_fa29_xor1[0];
  assign h_u_cska32_out[31] = h_u_cska32_fa30_xor1[0];
  assign h_u_cska32_out[32] = h_u_cska32_mux2to17_xor0[0];
endmodule