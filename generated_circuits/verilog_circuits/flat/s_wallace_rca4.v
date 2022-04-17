module s_wallace_rca4(input [3:0] a, input [3:0] b, output [7:0] s_wallace_rca4_out);
  wire s_wallace_rca4_and_2_0;
  wire s_wallace_rca4_and_1_1;
  wire s_wallace_rca4_ha0_xor0;
  wire s_wallace_rca4_ha0_and0;
  wire s_wallace_rca4_nand_3_0;
  wire s_wallace_rca4_and_2_1;
  wire s_wallace_rca4_fa0_xor0;
  wire s_wallace_rca4_fa0_and0;
  wire s_wallace_rca4_fa0_xor1;
  wire s_wallace_rca4_fa0_and1;
  wire s_wallace_rca4_fa0_or0;
  wire s_wallace_rca4_nand_3_1;
  wire s_wallace_rca4_fa1_xor0;
  wire s_wallace_rca4_fa1_xor1;
  wire s_wallace_rca4_fa1_and1;
  wire s_wallace_rca4_fa1_or0;
  wire s_wallace_rca4_and_1_2;
  wire s_wallace_rca4_nand_0_3;
  wire s_wallace_rca4_ha1_xor0;
  wire s_wallace_rca4_ha1_and0;
  wire s_wallace_rca4_and_2_2;
  wire s_wallace_rca4_nand_1_3;
  wire s_wallace_rca4_fa2_xor0;
  wire s_wallace_rca4_fa2_and0;
  wire s_wallace_rca4_fa2_xor1;
  wire s_wallace_rca4_fa2_and1;
  wire s_wallace_rca4_fa2_or0;
  wire s_wallace_rca4_nand_3_2;
  wire s_wallace_rca4_fa3_xor0;
  wire s_wallace_rca4_fa3_and0;
  wire s_wallace_rca4_fa3_xor1;
  wire s_wallace_rca4_fa3_and1;
  wire s_wallace_rca4_fa3_or0;
  wire s_wallace_rca4_and_0_0;
  wire s_wallace_rca4_and_1_0;
  wire s_wallace_rca4_and_0_2;
  wire s_wallace_rca4_nand_2_3;
  wire s_wallace_rca4_and_0_1;
  wire s_wallace_rca4_and_3_3;
  wire s_wallace_rca4_u_rca6_ha_xor0;
  wire s_wallace_rca4_u_rca6_ha_and0;
  wire s_wallace_rca4_u_rca6_fa1_xor0;
  wire s_wallace_rca4_u_rca6_fa1_and0;
  wire s_wallace_rca4_u_rca6_fa1_xor1;
  wire s_wallace_rca4_u_rca6_fa1_and1;
  wire s_wallace_rca4_u_rca6_fa1_or0;
  wire s_wallace_rca4_u_rca6_fa2_xor0;
  wire s_wallace_rca4_u_rca6_fa2_and0;
  wire s_wallace_rca4_u_rca6_fa2_xor1;
  wire s_wallace_rca4_u_rca6_fa2_and1;
  wire s_wallace_rca4_u_rca6_fa2_or0;
  wire s_wallace_rca4_u_rca6_fa3_xor0;
  wire s_wallace_rca4_u_rca6_fa3_and0;
  wire s_wallace_rca4_u_rca6_fa3_xor1;
  wire s_wallace_rca4_u_rca6_fa3_and1;
  wire s_wallace_rca4_u_rca6_fa3_or0;
  wire s_wallace_rca4_u_rca6_fa4_xor0;
  wire s_wallace_rca4_u_rca6_fa4_and0;
  wire s_wallace_rca4_u_rca6_fa4_xor1;
  wire s_wallace_rca4_u_rca6_fa4_and1;
  wire s_wallace_rca4_u_rca6_fa4_or0;
  wire s_wallace_rca4_u_rca6_fa5_xor0;
  wire s_wallace_rca4_u_rca6_fa5_and0;
  wire s_wallace_rca4_u_rca6_fa5_xor1;
  wire s_wallace_rca4_u_rca6_fa5_and1;
  wire s_wallace_rca4_u_rca6_fa5_or0;
  wire s_wallace_rca4_xor0;

  assign s_wallace_rca4_and_2_0 = a[2] & b[0];
  assign s_wallace_rca4_and_1_1 = a[1] & b[1];
  assign s_wallace_rca4_ha0_xor0 = s_wallace_rca4_and_2_0 ^ s_wallace_rca4_and_1_1;
  assign s_wallace_rca4_ha0_and0 = s_wallace_rca4_and_2_0 & s_wallace_rca4_and_1_1;
  assign s_wallace_rca4_nand_3_0 = ~(a[3] & b[0]);
  assign s_wallace_rca4_and_2_1 = a[2] & b[1];
  assign s_wallace_rca4_fa0_xor0 = s_wallace_rca4_ha0_and0 ^ s_wallace_rca4_nand_3_0;
  assign s_wallace_rca4_fa0_and0 = s_wallace_rca4_ha0_and0 & s_wallace_rca4_nand_3_0;
  assign s_wallace_rca4_fa0_xor1 = s_wallace_rca4_fa0_xor0 ^ s_wallace_rca4_and_2_1;
  assign s_wallace_rca4_fa0_and1 = s_wallace_rca4_fa0_xor0 & s_wallace_rca4_and_2_1;
  assign s_wallace_rca4_fa0_or0 = s_wallace_rca4_fa0_and0 | s_wallace_rca4_fa0_and1;
  assign s_wallace_rca4_nand_3_1 = ~(a[3] & b[1]);
  assign s_wallace_rca4_fa1_xor0 = ~s_wallace_rca4_fa0_or0;
  assign s_wallace_rca4_fa1_xor1 = s_wallace_rca4_fa1_xor0 ^ s_wallace_rca4_nand_3_1;
  assign s_wallace_rca4_fa1_and1 = s_wallace_rca4_fa1_xor0 & s_wallace_rca4_nand_3_1;
  assign s_wallace_rca4_fa1_or0 = s_wallace_rca4_fa0_or0 | s_wallace_rca4_fa1_and1;
  assign s_wallace_rca4_and_1_2 = a[1] & b[2];
  assign s_wallace_rca4_nand_0_3 = ~(a[0] & b[3]);
  assign s_wallace_rca4_ha1_xor0 = s_wallace_rca4_and_1_2 ^ s_wallace_rca4_nand_0_3;
  assign s_wallace_rca4_ha1_and0 = s_wallace_rca4_and_1_2 & s_wallace_rca4_nand_0_3;
  assign s_wallace_rca4_and_2_2 = a[2] & b[2];
  assign s_wallace_rca4_nand_1_3 = ~(a[1] & b[3]);
  assign s_wallace_rca4_fa2_xor0 = s_wallace_rca4_ha1_and0 ^ s_wallace_rca4_and_2_2;
  assign s_wallace_rca4_fa2_and0 = s_wallace_rca4_ha1_and0 & s_wallace_rca4_and_2_2;
  assign s_wallace_rca4_fa2_xor1 = s_wallace_rca4_fa2_xor0 ^ s_wallace_rca4_nand_1_3;
  assign s_wallace_rca4_fa2_and1 = s_wallace_rca4_fa2_xor0 & s_wallace_rca4_nand_1_3;
  assign s_wallace_rca4_fa2_or0 = s_wallace_rca4_fa2_and0 | s_wallace_rca4_fa2_and1;
  assign s_wallace_rca4_nand_3_2 = ~(a[3] & b[2]);
  assign s_wallace_rca4_fa3_xor0 = s_wallace_rca4_fa2_or0 ^ s_wallace_rca4_fa1_or0;
  assign s_wallace_rca4_fa3_and0 = s_wallace_rca4_fa2_or0 & s_wallace_rca4_fa1_or0;
  assign s_wallace_rca4_fa3_xor1 = s_wallace_rca4_fa3_xor0 ^ s_wallace_rca4_nand_3_2;
  assign s_wallace_rca4_fa3_and1 = s_wallace_rca4_fa3_xor0 & s_wallace_rca4_nand_3_2;
  assign s_wallace_rca4_fa3_or0 = s_wallace_rca4_fa3_and0 | s_wallace_rca4_fa3_and1;
  assign s_wallace_rca4_and_0_0 = a[0] & b[0];
  assign s_wallace_rca4_and_1_0 = a[1] & b[0];
  assign s_wallace_rca4_and_0_2 = a[0] & b[2];
  assign s_wallace_rca4_nand_2_3 = ~(a[2] & b[3]);
  assign s_wallace_rca4_and_0_1 = a[0] & b[1];
  assign s_wallace_rca4_and_3_3 = a[3] & b[3];
  assign s_wallace_rca4_u_rca6_ha_xor0 = s_wallace_rca4_and_1_0 ^ s_wallace_rca4_and_0_1;
  assign s_wallace_rca4_u_rca6_ha_and0 = s_wallace_rca4_and_1_0 & s_wallace_rca4_and_0_1;
  assign s_wallace_rca4_u_rca6_fa1_xor0 = s_wallace_rca4_and_0_2 ^ s_wallace_rca4_ha0_xor0;
  assign s_wallace_rca4_u_rca6_fa1_and0 = s_wallace_rca4_and_0_2 & s_wallace_rca4_ha0_xor0;
  assign s_wallace_rca4_u_rca6_fa1_xor1 = s_wallace_rca4_u_rca6_fa1_xor0 ^ s_wallace_rca4_u_rca6_ha_and0;
  assign s_wallace_rca4_u_rca6_fa1_and1 = s_wallace_rca4_u_rca6_fa1_xor0 & s_wallace_rca4_u_rca6_ha_and0;
  assign s_wallace_rca4_u_rca6_fa1_or0 = s_wallace_rca4_u_rca6_fa1_and0 | s_wallace_rca4_u_rca6_fa1_and1;
  assign s_wallace_rca4_u_rca6_fa2_xor0 = s_wallace_rca4_fa0_xor1 ^ s_wallace_rca4_ha1_xor0;
  assign s_wallace_rca4_u_rca6_fa2_and0 = s_wallace_rca4_fa0_xor1 & s_wallace_rca4_ha1_xor0;
  assign s_wallace_rca4_u_rca6_fa2_xor1 = s_wallace_rca4_u_rca6_fa2_xor0 ^ s_wallace_rca4_u_rca6_fa1_or0;
  assign s_wallace_rca4_u_rca6_fa2_and1 = s_wallace_rca4_u_rca6_fa2_xor0 & s_wallace_rca4_u_rca6_fa1_or0;
  assign s_wallace_rca4_u_rca6_fa2_or0 = s_wallace_rca4_u_rca6_fa2_and0 | s_wallace_rca4_u_rca6_fa2_and1;
  assign s_wallace_rca4_u_rca6_fa3_xor0 = s_wallace_rca4_fa1_xor1 ^ s_wallace_rca4_fa2_xor1;
  assign s_wallace_rca4_u_rca6_fa3_and0 = s_wallace_rca4_fa1_xor1 & s_wallace_rca4_fa2_xor1;
  assign s_wallace_rca4_u_rca6_fa3_xor1 = s_wallace_rca4_u_rca6_fa3_xor0 ^ s_wallace_rca4_u_rca6_fa2_or0;
  assign s_wallace_rca4_u_rca6_fa3_and1 = s_wallace_rca4_u_rca6_fa3_xor0 & s_wallace_rca4_u_rca6_fa2_or0;
  assign s_wallace_rca4_u_rca6_fa3_or0 = s_wallace_rca4_u_rca6_fa3_and0 | s_wallace_rca4_u_rca6_fa3_and1;
  assign s_wallace_rca4_u_rca6_fa4_xor0 = s_wallace_rca4_nand_2_3 ^ s_wallace_rca4_fa3_xor1;
  assign s_wallace_rca4_u_rca6_fa4_and0 = s_wallace_rca4_nand_2_3 & s_wallace_rca4_fa3_xor1;
  assign s_wallace_rca4_u_rca6_fa4_xor1 = s_wallace_rca4_u_rca6_fa4_xor0 ^ s_wallace_rca4_u_rca6_fa3_or0;
  assign s_wallace_rca4_u_rca6_fa4_and1 = s_wallace_rca4_u_rca6_fa4_xor0 & s_wallace_rca4_u_rca6_fa3_or0;
  assign s_wallace_rca4_u_rca6_fa4_or0 = s_wallace_rca4_u_rca6_fa4_and0 | s_wallace_rca4_u_rca6_fa4_and1;
  assign s_wallace_rca4_u_rca6_fa5_xor0 = s_wallace_rca4_fa3_or0 ^ s_wallace_rca4_and_3_3;
  assign s_wallace_rca4_u_rca6_fa5_and0 = s_wallace_rca4_fa3_or0 & s_wallace_rca4_and_3_3;
  assign s_wallace_rca4_u_rca6_fa5_xor1 = s_wallace_rca4_u_rca6_fa5_xor0 ^ s_wallace_rca4_u_rca6_fa4_or0;
  assign s_wallace_rca4_u_rca6_fa5_and1 = s_wallace_rca4_u_rca6_fa5_xor0 & s_wallace_rca4_u_rca6_fa4_or0;
  assign s_wallace_rca4_u_rca6_fa5_or0 = s_wallace_rca4_u_rca6_fa5_and0 | s_wallace_rca4_u_rca6_fa5_and1;
  assign s_wallace_rca4_xor0 = ~s_wallace_rca4_u_rca6_fa5_or0;

  assign s_wallace_rca4_out[0] = s_wallace_rca4_and_0_0;
  assign s_wallace_rca4_out[1] = s_wallace_rca4_u_rca6_ha_xor0;
  assign s_wallace_rca4_out[2] = s_wallace_rca4_u_rca6_fa1_xor1;
  assign s_wallace_rca4_out[3] = s_wallace_rca4_u_rca6_fa2_xor1;
  assign s_wallace_rca4_out[4] = s_wallace_rca4_u_rca6_fa3_xor1;
  assign s_wallace_rca4_out[5] = s_wallace_rca4_u_rca6_fa4_xor1;
  assign s_wallace_rca4_out[6] = s_wallace_rca4_u_rca6_fa5_xor1;
  assign s_wallace_rca4_out[7] = s_wallace_rca4_xor0;
endmodule