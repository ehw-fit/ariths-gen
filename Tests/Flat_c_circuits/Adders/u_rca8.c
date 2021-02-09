#include <stdio.h>
#include <stdint.h>

uint64_t u_rca8(uint64_t a, uint64_t b){
  uint64_t out = 0;
  uint8_t u_rca8_ha_a = 0;
  uint8_t u_rca8_ha_b = 0;
  uint8_t u_rca8_ha_y0 = 0;
  uint8_t u_rca8_ha_y1 = 0;
  uint8_t u_rca8_fa1_a = 0;
  uint8_t u_rca8_fa1_b = 0;
  uint8_t u_rca8_fa1_y0 = 0;
  uint8_t u_rca8_fa1_y1 = 0;
  uint8_t u_rca8_fa1_u_rca8_ha_y1 = 0;
  uint8_t u_rca8_fa1_y2 = 0;
  uint8_t u_rca8_fa1_y3 = 0;
  uint8_t u_rca8_fa1_y4 = 0;
  uint8_t u_rca8_fa2_a = 0;
  uint8_t u_rca8_fa2_b = 0;
  uint8_t u_rca8_fa2_y0 = 0;
  uint8_t u_rca8_fa2_y1 = 0;
  uint8_t u_rca8_fa2_u_rca8_fa1_y4 = 0;
  uint8_t u_rca8_fa2_y2 = 0;
  uint8_t u_rca8_fa2_y3 = 0;
  uint8_t u_rca8_fa2_y4 = 0;
  uint8_t u_rca8_fa3_a = 0;
  uint8_t u_rca8_fa3_b = 0;
  uint8_t u_rca8_fa3_y0 = 0;
  uint8_t u_rca8_fa3_y1 = 0;
  uint8_t u_rca8_fa3_u_rca8_fa2_y4 = 0;
  uint8_t u_rca8_fa3_y2 = 0;
  uint8_t u_rca8_fa3_y3 = 0;
  uint8_t u_rca8_fa3_y4 = 0;
  uint8_t u_rca8_fa4_a = 0;
  uint8_t u_rca8_fa4_b = 0;
  uint8_t u_rca8_fa4_y0 = 0;
  uint8_t u_rca8_fa4_y1 = 0;
  uint8_t u_rca8_fa4_u_rca8_fa3_y4 = 0;
  uint8_t u_rca8_fa4_y2 = 0;
  uint8_t u_rca8_fa4_y3 = 0;
  uint8_t u_rca8_fa4_y4 = 0;
  uint8_t u_rca8_fa5_a = 0;
  uint8_t u_rca8_fa5_b = 0;
  uint8_t u_rca8_fa5_y0 = 0;
  uint8_t u_rca8_fa5_y1 = 0;
  uint8_t u_rca8_fa5_u_rca8_fa4_y4 = 0;
  uint8_t u_rca8_fa5_y2 = 0;
  uint8_t u_rca8_fa5_y3 = 0;
  uint8_t u_rca8_fa5_y4 = 0;
  uint8_t u_rca8_fa6_a = 0;
  uint8_t u_rca8_fa6_b = 0;
  uint8_t u_rca8_fa6_y0 = 0;
  uint8_t u_rca8_fa6_y1 = 0;
  uint8_t u_rca8_fa6_u_rca8_fa5_y4 = 0;
  uint8_t u_rca8_fa6_y2 = 0;
  uint8_t u_rca8_fa6_y3 = 0;
  uint8_t u_rca8_fa6_y4 = 0;
  uint8_t u_rca8_fa7_a = 0;
  uint8_t u_rca8_fa7_b = 0;
  uint8_t u_rca8_fa7_y0 = 0;
  uint8_t u_rca8_fa7_y1 = 0;
  uint8_t u_rca8_fa7_u_rca8_fa6_y4 = 0;
  uint8_t u_rca8_fa7_y2 = 0;
  uint8_t u_rca8_fa7_y3 = 0;
  uint8_t u_rca8_fa7_y4 = 0;

  u_rca8_ha_a = ((a >> 0) & 0x01);
  u_rca8_ha_b = ((b >> 0) & 0x01);
  u_rca8_ha_y0 = u_rca8_ha_a ^ u_rca8_ha_b;
  u_rca8_ha_y1 = u_rca8_ha_a & u_rca8_ha_b;
  u_rca8_fa1_a = ((a >> 1) & 0x01);
  u_rca8_fa1_b = ((b >> 1) & 0x01);
  u_rca8_fa1_u_rca8_ha_y1 = ((u_rca8_ha_y1 >> 0) & 0x01);
  u_rca8_fa1_y0 = u_rca8_fa1_a ^ u_rca8_fa1_b;
  u_rca8_fa1_y1 = u_rca8_fa1_a & u_rca8_fa1_b;
  u_rca8_fa1_y2 = u_rca8_fa1_y0 ^ u_rca8_fa1_u_rca8_ha_y1;
  u_rca8_fa1_y3 = u_rca8_fa1_y0 & u_rca8_fa1_u_rca8_ha_y1;
  u_rca8_fa1_y4 = u_rca8_fa1_y1 | u_rca8_fa1_y3;
  u_rca8_fa2_a = ((a >> 2) & 0x01);
  u_rca8_fa2_b = ((b >> 2) & 0x01);
  u_rca8_fa2_u_rca8_fa1_y4 = ((u_rca8_fa1_y4 >> 0) & 0x01);
  u_rca8_fa2_y0 = u_rca8_fa2_a ^ u_rca8_fa2_b;
  u_rca8_fa2_y1 = u_rca8_fa2_a & u_rca8_fa2_b;
  u_rca8_fa2_y2 = u_rca8_fa2_y0 ^ u_rca8_fa2_u_rca8_fa1_y4;
  u_rca8_fa2_y3 = u_rca8_fa2_y0 & u_rca8_fa2_u_rca8_fa1_y4;
  u_rca8_fa2_y4 = u_rca8_fa2_y1 | u_rca8_fa2_y3;
  u_rca8_fa3_a = ((a >> 3) & 0x01);
  u_rca8_fa3_b = ((b >> 3) & 0x01);
  u_rca8_fa3_u_rca8_fa2_y4 = ((u_rca8_fa2_y4 >> 0) & 0x01);
  u_rca8_fa3_y0 = u_rca8_fa3_a ^ u_rca8_fa3_b;
  u_rca8_fa3_y1 = u_rca8_fa3_a & u_rca8_fa3_b;
  u_rca8_fa3_y2 = u_rca8_fa3_y0 ^ u_rca8_fa3_u_rca8_fa2_y4;
  u_rca8_fa3_y3 = u_rca8_fa3_y0 & u_rca8_fa3_u_rca8_fa2_y4;
  u_rca8_fa3_y4 = u_rca8_fa3_y1 | u_rca8_fa3_y3;
  u_rca8_fa4_a = ((a >> 4) & 0x01);
  u_rca8_fa4_b = ((b >> 4) & 0x01);
  u_rca8_fa4_u_rca8_fa3_y4 = ((u_rca8_fa3_y4 >> 0) & 0x01);
  u_rca8_fa4_y0 = u_rca8_fa4_a ^ u_rca8_fa4_b;
  u_rca8_fa4_y1 = u_rca8_fa4_a & u_rca8_fa4_b;
  u_rca8_fa4_y2 = u_rca8_fa4_y0 ^ u_rca8_fa4_u_rca8_fa3_y4;
  u_rca8_fa4_y3 = u_rca8_fa4_y0 & u_rca8_fa4_u_rca8_fa3_y4;
  u_rca8_fa4_y4 = u_rca8_fa4_y1 | u_rca8_fa4_y3;
  u_rca8_fa5_a = ((a >> 5) & 0x01);
  u_rca8_fa5_b = ((b >> 5) & 0x01);
  u_rca8_fa5_u_rca8_fa4_y4 = ((u_rca8_fa4_y4 >> 0) & 0x01);
  u_rca8_fa5_y0 = u_rca8_fa5_a ^ u_rca8_fa5_b;
  u_rca8_fa5_y1 = u_rca8_fa5_a & u_rca8_fa5_b;
  u_rca8_fa5_y2 = u_rca8_fa5_y0 ^ u_rca8_fa5_u_rca8_fa4_y4;
  u_rca8_fa5_y3 = u_rca8_fa5_y0 & u_rca8_fa5_u_rca8_fa4_y4;
  u_rca8_fa5_y4 = u_rca8_fa5_y1 | u_rca8_fa5_y3;
  u_rca8_fa6_a = ((a >> 6) & 0x01);
  u_rca8_fa6_b = ((b >> 6) & 0x01);
  u_rca8_fa6_u_rca8_fa5_y4 = ((u_rca8_fa5_y4 >> 0) & 0x01);
  u_rca8_fa6_y0 = u_rca8_fa6_a ^ u_rca8_fa6_b;
  u_rca8_fa6_y1 = u_rca8_fa6_a & u_rca8_fa6_b;
  u_rca8_fa6_y2 = u_rca8_fa6_y0 ^ u_rca8_fa6_u_rca8_fa5_y4;
  u_rca8_fa6_y3 = u_rca8_fa6_y0 & u_rca8_fa6_u_rca8_fa5_y4;
  u_rca8_fa6_y4 = u_rca8_fa6_y1 | u_rca8_fa6_y3;
  u_rca8_fa7_a = ((a >> 7) & 0x01);
  u_rca8_fa7_b = ((b >> 7) & 0x01);
  u_rca8_fa7_u_rca8_fa6_y4 = ((u_rca8_fa6_y4 >> 0) & 0x01);
  u_rca8_fa7_y0 = u_rca8_fa7_a ^ u_rca8_fa7_b;
  u_rca8_fa7_y1 = u_rca8_fa7_a & u_rca8_fa7_b;
  u_rca8_fa7_y2 = u_rca8_fa7_y0 ^ u_rca8_fa7_u_rca8_fa6_y4;
  u_rca8_fa7_y3 = u_rca8_fa7_y0 & u_rca8_fa7_u_rca8_fa6_y4;
  u_rca8_fa7_y4 = u_rca8_fa7_y1 | u_rca8_fa7_y3;

  out |= (u_rca8_ha_y0 & 0x01) << 0;
  out |= (u_rca8_fa1_y2 & 0x01) << 1;
  out |= (u_rca8_fa2_y2 & 0x01) << 2;
  out |= (u_rca8_fa3_y2 & 0x01) << 3;
  out |= (u_rca8_fa4_y2 & 0x01) << 4;
  out |= (u_rca8_fa5_y2 & 0x01) << 5;
  out |= (u_rca8_fa6_y2 & 0x01) << 6;
  out |= (u_rca8_fa7_y2 & 0x01) << 7;
  out |= (u_rca8_fa7_y4 & 0x01) << 8;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 256; i++){
    for (int j = 0; j < 256; j++){
      assert((i + j) == u_rca8(i,j));
    }
  }
  return 0;
}