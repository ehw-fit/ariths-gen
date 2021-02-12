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

uint8_t h_fa(uint8_t a, uint8_t b, uint8_t cout){
  uint8_t out = 0;
  uint8_t xor_1 = 0;
  uint8_t and_1 = 0;
  uint8_t and_2 = 0;

  xor_1 = xor_gate(a, b);
  and_1 = and_gate(a, b);
  and_2 = and_gate(xor_1, cout);

  out |= (xor_gate(xor_1, cout) & 0x01) << 0;
  out |= (or_gate(and_1, and_2) & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        assert((i + j + k) == h_fa(i,j,k));
      }
    }
  }
  return 0;
}