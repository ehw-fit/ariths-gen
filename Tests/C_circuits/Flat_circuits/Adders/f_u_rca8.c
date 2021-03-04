#include <stdio.h>
#include <stdint.h>

uint64_t f_u_rca8(uint64_t a, uint64_t b){
  uint64_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t a_4 = 0;
  uint8_t a_5 = 0;
  uint8_t a_6 = 0;
  uint8_t a_7 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t b_4 = 0;
  uint8_t b_5 = 0;
  uint8_t b_6 = 0;
  uint8_t b_7 = 0;
  uint8_t f_u_rca8_ha_a_0 = 0;
  uint8_t f_u_rca8_ha_b_0 = 0;
  uint8_t f_u_rca8_ha_y0 = 0;
  uint8_t f_u_rca8_ha_y1 = 0;
  uint8_t f_u_rca8_fa1_a_1 = 0;
  uint8_t f_u_rca8_fa1_b_1 = 0;
  uint8_t f_u_rca8_fa1_y0 = 0;
  uint8_t f_u_rca8_fa1_y1 = 0;
  uint8_t f_u_rca8_fa1_f_u_rca8_ha_y1 = 0;
  uint8_t f_u_rca8_fa1_y2 = 0;
  uint8_t f_u_rca8_fa1_y3 = 0;
  uint8_t f_u_rca8_fa1_y4 = 0;
  uint8_t f_u_rca8_fa2_a_2 = 0;
  uint8_t f_u_rca8_fa2_b_2 = 0;
  uint8_t f_u_rca8_fa2_y0 = 0;
  uint8_t f_u_rca8_fa2_y1 = 0;
  uint8_t f_u_rca8_fa2_f_u_rca8_fa1_y4 = 0;
  uint8_t f_u_rca8_fa2_y2 = 0;
  uint8_t f_u_rca8_fa2_y3 = 0;
  uint8_t f_u_rca8_fa2_y4 = 0;
  uint8_t f_u_rca8_fa3_a_3 = 0;
  uint8_t f_u_rca8_fa3_b_3 = 0;
  uint8_t f_u_rca8_fa3_y0 = 0;
  uint8_t f_u_rca8_fa3_y1 = 0;
  uint8_t f_u_rca8_fa3_f_u_rca8_fa2_y4 = 0;
  uint8_t f_u_rca8_fa3_y2 = 0;
  uint8_t f_u_rca8_fa3_y3 = 0;
  uint8_t f_u_rca8_fa3_y4 = 0;
  uint8_t f_u_rca8_fa4_a_4 = 0;
  uint8_t f_u_rca8_fa4_b_4 = 0;
  uint8_t f_u_rca8_fa4_y0 = 0;
  uint8_t f_u_rca8_fa4_y1 = 0;
  uint8_t f_u_rca8_fa4_f_u_rca8_fa3_y4 = 0;
  uint8_t f_u_rca8_fa4_y2 = 0;
  uint8_t f_u_rca8_fa4_y3 = 0;
  uint8_t f_u_rca8_fa4_y4 = 0;
  uint8_t f_u_rca8_fa5_a_5 = 0;
  uint8_t f_u_rca8_fa5_b_5 = 0;
  uint8_t f_u_rca8_fa5_y0 = 0;
  uint8_t f_u_rca8_fa5_y1 = 0;
  uint8_t f_u_rca8_fa5_f_u_rca8_fa4_y4 = 0;
  uint8_t f_u_rca8_fa5_y2 = 0;
  uint8_t f_u_rca8_fa5_y3 = 0;
  uint8_t f_u_rca8_fa5_y4 = 0;
  uint8_t f_u_rca8_fa6_a_6 = 0;
  uint8_t f_u_rca8_fa6_b_6 = 0;
  uint8_t f_u_rca8_fa6_y0 = 0;
  uint8_t f_u_rca8_fa6_y1 = 0;
  uint8_t f_u_rca8_fa6_f_u_rca8_fa5_y4 = 0;
  uint8_t f_u_rca8_fa6_y2 = 0;
  uint8_t f_u_rca8_fa6_y3 = 0;
  uint8_t f_u_rca8_fa6_y4 = 0;
  uint8_t f_u_rca8_fa7_a_7 = 0;
  uint8_t f_u_rca8_fa7_b_7 = 0;
  uint8_t f_u_rca8_fa7_y0 = 0;
  uint8_t f_u_rca8_fa7_y1 = 0;
  uint8_t f_u_rca8_fa7_f_u_rca8_fa6_y4 = 0;
  uint8_t f_u_rca8_fa7_y2 = 0;
  uint8_t f_u_rca8_fa7_y3 = 0;
  uint8_t f_u_rca8_fa7_y4 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  a_4 = ((a >> 4) & 0x01);
  a_5 = ((a >> 5) & 0x01);
  a_6 = ((a >> 6) & 0x01);
  a_7 = ((a >> 7) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  b_4 = ((b >> 4) & 0x01);
  b_5 = ((b >> 5) & 0x01);
  b_6 = ((b >> 6) & 0x01);
  b_7 = ((b >> 7) & 0x01);
  f_u_rca8_ha_a_0 = ((a_0 >> 0) & 0x01);
  f_u_rca8_ha_b_0 = ((b_0 >> 0) & 0x01);
  f_u_rca8_ha_y0 = f_u_rca8_ha_a_0 ^ f_u_rca8_ha_b_0;
  f_u_rca8_ha_y1 = f_u_rca8_ha_a_0 & f_u_rca8_ha_b_0;
  f_u_rca8_fa1_a_1 = ((a_1 >> 0) & 0x01);
  f_u_rca8_fa1_b_1 = ((b_1 >> 0) & 0x01);
  f_u_rca8_fa1_f_u_rca8_ha_y1 = ((f_u_rca8_ha_y1 >> 0) & 0x01);
  f_u_rca8_fa1_y0 = f_u_rca8_fa1_a_1 ^ f_u_rca8_fa1_b_1;
  f_u_rca8_fa1_y1 = f_u_rca8_fa1_a_1 & f_u_rca8_fa1_b_1;
  f_u_rca8_fa1_y2 = f_u_rca8_fa1_y0 ^ f_u_rca8_fa1_f_u_rca8_ha_y1;
  f_u_rca8_fa1_y3 = f_u_rca8_fa1_y0 & f_u_rca8_fa1_f_u_rca8_ha_y1;
  f_u_rca8_fa1_y4 = f_u_rca8_fa1_y1 | f_u_rca8_fa1_y3;
  f_u_rca8_fa2_a_2 = ((a_2 >> 0) & 0x01);
  f_u_rca8_fa2_b_2 = ((b_2 >> 0) & 0x01);
  f_u_rca8_fa2_f_u_rca8_fa1_y4 = ((f_u_rca8_fa1_y4 >> 0) & 0x01);
  f_u_rca8_fa2_y0 = f_u_rca8_fa2_a_2 ^ f_u_rca8_fa2_b_2;
  f_u_rca8_fa2_y1 = f_u_rca8_fa2_a_2 & f_u_rca8_fa2_b_2;
  f_u_rca8_fa2_y2 = f_u_rca8_fa2_y0 ^ f_u_rca8_fa2_f_u_rca8_fa1_y4;
  f_u_rca8_fa2_y3 = f_u_rca8_fa2_y0 & f_u_rca8_fa2_f_u_rca8_fa1_y4;
  f_u_rca8_fa2_y4 = f_u_rca8_fa2_y1 | f_u_rca8_fa2_y3;
  f_u_rca8_fa3_a_3 = ((a_3 >> 0) & 0x01);
  f_u_rca8_fa3_b_3 = ((b_3 >> 0) & 0x01);
  f_u_rca8_fa3_f_u_rca8_fa2_y4 = ((f_u_rca8_fa2_y4 >> 0) & 0x01);
  f_u_rca8_fa3_y0 = f_u_rca8_fa3_a_3 ^ f_u_rca8_fa3_b_3;
  f_u_rca8_fa3_y1 = f_u_rca8_fa3_a_3 & f_u_rca8_fa3_b_3;
  f_u_rca8_fa3_y2 = f_u_rca8_fa3_y0 ^ f_u_rca8_fa3_f_u_rca8_fa2_y4;
  f_u_rca8_fa3_y3 = f_u_rca8_fa3_y0 & f_u_rca8_fa3_f_u_rca8_fa2_y4;
  f_u_rca8_fa3_y4 = f_u_rca8_fa3_y1 | f_u_rca8_fa3_y3;
  f_u_rca8_fa4_a_4 = ((a_4 >> 0) & 0x01);
  f_u_rca8_fa4_b_4 = ((b_4 >> 0) & 0x01);
  f_u_rca8_fa4_f_u_rca8_fa3_y4 = ((f_u_rca8_fa3_y4 >> 0) & 0x01);
  f_u_rca8_fa4_y0 = f_u_rca8_fa4_a_4 ^ f_u_rca8_fa4_b_4;
  f_u_rca8_fa4_y1 = f_u_rca8_fa4_a_4 & f_u_rca8_fa4_b_4;
  f_u_rca8_fa4_y2 = f_u_rca8_fa4_y0 ^ f_u_rca8_fa4_f_u_rca8_fa3_y4;
  f_u_rca8_fa4_y3 = f_u_rca8_fa4_y0 & f_u_rca8_fa4_f_u_rca8_fa3_y4;
  f_u_rca8_fa4_y4 = f_u_rca8_fa4_y1 | f_u_rca8_fa4_y3;
  f_u_rca8_fa5_a_5 = ((a_5 >> 0) & 0x01);
  f_u_rca8_fa5_b_5 = ((b_5 >> 0) & 0x01);
  f_u_rca8_fa5_f_u_rca8_fa4_y4 = ((f_u_rca8_fa4_y4 >> 0) & 0x01);
  f_u_rca8_fa5_y0 = f_u_rca8_fa5_a_5 ^ f_u_rca8_fa5_b_5;
  f_u_rca8_fa5_y1 = f_u_rca8_fa5_a_5 & f_u_rca8_fa5_b_5;
  f_u_rca8_fa5_y2 = f_u_rca8_fa5_y0 ^ f_u_rca8_fa5_f_u_rca8_fa4_y4;
  f_u_rca8_fa5_y3 = f_u_rca8_fa5_y0 & f_u_rca8_fa5_f_u_rca8_fa4_y4;
  f_u_rca8_fa5_y4 = f_u_rca8_fa5_y1 | f_u_rca8_fa5_y3;
  f_u_rca8_fa6_a_6 = ((a_6 >> 0) & 0x01);
  f_u_rca8_fa6_b_6 = ((b_6 >> 0) & 0x01);
  f_u_rca8_fa6_f_u_rca8_fa5_y4 = ((f_u_rca8_fa5_y4 >> 0) & 0x01);
  f_u_rca8_fa6_y0 = f_u_rca8_fa6_a_6 ^ f_u_rca8_fa6_b_6;
  f_u_rca8_fa6_y1 = f_u_rca8_fa6_a_6 & f_u_rca8_fa6_b_6;
  f_u_rca8_fa6_y2 = f_u_rca8_fa6_y0 ^ f_u_rca8_fa6_f_u_rca8_fa5_y4;
  f_u_rca8_fa6_y3 = f_u_rca8_fa6_y0 & f_u_rca8_fa6_f_u_rca8_fa5_y4;
  f_u_rca8_fa6_y4 = f_u_rca8_fa6_y1 | f_u_rca8_fa6_y3;
  f_u_rca8_fa7_a_7 = ((a_7 >> 0) & 0x01);
  f_u_rca8_fa7_b_7 = ((b_7 >> 0) & 0x01);
  f_u_rca8_fa7_f_u_rca8_fa6_y4 = ((f_u_rca8_fa6_y4 >> 0) & 0x01);
  f_u_rca8_fa7_y0 = f_u_rca8_fa7_a_7 ^ f_u_rca8_fa7_b_7;
  f_u_rca8_fa7_y1 = f_u_rca8_fa7_a_7 & f_u_rca8_fa7_b_7;
  f_u_rca8_fa7_y2 = f_u_rca8_fa7_y0 ^ f_u_rca8_fa7_f_u_rca8_fa6_y4;
  f_u_rca8_fa7_y3 = f_u_rca8_fa7_y0 & f_u_rca8_fa7_f_u_rca8_fa6_y4;
  f_u_rca8_fa7_y4 = f_u_rca8_fa7_y1 | f_u_rca8_fa7_y3;

  out |= (f_u_rca8_ha_y0 & 0x01) << 0;
  out |= (f_u_rca8_fa1_y2 & 0x01) << 1;
  out |= (f_u_rca8_fa2_y2 & 0x01) << 2;
  out |= (f_u_rca8_fa3_y2 & 0x01) << 3;
  out |= (f_u_rca8_fa4_y2 & 0x01) << 4;
  out |= (f_u_rca8_fa5_y2 & 0x01) << 5;
  out |= (f_u_rca8_fa6_y2 & 0x01) << 6;
  out |= (f_u_rca8_fa7_y2 & 0x01) << 7;
  out |= (f_u_rca8_fa7_y4 & 0x01) << 8;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 256; i++){
    for (int j = 0; j < 256; j++){
      assert((i + j) == f_u_rca8(i,j));
    }
  }
  return 0;
}