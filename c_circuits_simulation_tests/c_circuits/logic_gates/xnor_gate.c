#include <stdio.h>
#include <stdint.h>

uint8_t xnor_gate(uint8_t a, uint8_t b){
  return ~(((a >> 0) & 0x01) ^ ((b >> 0) & 0x01)) & 0x01;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      assert(!(i ^ j) == xnor_gate(i,j));
    }
  }
  return 0;
}