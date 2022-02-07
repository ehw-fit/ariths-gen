module and_gate(input a, input b, output out);
  assign out = a & b;
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

module u_cska6(input [5:0] a, input [5:0] b, output [6:0] u_cska6_out);
  wire [0:0] u_cska6_xor0;
  wire [0:0] u_cska6_ha0_xor0;
  wire [0:0] u_cska6_ha0_and0;
  wire [0:0] u_cska6_xor1;
  wire [0:0] u_cska6_fa0_xor1;
  wire [0:0] u_cska6_fa0_or0;
  wire [0:0] u_cska6_xor2;
  wire [0:0] u_cska6_fa1_xor1;
  wire [0:0] u_cska6_fa1_or0;
  wire [0:0] u_cska6_xor3;
  wire [0:0] u_cska6_fa2_xor1;
  wire [0:0] u_cska6_fa2_or0;
  wire [0:0] u_cska6_and_propagate00;
  wire [0:0] u_cska6_and_propagate01;
  wire [0:0] u_cska6_and_propagate02;
  wire [0:0] u_cska6_mux2to10_and1;
  wire [0:0] u_cska6_xor4;
  wire [0:0] u_cska6_fa3_xor1;
  wire [0:0] u_cska6_fa3_or0;
  wire [0:0] u_cska6_xor5;
  wire [0:0] u_cska6_fa4_xor1;
  wire [0:0] u_cska6_fa4_or0;
  wire [0:0] u_cska6_and_propagate13;
  wire [0:0] u_cska6_mux2to11_xor0;

  xor_gate xor_gate_u_cska6_xor0(.a(a[0]), .b(b[0]), .out(u_cska6_xor0));
  ha ha_u_cska6_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(u_cska6_ha0_xor0), .ha_and0(u_cska6_ha0_and0));
  xor_gate xor_gate_u_cska6_xor1(.a(a[1]), .b(b[1]), .out(u_cska6_xor1));
  fa fa_u_cska6_fa0_out(.a(a[1]), .b(b[1]), .cin(u_cska6_ha0_and0[0]), .fa_xor1(u_cska6_fa0_xor1), .fa_or0(u_cska6_fa0_or0));
  xor_gate xor_gate_u_cska6_xor2(.a(a[2]), .b(b[2]), .out(u_cska6_xor2));
  fa fa_u_cska6_fa1_out(.a(a[2]), .b(b[2]), .cin(u_cska6_fa0_or0[0]), .fa_xor1(u_cska6_fa1_xor1), .fa_or0(u_cska6_fa1_or0));
  xor_gate xor_gate_u_cska6_xor3(.a(a[3]), .b(b[3]), .out(u_cska6_xor3));
  fa fa_u_cska6_fa2_out(.a(a[3]), .b(b[3]), .cin(u_cska6_fa1_or0[0]), .fa_xor1(u_cska6_fa2_xor1), .fa_or0(u_cska6_fa2_or0));
  and_gate and_gate_u_cska6_and_propagate00(.a(u_cska6_xor0[0]), .b(u_cska6_xor2[0]), .out(u_cska6_and_propagate00));
  and_gate and_gate_u_cska6_and_propagate01(.a(u_cska6_xor1[0]), .b(u_cska6_xor3[0]), .out(u_cska6_and_propagate01));
  and_gate and_gate_u_cska6_and_propagate02(.a(u_cska6_and_propagate00[0]), .b(u_cska6_and_propagate01[0]), .out(u_cska6_and_propagate02));
  mux2to1 mux2to1_u_cska6_mux2to10_out(.d0(u_cska6_fa2_or0[0]), .d1(1'b0), .sel(u_cska6_and_propagate02[0]), .mux2to1_xor0(u_cska6_mux2to10_and1));
  xor_gate xor_gate_u_cska6_xor4(.a(a[4]), .b(b[4]), .out(u_cska6_xor4));
  fa fa_u_cska6_fa3_out(.a(a[4]), .b(b[4]), .cin(u_cska6_mux2to10_and1[0]), .fa_xor1(u_cska6_fa3_xor1), .fa_or0(u_cska6_fa3_or0));
  xor_gate xor_gate_u_cska6_xor5(.a(a[5]), .b(b[5]), .out(u_cska6_xor5));
  fa fa_u_cska6_fa4_out(.a(a[5]), .b(b[5]), .cin(u_cska6_fa3_or0[0]), .fa_xor1(u_cska6_fa4_xor1), .fa_or0(u_cska6_fa4_or0));
  and_gate and_gate_u_cska6_and_propagate13(.a(u_cska6_xor4[0]), .b(u_cska6_xor5[0]), .out(u_cska6_and_propagate13));
  mux2to1 mux2to1_u_cska6_mux2to11_out(.d0(u_cska6_fa4_or0[0]), .d1(u_cska6_mux2to10_and1[0]), .sel(u_cska6_and_propagate13[0]), .mux2to1_xor0(u_cska6_mux2to11_xor0));

  assign u_cska6_out[0] = u_cska6_ha0_xor0[0];
  assign u_cska6_out[1] = u_cska6_fa0_xor1[0];
  assign u_cska6_out[2] = u_cska6_fa1_xor1[0];
  assign u_cska6_out[3] = u_cska6_fa2_xor1[0];
  assign u_cska6_out[4] = u_cska6_fa3_xor1[0];
  assign u_cska6_out[5] = u_cska6_fa4_xor1[0];
  assign u_cska6_out[6] = u_cska6_mux2to11_xor0[0];
endmodule

module u_dadda_cska4(input [3:0] a, input [3:0] b, output [7:0] u_dadda_cska4_out);
  wire [0:0] u_dadda_cska4_and_3_0;
  wire [0:0] u_dadda_cska4_and_2_1;
  wire [0:0] u_dadda_cska4_ha0_xor0;
  wire [0:0] u_dadda_cska4_ha0_and0;
  wire [0:0] u_dadda_cska4_and_3_1;
  wire [0:0] u_dadda_cska4_ha1_xor0;
  wire [0:0] u_dadda_cska4_ha1_and0;
  wire [0:0] u_dadda_cska4_and_2_0;
  wire [0:0] u_dadda_cska4_and_1_1;
  wire [0:0] u_dadda_cska4_ha2_xor0;
  wire [0:0] u_dadda_cska4_ha2_and0;
  wire [0:0] u_dadda_cska4_and_1_2;
  wire [0:0] u_dadda_cska4_and_0_3;
  wire [0:0] u_dadda_cska4_fa0_xor1;
  wire [0:0] u_dadda_cska4_fa0_or0;
  wire [0:0] u_dadda_cska4_and_2_2;
  wire [0:0] u_dadda_cska4_and_1_3;
  wire [0:0] u_dadda_cska4_fa1_xor1;
  wire [0:0] u_dadda_cska4_fa1_or0;
  wire [0:0] u_dadda_cska4_and_3_2;
  wire [0:0] u_dadda_cska4_fa2_xor1;
  wire [0:0] u_dadda_cska4_fa2_or0;
  wire [0:0] u_dadda_cska4_and_0_0;
  wire [0:0] u_dadda_cska4_and_1_0;
  wire [0:0] u_dadda_cska4_and_0_2;
  wire [0:0] u_dadda_cska4_and_2_3;
  wire [0:0] u_dadda_cska4_and_0_1;
  wire [0:0] u_dadda_cska4_and_3_3;
  wire [5:0] u_dadda_cska4_u_cska6_a;
  wire [5:0] u_dadda_cska4_u_cska6_b;
  wire [6:0] u_dadda_cska4_u_cska6_out;

  and_gate and_gate_u_dadda_cska4_and_3_0(.a(a[3]), .b(b[0]), .out(u_dadda_cska4_and_3_0));
  and_gate and_gate_u_dadda_cska4_and_2_1(.a(a[2]), .b(b[1]), .out(u_dadda_cska4_and_2_1));
  ha ha_u_dadda_cska4_ha0_out(.a(u_dadda_cska4_and_3_0[0]), .b(u_dadda_cska4_and_2_1[0]), .ha_xor0(u_dadda_cska4_ha0_xor0), .ha_and0(u_dadda_cska4_ha0_and0));
  and_gate and_gate_u_dadda_cska4_and_3_1(.a(a[3]), .b(b[1]), .out(u_dadda_cska4_and_3_1));
  ha ha_u_dadda_cska4_ha1_out(.a(u_dadda_cska4_ha0_and0[0]), .b(u_dadda_cska4_and_3_1[0]), .ha_xor0(u_dadda_cska4_ha1_xor0), .ha_and0(u_dadda_cska4_ha1_and0));
  and_gate and_gate_u_dadda_cska4_and_2_0(.a(a[2]), .b(b[0]), .out(u_dadda_cska4_and_2_0));
  and_gate and_gate_u_dadda_cska4_and_1_1(.a(a[1]), .b(b[1]), .out(u_dadda_cska4_and_1_1));
  ha ha_u_dadda_cska4_ha2_out(.a(u_dadda_cska4_and_2_0[0]), .b(u_dadda_cska4_and_1_1[0]), .ha_xor0(u_dadda_cska4_ha2_xor0), .ha_and0(u_dadda_cska4_ha2_and0));
  and_gate and_gate_u_dadda_cska4_and_1_2(.a(a[1]), .b(b[2]), .out(u_dadda_cska4_and_1_2));
  and_gate and_gate_u_dadda_cska4_and_0_3(.a(a[0]), .b(b[3]), .out(u_dadda_cska4_and_0_3));
  fa fa_u_dadda_cska4_fa0_out(.a(u_dadda_cska4_ha2_and0[0]), .b(u_dadda_cska4_and_1_2[0]), .cin(u_dadda_cska4_and_0_3[0]), .fa_xor1(u_dadda_cska4_fa0_xor1), .fa_or0(u_dadda_cska4_fa0_or0));
  and_gate and_gate_u_dadda_cska4_and_2_2(.a(a[2]), .b(b[2]), .out(u_dadda_cska4_and_2_2));
  and_gate and_gate_u_dadda_cska4_and_1_3(.a(a[1]), .b(b[3]), .out(u_dadda_cska4_and_1_3));
  fa fa_u_dadda_cska4_fa1_out(.a(u_dadda_cska4_fa0_or0[0]), .b(u_dadda_cska4_and_2_2[0]), .cin(u_dadda_cska4_and_1_3[0]), .fa_xor1(u_dadda_cska4_fa1_xor1), .fa_or0(u_dadda_cska4_fa1_or0));
  and_gate and_gate_u_dadda_cska4_and_3_2(.a(a[3]), .b(b[2]), .out(u_dadda_cska4_and_3_2));
  fa fa_u_dadda_cska4_fa2_out(.a(u_dadda_cska4_fa1_or0[0]), .b(u_dadda_cska4_ha1_and0[0]), .cin(u_dadda_cska4_and_3_2[0]), .fa_xor1(u_dadda_cska4_fa2_xor1), .fa_or0(u_dadda_cska4_fa2_or0));
  and_gate and_gate_u_dadda_cska4_and_0_0(.a(a[0]), .b(b[0]), .out(u_dadda_cska4_and_0_0));
  and_gate and_gate_u_dadda_cska4_and_1_0(.a(a[1]), .b(b[0]), .out(u_dadda_cska4_and_1_0));
  and_gate and_gate_u_dadda_cska4_and_0_2(.a(a[0]), .b(b[2]), .out(u_dadda_cska4_and_0_2));
  and_gate and_gate_u_dadda_cska4_and_2_3(.a(a[2]), .b(b[3]), .out(u_dadda_cska4_and_2_3));
  and_gate and_gate_u_dadda_cska4_and_0_1(.a(a[0]), .b(b[1]), .out(u_dadda_cska4_and_0_1));
  and_gate and_gate_u_dadda_cska4_and_3_3(.a(a[3]), .b(b[3]), .out(u_dadda_cska4_and_3_3));
  assign u_dadda_cska4_u_cska6_a[0] = u_dadda_cska4_and_1_0[0];
  assign u_dadda_cska4_u_cska6_a[1] = u_dadda_cska4_and_0_2[0];
  assign u_dadda_cska4_u_cska6_a[2] = u_dadda_cska4_ha0_xor0[0];
  assign u_dadda_cska4_u_cska6_a[3] = u_dadda_cska4_ha1_xor0[0];
  assign u_dadda_cska4_u_cska6_a[4] = u_dadda_cska4_and_2_3[0];
  assign u_dadda_cska4_u_cska6_a[5] = u_dadda_cska4_fa2_or0[0];
  assign u_dadda_cska4_u_cska6_b[0] = u_dadda_cska4_and_0_1[0];
  assign u_dadda_cska4_u_cska6_b[1] = u_dadda_cska4_ha2_xor0[0];
  assign u_dadda_cska4_u_cska6_b[2] = u_dadda_cska4_fa0_xor1[0];
  assign u_dadda_cska4_u_cska6_b[3] = u_dadda_cska4_fa1_xor1[0];
  assign u_dadda_cska4_u_cska6_b[4] = u_dadda_cska4_fa2_xor1[0];
  assign u_dadda_cska4_u_cska6_b[5] = u_dadda_cska4_and_3_3[0];
  u_cska6 u_cska6_u_dadda_cska4_u_cska6_out(.a(u_dadda_cska4_u_cska6_a), .b(u_dadda_cska4_u_cska6_b), .u_cska6_out(u_dadda_cska4_u_cska6_out));

  assign u_dadda_cska4_out[0] = u_dadda_cska4_and_0_0[0];
  assign u_dadda_cska4_out[1] = u_dadda_cska4_u_cska6_out[0];
  assign u_dadda_cska4_out[2] = u_dadda_cska4_u_cska6_out[1];
  assign u_dadda_cska4_out[3] = u_dadda_cska4_u_cska6_out[2];
  assign u_dadda_cska4_out[4] = u_dadda_cska4_u_cska6_out[3];
  assign u_dadda_cska4_out[5] = u_dadda_cska4_u_cska6_out[4];
  assign u_dadda_cska4_out[6] = u_dadda_cska4_u_cska6_out[5];
  assign u_dadda_cska4_out[7] = u_dadda_cska4_u_cska6_out[6];
endmodule