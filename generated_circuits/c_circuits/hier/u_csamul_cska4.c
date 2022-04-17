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

uint64_t u_cska4(uint64_t a, uint64_t b){
  uint8_t u_cska4_out = 0;
  uint8_t u_cska4_xor0 = 0;
  uint8_t u_cska4_ha0_xor0 = 0;
  uint8_t u_cska4_ha0_and0 = 0;
  uint8_t u_cska4_xor1 = 0;
  uint8_t u_cska4_fa0_xor1 = 0;
  uint8_t u_cska4_fa0_or0 = 0;
  uint8_t u_cska4_xor2 = 0;
  uint8_t u_cska4_fa1_xor1 = 0;
  uint8_t u_cska4_fa1_or0 = 0;
  uint8_t u_cska4_xor3 = 0;
  uint8_t u_cska4_fa2_xor1 = 0;
  uint8_t u_cska4_fa2_or0 = 0;
  uint8_t u_cska4_and_propagate00 = 0;
  uint8_t u_cska4_and_propagate01 = 0;
  uint8_t u_cska4_and_propagate02 = 0;
  uint8_t u_cska4_mux2to10_and1 = 0;

  u_cska4_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_cska4_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cska4_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cska4_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_cska4_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska4_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska4_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska4_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska4_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_cska4_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska4_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska4_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska4_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska4_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_cska4_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska4_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska4_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska4_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska4_and_propagate00 = and_gate(((u_cska4_xor0 >> 0) & 0x01), ((u_cska4_xor2 >> 0) & 0x01));
  u_cska4_and_propagate01 = and_gate(((u_cska4_xor1 >> 0) & 0x01), ((u_cska4_xor3 >> 0) & 0x01));
  u_cska4_and_propagate02 = and_gate(((u_cska4_and_propagate00 >> 0) & 0x01), ((u_cska4_and_propagate01 >> 0) & 0x01));
  u_cska4_mux2to10_and1 = (mux2to1(((u_cska4_fa2_or0 >> 0) & 0x01), (0x00), ((u_cska4_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;

  u_cska4_out |= ((u_cska4_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska4_out |= ((u_cska4_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska4_out |= ((u_cska4_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska4_out |= ((u_cska4_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska4_out |= ((u_cska4_mux2to10_and1 >> 0) & 0x01ull) << 4;
  return u_cska4_out;
}

uint64_t u_csamul_cska4(uint64_t a, uint64_t b){
  uint8_t u_csamul_cska4_out = 0;
  uint8_t u_csamul_cska4_and0_0 = 0;
  uint8_t u_csamul_cska4_and1_0 = 0;
  uint8_t u_csamul_cska4_and2_0 = 0;
  uint8_t u_csamul_cska4_and3_0 = 0;
  uint8_t u_csamul_cska4_and0_1 = 0;
  uint8_t u_csamul_cska4_ha0_1_xor0 = 0;
  uint8_t u_csamul_cska4_ha0_1_and0 = 0;
  uint8_t u_csamul_cska4_and1_1 = 0;
  uint8_t u_csamul_cska4_ha1_1_xor0 = 0;
  uint8_t u_csamul_cska4_ha1_1_and0 = 0;
  uint8_t u_csamul_cska4_and2_1 = 0;
  uint8_t u_csamul_cska4_ha2_1_xor0 = 0;
  uint8_t u_csamul_cska4_ha2_1_and0 = 0;
  uint8_t u_csamul_cska4_and3_1 = 0;
  uint8_t u_csamul_cska4_and0_2 = 0;
  uint8_t u_csamul_cska4_fa0_2_xor1 = 0;
  uint8_t u_csamul_cska4_fa0_2_or0 = 0;
  uint8_t u_csamul_cska4_and1_2 = 0;
  uint8_t u_csamul_cska4_fa1_2_xor1 = 0;
  uint8_t u_csamul_cska4_fa1_2_or0 = 0;
  uint8_t u_csamul_cska4_and2_2 = 0;
  uint8_t u_csamul_cska4_fa2_2_xor1 = 0;
  uint8_t u_csamul_cska4_fa2_2_or0 = 0;
  uint8_t u_csamul_cska4_and3_2 = 0;
  uint8_t u_csamul_cska4_and0_3 = 0;
  uint8_t u_csamul_cska4_fa0_3_xor1 = 0;
  uint8_t u_csamul_cska4_fa0_3_or0 = 0;
  uint8_t u_csamul_cska4_and1_3 = 0;
  uint8_t u_csamul_cska4_fa1_3_xor1 = 0;
  uint8_t u_csamul_cska4_fa1_3_or0 = 0;
  uint8_t u_csamul_cska4_and2_3 = 0;
  uint8_t u_csamul_cska4_fa2_3_xor1 = 0;
  uint8_t u_csamul_cska4_fa2_3_or0 = 0;
  uint8_t u_csamul_cska4_and3_3 = 0;
  uint64_t u_csamul_cska4_u_cska4_a = 0;
  uint64_t u_csamul_cska4_u_cska4_b = 0;
  uint64_t u_csamul_cska4_u_cska4_out = 0;

  u_csamul_cska4_and0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_csamul_cska4_and1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  u_csamul_cska4_and2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  u_csamul_cska4_and3_0 = and_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  u_csamul_cska4_and0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  u_csamul_cska4_ha0_1_xor0 = (ha(((u_csamul_cska4_and0_1 >> 0) & 0x01), ((u_csamul_cska4_and1_0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_ha0_1_and0 = (ha(((u_csamul_cska4_and0_1 >> 0) & 0x01), ((u_csamul_cska4_and1_0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_csamul_cska4_ha1_1_xor0 = (ha(((u_csamul_cska4_and1_1 >> 0) & 0x01), ((u_csamul_cska4_and2_0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_ha1_1_and0 = (ha(((u_csamul_cska4_and1_1 >> 0) & 0x01), ((u_csamul_cska4_and2_0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  u_csamul_cska4_ha2_1_xor0 = (ha(((u_csamul_cska4_and2_1 >> 0) & 0x01), ((u_csamul_cska4_and3_0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_ha2_1_and0 = (ha(((u_csamul_cska4_and2_1 >> 0) & 0x01), ((u_csamul_cska4_and3_0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and3_1 = and_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  u_csamul_cska4_and0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  u_csamul_cska4_fa0_2_xor1 = (fa(((u_csamul_cska4_and0_2 >> 0) & 0x01), ((u_csamul_cska4_ha1_1_xor0 >> 0) & 0x01), ((u_csamul_cska4_ha0_1_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_fa0_2_or0 = (fa(((u_csamul_cska4_and0_2 >> 0) & 0x01), ((u_csamul_cska4_ha1_1_xor0 >> 0) & 0x01), ((u_csamul_cska4_ha0_1_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  u_csamul_cska4_fa1_2_xor1 = (fa(((u_csamul_cska4_and1_2 >> 0) & 0x01), ((u_csamul_cska4_ha2_1_xor0 >> 0) & 0x01), ((u_csamul_cska4_ha1_1_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_fa1_2_or0 = (fa(((u_csamul_cska4_and1_2 >> 0) & 0x01), ((u_csamul_cska4_ha2_1_xor0 >> 0) & 0x01), ((u_csamul_cska4_ha1_1_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_csamul_cska4_fa2_2_xor1 = (fa(((u_csamul_cska4_and2_2 >> 0) & 0x01), ((u_csamul_cska4_and3_1 >> 0) & 0x01), ((u_csamul_cska4_ha2_1_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_fa2_2_or0 = (fa(((u_csamul_cska4_and2_2 >> 0) & 0x01), ((u_csamul_cska4_and3_1 >> 0) & 0x01), ((u_csamul_cska4_ha2_1_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and3_2 = and_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  u_csamul_cska4_and0_3 = and_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  u_csamul_cska4_fa0_3_xor1 = (fa(((u_csamul_cska4_and0_3 >> 0) & 0x01), ((u_csamul_cska4_fa1_2_xor1 >> 0) & 0x01), ((u_csamul_cska4_fa0_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_fa0_3_or0 = (fa(((u_csamul_cska4_and0_3 >> 0) & 0x01), ((u_csamul_cska4_fa1_2_xor1 >> 0) & 0x01), ((u_csamul_cska4_fa0_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and1_3 = and_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  u_csamul_cska4_fa1_3_xor1 = (fa(((u_csamul_cska4_and1_3 >> 0) & 0x01), ((u_csamul_cska4_fa2_2_xor1 >> 0) & 0x01), ((u_csamul_cska4_fa1_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_fa1_3_or0 = (fa(((u_csamul_cska4_and1_3 >> 0) & 0x01), ((u_csamul_cska4_fa2_2_xor1 >> 0) & 0x01), ((u_csamul_cska4_fa1_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and2_3 = and_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  u_csamul_cska4_fa2_3_xor1 = (fa(((u_csamul_cska4_and2_3 >> 0) & 0x01), ((u_csamul_cska4_and3_2 >> 0) & 0x01), ((u_csamul_cska4_fa2_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_csamul_cska4_fa2_3_or0 = (fa(((u_csamul_cska4_and2_3 >> 0) & 0x01), ((u_csamul_cska4_and3_2 >> 0) & 0x01), ((u_csamul_cska4_fa2_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_csamul_cska4_and3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_csamul_cska4_u_cska4_a |= ((u_csamul_cska4_fa1_3_xor1 >> 0) & 0x01ull) << 0;
  u_csamul_cska4_u_cska4_a |= ((u_csamul_cska4_fa2_3_xor1 >> 0) & 0x01ull) << 1;
  u_csamul_cska4_u_cska4_a |= ((u_csamul_cska4_and3_3 >> 0) & 0x01ull) << 2;
  u_csamul_cska4_u_cska4_a |= (0x00) << 3;
  u_csamul_cska4_u_cska4_b |= ((u_csamul_cska4_fa0_3_or0 >> 0) & 0x01ull) << 0;
  u_csamul_cska4_u_cska4_b |= ((u_csamul_cska4_fa1_3_or0 >> 0) & 0x01ull) << 1;
  u_csamul_cska4_u_cska4_b |= ((u_csamul_cska4_fa2_3_or0 >> 0) & 0x01ull) << 2;
  u_csamul_cska4_u_cska4_b |= (0x00) << 3;
  u_csamul_cska4_u_cska4_out = u_cska4(u_csamul_cska4_u_cska4_a, u_csamul_cska4_u_cska4_b);

  u_csamul_cska4_out |= ((u_csamul_cska4_and0_0 >> 0) & 0x01ull) << 0;
  u_csamul_cska4_out |= ((u_csamul_cska4_ha0_1_xor0 >> 0) & 0x01ull) << 1;
  u_csamul_cska4_out |= ((u_csamul_cska4_fa0_2_xor1 >> 0) & 0x01ull) << 2;
  u_csamul_cska4_out |= ((u_csamul_cska4_fa0_3_xor1 >> 0) & 0x01ull) << 3;
  u_csamul_cska4_out |= ((u_csamul_cska4_u_cska4_out >> 0) & 0x01ull) << 4;
  u_csamul_cska4_out |= ((u_csamul_cska4_u_cska4_out >> 1) & 0x01ull) << 5;
  u_csamul_cska4_out |= ((u_csamul_cska4_u_cska4_out >> 2) & 0x01ull) << 6;
  u_csamul_cska4_out |= ((u_csamul_cska4_u_cska4_out >> 3) & 0x01ull) << 7;
  return u_csamul_cska4_out;
}