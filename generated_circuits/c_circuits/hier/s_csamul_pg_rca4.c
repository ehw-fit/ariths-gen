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

  ha_out |= ((ha_xor0 >> 0) & 0x01ull) << 0;
  ha_out |= ((ha_and0 >> 0) & 0x01ull) << 1;
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

  fa_out |= ((fa_xor1 >> 0) & 0x01ull) << 0;
  fa_out |= ((fa_or0 >> 0) & 0x01ull) << 1;
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

  pg_fa_out |= ((pg_fa_xor0 >> 0) & 0x01ull) << 0;
  pg_fa_out |= ((pg_fa_and0 >> 0) & 0x01ull) << 1;
  pg_fa_out |= ((pg_fa_xor1 >> 0) & 0x01ull) << 2;
  return pg_fa_out;
}

uint64_t u_pg_rca4(uint64_t a, uint64_t b){
  uint8_t u_pg_rca4_out = 0;
  uint8_t u_pg_rca4_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa0_and0 = 0;
  uint8_t u_pg_rca4_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa1_and0 = 0;
  uint8_t u_pg_rca4_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca4_and1 = 0;
  uint8_t u_pg_rca4_or1 = 0;
  uint8_t u_pg_rca4_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa2_and0 = 0;
  uint8_t u_pg_rca4_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca4_and2 = 0;
  uint8_t u_pg_rca4_or2 = 0;
  uint8_t u_pg_rca4_pg_fa3_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa3_and0 = 0;
  uint8_t u_pg_rca4_pg_fa3_xor1 = 0;
  uint8_t u_pg_rca4_and3 = 0;
  uint8_t u_pg_rca4_or3 = 0;

  u_pg_rca4_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  u_pg_rca4_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  u_pg_rca4_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca4_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca4_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca4_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca4_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca4_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca4_and1 = and_gate(((u_pg_rca4_pg_fa0_and0 >> 0) & 0x01), ((u_pg_rca4_pg_fa1_xor0 >> 0) & 0x01));
  u_pg_rca4_or1 = or_gate(((u_pg_rca4_and1 >> 0) & 0x01), ((u_pg_rca4_pg_fa1_and0 >> 0) & 0x01));
  u_pg_rca4_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca4_or1 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca4_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca4_or1 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca4_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca4_or1 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca4_and2 = and_gate(((u_pg_rca4_or1 >> 0) & 0x01), ((u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01));
  u_pg_rca4_or2 = or_gate(((u_pg_rca4_and2 >> 0) & 0x01), ((u_pg_rca4_pg_fa2_and0 >> 0) & 0x01));
  u_pg_rca4_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca4_or2 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca4_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca4_or2 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca4_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca4_or2 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca4_and3 = and_gate(((u_pg_rca4_or2 >> 0) & 0x01), ((u_pg_rca4_pg_fa3_xor0 >> 0) & 0x01));
  u_pg_rca4_or3 = or_gate(((u_pg_rca4_and3 >> 0) & 0x01), ((u_pg_rca4_pg_fa3_and0 >> 0) & 0x01));

  u_pg_rca4_out |= ((u_pg_rca4_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca4_out |= ((u_pg_rca4_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca4_out |= ((u_pg_rca4_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca4_out |= ((u_pg_rca4_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_pg_rca4_out |= ((u_pg_rca4_or3 >> 0) & 0x01ull) << 4;
  return u_pg_rca4_out;
}

int64_t s_csamul_pg_rca4(int64_t a, int64_t b){
  int8_t s_csamul_pg_rca4_out = 0;
  uint8_t s_csamul_pg_rca4_and0_0 = 0;
  uint8_t s_csamul_pg_rca4_and1_0 = 0;
  uint8_t s_csamul_pg_rca4_and2_0 = 0;
  uint8_t s_csamul_pg_rca4_nand3_0 = 0;
  uint8_t s_csamul_pg_rca4_and0_1 = 0;
  uint8_t s_csamul_pg_rca4_ha0_1_xor0 = 0;
  uint8_t s_csamul_pg_rca4_ha0_1_and0 = 0;
  uint8_t s_csamul_pg_rca4_and1_1 = 0;
  uint8_t s_csamul_pg_rca4_ha1_1_xor0 = 0;
  uint8_t s_csamul_pg_rca4_ha1_1_and0 = 0;
  uint8_t s_csamul_pg_rca4_and2_1 = 0;
  uint8_t s_csamul_pg_rca4_ha2_1_xor0 = 0;
  uint8_t s_csamul_pg_rca4_ha2_1_and0 = 0;
  uint8_t s_csamul_pg_rca4_nand3_1 = 0;
  uint8_t s_csamul_pg_rca4_ha3_1_xor0 = 0;
  uint8_t s_csamul_pg_rca4_and0_2 = 0;
  uint8_t s_csamul_pg_rca4_fa0_2_xor1 = 0;
  uint8_t s_csamul_pg_rca4_fa0_2_or0 = 0;
  uint8_t s_csamul_pg_rca4_and1_2 = 0;
  uint8_t s_csamul_pg_rca4_fa1_2_xor1 = 0;
  uint8_t s_csamul_pg_rca4_fa1_2_or0 = 0;
  uint8_t s_csamul_pg_rca4_and2_2 = 0;
  uint8_t s_csamul_pg_rca4_fa2_2_xor1 = 0;
  uint8_t s_csamul_pg_rca4_fa2_2_or0 = 0;
  uint8_t s_csamul_pg_rca4_nand3_2 = 0;
  uint8_t s_csamul_pg_rca4_ha3_2_xor0 = 0;
  uint8_t s_csamul_pg_rca4_ha3_2_and0 = 0;
  uint8_t s_csamul_pg_rca4_nand0_3 = 0;
  uint8_t s_csamul_pg_rca4_fa0_3_xor1 = 0;
  uint8_t s_csamul_pg_rca4_fa0_3_or0 = 0;
  uint8_t s_csamul_pg_rca4_nand1_3 = 0;
  uint8_t s_csamul_pg_rca4_fa1_3_xor1 = 0;
  uint8_t s_csamul_pg_rca4_fa1_3_or0 = 0;
  uint8_t s_csamul_pg_rca4_nand2_3 = 0;
  uint8_t s_csamul_pg_rca4_fa2_3_xor1 = 0;
  uint8_t s_csamul_pg_rca4_fa2_3_or0 = 0;
  uint8_t s_csamul_pg_rca4_and3_3 = 0;
  uint8_t s_csamul_pg_rca4_ha3_3_xor0 = 0;
  uint8_t s_csamul_pg_rca4_ha3_3_and0 = 0;
  uint64_t s_csamul_pg_rca4_u_pg_rca4_a = 0;
  uint64_t s_csamul_pg_rca4_u_pg_rca4_b = 0;
  uint64_t s_csamul_pg_rca4_u_pg_rca4_out = 0;

  s_csamul_pg_rca4_and0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  s_csamul_pg_rca4_and1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  s_csamul_pg_rca4_and2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  s_csamul_pg_rca4_nand3_0 = nand_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  s_csamul_pg_rca4_and0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  s_csamul_pg_rca4_ha0_1_xor0 = (ha(((s_csamul_pg_rca4_and0_1 >> 0) & 0x01), ((s_csamul_pg_rca4_and1_0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_ha0_1_and0 = (ha(((s_csamul_pg_rca4_and0_1 >> 0) & 0x01), ((s_csamul_pg_rca4_and1_0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_and1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  s_csamul_pg_rca4_ha1_1_xor0 = (ha(((s_csamul_pg_rca4_and1_1 >> 0) & 0x01), ((s_csamul_pg_rca4_and2_0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_ha1_1_and0 = (ha(((s_csamul_pg_rca4_and1_1 >> 0) & 0x01), ((s_csamul_pg_rca4_and2_0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_and2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  s_csamul_pg_rca4_ha2_1_xor0 = (ha(((s_csamul_pg_rca4_and2_1 >> 0) & 0x01), ((s_csamul_pg_rca4_nand3_0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_ha2_1_and0 = (ha(((s_csamul_pg_rca4_and2_1 >> 0) & 0x01), ((s_csamul_pg_rca4_nand3_0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_nand3_1 = nand_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  s_csamul_pg_rca4_ha3_1_xor0 = (ha(((s_csamul_pg_rca4_nand3_1 >> 0) & 0x01), (0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_and0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  s_csamul_pg_rca4_fa0_2_xor1 = (fa(((s_csamul_pg_rca4_and0_2 >> 0) & 0x01), ((s_csamul_pg_rca4_ha1_1_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_ha0_1_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_fa0_2_or0 = (fa(((s_csamul_pg_rca4_and0_2 >> 0) & 0x01), ((s_csamul_pg_rca4_ha1_1_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_ha0_1_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_and1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  s_csamul_pg_rca4_fa1_2_xor1 = (fa(((s_csamul_pg_rca4_and1_2 >> 0) & 0x01), ((s_csamul_pg_rca4_ha2_1_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_ha1_1_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_fa1_2_or0 = (fa(((s_csamul_pg_rca4_and1_2 >> 0) & 0x01), ((s_csamul_pg_rca4_ha2_1_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_ha1_1_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_and2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  s_csamul_pg_rca4_fa2_2_xor1 = (fa(((s_csamul_pg_rca4_and2_2 >> 0) & 0x01), ((s_csamul_pg_rca4_ha3_1_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_ha2_1_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_fa2_2_or0 = (fa(((s_csamul_pg_rca4_and2_2 >> 0) & 0x01), ((s_csamul_pg_rca4_ha3_1_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_ha2_1_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_nand3_2 = nand_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  s_csamul_pg_rca4_ha3_2_xor0 = (ha(((s_csamul_pg_rca4_nand3_2 >> 0) & 0x01), ((s_csamul_pg_rca4_nand3_1 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_ha3_2_and0 = (ha(((s_csamul_pg_rca4_nand3_2 >> 0) & 0x01), ((s_csamul_pg_rca4_nand3_1 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_nand0_3 = nand_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  s_csamul_pg_rca4_fa0_3_xor1 = (fa(((s_csamul_pg_rca4_nand0_3 >> 0) & 0x01), ((s_csamul_pg_rca4_fa1_2_xor1 >> 0) & 0x01), ((s_csamul_pg_rca4_fa0_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_fa0_3_or0 = (fa(((s_csamul_pg_rca4_nand0_3 >> 0) & 0x01), ((s_csamul_pg_rca4_fa1_2_xor1 >> 0) & 0x01), ((s_csamul_pg_rca4_fa0_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_nand1_3 = nand_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  s_csamul_pg_rca4_fa1_3_xor1 = (fa(((s_csamul_pg_rca4_nand1_3 >> 0) & 0x01), ((s_csamul_pg_rca4_fa2_2_xor1 >> 0) & 0x01), ((s_csamul_pg_rca4_fa1_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_fa1_3_or0 = (fa(((s_csamul_pg_rca4_nand1_3 >> 0) & 0x01), ((s_csamul_pg_rca4_fa2_2_xor1 >> 0) & 0x01), ((s_csamul_pg_rca4_fa1_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_nand2_3 = nand_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  s_csamul_pg_rca4_fa2_3_xor1 = (fa(((s_csamul_pg_rca4_nand2_3 >> 0) & 0x01), ((s_csamul_pg_rca4_ha3_2_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_fa2_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_fa2_3_or0 = (fa(((s_csamul_pg_rca4_nand2_3 >> 0) & 0x01), ((s_csamul_pg_rca4_ha3_2_xor0 >> 0) & 0x01), ((s_csamul_pg_rca4_fa2_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_and3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_csamul_pg_rca4_ha3_3_xor0 = (ha(((s_csamul_pg_rca4_and3_3 >> 0) & 0x01), ((s_csamul_pg_rca4_ha3_2_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_csamul_pg_rca4_ha3_3_and0 = (ha(((s_csamul_pg_rca4_and3_3 >> 0) & 0x01), ((s_csamul_pg_rca4_ha3_2_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_csamul_pg_rca4_u_pg_rca4_a |= ((s_csamul_pg_rca4_fa1_3_xor1 >> 0) & 0x01ull) << 0;
  s_csamul_pg_rca4_u_pg_rca4_a |= ((s_csamul_pg_rca4_fa2_3_xor1 >> 0) & 0x01ull) << 1;
  s_csamul_pg_rca4_u_pg_rca4_a |= ((s_csamul_pg_rca4_ha3_3_xor0 >> 0) & 0x01ull) << 2;
  s_csamul_pg_rca4_u_pg_rca4_a |= (0x01) << 3;
  s_csamul_pg_rca4_u_pg_rca4_b |= ((s_csamul_pg_rca4_fa0_3_or0 >> 0) & 0x01ull) << 0;
  s_csamul_pg_rca4_u_pg_rca4_b |= ((s_csamul_pg_rca4_fa1_3_or0 >> 0) & 0x01ull) << 1;
  s_csamul_pg_rca4_u_pg_rca4_b |= ((s_csamul_pg_rca4_fa2_3_or0 >> 0) & 0x01ull) << 2;
  s_csamul_pg_rca4_u_pg_rca4_b |= ((s_csamul_pg_rca4_ha3_3_and0 >> 0) & 0x01ull) << 3;
  s_csamul_pg_rca4_u_pg_rca4_out = u_pg_rca4(s_csamul_pg_rca4_u_pg_rca4_a, s_csamul_pg_rca4_u_pg_rca4_b);

  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_and0_0 >> 0) & 0x01ull) << 0;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_ha0_1_xor0 >> 0) & 0x01ull) << 1;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_fa0_2_xor1 >> 0) & 0x01ull) << 2;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_fa0_3_xor1 >> 0) & 0x01ull) << 3;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_u_pg_rca4_out >> 0) & 0x01ull) << 4;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_u_pg_rca4_out >> 1) & 0x01ull) << 5;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_u_pg_rca4_out >> 2) & 0x01ull) << 6;
  s_csamul_pg_rca4_out |= ((s_csamul_pg_rca4_u_pg_rca4_out >> 3) & 0x01ull) << 7;
  return s_csamul_pg_rca4_out;
}