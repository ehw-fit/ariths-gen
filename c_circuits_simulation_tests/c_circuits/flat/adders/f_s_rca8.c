#include <stdio.h>
#include <stdint.h>

int64_t f_s_rca8(int64_t a, int64_t b){
  uint64_t f_s_rca8_out = 0;
  uint8_t f_s_rca8_ha_xor0 = 0;
  uint8_t f_s_rca8_ha_and0 = 0;
  uint8_t f_s_rca8_fa1_xor0 = 0;
  uint8_t f_s_rca8_fa1_and0 = 0;
  uint8_t f_s_rca8_fa1_xor1 = 0;
  uint8_t f_s_rca8_fa1_and1 = 0;
  uint8_t f_s_rca8_fa1_or0 = 0;
  uint8_t f_s_rca8_fa2_xor0 = 0;
  uint8_t f_s_rca8_fa2_and0 = 0;
  uint8_t f_s_rca8_fa2_xor1 = 0;
  uint8_t f_s_rca8_fa2_and1 = 0;
  uint8_t f_s_rca8_fa2_or0 = 0;
  uint8_t f_s_rca8_fa3_xor0 = 0;
  uint8_t f_s_rca8_fa3_and0 = 0;
  uint8_t f_s_rca8_fa3_xor1 = 0;
  uint8_t f_s_rca8_fa3_and1 = 0;
  uint8_t f_s_rca8_fa3_or0 = 0;
  uint8_t f_s_rca8_fa4_xor0 = 0;
  uint8_t f_s_rca8_fa4_and0 = 0;
  uint8_t f_s_rca8_fa4_xor1 = 0;
  uint8_t f_s_rca8_fa4_and1 = 0;
  uint8_t f_s_rca8_fa4_or0 = 0;
  uint8_t f_s_rca8_fa5_xor0 = 0;
  uint8_t f_s_rca8_fa5_and0 = 0;
  uint8_t f_s_rca8_fa5_xor1 = 0;
  uint8_t f_s_rca8_fa5_and1 = 0;
  uint8_t f_s_rca8_fa5_or0 = 0;
  uint8_t f_s_rca8_fa6_xor0 = 0;
  uint8_t f_s_rca8_fa6_and0 = 0;
  uint8_t f_s_rca8_fa6_xor1 = 0;
  uint8_t f_s_rca8_fa6_and1 = 0;
  uint8_t f_s_rca8_fa6_or0 = 0;
  uint8_t f_s_rca8_fa7_xor0 = 0;
  uint8_t f_s_rca8_fa7_and0 = 0;
  uint8_t f_s_rca8_fa7_xor1 = 0;
  uint8_t f_s_rca8_fa7_and1 = 0;
  uint8_t f_s_rca8_fa7_or0 = 0;
  uint8_t f_s_rca8_xor0 = 0;
  uint8_t f_s_rca8_xor1 = 0;

  f_s_rca8_ha_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_s_rca8_ha_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_s_rca8_fa1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_s_rca8_fa1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_s_rca8_fa1_xor1 = ((f_s_rca8_fa1_xor0 >> 0) & 0x01) ^ ((f_s_rca8_ha_and0 >> 0) & 0x01);
  f_s_rca8_fa1_and1 = ((f_s_rca8_fa1_xor0 >> 0) & 0x01) & ((f_s_rca8_ha_and0 >> 0) & 0x01);
  f_s_rca8_fa1_or0 = ((f_s_rca8_fa1_and0 >> 0) & 0x01) | ((f_s_rca8_fa1_and1 >> 0) & 0x01);
  f_s_rca8_fa2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_s_rca8_fa2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_s_rca8_fa2_xor1 = ((f_s_rca8_fa2_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa1_or0 >> 0) & 0x01);
  f_s_rca8_fa2_and1 = ((f_s_rca8_fa2_xor0 >> 0) & 0x01) & ((f_s_rca8_fa1_or0 >> 0) & 0x01);
  f_s_rca8_fa2_or0 = ((f_s_rca8_fa2_and0 >> 0) & 0x01) | ((f_s_rca8_fa2_and1 >> 0) & 0x01);
  f_s_rca8_fa3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_s_rca8_fa3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_s_rca8_fa3_xor1 = ((f_s_rca8_fa3_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa2_or0 >> 0) & 0x01);
  f_s_rca8_fa3_and1 = ((f_s_rca8_fa3_xor0 >> 0) & 0x01) & ((f_s_rca8_fa2_or0 >> 0) & 0x01);
  f_s_rca8_fa3_or0 = ((f_s_rca8_fa3_and0 >> 0) & 0x01) | ((f_s_rca8_fa3_and1 >> 0) & 0x01);
  f_s_rca8_fa4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  f_s_rca8_fa4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  f_s_rca8_fa4_xor1 = ((f_s_rca8_fa4_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa3_or0 >> 0) & 0x01);
  f_s_rca8_fa4_and1 = ((f_s_rca8_fa4_xor0 >> 0) & 0x01) & ((f_s_rca8_fa3_or0 >> 0) & 0x01);
  f_s_rca8_fa4_or0 = ((f_s_rca8_fa4_and0 >> 0) & 0x01) | ((f_s_rca8_fa4_and1 >> 0) & 0x01);
  f_s_rca8_fa5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  f_s_rca8_fa5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_s_rca8_fa5_xor1 = ((f_s_rca8_fa5_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa4_or0 >> 0) & 0x01);
  f_s_rca8_fa5_and1 = ((f_s_rca8_fa5_xor0 >> 0) & 0x01) & ((f_s_rca8_fa4_or0 >> 0) & 0x01);
  f_s_rca8_fa5_or0 = ((f_s_rca8_fa5_and0 >> 0) & 0x01) | ((f_s_rca8_fa5_and1 >> 0) & 0x01);
  f_s_rca8_fa6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  f_s_rca8_fa6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_s_rca8_fa6_xor1 = ((f_s_rca8_fa6_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa5_or0 >> 0) & 0x01);
  f_s_rca8_fa6_and1 = ((f_s_rca8_fa6_xor0 >> 0) & 0x01) & ((f_s_rca8_fa5_or0 >> 0) & 0x01);
  f_s_rca8_fa6_or0 = ((f_s_rca8_fa6_and0 >> 0) & 0x01) | ((f_s_rca8_fa6_and1 >> 0) & 0x01);
  f_s_rca8_fa7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_s_rca8_fa7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_s_rca8_fa7_xor1 = ((f_s_rca8_fa7_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa6_or0 >> 0) & 0x01);
  f_s_rca8_fa7_and1 = ((f_s_rca8_fa7_xor0 >> 0) & 0x01) & ((f_s_rca8_fa6_or0 >> 0) & 0x01);
  f_s_rca8_fa7_or0 = ((f_s_rca8_fa7_and0 >> 0) & 0x01) | ((f_s_rca8_fa7_and1 >> 0) & 0x01);
  f_s_rca8_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_s_rca8_xor1 = ((f_s_rca8_xor0 >> 0) & 0x01) ^ ((f_s_rca8_fa7_or0 >> 0) & 0x01);

  f_s_rca8_out |= ((f_s_rca8_ha_xor0 >> 0) & 0x01) << 0;
  f_s_rca8_out |= ((f_s_rca8_fa1_xor1 >> 0) & 0x01) << 1;
  f_s_rca8_out |= ((f_s_rca8_fa2_xor1 >> 0) & 0x01) << 2;
  f_s_rca8_out |= ((f_s_rca8_fa3_xor1 >> 0) & 0x01) << 3;
  f_s_rca8_out |= ((f_s_rca8_fa4_xor1 >> 0) & 0x01) << 4;
  f_s_rca8_out |= ((f_s_rca8_fa5_xor1 >> 0) & 0x01) << 5;
  f_s_rca8_out |= ((f_s_rca8_fa6_xor1 >> 0) & 0x01) << 6;
  f_s_rca8_out |= ((f_s_rca8_fa7_xor1 >> 0) & 0x01) << 7;
  f_s_rca8_out |= ((f_s_rca8_xor1 >> 0) & 0x01) << 8;
  return f_s_rca8_out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -128; i < 128; i++){
    for (int j = -128; j < 128; j++){
      result = i + j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 512 + result;  
      }

      assert(result == (int)f_s_rca8(i,j));
    }
  }
  return 0;
}