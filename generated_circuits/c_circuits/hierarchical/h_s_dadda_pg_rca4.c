#include <stdio.h>
#include <stdint.h>

uint8_t nand_gate(uint8_t a, uint8_t b){
  return ~(((a >> 0) & 0x01) & ((b >> 0) & 0x01)) & 0x01;
}

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
}

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t ha_out = 0;
  uint8_t ha_xor0 = 0;
  uint8_t ha_and0 = 0;

  ha_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  ha_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));

  ha_out |= ((ha_xor0 >> 0) & 0x01) << 0;
  ha_out |= ((ha_and0 >> 0) & 0x01) << 1;
  return ha_out;
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

  fa_out |= ((fa_xor1 >> 0) & 0x01) << 0;
  fa_out |= ((fa_or0 >> 0) & 0x01) << 1;
  return fa_out;
}

uint8_t pg_fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t pg_fa_out = 0;
  uint8_t pg_fa_xor0 = 0;
  uint8_t pg_fa_and0 = 0;
  uint8_t pg_fa_xor1 = 0;

  pg_fa_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  pg_fa_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  pg_fa_xor1 = xor_gate(((pg_fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));

  pg_fa_out |= ((pg_fa_xor0 >> 0) & 0x01) << 0;
  pg_fa_out |= ((pg_fa_and0 >> 0) & 0x01) << 1;
  pg_fa_out |= ((pg_fa_xor1 >> 0) & 0x01) << 2;
  return pg_fa_out;
}

uint64_t u_pg_rca6(uint64_t a, uint64_t b){
  uint8_t u_pg_rca6_out = 0;
  uint8_t u_pg_rca6_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca6_pg_fa0_and0 = 0;
  uint8_t u_pg_rca6_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca6_pg_fa1_and0 = 0;
  uint8_t u_pg_rca6_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca6_and1 = 0;
  uint8_t u_pg_rca6_or1 = 0;
  uint8_t u_pg_rca6_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca6_pg_fa2_and0 = 0;
  uint8_t u_pg_rca6_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca6_and2 = 0;
  uint8_t u_pg_rca6_or2 = 0;
  uint8_t u_pg_rca6_pg_fa3_xor0 = 0;
  uint8_t u_pg_rca6_pg_fa3_and0 = 0;
  uint8_t u_pg_rca6_pg_fa3_xor1 = 0;
  uint8_t u_pg_rca6_and3 = 0;
  uint8_t u_pg_rca6_or3 = 0;
  uint8_t u_pg_rca6_pg_fa4_xor0 = 0;
  uint8_t u_pg_rca6_pg_fa4_and0 = 0;
  uint8_t u_pg_rca6_pg_fa4_xor1 = 0;
  uint8_t u_pg_rca6_and4 = 0;
  uint8_t u_pg_rca6_or4 = 0;
  uint8_t u_pg_rca6_pg_fa5_xor0 = 0;
  uint8_t u_pg_rca6_pg_fa5_and0 = 0;
  uint8_t u_pg_rca6_pg_fa5_xor1 = 0;
  uint8_t u_pg_rca6_and5 = 0;
  uint8_t u_pg_rca6_or5 = 0;

  u_pg_rca6_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  u_pg_rca6_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  u_pg_rca6_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca6_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca6_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca6_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca6_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca6_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca6_and1 = and_gate(((u_pg_rca6_pg_fa0_and0 >> 0) & 0x01), ((u_pg_rca6_pg_fa1_xor0 >> 0) & 0x01));
  u_pg_rca6_or1 = or_gate(((u_pg_rca6_and1 >> 0) & 0x01), ((u_pg_rca6_pg_fa1_and0 >> 0) & 0x01));
  u_pg_rca6_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca6_or1 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca6_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca6_or1 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca6_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca6_or1 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca6_and2 = and_gate(((u_pg_rca6_or1 >> 0) & 0x01), ((u_pg_rca6_pg_fa2_xor0 >> 0) & 0x01));
  u_pg_rca6_or2 = or_gate(((u_pg_rca6_and2 >> 0) & 0x01), ((u_pg_rca6_pg_fa2_and0 >> 0) & 0x01));
  u_pg_rca6_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca6_or2 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca6_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca6_or2 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca6_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca6_or2 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca6_and3 = and_gate(((u_pg_rca6_or2 >> 0) & 0x01), ((u_pg_rca6_pg_fa3_xor0 >> 0) & 0x01));
  u_pg_rca6_or3 = or_gate(((u_pg_rca6_and3 >> 0) & 0x01), ((u_pg_rca6_pg_fa3_and0 >> 0) & 0x01));
  u_pg_rca6_pg_fa4_xor0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca6_or3 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca6_pg_fa4_and0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca6_or3 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca6_pg_fa4_xor1 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca6_or3 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca6_and4 = and_gate(((u_pg_rca6_or3 >> 0) & 0x01), ((u_pg_rca6_pg_fa4_xor0 >> 0) & 0x01));
  u_pg_rca6_or4 = or_gate(((u_pg_rca6_and4 >> 0) & 0x01), ((u_pg_rca6_pg_fa4_and0 >> 0) & 0x01));
  u_pg_rca6_pg_fa5_xor0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca6_or4 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca6_pg_fa5_and0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca6_or4 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca6_pg_fa5_xor1 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca6_or4 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca6_and5 = and_gate(((u_pg_rca6_or4 >> 0) & 0x01), ((u_pg_rca6_pg_fa5_xor0 >> 0) & 0x01));
  u_pg_rca6_or5 = or_gate(((u_pg_rca6_and5 >> 0) & 0x01), ((u_pg_rca6_pg_fa5_and0 >> 0) & 0x01));

  u_pg_rca6_out |= ((u_pg_rca6_pg_fa0_xor0 >> 0) & 0x01) << 0;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa1_xor1 >> 0) & 0x01) << 1;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa2_xor1 >> 0) & 0x01) << 2;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa3_xor1 >> 0) & 0x01) << 3;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa4_xor1 >> 0) & 0x01) << 4;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa5_xor1 >> 0) & 0x01) << 5;
  u_pg_rca6_out |= ((u_pg_rca6_or5 >> 0) & 0x01) << 6;
  return u_pg_rca6_out;
}

uint64_t h_s_dadda_pg_rca4(uint64_t a, uint64_t b){
  uint8_t h_s_dadda_pg_rca4_out = 0;
  uint8_t h_s_dadda_pg_rca4_nand_3_0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_2_1 = 0;
  uint8_t h_s_dadda_pg_rca4_ha0_xor0 = 0;
  uint8_t h_s_dadda_pg_rca4_ha0_and0 = 0;
  uint8_t h_s_dadda_pg_rca4_nand_3_1 = 0;
  uint8_t h_s_dadda_pg_rca4_fa0_xor1 = 0;
  uint8_t h_s_dadda_pg_rca4_fa0_or0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_2_0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_1_1 = 0;
  uint8_t h_s_dadda_pg_rca4_ha1_xor0 = 0;
  uint8_t h_s_dadda_pg_rca4_ha1_and0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_1_2 = 0;
  uint8_t h_s_dadda_pg_rca4_nand_0_3 = 0;
  uint8_t h_s_dadda_pg_rca4_fa1_xor1 = 0;
  uint8_t h_s_dadda_pg_rca4_fa1_or0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_2_2 = 0;
  uint8_t h_s_dadda_pg_rca4_nand_1_3 = 0;
  uint8_t h_s_dadda_pg_rca4_fa2_xor1 = 0;
  uint8_t h_s_dadda_pg_rca4_fa2_or0 = 0;
  uint8_t h_s_dadda_pg_rca4_nand_3_2 = 0;
  uint8_t h_s_dadda_pg_rca4_fa3_xor1 = 0;
  uint8_t h_s_dadda_pg_rca4_fa3_or0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_0_0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_1_0 = 0;
  uint8_t h_s_dadda_pg_rca4_and_0_2 = 0;
  uint8_t h_s_dadda_pg_rca4_nand_2_3 = 0;
  uint8_t h_s_dadda_pg_rca4_and_0_1 = 0;
  uint8_t h_s_dadda_pg_rca4_and_3_3 = 0;
  uint64_t h_s_dadda_pg_rca4_u_pg_rca6_a = 0;
  uint64_t h_s_dadda_pg_rca4_u_pg_rca6_b = 0;
  uint64_t h_s_dadda_pg_rca4_u_pg_rca6_out = 0;
  uint8_t h_s_dadda_pg_rca4_xor0 = 0;

  h_s_dadda_pg_rca4_nand_3_0 = nand_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  h_s_dadda_pg_rca4_and_2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  h_s_dadda_pg_rca4_ha0_xor0 = (ha(((h_s_dadda_pg_rca4_nand_3_0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_2_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_s_dadda_pg_rca4_ha0_and0 = (ha(((h_s_dadda_pg_rca4_nand_3_0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_2_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_s_dadda_pg_rca4_nand_3_1 = nand_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  h_s_dadda_pg_rca4_fa0_xor1 = (fa(((h_s_dadda_pg_rca4_ha0_and0 >> 0) & 0x01), (0x01), ((h_s_dadda_pg_rca4_nand_3_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_s_dadda_pg_rca4_fa0_or0 = (fa(((h_s_dadda_pg_rca4_ha0_and0 >> 0) & 0x01), (0x01), ((h_s_dadda_pg_rca4_nand_3_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_s_dadda_pg_rca4_and_2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  h_s_dadda_pg_rca4_and_1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  h_s_dadda_pg_rca4_ha1_xor0 = (ha(((h_s_dadda_pg_rca4_and_2_0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_1_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_s_dadda_pg_rca4_ha1_and0 = (ha(((h_s_dadda_pg_rca4_and_2_0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_1_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_s_dadda_pg_rca4_and_1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  h_s_dadda_pg_rca4_nand_0_3 = nand_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  h_s_dadda_pg_rca4_fa1_xor1 = (fa(((h_s_dadda_pg_rca4_ha1_and0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_1_2 >> 0) & 0x01), ((h_s_dadda_pg_rca4_nand_0_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_s_dadda_pg_rca4_fa1_or0 = (fa(((h_s_dadda_pg_rca4_ha1_and0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_1_2 >> 0) & 0x01), ((h_s_dadda_pg_rca4_nand_0_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_s_dadda_pg_rca4_and_2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  h_s_dadda_pg_rca4_nand_1_3 = nand_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  h_s_dadda_pg_rca4_fa2_xor1 = (fa(((h_s_dadda_pg_rca4_fa1_or0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_2_2 >> 0) & 0x01), ((h_s_dadda_pg_rca4_nand_1_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_s_dadda_pg_rca4_fa2_or0 = (fa(((h_s_dadda_pg_rca4_fa1_or0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_and_2_2 >> 0) & 0x01), ((h_s_dadda_pg_rca4_nand_1_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_s_dadda_pg_rca4_nand_3_2 = nand_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  h_s_dadda_pg_rca4_fa3_xor1 = (fa(((h_s_dadda_pg_rca4_fa2_or0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_fa0_or0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_nand_3_2 >> 0) & 0x01)) >> 0) & 0x01;
  h_s_dadda_pg_rca4_fa3_or0 = (fa(((h_s_dadda_pg_rca4_fa2_or0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_fa0_or0 >> 0) & 0x01), ((h_s_dadda_pg_rca4_nand_3_2 >> 0) & 0x01)) >> 1) & 0x01;
  h_s_dadda_pg_rca4_and_0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  h_s_dadda_pg_rca4_and_1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  h_s_dadda_pg_rca4_and_0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  h_s_dadda_pg_rca4_nand_2_3 = nand_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  h_s_dadda_pg_rca4_and_0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  h_s_dadda_pg_rca4_and_3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  h_s_dadda_pg_rca4_u_pg_rca6_a |= ((h_s_dadda_pg_rca4_and_1_0 >> 0) & 0x01) << 0;
  h_s_dadda_pg_rca4_u_pg_rca6_a |= ((h_s_dadda_pg_rca4_and_0_2 >> 0) & 0x01) << 1;
  h_s_dadda_pg_rca4_u_pg_rca6_a |= ((h_s_dadda_pg_rca4_ha0_xor0 >> 0) & 0x01) << 2;
  h_s_dadda_pg_rca4_u_pg_rca6_a |= ((h_s_dadda_pg_rca4_fa0_xor1 >> 0) & 0x01) << 3;
  h_s_dadda_pg_rca4_u_pg_rca6_a |= ((h_s_dadda_pg_rca4_nand_2_3 >> 0) & 0x01) << 4;
  h_s_dadda_pg_rca4_u_pg_rca6_a |= ((h_s_dadda_pg_rca4_fa3_or0 >> 0) & 0x01) << 5;
  h_s_dadda_pg_rca4_u_pg_rca6_b |= ((h_s_dadda_pg_rca4_and_0_1 >> 0) & 0x01) << 0;
  h_s_dadda_pg_rca4_u_pg_rca6_b |= ((h_s_dadda_pg_rca4_ha1_xor0 >> 0) & 0x01) << 1;
  h_s_dadda_pg_rca4_u_pg_rca6_b |= ((h_s_dadda_pg_rca4_fa1_xor1 >> 0) & 0x01) << 2;
  h_s_dadda_pg_rca4_u_pg_rca6_b |= ((h_s_dadda_pg_rca4_fa2_xor1 >> 0) & 0x01) << 3;
  h_s_dadda_pg_rca4_u_pg_rca6_b |= ((h_s_dadda_pg_rca4_fa3_xor1 >> 0) & 0x01) << 4;
  h_s_dadda_pg_rca4_u_pg_rca6_b |= ((h_s_dadda_pg_rca4_and_3_3 >> 0) & 0x01) << 5;
  h_s_dadda_pg_rca4_u_pg_rca6_out = u_pg_rca6(h_s_dadda_pg_rca4_u_pg_rca6_a, h_s_dadda_pg_rca4_u_pg_rca6_b);
  h_s_dadda_pg_rca4_xor0 = not_gate(((h_s_dadda_pg_rca4_u_pg_rca6_out >> 6) & 0x01));

  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_and_0_0 >> 0) & 0x01) << 0;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_u_pg_rca6_out >> 0) & 0x01) << 1;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_u_pg_rca6_out >> 1) & 0x01) << 2;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_u_pg_rca6_out >> 2) & 0x01) << 3;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_u_pg_rca6_out >> 3) & 0x01) << 4;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_u_pg_rca6_out >> 4) & 0x01) << 5;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_u_pg_rca6_out >> 5) & 0x01) << 6;
  h_s_dadda_pg_rca4_out |= ((h_s_dadda_pg_rca4_xor0 >> 0) & 0x01) << 7;
  return h_s_dadda_pg_rca4_out;
}