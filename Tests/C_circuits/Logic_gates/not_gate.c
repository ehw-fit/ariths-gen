#include <stdio.h>
#include <stdint.h>

uint8_t _not_gate(uint8_t _a){
  return ~((_a >> 0) & 0x01) & 0x01 << 0;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    assert(!(i) == _not_gate(i));
  }
  return 0;
}