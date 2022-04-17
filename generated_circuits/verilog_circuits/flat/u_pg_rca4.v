module u_pg_rca4(input [3:0] a, input [3:0] b, output [4:0] u_pg_rca4_out);
  wire u_pg_rca4_pg_fa0_xor0;
  wire u_pg_rca4_pg_fa0_and0;
  wire u_pg_rca4_pg_fa1_xor0;
  wire u_pg_rca4_pg_fa1_and0;
  wire u_pg_rca4_pg_fa1_xor1;
  wire u_pg_rca4_and1;
  wire u_pg_rca4_or1;
  wire u_pg_rca4_pg_fa2_xor0;
  wire u_pg_rca4_pg_fa2_and0;
  wire u_pg_rca4_pg_fa2_xor1;
  wire u_pg_rca4_and2;
  wire u_pg_rca4_or2;
  wire u_pg_rca4_pg_fa3_xor0;
  wire u_pg_rca4_pg_fa3_and0;
  wire u_pg_rca4_pg_fa3_xor1;
  wire u_pg_rca4_and3;
  wire u_pg_rca4_or3;

  assign u_pg_rca4_pg_fa0_xor0 = a[0] ^ b[0];
  assign u_pg_rca4_pg_fa0_and0 = a[0] & b[0];
  assign u_pg_rca4_pg_fa1_xor0 = a[1] ^ b[1];
  assign u_pg_rca4_pg_fa1_and0 = a[1] & b[1];
  assign u_pg_rca4_pg_fa1_xor1 = u_pg_rca4_pg_fa1_xor0 ^ u_pg_rca4_pg_fa0_and0;
  assign u_pg_rca4_and1 = u_pg_rca4_pg_fa0_and0 & u_pg_rca4_pg_fa1_xor0;
  assign u_pg_rca4_or1 = u_pg_rca4_and1 | u_pg_rca4_pg_fa1_and0;
  assign u_pg_rca4_pg_fa2_xor0 = a[2] ^ b[2];
  assign u_pg_rca4_pg_fa2_and0 = a[2] & b[2];
  assign u_pg_rca4_pg_fa2_xor1 = u_pg_rca4_pg_fa2_xor0 ^ u_pg_rca4_or1;
  assign u_pg_rca4_and2 = u_pg_rca4_or1 & u_pg_rca4_pg_fa2_xor0;
  assign u_pg_rca4_or2 = u_pg_rca4_and2 | u_pg_rca4_pg_fa2_and0;
  assign u_pg_rca4_pg_fa3_xor0 = a[3] ^ b[3];
  assign u_pg_rca4_pg_fa3_and0 = a[3] & b[3];
  assign u_pg_rca4_pg_fa3_xor1 = u_pg_rca4_pg_fa3_xor0 ^ u_pg_rca4_or2;
  assign u_pg_rca4_and3 = u_pg_rca4_or2 & u_pg_rca4_pg_fa3_xor0;
  assign u_pg_rca4_or3 = u_pg_rca4_and3 | u_pg_rca4_pg_fa3_and0;

  assign u_pg_rca4_out[0] = u_pg_rca4_pg_fa0_xor0;
  assign u_pg_rca4_out[1] = u_pg_rca4_pg_fa1_xor1;
  assign u_pg_rca4_out[2] = u_pg_rca4_pg_fa2_xor1;
  assign u_pg_rca4_out[3] = u_pg_rca4_pg_fa3_xor1;
  assign u_pg_rca4_out[4] = u_pg_rca4_or3;
endmodule