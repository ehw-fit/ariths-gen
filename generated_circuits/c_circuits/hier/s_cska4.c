#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
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

int64_t s_cska4(int64_t a, int64_t b){
  int8_t s_cska4_out = 0;
  uint8_t s_cska4_xor0 = 0;
  uint8_t s_cska4_ha0_xor0 = 0;
  uint8_t s_cska4_ha0_and0 = 0;
  uint8_t s_cska4_xor1 = 0;
  uint8_t s_cska4_fa0_xor1 = 0;
  uint8_t s_cska4_fa0_or0 = 0;
  uint8_t s_cska4_xor2 = 0;
  uint8_t s_cska4_fa1_xor1 = 0;
  uint8_t s_cska4_fa1_or0 = 0;
  uint8_t s_cska4_xor3 = 0;
  uint8_t s_cska4_fa2_xor1 = 0;
  uint8_t s_cska4_fa2_or0 = 0;
  uint8_t s_cska4_and_propagate00 = 0;
  uint8_t s_cska4_and_propagate01 = 0;
  uint8_t s_cska4_and_propagate02 = 0;
  uint8_t s_cska4_mux2to10_and1 = 0;
  uint8_t s_cska4_xor4 = 0;
  uint8_t s_cska4_xor5 = 0;

  s_cska4_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  s_cska4_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  s_cska4_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  s_cska4_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  s_cska4_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_cska4_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska4_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_cska4_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska4_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  s_cska4_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_cska4_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska4_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_cska4_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska4_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_cska4_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_cska4_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska4_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_cska4_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska4_and_propagate00 = and_gate(((s_cska4_xor0 >> 0) & 0x01), ((s_cska4_xor2 >> 0) & 0x01));
  s_cska4_and_propagate01 = and_gate(((s_cska4_xor1 >> 0) & 0x01), ((s_cska4_xor3 >> 0) & 0x01));
  s_cska4_and_propagate02 = and_gate(((s_cska4_and_propagate00 >> 0) & 0x01), ((s_cska4_and_propagate01 >> 0) & 0x01));
  s_cska4_mux2to10_and1 = (mux2to1(((s_cska4_fa2_or0 >> 0) & 0x01), (0x00), ((s_cska4_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska4_xor4 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_cska4_xor5 = xor_gate(((s_cska4_xor4 >> 0) & 0x01), ((s_cska4_mux2to10_and1 >> 0) & 0x01));

  s_cska4_out |= ((s_cska4_ha0_xor0 >> 0) & 0x01ull) << 0;
  s_cska4_out |= ((s_cska4_fa0_xor1 >> 0) & 0x01ull) << 1;
  s_cska4_out |= ((s_cska4_fa1_xor1 >> 0) & 0x01ull) << 2;
  s_cska4_out |= ((s_cska4_fa2_xor1 >> 0) & 0x01ull) << 3;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 4;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 5;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 6;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 7;
  return s_cska4_out;
}