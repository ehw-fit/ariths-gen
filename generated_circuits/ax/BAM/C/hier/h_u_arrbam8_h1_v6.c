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

uint64_t h_u_arrbam8_h1_v6(uint64_t a, uint64_t b){
  uint64_t h_u_arrbam8_h1_v6_out = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_1 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_1 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_1 = 0;
  uint8_t h_u_arrbam8_h1_v6_and4_2 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha4_2_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha4_2_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_2 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_2_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_2_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_2 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_2_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_2_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_2 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha7_2_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha7_2_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and3_3 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha3_3_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha3_3_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and4_3 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_3_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_3_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_3 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_3_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_3_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_3 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_3_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_3_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_3 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_3_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_3_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and2_4 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha2_4_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha2_4_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and3_4 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_4_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_4_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and4_4 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_4_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_4_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_4 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_4_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_4_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_4 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_4_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_4_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_4 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_4_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_4_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and1_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha1_5_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha1_5_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and2_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa2_5_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa2_5_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and3_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_5_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_5_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and4_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_5_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_5_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_5_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_5_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_5_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_5_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_5 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_5_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_5_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and0_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha0_6_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha0_6_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and1_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa1_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa1_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and2_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa2_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa2_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and3_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and4_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_6 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_6_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_6_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and0_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha0_7_xor0 = 0;
  uint8_t h_u_arrbam8_h1_v6_ha0_7_and0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and1_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa1_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa1_7_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and2_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa2_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa2_7_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and3_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa3_7_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and4_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa4_7_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and5_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa5_7_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and6_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa6_7_or0 = 0;
  uint8_t h_u_arrbam8_h1_v6_and7_7 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_7_xor1 = 0;
  uint8_t h_u_arrbam8_h1_v6_fa7_7_or0 = 0;

  h_u_arrbam8_h1_v6_and5_1 = and_gate(((a >> 5) & 0x01), ((b >> 1) & 0x01));
  h_u_arrbam8_h1_v6_and6_1 = and_gate(((a >> 6) & 0x01), ((b >> 1) & 0x01));
  h_u_arrbam8_h1_v6_and7_1 = and_gate(((a >> 7) & 0x01), ((b >> 1) & 0x01));
  h_u_arrbam8_h1_v6_and4_2 = and_gate(((a >> 4) & 0x01), ((b >> 2) & 0x01));
  h_u_arrbam8_h1_v6_ha4_2_xor0 = (ha(((h_u_arrbam8_h1_v6_and4_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_and5_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha4_2_and0 = (ha(((h_u_arrbam8_h1_v6_and4_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_and5_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and5_2 = and_gate(((a >> 5) & 0x01), ((b >> 2) & 0x01));
  h_u_arrbam8_h1_v6_fa5_2_xor1 = (fa(((h_u_arrbam8_h1_v6_and5_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_and6_1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha4_2_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa5_2_or0 = (fa(((h_u_arrbam8_h1_v6_and5_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_and6_1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha4_2_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and6_2 = and_gate(((a >> 6) & 0x01), ((b >> 2) & 0x01));
  h_u_arrbam8_h1_v6_fa6_2_xor1 = (fa(((h_u_arrbam8_h1_v6_and6_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_and7_1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa6_2_or0 = (fa(((h_u_arrbam8_h1_v6_and6_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_and7_1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and7_2 = and_gate(((a >> 7) & 0x01), ((b >> 2) & 0x01));
  h_u_arrbam8_h1_v6_ha7_2_xor0 = (ha(((h_u_arrbam8_h1_v6_and7_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha7_2_and0 = (ha(((h_u_arrbam8_h1_v6_and7_2 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  h_u_arrbam8_h1_v6_ha3_3_xor0 = (ha(((h_u_arrbam8_h1_v6_and3_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha4_2_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha3_3_and0 = (ha(((h_u_arrbam8_h1_v6_and3_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha4_2_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and4_3 = and_gate(((a >> 4) & 0x01), ((b >> 3) & 0x01));
  h_u_arrbam8_h1_v6_fa4_3_xor1 = (fa(((h_u_arrbam8_h1_v6_and4_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_2_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha3_3_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa4_3_or0 = (fa(((h_u_arrbam8_h1_v6_and4_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_2_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha3_3_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and5_3 = and_gate(((a >> 5) & 0x01), ((b >> 3) & 0x01));
  h_u_arrbam8_h1_v6_fa5_3_xor1 = (fa(((h_u_arrbam8_h1_v6_and5_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_2_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa5_3_or0 = (fa(((h_u_arrbam8_h1_v6_and5_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_2_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and6_3 = and_gate(((a >> 6) & 0x01), ((b >> 3) & 0x01));
  h_u_arrbam8_h1_v6_fa6_3_xor1 = (fa(((h_u_arrbam8_h1_v6_and6_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha7_2_xor0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa6_3_or0 = (fa(((h_u_arrbam8_h1_v6_and6_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha7_2_xor0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and7_3 = and_gate(((a >> 7) & 0x01), ((b >> 3) & 0x01));
  h_u_arrbam8_h1_v6_fa7_3_xor1 = (fa(((h_u_arrbam8_h1_v6_and7_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha7_2_and0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa7_3_or0 = (fa(((h_u_arrbam8_h1_v6_and7_3 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha7_2_and0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_3_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and2_4 = and_gate(((a >> 2) & 0x01), ((b >> 4) & 0x01));
  h_u_arrbam8_h1_v6_ha2_4_xor0 = (ha(((h_u_arrbam8_h1_v6_and2_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha3_3_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha2_4_and0 = (ha(((h_u_arrbam8_h1_v6_and2_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha3_3_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and3_4 = and_gate(((a >> 3) & 0x01), ((b >> 4) & 0x01));
  h_u_arrbam8_h1_v6_fa3_4_xor1 = (fa(((h_u_arrbam8_h1_v6_and3_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha2_4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa3_4_or0 = (fa(((h_u_arrbam8_h1_v6_and3_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha2_4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and4_4 = and_gate(((a >> 4) & 0x01), ((b >> 4) & 0x01));
  h_u_arrbam8_h1_v6_fa4_4_xor1 = (fa(((h_u_arrbam8_h1_v6_and4_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa4_4_or0 = (fa(((h_u_arrbam8_h1_v6_and4_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and5_4 = and_gate(((a >> 5) & 0x01), ((b >> 4) & 0x01));
  h_u_arrbam8_h1_v6_fa5_4_xor1 = (fa(((h_u_arrbam8_h1_v6_and5_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa5_4_or0 = (fa(((h_u_arrbam8_h1_v6_and5_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and6_4 = and_gate(((a >> 6) & 0x01), ((b >> 4) & 0x01));
  h_u_arrbam8_h1_v6_fa6_4_xor1 = (fa(((h_u_arrbam8_h1_v6_and6_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa6_4_or0 = (fa(((h_u_arrbam8_h1_v6_and6_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_3_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and7_4 = and_gate(((a >> 7) & 0x01), ((b >> 4) & 0x01));
  h_u_arrbam8_h1_v6_fa7_4_xor1 = (fa(((h_u_arrbam8_h1_v6_and7_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_3_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_4_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa7_4_or0 = (fa(((h_u_arrbam8_h1_v6_and7_4 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_3_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_4_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and1_5 = and_gate(((a >> 1) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_ha1_5_xor0 = (ha(((h_u_arrbam8_h1_v6_and1_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha2_4_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha1_5_and0 = (ha(((h_u_arrbam8_h1_v6_and1_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha2_4_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and2_5 = and_gate(((a >> 2) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_fa2_5_xor1 = (fa(((h_u_arrbam8_h1_v6_and2_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha1_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa2_5_or0 = (fa(((h_u_arrbam8_h1_v6_and2_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha1_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and3_5 = and_gate(((a >> 3) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_fa3_5_xor1 = (fa(((h_u_arrbam8_h1_v6_and3_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa3_5_or0 = (fa(((h_u_arrbam8_h1_v6_and3_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_fa4_5_xor1 = (fa(((h_u_arrbam8_h1_v6_and4_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa4_5_or0 = (fa(((h_u_arrbam8_h1_v6_and4_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_fa5_5_xor1 = (fa(((h_u_arrbam8_h1_v6_and5_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa5_5_or0 = (fa(((h_u_arrbam8_h1_v6_and5_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_fa6_5_xor1 = (fa(((h_u_arrbam8_h1_v6_and6_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa6_5_or0 = (fa(((h_u_arrbam8_h1_v6_and6_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_4_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_arrbam8_h1_v6_fa7_5_xor1 = (fa(((h_u_arrbam8_h1_v6_and7_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_4_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa7_5_or0 = (fa(((h_u_arrbam8_h1_v6_and7_5 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_4_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and0_6 = and_gate(((a >> 0) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_ha0_6_xor0 = (ha(((h_u_arrbam8_h1_v6_and0_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha1_5_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha0_6_and0 = (ha(((h_u_arrbam8_h1_v6_and0_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha1_5_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and1_6 = and_gate(((a >> 1) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa1_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and1_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha0_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa1_6_or0 = (fa(((h_u_arrbam8_h1_v6_and1_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha0_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and2_6 = and_gate(((a >> 2) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa2_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and2_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa1_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa2_6_or0 = (fa(((h_u_arrbam8_h1_v6_and2_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa1_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa3_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and3_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa3_6_or0 = (fa(((h_u_arrbam8_h1_v6_and3_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa4_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and4_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa4_6_or0 = (fa(((h_u_arrbam8_h1_v6_and4_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa5_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and5_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa5_6_or0 = (fa(((h_u_arrbam8_h1_v6_and5_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa6_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and6_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa6_6_or0 = (fa(((h_u_arrbam8_h1_v6_and6_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_5_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_arrbam8_h1_v6_fa7_6_xor1 = (fa(((h_u_arrbam8_h1_v6_and7_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_5_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa7_6_or0 = (fa(((h_u_arrbam8_h1_v6_and7_6 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_5_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and0_7 = and_gate(((a >> 0) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_ha0_7_xor0 = (ha(((h_u_arrbam8_h1_v6_and0_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa1_6_xor1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_ha0_7_and0 = (ha(((h_u_arrbam8_h1_v6_and0_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa1_6_xor1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and1_7 = and_gate(((a >> 1) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa1_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and1_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha0_7_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa1_7_or0 = (fa(((h_u_arrbam8_h1_v6_and1_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_ha0_7_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa2_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and2_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa1_7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa2_7_or0 = (fa(((h_u_arrbam8_h1_v6_and2_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa1_7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa3_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and3_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa3_7_or0 = (fa(((h_u_arrbam8_h1_v6_and3_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa2_7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa4_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and4_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa4_7_or0 = (fa(((h_u_arrbam8_h1_v6_and4_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa3_7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa5_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and5_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa5_7_or0 = (fa(((h_u_arrbam8_h1_v6_and5_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa4_7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa6_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and6_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa6_7_or0 = (fa(((h_u_arrbam8_h1_v6_and6_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_6_xor1 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa5_7_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_arrbam8_h1_v6_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_arrbam8_h1_v6_fa7_7_xor1 = (fa(((h_u_arrbam8_h1_v6_and7_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_6_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_arrbam8_h1_v6_fa7_7_or0 = (fa(((h_u_arrbam8_h1_v6_and7_7 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa7_6_or0 >> 0) & 0x01), ((h_u_arrbam8_h1_v6_fa6_7_or0 >> 0) & 0x01)) >> 1) & 0x01;

  h_u_arrbam8_h1_v6_out |= (0x00) << 0;
  h_u_arrbam8_h1_v6_out |= (0x00) << 1;
  h_u_arrbam8_h1_v6_out |= (0x00) << 2;
  h_u_arrbam8_h1_v6_out |= (0x00) << 3;
  h_u_arrbam8_h1_v6_out |= (0x00) << 4;
  h_u_arrbam8_h1_v6_out |= (0x00) << 5;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_ha0_6_xor0 >> 0) & 0x01ull) << 6;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_ha0_7_xor0 >> 0) & 0x01ull) << 7;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa1_7_xor1 >> 0) & 0x01ull) << 8;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa2_7_xor1 >> 0) & 0x01ull) << 9;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa3_7_xor1 >> 0) & 0x01ull) << 10;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa4_7_xor1 >> 0) & 0x01ull) << 11;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa5_7_xor1 >> 0) & 0x01ull) << 12;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa6_7_xor1 >> 0) & 0x01ull) << 13;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa7_7_xor1 >> 0) & 0x01ull) << 14;
  h_u_arrbam8_h1_v6_out |= ((h_u_arrbam8_h1_v6_fa7_7_or0 >> 0) & 0x01ull) << 15;
  return h_u_arrbam8_h1_v6_out;
}