#include <stdio.h>
#include <stdint.h>

uint64_t u_rca4(uint64_t a, uint64_t b){
  uint8_t u_rca4_out = 0;
  uint8_t u_rca4_ha_xor0 = 0;
  uint8_t u_rca4_ha_and0 = 0;
  uint8_t u_rca4_fa1_xor0 = 0;
  uint8_t u_rca4_fa1_and0 = 0;
  uint8_t u_rca4_fa1_xor1 = 0;
  uint8_t u_rca4_fa1_and1 = 0;
  uint8_t u_rca4_fa1_or0 = 0;
  uint8_t u_rca4_fa2_xor0 = 0;
  uint8_t u_rca4_fa2_and0 = 0;
  uint8_t u_rca4_fa2_xor1 = 0;
  uint8_t u_rca4_fa2_and1 = 0;
  uint8_t u_rca4_fa2_or0 = 0;
  uint8_t u_rca4_fa3_xor0 = 0;
  uint8_t u_rca4_fa3_and0 = 0;
  uint8_t u_rca4_fa3_xor1 = 0;
  uint8_t u_rca4_fa3_and1 = 0;
  uint8_t u_rca4_fa3_or0 = 0;

  u_rca4_ha_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_rca4_ha_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_rca4_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_rca4_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_rca4_fa1_xor1 = ((u_rca4_fa1_xor0 >> 0) & 0x01) ^ ((u_rca4_ha_and0 >> 0) & 0x01);
  u_rca4_fa1_and1 = ((u_rca4_fa1_xor0 >> 0) & 0x01) & ((u_rca4_ha_and0 >> 0) & 0x01);
  u_rca4_fa1_or0 = ((u_rca4_fa1_and0 >> 0) & 0x01) | ((u_rca4_fa1_and1 >> 0) & 0x01);
  u_rca4_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_rca4_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_rca4_fa2_xor1 = ((u_rca4_fa2_xor0 >> 0) & 0x01) ^ ((u_rca4_fa1_or0 >> 0) & 0x01);
  u_rca4_fa2_and1 = ((u_rca4_fa2_xor0 >> 0) & 0x01) & ((u_rca4_fa1_or0 >> 0) & 0x01);
  u_rca4_fa2_or0 = ((u_rca4_fa2_and0 >> 0) & 0x01) | ((u_rca4_fa2_and1 >> 0) & 0x01);
  u_rca4_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_rca4_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_rca4_fa3_xor1 = ((u_rca4_fa3_xor0 >> 0) & 0x01) ^ ((u_rca4_fa2_or0 >> 0) & 0x01);
  u_rca4_fa3_and1 = ((u_rca4_fa3_xor0 >> 0) & 0x01) & ((u_rca4_fa2_or0 >> 0) & 0x01);
  u_rca4_fa3_or0 = ((u_rca4_fa3_and0 >> 0) & 0x01) | ((u_rca4_fa3_and1 >> 0) & 0x01);

  u_rca4_out |= ((u_rca4_ha_xor0 >> 0) & 0x01ull) << 0;
  u_rca4_out |= ((u_rca4_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_rca4_out |= ((u_rca4_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_rca4_out |= ((u_rca4_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_rca4_out |= ((u_rca4_fa3_or0 >> 0) & 0x01ull) << 4;
  return u_rca4_out;
}