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
  out |= (xor_gate(a, b) & 0x01) << 0;
  out |= (and_gate(a, b) & 0x01) << 1;
  return out;
}

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t fa_y0 = 0;
  uint8_t fa_y1 = 0;
  uint8_t fa_y3 = 0;

  fa_y0 = xor_gate(a, b);
  fa_y1 = and_gate(a, b);
  fa_y3 = and_gate(fa_y0, cin);

  out |= (xor_gate(fa_y0, cin) & 0x01) << 0;
  out |= (or_gate(fa_y1, fa_y3) & 0x01) << 1;
  return out;
}

int64_t h_s_rca4(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t h_s_rca4_ha_y0 = 0;
  uint8_t h_s_rca4_ha_y1 = 0;
  uint8_t h_s_rca4_fa1_y2 = 0;
  uint8_t h_s_rca4_fa1_y4 = 0;
  uint8_t h_s_rca4_fa2_y2 = 0;
  uint8_t h_s_rca4_fa2_y4 = 0;
  uint8_t h_s_rca4_fa3_y2 = 0;
  uint8_t h_s_rca4_fa3_y4 = 0;
  uint8_t h_s_rca4_xor_1_y0 = 0;
  uint8_t h_s_rca4_xor_2_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  h_s_rca4_ha_y0 = (ha(a_0, b_0) >> 0) & 0x01;
  h_s_rca4_ha_y1 = (ha(a_0, b_0) >> 1) & 0x01;
  h_s_rca4_fa1_y2 = (fa(a_1, b_1, h_s_rca4_ha_y1) >> 0) & 0x01;
  h_s_rca4_fa1_y4 = (fa(a_1, b_1, h_s_rca4_ha_y1) >> 1) & 0x01;
  h_s_rca4_fa2_y2 = (fa(a_2, b_2, h_s_rca4_fa1_y4) >> 0) & 0x01;
  h_s_rca4_fa2_y4 = (fa(a_2, b_2, h_s_rca4_fa1_y4) >> 1) & 0x01;
  h_s_rca4_fa3_y2 = (fa(a_3, b_3, h_s_rca4_fa2_y4) >> 0) & 0x01;
  h_s_rca4_fa3_y4 = (fa(a_3, b_3, h_s_rca4_fa2_y4) >> 1) & 0x01;
  h_s_rca4_xor_1_y0 = xor_gate(a_3, b_3);
  h_s_rca4_xor_2_y0 = xor_gate(h_s_rca4_xor_1_y0, h_s_rca4_fa3_y4);

  out |= (h_s_rca4_ha_y0 & 0x01) << 0;
  out |= (h_s_rca4_fa1_y2 & 0x01) << 1;
  out |= (h_s_rca4_fa2_y2 & 0x01) << 2;
  out |= (h_s_rca4_fa3_y2 & 0x01) << 3;
  out |= (h_s_rca4_xor_2_y0 & 0x01) << 4;
  return out;
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

      assert(result == (int)h_s_rca4(i,j));
    }
  }
  return 0;
}