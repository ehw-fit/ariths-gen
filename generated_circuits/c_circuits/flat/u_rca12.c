#include <stdio.h>
#include <stdint.h>

uint64_t u_rca12(uint64_t a, uint64_t b){
  uint64_t u_rca12_out = 0;
  uint8_t u_rca12_ha_xor0 = 0;
  uint8_t u_rca12_ha_and0 = 0;
  uint8_t u_rca12_fa1_xor0 = 0;
  uint8_t u_rca12_fa1_and0 = 0;
  uint8_t u_rca12_fa1_xor1 = 0;
  uint8_t u_rca12_fa1_and1 = 0;
  uint8_t u_rca12_fa1_or0 = 0;
  uint8_t u_rca12_fa2_xor0 = 0;
  uint8_t u_rca12_fa2_and0 = 0;
  uint8_t u_rca12_fa2_xor1 = 0;
  uint8_t u_rca12_fa2_and1 = 0;
  uint8_t u_rca12_fa2_or0 = 0;
  uint8_t u_rca12_fa3_xor0 = 0;
  uint8_t u_rca12_fa3_and0 = 0;
  uint8_t u_rca12_fa3_xor1 = 0;
  uint8_t u_rca12_fa3_and1 = 0;
  uint8_t u_rca12_fa3_or0 = 0;
  uint8_t u_rca12_fa4_xor0 = 0;
  uint8_t u_rca12_fa4_and0 = 0;
  uint8_t u_rca12_fa4_xor1 = 0;
  uint8_t u_rca12_fa4_and1 = 0;
  uint8_t u_rca12_fa4_or0 = 0;
  uint8_t u_rca12_fa5_xor0 = 0;
  uint8_t u_rca12_fa5_and0 = 0;
  uint8_t u_rca12_fa5_xor1 = 0;
  uint8_t u_rca12_fa5_and1 = 0;
  uint8_t u_rca12_fa5_or0 = 0;
  uint8_t u_rca12_fa6_xor0 = 0;
  uint8_t u_rca12_fa6_and0 = 0;
  uint8_t u_rca12_fa6_xor1 = 0;
  uint8_t u_rca12_fa6_and1 = 0;
  uint8_t u_rca12_fa6_or0 = 0;
  uint8_t u_rca12_fa7_xor0 = 0;
  uint8_t u_rca12_fa7_and0 = 0;
  uint8_t u_rca12_fa7_xor1 = 0;
  uint8_t u_rca12_fa7_and1 = 0;
  uint8_t u_rca12_fa7_or0 = 0;
  uint8_t u_rca12_fa8_xor0 = 0;
  uint8_t u_rca12_fa8_and0 = 0;
  uint8_t u_rca12_fa8_xor1 = 0;
  uint8_t u_rca12_fa8_and1 = 0;
  uint8_t u_rca12_fa8_or0 = 0;
  uint8_t u_rca12_fa9_xor0 = 0;
  uint8_t u_rca12_fa9_and0 = 0;
  uint8_t u_rca12_fa9_xor1 = 0;
  uint8_t u_rca12_fa9_and1 = 0;
  uint8_t u_rca12_fa9_or0 = 0;
  uint8_t u_rca12_fa10_xor0 = 0;
  uint8_t u_rca12_fa10_and0 = 0;
  uint8_t u_rca12_fa10_xor1 = 0;
  uint8_t u_rca12_fa10_and1 = 0;
  uint8_t u_rca12_fa10_or0 = 0;
  uint8_t u_rca12_fa11_xor0 = 0;
  uint8_t u_rca12_fa11_and0 = 0;
  uint8_t u_rca12_fa11_xor1 = 0;
  uint8_t u_rca12_fa11_and1 = 0;
  uint8_t u_rca12_fa11_or0 = 0;

  u_rca12_ha_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_rca12_ha_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_rca12_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_rca12_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_rca12_fa1_xor1 = ((u_rca12_fa1_xor0 >> 0) & 0x01) ^ ((u_rca12_ha_and0 >> 0) & 0x01);
  u_rca12_fa1_and1 = ((u_rca12_fa1_xor0 >> 0) & 0x01) & ((u_rca12_ha_and0 >> 0) & 0x01);
  u_rca12_fa1_or0 = ((u_rca12_fa1_and0 >> 0) & 0x01) | ((u_rca12_fa1_and1 >> 0) & 0x01);
  u_rca12_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_rca12_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_rca12_fa2_xor1 = ((u_rca12_fa2_xor0 >> 0) & 0x01) ^ ((u_rca12_fa1_or0 >> 0) & 0x01);
  u_rca12_fa2_and1 = ((u_rca12_fa2_xor0 >> 0) & 0x01) & ((u_rca12_fa1_or0 >> 0) & 0x01);
  u_rca12_fa2_or0 = ((u_rca12_fa2_and0 >> 0) & 0x01) | ((u_rca12_fa2_and1 >> 0) & 0x01);
  u_rca12_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_rca12_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_rca12_fa3_xor1 = ((u_rca12_fa3_xor0 >> 0) & 0x01) ^ ((u_rca12_fa2_or0 >> 0) & 0x01);
  u_rca12_fa3_and1 = ((u_rca12_fa3_xor0 >> 0) & 0x01) & ((u_rca12_fa2_or0 >> 0) & 0x01);
  u_rca12_fa3_or0 = ((u_rca12_fa3_and0 >> 0) & 0x01) | ((u_rca12_fa3_and1 >> 0) & 0x01);
  u_rca12_fa4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  u_rca12_fa4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  u_rca12_fa4_xor1 = ((u_rca12_fa4_xor0 >> 0) & 0x01) ^ ((u_rca12_fa3_or0 >> 0) & 0x01);
  u_rca12_fa4_and1 = ((u_rca12_fa4_xor0 >> 0) & 0x01) & ((u_rca12_fa3_or0 >> 0) & 0x01);
  u_rca12_fa4_or0 = ((u_rca12_fa4_and0 >> 0) & 0x01) | ((u_rca12_fa4_and1 >> 0) & 0x01);
  u_rca12_fa5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  u_rca12_fa5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  u_rca12_fa5_xor1 = ((u_rca12_fa5_xor0 >> 0) & 0x01) ^ ((u_rca12_fa4_or0 >> 0) & 0x01);
  u_rca12_fa5_and1 = ((u_rca12_fa5_xor0 >> 0) & 0x01) & ((u_rca12_fa4_or0 >> 0) & 0x01);
  u_rca12_fa5_or0 = ((u_rca12_fa5_and0 >> 0) & 0x01) | ((u_rca12_fa5_and1 >> 0) & 0x01);
  u_rca12_fa6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  u_rca12_fa6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  u_rca12_fa6_xor1 = ((u_rca12_fa6_xor0 >> 0) & 0x01) ^ ((u_rca12_fa5_or0 >> 0) & 0x01);
  u_rca12_fa6_and1 = ((u_rca12_fa6_xor0 >> 0) & 0x01) & ((u_rca12_fa5_or0 >> 0) & 0x01);
  u_rca12_fa6_or0 = ((u_rca12_fa6_and0 >> 0) & 0x01) | ((u_rca12_fa6_and1 >> 0) & 0x01);
  u_rca12_fa7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  u_rca12_fa7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  u_rca12_fa7_xor1 = ((u_rca12_fa7_xor0 >> 0) & 0x01) ^ ((u_rca12_fa6_or0 >> 0) & 0x01);
  u_rca12_fa7_and1 = ((u_rca12_fa7_xor0 >> 0) & 0x01) & ((u_rca12_fa6_or0 >> 0) & 0x01);
  u_rca12_fa7_or0 = ((u_rca12_fa7_and0 >> 0) & 0x01) | ((u_rca12_fa7_and1 >> 0) & 0x01);
  u_rca12_fa8_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  u_rca12_fa8_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  u_rca12_fa8_xor1 = ((u_rca12_fa8_xor0 >> 0) & 0x01) ^ ((u_rca12_fa7_or0 >> 0) & 0x01);
  u_rca12_fa8_and1 = ((u_rca12_fa8_xor0 >> 0) & 0x01) & ((u_rca12_fa7_or0 >> 0) & 0x01);
  u_rca12_fa8_or0 = ((u_rca12_fa8_and0 >> 0) & 0x01) | ((u_rca12_fa8_and1 >> 0) & 0x01);
  u_rca12_fa9_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  u_rca12_fa9_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  u_rca12_fa9_xor1 = ((u_rca12_fa9_xor0 >> 0) & 0x01) ^ ((u_rca12_fa8_or0 >> 0) & 0x01);
  u_rca12_fa9_and1 = ((u_rca12_fa9_xor0 >> 0) & 0x01) & ((u_rca12_fa8_or0 >> 0) & 0x01);
  u_rca12_fa9_or0 = ((u_rca12_fa9_and0 >> 0) & 0x01) | ((u_rca12_fa9_and1 >> 0) & 0x01);
  u_rca12_fa10_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  u_rca12_fa10_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  u_rca12_fa10_xor1 = ((u_rca12_fa10_xor0 >> 0) & 0x01) ^ ((u_rca12_fa9_or0 >> 0) & 0x01);
  u_rca12_fa10_and1 = ((u_rca12_fa10_xor0 >> 0) & 0x01) & ((u_rca12_fa9_or0 >> 0) & 0x01);
  u_rca12_fa10_or0 = ((u_rca12_fa10_and0 >> 0) & 0x01) | ((u_rca12_fa10_and1 >> 0) & 0x01);
  u_rca12_fa11_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  u_rca12_fa11_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  u_rca12_fa11_xor1 = ((u_rca12_fa11_xor0 >> 0) & 0x01) ^ ((u_rca12_fa10_or0 >> 0) & 0x01);
  u_rca12_fa11_and1 = ((u_rca12_fa11_xor0 >> 0) & 0x01) & ((u_rca12_fa10_or0 >> 0) & 0x01);
  u_rca12_fa11_or0 = ((u_rca12_fa11_and0 >> 0) & 0x01) | ((u_rca12_fa11_and1 >> 0) & 0x01);

  u_rca12_out |= ((u_rca12_ha_xor0 >> 0) & 0x01ull) << 0;
  u_rca12_out |= ((u_rca12_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_rca12_out |= ((u_rca12_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_rca12_out |= ((u_rca12_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_rca12_out |= ((u_rca12_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_rca12_out |= ((u_rca12_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_rca12_out |= ((u_rca12_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_rca12_out |= ((u_rca12_fa7_xor1 >> 0) & 0x01ull) << 7;
  u_rca12_out |= ((u_rca12_fa8_xor1 >> 0) & 0x01ull) << 8;
  u_rca12_out |= ((u_rca12_fa9_xor1 >> 0) & 0x01ull) << 9;
  u_rca12_out |= ((u_rca12_fa10_xor1 >> 0) & 0x01ull) << 10;
  u_rca12_out |= ((u_rca12_fa11_xor1 >> 0) & 0x01ull) << 11;
  u_rca12_out |= ((u_rca12_fa11_or0 >> 0) & 0x01ull) << 12;
  return u_rca12_out;
}