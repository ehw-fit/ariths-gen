#include <stdio.h>
#include <stdint.h>

int64_t s_pg_rca4(int64_t a, int64_t b){
  int8_t s_pg_rca4_out = 0;
  uint8_t s_pg_rca4_pg_fa0_xor0 = 0;
  uint8_t s_pg_rca4_pg_fa0_and0 = 0;
  uint8_t s_pg_rca4_pg_fa1_xor0 = 0;
  uint8_t s_pg_rca4_pg_fa1_and0 = 0;
  uint8_t s_pg_rca4_pg_fa1_xor1 = 0;
  uint8_t s_pg_rca4_and1 = 0;
  uint8_t s_pg_rca4_or1 = 0;
  uint8_t s_pg_rca4_pg_fa2_xor0 = 0;
  uint8_t s_pg_rca4_pg_fa2_and0 = 0;
  uint8_t s_pg_rca4_pg_fa2_xor1 = 0;
  uint8_t s_pg_rca4_and2 = 0;
  uint8_t s_pg_rca4_or2 = 0;
  uint8_t s_pg_rca4_pg_fa3_xor0 = 0;
  uint8_t s_pg_rca4_pg_fa3_and0 = 0;
  uint8_t s_pg_rca4_pg_fa3_xor1 = 0;
  uint8_t s_pg_rca4_and3 = 0;
  uint8_t s_pg_rca4_or3 = 0;
  uint8_t s_pg_rca4_xor0 = 0;
  uint8_t s_pg_rca4_xor1 = 0;

  s_pg_rca4_pg_fa0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  s_pg_rca4_pg_fa0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  s_pg_rca4_pg_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  s_pg_rca4_pg_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  s_pg_rca4_pg_fa1_xor1 = ((s_pg_rca4_pg_fa1_xor0 >> 0) & 0x01) ^ ((s_pg_rca4_pg_fa0_and0 >> 0) & 0x01);
  s_pg_rca4_and1 = ((s_pg_rca4_pg_fa0_and0 >> 0) & 0x01) & ((s_pg_rca4_pg_fa1_xor0 >> 0) & 0x01);
  s_pg_rca4_or1 = ((s_pg_rca4_and1 >> 0) & 0x01) | ((s_pg_rca4_pg_fa1_and0 >> 0) & 0x01);
  s_pg_rca4_pg_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  s_pg_rca4_pg_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  s_pg_rca4_pg_fa2_xor1 = ((s_pg_rca4_pg_fa2_xor0 >> 0) & 0x01) ^ ((s_pg_rca4_or1 >> 0) & 0x01);
  s_pg_rca4_and2 = ((s_pg_rca4_or1 >> 0) & 0x01) & ((s_pg_rca4_pg_fa2_xor0 >> 0) & 0x01);
  s_pg_rca4_or2 = ((s_pg_rca4_and2 >> 0) & 0x01) | ((s_pg_rca4_pg_fa2_and0 >> 0) & 0x01);
  s_pg_rca4_pg_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_pg_rca4_pg_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  s_pg_rca4_pg_fa3_xor1 = ((s_pg_rca4_pg_fa3_xor0 >> 0) & 0x01) ^ ((s_pg_rca4_or2 >> 0) & 0x01);
  s_pg_rca4_and3 = ((s_pg_rca4_or2 >> 0) & 0x01) & ((s_pg_rca4_pg_fa3_xor0 >> 0) & 0x01);
  s_pg_rca4_or3 = ((s_pg_rca4_and3 >> 0) & 0x01) | ((s_pg_rca4_pg_fa3_and0 >> 0) & 0x01);
  s_pg_rca4_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_pg_rca4_xor1 = ((s_pg_rca4_xor0 >> 0) & 0x01) ^ ((s_pg_rca4_or3 >> 0) & 0x01);

  s_pg_rca4_out |= ((s_pg_rca4_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  s_pg_rca4_out |= ((s_pg_rca4_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  s_pg_rca4_out |= ((s_pg_rca4_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  s_pg_rca4_out |= ((s_pg_rca4_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  s_pg_rca4_out |= ((s_pg_rca4_xor1 >> 0) & 0x01ull) << 4;
  s_pg_rca4_out |= ((s_pg_rca4_xor1 >> 0) & 0x01ull) << 5;
  s_pg_rca4_out |= ((s_pg_rca4_xor1 >> 0) & 0x01ull) << 6;
  s_pg_rca4_out |= ((s_pg_rca4_xor1 >> 0) & 0x01ull) << 7;
  return s_pg_rca4_out;
}