#include <stdio.h>
#include <stdint.h>

int64_t f_s_arrmul4(int64_t a, int64_t b){
  uint8_t f_s_arrmul4_out = 0;
  uint8_t f_s_arrmul4_and0_0 = 0;
  uint8_t f_s_arrmul4_and1_0 = 0;
  uint8_t f_s_arrmul4_and2_0 = 0;
  uint8_t f_s_arrmul4_nand3_0 = 0;
  uint8_t f_s_arrmul4_and0_1 = 0;
  uint8_t f_s_arrmul4_ha0_1_xor0 = 0;
  uint8_t f_s_arrmul4_ha0_1_and0 = 0;
  uint8_t f_s_arrmul4_and1_1 = 0;
  uint8_t f_s_arrmul4_fa1_1_xor0 = 0;
  uint8_t f_s_arrmul4_fa1_1_and0 = 0;
  uint8_t f_s_arrmul4_fa1_1_xor1 = 0;
  uint8_t f_s_arrmul4_fa1_1_and1 = 0;
  uint8_t f_s_arrmul4_fa1_1_or0 = 0;
  uint8_t f_s_arrmul4_and2_1 = 0;
  uint8_t f_s_arrmul4_fa2_1_xor0 = 0;
  uint8_t f_s_arrmul4_fa2_1_and0 = 0;
  uint8_t f_s_arrmul4_fa2_1_xor1 = 0;
  uint8_t f_s_arrmul4_fa2_1_and1 = 0;
  uint8_t f_s_arrmul4_fa2_1_or0 = 0;
  uint8_t f_s_arrmul4_nand3_1 = 0;
  uint8_t f_s_arrmul4_fa3_1_xor0 = 0;
  uint8_t f_s_arrmul4_fa3_1_xor1 = 0;
  uint8_t f_s_arrmul4_fa3_1_and1 = 0;
  uint8_t f_s_arrmul4_fa3_1_or0 = 0;
  uint8_t f_s_arrmul4_and0_2 = 0;
  uint8_t f_s_arrmul4_ha0_2_xor0 = 0;
  uint8_t f_s_arrmul4_ha0_2_and0 = 0;
  uint8_t f_s_arrmul4_and1_2 = 0;
  uint8_t f_s_arrmul4_fa1_2_xor0 = 0;
  uint8_t f_s_arrmul4_fa1_2_and0 = 0;
  uint8_t f_s_arrmul4_fa1_2_xor1 = 0;
  uint8_t f_s_arrmul4_fa1_2_and1 = 0;
  uint8_t f_s_arrmul4_fa1_2_or0 = 0;
  uint8_t f_s_arrmul4_and2_2 = 0;
  uint8_t f_s_arrmul4_fa2_2_xor0 = 0;
  uint8_t f_s_arrmul4_fa2_2_and0 = 0;
  uint8_t f_s_arrmul4_fa2_2_xor1 = 0;
  uint8_t f_s_arrmul4_fa2_2_and1 = 0;
  uint8_t f_s_arrmul4_fa2_2_or0 = 0;
  uint8_t f_s_arrmul4_nand3_2 = 0;
  uint8_t f_s_arrmul4_fa3_2_xor0 = 0;
  uint8_t f_s_arrmul4_fa3_2_and0 = 0;
  uint8_t f_s_arrmul4_fa3_2_xor1 = 0;
  uint8_t f_s_arrmul4_fa3_2_and1 = 0;
  uint8_t f_s_arrmul4_fa3_2_or0 = 0;
  uint8_t f_s_arrmul4_nand0_3 = 0;
  uint8_t f_s_arrmul4_ha0_3_xor0 = 0;
  uint8_t f_s_arrmul4_ha0_3_and0 = 0;
  uint8_t f_s_arrmul4_nand1_3 = 0;
  uint8_t f_s_arrmul4_fa1_3_xor0 = 0;
  uint8_t f_s_arrmul4_fa1_3_and0 = 0;
  uint8_t f_s_arrmul4_fa1_3_xor1 = 0;
  uint8_t f_s_arrmul4_fa1_3_and1 = 0;
  uint8_t f_s_arrmul4_fa1_3_or0 = 0;
  uint8_t f_s_arrmul4_nand2_3 = 0;
  uint8_t f_s_arrmul4_fa2_3_xor0 = 0;
  uint8_t f_s_arrmul4_fa2_3_and0 = 0;
  uint8_t f_s_arrmul4_fa2_3_xor1 = 0;
  uint8_t f_s_arrmul4_fa2_3_and1 = 0;
  uint8_t f_s_arrmul4_fa2_3_or0 = 0;
  uint8_t f_s_arrmul4_and3_3 = 0;
  uint8_t f_s_arrmul4_fa3_3_xor0 = 0;
  uint8_t f_s_arrmul4_fa3_3_and0 = 0;
  uint8_t f_s_arrmul4_fa3_3_xor1 = 0;
  uint8_t f_s_arrmul4_fa3_3_and1 = 0;
  uint8_t f_s_arrmul4_fa3_3_or0 = 0;
  uint8_t f_s_arrmul4_xor4_3 = 0;

  f_s_arrmul4_and0_0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_s_arrmul4_and1_0 = ((a >> 1) & 0x01) & ((b >> 0) & 0x01);
  f_s_arrmul4_and2_0 = ((a >> 2) & 0x01) & ((b >> 0) & 0x01);
  f_s_arrmul4_nand3_0 = ~(((a >> 3) & 0x01) & ((b >> 0) & 0x01)) & 0x01;
  f_s_arrmul4_and0_1 = ((a >> 0) & 0x01) & ((b >> 1) & 0x01);
  f_s_arrmul4_ha0_1_xor0 = ((f_s_arrmul4_and0_1 >> 0) & 0x01) ^ ((f_s_arrmul4_and1_0 >> 0) & 0x01);
  f_s_arrmul4_ha0_1_and0 = ((f_s_arrmul4_and0_1 >> 0) & 0x01) & ((f_s_arrmul4_and1_0 >> 0) & 0x01);
  f_s_arrmul4_and1_1 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_s_arrmul4_fa1_1_xor0 = ((f_s_arrmul4_and1_1 >> 0) & 0x01) ^ ((f_s_arrmul4_and2_0 >> 0) & 0x01);
  f_s_arrmul4_fa1_1_and0 = ((f_s_arrmul4_and1_1 >> 0) & 0x01) & ((f_s_arrmul4_and2_0 >> 0) & 0x01);
  f_s_arrmul4_fa1_1_xor1 = ((f_s_arrmul4_fa1_1_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_ha0_1_and0 >> 0) & 0x01);
  f_s_arrmul4_fa1_1_and1 = ((f_s_arrmul4_fa1_1_xor0 >> 0) & 0x01) & ((f_s_arrmul4_ha0_1_and0 >> 0) & 0x01);
  f_s_arrmul4_fa1_1_or0 = ((f_s_arrmul4_fa1_1_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa1_1_and1 >> 0) & 0x01);
  f_s_arrmul4_and2_1 = ((a >> 2) & 0x01) & ((b >> 1) & 0x01);
  f_s_arrmul4_fa2_1_xor0 = ((f_s_arrmul4_and2_1 >> 0) & 0x01) ^ ((f_s_arrmul4_nand3_0 >> 0) & 0x01);
  f_s_arrmul4_fa2_1_and0 = ((f_s_arrmul4_and2_1 >> 0) & 0x01) & ((f_s_arrmul4_nand3_0 >> 0) & 0x01);
  f_s_arrmul4_fa2_1_xor1 = ((f_s_arrmul4_fa2_1_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_fa1_1_or0 >> 0) & 0x01);
  f_s_arrmul4_fa2_1_and1 = ((f_s_arrmul4_fa2_1_xor0 >> 0) & 0x01) & ((f_s_arrmul4_fa1_1_or0 >> 0) & 0x01);
  f_s_arrmul4_fa2_1_or0 = ((f_s_arrmul4_fa2_1_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa2_1_and1 >> 0) & 0x01);
  f_s_arrmul4_nand3_1 = ~(((a >> 3) & 0x01) & ((b >> 1) & 0x01)) & 0x01;
  f_s_arrmul4_fa3_1_xor0 = ~(((f_s_arrmul4_nand3_1 >> 0) & 0x01)) & 0x01;
  f_s_arrmul4_fa3_1_xor1 = ((f_s_arrmul4_fa3_1_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_fa2_1_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_1_and1 = ((f_s_arrmul4_fa3_1_xor0 >> 0) & 0x01) & ((f_s_arrmul4_fa2_1_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_1_or0 = ((f_s_arrmul4_nand3_1 >> 0) & 0x01) | ((f_s_arrmul4_fa3_1_and1 >> 0) & 0x01);
  f_s_arrmul4_and0_2 = ((a >> 0) & 0x01) & ((b >> 2) & 0x01);
  f_s_arrmul4_ha0_2_xor0 = ((f_s_arrmul4_and0_2 >> 0) & 0x01) ^ ((f_s_arrmul4_fa1_1_xor1 >> 0) & 0x01);
  f_s_arrmul4_ha0_2_and0 = ((f_s_arrmul4_and0_2 >> 0) & 0x01) & ((f_s_arrmul4_fa1_1_xor1 >> 0) & 0x01);
  f_s_arrmul4_and1_2 = ((a >> 1) & 0x01) & ((b >> 2) & 0x01);
  f_s_arrmul4_fa1_2_xor0 = ((f_s_arrmul4_and1_2 >> 0) & 0x01) ^ ((f_s_arrmul4_fa2_1_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa1_2_and0 = ((f_s_arrmul4_and1_2 >> 0) & 0x01) & ((f_s_arrmul4_fa2_1_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa1_2_xor1 = ((f_s_arrmul4_fa1_2_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_ha0_2_and0 >> 0) & 0x01);
  f_s_arrmul4_fa1_2_and1 = ((f_s_arrmul4_fa1_2_xor0 >> 0) & 0x01) & ((f_s_arrmul4_ha0_2_and0 >> 0) & 0x01);
  f_s_arrmul4_fa1_2_or0 = ((f_s_arrmul4_fa1_2_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa1_2_and1 >> 0) & 0x01);
  f_s_arrmul4_and2_2 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_s_arrmul4_fa2_2_xor0 = ((f_s_arrmul4_and2_2 >> 0) & 0x01) ^ ((f_s_arrmul4_fa3_1_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa2_2_and0 = ((f_s_arrmul4_and2_2 >> 0) & 0x01) & ((f_s_arrmul4_fa3_1_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa2_2_xor1 = ((f_s_arrmul4_fa2_2_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_fa1_2_or0 >> 0) & 0x01);
  f_s_arrmul4_fa2_2_and1 = ((f_s_arrmul4_fa2_2_xor0 >> 0) & 0x01) & ((f_s_arrmul4_fa1_2_or0 >> 0) & 0x01);
  f_s_arrmul4_fa2_2_or0 = ((f_s_arrmul4_fa2_2_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa2_2_and1 >> 0) & 0x01);
  f_s_arrmul4_nand3_2 = ~(((a >> 3) & 0x01) & ((b >> 2) & 0x01)) & 0x01;
  f_s_arrmul4_fa3_2_xor0 = ((f_s_arrmul4_nand3_2 >> 0) & 0x01) ^ ((f_s_arrmul4_fa3_1_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_2_and0 = ((f_s_arrmul4_nand3_2 >> 0) & 0x01) & ((f_s_arrmul4_fa3_1_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_2_xor1 = ((f_s_arrmul4_fa3_2_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_fa2_2_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_2_and1 = ((f_s_arrmul4_fa3_2_xor0 >> 0) & 0x01) & ((f_s_arrmul4_fa2_2_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_2_or0 = ((f_s_arrmul4_fa3_2_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa3_2_and1 >> 0) & 0x01);
  f_s_arrmul4_nand0_3 = ~(((a >> 0) & 0x01) & ((b >> 3) & 0x01)) & 0x01;
  f_s_arrmul4_ha0_3_xor0 = ((f_s_arrmul4_nand0_3 >> 0) & 0x01) ^ ((f_s_arrmul4_fa1_2_xor1 >> 0) & 0x01);
  f_s_arrmul4_ha0_3_and0 = ((f_s_arrmul4_nand0_3 >> 0) & 0x01) & ((f_s_arrmul4_fa1_2_xor1 >> 0) & 0x01);
  f_s_arrmul4_nand1_3 = ~(((a >> 1) & 0x01) & ((b >> 3) & 0x01)) & 0x01;
  f_s_arrmul4_fa1_3_xor0 = ((f_s_arrmul4_nand1_3 >> 0) & 0x01) ^ ((f_s_arrmul4_fa2_2_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa1_3_and0 = ((f_s_arrmul4_nand1_3 >> 0) & 0x01) & ((f_s_arrmul4_fa2_2_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa1_3_xor1 = ((f_s_arrmul4_fa1_3_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_ha0_3_and0 >> 0) & 0x01);
  f_s_arrmul4_fa1_3_and1 = ((f_s_arrmul4_fa1_3_xor0 >> 0) & 0x01) & ((f_s_arrmul4_ha0_3_and0 >> 0) & 0x01);
  f_s_arrmul4_fa1_3_or0 = ((f_s_arrmul4_fa1_3_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa1_3_and1 >> 0) & 0x01);
  f_s_arrmul4_nand2_3 = ~(((a >> 2) & 0x01) & ((b >> 3) & 0x01)) & 0x01;
  f_s_arrmul4_fa2_3_xor0 = ((f_s_arrmul4_nand2_3 >> 0) & 0x01) ^ ((f_s_arrmul4_fa3_2_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa2_3_and0 = ((f_s_arrmul4_nand2_3 >> 0) & 0x01) & ((f_s_arrmul4_fa3_2_xor1 >> 0) & 0x01);
  f_s_arrmul4_fa2_3_xor1 = ((f_s_arrmul4_fa2_3_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_fa1_3_or0 >> 0) & 0x01);
  f_s_arrmul4_fa2_3_and1 = ((f_s_arrmul4_fa2_3_xor0 >> 0) & 0x01) & ((f_s_arrmul4_fa1_3_or0 >> 0) & 0x01);
  f_s_arrmul4_fa2_3_or0 = ((f_s_arrmul4_fa2_3_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa2_3_and1 >> 0) & 0x01);
  f_s_arrmul4_and3_3 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_s_arrmul4_fa3_3_xor0 = ((f_s_arrmul4_and3_3 >> 0) & 0x01) ^ ((f_s_arrmul4_fa3_2_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_3_and0 = ((f_s_arrmul4_and3_3 >> 0) & 0x01) & ((f_s_arrmul4_fa3_2_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_3_xor1 = ((f_s_arrmul4_fa3_3_xor0 >> 0) & 0x01) ^ ((f_s_arrmul4_fa2_3_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_3_and1 = ((f_s_arrmul4_fa3_3_xor0 >> 0) & 0x01) & ((f_s_arrmul4_fa2_3_or0 >> 0) & 0x01);
  f_s_arrmul4_fa3_3_or0 = ((f_s_arrmul4_fa3_3_and0 >> 0) & 0x01) | ((f_s_arrmul4_fa3_3_and1 >> 0) & 0x01);
  f_s_arrmul4_xor4_3 = ~(((f_s_arrmul4_fa3_3_or0 >> 0) & 0x01)) & 0x01;

  f_s_arrmul4_out |= ((f_s_arrmul4_and0_0 >> 0) & 0x01) << 0;
  f_s_arrmul4_out |= ((f_s_arrmul4_ha0_1_xor0 >> 0) & 0x01) << 1;
  f_s_arrmul4_out |= ((f_s_arrmul4_ha0_2_xor0 >> 0) & 0x01) << 2;
  f_s_arrmul4_out |= ((f_s_arrmul4_ha0_3_xor0 >> 0) & 0x01) << 3;
  f_s_arrmul4_out |= ((f_s_arrmul4_fa1_3_xor1 >> 0) & 0x01) << 4;
  f_s_arrmul4_out |= ((f_s_arrmul4_fa2_3_xor1 >> 0) & 0x01) << 5;
  f_s_arrmul4_out |= ((f_s_arrmul4_fa3_3_xor1 >> 0) & 0x01) << 6;
  f_s_arrmul4_out |= ((f_s_arrmul4_xor4_3 >> 0) & 0x01) << 7;
  return f_s_arrmul4_out;
}

#include <assert.h>
int main(){
  int result = 0;
  for (int i = -8; i < 8; i++){
    for (int j = -8; j < 8; j++){
      result = i * j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 256 + result;  
      }
      
      assert(result == (int)f_s_arrmul4(i,j));
    }
  }
  return 0;
}