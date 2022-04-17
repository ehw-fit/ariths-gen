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

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
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

uint64_t u_cska5(uint64_t a, uint64_t b){
  uint8_t u_cska5_out = 0;
  uint8_t u_cska5_xor0 = 0;
  uint8_t u_cska5_ha0_xor0 = 0;
  uint8_t u_cska5_ha0_and0 = 0;
  uint8_t u_cska5_xor1 = 0;
  uint8_t u_cska5_fa0_xor1 = 0;
  uint8_t u_cska5_fa0_or0 = 0;
  uint8_t u_cska5_xor2 = 0;
  uint8_t u_cska5_fa1_xor1 = 0;
  uint8_t u_cska5_fa1_or0 = 0;
  uint8_t u_cska5_xor3 = 0;
  uint8_t u_cska5_fa2_xor1 = 0;
  uint8_t u_cska5_fa2_or0 = 0;
  uint8_t u_cska5_and_propagate00 = 0;
  uint8_t u_cska5_and_propagate01 = 0;
  uint8_t u_cska5_and_propagate02 = 0;
  uint8_t u_cska5_mux2to10_and1 = 0;
  uint8_t u_cska5_xor4 = 0;
  uint8_t u_cska5_fa3_xor1 = 0;
  uint8_t u_cska5_fa3_or0 = 0;
  uint8_t u_cska5_mux2to11_xor0 = 0;

  u_cska5_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_cska5_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cska5_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cska5_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_cska5_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska5_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska5_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska5_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska5_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_cska5_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska5_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska5_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska5_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska5_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_cska5_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska5_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska5_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska5_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska5_and_propagate00 = and_gate(((u_cska5_xor0 >> 0) & 0x01), ((u_cska5_xor2 >> 0) & 0x01));
  u_cska5_and_propagate01 = and_gate(((u_cska5_xor1 >> 0) & 0x01), ((u_cska5_xor3 >> 0) & 0x01));
  u_cska5_and_propagate02 = and_gate(((u_cska5_and_propagate00 >> 0) & 0x01), ((u_cska5_and_propagate01 >> 0) & 0x01));
  u_cska5_mux2to10_and1 = (mux2to1(((u_cska5_fa2_or0 >> 0) & 0x01), (0x00), ((u_cska5_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska5_xor4 = xor_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  u_cska5_fa3_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska5_mux2to10_and1 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska5_fa3_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska5_mux2to10_and1 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska5_mux2to11_xor0 = (mux2to1(((u_cska5_fa3_or0 >> 0) & 0x01), ((u_cska5_mux2to10_and1 >> 0) & 0x01), ((u_cska5_xor4 >> 0) & 0x01)) >> 0) & 0x01;

  u_cska5_out |= ((u_cska5_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska5_out |= ((u_cska5_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska5_out |= ((u_cska5_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska5_out |= ((u_cska5_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska5_out |= ((u_cska5_fa3_xor1 >> 0) & 0x01ull) << 4;
  u_cska5_out |= ((u_cska5_mux2to11_xor0 >> 0) & 0x01ull) << 5;
  return u_cska5_out;
}

uint64_t h_u_csatm8_cska_k3(uint64_t a, uint64_t b){
  uint64_t h_u_csatm8_cska_k3_out = 0;
  uint8_t h_u_csatm8_cska_k3_and3_3 = 0;
  uint8_t h_u_csatm8_cska_k3_and4_3 = 0;
  uint8_t h_u_csatm8_cska_k3_and5_3 = 0;
  uint8_t h_u_csatm8_cska_k3_and6_3 = 0;
  uint8_t h_u_csatm8_cska_k3_and7_3 = 0;
  uint8_t h_u_csatm8_cska_k3_and3_4 = 0;
  uint8_t h_u_csatm8_cska_k3_ha3_4_xor0 = 0;
  uint8_t h_u_csatm8_cska_k3_ha3_4_and0 = 0;
  uint8_t h_u_csatm8_cska_k3_and4_4 = 0;
  uint8_t h_u_csatm8_cska_k3_ha4_4_xor0 = 0;
  uint8_t h_u_csatm8_cska_k3_ha4_4_and0 = 0;
  uint8_t h_u_csatm8_cska_k3_and5_4 = 0;
  uint8_t h_u_csatm8_cska_k3_ha5_4_xor0 = 0;
  uint8_t h_u_csatm8_cska_k3_ha5_4_and0 = 0;
  uint8_t h_u_csatm8_cska_k3_and6_4 = 0;
  uint8_t h_u_csatm8_cska_k3_ha6_4_xor0 = 0;
  uint8_t h_u_csatm8_cska_k3_ha6_4_and0 = 0;
  uint8_t h_u_csatm8_cska_k3_and7_4 = 0;
  uint8_t h_u_csatm8_cska_k3_and3_5 = 0;
  uint8_t h_u_csatm8_cska_k3_fa3_5_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa3_5_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and4_5 = 0;
  uint8_t h_u_csatm8_cska_k3_fa4_5_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa4_5_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and5_5 = 0;
  uint8_t h_u_csatm8_cska_k3_fa5_5_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa5_5_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and6_5 = 0;
  uint8_t h_u_csatm8_cska_k3_fa6_5_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa6_5_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and7_5 = 0;
  uint8_t h_u_csatm8_cska_k3_and3_6 = 0;
  uint8_t h_u_csatm8_cska_k3_fa3_6_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa3_6_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and4_6 = 0;
  uint8_t h_u_csatm8_cska_k3_fa4_6_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa4_6_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and5_6 = 0;
  uint8_t h_u_csatm8_cska_k3_fa5_6_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa5_6_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and6_6 = 0;
  uint8_t h_u_csatm8_cska_k3_fa6_6_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa6_6_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and7_6 = 0;
  uint8_t h_u_csatm8_cska_k3_and3_7 = 0;
  uint8_t h_u_csatm8_cska_k3_fa3_7_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa3_7_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and4_7 = 0;
  uint8_t h_u_csatm8_cska_k3_fa4_7_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa4_7_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and5_7 = 0;
  uint8_t h_u_csatm8_cska_k3_fa5_7_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa5_7_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and6_7 = 0;
  uint8_t h_u_csatm8_cska_k3_fa6_7_xor1 = 0;
  uint8_t h_u_csatm8_cska_k3_fa6_7_or0 = 0;
  uint8_t h_u_csatm8_cska_k3_and7_7 = 0;
  uint64_t h_u_csatm8_cska_k3_u_cska5_a = 0;
  uint64_t h_u_csatm8_cska_k3_u_cska5_b = 0;
  uint64_t h_u_csatm8_cska_k3_u_cska5_out = 0;

  h_u_csatm8_cska_k3_and3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  h_u_csatm8_cska_k3_and4_3 = and_gate(((a >> 4) & 0x01), ((b >> 3) & 0x01));
  h_u_csatm8_cska_k3_and5_3 = and_gate(((a >> 5) & 0x01), ((b >> 3) & 0x01));
  h_u_csatm8_cska_k3_and6_3 = and_gate(((a >> 6) & 0x01), ((b >> 3) & 0x01));
  h_u_csatm8_cska_k3_and7_3 = and_gate(((a >> 7) & 0x01), ((b >> 3) & 0x01));
  h_u_csatm8_cska_k3_and3_4 = and_gate(((a >> 3) & 0x01), ((b >> 4) & 0x01));
  h_u_csatm8_cska_k3_ha3_4_xor0 = (ha(((h_u_csatm8_cska_k3_and3_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and4_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_ha3_4_and0 = (ha(((h_u_csatm8_cska_k3_and3_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and4_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and4_4 = and_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  h_u_csatm8_cska_k3_ha4_4_xor0 = (ha(((h_u_csatm8_cska_k3_and4_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and5_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_ha4_4_and0 = (ha(((h_u_csatm8_cska_k3_and4_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and5_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and5_4 = and_gate(((a >> 5) & 0x01), ((b >> 4) & 0x01));
  h_u_csatm8_cska_k3_ha5_4_xor0 = (ha(((h_u_csatm8_cska_k3_and5_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and6_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_ha5_4_and0 = (ha(((h_u_csatm8_cska_k3_and5_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and6_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and6_4 = and_gate(((a >> 6) & 0x01), ((b >> 4) & 0x01));
  h_u_csatm8_cska_k3_ha6_4_xor0 = (ha(((h_u_csatm8_cska_k3_and6_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_ha6_4_and0 = (ha(((h_u_csatm8_cska_k3_and6_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and7_4 = and_gate(((a >> 7) & 0x01), ((b >> 4) & 0x01));
  h_u_csatm8_cska_k3_and3_5 = and_gate(((a >> 3) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k3_fa3_5_xor1 = (fa(((h_u_csatm8_cska_k3_and3_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha4_4_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha3_4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa3_5_or0 = (fa(((h_u_csatm8_cska_k3_and3_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha4_4_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha3_4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k3_fa4_5_xor1 = (fa(((h_u_csatm8_cska_k3_and4_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha5_4_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha4_4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa4_5_or0 = (fa(((h_u_csatm8_cska_k3_and4_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha5_4_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha4_4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k3_fa5_5_xor1 = (fa(((h_u_csatm8_cska_k3_and5_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha6_4_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha5_4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa5_5_or0 = (fa(((h_u_csatm8_cska_k3_and5_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha6_4_xor0 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha5_4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k3_fa6_5_xor1 = (fa(((h_u_csatm8_cska_k3_and6_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha6_4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa6_5_or0 = (fa(((h_u_csatm8_cska_k3_and6_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_4 >> 0) & 0x01), ((h_u_csatm8_cska_k3_ha6_4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csatm8_cska_k3_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k3_fa3_6_xor1 = (fa(((h_u_csatm8_cska_k3_and3_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_5_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa3_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa3_6_or0 = (fa(((h_u_csatm8_cska_k3_and3_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_5_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa3_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k3_fa4_6_xor1 = (fa(((h_u_csatm8_cska_k3_and4_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_5_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa4_6_or0 = (fa(((h_u_csatm8_cska_k3_and4_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_5_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k3_fa5_6_xor1 = (fa(((h_u_csatm8_cska_k3_and5_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_5_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa5_6_or0 = (fa(((h_u_csatm8_cska_k3_and5_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_5_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k3_fa6_6_xor1 = (fa(((h_u_csatm8_cska_k3_and6_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa6_6_or0 = (fa(((h_u_csatm8_cska_k3_and6_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_5 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csatm8_cska_k3_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k3_fa3_7_xor1 = (fa(((h_u_csatm8_cska_k3_and3_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_6_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa3_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa3_7_or0 = (fa(((h_u_csatm8_cska_k3_and3_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_6_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa3_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k3_fa4_7_xor1 = (fa(((h_u_csatm8_cska_k3_and4_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_6_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa4_7_or0 = (fa(((h_u_csatm8_cska_k3_and4_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_6_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa4_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k3_fa5_7_xor1 = (fa(((h_u_csatm8_cska_k3_and5_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_6_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa5_7_or0 = (fa(((h_u_csatm8_cska_k3_and5_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_6_xor1 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa5_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k3_fa6_7_xor1 = (fa(((h_u_csatm8_cska_k3_and6_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csatm8_cska_k3_fa6_7_or0 = (fa(((h_u_csatm8_cska_k3_and6_7 >> 0) & 0x01), ((h_u_csatm8_cska_k3_and7_6 >> 0) & 0x01), ((h_u_csatm8_cska_k3_fa6_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csatm8_cska_k3_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csatm8_cska_k3_u_cska5_a |= ((h_u_csatm8_cska_k3_fa4_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csatm8_cska_k3_u_cska5_a |= ((h_u_csatm8_cska_k3_fa5_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csatm8_cska_k3_u_cska5_a |= ((h_u_csatm8_cska_k3_fa6_7_xor1 >> 0) & 0x01ull) << 2;
  h_u_csatm8_cska_k3_u_cska5_a |= ((h_u_csatm8_cska_k3_and7_7 >> 0) & 0x01ull) << 3;
  h_u_csatm8_cska_k3_u_cska5_a |= (0x00) << 4;
  h_u_csatm8_cska_k3_u_cska5_b |= ((h_u_csatm8_cska_k3_fa3_7_or0 >> 0) & 0x01ull) << 0;
  h_u_csatm8_cska_k3_u_cska5_b |= ((h_u_csatm8_cska_k3_fa4_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csatm8_cska_k3_u_cska5_b |= ((h_u_csatm8_cska_k3_fa5_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csatm8_cska_k3_u_cska5_b |= ((h_u_csatm8_cska_k3_fa6_7_or0 >> 0) & 0x01ull) << 3;
  h_u_csatm8_cska_k3_u_cska5_b |= (0x00) << 4;
  h_u_csatm8_cska_k3_u_cska5_out = u_cska5(h_u_csatm8_cska_k3_u_cska5_a, h_u_csatm8_cska_k3_u_cska5_b);

  h_u_csatm8_cska_k3_out |= (0x00) << 0;
  h_u_csatm8_cska_k3_out |= (0x00) << 1;
  h_u_csatm8_cska_k3_out |= (0x00) << 2;
  h_u_csatm8_cska_k3_out |= (0x00) << 3;
  h_u_csatm8_cska_k3_out |= (0x00) << 4;
  h_u_csatm8_cska_k3_out |= (0x00) << 5;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_and3_3 >> 0) & 0x01ull) << 6;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_ha3_4_xor0 >> 0) & 0x01ull) << 7;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_fa3_5_xor1 >> 0) & 0x01ull) << 8;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_fa3_6_xor1 >> 0) & 0x01ull) << 9;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_fa3_7_xor1 >> 0) & 0x01ull) << 10;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_u_cska5_out >> 0) & 0x01ull) << 11;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_u_cska5_out >> 1) & 0x01ull) << 12;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_u_cska5_out >> 2) & 0x01ull) << 13;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_u_cska5_out >> 3) & 0x01ull) << 14;
  h_u_csatm8_cska_k3_out |= ((h_u_csatm8_cska_k3_u_cska5_out >> 4) & 0x01ull) << 15;
  return h_u_csatm8_cska_k3_out;
}