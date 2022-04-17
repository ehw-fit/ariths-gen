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

module u_cska8(input [7:0] a, input [7:0] b, output [8:0] u_cska8_out);
  wire [0:0] u_cska8_xor0;
  wire [0:0] u_cska8_ha0_xor0;
  wire [0:0] u_cska8_ha0_and0;
  wire [0:0] u_cska8_xor1;
  wire [0:0] u_cska8_fa0_xor1;
  wire [0:0] u_cska8_fa0_or0;
  wire [0:0] u_cska8_xor2;
  wire [0:0] u_cska8_fa1_xor1;
  wire [0:0] u_cska8_fa1_or0;
  wire [0:0] u_cska8_xor3;
  wire [0:0] u_cska8_fa2_xor1;
  wire [0:0] u_cska8_fa2_or0;
  wire [0:0] u_cska8_and_propagate00;
  wire [0:0] u_cska8_and_propagate01;
  wire [0:0] u_cska8_and_propagate02;
  wire [0:0] u_cska8_mux2to10_and1;
  wire [0:0] u_cska8_xor4;
  wire [0:0] u_cska8_fa3_xor1;
  wire [0:0] u_cska8_fa3_or0;
  wire [0:0] u_cska8_xor5;
  wire [0:0] u_cska8_fa4_xor1;
  wire [0:0] u_cska8_fa4_or0;
  wire [0:0] u_cska8_xor6;
  wire [0:0] u_cska8_fa5_xor1;
  wire [0:0] u_cska8_fa5_or0;
  wire [0:0] u_cska8_xor7;
  wire [0:0] u_cska8_fa6_xor1;
  wire [0:0] u_cska8_fa6_or0;
  wire [0:0] u_cska8_and_propagate13;
  wire [0:0] u_cska8_and_propagate14;
  wire [0:0] u_cska8_and_propagate15;
  wire [0:0] u_cska8_mux2to11_xor0;

  xor_gate xor_gate_u_cska8_xor0(.a(a[0]), .b(b[0]), .out(u_cska8_xor0));
  ha ha_u_cska8_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(u_cska8_ha0_xor0), .ha_and0(u_cska8_ha0_and0));
  xor_gate xor_gate_u_cska8_xor1(.a(a[1]), .b(b[1]), .out(u_cska8_xor1));
  fa fa_u_cska8_fa0_out(.a(a[1]), .b(b[1]), .cin(u_cska8_ha0_and0[0]), .fa_xor1(u_cska8_fa0_xor1), .fa_or0(u_cska8_fa0_or0));
  xor_gate xor_gate_u_cska8_xor2(.a(a[2]), .b(b[2]), .out(u_cska8_xor2));
  fa fa_u_cska8_fa1_out(.a(a[2]), .b(b[2]), .cin(u_cska8_fa0_or0[0]), .fa_xor1(u_cska8_fa1_xor1), .fa_or0(u_cska8_fa1_or0));
  xor_gate xor_gate_u_cska8_xor3(.a(a[3]), .b(b[3]), .out(u_cska8_xor3));
  fa fa_u_cska8_fa2_out(.a(a[3]), .b(b[3]), .cin(u_cska8_fa1_or0[0]), .fa_xor1(u_cska8_fa2_xor1), .fa_or0(u_cska8_fa2_or0));
  and_gate and_gate_u_cska8_and_propagate00(.a(u_cska8_xor0[0]), .b(u_cska8_xor2[0]), .out(u_cska8_and_propagate00));
  and_gate and_gate_u_cska8_and_propagate01(.a(u_cska8_xor1[0]), .b(u_cska8_xor3[0]), .out(u_cska8_and_propagate01));
  and_gate and_gate_u_cska8_and_propagate02(.a(u_cska8_and_propagate00[0]), .b(u_cska8_and_propagate01[0]), .out(u_cska8_and_propagate02));
  mux2to1 mux2to1_u_cska8_mux2to10_out(.d0(u_cska8_fa2_or0[0]), .d1(1'b0), .sel(u_cska8_and_propagate02[0]), .mux2to1_xor0(u_cska8_mux2to10_and1));
  xor_gate xor_gate_u_cska8_xor4(.a(a[4]), .b(b[4]), .out(u_cska8_xor4));
  fa fa_u_cska8_fa3_out(.a(a[4]), .b(b[4]), .cin(u_cska8_mux2to10_and1[0]), .fa_xor1(u_cska8_fa3_xor1), .fa_or0(u_cska8_fa3_or0));
  xor_gate xor_gate_u_cska8_xor5(.a(a[5]), .b(b[5]), .out(u_cska8_xor5));
  fa fa_u_cska8_fa4_out(.a(a[5]), .b(b[5]), .cin(u_cska8_fa3_or0[0]), .fa_xor1(u_cska8_fa4_xor1), .fa_or0(u_cska8_fa4_or0));
  xor_gate xor_gate_u_cska8_xor6(.a(a[6]), .b(b[6]), .out(u_cska8_xor6));
  fa fa_u_cska8_fa5_out(.a(a[6]), .b(b[6]), .cin(u_cska8_fa4_or0[0]), .fa_xor1(u_cska8_fa5_xor1), .fa_or0(u_cska8_fa5_or0));
  xor_gate xor_gate_u_cska8_xor7(.a(a[7]), .b(b[7]), .out(u_cska8_xor7));
  fa fa_u_cska8_fa6_out(.a(a[7]), .b(b[7]), .cin(u_cska8_fa5_or0[0]), .fa_xor1(u_cska8_fa6_xor1), .fa_or0(u_cska8_fa6_or0));
  and_gate and_gate_u_cska8_and_propagate13(.a(u_cska8_xor4[0]), .b(u_cska8_xor6[0]), .out(u_cska8_and_propagate13));
  and_gate and_gate_u_cska8_and_propagate14(.a(u_cska8_xor5[0]), .b(u_cska8_xor7[0]), .out(u_cska8_and_propagate14));
  and_gate and_gate_u_cska8_and_propagate15(.a(u_cska8_and_propagate13[0]), .b(u_cska8_and_propagate14[0]), .out(u_cska8_and_propagate15));
  mux2to1 mux2to1_u_cska8_mux2to11_out(.d0(u_cska8_fa6_or0[0]), .d1(u_cska8_mux2to10_and1[0]), .sel(u_cska8_and_propagate15[0]), .mux2to1_xor0(u_cska8_mux2to11_xor0));

  assign u_cska8_out[0] = u_cska8_ha0_xor0[0];
  assign u_cska8_out[1] = u_cska8_fa0_xor1[0];
  assign u_cska8_out[2] = u_cska8_fa1_xor1[0];
  assign u_cska8_out[3] = u_cska8_fa2_xor1[0];
  assign u_cska8_out[4] = u_cska8_fa3_xor1[0];
  assign u_cska8_out[5] = u_cska8_fa4_xor1[0];
  assign u_cska8_out[6] = u_cska8_fa5_xor1[0];
  assign u_cska8_out[7] = u_cska8_fa6_xor1[0];
  assign u_cska8_out[8] = u_cska8_mux2to11_xor0[0];
endmodule

module h_u_csabam8_cska_h6_v6(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_cska_h6_v6_out);
  wire [0:0] h_u_csabam8_cska_h6_v6_and0_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and1_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and2_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and3_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and4_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and5_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and6_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and7_6;
  wire [0:0] h_u_csabam8_cska_h6_v6_and0_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha0_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha0_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and1_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha1_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha1_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and2_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha2_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha2_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and3_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha3_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha3_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and4_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha4_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha4_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and5_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha5_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha5_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and6_7;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha6_7_xor0;
  wire [0:0] h_u_csabam8_cska_h6_v6_ha6_7_and0;
  wire [0:0] h_u_csabam8_cska_h6_v6_and7_7;
  wire [7:0] h_u_csabam8_cska_h6_v6_u_cska8_a;
  wire [7:0] h_u_csabam8_cska_h6_v6_u_cska8_b;
  wire [8:0] h_u_csabam8_cska_h6_v6_u_cska8_out;

  and_gate and_gate_h_u_csabam8_cska_h6_v6_and0_6(.a(a[0]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and0_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and1_6(.a(a[1]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and1_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and2_6(.a(a[2]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and2_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and3_6(.a(a[3]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and3_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and4_6(.a(a[4]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and4_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and5_6(.a(a[5]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and5_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and6_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csabam8_cska_h6_v6_and7_6));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and0_7(.a(a[0]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and0_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha0_7_out(.a(h_u_csabam8_cska_h6_v6_and0_7[0]), .b(h_u_csabam8_cska_h6_v6_and1_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha0_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha0_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and1_7(.a(a[1]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and1_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha1_7_out(.a(h_u_csabam8_cska_h6_v6_and1_7[0]), .b(h_u_csabam8_cska_h6_v6_and2_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha1_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha1_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and2_7(.a(a[2]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and2_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha2_7_out(.a(h_u_csabam8_cska_h6_v6_and2_7[0]), .b(h_u_csabam8_cska_h6_v6_and3_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha2_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha2_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and3_7(.a(a[3]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and3_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha3_7_out(.a(h_u_csabam8_cska_h6_v6_and3_7[0]), .b(h_u_csabam8_cska_h6_v6_and4_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha3_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha3_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and4_7(.a(a[4]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and4_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha4_7_out(.a(h_u_csabam8_cska_h6_v6_and4_7[0]), .b(h_u_csabam8_cska_h6_v6_and5_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha4_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha4_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and5_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha5_7_out(.a(h_u_csabam8_cska_h6_v6_and5_7[0]), .b(h_u_csabam8_cska_h6_v6_and6_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha5_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha5_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and6_7));
  ha ha_h_u_csabam8_cska_h6_v6_ha6_7_out(.a(h_u_csabam8_cska_h6_v6_and6_7[0]), .b(h_u_csabam8_cska_h6_v6_and7_6[0]), .ha_xor0(h_u_csabam8_cska_h6_v6_ha6_7_xor0), .ha_and0(h_u_csabam8_cska_h6_v6_ha6_7_and0));
  and_gate and_gate_h_u_csabam8_cska_h6_v6_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_cska_h6_v6_and7_7));
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[0] = h_u_csabam8_cska_h6_v6_ha1_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[1] = h_u_csabam8_cska_h6_v6_ha2_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[2] = h_u_csabam8_cska_h6_v6_ha3_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[3] = h_u_csabam8_cska_h6_v6_ha4_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[4] = h_u_csabam8_cska_h6_v6_ha5_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[5] = h_u_csabam8_cska_h6_v6_ha6_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[6] = h_u_csabam8_cska_h6_v6_and7_7[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_a[7] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[0] = h_u_csabam8_cska_h6_v6_ha0_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[1] = h_u_csabam8_cska_h6_v6_ha1_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[2] = h_u_csabam8_cska_h6_v6_ha2_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[3] = h_u_csabam8_cska_h6_v6_ha3_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[4] = h_u_csabam8_cska_h6_v6_ha4_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[5] = h_u_csabam8_cska_h6_v6_ha5_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[6] = h_u_csabam8_cska_h6_v6_ha6_7_and0[0];
  assign h_u_csabam8_cska_h6_v6_u_cska8_b[7] = 1'b0;
  u_cska8 u_cska8_h_u_csabam8_cska_h6_v6_u_cska8_out(.a(h_u_csabam8_cska_h6_v6_u_cska8_a), .b(h_u_csabam8_cska_h6_v6_u_cska8_b), .u_cska8_out(h_u_csabam8_cska_h6_v6_u_cska8_out));

  assign h_u_csabam8_cska_h6_v6_out[0] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_out[1] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_out[2] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_out[3] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_out[4] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_out[5] = 1'b0;
  assign h_u_csabam8_cska_h6_v6_out[6] = h_u_csabam8_cska_h6_v6_and0_6[0];
  assign h_u_csabam8_cska_h6_v6_out[7] = h_u_csabam8_cska_h6_v6_ha0_7_xor0[0];
  assign h_u_csabam8_cska_h6_v6_out[8] = h_u_csabam8_cska_h6_v6_u_cska8_out[0];
  assign h_u_csabam8_cska_h6_v6_out[9] = h_u_csabam8_cska_h6_v6_u_cska8_out[1];
  assign h_u_csabam8_cska_h6_v6_out[10] = h_u_csabam8_cska_h6_v6_u_cska8_out[2];
  assign h_u_csabam8_cska_h6_v6_out[11] = h_u_csabam8_cska_h6_v6_u_cska8_out[3];
  assign h_u_csabam8_cska_h6_v6_out[12] = h_u_csabam8_cska_h6_v6_u_cska8_out[4];
  assign h_u_csabam8_cska_h6_v6_out[13] = h_u_csabam8_cska_h6_v6_u_cska8_out[5];
  assign h_u_csabam8_cska_h6_v6_out[14] = h_u_csabam8_cska_h6_v6_u_cska8_out[6];
  assign h_u_csabam8_cska_h6_v6_out[15] = h_u_csabam8_cska_h6_v6_u_cska8_out[7];
endmodule