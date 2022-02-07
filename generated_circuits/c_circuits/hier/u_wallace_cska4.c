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

uint64_t u_cska6(uint64_t a, uint64_t b){
  uint8_t u_cska6_out = 0;
  uint8_t u_cska6_xor0 = 0;
  uint8_t u_cska6_ha0_xor0 = 0;
  uint8_t u_cska6_ha0_and0 = 0;
  uint8_t u_cska6_xor1 = 0;
  uint8_t u_cska6_fa0_xor1 = 0;
  uint8_t u_cska6_fa0_or0 = 0;
  uint8_t u_cska6_xor2 = 0;
  uint8_t u_cska6_fa1_xor1 = 0;
  uint8_t u_cska6_fa1_or0 = 0;
  uint8_t u_cska6_xor3 = 0;
  uint8_t u_cska6_fa2_xor1 = 0;
  uint8_t u_cska6_fa2_or0 = 0;
  uint8_t u_cska6_and_propagate00 = 0;
  uint8_t u_cska6_and_propagate01 = 0;
  uint8_t u_cska6_and_propagate02 = 0;
  uint8_t u_cska6_mux2to10_and1 = 0;
  uint8_t u_cska6_xor4 = 0;
  uint8_t u_cska6_fa3_xor1 = 0;
  uint8_t u_cska6_fa3_or0 = 0;
  uint8_t u_cska6_xor5 = 0;
  uint8_t u_cska6_fa4_xor1 = 0;
  uint8_t u_cska6_fa4_or0 = 0;
  uint8_t u_cska6_and_propagate13 = 0;
  uint8_t u_cska6_mux2to11_xor0 = 0;

  u_cska6_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_cska6_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cska6_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_cska6_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska6_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska6_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska6_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_cska6_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska6_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska6_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska6_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_cska6_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska6_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska6_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska6_and_propagate00 = and_gate(((u_cska6_xor0 >> 0) & 0x01), ((u_cska6_xor2 >> 0) & 0x01));
  u_cska6_and_propagate01 = and_gate(((u_cska6_xor1 >> 0) & 0x01), ((u_cska6_xor3 >> 0) & 0x01));
  u_cska6_and_propagate02 = and_gate(((u_cska6_and_propagate00 >> 0) & 0x01), ((u_cska6_and_propagate01 >> 0) & 0x01));
  u_cska6_mux2to10_and1 = (mux2to1(((u_cska6_fa2_or0 >> 0) & 0x01), (0x00), ((u_cska6_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_xor4 = xor_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  u_cska6_fa3_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska6_mux2to10_and1 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_fa3_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska6_mux2to10_and1 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska6_xor5 = xor_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  u_cska6_fa4_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_cska6_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska6_fa4_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_cska6_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska6_and_propagate13 = and_gate(((u_cska6_xor4 >> 0) & 0x01), ((u_cska6_xor5 >> 0) & 0x01));
  u_cska6_mux2to11_xor0 = (mux2to1(((u_cska6_fa4_or0 >> 0) & 0x01), ((u_cska6_mux2to10_and1 >> 0) & 0x01), ((u_cska6_and_propagate13 >> 0) & 0x01)) >> 0) & 0x01;

  u_cska6_out |= ((u_cska6_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska6_out |= ((u_cska6_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska6_out |= ((u_cska6_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska6_out |= ((u_cska6_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska6_out |= ((u_cska6_fa3_xor1 >> 0) & 0x01ull) << 4;
  u_cska6_out |= ((u_cska6_fa4_xor1 >> 0) & 0x01ull) << 5;
  u_cska6_out |= ((u_cska6_mux2to11_xor0 >> 0) & 0x01ull) << 6;
  return u_cska6_out;
}

uint64_t u_wallace_cska4(uint64_t a, uint64_t b){
  uint8_t u_wallace_cska4_out = 0;
  uint8_t u_wallace_cska4_and_2_0 = 0;
  uint8_t u_wallace_cska4_and_1_1 = 0;
  uint8_t u_wallace_cska4_ha0_xor0 = 0;
  uint8_t u_wallace_cska4_ha0_and0 = 0;
  uint8_t u_wallace_cska4_and_3_0 = 0;
  uint8_t u_wallace_cska4_and_2_1 = 0;
  uint8_t u_wallace_cska4_fa0_xor1 = 0;
  uint8_t u_wallace_cska4_fa0_or0 = 0;
  uint8_t u_wallace_cska4_and_3_1 = 0;
  uint8_t u_wallace_cska4_and_2_2 = 0;
  uint8_t u_wallace_cska4_fa1_xor1 = 0;
  uint8_t u_wallace_cska4_fa1_or0 = 0;
  uint8_t u_wallace_cska4_and_1_2 = 0;
  uint8_t u_wallace_cska4_and_0_3 = 0;
  uint8_t u_wallace_cska4_ha1_xor0 = 0;
  uint8_t u_wallace_cska4_ha1_and0 = 0;
  uint8_t u_wallace_cska4_and_1_3 = 0;
  uint8_t u_wallace_cska4_ha2_xor0 = 0;
  uint8_t u_wallace_cska4_ha2_and0 = 0;
  uint8_t u_wallace_cska4_and_3_2 = 0;
  uint8_t u_wallace_cska4_fa2_xor1 = 0;
  uint8_t u_wallace_cska4_fa2_or0 = 0;
  uint8_t u_wallace_cska4_and_0_0 = 0;
  uint8_t u_wallace_cska4_and_1_0 = 0;
  uint8_t u_wallace_cska4_and_0_2 = 0;
  uint8_t u_wallace_cska4_and_2_3 = 0;
  uint8_t u_wallace_cska4_and_0_1 = 0;
  uint8_t u_wallace_cska4_and_3_3 = 0;
  uint64_t u_wallace_cska4_u_cska6_a = 0;
  uint64_t u_wallace_cska4_u_cska6_b = 0;
  uint64_t u_wallace_cska4_u_cska6_out = 0;

  u_wallace_cska4_and_2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  u_wallace_cska4_and_1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_wallace_cska4_ha0_xor0 = (ha(((u_wallace_cska4_and_2_0 >> 0) & 0x01), ((u_wallace_cska4_and_1_1 >> 0) & 0x01)) >> 0) & 0x01;
  u_wallace_cska4_ha0_and0 = (ha(((u_wallace_cska4_and_2_0 >> 0) & 0x01), ((u_wallace_cska4_and_1_1 >> 0) & 0x01)) >> 1) & 0x01;
  u_wallace_cska4_and_3_0 = and_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  u_wallace_cska4_and_2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  u_wallace_cska4_fa0_xor1 = (fa(((u_wallace_cska4_ha0_and0 >> 0) & 0x01), ((u_wallace_cska4_and_3_0 >> 0) & 0x01), ((u_wallace_cska4_and_2_1 >> 0) & 0x01)) >> 0) & 0x01;
  u_wallace_cska4_fa0_or0 = (fa(((u_wallace_cska4_ha0_and0 >> 0) & 0x01), ((u_wallace_cska4_and_3_0 >> 0) & 0x01), ((u_wallace_cska4_and_2_1 >> 0) & 0x01)) >> 1) & 0x01;
  u_wallace_cska4_and_3_1 = and_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  u_wallace_cska4_and_2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_wallace_cska4_fa1_xor1 = (fa(((u_wallace_cska4_fa0_or0 >> 0) & 0x01), ((u_wallace_cska4_and_3_1 >> 0) & 0x01), ((u_wallace_cska4_and_2_2 >> 0) & 0x01)) >> 0) & 0x01;
  u_wallace_cska4_fa1_or0 = (fa(((u_wallace_cska4_fa0_or0 >> 0) & 0x01), ((u_wallace_cska4_and_3_1 >> 0) & 0x01), ((u_wallace_cska4_and_2_2 >> 0) & 0x01)) >> 1) & 0x01;
  u_wallace_cska4_and_1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  u_wallace_cska4_and_0_3 = and_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  u_wallace_cska4_ha1_xor0 = (ha(((u_wallace_cska4_and_1_2 >> 0) & 0x01), ((u_wallace_cska4_and_0_3 >> 0) & 0x01)) >> 0) & 0x01;
  u_wallace_cska4_ha1_and0 = (ha(((u_wallace_cska4_and_1_2 >> 0) & 0x01), ((u_wallace_cska4_and_0_3 >> 0) & 0x01)) >> 1) & 0x01;
  u_wallace_cska4_and_1_3 = and_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  u_wallace_cska4_ha2_xor0 = (ha(((u_wallace_cska4_ha1_and0 >> 0) & 0x01), ((u_wallace_cska4_and_1_3 >> 0) & 0x01)) >> 0) & 0x01;
  u_wallace_cska4_ha2_and0 = (ha(((u_wallace_cska4_ha1_and0 >> 0) & 0x01), ((u_wallace_cska4_and_1_3 >> 0) & 0x01)) >> 1) & 0x01;
  u_wallace_cska4_and_3_2 = and_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  u_wallace_cska4_fa2_xor1 = (fa(((u_wallace_cska4_ha2_and0 >> 0) & 0x01), ((u_wallace_cska4_fa1_or0 >> 0) & 0x01), ((u_wallace_cska4_and_3_2 >> 0) & 0x01)) >> 0) & 0x01;
  u_wallace_cska4_fa2_or0 = (fa(((u_wallace_cska4_ha2_and0 >> 0) & 0x01), ((u_wallace_cska4_fa1_or0 >> 0) & 0x01), ((u_wallace_cska4_and_3_2 >> 0) & 0x01)) >> 1) & 0x01;
  u_wallace_cska4_and_0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_wallace_cska4_and_1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  u_wallace_cska4_and_0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  u_wallace_cska4_and_2_3 = and_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  u_wallace_cska4_and_0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  u_wallace_cska4_and_3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_wallace_cska4_u_cska6_a |= ((u_wallace_cska4_and_1_0 >> 0) & 0x01ull) << 0;
  u_wallace_cska4_u_cska6_a |= ((u_wallace_cska4_and_0_2 >> 0) & 0x01ull) << 1;
  u_wallace_cska4_u_cska6_a |= ((u_wallace_cska4_fa0_xor1 >> 0) & 0x01ull) << 2;
  u_wallace_cska4_u_cska6_a |= ((u_wallace_cska4_fa1_xor1 >> 0) & 0x01ull) << 3;
  u_wallace_cska4_u_cska6_a |= ((u_wallace_cska4_and_2_3 >> 0) & 0x01ull) << 4;
  u_wallace_cska4_u_cska6_a |= ((u_wallace_cska4_fa2_or0 >> 0) & 0x01ull) << 5;
  u_wallace_cska4_u_cska6_b |= ((u_wallace_cska4_and_0_1 >> 0) & 0x01ull) << 0;
  u_wallace_cska4_u_cska6_b |= ((u_wallace_cska4_ha0_xor0 >> 0) & 0x01ull) << 1;
  u_wallace_cska4_u_cska6_b |= ((u_wallace_cska4_ha1_xor0 >> 0) & 0x01ull) << 2;
  u_wallace_cska4_u_cska6_b |= ((u_wallace_cska4_ha2_xor0 >> 0) & 0x01ull) << 3;
  u_wallace_cska4_u_cska6_b |= ((u_wallace_cska4_fa2_xor1 >> 0) & 0x01ull) << 4;
  u_wallace_cska4_u_cska6_b |= ((u_wallace_cska4_and_3_3 >> 0) & 0x01ull) << 5;
  u_wallace_cska4_u_cska6_out = u_cska6(u_wallace_cska4_u_cska6_a, u_wallace_cska4_u_cska6_b);

  u_wallace_cska4_out |= ((u_wallace_cska4_and_0_0 >> 0) & 0x01ull) << 0;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 0) & 0x01ull) << 1;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 1) & 0x01ull) << 2;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 2) & 0x01ull) << 3;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 3) & 0x01ull) << 4;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 4) & 0x01ull) << 5;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 5) & 0x01ull) << 6;
  u_wallace_cska4_out |= ((u_wallace_cska4_u_cska6_out >> 6) & 0x01ull) << 7;
  return u_wallace_cska4_out;
}