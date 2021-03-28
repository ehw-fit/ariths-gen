module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module or_gate(input _a, input _b, output _y0);
  assign _y0 = _a | _b;
endmodule

module xnor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a ^ _b);
endmodule

module nor_gate(input _a, input _b, output _y0);
  assign _y0 = ~(_a | _b);
endmodule

module ha(input a, input b, output ha_y0, output ha_y1);
  wire ha_a;
  wire ha_b;

  assign ha_a = a;
  assign ha_b = b;

  xor_gate xor_gate_ha_y0(ha_a, ha_b, ha_y0);
  and_gate and_gate_ha_y1(ha_a, ha_b, ha_y1);
endmodule

module fa(input a, input b, input cin, output fa_y2, output fa_y4);
  wire fa_a;
  wire fa_b;
  wire fa_cin;

  assign fa_a = a;
  assign fa_b = b;
  assign fa_cin = cin;

  xor_gate xor_gate_fa_y0(fa_a, fa_b, fa_y0);
  and_gate and_gate_fa_y1(fa_a, fa_b, fa_y1);
  xor_gate xor_gate_fa_y2(fa_y0, fa_cin, fa_y2);
  and_gate and_gate_fa_y3(fa_y0, fa_cin, fa_y3);
  or_gate or_gate_fa_y4(fa_y1, fa_y3, fa_y4);
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

module u_pg_rca(input [5:0] a, input [5:0] b, output [6:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire a_4;
  wire a_5;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire b_4;
  wire b_5;
  wire constant_wire_0;
  wire u_pg_rca_fa0_y0;
  wire u_pg_rca_fa0_y1;
  wire u_pg_rca_fa0_y2;
  wire u_pg_rca_and0_y0;
  wire u_pg_rca_or0_y0;
  wire u_pg_rca_fa1_y0;
  wire u_pg_rca_fa1_y1;
  wire u_pg_rca_fa1_y2;
  wire u_pg_rca_and1_y0;
  wire u_pg_rca_or1_y0;
  wire u_pg_rca_fa2_y0;
  wire u_pg_rca_fa2_y1;
  wire u_pg_rca_fa2_y2;
  wire u_pg_rca_and2_y0;
  wire u_pg_rca_or2_y0;
  wire u_pg_rca_fa3_y0;
  wire u_pg_rca_fa3_y1;
  wire u_pg_rca_fa3_y2;
  wire u_pg_rca_and3_y0;
  wire u_pg_rca_or3_y0;
  wire u_pg_rca_fa4_y0;
  wire u_pg_rca_fa4_y1;
  wire u_pg_rca_fa4_y2;
  wire u_pg_rca_and4_y0;
  wire u_pg_rca_or4_y0;
  wire u_pg_rca_fa5_y0;
  wire u_pg_rca_fa5_y1;
  wire u_pg_rca_fa5_y2;
  wire u_pg_rca_and5_y0;
  wire u_pg_rca_or5_y0;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign a_4 = a[4];
  assign a_5 = a[5];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  assign b_4 = b[4];
  assign b_5 = b[5];
  constant_wire_value_0 constant_wire_value_0_constant_wire_0(a_0, b_0, constant_wire_0);
  fa_cla fa_cla_u_pg_rca_fa0_y0(a_0, b_0, constant_wire_0, u_pg_rca_fa0_y0, u_pg_rca_fa0_y1, u_pg_rca_fa0_y2);
  and_gate and_gate_u_pg_rca_and0_y0(constant_wire_0, u_pg_rca_fa0_y0, u_pg_rca_and0_y0);
  or_gate or_gate_u_pg_rca_or0_y0(u_pg_rca_and0_y0, u_pg_rca_fa0_y1, u_pg_rca_or0_y0);
  fa_cla fa_cla_u_pg_rca_fa1_y0(a_1, b_1, u_pg_rca_or0_y0, u_pg_rca_fa1_y0, u_pg_rca_fa1_y1, u_pg_rca_fa1_y2);
  and_gate and_gate_u_pg_rca_and1_y0(u_pg_rca_or0_y0, u_pg_rca_fa1_y0, u_pg_rca_and1_y0);
  or_gate or_gate_u_pg_rca_or1_y0(u_pg_rca_and1_y0, u_pg_rca_fa1_y1, u_pg_rca_or1_y0);
  fa_cla fa_cla_u_pg_rca_fa2_y0(a_2, b_2, u_pg_rca_or1_y0, u_pg_rca_fa2_y0, u_pg_rca_fa2_y1, u_pg_rca_fa2_y2);
  and_gate and_gate_u_pg_rca_and2_y0(u_pg_rca_or1_y0, u_pg_rca_fa2_y0, u_pg_rca_and2_y0);
  or_gate or_gate_u_pg_rca_or2_y0(u_pg_rca_and2_y0, u_pg_rca_fa2_y1, u_pg_rca_or2_y0);
  fa_cla fa_cla_u_pg_rca_fa3_y0(a_3, b_3, u_pg_rca_or2_y0, u_pg_rca_fa3_y0, u_pg_rca_fa3_y1, u_pg_rca_fa3_y2);
  and_gate and_gate_u_pg_rca_and3_y0(u_pg_rca_or2_y0, u_pg_rca_fa3_y0, u_pg_rca_and3_y0);
  or_gate or_gate_u_pg_rca_or3_y0(u_pg_rca_and3_y0, u_pg_rca_fa3_y1, u_pg_rca_or3_y0);
  fa_cla fa_cla_u_pg_rca_fa4_y0(a_4, b_4, u_pg_rca_or3_y0, u_pg_rca_fa4_y0, u_pg_rca_fa4_y1, u_pg_rca_fa4_y2);
  and_gate and_gate_u_pg_rca_and4_y0(u_pg_rca_or3_y0, u_pg_rca_fa4_y0, u_pg_rca_and4_y0);
  or_gate or_gate_u_pg_rca_or4_y0(u_pg_rca_and4_y0, u_pg_rca_fa4_y1, u_pg_rca_or4_y0);
  fa_cla fa_cla_u_pg_rca_fa5_y0(a_5, b_5, u_pg_rca_or4_y0, u_pg_rca_fa5_y0, u_pg_rca_fa5_y1, u_pg_rca_fa5_y2);
  and_gate and_gate_u_pg_rca_and5_y0(u_pg_rca_or4_y0, u_pg_rca_fa5_y0, u_pg_rca_and5_y0);
  or_gate or_gate_u_pg_rca_or5_y0(u_pg_rca_and5_y0, u_pg_rca_fa5_y1, u_pg_rca_or5_y0);

  assign out[0] = u_pg_rca_fa0_y2;
  assign out[1] = u_pg_rca_fa1_y2;
  assign out[2] = u_pg_rca_fa2_y2;
  assign out[3] = u_pg_rca_fa3_y2;
  assign out[4] = u_pg_rca_fa4_y2;
  assign out[5] = u_pg_rca_fa5_y2;
  assign out[6] = u_pg_rca_or5_y0;
endmodule

module h_u_wallace_pg_rca4(input [3:0] a, input [3:0] b, output [7:0] out);
  wire a_0;
  wire a_1;
  wire a_2;
  wire a_3;
  wire b_0;
  wire b_1;
  wire b_2;
  wire b_3;
  wire h_u_wallace_pg_rca4_and_2_0_y0;
  wire h_u_wallace_pg_rca4_and_1_1_y0;
  wire h_u_wallace_pg_rca4_ha0_y0;
  wire h_u_wallace_pg_rca4_ha0_y1;
  wire h_u_wallace_pg_rca4_and_3_0_y0;
  wire h_u_wallace_pg_rca4_and_2_1_y0;
  wire h_u_wallace_pg_rca4_fa0_y2;
  wire h_u_wallace_pg_rca4_fa0_y4;
  wire h_u_wallace_pg_rca4_and_3_1_y0;
  wire h_u_wallace_pg_rca4_and_2_2_y0;
  wire h_u_wallace_pg_rca4_fa1_y2;
  wire h_u_wallace_pg_rca4_fa1_y4;
  wire h_u_wallace_pg_rca4_and_1_2_y0;
  wire h_u_wallace_pg_rca4_and_0_3_y0;
  wire h_u_wallace_pg_rca4_ha1_y0;
  wire h_u_wallace_pg_rca4_ha1_y1;
  wire h_u_wallace_pg_rca4_and_1_3_y0;
  wire h_u_wallace_pg_rca4_ha2_y0;
  wire h_u_wallace_pg_rca4_ha2_y1;
  wire h_u_wallace_pg_rca4_and_3_2_y0;
  wire h_u_wallace_pg_rca4_fa2_y2;
  wire h_u_wallace_pg_rca4_fa2_y4;
  wire h_u_wallace_pg_rca4_and_0_0_y0;
  wire h_u_wallace_pg_rca4_and_1_0_y0;
  wire h_u_wallace_pg_rca4_and_0_2_y0;
  wire h_u_wallace_pg_rca4_and_2_3_y0;
  wire h_u_wallace_pg_rca4_and_0_1_y0;
  wire h_u_wallace_pg_rca4_and_3_3_y0;
  wire [5:0] h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a;
  wire [5:0] h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b;
  wire [6:0] h_u_wallace_pg_rca4_u_pg_rca_out;
  wire h_u_wallace_pg_rca4_u_pg_rca_fa0_y2;
  wire h_u_wallace_pg_rca4_u_pg_rca_fa1_y2;
  wire h_u_wallace_pg_rca4_u_pg_rca_fa2_y2;
  wire h_u_wallace_pg_rca4_u_pg_rca_fa3_y2;
  wire h_u_wallace_pg_rca4_u_pg_rca_fa4_y2;
  wire h_u_wallace_pg_rca4_u_pg_rca_fa5_y2;
  wire h_u_wallace_pg_rca4_u_pg_rca_or5_y0;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign a_2 = a[2];
  assign a_3 = a[3];
  assign b_0 = b[0];
  assign b_1 = b[1];
  assign b_2 = b[2];
  assign b_3 = b[3];
  and_gate and_gate_h_u_wallace_pg_rca4_and_2_0_y0(a_2, b_0, h_u_wallace_pg_rca4_and_2_0_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_1_1_y0(a_1, b_1, h_u_wallace_pg_rca4_and_1_1_y0);
  ha ha_h_u_wallace_pg_rca4_ha0_y0(h_u_wallace_pg_rca4_and_2_0_y0, h_u_wallace_pg_rca4_and_1_1_y0, h_u_wallace_pg_rca4_ha0_y0, h_u_wallace_pg_rca4_ha0_y1);
  and_gate and_gate_h_u_wallace_pg_rca4_and_3_0_y0(a_3, b_0, h_u_wallace_pg_rca4_and_3_0_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_2_1_y0(a_2, b_1, h_u_wallace_pg_rca4_and_2_1_y0);
  fa fa_h_u_wallace_pg_rca4_fa0_y2(h_u_wallace_pg_rca4_ha0_y1, h_u_wallace_pg_rca4_and_3_0_y0, h_u_wallace_pg_rca4_and_2_1_y0, h_u_wallace_pg_rca4_fa0_y2, h_u_wallace_pg_rca4_fa0_y4);
  and_gate and_gate_h_u_wallace_pg_rca4_and_3_1_y0(a_3, b_1, h_u_wallace_pg_rca4_and_3_1_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_2_2_y0(a_2, b_2, h_u_wallace_pg_rca4_and_2_2_y0);
  fa fa_h_u_wallace_pg_rca4_fa1_y2(h_u_wallace_pg_rca4_fa0_y4, h_u_wallace_pg_rca4_and_3_1_y0, h_u_wallace_pg_rca4_and_2_2_y0, h_u_wallace_pg_rca4_fa1_y2, h_u_wallace_pg_rca4_fa1_y4);
  and_gate and_gate_h_u_wallace_pg_rca4_and_1_2_y0(a_1, b_2, h_u_wallace_pg_rca4_and_1_2_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_0_3_y0(a_0, b_3, h_u_wallace_pg_rca4_and_0_3_y0);
  ha ha_h_u_wallace_pg_rca4_ha1_y0(h_u_wallace_pg_rca4_and_1_2_y0, h_u_wallace_pg_rca4_and_0_3_y0, h_u_wallace_pg_rca4_ha1_y0, h_u_wallace_pg_rca4_ha1_y1);
  and_gate and_gate_h_u_wallace_pg_rca4_and_1_3_y0(a_1, b_3, h_u_wallace_pg_rca4_and_1_3_y0);
  ha ha_h_u_wallace_pg_rca4_ha2_y0(h_u_wallace_pg_rca4_ha1_y1, h_u_wallace_pg_rca4_and_1_3_y0, h_u_wallace_pg_rca4_ha2_y0, h_u_wallace_pg_rca4_ha2_y1);
  and_gate and_gate_h_u_wallace_pg_rca4_and_3_2_y0(a_3, b_2, h_u_wallace_pg_rca4_and_3_2_y0);
  fa fa_h_u_wallace_pg_rca4_fa2_y2(h_u_wallace_pg_rca4_ha2_y1, h_u_wallace_pg_rca4_fa1_y4, h_u_wallace_pg_rca4_and_3_2_y0, h_u_wallace_pg_rca4_fa2_y2, h_u_wallace_pg_rca4_fa2_y4);
  and_gate and_gate_h_u_wallace_pg_rca4_and_0_0_y0(a_0, b_0, h_u_wallace_pg_rca4_and_0_0_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_1_0_y0(a_1, b_0, h_u_wallace_pg_rca4_and_1_0_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_0_2_y0(a_0, b_2, h_u_wallace_pg_rca4_and_0_2_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_2_3_y0(a_2, b_3, h_u_wallace_pg_rca4_and_2_3_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_0_1_y0(a_0, b_1, h_u_wallace_pg_rca4_and_0_1_y0);
  and_gate and_gate_h_u_wallace_pg_rca4_and_3_3_y0(a_3, b_3, h_u_wallace_pg_rca4_and_3_3_y0);
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a[0] = h_u_wallace_pg_rca4_and_1_0_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a[1] = h_u_wallace_pg_rca4_and_0_2_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a[2] = h_u_wallace_pg_rca4_fa0_y2;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a[3] = h_u_wallace_pg_rca4_fa1_y2;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a[4] = h_u_wallace_pg_rca4_and_2_3_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a[5] = h_u_wallace_pg_rca4_fa2_y4;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b[0] = h_u_wallace_pg_rca4_and_0_1_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b[1] = h_u_wallace_pg_rca4_ha0_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b[2] = h_u_wallace_pg_rca4_ha1_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b[3] = h_u_wallace_pg_rca4_ha2_y0;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b[4] = h_u_wallace_pg_rca4_fa2_y2;
  assign h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b[5] = h_u_wallace_pg_rca4_and_3_3_y0;
  u_pg_rca u_pg_rca_out(h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_a, h_u_wallace_pg_rca4_u_pg_rca_u_pg_rca_b, h_u_wallace_pg_rca4_u_pg_rca_out);
  assign h_u_wallace_pg_rca4_u_pg_rca_fa0_y2 = h_u_wallace_pg_rca4_u_pg_rca_out[0];
  assign h_u_wallace_pg_rca4_u_pg_rca_fa1_y2 = h_u_wallace_pg_rca4_u_pg_rca_out[1];
  assign h_u_wallace_pg_rca4_u_pg_rca_fa2_y2 = h_u_wallace_pg_rca4_u_pg_rca_out[2];
  assign h_u_wallace_pg_rca4_u_pg_rca_fa3_y2 = h_u_wallace_pg_rca4_u_pg_rca_out[3];
  assign h_u_wallace_pg_rca4_u_pg_rca_fa4_y2 = h_u_wallace_pg_rca4_u_pg_rca_out[4];
  assign h_u_wallace_pg_rca4_u_pg_rca_fa5_y2 = h_u_wallace_pg_rca4_u_pg_rca_out[5];
  assign h_u_wallace_pg_rca4_u_pg_rca_or5_y0 = h_u_wallace_pg_rca4_u_pg_rca_out[6];

  assign out[0] = h_u_wallace_pg_rca4_and_0_0_y0;
  assign out[1] = h_u_wallace_pg_rca4_u_pg_rca_fa0_y2;
  assign out[2] = h_u_wallace_pg_rca4_u_pg_rca_fa1_y2;
  assign out[3] = h_u_wallace_pg_rca4_u_pg_rca_fa2_y2;
  assign out[4] = h_u_wallace_pg_rca4_u_pg_rca_fa3_y2;
  assign out[5] = h_u_wallace_pg_rca4_u_pg_rca_fa4_y2;
  assign out[6] = h_u_wallace_pg_rca4_u_pg_rca_fa5_y2;
  assign out[7] = h_u_wallace_pg_rca4_u_pg_rca_or5_y0;
endmodule