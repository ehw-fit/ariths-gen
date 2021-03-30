#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) | ((_b >> 0) & 0x01);
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t ha_a = 0;
  uint8_t ha_b = 0;
  uint8_t ha_y0 = 0;
  uint8_t ha_y1 = 0;

  ha_a = ((a >> 0) & 0x01);
  ha_b = ((b >> 0) & 0x01);
  ha_y0 = xor_gate(ha_a, ha_b);
  ha_y1 = and_gate(ha_a, ha_b);

  out |= (ha_y0 & 0x01) << 0;
  out |= (ha_y1 & 0x01) << 1;
  return out;
}

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t fa_a = 0;
  uint8_t fa_b = 0;
  uint8_t fa_y0 = 0;
  uint8_t fa_y1 = 0;
  uint8_t fa_cin = 0;
  uint8_t fa_y2 = 0;
  uint8_t fa_y3 = 0;
  uint8_t fa_y4 = 0;

  fa_a = ((a >> 0) & 0x01);
  fa_b = ((b >> 0) & 0x01);
  fa_cin = ((cin >> 0) & 0x01);
  fa_y0 = xor_gate(fa_a, fa_b);
  fa_y1 = and_gate(fa_a, fa_b);
  fa_y2 = xor_gate(fa_y0, fa_cin);
  fa_y3 = and_gate(fa_y0, fa_cin);
  fa_y4 = or_gate(fa_y1, fa_y3);

  out |= (fa_y2 & 0x01) << 0;
  out |= (fa_y4 & 0x01) << 1;
  return out;
}

int64_t h_s_rca6(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t a_4 = 0;
  uint8_t a_5 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t b_4 = 0;
  uint8_t b_5 = 0;
  uint8_t h_s_rca6_ha_y0 = 0;
  uint8_t h_s_rca6_ha_y1 = 0;
  uint8_t h_s_rca6_fa1_y2 = 0;
  uint8_t h_s_rca6_fa1_y4 = 0;
  uint8_t h_s_rca6_fa2_y2 = 0;
  uint8_t h_s_rca6_fa2_y4 = 0;
  uint8_t h_s_rca6_fa3_y2 = 0;
  uint8_t h_s_rca6_fa3_y4 = 0;
  uint8_t h_s_rca6_fa4_y2 = 0;
  uint8_t h_s_rca6_fa4_y4 = 0;
  uint8_t h_s_rca6_fa5_y2 = 0;
  uint8_t h_s_rca6_fa5_y4 = 0;
  uint8_t h_s_rca6_xor0_y0 = 0;
  uint8_t h_s_rca6_xor1_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  a_4 = ((a >> 4) & 0x01);
  a_5 = ((a >> 5) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  b_4 = ((b >> 4) & 0x01);
  b_5 = ((b >> 5) & 0x01);
  h_s_rca6_ha_y0 = (ha(a_0, b_0) >> 0) & 0x01;
  h_s_rca6_ha_y1 = (ha(a_0, b_0) >> 1) & 0x01;
  h_s_rca6_fa1_y2 = (fa(a_1, b_1, h_s_rca6_ha_y1) >> 0) & 0x01;
  h_s_rca6_fa1_y4 = (fa(a_1, b_1, h_s_rca6_ha_y1) >> 1) & 0x01;
  h_s_rca6_fa2_y2 = (fa(a_2, b_2, h_s_rca6_fa1_y4) >> 0) & 0x01;
  h_s_rca6_fa2_y4 = (fa(a_2, b_2, h_s_rca6_fa1_y4) >> 1) & 0x01;
  h_s_rca6_fa3_y2 = (fa(a_3, b_3, h_s_rca6_fa2_y4) >> 0) & 0x01;
  h_s_rca6_fa3_y4 = (fa(a_3, b_3, h_s_rca6_fa2_y4) >> 1) & 0x01;
  h_s_rca6_fa4_y2 = (fa(a_4, b_4, h_s_rca6_fa3_y4) >> 0) & 0x01;
  h_s_rca6_fa4_y4 = (fa(a_4, b_4, h_s_rca6_fa3_y4) >> 1) & 0x01;
  h_s_rca6_fa5_y2 = (fa(a_5, b_5, h_s_rca6_fa4_y4) >> 0) & 0x01;
  h_s_rca6_fa5_y4 = (fa(a_5, b_5, h_s_rca6_fa4_y4) >> 1) & 0x01;
  h_s_rca6_xor0_y0 = xor_gate(a_5, b_5);
  h_s_rca6_xor1_y0 = xor_gate(h_s_rca6_xor0_y0, h_s_rca6_fa5_y4);

  out |= (h_s_rca6_ha_y0 & 0x01) << 0;
  out |= (h_s_rca6_fa1_y2 & 0x01) << 1;
  out |= (h_s_rca6_fa2_y2 & 0x01) << 2;
  out |= (h_s_rca6_fa3_y2 & 0x01) << 3;
  out |= (h_s_rca6_fa4_y2 & 0x01) << 4;
  out |= (h_s_rca6_fa5_y2 & 0x01) << 5;
  out |= (h_s_rca6_xor1_y0 & 0x01) << 6;
  return out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -32; i < 32; i++){
    for (int j = -32; j < 32; j++){
      result = i + j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 128 + result;  
      }
      
      assert(result == (int)h_s_rca6(i,j));
    }
  }
  return 0;
}