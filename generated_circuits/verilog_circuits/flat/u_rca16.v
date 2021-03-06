module u_rca16(input [15:0] a, input [15:0] b, output [16:0] u_rca16_out);
  wire u_rca16_ha_xor0;
  wire u_rca16_ha_and0;
  wire u_rca16_fa1_xor0;
  wire u_rca16_fa1_and0;
  wire u_rca16_fa1_xor1;
  wire u_rca16_fa1_and1;
  wire u_rca16_fa1_or0;
  wire u_rca16_fa2_xor0;
  wire u_rca16_fa2_and0;
  wire u_rca16_fa2_xor1;
  wire u_rca16_fa2_and1;
  wire u_rca16_fa2_or0;
  wire u_rca16_fa3_xor0;
  wire u_rca16_fa3_and0;
  wire u_rca16_fa3_xor1;
  wire u_rca16_fa3_and1;
  wire u_rca16_fa3_or0;
  wire u_rca16_fa4_xor0;
  wire u_rca16_fa4_and0;
  wire u_rca16_fa4_xor1;
  wire u_rca16_fa4_and1;
  wire u_rca16_fa4_or0;
  wire u_rca16_fa5_xor0;
  wire u_rca16_fa5_and0;
  wire u_rca16_fa5_xor1;
  wire u_rca16_fa5_and1;
  wire u_rca16_fa5_or0;
  wire u_rca16_fa6_xor0;
  wire u_rca16_fa6_and0;
  wire u_rca16_fa6_xor1;
  wire u_rca16_fa6_and1;
  wire u_rca16_fa6_or0;
  wire u_rca16_fa7_xor0;
  wire u_rca16_fa7_and0;
  wire u_rca16_fa7_xor1;
  wire u_rca16_fa7_and1;
  wire u_rca16_fa7_or0;
  wire u_rca16_fa8_xor0;
  wire u_rca16_fa8_and0;
  wire u_rca16_fa8_xor1;
  wire u_rca16_fa8_and1;
  wire u_rca16_fa8_or0;
  wire u_rca16_fa9_xor0;
  wire u_rca16_fa9_and0;
  wire u_rca16_fa9_xor1;
  wire u_rca16_fa9_and1;
  wire u_rca16_fa9_or0;
  wire u_rca16_fa10_xor0;
  wire u_rca16_fa10_and0;
  wire u_rca16_fa10_xor1;
  wire u_rca16_fa10_and1;
  wire u_rca16_fa10_or0;
  wire u_rca16_fa11_xor0;
  wire u_rca16_fa11_and0;
  wire u_rca16_fa11_xor1;
  wire u_rca16_fa11_and1;
  wire u_rca16_fa11_or0;
  wire u_rca16_fa12_xor0;
  wire u_rca16_fa12_and0;
  wire u_rca16_fa12_xor1;
  wire u_rca16_fa12_and1;
  wire u_rca16_fa12_or0;
  wire u_rca16_fa13_xor0;
  wire u_rca16_fa13_and0;
  wire u_rca16_fa13_xor1;
  wire u_rca16_fa13_and1;
  wire u_rca16_fa13_or0;
  wire u_rca16_fa14_xor0;
  wire u_rca16_fa14_and0;
  wire u_rca16_fa14_xor1;
  wire u_rca16_fa14_and1;
  wire u_rca16_fa14_or0;
  wire u_rca16_fa15_xor0;
  wire u_rca16_fa15_and0;
  wire u_rca16_fa15_xor1;
  wire u_rca16_fa15_and1;
  wire u_rca16_fa15_or0;

  assign u_rca16_ha_xor0 = a[0] ^ b[0];
  assign u_rca16_ha_and0 = a[0] & b[0];
  assign u_rca16_fa1_xor0 = a[1] ^ b[1];
  assign u_rca16_fa1_and0 = a[1] & b[1];
  assign u_rca16_fa1_xor1 = u_rca16_fa1_xor0 ^ u_rca16_ha_and0;
  assign u_rca16_fa1_and1 = u_rca16_fa1_xor0 & u_rca16_ha_and0;
  assign u_rca16_fa1_or0 = u_rca16_fa1_and0 | u_rca16_fa1_and1;
  assign u_rca16_fa2_xor0 = a[2] ^ b[2];
  assign u_rca16_fa2_and0 = a[2] & b[2];
  assign u_rca16_fa2_xor1 = u_rca16_fa2_xor0 ^ u_rca16_fa1_or0;
  assign u_rca16_fa2_and1 = u_rca16_fa2_xor0 & u_rca16_fa1_or0;
  assign u_rca16_fa2_or0 = u_rca16_fa2_and0 | u_rca16_fa2_and1;
  assign u_rca16_fa3_xor0 = a[3] ^ b[3];
  assign u_rca16_fa3_and0 = a[3] & b[3];
  assign u_rca16_fa3_xor1 = u_rca16_fa3_xor0 ^ u_rca16_fa2_or0;
  assign u_rca16_fa3_and1 = u_rca16_fa3_xor0 & u_rca16_fa2_or0;
  assign u_rca16_fa3_or0 = u_rca16_fa3_and0 | u_rca16_fa3_and1;
  assign u_rca16_fa4_xor0 = a[4] ^ b[4];
  assign u_rca16_fa4_and0 = a[4] & b[4];
  assign u_rca16_fa4_xor1 = u_rca16_fa4_xor0 ^ u_rca16_fa3_or0;
  assign u_rca16_fa4_and1 = u_rca16_fa4_xor0 & u_rca16_fa3_or0;
  assign u_rca16_fa4_or0 = u_rca16_fa4_and0 | u_rca16_fa4_and1;
  assign u_rca16_fa5_xor0 = a[5] ^ b[5];
  assign u_rca16_fa5_and0 = a[5] & b[5];
  assign u_rca16_fa5_xor1 = u_rca16_fa5_xor0 ^ u_rca16_fa4_or0;
  assign u_rca16_fa5_and1 = u_rca16_fa5_xor0 & u_rca16_fa4_or0;
  assign u_rca16_fa5_or0 = u_rca16_fa5_and0 | u_rca16_fa5_and1;
  assign u_rca16_fa6_xor0 = a[6] ^ b[6];
  assign u_rca16_fa6_and0 = a[6] & b[6];
  assign u_rca16_fa6_xor1 = u_rca16_fa6_xor0 ^ u_rca16_fa5_or0;
  assign u_rca16_fa6_and1 = u_rca16_fa6_xor0 & u_rca16_fa5_or0;
  assign u_rca16_fa6_or0 = u_rca16_fa6_and0 | u_rca16_fa6_and1;
  assign u_rca16_fa7_xor0 = a[7] ^ b[7];
  assign u_rca16_fa7_and0 = a[7] & b[7];
  assign u_rca16_fa7_xor1 = u_rca16_fa7_xor0 ^ u_rca16_fa6_or0;
  assign u_rca16_fa7_and1 = u_rca16_fa7_xor0 & u_rca16_fa6_or0;
  assign u_rca16_fa7_or0 = u_rca16_fa7_and0 | u_rca16_fa7_and1;
  assign u_rca16_fa8_xor0 = a[8] ^ b[8];
  assign u_rca16_fa8_and0 = a[8] & b[8];
  assign u_rca16_fa8_xor1 = u_rca16_fa8_xor0 ^ u_rca16_fa7_or0;
  assign u_rca16_fa8_and1 = u_rca16_fa8_xor0 & u_rca16_fa7_or0;
  assign u_rca16_fa8_or0 = u_rca16_fa8_and0 | u_rca16_fa8_and1;
  assign u_rca16_fa9_xor0 = a[9] ^ b[9];
  assign u_rca16_fa9_and0 = a[9] & b[9];
  assign u_rca16_fa9_xor1 = u_rca16_fa9_xor0 ^ u_rca16_fa8_or0;
  assign u_rca16_fa9_and1 = u_rca16_fa9_xor0 & u_rca16_fa8_or0;
  assign u_rca16_fa9_or0 = u_rca16_fa9_and0 | u_rca16_fa9_and1;
  assign u_rca16_fa10_xor0 = a[10] ^ b[10];
  assign u_rca16_fa10_and0 = a[10] & b[10];
  assign u_rca16_fa10_xor1 = u_rca16_fa10_xor0 ^ u_rca16_fa9_or0;
  assign u_rca16_fa10_and1 = u_rca16_fa10_xor0 & u_rca16_fa9_or0;
  assign u_rca16_fa10_or0 = u_rca16_fa10_and0 | u_rca16_fa10_and1;
  assign u_rca16_fa11_xor0 = a[11] ^ b[11];
  assign u_rca16_fa11_and0 = a[11] & b[11];
  assign u_rca16_fa11_xor1 = u_rca16_fa11_xor0 ^ u_rca16_fa10_or0;
  assign u_rca16_fa11_and1 = u_rca16_fa11_xor0 & u_rca16_fa10_or0;
  assign u_rca16_fa11_or0 = u_rca16_fa11_and0 | u_rca16_fa11_and1;
  assign u_rca16_fa12_xor0 = a[12] ^ b[12];
  assign u_rca16_fa12_and0 = a[12] & b[12];
  assign u_rca16_fa12_xor1 = u_rca16_fa12_xor0 ^ u_rca16_fa11_or0;
  assign u_rca16_fa12_and1 = u_rca16_fa12_xor0 & u_rca16_fa11_or0;
  assign u_rca16_fa12_or0 = u_rca16_fa12_and0 | u_rca16_fa12_and1;
  assign u_rca16_fa13_xor0 = a[13] ^ b[13];
  assign u_rca16_fa13_and0 = a[13] & b[13];
  assign u_rca16_fa13_xor1 = u_rca16_fa13_xor0 ^ u_rca16_fa12_or0;
  assign u_rca16_fa13_and1 = u_rca16_fa13_xor0 & u_rca16_fa12_or0;
  assign u_rca16_fa13_or0 = u_rca16_fa13_and0 | u_rca16_fa13_and1;
  assign u_rca16_fa14_xor0 = a[14] ^ b[14];
  assign u_rca16_fa14_and0 = a[14] & b[14];
  assign u_rca16_fa14_xor1 = u_rca16_fa14_xor0 ^ u_rca16_fa13_or0;
  assign u_rca16_fa14_and1 = u_rca16_fa14_xor0 & u_rca16_fa13_or0;
  assign u_rca16_fa14_or0 = u_rca16_fa14_and0 | u_rca16_fa14_and1;
  assign u_rca16_fa15_xor0 = a[15] ^ b[15];
  assign u_rca16_fa15_and0 = a[15] & b[15];
  assign u_rca16_fa15_xor1 = u_rca16_fa15_xor0 ^ u_rca16_fa14_or0;
  assign u_rca16_fa15_and1 = u_rca16_fa15_xor0 & u_rca16_fa14_or0;
  assign u_rca16_fa15_or0 = u_rca16_fa15_and0 | u_rca16_fa15_and1;

  assign u_rca16_out[0] = u_rca16_ha_xor0;
  assign u_rca16_out[1] = u_rca16_fa1_xor1;
  assign u_rca16_out[2] = u_rca16_fa2_xor1;
  assign u_rca16_out[3] = u_rca16_fa3_xor1;
  assign u_rca16_out[4] = u_rca16_fa4_xor1;
  assign u_rca16_out[5] = u_rca16_fa5_xor1;
  assign u_rca16_out[6] = u_rca16_fa6_xor1;
  assign u_rca16_out[7] = u_rca16_fa7_xor1;
  assign u_rca16_out[8] = u_rca16_fa8_xor1;
  assign u_rca16_out[9] = u_rca16_fa9_xor1;
  assign u_rca16_out[10] = u_rca16_fa10_xor1;
  assign u_rca16_out[11] = u_rca16_fa11_xor1;
  assign u_rca16_out[12] = u_rca16_fa12_xor1;
  assign u_rca16_out[13] = u_rca16_fa13_xor1;
  assign u_rca16_out[14] = u_rca16_fa14_xor1;
  assign u_rca16_out[15] = u_rca16_fa15_xor1;
  assign u_rca16_out[16] = u_rca16_fa15_or0;
endmodule