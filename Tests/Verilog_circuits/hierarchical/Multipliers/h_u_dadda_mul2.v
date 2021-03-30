module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module ha(input a, input b, output ha_y0, output ha_y1);
  xor_gate xor_gate_ha_y0(a, b, ha_y0);
  and_gate and_gate_ha_y1(a, b, ha_y1);
endmodule

module h_u_dadda_mul2(input [1:0] a, input [1:0] b, output [3:0] out);
  wire a_0;
  wire a_1;
  wire b_0;
  wire b_1;
  wire h_u_dadda_mul2_and_0_0_y0;
  wire h_u_dadda_mul2_and_1_0_y0;
  wire h_u_dadda_mul2_and_0_1_y0;
  wire h_u_dadda_mul2_ha0_y0;
  wire h_u_dadda_mul2_ha0_y1;
  wire h_u_dadda_mul2_and_1_1_y0;
  wire h_u_dadda_mul2_ha1_y0;
  wire h_u_dadda_mul2_ha1_y1;

  assign a_0 = a[0];
  assign a_1 = a[1];
  assign b_0 = b[0];
  assign b_1 = b[1];
  and_gate and_gate_h_u_dadda_mul2_and_0_0_y0(a_0, b_0, h_u_dadda_mul2_and_0_0_y0);
  and_gate and_gate_h_u_dadda_mul2_and_1_0_y0(a_1, b_0, h_u_dadda_mul2_and_1_0_y0);
  and_gate and_gate_h_u_dadda_mul2_and_0_1_y0(a_0, b_1, h_u_dadda_mul2_and_0_1_y0);
  ha ha_h_u_dadda_mul2_ha0_y1(h_u_dadda_mul2_and_1_0_y0, h_u_dadda_mul2_and_0_1_y0, h_u_dadda_mul2_ha0_y0, h_u_dadda_mul2_ha0_y1);
  and_gate and_gate_h_u_dadda_mul2_and_1_1_y0(a_1, b_1, h_u_dadda_mul2_and_1_1_y0);
  ha ha_h_u_dadda_mul2_ha1_y1(h_u_dadda_mul2_ha0_y1, h_u_dadda_mul2_and_1_1_y0, h_u_dadda_mul2_ha1_y0, h_u_dadda_mul2_ha1_y1);

  assign out[0] = h_u_dadda_mul2_and_0_0_y0;
  assign out[1] = h_u_dadda_mul2_ha0_y0;
  assign out[2] = h_u_dadda_mul2_ha1_y0;
  assign out[3] = h_u_dadda_mul2_ha1_y1;
endmodule