module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
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