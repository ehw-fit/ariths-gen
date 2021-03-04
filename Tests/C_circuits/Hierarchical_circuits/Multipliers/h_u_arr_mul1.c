#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t xnor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint64_t h_u_arr_mul1(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t b_0 = 0;
  uint8_t h_u_arr_mul1_and_0_0_y0 = 0;
  uint8_t h_u_arr_mul1_xor_constant_wire_y0 = 0;
  uint8_t h_u_arr_mul1_xnor_constant_wire_y0 = 0;
  uint8_t constant_wire = 0;

  a_0 = ((a >> 0) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  h_u_arr_mul1_and_0_0_y0 = and_gate(a_0, b_0);
  h_u_arr_mul1_xor_constant_wire_y0 = xor_gate(a_0, b_0);
  h_u_arr_mul1_xnor_constant_wire_y0 = xnor_gate(a_0, b_0);
  constant_wire = and_gate(h_u_arr_mul1_xor_constant_wire_y0, h_u_arr_mul1_xnor_constant_wire_y0);

  out |= (h_u_arr_mul1_and_0_0_y0 & 0x01) << 0;
  out |= (constant_wire & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      assert((i * j) == h_u_arr_mul1(i,j));
    }
  }
  return 0;
}