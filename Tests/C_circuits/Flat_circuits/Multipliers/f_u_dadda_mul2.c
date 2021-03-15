#include <stdio.h>
#include <stdint.h>

uint64_t f_u_dadda_mul2(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t f_u_dadda_mul2_and_0_0_a_0 = 0;
  uint8_t f_u_dadda_mul2_and_0_0_b_0 = 0;
  uint8_t f_u_dadda_mul2_and_0_0_y0 = 0;
  uint8_t f_u_dadda_mul2_and_1_0_a_1 = 0;
  uint8_t f_u_dadda_mul2_and_1_0_b_0 = 0;
  uint8_t f_u_dadda_mul2_and_1_0_y0 = 0;
  uint8_t f_u_dadda_mul2_and_0_1_a_0 = 0;
  uint8_t f_u_dadda_mul2_and_0_1_b_1 = 0;
  uint8_t f_u_dadda_mul2_and_0_1_y0 = 0;
  uint8_t f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_1_0_y0 = 0;
  uint8_t f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_0_1_y0 = 0;
  uint8_t f_u_dadda_mul2_ha0_y0 = 0;
  uint8_t f_u_dadda_mul2_ha0_y1 = 0;
  uint8_t f_u_dadda_mul2_and_1_1_a_1 = 0;
  uint8_t f_u_dadda_mul2_and_1_1_b_1 = 0;
  uint8_t f_u_dadda_mul2_and_1_1_y0 = 0;
  uint8_t f_u_dadda_mul2_ha1_f_u_dadda_mul2_ha0_y1 = 0;
  uint8_t f_u_dadda_mul2_ha1_f_u_dadda_mul2_and_1_1_y0 = 0;
  uint8_t f_u_dadda_mul2_ha1_y0 = 0;
  uint8_t f_u_dadda_mul2_ha1_y1 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  f_u_dadda_mul2_and_0_0_a_0 = a_0;
  f_u_dadda_mul2_and_0_0_b_0 = b_0;
  f_u_dadda_mul2_and_0_0_y0 = f_u_dadda_mul2_and_0_0_a_0 & f_u_dadda_mul2_and_0_0_b_0;
  f_u_dadda_mul2_and_1_0_a_1 = a_1;
  f_u_dadda_mul2_and_1_0_b_0 = b_0;
  f_u_dadda_mul2_and_1_0_y0 = f_u_dadda_mul2_and_1_0_a_1 & f_u_dadda_mul2_and_1_0_b_0;
  f_u_dadda_mul2_and_0_1_a_0 = a_0;
  f_u_dadda_mul2_and_0_1_b_1 = b_1;
  f_u_dadda_mul2_and_0_1_y0 = f_u_dadda_mul2_and_0_1_a_0 & f_u_dadda_mul2_and_0_1_b_1;
  f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_1_0_y0 = ((f_u_dadda_mul2_and_1_0_y0 >> 0) & 0x01);
  f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_0_1_y0 = ((f_u_dadda_mul2_and_0_1_y0 >> 0) & 0x01);
  f_u_dadda_mul2_ha0_y0 = f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_1_0_y0 ^ f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_0_1_y0;
  f_u_dadda_mul2_ha0_y1 = f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_1_0_y0 & f_u_dadda_mul2_ha0_f_u_dadda_mul2_and_0_1_y0;
  f_u_dadda_mul2_and_1_1_a_1 = a_1;
  f_u_dadda_mul2_and_1_1_b_1 = b_1;
  f_u_dadda_mul2_and_1_1_y0 = f_u_dadda_mul2_and_1_1_a_1 & f_u_dadda_mul2_and_1_1_b_1;
  f_u_dadda_mul2_ha1_f_u_dadda_mul2_ha0_y1 = ((f_u_dadda_mul2_ha0_y1 >> 0) & 0x01);
  f_u_dadda_mul2_ha1_f_u_dadda_mul2_and_1_1_y0 = ((f_u_dadda_mul2_and_1_1_y0 >> 0) & 0x01);
  f_u_dadda_mul2_ha1_y0 = f_u_dadda_mul2_ha1_f_u_dadda_mul2_ha0_y1 ^ f_u_dadda_mul2_ha1_f_u_dadda_mul2_and_1_1_y0;
  f_u_dadda_mul2_ha1_y1 = f_u_dadda_mul2_ha1_f_u_dadda_mul2_ha0_y1 & f_u_dadda_mul2_ha1_f_u_dadda_mul2_and_1_1_y0;

  out |= (f_u_dadda_mul2_and_0_0_y0 & 0x01) << 0;
  out |= (f_u_dadda_mul2_ha0_y0 & 0x01) << 1;
  out |= (f_u_dadda_mul2_ha1_y0 & 0x01) << 2;
  out |= (f_u_dadda_mul2_ha1_y1 & 0x01) << 3;
  return out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      assert((i * j) == f_u_dadda_mul2(i,j));
    }
  }
  return 0;
}