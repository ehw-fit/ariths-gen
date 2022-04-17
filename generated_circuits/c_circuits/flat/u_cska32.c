#include <stdio.h>
#include <stdint.h>

uint64_t u_cska32(uint64_t a, uint64_t b){
  uint64_t u_cska32_out = 0;
  uint8_t u_cska32_xor0 = 0;
  uint8_t u_cska32_ha0_xor0 = 0;
  uint8_t u_cska32_ha0_and0 = 0;
  uint8_t u_cska32_xor1 = 0;
  uint8_t u_cska32_fa0_xor0 = 0;
  uint8_t u_cska32_fa0_and0 = 0;
  uint8_t u_cska32_fa0_xor1 = 0;
  uint8_t u_cska32_fa0_and1 = 0;
  uint8_t u_cska32_fa0_or0 = 0;
  uint8_t u_cska32_xor2 = 0;
  uint8_t u_cska32_fa1_xor0 = 0;
  uint8_t u_cska32_fa1_and0 = 0;
  uint8_t u_cska32_fa1_xor1 = 0;
  uint8_t u_cska32_fa1_and1 = 0;
  uint8_t u_cska32_fa1_or0 = 0;
  uint8_t u_cska32_xor3 = 0;
  uint8_t u_cska32_fa2_xor0 = 0;
  uint8_t u_cska32_fa2_and0 = 0;
  uint8_t u_cska32_fa2_xor1 = 0;
  uint8_t u_cska32_fa2_and1 = 0;
  uint8_t u_cska32_fa2_or0 = 0;
  uint8_t u_cska32_and_propagate00 = 0;
  uint8_t u_cska32_and_propagate01 = 0;
  uint8_t u_cska32_and_propagate02 = 0;
  uint8_t u_cska32_mux2to10_not0 = 0;
  uint8_t u_cska32_mux2to10_and1 = 0;
  uint8_t u_cska32_xor4 = 0;
  uint8_t u_cska32_fa3_xor0 = 0;
  uint8_t u_cska32_fa3_and0 = 0;
  uint8_t u_cska32_fa3_xor1 = 0;
  uint8_t u_cska32_fa3_and1 = 0;
  uint8_t u_cska32_fa3_or0 = 0;
  uint8_t u_cska32_xor5 = 0;
  uint8_t u_cska32_fa4_xor0 = 0;
  uint8_t u_cska32_fa4_and0 = 0;
  uint8_t u_cska32_fa4_xor1 = 0;
  uint8_t u_cska32_fa4_and1 = 0;
  uint8_t u_cska32_fa4_or0 = 0;
  uint8_t u_cska32_xor6 = 0;
  uint8_t u_cska32_fa5_xor0 = 0;
  uint8_t u_cska32_fa5_and0 = 0;
  uint8_t u_cska32_fa5_xor1 = 0;
  uint8_t u_cska32_fa5_and1 = 0;
  uint8_t u_cska32_fa5_or0 = 0;
  uint8_t u_cska32_xor7 = 0;
  uint8_t u_cska32_fa6_xor0 = 0;
  uint8_t u_cska32_fa6_and0 = 0;
  uint8_t u_cska32_fa6_xor1 = 0;
  uint8_t u_cska32_fa6_and1 = 0;
  uint8_t u_cska32_fa6_or0 = 0;
  uint8_t u_cska32_and_propagate13 = 0;
  uint8_t u_cska32_and_propagate14 = 0;
  uint8_t u_cska32_and_propagate15 = 0;
  uint8_t u_cska32_mux2to11_and0 = 0;
  uint8_t u_cska32_mux2to11_not0 = 0;
  uint8_t u_cska32_mux2to11_and1 = 0;
  uint8_t u_cska32_mux2to11_xor0 = 0;
  uint8_t u_cska32_xor8 = 0;
  uint8_t u_cska32_fa7_xor0 = 0;
  uint8_t u_cska32_fa7_and0 = 0;
  uint8_t u_cska32_fa7_xor1 = 0;
  uint8_t u_cska32_fa7_and1 = 0;
  uint8_t u_cska32_fa7_or0 = 0;
  uint8_t u_cska32_xor9 = 0;
  uint8_t u_cska32_fa8_xor0 = 0;
  uint8_t u_cska32_fa8_and0 = 0;
  uint8_t u_cska32_fa8_xor1 = 0;
  uint8_t u_cska32_fa8_and1 = 0;
  uint8_t u_cska32_fa8_or0 = 0;
  uint8_t u_cska32_xor10 = 0;
  uint8_t u_cska32_fa9_xor0 = 0;
  uint8_t u_cska32_fa9_and0 = 0;
  uint8_t u_cska32_fa9_xor1 = 0;
  uint8_t u_cska32_fa9_and1 = 0;
  uint8_t u_cska32_fa9_or0 = 0;
  uint8_t u_cska32_xor11 = 0;
  uint8_t u_cska32_fa10_xor0 = 0;
  uint8_t u_cska32_fa10_and0 = 0;
  uint8_t u_cska32_fa10_xor1 = 0;
  uint8_t u_cska32_fa10_and1 = 0;
  uint8_t u_cska32_fa10_or0 = 0;
  uint8_t u_cska32_and_propagate26 = 0;
  uint8_t u_cska32_and_propagate27 = 0;
  uint8_t u_cska32_and_propagate28 = 0;
  uint8_t u_cska32_mux2to12_and0 = 0;
  uint8_t u_cska32_mux2to12_not0 = 0;
  uint8_t u_cska32_mux2to12_and1 = 0;
  uint8_t u_cska32_mux2to12_xor0 = 0;
  uint8_t u_cska32_xor12 = 0;
  uint8_t u_cska32_fa11_xor0 = 0;
  uint8_t u_cska32_fa11_and0 = 0;
  uint8_t u_cska32_fa11_xor1 = 0;
  uint8_t u_cska32_fa11_and1 = 0;
  uint8_t u_cska32_fa11_or0 = 0;
  uint8_t u_cska32_xor13 = 0;
  uint8_t u_cska32_fa12_xor0 = 0;
  uint8_t u_cska32_fa12_and0 = 0;
  uint8_t u_cska32_fa12_xor1 = 0;
  uint8_t u_cska32_fa12_and1 = 0;
  uint8_t u_cska32_fa12_or0 = 0;
  uint8_t u_cska32_xor14 = 0;
  uint8_t u_cska32_fa13_xor0 = 0;
  uint8_t u_cska32_fa13_and0 = 0;
  uint8_t u_cska32_fa13_xor1 = 0;
  uint8_t u_cska32_fa13_and1 = 0;
  uint8_t u_cska32_fa13_or0 = 0;
  uint8_t u_cska32_xor15 = 0;
  uint8_t u_cska32_fa14_xor0 = 0;
  uint8_t u_cska32_fa14_and0 = 0;
  uint8_t u_cska32_fa14_xor1 = 0;
  uint8_t u_cska32_fa14_and1 = 0;
  uint8_t u_cska32_fa14_or0 = 0;
  uint8_t u_cska32_and_propagate39 = 0;
  uint8_t u_cska32_and_propagate310 = 0;
  uint8_t u_cska32_and_propagate311 = 0;
  uint8_t u_cska32_mux2to13_and0 = 0;
  uint8_t u_cska32_mux2to13_not0 = 0;
  uint8_t u_cska32_mux2to13_and1 = 0;
  uint8_t u_cska32_mux2to13_xor0 = 0;
  uint8_t u_cska32_xor16 = 0;
  uint8_t u_cska32_fa15_xor0 = 0;
  uint8_t u_cska32_fa15_and0 = 0;
  uint8_t u_cska32_fa15_xor1 = 0;
  uint8_t u_cska32_fa15_and1 = 0;
  uint8_t u_cska32_fa15_or0 = 0;
  uint8_t u_cska32_xor17 = 0;
  uint8_t u_cska32_fa16_xor0 = 0;
  uint8_t u_cska32_fa16_and0 = 0;
  uint8_t u_cska32_fa16_xor1 = 0;
  uint8_t u_cska32_fa16_and1 = 0;
  uint8_t u_cska32_fa16_or0 = 0;
  uint8_t u_cska32_xor18 = 0;
  uint8_t u_cska32_fa17_xor0 = 0;
  uint8_t u_cska32_fa17_and0 = 0;
  uint8_t u_cska32_fa17_xor1 = 0;
  uint8_t u_cska32_fa17_and1 = 0;
  uint8_t u_cska32_fa17_or0 = 0;
  uint8_t u_cska32_xor19 = 0;
  uint8_t u_cska32_fa18_xor0 = 0;
  uint8_t u_cska32_fa18_and0 = 0;
  uint8_t u_cska32_fa18_xor1 = 0;
  uint8_t u_cska32_fa18_and1 = 0;
  uint8_t u_cska32_fa18_or0 = 0;
  uint8_t u_cska32_and_propagate412 = 0;
  uint8_t u_cska32_and_propagate413 = 0;
  uint8_t u_cska32_and_propagate414 = 0;
  uint8_t u_cska32_mux2to14_and0 = 0;
  uint8_t u_cska32_mux2to14_not0 = 0;
  uint8_t u_cska32_mux2to14_and1 = 0;
  uint8_t u_cska32_mux2to14_xor0 = 0;
  uint8_t u_cska32_xor20 = 0;
  uint8_t u_cska32_fa19_xor0 = 0;
  uint8_t u_cska32_fa19_and0 = 0;
  uint8_t u_cska32_fa19_xor1 = 0;
  uint8_t u_cska32_fa19_and1 = 0;
  uint8_t u_cska32_fa19_or0 = 0;
  uint8_t u_cska32_xor21 = 0;
  uint8_t u_cska32_fa20_xor0 = 0;
  uint8_t u_cska32_fa20_and0 = 0;
  uint8_t u_cska32_fa20_xor1 = 0;
  uint8_t u_cska32_fa20_and1 = 0;
  uint8_t u_cska32_fa20_or0 = 0;
  uint8_t u_cska32_xor22 = 0;
  uint8_t u_cska32_fa21_xor0 = 0;
  uint8_t u_cska32_fa21_and0 = 0;
  uint8_t u_cska32_fa21_xor1 = 0;
  uint8_t u_cska32_fa21_and1 = 0;
  uint8_t u_cska32_fa21_or0 = 0;
  uint8_t u_cska32_xor23 = 0;
  uint8_t u_cska32_fa22_xor0 = 0;
  uint8_t u_cska32_fa22_and0 = 0;
  uint8_t u_cska32_fa22_xor1 = 0;
  uint8_t u_cska32_fa22_and1 = 0;
  uint8_t u_cska32_fa22_or0 = 0;
  uint8_t u_cska32_and_propagate515 = 0;
  uint8_t u_cska32_and_propagate516 = 0;
  uint8_t u_cska32_and_propagate517 = 0;
  uint8_t u_cska32_mux2to15_and0 = 0;
  uint8_t u_cska32_mux2to15_not0 = 0;
  uint8_t u_cska32_mux2to15_and1 = 0;
  uint8_t u_cska32_mux2to15_xor0 = 0;
  uint8_t u_cska32_xor24 = 0;
  uint8_t u_cska32_fa23_xor0 = 0;
  uint8_t u_cska32_fa23_and0 = 0;
  uint8_t u_cska32_fa23_xor1 = 0;
  uint8_t u_cska32_fa23_and1 = 0;
  uint8_t u_cska32_fa23_or0 = 0;
  uint8_t u_cska32_xor25 = 0;
  uint8_t u_cska32_fa24_xor0 = 0;
  uint8_t u_cska32_fa24_and0 = 0;
  uint8_t u_cska32_fa24_xor1 = 0;
  uint8_t u_cska32_fa24_and1 = 0;
  uint8_t u_cska32_fa24_or0 = 0;
  uint8_t u_cska32_xor26 = 0;
  uint8_t u_cska32_fa25_xor0 = 0;
  uint8_t u_cska32_fa25_and0 = 0;
  uint8_t u_cska32_fa25_xor1 = 0;
  uint8_t u_cska32_fa25_and1 = 0;
  uint8_t u_cska32_fa25_or0 = 0;
  uint8_t u_cska32_xor27 = 0;
  uint8_t u_cska32_fa26_xor0 = 0;
  uint8_t u_cska32_fa26_and0 = 0;
  uint8_t u_cska32_fa26_xor1 = 0;
  uint8_t u_cska32_fa26_and1 = 0;
  uint8_t u_cska32_fa26_or0 = 0;
  uint8_t u_cska32_and_propagate618 = 0;
  uint8_t u_cska32_and_propagate619 = 0;
  uint8_t u_cska32_and_propagate620 = 0;
  uint8_t u_cska32_mux2to16_and0 = 0;
  uint8_t u_cska32_mux2to16_not0 = 0;
  uint8_t u_cska32_mux2to16_and1 = 0;
  uint8_t u_cska32_mux2to16_xor0 = 0;
  uint8_t u_cska32_xor28 = 0;
  uint8_t u_cska32_fa27_xor0 = 0;
  uint8_t u_cska32_fa27_and0 = 0;
  uint8_t u_cska32_fa27_xor1 = 0;
  uint8_t u_cska32_fa27_and1 = 0;
  uint8_t u_cska32_fa27_or0 = 0;
  uint8_t u_cska32_xor29 = 0;
  uint8_t u_cska32_fa28_xor0 = 0;
  uint8_t u_cska32_fa28_and0 = 0;
  uint8_t u_cska32_fa28_xor1 = 0;
  uint8_t u_cska32_fa28_and1 = 0;
  uint8_t u_cska32_fa28_or0 = 0;
  uint8_t u_cska32_xor30 = 0;
  uint8_t u_cska32_fa29_xor0 = 0;
  uint8_t u_cska32_fa29_and0 = 0;
  uint8_t u_cska32_fa29_xor1 = 0;
  uint8_t u_cska32_fa29_and1 = 0;
  uint8_t u_cska32_fa29_or0 = 0;
  uint8_t u_cska32_xor31 = 0;
  uint8_t u_cska32_fa30_xor0 = 0;
  uint8_t u_cska32_fa30_and0 = 0;
  uint8_t u_cska32_fa30_xor1 = 0;
  uint8_t u_cska32_fa30_and1 = 0;
  uint8_t u_cska32_fa30_or0 = 0;
  uint8_t u_cska32_and_propagate721 = 0;
  uint8_t u_cska32_and_propagate722 = 0;
  uint8_t u_cska32_and_propagate723 = 0;
  uint8_t u_cska32_mux2to17_and0 = 0;
  uint8_t u_cska32_mux2to17_not0 = 0;
  uint8_t u_cska32_mux2to17_and1 = 0;
  uint8_t u_cska32_mux2to17_xor0 = 0;

  u_cska32_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_cska32_ha0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_cska32_ha0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_cska32_xor1 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_cska32_fa0_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_cska32_fa0_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_cska32_fa0_xor1 = ((u_cska32_fa0_xor0 >> 0) & 0x01) ^ ((u_cska32_ha0_and0 >> 0) & 0x01);
  u_cska32_fa0_and1 = ((u_cska32_fa0_xor0 >> 0) & 0x01) & ((u_cska32_ha0_and0 >> 0) & 0x01);
  u_cska32_fa0_or0 = ((u_cska32_fa0_and0 >> 0) & 0x01) | ((u_cska32_fa0_and1 >> 0) & 0x01);
  u_cska32_xor2 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_cska32_fa1_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_cska32_fa1_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_cska32_fa1_xor1 = ((u_cska32_fa1_xor0 >> 0) & 0x01) ^ ((u_cska32_fa0_or0 >> 0) & 0x01);
  u_cska32_fa1_and1 = ((u_cska32_fa1_xor0 >> 0) & 0x01) & ((u_cska32_fa0_or0 >> 0) & 0x01);
  u_cska32_fa1_or0 = ((u_cska32_fa1_and0 >> 0) & 0x01) | ((u_cska32_fa1_and1 >> 0) & 0x01);
  u_cska32_xor3 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_cska32_fa2_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_cska32_fa2_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_cska32_fa2_xor1 = ((u_cska32_fa2_xor0 >> 0) & 0x01) ^ ((u_cska32_fa1_or0 >> 0) & 0x01);
  u_cska32_fa2_and1 = ((u_cska32_fa2_xor0 >> 0) & 0x01) & ((u_cska32_fa1_or0 >> 0) & 0x01);
  u_cska32_fa2_or0 = ((u_cska32_fa2_and0 >> 0) & 0x01) | ((u_cska32_fa2_and1 >> 0) & 0x01);
  u_cska32_and_propagate00 = ((u_cska32_xor0 >> 0) & 0x01) & ((u_cska32_xor2 >> 0) & 0x01);
  u_cska32_and_propagate01 = ((u_cska32_xor1 >> 0) & 0x01) & ((u_cska32_xor3 >> 0) & 0x01);
  u_cska32_and_propagate02 = ((u_cska32_and_propagate00 >> 0) & 0x01) & ((u_cska32_and_propagate01 >> 0) & 0x01);
  u_cska32_mux2to10_not0 = ~(((u_cska32_and_propagate02 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to10_and1 = ((u_cska32_fa2_or0 >> 0) & 0x01) & ((u_cska32_mux2to10_not0 >> 0) & 0x01);
  u_cska32_xor4 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  u_cska32_fa3_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  u_cska32_fa3_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  u_cska32_fa3_xor1 = ((u_cska32_fa3_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to10_and1 >> 0) & 0x01);
  u_cska32_fa3_and1 = ((u_cska32_fa3_xor0 >> 0) & 0x01) & ((u_cska32_mux2to10_and1 >> 0) & 0x01);
  u_cska32_fa3_or0 = ((u_cska32_fa3_and0 >> 0) & 0x01) | ((u_cska32_fa3_and1 >> 0) & 0x01);
  u_cska32_xor5 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  u_cska32_fa4_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  u_cska32_fa4_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  u_cska32_fa4_xor1 = ((u_cska32_fa4_xor0 >> 0) & 0x01) ^ ((u_cska32_fa3_or0 >> 0) & 0x01);
  u_cska32_fa4_and1 = ((u_cska32_fa4_xor0 >> 0) & 0x01) & ((u_cska32_fa3_or0 >> 0) & 0x01);
  u_cska32_fa4_or0 = ((u_cska32_fa4_and0 >> 0) & 0x01) | ((u_cska32_fa4_and1 >> 0) & 0x01);
  u_cska32_xor6 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  u_cska32_fa5_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  u_cska32_fa5_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  u_cska32_fa5_xor1 = ((u_cska32_fa5_xor0 >> 0) & 0x01) ^ ((u_cska32_fa4_or0 >> 0) & 0x01);
  u_cska32_fa5_and1 = ((u_cska32_fa5_xor0 >> 0) & 0x01) & ((u_cska32_fa4_or0 >> 0) & 0x01);
  u_cska32_fa5_or0 = ((u_cska32_fa5_and0 >> 0) & 0x01) | ((u_cska32_fa5_and1 >> 0) & 0x01);
  u_cska32_xor7 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  u_cska32_fa6_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  u_cska32_fa6_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  u_cska32_fa6_xor1 = ((u_cska32_fa6_xor0 >> 0) & 0x01) ^ ((u_cska32_fa5_or0 >> 0) & 0x01);
  u_cska32_fa6_and1 = ((u_cska32_fa6_xor0 >> 0) & 0x01) & ((u_cska32_fa5_or0 >> 0) & 0x01);
  u_cska32_fa6_or0 = ((u_cska32_fa6_and0 >> 0) & 0x01) | ((u_cska32_fa6_and1 >> 0) & 0x01);
  u_cska32_and_propagate13 = ((u_cska32_xor4 >> 0) & 0x01) & ((u_cska32_xor6 >> 0) & 0x01);
  u_cska32_and_propagate14 = ((u_cska32_xor5 >> 0) & 0x01) & ((u_cska32_xor7 >> 0) & 0x01);
  u_cska32_and_propagate15 = ((u_cska32_and_propagate13 >> 0) & 0x01) & ((u_cska32_and_propagate14 >> 0) & 0x01);
  u_cska32_mux2to11_and0 = ((u_cska32_mux2to10_and1 >> 0) & 0x01) & ((u_cska32_and_propagate15 >> 0) & 0x01);
  u_cska32_mux2to11_not0 = ~(((u_cska32_and_propagate15 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to11_and1 = ((u_cska32_fa6_or0 >> 0) & 0x01) & ((u_cska32_mux2to11_not0 >> 0) & 0x01);
  u_cska32_mux2to11_xor0 = ((u_cska32_mux2to11_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to11_and1 >> 0) & 0x01);
  u_cska32_xor8 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  u_cska32_fa7_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  u_cska32_fa7_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  u_cska32_fa7_xor1 = ((u_cska32_fa7_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to11_xor0 >> 0) & 0x01);
  u_cska32_fa7_and1 = ((u_cska32_fa7_xor0 >> 0) & 0x01) & ((u_cska32_mux2to11_xor0 >> 0) & 0x01);
  u_cska32_fa7_or0 = ((u_cska32_fa7_and0 >> 0) & 0x01) | ((u_cska32_fa7_and1 >> 0) & 0x01);
  u_cska32_xor9 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  u_cska32_fa8_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  u_cska32_fa8_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  u_cska32_fa8_xor1 = ((u_cska32_fa8_xor0 >> 0) & 0x01) ^ ((u_cska32_fa7_or0 >> 0) & 0x01);
  u_cska32_fa8_and1 = ((u_cska32_fa8_xor0 >> 0) & 0x01) & ((u_cska32_fa7_or0 >> 0) & 0x01);
  u_cska32_fa8_or0 = ((u_cska32_fa8_and0 >> 0) & 0x01) | ((u_cska32_fa8_and1 >> 0) & 0x01);
  u_cska32_xor10 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  u_cska32_fa9_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  u_cska32_fa9_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  u_cska32_fa9_xor1 = ((u_cska32_fa9_xor0 >> 0) & 0x01) ^ ((u_cska32_fa8_or0 >> 0) & 0x01);
  u_cska32_fa9_and1 = ((u_cska32_fa9_xor0 >> 0) & 0x01) & ((u_cska32_fa8_or0 >> 0) & 0x01);
  u_cska32_fa9_or0 = ((u_cska32_fa9_and0 >> 0) & 0x01) | ((u_cska32_fa9_and1 >> 0) & 0x01);
  u_cska32_xor11 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  u_cska32_fa10_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  u_cska32_fa10_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  u_cska32_fa10_xor1 = ((u_cska32_fa10_xor0 >> 0) & 0x01) ^ ((u_cska32_fa9_or0 >> 0) & 0x01);
  u_cska32_fa10_and1 = ((u_cska32_fa10_xor0 >> 0) & 0x01) & ((u_cska32_fa9_or0 >> 0) & 0x01);
  u_cska32_fa10_or0 = ((u_cska32_fa10_and0 >> 0) & 0x01) | ((u_cska32_fa10_and1 >> 0) & 0x01);
  u_cska32_and_propagate26 = ((u_cska32_xor8 >> 0) & 0x01) & ((u_cska32_xor10 >> 0) & 0x01);
  u_cska32_and_propagate27 = ((u_cska32_xor9 >> 0) & 0x01) & ((u_cska32_xor11 >> 0) & 0x01);
  u_cska32_and_propagate28 = ((u_cska32_and_propagate26 >> 0) & 0x01) & ((u_cska32_and_propagate27 >> 0) & 0x01);
  u_cska32_mux2to12_and0 = ((u_cska32_mux2to11_xor0 >> 0) & 0x01) & ((u_cska32_and_propagate28 >> 0) & 0x01);
  u_cska32_mux2to12_not0 = ~(((u_cska32_and_propagate28 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to12_and1 = ((u_cska32_fa10_or0 >> 0) & 0x01) & ((u_cska32_mux2to12_not0 >> 0) & 0x01);
  u_cska32_mux2to12_xor0 = ((u_cska32_mux2to12_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to12_and1 >> 0) & 0x01);
  u_cska32_xor12 = ((a >> 12) & 0x01) ^ ((b >> 12) & 0x01);
  u_cska32_fa11_xor0 = ((a >> 12) & 0x01) ^ ((b >> 12) & 0x01);
  u_cska32_fa11_and0 = ((a >> 12) & 0x01) & ((b >> 12) & 0x01);
  u_cska32_fa11_xor1 = ((u_cska32_fa11_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to12_xor0 >> 0) & 0x01);
  u_cska32_fa11_and1 = ((u_cska32_fa11_xor0 >> 0) & 0x01) & ((u_cska32_mux2to12_xor0 >> 0) & 0x01);
  u_cska32_fa11_or0 = ((u_cska32_fa11_and0 >> 0) & 0x01) | ((u_cska32_fa11_and1 >> 0) & 0x01);
  u_cska32_xor13 = ((a >> 13) & 0x01) ^ ((b >> 13) & 0x01);
  u_cska32_fa12_xor0 = ((a >> 13) & 0x01) ^ ((b >> 13) & 0x01);
  u_cska32_fa12_and0 = ((a >> 13) & 0x01) & ((b >> 13) & 0x01);
  u_cska32_fa12_xor1 = ((u_cska32_fa12_xor0 >> 0) & 0x01) ^ ((u_cska32_fa11_or0 >> 0) & 0x01);
  u_cska32_fa12_and1 = ((u_cska32_fa12_xor0 >> 0) & 0x01) & ((u_cska32_fa11_or0 >> 0) & 0x01);
  u_cska32_fa12_or0 = ((u_cska32_fa12_and0 >> 0) & 0x01) | ((u_cska32_fa12_and1 >> 0) & 0x01);
  u_cska32_xor14 = ((a >> 14) & 0x01) ^ ((b >> 14) & 0x01);
  u_cska32_fa13_xor0 = ((a >> 14) & 0x01) ^ ((b >> 14) & 0x01);
  u_cska32_fa13_and0 = ((a >> 14) & 0x01) & ((b >> 14) & 0x01);
  u_cska32_fa13_xor1 = ((u_cska32_fa13_xor0 >> 0) & 0x01) ^ ((u_cska32_fa12_or0 >> 0) & 0x01);
  u_cska32_fa13_and1 = ((u_cska32_fa13_xor0 >> 0) & 0x01) & ((u_cska32_fa12_or0 >> 0) & 0x01);
  u_cska32_fa13_or0 = ((u_cska32_fa13_and0 >> 0) & 0x01) | ((u_cska32_fa13_and1 >> 0) & 0x01);
  u_cska32_xor15 = ((a >> 15) & 0x01) ^ ((b >> 15) & 0x01);
  u_cska32_fa14_xor0 = ((a >> 15) & 0x01) ^ ((b >> 15) & 0x01);
  u_cska32_fa14_and0 = ((a >> 15) & 0x01) & ((b >> 15) & 0x01);
  u_cska32_fa14_xor1 = ((u_cska32_fa14_xor0 >> 0) & 0x01) ^ ((u_cska32_fa13_or0 >> 0) & 0x01);
  u_cska32_fa14_and1 = ((u_cska32_fa14_xor0 >> 0) & 0x01) & ((u_cska32_fa13_or0 >> 0) & 0x01);
  u_cska32_fa14_or0 = ((u_cska32_fa14_and0 >> 0) & 0x01) | ((u_cska32_fa14_and1 >> 0) & 0x01);
  u_cska32_and_propagate39 = ((u_cska32_xor12 >> 0) & 0x01) & ((u_cska32_xor14 >> 0) & 0x01);
  u_cska32_and_propagate310 = ((u_cska32_xor13 >> 0) & 0x01) & ((u_cska32_xor15 >> 0) & 0x01);
  u_cska32_and_propagate311 = ((u_cska32_and_propagate39 >> 0) & 0x01) & ((u_cska32_and_propagate310 >> 0) & 0x01);
  u_cska32_mux2to13_and0 = ((u_cska32_mux2to12_xor0 >> 0) & 0x01) & ((u_cska32_and_propagate311 >> 0) & 0x01);
  u_cska32_mux2to13_not0 = ~(((u_cska32_and_propagate311 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to13_and1 = ((u_cska32_fa14_or0 >> 0) & 0x01) & ((u_cska32_mux2to13_not0 >> 0) & 0x01);
  u_cska32_mux2to13_xor0 = ((u_cska32_mux2to13_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to13_and1 >> 0) & 0x01);
  u_cska32_xor16 = ((a >> 16) & 0x01) ^ ((b >> 16) & 0x01);
  u_cska32_fa15_xor0 = ((a >> 16) & 0x01) ^ ((b >> 16) & 0x01);
  u_cska32_fa15_and0 = ((a >> 16) & 0x01) & ((b >> 16) & 0x01);
  u_cska32_fa15_xor1 = ((u_cska32_fa15_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to13_xor0 >> 0) & 0x01);
  u_cska32_fa15_and1 = ((u_cska32_fa15_xor0 >> 0) & 0x01) & ((u_cska32_mux2to13_xor0 >> 0) & 0x01);
  u_cska32_fa15_or0 = ((u_cska32_fa15_and0 >> 0) & 0x01) | ((u_cska32_fa15_and1 >> 0) & 0x01);
  u_cska32_xor17 = ((a >> 17) & 0x01) ^ ((b >> 17) & 0x01);
  u_cska32_fa16_xor0 = ((a >> 17) & 0x01) ^ ((b >> 17) & 0x01);
  u_cska32_fa16_and0 = ((a >> 17) & 0x01) & ((b >> 17) & 0x01);
  u_cska32_fa16_xor1 = ((u_cska32_fa16_xor0 >> 0) & 0x01) ^ ((u_cska32_fa15_or0 >> 0) & 0x01);
  u_cska32_fa16_and1 = ((u_cska32_fa16_xor0 >> 0) & 0x01) & ((u_cska32_fa15_or0 >> 0) & 0x01);
  u_cska32_fa16_or0 = ((u_cska32_fa16_and0 >> 0) & 0x01) | ((u_cska32_fa16_and1 >> 0) & 0x01);
  u_cska32_xor18 = ((a >> 18) & 0x01) ^ ((b >> 18) & 0x01);
  u_cska32_fa17_xor0 = ((a >> 18) & 0x01) ^ ((b >> 18) & 0x01);
  u_cska32_fa17_and0 = ((a >> 18) & 0x01) & ((b >> 18) & 0x01);
  u_cska32_fa17_xor1 = ((u_cska32_fa17_xor0 >> 0) & 0x01) ^ ((u_cska32_fa16_or0 >> 0) & 0x01);
  u_cska32_fa17_and1 = ((u_cska32_fa17_xor0 >> 0) & 0x01) & ((u_cska32_fa16_or0 >> 0) & 0x01);
  u_cska32_fa17_or0 = ((u_cska32_fa17_and0 >> 0) & 0x01) | ((u_cska32_fa17_and1 >> 0) & 0x01);
  u_cska32_xor19 = ((a >> 19) & 0x01) ^ ((b >> 19) & 0x01);
  u_cska32_fa18_xor0 = ((a >> 19) & 0x01) ^ ((b >> 19) & 0x01);
  u_cska32_fa18_and0 = ((a >> 19) & 0x01) & ((b >> 19) & 0x01);
  u_cska32_fa18_xor1 = ((u_cska32_fa18_xor0 >> 0) & 0x01) ^ ((u_cska32_fa17_or0 >> 0) & 0x01);
  u_cska32_fa18_and1 = ((u_cska32_fa18_xor0 >> 0) & 0x01) & ((u_cska32_fa17_or0 >> 0) & 0x01);
  u_cska32_fa18_or0 = ((u_cska32_fa18_and0 >> 0) & 0x01) | ((u_cska32_fa18_and1 >> 0) & 0x01);
  u_cska32_and_propagate412 = ((u_cska32_xor16 >> 0) & 0x01) & ((u_cska32_xor18 >> 0) & 0x01);
  u_cska32_and_propagate413 = ((u_cska32_xor17 >> 0) & 0x01) & ((u_cska32_xor19 >> 0) & 0x01);
  u_cska32_and_propagate414 = ((u_cska32_and_propagate412 >> 0) & 0x01) & ((u_cska32_and_propagate413 >> 0) & 0x01);
  u_cska32_mux2to14_and0 = ((u_cska32_mux2to13_xor0 >> 0) & 0x01) & ((u_cska32_and_propagate414 >> 0) & 0x01);
  u_cska32_mux2to14_not0 = ~(((u_cska32_and_propagate414 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to14_and1 = ((u_cska32_fa18_or0 >> 0) & 0x01) & ((u_cska32_mux2to14_not0 >> 0) & 0x01);
  u_cska32_mux2to14_xor0 = ((u_cska32_mux2to14_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to14_and1 >> 0) & 0x01);
  u_cska32_xor20 = ((a >> 20) & 0x01) ^ ((b >> 20) & 0x01);
  u_cska32_fa19_xor0 = ((a >> 20) & 0x01) ^ ((b >> 20) & 0x01);
  u_cska32_fa19_and0 = ((a >> 20) & 0x01) & ((b >> 20) & 0x01);
  u_cska32_fa19_xor1 = ((u_cska32_fa19_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to14_xor0 >> 0) & 0x01);
  u_cska32_fa19_and1 = ((u_cska32_fa19_xor0 >> 0) & 0x01) & ((u_cska32_mux2to14_xor0 >> 0) & 0x01);
  u_cska32_fa19_or0 = ((u_cska32_fa19_and0 >> 0) & 0x01) | ((u_cska32_fa19_and1 >> 0) & 0x01);
  u_cska32_xor21 = ((a >> 21) & 0x01) ^ ((b >> 21) & 0x01);
  u_cska32_fa20_xor0 = ((a >> 21) & 0x01) ^ ((b >> 21) & 0x01);
  u_cska32_fa20_and0 = ((a >> 21) & 0x01) & ((b >> 21) & 0x01);
  u_cska32_fa20_xor1 = ((u_cska32_fa20_xor0 >> 0) & 0x01) ^ ((u_cska32_fa19_or0 >> 0) & 0x01);
  u_cska32_fa20_and1 = ((u_cska32_fa20_xor0 >> 0) & 0x01) & ((u_cska32_fa19_or0 >> 0) & 0x01);
  u_cska32_fa20_or0 = ((u_cska32_fa20_and0 >> 0) & 0x01) | ((u_cska32_fa20_and1 >> 0) & 0x01);
  u_cska32_xor22 = ((a >> 22) & 0x01) ^ ((b >> 22) & 0x01);
  u_cska32_fa21_xor0 = ((a >> 22) & 0x01) ^ ((b >> 22) & 0x01);
  u_cska32_fa21_and0 = ((a >> 22) & 0x01) & ((b >> 22) & 0x01);
  u_cska32_fa21_xor1 = ((u_cska32_fa21_xor0 >> 0) & 0x01) ^ ((u_cska32_fa20_or0 >> 0) & 0x01);
  u_cska32_fa21_and1 = ((u_cska32_fa21_xor0 >> 0) & 0x01) & ((u_cska32_fa20_or0 >> 0) & 0x01);
  u_cska32_fa21_or0 = ((u_cska32_fa21_and0 >> 0) & 0x01) | ((u_cska32_fa21_and1 >> 0) & 0x01);
  u_cska32_xor23 = ((a >> 23) & 0x01) ^ ((b >> 23) & 0x01);
  u_cska32_fa22_xor0 = ((a >> 23) & 0x01) ^ ((b >> 23) & 0x01);
  u_cska32_fa22_and0 = ((a >> 23) & 0x01) & ((b >> 23) & 0x01);
  u_cska32_fa22_xor1 = ((u_cska32_fa22_xor0 >> 0) & 0x01) ^ ((u_cska32_fa21_or0 >> 0) & 0x01);
  u_cska32_fa22_and1 = ((u_cska32_fa22_xor0 >> 0) & 0x01) & ((u_cska32_fa21_or0 >> 0) & 0x01);
  u_cska32_fa22_or0 = ((u_cska32_fa22_and0 >> 0) & 0x01) | ((u_cska32_fa22_and1 >> 0) & 0x01);
  u_cska32_and_propagate515 = ((u_cska32_xor20 >> 0) & 0x01) & ((u_cska32_xor22 >> 0) & 0x01);
  u_cska32_and_propagate516 = ((u_cska32_xor21 >> 0) & 0x01) & ((u_cska32_xor23 >> 0) & 0x01);
  u_cska32_and_propagate517 = ((u_cska32_and_propagate515 >> 0) & 0x01) & ((u_cska32_and_propagate516 >> 0) & 0x01);
  u_cska32_mux2to15_and0 = ((u_cska32_mux2to14_xor0 >> 0) & 0x01) & ((u_cska32_and_propagate517 >> 0) & 0x01);
  u_cska32_mux2to15_not0 = ~(((u_cska32_and_propagate517 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to15_and1 = ((u_cska32_fa22_or0 >> 0) & 0x01) & ((u_cska32_mux2to15_not0 >> 0) & 0x01);
  u_cska32_mux2to15_xor0 = ((u_cska32_mux2to15_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to15_and1 >> 0) & 0x01);
  u_cska32_xor24 = ((a >> 24) & 0x01) ^ ((b >> 24) & 0x01);
  u_cska32_fa23_xor0 = ((a >> 24) & 0x01) ^ ((b >> 24) & 0x01);
  u_cska32_fa23_and0 = ((a >> 24) & 0x01) & ((b >> 24) & 0x01);
  u_cska32_fa23_xor1 = ((u_cska32_fa23_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to15_xor0 >> 0) & 0x01);
  u_cska32_fa23_and1 = ((u_cska32_fa23_xor0 >> 0) & 0x01) & ((u_cska32_mux2to15_xor0 >> 0) & 0x01);
  u_cska32_fa23_or0 = ((u_cska32_fa23_and0 >> 0) & 0x01) | ((u_cska32_fa23_and1 >> 0) & 0x01);
  u_cska32_xor25 = ((a >> 25) & 0x01) ^ ((b >> 25) & 0x01);
  u_cska32_fa24_xor0 = ((a >> 25) & 0x01) ^ ((b >> 25) & 0x01);
  u_cska32_fa24_and0 = ((a >> 25) & 0x01) & ((b >> 25) & 0x01);
  u_cska32_fa24_xor1 = ((u_cska32_fa24_xor0 >> 0) & 0x01) ^ ((u_cska32_fa23_or0 >> 0) & 0x01);
  u_cska32_fa24_and1 = ((u_cska32_fa24_xor0 >> 0) & 0x01) & ((u_cska32_fa23_or0 >> 0) & 0x01);
  u_cska32_fa24_or0 = ((u_cska32_fa24_and0 >> 0) & 0x01) | ((u_cska32_fa24_and1 >> 0) & 0x01);
  u_cska32_xor26 = ((a >> 26) & 0x01) ^ ((b >> 26) & 0x01);
  u_cska32_fa25_xor0 = ((a >> 26) & 0x01) ^ ((b >> 26) & 0x01);
  u_cska32_fa25_and0 = ((a >> 26) & 0x01) & ((b >> 26) & 0x01);
  u_cska32_fa25_xor1 = ((u_cska32_fa25_xor0 >> 0) & 0x01) ^ ((u_cska32_fa24_or0 >> 0) & 0x01);
  u_cska32_fa25_and1 = ((u_cska32_fa25_xor0 >> 0) & 0x01) & ((u_cska32_fa24_or0 >> 0) & 0x01);
  u_cska32_fa25_or0 = ((u_cska32_fa25_and0 >> 0) & 0x01) | ((u_cska32_fa25_and1 >> 0) & 0x01);
  u_cska32_xor27 = ((a >> 27) & 0x01) ^ ((b >> 27) & 0x01);
  u_cska32_fa26_xor0 = ((a >> 27) & 0x01) ^ ((b >> 27) & 0x01);
  u_cska32_fa26_and0 = ((a >> 27) & 0x01) & ((b >> 27) & 0x01);
  u_cska32_fa26_xor1 = ((u_cska32_fa26_xor0 >> 0) & 0x01) ^ ((u_cska32_fa25_or0 >> 0) & 0x01);
  u_cska32_fa26_and1 = ((u_cska32_fa26_xor0 >> 0) & 0x01) & ((u_cska32_fa25_or0 >> 0) & 0x01);
  u_cska32_fa26_or0 = ((u_cska32_fa26_and0 >> 0) & 0x01) | ((u_cska32_fa26_and1 >> 0) & 0x01);
  u_cska32_and_propagate618 = ((u_cska32_xor24 >> 0) & 0x01) & ((u_cska32_xor26 >> 0) & 0x01);
  u_cska32_and_propagate619 = ((u_cska32_xor25 >> 0) & 0x01) & ((u_cska32_xor27 >> 0) & 0x01);
  u_cska32_and_propagate620 = ((u_cska32_and_propagate618 >> 0) & 0x01) & ((u_cska32_and_propagate619 >> 0) & 0x01);
  u_cska32_mux2to16_and0 = ((u_cska32_mux2to15_xor0 >> 0) & 0x01) & ((u_cska32_and_propagate620 >> 0) & 0x01);
  u_cska32_mux2to16_not0 = ~(((u_cska32_and_propagate620 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to16_and1 = ((u_cska32_fa26_or0 >> 0) & 0x01) & ((u_cska32_mux2to16_not0 >> 0) & 0x01);
  u_cska32_mux2to16_xor0 = ((u_cska32_mux2to16_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to16_and1 >> 0) & 0x01);
  u_cska32_xor28 = ((a >> 28) & 0x01) ^ ((b >> 28) & 0x01);
  u_cska32_fa27_xor0 = ((a >> 28) & 0x01) ^ ((b >> 28) & 0x01);
  u_cska32_fa27_and0 = ((a >> 28) & 0x01) & ((b >> 28) & 0x01);
  u_cska32_fa27_xor1 = ((u_cska32_fa27_xor0 >> 0) & 0x01) ^ ((u_cska32_mux2to16_xor0 >> 0) & 0x01);
  u_cska32_fa27_and1 = ((u_cska32_fa27_xor0 >> 0) & 0x01) & ((u_cska32_mux2to16_xor0 >> 0) & 0x01);
  u_cska32_fa27_or0 = ((u_cska32_fa27_and0 >> 0) & 0x01) | ((u_cska32_fa27_and1 >> 0) & 0x01);
  u_cska32_xor29 = ((a >> 29) & 0x01) ^ ((b >> 29) & 0x01);
  u_cska32_fa28_xor0 = ((a >> 29) & 0x01) ^ ((b >> 29) & 0x01);
  u_cska32_fa28_and0 = ((a >> 29) & 0x01) & ((b >> 29) & 0x01);
  u_cska32_fa28_xor1 = ((u_cska32_fa28_xor0 >> 0) & 0x01) ^ ((u_cska32_fa27_or0 >> 0) & 0x01);
  u_cska32_fa28_and1 = ((u_cska32_fa28_xor0 >> 0) & 0x01) & ((u_cska32_fa27_or0 >> 0) & 0x01);
  u_cska32_fa28_or0 = ((u_cska32_fa28_and0 >> 0) & 0x01) | ((u_cska32_fa28_and1 >> 0) & 0x01);
  u_cska32_xor30 = ((a >> 30) & 0x01) ^ ((b >> 30) & 0x01);
  u_cska32_fa29_xor0 = ((a >> 30) & 0x01) ^ ((b >> 30) & 0x01);
  u_cska32_fa29_and0 = ((a >> 30) & 0x01) & ((b >> 30) & 0x01);
  u_cska32_fa29_xor1 = ((u_cska32_fa29_xor0 >> 0) & 0x01) ^ ((u_cska32_fa28_or0 >> 0) & 0x01);
  u_cska32_fa29_and1 = ((u_cska32_fa29_xor0 >> 0) & 0x01) & ((u_cska32_fa28_or0 >> 0) & 0x01);
  u_cska32_fa29_or0 = ((u_cska32_fa29_and0 >> 0) & 0x01) | ((u_cska32_fa29_and1 >> 0) & 0x01);
  u_cska32_xor31 = ((a >> 31) & 0x01) ^ ((b >> 31) & 0x01);
  u_cska32_fa30_xor0 = ((a >> 31) & 0x01) ^ ((b >> 31) & 0x01);
  u_cska32_fa30_and0 = ((a >> 31) & 0x01) & ((b >> 31) & 0x01);
  u_cska32_fa30_xor1 = ((u_cska32_fa30_xor0 >> 0) & 0x01) ^ ((u_cska32_fa29_or0 >> 0) & 0x01);
  u_cska32_fa30_and1 = ((u_cska32_fa30_xor0 >> 0) & 0x01) & ((u_cska32_fa29_or0 >> 0) & 0x01);
  u_cska32_fa30_or0 = ((u_cska32_fa30_and0 >> 0) & 0x01) | ((u_cska32_fa30_and1 >> 0) & 0x01);
  u_cska32_and_propagate721 = ((u_cska32_xor28 >> 0) & 0x01) & ((u_cska32_xor30 >> 0) & 0x01);
  u_cska32_and_propagate722 = ((u_cska32_xor29 >> 0) & 0x01) & ((u_cska32_xor31 >> 0) & 0x01);
  u_cska32_and_propagate723 = ((u_cska32_and_propagate721 >> 0) & 0x01) & ((u_cska32_and_propagate722 >> 0) & 0x01);
  u_cska32_mux2to17_and0 = ((u_cska32_mux2to16_xor0 >> 0) & 0x01) & ((u_cska32_and_propagate723 >> 0) & 0x01);
  u_cska32_mux2to17_not0 = ~(((u_cska32_and_propagate723 >> 0) & 0x01)) & 0x01;
  u_cska32_mux2to17_and1 = ((u_cska32_fa30_or0 >> 0) & 0x01) & ((u_cska32_mux2to17_not0 >> 0) & 0x01);
  u_cska32_mux2to17_xor0 = ((u_cska32_mux2to17_and0 >> 0) & 0x01) ^ ((u_cska32_mux2to17_and1 >> 0) & 0x01);

  u_cska32_out |= ((u_cska32_ha0_xor0 >> 0) & 0x01ull) << 0;
  u_cska32_out |= ((u_cska32_fa0_xor1 >> 0) & 0x01ull) << 1;
  u_cska32_out |= ((u_cska32_fa1_xor1 >> 0) & 0x01ull) << 2;
  u_cska32_out |= ((u_cska32_fa2_xor1 >> 0) & 0x01ull) << 3;
  u_cska32_out |= ((u_cska32_fa3_xor1 >> 0) & 0x01ull) << 4;
  u_cska32_out |= ((u_cska32_fa4_xor1 >> 0) & 0x01ull) << 5;
  u_cska32_out |= ((u_cska32_fa5_xor1 >> 0) & 0x01ull) << 6;
  u_cska32_out |= ((u_cska32_fa6_xor1 >> 0) & 0x01ull) << 7;
  u_cska32_out |= ((u_cska32_fa7_xor1 >> 0) & 0x01ull) << 8;
  u_cska32_out |= ((u_cska32_fa8_xor1 >> 0) & 0x01ull) << 9;
  u_cska32_out |= ((u_cska32_fa9_xor1 >> 0) & 0x01ull) << 10;
  u_cska32_out |= ((u_cska32_fa10_xor1 >> 0) & 0x01ull) << 11;
  u_cska32_out |= ((u_cska32_fa11_xor1 >> 0) & 0x01ull) << 12;
  u_cska32_out |= ((u_cska32_fa12_xor1 >> 0) & 0x01ull) << 13;
  u_cska32_out |= ((u_cska32_fa13_xor1 >> 0) & 0x01ull) << 14;
  u_cska32_out |= ((u_cska32_fa14_xor1 >> 0) & 0x01ull) << 15;
  u_cska32_out |= ((u_cska32_fa15_xor1 >> 0) & 0x01ull) << 16;
  u_cska32_out |= ((u_cska32_fa16_xor1 >> 0) & 0x01ull) << 17;
  u_cska32_out |= ((u_cska32_fa17_xor1 >> 0) & 0x01ull) << 18;
  u_cska32_out |= ((u_cska32_fa18_xor1 >> 0) & 0x01ull) << 19;
  u_cska32_out |= ((u_cska32_fa19_xor1 >> 0) & 0x01ull) << 20;
  u_cska32_out |= ((u_cska32_fa20_xor1 >> 0) & 0x01ull) << 21;
  u_cska32_out |= ((u_cska32_fa21_xor1 >> 0) & 0x01ull) << 22;
  u_cska32_out |= ((u_cska32_fa22_xor1 >> 0) & 0x01ull) << 23;
  u_cska32_out |= ((u_cska32_fa23_xor1 >> 0) & 0x01ull) << 24;
  u_cska32_out |= ((u_cska32_fa24_xor1 >> 0) & 0x01ull) << 25;
  u_cska32_out |= ((u_cska32_fa25_xor1 >> 0) & 0x01ull) << 26;
  u_cska32_out |= ((u_cska32_fa26_xor1 >> 0) & 0x01ull) << 27;
  u_cska32_out |= ((u_cska32_fa27_xor1 >> 0) & 0x01ull) << 28;
  u_cska32_out |= ((u_cska32_fa28_xor1 >> 0) & 0x01ull) << 29;
  u_cska32_out |= ((u_cska32_fa29_xor1 >> 0) & 0x01ull) << 30;
  u_cska32_out |= ((u_cska32_fa30_xor1 >> 0) & 0x01ull) << 31;
  u_cska32_out |= ((u_cska32_mux2to17_xor0 >> 0) & 0x01ull) << 32;
  return u_cska32_out;
}