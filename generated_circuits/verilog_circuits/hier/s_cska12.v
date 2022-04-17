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

module s_cska12(input [11:0] a, input [11:0] b, output [12:0] s_cska12_out);
  wire [0:0] s_cska12_xor0;
  wire [0:0] s_cska12_ha0_xor0;
  wire [0:0] s_cska12_ha0_and0;
  wire [0:0] s_cska12_xor1;
  wire [0:0] s_cska12_fa0_xor1;
  wire [0:0] s_cska12_fa0_or0;
  wire [0:0] s_cska12_xor2;
  wire [0:0] s_cska12_fa1_xor1;
  wire [0:0] s_cska12_fa1_or0;
  wire [0:0] s_cska12_xor3;
  wire [0:0] s_cska12_fa2_xor1;
  wire [0:0] s_cska12_fa2_or0;
  wire [0:0] s_cska12_and_propagate00;
  wire [0:0] s_cska12_and_propagate01;
  wire [0:0] s_cska12_and_propagate02;
  wire [0:0] s_cska12_mux2to10_and1;
  wire [0:0] s_cska12_xor4;
  wire [0:0] s_cska12_fa3_xor1;
  wire [0:0] s_cska12_fa3_or0;
  wire [0:0] s_cska12_xor5;
  wire [0:0] s_cska12_fa4_xor1;
  wire [0:0] s_cska12_fa4_or0;
  wire [0:0] s_cska12_xor6;
  wire [0:0] s_cska12_fa5_xor1;
  wire [0:0] s_cska12_fa5_or0;
  wire [0:0] s_cska12_xor7;
  wire [0:0] s_cska12_fa6_xor1;
  wire [0:0] s_cska12_fa6_or0;
  wire [0:0] s_cska12_and_propagate13;
  wire [0:0] s_cska12_and_propagate14;
  wire [0:0] s_cska12_and_propagate15;
  wire [0:0] s_cska12_mux2to11_xor0;
  wire [0:0] s_cska12_xor8;
  wire [0:0] s_cska12_fa7_xor1;
  wire [0:0] s_cska12_fa7_or0;
  wire [0:0] s_cska12_xor9;
  wire [0:0] s_cska12_fa8_xor1;
  wire [0:0] s_cska12_fa8_or0;
  wire [0:0] s_cska12_xor10;
  wire [0:0] s_cska12_fa9_xor1;
  wire [0:0] s_cska12_fa9_or0;
  wire [0:0] s_cska12_xor11;
  wire [0:0] s_cska12_fa10_xor1;
  wire [0:0] s_cska12_fa10_or0;
  wire [0:0] s_cska12_and_propagate26;
  wire [0:0] s_cska12_and_propagate27;
  wire [0:0] s_cska12_and_propagate28;
  wire [0:0] s_cska12_mux2to12_xor0;
  wire [0:0] s_cska12_xor12;
  wire [0:0] s_cska12_xor13;

  xor_gate xor_gate_s_cska12_xor0(.a(a[0]), .b(b[0]), .out(s_cska12_xor0));
  ha ha_s_cska12_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(s_cska12_ha0_xor0), .ha_and0(s_cska12_ha0_and0));
  xor_gate xor_gate_s_cska12_xor1(.a(a[1]), .b(b[1]), .out(s_cska12_xor1));
  fa fa_s_cska12_fa0_out(.a(a[1]), .b(b[1]), .cin(s_cska12_ha0_and0[0]), .fa_xor1(s_cska12_fa0_xor1), .fa_or0(s_cska12_fa0_or0));
  xor_gate xor_gate_s_cska12_xor2(.a(a[2]), .b(b[2]), .out(s_cska12_xor2));
  fa fa_s_cska12_fa1_out(.a(a[2]), .b(b[2]), .cin(s_cska12_fa0_or0[0]), .fa_xor1(s_cska12_fa1_xor1), .fa_or0(s_cska12_fa1_or0));
  xor_gate xor_gate_s_cska12_xor3(.a(a[3]), .b(b[3]), .out(s_cska12_xor3));
  fa fa_s_cska12_fa2_out(.a(a[3]), .b(b[3]), .cin(s_cska12_fa1_or0[0]), .fa_xor1(s_cska12_fa2_xor1), .fa_or0(s_cska12_fa2_or0));
  and_gate and_gate_s_cska12_and_propagate00(.a(s_cska12_xor0[0]), .b(s_cska12_xor2[0]), .out(s_cska12_and_propagate00));
  and_gate and_gate_s_cska12_and_propagate01(.a(s_cska12_xor1[0]), .b(s_cska12_xor3[0]), .out(s_cska12_and_propagate01));
  and_gate and_gate_s_cska12_and_propagate02(.a(s_cska12_and_propagate00[0]), .b(s_cska12_and_propagate01[0]), .out(s_cska12_and_propagate02));
  mux2to1 mux2to1_s_cska12_mux2to10_out(.d0(s_cska12_fa2_or0[0]), .d1(1'b0), .sel(s_cska12_and_propagate02[0]), .mux2to1_xor0(s_cska12_mux2to10_and1));
  xor_gate xor_gate_s_cska12_xor4(.a(a[4]), .b(b[4]), .out(s_cska12_xor4));
  fa fa_s_cska12_fa3_out(.a(a[4]), .b(b[4]), .cin(s_cska12_mux2to10_and1[0]), .fa_xor1(s_cska12_fa3_xor1), .fa_or0(s_cska12_fa3_or0));
  xor_gate xor_gate_s_cska12_xor5(.a(a[5]), .b(b[5]), .out(s_cska12_xor5));
  fa fa_s_cska12_fa4_out(.a(a[5]), .b(b[5]), .cin(s_cska12_fa3_or0[0]), .fa_xor1(s_cska12_fa4_xor1), .fa_or0(s_cska12_fa4_or0));
  xor_gate xor_gate_s_cska12_xor6(.a(a[6]), .b(b[6]), .out(s_cska12_xor6));
  fa fa_s_cska12_fa5_out(.a(a[6]), .b(b[6]), .cin(s_cska12_fa4_or0[0]), .fa_xor1(s_cska12_fa5_xor1), .fa_or0(s_cska12_fa5_or0));
  xor_gate xor_gate_s_cska12_xor7(.a(a[7]), .b(b[7]), .out(s_cska12_xor7));
  fa fa_s_cska12_fa6_out(.a(a[7]), .b(b[7]), .cin(s_cska12_fa5_or0[0]), .fa_xor1(s_cska12_fa6_xor1), .fa_or0(s_cska12_fa6_or0));
  and_gate and_gate_s_cska12_and_propagate13(.a(s_cska12_xor4[0]), .b(s_cska12_xor6[0]), .out(s_cska12_and_propagate13));
  and_gate and_gate_s_cska12_and_propagate14(.a(s_cska12_xor5[0]), .b(s_cska12_xor7[0]), .out(s_cska12_and_propagate14));
  and_gate and_gate_s_cska12_and_propagate15(.a(s_cska12_and_propagate13[0]), .b(s_cska12_and_propagate14[0]), .out(s_cska12_and_propagate15));
  mux2to1 mux2to1_s_cska12_mux2to11_out(.d0(s_cska12_fa6_or0[0]), .d1(s_cska12_mux2to10_and1[0]), .sel(s_cska12_and_propagate15[0]), .mux2to1_xor0(s_cska12_mux2to11_xor0));
  xor_gate xor_gate_s_cska12_xor8(.a(a[8]), .b(b[8]), .out(s_cska12_xor8));
  fa fa_s_cska12_fa7_out(.a(a[8]), .b(b[8]), .cin(s_cska12_mux2to11_xor0[0]), .fa_xor1(s_cska12_fa7_xor1), .fa_or0(s_cska12_fa7_or0));
  xor_gate xor_gate_s_cska12_xor9(.a(a[9]), .b(b[9]), .out(s_cska12_xor9));
  fa fa_s_cska12_fa8_out(.a(a[9]), .b(b[9]), .cin(s_cska12_fa7_or0[0]), .fa_xor1(s_cska12_fa8_xor1), .fa_or0(s_cska12_fa8_or0));
  xor_gate xor_gate_s_cska12_xor10(.a(a[10]), .b(b[10]), .out(s_cska12_xor10));
  fa fa_s_cska12_fa9_out(.a(a[10]), .b(b[10]), .cin(s_cska12_fa8_or0[0]), .fa_xor1(s_cska12_fa9_xor1), .fa_or0(s_cska12_fa9_or0));
  xor_gate xor_gate_s_cska12_xor11(.a(a[11]), .b(b[11]), .out(s_cska12_xor11));
  fa fa_s_cska12_fa10_out(.a(a[11]), .b(b[11]), .cin(s_cska12_fa9_or0[0]), .fa_xor1(s_cska12_fa10_xor1), .fa_or0(s_cska12_fa10_or0));
  and_gate and_gate_s_cska12_and_propagate26(.a(s_cska12_xor8[0]), .b(s_cska12_xor10[0]), .out(s_cska12_and_propagate26));
  and_gate and_gate_s_cska12_and_propagate27(.a(s_cska12_xor9[0]), .b(s_cska12_xor11[0]), .out(s_cska12_and_propagate27));
  and_gate and_gate_s_cska12_and_propagate28(.a(s_cska12_and_propagate26[0]), .b(s_cska12_and_propagate27[0]), .out(s_cska12_and_propagate28));
  mux2to1 mux2to1_s_cska12_mux2to12_out(.d0(s_cska12_fa10_or0[0]), .d1(s_cska12_mux2to11_xor0[0]), .sel(s_cska12_and_propagate28[0]), .mux2to1_xor0(s_cska12_mux2to12_xor0));
  xor_gate xor_gate_s_cska12_xor12(.a(a[11]), .b(b[11]), .out(s_cska12_xor12));
  xor_gate xor_gate_s_cska12_xor13(.a(s_cska12_xor12[0]), .b(s_cska12_mux2to12_xor0[0]), .out(s_cska12_xor13));

  assign s_cska12_out[0] = s_cska12_ha0_xor0[0];
  assign s_cska12_out[1] = s_cska12_fa0_xor1[0];
  assign s_cska12_out[2] = s_cska12_fa1_xor1[0];
  assign s_cska12_out[3] = s_cska12_fa2_xor1[0];
  assign s_cska12_out[4] = s_cska12_fa3_xor1[0];
  assign s_cska12_out[5] = s_cska12_fa4_xor1[0];
  assign s_cska12_out[6] = s_cska12_fa5_xor1[0];
  assign s_cska12_out[7] = s_cska12_fa6_xor1[0];
  assign s_cska12_out[8] = s_cska12_fa7_xor1[0];
  assign s_cska12_out[9] = s_cska12_fa8_xor1[0];
  assign s_cska12_out[10] = s_cska12_fa9_xor1[0];
  assign s_cska12_out[11] = s_cska12_fa10_xor1[0];
  assign s_cska12_out[12] = s_cska12_xor13[0];
endmodule