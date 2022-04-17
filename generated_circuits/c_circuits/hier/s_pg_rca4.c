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

uint8_t pg_fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t pg_fa_out = 0;
  uint8_t pg_fa_xor0 = 0;
  uint8_t pg_fa_and0 = 0;
  uint8_t pg_fa_xor1 = 0;

  pg_fa_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  pg_fa_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  pg_fa_xor1 = xor_gate(((pg_fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));

  pg_fa_out |= ((pg_fa_xor0 >> 0) & 0x01ull) << 0;
  pg_fa_out |= ((pg_fa_and0 >> 0) & 0x01ull) << 1;
  pg_fa_out |= ((pg_fa_xor1 >> 0) & 0x01ull) << 2;
  return pg_fa_out;
}

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

  s_pg_rca4_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  s_pg_rca4_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  s_pg_rca4_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_pg_rca4_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  s_pg_rca4_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_pg_rca4_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  s_pg_rca4_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((s_pg_rca4_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  s_pg_rca4_and1 = and_gate(((s_pg_rca4_pg_fa0_and0 >> 0) & 0x01), ((s_pg_rca4_pg_fa1_xor0 >> 0) & 0x01));
  s_pg_rca4_or1 = or_gate(((s_pg_rca4_and1 >> 0) & 0x01), ((s_pg_rca4_pg_fa1_and0 >> 0) & 0x01));
  s_pg_rca4_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_pg_rca4_or1 >> 0) & 0x01)) >> 0) & 0x01;
  s_pg_rca4_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_pg_rca4_or1 >> 0) & 0x01)) >> 1) & 0x01;
  s_pg_rca4_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((s_pg_rca4_or1 >> 0) & 0x01)) >> 2) & 0x01;
  s_pg_rca4_and2 = and_gate(((s_pg_rca4_or1 >> 0) & 0x01), ((s_pg_rca4_pg_fa2_xor0 >> 0) & 0x01));
  s_pg_rca4_or2 = or_gate(((s_pg_rca4_and2 >> 0) & 0x01), ((s_pg_rca4_pg_fa2_and0 >> 0) & 0x01));
  s_pg_rca4_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_pg_rca4_or2 >> 0) & 0x01)) >> 0) & 0x01;
  s_pg_rca4_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_pg_rca4_or2 >> 0) & 0x01)) >> 1) & 0x01;
  s_pg_rca4_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((s_pg_rca4_or2 >> 0) & 0x01)) >> 2) & 0x01;
  s_pg_rca4_and3 = and_gate(((s_pg_rca4_or2 >> 0) & 0x01), ((s_pg_rca4_pg_fa3_xor0 >> 0) & 0x01));
  s_pg_rca4_or3 = or_gate(((s_pg_rca4_and3 >> 0) & 0x01), ((s_pg_rca4_pg_fa3_and0 >> 0) & 0x01));
  s_pg_rca4_xor0 = xor_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_pg_rca4_xor1 = xor_gate(((s_pg_rca4_xor0 >> 0) & 0x01), ((s_pg_rca4_or3 >> 0) & 0x01));

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