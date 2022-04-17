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

int64_t s_cska24(int64_t a, int64_t b){
  int64_t s_cska24_out = 0;
  uint8_t s_cska24_xor0 = 0;
  uint8_t s_cska24_ha0_xor0 = 0;
  uint8_t s_cska24_ha0_and0 = 0;
  uint8_t s_cska24_xor1 = 0;
  uint8_t s_cska24_fa0_xor1 = 0;
  uint8_t s_cska24_fa0_or0 = 0;
  uint8_t s_cska24_xor2 = 0;
  uint8_t s_cska24_fa1_xor1 = 0;
  uint8_t s_cska24_fa1_or0 = 0;
  uint8_t s_cska24_xor3 = 0;
  uint8_t s_cska24_fa2_xor1 = 0;
  uint8_t s_cska24_fa2_or0 = 0;
  uint8_t s_cska24_and_propagate00 = 0;
  uint8_t s_cska24_and_propagate01 = 0;
  uint8_t s_cska24_and_propagate02 = 0;
  uint8_t s_cska24_mux2to10_and1 = 0;
  uint8_t s_cska24_xor4 = 0;
  uint8_t s_cska24_fa3_xor1 = 0;
  uint8_t s_cska24_fa3_or0 = 0;
  uint8_t s_cska24_xor5 = 0;
  uint8_t s_cska24_fa4_xor1 = 0;
  uint8_t s_cska24_fa4_or0 = 0;
  uint8_t s_cska24_xor6 = 0;
  uint8_t s_cska24_fa5_xor1 = 0;
  uint8_t s_cska24_fa5_or0 = 0;
  uint8_t s_cska24_xor7 = 0;
  uint8_t s_cska24_fa6_xor1 = 0;
  uint8_t s_cska24_fa6_or0 = 0;
  uint8_t s_cska24_and_propagate13 = 0;
  uint8_t s_cska24_and_propagate14 = 0;
  uint8_t s_cska24_and_propagate15 = 0;
  uint8_t s_cska24_mux2to11_xor0 = 0;
  uint8_t s_cska24_xor8 = 0;
  uint8_t s_cska24_fa7_xor1 = 0;
  uint8_t s_cska24_fa7_or0 = 0;
  uint8_t s_cska24_xor9 = 0;
  uint8_t s_cska24_fa8_xor1 = 0;
  uint8_t s_cska24_fa8_or0 = 0;
  uint8_t s_cska24_xor10 = 0;
  uint8_t s_cska24_fa9_xor1 = 0;
  uint8_t s_cska24_fa9_or0 = 0;
  uint8_t s_cska24_xor11 = 0;
  uint8_t s_cska24_fa10_xor1 = 0;
  uint8_t s_cska24_fa10_or0 = 0;
  uint8_t s_cska24_and_propagate26 = 0;
  uint8_t s_cska24_and_propagate27 = 0;
  uint8_t s_cska24_and_propagate28 = 0;
  uint8_t s_cska24_mux2to12_xor0 = 0;
  uint8_t s_cska24_xor12 = 0;
  uint8_t s_cska24_fa11_xor1 = 0;
  uint8_t s_cska24_fa11_or0 = 0;
  uint8_t s_cska24_xor13 = 0;
  uint8_t s_cska24_fa12_xor1 = 0;
  uint8_t s_cska24_fa12_or0 = 0;
  uint8_t s_cska24_xor14 = 0;
  uint8_t s_cska24_fa13_xor1 = 0;
  uint8_t s_cska24_fa13_or0 = 0;
  uint8_t s_cska24_xor15 = 0;
  uint8_t s_cska24_fa14_xor1 = 0;
  uint8_t s_cska24_fa14_or0 = 0;
  uint8_t s_cska24_and_propagate39 = 0;
  uint8_t s_cska24_and_propagate310 = 0;
  uint8_t s_cska24_and_propagate311 = 0;
  uint8_t s_cska24_mux2to13_xor0 = 0;
  uint8_t s_cska24_xor16 = 0;
  uint8_t s_cska24_fa15_xor1 = 0;
  uint8_t s_cska24_fa15_or0 = 0;
  uint8_t s_cska24_xor17 = 0;
  uint8_t s_cska24_fa16_xor1 = 0;
  uint8_t s_cska24_fa16_or0 = 0;
  uint8_t s_cska24_xor18 = 0;
  uint8_t s_cska24_fa17_xor1 = 0;
  uint8_t s_cska24_fa17_or0 = 0;
  uint8_t s_cska24_xor19 = 0;
  uint8_t s_cska24_fa18_xor1 = 0;
  uint8_t s_cska24_fa18_or0 = 0;
  uint8_t s_cska24_and_propagate412 = 0;
  uint8_t s_cska24_and_propagate413 = 0;
  uint8_t s_cska24_and_propagate414 = 0;
  uint8_t s_cska24_mux2to14_xor0 = 0;
  uint8_t s_cska24_xor20 = 0;
  uint8_t s_cska24_fa19_xor1 = 0;
  uint8_t s_cska24_fa19_or0 = 0;
  uint8_t s_cska24_xor21 = 0;
  uint8_t s_cska24_fa20_xor1 = 0;
  uint8_t s_cska24_fa20_or0 = 0;
  uint8_t s_cska24_xor22 = 0;
  uint8_t s_cska24_fa21_xor1 = 0;
  uint8_t s_cska24_fa21_or0 = 0;
  uint8_t s_cska24_xor23 = 0;
  uint8_t s_cska24_fa22_xor1 = 0;
  uint8_t s_cska24_fa22_or0 = 0;
  uint8_t s_cska24_and_propagate515 = 0;
  uint8_t s_cska24_and_propagate516 = 0;
  uint8_t s_cska24_and_propagate517 = 0;
  uint8_t s_cska24_mux2to15_xor0 = 0;
  uint8_t s_cska24_xor24 = 0;
  uint8_t s_cska24_xor25 = 0;

  s_cska24_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  s_cska24_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  s_cska24_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_cska24_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_cska24_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  s_cska24_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_cska24_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_cska24_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_cska24_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_cska24_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_cska24_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_and_propagate00 = and_gate(((s_cska24_xor0 >> 0) & 0x01), ((s_cska24_xor2 >> 0) & 0x01));
  s_cska24_and_propagate01 = and_gate(((s_cska24_xor1 >> 0) & 0x01), ((s_cska24_xor3 >> 0) & 0x01));
  s_cska24_and_propagate02 = and_gate(((s_cska24_and_propagate00 >> 0) & 0x01), ((s_cska24_and_propagate01 >> 0) & 0x01));
  s_cska24_mux2to10_and1 = (mux2to1(((s_cska24_fa2_or0 >> 0) & 0x01), (0x00), ((s_cska24_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_xor4 = xor_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  s_cska24_fa3_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((s_cska24_mux2to10_and1 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa3_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((s_cska24_mux2to10_and1 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor5 = xor_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  s_cska24_fa4_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((s_cska24_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa4_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((s_cska24_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor6 = xor_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  s_cska24_fa5_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((s_cska24_fa4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa5_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((s_cska24_fa4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor7 = xor_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  s_cska24_fa6_xor1 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((s_cska24_fa5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa6_or0 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((s_cska24_fa5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_and_propagate13 = and_gate(((s_cska24_xor4 >> 0) & 0x01), ((s_cska24_xor6 >> 0) & 0x01));
  s_cska24_and_propagate14 = and_gate(((s_cska24_xor5 >> 0) & 0x01), ((s_cska24_xor7 >> 0) & 0x01));
  s_cska24_and_propagate15 = and_gate(((s_cska24_and_propagate13 >> 0) & 0x01), ((s_cska24_and_propagate14 >> 0) & 0x01));
  s_cska24_mux2to11_xor0 = (mux2to1(((s_cska24_fa6_or0 >> 0) & 0x01), ((s_cska24_mux2to10_and1 >> 0) & 0x01), ((s_cska24_and_propagate15 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_xor8 = xor_gate(((a >> 8) & 0x01), ((b >> 8) & 0x01));
  s_cska24_fa7_xor1 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((s_cska24_mux2to11_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa7_or0 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((s_cska24_mux2to11_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor9 = xor_gate(((a >> 9) & 0x01), ((b >> 9) & 0x01));
  s_cska24_fa8_xor1 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((s_cska24_fa7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa8_or0 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((s_cska24_fa7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor10 = xor_gate(((a >> 10) & 0x01), ((b >> 10) & 0x01));
  s_cska24_fa9_xor1 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((s_cska24_fa8_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa9_or0 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((s_cska24_fa8_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor11 = xor_gate(((a >> 11) & 0x01), ((b >> 11) & 0x01));
  s_cska24_fa10_xor1 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((s_cska24_fa9_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa10_or0 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((s_cska24_fa9_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_and_propagate26 = and_gate(((s_cska24_xor8 >> 0) & 0x01), ((s_cska24_xor10 >> 0) & 0x01));
  s_cska24_and_propagate27 = and_gate(((s_cska24_xor9 >> 0) & 0x01), ((s_cska24_xor11 >> 0) & 0x01));
  s_cska24_and_propagate28 = and_gate(((s_cska24_and_propagate26 >> 0) & 0x01), ((s_cska24_and_propagate27 >> 0) & 0x01));
  s_cska24_mux2to12_xor0 = (mux2to1(((s_cska24_fa10_or0 >> 0) & 0x01), ((s_cska24_mux2to11_xor0 >> 0) & 0x01), ((s_cska24_and_propagate28 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_xor12 = xor_gate(((a >> 12) & 0x01), ((b >> 12) & 0x01));
  s_cska24_fa11_xor1 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((s_cska24_mux2to12_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa11_or0 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((s_cska24_mux2to12_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor13 = xor_gate(((a >> 13) & 0x01), ((b >> 13) & 0x01));
  s_cska24_fa12_xor1 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((s_cska24_fa11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa12_or0 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((s_cska24_fa11_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor14 = xor_gate(((a >> 14) & 0x01), ((b >> 14) & 0x01));
  s_cska24_fa13_xor1 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((s_cska24_fa12_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa13_or0 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((s_cska24_fa12_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor15 = xor_gate(((a >> 15) & 0x01), ((b >> 15) & 0x01));
  s_cska24_fa14_xor1 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((s_cska24_fa13_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa14_or0 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((s_cska24_fa13_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_and_propagate39 = and_gate(((s_cska24_xor12 >> 0) & 0x01), ((s_cska24_xor14 >> 0) & 0x01));
  s_cska24_and_propagate310 = and_gate(((s_cska24_xor13 >> 0) & 0x01), ((s_cska24_xor15 >> 0) & 0x01));
  s_cska24_and_propagate311 = and_gate(((s_cska24_and_propagate39 >> 0) & 0x01), ((s_cska24_and_propagate310 >> 0) & 0x01));
  s_cska24_mux2to13_xor0 = (mux2to1(((s_cska24_fa14_or0 >> 0) & 0x01), ((s_cska24_mux2to12_xor0 >> 0) & 0x01), ((s_cska24_and_propagate311 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_xor16 = xor_gate(((a >> 16) & 0x01), ((b >> 16) & 0x01));
  s_cska24_fa15_xor1 = (fa(((a >> 16) & 0x01), ((b >> 16) & 0x01), ((s_cska24_mux2to13_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa15_or0 = (fa(((a >> 16) & 0x01), ((b >> 16) & 0x01), ((s_cska24_mux2to13_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor17 = xor_gate(((a >> 17) & 0x01), ((b >> 17) & 0x01));
  s_cska24_fa16_xor1 = (fa(((a >> 17) & 0x01), ((b >> 17) & 0x01), ((s_cska24_fa15_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa16_or0 = (fa(((a >> 17) & 0x01), ((b >> 17) & 0x01), ((s_cska24_fa15_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor18 = xor_gate(((a >> 18) & 0x01), ((b >> 18) & 0x01));
  s_cska24_fa17_xor1 = (fa(((a >> 18) & 0x01), ((b >> 18) & 0x01), ((s_cska24_fa16_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa17_or0 = (fa(((a >> 18) & 0x01), ((b >> 18) & 0x01), ((s_cska24_fa16_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor19 = xor_gate(((a >> 19) & 0x01), ((b >> 19) & 0x01));
  s_cska24_fa18_xor1 = (fa(((a >> 19) & 0x01), ((b >> 19) & 0x01), ((s_cska24_fa17_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa18_or0 = (fa(((a >> 19) & 0x01), ((b >> 19) & 0x01), ((s_cska24_fa17_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_and_propagate412 = and_gate(((s_cska24_xor16 >> 0) & 0x01), ((s_cska24_xor18 >> 0) & 0x01));
  s_cska24_and_propagate413 = and_gate(((s_cska24_xor17 >> 0) & 0x01), ((s_cska24_xor19 >> 0) & 0x01));
  s_cska24_and_propagate414 = and_gate(((s_cska24_and_propagate412 >> 0) & 0x01), ((s_cska24_and_propagate413 >> 0) & 0x01));
  s_cska24_mux2to14_xor0 = (mux2to1(((s_cska24_fa18_or0 >> 0) & 0x01), ((s_cska24_mux2to13_xor0 >> 0) & 0x01), ((s_cska24_and_propagate414 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_xor20 = xor_gate(((a >> 20) & 0x01), ((b >> 20) & 0x01));
  s_cska24_fa19_xor1 = (fa(((a >> 20) & 0x01), ((b >> 20) & 0x01), ((s_cska24_mux2to14_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa19_or0 = (fa(((a >> 20) & 0x01), ((b >> 20) & 0x01), ((s_cska24_mux2to14_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor21 = xor_gate(((a >> 21) & 0x01), ((b >> 21) & 0x01));
  s_cska24_fa20_xor1 = (fa(((a >> 21) & 0x01), ((b >> 21) & 0x01), ((s_cska24_fa19_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa20_or0 = (fa(((a >> 21) & 0x01), ((b >> 21) & 0x01), ((s_cska24_fa19_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor22 = xor_gate(((a >> 22) & 0x01), ((b >> 22) & 0x01));
  s_cska24_fa21_xor1 = (fa(((a >> 22) & 0x01), ((b >> 22) & 0x01), ((s_cska24_fa20_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa21_or0 = (fa(((a >> 22) & 0x01), ((b >> 22) & 0x01), ((s_cska24_fa20_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_xor23 = xor_gate(((a >> 23) & 0x01), ((b >> 23) & 0x01));
  s_cska24_fa22_xor1 = (fa(((a >> 23) & 0x01), ((b >> 23) & 0x01), ((s_cska24_fa21_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_fa22_or0 = (fa(((a >> 23) & 0x01), ((b >> 23) & 0x01), ((s_cska24_fa21_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_cska24_and_propagate515 = and_gate(((s_cska24_xor20 >> 0) & 0x01), ((s_cska24_xor22 >> 0) & 0x01));
  s_cska24_and_propagate516 = and_gate(((s_cska24_xor21 >> 0) & 0x01), ((s_cska24_xor23 >> 0) & 0x01));
  s_cska24_and_propagate517 = and_gate(((s_cska24_and_propagate515 >> 0) & 0x01), ((s_cska24_and_propagate516 >> 0) & 0x01));
  s_cska24_mux2to15_xor0 = (mux2to1(((s_cska24_fa22_or0 >> 0) & 0x01), ((s_cska24_mux2to14_xor0 >> 0) & 0x01), ((s_cska24_and_propagate517 >> 0) & 0x01)) >> 0) & 0x01;
  s_cska24_xor24 = xor_gate(((a >> 23) & 0x01), ((b >> 23) & 0x01));
  s_cska24_xor25 = xor_gate(((s_cska24_xor24 >> 0) & 0x01), ((s_cska24_mux2to15_xor0 >> 0) & 0x01));

  s_cska24_out |= ((s_cska24_ha0_xor0 >> 0) & 0x01ull) << 0;
  s_cska24_out |= ((s_cska24_fa0_xor1 >> 0) & 0x01ull) << 1;
  s_cska24_out |= ((s_cska24_fa1_xor1 >> 0) & 0x01ull) << 2;
  s_cska24_out |= ((s_cska24_fa2_xor1 >> 0) & 0x01ull) << 3;
  s_cska24_out |= ((s_cska24_fa3_xor1 >> 0) & 0x01ull) << 4;
  s_cska24_out |= ((s_cska24_fa4_xor1 >> 0) & 0x01ull) << 5;
  s_cska24_out |= ((s_cska24_fa5_xor1 >> 0) & 0x01ull) << 6;
  s_cska24_out |= ((s_cska24_fa6_xor1 >> 0) & 0x01ull) << 7;
  s_cska24_out |= ((s_cska24_fa7_xor1 >> 0) & 0x01ull) << 8;
  s_cska24_out |= ((s_cska24_fa8_xor1 >> 0) & 0x01ull) << 9;
  s_cska24_out |= ((s_cska24_fa9_xor1 >> 0) & 0x01ull) << 10;
  s_cska24_out |= ((s_cska24_fa10_xor1 >> 0) & 0x01ull) << 11;
  s_cska24_out |= ((s_cska24_fa11_xor1 >> 0) & 0x01ull) << 12;
  s_cska24_out |= ((s_cska24_fa12_xor1 >> 0) & 0x01ull) << 13;
  s_cska24_out |= ((s_cska24_fa13_xor1 >> 0) & 0x01ull) << 14;
  s_cska24_out |= ((s_cska24_fa14_xor1 >> 0) & 0x01ull) << 15;
  s_cska24_out |= ((s_cska24_fa15_xor1 >> 0) & 0x01ull) << 16;
  s_cska24_out |= ((s_cska24_fa16_xor1 >> 0) & 0x01ull) << 17;
  s_cska24_out |= ((s_cska24_fa17_xor1 >> 0) & 0x01ull) << 18;
  s_cska24_out |= ((s_cska24_fa18_xor1 >> 0) & 0x01ull) << 19;
  s_cska24_out |= ((s_cska24_fa19_xor1 >> 0) & 0x01ull) << 20;
  s_cska24_out |= ((s_cska24_fa20_xor1 >> 0) & 0x01ull) << 21;
  s_cska24_out |= ((s_cska24_fa21_xor1 >> 0) & 0x01ull) << 22;
  s_cska24_out |= ((s_cska24_fa22_xor1 >> 0) & 0x01ull) << 23;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 24;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 25;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 26;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 27;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 28;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 29;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 30;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 31;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 32;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 33;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 34;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 35;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 36;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 37;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 38;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 39;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 40;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 41;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 42;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 43;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 44;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 45;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 46;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 47;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 48;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 49;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 50;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 51;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 52;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 53;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 54;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 55;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 56;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 57;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 58;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 59;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 60;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 61;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 62;
  s_cska24_out |= ((s_cska24_xor25 >> 0) & 0x01ull) << 63;
  return s_cska24_out;
}