#include <stdio.h>
#include <stdint.h>

uint8_t f_ha(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t f_ha_a = 0;
  uint8_t f_ha_b = 0;
  uint8_t f_ha_y0 = 0;
  uint8_t f_ha_y1 = 0;

  f_ha_a = ((a >> 0) & 0x01);
  f_ha_b = ((b >> 0) & 0x01);
  f_ha_y0 = f_ha_a ^ f_ha_b;
  f_ha_y1 = f_ha_a & f_ha_b;

  out |= (f_ha_y0 & 0x01) << 0;
  out |= (f_ha_y1 & 0x01) << 1;
  return out;
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