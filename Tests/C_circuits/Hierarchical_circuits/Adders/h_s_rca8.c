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

uint8_t fa(uint8_t a_7, uint8_t b_7, uint8_t cin){
  uint8_t out = 0;
  uint8_t xor_1 = 0;
  uint8_t and_1 = 0;
  uint8_t and_2 = 0;

  xor_1 = xor_gate(a_7, b_7);
  and_1 = and_gate(a_7, b_7);
  and_2 = and_gate(xor_1, cin);

  out |= (xor_gate(xor_1, cin) & 0x01) << 0;
  out |= (or_gate(and_1, and_2) & 0x01) << 1;
  return out;
}

uint64_t s_rca8(int64_t a, int64_t b){
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
  uint8_t cout_0 = 0;
  uint8_t cout_1 = 0;
  uint8_t cout_2 = 0;
  uint8_t cout_3 = 0;
  uint8_t cout_4 = 0;
  uint8_t cout_5 = 0;
  uint8_t cout_6 = 0;
  uint8_t cout_7 = 0;
  uint8_t s_rca8_xor_1_y0 = 0;

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
  cout_0 = (ha(a_0, b_0) >> 1) & 0x01;
  cout_1 = (fa(a_1, b_1, cout_0) >> 1) & 0x01;
  cout_2 = (fa(a_2, b_2, cout_1) >> 1) & 0x01;
  cout_3 = (fa(a_3, b_3, cout_2) >> 1) & 0x01;
  cout_4 = (fa(a_4, b_4, cout_3) >> 1) & 0x01;
  cout_5 = (fa(a_5, b_5, cout_4) >> 1) & 0x01;
  cout_6 = (fa(a_6, b_6, cout_5) >> 1) & 0x01;
  cout_7 = (fa(a_7, b_7, cout_6) >> 1) & 0x01;
  s_rca8_xor_1_y0 = xor_gate(a_7, b_7);

  out |= ((ha(a_0, b_0) >> 0) & 0x01) << 0;
  out |= ((fa(a_1, b_1, cout_0) >> 0) & 0x01) << 1;
  out |= ((fa(a_2, b_2, cout_1) >> 0) & 0x01) << 2;
  out |= ((fa(a_3, b_3, cout_2) >> 0) & 0x01) << 3;
  out |= ((fa(a_4, b_4, cout_3) >> 0) & 0x01) << 4;
  out |= ((fa(a_5, b_5, cout_4) >> 0) & 0x01) << 5;
  out |= ((fa(a_6, b_6, cout_5) >> 0) & 0x01) << 6;
  out |= ((fa(a_7, b_7, cout_6) >> 0) & 0x01) << 7;
  out |= (xor_gate(s_rca8_xor_1_y0, cout_7) & 0x01) << 8;
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