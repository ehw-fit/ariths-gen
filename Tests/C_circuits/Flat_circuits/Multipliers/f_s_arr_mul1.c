#include <stdio.h>
#include <stdint.h>

int64_t f_s_arr_mul1(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t b_0 = 0;
  uint8_t f_s_arr_mul1_xor_constant_wire_a_0 = 0;
  uint8_t f_s_arr_mul1_xor_constant_wire_b_0 = 0;
  uint8_t f_s_arr_mul1_xor_constant_wire_y0 = 0;
  uint8_t f_s_arr_mul1_xnor_constant_wire_a_0 = 0;
  uint8_t f_s_arr_mul1_xnor_constant_wire_b_0 = 0;
  uint8_t f_s_arr_mul1_xnor_constant_wire_y0 = 0;
  uint8_t f_s_arr_mul1_or_constant_wire_f_s_arr_mul1_xor_constant_wire_y0 = 0;
  uint8_t f_s_arr_mul1_or_constant_wire_f_s_arr_mul1_xnor_constant_wire_y0 = 0;
  uint8_t constant_wire = 0;
  uint8_t f_s_arr_mul1_and_0_0_a_0 = 0;
  uint8_t f_s_arr_mul1_and_0_0_b_0 = 0;
  uint8_t f_s_arr_mul1_and_0_0_y0 = 0;
  uint8_t f_s_arr_mul1_nor_zero_extend_constant_wire = 0;
  uint8_t f_s_arr_mul1_nor_zero_extend_f_s_arr_mul1_and_0_0_y0 = 0;
  uint8_t f_s_arr_mul1_nor_zero_extend_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  f_s_arr_mul1_xor_constant_wire_a_0 = a_0;
  f_s_arr_mul1_xor_constant_wire_b_0 = b_0;
  f_s_arr_mul1_xor_constant_wire_y0 = f_s_arr_mul1_xor_constant_wire_a_0 ^ f_s_arr_mul1_xor_constant_wire_b_0;
  f_s_arr_mul1_xnor_constant_wire_a_0 = a_0;
  f_s_arr_mul1_xnor_constant_wire_b_0 = b_0;
  f_s_arr_mul1_xnor_constant_wire_y0 = ~(f_s_arr_mul1_xnor_constant_wire_a_0 ^ f_s_arr_mul1_xnor_constant_wire_b_0);
  f_s_arr_mul1_or_constant_wire_f_s_arr_mul1_xor_constant_wire_y0 = f_s_arr_mul1_xor_constant_wire_y0;
  f_s_arr_mul1_or_constant_wire_f_s_arr_mul1_xnor_constant_wire_y0 = f_s_arr_mul1_xnor_constant_wire_y0;
  constant_wire = f_s_arr_mul1_or_constant_wire_f_s_arr_mul1_xor_constant_wire_y0 | f_s_arr_mul1_or_constant_wire_f_s_arr_mul1_xnor_constant_wire_y0;
  f_s_arr_mul1_and_0_0_a_0 = a_0;
  f_s_arr_mul1_and_0_0_b_0 = b_0;
  f_s_arr_mul1_and_0_0_y0 = f_s_arr_mul1_and_0_0_a_0 & f_s_arr_mul1_and_0_0_b_0;
  f_s_arr_mul1_nor_zero_extend_constant_wire = constant_wire;
  f_s_arr_mul1_nor_zero_extend_f_s_arr_mul1_and_0_0_y0 = f_s_arr_mul1_and_0_0_y0;
  f_s_arr_mul1_nor_zero_extend_y0 = ~(f_s_arr_mul1_nor_zero_extend_constant_wire | f_s_arr_mul1_nor_zero_extend_f_s_arr_mul1_and_0_0_y0);

  out |= (f_s_arr_mul1_and_0_0_y0 & 0x01) << 0;
  out |= (f_s_arr_mul1_nor_zero_extend_y0 & 0x01) << 1;
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
      
      assert(result == (int)f_s_arr_mul1(i,j));
    }
  }
  return 0;
}