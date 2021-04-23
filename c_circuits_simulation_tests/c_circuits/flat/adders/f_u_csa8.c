#include <stdio.h>
#include <stdint.h>

uint64_t f_u_csa8(uint64_t a, uint64_t b){
  uint64_t f_u_csa8_out = 0;
  uint8_t f_u_csa8_xor0 = 0;
  uint8_t f_u_csa8_ha0_xor0 = 0;
  uint8_t f_u_csa8_ha0_and0 = 0;
  uint8_t f_u_csa8_xor1 = 0;
  uint8_t f_u_csa8_fa0_xor0 = 0;
  uint8_t f_u_csa8_fa0_and0 = 0;
  uint8_t f_u_csa8_fa0_xor1 = 0;
  uint8_t f_u_csa8_fa0_and1 = 0;
  uint8_t f_u_csa8_fa0_or0 = 0;
  uint8_t f_u_csa8_xor2 = 0;
  uint8_t f_u_csa8_fa1_xor0 = 0;
  uint8_t f_u_csa8_fa1_and0 = 0;
  uint8_t f_u_csa8_fa1_xor1 = 0;
  uint8_t f_u_csa8_fa1_and1 = 0;
  uint8_t f_u_csa8_fa1_or0 = 0;
  uint8_t f_u_csa8_xor3 = 0;
  uint8_t f_u_csa8_fa2_xor0 = 0;
  uint8_t f_u_csa8_fa2_and0 = 0;
  uint8_t f_u_csa8_fa2_xor1 = 0;
  uint8_t f_u_csa8_fa2_and1 = 0;
  uint8_t f_u_csa8_fa2_or0 = 0;
  uint8_t f_u_csa8_and_propagate00 = 0;
  uint8_t f_u_csa8_and_propagate01 = 0;
  uint8_t f_u_csa8_and_propagate02 = 0;
  uint8_t f_u_csa8_mux2to10_not0 = 0;
  uint8_t f_u_csa8_mux2to10_and1 = 0;
  uint8_t f_u_csa8_xor4 = 0;
  uint8_t f_u_csa8_fa3_xor0 = 0;
  uint8_t f_u_csa8_fa3_and0 = 0;
  uint8_t f_u_csa8_fa3_xor1 = 0;
  uint8_t f_u_csa8_fa3_and1 = 0;
  uint8_t f_u_csa8_fa3_or0 = 0;
  uint8_t f_u_csa8_xor5 = 0;
  uint8_t f_u_csa8_fa4_xor0 = 0;
  uint8_t f_u_csa8_fa4_and0 = 0;
  uint8_t f_u_csa8_fa4_xor1 = 0;
  uint8_t f_u_csa8_fa4_and1 = 0;
  uint8_t f_u_csa8_fa4_or0 = 0;
  uint8_t f_u_csa8_xor6 = 0;
  uint8_t f_u_csa8_fa5_xor0 = 0;
  uint8_t f_u_csa8_fa5_and0 = 0;
  uint8_t f_u_csa8_fa5_xor1 = 0;
  uint8_t f_u_csa8_fa5_and1 = 0;
  uint8_t f_u_csa8_fa5_or0 = 0;
  uint8_t f_u_csa8_xor7 = 0;
  uint8_t f_u_csa8_fa6_xor0 = 0;
  uint8_t f_u_csa8_fa6_and0 = 0;
  uint8_t f_u_csa8_fa6_xor1 = 0;
  uint8_t f_u_csa8_fa6_and1 = 0;
  uint8_t f_u_csa8_fa6_or0 = 0;
  uint8_t f_u_csa8_and_propagate13 = 0;
  uint8_t f_u_csa8_and_propagate14 = 0;
  uint8_t f_u_csa8_and_propagate15 = 0;
  uint8_t f_u_csa8_mux2to11_and0 = 0;
  uint8_t f_u_csa8_mux2to11_not0 = 0;
  uint8_t f_u_csa8_mux2to11_and1 = 0;
  uint8_t f_u_csa8_mux2to11_xor0 = 0;

  f_u_csa8_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_u_csa8_ha0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_u_csa8_ha0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_u_csa8_xor1 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_u_csa8_fa0_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_u_csa8_fa0_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_u_csa8_fa0_xor1 = ((f_u_csa8_fa0_xor0 >> 0) & 0x01) ^ ((f_u_csa8_ha0_and0 >> 0) & 0x01);
  f_u_csa8_fa0_and1 = ((f_u_csa8_fa0_xor0 >> 0) & 0x01) & ((f_u_csa8_ha0_and0 >> 0) & 0x01);
  f_u_csa8_fa0_or0 = ((f_u_csa8_fa0_and0 >> 0) & 0x01) | ((f_u_csa8_fa0_and1 >> 0) & 0x01);
  f_u_csa8_xor2 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_u_csa8_fa1_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_u_csa8_fa1_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_u_csa8_fa1_xor1 = ((f_u_csa8_fa1_xor0 >> 0) & 0x01) ^ ((f_u_csa8_fa0_or0 >> 0) & 0x01);
  f_u_csa8_fa1_and1 = ((f_u_csa8_fa1_xor0 >> 0) & 0x01) & ((f_u_csa8_fa0_or0 >> 0) & 0x01);
  f_u_csa8_fa1_or0 = ((f_u_csa8_fa1_and0 >> 0) & 0x01) | ((f_u_csa8_fa1_and1 >> 0) & 0x01);
  f_u_csa8_xor3 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_u_csa8_fa2_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_u_csa8_fa2_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_u_csa8_fa2_xor1 = ((f_u_csa8_fa2_xor0 >> 0) & 0x01) ^ ((f_u_csa8_fa1_or0 >> 0) & 0x01);
  f_u_csa8_fa2_and1 = ((f_u_csa8_fa2_xor0 >> 0) & 0x01) & ((f_u_csa8_fa1_or0 >> 0) & 0x01);
  f_u_csa8_fa2_or0 = ((f_u_csa8_fa2_and0 >> 0) & 0x01) | ((f_u_csa8_fa2_and1 >> 0) & 0x01);
  f_u_csa8_and_propagate00 = ((f_u_csa8_xor0 >> 0) & 0x01) & ((f_u_csa8_xor2 >> 0) & 0x01);
  f_u_csa8_and_propagate01 = ((f_u_csa8_xor1 >> 0) & 0x01) & ((f_u_csa8_xor3 >> 0) & 0x01);
  f_u_csa8_and_propagate02 = ((f_u_csa8_and_propagate00 >> 0) & 0x01) & ((f_u_csa8_and_propagate01 >> 0) & 0x01);
  f_u_csa8_mux2to10_not0 = ~(((f_u_csa8_and_propagate02 >> 0) & 0x01)) & 0x01;
  f_u_csa8_mux2to10_and1 = ((f_u_csa8_fa2_or0 >> 0) & 0x01) & ((f_u_csa8_mux2to10_not0 >> 0) & 0x01);
  f_u_csa8_xor4 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  f_u_csa8_fa3_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  f_u_csa8_fa3_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  f_u_csa8_fa3_xor1 = ((f_u_csa8_fa3_xor0 >> 0) & 0x01) ^ ((f_u_csa8_mux2to10_and1 >> 0) & 0x01);
  f_u_csa8_fa3_and1 = ((f_u_csa8_fa3_xor0 >> 0) & 0x01) & ((f_u_csa8_mux2to10_and1 >> 0) & 0x01);
  f_u_csa8_fa3_or0 = ((f_u_csa8_fa3_and0 >> 0) & 0x01) | ((f_u_csa8_fa3_and1 >> 0) & 0x01);
  f_u_csa8_xor5 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  f_u_csa8_fa4_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  f_u_csa8_fa4_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_u_csa8_fa4_xor1 = ((f_u_csa8_fa4_xor0 >> 0) & 0x01) ^ ((f_u_csa8_fa3_or0 >> 0) & 0x01);
  f_u_csa8_fa4_and1 = ((f_u_csa8_fa4_xor0 >> 0) & 0x01) & ((f_u_csa8_fa3_or0 >> 0) & 0x01);
  f_u_csa8_fa4_or0 = ((f_u_csa8_fa4_and0 >> 0) & 0x01) | ((f_u_csa8_fa4_and1 >> 0) & 0x01);
  f_u_csa8_xor6 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  f_u_csa8_fa5_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  f_u_csa8_fa5_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_u_csa8_fa5_xor1 = ((f_u_csa8_fa5_xor0 >> 0) & 0x01) ^ ((f_u_csa8_fa4_or0 >> 0) & 0x01);
  f_u_csa8_fa5_and1 = ((f_u_csa8_fa5_xor0 >> 0) & 0x01) & ((f_u_csa8_fa4_or0 >> 0) & 0x01);
  f_u_csa8_fa5_or0 = ((f_u_csa8_fa5_and0 >> 0) & 0x01) | ((f_u_csa8_fa5_and1 >> 0) & 0x01);
  f_u_csa8_xor7 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_u_csa8_fa6_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_u_csa8_fa6_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_u_csa8_fa6_xor1 = ((f_u_csa8_fa6_xor0 >> 0) & 0x01) ^ ((f_u_csa8_fa5_or0 >> 0) & 0x01);
  f_u_csa8_fa6_and1 = ((f_u_csa8_fa6_xor0 >> 0) & 0x01) & ((f_u_csa8_fa5_or0 >> 0) & 0x01);
  f_u_csa8_fa6_or0 = ((f_u_csa8_fa6_and0 >> 0) & 0x01) | ((f_u_csa8_fa6_and1 >> 0) & 0x01);
  f_u_csa8_and_propagate13 = ((f_u_csa8_xor4 >> 0) & 0x01) & ((f_u_csa8_xor6 >> 0) & 0x01);
  f_u_csa8_and_propagate14 = ((f_u_csa8_xor5 >> 0) & 0x01) & ((f_u_csa8_xor7 >> 0) & 0x01);
  f_u_csa8_and_propagate15 = ((f_u_csa8_and_propagate13 >> 0) & 0x01) & ((f_u_csa8_and_propagate14 >> 0) & 0x01);
  f_u_csa8_mux2to11_and0 = ((f_u_csa8_mux2to10_and1 >> 0) & 0x01) & ((f_u_csa8_and_propagate15 >> 0) & 0x01);
  f_u_csa8_mux2to11_not0 = ~(((f_u_csa8_and_propagate15 >> 0) & 0x01)) & 0x01;
  f_u_csa8_mux2to11_and1 = ((f_u_csa8_fa6_or0 >> 0) & 0x01) & ((f_u_csa8_mux2to11_not0 >> 0) & 0x01);
  f_u_csa8_mux2to11_xor0 = ((f_u_csa8_mux2to11_and0 >> 0) & 0x01) ^ ((f_u_csa8_mux2to11_and1 >> 0) & 0x01);

  f_u_csa8_out |= ((f_u_csa8_ha0_xor0 >> 0) & 0x01) << 0;
  f_u_csa8_out |= ((f_u_csa8_fa0_xor1 >> 0) & 0x01) << 1;
  f_u_csa8_out |= ((f_u_csa8_fa1_xor1 >> 0) & 0x01) << 2;
  f_u_csa8_out |= ((f_u_csa8_fa2_xor1 >> 0) & 0x01) << 3;
  f_u_csa8_out |= ((f_u_csa8_fa3_xor1 >> 0) & 0x01) << 4;
  f_u_csa8_out |= ((f_u_csa8_fa4_xor1 >> 0) & 0x01) << 5;
  f_u_csa8_out |= ((f_u_csa8_fa5_xor1 >> 0) & 0x01) << 6;
  f_u_csa8_out |= ((f_u_csa8_fa6_xor1 >> 0) & 0x01) << 7;
  f_u_csa8_out |= ((f_u_csa8_mux2to11_xor0 >> 0) & 0x01) << 8;
  return f_u_csa8_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 256; i++){
    for (int j = 0; j < 256; j++){
      assert((i + j) == f_u_csa8(i,j));
    }
  }
  return 0;
}