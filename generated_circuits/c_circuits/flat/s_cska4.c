#include <stdio.h>
#include <stdint.h>

int64_t s_cska4(int64_t a, int64_t b){
  int8_t s_cska4_out = 0;
  uint8_t s_cska4_xor0 = 0;
  uint8_t s_cska4_ha0_xor0 = 0;
  uint8_t s_cska4_ha0_and0 = 0;
  uint8_t s_cska4_xor1 = 0;
  uint8_t s_cska4_fa0_xor0 = 0;
  uint8_t s_cska4_fa0_and0 = 0;
  uint8_t s_cska4_fa0_xor1 = 0;
  uint8_t s_cska4_fa0_and1 = 0;
  uint8_t s_cska4_fa0_or0 = 0;
  uint8_t s_cska4_xor2 = 0;
  uint8_t s_cska4_fa1_xor0 = 0;
  uint8_t s_cska4_fa1_and0 = 0;
  uint8_t s_cska4_fa1_xor1 = 0;
  uint8_t s_cska4_fa1_and1 = 0;
  uint8_t s_cska4_fa1_or0 = 0;
  uint8_t s_cska4_xor3 = 0;
  uint8_t s_cska4_fa2_xor0 = 0;
  uint8_t s_cska4_fa2_and0 = 0;
  uint8_t s_cska4_fa2_xor1 = 0;
  uint8_t s_cska4_fa2_and1 = 0;
  uint8_t s_cska4_fa2_or0 = 0;
  uint8_t s_cska4_and_propagate00 = 0;
  uint8_t s_cska4_and_propagate01 = 0;
  uint8_t s_cska4_and_propagate02 = 0;
  uint8_t s_cska4_mux2to10_not0 = 0;
  uint8_t s_cska4_mux2to10_and1 = 0;
  uint8_t s_cska4_xor4 = 0;
  uint8_t s_cska4_xor5 = 0;

  s_cska4_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  s_cska4_ha0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  s_cska4_ha0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  s_cska4_xor1 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  s_cska4_fa0_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  s_cska4_fa0_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  s_cska4_fa0_xor1 = ((s_cska4_fa0_xor0 >> 0) & 0x01) ^ ((s_cska4_ha0_and0 >> 0) & 0x01);
  s_cska4_fa0_and1 = ((s_cska4_fa0_xor0 >> 0) & 0x01) & ((s_cska4_ha0_and0 >> 0) & 0x01);
  s_cska4_fa0_or0 = ((s_cska4_fa0_and0 >> 0) & 0x01) | ((s_cska4_fa0_and1 >> 0) & 0x01);
  s_cska4_xor2 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  s_cska4_fa1_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  s_cska4_fa1_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  s_cska4_fa1_xor1 = ((s_cska4_fa1_xor0 >> 0) & 0x01) ^ ((s_cska4_fa0_or0 >> 0) & 0x01);
  s_cska4_fa1_and1 = ((s_cska4_fa1_xor0 >> 0) & 0x01) & ((s_cska4_fa0_or0 >> 0) & 0x01);
  s_cska4_fa1_or0 = ((s_cska4_fa1_and0 >> 0) & 0x01) | ((s_cska4_fa1_and1 >> 0) & 0x01);
  s_cska4_xor3 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_cska4_fa2_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_cska4_fa2_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  s_cska4_fa2_xor1 = ((s_cska4_fa2_xor0 >> 0) & 0x01) ^ ((s_cska4_fa1_or0 >> 0) & 0x01);
  s_cska4_fa2_and1 = ((s_cska4_fa2_xor0 >> 0) & 0x01) & ((s_cska4_fa1_or0 >> 0) & 0x01);
  s_cska4_fa2_or0 = ((s_cska4_fa2_and0 >> 0) & 0x01) | ((s_cska4_fa2_and1 >> 0) & 0x01);
  s_cska4_and_propagate00 = ((s_cska4_xor0 >> 0) & 0x01) & ((s_cska4_xor2 >> 0) & 0x01);
  s_cska4_and_propagate01 = ((s_cska4_xor1 >> 0) & 0x01) & ((s_cska4_xor3 >> 0) & 0x01);
  s_cska4_and_propagate02 = ((s_cska4_and_propagate00 >> 0) & 0x01) & ((s_cska4_and_propagate01 >> 0) & 0x01);
  s_cska4_mux2to10_not0 = ~(((s_cska4_and_propagate02 >> 0) & 0x01)) & 0x01;
  s_cska4_mux2to10_and1 = ((s_cska4_fa2_or0 >> 0) & 0x01) & ((s_cska4_mux2to10_not0 >> 0) & 0x01);
  s_cska4_xor4 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  s_cska4_xor5 = ((s_cska4_xor4 >> 0) & 0x01) ^ ((s_cska4_mux2to10_and1 >> 0) & 0x01);

  s_cska4_out |= ((s_cska4_ha0_xor0 >> 0) & 0x01ull) << 0;
  s_cska4_out |= ((s_cska4_fa0_xor1 >> 0) & 0x01ull) << 1;
  s_cska4_out |= ((s_cska4_fa1_xor1 >> 0) & 0x01ull) << 2;
  s_cska4_out |= ((s_cska4_fa2_xor1 >> 0) & 0x01ull) << 3;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 4;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 5;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 6;
  s_cska4_out |= ((s_cska4_xor5 >> 0) & 0x01ull) << 7;
  return s_cska4_out;
}