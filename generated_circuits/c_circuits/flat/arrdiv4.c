#include <stdio.h>
#include <stdint.h>

uint64_t arrdiv4(uint64_t a, uint64_t b){
  uint8_t arrdiv4_out = 0;
  uint8_t arrdiv4_fs0_xor0 = 0;
  uint8_t arrdiv4_fs0_not0 = 0;
  uint8_t arrdiv4_fs0_and0 = 0;
  uint8_t arrdiv4_fs0_not1 = 0;
  uint8_t arrdiv4_fs1_xor1 = 0;
  uint8_t arrdiv4_fs1_not1 = 0;
  uint8_t arrdiv4_fs1_and1 = 0;
  uint8_t arrdiv4_fs1_or0 = 0;
  uint8_t arrdiv4_fs2_xor1 = 0;
  uint8_t arrdiv4_fs2_not1 = 0;
  uint8_t arrdiv4_fs2_and1 = 0;
  uint8_t arrdiv4_fs2_or0 = 0;
  uint8_t arrdiv4_fs3_xor1 = 0;
  uint8_t arrdiv4_fs3_not1 = 0;
  uint8_t arrdiv4_fs3_and1 = 0;
  uint8_t arrdiv4_fs3_or0 = 0;
  uint8_t arrdiv4_mux2to10_and0 = 0;
  uint8_t arrdiv4_mux2to10_not0 = 0;
  uint8_t arrdiv4_mux2to10_and1 = 0;
  uint8_t arrdiv4_mux2to10_xor0 = 0;
  uint8_t arrdiv4_mux2to11_not0 = 0;
  uint8_t arrdiv4_mux2to11_and1 = 0;
  uint8_t arrdiv4_mux2to12_not0 = 0;
  uint8_t arrdiv4_mux2to12_and1 = 0;
  uint8_t arrdiv4_not0 = 0;
  uint8_t arrdiv4_fs4_xor0 = 0;
  uint8_t arrdiv4_fs4_not0 = 0;
  uint8_t arrdiv4_fs4_and0 = 0;
  uint8_t arrdiv4_fs4_not1 = 0;
  uint8_t arrdiv4_fs5_xor0 = 0;
  uint8_t arrdiv4_fs5_not0 = 0;
  uint8_t arrdiv4_fs5_and0 = 0;
  uint8_t arrdiv4_fs5_xor1 = 0;
  uint8_t arrdiv4_fs5_not1 = 0;
  uint8_t arrdiv4_fs5_and1 = 0;
  uint8_t arrdiv4_fs5_or0 = 0;
  uint8_t arrdiv4_fs6_xor0 = 0;
  uint8_t arrdiv4_fs6_not0 = 0;
  uint8_t arrdiv4_fs6_and0 = 0;
  uint8_t arrdiv4_fs6_xor1 = 0;
  uint8_t arrdiv4_fs6_not1 = 0;
  uint8_t arrdiv4_fs6_and1 = 0;
  uint8_t arrdiv4_fs6_or0 = 0;
  uint8_t arrdiv4_fs7_xor0 = 0;
  uint8_t arrdiv4_fs7_not0 = 0;
  uint8_t arrdiv4_fs7_and0 = 0;
  uint8_t arrdiv4_fs7_xor1 = 0;
  uint8_t arrdiv4_fs7_not1 = 0;
  uint8_t arrdiv4_fs7_and1 = 0;
  uint8_t arrdiv4_fs7_or0 = 0;
  uint8_t arrdiv4_mux2to13_and0 = 0;
  uint8_t arrdiv4_mux2to13_not0 = 0;
  uint8_t arrdiv4_mux2to13_and1 = 0;
  uint8_t arrdiv4_mux2to13_xor0 = 0;
  uint8_t arrdiv4_mux2to14_and0 = 0;
  uint8_t arrdiv4_mux2to14_not0 = 0;
  uint8_t arrdiv4_mux2to14_and1 = 0;
  uint8_t arrdiv4_mux2to14_xor0 = 0;
  uint8_t arrdiv4_mux2to15_and0 = 0;
  uint8_t arrdiv4_mux2to15_not0 = 0;
  uint8_t arrdiv4_mux2to15_and1 = 0;
  uint8_t arrdiv4_mux2to15_xor0 = 0;
  uint8_t arrdiv4_not1 = 0;
  uint8_t arrdiv4_fs8_xor0 = 0;
  uint8_t arrdiv4_fs8_not0 = 0;
  uint8_t arrdiv4_fs8_and0 = 0;
  uint8_t arrdiv4_fs8_not1 = 0;
  uint8_t arrdiv4_fs9_xor0 = 0;
  uint8_t arrdiv4_fs9_not0 = 0;
  uint8_t arrdiv4_fs9_and0 = 0;
  uint8_t arrdiv4_fs9_xor1 = 0;
  uint8_t arrdiv4_fs9_not1 = 0;
  uint8_t arrdiv4_fs9_and1 = 0;
  uint8_t arrdiv4_fs9_or0 = 0;
  uint8_t arrdiv4_fs10_xor0 = 0;
  uint8_t arrdiv4_fs10_not0 = 0;
  uint8_t arrdiv4_fs10_and0 = 0;
  uint8_t arrdiv4_fs10_xor1 = 0;
  uint8_t arrdiv4_fs10_not1 = 0;
  uint8_t arrdiv4_fs10_and1 = 0;
  uint8_t arrdiv4_fs10_or0 = 0;
  uint8_t arrdiv4_fs11_xor0 = 0;
  uint8_t arrdiv4_fs11_not0 = 0;
  uint8_t arrdiv4_fs11_and0 = 0;
  uint8_t arrdiv4_fs11_xor1 = 0;
  uint8_t arrdiv4_fs11_not1 = 0;
  uint8_t arrdiv4_fs11_and1 = 0;
  uint8_t arrdiv4_fs11_or0 = 0;
  uint8_t arrdiv4_mux2to16_and0 = 0;
  uint8_t arrdiv4_mux2to16_not0 = 0;
  uint8_t arrdiv4_mux2to16_and1 = 0;
  uint8_t arrdiv4_mux2to16_xor0 = 0;
  uint8_t arrdiv4_mux2to17_and0 = 0;
  uint8_t arrdiv4_mux2to17_not0 = 0;
  uint8_t arrdiv4_mux2to17_and1 = 0;
  uint8_t arrdiv4_mux2to17_xor0 = 0;
  uint8_t arrdiv4_mux2to18_and0 = 0;
  uint8_t arrdiv4_mux2to18_not0 = 0;
  uint8_t arrdiv4_mux2to18_and1 = 0;
  uint8_t arrdiv4_mux2to18_xor0 = 0;
  uint8_t arrdiv4_not2 = 0;
  uint8_t arrdiv4_fs12_xor0 = 0;
  uint8_t arrdiv4_fs12_not0 = 0;
  uint8_t arrdiv4_fs12_and0 = 0;
  uint8_t arrdiv4_fs12_not1 = 0;
  uint8_t arrdiv4_fs13_xor0 = 0;
  uint8_t arrdiv4_fs13_not0 = 0;
  uint8_t arrdiv4_fs13_and0 = 0;
  uint8_t arrdiv4_fs13_xor1 = 0;
  uint8_t arrdiv4_fs13_not1 = 0;
  uint8_t arrdiv4_fs13_and1 = 0;
  uint8_t arrdiv4_fs13_or0 = 0;
  uint8_t arrdiv4_fs14_xor0 = 0;
  uint8_t arrdiv4_fs14_not0 = 0;
  uint8_t arrdiv4_fs14_and0 = 0;
  uint8_t arrdiv4_fs14_xor1 = 0;
  uint8_t arrdiv4_fs14_not1 = 0;
  uint8_t arrdiv4_fs14_and1 = 0;
  uint8_t arrdiv4_fs14_or0 = 0;
  uint8_t arrdiv4_fs15_xor0 = 0;
  uint8_t arrdiv4_fs15_not0 = 0;
  uint8_t arrdiv4_fs15_and0 = 0;
  uint8_t arrdiv4_fs15_xor1 = 0;
  uint8_t arrdiv4_fs15_not1 = 0;
  uint8_t arrdiv4_fs15_and1 = 0;
  uint8_t arrdiv4_fs15_or0 = 0;
  uint8_t arrdiv4_not3 = 0;

  arrdiv4_fs0_xor0 = ((a >> 3) & 0x01) ^ ((b >> 0) & 0x01);
  arrdiv4_fs0_not0 = ~(((a >> 3) & 0x01)) & 0x01;
  arrdiv4_fs0_and0 = ((arrdiv4_fs0_not0 >> 0) & 0x01) & ((b >> 0) & 0x01);
  arrdiv4_fs0_not1 = ~(((arrdiv4_fs0_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs1_xor1 = ((arrdiv4_fs0_and0 >> 0) & 0x01) ^ ((b >> 1) & 0x01);
  arrdiv4_fs1_not1 = ~(((b >> 1) & 0x01)) & 0x01;
  arrdiv4_fs1_and1 = ((arrdiv4_fs1_not1 >> 0) & 0x01) & ((arrdiv4_fs0_and0 >> 0) & 0x01);
  arrdiv4_fs1_or0 = ((arrdiv4_fs1_and1 >> 0) & 0x01) | ((b >> 1) & 0x01);
  arrdiv4_fs2_xor1 = ((arrdiv4_fs1_or0 >> 0) & 0x01) ^ ((b >> 2) & 0x01);
  arrdiv4_fs2_not1 = ~(((b >> 2) & 0x01)) & 0x01;
  arrdiv4_fs2_and1 = ((arrdiv4_fs2_not1 >> 0) & 0x01) & ((arrdiv4_fs1_or0 >> 0) & 0x01);
  arrdiv4_fs2_or0 = ((arrdiv4_fs2_and1 >> 0) & 0x01) | ((b >> 2) & 0x01);
  arrdiv4_fs3_xor1 = ((arrdiv4_fs2_or0 >> 0) & 0x01) ^ ((b >> 3) & 0x01);
  arrdiv4_fs3_not1 = ~(((b >> 3) & 0x01)) & 0x01;
  arrdiv4_fs3_and1 = ((arrdiv4_fs3_not1 >> 0) & 0x01) & ((arrdiv4_fs2_or0 >> 0) & 0x01);
  arrdiv4_fs3_or0 = ((arrdiv4_fs3_and1 >> 0) & 0x01) | ((b >> 3) & 0x01);
  arrdiv4_mux2to10_and0 = ((a >> 3) & 0x01) & ((arrdiv4_fs3_or0 >> 0) & 0x01);
  arrdiv4_mux2to10_not0 = ~(((arrdiv4_fs3_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to10_and1 = ((arrdiv4_fs0_xor0 >> 0) & 0x01) & ((arrdiv4_mux2to10_not0 >> 0) & 0x01);
  arrdiv4_mux2to10_xor0 = ((arrdiv4_mux2to10_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to10_and1 >> 0) & 0x01);
  arrdiv4_mux2to11_not0 = ~(((arrdiv4_fs3_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to11_and1 = ((arrdiv4_fs1_xor1 >> 0) & 0x01) & ((arrdiv4_mux2to11_not0 >> 0) & 0x01);
  arrdiv4_mux2to12_not0 = ~(((arrdiv4_fs3_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to12_and1 = ((arrdiv4_fs2_xor1 >> 0) & 0x01) & ((arrdiv4_mux2to12_not0 >> 0) & 0x01);
  arrdiv4_not0 = ~(((arrdiv4_fs3_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs4_xor0 = ((a >> 2) & 0x01) ^ ((b >> 0) & 0x01);
  arrdiv4_fs4_not0 = ~(((a >> 2) & 0x01)) & 0x01;
  arrdiv4_fs4_and0 = ((arrdiv4_fs4_not0 >> 0) & 0x01) & ((b >> 0) & 0x01);
  arrdiv4_fs4_not1 = ~(((arrdiv4_fs4_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs5_xor0 = ((arrdiv4_mux2to10_xor0 >> 0) & 0x01) ^ ((b >> 1) & 0x01);
  arrdiv4_fs5_not0 = ~(((arrdiv4_mux2to10_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs5_and0 = ((arrdiv4_fs5_not0 >> 0) & 0x01) & ((b >> 1) & 0x01);
  arrdiv4_fs5_xor1 = ((arrdiv4_fs4_and0 >> 0) & 0x01) ^ ((arrdiv4_fs5_xor0 >> 0) & 0x01);
  arrdiv4_fs5_not1 = ~(((arrdiv4_fs5_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs5_and1 = ((arrdiv4_fs5_not1 >> 0) & 0x01) & ((arrdiv4_fs4_and0 >> 0) & 0x01);
  arrdiv4_fs5_or0 = ((arrdiv4_fs5_and1 >> 0) & 0x01) | ((arrdiv4_fs5_and0 >> 0) & 0x01);
  arrdiv4_fs6_xor0 = ((arrdiv4_mux2to11_and1 >> 0) & 0x01) ^ ((b >> 2) & 0x01);
  arrdiv4_fs6_not0 = ~(((arrdiv4_mux2to11_and1 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs6_and0 = ((arrdiv4_fs6_not0 >> 0) & 0x01) & ((b >> 2) & 0x01);
  arrdiv4_fs6_xor1 = ((arrdiv4_fs5_or0 >> 0) & 0x01) ^ ((arrdiv4_fs6_xor0 >> 0) & 0x01);
  arrdiv4_fs6_not1 = ~(((arrdiv4_fs6_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs6_and1 = ((arrdiv4_fs6_not1 >> 0) & 0x01) & ((arrdiv4_fs5_or0 >> 0) & 0x01);
  arrdiv4_fs6_or0 = ((arrdiv4_fs6_and1 >> 0) & 0x01) | ((arrdiv4_fs6_and0 >> 0) & 0x01);
  arrdiv4_fs7_xor0 = ((arrdiv4_mux2to12_and1 >> 0) & 0x01) ^ ((b >> 3) & 0x01);
  arrdiv4_fs7_not0 = ~(((arrdiv4_mux2to12_and1 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs7_and0 = ((arrdiv4_fs7_not0 >> 0) & 0x01) & ((b >> 3) & 0x01);
  arrdiv4_fs7_xor1 = ((arrdiv4_fs6_or0 >> 0) & 0x01) ^ ((arrdiv4_fs7_xor0 >> 0) & 0x01);
  arrdiv4_fs7_not1 = ~(((arrdiv4_fs7_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs7_and1 = ((arrdiv4_fs7_not1 >> 0) & 0x01) & ((arrdiv4_fs6_or0 >> 0) & 0x01);
  arrdiv4_fs7_or0 = ((arrdiv4_fs7_and1 >> 0) & 0x01) | ((arrdiv4_fs7_and0 >> 0) & 0x01);
  arrdiv4_mux2to13_and0 = ((a >> 2) & 0x01) & ((arrdiv4_fs7_or0 >> 0) & 0x01);
  arrdiv4_mux2to13_not0 = ~(((arrdiv4_fs7_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to13_and1 = ((arrdiv4_fs4_xor0 >> 0) & 0x01) & ((arrdiv4_mux2to13_not0 >> 0) & 0x01);
  arrdiv4_mux2to13_xor0 = ((arrdiv4_mux2to13_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to13_and1 >> 0) & 0x01);
  arrdiv4_mux2to14_and0 = ((arrdiv4_mux2to10_xor0 >> 0) & 0x01) & ((arrdiv4_fs7_or0 >> 0) & 0x01);
  arrdiv4_mux2to14_not0 = ~(((arrdiv4_fs7_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to14_and1 = ((arrdiv4_fs5_xor1 >> 0) & 0x01) & ((arrdiv4_mux2to14_not0 >> 0) & 0x01);
  arrdiv4_mux2to14_xor0 = ((arrdiv4_mux2to14_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to14_and1 >> 0) & 0x01);
  arrdiv4_mux2to15_and0 = ((arrdiv4_mux2to11_and1 >> 0) & 0x01) & ((arrdiv4_fs7_or0 >> 0) & 0x01);
  arrdiv4_mux2to15_not0 = ~(((arrdiv4_fs7_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to15_and1 = ((arrdiv4_fs6_xor1 >> 0) & 0x01) & ((arrdiv4_mux2to15_not0 >> 0) & 0x01);
  arrdiv4_mux2to15_xor0 = ((arrdiv4_mux2to15_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to15_and1 >> 0) & 0x01);
  arrdiv4_not1 = ~(((arrdiv4_fs7_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs8_xor0 = ((a >> 1) & 0x01) ^ ((b >> 0) & 0x01);
  arrdiv4_fs8_not0 = ~(((a >> 1) & 0x01)) & 0x01;
  arrdiv4_fs8_and0 = ((arrdiv4_fs8_not0 >> 0) & 0x01) & ((b >> 0) & 0x01);
  arrdiv4_fs8_not1 = ~(((arrdiv4_fs8_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs9_xor0 = ((arrdiv4_mux2to13_xor0 >> 0) & 0x01) ^ ((b >> 1) & 0x01);
  arrdiv4_fs9_not0 = ~(((arrdiv4_mux2to13_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs9_and0 = ((arrdiv4_fs9_not0 >> 0) & 0x01) & ((b >> 1) & 0x01);
  arrdiv4_fs9_xor1 = ((arrdiv4_fs8_and0 >> 0) & 0x01) ^ ((arrdiv4_fs9_xor0 >> 0) & 0x01);
  arrdiv4_fs9_not1 = ~(((arrdiv4_fs9_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs9_and1 = ((arrdiv4_fs9_not1 >> 0) & 0x01) & ((arrdiv4_fs8_and0 >> 0) & 0x01);
  arrdiv4_fs9_or0 = ((arrdiv4_fs9_and1 >> 0) & 0x01) | ((arrdiv4_fs9_and0 >> 0) & 0x01);
  arrdiv4_fs10_xor0 = ((arrdiv4_mux2to14_xor0 >> 0) & 0x01) ^ ((b >> 2) & 0x01);
  arrdiv4_fs10_not0 = ~(((arrdiv4_mux2to14_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs10_and0 = ((arrdiv4_fs10_not0 >> 0) & 0x01) & ((b >> 2) & 0x01);
  arrdiv4_fs10_xor1 = ((arrdiv4_fs9_or0 >> 0) & 0x01) ^ ((arrdiv4_fs10_xor0 >> 0) & 0x01);
  arrdiv4_fs10_not1 = ~(((arrdiv4_fs10_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs10_and1 = ((arrdiv4_fs10_not1 >> 0) & 0x01) & ((arrdiv4_fs9_or0 >> 0) & 0x01);
  arrdiv4_fs10_or0 = ((arrdiv4_fs10_and1 >> 0) & 0x01) | ((arrdiv4_fs10_and0 >> 0) & 0x01);
  arrdiv4_fs11_xor0 = ((arrdiv4_mux2to15_xor0 >> 0) & 0x01) ^ ((b >> 3) & 0x01);
  arrdiv4_fs11_not0 = ~(((arrdiv4_mux2to15_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs11_and0 = ((arrdiv4_fs11_not0 >> 0) & 0x01) & ((b >> 3) & 0x01);
  arrdiv4_fs11_xor1 = ((arrdiv4_fs10_or0 >> 0) & 0x01) ^ ((arrdiv4_fs11_xor0 >> 0) & 0x01);
  arrdiv4_fs11_not1 = ~(((arrdiv4_fs11_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs11_and1 = ((arrdiv4_fs11_not1 >> 0) & 0x01) & ((arrdiv4_fs10_or0 >> 0) & 0x01);
  arrdiv4_fs11_or0 = ((arrdiv4_fs11_and1 >> 0) & 0x01) | ((arrdiv4_fs11_and0 >> 0) & 0x01);
  arrdiv4_mux2to16_and0 = ((a >> 1) & 0x01) & ((arrdiv4_fs11_or0 >> 0) & 0x01);
  arrdiv4_mux2to16_not0 = ~(((arrdiv4_fs11_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to16_and1 = ((arrdiv4_fs8_xor0 >> 0) & 0x01) & ((arrdiv4_mux2to16_not0 >> 0) & 0x01);
  arrdiv4_mux2to16_xor0 = ((arrdiv4_mux2to16_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to16_and1 >> 0) & 0x01);
  arrdiv4_mux2to17_and0 = ((arrdiv4_mux2to13_xor0 >> 0) & 0x01) & ((arrdiv4_fs11_or0 >> 0) & 0x01);
  arrdiv4_mux2to17_not0 = ~(((arrdiv4_fs11_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to17_and1 = ((arrdiv4_fs9_xor1 >> 0) & 0x01) & ((arrdiv4_mux2to17_not0 >> 0) & 0x01);
  arrdiv4_mux2to17_xor0 = ((arrdiv4_mux2to17_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to17_and1 >> 0) & 0x01);
  arrdiv4_mux2to18_and0 = ((arrdiv4_mux2to14_xor0 >> 0) & 0x01) & ((arrdiv4_fs11_or0 >> 0) & 0x01);
  arrdiv4_mux2to18_not0 = ~(((arrdiv4_fs11_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_mux2to18_and1 = ((arrdiv4_fs10_xor1 >> 0) & 0x01) & ((arrdiv4_mux2to18_not0 >> 0) & 0x01);
  arrdiv4_mux2to18_xor0 = ((arrdiv4_mux2to18_and0 >> 0) & 0x01) ^ ((arrdiv4_mux2to18_and1 >> 0) & 0x01);
  arrdiv4_not2 = ~(((arrdiv4_fs11_or0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs12_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  arrdiv4_fs12_not0 = ~(((a >> 0) & 0x01)) & 0x01;
  arrdiv4_fs12_and0 = ((arrdiv4_fs12_not0 >> 0) & 0x01) & ((b >> 0) & 0x01);
  arrdiv4_fs12_not1 = ~(((arrdiv4_fs12_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs13_xor0 = ((arrdiv4_mux2to16_xor0 >> 0) & 0x01) ^ ((b >> 1) & 0x01);
  arrdiv4_fs13_not0 = ~(((arrdiv4_mux2to16_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs13_and0 = ((arrdiv4_fs13_not0 >> 0) & 0x01) & ((b >> 1) & 0x01);
  arrdiv4_fs13_xor1 = ((arrdiv4_fs12_and0 >> 0) & 0x01) ^ ((arrdiv4_fs13_xor0 >> 0) & 0x01);
  arrdiv4_fs13_not1 = ~(((arrdiv4_fs13_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs13_and1 = ((arrdiv4_fs13_not1 >> 0) & 0x01) & ((arrdiv4_fs12_and0 >> 0) & 0x01);
  arrdiv4_fs13_or0 = ((arrdiv4_fs13_and1 >> 0) & 0x01) | ((arrdiv4_fs13_and0 >> 0) & 0x01);
  arrdiv4_fs14_xor0 = ((arrdiv4_mux2to17_xor0 >> 0) & 0x01) ^ ((b >> 2) & 0x01);
  arrdiv4_fs14_not0 = ~(((arrdiv4_mux2to17_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs14_and0 = ((arrdiv4_fs14_not0 >> 0) & 0x01) & ((b >> 2) & 0x01);
  arrdiv4_fs14_xor1 = ((arrdiv4_fs13_or0 >> 0) & 0x01) ^ ((arrdiv4_fs14_xor0 >> 0) & 0x01);
  arrdiv4_fs14_not1 = ~(((arrdiv4_fs14_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs14_and1 = ((arrdiv4_fs14_not1 >> 0) & 0x01) & ((arrdiv4_fs13_or0 >> 0) & 0x01);
  arrdiv4_fs14_or0 = ((arrdiv4_fs14_and1 >> 0) & 0x01) | ((arrdiv4_fs14_and0 >> 0) & 0x01);
  arrdiv4_fs15_xor0 = ((arrdiv4_mux2to18_xor0 >> 0) & 0x01) ^ ((b >> 3) & 0x01);
  arrdiv4_fs15_not0 = ~(((arrdiv4_mux2to18_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs15_and0 = ((arrdiv4_fs15_not0 >> 0) & 0x01) & ((b >> 3) & 0x01);
  arrdiv4_fs15_xor1 = ((arrdiv4_fs14_or0 >> 0) & 0x01) ^ ((arrdiv4_fs15_xor0 >> 0) & 0x01);
  arrdiv4_fs15_not1 = ~(((arrdiv4_fs15_xor0 >> 0) & 0x01)) & 0x01;
  arrdiv4_fs15_and1 = ((arrdiv4_fs15_not1 >> 0) & 0x01) & ((arrdiv4_fs14_or0 >> 0) & 0x01);
  arrdiv4_fs15_or0 = ((arrdiv4_fs15_and1 >> 0) & 0x01) | ((arrdiv4_fs15_and0 >> 0) & 0x01);
  arrdiv4_not3 = ~(((arrdiv4_fs15_or0 >> 0) & 0x01)) & 0x01;

  arrdiv4_out |= ((arrdiv4_not3 >> 0) & 0x01ull) << 0;
  arrdiv4_out |= ((arrdiv4_not2 >> 0) & 0x01ull) << 1;
  arrdiv4_out |= ((arrdiv4_not1 >> 0) & 0x01ull) << 2;
  arrdiv4_out |= ((arrdiv4_not0 >> 0) & 0x01ull) << 3;
  return arrdiv4_out;
}