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

uint64_t h_u_csabam8_rca_h5_v7(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_rca_h5_v7_out = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and2_5 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and3_5 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and4_5 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and5_5 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and6_5 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and7_5 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and1_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha1_6_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha1_6_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and2_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha2_6_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha2_6_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and3_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha3_6_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha3_6_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and4_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha4_6_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha4_6_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and5_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha5_6_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha5_6_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and6_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha6_6_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha6_6_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and7_6 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and0_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha0_7_xor0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_ha0_7_and0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and1_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa1_7_xor1 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa1_7_or0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and2_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa2_7_xor1 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa2_7_or0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and3_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa3_7_xor1 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa3_7_or0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and4_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa4_7_xor1 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa4_7_or0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and5_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa5_7_xor1 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa5_7_or0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and6_7 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_rca_h5_v7_and7_7 = 0;
  uint64_t h_u_csabam8_rca_h5_v7_u_rca8_a = 0;
  uint64_t h_u_csabam8_rca_h5_v7_u_rca8_b = 0;
  uint64_t h_u_csabam8_rca_h5_v7_u_rca8_out = 0;

  h_u_csabam8_rca_h5_v7_and2_5 = and_gate(((a >> 2) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_rca_h5_v7_and3_5 = and_gate(((a >> 3) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_rca_h5_v7_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_rca_h5_v7_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_rca_h5_v7_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_rca_h5_v7_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_rca_h5_v7_and1_6 = and_gate(((a >> 1) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_ha1_6_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and1_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and2_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha1_6_and0 = (ha(((h_u_csabam8_rca_h5_v7_and1_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and2_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and2_6 = and_gate(((a >> 2) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_ha2_6_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and2_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and3_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha2_6_and0 = (ha(((h_u_csabam8_rca_h5_v7_and2_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and3_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_ha3_6_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and3_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and4_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha3_6_and0 = (ha(((h_u_csabam8_rca_h5_v7_and3_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and4_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_ha4_6_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and4_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and5_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha4_6_and0 = (ha(((h_u_csabam8_rca_h5_v7_and4_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and5_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_ha5_6_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and5_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and6_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha5_6_and0 = (ha(((h_u_csabam8_rca_h5_v7_and5_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and6_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_ha6_6_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and6_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and7_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha6_6_and0 = (ha(((h_u_csabam8_rca_h5_v7_and6_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and7_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_rca_h5_v7_and0_7 = and_gate(((a >> 0) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_ha0_7_xor0 = (ha(((h_u_csabam8_rca_h5_v7_and0_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha1_6_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_ha0_7_and0 = (ha(((h_u_csabam8_rca_h5_v7_and0_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha1_6_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and1_7 = and_gate(((a >> 1) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_fa1_7_xor1 = (fa(((h_u_csabam8_rca_h5_v7_and1_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha2_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha1_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_fa1_7_or0 = (fa(((h_u_csabam8_rca_h5_v7_and1_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha2_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha1_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_fa2_7_xor1 = (fa(((h_u_csabam8_rca_h5_v7_and2_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha3_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha2_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_fa2_7_or0 = (fa(((h_u_csabam8_rca_h5_v7_and2_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha3_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha2_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_fa3_7_xor1 = (fa(((h_u_csabam8_rca_h5_v7_and3_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha4_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha3_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_fa3_7_or0 = (fa(((h_u_csabam8_rca_h5_v7_and3_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha4_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha3_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_fa4_7_xor1 = (fa(((h_u_csabam8_rca_h5_v7_and4_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha5_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha4_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_fa4_7_or0 = (fa(((h_u_csabam8_rca_h5_v7_and4_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha5_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha4_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_fa5_7_xor1 = (fa(((h_u_csabam8_rca_h5_v7_and5_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha6_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha5_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_fa5_7_or0 = (fa(((h_u_csabam8_rca_h5_v7_and5_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha6_6_xor0 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha5_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_fa6_7_xor1 = (fa(((h_u_csabam8_rca_h5_v7_and6_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and7_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha6_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_rca_h5_v7_fa6_7_or0 = (fa(((h_u_csabam8_rca_h5_v7_and6_7 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_and7_6 >> 0) & 0x01), ((h_u_csabam8_rca_h5_v7_ha6_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_rca_h5_v7_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_fa1_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_fa2_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_fa3_7_xor1 >> 0) & 0x01ull) << 2;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_fa4_7_xor1 >> 0) & 0x01ull) << 3;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_fa5_7_xor1 >> 0) & 0x01ull) << 4;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_fa6_7_xor1 >> 0) & 0x01ull) << 5;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= ((h_u_csabam8_rca_h5_v7_and7_7 >> 0) & 0x01ull) << 6;
  h_u_csabam8_rca_h5_v7_u_rca8_a |= (0x00) << 7;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= (0x00) << 0;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= ((h_u_csabam8_rca_h5_v7_fa1_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= ((h_u_csabam8_rca_h5_v7_fa2_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= ((h_u_csabam8_rca_h5_v7_fa3_7_or0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= ((h_u_csabam8_rca_h5_v7_fa4_7_or0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= ((h_u_csabam8_rca_h5_v7_fa5_7_or0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= ((h_u_csabam8_rca_h5_v7_fa6_7_or0 >> 0) & 0x01ull) << 6;
  h_u_csabam8_rca_h5_v7_u_rca8_b |= (0x00) << 7;
  h_u_csabam8_rca_h5_v7_u_rca8_out = u_rca8(h_u_csabam8_rca_h5_v7_u_rca8_a, h_u_csabam8_rca_h5_v7_u_rca8_b);

  h_u_csabam8_rca_h5_v7_out |= (0x00) << 0;
  h_u_csabam8_rca_h5_v7_out |= (0x00) << 1;
  h_u_csabam8_rca_h5_v7_out |= (0x00) << 2;
  h_u_csabam8_rca_h5_v7_out |= (0x00) << 3;
  h_u_csabam8_rca_h5_v7_out |= (0x00) << 4;
  h_u_csabam8_rca_h5_v7_out |= (0x00) << 5;
  h_u_csabam8_rca_h5_v7_out |= (0x00) << 6;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_ha0_7_xor0 >> 0) & 0x01ull) << 7;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 0) & 0x01ull) << 8;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 1) & 0x01ull) << 9;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 2) & 0x01ull) << 10;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 3) & 0x01ull) << 11;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 4) & 0x01ull) << 12;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 5) & 0x01ull) << 13;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 6) & 0x01ull) << 14;
  h_u_csabam8_rca_h5_v7_out |= ((h_u_csabam8_rca_h5_v7_u_rca8_out >> 7) & 0x01ull) << 15;
  return h_u_csabam8_rca_h5_v7_out;
}