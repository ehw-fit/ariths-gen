#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t nand_gate(uint8_t a, uint8_t b){
  return ~(((a >> 0) & 0x01) & ((b >> 0) & 0x01)) & 0x01;
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
}

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t fa_out = 0;
  uint8_t fa_xor0 = 0;
  uint8_t fa_and0 = 0;
  uint8_t fa_xor1 = 0;
  uint8_t fa_and1 = 0;
  uint8_t fa_or0 = 0;

  fa_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  fa_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  fa_xor1 = xor_gate(((fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));
  fa_and1 = and_gate(((fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));
  fa_or0 = or_gate(((fa_and0 >> 0) & 0x01), ((fa_and1 >> 0) & 0x01));

  fa_out |= ((fa_xor1 >> 0) & 0x01ull) << 0;
  fa_out |= ((fa_or0 >> 0) & 0x01ull) << 1;
  return fa_out;
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t ha_out = 0;
  uint8_t ha_xor0 = 0;
  uint8_t ha_and0 = 0;

  ha_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  ha_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));

  ha_out |= ((ha_xor0 >> 0) & 0x01ull) << 0;
  ha_out |= ((ha_and0 >> 0) & 0x01ull) << 1;
  return ha_out;
}

uint64_t csa_component6(uint64_t a, uint64_t b, uint64_t c){
  uint64_t csa_component6_out = 0;
  uint8_t csa_component6_fa0_xor1 = 0;
  uint8_t csa_component6_fa0_or0 = 0;
  uint8_t csa_component6_fa1_xor1 = 0;
  uint8_t csa_component6_fa1_or0 = 0;
  uint8_t csa_component6_fa2_xor1 = 0;
  uint8_t csa_component6_fa2_or0 = 0;
  uint8_t csa_component6_fa3_xor1 = 0;
  uint8_t csa_component6_fa3_or0 = 0;
  uint8_t csa_component6_fa4_xor1 = 0;
  uint8_t csa_component6_fa4_or0 = 0;
  uint8_t csa_component6_fa5_xor1 = 0;
  uint8_t csa_component6_fa5_or0 = 0;

  csa_component6_fa0_xor1 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 0) & 0x01;
  csa_component6_fa0_or0 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 1) & 0x01;
  csa_component6_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 0) & 0x01;
  csa_component6_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 1) & 0x01;
  csa_component6_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 0) & 0x01;
  csa_component6_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 1) & 0x01;
  csa_component6_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 0) & 0x01;
  csa_component6_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 1) & 0x01;
  csa_component6_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 0) & 0x01;
  csa_component6_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 1) & 0x01;
  csa_component6_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 0) & 0x01;
  csa_component6_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 1) & 0x01;

  csa_component6_out |= ((csa_component6_fa0_xor1 >> 0) & 0x01ull) << 0;
  csa_component6_out |= ((csa_component6_fa1_xor1 >> 0) & 0x01ull) << 1;
  csa_component6_out |= ((csa_component6_fa2_xor1 >> 0) & 0x01ull) << 2;
  csa_component6_out |= ((csa_component6_fa3_xor1 >> 0) & 0x01ull) << 3;
  csa_component6_out |= ((csa_component6_fa4_xor1 >> 0) & 0x01ull) << 4;
  csa_component6_out |= ((csa_component6_fa5_xor1 >> 0) & 0x01ull) << 5;
  csa_component6_out |= (0x00) << 6;
  csa_component6_out |= (0x00) << 7;
  csa_component6_out |= ((csa_component6_fa0_or0 >> 0) & 0x01ull) << 8;
  csa_component6_out |= ((csa_component6_fa1_or0 >> 0) & 0x01ull) << 9;
  csa_component6_out |= ((csa_component6_fa2_or0 >> 0) & 0x01ull) << 10;
  csa_component6_out |= ((csa_component6_fa3_or0 >> 0) & 0x01ull) << 11;
  csa_component6_out |= ((csa_component6_fa4_or0 >> 0) & 0x01ull) << 12;
  csa_component6_out |= ((csa_component6_fa5_or0 >> 0) & 0x01ull) << 13;
  return csa_component6_out;
}

uint64_t csa_component7(uint64_t a, uint64_t b, uint64_t c){
  uint64_t csa_component7_out = 0;
  uint8_t csa_component7_fa0_xor1 = 0;
  uint8_t csa_component7_fa0_or0 = 0;
  uint8_t csa_component7_fa1_xor1 = 0;
  uint8_t csa_component7_fa1_or0 = 0;
  uint8_t csa_component7_fa2_xor1 = 0;
  uint8_t csa_component7_fa2_or0 = 0;
  uint8_t csa_component7_fa3_xor1 = 0;
  uint8_t csa_component7_fa3_or0 = 0;
  uint8_t csa_component7_fa4_xor1 = 0;
  uint8_t csa_component7_fa4_or0 = 0;
  uint8_t csa_component7_fa5_xor1 = 0;
  uint8_t csa_component7_fa5_or0 = 0;
  uint8_t csa_component7_fa6_xor1 = 0;
  uint8_t csa_component7_fa6_or0 = 0;

  csa_component7_fa0_xor1 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 0) & 0x01;
  csa_component7_fa0_or0 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 1) & 0x01;
  csa_component7_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 0) & 0x01;
  csa_component7_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 1) & 0x01;
  csa_component7_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 0) & 0x01;
  csa_component7_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 1) & 0x01;
  csa_component7_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 0) & 0x01;
  csa_component7_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 1) & 0x01;
  csa_component7_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 0) & 0x01;
  csa_component7_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 1) & 0x01;
  csa_component7_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 0) & 0x01;
  csa_component7_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 1) & 0x01;
  csa_component7_fa6_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((c >> 6) & 0x01)) >> 0) & 0x01;
  csa_component7_fa6_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((c >> 6) & 0x01)) >> 1) & 0x01;

  csa_component7_out |= ((csa_component7_fa0_xor1 >> 0) & 0x01ull) << 0;
  csa_component7_out |= ((csa_component7_fa1_xor1 >> 0) & 0x01ull) << 1;
  csa_component7_out |= ((csa_component7_fa2_xor1 >> 0) & 0x01ull) << 2;
  csa_component7_out |= ((csa_component7_fa3_xor1 >> 0) & 0x01ull) << 3;
  csa_component7_out |= ((csa_component7_fa4_xor1 >> 0) & 0x01ull) << 4;
  csa_component7_out |= ((csa_component7_fa5_xor1 >> 0) & 0x01ull) << 5;
  csa_component7_out |= ((csa_component7_fa6_xor1 >> 0) & 0x01ull) << 6;
  csa_component7_out |= (0x00) << 7;
  csa_component7_out |= (0x00) << 8;
  csa_component7_out |= ((csa_component7_fa0_or0 >> 0) & 0x01ull) << 9;
  csa_component7_out |= ((csa_component7_fa1_or0 >> 0) & 0x01ull) << 10;
  csa_component7_out |= ((csa_component7_fa2_or0 >> 0) & 0x01ull) << 11;
  csa_component7_out |= ((csa_component7_fa3_or0 >> 0) & 0x01ull) << 12;
  csa_component7_out |= ((csa_component7_fa4_or0 >> 0) & 0x01ull) << 13;
  csa_component7_out |= ((csa_component7_fa5_or0 >> 0) & 0x01ull) << 14;
  csa_component7_out |= ((csa_component7_fa6_or0 >> 0) & 0x01ull) << 15;
  return csa_component7_out;
}

uint64_t u_rca8(uint64_t a, uint64_t b){
  uint64_t u_rca8_out = 0;
  uint8_t u_rca8_ha_xor0 = 0;
  uint8_t u_rca8_ha_and0 = 0;
  uint8_t u_rca8_fa1_xor1 = 0;
  uint8_t u_rca8_fa1_or0 = 0;
  uint8_t u_rca8_fa2_xor1 = 0;
  uint8_t u_rca8_fa2_or0 = 0;
  uint8_t u_rca8_fa3_xor1 = 0;
  uint8_t u_rca8_fa3_or0 = 0;
  uint8_t u_rca8_fa4_xor1 = 0;
  uint8_t u_rca8_fa4_or0 = 0;
  uint8_t u_rca8_fa5_xor1 = 0;
  uint8_t u_rca8_fa5_or0 = 0;
  uint8_t u_rca8_fa6_xor1 = 0;
  uint8_t u_rca8_fa6_or0 = 0;
  uint8_t u_rca8_fa7_xor1 = 0;
  uint8_t u_rca8_fa7_or0 = 0;

  u_rca8_ha_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_ha_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_rca8_ha_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_rca8_ha_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_rca8_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_rca8_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_rca8_fa2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_rca8_fa2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_rca8_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_rca8_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_rca8_fa4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_rca8_fa4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa6_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_rca8_fa5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa6_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_rca8_fa5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca8_fa7_xor1 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_rca8_fa6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca8_fa7_or0 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_rca8_fa6_or0 >> 0) & 0x01)) >> 1) & 0x01;

  u_rca8_out |= ((u_rca8_ha_xor0 >> 0) & 0x01ull) << 0;
  u_rca8_out |= ((u_rca8_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_rca8_out |= ((u_rca8_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_rca8_out |= ((u_rca8_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_rca8_out |= ((u_rca8_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_rca8_out |= ((u_rca8_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_rca8_out |= ((u_rca8_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_rca8_out |= ((u_rca8_fa7_xor1 >> 0) & 0x01ull) << 7;
  u_rca8_out |= ((u_rca8_fa7_or0 >> 0) & 0x01ull) << 8;
  return u_rca8_out;
}

int64_t s_CSAwallace_rca4(int64_t a, int64_t b){
  int8_t s_CSAwallace_rca4_out = 0;
  uint8_t s_CSAwallace_rca4_and_0_0 = 0;
  uint8_t s_CSAwallace_rca4_and_1_0 = 0;
  uint8_t s_CSAwallace_rca4_and_2_0 = 0;
  uint8_t s_CSAwallace_rca4_nand_3_0 = 0;
  uint8_t s_CSAwallace_rca4_and_0_1 = 0;
  uint8_t s_CSAwallace_rca4_and_1_1 = 0;
  uint8_t s_CSAwallace_rca4_and_2_1 = 0;
  uint8_t s_CSAwallace_rca4_nand_3_1 = 0;
  uint8_t s_CSAwallace_rca4_and_0_2 = 0;
  uint8_t s_CSAwallace_rca4_and_1_2 = 0;
  uint8_t s_CSAwallace_rca4_and_2_2 = 0;
  uint8_t s_CSAwallace_rca4_nand_3_2 = 0;
  uint8_t s_CSAwallace_rca4_nand_0_3 = 0;
  uint8_t s_CSAwallace_rca4_nand_1_3 = 0;
  uint8_t s_CSAwallace_rca4_nand_2_3 = 0;
  uint8_t s_CSAwallace_rca4_and_3_3 = 0;
  int64_t s_CSAwallace_rca4_csa0_csa_component_pp_row0 = 0;
  int64_t s_CSAwallace_rca4_csa0_csa_component_pp_row1 = 0;
  int64_t s_CSAwallace_rca4_csa0_csa_component_pp_row2 = 0;
  int64_t s_CSAwallace_rca4_csa0_csa_component_out = 0;
  int64_t s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 = 0;
  int64_t s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 = 0;
  int64_t s_CSAwallace_rca4_csa1_csa_component_pp_row3 = 0;
  int64_t s_CSAwallace_rca4_csa1_csa_component_out = 0;
  uint64_t s_CSAwallace_rca4_u_rca8_a = 0;
  uint64_t s_CSAwallace_rca4_u_rca8_b = 0;
  uint64_t s_CSAwallace_rca4_u_rca8_out = 0;
  uint8_t s_CSAwallace_rca4_xor0 = 0;

  s_CSAwallace_rca4_and_0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_rca4_and_1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_rca4_and_2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_rca4_nand_3_0 = nand_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_rca4_and_0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_rca4_and_1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_rca4_and_2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_rca4_nand_3_1 = nand_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_rca4_and_0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_rca4_and_1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_rca4_and_2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_rca4_nand_3_2 = nand_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_rca4_nand_0_3 = nand_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_rca4_nand_1_3 = nand_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_rca4_nand_2_3 = nand_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_rca4_and_3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_rca4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_rca4_and_0_0 >> 0) & 0x01ull) << 0;
  s_CSAwallace_rca4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_rca4_and_1_0 >> 0) & 0x01ull) << 1;
  s_CSAwallace_rca4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_rca4_and_2_0 >> 0) & 0x01ull) << 2;
  s_CSAwallace_rca4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_rca4_nand_3_0 >> 0) & 0x01ull) << 3;
  s_CSAwallace_rca4_csa0_csa_component_pp_row0 |= (0x01) << 4;
  s_CSAwallace_rca4_csa0_csa_component_pp_row0 |= (0x01) << 5;
  s_CSAwallace_rca4_csa0_csa_component_pp_row1 |= (0x00) << 0;
  s_CSAwallace_rca4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_rca4_and_0_1 >> 0) & 0x01ull) << 1;
  s_CSAwallace_rca4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_rca4_and_1_1 >> 0) & 0x01ull) << 2;
  s_CSAwallace_rca4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_rca4_and_2_1 >> 0) & 0x01ull) << 3;
  s_CSAwallace_rca4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_rca4_nand_3_1 >> 0) & 0x01ull) << 4;
  s_CSAwallace_rca4_csa0_csa_component_pp_row1 |= (0x01) << 5;
  s_CSAwallace_rca4_csa0_csa_component_pp_row2 |= (0x00) << 0;
  s_CSAwallace_rca4_csa0_csa_component_pp_row2 |= (0x00) << 1;
  s_CSAwallace_rca4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_rca4_and_0_2 >> 0) & 0x01ull) << 2;
  s_CSAwallace_rca4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_rca4_and_1_2 >> 0) & 0x01ull) << 3;
  s_CSAwallace_rca4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_rca4_and_2_2 >> 0) & 0x01ull) << 4;
  s_CSAwallace_rca4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_rca4_nand_3_2 >> 0) & 0x01ull) << 5;
  s_CSAwallace_rca4_csa0_csa_component_out = csa_component6(s_CSAwallace_rca4_csa0_csa_component_pp_row0, s_CSAwallace_rca4_csa0_csa_component_pp_row1, s_CSAwallace_rca4_csa0_csa_component_pp_row2);
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 0) & 0x01ull) << 0;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 1) & 0x01ull) << 1;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 2) & 0x01ull) << 2;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 3) & 0x01ull) << 3;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 4) & 0x01ull) << 4;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 5) & 0x01ull) << 5;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1 |= (0x01) << 6;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= (0x00) << 0;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= (0x00) << 1;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 9) & 0x01ull) << 2;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 10) & 0x01ull) << 3;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 11) & 0x01ull) << 4;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= ((s_CSAwallace_rca4_csa0_csa_component_out >> 12) & 0x01ull) << 5;
  s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1 |= (0x01) << 6;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= (0x00) << 0;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= (0x00) << 1;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= (0x00) << 2;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_rca4_nand_0_3 >> 0) & 0x01ull) << 3;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_rca4_nand_1_3 >> 0) & 0x01ull) << 4;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_rca4_nand_2_3 >> 0) & 0x01ull) << 5;
  s_CSAwallace_rca4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_rca4_and_3_3 >> 0) & 0x01ull) << 6;
  s_CSAwallace_rca4_csa1_csa_component_out = csa_component7(s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_s1, s_CSAwallace_rca4_csa1_csa_component_s_CSAwallace_rca4_csa_c1, s_CSAwallace_rca4_csa1_csa_component_pp_row3);
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 0) & 0x01ull) << 0;
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 1) & 0x01ull) << 1;
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 2) & 0x01ull) << 2;
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 3) & 0x01ull) << 3;
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 4) & 0x01ull) << 4;
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 5) & 0x01ull) << 5;
  s_CSAwallace_rca4_u_rca8_a |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 6) & 0x01ull) << 6;
  s_CSAwallace_rca4_u_rca8_a |= (0x01) << 7;
  s_CSAwallace_rca4_u_rca8_b |= (0x00) << 0;
  s_CSAwallace_rca4_u_rca8_b |= (0x00) << 1;
  s_CSAwallace_rca4_u_rca8_b |= (0x00) << 2;
  s_CSAwallace_rca4_u_rca8_b |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 11) & 0x01ull) << 3;
  s_CSAwallace_rca4_u_rca8_b |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 12) & 0x01ull) << 4;
  s_CSAwallace_rca4_u_rca8_b |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 13) & 0x01ull) << 5;
  s_CSAwallace_rca4_u_rca8_b |= ((s_CSAwallace_rca4_csa1_csa_component_out >> 14) & 0x01ull) << 6;
  s_CSAwallace_rca4_u_rca8_b |= (0x01) << 7;
  s_CSAwallace_rca4_u_rca8_out = u_rca8(s_CSAwallace_rca4_u_rca8_a, s_CSAwallace_rca4_u_rca8_b);
  s_CSAwallace_rca4_xor0 = not_gate(((s_CSAwallace_rca4_u_rca8_out >> 7) & 0x01));

  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 0) & 0x01ull) << 0;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 1) & 0x01ull) << 1;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 2) & 0x01ull) << 2;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 3) & 0x01ull) << 3;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 4) & 0x01ull) << 4;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 5) & 0x01ull) << 5;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_u_rca8_out >> 6) & 0x01ull) << 6;
  s_CSAwallace_rca4_out |= ((s_CSAwallace_rca4_xor0 >> 0) & 0x01ull) << 7;
  return s_CSAwallace_rca4_out;
}