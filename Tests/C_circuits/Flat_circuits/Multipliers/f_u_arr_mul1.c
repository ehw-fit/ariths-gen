#include <stdio.h>
#include <stdint.h>

uint64_t f_u_arr_mul1(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t b_0 = 0;
  uint8_t f_u_arr_mul1_and_0_0_a_0 = 0;
  uint8_t f_u_arr_mul1_and_0_0_b_0 = 0;
  uint8_t f_u_arr_mul1_and_0_0_y0 = 0;
  uint8_t f_u_arr_mul1_xor_constant_wire_a_0 = 0;
  uint8_t f_u_arr_mul1_xor_constant_wire_b_0 = 0;
  uint8_t f_u_arr_mul1_xor_constant_wire_y0 = 0;
  uint8_t f_u_arr_mul1_xnor_constant_wire_a_0 = 0;
  uint8_t f_u_arr_mul1_xnor_constant_wire_b_0 = 0;
  uint8_t f_u_arr_mul1_xnor_constant_wire_y0 = 0;
  uint8_t f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xor_constant_wire_y0 = 0;
  uint8_t f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xnor_constant_wire_y0 = 0;
  uint8_t constant_wire = 0;

  a_0 = ((a >> 0) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  f_u_arr_mul1_and_0_0_a_0 = a_0;
  f_u_arr_mul1_and_0_0_b_0 = b_0;
  f_u_arr_mul1_and_0_0_y0 = f_u_arr_mul1_and_0_0_a_0 & f_u_arr_mul1_and_0_0_b_0;
  f_u_arr_mul1_xor_constant_wire_a_0 = a_0;
  f_u_arr_mul1_xor_constant_wire_b_0 = b_0;
  f_u_arr_mul1_xor_constant_wire_y0 = f_u_arr_mul1_xor_constant_wire_a_0 ^ f_u_arr_mul1_xor_constant_wire_b_0;
  f_u_arr_mul1_xnor_constant_wire_a_0 = a_0;
  f_u_arr_mul1_xnor_constant_wire_b_0 = b_0;
  f_u_arr_mul1_xnor_constant_wire_y0 = ~(f_u_arr_mul1_xnor_constant_wire_a_0 ^ f_u_arr_mul1_xnor_constant_wire_b_0);
  f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xor_constant_wire_y0 = f_u_arr_mul1_xor_constant_wire_y0;
  f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xnor_constant_wire_y0 = f_u_arr_mul1_xnor_constant_wire_y0;
  constant_wire = f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xor_constant_wire_y0 & f_u_arr_mul1_and_constant_wire_f_u_arr_mul1_xnor_constant_wire_y0;

  out |= (f_u_arr_mul1_and_0_0_y0 & 0x01) << 0;
  out |= (constant_wire & 0x01) << 1;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      assert((i * j) == f_u_arr_mul1(i,j));
    }
  }
  return 0;
}