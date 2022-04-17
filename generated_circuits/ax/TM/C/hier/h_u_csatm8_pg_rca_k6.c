#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
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

uint64_t u_pg_rca2(uint64_t a, uint64_t b){
  uint8_t u_pg_rca2_out = 0;
  uint8_t u_pg_rca2_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca2_pg_fa0_and0 = 0;
  uint8_t u_pg_rca2_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca2_pg_fa1_and0 = 0;
  uint8_t u_pg_rca2_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca2_and1 = 0;
  uint8_t u_pg_rca2_or1 = 0;

  u_pg_rca2_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  u_pg_rca2_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  u_pg_rca2_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca2_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca2_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca2_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca2_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca2_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca2_and1 = and_gate(((u_pg_rca2_pg_fa0_and0 >> 0) & 0x01), ((u_pg_rca2_pg_fa1_xor0 >> 0) & 0x01));
  u_pg_rca2_or1 = or_gate(((u_pg_rca2_and1 >> 0) & 0x01), ((u_pg_rca2_pg_fa1_and0 >> 0) & 0x01));

  u_pg_rca2_out |= ((u_pg_rca2_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca2_out |= ((u_pg_rca2_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca2_out |= ((u_pg_rca2_or1 >> 0) & 0x01ull) << 2;
  return u_pg_rca2_out;
}

uint64_t h_u_csatm8_pg_rca_k6(uint64_t a, uint64_t b){
  uint64_t h_u_csatm8_pg_rca_k6_out = 0;
  uint8_t h_u_csatm8_pg_rca_k6_and6_6 = 0;
  uint8_t h_u_csatm8_pg_rca_k6_and7_6 = 0;
  uint8_t h_u_csatm8_pg_rca_k6_and6_7 = 0;
  uint8_t h_u_csatm8_pg_rca_k6_ha6_7_xor0 = 0;
  uint8_t h_u_csatm8_pg_rca_k6_ha6_7_and0 = 0;
  uint8_t h_u_csatm8_pg_rca_k6_and7_7 = 0;
  uint64_t h_u_csatm8_pg_rca_k6_u_pg_rca2_a = 0;
  uint64_t h_u_csatm8_pg_rca_k6_u_pg_rca2_b = 0;
  uint64_t h_u_csatm8_pg_rca_k6_u_pg_rca2_out = 0;

  h_u_csatm8_pg_rca_k6_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_pg_rca_k6_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_pg_rca_k6_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_pg_rca_k6_ha6_7_xor0 = (ha(((h_u_csatm8_pg_rca_k6_and6_7 >> 0) & 0x01), ((h_u_csatm8_pg_rca_k6_and7_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_pg_rca_k6_ha6_7_and0 = (ha(((h_u_csatm8_pg_rca_k6_and6_7 >> 0) & 0x01), ((h_u_csatm8_pg_rca_k6_and7_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_pg_rca_k6_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_pg_rca_k6_u_pg_rca2_a |= ((h_u_csatm8_pg_rca_k6_and7_7 >> 0) & 0x01ull) << 0;
  h_u_csatm8_pg_rca_k6_u_pg_rca2_a |= (0x00) << 1;
  h_u_csatm8_pg_rca_k6_u_pg_rca2_b |= ((h_u_csatm8_pg_rca_k6_ha6_7_and0 >> 0) & 0x01ull) << 0;
  h_u_csatm8_pg_rca_k6_u_pg_rca2_b |= (0x00) << 1;
  h_u_csatm8_pg_rca_k6_u_pg_rca2_out = u_pg_rca2(h_u_csatm8_pg_rca_k6_u_pg_rca2_a, h_u_csatm8_pg_rca_k6_u_pg_rca2_b);

  h_u_csatm8_pg_rca_k6_out |= (0x00) << 0;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 1;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 2;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 3;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 4;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 5;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 6;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 7;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 8;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 9;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 10;
  h_u_csatm8_pg_rca_k6_out |= (0x00) << 11;
  h_u_csatm8_pg_rca_k6_out |= ((h_u_csatm8_pg_rca_k6_and6_6 >> 0) & 0x01ull) << 12;
  h_u_csatm8_pg_rca_k6_out |= ((h_u_csatm8_pg_rca_k6_ha6_7_xor0 >> 0) & 0x01ull) << 13;
  h_u_csatm8_pg_rca_k6_out |= ((h_u_csatm8_pg_rca_k6_u_pg_rca2_out >> 0) & 0x01ull) << 14;
  h_u_csatm8_pg_rca_k6_out |= ((h_u_csatm8_pg_rca_k6_u_pg_rca2_out >> 1) & 0x01ull) << 15;
  return h_u_csatm8_pg_rca_k6_out;
}