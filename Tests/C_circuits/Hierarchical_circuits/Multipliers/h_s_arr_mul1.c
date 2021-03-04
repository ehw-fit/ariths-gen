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

int64_t h_s_arr_mul1(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t b_0 = 0;
  uint8_t h_s_arr_mul1_xor_constant_wire_y0 = 0;
  uint8_t h_s_arr_mul1_xnor_constant_wire_y0 = 0;
  uint8_t constant_wire = 0;
  uint8_t h_s_arr_mul1_and_0_0_y0 = 0;
  uint8_t h_s_arr_mul1_nor_zero_extend_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  h_s_arr_mul1_xor_constant_wire_y0 = xor_gate(a_0, b_0);
  h_s_arr_mul1_xnor_constant_wire_y0 = xnor_gate(a_0, b_0);
  constant_wire = or_gate(h_s_arr_mul1_xor_constant_wire_y0, h_s_arr_mul1_xnor_constant_wire_y0);
  h_s_arr_mul1_and_0_0_y0 = and_gate(a_0, b_0);
  h_s_arr_mul1_nor_zero_extend_y0 = nor_gate(constant_wire, h_s_arr_mul1_and_0_0_y0);

  out |= (h_s_arr_mul1_and_0_0_y0 & 0x01) << 0;
  out |= (h_s_arr_mul1_nor_zero_extend_y0 & 0x01) << 1;
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
      
      assert(result == (int)h_s_arr_mul1(i,j));
    }
  }
  return 0;
}