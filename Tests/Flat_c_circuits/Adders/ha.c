#include <stdio.h>
#include <stdint.h>

uint8_t half_adder(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t half_adder_a = 0;
  uint8_t half_adder_b = 0;
  uint8_t half_adder_y0 = 0;
  uint8_t half_adder_y1 = 0;

  half_adder_a = ((a >> 0) & 0x01);
  half_adder_b = ((b >> 0) & 0x01);
  half_adder_y0 = half_adder_a ^ half_adder_b;
  half_adder_y1 = half_adder_a & half_adder_b;

  out |= (half_adder_y0 & 0x01) << 0;
  out |= (half_adder_y1 & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      assert((i + j) == half_adder(i,j));
    }
  }
  return 0;
}