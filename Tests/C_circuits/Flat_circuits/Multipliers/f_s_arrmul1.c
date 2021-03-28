#include <stdio.h>
#include <stdint.h>

int64_t f_s_arrmul1(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t b_0 = 0;
  uint8_t constant_wire_value_1_a_0 = 0;
  uint8_t constant_wire_value_1_b_0 = 0;
  uint8_t constant_wire_value_1_y0 = 0;
  uint8_t constant_wire_value_1_y1 = 0;
  uint8_t constant_wire_1 = 0;
  uint8_t f_s_arrmul1_and0_0_a_0 = 0;
  uint8_t f_s_arrmul1_and0_0_b_0 = 0;
  uint8_t f_s_arrmul1_and0_0_y0 = 0;
  uint8_t f_s_arrmul1_nor_zero_extend_constant_wire_1 = 0;
  uint8_t f_s_arrmul1_nor_zero_extend_f_s_arrmul1_and0_0_y0 = 0;
  uint8_t f_s_arrmul1_nor_zero_extend_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  constant_wire_value_1_a_0 = ((a_0 >> 0) & 0x01);
  constant_wire_value_1_b_0 = ((b_0 >> 0) & 0x01);
  constant_wire_value_1_y0 = constant_wire_value_1_a_0 ^ constant_wire_value_1_b_0;
  constant_wire_value_1_y1 = ~(constant_wire_value_1_a_0 ^ constant_wire_value_1_b_0);
  constant_wire_1 = constant_wire_value_1_y0 | constant_wire_value_1_y1;
  f_s_arrmul1_and0_0_a_0 = a_0;
  f_s_arrmul1_and0_0_b_0 = b_0;
  f_s_arrmul1_and0_0_y0 = f_s_arrmul1_and0_0_a_0 & f_s_arrmul1_and0_0_b_0;
  f_s_arrmul1_nor_zero_extend_constant_wire_1 = constant_wire_1;
  f_s_arrmul1_nor_zero_extend_f_s_arrmul1_and0_0_y0 = f_s_arrmul1_and0_0_y0;
  f_s_arrmul1_nor_zero_extend_y0 = ~(f_s_arrmul1_nor_zero_extend_constant_wire_1 | f_s_arrmul1_nor_zero_extend_f_s_arrmul1_and0_0_y0);

  out |= (f_s_arrmul1_and0_0_y0 & 0x01) << 0;
  out |= (f_s_arrmul1_nor_zero_extend_y0 & 0x01) << 1;
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
      
      assert(result == (int)f_s_arrmul1(i,j));
    }
  }
  return 0;
}