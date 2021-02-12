#include <stdio.h>
#include <stdint.h>

uint64_t u_rca5(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t u_rca5_ha_a_0 = 0;
  uint8_t u_rca5_ha_b_0 = 0;
  uint8_t u_rca5_ha_y0 = 0;
  uint8_t u_rca5_ha_y1 = 0;
  uint8_t u_rca5_fa1_a_1 = 0;
  uint8_t u_rca5_fa1_b_1 = 0;
  uint8_t u_rca5_fa1_y0 = 0;
  uint8_t u_rca5_fa1_y1 = 0;
  uint8_t u_rca5_fa1_u_rca5_ha_y1 = 0;
  uint8_t u_rca5_fa1_y2 = 0;
  uint8_t u_rca5_fa1_y3 = 0;
  uint8_t u_rca5_fa1_y4 = 0;
  uint8_t u_rca5_fa2_a_2 = 0;
  uint8_t u_rca5_fa2_b_2 = 0;
  uint8_t u_rca5_fa2_y0 = 0;
  uint8_t u_rca5_fa2_y1 = 0;
  uint8_t u_rca5_fa2_u_rca5_fa1_y4 = 0;
  uint8_t u_rca5_fa2_y2 = 0;
  uint8_t u_rca5_fa2_y3 = 0;
  uint8_t u_rca5_fa2_y4 = 0;
  uint8_t u_rca5_fa3_a_3 = 0;
  uint8_t u_rca5_fa3_b_3 = 0;
  uint8_t u_rca5_fa3_y0 = 0;
  uint8_t u_rca5_fa3_y1 = 0;
  uint8_t u_rca5_fa3_u_rca5_fa2_y4 = 0;
  uint8_t u_rca5_fa3_y2 = 0;
  uint8_t u_rca5_fa3_y3 = 0;
  uint8_t u_rca5_fa3_y4 = 0;
  uint8_t u_rca5_fa4_a_4 = 0;
  uint8_t u_rca5_fa4_b_4 = 0;
  uint8_t u_rca5_fa4_y0 = 0;
  uint8_t u_rca5_fa4_y1 = 0;
  uint8_t u_rca5_fa4_u_rca5_fa3_y4 = 0;
  uint8_t u_rca5_fa4_y2 = 0;
  uint8_t u_rca5_fa4_y3 = 0;
  uint8_t u_rca5_fa4_y4 = 0;

  u_rca5_ha_a_0 = ((a >> 0) & 0x01);
  u_rca5_ha_b_0 = ((b >> 0) & 0x01);
  u_rca5_ha_y0 = u_rca5_ha_a_0 ^ u_rca5_ha_b_0;
  u_rca5_ha_y1 = u_rca5_ha_a_0 & u_rca5_ha_b_0;
  u_rca5_fa1_a_1 = ((a >> 1) & 0x01);
  u_rca5_fa1_b_1 = ((b >> 1) & 0x01);
  u_rca5_fa1_u_rca5_ha_y1 = ((u_rca5_ha_y1 >> 0) & 0x01);
  u_rca5_fa1_y0 = u_rca5_fa1_a_1 ^ u_rca5_fa1_b_1;
  u_rca5_fa1_y1 = u_rca5_fa1_a_1 & u_rca5_fa1_b_1;
  u_rca5_fa1_y2 = u_rca5_fa1_y0 ^ u_rca5_fa1_u_rca5_ha_y1;
  u_rca5_fa1_y3 = u_rca5_fa1_y0 & u_rca5_fa1_u_rca5_ha_y1;
  u_rca5_fa1_y4 = u_rca5_fa1_y1 | u_rca5_fa1_y3;
  u_rca5_fa2_a_2 = ((a >> 2) & 0x01);
  u_rca5_fa2_b_2 = ((b >> 2) & 0x01);
  u_rca5_fa2_u_rca5_fa1_y4 = ((u_rca5_fa1_y4 >> 0) & 0x01);
  u_rca5_fa2_y0 = u_rca5_fa2_a_2 ^ u_rca5_fa2_b_2;
  u_rca5_fa2_y1 = u_rca5_fa2_a_2 & u_rca5_fa2_b_2;
  u_rca5_fa2_y2 = u_rca5_fa2_y0 ^ u_rca5_fa2_u_rca5_fa1_y4;
  u_rca5_fa2_y3 = u_rca5_fa2_y0 & u_rca5_fa2_u_rca5_fa1_y4;
  u_rca5_fa2_y4 = u_rca5_fa2_y1 | u_rca5_fa2_y3;
  u_rca5_fa3_a_3 = ((a >> 3) & 0x01);
  u_rca5_fa3_b_3 = ((b >> 3) & 0x01);
  u_rca5_fa3_u_rca5_fa2_y4 = ((u_rca5_fa2_y4 >> 0) & 0x01);
  u_rca5_fa3_y0 = u_rca5_fa3_a_3 ^ u_rca5_fa3_b_3;
  u_rca5_fa3_y1 = u_rca5_fa3_a_3 & u_rca5_fa3_b_3;
  u_rca5_fa3_y2 = u_rca5_fa3_y0 ^ u_rca5_fa3_u_rca5_fa2_y4;
  u_rca5_fa3_y3 = u_rca5_fa3_y0 & u_rca5_fa3_u_rca5_fa2_y4;
  u_rca5_fa3_y4 = u_rca5_fa3_y1 | u_rca5_fa3_y3;
  u_rca5_fa4_a_4 = ((a >> 4) & 0x01);
  u_rca5_fa4_b_4 = ((b >> 4) & 0x01);
  u_rca5_fa4_u_rca5_fa3_y4 = ((u_rca5_fa3_y4 >> 0) & 0x01);
  u_rca5_fa4_y0 = u_rca5_fa4_a_4 ^ u_rca5_fa4_b_4;
  u_rca5_fa4_y1 = u_rca5_fa4_a_4 & u_rca5_fa4_b_4;
  u_rca5_fa4_y2 = u_rca5_fa4_y0 ^ u_rca5_fa4_u_rca5_fa3_y4;
  u_rca5_fa4_y3 = u_rca5_fa4_y0 & u_rca5_fa4_u_rca5_fa3_y4;
  u_rca5_fa4_y4 = u_rca5_fa4_y1 | u_rca5_fa4_y3;

  out |= (u_rca5_ha_y0 & 0x01) << 0;
  out |= (u_rca5_fa1_y2 & 0x01) << 1;
  out |= (u_rca5_fa2_y2 & 0x01) << 2;
  out |= (u_rca5_fa3_y2 & 0x01) << 3;
  out |= (u_rca5_fa4_y2 & 0x01) << 4;
  out |= (u_rca5_fa4_y4 & 0x01) << 5;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 32; j++){
      assert((i + j) == u_rca5(i,j));
    }
  }
  return 0;
}