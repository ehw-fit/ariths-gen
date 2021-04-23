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

  pg_fa_out |= ((pg_fa_xor0 >> 0) & 0x01) << 0;
  pg_fa_out |= ((pg_fa_and0 >> 0) & 0x01) << 1;
  pg_fa_out |= ((pg_fa_xor1 >> 0) & 0x01) << 2;
  return pg_fa_out;
}

uint64_t h_u_pg_rca12(uint64_t a, uint64_t b){
  uint64_t h_u_pg_rca12_out = 0;
  uint8_t h_u_pg_rca12_pg_fa0_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa0_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa1_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa1_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa1_xor1 = 0;
  uint8_t h_u_pg_rca12_and1 = 0;
  uint8_t h_u_pg_rca12_or1 = 0;
  uint8_t h_u_pg_rca12_pg_fa2_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa2_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa2_xor1 = 0;
  uint8_t h_u_pg_rca12_and2 = 0;
  uint8_t h_u_pg_rca12_or2 = 0;
  uint8_t h_u_pg_rca12_pg_fa3_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa3_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa3_xor1 = 0;
  uint8_t h_u_pg_rca12_and3 = 0;
  uint8_t h_u_pg_rca12_or3 = 0;
  uint8_t h_u_pg_rca12_pg_fa4_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa4_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa4_xor1 = 0;
  uint8_t h_u_pg_rca12_and4 = 0;
  uint8_t h_u_pg_rca12_or4 = 0;
  uint8_t h_u_pg_rca12_pg_fa5_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa5_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa5_xor1 = 0;
  uint8_t h_u_pg_rca12_and5 = 0;
  uint8_t h_u_pg_rca12_or5 = 0;
  uint8_t h_u_pg_rca12_pg_fa6_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa6_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa6_xor1 = 0;
  uint8_t h_u_pg_rca12_and6 = 0;
  uint8_t h_u_pg_rca12_or6 = 0;
  uint8_t h_u_pg_rca12_pg_fa7_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa7_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa7_xor1 = 0;
  uint8_t h_u_pg_rca12_and7 = 0;
  uint8_t h_u_pg_rca12_or7 = 0;
  uint8_t h_u_pg_rca12_pg_fa8_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa8_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa8_xor1 = 0;
  uint8_t h_u_pg_rca12_and8 = 0;
  uint8_t h_u_pg_rca12_or8 = 0;
  uint8_t h_u_pg_rca12_pg_fa9_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa9_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa9_xor1 = 0;
  uint8_t h_u_pg_rca12_and9 = 0;
  uint8_t h_u_pg_rca12_or9 = 0;
  uint8_t h_u_pg_rca12_pg_fa10_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa10_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa10_xor1 = 0;
  uint8_t h_u_pg_rca12_and10 = 0;
  uint8_t h_u_pg_rca12_or10 = 0;
  uint8_t h_u_pg_rca12_pg_fa11_xor0 = 0;
  uint8_t h_u_pg_rca12_pg_fa11_and0 = 0;
  uint8_t h_u_pg_rca12_pg_fa11_xor1 = 0;
  uint8_t h_u_pg_rca12_and11 = 0;
  uint8_t h_u_pg_rca12_or11 = 0;

  h_u_pg_rca12_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_pg_rca12_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_pg_rca12_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_pg_rca12_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and1 = and_gate(((h_u_pg_rca12_pg_fa0_and0 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa1_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or1 = or_gate(((h_u_pg_rca12_and1 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa1_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_pg_rca12_or1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_pg_rca12_or1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_pg_rca12_or1 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and2 = and_gate(((h_u_pg_rca12_or1 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa2_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or2 = or_gate(((h_u_pg_rca12_and2 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa2_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_pg_rca12_or2 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_pg_rca12_or2 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_pg_rca12_or2 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and3 = and_gate(((h_u_pg_rca12_or2 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa3_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or3 = or_gate(((h_u_pg_rca12_and3 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa3_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa4_xor0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_pg_rca12_or3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa4_and0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_pg_rca12_or3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa4_xor1 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_pg_rca12_or3 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and4 = and_gate(((h_u_pg_rca12_or3 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa4_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or4 = or_gate(((h_u_pg_rca12_and4 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa4_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa5_xor0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_pg_rca12_or4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa5_and0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_pg_rca12_or4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa5_xor1 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_pg_rca12_or4 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and5 = and_gate(((h_u_pg_rca12_or4 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa5_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or5 = or_gate(((h_u_pg_rca12_and5 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa5_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa6_xor0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_pg_rca12_or5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa6_and0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_pg_rca12_or5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa6_xor1 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_pg_rca12_or5 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and6 = and_gate(((h_u_pg_rca12_or5 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa6_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or6 = or_gate(((h_u_pg_rca12_and6 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa6_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa7_xor0 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_pg_rca12_or6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa7_and0 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_pg_rca12_or6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa7_xor1 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_pg_rca12_or6 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and7 = and_gate(((h_u_pg_rca12_or6 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa7_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or7 = or_gate(((h_u_pg_rca12_and7 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa7_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa8_xor0 = (pg_fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((h_u_pg_rca12_or7 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa8_and0 = (pg_fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((h_u_pg_rca12_or7 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa8_xor1 = (pg_fa(((a >> 8) & 0x01), ((b >> 8) & 0x01), ((h_u_pg_rca12_or7 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and8 = and_gate(((h_u_pg_rca12_or7 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa8_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or8 = or_gate(((h_u_pg_rca12_and8 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa8_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa9_xor0 = (pg_fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((h_u_pg_rca12_or8 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa9_and0 = (pg_fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((h_u_pg_rca12_or8 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa9_xor1 = (pg_fa(((a >> 9) & 0x01), ((b >> 9) & 0x01), ((h_u_pg_rca12_or8 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and9 = and_gate(((h_u_pg_rca12_or8 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa9_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or9 = or_gate(((h_u_pg_rca12_and9 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa9_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa10_xor0 = (pg_fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((h_u_pg_rca12_or9 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa10_and0 = (pg_fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((h_u_pg_rca12_or9 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa10_xor1 = (pg_fa(((a >> 10) & 0x01), ((b >> 10) & 0x01), ((h_u_pg_rca12_or9 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and10 = and_gate(((h_u_pg_rca12_or9 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa10_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or10 = or_gate(((h_u_pg_rca12_and10 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa10_and0 >> 0) & 0x01));
  h_u_pg_rca12_pg_fa11_xor0 = (pg_fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((h_u_pg_rca12_or10 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca12_pg_fa11_and0 = (pg_fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((h_u_pg_rca12_or10 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca12_pg_fa11_xor1 = (pg_fa(((a >> 11) & 0x01), ((b >> 11) & 0x01), ((h_u_pg_rca12_or10 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca12_and11 = and_gate(((h_u_pg_rca12_or10 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa11_xor0 >> 0) & 0x01));
  h_u_pg_rca12_or11 = or_gate(((h_u_pg_rca12_and11 >> 0) & 0x01), ((h_u_pg_rca12_pg_fa11_and0 >> 0) & 0x01));

  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa0_xor0 >> 0) & 0x01) << 0;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa1_xor1 >> 0) & 0x01) << 1;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa2_xor1 >> 0) & 0x01) << 2;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa3_xor1 >> 0) & 0x01) << 3;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa4_xor1 >> 0) & 0x01) << 4;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa5_xor1 >> 0) & 0x01) << 5;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa6_xor1 >> 0) & 0x01) << 6;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa7_xor1 >> 0) & 0x01) << 7;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa8_xor1 >> 0) & 0x01) << 8;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa9_xor1 >> 0) & 0x01) << 9;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa10_xor1 >> 0) & 0x01) << 10;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_pg_fa11_xor1 >> 0) & 0x01) << 11;
  h_u_pg_rca12_out |= ((h_u_pg_rca12_or11 >> 0) & 0x01) << 12;
  return h_u_pg_rca12_out;
}