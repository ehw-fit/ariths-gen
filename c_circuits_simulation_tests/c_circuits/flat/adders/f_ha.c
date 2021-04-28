#include <stdio.h>
#include <stdint.h>

uint8_t f_ha(uint8_t a, uint8_t b){
  uint8_t f_ha_out = 0;
  uint8_t f_ha_xor0 = 0;
  uint8_t f_ha_and0 = 0;

  f_ha_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_ha_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);

  f_ha_out |= ((f_ha_xor0 >> 0) & 0x01) << 0;
  f_ha_out |= ((f_ha_and0 >> 0) & 0x01) << 1;
  return f_ha_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      assert((i + j) == f_ha(i,j));
    }
  }
  return 0;
}