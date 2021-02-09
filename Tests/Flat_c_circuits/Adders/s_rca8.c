#include <stdio.h>
#include <stdint.h>

uint64_t s_rca8(int64_t a, int64_t b){
  uint64_t out = 0;
  uint8_t s_rca8_ha_a = 0;
  uint8_t s_rca8_ha_b = 0;
  uint8_t s_rca8_ha_y0 = 0;
  uint8_t s_rca8_ha_y1 = 0;
  uint8_t s_rca8_fa1_a = 0;
  uint8_t s_rca8_fa1_b = 0;
  uint8_t s_rca8_fa1_y0 = 0;
  uint8_t s_rca8_fa1_y1 = 0;
  uint8_t s_rca8_fa1_s_rca8_ha_y1 = 0;
  uint8_t s_rca8_fa1_y2 = 0;
  uint8_t s_rca8_fa1_y3 = 0;
  uint8_t s_rca8_fa1_y4 = 0;
  uint8_t s_rca8_fa2_a = 0;
  uint8_t s_rca8_fa2_b = 0;
  uint8_t s_rca8_fa2_y0 = 0;
  uint8_t s_rca8_fa2_y1 = 0;
  uint8_t s_rca8_fa2_s_rca8_fa1_y4 = 0;
  uint8_t s_rca8_fa2_y2 = 0;
  uint8_t s_rca8_fa2_y3 = 0;
  uint8_t s_rca8_fa2_y4 = 0;
  uint8_t s_rca8_fa3_a = 0;
  uint8_t s_rca8_fa3_b = 0;
  uint8_t s_rca8_fa3_y0 = 0;
  uint8_t s_rca8_fa3_y1 = 0;
  uint8_t s_rca8_fa3_s_rca8_fa2_y4 = 0;
  uint8_t s_rca8_fa3_y2 = 0;
  uint8_t s_rca8_fa3_y3 = 0;
  uint8_t s_rca8_fa3_y4 = 0;
  uint8_t s_rca8_fa4_a = 0;
  uint8_t s_rca8_fa4_b = 0;
  uint8_t s_rca8_fa4_y0 = 0;
  uint8_t s_rca8_fa4_y1 = 0;
  uint8_t s_rca8_fa4_s_rca8_fa3_y4 = 0;
  uint8_t s_rca8_fa4_y2 = 0;
  uint8_t s_rca8_fa4_y3 = 0;
  uint8_t s_rca8_fa4_y4 = 0;
  uint8_t s_rca8_fa5_a = 0;
  uint8_t s_rca8_fa5_b = 0;
  uint8_t s_rca8_fa5_y0 = 0;
  uint8_t s_rca8_fa5_y1 = 0;
  uint8_t s_rca8_fa5_s_rca8_fa4_y4 = 0;
  uint8_t s_rca8_fa5_y2 = 0;
  uint8_t s_rca8_fa5_y3 = 0;
  uint8_t s_rca8_fa5_y4 = 0;
  uint8_t s_rca8_fa6_a = 0;
  uint8_t s_rca8_fa6_b = 0;
  uint8_t s_rca8_fa6_y0 = 0;
  uint8_t s_rca8_fa6_y1 = 0;
  uint8_t s_rca8_fa6_s_rca8_fa5_y4 = 0;
  uint8_t s_rca8_fa6_y2 = 0;
  uint8_t s_rca8_fa6_y3 = 0;
  uint8_t s_rca8_fa6_y4 = 0;
  uint8_t s_rca8_fa7_a = 0;
  uint8_t s_rca8_fa7_b = 0;
  uint8_t s_rca8_fa7_y0 = 0;
  uint8_t s_rca8_fa7_y1 = 0;
  uint8_t s_rca8_fa7_s_rca8_fa6_y4 = 0;
  uint8_t s_rca8_fa7_y2 = 0;
  uint8_t s_rca8_fa7_y3 = 0;
  uint8_t s_rca8_fa7_y4 = 0;
  uint8_t s_rca8_xor_1_a = 0;
  uint8_t s_rca8_xor_1_b = 0;
  uint8_t s_rca8_xor_1_y0 = 0;
  uint8_t s_rca8_xor_2_s_rca8_xor_1_y0 = 0;
  uint8_t s_rca8_xor_2_s_rca8_fa7_y4 = 0;
  uint8_t s_rca8_xor_2_y0 = 0;

  s_rca8_ha_a = ((a >> 0) & 0x01);
  s_rca8_ha_b = ((b >> 0) & 0x01);
  s_rca8_ha_y0 = s_rca8_ha_a ^ s_rca8_ha_b;
  s_rca8_ha_y1 = s_rca8_ha_a & s_rca8_ha_b;
  s_rca8_fa1_a = ((a >> 1) & 0x01);
  s_rca8_fa1_b = ((b >> 1) & 0x01);
  s_rca8_fa1_s_rca8_ha_y1 = ((s_rca8_ha_y1 >> 0) & 0x01);
  s_rca8_fa1_y0 = s_rca8_fa1_a ^ s_rca8_fa1_b;
  s_rca8_fa1_y1 = s_rca8_fa1_a & s_rca8_fa1_b;
  s_rca8_fa1_y2 = s_rca8_fa1_y0 ^ s_rca8_fa1_s_rca8_ha_y1;
  s_rca8_fa1_y3 = s_rca8_fa1_y0 & s_rca8_fa1_s_rca8_ha_y1;
  s_rca8_fa1_y4 = s_rca8_fa1_y1 | s_rca8_fa1_y3;
  s_rca8_fa2_a = ((a >> 2) & 0x01);
  s_rca8_fa2_b = ((b >> 2) & 0x01);
  s_rca8_fa2_s_rca8_fa1_y4 = ((s_rca8_fa1_y4 >> 0) & 0x01);
  s_rca8_fa2_y0 = s_rca8_fa2_a ^ s_rca8_fa2_b;
  s_rca8_fa2_y1 = s_rca8_fa2_a & s_rca8_fa2_b;
  s_rca8_fa2_y2 = s_rca8_fa2_y0 ^ s_rca8_fa2_s_rca8_fa1_y4;
  s_rca8_fa2_y3 = s_rca8_fa2_y0 & s_rca8_fa2_s_rca8_fa1_y4;
  s_rca8_fa2_y4 = s_rca8_fa2_y1 | s_rca8_fa2_y3;
  s_rca8_fa3_a = ((a >> 3) & 0x01);
  s_rca8_fa3_b = ((b >> 3) & 0x01);
  s_rca8_fa3_s_rca8_fa2_y4 = ((s_rca8_fa2_y4 >> 0) & 0x01);
  s_rca8_fa3_y0 = s_rca8_fa3_a ^ s_rca8_fa3_b;
  s_rca8_fa3_y1 = s_rca8_fa3_a & s_rca8_fa3_b;
  s_rca8_fa3_y2 = s_rca8_fa3_y0 ^ s_rca8_fa3_s_rca8_fa2_y4;
  s_rca8_fa3_y3 = s_rca8_fa3_y0 & s_rca8_fa3_s_rca8_fa2_y4;
  s_rca8_fa3_y4 = s_rca8_fa3_y1 | s_rca8_fa3_y3;
  s_rca8_fa4_a = ((a >> 4) & 0x01);
  s_rca8_fa4_b = ((b >> 4) & 0x01);
  s_rca8_fa4_s_rca8_fa3_y4 = ((s_rca8_fa3_y4 >> 0) & 0x01);
  s_rca8_fa4_y0 = s_rca8_fa4_a ^ s_rca8_fa4_b;
  s_rca8_fa4_y1 = s_rca8_fa4_a & s_rca8_fa4_b;
  s_rca8_fa4_y2 = s_rca8_fa4_y0 ^ s_rca8_fa4_s_rca8_fa3_y4;
  s_rca8_fa4_y3 = s_rca8_fa4_y0 & s_rca8_fa4_s_rca8_fa3_y4;
  s_rca8_fa4_y4 = s_rca8_fa4_y1 | s_rca8_fa4_y3;
  s_rca8_fa5_a = ((a >> 5) & 0x01);
  s_rca8_fa5_b = ((b >> 5) & 0x01);
  s_rca8_fa5_s_rca8_fa4_y4 = ((s_rca8_fa4_y4 >> 0) & 0x01);
  s_rca8_fa5_y0 = s_rca8_fa5_a ^ s_rca8_fa5_b;
  s_rca8_fa5_y1 = s_rca8_fa5_a & s_rca8_fa5_b;
  s_rca8_fa5_y2 = s_rca8_fa5_y0 ^ s_rca8_fa5_s_rca8_fa4_y4;
  s_rca8_fa5_y3 = s_rca8_fa5_y0 & s_rca8_fa5_s_rca8_fa4_y4;
  s_rca8_fa5_y4 = s_rca8_fa5_y1 | s_rca8_fa5_y3;
  s_rca8_fa6_a = ((a >> 6) & 0x01);
  s_rca8_fa6_b = ((b >> 6) & 0x01);
  s_rca8_fa6_s_rca8_fa5_y4 = ((s_rca8_fa5_y4 >> 0) & 0x01);
  s_rca8_fa6_y0 = s_rca8_fa6_a ^ s_rca8_fa6_b;
  s_rca8_fa6_y1 = s_rca8_fa6_a & s_rca8_fa6_b;
  s_rca8_fa6_y2 = s_rca8_fa6_y0 ^ s_rca8_fa6_s_rca8_fa5_y4;
  s_rca8_fa6_y3 = s_rca8_fa6_y0 & s_rca8_fa6_s_rca8_fa5_y4;
  s_rca8_fa6_y4 = s_rca8_fa6_y1 | s_rca8_fa6_y3;
  s_rca8_fa7_a = ((a >> 7) & 0x01);
  s_rca8_fa7_b = ((b >> 7) & 0x01);
  s_rca8_fa7_s_rca8_fa6_y4 = ((s_rca8_fa6_y4 >> 0) & 0x01);
  s_rca8_fa7_y0 = s_rca8_fa7_a ^ s_rca8_fa7_b;
  s_rca8_fa7_y1 = s_rca8_fa7_a & s_rca8_fa7_b;
  s_rca8_fa7_y2 = s_rca8_fa7_y0 ^ s_rca8_fa7_s_rca8_fa6_y4;
  s_rca8_fa7_y3 = s_rca8_fa7_y0 & s_rca8_fa7_s_rca8_fa6_y4;
  s_rca8_fa7_y4 = s_rca8_fa7_y1 | s_rca8_fa7_y3;
  s_rca8_xor_1_a = ((a >> 7) & 0x01);
  s_rca8_xor_1_b = ((b >> 7) & 0x01);
  s_rca8_xor_1_y0 = s_rca8_xor_1_a ^ s_rca8_xor_1_b;
  s_rca8_xor_2_s_rca8_xor_1_y0 = ((s_rca8_xor_1_y0 >> 0) & 0x01);
  s_rca8_xor_2_s_rca8_fa7_y4 = ((s_rca8_fa7_y4 >> 0) & 0x01);
  s_rca8_xor_2_y0 = s_rca8_xor_2_s_rca8_xor_1_y0 ^ s_rca8_xor_2_s_rca8_fa7_y4;

  out |= (s_rca8_ha_y0 & 0x01) << 0;
  out |= (s_rca8_fa1_y2 & 0x01) << 1;
  out |= (s_rca8_fa2_y2 & 0x01) << 2;
  out |= (s_rca8_fa3_y2 & 0x01) << 3;
  out |= (s_rca8_fa4_y2 & 0x01) << 4;
  out |= (s_rca8_fa5_y2 & 0x01) << 5;
  out |= (s_rca8_fa6_y2 & 0x01) << 6;
  out |= (s_rca8_fa7_y2 & 0x01) << 7;
  out |= (s_rca8_xor_2_y0 & 0x01) << 8;
  return out;
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

      assert(result == (int)s_rca8(i,j));
    }
  }
  return 0;
}