module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module xnor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a ^ _b);
endmodule

module nor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a | _b);
endmodule

module or_gate(input _a, input _b, output _y0);
  assign _y0 = _a | _b;
endmodule

module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
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

module pg_logic(input a, input b, output pg_logic_y0, output pg_logic_y1, output pg_logic_y2);
  wire pg_logic_a;
  wire pg_logic_b;

  assign pg_logic_a = a;
  assign pg_logic_b = b;

  or_gate or_gate_pg_logic_y0(pg_logic_a, pg_logic_b, pg_logic_y0);
  and_gate and_gate_pg_logic_y1(pg_logic_a, pg_logic_b, pg_logic_y1);
  xor_gate xor_gate_pg_logic_y2(pg_logic_a, pg_logic_b, pg_logic_y2);
endmodule

module h_u_cla4(input [3:0] a, input [3:0] b, output [4:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire constant_wire_0;
  wire h_u_cla4_pg_logic0_y0;
  wire h_u_cla4_pg_logic0_y1;
  wire h_u_cla4_pg_logic0_y2;
  wire h_u_cla4_xor0_y0;
  wire h_u_cla4_and0_y0;
  wire h_u_cla4_or0_y0;
  wire h_u_cla4_pg_logic1_y0;
  wire h_u_cla4_pg_logic1_y1;
  wire h_u_cla4_pg_logic1_y2;
  wire h_u_cla4_xor1_y0;
  wire h_u_cla4_and1_y0;
  wire h_u_cla4_and2_y0;
  wire h_u_cla4_and3_y0;
  wire h_u_cla4_and4_y0;
  wire h_u_cla4_or1_y0;
  wire h_u_cla4_or2_y0;
  wire h_u_cla4_pg_logic2_y0;
  wire h_u_cla4_pg_logic2_y1;
  wire h_u_cla4_pg_logic2_y2;
  wire h_u_cla4_xor2_y0;
  wire h_u_cla4_and5_y0;
  wire h_u_cla4_and6_y0;
  wire h_u_cla4_and7_y0;
  wire h_u_cla4_and8_y0;
  wire h_u_cla4_and9_y0;
  wire h_u_cla4_and10_y0;
  wire h_u_cla4_and11_y0;
  wire h_u_cla4_and12_y0;
  wire h_u_cla4_and13_y0;
  wire h_u_cla4_or3_y0;
  wire h_u_cla4_or4_y0;
  wire h_u_cla4_or5_y0;
  wire h_u_cla4_pg_logic3_y0;
  wire h_u_cla4_pg_logic3_y1;
  wire h_u_cla4_pg_logic3_y2;
  wire h_u_cla4_xor3_y0;
  wire h_u_cla4_and14_y0;
  wire h_u_cla4_and15_y0;
  wire h_u_cla4_and16_y0;
  wire h_u_cla4_and17_y0;
  wire h_u_cla4_and18_y0;
  wire h_u_cla4_and19_y0;
  wire h_u_cla4_and20_y0;
  wire h_u_cla4_and21_y0;
  wire h_u_cla4_and22_y0;
  wire h_u_cla4_and23_y0;
  wire h_u_cla4_and24_y0;
  wire h_u_cla4_and25_y0;
  wire h_u_cla4_and26_y0;
  wire h_u_cla4_and27_y0;
  wire h_u_cla4_and28_y0;
  wire h_u_cla4_and29_y0;
  wire h_u_cla4_or6_y0;
  wire h_u_cla4_or7_y0;
  wire h_u_cla4_or8_y0;
  wire h_u_cla4_or9_y0;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  constant_wire_value_0 constant_wire_value_0_constant_wire_0(a_0, b_0, constant_wire_0);
  pg_logic pg_logic_h_u_cla4_pg_logic0_y0(a_0, b_0, h_u_cla4_pg_logic0_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_pg_logic0_y2);
  xor_gate xor_gate_h_u_cla4_xor0_y0(h_u_cla4_pg_logic0_y2, constant_wire_0, h_u_cla4_xor0_y0);
  and_gate and_gate_h_u_cla4_and0_y0(h_u_cla4_pg_logic0_y0, constant_wire_0, h_u_cla4_and0_y0);
  or_gate or_gate_h_u_cla4_or0_y0(h_u_cla4_pg_logic0_y1, h_u_cla4_and0_y0, h_u_cla4_or0_y0);
  pg_logic pg_logic_h_u_cla4_pg_logic1_y0(a_1, b_1, h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic1_y1, h_u_cla4_pg_logic1_y2);
  xor_gate xor_gate_h_u_cla4_xor1_y0(h_u_cla4_pg_logic1_y2, h_u_cla4_or0_y0, h_u_cla4_xor1_y0);
  and_gate and_gate_h_u_cla4_and1_y0(h_u_cla4_pg_logic0_y0, constant_wire_0, h_u_cla4_and1_y0);
  and_gate and_gate_h_u_cla4_and2_y0(h_u_cla4_pg_logic1_y0, constant_wire_0, h_u_cla4_and2_y0);
  and_gate and_gate_h_u_cla4_and3_y0(h_u_cla4_and2_y0, h_u_cla4_and1_y0, h_u_cla4_and3_y0);
  and_gate and_gate_h_u_cla4_and4_y0(h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_and4_y0);
  or_gate or_gate_h_u_cla4_or1_y0(h_u_cla4_and4_y0, h_u_cla4_and3_y0, h_u_cla4_or1_y0);
  or_gate or_gate_h_u_cla4_or2_y0(h_u_cla4_pg_logic1_y1, h_u_cla4_or1_y0, h_u_cla4_or2_y0);
  pg_logic pg_logic_h_u_cla4_pg_logic2_y0(a_2, b_2, h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic2_y1, h_u_cla4_pg_logic2_y2);
  xor_gate xor_gate_h_u_cla4_xor2_y0(h_u_cla4_pg_logic2_y2, h_u_cla4_or2_y0, h_u_cla4_xor2_y0);
  and_gate and_gate_h_u_cla4_and5_y0(h_u_cla4_pg_logic0_y0, constant_wire_0, h_u_cla4_and5_y0);
  and_gate and_gate_h_u_cla4_and6_y0(h_u_cla4_pg_logic1_y0, constant_wire_0, h_u_cla4_and6_y0);
  and_gate and_gate_h_u_cla4_and7_y0(h_u_cla4_and6_y0, h_u_cla4_and5_y0, h_u_cla4_and7_y0);
  and_gate and_gate_h_u_cla4_and8_y0(h_u_cla4_pg_logic2_y0, constant_wire_0, h_u_cla4_and8_y0);
  and_gate and_gate_h_u_cla4_and9_y0(h_u_cla4_and8_y0, h_u_cla4_and7_y0, h_u_cla4_and9_y0);
  and_gate and_gate_h_u_cla4_and10_y0(h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_and10_y0);
  and_gate and_gate_h_u_cla4_and11_y0(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_and11_y0);
  and_gate and_gate_h_u_cla4_and12_y0(h_u_cla4_and11_y0, h_u_cla4_and10_y0, h_u_cla4_and12_y0);
  and_gate and_gate_h_u_cla4_and13_y0(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic1_y1, h_u_cla4_and13_y0);
  or_gate or_gate_h_u_cla4_or3_y0(h_u_cla4_and13_y0, h_u_cla4_and9_y0, h_u_cla4_or3_y0);
  or_gate or_gate_h_u_cla4_or4_y0(h_u_cla4_or3_y0, h_u_cla4_and12_y0, h_u_cla4_or4_y0);
  or_gate or_gate_h_u_cla4_or5_y0(h_u_cla4_pg_logic2_y1, h_u_cla4_or4_y0, h_u_cla4_or5_y0);
  pg_logic pg_logic_h_u_cla4_pg_logic3_y0(a_3, b_3, h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic3_y1, h_u_cla4_pg_logic3_y2);
  xor_gate xor_gate_h_u_cla4_xor3_y0(h_u_cla4_pg_logic3_y2, h_u_cla4_or5_y0, h_u_cla4_xor3_y0);
  and_gate and_gate_h_u_cla4_and14_y0(h_u_cla4_pg_logic0_y0, constant_wire_0, h_u_cla4_and14_y0);
  and_gate and_gate_h_u_cla4_and15_y0(h_u_cla4_pg_logic1_y0, constant_wire_0, h_u_cla4_and15_y0);
  and_gate and_gate_h_u_cla4_and16_y0(h_u_cla4_and15_y0, h_u_cla4_and14_y0, h_u_cla4_and16_y0);
  and_gate and_gate_h_u_cla4_and17_y0(h_u_cla4_pg_logic2_y0, constant_wire_0, h_u_cla4_and17_y0);
  and_gate and_gate_h_u_cla4_and18_y0(h_u_cla4_and17_y0, h_u_cla4_and16_y0, h_u_cla4_and18_y0);
  and_gate and_gate_h_u_cla4_and19_y0(h_u_cla4_pg_logic3_y0, constant_wire_0, h_u_cla4_and19_y0);
  and_gate and_gate_h_u_cla4_and20_y0(h_u_cla4_and19_y0, h_u_cla4_and18_y0, h_u_cla4_and20_y0);
  and_gate and_gate_h_u_cla4_and21_y0(h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_and21_y0);
  and_gate and_gate_h_u_cla4_and22_y0(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_and22_y0);
  and_gate and_gate_h_u_cla4_and23_y0(h_u_cla4_and22_y0, h_u_cla4_and21_y0, h_u_cla4_and23_y0);
  and_gate and_gate_h_u_cla4_and24_y0(h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic0_y1, h_u_cla4_and24_y0);
  and_gate and_gate_h_u_cla4_and25_y0(h_u_cla4_and24_y0, h_u_cla4_and23_y0, h_u_cla4_and25_y0);
  and_gate and_gate_h_u_cla4_and26_y0(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic1_y1, h_u_cla4_and26_y0);
  and_gate and_gate_h_u_cla4_and27_y0(h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic1_y1, h_u_cla4_and27_y0);
  and_gate and_gate_h_u_cla4_and28_y0(h_u_cla4_and27_y0, h_u_cla4_and26_y0, h_u_cla4_and28_y0);
  and_gate and_gate_h_u_cla4_and29_y0(h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic2_y1, h_u_cla4_and29_y0);
  or_gate or_gate_h_u_cla4_or6_y0(h_u_cla4_and29_y0, h_u_cla4_and20_y0, h_u_cla4_or6_y0);
  or_gate or_gate_h_u_cla4_or7_y0(h_u_cla4_or6_y0, h_u_cla4_and25_y0, h_u_cla4_or7_y0);
  or_gate or_gate_h_u_cla4_or8_y0(h_u_cla4_or7_y0, h_u_cla4_and28_y0, h_u_cla4_or8_y0);
  or_gate or_gate_h_u_cla4_or9_y0(h_u_cla4_pg_logic3_y1, h_u_cla4_or8_y0, h_u_cla4_or9_y0);

  assign out[0] = h_u_cla4_xor0_y0;
  assign out[1] = h_u_cla4_xor1_y0;
  assign out[2] = h_u_cla4_xor2_y0;
  assign out[3] = h_u_cla4_xor3_y0;
  assign out[4] = h_u_cla4_or9_y0;
endmodule