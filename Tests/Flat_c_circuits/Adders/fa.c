#include <stdio.h>
#include <stdint.h>

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t full_adder_a = 0;
  uint8_t full_adder_b = 0;
  uint8_t full_adder_y0 = 0;
  uint8_t full_adder_y1 = 0;
  uint8_t full_adder_cin = 0;
  uint8_t full_adder_y2 = 0;
  uint8_t full_adder_y3 = 0;
  uint8_t full_adder_y4 = 0;

  full_adder_a = ((a >> 0) & 0x01);
  full_adder_b = ((b >> 0) & 0x01);
  full_adder_cin = ((cin >> 0) & 0x01);
  full_adder_y0 = full_adder_a ^ full_adder_b;
  full_adder_y1 = full_adder_a & full_adder_b;
  full_adder_y2 = full_adder_y0 ^ full_adder_cin;
  full_adder_y3 = full_adder_y0 & full_adder_cin;
  full_adder_y4 = full_adder_y1 | full_adder_y3;

  out |= (full_adder_y2 & 0x01) << 0;
  out |= (full_adder_y4 & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        assert((i + j + k) == full_adder(i,j,k));
      }
    }
  }
  return 0;
}