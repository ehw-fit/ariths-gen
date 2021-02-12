#include <stdio.h>
#include <stdint.h>

uint64_t u_rca3(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t u_rca3_ha_a_0 = 0;
  uint8_t u_rca3_ha_b_0 = 0;
  uint8_t u_rca3_ha_y0 = 0;
  uint8_t u_rca3_ha_y1 = 0;
  uint8_t u_rca3_fa1_a_1 = 0;
  uint8_t u_rca3_fa1_b_1 = 0;
  uint8_t u_rca3_fa1_y0 = 0;
  uint8_t u_rca3_fa1_y1 = 0;
  uint8_t u_rca3_fa1_u_rca3_ha_y1 = 0;
  uint8_t u_rca3_fa1_y2 = 0;
  uint8_t u_rca3_fa1_y3 = 0;
  uint8_t u_rca3_fa1_y4 = 0;
  uint8_t u_rca3_fa2_a_2 = 0;
  uint8_t u_rca3_fa2_b_2 = 0;
  uint8_t u_rca3_fa2_y0 = 0;
  uint8_t u_rca3_fa2_y1 = 0;
  uint8_t u_rca3_fa2_u_rca3_fa1_y4 = 0;
  uint8_t u_rca3_fa2_y2 = 0;
  uint8_t u_rca3_fa2_y3 = 0;
  uint8_t u_rca3_fa2_y4 = 0;

  u_rca3_ha_a_0 = ((a >> 0) & 0x01);
  u_rca3_ha_b_0 = ((b >> 0) & 0x01);
  u_rca3_ha_y0 = u_rca3_ha_a_0 ^ u_rca3_ha_b_0;
  u_rca3_ha_y1 = u_rca3_ha_a_0 & u_rca3_ha_b_0;
  u_rca3_fa1_a_1 = ((a >> 1) & 0x01);
  u_rca3_fa1_b_1 = ((b >> 1) & 0x01);
  u_rca3_fa1_u_rca3_ha_y1 = ((u_rca3_ha_y1 >> 0) & 0x01);
  u_rca3_fa1_y0 = u_rca3_fa1_a_1 ^ u_rca3_fa1_b_1;
  u_rca3_fa1_y1 = u_rca3_fa1_a_1 & u_rca3_fa1_b_1;
  u_rca3_fa1_y2 = u_rca3_fa1_y0 ^ u_rca3_fa1_u_rca3_ha_y1;
  u_rca3_fa1_y3 = u_rca3_fa1_y0 & u_rca3_fa1_u_rca3_ha_y1;
  u_rca3_fa1_y4 = u_rca3_fa1_y1 | u_rca3_fa1_y3;
  u_rca3_fa2_a_2 = ((a >> 2) & 0x01);
  u_rca3_fa2_b_2 = ((b >> 2) & 0x01);
  u_rca3_fa2_u_rca3_fa1_y4 = ((u_rca3_fa1_y4 >> 0) & 0x01);
  u_rca3_fa2_y0 = u_rca3_fa2_a_2 ^ u_rca3_fa2_b_2;
  u_rca3_fa2_y1 = u_rca3_fa2_a_2 & u_rca3_fa2_b_2;
  u_rca3_fa2_y2 = u_rca3_fa2_y0 ^ u_rca3_fa2_u_rca3_fa1_y4;
  u_rca3_fa2_y3 = u_rca3_fa2_y0 & u_rca3_fa2_u_rca3_fa1_y4;
  u_rca3_fa2_y4 = u_rca3_fa2_y1 | u_rca3_fa2_y3;

  out |= (u_rca3_ha_y0 & 0x01) << 0;
  out |= (u_rca3_fa1_y2 & 0x01) << 1;
  out |= (u_rca3_fa2_y2 & 0x01) << 2;
  out |= (u_rca3_fa2_y4 & 0x01) << 3;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      assert((i + j) == u_rca3(i,j));
    }
  }
  return 0;
}