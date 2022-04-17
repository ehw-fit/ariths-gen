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

uint64_t u_pg_rca8(uint64_t a, uint64_t b){
  uint64_t u_pg_rca8_out = 0;
  uint8_t u_pg_rca8_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa0_and0 = 0;
  uint8_t u_pg_rca8_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa1_and0 = 0;
  uint8_t u_pg_rca8_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca8_and1 = 0;
  uint8_t u_pg_rca8_or1 = 0;
  uint8_t u_pg_rca8_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa2_and0 = 0;
  uint8_t u_pg_rca8_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca8_and2 = 0;
  uint8_t u_pg_rca8_or2 = 0;
  uint8_t u_pg_rca8_pg_fa3_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa3_and0 = 0;
  uint8_t u_pg_rca8_pg_fa3_xor1 = 0;
  uint8_t u_pg_rca8_and3 = 0;
  uint8_t u_pg_rca8_or3 = 0;
  uint8_t u_pg_rca8_pg_fa4_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa4_and0 = 0;
  uint8_t u_pg_rca8_pg_fa4_xor1 = 0;
  uint8_t u_pg_rca8_and4 = 0;
  uint8_t u_pg_rca8_or4 = 0;
  uint8_t u_pg_rca8_pg_fa5_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa5_and0 = 0;
  uint8_t u_pg_rca8_pg_fa5_xor1 = 0;
  uint8_t u_pg_rca8_and5 = 0;
  uint8_t u_pg_rca8_or5 = 0;
  uint8_t u_pg_rca8_pg_fa6_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa6_and0 = 0;
  uint8_t u_pg_rca8_pg_fa6_xor1 = 0;
  uint8_t u_pg_rca8_and6 = 0;
  uint8_t u_pg_rca8_or6 = 0;
  uint8_t u_pg_rca8_pg_fa7_xor0 = 0;
  uint8_t u_pg_rca8_pg_fa7_and0 = 0;
  uint8_t u_pg_rca8_pg_fa7_xor1 = 0;
  uint8_t u_pg_rca8_and7 = 0;
  uint8_t u_pg_rca8_or7 = 0;

  u_pg_rca8_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  u_pg_rca8_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  u_pg_rca8_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca8_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca8_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_pg_rca8_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and1 = and_gate(((u_pg_rca8_pg_fa0_and0 >> 0) & 0x01), ((u_pg_rca8_pg_fa1_xor0 >> 0) & 0x01));
  u_pg_rca8_or1 = or_gate(((u_pg_rca8_and1 >> 0) & 0x01), ((u_pg_rca8_pg_fa1_and0 >> 0) & 0x01));
  u_pg_rca8_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca8_or1 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca8_or1 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_pg_rca8_or1 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and2 = and_gate(((u_pg_rca8_or1 >> 0) & 0x01), ((u_pg_rca8_pg_fa2_xor0 >> 0) & 0x01));
  u_pg_rca8_or2 = or_gate(((u_pg_rca8_and2 >> 0) & 0x01), ((u_pg_rca8_pg_fa2_and0 >> 0) & 0x01));
  u_pg_rca8_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca8_or2 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca8_or2 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_pg_rca8_or2 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and3 = and_gate(((u_pg_rca8_or2 >> 0) & 0x01), ((u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01));
  u_pg_rca8_or3 = or_gate(((u_pg_rca8_and3 >> 0) & 0x01), ((u_pg_rca8_pg_fa3_and0 >> 0) & 0x01));
  u_pg_rca8_pg_fa4_xor0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca8_or3 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa4_and0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca8_or3 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa4_xor1 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_pg_rca8_or3 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and4 = and_gate(((u_pg_rca8_or3 >> 0) & 0x01), ((u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01));
  u_pg_rca8_or4 = or_gate(((u_pg_rca8_and4 >> 0) & 0x01), ((u_pg_rca8_pg_fa4_and0 >> 0) & 0x01));
  u_pg_rca8_pg_fa5_xor0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca8_or4 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa5_and0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca8_or4 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa5_xor1 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_pg_rca8_or4 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and5 = and_gate(((u_pg_rca8_or4 >> 0) & 0x01), ((u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01));
  u_pg_rca8_or5 = or_gate(((u_pg_rca8_and5 >> 0) & 0x01), ((u_pg_rca8_pg_fa5_and0 >> 0) & 0x01));
  u_pg_rca8_pg_fa6_xor0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_pg_rca8_or5 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa6_and0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_pg_rca8_or5 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa6_xor1 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_pg_rca8_or5 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and6 = and_gate(((u_pg_rca8_or5 >> 0) & 0x01), ((u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01));
  u_pg_rca8_or6 = or_gate(((u_pg_rca8_and6 >> 0) & 0x01), ((u_pg_rca8_pg_fa6_and0 >> 0) & 0x01));
  u_pg_rca8_pg_fa7_xor0 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_pg_rca8_or6 >> 0) & 0x01)) >> 0) & 0x01;
  u_pg_rca8_pg_fa7_and0 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_pg_rca8_or6 >> 0) & 0x01)) >> 1) & 0x01;
  u_pg_rca8_pg_fa7_xor1 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_pg_rca8_or6 >> 0) & 0x01)) >> 2) & 0x01;
  u_pg_rca8_and7 = and_gate(((u_pg_rca8_or6 >> 0) & 0x01), ((u_pg_rca8_pg_fa7_xor0 >> 0) & 0x01));
  u_pg_rca8_or7 = or_gate(((u_pg_rca8_and7 >> 0) & 0x01), ((u_pg_rca8_pg_fa7_and0 >> 0) & 0x01));

  u_pg_rca8_out |= ((u_pg_rca8_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_pg_rca8_out |= ((u_pg_rca8_pg_fa7_xor1 >> 0) & 0x01ull) << 7;
  u_pg_rca8_out |= ((u_pg_rca8_or7 >> 0) & 0x01ull) << 8;
  return u_pg_rca8_out;
}

uint64_t h_u_csabam8_pg_rca_h6_v6(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_pg_rca_h6_v6_out = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and0_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and1_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and2_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and3_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and4_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and5_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and6_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and7_6 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and0_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha0_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha0_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and1_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha1_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha1_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and2_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha2_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha2_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and3_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha3_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha3_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and4_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha4_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha4_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and5_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha5_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha5_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and6_7 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha6_7_xor0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_ha6_7_and0 = 0;
  uint8_t h_u_csabam8_pg_rca_h6_v6_and7_7 = 0;
  uint64_t h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a = 0;
  uint64_t h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b = 0;
  uint64_t h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out = 0;

  h_u_csabam8_pg_rca_h6_v6_and0_6 = and_gate(((a >> 0) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and1_6 = and_gate(((a >> 1) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and2_6 = and_gate(((a >> 2) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_and0_7 = and_gate(((a >> 0) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha0_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and0_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and1_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha0_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and0_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and1_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and1_7 = and_gate(((a >> 1) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha1_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and1_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and2_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha1_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and1_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and2_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha2_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and2_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and3_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha2_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and2_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and3_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha3_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and3_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and4_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha3_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and3_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and4_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha4_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and4_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and5_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha4_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and4_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and5_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha5_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and6_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha5_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and5_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and6_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_ha6_7_xor0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and7_6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_ha6_7_and0 = (ha(((h_u_csabam8_pg_rca_h6_v6_and6_7 >> 0) & 0x01), ((h_u_csabam8_pg_rca_h6_v6_and7_6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_pg_rca_h6_v6_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_ha1_7_xor0 >> 0) & 0x01ull) << 0;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_ha2_7_xor0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_ha3_7_xor0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_ha4_7_xor0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_ha5_7_xor0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_ha6_7_xor0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= ((h_u_csabam8_pg_rca_h6_v6_and7_7 >> 0) & 0x01ull) << 6;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a |= (0x00) << 7;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha0_7_and0 >> 0) & 0x01ull) << 0;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha1_7_and0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha2_7_and0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha3_7_and0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha4_7_and0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha5_7_and0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= ((h_u_csabam8_pg_rca_h6_v6_ha6_7_and0 >> 0) & 0x01ull) << 6;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b |= (0x00) << 7;
  h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out = u_pg_rca8(h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_a, h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_b);

  h_u_csabam8_pg_rca_h6_v6_out |= (0x00) << 0;
  h_u_csabam8_pg_rca_h6_v6_out |= (0x00) << 1;
  h_u_csabam8_pg_rca_h6_v6_out |= (0x00) << 2;
  h_u_csabam8_pg_rca_h6_v6_out |= (0x00) << 3;
  h_u_csabam8_pg_rca_h6_v6_out |= (0x00) << 4;
  h_u_csabam8_pg_rca_h6_v6_out |= (0x00) << 5;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_and0_6 >> 0) & 0x01ull) << 6;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_ha0_7_xor0 >> 0) & 0x01ull) << 7;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 0) & 0x01ull) << 8;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 1) & 0x01ull) << 9;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 2) & 0x01ull) << 10;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 3) & 0x01ull) << 11;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 4) & 0x01ull) << 12;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 5) & 0x01ull) << 13;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 6) & 0x01ull) << 14;
  h_u_csabam8_pg_rca_h6_v6_out |= ((h_u_csabam8_pg_rca_h6_v6_u_pg_rca8_out >> 7) & 0x01ull) << 15;
  return h_u_csabam8_pg_rca_h6_v6_out;
}