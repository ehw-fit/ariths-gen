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

uint64_t u_pg_rca7(uint64_t a, uint64_t b){
  uint8_t u_pg_rca7_out = 0;
  uint8_t u_pg_rca7_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa0_and0 = 0;
  uint8_t u_pg_rca7_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa1_and0 = 0;
  uint8_t u_pg_rca7_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca7_and1 = 0;
  uint8_t u_pg_rca7_or1 = 0;
  uint8_t u_pg_rca7_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa2_and0 = 0;
  uint8_t u_pg_rca7_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca7_and2 = 0;
  uint8_t u_pg_rca7_or2 = 0;
  uint8_t u_pg_rca7_pg_fa3_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa3_and0 = 0;
  uint8_t u_pg_rca7_pg_fa3_xor1 = 0;
  uint8_t u_pg_rca7_and3 = 0;
  uint8_t u_pg_rca7_or3 = 0;
  uint8_t u_pg_rca7_pg_fa4_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa4_and0 = 0;
  uint8_t u_pg_rca7_pg_fa4_xor1 = 0;
  uint8_t u_pg_rca7_and4 = 0;
  uint8_t u_pg_rca7_or4 = 0;
  uint8_t u_pg_rca7_pg_fa5_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa5_and0 = 0;
  uint8_t u_pg_rca7_pg_fa5_xor1 = 0;
  uint8_t u_pg_rca7_and5 = 0;
  uint8_t u_pg_rca7_or5 = 0;
  uint8_t u_pg_rca7_pg_fa6_xor0 = 0;
  uint8_t u_pg_rca7_pg_fa6_and0 = 0;
  uint8_t u_pg_rca7_pg_fa6_xor1 = 0;
  uint8_t u_pg_rca7_and6 = 0;
  uint8_t u_pg_rca7_or6 = 0;

  u_pg_rca7_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  u_pg_rca7_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  u_pg_rca7_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca7_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca7_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca7_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca7_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca7_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca7_and1 = and_gate(((u_pg_rca7_pg_fa0_and0 >> 0) & 0x01), ((u_pg_rca7_pg_fa1_xor0 >> 0) & 0x01));
  u_pg_rca7_or1 = or_gate(((u_pg_rca7_and1 >> 0) & 0x01), ((u_pg_rca7_pg_fa1_and0 >> 0) & 0x01));
  u_pg_rca7_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca7_or1 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca7_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca7_or1 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca7_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca7_or1 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca7_and2 = and_gate(((u_pg_rca7_or1 >> 0) & 0x01), ((u_pg_rca7_pg_fa2_xor0 >> 0) & 0x01));
  u_pg_rca7_or2 = or_gate(((u_pg_rca7_and2 >> 0) & 0x01), ((u_pg_rca7_pg_fa2_and0 >> 0) & 0x01));
  u_pg_rca7_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca7_or2 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca7_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca7_or2 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca7_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca7_or2 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca7_and3 = and_gate(((u_pg_rca7_or2 >> 0) & 0x01), ((u_pg_rca7_pg_fa3_xor0 >> 0) & 0x01));
  u_pg_rca7_or3 = or_gate(((u_pg_rca7_and3 >> 0) & 0x01), ((u_pg_rca7_pg_fa3_and0 >> 0) & 0x01));
  u_pg_rca7_pg_fa4_xor0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca7_or3 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca7_pg_fa4_and0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca7_or3 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca7_pg_fa4_xor1 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca7_or3 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca7_and4 = and_gate(((u_pg_rca7_or3 >> 0) & 0x01), ((u_pg_rca7_pg_fa4_xor0 >> 0) & 0x01));
  u_pg_rca7_or4 = or_gate(((u_pg_rca7_and4 >> 0) & 0x01), ((u_pg_rca7_pg_fa4_and0 >> 0) & 0x01));
  u_pg_rca7_pg_fa5_xor0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca7_or4 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca7_pg_fa5_and0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca7_or4 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca7_pg_fa5_xor1 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca7_or4 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca7_and5 = and_gate(((u_pg_rca7_or4 >> 0) & 0x01), ((u_pg_rca7_pg_fa5_xor0 >> 0) & 0x01));
  u_pg_rca7_or5 = or_gate(((u_pg_rca7_and5 >> 0) & 0x01), ((u_pg_rca7_pg_fa5_and0 >> 0) & 0x01));
  u_pg_rca7_pg_fa6_xor0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_pg_rca7_or5 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca7_pg_fa6_and0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_pg_rca7_or5 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca7_pg_fa6_xor1 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_pg_rca7_or5 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca7_and6 = and_gate(((u_pg_rca7_or5 >> 0) & 0x01), ((u_pg_rca7_pg_fa6_xor0 >> 0) & 0x01));
  u_pg_rca7_or6 = or_gate(((u_pg_rca7_and6 >> 0) & 0x01), ((u_pg_rca7_pg_fa6_and0 >> 0) & 0x01));

  u_pg_rca7_out |= ((u_pg_rca7_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca7_out |= ((u_pg_rca7_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca7_out |= ((u_pg_rca7_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca7_out |= ((u_pg_rca7_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_pg_rca7_out |= ((u_pg_rca7_pg_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_pg_rca7_out |= ((u_pg_rca7_pg_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_pg_rca7_out |= ((u_pg_rca7_pg_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_pg_rca7_out |= ((u_pg_rca7_or6 >> 0) & 0x01ull) << 7;
  return u_pg_rca7_out;
}

uint64_t h_u_csabam8_pg_rca_h4_v8(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_pg_rca_h4_v8_out = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and4_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and5_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and6_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and7_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and3_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha3_5_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha3_5_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and4_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha4_5_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha4_5_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and5_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha5_5_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha5_5_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and6_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha6_5_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha6_5_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and7_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and2_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha2_6_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha2_6_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and3_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa3_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa3_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and4_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa4_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa4_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and5_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa5_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa5_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and6_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa6_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa6_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and7_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and1_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha1_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_ha1_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and2_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa2_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa2_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and3_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa3_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa3_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and4_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa4_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa4_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and5_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa5_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa5_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and6_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h4_v8_and7_7 = 0;
  uint64_t h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a = 0;
  uint64_t h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b = 0;
  uint64_t h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out = 0;

  h_u_csabam8_pg_rca_h4_v8_and4_4 = and_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_and5_4 = and_gate(((a >> 5) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_and6_4 = and_gate(((a >> 6) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_and7_4 = and_gate(((a >> 7) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_and3_5 = and_gate(((a >> 3) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_ha3_5_xor0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and3_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and4_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_ha3_5_and0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and3_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and4_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_ha4_5_xor0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and4_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and5_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_ha4_5_and0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and4_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and5_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_ha5_5_xor0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and5_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and6_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_ha5_5_and0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and5_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and6_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_ha6_5_xor0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and6_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and7_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_ha6_5_and0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and6_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and7_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_and2_6 = and_gate(((a >> 2) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_ha2_6_xor0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and2_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha3_5_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_ha2_6_and0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and2_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha3_5_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa3_6_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and3_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha4_5_xor0 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha3_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa3_6_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and3_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha4_5_xor0 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha3_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa4_6_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and4_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha5_5_xor0 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha4_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa4_6_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and4_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha5_5_xor0 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha4_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa5_6_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and5_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha6_5_xor0 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha5_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa5_6_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and5_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha6_5_xor0 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha5_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa6_6_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and6_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and7_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha6_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa6_6_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and6_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and7_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha6_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_and1_7 = and_gate(((a >> 1) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_ha1_7_xor0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and1_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha2_6_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_ha1_7_and0 = (ha(((h_u_csabam8_pg_rca_h4_v8_and1_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha2_6_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa2_7_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and2_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa3_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha2_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa2_7_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and2_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa3_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_ha2_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa3_7_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and3_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa4_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa3_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa3_7_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and3_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa4_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa3_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa4_7_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and4_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa5_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa4_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa4_7_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and4_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa5_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa4_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa5_7_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa5_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa5_7_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa5_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_fa6_7_xor1 = (fa(((h_u_csabam8_pg_rca_h4_v8_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and7_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa6_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_fa6_7_or0 = (fa(((h_u_csabam8_pg_rca_h4_v8_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_and7_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h4_v8_fa6_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h4_v8_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= ((h_u_csabam8_pg_rca_h4_v8_fa2_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= ((h_u_csabam8_pg_rca_h4_v8_fa3_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= ((h_u_csabam8_pg_rca_h4_v8_fa4_7_xor1 >> 0) & 0x01ull) << 2;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= ((h_u_csabam8_pg_rca_h4_v8_fa5_7_xor1 >> 0) & 0x01ull) << 3;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= ((h_u_csabam8_pg_rca_h4_v8_fa6_7_xor1 >> 0) & 0x01ull) << 4;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= ((h_u_csabam8_pg_rca_h4_v8_and7_7 >> 0) & 0x01ull) << 5;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a |= (0x00) << 6;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= (0x00) << 0;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= ((h_u_csabam8_pg_rca_h4_v8_fa2_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= ((h_u_csabam8_pg_rca_h4_v8_fa3_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= ((h_u_csabam8_pg_rca_h4_v8_fa4_7_or0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= ((h_u_csabam8_pg_rca_h4_v8_fa5_7_or0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= ((h_u_csabam8_pg_rca_h4_v8_fa6_7_or0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b |= (0x00) << 6;
  h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out = u_pg_rca7(h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_a, h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_b);

  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 0;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 1;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 2;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 3;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 4;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 5;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 6;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 7;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 0) & 0x01ull) << 8;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 1) & 0x01ull) << 9;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 2) & 0x01ull) << 10;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 3) & 0x01ull) << 11;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 4) & 0x01ull) << 12;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 5) & 0x01ull) << 13;
  h_u_csabam8_pg_rca_h4_v8_out |= ((h_u_csabam8_pg_rca_h4_v8_u_pg_rca7_out >> 6) & 0x01ull) << 14;
  h_u_csabam8_pg_rca_h4_v8_out |= (0x00) << 15;
  return h_u_csabam8_pg_rca_h4_v8_out;
}