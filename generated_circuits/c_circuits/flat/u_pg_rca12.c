#include <stdio.h>
#include <stdint.h>

uint64_t u_pg_rca12(uint64_t a, uint64_t b){
  uint64_t u_pg_rca12_out = 0;
  uint8_t u_pg_rca12_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa0_and0 = 0;
  uint8_t u_pg_rca12_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa1_and0 = 0;
  uint8_t u_pg_rca12_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca12_and1 = 0;
  uint8_t u_pg_rca12_or1 = 0;
  uint8_t u_pg_rca12_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa2_and0 = 0;
  uint8_t u_pg_rca12_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca12_and2 = 0;
  uint8_t u_pg_rca12_or2 = 0;
  uint8_t u_pg_rca12_pg_fa3_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa3_and0 = 0;
  uint8_t u_pg_rca12_pg_fa3_xor1 = 0;
  uint8_t u_pg_rca12_and3 = 0;
  uint8_t u_pg_rca12_or3 = 0;
  uint8_t u_pg_rca12_pg_fa4_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa4_and0 = 0;
  uint8_t u_pg_rca12_pg_fa4_xor1 = 0;
  uint8_t u_pg_rca12_and4 = 0;
  uint8_t u_pg_rca12_or4 = 0;
  uint8_t u_pg_rca12_pg_fa5_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa5_and0 = 0;
  uint8_t u_pg_rca12_pg_fa5_xor1 = 0;
  uint8_t u_pg_rca12_and5 = 0;
  uint8_t u_pg_rca12_or5 = 0;
  uint8_t u_pg_rca12_pg_fa6_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa6_and0 = 0;
  uint8_t u_pg_rca12_pg_fa6_xor1 = 0;
  uint8_t u_pg_rca12_and6 = 0;
  uint8_t u_pg_rca12_or6 = 0;
  uint8_t u_pg_rca12_pg_fa7_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa7_and0 = 0;
  uint8_t u_pg_rca12_pg_fa7_xor1 = 0;
  uint8_t u_pg_rca12_and7 = 0;
  uint8_t u_pg_rca12_or7 = 0;
  uint8_t u_pg_rca12_pg_fa8_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa8_and0 = 0;
  uint8_t u_pg_rca12_pg_fa8_xor1 = 0;
  uint8_t u_pg_rca12_and8 = 0;
  uint8_t u_pg_rca12_or8 = 0;
  uint8_t u_pg_rca12_pg_fa9_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa9_and0 = 0;
  uint8_t u_pg_rca12_pg_fa9_xor1 = 0;
  uint8_t u_pg_rca12_and9 = 0;
  uint8_t u_pg_rca12_or9 = 0;
  uint8_t u_pg_rca12_pg_fa10_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa10_and0 = 0;
  uint8_t u_pg_rca12_pg_fa10_xor1 = 0;
  uint8_t u_pg_rca12_and10 = 0;
  uint8_t u_pg_rca12_or10 = 0;
  uint8_t u_pg_rca12_pg_fa11_xor0 = 0;
  uint8_t u_pg_rca12_pg_fa11_and0 = 0;
  uint8_t u_pg_rca12_pg_fa11_xor1 = 0;
  uint8_t u_pg_rca12_and11 = 0;
  uint8_t u_pg_rca12_or11 = 0;

  u_pg_rca12_pg_fa0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_pg_rca12_pg_fa0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_pg_rca12_pg_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_pg_rca12_pg_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_pg_rca12_pg_fa1_xor1 = ((u_pg_rca12_pg_fa1_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_pg_fa0_and0 >> 0) & 0x01);
  u_pg_rca12_and1 = ((u_pg_rca12_pg_fa0_and0 >> 0) & 0x01) & ((u_pg_rca12_pg_fa1_xor0 >> 0) & 0x01);
  u_pg_rca12_or1 = ((u_pg_rca12_and1 >> 0) & 0x01) | ((u_pg_rca12_pg_fa1_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_pg_rca12_pg_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_pg_rca12_pg_fa2_xor1 = ((u_pg_rca12_pg_fa2_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or1 >> 0) & 0x01);
  u_pg_rca12_and2 = ((u_pg_rca12_or1 >> 0) & 0x01) & ((u_pg_rca12_pg_fa2_xor0 >> 0) & 0x01);
  u_pg_rca12_or2 = ((u_pg_rca12_and2 >> 0) & 0x01) | ((u_pg_rca12_pg_fa2_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_pg_rca12_pg_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_pg_rca12_pg_fa3_xor1 = ((u_pg_rca12_pg_fa3_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or2 >> 0) & 0x01);
  u_pg_rca12_and3 = ((u_pg_rca12_or2 >> 0) & 0x01) & ((u_pg_rca12_pg_fa3_xor0 >> 0) & 0x01);
  u_pg_rca12_or3 = ((u_pg_rca12_and3 >> 0) & 0x01) | ((u_pg_rca12_pg_fa3_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  u_pg_rca12_pg_fa4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  u_pg_rca12_pg_fa4_xor1 = ((u_pg_rca12_pg_fa4_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or3 >> 0) & 0x01);
  u_pg_rca12_and4 = ((u_pg_rca12_or3 >> 0) & 0x01) & ((u_pg_rca12_pg_fa4_xor0 >> 0) & 0x01);
  u_pg_rca12_or4 = ((u_pg_rca12_and4 >> 0) & 0x01) | ((u_pg_rca12_pg_fa4_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  u_pg_rca12_pg_fa5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  u_pg_rca12_pg_fa5_xor1 = ((u_pg_rca12_pg_fa5_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or4 >> 0) & 0x01);
  u_pg_rca12_and5 = ((u_pg_rca12_or4 >> 0) & 0x01) & ((u_pg_rca12_pg_fa5_xor0 >> 0) & 0x01);
  u_pg_rca12_or5 = ((u_pg_rca12_and5 >> 0) & 0x01) | ((u_pg_rca12_pg_fa5_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  u_pg_rca12_pg_fa6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  u_pg_rca12_pg_fa6_xor1 = ((u_pg_rca12_pg_fa6_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or5 >> 0) & 0x01);
  u_pg_rca12_and6 = ((u_pg_rca12_or5 >> 0) & 0x01) & ((u_pg_rca12_pg_fa6_xor0 >> 0) & 0x01);
  u_pg_rca12_or6 = ((u_pg_rca12_and6 >> 0) & 0x01) | ((u_pg_rca12_pg_fa6_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  u_pg_rca12_pg_fa7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  u_pg_rca12_pg_fa7_xor1 = ((u_pg_rca12_pg_fa7_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or6 >> 0) & 0x01);
  u_pg_rca12_and7 = ((u_pg_rca12_or6 >> 0) & 0x01) & ((u_pg_rca12_pg_fa7_xor0 >> 0) & 0x01);
  u_pg_rca12_or7 = ((u_pg_rca12_and7 >> 0) & 0x01) | ((u_pg_rca12_pg_fa7_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa8_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  u_pg_rca12_pg_fa8_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  u_pg_rca12_pg_fa8_xor1 = ((u_pg_rca12_pg_fa8_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or7 >> 0) & 0x01);
  u_pg_rca12_and8 = ((u_pg_rca12_or7 >> 0) & 0x01) & ((u_pg_rca12_pg_fa8_xor0 >> 0) & 0x01);
  u_pg_rca12_or8 = ((u_pg_rca12_and8 >> 0) & 0x01) | ((u_pg_rca12_pg_fa8_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa9_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  u_pg_rca12_pg_fa9_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  u_pg_rca12_pg_fa9_xor1 = ((u_pg_rca12_pg_fa9_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or8 >> 0) & 0x01);
  u_pg_rca12_and9 = ((u_pg_rca12_or8 >> 0) & 0x01) & ((u_pg_rca12_pg_fa9_xor0 >> 0) & 0x01);
  u_pg_rca12_or9 = ((u_pg_rca12_and9 >> 0) & 0x01) | ((u_pg_rca12_pg_fa9_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa10_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  u_pg_rca12_pg_fa10_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  u_pg_rca12_pg_fa10_xor1 = ((u_pg_rca12_pg_fa10_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or9 >> 0) & 0x01);
  u_pg_rca12_and10 = ((u_pg_rca12_or9 >> 0) & 0x01) & ((u_pg_rca12_pg_fa10_xor0 >> 0) & 0x01);
  u_pg_rca12_or10 = ((u_pg_rca12_and10 >> 0) & 0x01) | ((u_pg_rca12_pg_fa10_and0 >> 0) & 0x01);
  u_pg_rca12_pg_fa11_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  u_pg_rca12_pg_fa11_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  u_pg_rca12_pg_fa11_xor1 = ((u_pg_rca12_pg_fa11_xor0 >> 0) & 0x01) ^ ((u_pg_rca12_or10 >> 0) & 0x01);
  u_pg_rca12_and11 = ((u_pg_rca12_or10 >> 0) & 0x01) & ((u_pg_rca12_pg_fa11_xor0 >> 0) & 0x01);
  u_pg_rca12_or11 = ((u_pg_rca12_and11 >> 0) & 0x01) | ((u_pg_rca12_pg_fa11_and0 >> 0) & 0x01);

  u_pg_rca12_out |= ((u_pg_rca12_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa4_xor1 >> 0) & 0x01ull) << 4;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa5_xor1 >> 0) & 0x01ull) << 5;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa6_xor1 >> 0) & 0x01ull) << 6;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa7_xor1 >> 0) & 0x01ull) << 7;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa8_xor1 >> 0) & 0x01ull) << 8;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa9_xor1 >> 0) & 0x01ull) << 9;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa10_xor1 >> 0) & 0x01ull) << 10;
  u_pg_rca12_out |= ((u_pg_rca12_pg_fa11_xor1 >> 0) & 0x01ull) << 11;
  u_pg_rca12_out |= ((u_pg_rca12_or11 >> 0) & 0x01ull) << 12;
  return u_pg_rca12_out;
}