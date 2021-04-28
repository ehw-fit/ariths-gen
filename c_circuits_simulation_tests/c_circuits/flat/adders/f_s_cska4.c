#include <stdio.h>
#include <stdint.h>

int64_t f_s_cska4(int64_t a, int64_t b){
  uint8_t f_s_cska4_out = 0;
  uint8_t f_s_cska4_xor0 = 0;
  uint8_t f_s_cska4_ha0_xor0 = 0;
  uint8_t f_s_cska4_ha0_and0 = 0;
  uint8_t f_s_cska4_xor1 = 0;
  uint8_t f_s_cska4_fa0_xor0 = 0;
  uint8_t f_s_cska4_fa0_and0 = 0;
  uint8_t f_s_cska4_fa0_xor1 = 0;
  uint8_t f_s_cska4_fa0_and1 = 0;
  uint8_t f_s_cska4_fa0_or0 = 0;
  uint8_t f_s_cska4_xor2 = 0;
  uint8_t f_s_cska4_fa1_xor0 = 0;
  uint8_t f_s_cska4_fa1_and0 = 0;
  uint8_t f_s_cska4_fa1_xor1 = 0;
  uint8_t f_s_cska4_fa1_and1 = 0;
  uint8_t f_s_cska4_fa1_or0 = 0;
  uint8_t f_s_cska4_xor3 = 0;
  uint8_t f_s_cska4_fa2_xor0 = 0;
  uint8_t f_s_cska4_fa2_and0 = 0;
  uint8_t f_s_cska4_fa2_xor1 = 0;
  uint8_t f_s_cska4_fa2_and1 = 0;
  uint8_t f_s_cska4_fa2_or0 = 0;
  uint8_t f_s_cska4_and_propagate00 = 0;
  uint8_t f_s_cska4_and_propagate01 = 0;
  uint8_t f_s_cska4_and_propagate02 = 0;
  uint8_t f_s_cska4_mux2to10_not0 = 0;
  uint8_t f_s_cska4_mux2to10_and1 = 0;
  uint8_t f_s_cska4_xor4 = 0;
  uint8_t f_s_cska4_xor5 = 0;

  f_s_cska4_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_s_cska4_ha0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_s_cska4_ha0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_s_cska4_xor1 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_s_cska4_fa0_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_s_cska4_fa0_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_s_cska4_fa0_xor1 = ((f_s_cska4_fa0_xor0 >> 0) & 0x01) ^ ((f_s_cska4_ha0_and0 >> 0) & 0x01);
  f_s_cska4_fa0_and1 = ((f_s_cska4_fa0_xor0 >> 0) & 0x01) & ((f_s_cska4_ha0_and0 >> 0) & 0x01);
  f_s_cska4_fa0_or0 = ((f_s_cska4_fa0_and0 >> 0) & 0x01) | ((f_s_cska4_fa0_and1 >> 0) & 0x01);
  f_s_cska4_xor2 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_s_cska4_fa1_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_s_cska4_fa1_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_s_cska4_fa1_xor1 = ((f_s_cska4_fa1_xor0 >> 0) & 0x01) ^ ((f_s_cska4_fa0_or0 >> 0) & 0x01);
  f_s_cska4_fa1_and1 = ((f_s_cska4_fa1_xor0 >> 0) & 0x01) & ((f_s_cska4_fa0_or0 >> 0) & 0x01);
  f_s_cska4_fa1_or0 = ((f_s_cska4_fa1_and0 >> 0) & 0x01) | ((f_s_cska4_fa1_and1 >> 0) & 0x01);
  f_s_cska4_xor3 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_s_cska4_fa2_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_s_cska4_fa2_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_s_cska4_fa2_xor1 = ((f_s_cska4_fa2_xor0 >> 0) & 0x01) ^ ((f_s_cska4_fa1_or0 >> 0) & 0x01);
  f_s_cska4_fa2_and1 = ((f_s_cska4_fa2_xor0 >> 0) & 0x01) & ((f_s_cska4_fa1_or0 >> 0) & 0x01);
  f_s_cska4_fa2_or0 = ((f_s_cska4_fa2_and0 >> 0) & 0x01) | ((f_s_cska4_fa2_and1 >> 0) & 0x01);
  f_s_cska4_and_propagate00 = ((f_s_cska4_xor0 >> 0) & 0x01) & ((f_s_cska4_xor2 >> 0) & 0x01);
  f_s_cska4_and_propagate01 = ((f_s_cska4_xor1 >> 0) & 0x01) & ((f_s_cska4_xor3 >> 0) & 0x01);
  f_s_cska4_and_propagate02 = ((f_s_cska4_and_propagate00 >> 0) & 0x01) & ((f_s_cska4_and_propagate01 >> 0) & 0x01);
  f_s_cska4_mux2to10_not0 = ~(((f_s_cska4_and_propagate02 >> 0) & 0x01)) & 0x01;
  f_s_cska4_mux2to10_and1 = ((f_s_cska4_fa2_or0 >> 0) & 0x01) & ((f_s_cska4_mux2to10_not0 >> 0) & 0x01);
  f_s_cska4_xor4 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_s_cska4_xor5 = ((f_s_cska4_xor4 >> 0) & 0x01) ^ ((f_s_cska4_mux2to10_and1 >> 0) & 0x01);

  f_s_cska4_out |= ((f_s_cska4_ha0_xor0 >> 0) & 0x01) << 0;
  f_s_cska4_out |= ((f_s_cska4_fa0_xor1 >> 0) & 0x01) << 1;
  f_s_cska4_out |= ((f_s_cska4_fa1_xor1 >> 0) & 0x01) << 2;
  f_s_cska4_out |= ((f_s_cska4_fa2_xor1 >> 0) & 0x01) << 3;
  f_s_cska4_out |= ((f_s_cska4_xor5 >> 0) & 0x01) << 4;
  return f_s_cska4_out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -8; i < 8; i++){
    for (int j = -8; j < 8; j++){
      result = i + j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 32 + result;  
      }
      
      assert(result == (int)f_s_cska4(i,j));
    }
  }
  return 0;
}