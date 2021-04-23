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
  xor_gate xor_gate_ha_xor0(a[0], b[0], ha_xor0);
  and_gate and_gate_ha_and0(a[0], b[0], ha_and0);
endmodule

module fa(input [0:0] a, input [0:0] b, input [0:0] cin, output [0:0] fa_xor1, output [0:0] fa_or0);
  wire [0:0] fa_xor0;
  wire [0:0] fa_and0;
  wire [0:0] fa_and1;
  xor_gate xor_gate_fa_xor0(a[0], b[0], fa_xor0);
  and_gate and_gate_fa_and0(a[0], b[0], fa_and0);
  xor_gate xor_gate_fa_xor1(fa_xor0[0], cin[0], fa_xor1);
  and_gate and_gate_fa_and1(fa_xor0[0], cin[0], fa_and1);
  or_gate or_gate_fa_or0(fa_and0[0], fa_and1[0], fa_or0);
endmodule

module u_rca6(input [5:0] a, input [5:0] b, output [6:0] u_rca6_out);
  wire [0:0] u_rca6_ha_xor0;
  wire [0:0] u_rca6_ha_and0;
  wire [0:0] u_rca6_fa1_xor1;
  wire [0:0] u_rca6_fa1_or0;
  wire [0:0] u_rca6_fa2_xor1;
  wire [0:0] u_rca6_fa2_or0;
  wire [0:0] u_rca6_fa3_xor1;
  wire [0:0] u_rca6_fa3_or0;
  wire [0:0] u_rca6_fa4_xor1;
  wire [0:0] u_rca6_fa4_or0;
  wire [0:0] u_rca6_fa5_xor1;
  wire [0:0] u_rca6_fa5_or0;

  ha ha_u_rca6_ha_out(a[0], b[0], u_rca6_ha_xor0, u_rca6_ha_and0);
  fa fa_u_rca6_fa1_out(a[1], b[1], u_rca6_ha_and0[0], u_rca6_fa1_xor1, u_rca6_fa1_or0);
  fa fa_u_rca6_fa2_out(a[2], b[2], u_rca6_fa1_or0[0], u_rca6_fa2_xor1, u_rca6_fa2_or0);
  fa fa_u_rca6_fa3_out(a[3], b[3], u_rca6_fa2_or0[0], u_rca6_fa3_xor1, u_rca6_fa3_or0);
  fa fa_u_rca6_fa4_out(a[4], b[4], u_rca6_fa3_or0[0], u_rca6_fa4_xor1, u_rca6_fa4_or0);
  fa fa_u_rca6_fa5_out(a[5], b[5], u_rca6_fa4_or0[0], u_rca6_fa5_xor1, u_rca6_fa5_or0);

  assign u_rca6_out[0] = u_rca6_ha_xor0[0];
  assign u_rca6_out[1] = u_rca6_fa1_xor1[0];
  assign u_rca6_out[2] = u_rca6_fa2_xor1[0];
  assign u_rca6_out[3] = u_rca6_fa3_xor1[0];
  assign u_rca6_out[4] = u_rca6_fa4_xor1[0];
  assign u_rca6_out[5] = u_rca6_fa5_xor1[0];
  assign u_rca6_out[6] = u_rca6_fa5_or0[0];
endmodule

module h_u_dadda_rca4(input [3:0] a, input [3:0] b, output [7:0] h_u_dadda_rca4_out);
  wire [0:0] h_u_dadda_rca4_and_3_0;
  wire [0:0] h_u_dadda_rca4_and_2_1;
  wire [0:0] h_u_dadda_rca4_ha0_xor0;
  wire [0:0] h_u_dadda_rca4_ha0_and0;
  wire [0:0] h_u_dadda_rca4_and_3_1;
  wire [0:0] h_u_dadda_rca4_ha1_xor0;
  wire [0:0] h_u_dadda_rca4_ha1_and0;
  wire [0:0] h_u_dadda_rca4_and_2_0;
  wire [0:0] h_u_dadda_rca4_and_1_1;
  wire [0:0] h_u_dadda_rca4_ha2_xor0;
  wire [0:0] h_u_dadda_rca4_ha2_and0;
  wire [0:0] h_u_dadda_rca4_and_1_2;
  wire [0:0] h_u_dadda_rca4_and_0_3;
  wire [0:0] h_u_dadda_rca4_fa0_xor1;
  wire [0:0] h_u_dadda_rca4_fa0_or0;
  wire [0:0] h_u_dadda_rca4_and_2_2;
  wire [0:0] h_u_dadda_rca4_and_1_3;
  wire [0:0] h_u_dadda_rca4_fa1_xor1;
  wire [0:0] h_u_dadda_rca4_fa1_or0;
  wire [0:0] h_u_dadda_rca4_and_3_2;
  wire [0:0] h_u_dadda_rca4_fa2_xor1;
  wire [0:0] h_u_dadda_rca4_fa2_or0;
  wire [0:0] h_u_dadda_rca4_and_0_0;
  wire [0:0] h_u_dadda_rca4_and_1_0;
  wire [0:0] h_u_dadda_rca4_and_0_2;
  wire [0:0] h_u_dadda_rca4_and_2_3;
  wire [0:0] h_u_dadda_rca4_and_0_1;
  wire [0:0] h_u_dadda_rca4_and_3_3;
  wire [5:0] h_u_dadda_rca4_u_rca6_a;
  wire [5:0] h_u_dadda_rca4_u_rca6_b;
  wire [6:0] h_u_dadda_rca4_u_rca6_out;

  and_gate and_gate_h_u_dadda_rca4_and_3_0(a[3], b[0], h_u_dadda_rca4_and_3_0);
  and_gate and_gate_h_u_dadda_rca4_and_2_1(a[2], b[1], h_u_dadda_rca4_and_2_1);
  ha ha_h_u_dadda_rca4_ha0_out(h_u_dadda_rca4_and_3_0[0], h_u_dadda_rca4_and_2_1[0], h_u_dadda_rca4_ha0_xor0, h_u_dadda_rca4_ha0_and0);
  and_gate and_gate_h_u_dadda_rca4_and_3_1(a[3], b[1], h_u_dadda_rca4_and_3_1);
  ha ha_h_u_dadda_rca4_ha1_out(h_u_dadda_rca4_ha0_and0[0], h_u_dadda_rca4_and_3_1[0], h_u_dadda_rca4_ha1_xor0, h_u_dadda_rca4_ha1_and0);
  and_gate and_gate_h_u_dadda_rca4_and_2_0(a[2], b[0], h_u_dadda_rca4_and_2_0);
  and_gate and_gate_h_u_dadda_rca4_and_1_1(a[1], b[1], h_u_dadda_rca4_and_1_1);
  ha ha_h_u_dadda_rca4_ha2_out(h_u_dadda_rca4_and_2_0[0], h_u_dadda_rca4_and_1_1[0], h_u_dadda_rca4_ha2_xor0, h_u_dadda_rca4_ha2_and0);
  and_gate and_gate_h_u_dadda_rca4_and_1_2(a[1], b[2], h_u_dadda_rca4_and_1_2);
  and_gate and_gate_h_u_dadda_rca4_and_0_3(a[0], b[3], h_u_dadda_rca4_and_0_3);
  fa fa_h_u_dadda_rca4_fa0_out(h_u_dadda_rca4_ha2_and0[0], h_u_dadda_rca4_and_1_2[0], h_u_dadda_rca4_and_0_3[0], h_u_dadda_rca4_fa0_xor1, h_u_dadda_rca4_fa0_or0);
  and_gate and_gate_h_u_dadda_rca4_and_2_2(a[2], b[2], h_u_dadda_rca4_and_2_2);
  and_gate and_gate_h_u_dadda_rca4_and_1_3(a[1], b[3], h_u_dadda_rca4_and_1_3);
  fa fa_h_u_dadda_rca4_fa1_out(h_u_dadda_rca4_fa0_or0[0], h_u_dadda_rca4_and_2_2[0], h_u_dadda_rca4_and_1_3[0], h_u_dadda_rca4_fa1_xor1, h_u_dadda_rca4_fa1_or0);
  and_gate and_gate_h_u_dadda_rca4_and_3_2(a[3], b[2], h_u_dadda_rca4_and_3_2);
  fa fa_h_u_dadda_rca4_fa2_out(h_u_dadda_rca4_fa1_or0[0], h_u_dadda_rca4_ha1_and0[0], h_u_dadda_rca4_and_3_2[0], h_u_dadda_rca4_fa2_xor1, h_u_dadda_rca4_fa2_or0);
  and_gate and_gate_h_u_dadda_rca4_and_0_0(a[0], b[0], h_u_dadda_rca4_and_0_0);
  and_gate and_gate_h_u_dadda_rca4_and_1_0(a[1], b[0], h_u_dadda_rca4_and_1_0);
  and_gate and_gate_h_u_dadda_rca4_and_0_2(a[0], b[2], h_u_dadda_rca4_and_0_2);
  and_gate and_gate_h_u_dadda_rca4_and_2_3(a[2], b[3], h_u_dadda_rca4_and_2_3);
  and_gate and_gate_h_u_dadda_rca4_and_0_1(a[0], b[1], h_u_dadda_rca4_and_0_1);
  and_gate and_gate_h_u_dadda_rca4_and_3_3(a[3], b[3], h_u_dadda_rca4_and_3_3);
  assign h_u_dadda_rca4_u_rca6_a[0] = h_u_dadda_rca4_and_1_0[0];
  assign h_u_dadda_rca4_u_rca6_a[1] = h_u_dadda_rca4_and_0_2[0];
  assign h_u_dadda_rca4_u_rca6_a[2] = h_u_dadda_rca4_ha0_xor0[0];
  assign h_u_dadda_rca4_u_rca6_a[3] = h_u_dadda_rca4_ha1_xor0[0];
  assign h_u_dadda_rca4_u_rca6_a[4] = h_u_dadda_rca4_and_2_3[0];
  assign h_u_dadda_rca4_u_rca6_a[5] = h_u_dadda_rca4_fa2_or0[0];
  assign h_u_dadda_rca4_u_rca6_b[0] = h_u_dadda_rca4_and_0_1[0];
  assign h_u_dadda_rca4_u_rca6_b[1] = h_u_dadda_rca4_ha2_xor0[0];
  assign h_u_dadda_rca4_u_rca6_b[2] = h_u_dadda_rca4_fa0_xor1[0];
  assign h_u_dadda_rca4_u_rca6_b[3] = h_u_dadda_rca4_fa1_xor1[0];
  assign h_u_dadda_rca4_u_rca6_b[4] = h_u_dadda_rca4_fa2_xor1[0];
  assign h_u_dadda_rca4_u_rca6_b[5] = h_u_dadda_rca4_and_3_3[0];
  u_rca6 u_rca6_h_u_dadda_rca4_u_rca6_out(h_u_dadda_rca4_u_rca6_a, h_u_dadda_rca4_u_rca6_b, h_u_dadda_rca4_u_rca6_out);

  assign h_u_dadda_rca4_out[0] = h_u_dadda_rca4_and_0_0[0];
  assign h_u_dadda_rca4_out[1] = h_u_dadda_rca4_u_rca6_out[0];
  assign h_u_dadda_rca4_out[2] = h_u_dadda_rca4_u_rca6_out[1];
  assign h_u_dadda_rca4_out[3] = h_u_dadda_rca4_u_rca6_out[2];
  assign h_u_dadda_rca4_out[4] = h_u_dadda_rca4_u_rca6_out[3];
  assign h_u_dadda_rca4_out[5] = h_u_dadda_rca4_u_rca6_out[4];
  assign h_u_dadda_rca4_out[6] = h_u_dadda_rca4_u_rca6_out[5];
  assign h_u_dadda_rca4_out[7] = h_u_dadda_rca4_u_rca6_out[6];
endmodule