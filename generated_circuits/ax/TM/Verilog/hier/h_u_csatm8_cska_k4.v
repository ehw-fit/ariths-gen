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

module mux2to1(input [0:0] d0, input [0:0] d1, input [0:0] sel, output [0:0] mux2to1_xor0);
  wire [0:0] mux2to1_and0;
  wire [0:0] mux2to1_not0;
  wire [0:0] mux2to1_and1;
  and_gate and_gate_mux2to1_and0(.a(d1[0]), .b(sel[0]), .out(mux2to1_and0));
  not_gate not_gate_mux2to1_not0(.a(sel[0]), .out(mux2to1_not0));
  and_gate and_gate_mux2to1_and1(.a(d0[0]), .b(mux2to1_not0[0]), .out(mux2to1_and1));
  xor_gate xor_gate_mux2to1_xor0(.a(mux2to1_and0[0]), .b(mux2to1_and1[0]), .out(mux2to1_xor0));
endmodule

module u_cska4(input [3:0] a, input [3:0] b, output [4:0] u_cska4_out);
  wire [0:0] u_cska4_xor0;
  wire [0:0] u_cska4_ha0_xor0;
  wire [0:0] u_cska4_ha0_and0;
  wire [0:0] u_cska4_xor1;
  wire [0:0] u_cska4_fa0_xor1;
  wire [0:0] u_cska4_fa0_or0;
  wire [0:0] u_cska4_xor2;
  wire [0:0] u_cska4_fa1_xor1;
  wire [0:0] u_cska4_fa1_or0;
  wire [0:0] u_cska4_xor3;
  wire [0:0] u_cska4_fa2_xor1;
  wire [0:0] u_cska4_fa2_or0;
  wire [0:0] u_cska4_and_propagate00;
  wire [0:0] u_cska4_and_propagate01;
  wire [0:0] u_cska4_and_propagate02;
  wire [0:0] u_cska4_mux2to10_and1;

  xor_gate xor_gate_u_cska4_xor0(.a(a[0]), .b(b[0]), .out(u_cska4_xor0));
  ha ha_u_cska4_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(u_cska4_ha0_xor0), .ha_and0(u_cska4_ha0_and0));
  xor_gate xor_gate_u_cska4_xor1(.a(a[1]), .b(b[1]), .out(u_cska4_xor1));
  fa fa_u_cska4_fa0_out(.a(a[1]), .b(b[1]), .cin(u_cska4_ha0_and0[0]), .fa_xor1(u_cska4_fa0_xor1), .fa_or0(u_cska4_fa0_or0));
  xor_gate xor_gate_u_cska4_xor2(.a(a[2]), .b(b[2]), .out(u_cska4_xor2));
  fa fa_u_cska4_fa1_out(.a(a[2]), .b(b[2]), .cin(u_cska4_fa0_or0[0]), .fa_xor1(u_cska4_fa1_xor1), .fa_or0(u_cska4_fa1_or0));
  xor_gate xor_gate_u_cska4_xor3(.a(a[3]), .b(b[3]), .out(u_cska4_xor3));
  fa fa_u_cska4_fa2_out(.a(a[3]), .b(b[3]), .cin(u_cska4_fa1_or0[0]), .fa_xor1(u_cska4_fa2_xor1), .fa_or0(u_cska4_fa2_or0));
  and_gate and_gate_u_cska4_and_propagate00(.a(u_cska4_xor0[0]), .b(u_cska4_xor2[0]), .out(u_cska4_and_propagate00));
  and_gate and_gate_u_cska4_and_propagate01(.a(u_cska4_xor1[0]), .b(u_cska4_xor3[0]), .out(u_cska4_and_propagate01));
  and_gate and_gate_u_cska4_and_propagate02(.a(u_cska4_and_propagate00[0]), .b(u_cska4_and_propagate01[0]), .out(u_cska4_and_propagate02));
  mux2to1 mux2to1_u_cska4_mux2to10_out(.d0(u_cska4_fa2_or0[0]), .d1(1'b0), .sel(u_cska4_and_propagate02[0]), .mux2to1_xor0(u_cska4_mux2to10_and1));

  assign u_cska4_out[0] = u_cska4_ha0_xor0[0];
  assign u_cska4_out[1] = u_cska4_fa0_xor1[0];
  assign u_cska4_out[2] = u_cska4_fa1_xor1[0];
  assign u_cska4_out[3] = u_cska4_fa2_xor1[0];
  assign u_cska4_out[4] = u_cska4_mux2to10_and1[0];
endmodule

module h_u_csatm8_cska_k4(input [7:0] a, input [7:0] b, output [15:0] h_u_csatm8_cska_k4_out);
  wire [0:0] h_u_csatm8_cska_k4_and4_4;
  wire [0:0] h_u_csatm8_cska_k4_and5_4;
  wire [0:0] h_u_csatm8_cska_k4_and6_4;
  wire [0:0] h_u_csatm8_cska_k4_and7_4;
  wire [0:0] h_u_csatm8_cska_k4_and4_5;
  wire [0:0] h_u_csatm8_cska_k4_ha4_5_xor0;
  wire [0:0] h_u_csatm8_cska_k4_ha4_5_and0;
  wire [0:0] h_u_csatm8_cska_k4_and5_5;
  wire [0:0] h_u_csatm8_cska_k4_ha5_5_xor0;
  wire [0:0] h_u_csatm8_cska_k4_ha5_5_and0;
  wire [0:0] h_u_csatm8_cska_k4_and6_5;
  wire [0:0] h_u_csatm8_cska_k4_ha6_5_xor0;
  wire [0:0] h_u_csatm8_cska_k4_ha6_5_and0;
  wire [0:0] h_u_csatm8_cska_k4_and7_5;
  wire [0:0] h_u_csatm8_cska_k4_and4_6;
  wire [0:0] h_u_csatm8_cska_k4_fa4_6_xor1;
  wire [0:0] h_u_csatm8_cska_k4_fa4_6_or0;
  wire [0:0] h_u_csatm8_cska_k4_and5_6;
  wire [0:0] h_u_csatm8_cska_k4_fa5_6_xor1;
  wire [0:0] h_u_csatm8_cska_k4_fa5_6_or0;
  wire [0:0] h_u_csatm8_cska_k4_and6_6;
  wire [0:0] h_u_csatm8_cska_k4_fa6_6_xor1;
  wire [0:0] h_u_csatm8_cska_k4_fa6_6_or0;
  wire [0:0] h_u_csatm8_cska_k4_and7_6;
  wire [0:0] h_u_csatm8_cska_k4_and4_7;
  wire [0:0] h_u_csatm8_cska_k4_fa4_7_xor1;
  wire [0:0] h_u_csatm8_cska_k4_fa4_7_or0;
  wire [0:0] h_u_csatm8_cska_k4_and5_7;
  wire [0:0] h_u_csatm8_cska_k4_fa5_7_xor1;
  wire [0:0] h_u_csatm8_cska_k4_fa5_7_or0;
  wire [0:0] h_u_csatm8_cska_k4_and6_7;
  wire [0:0] h_u_csatm8_cska_k4_fa6_7_xor1;
  wire [0:0] h_u_csatm8_cska_k4_fa6_7_or0;
  wire [0:0] h_u_csatm8_cska_k4_and7_7;
  wire [3:0] h_u_csatm8_cska_k4_u_cska4_a;
  wire [3:0] h_u_csatm8_cska_k4_u_cska4_b;
  wire [4:0] h_u_csatm8_cska_k4_u_cska4_out;

  and_gate and_gate_h_u_csatm8_cska_k4_and4_4(.a(a[4]), .b(b[4]), .out(h_u_csatm8_cska_k4_and4_4));
  and_gate and_gate_h_u_csatm8_cska_k4_and5_4(.a(a[5]), .b(b[4]), .out(h_u_csatm8_cska_k4_and5_4));
  and_gate and_gate_h_u_csatm8_cska_k4_and6_4(.a(a[6]), .b(b[4]), .out(h_u_csatm8_cska_k4_and6_4));
  and_gate and_gate_h_u_csatm8_cska_k4_and7_4(.a(a[7]), .b(b[4]), .out(h_u_csatm8_cska_k4_and7_4));
  and_gate and_gate_h_u_csatm8_cska_k4_and4_5(.a(a[4]), .b(b[5]), .out(h_u_csatm8_cska_k4_and4_5));
  ha ha_h_u_csatm8_cska_k4_ha4_5_out(.a(h_u_csatm8_cska_k4_and4_5[0]), .b(h_u_csatm8_cska_k4_and5_4[0]), .ha_xor0(h_u_csatm8_cska_k4_ha4_5_xor0), .ha_and0(h_u_csatm8_cska_k4_ha4_5_and0));
  and_gate and_gate_h_u_csatm8_cska_k4_and5_5(.a(a[5]), .b(b[5]), .out(h_u_csatm8_cska_k4_and5_5));
  ha ha_h_u_csatm8_cska_k4_ha5_5_out(.a(h_u_csatm8_cska_k4_and5_5[0]), .b(h_u_csatm8_cska_k4_and6_4[0]), .ha_xor0(h_u_csatm8_cska_k4_ha5_5_xor0), .ha_and0(h_u_csatm8_cska_k4_ha5_5_and0));
  and_gate and_gate_h_u_csatm8_cska_k4_and6_5(.a(a[6]), .b(b[5]), .out(h_u_csatm8_cska_k4_and6_5));
  ha ha_h_u_csatm8_cska_k4_ha6_5_out(.a(h_u_csatm8_cska_k4_and6_5[0]), .b(h_u_csatm8_cska_k4_and7_4[0]), .ha_xor0(h_u_csatm8_cska_k4_ha6_5_xor0), .ha_and0(h_u_csatm8_cska_k4_ha6_5_and0));
  and_gate and_gate_h_u_csatm8_cska_k4_and7_5(.a(a[7]), .b(b[5]), .out(h_u_csatm8_cska_k4_and7_5));
  and_gate and_gate_h_u_csatm8_cska_k4_and4_6(.a(a[4]), .b(b[6]), .out(h_u_csatm8_cska_k4_and4_6));
  fa fa_h_u_csatm8_cska_k4_fa4_6_out(.a(h_u_csatm8_cska_k4_and4_6[0]), .b(h_u_csatm8_cska_k4_ha5_5_xor0[0]), .cin(h_u_csatm8_cska_k4_ha4_5_and0[0]), .fa_xor1(h_u_csatm8_cska_k4_fa4_6_xor1), .fa_or0(h_u_csatm8_cska_k4_fa4_6_or0));
  and_gate and_gate_h_u_csatm8_cska_k4_and5_6(.a(a[5]), .b(b[6]), .out(h_u_csatm8_cska_k4_and5_6));
  fa fa_h_u_csatm8_cska_k4_fa5_6_out(.a(h_u_csatm8_cska_k4_and5_6[0]), .b(h_u_csatm8_cska_k4_ha6_5_xor0[0]), .cin(h_u_csatm8_cska_k4_ha5_5_and0[0]), .fa_xor1(h_u_csatm8_cska_k4_fa5_6_xor1), .fa_or0(h_u_csatm8_cska_k4_fa5_6_or0));
  and_gate and_gate_h_u_csatm8_cska_k4_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csatm8_cska_k4_and6_6));
  fa fa_h_u_csatm8_cska_k4_fa6_6_out(.a(h_u_csatm8_cska_k4_and6_6[0]), .b(h_u_csatm8_cska_k4_and7_5[0]), .cin(h_u_csatm8_cska_k4_ha6_5_and0[0]), .fa_xor1(h_u_csatm8_cska_k4_fa6_6_xor1), .fa_or0(h_u_csatm8_cska_k4_fa6_6_or0));
  and_gate and_gate_h_u_csatm8_cska_k4_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csatm8_cska_k4_and7_6));
  and_gate and_gate_h_u_csatm8_cska_k4_and4_7(.a(a[4]), .b(b[7]), .out(h_u_csatm8_cska_k4_and4_7));
  fa fa_h_u_csatm8_cska_k4_fa4_7_out(.a(h_u_csatm8_cska_k4_and4_7[0]), .b(h_u_csatm8_cska_k4_fa5_6_xor1[0]), .cin(h_u_csatm8_cska_k4_fa4_6_or0[0]), .fa_xor1(h_u_csatm8_cska_k4_fa4_7_xor1), .fa_or0(h_u_csatm8_cska_k4_fa4_7_or0));
  and_gate and_gate_h_u_csatm8_cska_k4_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csatm8_cska_k4_and5_7));
  fa fa_h_u_csatm8_cska_k4_fa5_7_out(.a(h_u_csatm8_cska_k4_and5_7[0]), .b(h_u_csatm8_cska_k4_fa6_6_xor1[0]), .cin(h_u_csatm8_cska_k4_fa5_6_or0[0]), .fa_xor1(h_u_csatm8_cska_k4_fa5_7_xor1), .fa_or0(h_u_csatm8_cska_k4_fa5_7_or0));
  and_gate and_gate_h_u_csatm8_cska_k4_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csatm8_cska_k4_and6_7));
  fa fa_h_u_csatm8_cska_k4_fa6_7_out(.a(h_u_csatm8_cska_k4_and6_7[0]), .b(h_u_csatm8_cska_k4_and7_6[0]), .cin(h_u_csatm8_cska_k4_fa6_6_or0[0]), .fa_xor1(h_u_csatm8_cska_k4_fa6_7_xor1), .fa_or0(h_u_csatm8_cska_k4_fa6_7_or0));
  and_gate and_gate_h_u_csatm8_cska_k4_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csatm8_cska_k4_and7_7));
  assign h_u_csatm8_cska_k4_u_cska4_a[0] = h_u_csatm8_cska_k4_fa5_7_xor1[0];
  assign h_u_csatm8_cska_k4_u_cska4_a[1] = h_u_csatm8_cska_k4_fa6_7_xor1[0];
  assign h_u_csatm8_cska_k4_u_cska4_a[2] = h_u_csatm8_cska_k4_and7_7[0];
  assign h_u_csatm8_cska_k4_u_cska4_a[3] = 1'b0;
  assign h_u_csatm8_cska_k4_u_cska4_b[0] = h_u_csatm8_cska_k4_fa4_7_or0[0];
  assign h_u_csatm8_cska_k4_u_cska4_b[1] = h_u_csatm8_cska_k4_fa5_7_or0[0];
  assign h_u_csatm8_cska_k4_u_cska4_b[2] = h_u_csatm8_cska_k4_fa6_7_or0[0];
  assign h_u_csatm8_cska_k4_u_cska4_b[3] = 1'b0;
  u_cska4 u_cska4_h_u_csatm8_cska_k4_u_cska4_out(.a(h_u_csatm8_cska_k4_u_cska4_a), .b(h_u_csatm8_cska_k4_u_cska4_b), .u_cska4_out(h_u_csatm8_cska_k4_u_cska4_out));

  assign h_u_csatm8_cska_k4_out[0] = 1'b0;
  assign h_u_csatm8_cska_k4_out[1] = 1'b0;
  assign h_u_csatm8_cska_k4_out[2] = 1'b0;
  assign h_u_csatm8_cska_k4_out[3] = 1'b0;
  assign h_u_csatm8_cska_k4_out[4] = 1'b0;
  assign h_u_csatm8_cska_k4_out[5] = 1'b0;
  assign h_u_csatm8_cska_k4_out[6] = 1'b0;
  assign h_u_csatm8_cska_k4_out[7] = 1'b0;
  assign h_u_csatm8_cska_k4_out[8] = h_u_csatm8_cska_k4_and4_4[0];
  assign h_u_csatm8_cska_k4_out[9] = h_u_csatm8_cska_k4_ha4_5_xor0[0];
  assign h_u_csatm8_cska_k4_out[10] = h_u_csatm8_cska_k4_fa4_6_xor1[0];
  assign h_u_csatm8_cska_k4_out[11] = h_u_csatm8_cska_k4_fa4_7_xor1[0];
  assign h_u_csatm8_cska_k4_out[12] = h_u_csatm8_cska_k4_u_cska4_out[0];
  assign h_u_csatm8_cska_k4_out[13] = h_u_csatm8_cska_k4_u_cska4_out[1];
  assign h_u_csatm8_cska_k4_out[14] = h_u_csatm8_cska_k4_u_cska4_out[2];
  assign h_u_csatm8_cska_k4_out[15] = h_u_csatm8_cska_k4_u_cska4_out[3];
endmodule