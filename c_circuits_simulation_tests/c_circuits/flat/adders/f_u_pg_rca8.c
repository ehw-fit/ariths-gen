#include <stdio.h>
#include <stdint.h>

uint64_t f_u_pg_rca8(uint64_t a, uint64_t b){
  uint64_t f_u_pg_rca8_out = 0;
  uint8_t f_u_pg_rca8_pg_fa0_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa0_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa1_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa1_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa1_xor1 = 0;
  uint8_t f_u_pg_rca8_and1 = 0;
  uint8_t f_u_pg_rca8_or1 = 0;
  uint8_t f_u_pg_rca8_pg_fa2_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa2_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa2_xor1 = 0;
  uint8_t f_u_pg_rca8_and2 = 0;
  uint8_t f_u_pg_rca8_or2 = 0;
  uint8_t f_u_pg_rca8_pg_fa3_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa3_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa3_xor1 = 0;
  uint8_t f_u_pg_rca8_and3 = 0;
  uint8_t f_u_pg_rca8_or3 = 0;
  uint8_t f_u_pg_rca8_pg_fa4_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa4_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa4_xor1 = 0;
  uint8_t f_u_pg_rca8_and4 = 0;
  uint8_t f_u_pg_rca8_or4 = 0;
  uint8_t f_u_pg_rca8_pg_fa5_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa5_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa5_xor1 = 0;
  uint8_t f_u_pg_rca8_and5 = 0;
  uint8_t f_u_pg_rca8_or5 = 0;
  uint8_t f_u_pg_rca8_pg_fa6_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa6_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa6_xor1 = 0;
  uint8_t f_u_pg_rca8_and6 = 0;
  uint8_t f_u_pg_rca8_or6 = 0;
  uint8_t f_u_pg_rca8_pg_fa7_xor0 = 0;
  uint8_t f_u_pg_rca8_pg_fa7_and0 = 0;
  uint8_t f_u_pg_rca8_pg_fa7_xor1 = 0;
  uint8_t f_u_pg_rca8_and7 = 0;
  uint8_t f_u_pg_rca8_or7 = 0;

  f_u_pg_rca8_pg_fa0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_u_pg_rca8_pg_fa0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_u_pg_rca8_pg_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_u_pg_rca8_pg_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_u_pg_rca8_pg_fa1_xor1 = ((f_u_pg_rca8_pg_fa1_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_pg_fa0_and0 >> 0) & 0x01);
  f_u_pg_rca8_and1 = ((f_u_pg_rca8_pg_fa0_and0 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa1_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or1 = ((f_u_pg_rca8_and1 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa1_and0 >> 0) & 0x01);
  f_u_pg_rca8_pg_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_u_pg_rca8_pg_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_u_pg_rca8_pg_fa2_xor1 = ((f_u_pg_rca8_pg_fa2_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_or1 >> 0) & 0x01);
  f_u_pg_rca8_and2 = ((f_u_pg_rca8_or1 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa2_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or2 = ((f_u_pg_rca8_and2 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa2_and0 >> 0) & 0x01);
  f_u_pg_rca8_pg_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_u_pg_rca8_pg_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_u_pg_rca8_pg_fa3_xor1 = ((f_u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_or2 >> 0) & 0x01);
  f_u_pg_rca8_and3 = ((f_u_pg_rca8_or2 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or3 = ((f_u_pg_rca8_and3 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa3_and0 >> 0) & 0x01);
  f_u_pg_rca8_pg_fa4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  f_u_pg_rca8_pg_fa4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  f_u_pg_rca8_pg_fa4_xor1 = ((f_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_or3 >> 0) & 0x01);
  f_u_pg_rca8_and4 = ((f_u_pg_rca8_or3 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or4 = ((f_u_pg_rca8_and4 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa4_and0 >> 0) & 0x01);
  f_u_pg_rca8_pg_fa5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  f_u_pg_rca8_pg_fa5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_u_pg_rca8_pg_fa5_xor1 = ((f_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_or4 >> 0) & 0x01);
  f_u_pg_rca8_and5 = ((f_u_pg_rca8_or4 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or5 = ((f_u_pg_rca8_and5 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa5_and0 >> 0) & 0x01);
  f_u_pg_rca8_pg_fa6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  f_u_pg_rca8_pg_fa6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_u_pg_rca8_pg_fa6_xor1 = ((f_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_or5 >> 0) & 0x01);
  f_u_pg_rca8_and6 = ((f_u_pg_rca8_or5 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or6 = ((f_u_pg_rca8_and6 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa6_and0 >> 0) & 0x01);
  f_u_pg_rca8_pg_fa7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_u_pg_rca8_pg_fa7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_u_pg_rca8_pg_fa7_xor1 = ((f_u_pg_rca8_pg_fa7_xor0 >> 0) & 0x01) ^ ((f_u_pg_rca8_or6 >> 0) & 0x01);
  f_u_pg_rca8_and7 = ((f_u_pg_rca8_or6 >> 0) & 0x01) & ((f_u_pg_rca8_pg_fa7_xor0 >> 0) & 0x01);
  f_u_pg_rca8_or7 = ((f_u_pg_rca8_and7 >> 0) & 0x01) | ((f_u_pg_rca8_pg_fa7_and0 >> 0) & 0x01);

  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa0_xor0 >> 0) & 0x01) << 0;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa1_xor1 >> 0) & 0x01) << 1;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa2_xor1 >> 0) & 0x01) << 2;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa3_xor1 >> 0) & 0x01) << 3;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa4_xor1 >> 0) & 0x01) << 4;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa5_xor1 >> 0) & 0x01) << 5;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa6_xor1 >> 0) & 0x01) << 6;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_pg_fa7_xor1 >> 0) & 0x01) << 7;
  f_u_pg_rca8_out |= ((f_u_pg_rca8_or7 >> 0) & 0x01) << 8;
  return f_u_pg_rca8_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 256; i++){
    for (int j = 0; j < 256; j++){
      assert((i + j) == f_u_pg_rca8(i,j));
    }
  }
  return 0;
}