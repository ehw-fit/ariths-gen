#include <stdio.h>
#include <stdint.h>

uint64_t u_CSAwallace_rca4(uint64_t a, uint64_t b){
  uint8_t u_CSAwallace_rca4_out = 0;
  uint8_t u_CSAwallace_rca4_and_0_0 = 0;
  uint8_t u_CSAwallace_rca4_and_1_0 = 0;
  uint8_t u_CSAwallace_rca4_and_2_0 = 0;
  uint8_t u_CSAwallace_rca4_and_3_0 = 0;
  uint8_t u_CSAwallace_rca4_and_0_1 = 0;
  uint8_t u_CSAwallace_rca4_and_1_1 = 0;
  uint8_t u_CSAwallace_rca4_and_2_1 = 0;
  uint8_t u_CSAwallace_rca4_and_3_1 = 0;
  uint8_t u_CSAwallace_rca4_and_0_2 = 0;
  uint8_t u_CSAwallace_rca4_and_1_2 = 0;
  uint8_t u_CSAwallace_rca4_and_2_2 = 0;
  uint8_t u_CSAwallace_rca4_and_3_2 = 0;
  uint8_t u_CSAwallace_rca4_and_0_3 = 0;
  uint8_t u_CSAwallace_rca4_and_1_3 = 0;
  uint8_t u_CSAwallace_rca4_and_2_3 = 0;
  uint8_t u_CSAwallace_rca4_and_3_3 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa1_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa1_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa2_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa2_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa2_xor1 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa2_and1 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa2_or0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa3_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa3_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa3_xor1 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa3_and1 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa3_or0 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa4_xor1 = 0;
  uint8_t u_CSAwallace_rca4_csa0_csa_component_fa4_and1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa2_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa2_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa3_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa3_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa3_xor1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa3_and1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa3_or0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa4_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa4_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa4_xor1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa4_and1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa4_or0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa5_xor0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa5_and0 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa5_xor1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa5_and1 = 0;
  uint8_t u_CSAwallace_rca4_csa1_csa_component_fa5_or0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa3_xor0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa3_and0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa4_xor0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa4_and0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa4_xor1 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa4_and1 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa4_or0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa5_xor0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa5_and0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa5_xor1 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa5_and1 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa5_or0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa6_xor0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa6_and0 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa6_xor1 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa6_and1 = 0;
  uint8_t u_CSAwallace_rca4_u_rca8_fa6_or0 = 0;

  u_CSAwallace_rca4_and_0_0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_CSAwallace_rca4_and_1_0 = ((a >> 1) & 0x01) & ((b >> 0) & 0x01);
  u_CSAwallace_rca4_and_2_0 = ((a >> 2) & 0x01) & ((b >> 0) & 0x01);
  u_CSAwallace_rca4_and_3_0 = ((a >> 3) & 0x01) & ((b >> 0) & 0x01);
  u_CSAwallace_rca4_and_0_1 = ((a >> 0) & 0x01) & ((b >> 1) & 0x01);
  u_CSAwallace_rca4_and_1_1 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_CSAwallace_rca4_and_2_1 = ((a >> 2) & 0x01) & ((b >> 1) & 0x01);
  u_CSAwallace_rca4_and_3_1 = ((a >> 3) & 0x01) & ((b >> 1) & 0x01);
  u_CSAwallace_rca4_and_0_2 = ((a >> 0) & 0x01) & ((b >> 2) & 0x01);
  u_CSAwallace_rca4_and_1_2 = ((a >> 1) & 0x01) & ((b >> 2) & 0x01);
  u_CSAwallace_rca4_and_2_2 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_CSAwallace_rca4_and_3_2 = ((a >> 3) & 0x01) & ((b >> 2) & 0x01);
  u_CSAwallace_rca4_and_0_3 = ((a >> 0) & 0x01) & ((b >> 3) & 0x01);
  u_CSAwallace_rca4_and_1_3 = ((a >> 1) & 0x01) & ((b >> 3) & 0x01);
  u_CSAwallace_rca4_and_2_3 = ((a >> 2) & 0x01) & ((b >> 3) & 0x01);
  u_CSAwallace_rca4_and_3_3 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa1_xor0 = ((u_CSAwallace_rca4_and_1_0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_0_1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa1_and0 = ((u_CSAwallace_rca4_and_1_0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_0_1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa2_xor0 = ((u_CSAwallace_rca4_and_2_0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_1_1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa2_and0 = ((u_CSAwallace_rca4_and_2_0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_1_1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa2_xor1 = ((u_CSAwallace_rca4_csa0_csa_component_fa2_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_0_2 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa2_and1 = ((u_CSAwallace_rca4_csa0_csa_component_fa2_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_0_2 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa2_or0 = ((u_CSAwallace_rca4_csa0_csa_component_fa2_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_csa0_csa_component_fa2_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa3_xor0 = ((u_CSAwallace_rca4_and_3_0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_2_1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa3_and0 = ((u_CSAwallace_rca4_and_3_0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_2_1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa3_xor1 = ((u_CSAwallace_rca4_csa0_csa_component_fa3_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_1_2 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa3_and1 = ((u_CSAwallace_rca4_csa0_csa_component_fa3_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_1_2 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa3_or0 = ((u_CSAwallace_rca4_csa0_csa_component_fa3_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_csa0_csa_component_fa3_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa4_xor1 = ((u_CSAwallace_rca4_and_3_1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_2_2 >> 0) & 0x01);
  u_CSAwallace_rca4_csa0_csa_component_fa4_and1 = ((u_CSAwallace_rca4_and_3_1 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_2_2 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa2_xor0 = ((u_CSAwallace_rca4_csa0_csa_component_fa2_xor1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa0_csa_component_fa1_and0 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa2_and0 = ((u_CSAwallace_rca4_csa0_csa_component_fa2_xor1 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa0_csa_component_fa1_and0 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa3_xor0 = ((u_CSAwallace_rca4_csa0_csa_component_fa3_xor1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa0_csa_component_fa2_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa3_and0 = ((u_CSAwallace_rca4_csa0_csa_component_fa3_xor1 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa0_csa_component_fa2_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa3_xor1 = ((u_CSAwallace_rca4_csa1_csa_component_fa3_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_0_3 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa3_and1 = ((u_CSAwallace_rca4_csa1_csa_component_fa3_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_0_3 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa3_or0 = ((u_CSAwallace_rca4_csa1_csa_component_fa3_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_csa1_csa_component_fa3_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa4_xor0 = ((u_CSAwallace_rca4_csa0_csa_component_fa4_xor1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa0_csa_component_fa3_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa4_and0 = ((u_CSAwallace_rca4_csa0_csa_component_fa4_xor1 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa0_csa_component_fa3_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa4_xor1 = ((u_CSAwallace_rca4_csa1_csa_component_fa4_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_1_3 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa4_and1 = ((u_CSAwallace_rca4_csa1_csa_component_fa4_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_1_3 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa4_or0 = ((u_CSAwallace_rca4_csa1_csa_component_fa4_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_csa1_csa_component_fa4_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa5_xor0 = ((u_CSAwallace_rca4_and_3_2 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa0_csa_component_fa4_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa5_and0 = ((u_CSAwallace_rca4_and_3_2 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa0_csa_component_fa4_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa5_xor1 = ((u_CSAwallace_rca4_csa1_csa_component_fa5_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_and_2_3 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa5_and1 = ((u_CSAwallace_rca4_csa1_csa_component_fa5_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_and_2_3 >> 0) & 0x01);
  u_CSAwallace_rca4_csa1_csa_component_fa5_or0 = ((u_CSAwallace_rca4_csa1_csa_component_fa5_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_csa1_csa_component_fa5_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa3_xor0 = ((u_CSAwallace_rca4_csa1_csa_component_fa3_xor1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa1_csa_component_fa2_and0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa3_and0 = ((u_CSAwallace_rca4_csa1_csa_component_fa3_xor1 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa1_csa_component_fa2_and0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa4_xor0 = ((u_CSAwallace_rca4_csa1_csa_component_fa4_xor1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa1_csa_component_fa3_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa4_and0 = ((u_CSAwallace_rca4_csa1_csa_component_fa4_xor1 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa1_csa_component_fa3_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa4_xor1 = ((u_CSAwallace_rca4_u_rca8_fa4_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_u_rca8_fa3_and0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa4_and1 = ((u_CSAwallace_rca4_u_rca8_fa4_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_u_rca8_fa3_and0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa4_or0 = ((u_CSAwallace_rca4_u_rca8_fa4_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_u_rca8_fa4_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa5_xor0 = ((u_CSAwallace_rca4_csa1_csa_component_fa5_xor1 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa1_csa_component_fa4_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa5_and0 = ((u_CSAwallace_rca4_csa1_csa_component_fa5_xor1 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa1_csa_component_fa4_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa5_xor1 = ((u_CSAwallace_rca4_u_rca8_fa5_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_u_rca8_fa4_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa5_and1 = ((u_CSAwallace_rca4_u_rca8_fa5_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_u_rca8_fa4_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa5_or0 = ((u_CSAwallace_rca4_u_rca8_fa5_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_u_rca8_fa5_and1 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa6_xor0 = ((u_CSAwallace_rca4_and_3_3 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_csa1_csa_component_fa5_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa6_and0 = ((u_CSAwallace_rca4_and_3_3 >> 0) & 0x01) & ((u_CSAwallace_rca4_csa1_csa_component_fa5_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa6_xor1 = ((u_CSAwallace_rca4_u_rca8_fa6_xor0 >> 0) & 0x01) ^ ((u_CSAwallace_rca4_u_rca8_fa5_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa6_and1 = ((u_CSAwallace_rca4_u_rca8_fa6_xor0 >> 0) & 0x01) & ((u_CSAwallace_rca4_u_rca8_fa5_or0 >> 0) & 0x01);
  u_CSAwallace_rca4_u_rca8_fa6_or0 = ((u_CSAwallace_rca4_u_rca8_fa6_and0 >> 0) & 0x01) | ((u_CSAwallace_rca4_u_rca8_fa6_and1 >> 0) & 0x01);

  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_and_0_0 >> 0) & 0x01ull) << 0;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_csa0_csa_component_fa1_xor0 >> 0) & 0x01ull) << 1;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_csa1_csa_component_fa2_xor0 >> 0) & 0x01ull) << 2;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_u_rca8_fa3_xor0 >> 0) & 0x01ull) << 3;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_u_rca8_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_u_rca8_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_u_rca8_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_CSAwallace_rca4_out |= ((u_CSAwallace_rca4_u_rca8_fa6_or0 >> 0) & 0x01ull) << 7;
  return u_CSAwallace_rca4_out;
}