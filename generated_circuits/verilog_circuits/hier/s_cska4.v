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

module s_cska4(input [3:0] a, input [3:0] b, output [4:0] s_cska4_out);
  wire [0:0] s_cska4_xor0;
  wire [0:0] s_cska4_ha0_xor0;
  wire [0:0] s_cska4_ha0_and0;
  wire [0:0] s_cska4_xor1;
  wire [0:0] s_cska4_fa0_xor1;
  wire [0:0] s_cska4_fa0_or0;
  wire [0:0] s_cska4_xor2;
  wire [0:0] s_cska4_fa1_xor1;
  wire [0:0] s_cska4_fa1_or0;
  wire [0:0] s_cska4_xor3;
  wire [0:0] s_cska4_fa2_xor1;
  wire [0:0] s_cska4_fa2_or0;
  wire [0:0] s_cska4_and_propagate00;
  wire [0:0] s_cska4_and_propagate01;
  wire [0:0] s_cska4_and_propagate02;
  wire [0:0] s_cska4_mux2to10_and1;
  wire [0:0] s_cska4_xor4;
  wire [0:0] s_cska4_xor5;

  xor_gate xor_gate_s_cska4_xor0(.a(a[0]), .b(b[0]), .out(s_cska4_xor0));
  ha ha_s_cska4_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(s_cska4_ha0_xor0), .ha_and0(s_cska4_ha0_and0));
  xor_gate xor_gate_s_cska4_xor1(.a(a[1]), .b(b[1]), .out(s_cska4_xor1));
  fa fa_s_cska4_fa0_out(.a(a[1]), .b(b[1]), .cin(s_cska4_ha0_and0[0]), .fa_xor1(s_cska4_fa0_xor1), .fa_or0(s_cska4_fa0_or0));
  xor_gate xor_gate_s_cska4_xor2(.a(a[2]), .b(b[2]), .out(s_cska4_xor2));
  fa fa_s_cska4_fa1_out(.a(a[2]), .b(b[2]), .cin(s_cska4_fa0_or0[0]), .fa_xor1(s_cska4_fa1_xor1), .fa_or0(s_cska4_fa1_or0));
  xor_gate xor_gate_s_cska4_xor3(.a(a[3]), .b(b[3]), .out(s_cska4_xor3));
  fa fa_s_cska4_fa2_out(.a(a[3]), .b(b[3]), .cin(s_cska4_fa1_or0[0]), .fa_xor1(s_cska4_fa2_xor1), .fa_or0(s_cska4_fa2_or0));
  and_gate and_gate_s_cska4_and_propagate00(.a(s_cska4_xor0[0]), .b(s_cska4_xor2[0]), .out(s_cska4_and_propagate00));
  and_gate and_gate_s_cska4_and_propagate01(.a(s_cska4_xor1[0]), .b(s_cska4_xor3[0]), .out(s_cska4_and_propagate01));
  and_gate and_gate_s_cska4_and_propagate02(.a(s_cska4_and_propagate00[0]), .b(s_cska4_and_propagate01[0]), .out(s_cska4_and_propagate02));
  mux2to1 mux2to1_s_cska4_mux2to10_out(.d0(s_cska4_fa2_or0[0]), .d1(1'b0), .sel(s_cska4_and_propagate02[0]), .mux2to1_xor0(s_cska4_mux2to10_and1));
  xor_gate xor_gate_s_cska4_xor4(.a(a[3]), .b(b[3]), .out(s_cska4_xor4));
  xor_gate xor_gate_s_cska4_xor5(.a(s_cska4_xor4[0]), .b(s_cska4_mux2to10_and1[0]), .out(s_cska4_xor5));

  assign s_cska4_out[0] = s_cska4_ha0_xor0[0];
  assign s_cska4_out[1] = s_cska4_fa0_xor1[0];
  assign s_cska4_out[2] = s_cska4_fa1_xor1[0];
  assign s_cska4_out[3] = s_cska4_fa2_xor1[0];
  assign s_cska4_out[4] = s_cska4_xor5[0];
endmodule