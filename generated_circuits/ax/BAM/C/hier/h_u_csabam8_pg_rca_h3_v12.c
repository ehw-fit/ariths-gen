#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
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

uint64_t u_pg_rca3(uint64_t a, uint64_t b){
  uint8_t u_pg_rca3_out = 0;
  uint8_t u_pg_rca3_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca3_pg_fa0_and0 = 0;
  uint8_t u_pg_rca3_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca3_pg_fa1_and0 = 0;
  uint8_t u_pg_rca3_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca3_and1 = 0;
  uint8_t u_pg_rca3_or1 = 0;
  uint8_t u_pg_rca3_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca3_pg_fa2_and0 = 0;
  uint8_t u_pg_rca3_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca3_and2 = 0;
  uint8_t u_pg_rca3_or2 = 0;

  u_pg_rca3_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  u_pg_rca3_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  u_pg_rca3_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca3_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca3_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca3_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca3_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca3_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca3_and1 = and_gate(((u_pg_rca3_pg_fa0_and0 >> 0) & 0x01), ((u_pg_rca3_pg_fa1_xor0 >> 0) & 0x01));
  u_pg_rca3_or1 = or_gate(((u_pg_rca3_and1 >> 0) & 0x01), ((u_pg_rca3_pg_fa1_and0 >> 0) & 0x01));
  u_pg_rca3_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca3_or1 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca3_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca3_or1 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca3_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca3_or1 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca3_and2 = and_gate(((u_pg_rca3_or1 >> 0) & 0x01), ((u_pg_rca3_pg_fa2_xor0 >> 0) & 0x01));
  u_pg_rca3_or2 = or_gate(((u_pg_rca3_and2 >> 0) & 0x01), ((u_pg_rca3_pg_fa2_and0 >> 0) & 0x01));

  u_pg_rca3_out |= ((u_pg_rca3_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca3_out |= ((u_pg_rca3_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca3_out |= ((u_pg_rca3_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca3_out |= ((u_pg_rca3_or2 >> 0) & 0x01ull) << 3;
  return u_pg_rca3_out;
}

uint64_t h_u_csabam8_pg_rca_h3_v12(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_pg_rca_h3_v12_out = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_and7_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_and6_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_ha6_6_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_ha6_6_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_and7_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_and5_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_ha5_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_ha5_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_and6_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h3_v12_and7_7 = 0;
  uint64_t h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_a = 0;
  uint64_t h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_b = 0;
  uint64_t h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_out = 0;

  h_u_csabam8_pg_rca_h3_v12_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h3_v12_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h3_v12_ha6_6_xor0 = (ha(((h_u_csabam8_pg_rca_h3_v12_and6_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_and7_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h3_v12_ha6_6_and0 = (ha(((h_u_csabam8_pg_rca_h3_v12_and6_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_and7_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h3_v12_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h3_v12_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h3_v12_ha5_7_xor0 = (ha(((h_u_csabam8_pg_rca_h3_v12_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_ha6_6_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h3_v12_ha5_7_and0 = (ha(((h_u_csabam8_pg_rca_h3_v12_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_ha6_6_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h3_v12_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h3_v12_fa6_7_xor1 = (fa(((h_u_csabam8_pg_rca_h3_v12_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_and7_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_ha6_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h3_v12_fa6_7_or0 = (fa(((h_u_csabam8_pg_rca_h3_v12_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_and7_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h3_v12_ha6_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h3_v12_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_a |= ((h_u_csabam8_pg_rca_h3_v12_fa6_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_a |= ((h_u_csabam8_pg_rca_h3_v12_and7_7 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_a |= (0x00) << 2;
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_b |= (0x00) << 0;
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_b |= ((h_u_csabam8_pg_rca_h3_v12_fa6_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_b |= (0x00) << 2;
  h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_out = u_pg_rca3(h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_a, h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_b);

  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 0;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 1;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 2;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 3;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 4;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 5;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 6;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 7;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 8;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 9;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 10;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 11;
  h_u_csabam8_pg_rca_h3_v12_out |= ((h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_out >> 0) & 0x01ull) << 12;
  h_u_csabam8_pg_rca_h3_v12_out |= ((h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_out >> 1) & 0x01ull) << 13;
  h_u_csabam8_pg_rca_h3_v12_out |= ((h_u_csabam8_pg_rca_h3_v12_u_pg_rca3_out >> 2) & 0x01ull) << 14;
  h_u_csabam8_pg_rca_h3_v12_out |= (0x00) << 15;
  return h_u_csabam8_pg_rca_h3_v12_out;
}