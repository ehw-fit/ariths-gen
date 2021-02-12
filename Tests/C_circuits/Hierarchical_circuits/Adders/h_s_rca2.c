#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t ha(uint8_t a_0, uint8_t b_0){
  uint8_t out = 0;

  out |= (xor_gate(a_0, b_0) & 0x01) << 0;
  out |= (and_gate(a_0, b_0) & 0x01) << 1;
  return out;
}

uint8_t fa(uint8_t a_1, uint8_t b_1, uint8_t cin){
  uint8_t out = 0;
  uint8_t xor_1 = 0;
  uint8_t and_1 = 0;
  uint8_t and_2 = 0;

  xor_1 = xor_gate(a_1, b_1);
  and_1 = and_gate(a_1, b_1);
  and_2 = and_gate(xor_1, cin);

  out |= (xor_gate(xor_1, cin) & 0x01) << 0;
  out |= (or_gate(and_1, and_2) & 0x01) << 1;
  return out;
}

uint64_t s_rca2(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t cout_0 = 0;
  uint8_t cout_1 = 0;
  uint8_t s_rca2_xor_1_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  cout_0 = (ha(a_0, b_0) >> 1) & 0x01;
  cout_1 = (fa(a_1, b_1, cout_0) >> 1) & 0x01;
  s_rca2_xor_1_y0 = xor_gate(a_1, b_1);

  out |= ((ha(a_0, b_0) >> 0) & 0x01) << 0;
  out |= ((fa(a_1, b_1, cout_0) >> 0) & 0x01) << 1;
  out |= (xor_gate(s_rca2_xor_1_y0, cout_1) & 0x01) << 2;
  return out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -2; i < 2; i++){
    for (int j = -2; j < 2; j++){
      result = i + j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 8 + result;  
      }

      assert(result == (int)s_rca2(i,j));
    }
  }
  return 0;
}