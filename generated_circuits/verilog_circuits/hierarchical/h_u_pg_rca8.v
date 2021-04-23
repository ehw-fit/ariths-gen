module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module pg_fa(input [0:0] a, input [0:0] b, input [0:0] cin, output [0:0] pg_fa_xor0, output [0:0] pg_fa_and0, output [0:0] pg_fa_xor1);
  xor_gate xor_gate_pg_fa_xor0(a[0], b[0], pg_fa_xor0);
  and_gate and_gate_pg_fa_and0(a[0], b[0], pg_fa_and0);
  xor_gate xor_gate_pg_fa_xor1(pg_fa_xor0[0], cin[0], pg_fa_xor1);
endmodule

module h_u_pg_rca8(input [7:0] a, input [7:0] b, output [8:0] h_u_pg_rca8_out);
  wire [0:0] h_u_pg_rca8_pg_fa0_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa0_and0;
  wire [0:0] h_u_pg_rca8_pg_fa1_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa1_and0;
  wire [0:0] h_u_pg_rca8_pg_fa1_xor1;
  wire [0:0] h_u_pg_rca8_and1;
  wire [0:0] h_u_pg_rca8_or1;
  wire [0:0] h_u_pg_rca8_pg_fa2_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa2_and0;
  wire [0:0] h_u_pg_rca8_pg_fa2_xor1;
  wire [0:0] h_u_pg_rca8_and2;
  wire [0:0] h_u_pg_rca8_or2;
  wire [0:0] h_u_pg_rca8_pg_fa3_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa3_and0;
  wire [0:0] h_u_pg_rca8_pg_fa3_xor1;
  wire [0:0] h_u_pg_rca8_and3;
  wire [0:0] h_u_pg_rca8_or3;
  wire [0:0] h_u_pg_rca8_pg_fa4_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa4_and0;
  wire [0:0] h_u_pg_rca8_pg_fa4_xor1;
  wire [0:0] h_u_pg_rca8_and4;
  wire [0:0] h_u_pg_rca8_or4;
  wire [0:0] h_u_pg_rca8_pg_fa5_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa5_and0;
  wire [0:0] h_u_pg_rca8_pg_fa5_xor1;
  wire [0:0] h_u_pg_rca8_and5;
  wire [0:0] h_u_pg_rca8_or5;
  wire [0:0] h_u_pg_rca8_pg_fa6_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa6_and0;
  wire [0:0] h_u_pg_rca8_pg_fa6_xor1;
  wire [0:0] h_u_pg_rca8_and6;
  wire [0:0] h_u_pg_rca8_or6;
  wire [0:0] h_u_pg_rca8_pg_fa7_xor0;
  wire [0:0] h_u_pg_rca8_pg_fa7_and0;
  wire [0:0] h_u_pg_rca8_pg_fa7_xor1;
  wire [0:0] h_u_pg_rca8_and7;
  wire [0:0] h_u_pg_rca8_or7;

  pg_fa pg_fa_h_u_pg_rca8_pg_fa0_out(a[0], b[0], 1'b0, h_u_pg_rca8_pg_fa0_xor0, h_u_pg_rca8_pg_fa0_and0);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa1_out(a[1], b[1], h_u_pg_rca8_pg_fa0_and0[0], h_u_pg_rca8_pg_fa1_xor0, h_u_pg_rca8_pg_fa1_and0, h_u_pg_rca8_pg_fa1_xor1);
  and_gate and_gate_h_u_pg_rca8_and1(h_u_pg_rca8_pg_fa0_and0[0], h_u_pg_rca8_pg_fa1_xor0[0], h_u_pg_rca8_and1);
  or_gate or_gate_h_u_pg_rca8_or1(h_u_pg_rca8_and1[0], h_u_pg_rca8_pg_fa1_and0[0], h_u_pg_rca8_or1);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa2_out(a[2], b[2], h_u_pg_rca8_or1[0], h_u_pg_rca8_pg_fa2_xor0, h_u_pg_rca8_pg_fa2_and0, h_u_pg_rca8_pg_fa2_xor1);
  and_gate and_gate_h_u_pg_rca8_and2(h_u_pg_rca8_or1[0], h_u_pg_rca8_pg_fa2_xor0[0], h_u_pg_rca8_and2);
  or_gate or_gate_h_u_pg_rca8_or2(h_u_pg_rca8_and2[0], h_u_pg_rca8_pg_fa2_and0[0], h_u_pg_rca8_or2);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa3_out(a[3], b[3], h_u_pg_rca8_or2[0], h_u_pg_rca8_pg_fa3_xor0, h_u_pg_rca8_pg_fa3_and0, h_u_pg_rca8_pg_fa3_xor1);
  and_gate and_gate_h_u_pg_rca8_and3(h_u_pg_rca8_or2[0], h_u_pg_rca8_pg_fa3_xor0[0], h_u_pg_rca8_and3);
  or_gate or_gate_h_u_pg_rca8_or3(h_u_pg_rca8_and3[0], h_u_pg_rca8_pg_fa3_and0[0], h_u_pg_rca8_or3);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa4_out(a[4], b[4], h_u_pg_rca8_or3[0], h_u_pg_rca8_pg_fa4_xor0, h_u_pg_rca8_pg_fa4_and0, h_u_pg_rca8_pg_fa4_xor1);
  and_gate and_gate_h_u_pg_rca8_and4(h_u_pg_rca8_or3[0], h_u_pg_rca8_pg_fa4_xor0[0], h_u_pg_rca8_and4);
  or_gate or_gate_h_u_pg_rca8_or4(h_u_pg_rca8_and4[0], h_u_pg_rca8_pg_fa4_and0[0], h_u_pg_rca8_or4);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa5_out(a[5], b[5], h_u_pg_rca8_or4[0], h_u_pg_rca8_pg_fa5_xor0, h_u_pg_rca8_pg_fa5_and0, h_u_pg_rca8_pg_fa5_xor1);
  and_gate and_gate_h_u_pg_rca8_and5(h_u_pg_rca8_or4[0], h_u_pg_rca8_pg_fa5_xor0[0], h_u_pg_rca8_and5);
  or_gate or_gate_h_u_pg_rca8_or5(h_u_pg_rca8_and5[0], h_u_pg_rca8_pg_fa5_and0[0], h_u_pg_rca8_or5);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa6_out(a[6], b[6], h_u_pg_rca8_or5[0], h_u_pg_rca8_pg_fa6_xor0, h_u_pg_rca8_pg_fa6_and0, h_u_pg_rca8_pg_fa6_xor1);
  and_gate and_gate_h_u_pg_rca8_and6(h_u_pg_rca8_or5[0], h_u_pg_rca8_pg_fa6_xor0[0], h_u_pg_rca8_and6);
  or_gate or_gate_h_u_pg_rca8_or6(h_u_pg_rca8_and6[0], h_u_pg_rca8_pg_fa6_and0[0], h_u_pg_rca8_or6);
  pg_fa pg_fa_h_u_pg_rca8_pg_fa7_out(a[7], b[7], h_u_pg_rca8_or6[0], h_u_pg_rca8_pg_fa7_xor0, h_u_pg_rca8_pg_fa7_and0, h_u_pg_rca8_pg_fa7_xor1);
  and_gate and_gate_h_u_pg_rca8_and7(h_u_pg_rca8_or6[0], h_u_pg_rca8_pg_fa7_xor0[0], h_u_pg_rca8_and7);
  or_gate or_gate_h_u_pg_rca8_or7(h_u_pg_rca8_and7[0], h_u_pg_rca8_pg_fa7_and0[0], h_u_pg_rca8_or7);

  assign h_u_pg_rca8_out[0] = h_u_pg_rca8_pg_fa0_xor0[0];
  assign h_u_pg_rca8_out[1] = h_u_pg_rca8_pg_fa1_xor1[0];
  assign h_u_pg_rca8_out[2] = h_u_pg_rca8_pg_fa2_xor1[0];
  assign h_u_pg_rca8_out[3] = h_u_pg_rca8_pg_fa3_xor1[0];
  assign h_u_pg_rca8_out[4] = h_u_pg_rca8_pg_fa4_xor1[0];
  assign h_u_pg_rca8_out[5] = h_u_pg_rca8_pg_fa5_xor1[0];
  assign h_u_pg_rca8_out[6] = h_u_pg_rca8_pg_fa6_xor1[0];
  assign h_u_pg_rca8_out[7] = h_u_pg_rca8_pg_fa7_xor1[0];
  assign h_u_pg_rca8_out[8] = h_u_pg_rca8_or7[0];
endmodule