module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module pg_logic(input [0:0] a, input [0:0] b, output [0:0] pg_logic_or0, output [0:0] pg_logic_and0, output [0:0] pg_logic_xor0);
  or_gate or_gate_pg_logic_or0(a[0], b[0], pg_logic_or0);
  and_gate and_gate_pg_logic_and0(a[0], b[0], pg_logic_and0);
  xor_gate xor_gate_pg_logic_xor0(a[0], b[0], pg_logic_xor0);
endmodule

module h_s_cla4(input [3:0] a, input [3:0] b, output [4:0] h_s_cla4_out);
  wire [0:0] h_s_cla4_pg_logic0_or0;
  wire [0:0] h_s_cla4_pg_logic0_and0;
  wire [0:0] h_s_cla4_pg_logic0_xor0;
  wire [0:0] h_s_cla4_pg_logic1_or0;
  wire [0:0] h_s_cla4_pg_logic1_and0;
  wire [0:0] h_s_cla4_pg_logic1_xor0;
  wire [0:0] h_s_cla4_xor1;
  wire [0:0] h_s_cla4_and0;
  wire [0:0] h_s_cla4_or0;
  wire [0:0] h_s_cla4_pg_logic2_or0;
  wire [0:0] h_s_cla4_pg_logic2_and0;
  wire [0:0] h_s_cla4_pg_logic2_xor0;
  wire [0:0] h_s_cla4_xor2;
  wire [0:0] h_s_cla4_and1;
  wire [0:0] h_s_cla4_and2;
  wire [0:0] h_s_cla4_and3;
  wire [0:0] h_s_cla4_and4;
  wire [0:0] h_s_cla4_or1;
  wire [0:0] h_s_cla4_or2;
  wire [0:0] h_s_cla4_pg_logic3_or0;
  wire [0:0] h_s_cla4_pg_logic3_and0;
  wire [0:0] h_s_cla4_pg_logic3_xor0;
  wire [0:0] h_s_cla4_xor3;
  wire [0:0] h_s_cla4_and5;
  wire [0:0] h_s_cla4_and6;
  wire [0:0] h_s_cla4_and7;
  wire [0:0] h_s_cla4_and8;
  wire [0:0] h_s_cla4_and9;
  wire [0:0] h_s_cla4_and10;
  wire [0:0] h_s_cla4_and11;
  wire [0:0] h_s_cla4_or3;
  wire [0:0] h_s_cla4_or4;
  wire [0:0] h_s_cla4_or5;
  wire [0:0] h_s_cla4_xor4;
  wire [0:0] h_s_cla4_xor5;

  pg_logic pg_logic_h_s_cla4_pg_logic0_out(a[0], b[0], h_s_cla4_pg_logic0_or0, h_s_cla4_pg_logic0_and0, h_s_cla4_pg_logic0_xor0);
  pg_logic pg_logic_h_s_cla4_pg_logic1_out(a[1], b[1], h_s_cla4_pg_logic1_or0, h_s_cla4_pg_logic1_and0, h_s_cla4_pg_logic1_xor0);
  xor_gate xor_gate_h_s_cla4_xor1(h_s_cla4_pg_logic1_xor0[0], h_s_cla4_pg_logic0_and0[0], h_s_cla4_xor1);
  and_gate and_gate_h_s_cla4_and0(h_s_cla4_pg_logic0_and0[0], h_s_cla4_pg_logic1_or0[0], h_s_cla4_and0);
  or_gate or_gate_h_s_cla4_or0(h_s_cla4_pg_logic1_and0[0], h_s_cla4_and0[0], h_s_cla4_or0);
  pg_logic pg_logic_h_s_cla4_pg_logic2_out(a[2], b[2], h_s_cla4_pg_logic2_or0, h_s_cla4_pg_logic2_and0, h_s_cla4_pg_logic2_xor0);
  xor_gate xor_gate_h_s_cla4_xor2(h_s_cla4_pg_logic2_xor0[0], h_s_cla4_or0[0], h_s_cla4_xor2);
  and_gate and_gate_h_s_cla4_and1(h_s_cla4_pg_logic2_or0[0], h_s_cla4_pg_logic0_or0[0], h_s_cla4_and1);
  and_gate and_gate_h_s_cla4_and2(h_s_cla4_pg_logic0_and0[0], h_s_cla4_pg_logic2_or0[0], h_s_cla4_and2);
  and_gate and_gate_h_s_cla4_and3(h_s_cla4_and2[0], h_s_cla4_pg_logic1_or0[0], h_s_cla4_and3);
  and_gate and_gate_h_s_cla4_and4(h_s_cla4_pg_logic1_and0[0], h_s_cla4_pg_logic2_or0[0], h_s_cla4_and4);
  or_gate or_gate_h_s_cla4_or1(h_s_cla4_and3[0], h_s_cla4_and4[0], h_s_cla4_or1);
  or_gate or_gate_h_s_cla4_or2(h_s_cla4_pg_logic2_and0[0], h_s_cla4_or1[0], h_s_cla4_or2);
  pg_logic pg_logic_h_s_cla4_pg_logic3_out(a[3], b[3], h_s_cla4_pg_logic3_or0, h_s_cla4_pg_logic3_and0, h_s_cla4_pg_logic3_xor0);
  xor_gate xor_gate_h_s_cla4_xor3(h_s_cla4_pg_logic3_xor0[0], h_s_cla4_or2[0], h_s_cla4_xor3);
  and_gate and_gate_h_s_cla4_and5(h_s_cla4_pg_logic3_or0[0], h_s_cla4_pg_logic1_or0[0], h_s_cla4_and5);
  and_gate and_gate_h_s_cla4_and6(h_s_cla4_pg_logic0_and0[0], h_s_cla4_pg_logic2_or0[0], h_s_cla4_and6);
  and_gate and_gate_h_s_cla4_and7(h_s_cla4_pg_logic3_or0[0], h_s_cla4_pg_logic1_or0[0], h_s_cla4_and7);
  and_gate and_gate_h_s_cla4_and8(h_s_cla4_and6[0], h_s_cla4_and7[0], h_s_cla4_and8);
  and_gate and_gate_h_s_cla4_and9(h_s_cla4_pg_logic1_and0[0], h_s_cla4_pg_logic3_or0[0], h_s_cla4_and9);
  and_gate and_gate_h_s_cla4_and10(h_s_cla4_and9[0], h_s_cla4_pg_logic2_or0[0], h_s_cla4_and10);
  and_gate and_gate_h_s_cla4_and11(h_s_cla4_pg_logic2_and0[0], h_s_cla4_pg_logic3_or0[0], h_s_cla4_and11);
  or_gate or_gate_h_s_cla4_or3(h_s_cla4_and8[0], h_s_cla4_and11[0], h_s_cla4_or3);
  or_gate or_gate_h_s_cla4_or4(h_s_cla4_and10[0], h_s_cla4_or3[0], h_s_cla4_or4);
  or_gate or_gate_h_s_cla4_or5(h_s_cla4_pg_logic3_and0[0], h_s_cla4_or4[0], h_s_cla4_or5);
  xor_gate xor_gate_h_s_cla4_xor4(a[3], b[3], h_s_cla4_xor4);
  xor_gate xor_gate_h_s_cla4_xor5(h_s_cla4_xor4[0], h_s_cla4_or5[0], h_s_cla4_xor5);

  assign h_s_cla4_out[0] = h_s_cla4_pg_logic0_xor0[0];
  assign h_s_cla4_out[1] = h_s_cla4_xor1[0];
  assign h_s_cla4_out[2] = h_s_cla4_xor2[0];
  assign h_s_cla4_out[3] = h_s_cla4_xor3[0];
  assign h_s_cla4_out[4] = h_s_cla4_xor5[0];
endmodule