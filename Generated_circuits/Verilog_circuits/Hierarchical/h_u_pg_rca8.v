module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module xnor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a ^ _b);
endmodule

module nor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a | _b);
endmodule

module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module or_gate(input _a, input _b, output _y0);
  assign _y0 = _a | _b;
endmodule

module constant_wire_value_0(input a, input b, output constant_wire_0);
  wire constant_wire_value_0_a;
  wire constant_wire_value_0_b;

  assign constant_wire_value_0_a = a;
  assign constant_wire_value_0_b = b;

  xor_gate xor_gate_constant_wire_value_0_y0(constant_wire_value_0_a, constant_wire_value_0_b, constant_wire_value_0_y0);
  xnor_gate xnor_gate_constant_wire_value_0_y1(constant_wire_value_0_a, constant_wire_value_0_b, constant_wire_value_0_y1);
  nor_gate nor_gate_constant_wire_0(constant_wire_value_0_y0, constant_wire_value_0_y1, constant_wire_0);
endmodule

module fa_cla(input a, input b, input cin, output fa_cla_y0, output fa_cla_y1, output fa_cla_y2);
  wire fa_cla_a;
  wire fa_cla_b;
  wire fa_cla_cin;

  assign fa_cla_a = a;
  assign fa_cla_b = b;
  assign fa_cla_cin = cin;

  xor_gate xor_gate_fa_cla_y0(fa_cla_a, fa_cla_b, fa_cla_y0);
  and_gate and_gate_fa_cla_y1(fa_cla_a, fa_cla_b, fa_cla_y1);
  xor_gate xor_gate_fa_cla_y2(fa_cla_y0, fa_cla_cin, fa_cla_y2);
endmodule

module h_u_pg_rca8(input [7:0] a, input [7:0] b, output [8:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire a_4;
  wire a_5;
  wire a_6;
  wire a_7;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire b_4;
  wire b_5;
  wire b_6;
  wire b_7;
  wire constant_wire_0;
  wire h_u_pg_rca8_fa0_y0;
  wire h_u_pg_rca8_fa0_y1;
  wire h_u_pg_rca8_fa0_y2;
  wire h_u_pg_rca8_and0_y0;
  wire h_u_pg_rca8_or0_y0;
  wire h_u_pg_rca8_fa1_y0;
  wire h_u_pg_rca8_fa1_y1;
  wire h_u_pg_rca8_fa1_y2;
  wire h_u_pg_rca8_and1_y0;
  wire h_u_pg_rca8_or1_y0;
  wire h_u_pg_rca8_fa2_y0;
  wire h_u_pg_rca8_fa2_y1;
  wire h_u_pg_rca8_fa2_y2;
  wire h_u_pg_rca8_and2_y0;
  wire h_u_pg_rca8_or2_y0;
  wire h_u_pg_rca8_fa3_y0;
  wire h_u_pg_rca8_fa3_y1;
  wire h_u_pg_rca8_fa3_y2;
  wire h_u_pg_rca8_and3_y0;
  wire h_u_pg_rca8_or3_y0;
  wire h_u_pg_rca8_fa4_y0;
  wire h_u_pg_rca8_fa4_y1;
  wire h_u_pg_rca8_fa4_y2;
  wire h_u_pg_rca8_and4_y0;
  wire h_u_pg_rca8_or4_y0;
  wire h_u_pg_rca8_fa5_y0;
  wire h_u_pg_rca8_fa5_y1;
  wire h_u_pg_rca8_fa5_y2;
  wire h_u_pg_rca8_and5_y0;
  wire h_u_pg_rca8_or5_y0;
  wire h_u_pg_rca8_fa6_y0;
  wire h_u_pg_rca8_fa6_y1;
  wire h_u_pg_rca8_fa6_y2;
  wire h_u_pg_rca8_and6_y0;
  wire h_u_pg_rca8_or6_y0;
  wire h_u_pg_rca8_fa7_y0;
  wire h_u_pg_rca8_fa7_y1;
  wire h_u_pg_rca8_fa7_y2;
  wire h_u_pg_rca8_and7_y0;
  wire h_u_pg_rca8_or7_y0;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign a_4 = a[4];
  assign a_5 = a[5];
  assign a_6 = a[6];
  assign a_7 = a[7];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  assign b_4 = b[4];
  assign b_5 = b[5];
  assign b_6 = b[6];
  assign b_7 = b[7];
  constant_wire_value_0 constant_wire_value_0_constant_wire_0(a_0, b_0, constant_wire_0);
  fa_cla fa_cla_h_u_pg_rca8_fa0_y0(a_0, b_0, constant_wire_0, h_u_pg_rca8_fa0_y0, h_u_pg_rca8_fa0_y1, h_u_pg_rca8_fa0_y2);
  and_gate and_gate_h_u_pg_rca8_and0_y0(constant_wire_0, h_u_pg_rca8_fa0_y0, h_u_pg_rca8_and0_y0);
  or_gate or_gate_h_u_pg_rca8_or0_y0(h_u_pg_rca8_and0_y0, h_u_pg_rca8_fa0_y1, h_u_pg_rca8_or0_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa1_y0(a_1, b_1, h_u_pg_rca8_or0_y0, h_u_pg_rca8_fa1_y0, h_u_pg_rca8_fa1_y1, h_u_pg_rca8_fa1_y2);
  and_gate and_gate_h_u_pg_rca8_and1_y0(h_u_pg_rca8_or0_y0, h_u_pg_rca8_fa1_y0, h_u_pg_rca8_and1_y0);
  or_gate or_gate_h_u_pg_rca8_or1_y0(h_u_pg_rca8_and1_y0, h_u_pg_rca8_fa1_y1, h_u_pg_rca8_or1_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa2_y0(a_2, b_2, h_u_pg_rca8_or1_y0, h_u_pg_rca8_fa2_y0, h_u_pg_rca8_fa2_y1, h_u_pg_rca8_fa2_y2);
  and_gate and_gate_h_u_pg_rca8_and2_y0(h_u_pg_rca8_or1_y0, h_u_pg_rca8_fa2_y0, h_u_pg_rca8_and2_y0);
  or_gate or_gate_h_u_pg_rca8_or2_y0(h_u_pg_rca8_and2_y0, h_u_pg_rca8_fa2_y1, h_u_pg_rca8_or2_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa3_y0(a_3, b_3, h_u_pg_rca8_or2_y0, h_u_pg_rca8_fa3_y0, h_u_pg_rca8_fa3_y1, h_u_pg_rca8_fa3_y2);
  and_gate and_gate_h_u_pg_rca8_and3_y0(h_u_pg_rca8_or2_y0, h_u_pg_rca8_fa3_y0, h_u_pg_rca8_and3_y0);
  or_gate or_gate_h_u_pg_rca8_or3_y0(h_u_pg_rca8_and3_y0, h_u_pg_rca8_fa3_y1, h_u_pg_rca8_or3_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa4_y0(a_4, b_4, h_u_pg_rca8_or3_y0, h_u_pg_rca8_fa4_y0, h_u_pg_rca8_fa4_y1, h_u_pg_rca8_fa4_y2);
  and_gate and_gate_h_u_pg_rca8_and4_y0(h_u_pg_rca8_or3_y0, h_u_pg_rca8_fa4_y0, h_u_pg_rca8_and4_y0);
  or_gate or_gate_h_u_pg_rca8_or4_y0(h_u_pg_rca8_and4_y0, h_u_pg_rca8_fa4_y1, h_u_pg_rca8_or4_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa5_y0(a_5, b_5, h_u_pg_rca8_or4_y0, h_u_pg_rca8_fa5_y0, h_u_pg_rca8_fa5_y1, h_u_pg_rca8_fa5_y2);
  and_gate and_gate_h_u_pg_rca8_and5_y0(h_u_pg_rca8_or4_y0, h_u_pg_rca8_fa5_y0, h_u_pg_rca8_and5_y0);
  or_gate or_gate_h_u_pg_rca8_or5_y0(h_u_pg_rca8_and5_y0, h_u_pg_rca8_fa5_y1, h_u_pg_rca8_or5_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa6_y0(a_6, b_6, h_u_pg_rca8_or5_y0, h_u_pg_rca8_fa6_y0, h_u_pg_rca8_fa6_y1, h_u_pg_rca8_fa6_y2);
  and_gate and_gate_h_u_pg_rca8_and6_y0(h_u_pg_rca8_or5_y0, h_u_pg_rca8_fa6_y0, h_u_pg_rca8_and6_y0);
  or_gate or_gate_h_u_pg_rca8_or6_y0(h_u_pg_rca8_and6_y0, h_u_pg_rca8_fa6_y1, h_u_pg_rca8_or6_y0);
  fa_cla fa_cla_h_u_pg_rca8_fa7_y0(a_7, b_7, h_u_pg_rca8_or6_y0, h_u_pg_rca8_fa7_y0, h_u_pg_rca8_fa7_y1, h_u_pg_rca8_fa7_y2);
  and_gate and_gate_h_u_pg_rca8_and7_y0(h_u_pg_rca8_or6_y0, h_u_pg_rca8_fa7_y0, h_u_pg_rca8_and7_y0);
  or_gate or_gate_h_u_pg_rca8_or7_y0(h_u_pg_rca8_and7_y0, h_u_pg_rca8_fa7_y1, h_u_pg_rca8_or7_y0);

  assign out[0] = h_u_pg_rca8_fa0_y2;
  assign out[1] = h_u_pg_rca8_fa1_y2;
  assign out[2] = h_u_pg_rca8_fa2_y2;
  assign out[3] = h_u_pg_rca8_fa3_y2;
  assign out[4] = h_u_pg_rca8_fa4_y2;
  assign out[5] = h_u_pg_rca8_fa5_y2;
  assign out[6] = h_u_pg_rca8_fa6_y2;
  assign out[7] = h_u_pg_rca8_fa7_y2;
  assign out[8] = h_u_pg_rca8_or7_y0;
endmodule