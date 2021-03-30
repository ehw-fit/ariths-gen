#include <stdio.h>
#include <stdint.h>

int64_t f_s_arrmul2(int64_t a, int64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t constant_wire_value_1_a_0 = 0;
  uint8_t constant_wire_value_1_b_0 = 0;
  uint8_t constant_wire_value_1_y0 = 0;
  uint8_t constant_wire_value_1_y1 = 0;
  uint8_t constant_wire_1 = 0;
  uint8_t f_s_arrmul2_and0_0_a_0 = 0;
  uint8_t f_s_arrmul2_and0_0_b_0 = 0;
  uint8_t f_s_arrmul2_and0_0_y0 = 0;
  uint8_t f_s_arrmul2_nand1_0_a_1 = 0;
  uint8_t f_s_arrmul2_nand1_0_b_0 = 0;
  uint8_t f_s_arrmul2_nand1_0_y0 = 0;
  uint8_t f_s_arrmul2_nand0_1_a_0 = 0;
  uint8_t f_s_arrmul2_nand0_1_b_1 = 0;
  uint8_t f_s_arrmul2_nand0_1_y0 = 0;
  uint8_t f_s_arrmul2_ha0_1_f_s_arrmul2_nand0_1_y0 = 0;
  uint8_t f_s_arrmul2_ha0_1_f_s_arrmul2_nand1_0_y0 = 0;
  uint8_t f_s_arrmul2_ha0_1_y0 = 0;
  uint8_t f_s_arrmul2_ha0_1_y1 = 0;
  uint8_t f_s_arrmul2_and1_1_a_1 = 0;
  uint8_t f_s_arrmul2_and1_1_b_1 = 0;
  uint8_t f_s_arrmul2_and1_1_y0 = 0;
  uint8_t f_s_arrmul2_fa1_1_f_s_arrmul2_and1_1_y0 = 0;
  uint8_t f_s_arrmul2_fa1_1_constant_wire_1 = 0;
  uint8_t f_s_arrmul2_fa1_1_y0 = 0;
  uint8_t f_s_arrmul2_fa1_1_y1 = 0;
  uint8_t f_s_arrmul2_fa1_1_f_s_arrmul2_ha0_1_y1 = 0;
  uint8_t f_s_arrmul2_fa1_1_y2 = 0;
  uint8_t f_s_arrmul2_fa1_1_y3 = 0;
  uint8_t f_s_arrmul2_fa1_1_y4 = 0;
  uint8_t f_s_arrmul2_xor2_1_f_s_arrmul2_fa1_1_y4 = 0;
  uint8_t f_s_arrmul2_xor2_1_constant_wire_1 = 0;
  uint8_t f_s_arrmul2_xor2_1_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  constant_wire_value_1_a_0 = ((a_0 >> 0) & 0x01);
  constant_wire_value_1_b_0 = ((b_0 >> 0) & 0x01);
  constant_wire_value_1_y0 = constant_wire_value_1_a_0 ^ constant_wire_value_1_b_0;
  constant_wire_value_1_y1 = ~(constant_wire_value_1_a_0 ^ constant_wire_value_1_b_0);
  constant_wire_1 = constant_wire_value_1_y0 | constant_wire_value_1_y1;
  f_s_arrmul2_and0_0_a_0 = a_0;
  f_s_arrmul2_and0_0_b_0 = b_0;
  f_s_arrmul2_and0_0_y0 = f_s_arrmul2_and0_0_a_0 & f_s_arrmul2_and0_0_b_0;
  f_s_arrmul2_nand1_0_a_1 = a_1;
  f_s_arrmul2_nand1_0_b_0 = b_0;
  f_s_arrmul2_nand1_0_y0 = ~(f_s_arrmul2_nand1_0_a_1 & f_s_arrmul2_nand1_0_b_0);
  f_s_arrmul2_nand0_1_a_0 = a_0;
  f_s_arrmul2_nand0_1_b_1 = b_1;
  f_s_arrmul2_nand0_1_y0 = ~(f_s_arrmul2_nand0_1_a_0 & f_s_arrmul2_nand0_1_b_1);
  f_s_arrmul2_ha0_1_f_s_arrmul2_nand0_1_y0 = ((f_s_arrmul2_nand0_1_y0 >> 0) & 0x01);
  f_s_arrmul2_ha0_1_f_s_arrmul2_nand1_0_y0 = ((f_s_arrmul2_nand1_0_y0 >> 0) & 0x01);
  f_s_arrmul2_ha0_1_y0 = f_s_arrmul2_ha0_1_f_s_arrmul2_nand0_1_y0 ^ f_s_arrmul2_ha0_1_f_s_arrmul2_nand1_0_y0;
  f_s_arrmul2_ha0_1_y1 = f_s_arrmul2_ha0_1_f_s_arrmul2_nand0_1_y0 & f_s_arrmul2_ha0_1_f_s_arrmul2_nand1_0_y0;
  f_s_arrmul2_and1_1_a_1 = a_1;
  f_s_arrmul2_and1_1_b_1 = b_1;
  f_s_arrmul2_and1_1_y0 = f_s_arrmul2_and1_1_a_1 & f_s_arrmul2_and1_1_b_1;
  f_s_arrmul2_fa1_1_f_s_arrmul2_and1_1_y0 = ((f_s_arrmul2_and1_1_y0 >> 0) & 0x01);
  f_s_arrmul2_fa1_1_constant_wire_1 = ((constant_wire_1 >> 0) & 0x01);
  f_s_arrmul2_fa1_1_f_s_arrmul2_ha0_1_y1 = ((f_s_arrmul2_ha0_1_y1 >> 0) & 0x01);
  f_s_arrmul2_fa1_1_y0 = f_s_arrmul2_fa1_1_f_s_arrmul2_and1_1_y0 ^ f_s_arrmul2_fa1_1_constant_wire_1;
  f_s_arrmul2_fa1_1_y1 = f_s_arrmul2_fa1_1_f_s_arrmul2_and1_1_y0 & f_s_arrmul2_fa1_1_constant_wire_1;
  f_s_arrmul2_fa1_1_y2 = f_s_arrmul2_fa1_1_y0 ^ f_s_arrmul2_fa1_1_f_s_arrmul2_ha0_1_y1;
  f_s_arrmul2_fa1_1_y3 = f_s_arrmul2_fa1_1_y0 & f_s_arrmul2_fa1_1_f_s_arrmul2_ha0_1_y1;
  f_s_arrmul2_fa1_1_y4 = f_s_arrmul2_fa1_1_y1 | f_s_arrmul2_fa1_1_y3;
  f_s_arrmul2_xor2_1_f_s_arrmul2_fa1_1_y4 = f_s_arrmul2_fa1_1_y4;
  f_s_arrmul2_xor2_1_constant_wire_1 = constant_wire_1;
  f_s_arrmul2_xor2_1_y0 = f_s_arrmul2_xor2_1_f_s_arrmul2_fa1_1_y4 ^ f_s_arrmul2_xor2_1_constant_wire_1;

  out |= (f_s_arrmul2_and0_0_y0 & 0x01) << 0;
  out |= (f_s_arrmul2_ha0_1_y0 & 0x01) << 1;
  out |= (f_s_arrmul2_fa1_1_y2 & 0x01) << 2;
  out |= (f_s_arrmul2_xor2_1_y0 & 0x01) << 3;
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
      
      assert(result == (int)f_s_arrmul2(i,j));
    }
  }
  return 0;
}