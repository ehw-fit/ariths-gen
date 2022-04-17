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

uint8_t mux2to1(uint8_t d0, uint8_t d1, uint8_t sel){
  uint8_t mux2to1_out = 0;
  uint8_t mux2to1_and0 = 0;
  uint8_t mux2to1_not0 = 0;
  uint8_t mux2to1_and1 = 0;
  uint8_t mux2to1_xor0 = 0;

  mux2to1_and0 = and_gate(((d1 >> 0) & 0x01), ((sel >> 0) & 0x01));
  mux2to1_not0 = not_gate(((sel >> 0) & 0x01));
  mux2to1_and1 = and_gate(((d0 >> 0) & 0x01), ((mux2to1_not0 >> 0) & 0x01));
  mux2to1_xor0 = xor_gate(((mux2to1_and0 >> 0) & 0x01), ((mux2to1_and1 >> 0) & 0x01));

  mux2to1_out |= ((mux2to1_xor0 >> 0) & 0x01ull) << 0;
  return mux2to1_out;
}

uint64_t u_cska3(uint64_t a, uint64_t b){
  uint8_t u_cska3_out = 0;
  uint8_t u_cska3_xor0 = 0;
  uint8_t u_cska3_ha0_xor0 = 0;
  uint8_t u_cska3_ha0_and0 = 0;
  uint8_t u_cska3_xor1 = 0;
  uint8_t u_cska3_fa0_xor1 = 0;
  uint8_t u_cska3_fa0_or0 = 0;
  uint8_t u_cska3_xor2 = 0;
  uint8_t u_cska3_fa1_xor1 = 0;
  uint8_t u_cska3_fa1_or0 = 0;
  uint8_t u_cska3_and_propagate00 = 0;
  uint8_t u_cska3_and_propagate01 = 0;
  uint8_t u_cska3_mux2to10_and1 = 0;

  u_cska3_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_cska3_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cska3_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cska3_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_cska3_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska3_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska3_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska3_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska3_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_cska3_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska3_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska3_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska3_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska3_and_propagate00 = and_gate(((u_cska3_xor0 >> 0) & 0x01), ((u_cska3_xor1 >> 0) & 0x01));
  u_cska3_and_propagate01 = and_gate(((u_cska3_and_propagate00 >> 0) & 0x01), ((u_cska3_xor2 >> 0) & 0x01));
  u_cska3_mux2to10_and1 = (mux2to1(((u_cska3_fa1_or0 >> 0) & 0x01), (0x00), ((u_cska3_and_propagate01 >> 0) & 0x01)) >> 0) & 0x01;

  u_cska3_out |= ((u_cska3_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska3_out |= ((u_cska3_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska3_out |= ((u_cska3_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska3_out |= ((u_cska3_mux2to10_and1 >> 0) & 0x01ull) << 3;
  return u_cska3_out;
}

uint64_t h_u_csatm8_cska_k5(uint64_t a, uint64_t b){
  uint64_t h_u_csatm8_cska_k5_out = 0;
  uint8_t h_u_csatm8_cska_k5_and5_5 = 0;
  uint8_t h_u_csatm8_cska_k5_and6_5 = 0;
  uint8_t h_u_csatm8_cska_k5_and7_5 = 0;
  uint8_t h_u_csatm8_cska_k5_and5_6 = 0;
  uint8_t h_u_csatm8_cska_k5_ha5_6_xor0 = 0;
  uint8_t h_u_csatm8_cska_k5_ha5_6_and0 = 0;
  uint8_t h_u_csatm8_cska_k5_and6_6 = 0;
  uint8_t h_u_csatm8_cska_k5_ha6_6_xor0 = 0;
  uint8_t h_u_csatm8_cska_k5_ha6_6_and0 = 0;
  uint8_t h_u_csatm8_cska_k5_and7_6 = 0;
  uint8_t h_u_csatm8_cska_k5_and5_7 = 0;
  uint8_t h_u_csatm8_cska_k5_fa5_7_xor1 = 0;
  uint8_t h_u_csatm8_cska_k5_fa5_7_or0 = 0;
  uint8_t h_u_csatm8_cska_k5_and6_7 = 0;
  uint8_t h_u_csatm8_cska_k5_fa6_7_xor1 = 0;
  uint8_t h_u_csatm8_cska_k5_fa6_7_or0 = 0;
  uint8_t h_u_csatm8_cska_k5_and7_7 = 0;
  uint64_t h_u_csatm8_cska_k5_u_cska3_a = 0;
  uint64_t h_u_csatm8_cska_k5_u_cska3_b = 0;
  uint64_t h_u_csatm8_cska_k5_u_cska3_out = 0;

  h_u_csatm8_cska_k5_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k5_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k5_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k5_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k5_ha5_6_xor0 = (ha(((h_u_csatm8_cska_k5_and5_6 >> 0) & 0x01), ((h_u_csatm8_cska_k5_and6_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k5_ha5_6_and0 = (ha(((h_u_csatm8_cska_k5_and5_6 >> 0) & 0x01), ((h_u_csatm8_cska_k5_and6_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k5_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k5_ha6_6_xor0 = (ha(((h_u_csatm8_cska_k5_and6_6 >> 0) & 0x01), ((h_u_csatm8_cska_k5_and7_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k5_ha6_6_and0 = (ha(((h_u_csatm8_cska_k5_and6_6 >> 0) & 0x01), ((h_u_csatm8_cska_k5_and7_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k5_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k5_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k5_fa5_7_xor1 = (fa(((h_u_csatm8_cska_k5_and5_7 >> 0) & 0x01), ((h_u_csatm8_cska_k5_ha6_6_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k5_ha5_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k5_fa5_7_or0 = (fa(((h_u_csatm8_cska_k5_and5_7 >> 0) & 0x01), ((h_u_csatm8_cska_k5_ha6_6_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k5_ha5_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k5_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k5_fa6_7_xor1 = (fa(((h_u_csatm8_cska_k5_and6_7 >> 0) & 0x01), ((h_u_csatm8_cska_k5_and7_6 >> 0) & 0x01), ((h_u_csatm8_cska_k5_ha6_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k5_fa6_7_or0 = (fa(((h_u_csatm8_cska_k5_and6_7 >> 0) & 0x01), ((h_u_csatm8_cska_k5_and7_6 >> 0) & 0x01), ((h_u_csatm8_cska_k5_ha6_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k5_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k5_u_cska3_a |= ((h_u_csatm8_cska_k5_fa6_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csatm8_cska_k5_u_cska3_a |= ((h_u_csatm8_cska_k5_and7_7 >> 0) & 0x01ull) << 1;
  h_u_csatm8_cska_k5_u_cska3_a |= (0x00) << 2;
  h_u_csatm8_cska_k5_u_cska3_b |= ((h_u_csatm8_cska_k5_fa5_7_or0 >> 0) & 0x01ull) << 0;
  h_u_csatm8_cska_k5_u_cska3_b |= ((h_u_csatm8_cska_k5_fa6_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csatm8_cska_k5_u_cska3_b |= (0x00) << 2;
  h_u_csatm8_cska_k5_u_cska3_out = u_cska3(h_u_csatm8_cska_k5_u_cska3_a, h_u_csatm8_cska_k5_u_cska3_b);

  h_u_csatm8_cska_k5_out |= (0x00) << 0;
  h_u_csatm8_cska_k5_out |= (0x00) << 1;
  h_u_csatm8_cska_k5_out |= (0x00) << 2;
  h_u_csatm8_cska_k5_out |= (0x00) << 3;
  h_u_csatm8_cska_k5_out |= (0x00) << 4;
  h_u_csatm8_cska_k5_out |= (0x00) << 5;
  h_u_csatm8_cska_k5_out |= (0x00) << 6;
  h_u_csatm8_cska_k5_out |= (0x00) << 7;
  h_u_csatm8_cska_k5_out |= (0x00) << 8;
  h_u_csatm8_cska_k5_out |= (0x00) << 9;
  h_u_csatm8_cska_k5_out |= ((h_u_csatm8_cska_k5_and5_5 >> 0) & 0x01ull) << 10;
  h_u_csatm8_cska_k5_out |= ((h_u_csatm8_cska_k5_ha5_6_xor0 >> 0) & 0x01ull) << 11;
  h_u_csatm8_cska_k5_out |= ((h_u_csatm8_cska_k5_fa5_7_xor1 >> 0) & 0x01ull) << 12;
  h_u_csatm8_cska_k5_out |= ((h_u_csatm8_cska_k5_u_cska3_out >> 0) & 0x01ull) << 13;
  h_u_csatm8_cska_k5_out |= ((h_u_csatm8_cska_k5_u_cska3_out >> 1) & 0x01ull) << 14;
  h_u_csatm8_cska_k5_out |= ((h_u_csatm8_cska_k5_u_cska3_out >> 2) & 0x01ull) << 15;
  return h_u_csatm8_cska_k5_out;
}