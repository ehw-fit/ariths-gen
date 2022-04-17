module s_rca4(input [3:0] a, input [3:0] b, output [4:0] s_rca4_out);
  wire s_rca4_ha_xor0;
  wire s_rca4_ha_and0;
  wire s_rca4_fa1_xor0;
  wire s_rca4_fa1_and0;
  wire s_rca4_fa1_xor1;
  wire s_rca4_fa1_and1;
  wire s_rca4_fa1_or0;
  wire s_rca4_fa2_xor0;
  wire s_rca4_fa2_and0;
  wire s_rca4_fa2_xor1;
  wire s_rca4_fa2_and1;
  wire s_rca4_fa2_or0;
  wire s_rca4_fa3_xor0;
  wire s_rca4_fa3_and0;
  wire s_rca4_fa3_xor1;
  wire s_rca4_fa3_and1;
  wire s_rca4_fa3_or0;
  wire s_rca4_xor0;
  wire s_rca4_xor1;

  assign s_rca4_ha_xor0 = a[0] ^ b[0];
  assign s_rca4_ha_and0 = a[0] & b[0];
  assign s_rca4_fa1_xor0 = a[1] ^ b[1];
  assign s_rca4_fa1_and0 = a[1] & b[1];
  assign s_rca4_fa1_xor1 = s_rca4_fa1_xor0 ^ s_rca4_ha_and0;
  assign s_rca4_fa1_and1 = s_rca4_fa1_xor0 & s_rca4_ha_and0;
  assign s_rca4_fa1_or0 = s_rca4_fa1_and0 | s_rca4_fa1_and1;
  assign s_rca4_fa2_xor0 = a[2] ^ b[2];
  assign s_rca4_fa2_and0 = a[2] & b[2];
  assign s_rca4_fa2_xor1 = s_rca4_fa2_xor0 ^ s_rca4_fa1_or0;
  assign s_rca4_fa2_and1 = s_rca4_fa2_xor0 & s_rca4_fa1_or0;
  assign s_rca4_fa2_or0 = s_rca4_fa2_and0 | s_rca4_fa2_and1;
  assign s_rca4_fa3_xor0 = a[3] ^ b[3];
  assign s_rca4_fa3_and0 = a[3] & b[3];
  assign s_rca4_fa3_xor1 = s_rca4_fa3_xor0 ^ s_rca4_fa2_or0;
  assign s_rca4_fa3_and1 = s_rca4_fa3_xor0 & s_rca4_fa2_or0;
  assign s_rca4_fa3_or0 = s_rca4_fa3_and0 | s_rca4_fa3_and1;
  assign s_rca4_xor0 = a[3] ^ b[3];
  assign s_rca4_xor1 = s_rca4_xor0 ^ s_rca4_fa3_or0;

  assign s_rca4_out[0] = s_rca4_ha_xor0;
  assign s_rca4_out[1] = s_rca4_fa1_xor1;
  assign s_rca4_out[2] = s_rca4_fa2_xor1;
  assign s_rca4_out[3] = s_rca4_fa3_xor1;
  assign s_rca4_out[4] = s_rca4_xor1;
endmodule