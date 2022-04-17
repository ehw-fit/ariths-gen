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

int64_t s_rca32(int64_t a, int64_t b){
  int64_t s_rca32_out = 0;
  uint8_t s_rca32_ha_xor0 = 0;
  uint8_t s_rca32_ha_and0 = 0;
  uint8_t s_rca32_fa1_xor1 = 0;
  uint8_t s_rca32_fa1_or0 = 0;
  uint8_t s_rca32_fa2_xor1 = 0;
  uint8_t s_rca32_fa2_or0 = 0;
  uint8_t s_rca32_fa3_xor1 = 0;
  uint8_t s_rca32_fa3_or0 = 0;
  uint8_t s_rca32_fa4_xor1 = 0;
  uint8_t s_rca32_fa4_or0 = 0;
  uint8_t s_rca32_fa5_xor1 = 0;
  uint8_t s_rca32_fa5_or0 = 0;
  uint8_t s_rca32_fa6_xor1 = 0;
  uint8_t s_rca32_fa6_or0 = 0;
  uint8_t s_rca32_fa7_xor1 = 0;
  uint8_t s_rca32_fa7_or0 = 0;
  uint8_t s_rca32_fa8_xor1 = 0;
  uint8_t s_rca32_fa8_or0 = 0;
  uint8_t s_rca32_fa9_xor1 = 0;
  uint8_t s_rca32_fa9_or0 = 0;
  uint8_t s_rca32_fa10_xor1 = 0;
  uint8_t s_rca32_fa10_or0 = 0;
  uint8_t s_rca32_fa11_xor1 = 0;
  uint8_t s_rca32_fa11_or0 = 0;
  uint8_t s_rca32_fa12_xor1 = 0;
  uint8_t s_rca32_fa12_or0 = 0;
  uint8_t s_rca32_fa13_xor1 = 0;
  uint8_t s_rca32_fa13_or0 = 0;
  uint8_t s_rca32_fa14_xor1 = 0;
  uint8_t s_rca32_fa14_or0 = 0;
  uint8_t s_rca32_fa15_xor1 = 0;
  uint8_t s_rca32_fa15_or0 = 0;
  uint8_t s_rca32_fa16_xor1 = 0;
  uint8_t s_rca32_fa16_or0 = 0;
  uint8_t s_rca32_fa17_xor1 = 0;
  uint8_t s_rca32_fa17_or0 = 0;
  uint8_t s_rca32_fa18_xor1 = 0;
  uint8_t s_rca32_fa18_or0 = 0;
  uint8_t s_rca32_fa19_xor1 = 0;
  uint8_t s_rca32_fa19_or0 = 0;
  uint8_t s_rca32_fa20_xor1 = 0;
  uint8_t s_rca32_fa20_or0 = 0;
  uint8_t s_rca32_fa21_xor1 = 0;
  uint8_t s_rca32_fa21_or0 = 0;
  uint8_t s_rca32_fa22_xor1 = 0;
  uint8_t s_rca32_fa22_or0 = 0;
  uint8_t s_rca32_fa23_xor1 = 0;
  uint8_t s_rca32_fa23_or0 = 0;
  uint8_t s_rca32_fa24_xor1 = 0;
  uint8_t s_rca32_fa24_or0 = 0;
  uint8_t s_rca32_fa25_xor1 = 0;
  uint8_t s_rca32_fa25_or0 = 0;
  uint8_t s_rca32_fa26_xor1 = 0;
  uint8_t s_rca32_fa26_or0 = 0;
  uint8_t s_rca32_fa27_xor1 = 0;
  uint8_t s_rca32_fa27_or0 = 0;
  uint8_t s_rca32_fa28_xor1 = 0;
  uint8_t s_rca32_fa28_or0 = 0;
  uint8_t s_rca32_fa29_xor1 = 0;
  uint8_t s_rca32_fa29_or0 = 0;
  uint8_t s_rca32_fa30_xor1 = 0;
  uint8_t s_rca32_fa30_or0 = 0;
  uint8_t s_rca32_fa31_xor1 = 0;
  uint8_t s_rca32_fa31_or0 = 0;
  uint8_t s_rca32_xor0 = 0;
  uint8_t s_rca32_xor1 = 0;

  s_rca32_ha_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_ha_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_rca32_ha_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_rca32_ha_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_rca32_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_rca32_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_rca32_fa2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_rca32_fa2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((s_rca32_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((s_rca32_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((s_rca32_fa4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((s_rca32_fa4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa6_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((s_rca32_fa5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa6_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((s_rca32_fa5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa7_xor1 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((s_rca32_fa6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa7_or0 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((s_rca32_fa6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa8_xor1 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((s_rca32_fa7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa8_or0 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((s_rca32_fa7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa9_xor1 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((s_rca32_fa8_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa9_or0 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((s_rca32_fa8_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa10_xor1 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((s_rca32_fa9_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa10_or0 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((s_rca32_fa9_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa11_xor1 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((s_rca32_fa10_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa11_or0 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((s_rca32_fa10_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa12_xor1 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((s_rca32_fa11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa12_or0 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((s_rca32_fa11_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa13_xor1 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((s_rca32_fa12_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa13_or0 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((s_rca32_fa12_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa14_xor1 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((s_rca32_fa13_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa14_or0 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((s_rca32_fa13_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa15_xor1 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((s_rca32_fa14_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa15_or0 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((s_rca32_fa14_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa16_xor1 = (fa(((a >> 16) & 0x01), ((b >> 16) & 0x01), ((s_rca32_fa15_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa16_or0 = (fa(((a >> 16) & 0x01), ((b >> 16) & 0x01), ((s_rca32_fa15_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa17_xor1 = (fa(((a >> 17) & 0x01), ((b >> 17) & 0x01), ((s_rca32_fa16_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa17_or0 = (fa(((a >> 17) & 0x01), ((b >> 17) & 0x01), ((s_rca32_fa16_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa18_xor1 = (fa(((a >> 18) & 0x01), ((b >> 18) & 0x01), ((s_rca32_fa17_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa18_or0 = (fa(((a >> 18) & 0x01), ((b >> 18) & 0x01), ((s_rca32_fa17_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa19_xor1 = (fa(((a >> 19) & 0x01), ((b >> 19) & 0x01), ((s_rca32_fa18_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa19_or0 = (fa(((a >> 19) & 0x01), ((b >> 19) & 0x01), ((s_rca32_fa18_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa20_xor1 = (fa(((a >> 20) & 0x01), ((b >> 20) & 0x01), ((s_rca32_fa19_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa20_or0 = (fa(((a >> 20) & 0x01), ((b >> 20) & 0x01), ((s_rca32_fa19_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa21_xor1 = (fa(((a >> 21) & 0x01), ((b >> 21) & 0x01), ((s_rca32_fa20_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa21_or0 = (fa(((a >> 21) & 0x01), ((b >> 21) & 0x01), ((s_rca32_fa20_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa22_xor1 = (fa(((a >> 22) & 0x01), ((b >> 22) & 0x01), ((s_rca32_fa21_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa22_or0 = (fa(((a >> 22) & 0x01), ((b >> 22) & 0x01), ((s_rca32_fa21_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa23_xor1 = (fa(((a >> 23) & 0x01), ((b >> 23) & 0x01), ((s_rca32_fa22_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa23_or0 = (fa(((a >> 23) & 0x01), ((b >> 23) & 0x01), ((s_rca32_fa22_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa24_xor1 = (fa(((a >> 24) & 0x01), ((b >> 24) & 0x01), ((s_rca32_fa23_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa24_or0 = (fa(((a >> 24) & 0x01), ((b >> 24) & 0x01), ((s_rca32_fa23_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa25_xor1 = (fa(((a >> 25) & 0x01), ((b >> 25) & 0x01), ((s_rca32_fa24_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa25_or0 = (fa(((a >> 25) & 0x01), ((b >> 25) & 0x01), ((s_rca32_fa24_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa26_xor1 = (fa(((a >> 26) & 0x01), ((b >> 26) & 0x01), ((s_rca32_fa25_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa26_or0 = (fa(((a >> 26) & 0x01), ((b >> 26) & 0x01), ((s_rca32_fa25_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa27_xor1 = (fa(((a >> 27) & 0x01), ((b >> 27) & 0x01), ((s_rca32_fa26_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa27_or0 = (fa(((a >> 27) & 0x01), ((b >> 27) & 0x01), ((s_rca32_fa26_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa28_xor1 = (fa(((a >> 28) & 0x01), ((b >> 28) & 0x01), ((s_rca32_fa27_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa28_or0 = (fa(((a >> 28) & 0x01), ((b >> 28) & 0x01), ((s_rca32_fa27_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa29_xor1 = (fa(((a >> 29) & 0x01), ((b >> 29) & 0x01), ((s_rca32_fa28_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa29_or0 = (fa(((a >> 29) & 0x01), ((b >> 29) & 0x01), ((s_rca32_fa28_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa30_xor1 = (fa(((a >> 30) & 0x01), ((b >> 30) & 0x01), ((s_rca32_fa29_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa30_or0 = (fa(((a >> 30) & 0x01), ((b >> 30) & 0x01), ((s_rca32_fa29_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_fa31_xor1 = (fa(((a >> 31) & 0x01), ((b >> 31) & 0x01), ((s_rca32_fa30_or0 >> 0) & 0x01)) >> 0) & 0x01;
  s_rca32_fa31_or0 = (fa(((a >> 31) & 0x01), ((b >> 31) & 0x01), ((s_rca32_fa30_or0 >> 0) & 0x01)) >> 1) & 0x01;
  s_rca32_xor0 = xor_gate(((a >> 31) & 0x01), ((b >> 31) & 0x01));
  s_rca32_xor1 = xor_gate(((s_rca32_xor0 >> 0) & 0x01), ((s_rca32_fa31_or0 >> 0) & 0x01));

  s_rca32_out |= ((s_rca32_ha_xor0 >> 0) & 0x01ull) << 0;
  s_rca32_out |= ((s_rca32_fa1_xor1 >> 0) & 0x01ull) << 1;
  s_rca32_out |= ((s_rca32_fa2_xor1 >> 0) & 0x01ull) << 2;
  s_rca32_out |= ((s_rca32_fa3_xor1 >> 0) & 0x01ull) << 3;
  s_rca32_out |= ((s_rca32_fa4_xor1 >> 0) & 0x01ull) << 4;
  s_rca32_out |= ((s_rca32_fa5_xor1 >> 0) & 0x01ull) << 5;
  s_rca32_out |= ((s_rca32_fa6_xor1 >> 0) & 0x01ull) << 6;
  s_rca32_out |= ((s_rca32_fa7_xor1 >> 0) & 0x01ull) << 7;
  s_rca32_out |= ((s_rca32_fa8_xor1 >> 0) & 0x01ull) << 8;
  s_rca32_out |= ((s_rca32_fa9_xor1 >> 0) & 0x01ull) << 9;
  s_rca32_out |= ((s_rca32_fa10_xor1 >> 0) & 0x01ull) << 10;
  s_rca32_out |= ((s_rca32_fa11_xor1 >> 0) & 0x01ull) << 11;
  s_rca32_out |= ((s_rca32_fa12_xor1 >> 0) & 0x01ull) << 12;
  s_rca32_out |= ((s_rca32_fa13_xor1 >> 0) & 0x01ull) << 13;
  s_rca32_out |= ((s_rca32_fa14_xor1 >> 0) & 0x01ull) << 14;
  s_rca32_out |= ((s_rca32_fa15_xor1 >> 0) & 0x01ull) << 15;
  s_rca32_out |= ((s_rca32_fa16_xor1 >> 0) & 0x01ull) << 16;
  s_rca32_out |= ((s_rca32_fa17_xor1 >> 0) & 0x01ull) << 17;
  s_rca32_out |= ((s_rca32_fa18_xor1 >> 0) & 0x01ull) << 18;
  s_rca32_out |= ((s_rca32_fa19_xor1 >> 0) & 0x01ull) << 19;
  s_rca32_out |= ((s_rca32_fa20_xor1 >> 0) & 0x01ull) << 20;
  s_rca32_out |= ((s_rca32_fa21_xor1 >> 0) & 0x01ull) << 21;
  s_rca32_out |= ((s_rca32_fa22_xor1 >> 0) & 0x01ull) << 22;
  s_rca32_out |= ((s_rca32_fa23_xor1 >> 0) & 0x01ull) << 23;
  s_rca32_out |= ((s_rca32_fa24_xor1 >> 0) & 0x01ull) << 24;
  s_rca32_out |= ((s_rca32_fa25_xor1 >> 0) & 0x01ull) << 25;
  s_rca32_out |= ((s_rca32_fa26_xor1 >> 0) & 0x01ull) << 26;
  s_rca32_out |= ((s_rca32_fa27_xor1 >> 0) & 0x01ull) << 27;
  s_rca32_out |= ((s_rca32_fa28_xor1 >> 0) & 0x01ull) << 28;
  s_rca32_out |= ((s_rca32_fa29_xor1 >> 0) & 0x01ull) << 29;
  s_rca32_out |= ((s_rca32_fa30_xor1 >> 0) & 0x01ull) << 30;
  s_rca32_out |= ((s_rca32_fa31_xor1 >> 0) & 0x01ull) << 31;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 32;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 33;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 34;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 35;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 36;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 37;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 38;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 39;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 40;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 41;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 42;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 43;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 44;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 45;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 46;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 47;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 48;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 49;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 50;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 51;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 52;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 53;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 54;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 55;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 56;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 57;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 58;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 59;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 60;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 61;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 62;
  s_rca32_out |= ((s_rca32_xor1 >> 0) & 0x01ull) << 63;
  return s_rca32_out;
}