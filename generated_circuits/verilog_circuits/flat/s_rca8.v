module s_rca8(input [7:0] a, input [7:0] b, output [8:0] s_rca8_out);
  wire s_rca8_ha_xor0;
  wire s_rca8_ha_and0;
  wire s_rca8_fa1_xor0;
  wire s_rca8_fa1_and0;
  wire s_rca8_fa1_xor1;
  wire s_rca8_fa1_and1;
  wire s_rca8_fa1_or0;
  wire s_rca8_fa2_xor0;
  wire s_rca8_fa2_and0;
  wire s_rca8_fa2_xor1;
  wire s_rca8_fa2_and1;
  wire s_rca8_fa2_or0;
  wire s_rca8_fa3_xor0;
  wire s_rca8_fa3_and0;
  wire s_rca8_fa3_xor1;
  wire s_rca8_fa3_and1;
  wire s_rca8_fa3_or0;
  wire s_rca8_fa4_xor0;
  wire s_rca8_fa4_and0;
  wire s_rca8_fa4_xor1;
  wire s_rca8_fa4_and1;
  wire s_rca8_fa4_or0;
  wire s_rca8_fa5_xor0;
  wire s_rca8_fa5_and0;
  wire s_rca8_fa5_xor1;
  wire s_rca8_fa5_and1;
  wire s_rca8_fa5_or0;
  wire s_rca8_fa6_xor0;
  wire s_rca8_fa6_and0;
  wire s_rca8_fa6_xor1;
  wire s_rca8_fa6_and1;
  wire s_rca8_fa6_or0;
  wire s_rca8_fa7_xor0;
  wire s_rca8_fa7_and0;
  wire s_rca8_fa7_xor1;
  wire s_rca8_fa7_and1;
  wire s_rca8_fa7_or0;
  wire s_rca8_xor0;
  wire s_rca8_xor1;

  assign s_rca8_ha_xor0 = a[0] ^ b[0];
  assign s_rca8_ha_and0 = a[0] & b[0];
  assign s_rca8_fa1_xor0 = a[1] ^ b[1];
  assign s_rca8_fa1_and0 = a[1] & b[1];
  assign s_rca8_fa1_xor1 = s_rca8_fa1_xor0 ^ s_rca8_ha_and0;
  assign s_rca8_fa1_and1 = s_rca8_fa1_xor0 & s_rca8_ha_and0;
  assign s_rca8_fa1_or0 = s_rca8_fa1_and0 | s_rca8_fa1_and1;
  assign s_rca8_fa2_xor0 = a[2] ^ b[2];
  assign s_rca8_fa2_and0 = a[2] & b[2];
  assign s_rca8_fa2_xor1 = s_rca8_fa2_xor0 ^ s_rca8_fa1_or0;
  assign s_rca8_fa2_and1 = s_rca8_fa2_xor0 & s_rca8_fa1_or0;
  assign s_rca8_fa2_or0 = s_rca8_fa2_and0 | s_rca8_fa2_and1;
  assign s_rca8_fa3_xor0 = a[3] ^ b[3];
  assign s_rca8_fa3_and0 = a[3] & b[3];
  assign s_rca8_fa3_xor1 = s_rca8_fa3_xor0 ^ s_rca8_fa2_or0;
  assign s_rca8_fa3_and1 = s_rca8_fa3_xor0 & s_rca8_fa2_or0;
  assign s_rca8_fa3_or0 = s_rca8_fa3_and0 | s_rca8_fa3_and1;
  assign s_rca8_fa4_xor0 = a[4] ^ b[4];
  assign s_rca8_fa4_and0 = a[4] & b[4];
  assign s_rca8_fa4_xor1 = s_rca8_fa4_xor0 ^ s_rca8_fa3_or0;
  assign s_rca8_fa4_and1 = s_rca8_fa4_xor0 & s_rca8_fa3_or0;
  assign s_rca8_fa4_or0 = s_rca8_fa4_and0 | s_rca8_fa4_and1;
  assign s_rca8_fa5_xor0 = a[5] ^ b[5];
  assign s_rca8_fa5_and0 = a[5] & b[5];
  assign s_rca8_fa5_xor1 = s_rca8_fa5_xor0 ^ s_rca8_fa4_or0;
  assign s_rca8_fa5_and1 = s_rca8_fa5_xor0 & s_rca8_fa4_or0;
  assign s_rca8_fa5_or0 = s_rca8_fa5_and0 | s_rca8_fa5_and1;
  assign s_rca8_fa6_xor0 = a[6] ^ b[6];
  assign s_rca8_fa6_and0 = a[6] & b[6];
  assign s_rca8_fa6_xor1 = s_rca8_fa6_xor0 ^ s_rca8_fa5_or0;
  assign s_rca8_fa6_and1 = s_rca8_fa6_xor0 & s_rca8_fa5_or0;
  assign s_rca8_fa6_or0 = s_rca8_fa6_and0 | s_rca8_fa6_and1;
  assign s_rca8_fa7_xor0 = a[7] ^ b[7];
  assign s_rca8_fa7_and0 = a[7] & b[7];
  assign s_rca8_fa7_xor1 = s_rca8_fa7_xor0 ^ s_rca8_fa6_or0;
  assign s_rca8_fa7_and1 = s_rca8_fa7_xor0 & s_rca8_fa6_or0;
  assign s_rca8_fa7_or0 = s_rca8_fa7_and0 | s_rca8_fa7_and1;
  assign s_rca8_xor0 = a[7] ^ b[7];
  assign s_rca8_xor1 = s_rca8_xor0 ^ s_rca8_fa7_or0;

  assign s_rca8_out[0] = s_rca8_ha_xor0;
  assign s_rca8_out[1] = s_rca8_fa1_xor1;
  assign s_rca8_out[2] = s_rca8_fa2_xor1;
  assign s_rca8_out[3] = s_rca8_fa3_xor1;
  assign s_rca8_out[4] = s_rca8_fa4_xor1;
  assign s_rca8_out[5] = s_rca8_fa5_xor1;
  assign s_rca8_out[6] = s_rca8_fa6_xor1;
  assign s_rca8_out[7] = s_rca8_fa7_xor1;
  assign s_rca8_out[8] = s_rca8_xor1;
endmodule