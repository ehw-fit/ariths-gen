#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t ha_a = 0;
  uint8_t ha_b = 0;
  uint8_t ha_y0 = 0;
  uint8_t ha_y1 = 0;

  ha_a = ((a >> 0) & 0x01);
  ha_b = ((b >> 0) & 0x01);
  ha_y0 = xor_gate(ha_a, ha_b);
  ha_y1 = and_gate(ha_a, ha_b);

  out |= (ha_y0 & 0x01) << 0;
  out |= (ha_y1 & 0x01) << 1;
  return out;
}

uint64_t h_u_arrmul2(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t h_u_arrmul2_and0_0_y0 = 0;
  uint8_t h_u_arrmul2_and1_0_y0 = 0;
  uint8_t h_u_arrmul2_and0_1_y0 = 0;
  uint8_t h_u_arrmul2_ha0_1_y0 = 0;
  uint8_t h_u_arrmul2_ha0_1_y1 = 0;
  uint8_t h_u_arrmul2_and1_1_y0 = 0;
  uint8_t h_u_arrmul2_ha1_1_y0 = 0;
  uint8_t h_u_arrmul2_ha1_1_y1 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  h_u_arrmul2_and0_0_y0 = and_gate(a_0, b_0);
  h_u_arrmul2_and1_0_y0 = and_gate(a_1, b_0);
  h_u_arrmul2_and0_1_y0 = and_gate(a_0, b_1);
  h_u_arrmul2_ha0_1_y0 = (ha(h_u_arrmul2_and0_1_y0, h_u_arrmul2_and1_0_y0) >> 0) & 0x01;
  h_u_arrmul2_ha0_1_y1 = (ha(h_u_arrmul2_and0_1_y0, h_u_arrmul2_and1_0_y0) >> 1) & 0x01;
  h_u_arrmul2_and1_1_y0 = and_gate(a_1, b_1);
  h_u_arrmul2_ha1_1_y0 = (ha(h_u_arrmul2_and1_1_y0, h_u_arrmul2_ha0_1_y1) >> 0) & 0x01;
  h_u_arrmul2_ha1_1_y1 = (ha(h_u_arrmul2_and1_1_y0, h_u_arrmul2_ha0_1_y1) >> 1) & 0x01;

  out |= (h_u_arrmul2_and0_0_y0 & 0x01) << 0;
  out |= (h_u_arrmul2_ha0_1_y0 & 0x01) << 1;
  out |= (h_u_arrmul2_ha1_1_y0 & 0x01) << 2;
  out |= (h_u_arrmul2_ha1_1_y1 & 0x01) << 3;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      assert((i * j) == h_u_arrmul2(i,j));
    }
  }
  return 0;
}