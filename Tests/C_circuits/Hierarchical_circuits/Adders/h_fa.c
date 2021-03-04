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

uint8_t h_fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t h_fa_y0 = 0;
  uint8_t h_fa_y1 = 0;
  uint8_t h_fa_y3 = 0;

  h_fa_y0 = xor_gate(a, b);
  h_fa_y1 = and_gate(a, b);
  h_fa_y3 = and_gate(h_fa_y0, cin);

  out |= (xor_gate(h_fa_y0, cin) & 0x01) << 0;
  out |= (or_gate(h_fa_y1, h_fa_y3) & 0x01) << 1;
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