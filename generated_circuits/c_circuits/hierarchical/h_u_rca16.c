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

  ha_out |= ((ha_xor0 >> 0) & 0x01) << 0;
  ha_out |= ((ha_and0 >> 0) & 0x01) << 1;
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

  fa_out |= ((fa_xor1 >> 0) & 0x01) << 0;
  fa_out |= ((fa_or0 >> 0) & 0x01) << 1;
  return fa_out;
}

uint64_t h_u_rca16(uint64_t a, uint64_t b){
  uint64_t h_u_rca16_out = 0;
  uint8_t h_u_rca16_ha_xor0 = 0;
  uint8_t h_u_rca16_ha_and0 = 0;
  uint8_t h_u_rca16_fa1_xor1 = 0;
  uint8_t h_u_rca16_fa1_or0 = 0;
  uint8_t h_u_rca16_fa2_xor1 = 0;
  uint8_t h_u_rca16_fa2_or0 = 0;
  uint8_t h_u_rca16_fa3_xor1 = 0;
  uint8_t h_u_rca16_fa3_or0 = 0;
  uint8_t h_u_rca16_fa4_xor1 = 0;
  uint8_t h_u_rca16_fa4_or0 = 0;
  uint8_t h_u_rca16_fa5_xor1 = 0;
  uint8_t h_u_rca16_fa5_or0 = 0;
  uint8_t h_u_rca16_fa6_xor1 = 0;
  uint8_t h_u_rca16_fa6_or0 = 0;
  uint8_t h_u_rca16_fa7_xor1 = 0;
  uint8_t h_u_rca16_fa7_or0 = 0;
  uint8_t h_u_rca16_fa8_xor1 = 0;
  uint8_t h_u_rca16_fa8_or0 = 0;
  uint8_t h_u_rca16_fa9_xor1 = 0;
  uint8_t h_u_rca16_fa9_or0 = 0;
  uint8_t h_u_rca16_fa10_xor1 = 0;
  uint8_t h_u_rca16_fa10_or0 = 0;
  uint8_t h_u_rca16_fa11_xor1 = 0;
  uint8_t h_u_rca16_fa11_or0 = 0;
  uint8_t h_u_rca16_fa12_xor1 = 0;
  uint8_t h_u_rca16_fa12_or0 = 0;
  uint8_t h_u_rca16_fa13_xor1 = 0;
  uint8_t h_u_rca16_fa13_or0 = 0;
  uint8_t h_u_rca16_fa14_xor1 = 0;
  uint8_t h_u_rca16_fa14_or0 = 0;
  uint8_t h_u_rca16_fa15_xor1 = 0;
  uint8_t h_u_rca16_fa15_or0 = 0;

  h_u_rca16_ha_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_ha_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_rca16_ha_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_rca16_ha_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_rca16_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_rca16_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_rca16_fa2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_rca16_fa2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_rca16_fa3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_rca16_fa3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_rca16_fa4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_rca16_fa4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa6_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_rca16_fa5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa6_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_rca16_fa5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa7_xor1 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_rca16_fa6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa7_or0 = (fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_rca16_fa6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa8_xor1 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((h_u_rca16_fa7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa8_or0 = (fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((h_u_rca16_fa7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa9_xor1 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((h_u_rca16_fa8_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa9_or0 = (fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((h_u_rca16_fa8_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa10_xor1 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((h_u_rca16_fa9_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa10_or0 = (fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((h_u_rca16_fa9_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa11_xor1 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((h_u_rca16_fa10_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa11_or0 = (fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((h_u_rca16_fa10_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa12_xor1 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((h_u_rca16_fa11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa12_or0 = (fa(((a >> 12) & 0x01), ((b >> 12) & 0x01), ((h_u_rca16_fa11_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa13_xor1 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((h_u_rca16_fa12_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa13_or0 = (fa(((a >> 13) & 0x01), ((b >> 13) & 0x01), ((h_u_rca16_fa12_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa14_xor1 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((h_u_rca16_fa13_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa14_or0 = (fa(((a >> 14) & 0x01), ((b >> 14) & 0x01), ((h_u_rca16_fa13_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_rca16_fa15_xor1 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((h_u_rca16_fa14_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_rca16_fa15_or0 = (fa(((a >> 15) & 0x01), ((b >> 15) & 0x01), ((h_u_rca16_fa14_or0 >> 0) & 0x01)) >> 1) & 0x01;

  h_u_rca16_out |= ((h_u_rca16_ha_xor0 >> 0) & 0x01) << 0;
  h_u_rca16_out |= ((h_u_rca16_fa1_xor1 >> 0) & 0x01) << 1;
  h_u_rca16_out |= ((h_u_rca16_fa2_xor1 >> 0) & 0x01) << 2;
  h_u_rca16_out |= ((h_u_rca16_fa3_xor1 >> 0) & 0x01) << 3;
  h_u_rca16_out |= ((h_u_rca16_fa4_xor1 >> 0) & 0x01) << 4;
  h_u_rca16_out |= ((h_u_rca16_fa5_xor1 >> 0) & 0x01) << 5;
  h_u_rca16_out |= ((h_u_rca16_fa6_xor1 >> 0) & 0x01) << 6;
  h_u_rca16_out |= ((h_u_rca16_fa7_xor1 >> 0) & 0x01) << 7;
  h_u_rca16_out |= ((h_u_rca16_fa8_xor1 >> 0) & 0x01) << 8;
  h_u_rca16_out |= ((h_u_rca16_fa9_xor1 >> 0) & 0x01) << 9;
  h_u_rca16_out |= ((h_u_rca16_fa10_xor1 >> 0) & 0x01) << 10;
  h_u_rca16_out |= ((h_u_rca16_fa11_xor1 >> 0) & 0x01) << 11;
  h_u_rca16_out |= ((h_u_rca16_fa12_xor1 >> 0) & 0x01) << 12;
  h_u_rca16_out |= ((h_u_rca16_fa13_xor1 >> 0) & 0x01) << 13;
  h_u_rca16_out |= ((h_u_rca16_fa14_xor1 >> 0) & 0x01) << 14;
  h_u_rca16_out |= ((h_u_rca16_fa15_xor1 >> 0) & 0x01) << 15;
  h_u_rca16_out |= ((h_u_rca16_fa15_or0 >> 0) & 0x01) << 16;
  return h_u_rca16_out;
}