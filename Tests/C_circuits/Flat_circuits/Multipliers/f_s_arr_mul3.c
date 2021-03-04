#include <stdio.h>
#include <stdint.h>

int64_t f_s_arr_mul3(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t f_s_arr_mul3_xor_constant_wire_a_0 = 0;
  uint8_t f_s_arr_mul3_xor_constant_wire_b_0 = 0;
  uint8_t f_s_arr_mul3_xor_constant_wire_y0 = 0;
  uint8_t f_s_arr_mul3_xnor_constant_wire_a_0 = 0;
  uint8_t f_s_arr_mul3_xnor_constant_wire_b_0 = 0;
  uint8_t f_s_arr_mul3_xnor_constant_wire_y0 = 0;
  uint8_t f_s_arr_mul3_or_constant_wire_f_s_arr_mul3_xor_constant_wire_y0 = 0;
  uint8_t f_s_arr_mul3_or_constant_wire_f_s_arr_mul3_xnor_constant_wire_y0 = 0;
  uint8_t constant_wire = 0;
  uint8_t f_s_arr_mul3_and_0_0_a_0 = 0;
  uint8_t f_s_arr_mul3_and_0_0_b_0 = 0;
  uint8_t f_s_arr_mul3_and_0_0_y0 = 0;
  uint8_t f_s_arr_mul3_and_1_0_a_1 = 0;
  uint8_t f_s_arr_mul3_and_1_0_b_0 = 0;
  uint8_t f_s_arr_mul3_and_1_0_y0 = 0;
  uint8_t f_s_arr_mul3_nand_2_0_a_2 = 0;
  uint8_t f_s_arr_mul3_nand_2_0_b_0 = 0;
  uint8_t f_s_arr_mul3_nand_2_0_y0 = 0;
  uint8_t f_s_arr_mul3_and_0_1_a_0 = 0;
  uint8_t f_s_arr_mul3_and_0_1_b_1 = 0;
  uint8_t f_s_arr_mul3_and_0_1_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_0_1_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_1_0_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_1_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_1_y1 = 0;
  uint8_t f_s_arr_mul3_and_1_1_a_1 = 0;
  uint8_t f_s_arr_mul3_and_1_1_b_1 = 0;
  uint8_t f_s_arr_mul3_and_1_1_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_f_s_arr_mul3_and_1_1_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_f_s_arr_mul3_nand_2_0_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_y1 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_f_s_arr_mul3_ha_0_1_y1 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_y2 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_y3 = 0;
  uint8_t f_s_arr_mul3_fa_1_1_y4 = 0;
  uint8_t f_s_arr_mul3_nand_2_1_a_2 = 0;
  uint8_t f_s_arr_mul3_nand_2_1_b_1 = 0;
  uint8_t f_s_arr_mul3_nand_2_1_y0 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_f_s_arr_mul3_nand_2_1_y0 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_constant_wire = 0;
  uint8_t f_s_arr_mul3_fa_2_1_y0 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_y1 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_f_s_arr_mul3_fa_1_1_y4 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_y2 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_y3 = 0;
  uint8_t f_s_arr_mul3_fa_2_1_y4 = 0;
  uint8_t f_s_arr_mul3_nand_0_2_a_0 = 0;
  uint8_t f_s_arr_mul3_nand_0_2_b_2 = 0;
  uint8_t f_s_arr_mul3_nand_0_2_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_2_f_s_arr_mul3_nand_0_2_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_2_f_s_arr_mul3_fa_1_1_y2 = 0;
  uint8_t f_s_arr_mul3_ha_0_2_y0 = 0;
  uint8_t f_s_arr_mul3_ha_0_2_y1 = 0;
  uint8_t f_s_arr_mul3_nand_1_2_a_1 = 0;
  uint8_t f_s_arr_mul3_nand_1_2_b_2 = 0;
  uint8_t f_s_arr_mul3_nand_1_2_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_f_s_arr_mul3_nand_1_2_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_f_s_arr_mul3_fa_2_1_y2 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_y0 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_y1 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_f_s_arr_mul3_ha_0_2_y1 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_y2 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_y3 = 0;
  uint8_t f_s_arr_mul3_fa_1_2_y4 = 0;
  uint8_t f_s_arr_mul3_and_2_2_a_2 = 0;
  uint8_t f_s_arr_mul3_and_2_2_b_2 = 0;
  uint8_t f_s_arr_mul3_and_2_2_y0 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_f_s_arr_mul3_and_2_2_y0 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_2_1_y4 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_y0 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_y1 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_1_2_y4 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_y2 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_y3 = 0;
  uint8_t f_s_arr_mul3_fa_2_2_y4 = 0;
  uint8_t f_s_arr_mul3_xor_3_2_f_s_arr_mul3_fa_2_2_y4 = 0;
  uint8_t f_s_arr_mul3_xor_3_2_constant_wire = 0;
  uint8_t f_s_arr_mul3_xor_3_2_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  f_s_arr_mul3_xor_constant_wire_a_0 = a_0;
  f_s_arr_mul3_xor_constant_wire_b_0 = b_0;
  f_s_arr_mul3_xor_constant_wire_y0 = f_s_arr_mul3_xor_constant_wire_a_0 ^ f_s_arr_mul3_xor_constant_wire_b_0;
  f_s_arr_mul3_xnor_constant_wire_a_0 = a_0;
  f_s_arr_mul3_xnor_constant_wire_b_0 = b_0;
  f_s_arr_mul3_xnor_constant_wire_y0 = ~(f_s_arr_mul3_xnor_constant_wire_a_0 ^ f_s_arr_mul3_xnor_constant_wire_b_0);
  f_s_arr_mul3_or_constant_wire_f_s_arr_mul3_xor_constant_wire_y0 = f_s_arr_mul3_xor_constant_wire_y0;
  f_s_arr_mul3_or_constant_wire_f_s_arr_mul3_xnor_constant_wire_y0 = f_s_arr_mul3_xnor_constant_wire_y0;
  constant_wire = f_s_arr_mul3_or_constant_wire_f_s_arr_mul3_xor_constant_wire_y0 | f_s_arr_mul3_or_constant_wire_f_s_arr_mul3_xnor_constant_wire_y0;
  f_s_arr_mul3_and_0_0_a_0 = a_0;
  f_s_arr_mul3_and_0_0_b_0 = b_0;
  f_s_arr_mul3_and_0_0_y0 = f_s_arr_mul3_and_0_0_a_0 & f_s_arr_mul3_and_0_0_b_0;
  f_s_arr_mul3_and_1_0_a_1 = a_1;
  f_s_arr_mul3_and_1_0_b_0 = b_0;
  f_s_arr_mul3_and_1_0_y0 = f_s_arr_mul3_and_1_0_a_1 & f_s_arr_mul3_and_1_0_b_0;
  f_s_arr_mul3_nand_2_0_a_2 = a_2;
  f_s_arr_mul3_nand_2_0_b_0 = b_0;
  f_s_arr_mul3_nand_2_0_y0 = ~(f_s_arr_mul3_nand_2_0_a_2 & f_s_arr_mul3_nand_2_0_b_0);
  f_s_arr_mul3_and_0_1_a_0 = a_0;
  f_s_arr_mul3_and_0_1_b_1 = b_1;
  f_s_arr_mul3_and_0_1_y0 = f_s_arr_mul3_and_0_1_a_0 & f_s_arr_mul3_and_0_1_b_1;
  f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_0_1_y0 = ((f_s_arr_mul3_and_0_1_y0 >> 0) & 0x01);
  f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_1_0_y0 = ((f_s_arr_mul3_and_1_0_y0 >> 0) & 0x01);
  f_s_arr_mul3_ha_0_1_y0 = f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_0_1_y0 ^ f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_1_0_y0;
  f_s_arr_mul3_ha_0_1_y1 = f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_0_1_y0 & f_s_arr_mul3_ha_0_1_f_s_arr_mul3_and_1_0_y0;
  f_s_arr_mul3_and_1_1_a_1 = a_1;
  f_s_arr_mul3_and_1_1_b_1 = b_1;
  f_s_arr_mul3_and_1_1_y0 = f_s_arr_mul3_and_1_1_a_1 & f_s_arr_mul3_and_1_1_b_1;
  f_s_arr_mul3_fa_1_1_f_s_arr_mul3_and_1_1_y0 = ((f_s_arr_mul3_and_1_1_y0 >> 0) & 0x01);
  f_s_arr_mul3_fa_1_1_f_s_arr_mul3_nand_2_0_y0 = ((f_s_arr_mul3_nand_2_0_y0 >> 0) & 0x01);
  f_s_arr_mul3_fa_1_1_f_s_arr_mul3_ha_0_1_y1 = ((f_s_arr_mul3_ha_0_1_y1 >> 0) & 0x01);
  f_s_arr_mul3_fa_1_1_y0 = f_s_arr_mul3_fa_1_1_f_s_arr_mul3_and_1_1_y0 ^ f_s_arr_mul3_fa_1_1_f_s_arr_mul3_nand_2_0_y0;
  f_s_arr_mul3_fa_1_1_y1 = f_s_arr_mul3_fa_1_1_f_s_arr_mul3_and_1_1_y0 & f_s_arr_mul3_fa_1_1_f_s_arr_mul3_nand_2_0_y0;
  f_s_arr_mul3_fa_1_1_y2 = f_s_arr_mul3_fa_1_1_y0 ^ f_s_arr_mul3_fa_1_1_f_s_arr_mul3_ha_0_1_y1;
  f_s_arr_mul3_fa_1_1_y3 = f_s_arr_mul3_fa_1_1_y0 & f_s_arr_mul3_fa_1_1_f_s_arr_mul3_ha_0_1_y1;
  f_s_arr_mul3_fa_1_1_y4 = f_s_arr_mul3_fa_1_1_y1 | f_s_arr_mul3_fa_1_1_y3;
  f_s_arr_mul3_nand_2_1_a_2 = a_2;
  f_s_arr_mul3_nand_2_1_b_1 = b_1;
  f_s_arr_mul3_nand_2_1_y0 = ~(f_s_arr_mul3_nand_2_1_a_2 & f_s_arr_mul3_nand_2_1_b_1);
  f_s_arr_mul3_fa_2_1_f_s_arr_mul3_nand_2_1_y0 = ((f_s_arr_mul3_nand_2_1_y0 >> 0) & 0x01);
  f_s_arr_mul3_fa_2_1_constant_wire = ((constant_wire >> 0) & 0x01);
  f_s_arr_mul3_fa_2_1_f_s_arr_mul3_fa_1_1_y4 = ((f_s_arr_mul3_fa_1_1_y4 >> 0) & 0x01);
  f_s_arr_mul3_fa_2_1_y0 = f_s_arr_mul3_fa_2_1_f_s_arr_mul3_nand_2_1_y0 ^ f_s_arr_mul3_fa_2_1_constant_wire;
  f_s_arr_mul3_fa_2_1_y1 = f_s_arr_mul3_fa_2_1_f_s_arr_mul3_nand_2_1_y0 & f_s_arr_mul3_fa_2_1_constant_wire;
  f_s_arr_mul3_fa_2_1_y2 = f_s_arr_mul3_fa_2_1_y0 ^ f_s_arr_mul3_fa_2_1_f_s_arr_mul3_fa_1_1_y4;
  f_s_arr_mul3_fa_2_1_y3 = f_s_arr_mul3_fa_2_1_y0 & f_s_arr_mul3_fa_2_1_f_s_arr_mul3_fa_1_1_y4;
  f_s_arr_mul3_fa_2_1_y4 = f_s_arr_mul3_fa_2_1_y1 | f_s_arr_mul3_fa_2_1_y3;
  f_s_arr_mul3_nand_0_2_a_0 = a_0;
  f_s_arr_mul3_nand_0_2_b_2 = b_2;
  f_s_arr_mul3_nand_0_2_y0 = ~(f_s_arr_mul3_nand_0_2_a_0 & f_s_arr_mul3_nand_0_2_b_2);
  f_s_arr_mul3_ha_0_2_f_s_arr_mul3_nand_0_2_y0 = ((f_s_arr_mul3_nand_0_2_y0 >> 0) & 0x01);
  f_s_arr_mul3_ha_0_2_f_s_arr_mul3_fa_1_1_y2 = ((f_s_arr_mul3_fa_1_1_y2 >> 0) & 0x01);
  f_s_arr_mul3_ha_0_2_y0 = f_s_arr_mul3_ha_0_2_f_s_arr_mul3_nand_0_2_y0 ^ f_s_arr_mul3_ha_0_2_f_s_arr_mul3_fa_1_1_y2;
  f_s_arr_mul3_ha_0_2_y1 = f_s_arr_mul3_ha_0_2_f_s_arr_mul3_nand_0_2_y0 & f_s_arr_mul3_ha_0_2_f_s_arr_mul3_fa_1_1_y2;
  f_s_arr_mul3_nand_1_2_a_1 = a_1;
  f_s_arr_mul3_nand_1_2_b_2 = b_2;
  f_s_arr_mul3_nand_1_2_y0 = ~(f_s_arr_mul3_nand_1_2_a_1 & f_s_arr_mul3_nand_1_2_b_2);
  f_s_arr_mul3_fa_1_2_f_s_arr_mul3_nand_1_2_y0 = ((f_s_arr_mul3_nand_1_2_y0 >> 0) & 0x01);
  f_s_arr_mul3_fa_1_2_f_s_arr_mul3_fa_2_1_y2 = ((f_s_arr_mul3_fa_2_1_y2 >> 0) & 0x01);
  f_s_arr_mul3_fa_1_2_f_s_arr_mul3_ha_0_2_y1 = ((f_s_arr_mul3_ha_0_2_y1 >> 0) & 0x01);
  f_s_arr_mul3_fa_1_2_y0 = f_s_arr_mul3_fa_1_2_f_s_arr_mul3_nand_1_2_y0 ^ f_s_arr_mul3_fa_1_2_f_s_arr_mul3_fa_2_1_y2;
  f_s_arr_mul3_fa_1_2_y1 = f_s_arr_mul3_fa_1_2_f_s_arr_mul3_nand_1_2_y0 & f_s_arr_mul3_fa_1_2_f_s_arr_mul3_fa_2_1_y2;
  f_s_arr_mul3_fa_1_2_y2 = f_s_arr_mul3_fa_1_2_y0 ^ f_s_arr_mul3_fa_1_2_f_s_arr_mul3_ha_0_2_y1;
  f_s_arr_mul3_fa_1_2_y3 = f_s_arr_mul3_fa_1_2_y0 & f_s_arr_mul3_fa_1_2_f_s_arr_mul3_ha_0_2_y1;
  f_s_arr_mul3_fa_1_2_y4 = f_s_arr_mul3_fa_1_2_y1 | f_s_arr_mul3_fa_1_2_y3;
  f_s_arr_mul3_and_2_2_a_2 = a_2;
  f_s_arr_mul3_and_2_2_b_2 = b_2;
  f_s_arr_mul3_and_2_2_y0 = f_s_arr_mul3_and_2_2_a_2 & f_s_arr_mul3_and_2_2_b_2;
  f_s_arr_mul3_fa_2_2_f_s_arr_mul3_and_2_2_y0 = ((f_s_arr_mul3_and_2_2_y0 >> 0) & 0x01);
  f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_2_1_y4 = ((f_s_arr_mul3_fa_2_1_y4 >> 0) & 0x01);
  f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_1_2_y4 = ((f_s_arr_mul3_fa_1_2_y4 >> 0) & 0x01);
  f_s_arr_mul3_fa_2_2_y0 = f_s_arr_mul3_fa_2_2_f_s_arr_mul3_and_2_2_y0 ^ f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_2_1_y4;
  f_s_arr_mul3_fa_2_2_y1 = f_s_arr_mul3_fa_2_2_f_s_arr_mul3_and_2_2_y0 & f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_2_1_y4;
  f_s_arr_mul3_fa_2_2_y2 = f_s_arr_mul3_fa_2_2_y0 ^ f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_1_2_y4;
  f_s_arr_mul3_fa_2_2_y3 = f_s_arr_mul3_fa_2_2_y0 & f_s_arr_mul3_fa_2_2_f_s_arr_mul3_fa_1_2_y4;
  f_s_arr_mul3_fa_2_2_y4 = f_s_arr_mul3_fa_2_2_y1 | f_s_arr_mul3_fa_2_2_y3;
  f_s_arr_mul3_xor_3_2_f_s_arr_mul3_fa_2_2_y4 = f_s_arr_mul3_fa_2_2_y4;
  f_s_arr_mul3_xor_3_2_constant_wire = constant_wire;
  f_s_arr_mul3_xor_3_2_y0 = f_s_arr_mul3_xor_3_2_f_s_arr_mul3_fa_2_2_y4 ^ f_s_arr_mul3_xor_3_2_constant_wire;

  out |= (f_s_arr_mul3_and_0_0_y0 & 0x01) << 0;
  out |= (f_s_arr_mul3_ha_0_1_y0 & 0x01) << 1;
  out |= (f_s_arr_mul3_ha_0_2_y0 & 0x01) << 2;
  out |= (f_s_arr_mul3_fa_1_2_y2 & 0x01) << 3;
  out |= (f_s_arr_mul3_fa_2_2_y2 & 0x01) << 4;
  out |= (f_s_arr_mul3_xor_3_2_y0 & 0x01) << 5;
  return out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -4; i < 4; i++){
    for (int j = -4; j < 4; j++){
      result = i * j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 64 + result;  
      }
      
      assert(result == (int)f_s_arr_mul3(i,j));
    }
  }
  return 0;
}