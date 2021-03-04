#include <stdio.h>
#include <stdint.h>

uint8_t f_fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t f_fa_a = 0;
  uint8_t f_fa_b = 0;
  uint8_t f_fa_y0 = 0;
  uint8_t f_fa_y1 = 0;
  uint8_t f_fa_cin = 0;
  uint8_t f_fa_y2 = 0;
  uint8_t f_fa_y3 = 0;
  uint8_t f_fa_y4 = 0;

  f_fa_a = ((a >> 0) & 0x01);
  f_fa_b = ((b >> 0) & 0x01);
  f_fa_cin = ((cin >> 0) & 0x01);
  f_fa_y0 = f_fa_a ^ f_fa_b;
  f_fa_y1 = f_fa_a & f_fa_b;
  f_fa_y2 = f_fa_y0 ^ f_fa_cin;
  f_fa_y3 = f_fa_y0 & f_fa_cin;
  f_fa_y4 = f_fa_y1 | f_fa_y3;

  out |= (f_fa_y2 & 0x01) << 0;
  out |= (f_fa_y4 & 0x01) << 1;
  return out;
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