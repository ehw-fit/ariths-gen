module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
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

module u_cska2(input [1:0] a, input [1:0] b, output [2:0] u_cska2_out);
  wire [0:0] u_cska2_xor0;
  wire [0:0] u_cska2_ha0_xor0;
  wire [0:0] u_cska2_ha0_and0;
  wire [0:0] u_cska2_xor1;
  wire [0:0] u_cska2_fa0_xor1;
  wire [0:0] u_cska2_fa0_or0;
  wire [0:0] u_cska2_and_propagate00;
  wire [0:0] u_cska2_mux2to10_and1;

  xor_gate xor_gate_u_cska2_xor0(.a(a[0]), .b(b[0]), .out(u_cska2_xor0));
  ha ha_u_cska2_ha0_out(.a(a[0]), .b(b[0]), .ha_xor0(u_cska2_ha0_xor0), .ha_and0(u_cska2_ha0_and0));
  xor_gate xor_gate_u_cska2_xor1(.a(a[1]), .b(b[1]), .out(u_cska2_xor1));
  fa fa_u_cska2_fa0_out(.a(a[1]), .b(b[1]), .cin(u_cska2_ha0_and0[0]), .fa_xor1(u_cska2_fa0_xor1), .fa_or0(u_cska2_fa0_or0));
  and_gate and_gate_u_cska2_and_propagate00(.a(u_cska2_xor0[0]), .b(u_cska2_xor1[0]), .out(u_cska2_and_propagate00));
  mux2to1 mux2to1_u_cska2_mux2to10_out(.d0(u_cska2_fa0_or0[0]), .d1(1'b0), .sel(u_cska2_and_propagate00[0]), .mux2to1_xor0(u_cska2_mux2to10_and1));

  assign u_cska2_out[0] = u_cska2_ha0_xor0[0];
  assign u_cska2_out[1] = u_cska2_fa0_xor1[0];
  assign u_cska2_out[2] = u_cska2_mux2to10_and1[0];
endmodule

module h_u_csatm8_cska_k6(input [7:0] a, input [7:0] b, output [15:0] h_u_csatm8_cska_k6_out);
  wire [0:0] h_u_csatm8_cska_k6_and6_6;
  wire [0:0] h_u_csatm8_cska_k6_and7_6;
  wire [0:0] h_u_csatm8_cska_k6_and6_7;
  wire [0:0] h_u_csatm8_cska_k6_ha6_7_xor0;
  wire [0:0] h_u_csatm8_cska_k6_ha6_7_and0;
  wire [0:0] h_u_csatm8_cska_k6_and7_7;
  wire [1:0] h_u_csatm8_cska_k6_u_cska2_a;
  wire [1:0] h_u_csatm8_cska_k6_u_cska2_b;
  wire [2:0] h_u_csatm8_cska_k6_u_cska2_out;

  and_gate and_gate_h_u_csatm8_cska_k6_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csatm8_cska_k6_and6_6));
  and_gate and_gate_h_u_csatm8_cska_k6_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csatm8_cska_k6_and7_6));
  and_gate and_gate_h_u_csatm8_cska_k6_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csatm8_cska_k6_and6_7));
  ha ha_h_u_csatm8_cska_k6_ha6_7_out(.a(h_u_csatm8_cska_k6_and6_7[0]), .b(h_u_csatm8_cska_k6_and7_6[0]), .ha_xor0(h_u_csatm8_cska_k6_ha6_7_xor0), .ha_and0(h_u_csatm8_cska_k6_ha6_7_and0));
  and_gate and_gate_h_u_csatm8_cska_k6_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csatm8_cska_k6_and7_7));
  assign h_u_csatm8_cska_k6_u_cska2_a[0] = h_u_csatm8_cska_k6_and7_7[0];
  assign h_u_csatm8_cska_k6_u_cska2_a[1] = 1'b0;
  assign h_u_csatm8_cska_k6_u_cska2_b[0] = h_u_csatm8_cska_k6_ha6_7_and0[0];
  assign h_u_csatm8_cska_k6_u_cska2_b[1] = 1'b0;
  u_cska2 u_cska2_h_u_csatm8_cska_k6_u_cska2_out(.a(h_u_csatm8_cska_k6_u_cska2_a), .b(h_u_csatm8_cska_k6_u_cska2_b), .u_cska2_out(h_u_csatm8_cska_k6_u_cska2_out));

  assign h_u_csatm8_cska_k6_out[0] = 1'b0;
  assign h_u_csatm8_cska_k6_out[1] = 1'b0;
  assign h_u_csatm8_cska_k6_out[2] = 1'b0;
  assign h_u_csatm8_cska_k6_out[3] = 1'b0;
  assign h_u_csatm8_cska_k6_out[4] = 1'b0;
  assign h_u_csatm8_cska_k6_out[5] = 1'b0;
  assign h_u_csatm8_cska_k6_out[6] = 1'b0;
  assign h_u_csatm8_cska_k6_out[7] = 1'b0;
  assign h_u_csatm8_cska_k6_out[8] = 1'b0;
  assign h_u_csatm8_cska_k6_out[9] = 1'b0;
  assign h_u_csatm8_cska_k6_out[10] = 1'b0;
  assign h_u_csatm8_cska_k6_out[11] = 1'b0;
  assign h_u_csatm8_cska_k6_out[12] = h_u_csatm8_cska_k6_and6_6[0];
  assign h_u_csatm8_cska_k6_out[13] = h_u_csatm8_cska_k6_ha6_7_xor0[0];
  assign h_u_csatm8_cska_k6_out[14] = h_u_csatm8_cska_k6_u_cska2_out[0];
  assign h_u_csatm8_cska_k6_out[15] = h_u_csatm8_cska_k6_u_cska2_out[1];
endmodule