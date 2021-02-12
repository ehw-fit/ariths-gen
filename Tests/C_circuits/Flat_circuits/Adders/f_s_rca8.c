#include <stdio.h>
#include <stdint.h>

uint64_t s_rca8(int64_t a, int64_t b){
  uint64_t out = 0;
  uint8_t s_rca8_ha_a_0 = 0;
  uint8_t s_rca8_ha_b_0 = 0;
  uint8_t s_rca8_ha_y0 = 0;
  uint8_t s_rca8_ha_y1 = 0;
  uint8_t s_rca8_fa1_a_1 = 0;
  uint8_t s_rca8_fa1_b_1 = 0;
  uint8_t s_rca8_fa1_y0 = 0;
  uint8_t s_rca8_fa1_y1 = 0;
  uint8_t s_rca8_fa1_s_rca8_ha_y1 = 0;
  uint8_t s_rca8_fa1_y2 = 0;
  uint8_t s_rca8_fa1_y3 = 0;
  uint8_t s_rca8_fa1_y4 = 0;
  uint8_t s_rca8_fa2_a_2 = 0;
  uint8_t s_rca8_fa2_b_2 = 0;
  uint8_t s_rca8_fa2_y0 = 0;
  uint8_t s_rca8_fa2_y1 = 0;
  uint8_t s_rca8_fa2_s_rca8_fa1_y4 = 0;
  uint8_t s_rca8_fa2_y2 = 0;
  uint8_t s_rca8_fa2_y3 = 0;
  uint8_t s_rca8_fa2_y4 = 0;
  uint8_t s_rca8_fa3_a_3 = 0;
  uint8_t s_rca8_fa3_b_3 = 0;
  uint8_t s_rca8_fa3_y0 = 0;
  uint8_t s_rca8_fa3_y1 = 0;
  uint8_t s_rca8_fa3_s_rca8_fa2_y4 = 0;
  uint8_t s_rca8_fa3_y2 = 0;
  uint8_t s_rca8_fa3_y3 = 0;
  uint8_t s_rca8_fa3_y4 = 0;
  uint8_t s_rca8_fa4_a_4 = 0;
  uint8_t s_rca8_fa4_b_4 = 0;
  uint8_t s_rca8_fa4_y0 = 0;
  uint8_t s_rca8_fa4_y1 = 0;
  uint8_t s_rca8_fa4_s_rca8_fa3_y4 = 0;
  uint8_t s_rca8_fa4_y2 = 0;
  uint8_t s_rca8_fa4_y3 = 0;
  uint8_t s_rca8_fa4_y4 = 0;
  uint8_t s_rca8_fa5_a_5 = 0;
  uint8_t s_rca8_fa5_b_5 = 0;
  uint8_t s_rca8_fa5_y0 = 0;
  uint8_t s_rca8_fa5_y1 = 0;
  uint8_t s_rca8_fa5_s_rca8_fa4_y4 = 0;
  uint8_t s_rca8_fa5_y2 = 0;
  uint8_t s_rca8_fa5_y3 = 0;
  uint8_t s_rca8_fa5_y4 = 0;
  uint8_t s_rca8_fa6_a_6 = 0;
  uint8_t s_rca8_fa6_b_6 = 0;
  uint8_t s_rca8_fa6_y0 = 0;
  uint8_t s_rca8_fa6_y1 = 0;
  uint8_t s_rca8_fa6_s_rca8_fa5_y4 = 0;
  uint8_t s_rca8_fa6_y2 = 0;
  uint8_t s_rca8_fa6_y3 = 0;
  uint8_t s_rca8_fa6_y4 = 0;
  uint8_t s_rca8_fa7_a_7 = 0;
  uint8_t s_rca8_fa7_b_7 = 0;
  uint8_t s_rca8_fa7_y0 = 0;
  uint8_t s_rca8_fa7_y1 = 0;
  uint8_t s_rca8_fa7_s_rca8_fa6_y4 = 0;
  uint8_t s_rca8_fa7_y2 = 0;
  uint8_t s_rca8_fa7_y3 = 0;
  uint8_t s_rca8_fa7_y4 = 0;
  uint8_t s_rca8_xor_1_a_7 = 0;
  uint8_t s_rca8_xor_1_b_7 = 0;
  uint8_t s_rca8_xor_1_y0 = 0;
  uint8_t s_rca8_xor_2_s_rca8_xor_1_y0 = 0;
  uint8_t s_rca8_xor_2_s_rca8_fa7_y4 = 0;
  uint8_t s_rca8_xor_2_y0 = 0;

  s_rca8_ha_a_0 = ((a >> 0) & 0x01);
  s_rca8_ha_b_0 = ((b >> 0) & 0x01);
  s_rca8_ha_y0 = s_rca8_ha_a_0 ^ s_rca8_ha_b_0;
  s_rca8_ha_y1 = s_rca8_ha_a_0 & s_rca8_ha_b_0;
  s_rca8_fa1_a_1 = ((a >> 1) & 0x01);
  s_rca8_fa1_b_1 = ((b >> 1) & 0x01);
  s_rca8_fa1_s_rca8_ha_y1 = ((s_rca8_ha_y1 >> 0) & 0x01);
  s_rca8_fa1_y0 = s_rca8_fa1_a_1 ^ s_rca8_fa1_b_1;
  s_rca8_fa1_y1 = s_rca8_fa1_a_1 & s_rca8_fa1_b_1;
  s_rca8_fa1_y2 = s_rca8_fa1_y0 ^ s_rca8_fa1_s_rca8_ha_y1;
  s_rca8_fa1_y3 = s_rca8_fa1_y0 & s_rca8_fa1_s_rca8_ha_y1;
  s_rca8_fa1_y4 = s_rca8_fa1_y1 | s_rca8_fa1_y3;
  s_rca8_fa2_a_2 = ((a >> 2) & 0x01);
  s_rca8_fa2_b_2 = ((b >> 2) & 0x01);
  s_rca8_fa2_s_rca8_fa1_y4 = ((s_rca8_fa1_y4 >> 0) & 0x01);
  s_rca8_fa2_y0 = s_rca8_fa2_a_2 ^ s_rca8_fa2_b_2;
  s_rca8_fa2_y1 = s_rca8_fa2_a_2 & s_rca8_fa2_b_2;
  s_rca8_fa2_y2 = s_rca8_fa2_y0 ^ s_rca8_fa2_s_rca8_fa1_y4;
  s_rca8_fa2_y3 = s_rca8_fa2_y0 & s_rca8_fa2_s_rca8_fa1_y4;
  s_rca8_fa2_y4 = s_rca8_fa2_y1 | s_rca8_fa2_y3;
  s_rca8_fa3_a_3 = ((a >> 3) & 0x01);
  s_rca8_fa3_b_3 = ((b >> 3) & 0x01);
  s_rca8_fa3_s_rca8_fa2_y4 = ((s_rca8_fa2_y4 >> 0) & 0x01);
  s_rca8_fa3_y0 = s_rca8_fa3_a_3 ^ s_rca8_fa3_b_3;
  s_rca8_fa3_y1 = s_rca8_fa3_a_3 & s_rca8_fa3_b_3;
  s_rca8_fa3_y2 = s_rca8_fa3_y0 ^ s_rca8_fa3_s_rca8_fa2_y4;
  s_rca8_fa3_y3 = s_rca8_fa3_y0 & s_rca8_fa3_s_rca8_fa2_y4;
  s_rca8_fa3_y4 = s_rca8_fa3_y1 | s_rca8_fa3_y3;
  s_rca8_fa4_a_4 = ((a >> 4) & 0x01);
  s_rca8_fa4_b_4 = ((b >> 4) & 0x01);
  s_rca8_fa4_s_rca8_fa3_y4 = ((s_rca8_fa3_y4 >> 0) & 0x01);
  s_rca8_fa4_y0 = s_rca8_fa4_a_4 ^ s_rca8_fa4_b_4;
  s_rca8_fa4_y1 = s_rca8_fa4_a_4 & s_rca8_fa4_b_4;
  s_rca8_fa4_y2 = s_rca8_fa4_y0 ^ s_rca8_fa4_s_rca8_fa3_y4;
  s_rca8_fa4_y3 = s_rca8_fa4_y0 & s_rca8_fa4_s_rca8_fa3_y4;
  s_rca8_fa4_y4 = s_rca8_fa4_y1 | s_rca8_fa4_y3;
  s_rca8_fa5_a_5 = ((a >> 5) & 0x01);
  s_rca8_fa5_b_5 = ((b >> 5) & 0x01);
  s_rca8_fa5_s_rca8_fa4_y4 = ((s_rca8_fa4_y4 >> 0) & 0x01);
  s_rca8_fa5_y0 = s_rca8_fa5_a_5 ^ s_rca8_fa5_b_5;
  s_rca8_fa5_y1 = s_rca8_fa5_a_5 & s_rca8_fa5_b_5;
  s_rca8_fa5_y2 = s_rca8_fa5_y0 ^ s_rca8_fa5_s_rca8_fa4_y4;
  s_rca8_fa5_y3 = s_rca8_fa5_y0 & s_rca8_fa5_s_rca8_fa4_y4;
  s_rca8_fa5_y4 = s_rca8_fa5_y1 | s_rca8_fa5_y3;
  s_rca8_fa6_a_6 = ((a >> 6) & 0x01);
  s_rca8_fa6_b_6 = ((b >> 6) & 0x01);
  s_rca8_fa6_s_rca8_fa5_y4 = ((s_rca8_fa5_y4 >> 0) & 0x01);
  s_rca8_fa6_y0 = s_rca8_fa6_a_6 ^ s_rca8_fa6_b_6;
  s_rca8_fa6_y1 = s_rca8_fa6_a_6 & s_rca8_fa6_b_6;
  s_rca8_fa6_y2 = s_rca8_fa6_y0 ^ s_rca8_fa6_s_rca8_fa5_y4;
  s_rca8_fa6_y3 = s_rca8_fa6_y0 & s_rca8_fa6_s_rca8_fa5_y4;
  s_rca8_fa6_y4 = s_rca8_fa6_y1 | s_rca8_fa6_y3;
  s_rca8_fa7_a_7 = ((a >> 7) & 0x01);
  s_rca8_fa7_b_7 = ((b >> 7) & 0x01);
  s_rca8_fa7_s_rca8_fa6_y4 = ((s_rca8_fa6_y4 >> 0) & 0x01);
  s_rca8_fa7_y0 = s_rca8_fa7_a_7 ^ s_rca8_fa7_b_7;
  s_rca8_fa7_y1 = s_rca8_fa7_a_7 & s_rca8_fa7_b_7;
  s_rca8_fa7_y2 = s_rca8_fa7_y0 ^ s_rca8_fa7_s_rca8_fa6_y4;
  s_rca8_fa7_y3 = s_rca8_fa7_y0 & s_rca8_fa7_s_rca8_fa6_y4;
  s_rca8_fa7_y4 = s_rca8_fa7_y1 | s_rca8_fa7_y3;
  s_rca8_xor_1_a_7 = ((a >> 7) & 0x01);
  s_rca8_xor_1_b_7 = ((b >> 7) & 0x01);
  s_rca8_xor_1_y0 = s_rca8_xor_1_a_7 ^ s_rca8_xor_1_b_7;
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