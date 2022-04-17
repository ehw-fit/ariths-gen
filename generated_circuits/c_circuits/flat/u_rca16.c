#include <stdio.h>
#include <stdint.h>

uint64_t u_rca16(uint64_t a, uint64_t b){
  uint64_t u_rca16_out = 0;
  uint8_t u_rca16_ha_xor0 = 0;
  uint8_t u_rca16_ha_and0 = 0;
  uint8_t u_rca16_fa1_xor0 = 0;
  uint8_t u_rca16_fa1_and0 = 0;
  uint8_t u_rca16_fa1_xor1 = 0;
  uint8_t u_rca16_fa1_and1 = 0;
  uint8_t u_rca16_fa1_or0 = 0;
  uint8_t u_rca16_fa2_xor0 = 0;
  uint8_t u_rca16_fa2_and0 = 0;
  uint8_t u_rca16_fa2_xor1 = 0;
  uint8_t u_rca16_fa2_and1 = 0;
  uint8_t u_rca16_fa2_or0 = 0;
  uint8_t u_rca16_fa3_xor0 = 0;
  uint8_t u_rca16_fa3_and0 = 0;
  uint8_t u_rca16_fa3_xor1 = 0;
  uint8_t u_rca16_fa3_and1 = 0;
  uint8_t u_rca16_fa3_or0 = 0;
  uint8_t u_rca16_fa4_xor0 = 0;
  uint8_t u_rca16_fa4_and0 = 0;
  uint8_t u_rca16_fa4_xor1 = 0;
  uint8_t u_rca16_fa4_and1 = 0;
  uint8_t u_rca16_fa4_or0 = 0;
  uint8_t u_rca16_fa5_xor0 = 0;
  uint8_t u_rca16_fa5_and0 = 0;
  uint8_t u_rca16_fa5_xor1 = 0;
  uint8_t u_rca16_fa5_and1 = 0;
  uint8_t u_rca16_fa5_or0 = 0;
  uint8_t u_rca16_fa6_xor0 = 0;
  uint8_t u_rca16_fa6_and0 = 0;
  uint8_t u_rca16_fa6_xor1 = 0;
  uint8_t u_rca16_fa6_and1 = 0;
  uint8_t u_rca16_fa6_or0 = 0;
  uint8_t u_rca16_fa7_xor0 = 0;
  uint8_t u_rca16_fa7_and0 = 0;
  uint8_t u_rca16_fa7_xor1 = 0;
  uint8_t u_rca16_fa7_and1 = 0;
  uint8_t u_rca16_fa7_or0 = 0;
  uint8_t u_rca16_fa8_xor0 = 0;
  uint8_t u_rca16_fa8_and0 = 0;
  uint8_t u_rca16_fa8_xor1 = 0;
  uint8_t u_rca16_fa8_and1 = 0;
  uint8_t u_rca16_fa8_or0 = 0;
  uint8_t u_rca16_fa9_xor0 = 0;
  uint8_t u_rca16_fa9_and0 = 0;
  uint8_t u_rca16_fa9_xor1 = 0;
  uint8_t u_rca16_fa9_and1 = 0;
  uint8_t u_rca16_fa9_or0 = 0;
  uint8_t u_rca16_fa10_xor0 = 0;
  uint8_t u_rca16_fa10_and0 = 0;
  uint8_t u_rca16_fa10_xor1 = 0;
  uint8_t u_rca16_fa10_and1 = 0;
  uint8_t u_rca16_fa10_or0 = 0;
  uint8_t u_rca16_fa11_xor0 = 0;
  uint8_t u_rca16_fa11_and0 = 0;
  uint8_t u_rca16_fa11_xor1 = 0;
  uint8_t u_rca16_fa11_and1 = 0;
  uint8_t u_rca16_fa11_or0 = 0;
  uint8_t u_rca16_fa12_xor0 = 0;
  uint8_t u_rca16_fa12_and0 = 0;
  uint8_t u_rca16_fa12_xor1 = 0;
  uint8_t u_rca16_fa12_and1 = 0;
  uint8_t u_rca16_fa12_or0 = 0;
  uint8_t u_rca16_fa13_xor0 = 0;
  uint8_t u_rca16_fa13_and0 = 0;
  uint8_t u_rca16_fa13_xor1 = 0;
  uint8_t u_rca16_fa13_and1 = 0;
  uint8_t u_rca16_fa13_or0 = 0;
  uint8_t u_rca16_fa14_xor0 = 0;
  uint8_t u_rca16_fa14_and0 = 0;
  uint8_t u_rca16_fa14_xor1 = 0;
  uint8_t u_rca16_fa14_and1 = 0;
  uint8_t u_rca16_fa14_or0 = 0;
  uint8_t u_rca16_fa15_xor0 = 0;
  uint8_t u_rca16_fa15_and0 = 0;
  uint8_t u_rca16_fa15_xor1 = 0;
  uint8_t u_rca16_fa15_and1 = 0;
  uint8_t u_rca16_fa15_or0 = 0;

  u_rca16_ha_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_rca16_ha_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_rca16_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_rca16_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_rca16_fa1_xor1 = ((u_rca16_fa1_xor0 >> 0) & 0x01) ^ ((u_rca16_ha_and0 >> 0) & 0x01);
  u_rca16_fa1_and1 = ((u_rca16_fa1_xor0 >> 0) & 0x01) & ((u_rca16_ha_and0 >> 0) & 0x01);
  u_rca16_fa1_or0 = ((u_rca16_fa1_and0 >> 0) & 0x01) | ((u_rca16_fa1_and1 >> 0) & 0x01);
  u_rca16_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_rca16_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_rca16_fa2_xor1 = ((u_rca16_fa2_xor0 >> 0) & 0x01) ^ ((u_rca16_fa1_or0 >> 0) & 0x01);
  u_rca16_fa2_and1 = ((u_rca16_fa2_xor0 >> 0) & 0x01) & ((u_rca16_fa1_or0 >> 0) & 0x01);
  u_rca16_fa2_or0 = ((u_rca16_fa2_and0 >> 0) & 0x01) | ((u_rca16_fa2_and1 >> 0) & 0x01);
  u_rca16_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_rca16_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_rca16_fa3_xor1 = ((u_rca16_fa3_xor0 >> 0) & 0x01) ^ ((u_rca16_fa2_or0 >> 0) & 0x01);
  u_rca16_fa3_and1 = ((u_rca16_fa3_xor0 >> 0) & 0x01) & ((u_rca16_fa2_or0 >> 0) & 0x01);
  u_rca16_fa3_or0 = ((u_rca16_fa3_and0 >> 0) & 0x01) | ((u_rca16_fa3_and1 >> 0) & 0x01);
  u_rca16_fa4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  u_rca16_fa4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  u_rca16_fa4_xor1 = ((u_rca16_fa4_xor0 >> 0) & 0x01) ^ ((u_rca16_fa3_or0 >> 0) & 0x01);
  u_rca16_fa4_and1 = ((u_rca16_fa4_xor0 >> 0) & 0x01) & ((u_rca16_fa3_or0 >> 0) & 0x01);
  u_rca16_fa4_or0 = ((u_rca16_fa4_and0 >> 0) & 0x01) | ((u_rca16_fa4_and1 >> 0) & 0x01);
  u_rca16_fa5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  u_rca16_fa5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  u_rca16_fa5_xor1 = ((u_rca16_fa5_xor0 >> 0) & 0x01) ^ ((u_rca16_fa4_or0 >> 0) & 0x01);
  u_rca16_fa5_and1 = ((u_rca16_fa5_xor0 >> 0) & 0x01) & ((u_rca16_fa4_or0 >> 0) & 0x01);
  u_rca16_fa5_or0 = ((u_rca16_fa5_and0 >> 0) & 0x01) | ((u_rca16_fa5_and1 >> 0) & 0x01);
  u_rca16_fa6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  u_rca16_fa6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  u_rca16_fa6_xor1 = ((u_rca16_fa6_xor0 >> 0) & 0x01) ^ ((u_rca16_fa5_or0 >> 0) & 0x01);
  u_rca16_fa6_and1 = ((u_rca16_fa6_xor0 >> 0) & 0x01) & ((u_rca16_fa5_or0 >> 0) & 0x01);
  u_rca16_fa6_or0 = ((u_rca16_fa6_and0 >> 0) & 0x01) | ((u_rca16_fa6_and1 >> 0) & 0x01);
  u_rca16_fa7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  u_rca16_fa7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  u_rca16_fa7_xor1 = ((u_rca16_fa7_xor0 >> 0) & 0x01) ^ ((u_rca16_fa6_or0 >> 0) & 0x01);
  u_rca16_fa7_and1 = ((u_rca16_fa7_xor0 >> 0) & 0x01) & ((u_rca16_fa6_or0 >> 0) & 0x01);
  u_rca16_fa7_or0 = ((u_rca16_fa7_and0 >> 0) & 0x01) | ((u_rca16_fa7_and1 >> 0) & 0x01);
  u_rca16_fa8_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  u_rca16_fa8_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  u_rca16_fa8_xor1 = ((u_rca16_fa8_xor0 >> 0) & 0x01) ^ ((u_rca16_fa7_or0 >> 0) & 0x01);
  u_rca16_fa8_and1 = ((u_rca16_fa8_xor0 >> 0) & 0x01) & ((u_rca16_fa7_or0 >> 0) & 0x01);
  u_rca16_fa8_or0 = ((u_rca16_fa8_and0 >> 0) & 0x01) | ((u_rca16_fa8_and1 >> 0) & 0x01);
  u_rca16_fa9_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  u_rca16_fa9_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  u_rca16_fa9_xor1 = ((u_rca16_fa9_xor0 >> 0) & 0x01) ^ ((u_rca16_fa8_or0 >> 0) & 0x01);
  u_rca16_fa9_and1 = ((u_rca16_fa9_xor0 >> 0) & 0x01) & ((u_rca16_fa8_or0 >> 0) & 0x01);
  u_rca16_fa9_or0 = ((u_rca16_fa9_and0 >> 0) & 0x01) | ((u_rca16_fa9_and1 >> 0) & 0x01);
  u_rca16_fa10_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  u_rca16_fa10_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  u_rca16_fa10_xor1 = ((u_rca16_fa10_xor0 >> 0) & 0x01) ^ ((u_rca16_fa9_or0 >> 0) & 0x01);
  u_rca16_fa10_and1 = ((u_rca16_fa10_xor0 >> 0) & 0x01) & ((u_rca16_fa9_or0 >> 0) & 0x01);
  u_rca16_fa10_or0 = ((u_rca16_fa10_and0 >> 0) & 0x01) | ((u_rca16_fa10_and1 >> 0) & 0x01);
  u_rca16_fa11_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  u_rca16_fa11_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  u_rca16_fa11_xor1 = ((u_rca16_fa11_xor0 >> 0) & 0x01) ^ ((u_rca16_fa10_or0 >> 0) & 0x01);
  u_rca16_fa11_and1 = ((u_rca16_fa11_xor0 >> 0) & 0x01) & ((u_rca16_fa10_or0 >> 0) & 0x01);
  u_rca16_fa11_or0 = ((u_rca16_fa11_and0 >> 0) & 0x01) | ((u_rca16_fa11_and1 >> 0) & 0x01);
  u_rca16_fa12_xor0 = ((a >> 12) & 0x01) ^ ((b >> 12) & 0x01);
  u_rca16_fa12_and0 = ((a >> 12) & 0x01) & ((b >> 12) & 0x01);
  u_rca16_fa12_xor1 = ((u_rca16_fa12_xor0 >> 0) & 0x01) ^ ((u_rca16_fa11_or0 >> 0) & 0x01);
  u_rca16_fa12_and1 = ((u_rca16_fa12_xor0 >> 0) & 0x01) & ((u_rca16_fa11_or0 >> 0) & 0x01);
  u_rca16_fa12_or0 = ((u_rca16_fa12_and0 >> 0) & 0x01) | ((u_rca16_fa12_and1 >> 0) & 0x01);
  u_rca16_fa13_xor0 = ((a >> 13) & 0x01) ^ ((b >> 13) & 0x01);
  u_rca16_fa13_and0 = ((a >> 13) & 0x01) & ((b >> 13) & 0x01);
  u_rca16_fa13_xor1 = ((u_rca16_fa13_xor0 >> 0) & 0x01) ^ ((u_rca16_fa12_or0 >> 0) & 0x01);
  u_rca16_fa13_and1 = ((u_rca16_fa13_xor0 >> 0) & 0x01) & ((u_rca16_fa12_or0 >> 0) & 0x01);
  u_rca16_fa13_or0 = ((u_rca16_fa13_and0 >> 0) & 0x01) | ((u_rca16_fa13_and1 >> 0) & 0x01);
  u_rca16_fa14_xor0 = ((a >> 14) & 0x01) ^ ((b >> 14) & 0x01);
  u_rca16_fa14_and0 = ((a >> 14) & 0x01) & ((b >> 14) & 0x01);
  u_rca16_fa14_xor1 = ((u_rca16_fa14_xor0 >> 0) & 0x01) ^ ((u_rca16_fa13_or0 >> 0) & 0x01);
  u_rca16_fa14_and1 = ((u_rca16_fa14_xor0 >> 0) & 0x01) & ((u_rca16_fa13_or0 >> 0) & 0x01);
  u_rca16_fa14_or0 = ((u_rca16_fa14_and0 >> 0) & 0x01) | ((u_rca16_fa14_and1 >> 0) & 0x01);
  u_rca16_fa15_xor0 = ((a >> 15) & 0x01) ^ ((b >> 15) & 0x01);
  u_rca16_fa15_and0 = ((a >> 15) & 0x01) & ((b >> 15) & 0x01);
  u_rca16_fa15_xor1 = ((u_rca16_fa15_xor0 >> 0) & 0x01) ^ ((u_rca16_fa14_or0 >> 0) & 0x01);
  u_rca16_fa15_and1 = ((u_rca16_fa15_xor0 >> 0) & 0x01) & ((u_rca16_fa14_or0 >> 0) & 0x01);
  u_rca16_fa15_or0 = ((u_rca16_fa15_and0 >> 0) & 0x01) | ((u_rca16_fa15_and1 >> 0) & 0x01);

  u_rca16_out |= ((u_rca16_ha_xor0 >> 0) & 0x01ull) << 0;
  u_rca16_out |= ((u_rca16_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_rca16_out |= ((u_rca16_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_rca16_out |= ((u_rca16_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_rca16_out |= ((u_rca16_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_rca16_out |= ((u_rca16_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_rca16_out |= ((u_rca16_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_rca16_out |= ((u_rca16_fa7_xor1 >> 0) & 0x01ull) << 7;
  u_rca16_out |= ((u_rca16_fa8_xor1 >> 0) & 0x01ull) << 8;
  u_rca16_out |= ((u_rca16_fa9_xor1 >> 0) & 0x01ull) << 9;
  u_rca16_out |= ((u_rca16_fa10_xor1 >> 0) & 0x01ull) << 10;
  u_rca16_out |= ((u_rca16_fa11_xor1 >> 0) & 0x01ull) << 11;
  u_rca16_out |= ((u_rca16_fa12_xor1 >> 0) & 0x01ull) << 12;
  u_rca16_out |= ((u_rca16_fa13_xor1 >> 0) & 0x01ull) << 13;
  u_rca16_out |= ((u_rca16_fa14_xor1 >> 0) & 0x01ull) << 14;
  u_rca16_out |= ((u_rca16_fa15_xor1 >> 0) & 0x01ull) << 15;
  u_rca16_out |= ((u_rca16_fa15_or0 >> 0) & 0x01ull) << 16;
  return u_rca16_out;
}