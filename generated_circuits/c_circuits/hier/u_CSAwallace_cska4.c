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

uint64_t csa_component6(uint64_t a, uint64_t b, uint64_t c){
  uint64_t csa_component6_out = 0;
  uint8_t csa_component6_fa0_xor1 = 0;
  uint8_t csa_component6_fa0_or0 = 0;
  uint8_t csa_component6_fa1_xor1 = 0;
  uint8_t csa_component6_fa1_or0 = 0;
  uint8_t csa_component6_fa2_xor1 = 0;
  uint8_t csa_component6_fa2_or0 = 0;
  uint8_t csa_component6_fa3_xor1 = 0;
  uint8_t csa_component6_fa3_or0 = 0;
  uint8_t csa_component6_fa4_xor1 = 0;
  uint8_t csa_component6_fa4_or0 = 0;
  uint8_t csa_component6_fa5_xor1 = 0;
  uint8_t csa_component6_fa5_or0 = 0;

  csa_component6_fa0_xor1 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 0) & 0x01;
  csa_component6_fa0_or0 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 1) & 0x01;
  csa_component6_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 0) & 0x01;
  csa_component6_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 1) & 0x01;
  csa_component6_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 0) & 0x01;
  csa_component6_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 1) & 0x01;
  csa_component6_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 0) & 0x01;
  csa_component6_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 1) & 0x01;
  csa_component6_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 0) & 0x01;
  csa_component6_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 1) & 0x01;
  csa_component6_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 0) & 0x01;
  csa_component6_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 1) & 0x01;

  csa_component6_out |= ((csa_component6_fa0_xor1 >> 0) & 0x01ull) << 0;
  csa_component6_out |= ((csa_component6_fa1_xor1 >> 0) & 0x01ull) << 1;
  csa_component6_out |= ((csa_component6_fa2_xor1 >> 0) & 0x01ull) << 2;
  csa_component6_out |= ((csa_component6_fa3_xor1 >> 0) & 0x01ull) << 3;
  csa_component6_out |= ((csa_component6_fa4_xor1 >> 0) & 0x01ull) << 4;
  csa_component6_out |= ((csa_component6_fa5_xor1 >> 0) & 0x01ull) << 5;
  csa_component6_out |= (0x00) << 6;
  csa_component6_out |= (0x00) << 7;
  csa_component6_out |= ((csa_component6_fa0_or0 >> 0) & 0x01ull) << 8;
  csa_component6_out |= ((csa_component6_fa1_or0 >> 0) & 0x01ull) << 9;
  csa_component6_out |= ((csa_component6_fa2_or0 >> 0) & 0x01ull) << 10;
  csa_component6_out |= ((csa_component6_fa3_or0 >> 0) & 0x01ull) << 11;
  csa_component6_out |= ((csa_component6_fa4_or0 >> 0) & 0x01ull) << 12;
  csa_component6_out |= ((csa_component6_fa5_or0 >> 0) & 0x01ull) << 13;
  return csa_component6_out;
}

uint64_t csa_component7(uint64_t a, uint64_t b, uint64_t c){
  uint64_t csa_component7_out = 0;
  uint8_t csa_component7_fa0_xor1 = 0;
  uint8_t csa_component7_fa0_or0 = 0;
  uint8_t csa_component7_fa1_xor1 = 0;
  uint8_t csa_component7_fa1_or0 = 0;
  uint8_t csa_component7_fa2_xor1 = 0;
  uint8_t csa_component7_fa2_or0 = 0;
  uint8_t csa_component7_fa3_xor1 = 0;
  uint8_t csa_component7_fa3_or0 = 0;
  uint8_t csa_component7_fa4_xor1 = 0;
  uint8_t csa_component7_fa4_or0 = 0;
  uint8_t csa_component7_fa5_xor1 = 0;
  uint8_t csa_component7_fa5_or0 = 0;
  uint8_t csa_component7_fa6_xor1 = 0;
  uint8_t csa_component7_fa6_or0 = 0;

  csa_component7_fa0_xor1 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 0) & 0x01;
  csa_component7_fa0_or0 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 1) & 0x01;
  csa_component7_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 0) & 0x01;
  csa_component7_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 1) & 0x01;
  csa_component7_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 0) & 0x01;
  csa_component7_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 1) & 0x01;
  csa_component7_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 0) & 0x01;
  csa_component7_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 1) & 0x01;
  csa_component7_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 0) & 0x01;
  csa_component7_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 1) & 0x01;
  csa_component7_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 0) & 0x01;
  csa_component7_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 1) & 0x01;
  csa_component7_fa6_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((c >> 6) & 0x01)) >> 0) & 0x01;
  csa_component7_fa6_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((c >> 6) & 0x01)) >> 1) & 0x01;

  csa_component7_out |= ((csa_component7_fa0_xor1 >> 0) & 0x01ull) << 0;
  csa_component7_out |= ((csa_component7_fa1_xor1 >> 0) & 0x01ull) << 1;
  csa_component7_out |= ((csa_component7_fa2_xor1 >> 0) & 0x01ull) << 2;
  csa_component7_out |= ((csa_component7_fa3_xor1 >> 0) & 0x01ull) << 3;
  csa_component7_out |= ((csa_component7_fa4_xor1 >> 0) & 0x01ull) << 4;
  csa_component7_out |= ((csa_component7_fa5_xor1 >> 0) & 0x01ull) << 5;
  csa_component7_out |= ((csa_component7_fa6_xor1 >> 0) & 0x01ull) << 6;
  csa_component7_out |= (0x00) << 7;
  csa_component7_out |= (0x00) << 8;
  csa_component7_out |= ((csa_component7_fa0_or0 >> 0) & 0x01ull) << 9;
  csa_component7_out |= ((csa_component7_fa1_or0 >> 0) & 0x01ull) << 10;
  csa_component7_out |= ((csa_component7_fa2_or0 >> 0) & 0x01ull) << 11;
  csa_component7_out |= ((csa_component7_fa3_or0 >> 0) & 0x01ull) << 12;
  csa_component7_out |= ((csa_component7_fa4_or0 >> 0) & 0x01ull) << 13;
  csa_component7_out |= ((csa_component7_fa5_or0 >> 0) & 0x01ull) << 14;
  csa_component7_out |= ((csa_component7_fa6_or0 >> 0) & 0x01ull) << 15;
  return csa_component7_out;
}

uint64_t u_cska8(uint64_t a, uint64_t b){
  uint64_t u_cska8_out = 0;
  uint8_t u_cska8_xor0 = 0;
  uint8_t u_cska8_ha0_xor0 = 0;
  uint8_t u_cska8_ha0_and0 = 0;
  uint8_t u_cska8_xor1 = 0;
  uint8_t u_cska8_fa0_xor1 = 0;
  uint8_t u_cska8_fa0_or0 = 0;
  uint8_t u_cska8_xor2 = 0;
  uint8_t u_cska8_fa1_xor1 = 0;
  uint8_t u_cska8_fa1_or0 = 0;
  uint8_t u_cska8_xor3 = 0;
  uint8_t u_cska8_fa2_xor1 = 0;
  uint8_t u_cska8_fa2_or0 = 0;
  uint8_t u_cska8_and_propagate00 = 0;
  uint8_t u_cska8_and_propagate01 = 0;
  uint8_t u_cska8_and_propagate02 = 0;
  uint8_t u_cska8_mux2to10_and1 = 0;
  uint8_t u_cska8_xor4 = 0;
  uint8_t u_cska8_fa3_xor1 = 0;
  uint8_t u_cska8_fa3_or0 = 0;
  uint8_t u_cska8_xor5 = 0;
  uint8_t u_cska8_fa4_xor1 = 0;
  uint8_t u_cska8_fa4_or0 = 0;
  uint8_t u_cska8_xor6 = 0;
  uint8_t u_cska8_fa5_xor1 = 0;
  uint8_t u_cska8_fa5_or0 = 0;
  uint8_t u_cska8_xor7 = 0;
  uint8_t u_cska8_fa6_xor1 = 0;
  uint8_t u_cska8_fa6_or0 = 0;
  uint8_t u_cska8_and_propagate13 = 0;
  uint8_t u_cska8_and_propagate14 = 0;
  uint8_t u_cska8_and_propagate15 = 0;
  uint8_t u_cska8_mux2to11_xor0 = 0;

  u_cska8_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_cska8_ha0_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_ha0_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_xor1 = xor_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_cska8_fa0_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska8_ha0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa0_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_cska8_ha0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_xor2 = xor_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_cska8_fa1_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska8_fa0_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa1_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_cska8_fa0_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_xor3 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_cska8_fa2_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska8_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa2_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_cska8_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_and_propagate00 = and_gate(((u_cska8_xor0 >> 0) & 0x01), ((u_cska8_xor2 >> 0) & 0x01));
  u_cska8_and_propagate01 = and_gate(((u_cska8_xor1 >> 0) & 0x01), ((u_cska8_xor3 >> 0) & 0x01));
  u_cska8_and_propagate02 = and_gate(((u_cska8_and_propagate00 >> 0) & 0x01), ((u_cska8_and_propagate01 >> 0) & 0x01));
  u_cska8_mux2to10_and1 = (mux2to1(((u_cska8_fa2_or0 >> 0) & 0x01), (0x00), ((u_cska8_and_propagate02 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_xor4 = xor_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  u_cska8_fa3_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska8_mux2to10_and1 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa3_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((u_cska8_mux2to10_and1 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_xor5 = xor_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  u_cska8_fa4_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_cska8_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa4_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((u_cska8_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_xor6 = xor_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  u_cska8_fa5_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_cska8_fa4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa5_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((u_cska8_fa4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_xor7 = xor_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  u_cska8_fa6_xor1 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_cska8_fa5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_cska8_fa6_or0 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((u_cska8_fa5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_cska8_and_propagate13 = and_gate(((u_cska8_xor4 >> 0) & 0x01), ((u_cska8_xor6 >> 0) & 0x01));
  u_cska8_and_propagate14 = and_gate(((u_cska8_xor5 >> 0) & 0x01), ((u_cska8_xor7 >> 0) & 0x01));
  u_cska8_and_propagate15 = and_gate(((u_cska8_and_propagate13 >> 0) & 0x01), ((u_cska8_and_propagate14 >> 0) & 0x01));
  u_cska8_mux2to11_xor0 = (mux2to1(((u_cska8_fa6_or0 >> 0) & 0x01), ((u_cska8_mux2to10_and1 >> 0) & 0x01), ((u_cska8_and_propagate15 >> 0) & 0x01)) >> 0) & 0x01;

  u_cska8_out |= ((u_cska8_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska8_out |= ((u_cska8_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska8_out |= ((u_cska8_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska8_out |= ((u_cska8_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska8_out |= ((u_cska8_fa3_xor1 >> 0) & 0x01ull) << 4;
  u_cska8_out |= ((u_cska8_fa4_xor1 >> 0) & 0x01ull) << 5;
  u_cska8_out |= ((u_cska8_fa5_xor1 >> 0) & 0x01ull) << 6;
  u_cska8_out |= ((u_cska8_fa6_xor1 >> 0) & 0x01ull) << 7;
  u_cska8_out |= ((u_cska8_mux2to11_xor0 >> 0) & 0x01ull) << 8;
  return u_cska8_out;
}

uint64_t u_CSAwallace_cska4(uint64_t a, uint64_t b){
  uint8_t u_CSAwallace_cska4_out = 0;
  uint8_t u_CSAwallace_cska4_and_0_0 = 0;
  uint8_t u_CSAwallace_cska4_and_1_0 = 0;
  uint8_t u_CSAwallace_cska4_and_2_0 = 0;
  uint8_t u_CSAwallace_cska4_and_3_0 = 0;
  uint8_t u_CSAwallace_cska4_and_0_1 = 0;
  uint8_t u_CSAwallace_cska4_and_1_1 = 0;
  uint8_t u_CSAwallace_cska4_and_2_1 = 0;
  uint8_t u_CSAwallace_cska4_and_3_1 = 0;
  uint8_t u_CSAwallace_cska4_and_0_2 = 0;
  uint8_t u_CSAwallace_cska4_and_1_2 = 0;
  uint8_t u_CSAwallace_cska4_and_2_2 = 0;
  uint8_t u_CSAwallace_cska4_and_3_2 = 0;
  uint8_t u_CSAwallace_cska4_and_0_3 = 0;
  uint8_t u_CSAwallace_cska4_and_1_3 = 0;
  uint8_t u_CSAwallace_cska4_and_2_3 = 0;
  uint8_t u_CSAwallace_cska4_and_3_3 = 0;
  uint64_t u_CSAwallace_cska4_csa0_csa_component_pp_row0 = 0;
  uint64_t u_CSAwallace_cska4_csa0_csa_component_pp_row1 = 0;
  uint64_t u_CSAwallace_cska4_csa0_csa_component_pp_row2 = 0;
  uint64_t u_CSAwallace_cska4_csa0_csa_component_out = 0;
  uint64_t u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 = 0;
  uint64_t u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 = 0;
  uint64_t u_CSAwallace_cska4_csa1_csa_component_pp_row3 = 0;
  uint64_t u_CSAwallace_cska4_csa1_csa_component_out = 0;
  uint64_t u_CSAwallace_cska4_u_cska8_a = 0;
  uint64_t u_CSAwallace_cska4_u_cska8_b = 0;
  uint64_t u_CSAwallace_cska4_u_cska8_out = 0;

  u_CSAwallace_cska4_and_0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  u_CSAwallace_cska4_and_1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  u_CSAwallace_cska4_and_2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  u_CSAwallace_cska4_and_3_0 = and_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  u_CSAwallace_cska4_and_0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  u_CSAwallace_cska4_and_1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  u_CSAwallace_cska4_and_2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  u_CSAwallace_cska4_and_3_1 = and_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  u_CSAwallace_cska4_and_0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  u_CSAwallace_cska4_and_1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  u_CSAwallace_cska4_and_2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  u_CSAwallace_cska4_and_3_2 = and_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  u_CSAwallace_cska4_and_0_3 = and_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  u_CSAwallace_cska4_and_1_3 = and_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  u_CSAwallace_cska4_and_2_3 = and_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  u_CSAwallace_cska4_and_3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  u_CSAwallace_cska4_csa0_csa_component_pp_row0 |= ((u_CSAwallace_cska4_and_0_0 >> 0) & 0x01ull) << 0;
  u_CSAwallace_cska4_csa0_csa_component_pp_row0 |= ((u_CSAwallace_cska4_and_1_0 >> 0) & 0x01ull) << 1;
  u_CSAwallace_cska4_csa0_csa_component_pp_row0 |= ((u_CSAwallace_cska4_and_2_0 >> 0) & 0x01ull) << 2;
  u_CSAwallace_cska4_csa0_csa_component_pp_row0 |= ((u_CSAwallace_cska4_and_3_0 >> 0) & 0x01ull) << 3;
  u_CSAwallace_cska4_csa0_csa_component_pp_row0 |= (0x00) << 4;
  u_CSAwallace_cska4_csa0_csa_component_pp_row0 |= (0x00) << 5;
  u_CSAwallace_cska4_csa0_csa_component_pp_row1 |= (0x00) << 0;
  u_CSAwallace_cska4_csa0_csa_component_pp_row1 |= ((u_CSAwallace_cska4_and_0_1 >> 0) & 0x01ull) << 1;
  u_CSAwallace_cska4_csa0_csa_component_pp_row1 |= ((u_CSAwallace_cska4_and_1_1 >> 0) & 0x01ull) << 2;
  u_CSAwallace_cska4_csa0_csa_component_pp_row1 |= ((u_CSAwallace_cska4_and_2_1 >> 0) & 0x01ull) << 3;
  u_CSAwallace_cska4_csa0_csa_component_pp_row1 |= ((u_CSAwallace_cska4_and_3_1 >> 0) & 0x01ull) << 4;
  u_CSAwallace_cska4_csa0_csa_component_pp_row1 |= (0x00) << 5;
  u_CSAwallace_cska4_csa0_csa_component_pp_row2 |= (0x00) << 0;
  u_CSAwallace_cska4_csa0_csa_component_pp_row2 |= (0x00) << 1;
  u_CSAwallace_cska4_csa0_csa_component_pp_row2 |= ((u_CSAwallace_cska4_and_0_2 >> 0) & 0x01ull) << 2;
  u_CSAwallace_cska4_csa0_csa_component_pp_row2 |= ((u_CSAwallace_cska4_and_1_2 >> 0) & 0x01ull) << 3;
  u_CSAwallace_cska4_csa0_csa_component_pp_row2 |= ((u_CSAwallace_cska4_and_2_2 >> 0) & 0x01ull) << 4;
  u_CSAwallace_cska4_csa0_csa_component_pp_row2 |= ((u_CSAwallace_cska4_and_3_2 >> 0) & 0x01ull) << 5;
  u_CSAwallace_cska4_csa0_csa_component_out = csa_component6(u_CSAwallace_cska4_csa0_csa_component_pp_row0, u_CSAwallace_cska4_csa0_csa_component_pp_row1, u_CSAwallace_cska4_csa0_csa_component_pp_row2);
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 0) & 0x01ull) << 0;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 1) & 0x01ull) << 1;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 2) & 0x01ull) << 2;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 3) & 0x01ull) << 3;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 4) & 0x01ull) << 4;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 5) & 0x01ull) << 5;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1 |= (0x00) << 6;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= (0x00) << 0;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= (0x00) << 1;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 9) & 0x01ull) << 2;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 10) & 0x01ull) << 3;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 11) & 0x01ull) << 4;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= ((u_CSAwallace_cska4_csa0_csa_component_out >> 12) & 0x01ull) << 5;
  u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1 |= (0x00) << 6;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= (0x00) << 0;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= (0x00) << 1;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= (0x00) << 2;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= ((u_CSAwallace_cska4_and_0_3 >> 0) & 0x01ull) << 3;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= ((u_CSAwallace_cska4_and_1_3 >> 0) & 0x01ull) << 4;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= ((u_CSAwallace_cska4_and_2_3 >> 0) & 0x01ull) << 5;
  u_CSAwallace_cska4_csa1_csa_component_pp_row3 |= ((u_CSAwallace_cska4_and_3_3 >> 0) & 0x01ull) << 6;
  u_CSAwallace_cska4_csa1_csa_component_out = csa_component7(u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_s1, u_CSAwallace_cska4_csa1_csa_component_u_CSAwallace_cska4_csa_c1, u_CSAwallace_cska4_csa1_csa_component_pp_row3);
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 0) & 0x01ull) << 0;
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 1) & 0x01ull) << 1;
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 2) & 0x01ull) << 2;
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 3) & 0x01ull) << 3;
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 4) & 0x01ull) << 4;
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 5) & 0x01ull) << 5;
  u_CSAwallace_cska4_u_cska8_a |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 6) & 0x01ull) << 6;
  u_CSAwallace_cska4_u_cska8_a |= (0x00) << 7;
  u_CSAwallace_cska4_u_cska8_b |= (0x00) << 0;
  u_CSAwallace_cska4_u_cska8_b |= (0x00) << 1;
  u_CSAwallace_cska4_u_cska8_b |= (0x00) << 2;
  u_CSAwallace_cska4_u_cska8_b |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 11) & 0x01ull) << 3;
  u_CSAwallace_cska4_u_cska8_b |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 12) & 0x01ull) << 4;
  u_CSAwallace_cska4_u_cska8_b |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 13) & 0x01ull) << 5;
  u_CSAwallace_cska4_u_cska8_b |= ((u_CSAwallace_cska4_csa1_csa_component_out >> 14) & 0x01ull) << 6;
  u_CSAwallace_cska4_u_cska8_b |= (0x00) << 7;
  u_CSAwallace_cska4_u_cska8_out = u_cska8(u_CSAwallace_cska4_u_cska8_a, u_CSAwallace_cska4_u_cska8_b);

  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 0) & 0x01ull) << 0;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 1) & 0x01ull) << 1;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 2) & 0x01ull) << 2;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 3) & 0x01ull) << 3;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 4) & 0x01ull) << 4;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 5) & 0x01ull) << 5;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 6) & 0x01ull) << 6;
  u_CSAwallace_cska4_out |= ((u_CSAwallace_cska4_u_cska8_out >> 7) & 0x01ull) << 7;
  return u_CSAwallace_cska4_out;
}