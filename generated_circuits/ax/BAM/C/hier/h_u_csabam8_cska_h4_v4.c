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

uint64_t h_u_csabam8_cska_h4_v4(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_cska_h4_v4_out = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and0_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and1_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and2_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and3_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and4_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and5_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and6_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and7_4 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and0_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha0_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha0_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and1_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha1_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha1_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and2_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha2_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha2_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and3_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha3_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha3_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and4_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha4_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha4_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and5_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha5_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha5_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and6_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha6_5_xor0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_ha6_5_and0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and7_5 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and0_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa0_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa0_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and1_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa1_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa1_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and2_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa2_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa2_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and3_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa3_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa3_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and4_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa4_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa4_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and5_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa5_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa5_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and6_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa6_6_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa6_6_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and7_6 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and0_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa0_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa0_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and1_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa1_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa1_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and2_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa2_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa2_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and3_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa3_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa3_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and4_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa4_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa4_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and5_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa5_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa5_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and6_7 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_cska_h4_v4_and7_7 = 0;
  uint64_t h_u_csabam8_cska_h4_v4_u_cska8_a = 0;
  uint64_t h_u_csabam8_cska_h4_v4_u_cska8_b = 0;
  uint64_t h_u_csabam8_cska_h4_v4_u_cska8_out = 0;

  h_u_csabam8_cska_h4_v4_and0_4 = and_gate(((a >> 0) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and1_4 = and_gate(((a >> 1) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and2_4 = and_gate(((a >> 2) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and3_4 = and_gate(((a >> 3) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and4_4 = and_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and5_4 = and_gate(((a >> 5) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and6_4 = and_gate(((a >> 6) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and7_4 = and_gate(((a >> 7) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cska_h4_v4_and0_5 = and_gate(((a >> 0) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha0_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and0_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and1_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha0_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and0_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and1_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and1_5 = and_gate(((a >> 1) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha1_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and1_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and2_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha1_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and1_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and2_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and2_5 = and_gate(((a >> 2) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha2_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and2_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and3_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha2_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and2_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and3_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and3_5 = and_gate(((a >> 3) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha3_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and3_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and4_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha3_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and3_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and4_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha4_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and4_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and5_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha4_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and4_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and5_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha5_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and5_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and6_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha5_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and5_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and6_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_ha6_5_xor0 = (ha(((h_u_csabam8_cska_h4_v4_and6_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and7_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_ha6_5_and0 = (ha(((h_u_csabam8_cska_h4_v4_and6_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and7_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cska_h4_v4_and0_6 = and_gate(((a >> 0) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa0_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and0_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha1_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha0_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa0_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and0_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha1_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha0_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and1_6 = and_gate(((a >> 1) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa1_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and1_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha2_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha1_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa1_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and1_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha2_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha1_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and2_6 = and_gate(((a >> 2) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa2_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and2_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha3_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha2_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa2_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and2_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha3_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha2_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa3_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and3_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha4_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha3_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa3_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and3_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha4_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha3_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa4_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and4_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha5_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha4_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa4_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and4_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha5_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha4_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa5_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and5_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha6_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha5_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa5_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and5_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha6_5_xor0 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha5_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_fa6_6_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and6_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and7_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha6_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa6_6_or0 = (fa(((h_u_csabam8_cska_h4_v4_and6_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and7_5 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_ha6_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cska_h4_v4_and0_7 = and_gate(((a >> 0) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa0_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and0_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa1_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa0_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa0_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and0_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa1_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa0_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and1_7 = and_gate(((a >> 1) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa1_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and1_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa2_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa1_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa1_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and1_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa2_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa1_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa2_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and2_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa3_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa2_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa2_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and2_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa3_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa2_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa3_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and3_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa4_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa3_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa3_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and3_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa4_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa3_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa4_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and4_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa5_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa4_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa4_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and4_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa5_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa4_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa5_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and5_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa5_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa5_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and5_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa5_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_fa6_7_xor1 = (fa(((h_u_csabam8_cska_h4_v4_and6_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and7_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa6_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cska_h4_v4_fa6_7_or0 = (fa(((h_u_csabam8_cska_h4_v4_and6_7 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_and7_6 >> 0) & 0x01), ((h_u_csabam8_cska_h4_v4_fa6_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cska_h4_v4_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_fa1_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_fa2_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_fa3_7_xor1 >> 0) & 0x01ull) << 2;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_fa4_7_xor1 >> 0) & 0x01ull) << 3;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_fa5_7_xor1 >> 0) & 0x01ull) << 4;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_fa6_7_xor1 >> 0) & 0x01ull) << 5;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= ((h_u_csabam8_cska_h4_v4_and7_7 >> 0) & 0x01ull) << 6;
  h_u_csabam8_cska_h4_v4_u_cska8_a |= (0x00) << 7;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa0_7_or0 >> 0) & 0x01ull) << 0;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa1_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa2_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa3_7_or0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa4_7_or0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa5_7_or0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= ((h_u_csabam8_cska_h4_v4_fa6_7_or0 >> 0) & 0x01ull) << 6;
  h_u_csabam8_cska_h4_v4_u_cska8_b |= (0x00) << 7;
  h_u_csabam8_cska_h4_v4_u_cska8_out = u_cska8(h_u_csabam8_cska_h4_v4_u_cska8_a, h_u_csabam8_cska_h4_v4_u_cska8_b);

  h_u_csabam8_cska_h4_v4_out |= (0x00) << 0;
  h_u_csabam8_cska_h4_v4_out |= (0x00) << 1;
  h_u_csabam8_cska_h4_v4_out |= (0x00) << 2;
  h_u_csabam8_cska_h4_v4_out |= (0x00) << 3;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_and0_4 >> 0) & 0x01ull) << 4;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_ha0_5_xor0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_fa0_6_xor1 >> 0) & 0x01ull) << 6;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_fa0_7_xor1 >> 0) & 0x01ull) << 7;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 0) & 0x01ull) << 8;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 1) & 0x01ull) << 9;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 2) & 0x01ull) << 10;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 3) & 0x01ull) << 11;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 4) & 0x01ull) << 12;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 5) & 0x01ull) << 13;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 6) & 0x01ull) << 14;
  h_u_csabam8_cska_h4_v4_out |= ((h_u_csabam8_cska_h4_v4_u_cska8_out >> 7) & 0x01ull) << 15;
  return h_u_csabam8_cska_h4_v4_out;
}