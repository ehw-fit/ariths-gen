#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t h_ha(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t h_ha_a = 0;
  uint8_t h_ha_b = 0;
  uint8_t h_ha_y0 = 0;
  uint8_t h_ha_y1 = 0;

  h_ha_a = ((a >> 0) & 0x01);
  h_ha_b = ((b >> 0) & 0x01);
  h_ha_y0 = xor_gate(h_ha_a, h_ha_b);
  h_ha_y1 = and_gate(h_ha_a, h_ha_b);

  out |= (h_ha_y0 & 0x01) << 0;
  out |= (h_ha_y1 & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      assert((i + j) == h_ha(i,j));
    }
  }
  return 0;
}