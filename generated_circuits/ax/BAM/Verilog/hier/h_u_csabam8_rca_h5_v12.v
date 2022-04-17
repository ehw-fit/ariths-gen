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

module u_rca3(input [2:0] a, input [2:0] b, output [3:0] u_rca3_out);
  wire [0:0] u_rca3_ha_xor0;
  wire [0:0] u_rca3_ha_and0;
  wire [0:0] u_rca3_fa1_xor1;
  wire [0:0] u_rca3_fa1_or0;
  wire [0:0] u_rca3_fa2_xor1;
  wire [0:0] u_rca3_fa2_or0;

  ha ha_u_rca3_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(u_rca3_ha_xor0), .ha_and0(u_rca3_ha_and0));
  fa fa_u_rca3_fa1_out(.a(a[1]), .b(b[1]), .cin(u_rca3_ha_and0[0]), .fa_xor1(u_rca3_fa1_xor1), .fa_or0(u_rca3_fa1_or0));
  fa fa_u_rca3_fa2_out(.a(a[2]), .b(b[2]), .cin(u_rca3_fa1_or0[0]), .fa_xor1(u_rca3_fa2_xor1), .fa_or0(u_rca3_fa2_or0));

  assign u_rca3_out[0] = u_rca3_ha_xor0[0];
  assign u_rca3_out[1] = u_rca3_fa1_xor1[0];
  assign u_rca3_out[2] = u_rca3_fa2_xor1[0];
  assign u_rca3_out[3] = u_rca3_fa2_or0[0];
endmodule

module h_u_csabam8_rca_h5_v12(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_rca_h5_v12_out);
  wire [0:0] h_u_csabam8_rca_h5_v12_and7_5;
  wire [0:0] h_u_csabam8_rca_h5_v12_and6_6;
  wire [0:0] h_u_csabam8_rca_h5_v12_ha6_6_xor0;
  wire [0:0] h_u_csabam8_rca_h5_v12_ha6_6_and0;
  wire [0:0] h_u_csabam8_rca_h5_v12_and7_6;
  wire [0:0] h_u_csabam8_rca_h5_v12_and5_7;
  wire [0:0] h_u_csabam8_rca_h5_v12_ha5_7_xor0;
  wire [0:0] h_u_csabam8_rca_h5_v12_ha5_7_and0;
  wire [0:0] h_u_csabam8_rca_h5_v12_and6_7;
  wire [0:0] h_u_csabam8_rca_h5_v12_fa6_7_xor1;
  wire [0:0] h_u_csabam8_rca_h5_v12_fa6_7_or0;
  wire [0:0] h_u_csabam8_rca_h5_v12_and7_7;
  wire [2:0] h_u_csabam8_rca_h5_v12_u_rca3_a;
  wire [2:0] h_u_csabam8_rca_h5_v12_u_rca3_b;
  wire [3:0] h_u_csabam8_rca_h5_v12_u_rca3_out;

  and_gate and_gate_h_u_csabam8_rca_h5_v12_and7_5(.a(a[7]), .b(b[5]), .out(h_u_csabam8_rca_h5_v12_and7_5));
  and_gate and_gate_h_u_csabam8_rca_h5_v12_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csabam8_rca_h5_v12_and6_6));
  ha ha_h_u_csabam8_rca_h5_v12_ha6_6_out(.a(h_u_csabam8_rca_h5_v12_and6_6[0]), .b(h_u_csabam8_rca_h5_v12_and7_5[0]), .ha_xor0(h_u_csabam8_rca_h5_v12_ha6_6_xor0), .ha_and0(h_u_csabam8_rca_h5_v12_ha6_6_and0));
  and_gate and_gate_h_u_csabam8_rca_h5_v12_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csabam8_rca_h5_v12_and7_6));
  and_gate and_gate_h_u_csabam8_rca_h5_v12_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_rca_h5_v12_and5_7));
  ha ha_h_u_csabam8_rca_h5_v12_ha5_7_out(.a(h_u_csabam8_rca_h5_v12_and5_7[0]), .b(h_u_csabam8_rca_h5_v12_ha6_6_xor0[0]), .ha_xor0(h_u_csabam8_rca_h5_v12_ha5_7_xor0), .ha_and0(h_u_csabam8_rca_h5_v12_ha5_7_and0));
  and_gate and_gate_h_u_csabam8_rca_h5_v12_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_rca_h5_v12_and6_7));
  fa fa_h_u_csabam8_rca_h5_v12_fa6_7_out(.a(h_u_csabam8_rca_h5_v12_and6_7[0]), .b(h_u_csabam8_rca_h5_v12_and7_6[0]), .cin(h_u_csabam8_rca_h5_v12_ha6_6_and0[0]), .fa_xor1(h_u_csabam8_rca_h5_v12_fa6_7_xor1), .fa_or0(h_u_csabam8_rca_h5_v12_fa6_7_or0));
  and_gate and_gate_h_u_csabam8_rca_h5_v12_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_rca_h5_v12_and7_7));
  assign h_u_csabam8_rca_h5_v12_u_rca3_a[0] = h_u_csabam8_rca_h5_v12_fa6_7_xor1[0];
  assign h_u_csabam8_rca_h5_v12_u_rca3_a[1] = h_u_csabam8_rca_h5_v12_and7_7[0];
  assign h_u_csabam8_rca_h5_v12_u_rca3_a[2] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_u_rca3_b[0] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_u_rca3_b[1] = h_u_csabam8_rca_h5_v12_fa6_7_or0[0];
  assign h_u_csabam8_rca_h5_v12_u_rca3_b[2] = 1'b0;
  u_rca3 u_rca3_h_u_csabam8_rca_h5_v12_u_rca3_out(.a(h_u_csabam8_rca_h5_v12_u_rca3_a), .b(h_u_csabam8_rca_h5_v12_u_rca3_b), .u_rca3_out(h_u_csabam8_rca_h5_v12_u_rca3_out));

  assign h_u_csabam8_rca_h5_v12_out[0] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[1] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[2] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[3] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[4] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[5] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[6] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[7] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[8] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[9] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[10] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[11] = 1'b0;
  assign h_u_csabam8_rca_h5_v12_out[12] = h_u_csabam8_rca_h5_v12_u_rca3_out[0];
  assign h_u_csabam8_rca_h5_v12_out[13] = h_u_csabam8_rca_h5_v12_u_rca3_out[1];
  assign h_u_csabam8_rca_h5_v12_out[14] = h_u_csabam8_rca_h5_v12_u_rca3_out[2];
  assign h_u_csabam8_rca_h5_v12_out[15] = 1'b0;
endmodule