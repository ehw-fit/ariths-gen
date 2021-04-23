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

module h_u_pg_rca4(input [3:0] a, input [3:0] b, output [4:0] h_u_pg_rca4_out);
  wire [0:0] h_u_pg_rca4_pg_fa0_xor0;
  wire [0:0] h_u_pg_rca4_pg_fa0_and0;
  wire [0:0] h_u_pg_rca4_pg_fa1_xor0;
  wire [0:0] h_u_pg_rca4_pg_fa1_and0;
  wire [0:0] h_u_pg_rca4_pg_fa1_xor1;
  wire [0:0] h_u_pg_rca4_and1;
  wire [0:0] h_u_pg_rca4_or1;
  wire [0:0] h_u_pg_rca4_pg_fa2_xor0;
  wire [0:0] h_u_pg_rca4_pg_fa2_and0;
  wire [0:0] h_u_pg_rca4_pg_fa2_xor1;
  wire [0:0] h_u_pg_rca4_and2;
  wire [0:0] h_u_pg_rca4_or2;
  wire [0:0] h_u_pg_rca4_pg_fa3_xor0;
  wire [0:0] h_u_pg_rca4_pg_fa3_and0;
  wire [0:0] h_u_pg_rca4_pg_fa3_xor1;
  wire [0:0] h_u_pg_rca4_and3;
  wire [0:0] h_u_pg_rca4_or3;

  pg_fa pg_fa_h_u_pg_rca4_pg_fa0_out(a[0], b[0], 1'b0, h_u_pg_rca4_pg_fa0_xor0, h_u_pg_rca4_pg_fa0_and0);
  pg_fa pg_fa_h_u_pg_rca4_pg_fa1_out(a[1], b[1], h_u_pg_rca4_pg_fa0_and0[0], h_u_pg_rca4_pg_fa1_xor0, h_u_pg_rca4_pg_fa1_and0, h_u_pg_rca4_pg_fa1_xor1);
  and_gate and_gate_h_u_pg_rca4_and1(h_u_pg_rca4_pg_fa0_and0[0], h_u_pg_rca4_pg_fa1_xor0[0], h_u_pg_rca4_and1);
  or_gate or_gate_h_u_pg_rca4_or1(h_u_pg_rca4_and1[0], h_u_pg_rca4_pg_fa1_and0[0], h_u_pg_rca4_or1);
  pg_fa pg_fa_h_u_pg_rca4_pg_fa2_out(a[2], b[2], h_u_pg_rca4_or1[0], h_u_pg_rca4_pg_fa2_xor0, h_u_pg_rca4_pg_fa2_and0, h_u_pg_rca4_pg_fa2_xor1);
  and_gate and_gate_h_u_pg_rca4_and2(h_u_pg_rca4_or1[0], h_u_pg_rca4_pg_fa2_xor0[0], h_u_pg_rca4_and2);
  or_gate or_gate_h_u_pg_rca4_or2(h_u_pg_rca4_and2[0], h_u_pg_rca4_pg_fa2_and0[0], h_u_pg_rca4_or2);
  pg_fa pg_fa_h_u_pg_rca4_pg_fa3_out(a[3], b[3], h_u_pg_rca4_or2[0], h_u_pg_rca4_pg_fa3_xor0, h_u_pg_rca4_pg_fa3_and0, h_u_pg_rca4_pg_fa3_xor1);
  and_gate and_gate_h_u_pg_rca4_and3(h_u_pg_rca4_or2[0], h_u_pg_rca4_pg_fa3_xor0[0], h_u_pg_rca4_and3);
  or_gate or_gate_h_u_pg_rca4_or3(h_u_pg_rca4_and3[0], h_u_pg_rca4_pg_fa3_and0[0], h_u_pg_rca4_or3);

  assign h_u_pg_rca4_out[0] = h_u_pg_rca4_pg_fa0_xor0[0];
  assign h_u_pg_rca4_out[1] = h_u_pg_rca4_pg_fa1_xor1[0];
  assign h_u_pg_rca4_out[2] = h_u_pg_rca4_pg_fa2_xor1[0];
  assign h_u_pg_rca4_out[3] = h_u_pg_rca4_pg_fa3_xor1[0];
  assign h_u_pg_rca4_out[4] = h_u_pg_rca4_or3[0];
endmodule