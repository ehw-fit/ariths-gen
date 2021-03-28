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

uint8_t nor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) | ((_b >> 0) & 0x01)) & 0x01 << 0;
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

int64_t h_s_arrmul1(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t b_0 = 0;
  uint8_t constant_wire_1 = 0;
  uint8_t h_s_arrmul1_and0_0_y0 = 0;
  uint8_t h_s_arrmul1_nor_zero_extend_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  constant_wire_1 = (constant_wire_value_1(a_0, b_0) >> 0) & 0x01;
  h_s_arrmul1_and0_0_y0 = and_gate(a_0, b_0);
  h_s_arrmul1_nor_zero_extend_y0 = nor_gate(constant_wire_1, h_s_arrmul1_and0_0_y0);

  out |= (h_s_arrmul1_and0_0_y0 & 0x01) << 0;
  out |= (h_s_arrmul1_nor_zero_extend_y0 & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -1; i < 1; i++){
    for (int j = -1; j < 1; j++){
      result = i * j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 4 + result;  
      }
      
      assert(result == (int)h_s_arrmul1(i,j));
    }
  }
  return 0;
}