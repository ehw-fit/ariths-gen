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

  u_pg_rca6_out |= ((u_pg_rca6_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_pg_rca6_out |= ((u_pg_rca6_pg_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_pg_rca6_out |= ((u_pg_rca6_or5 >> 0) & 0x01ull) << 6;
  return u_pg_rca6_out;
}

uint64_t h_u_csabam8_pg_rca_h0_v9(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_pg_rca_h0_v9_out = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and7_2 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and6_3 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha6_3_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha6_3_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and7_3 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and5_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha5_4_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha5_4_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and6_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_4_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_4_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and7_4 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and4_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha4_5_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha4_5_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and5_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa5_5_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa5_5_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and6_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_5_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_5_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and7_5 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and3_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha3_6_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha3_6_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and4_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa4_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa4_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and5_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa5_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa5_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and6_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_6_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_6_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and7_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and2_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha2_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_ha2_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and3_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa3_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa3_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and4_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa4_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa4_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and5_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa5_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa5_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and6_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_pg_rca_h0_v9_and7_7 = 0;
  uint64_t h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a = 0;
  uint64_t h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b = 0;
  uint64_t h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out = 0;

  h_u_csabam8_pg_rca_h0_v9_and7_2 = and_gate(((a >> 7) & 0x01), ((b >> 2) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_and6_3 = and_gate(((a >> 6) & 0x01), ((b >> 3) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_ha6_3_xor0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and6_3 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_2 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_ha6_3_and0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and6_3 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_2 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and7_3 = and_gate(((a >> 7) & 0x01), ((b >> 3) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_and5_4 = and_gate(((a >> 5) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_ha5_4_xor0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and5_4 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha6_3_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_ha5_4_and0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and5_4 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha6_3_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and6_4 = and_gate(((a >> 6) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa6_4_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_4 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_3 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha6_3_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa6_4_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_4 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_3 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha6_3_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and7_4 = and_gate(((a >> 7) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_ha4_5_xor0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and4_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha5_4_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_ha4_5_and0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and4_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha5_4_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa5_5_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and5_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_4_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha5_4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa5_5_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and5_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_4_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha5_4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa6_5_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_4 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa6_5_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_4 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_ha3_6_xor0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and3_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha4_5_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_ha3_6_and0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and3_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha4_5_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa4_6_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and4_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_5_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha4_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa4_6_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and4_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_5_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha4_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa5_6_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and5_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_5_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa5_6_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and5_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_5_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa6_6_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa6_6_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_5 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_ha2_7_xor0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and2_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha3_6_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_ha2_7_and0 = (ha(((h_u_csabam8_pg_rca_h0_v9_and2_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha3_6_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa3_7_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and3_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa4_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha3_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa3_7_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and3_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa4_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_ha3_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa4_7_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and4_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa4_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa4_7_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and4_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa4_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa5_7_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa5_7_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa5_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_fa6_7_xor1 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_fa6_7_or0 = (fa(((h_u_csabam8_pg_rca_h0_v9_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_and7_6 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h0_v9_fa6_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h0_v9_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a |= ((h_u_csabam8_pg_rca_h0_v9_fa3_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a |= ((h_u_csabam8_pg_rca_h0_v9_fa4_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a |= ((h_u_csabam8_pg_rca_h0_v9_fa5_7_xor1 >> 0) & 0x01ull) << 2;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a |= ((h_u_csabam8_pg_rca_h0_v9_fa6_7_xor1 >> 0) & 0x01ull) << 3;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a |= ((h_u_csabam8_pg_rca_h0_v9_and7_7 >> 0) & 0x01ull) << 4;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a |= (0x00) << 5;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b |= (0x00) << 0;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b |= ((h_u_csabam8_pg_rca_h0_v9_fa3_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b |= ((h_u_csabam8_pg_rca_h0_v9_fa4_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b |= ((h_u_csabam8_pg_rca_h0_v9_fa5_7_or0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b |= ((h_u_csabam8_pg_rca_h0_v9_fa6_7_or0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b |= (0x00) << 5;
  h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out = u_pg_rca6(h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_a, h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_b);

  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 0;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 1;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 2;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 3;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 4;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 5;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 6;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 7;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 8;
  h_u_csabam8_pg_rca_h0_v9_out |= ((h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out >> 0) & 0x01ull) << 9;
  h_u_csabam8_pg_rca_h0_v9_out |= ((h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out >> 1) & 0x01ull) << 10;
  h_u_csabam8_pg_rca_h0_v9_out |= ((h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out >> 2) & 0x01ull) << 11;
  h_u_csabam8_pg_rca_h0_v9_out |= ((h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out >> 3) & 0x01ull) << 12;
  h_u_csabam8_pg_rca_h0_v9_out |= ((h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out >> 4) & 0x01ull) << 13;
  h_u_csabam8_pg_rca_h0_v9_out |= ((h_u_csabam8_pg_rca_h0_v9_u_pg_rca6_out >> 5) & 0x01ull) << 14;
  h_u_csabam8_pg_rca_h0_v9_out |= (0x00) << 15;
  return h_u_csabam8_pg_rca_h0_v9_out;
}