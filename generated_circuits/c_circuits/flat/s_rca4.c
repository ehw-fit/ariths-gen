#include <stdio.h>
#include <stdint.h>

int64_t s_rca4(int64_t a, int64_t b){
  int8_t s_rca4_out = 0;
  uint8_t s_rca4_ha_xor0 = 0;
  uint8_t s_rca4_ha_and0 = 0;
  uint8_t s_rca4_fa1_xor0 = 0;
  uint8_t s_rca4_fa1_and0 = 0;
  uint8_t s_rca4_fa1_xor1 = 0;
  uint8_t s_rca4_fa1_and1 = 0;
  uint8_t s_rca4_fa1_or0 = 0;
  uint8_t s_rca4_fa2_xor0 = 0;
  uint8_t s_rca4_fa2_and0 = 0;
  uint8_t s_rca4_fa2_xor1 = 0;
  uint8_t s_rca4_fa2_and1 = 0;
  uint8_t s_rca4_fa2_or0 = 0;
  uint8_t s_rca4_fa3_xor0 = 0;
  uint8_t s_rca4_fa3_and0 = 0;
  uint8_t s_rca4_fa3_xor1 = 0;
  uint8_t s_rca4_fa3_and1 = 0;
  uint8_t s_rca4_fa3_or0 = 0;
  uint8_t s_rca4_xor0 = 0;
  uint8_t s_rca4_xor1 = 0;

  s_rca4_ha_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  s_rca4_ha_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  s_rca4_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  s_rca4_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  s_rca4_fa1_xor1 = ((s_rca4_fa1_xor0 >> 0) & 0x01) ^ ((s_rca4_ha_and0 >> 0) & 0x01);
  s_rca4_fa1_and1 = ((s_rca4_fa1_xor0 >> 0) & 0x01) & ((s_rca4_ha_and0 >> 0) & 0x01);
  s_rca4_fa1_or0 = ((s_rca4_fa1_and0 >> 0) & 0x01) | ((s_rca4_fa1_and1 >> 0) & 0x01);
  s_rca4_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  s_rca4_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  s_rca4_fa2_xor1 = ((s_rca4_fa2_xor0 >> 0) & 0x01) ^ ((s_rca4_fa1_or0 >> 0) & 0x01);
  s_rca4_fa2_and1 = ((s_rca4_fa2_xor0 >> 0) & 0x01) & ((s_rca4_fa1_or0 >> 0) & 0x01);
  s_rca4_fa2_or0 = ((s_rca4_fa2_and0 >> 0) & 0x01) | ((s_rca4_fa2_and1 >> 0) & 0x01);
  s_rca4_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_rca4_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  s_rca4_fa3_xor1 = ((s_rca4_fa3_xor0 >> 0) & 0x01) ^ ((s_rca4_fa2_or0 >> 0) & 0x01);
  s_rca4_fa3_and1 = ((s_rca4_fa3_xor0 >> 0) & 0x01) & ((s_rca4_fa2_or0 >> 0) & 0x01);
  s_rca4_fa3_or0 = ((s_rca4_fa3_and0 >> 0) & 0x01) | ((s_rca4_fa3_and1 >> 0) & 0x01);
  s_rca4_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_rca4_xor1 = ((s_rca4_xor0 >> 0) & 0x01) ^ ((s_rca4_fa3_or0 >> 0) & 0x01);

  s_rca4_out |= ((s_rca4_ha_xor0 >> 0) & 0x01ull) << 0;
  s_rca4_out |= ((s_rca4_fa1_xor1 >> 0) & 0x01ull) << 1;
  s_rca4_out |= ((s_rca4_fa2_xor1 >> 0) & 0x01ull) << 2;
  s_rca4_out |= ((s_rca4_fa3_xor1 >> 0) & 0x01ull) << 3;
  s_rca4_out |= ((s_rca4_xor1 >> 0) & 0x01ull) << 4;
  s_rca4_out |= ((s_rca4_xor1 >> 0) & 0x01ull) << 5;
  s_rca4_out |= ((s_rca4_xor1 >> 0) & 0x01ull) << 6;
  s_rca4_out |= ((s_rca4_xor1 >> 0) & 0x01ull) << 7;
  return s_rca4_out;
}