module s_pg_rca8(input [7:0] a, input [7:0] b, output [8:0] s_pg_rca8_out);
  wire s_pg_rca8_pg_fa0_xor0;
  wire s_pg_rca8_pg_fa0_and0;
  wire s_pg_rca8_pg_fa1_xor0;
  wire s_pg_rca8_pg_fa1_and0;
  wire s_pg_rca8_pg_fa1_xor1;
  wire s_pg_rca8_and1;
  wire s_pg_rca8_or1;
  wire s_pg_rca8_pg_fa2_xor0;
  wire s_pg_rca8_pg_fa2_and0;
  wire s_pg_rca8_pg_fa2_xor1;
  wire s_pg_rca8_and2;
  wire s_pg_rca8_or2;
  wire s_pg_rca8_pg_fa3_xor0;
  wire s_pg_rca8_pg_fa3_and0;
  wire s_pg_rca8_pg_fa3_xor1;
  wire s_pg_rca8_and3;
  wire s_pg_rca8_or3;
  wire s_pg_rca8_pg_fa4_xor0;
  wire s_pg_rca8_pg_fa4_and0;
  wire s_pg_rca8_pg_fa4_xor1;
  wire s_pg_rca8_and4;
  wire s_pg_rca8_or4;
  wire s_pg_rca8_pg_fa5_xor0;
  wire s_pg_rca8_pg_fa5_and0;
  wire s_pg_rca8_pg_fa5_xor1;
  wire s_pg_rca8_and5;
  wire s_pg_rca8_or5;
  wire s_pg_rca8_pg_fa6_xor0;
  wire s_pg_rca8_pg_fa6_and0;
  wire s_pg_rca8_pg_fa6_xor1;
  wire s_pg_rca8_and6;
  wire s_pg_rca8_or6;
  wire s_pg_rca8_pg_fa7_xor0;
  wire s_pg_rca8_pg_fa7_and0;
  wire s_pg_rca8_pg_fa7_xor1;
  wire s_pg_rca8_and7;
  wire s_pg_rca8_or7;
  wire s_pg_rca8_xor0;
  wire s_pg_rca8_xor1;

  assign s_pg_rca8_pg_fa0_xor0 = a[0] ^ b[0];
  assign s_pg_rca8_pg_fa0_and0 = a[0] & b[0];
  assign s_pg_rca8_pg_fa1_xor0 = a[1] ^ b[1];
  assign s_pg_rca8_pg_fa1_and0 = a[1] & b[1];
  assign s_pg_rca8_pg_fa1_xor1 = s_pg_rca8_pg_fa1_xor0 ^ s_pg_rca8_pg_fa0_and0;
  assign s_pg_rca8_and1 = s_pg_rca8_pg_fa0_and0 & s_pg_rca8_pg_fa1_xor0;
  assign s_pg_rca8_or1 = s_pg_rca8_and1 | s_pg_rca8_pg_fa1_and0;
  assign s_pg_rca8_pg_fa2_xor0 = a[2] ^ b[2];
  assign s_pg_rca8_pg_fa2_and0 = a[2] & b[2];
  assign s_pg_rca8_pg_fa2_xor1 = s_pg_rca8_pg_fa2_xor0 ^ s_pg_rca8_or1;
  assign s_pg_rca8_and2 = s_pg_rca8_or1 & s_pg_rca8_pg_fa2_xor0;
  assign s_pg_rca8_or2 = s_pg_rca8_and2 | s_pg_rca8_pg_fa2_and0;
  assign s_pg_rca8_pg_fa3_xor0 = a[3] ^ b[3];
  assign s_pg_rca8_pg_fa3_and0 = a[3] & b[3];
  assign s_pg_rca8_pg_fa3_xor1 = s_pg_rca8_pg_fa3_xor0 ^ s_pg_rca8_or2;
  assign s_pg_rca8_and3 = s_pg_rca8_or2 & s_pg_rca8_pg_fa3_xor0;
  assign s_pg_rca8_or3 = s_pg_rca8_and3 | s_pg_rca8_pg_fa3_and0;
  assign s_pg_rca8_pg_fa4_xor0 = a[4] ^ b[4];
  assign s_pg_rca8_pg_fa4_and0 = a[4] & b[4];
  assign s_pg_rca8_pg_fa4_xor1 = s_pg_rca8_pg_fa4_xor0 ^ s_pg_rca8_or3;
  assign s_pg_rca8_and4 = s_pg_rca8_or3 & s_pg_rca8_pg_fa4_xor0;
  assign s_pg_rca8_or4 = s_pg_rca8_and4 | s_pg_rca8_pg_fa4_and0;
  assign s_pg_rca8_pg_fa5_xor0 = a[5] ^ b[5];
  assign s_pg_rca8_pg_fa5_and0 = a[5] & b[5];
  assign s_pg_rca8_pg_fa5_xor1 = s_pg_rca8_pg_fa5_xor0 ^ s_pg_rca8_or4;
  assign s_pg_rca8_and5 = s_pg_rca8_or4 & s_pg_rca8_pg_fa5_xor0;
  assign s_pg_rca8_or5 = s_pg_rca8_and5 | s_pg_rca8_pg_fa5_and0;
  assign s_pg_rca8_pg_fa6_xor0 = a[6] ^ b[6];
  assign s_pg_rca8_pg_fa6_and0 = a[6] & b[6];
  assign s_pg_rca8_pg_fa6_xor1 = s_pg_rca8_pg_fa6_xor0 ^ s_pg_rca8_or5;
  assign s_pg_rca8_and6 = s_pg_rca8_or5 & s_pg_rca8_pg_fa6_xor0;
  assign s_pg_rca8_or6 = s_pg_rca8_and6 | s_pg_rca8_pg_fa6_and0;
  assign s_pg_rca8_pg_fa7_xor0 = a[7] ^ b[7];
  assign s_pg_rca8_pg_fa7_and0 = a[7] & b[7];
  assign s_pg_rca8_pg_fa7_xor1 = s_pg_rca8_pg_fa7_xor0 ^ s_pg_rca8_or6;
  assign s_pg_rca8_and7 = s_pg_rca8_or6 & s_pg_rca8_pg_fa7_xor0;
  assign s_pg_rca8_or7 = s_pg_rca8_and7 | s_pg_rca8_pg_fa7_and0;
  assign s_pg_rca8_xor0 = a[7] ^ b[7];
  assign s_pg_rca8_xor1 = s_pg_rca8_xor0 ^ s_pg_rca8_or7;

  assign s_pg_rca8_out[0] = s_pg_rca8_pg_fa0_xor0;
  assign s_pg_rca8_out[1] = s_pg_rca8_pg_fa1_xor1;
  assign s_pg_rca8_out[2] = s_pg_rca8_pg_fa2_xor1;
  assign s_pg_rca8_out[3] = s_pg_rca8_pg_fa3_xor1;
  assign s_pg_rca8_out[4] = s_pg_rca8_pg_fa4_xor1;
  assign s_pg_rca8_out[5] = s_pg_rca8_pg_fa5_xor1;
  assign s_pg_rca8_out[6] = s_pg_rca8_pg_fa6_xor1;
  assign s_pg_rca8_out[7] = s_pg_rca8_pg_fa7_xor1;
  assign s_pg_rca8_out[8] = s_pg_rca8_xor1;
endmodule