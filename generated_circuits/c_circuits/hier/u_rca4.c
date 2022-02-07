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

uint64_t u_rca4(uint64_t a, uint64_t b){
  uint8_t u_rca4_out = 0;
  uint8_t u_rca4_ha_xor0 = 0;
  uint8_t u_rca4_ha_and0 = 0;
  uint8_t u_rca4_fa1_xor1 = 0;
  uint8_t u_rca4_fa1_or0 = 0;
  uint8_t u_rca4_fa2_xor1 = 0;
  uint8_t u_rca4_fa2_or0 = 0;
  uint8_t u_rca4_fa3_xor1 = 0;
  uint8_t u_rca4_fa3_or0 = 0;

  u_rca4_ha_xor0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_rca4_ha_and0 = (ha(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_rca4_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_rca4_ha_and0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca4_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((u_rca4_ha_and0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca4_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_rca4_fa1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca4_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((u_rca4_fa1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  u_rca4_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_rca4_fa2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  u_rca4_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((u_rca4_fa2_or0 >> 0) & 0x01)) >> 1) & 0x01;

  u_rca4_out |= ((u_rca4_ha_xor0 >> 0) & 0x01ull) << 0;
  u_rca4_out |= ((u_rca4_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_rca4_out |= ((u_rca4_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_rca4_out |= ((u_rca4_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_rca4_out |= ((u_rca4_fa3_or0 >> 0) & 0x01ull) << 4;
  return u_rca4_out;
}