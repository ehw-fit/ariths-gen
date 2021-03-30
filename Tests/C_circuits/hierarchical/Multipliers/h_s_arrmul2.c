#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t xnor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint8_t or_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) | ((_b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t nand_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) & ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint8_t constant_wire_value_1(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t constant_wire_value_1_a = 0;
  uint8_t constant_wire_value_1_b = 0;
  uint8_t constant_wire_value_1_y0 = 0;
  uint8_t constant_wire_value_1_y1 = 0;
  uint8_t constant_wire_1 = 0;

  constant_wire_value_1_a = ((a >> 0) & 0x01);
  constant_wire_value_1_b = ((b >> 0) & 0x01);
  constant_wire_value_1_y0 = xor_gate(constant_wire_value_1_a, constant_wire_value_1_b);
  constant_wire_value_1_y1 = xnor_gate(constant_wire_value_1_a, constant_wire_value_1_b);
  constant_wire_1 = or_gate(constant_wire_value_1_y0, constant_wire_value_1_y1);

  out |= (constant_wire_1 & 0x01) << 0;
  return out;
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

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t fa_a = 0;
  uint8_t fa_b = 0;
  uint8_t fa_y0 = 0;
  uint8_t fa_y1 = 0;
  uint8_t fa_cin = 0;
  uint8_t fa_y2 = 0;
  uint8_t fa_y3 = 0;
  uint8_t fa_y4 = 0;

  fa_a = ((a >> 0) & 0x01);
  fa_b = ((b >> 0) & 0x01);
  fa_cin = ((cin >> 0) & 0x01);
  fa_y0 = xor_gate(fa_a, fa_b);
  fa_y1 = and_gate(fa_a, fa_b);
  fa_y2 = xor_gate(fa_y0, fa_cin);
  fa_y3 = and_gate(fa_y0, fa_cin);
  fa_y4 = or_gate(fa_y1, fa_y3);

  out |= (fa_y2 & 0x01) << 0;
  out |= (fa_y4 & 0x01) << 1;
  return out;
}

int64_t h_s_arrmul2(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t constant_wire_1 = 0;
  uint8_t h_s_arrmul2_and0_0_y0 = 0;
  uint8_t h_s_arrmul2_nand1_0_y0 = 0;
  uint8_t h_s_arrmul2_nand0_1_y0 = 0;
  uint8_t h_s_arrmul2_ha0_1_y0 = 0;
  uint8_t h_s_arrmul2_ha0_1_y1 = 0;
  uint8_t h_s_arrmul2_and1_1_y0 = 0;
  uint8_t h_s_arrmul2_fa1_1_y2 = 0;
  uint8_t h_s_arrmul2_fa1_1_y4 = 0;
  uint8_t h_s_arrmul2_xor2_1_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  constant_wire_1 = (constant_wire_value_1(a_0, b_0) >> 0) & 0x01;
  h_s_arrmul2_and0_0_y0 = and_gate(a_0, b_0);
  h_s_arrmul2_nand1_0_y0 = nand_gate(a_1, b_0);
  h_s_arrmul2_nand0_1_y0 = nand_gate(a_0, b_1);
  h_s_arrmul2_ha0_1_y0 = (ha(h_s_arrmul2_nand0_1_y0, h_s_arrmul2_nand1_0_y0) >> 0) & 0x01;
  h_s_arrmul2_ha0_1_y1 = (ha(h_s_arrmul2_nand0_1_y0, h_s_arrmul2_nand1_0_y0) >> 1) & 0x01;
  h_s_arrmul2_and1_1_y0 = and_gate(a_1, b_1);
  h_s_arrmul2_fa1_1_y2 = (fa(h_s_arrmul2_and1_1_y0, constant_wire_1, h_s_arrmul2_ha0_1_y1) >> 0) & 0x01;
  h_s_arrmul2_fa1_1_y4 = (fa(h_s_arrmul2_and1_1_y0, constant_wire_1, h_s_arrmul2_ha0_1_y1) >> 1) & 0x01;
  h_s_arrmul2_xor2_1_y0 = xor_gate(h_s_arrmul2_fa1_1_y4, constant_wire_1);

  out |= (h_s_arrmul2_and0_0_y0 & 0x01) << 0;
  out |= (h_s_arrmul2_ha0_1_y0 & 0x01) << 1;
  out |= (h_s_arrmul2_fa1_1_y2 & 0x01) << 2;
  out |= (h_s_arrmul2_xor2_1_y0 & 0x01) << 3;
  return out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -2; i < 2; i++){
    for (int j = -2; j < 2; j++){
      result = i * j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 16 + result;  
      }
      
      assert(result == (int)h_s_arrmul2(i,j));
    }
  }
  return 0;
}