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

module u_rca4(input [3:0] a, input [3:0] b, output [4:0] u_rca4_out);
  wire [0:0] u_rca4_ha_xor0;
  wire [0:0] u_rca4_ha_and0;
  wire [0:0] u_rca4_fa1_xor1;
  wire [0:0] u_rca4_fa1_or0;
  wire [0:0] u_rca4_fa2_xor1;
  wire [0:0] u_rca4_fa2_or0;
  wire [0:0] u_rca4_fa3_xor1;
  wire [0:0] u_rca4_fa3_or0;

  ha ha_u_rca4_ha_out(.a(a[0]), .b(b[0]), .ha_xor0(u_rca4_ha_xor0), .ha_and0(u_rca4_ha_and0));
  fa fa_u_rca4_fa1_out(.a(a[1]), .b(b[1]), .cin(u_rca4_ha_and0[0]), .fa_xor1(u_rca4_fa1_xor1), .fa_or0(u_rca4_fa1_or0));
  fa fa_u_rca4_fa2_out(.a(a[2]), .b(b[2]), .cin(u_rca4_fa1_or0[0]), .fa_xor1(u_rca4_fa2_xor1), .fa_or0(u_rca4_fa2_or0));
  fa fa_u_rca4_fa3_out(.a(a[3]), .b(b[3]), .cin(u_rca4_fa2_or0[0]), .fa_xor1(u_rca4_fa3_xor1), .fa_or0(u_rca4_fa3_or0));

  assign u_rca4_out[0] = u_rca4_ha_xor0[0];
  assign u_rca4_out[1] = u_rca4_fa1_xor1[0];
  assign u_rca4_out[2] = u_rca4_fa2_xor1[0];
  assign u_rca4_out[3] = u_rca4_fa3_xor1[0];
  assign u_rca4_out[4] = u_rca4_fa3_or0[0];
endmodule

module u_csamul_rca4(input [3:0] a, input [3:0] b, output [7:0] u_csamul_rca4_out);
  wire [0:0] u_csamul_rca4_and0_0;
  wire [0:0] u_csamul_rca4_and1_0;
  wire [0:0] u_csamul_rca4_and2_0;
  wire [0:0] u_csamul_rca4_and3_0;
  wire [0:0] u_csamul_rca4_and0_1;
  wire [0:0] u_csamul_rca4_ha0_1_xor0;
  wire [0:0] u_csamul_rca4_ha0_1_and0;
  wire [0:0] u_csamul_rca4_and1_1;
  wire [0:0] u_csamul_rca4_ha1_1_xor0;
  wire [0:0] u_csamul_rca4_ha1_1_and0;
  wire [0:0] u_csamul_rca4_and2_1;
  wire [0:0] u_csamul_rca4_ha2_1_xor0;
  wire [0:0] u_csamul_rca4_ha2_1_and0;
  wire [0:0] u_csamul_rca4_and3_1;
  wire [0:0] u_csamul_rca4_and0_2;
  wire [0:0] u_csamul_rca4_fa0_2_xor1;
  wire [0:0] u_csamul_rca4_fa0_2_or0;
  wire [0:0] u_csamul_rca4_and1_2;
  wire [0:0] u_csamul_rca4_fa1_2_xor1;
  wire [0:0] u_csamul_rca4_fa1_2_or0;
  wire [0:0] u_csamul_rca4_and2_2;
  wire [0:0] u_csamul_rca4_fa2_2_xor1;
  wire [0:0] u_csamul_rca4_fa2_2_or0;
  wire [0:0] u_csamul_rca4_and3_2;
  wire [0:0] u_csamul_rca4_and0_3;
  wire [0:0] u_csamul_rca4_fa0_3_xor1;
  wire [0:0] u_csamul_rca4_fa0_3_or0;
  wire [0:0] u_csamul_rca4_and1_3;
  wire [0:0] u_csamul_rca4_fa1_3_xor1;
  wire [0:0] u_csamul_rca4_fa1_3_or0;
  wire [0:0] u_csamul_rca4_and2_3;
  wire [0:0] u_csamul_rca4_fa2_3_xor1;
  wire [0:0] u_csamul_rca4_fa2_3_or0;
  wire [0:0] u_csamul_rca4_and3_3;
  wire [3:0] u_csamul_rca4_u_rca4_a;
  wire [3:0] u_csamul_rca4_u_rca4_b;
  wire [4:0] u_csamul_rca4_u_rca4_out;

  and_gate and_gate_u_csamul_rca4_and0_0(.a(a[0]), .b(b[0]), .out(u_csamul_rca4_and0_0));
  and_gate and_gate_u_csamul_rca4_and1_0(.a(a[1]), .b(b[0]), .out(u_csamul_rca4_and1_0));
  and_gate and_gate_u_csamul_rca4_and2_0(.a(a[2]), .b(b[0]), .out(u_csamul_rca4_and2_0));
  and_gate and_gate_u_csamul_rca4_and3_0(.a(a[3]), .b(b[0]), .out(u_csamul_rca4_and3_0));
  and_gate and_gate_u_csamul_rca4_and0_1(.a(a[0]), .b(b[1]), .out(u_csamul_rca4_and0_1));
  ha ha_u_csamul_rca4_ha0_1_out(.a(u_csamul_rca4_and0_1[0]), .b(u_csamul_rca4_and1_0[0]), .ha_xor0(u_csamul_rca4_ha0_1_xor0), .ha_and0(u_csamul_rca4_ha0_1_and0));
  and_gate and_gate_u_csamul_rca4_and1_1(.a(a[1]), .b(b[1]), .out(u_csamul_rca4_and1_1));
  ha ha_u_csamul_rca4_ha1_1_out(.a(u_csamul_rca4_and1_1[0]), .b(u_csamul_rca4_and2_0[0]), .ha_xor0(u_csamul_rca4_ha1_1_xor0), .ha_and0(u_csamul_rca4_ha1_1_and0));
  and_gate and_gate_u_csamul_rca4_and2_1(.a(a[2]), .b(b[1]), .out(u_csamul_rca4_and2_1));
  ha ha_u_csamul_rca4_ha2_1_out(.a(u_csamul_rca4_and2_1[0]), .b(u_csamul_rca4_and3_0[0]), .ha_xor0(u_csamul_rca4_ha2_1_xor0), .ha_and0(u_csamul_rca4_ha2_1_and0));
  and_gate and_gate_u_csamul_rca4_and3_1(.a(a[3]), .b(b[1]), .out(u_csamul_rca4_and3_1));
  and_gate and_gate_u_csamul_rca4_and0_2(.a(a[0]), .b(b[2]), .out(u_csamul_rca4_and0_2));
  fa fa_u_csamul_rca4_fa0_2_out(.a(u_csamul_rca4_and0_2[0]), .b(u_csamul_rca4_ha1_1_xor0[0]), .cin(u_csamul_rca4_ha0_1_and0[0]), .fa_xor1(u_csamul_rca4_fa0_2_xor1), .fa_or0(u_csamul_rca4_fa0_2_or0));
  and_gate and_gate_u_csamul_rca4_and1_2(.a(a[1]), .b(b[2]), .out(u_csamul_rca4_and1_2));
  fa fa_u_csamul_rca4_fa1_2_out(.a(u_csamul_rca4_and1_2[0]), .b(u_csamul_rca4_ha2_1_xor0[0]), .cin(u_csamul_rca4_ha1_1_and0[0]), .fa_xor1(u_csamul_rca4_fa1_2_xor1), .fa_or0(u_csamul_rca4_fa1_2_or0));
  and_gate and_gate_u_csamul_rca4_and2_2(.a(a[2]), .b(b[2]), .out(u_csamul_rca4_and2_2));
  fa fa_u_csamul_rca4_fa2_2_out(.a(u_csamul_rca4_and2_2[0]), .b(u_csamul_rca4_and3_1[0]), .cin(u_csamul_rca4_ha2_1_and0[0]), .fa_xor1(u_csamul_rca4_fa2_2_xor1), .fa_or0(u_csamul_rca4_fa2_2_or0));
  and_gate and_gate_u_csamul_rca4_and3_2(.a(a[3]), .b(b[2]), .out(u_csamul_rca4_and3_2));
  and_gate and_gate_u_csamul_rca4_and0_3(.a(a[0]), .b(b[3]), .out(u_csamul_rca4_and0_3));
  fa fa_u_csamul_rca4_fa0_3_out(.a(u_csamul_rca4_and0_3[0]), .b(u_csamul_rca4_fa1_2_xor1[0]), .cin(u_csamul_rca4_fa0_2_or0[0]), .fa_xor1(u_csamul_rca4_fa0_3_xor1), .fa_or0(u_csamul_rca4_fa0_3_or0));
  and_gate and_gate_u_csamul_rca4_and1_3(.a(a[1]), .b(b[3]), .out(u_csamul_rca4_and1_3));
  fa fa_u_csamul_rca4_fa1_3_out(.a(u_csamul_rca4_and1_3[0]), .b(u_csamul_rca4_fa2_2_xor1[0]), .cin(u_csamul_rca4_fa1_2_or0[0]), .fa_xor1(u_csamul_rca4_fa1_3_xor1), .fa_or0(u_csamul_rca4_fa1_3_or0));
  and_gate and_gate_u_csamul_rca4_and2_3(.a(a[2]), .b(b[3]), .out(u_csamul_rca4_and2_3));
  fa fa_u_csamul_rca4_fa2_3_out(.a(u_csamul_rca4_and2_3[0]), .b(u_csamul_rca4_and3_2[0]), .cin(u_csamul_rca4_fa2_2_or0[0]), .fa_xor1(u_csamul_rca4_fa2_3_xor1), .fa_or0(u_csamul_rca4_fa2_3_or0));
  and_gate and_gate_u_csamul_rca4_and3_3(.a(a[3]), .b(b[3]), .out(u_csamul_rca4_and3_3));
  assign u_csamul_rca4_u_rca4_a[0] = u_csamul_rca4_fa1_3_xor1[0];
  assign u_csamul_rca4_u_rca4_a[1] = u_csamul_rca4_fa2_3_xor1[0];
  assign u_csamul_rca4_u_rca4_a[2] = u_csamul_rca4_and3_3[0];
  assign u_csamul_rca4_u_rca4_a[3] = 1'b0;
  assign u_csamul_rca4_u_rca4_b[0] = u_csamul_rca4_fa0_3_or0[0];
  assign u_csamul_rca4_u_rca4_b[1] = u_csamul_rca4_fa1_3_or0[0];
  assign u_csamul_rca4_u_rca4_b[2] = u_csamul_rca4_fa2_3_or0[0];
  assign u_csamul_rca4_u_rca4_b[3] = 1'b0;
  u_rca4 u_rca4_u_csamul_rca4_u_rca4_out(.a(u_csamul_rca4_u_rca4_a), .b(u_csamul_rca4_u_rca4_b), .u_rca4_out(u_csamul_rca4_u_rca4_out));

  assign u_csamul_rca4_out[0] = u_csamul_rca4_and0_0[0];
  assign u_csamul_rca4_out[1] = u_csamul_rca4_ha0_1_xor0[0];
  assign u_csamul_rca4_out[2] = u_csamul_rca4_fa0_2_xor1[0];
  assign u_csamul_rca4_out[3] = u_csamul_rca4_fa0_3_xor1[0];
  assign u_csamul_rca4_out[4] = u_csamul_rca4_u_rca4_out[0];
  assign u_csamul_rca4_out[5] = u_csamul_rca4_u_rca4_out[1];
  assign u_csamul_rca4_out[6] = u_csamul_rca4_u_rca4_out[2];
  assign u_csamul_rca4_out[7] = u_csamul_rca4_u_rca4_out[3];
endmodule