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

uint64_t h_u_pg_rca8(uint64_t a, uint64_t b){
  uint64_t h_u_pg_rca8_out = 0;
  uint8_t h_u_pg_rca8_pg_fa0_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa0_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa1_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa1_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa1_xor1 = 0;
  uint8_t h_u_pg_rca8_and1 = 0;
  uint8_t h_u_pg_rca8_or1 = 0;
  uint8_t h_u_pg_rca8_pg_fa2_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa2_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa2_xor1 = 0;
  uint8_t h_u_pg_rca8_and2 = 0;
  uint8_t h_u_pg_rca8_or2 = 0;
  uint8_t h_u_pg_rca8_pg_fa3_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa3_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa3_xor1 = 0;
  uint8_t h_u_pg_rca8_and3 = 0;
  uint8_t h_u_pg_rca8_or3 = 0;
  uint8_t h_u_pg_rca8_pg_fa4_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa4_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa4_xor1 = 0;
  uint8_t h_u_pg_rca8_and4 = 0;
  uint8_t h_u_pg_rca8_or4 = 0;
  uint8_t h_u_pg_rca8_pg_fa5_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa5_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa5_xor1 = 0;
  uint8_t h_u_pg_rca8_and5 = 0;
  uint8_t h_u_pg_rca8_or5 = 0;
  uint8_t h_u_pg_rca8_pg_fa6_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa6_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa6_xor1 = 0;
  uint8_t h_u_pg_rca8_and6 = 0;
  uint8_t h_u_pg_rca8_or6 = 0;
  uint8_t h_u_pg_rca8_pg_fa7_xor0 = 0;
  uint8_t h_u_pg_rca8_pg_fa7_and0 = 0;
  uint8_t h_u_pg_rca8_pg_fa7_xor1 = 0;
  uint8_t h_u_pg_rca8_and7 = 0;
  uint8_t h_u_pg_rca8_or7 = 0;

  h_u_pg_rca8_pg_fa0_xor0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa0_and0 = (pg_fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa1_xor0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_pg_rca8_pg_fa0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa1_and0 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_pg_rca8_pg_fa0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa1_xor1 = (pg_fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((h_u_pg_rca8_pg_fa0_and0 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and1 = and_gate(((h_u_pg_rca8_pg_fa0_and0 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa1_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or1 = or_gate(((h_u_pg_rca8_and1 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa1_and0 >> 0) & 0x01));
  h_u_pg_rca8_pg_fa2_xor0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_pg_rca8_or1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa2_and0 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_pg_rca8_or1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa2_xor1 = (pg_fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((h_u_pg_rca8_or1 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and2 = and_gate(((h_u_pg_rca8_or1 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa2_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or2 = or_gate(((h_u_pg_rca8_and2 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa2_and0 >> 0) & 0x01));
  h_u_pg_rca8_pg_fa3_xor0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_pg_rca8_or2 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa3_and0 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_pg_rca8_or2 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa3_xor1 = (pg_fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((h_u_pg_rca8_or2 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and3 = and_gate(((h_u_pg_rca8_or2 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or3 = or_gate(((h_u_pg_rca8_and3 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa3_and0 >> 0) & 0x01));
  h_u_pg_rca8_pg_fa4_xor0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_pg_rca8_or3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa4_and0 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_pg_rca8_or3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa4_xor1 = (pg_fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((h_u_pg_rca8_or3 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and4 = and_gate(((h_u_pg_rca8_or3 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or4 = or_gate(((h_u_pg_rca8_and4 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa4_and0 >> 0) & 0x01));
  h_u_pg_rca8_pg_fa5_xor0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_pg_rca8_or4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa5_and0 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_pg_rca8_or4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa5_xor1 = (pg_fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((h_u_pg_rca8_or4 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and5 = and_gate(((h_u_pg_rca8_or4 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or5 = or_gate(((h_u_pg_rca8_and5 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa5_and0 >> 0) & 0x01));
  h_u_pg_rca8_pg_fa6_xor0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_pg_rca8_or5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa6_and0 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_pg_rca8_or5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa6_xor1 = (pg_fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((h_u_pg_rca8_or5 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and6 = and_gate(((h_u_pg_rca8_or5 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or6 = or_gate(((h_u_pg_rca8_and6 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa6_and0 >> 0) & 0x01));
  h_u_pg_rca8_pg_fa7_xor0 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_pg_rca8_or6 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_pg_rca8_pg_fa7_and0 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_pg_rca8_or6 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_pg_rca8_pg_fa7_xor1 = (pg_fa(((a >> 7) & 0x01), ((b >> 7) & 0x01), ((h_u_pg_rca8_or6 >> 0) & 0x01)) >> 2) & 0x01;
  h_u_pg_rca8_and7 = and_gate(((h_u_pg_rca8_or6 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa7_xor0 >> 0) & 0x01));
  h_u_pg_rca8_or7 = or_gate(((h_u_pg_rca8_and7 >> 0) & 0x01), ((h_u_pg_rca8_pg_fa7_and0 >> 0) & 0x01));

  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa0_xor0 >> 0) & 0x01) << 0;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa1_xor1 >> 0) & 0x01) << 1;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa2_xor1 >> 0) & 0x01) << 2;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa3_xor1 >> 0) & 0x01) << 3;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa4_xor1 >> 0) & 0x01) << 4;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa5_xor1 >> 0) & 0x01) << 5;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa6_xor1 >> 0) & 0x01) << 6;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_pg_fa7_xor1 >> 0) & 0x01) << 7;
  h_u_pg_rca8_out |= ((h_u_pg_rca8_or7 >> 0) & 0x01) << 8;
  return h_u_pg_rca8_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 256; i++){
    for (int j = 0; j < 256; j++){
      assert((i + j) == h_u_pg_rca8(i,j));
    }
  }
  return 0;
}