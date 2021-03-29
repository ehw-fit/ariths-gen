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
  wire constant_wire_value_0_y0;
  wire constant_wire_value_0_y1;

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

module h_s_pg_rca4(input [3:0] a, input [3:0] b, output [4:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire constant_wire_0;
  wire h_s_pg_rca4_fa0_y0;
  wire h_s_pg_rca4_fa0_y1;
  wire h_s_pg_rca4_fa0_y2;
  wire h_s_pg_rca4_and0_y0;
  wire h_s_pg_rca4_or0_y0;
  wire h_s_pg_rca4_fa1_y0;
  wire h_s_pg_rca4_fa1_y1;
  wire h_s_pg_rca4_fa1_y2;
  wire h_s_pg_rca4_and1_y0;
  wire h_s_pg_rca4_or1_y0;
  wire h_s_pg_rca4_fa2_y0;
  wire h_s_pg_rca4_fa2_y1;
  wire h_s_pg_rca4_fa2_y2;
  wire h_s_pg_rca4_and2_y0;
  wire h_s_pg_rca4_or2_y0;
  wire h_s_pg_rca4_fa3_y0;
  wire h_s_pg_rca4_fa3_y1;
  wire h_s_pg_rca4_fa3_y2;
  wire h_s_pg_rca4_and3_y0;
  wire h_s_pg_rca4_or3_y0;
  wire h_s_pg_rca4_xor0_y0;
  wire h_s_pg_rca4_xor1_y0;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  constant_wire_value_0 constant_wire_value_0_constant_wire_0(a_0, b_0, constant_wire_0);
  fa_cla fa_cla_h_s_pg_rca4_fa0_y0(a_0, b_0, constant_wire_0, h_s_pg_rca4_fa0_y0, h_s_pg_rca4_fa0_y1, h_s_pg_rca4_fa0_y2);
  and_gate and_gate_h_s_pg_rca4_and0_y0(constant_wire_0, h_s_pg_rca4_fa0_y0, h_s_pg_rca4_and0_y0);
  or_gate or_gate_h_s_pg_rca4_or0_y0(h_s_pg_rca4_and0_y0, h_s_pg_rca4_fa0_y1, h_s_pg_rca4_or0_y0);
  fa_cla fa_cla_h_s_pg_rca4_fa1_y0(a_1, b_1, h_s_pg_rca4_or0_y0, h_s_pg_rca4_fa1_y0, h_s_pg_rca4_fa1_y1, h_s_pg_rca4_fa1_y2);
  and_gate and_gate_h_s_pg_rca4_and1_y0(h_s_pg_rca4_or0_y0, h_s_pg_rca4_fa1_y0, h_s_pg_rca4_and1_y0);
  or_gate or_gate_h_s_pg_rca4_or1_y0(h_s_pg_rca4_and1_y0, h_s_pg_rca4_fa1_y1, h_s_pg_rca4_or1_y0);
  fa_cla fa_cla_h_s_pg_rca4_fa2_y0(a_2, b_2, h_s_pg_rca4_or1_y0, h_s_pg_rca4_fa2_y0, h_s_pg_rca4_fa2_y1, h_s_pg_rca4_fa2_y2);
  and_gate and_gate_h_s_pg_rca4_and2_y0(h_s_pg_rca4_or1_y0, h_s_pg_rca4_fa2_y0, h_s_pg_rca4_and2_y0);
  or_gate or_gate_h_s_pg_rca4_or2_y0(h_s_pg_rca4_and2_y0, h_s_pg_rca4_fa2_y1, h_s_pg_rca4_or2_y0);
  fa_cla fa_cla_h_s_pg_rca4_fa3_y0(a_3, b_3, h_s_pg_rca4_or2_y0, h_s_pg_rca4_fa3_y0, h_s_pg_rca4_fa3_y1, h_s_pg_rca4_fa3_y2);
  and_gate and_gate_h_s_pg_rca4_and3_y0(h_s_pg_rca4_or2_y0, h_s_pg_rca4_fa3_y0, h_s_pg_rca4_and3_y0);
  or_gate or_gate_h_s_pg_rca4_or3_y0(h_s_pg_rca4_and3_y0, h_s_pg_rca4_fa3_y1, h_s_pg_rca4_or3_y0);
  xor_gate xor_gate_h_s_pg_rca4_xor0_y0(a_3, b_3, h_s_pg_rca4_xor0_y0);
  xor_gate xor_gate_h_s_pg_rca4_xor1_y0(h_s_pg_rca4_xor0_y0, h_s_pg_rca4_or3_y0, h_s_pg_rca4_xor1_y0);

  assign out[0] = h_s_pg_rca4_fa0_y2;
  assign out[1] = h_s_pg_rca4_fa1_y2;
  assign out[2] = h_s_pg_rca4_fa2_y2;
  assign out[3] = h_s_pg_rca4_fa3_y2;
  assign out[4] = h_s_pg_rca4_xor1_y0;
endmodule