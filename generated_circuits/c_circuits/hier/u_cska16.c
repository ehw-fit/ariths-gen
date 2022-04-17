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

uint64_t u_cska16(uint64_t a, uint64_t b){
  uint64_t u_cska16_out = 0;
  uint8_t u_cska16_xor0 = 0;
  uint8_t u_cska16_ha0_xor0 = 0;
  uint8_t u_cska16_ha0_and0 = 0;
  uint8_t u_cska16_xor1 = 0;
  uint8_t u_cska16_fa0_xor1 = 0;
  uint8_t u_cska16_fa0_or0 = 0;
  uint8_t u_cska16_xor2 = 0;
  uint8_t u_cska16_fa1_xor1 = 0;
  uint8_t u_cska16_fa1_or0 = 0;
  uint8_t u_cska16_xor3 = 0;
  uint8_t u_cska16_fa2_xor1 = 0;
  uint8_t u_cska16_fa2_or0 = 0;
  uint8_t u_cska16_and_propagate00 = 0;
  uint8_t u_cska16_and_propagate01 = 0;
  uint8_t u_cska16_and_propagate02 = 0;
  uint8_t u_cska16_mux2to10_and1 = 0;
  uint8_t u_cska16_xor4 = 0;
  uint8_t u_cska16_fa3_xor1 = 0;
  uint8_t u_cska16_fa3_or0 = 0;
  uint8_t u_cska16_xor5 = 0;
  uint8_t u_cska16_fa4_xor1 = 0;
  uint8_t u_cska16_fa4_or0 = 0;
  uint8_t u_cska16_xor6 = 0;
  uint8_t u_cska16_fa5_xor1 = 0;
  uint8_t u_cska16_fa5_or0 = 0;
  uint8_t u_cska16_xor7 = 0;
  uint8_t u_cska16_fa6_xor1 = 0;
  uint8_t u_cska16_fa6_or0 = 0;
  uint8_t u_cska16_and_propagate13 = 0;
  uint8_t u_cska16_and_propagate14 = 0;
  uint8_t u_cska16_and_propagate15 = 0;
  uint8_t u_cska16_mux2to11_xor0 = 0;
  uint8_t u_cska16_xor8 = 0;
  uint8_t u_cska16_fa7_xor1 = 0;
  uint8_t u_cska16_fa7_or0 = 0;
  uint8_t u_cska16_xor9 = 0;
  uint8_t u_cska16_fa8_xor1 = 0;
  uint8_t u_cska16_fa8_or0 = 0;
  uint8_t u_cska16_xor10 = 0;
  uint8_t u_cska16_fa9_xor1 = 0;
  uint8_t u_cska16_fa9_or0 = 0;
  uint8_t u_cska16_xor11 = 0;
  uint8_t u_cska16_fa10_xor1 = 0;
  uint8_t u_cska16_fa10_or0 = 0;
  uint8_t u_cska16_and_propagate26 = 0;
  uint8_t u_cska16_and_propagate27 = 0;
  uint8_t u_cska16_and_propagate28 = 0;
  uint8_t u_cska16_mux2to12_xor0 = 0;
  uint8_t u_cska16_xor12 = 0;
  uint8_t u_cska16_fa11_xor1 = 0;
  uint8_t u_cska16_fa11_or0 = 0;
  uint8_t u_cska16_xor13 = 0;
  uint8_t u_cska16_fa12_xor1 = 0;
  uint8_t u_cska16_fa12_or0 = 0;
  uint8_t u_cska16_xor14 = 0;
  uint8_t u_cska16_fa13_xor1 = 0;
  uint8_t u_cska16_fa13_or0 = 0;
  uint8_t u_cska16_xor15 = 0;
  uint8_t u_cska16_fa14_xor1 = 0;
  uint8_t u_cska16_fa14_or0 = 0;
  uint8_t u_cska16_and_propagate39 = 0;
  uint8_t u_cska16_and_propagate310 = 0;
  uint8_t u_cska16_and_propagate311 = 0;
  uint8_t u_cska16_mux2to13_xor0 = 0;

  u_cska16_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_cska16_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_cska16_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska16_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska16_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_cska16_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska16_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska16_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_cska16_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska16_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska16_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_and_propagate00 = and_gate(((u_cska16_xor0 >> 0) & 0x01), ((u_cska16_xor2 >> 0) & 0x01));
  u_cska16_and_propagate01 = and_gate(((u_cska16_xor1 >> 0) & 0x01), ((u_cska16_xor3 >> 0) & 0x01));
  u_cska16_and_propagate02 = and_gate(((u_cska16_and_propagate00 >> 0) & 0x01), ((u_cska16_and_propagate01 >> 0) & 0x01));
  u_cska16_mux2to10_and1 = (mux2to1(((u_cska16_fa2_or0 >> 0) & 0x01), (0x00), ((u_cska16_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_xor4 = xor_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  u_cska16_fa3_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska16_mux2to10_and1 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa3_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska16_mux2to10_and1 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor5 = xor_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  u_cska16_fa4_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_cska16_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa4_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_cska16_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor6 = xor_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  u_cska16_fa5_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_cska16_fa4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa5_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_cska16_fa4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor7 = xor_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  u_cska16_fa6_xor1 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_cska16_fa5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa6_or0 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_cska16_fa5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_and_propagate13 = and_gate(((u_cska16_xor4 >> 0) & 0x01), ((u_cska16_xor6 >> 0) & 0x01));
  u_cska16_and_propagate14 = and_gate(((u_cska16_xor5 >> 0) & 0x01), ((u_cska16_xor7 >> 0) & 0x01));
  u_cska16_and_propagate15 = and_gate(((u_cska16_and_propagate13 >> 0) & 0x01), ((u_cska16_and_propagate14 >> 0) & 0x01));
  u_cska16_mux2to11_xor0 = (mux2to1(((u_cska16_fa6_or0 >> 0) & 0x01), ((u_cska16_mux2to10_and1 >> 0) & 0x01), ((u_cska16_and_propagate15 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_xor8 = xor_gate(((a >> 8) & 0x01), ((b >> 8) & 0x01));
  u_cska16_fa7_xor1 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((u_cska16_mux2to11_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa7_or0 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((u_cska16_mux2to11_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor9 = xor_gate(((a >> 9) & 0x01), ((b >> 9) & 0x01));
  u_cska16_fa8_xor1 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((u_cska16_fa7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa8_or0 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((u_cska16_fa7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor10 = xor_gate(((a >> 10) & 0x01), ((b >> 10) & 0x01));
  u_cska16_fa9_xor1 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((u_cska16_fa8_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa9_or0 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((u_cska16_fa8_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor11 = xor_gate(((a >> 11) & 0x01), ((b >> 11) & 0x01));
  u_cska16_fa10_xor1 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((u_cska16_fa9_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa10_or0 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((u_cska16_fa9_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_and_propagate26 = and_gate(((u_cska16_xor8 >> 0) & 0x01), ((u_cska16_xor10 >> 0) & 0x01));
  u_cska16_and_propagate27 = and_gate(((u_cska16_xor9 >> 0) & 0x01), ((u_cska16_xor11 >> 0) & 0x01));
  u_cska16_and_propagate28 = and_gate(((u_cska16_and_propagate26 >> 0) & 0x01), ((u_cska16_and_propagate27 >> 0) & 0x01));
  u_cska16_mux2to12_xor0 = (mux2to1(((u_cska16_fa10_or0 >> 0) & 0x01), ((u_cska16_mux2to11_xor0 >> 0) & 0x01), ((u_cska16_and_propagate28 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_xor12 = xor_gate(((a >> 12) & 0x01), ((b >> 12) & 0x01));
  u_cska16_fa11_xor1 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((u_cska16_mux2to12_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa11_or0 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((u_cska16_mux2to12_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor13 = xor_gate(((a >> 13) & 0x01), ((b >> 13) & 0x01));
  u_cska16_fa12_xor1 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((u_cska16_fa11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa12_or0 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((u_cska16_fa11_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor14 = xor_gate(((a >> 14) & 0x01), ((b >> 14) & 0x01));
  u_cska16_fa13_xor1 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((u_cska16_fa12_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa13_or0 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((u_cska16_fa12_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_xor15 = xor_gate(((a >> 15) & 0x01), ((b >> 15) & 0x01));
  u_cska16_fa14_xor1 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((u_cska16_fa13_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska16_fa14_or0 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((u_cska16_fa13_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska16_and_propagate39 = and_gate(((u_cska16_xor12 >> 0) & 0x01), ((u_cska16_xor14 >> 0) & 0x01));
  u_cska16_and_propagate310 = and_gate(((u_cska16_xor13 >> 0) & 0x01), ((u_cska16_xor15 >> 0) & 0x01));
  u_cska16_and_propagate311 = and_gate(((u_cska16_and_propagate39 >> 0) & 0x01), ((u_cska16_and_propagate310 >> 0) & 0x01));
  u_cska16_mux2to13_xor0 = (mux2to1(((u_cska16_fa14_or0 >> 0) & 0x01), ((u_cska16_mux2to12_xor0 >> 0) & 0x01), ((u_cska16_and_propagate311 >> 0) & 0x01)) >> 0) & 0x01;

  u_cska16_out |= ((u_cska16_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska16_out |= ((u_cska16_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska16_out |= ((u_cska16_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska16_out |= ((u_cska16_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska16_out |= ((u_cska16_fa3_xor1 >> 0) & 0x01ull) << 4;
  u_cska16_out |= ((u_cska16_fa4_xor1 >> 0) & 0x01ull) << 5;
  u_cska16_out |= ((u_cska16_fa5_xor1 >> 0) & 0x01ull) << 6;
  u_cska16_out |= ((u_cska16_fa6_xor1 >> 0) & 0x01ull) << 7;
  u_cska16_out |= ((u_cska16_fa7_xor1 >> 0) & 0x01ull) << 8;
  u_cska16_out |= ((u_cska16_fa8_xor1 >> 0) & 0x01ull) << 9;
  u_cska16_out |= ((u_cska16_fa9_xor1 >> 0) & 0x01ull) << 10;
  u_cska16_out |= ((u_cska16_fa10_xor1 >> 0) & 0x01ull) << 11;
  u_cska16_out |= ((u_cska16_fa11_xor1 >> 0) & 0x01ull) << 12;
  u_cska16_out |= ((u_cska16_fa12_xor1 >> 0) & 0x01ull) << 13;
  u_cska16_out |= ((u_cska16_fa13_xor1 >> 0) & 0x01ull) << 14;
  u_cska16_out |= ((u_cska16_fa14_xor1 >> 0) & 0x01ull) << 15;
  u_cska16_out |= ((u_cska16_mux2to13_xor0 >> 0) & 0x01ull) << 16;
  return u_cska16_out;
}