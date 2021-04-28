#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t h_ha(uint8_t a, uint8_t b){
  uint8_t h_ha_out = 0;
  uint8_t h_ha_xor0 = 0;
  uint8_t h_ha_and0 = 0;

  h_ha_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  h_ha_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));

  h_ha_out |= ((h_ha_xor0 >> 0) & 0x01) << 0;
  h_ha_out |= ((h_ha_and0 >> 0) & 0x01) << 1;
  return h_ha_out;
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