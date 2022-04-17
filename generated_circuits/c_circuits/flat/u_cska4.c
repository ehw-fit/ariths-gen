#include <stdio.h>
#include <stdint.h>

uint64_t u_cska4(uint64_t a, uint64_t b){
  uint8_t u_cska4_out = 0;
  uint8_t u_cska4_xor0 = 0;
  uint8_t u_cska4_ha0_xor0 = 0;
  uint8_t u_cska4_ha0_and0 = 0;
  uint8_t u_cska4_xor1 = 0;
  uint8_t u_cska4_fa0_xor0 = 0;
  uint8_t u_cska4_fa0_and0 = 0;
  uint8_t u_cska4_fa0_xor1 = 0;
  uint8_t u_cska4_fa0_and1 = 0;
  uint8_t u_cska4_fa0_or0 = 0;
  uint8_t u_cska4_xor2 = 0;
  uint8_t u_cska4_fa1_xor0 = 0;
  uint8_t u_cska4_fa1_and0 = 0;
  uint8_t u_cska4_fa1_xor1 = 0;
  uint8_t u_cska4_fa1_and1 = 0;
  uint8_t u_cska4_fa1_or0 = 0;
  uint8_t u_cska4_xor3 = 0;
  uint8_t u_cska4_fa2_xor0 = 0;
  uint8_t u_cska4_fa2_and0 = 0;
  uint8_t u_cska4_fa2_xor1 = 0;
  uint8_t u_cska4_fa2_and1 = 0;
  uint8_t u_cska4_fa2_or0 = 0;
  uint8_t u_cska4_and_propagate00 = 0;
  uint8_t u_cska4_and_propagate01 = 0;
  uint8_t u_cska4_and_propagate02 = 0;
  uint8_t u_cska4_mux2to10_not0 = 0;
  uint8_t u_cska4_mux2to10_and1 = 0;

  u_cska4_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_cska4_ha0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_cska4_ha0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_cska4_xor1 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_cska4_fa0_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_cska4_fa0_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_cska4_fa0_xor1 = ((u_cska4_fa0_xor0 >> 0) & 0x01) ^ ((u_cska4_ha0_and0 >> 0) & 0x01);
  u_cska4_fa0_and1 = ((u_cska4_fa0_xor0 >> 0) & 0x01) & ((u_cska4_ha0_and0 >> 0) & 0x01);
  u_cska4_fa0_or0 = ((u_cska4_fa0_and0 >> 0) & 0x01) | ((u_cska4_fa0_and1 >> 0) & 0x01);
  u_cska4_xor2 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_cska4_fa1_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_cska4_fa1_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_cska4_fa1_xor1 = ((u_cska4_fa1_xor0 >> 0) & 0x01) ^ ((u_cska4_fa0_or0 >> 0) & 0x01);
  u_cska4_fa1_and1 = ((u_cska4_fa1_xor0 >> 0) & 0x01) & ((u_cska4_fa0_or0 >> 0) & 0x01);
  u_cska4_fa1_or0 = ((u_cska4_fa1_and0 >> 0) & 0x01) | ((u_cska4_fa1_and1 >> 0) & 0x01);
  u_cska4_xor3 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_cska4_fa2_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_cska4_fa2_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_cska4_fa2_xor1 = ((u_cska4_fa2_xor0 >> 0) & 0x01) ^ ((u_cska4_fa1_or0 >> 0) & 0x01);
  u_cska4_fa2_and1 = ((u_cska4_fa2_xor0 >> 0) & 0x01) & ((u_cska4_fa1_or0 >> 0) & 0x01);
  u_cska4_fa2_or0 = ((u_cska4_fa2_and0 >> 0) & 0x01) | ((u_cska4_fa2_and1 >> 0) & 0x01);
  u_cska4_and_propagate00 = ((u_cska4_xor0 >> 0) & 0x01) & ((u_cska4_xor2 >> 0) & 0x01);
  u_cska4_and_propagate01 = ((u_cska4_xor1 >> 0) & 0x01) & ((u_cska4_xor3 >> 0) & 0x01);
  u_cska4_and_propagate02 = ((u_cska4_and_propagate00 >> 0) & 0x01) & ((u_cska4_and_propagate01 >> 0) & 0x01);
  u_cska4_mux2to10_not0 = ~(((u_cska4_and_propagate02 >> 0) & 0x01)) & 0x01;
  u_cska4_mux2to10_and1 = ((u_cska4_fa2_or0 >> 0) & 0x01) & ((u_cska4_mux2to10_not0 >> 0) & 0x01);

  u_cska4_out |= ((u_cska4_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska4_out |= ((u_cska4_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska4_out |= ((u_cska4_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska4_out |= ((u_cska4_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska4_out |= ((u_cska4_mux2to10_and1 >> 0) & 0x01ull) << 4;
  return u_cska4_out;
}