#include <stdio.h>
#include <stdint.h>

uint8_t f_fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t f_fa_out = 0;
  uint8_t f_fa_xor0 = 0;
  uint8_t f_fa_and0 = 0;
  uint8_t f_fa_xor1 = 0;
  uint8_t f_fa_and1 = 0;
  uint8_t f_fa_or0 = 0;

  f_fa_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_fa_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_fa_xor1 = ((f_fa_xor0 >> 0) & 0x01) ^ ((cin >> 0) & 0x01);
  f_fa_and1 = ((f_fa_xor0 >> 0) & 0x01) & ((cin >> 0) & 0x01);
  f_fa_or0 = ((f_fa_and0 >> 0) & 0x01) | ((f_fa_and1 >> 0) & 0x01);

  f_fa_out |= ((f_fa_xor1 >> 0) & 0x01) << 0;
  f_fa_out |= ((f_fa_or0 >> 0) & 0x01) << 1;
  return f_fa_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        assert((i + j + k) == f_fa(i,j,k));
      }
    }
  }
  return 0;
}