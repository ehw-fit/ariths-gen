#include <stdio.h>
#include <stdint.h>

uint64_t u_csamul_pg_rca4(uint64_t a, uint64_t b){
  uint8_t u_csamul_pg_rca4_out = 0;
  uint8_t u_csamul_pg_rca4_and0_0 = 0;
  uint8_t u_csamul_pg_rca4_and1_0 = 0;
  uint8_t u_csamul_pg_rca4_and2_0 = 0;
  uint8_t u_csamul_pg_rca4_and3_0 = 0;
  uint8_t u_csamul_pg_rca4_and0_1 = 0;
  uint8_t u_csamul_pg_rca4_ha0_1_xor0 = 0;
  uint8_t u_csamul_pg_rca4_ha0_1_and0 = 0;
  uint8_t u_csamul_pg_rca4_and1_1 = 0;
  uint8_t u_csamul_pg_rca4_ha1_1_xor0 = 0;
  uint8_t u_csamul_pg_rca4_ha1_1_and0 = 0;
  uint8_t u_csamul_pg_rca4_and2_1 = 0;
  uint8_t u_csamul_pg_rca4_ha2_1_xor0 = 0;
  uint8_t u_csamul_pg_rca4_ha2_1_and0 = 0;
  uint8_t u_csamul_pg_rca4_and3_1 = 0;
  uint8_t u_csamul_pg_rca4_and0_2 = 0;
  uint8_t u_csamul_pg_rca4_fa0_2_xor0 = 0;
  uint8_t u_csamul_pg_rca4_fa0_2_and0 = 0;
  uint8_t u_csamul_pg_rca4_fa0_2_xor1 = 0;
  uint8_t u_csamul_pg_rca4_fa0_2_and1 = 0;
  uint8_t u_csamul_pg_rca4_fa0_2_or0 = 0;
  uint8_t u_csamul_pg_rca4_and1_2 = 0;
  uint8_t u_csamul_pg_rca4_fa1_2_xor0 = 0;
  uint8_t u_csamul_pg_rca4_fa1_2_and0 = 0;
  uint8_t u_csamul_pg_rca4_fa1_2_xor1 = 0;
  uint8_t u_csamul_pg_rca4_fa1_2_and1 = 0;
  uint8_t u_csamul_pg_rca4_fa1_2_or0 = 0;
  uint8_t u_csamul_pg_rca4_and2_2 = 0;
  uint8_t u_csamul_pg_rca4_fa2_2_xor0 = 0;
  uint8_t u_csamul_pg_rca4_fa2_2_and0 = 0;
  uint8_t u_csamul_pg_rca4_fa2_2_xor1 = 0;
  uint8_t u_csamul_pg_rca4_fa2_2_and1 = 0;
  uint8_t u_csamul_pg_rca4_fa2_2_or0 = 0;
  uint8_t u_csamul_pg_rca4_and3_2 = 0;
  uint8_t u_csamul_pg_rca4_and0_3 = 0;
  uint8_t u_csamul_pg_rca4_fa0_3_xor0 = 0;
  uint8_t u_csamul_pg_rca4_fa0_3_and0 = 0;
  uint8_t u_csamul_pg_rca4_fa0_3_xor1 = 0;
  uint8_t u_csamul_pg_rca4_fa0_3_and1 = 0;
  uint8_t u_csamul_pg_rca4_fa0_3_or0 = 0;
  uint8_t u_csamul_pg_rca4_and1_3 = 0;
  uint8_t u_csamul_pg_rca4_fa1_3_xor0 = 0;
  uint8_t u_csamul_pg_rca4_fa1_3_and0 = 0;
  uint8_t u_csamul_pg_rca4_fa1_3_xor1 = 0;
  uint8_t u_csamul_pg_rca4_fa1_3_and1 = 0;
  uint8_t u_csamul_pg_rca4_fa1_3_or0 = 0;
  uint8_t u_csamul_pg_rca4_and2_3 = 0;
  uint8_t u_csamul_pg_rca4_fa2_3_xor0 = 0;
  uint8_t u_csamul_pg_rca4_fa2_3_and0 = 0;
  uint8_t u_csamul_pg_rca4_fa2_3_xor1 = 0;
  uint8_t u_csamul_pg_rca4_fa2_3_and1 = 0;
  uint8_t u_csamul_pg_rca4_fa2_3_or0 = 0;
  uint8_t u_csamul_pg_rca4_and3_3 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa0_xor0 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa0_and0 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor0 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa1_and0 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor1 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_and1 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_or1 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor0 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa2_and0 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor1 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_and2 = 0;
  uint8_t u_csamul_pg_rca4_u_pg_rca4_or2 = 0;

  u_csamul_pg_rca4_and0_0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_csamul_pg_rca4_and1_0 = ((a >> 1) & 0x01) & ((b >> 0) & 0x01);
  u_csamul_pg_rca4_and2_0 = ((a >> 2) & 0x01) & ((b >> 0) & 0x01);
  u_csamul_pg_rca4_and3_0 = ((a >> 3) & 0x01) & ((b >> 0) & 0x01);
  u_csamul_pg_rca4_and0_1 = ((a >> 0) & 0x01) & ((b >> 1) & 0x01);
  u_csamul_pg_rca4_ha0_1_xor0 = ((u_csamul_pg_rca4_and0_1 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_and1_0 >> 0) & 0x01);
  u_csamul_pg_rca4_ha0_1_and0 = ((u_csamul_pg_rca4_and0_1 >> 0) & 0x01) & ((u_csamul_pg_rca4_and1_0 >> 0) & 0x01);
  u_csamul_pg_rca4_and1_1 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_csamul_pg_rca4_ha1_1_xor0 = ((u_csamul_pg_rca4_and1_1 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_and2_0 >> 0) & 0x01);
  u_csamul_pg_rca4_ha1_1_and0 = ((u_csamul_pg_rca4_and1_1 >> 0) & 0x01) & ((u_csamul_pg_rca4_and2_0 >> 0) & 0x01);
  u_csamul_pg_rca4_and2_1 = ((a >> 2) & 0x01) & ((b >> 1) & 0x01);
  u_csamul_pg_rca4_ha2_1_xor0 = ((u_csamul_pg_rca4_and2_1 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_and3_0 >> 0) & 0x01);
  u_csamul_pg_rca4_ha2_1_and0 = ((u_csamul_pg_rca4_and2_1 >> 0) & 0x01) & ((u_csamul_pg_rca4_and3_0 >> 0) & 0x01);
  u_csamul_pg_rca4_and3_1 = ((a >> 3) & 0x01) & ((b >> 1) & 0x01);
  u_csamul_pg_rca4_and0_2 = ((a >> 0) & 0x01) & ((b >> 2) & 0x01);
  u_csamul_pg_rca4_fa0_2_xor0 = ((u_csamul_pg_rca4_and0_2 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_ha1_1_xor0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_2_and0 = ((u_csamul_pg_rca4_and0_2 >> 0) & 0x01) & ((u_csamul_pg_rca4_ha1_1_xor0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_2_xor1 = ((u_csamul_pg_rca4_fa0_2_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_ha0_1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_2_and1 = ((u_csamul_pg_rca4_fa0_2_xor0 >> 0) & 0x01) & ((u_csamul_pg_rca4_ha0_1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_2_or0 = ((u_csamul_pg_rca4_fa0_2_and0 >> 0) & 0x01) | ((u_csamul_pg_rca4_fa0_2_and1 >> 0) & 0x01);
  u_csamul_pg_rca4_and1_2 = ((a >> 1) & 0x01) & ((b >> 2) & 0x01);
  u_csamul_pg_rca4_fa1_2_xor0 = ((u_csamul_pg_rca4_and1_2 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_ha2_1_xor0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_2_and0 = ((u_csamul_pg_rca4_and1_2 >> 0) & 0x01) & ((u_csamul_pg_rca4_ha2_1_xor0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_2_xor1 = ((u_csamul_pg_rca4_fa1_2_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_ha1_1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_2_and1 = ((u_csamul_pg_rca4_fa1_2_xor0 >> 0) & 0x01) & ((u_csamul_pg_rca4_ha1_1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_2_or0 = ((u_csamul_pg_rca4_fa1_2_and0 >> 0) & 0x01) | ((u_csamul_pg_rca4_fa1_2_and1 >> 0) & 0x01);
  u_csamul_pg_rca4_and2_2 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_csamul_pg_rca4_fa2_2_xor0 = ((u_csamul_pg_rca4_and2_2 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_and3_1 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_2_and0 = ((u_csamul_pg_rca4_and2_2 >> 0) & 0x01) & ((u_csamul_pg_rca4_and3_1 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_2_xor1 = ((u_csamul_pg_rca4_fa2_2_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_ha2_1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_2_and1 = ((u_csamul_pg_rca4_fa2_2_xor0 >> 0) & 0x01) & ((u_csamul_pg_rca4_ha2_1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_2_or0 = ((u_csamul_pg_rca4_fa2_2_and0 >> 0) & 0x01) | ((u_csamul_pg_rca4_fa2_2_and1 >> 0) & 0x01);
  u_csamul_pg_rca4_and3_2 = ((a >> 3) & 0x01) & ((b >> 2) & 0x01);
  u_csamul_pg_rca4_and0_3 = ((a >> 0) & 0x01) & ((b >> 3) & 0x01);
  u_csamul_pg_rca4_fa0_3_xor0 = ((u_csamul_pg_rca4_and0_3 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa1_2_xor1 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_3_and0 = ((u_csamul_pg_rca4_and0_3 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa1_2_xor1 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_3_xor1 = ((u_csamul_pg_rca4_fa0_3_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa0_2_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_3_and1 = ((u_csamul_pg_rca4_fa0_3_xor0 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa0_2_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa0_3_or0 = ((u_csamul_pg_rca4_fa0_3_and0 >> 0) & 0x01) | ((u_csamul_pg_rca4_fa0_3_and1 >> 0) & 0x01);
  u_csamul_pg_rca4_and1_3 = ((a >> 1) & 0x01) & ((b >> 3) & 0x01);
  u_csamul_pg_rca4_fa1_3_xor0 = ((u_csamul_pg_rca4_and1_3 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa2_2_xor1 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_3_and0 = ((u_csamul_pg_rca4_and1_3 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa2_2_xor1 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_3_xor1 = ((u_csamul_pg_rca4_fa1_3_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa1_2_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_3_and1 = ((u_csamul_pg_rca4_fa1_3_xor0 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa1_2_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa1_3_or0 = ((u_csamul_pg_rca4_fa1_3_and0 >> 0) & 0x01) | ((u_csamul_pg_rca4_fa1_3_and1 >> 0) & 0x01);
  u_csamul_pg_rca4_and2_3 = ((a >> 2) & 0x01) & ((b >> 3) & 0x01);
  u_csamul_pg_rca4_fa2_3_xor0 = ((u_csamul_pg_rca4_and2_3 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_and3_2 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_3_and0 = ((u_csamul_pg_rca4_and2_3 >> 0) & 0x01) & ((u_csamul_pg_rca4_and3_2 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_3_xor1 = ((u_csamul_pg_rca4_fa2_3_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa2_2_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_3_and1 = ((u_csamul_pg_rca4_fa2_3_xor0 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa2_2_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_fa2_3_or0 = ((u_csamul_pg_rca4_fa2_3_and0 >> 0) & 0x01) | ((u_csamul_pg_rca4_fa2_3_and1 >> 0) & 0x01);
  u_csamul_pg_rca4_and3_3 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa0_xor0 = ((u_csamul_pg_rca4_fa1_3_xor1 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa0_3_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa0_and0 = ((u_csamul_pg_rca4_fa1_3_xor1 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa0_3_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor0 = ((u_csamul_pg_rca4_fa2_3_xor1 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa1_3_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa1_and0 = ((u_csamul_pg_rca4_fa2_3_xor1 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa1_3_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor1 = ((u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_u_pg_rca4_pg_fa0_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_and1 = ((u_csamul_pg_rca4_u_pg_rca4_pg_fa0_and0 >> 0) & 0x01) & ((u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_or1 = ((u_csamul_pg_rca4_u_pg_rca4_and1 >> 0) & 0x01) | ((u_csamul_pg_rca4_u_pg_rca4_pg_fa1_and0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor0 = ((u_csamul_pg_rca4_and3_3 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_fa2_3_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa2_and0 = ((u_csamul_pg_rca4_and3_3 >> 0) & 0x01) & ((u_csamul_pg_rca4_fa2_3_or0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor1 = ((u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01) ^ ((u_csamul_pg_rca4_u_pg_rca4_or1 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_and2 = ((u_csamul_pg_rca4_u_pg_rca4_or1 >> 0) & 0x01) & ((u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01);
  u_csamul_pg_rca4_u_pg_rca4_or2 = ((u_csamul_pg_rca4_u_pg_rca4_and2 >> 0) & 0x01) | ((u_csamul_pg_rca4_u_pg_rca4_pg_fa2_and0 >> 0) & 0x01);

  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_and0_0 >> 0) & 0x01ull) << 0;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_ha0_1_xor0 >> 0) & 0x01ull) << 1;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_fa0_2_xor1 >> 0) & 0x01ull) << 2;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_fa0_3_xor1 >> 0) & 0x01ull) << 3;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_u_pg_rca4_pg_fa0_xor0 >> 0) & 0x01ull) << 4;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_u_pg_rca4_pg_fa1_xor1 >> 0) & 0x01ull) << 5;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_u_pg_rca4_pg_fa2_xor1 >> 0) & 0x01ull) << 6;
  u_csamul_pg_rca4_out |= ((u_csamul_pg_rca4_u_pg_rca4_or2 >> 0) & 0x01ull) << 7;
  return u_csamul_pg_rca4_out;
}