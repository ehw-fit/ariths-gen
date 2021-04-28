#include <stdio.h>
#include <stdint.h>

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    assert(!(i) == not_gate(i));
  }
  return 0;
}