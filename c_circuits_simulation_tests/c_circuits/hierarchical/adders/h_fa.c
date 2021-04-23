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

uint8_t h_fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t h_fa_out = 0;
  uint8_t h_fa_xor0 = 0;
  uint8_t h_fa_and0 = 0;
  uint8_t h_fa_xor1 = 0;
  uint8_t h_fa_and1 = 0;
  uint8_t h_fa_or0 = 0;

  h_fa_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  h_fa_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  h_fa_xor1 = xor_gate(((h_fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));
  h_fa_and1 = and_gate(((h_fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));
  h_fa_or0 = or_gate(((h_fa_and0 >> 0) & 0x01), ((h_fa_and1 >> 0) & 0x01));

  h_fa_out |= ((h_fa_xor1 >> 0) & 0x01) << 0;
  h_fa_out |= ((h_fa_or0 >> 0) & 0x01) << 1;
  return h_fa_out;
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