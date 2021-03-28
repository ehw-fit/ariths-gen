#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) | ((_b >> 0) & 0x01);
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t ha_a = 0;
  uint8_t ha_b = 0;
  uint8_t ha_y0 = 0;
  uint8_t ha_y1 = 0;

  ha_a = ((a >> 0) & 0x01);
  ha_b = ((b >> 0) & 0x01);
  ha_y0 = xor_gate(ha_a, ha_b);
  ha_y1 = and_gate(ha_a, ha_b);

  out |= (ha_y0 & 0x01) << 0;
  out |= (ha_y1 & 0x01) << 1;
  return out;
}

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t fa_a = 0;
  uint8_t fa_b = 0;
  uint8_t fa_y0 = 0;
  uint8_t fa_y1 = 0;
  uint8_t fa_cin = 0;
  uint8_t fa_y2 = 0;
  uint8_t fa_y3 = 0;
  uint8_t fa_y4 = 0;

  fa_a = ((a >> 0) & 0x01);
  fa_b = ((b >> 0) & 0x01);
  fa_cin = ((cin >> 0) & 0x01);
  fa_y0 = xor_gate(fa_a, fa_b);
  fa_y1 = and_gate(fa_a, fa_b);
  fa_y2 = xor_gate(fa_y0, fa_cin);
  fa_y3 = and_gate(fa_y0, fa_cin);
  fa_y4 = or_gate(fa_y1, fa_y3);

  out |= (fa_y2 & 0x01) << 0;
  out |= (fa_y4 & 0x01) << 1;
  return out;
}

uint64_t h_s_rca16(uint64_t a, uint64_t b){
  uint64_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t a_4 = 0;
  uint8_t a_5 = 0;
  uint8_t a_6 = 0;
  uint8_t a_7 = 0;
  uint8_t a_8 = 0;
  uint8_t a_9 = 0;
  uint8_t a_10 = 0;
  uint8_t a_11 = 0;
  uint8_t a_12 = 0;
  uint8_t a_13 = 0;
  uint8_t a_14 = 0;
  uint8_t a_15 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t b_4 = 0;
  uint8_t b_5 = 0;
  uint8_t b_6 = 0;
  uint8_t b_7 = 0;
  uint8_t b_8 = 0;
  uint8_t b_9 = 0;
  uint8_t b_10 = 0;
  uint8_t b_11 = 0;
  uint8_t b_12 = 0;
  uint8_t b_13 = 0;
  uint8_t b_14 = 0;
  uint8_t b_15 = 0;
  uint8_t h_s_rca16_ha_y0 = 0;
  uint8_t h_s_rca16_ha_y1 = 0;
  uint8_t h_s_rca16_fa1_y2 = 0;
  uint8_t h_s_rca16_fa1_y4 = 0;
  uint8_t h_s_rca16_fa2_y2 = 0;
  uint8_t h_s_rca16_fa2_y4 = 0;
  uint8_t h_s_rca16_fa3_y2 = 0;
  uint8_t h_s_rca16_fa3_y4 = 0;
  uint8_t h_s_rca16_fa4_y2 = 0;
  uint8_t h_s_rca16_fa4_y4 = 0;
  uint8_t h_s_rca16_fa5_y2 = 0;
  uint8_t h_s_rca16_fa5_y4 = 0;
  uint8_t h_s_rca16_fa6_y2 = 0;
  uint8_t h_s_rca16_fa6_y4 = 0;
  uint8_t h_s_rca16_fa7_y2 = 0;
  uint8_t h_s_rca16_fa7_y4 = 0;
  uint8_t h_s_rca16_fa8_y2 = 0;
  uint8_t h_s_rca16_fa8_y4 = 0;
  uint8_t h_s_rca16_fa9_y2 = 0;
  uint8_t h_s_rca16_fa9_y4 = 0;
  uint8_t h_s_rca16_fa10_y2 = 0;
  uint8_t h_s_rca16_fa10_y4 = 0;
  uint8_t h_s_rca16_fa11_y2 = 0;
  uint8_t h_s_rca16_fa11_y4 = 0;
  uint8_t h_s_rca16_fa12_y2 = 0;
  uint8_t h_s_rca16_fa12_y4 = 0;
  uint8_t h_s_rca16_fa13_y2 = 0;
  uint8_t h_s_rca16_fa13_y4 = 0;
  uint8_t h_s_rca16_fa14_y2 = 0;
  uint8_t h_s_rca16_fa14_y4 = 0;
  uint8_t h_s_rca16_fa15_y2 = 0;
  uint8_t h_s_rca16_fa15_y4 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  a_4 = ((a >> 4) & 0x01);
  a_5 = ((a >> 5) & 0x01);
  a_6 = ((a >> 6) & 0x01);
  a_7 = ((a >> 7) & 0x01);
  a_8 = ((a >> 8) & 0x01);
  a_9 = ((a >> 9) & 0x01);
  a_10 = ((a >> 10) & 0x01);
  a_11 = ((a >> 11) & 0x01);
  a_12 = ((a >> 12) & 0x01);
  a_13 = ((a >> 13) & 0x01);
  a_14 = ((a >> 14) & 0x01);
  a_15 = ((a >> 15) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  b_4 = ((b >> 4) & 0x01);
  b_5 = ((b >> 5) & 0x01);
  b_6 = ((b >> 6) & 0x01);
  b_7 = ((b >> 7) & 0x01);
  b_8 = ((b >> 8) & 0x01);
  b_9 = ((b >> 9) & 0x01);
  b_10 = ((b >> 10) & 0x01);
  b_11 = ((b >> 11) & 0x01);
  b_12 = ((b >> 12) & 0x01);
  b_13 = ((b >> 13) & 0x01);
  b_14 = ((b >> 14) & 0x01);
  b_15 = ((b >> 15) & 0x01);
  h_s_rca16_ha_y0 = (ha(a_0, b_0) >> 0) & 0x01;
  h_s_rca16_ha_y1 = (ha(a_0, b_0) >> 1) & 0x01;
  h_s_rca16_fa1_y2 = (fa(a_1, b_1, h_s_rca16_ha_y1) >> 0) & 0x01;
  h_s_rca16_fa1_y4 = (fa(a_1, b_1, h_s_rca16_ha_y1) >> 1) & 0x01;
  h_s_rca16_fa2_y2 = (fa(a_2, b_2, h_s_rca16_fa1_y4) >> 0) & 0x01;
  h_s_rca16_fa2_y4 = (fa(a_2, b_2, h_s_rca16_fa1_y4) >> 1) & 0x01;
  h_s_rca16_fa3_y2 = (fa(a_3, b_3, h_s_rca16_fa2_y4) >> 0) & 0x01;
  h_s_rca16_fa3_y4 = (fa(a_3, b_3, h_s_rca16_fa2_y4) >> 1) & 0x01;
  h_s_rca16_fa4_y2 = (fa(a_4, b_4, h_s_rca16_fa3_y4) >> 0) & 0x01;
  h_s_rca16_fa4_y4 = (fa(a_4, b_4, h_s_rca16_fa3_y4) >> 1) & 0x01;
  h_s_rca16_fa5_y2 = (fa(a_5, b_5, h_s_rca16_fa4_y4) >> 0) & 0x01;
  h_s_rca16_fa5_y4 = (fa(a_5, b_5, h_s_rca16_fa4_y4) >> 1) & 0x01;
  h_s_rca16_fa6_y2 = (fa(a_6, b_6, h_s_rca16_fa5_y4) >> 0) & 0x01;
  h_s_rca16_fa6_y4 = (fa(a_6, b_6, h_s_rca16_fa5_y4) >> 1) & 0x01;
  h_s_rca16_fa7_y2 = (fa(a_7, b_7, h_s_rca16_fa6_y4) >> 0) & 0x01;
  h_s_rca16_fa7_y4 = (fa(a_7, b_7, h_s_rca16_fa6_y4) >> 1) & 0x01;
  h_s_rca16_fa8_y2 = (fa(a_8, b_8, h_s_rca16_fa7_y4) >> 0) & 0x01;
  h_s_rca16_fa8_y4 = (fa(a_8, b_8, h_s_rca16_fa7_y4) >> 1) & 0x01;
  h_s_rca16_fa9_y2 = (fa(a_9, b_9, h_s_rca16_fa8_y4) >> 0) & 0x01;
  h_s_rca16_fa9_y4 = (fa(a_9, b_9, h_s_rca16_fa8_y4) >> 1) & 0x01;
  h_s_rca16_fa10_y2 = (fa(a_10, b_10, h_s_rca16_fa9_y4) >> 0) & 0x01;
  h_s_rca16_fa10_y4 = (fa(a_10, b_10, h_s_rca16_fa9_y4) >> 1) & 0x01;
  h_s_rca16_fa11_y2 = (fa(a_11, b_11, h_s_rca16_fa10_y4) >> 0) & 0x01;
  h_s_rca16_fa11_y4 = (fa(a_11, b_11, h_s_rca16_fa10_y4) >> 1) & 0x01;
  h_s_rca16_fa12_y2 = (fa(a_12, b_12, h_s_rca16_fa11_y4) >> 0) & 0x01;
  h_s_rca16_fa12_y4 = (fa(a_12, b_12, h_s_rca16_fa11_y4) >> 1) & 0x01;
  h_s_rca16_fa13_y2 = (fa(a_13, b_13, h_s_rca16_fa12_y4) >> 0) & 0x01;
  h_s_rca16_fa13_y4 = (fa(a_13, b_13, h_s_rca16_fa12_y4) >> 1) & 0x01;
  h_s_rca16_fa14_y2 = (fa(a_14, b_14, h_s_rca16_fa13_y4) >> 0) & 0x01;
  h_s_rca16_fa14_y4 = (fa(a_14, b_14, h_s_rca16_fa13_y4) >> 1) & 0x01;
  h_s_rca16_fa15_y2 = (fa(a_15, b_15, h_s_rca16_fa14_y4) >> 0) & 0x01;
  h_s_rca16_fa15_y4 = (fa(a_15, b_15, h_s_rca16_fa14_y4) >> 1) & 0x01;

  out |= (h_s_rca16_ha_y0 & 0x01) << 0;
  out |= (h_s_rca16_fa1_y2 & 0x01) << 1;
  out |= (h_s_rca16_fa2_y2 & 0x01) << 2;
  out |= (h_s_rca16_fa3_y2 & 0x01) << 3;
  out |= (h_s_rca16_fa4_y2 & 0x01) << 4;
  out |= (h_s_rca16_fa5_y2 & 0x01) << 5;
  out |= (h_s_rca16_fa6_y2 & 0x01) << 6;
  out |= (h_s_rca16_fa7_y2 & 0x01) << 7;
  out |= (h_s_rca16_fa8_y2 & 0x01) << 8;
  out |= (h_s_rca16_fa9_y2 & 0x01) << 9;
  out |= (h_s_rca16_fa10_y2 & 0x01) << 10;
  out |= (h_s_rca16_fa11_y2 & 0x01) << 11;
  out |= (h_s_rca16_fa12_y2 & 0x01) << 12;
  out |= (h_s_rca16_fa13_y2 & 0x01) << 13;
  out |= (h_s_rca16_fa14_y2 & 0x01) << 14;
  out |= (h_s_rca16_fa15_y2 & 0x01) << 15;
  out |= (h_s_rca16_fa15_y4 & 0x01) << 16;
  return out;
}