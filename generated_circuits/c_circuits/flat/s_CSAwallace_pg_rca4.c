#include <stdio.h>
#include <stdint.h>

int64_t s_CSAwallace_pg_rca4(int64_t a, int64_t b){
  int8_t s_CSAwallace_pg_rca4_out = 0;
  uint8_t s_CSAwallace_pg_rca4_and_0_0 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_1_0 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_2_0 = 0;
  uint8_t s_CSAwallace_pg_rca4_nand_3_0 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_0_1 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_1_1 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_2_1 = 0;
  uint8_t s_CSAwallace_pg_rca4_nand_3_1 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_0_2 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_1_2 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_2_2 = 0;
  uint8_t s_CSAwallace_pg_rca4_nand_3_2 = 0;
  uint8_t s_CSAwallace_pg_rca4_nand_0_3 = 0;
  uint8_t s_CSAwallace_pg_rca4_nand_1_3 = 0;
  uint8_t s_CSAwallace_pg_rca4_nand_2_3 = 0;
  uint8_t s_CSAwallace_pg_rca4_and_3_3 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa1_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa2_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa2_and1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa3_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa3_and1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa0_csa_component_fa4_or0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa2_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa3_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa3_and1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa4_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa4_and1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa5_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa5_and1 = 0;
  uint8_t s_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_and4 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_or4 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_and5 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_or5 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_and0 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor1 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_and6 = 0;
  uint8_t s_CSAwallace_pg_rca4_u_pg_rca8_or6 = 0;
  uint8_t s_CSAwallace_pg_rca4_xor0 = 0;

  s_CSAwallace_pg_rca4_and_0_0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  s_CSAwallace_pg_rca4_and_1_0 = ((a >> 1) & 0x01) & ((b >> 0) & 0x01);
  s_CSAwallace_pg_rca4_and_2_0 = ((a >> 2) & 0x01) & ((b >> 0) & 0x01);
  s_CSAwallace_pg_rca4_nand_3_0 = ~(((a >> 3) & 0x01) & ((b >> 0) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_and_0_1 = ((a >> 0) & 0x01) & ((b >> 1) & 0x01);
  s_CSAwallace_pg_rca4_and_1_1 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  s_CSAwallace_pg_rca4_and_2_1 = ((a >> 2) & 0x01) & ((b >> 1) & 0x01);
  s_CSAwallace_pg_rca4_nand_3_1 = ~(((a >> 3) & 0x01) & ((b >> 1) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_and_0_2 = ((a >> 0) & 0x01) & ((b >> 2) & 0x01);
  s_CSAwallace_pg_rca4_and_1_2 = ((a >> 1) & 0x01) & ((b >> 2) & 0x01);
  s_CSAwallace_pg_rca4_and_2_2 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  s_CSAwallace_pg_rca4_nand_3_2 = ~(((a >> 3) & 0x01) & ((b >> 2) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_nand_0_3 = ~(((a >> 0) & 0x01) & ((b >> 3) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_nand_1_3 = ~(((a >> 1) & 0x01) & ((b >> 3) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_nand_2_3 = ~(((a >> 2) & 0x01) & ((b >> 3) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_and_3_3 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa1_xor0 = ((s_CSAwallace_pg_rca4_and_1_0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_and_0_1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0 = ((s_CSAwallace_pg_rca4_and_1_0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_and_0_1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 = ((s_CSAwallace_pg_rca4_and_2_0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_and_1_1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa2_and0 = ((s_CSAwallace_pg_rca4_and_2_0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_and_1_1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_and_0_2 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa2_and1 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_and_0_2 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_and0 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_and1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 = ((s_CSAwallace_pg_rca4_nand_3_0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_and_2_1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa3_and0 = ((s_CSAwallace_pg_rca4_nand_3_0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_and_2_1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_and_1_2 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa3_and1 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_and_1_2 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_and0 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_and1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor0 = ~(((s_CSAwallace_pg_rca4_nand_3_1 >> 0) & 0x01)) & 0x01;
  s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_and_2_2 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_and_2_2 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa0_csa_component_fa4_or0 = ((s_CSAwallace_pg_rca4_nand_3_1 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa2_xor0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa3_and0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_nand_0_3 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa3_and1 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_nand_0_3 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_and0 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_and1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa4_and0 = ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_nand_1_3 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa4_and1 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_nand_1_3 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_and0 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_and1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 = ((s_CSAwallace_pg_rca4_nand_3_2 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa5_and0 = ((s_CSAwallace_pg_rca4_nand_3_2 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa0_csa_component_fa4_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_nand_2_3 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa5_and1 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_nand_2_3 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_and0 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_and1 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_xor0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_and0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor1 = ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_and4 = ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_or4 = ((s_CSAwallace_pg_rca4_u_pg_rca8_and4 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_and0 = ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor1 = ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_u_pg_rca8_or4 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_and5 = ((s_CSAwallace_pg_rca4_u_pg_rca8_or4 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_or5 = ((s_CSAwallace_pg_rca4_u_pg_rca8_and5 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0 = ((s_CSAwallace_pg_rca4_and_3_3 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_and0 = ((s_CSAwallace_pg_rca4_and_3_3 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor1 = ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01) ^ ((s_CSAwallace_pg_rca4_u_pg_rca8_or5 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_and6 = ((s_CSAwallace_pg_rca4_u_pg_rca8_or5 >> 0) & 0x01) & ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_u_pg_rca8_or6 = ((s_CSAwallace_pg_rca4_u_pg_rca8_and6 >> 0) & 0x01) | ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_and0 >> 0) & 0x01);
  s_CSAwallace_pg_rca4_xor0 = ~(((s_CSAwallace_pg_rca4_u_pg_rca8_or6 >> 0) & 0x01)) & 0x01;

  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_and_0_0 >> 0) & 0x01ull) << 0;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_csa0_csa_component_fa1_xor0 >> 0) & 0x01ull) << 1;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_csa1_csa_component_fa2_xor0 >> 0) & 0x01ull) << 2;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01ull) << 3;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor1 >> 0) & 0x01ull) << 4;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor1 >> 0) & 0x01ull) << 5;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor1 >> 0) & 0x01ull) << 6;
  s_CSAwallace_pg_rca4_out |= ((s_CSAwallace_pg_rca4_xor0 >> 0) & 0x01ull) << 7;
  return s_CSAwallace_pg_rca4_out;
}