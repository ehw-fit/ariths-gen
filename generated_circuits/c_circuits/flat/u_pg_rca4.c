#include <stdio.h>
#include <stdint.h>

uint64_t u_pg_rca4(uint64_t a, uint64_t b){
  uint8_t u_pg_rca4_out = 0;
  uint8_t u_pg_rca4_pg_fa0_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa0_and0 = 0;
  uint8_t u_pg_rca4_pg_fa1_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa1_and0 = 0;
  uint8_t u_pg_rca4_pg_fa1_xor1 = 0;
  uint8_t u_pg_rca4_and1 = 0;
  uint8_t u_pg_rca4_or1 = 0;
  uint8_t u_pg_rca4_pg_fa2_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa2_and0 = 0;
  uint8_t u_pg_rca4_pg_fa2_xor1 = 0;
  uint8_t u_pg_rca4_and2 = 0;
  uint8_t u_pg_rca4_or2 = 0;
  uint8_t u_pg_rca4_pg_fa3_xor0 = 0;
  uint8_t u_pg_rca4_pg_fa3_and0 = 0;
  uint8_t u_pg_rca4_pg_fa3_xor1 = 0;
  uint8_t u_pg_rca4_and3 = 0;
  uint8_t u_pg_rca4_or3 = 0;

  u_pg_rca4_pg_fa0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_pg_rca4_pg_fa0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_pg_rca4_pg_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_pg_rca4_pg_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_pg_rca4_pg_fa1_xor1 = ((u_pg_rca4_pg_fa1_xor0 >> 0) & 0x01) ^ ((u_pg_rca4_pg_fa0_and0 >> 0) & 0x01);
  u_pg_rca4_and1 = ((u_pg_rca4_pg_fa0_and0 >> 0) & 0x01) & ((u_pg_rca4_pg_fa1_xor0 >> 0) & 0x01);
  u_pg_rca4_or1 = ((u_pg_rca4_and1 >> 0) & 0x01) | ((u_pg_rca4_pg_fa1_and0 >> 0) & 0x01);
  u_pg_rca4_pg_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_pg_rca4_pg_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_pg_rca4_pg_fa2_xor1 = ((u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01) ^ ((u_pg_rca4_or1 >> 0) & 0x01);
  u_pg_rca4_and2 = ((u_pg_rca4_or1 >> 0) & 0x01) & ((u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01);
  u_pg_rca4_or2 = ((u_pg_rca4_and2 >> 0) & 0x01) | ((u_pg_rca4_pg_fa2_and0 >> 0) & 0x01);
  u_pg_rca4_pg_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_pg_rca4_pg_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_pg_rca4_pg_fa3_xor1 = ((u_pg_rca4_pg_fa3_xor0 >> 0) & 0x01) ^ ((u_pg_rca4_or2 >> 0) & 0x01);
  u_pg_rca4_and3 = ((u_pg_rca4_or2 >> 0) & 0x01) & ((u_pg_rca4_pg_fa3_xor0 >> 0) & 0x01);
  u_pg_rca4_or3 = ((u_pg_rca4_and3 >> 0) & 0x01) | ((u_pg_rca4_pg_fa3_and0 >> 0) & 0x01);

  u_pg_rca4_out |= ((u_pg_rca4_pg_fa0_xor0 >> 0) & 0x01ull) << 0;
  u_pg_rca4_out |= ((u_pg_rca4_pg_fa1_xor1 >> 0) & 0x01ull) << 1;
  u_pg_rca4_out |= ((u_pg_rca4_pg_fa2_xor1 >> 0) & 0x01ull) << 2;
  u_pg_rca4_out |= ((u_pg_rca4_pg_fa3_xor1 >> 0) & 0x01ull) << 3;
  u_pg_rca4_out |= ((u_pg_rca4_or3 >> 0) & 0x01ull) << 4;
  return u_pg_rca4_out;
}