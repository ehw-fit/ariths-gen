#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
}

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t fs(uint8_t a, uint8_t b, uint8_t bin){
  uint8_t fs_out = 0;
  uint8_t fs_xor0 = 0;
  uint8_t fs_not0 = 0;
  uint8_t fs_and0 = 0;
  uint8_t fs_xor1 = 0;
  uint8_t fs_not1 = 0;
  uint8_t fs_and1 = 0;
  uint8_t fs_or0 = 0;

  fs_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  fs_not0 = not_gate(((a >> 0) & 0x01));
  fs_and0 = and_gate(((fs_not0 >> 0) & 0x01), ((b >> 0) & 0x01));
  fs_xor1 = xor_gate(((bin >> 0) & 0x01), ((fs_xor0 >> 0) & 0x01));
  fs_not1 = not_gate(((fs_xor0 >> 0) & 0x01));
  fs_and1 = and_gate(((fs_not1 >> 0) & 0x01), ((bin >> 0) & 0x01));
  fs_or0 = or_gate(((fs_and1 >> 0) & 0x01), ((fs_and0 >> 0) & 0x01));

  fs_out |= ((fs_xor1 >> 0) & 0x01) << 0;
  fs_out |= ((fs_or0 >> 0) & 0x01) << 1;
  return fs_out;
}

uint8_t mux2to1(uint8_t d0, uint8_t d1, uint8_t sel){
  uint8_t mux2to1_out = 0;
  uint8_t mux2to1_and0 = 0;
  uint8_t mux2to1_not0 = 0;
  uint8_t mux2to1_and1 = 0;
  uint8_t mux2to1_xor0 = 0;

  mux2to1_and0 = and_gate(((d1 >> 0) & 0x01), ((sel >> 0) & 0x01));
  mux2to1_not0 = not_gate(((sel >> 0) & 0x01));
  mux2to1_and1 = and_gate(((d0 >> 0) & 0x01), ((mux2to1_not0 >> 0) & 0x01));
  mux2to1_xor0 = xor_gate(((mux2to1_and0 >> 0) & 0x01), ((mux2to1_and1 >> 0) & 0x01));

  mux2to1_out |= ((mux2to1_xor0 >> 0) & 0x01) << 0;
  return mux2to1_out;
}

uint64_t h_arrdiv4(uint64_t a, uint64_t b){
  uint8_t h_arrdiv4_out = 0;
  uint8_t h_arrdiv4_fs0_xor0 = 0;
  uint8_t h_arrdiv4_fs0_and0 = 0;
  uint8_t h_arrdiv4_fs1_xor1 = 0;
  uint8_t h_arrdiv4_fs1_or0 = 0;
  uint8_t h_arrdiv4_fs2_xor1 = 0;
  uint8_t h_arrdiv4_fs2_or0 = 0;
  uint8_t h_arrdiv4_fs3_xor1 = 0;
  uint8_t h_arrdiv4_fs3_or0 = 0;
  uint8_t h_arrdiv4_mux2to10_xor0 = 0;
  uint8_t h_arrdiv4_mux2to11_and1 = 0;
  uint8_t h_arrdiv4_mux2to12_and1 = 0;
  uint8_t h_arrdiv4_not0 = 0;
  uint8_t h_arrdiv4_fs4_xor0 = 0;
  uint8_t h_arrdiv4_fs4_and0 = 0;
  uint8_t h_arrdiv4_fs5_xor1 = 0;
  uint8_t h_arrdiv4_fs5_or0 = 0;
  uint8_t h_arrdiv4_fs6_xor1 = 0;
  uint8_t h_arrdiv4_fs6_or0 = 0;
  uint8_t h_arrdiv4_fs7_xor1 = 0;
  uint8_t h_arrdiv4_fs7_or0 = 0;
  uint8_t h_arrdiv4_mux2to13_xor0 = 0;
  uint8_t h_arrdiv4_mux2to14_xor0 = 0;
  uint8_t h_arrdiv4_mux2to15_xor0 = 0;
  uint8_t h_arrdiv4_not1 = 0;
  uint8_t h_arrdiv4_fs8_xor0 = 0;
  uint8_t h_arrdiv4_fs8_and0 = 0;
  uint8_t h_arrdiv4_fs9_xor1 = 0;
  uint8_t h_arrdiv4_fs9_or0 = 0;
  uint8_t h_arrdiv4_fs10_xor1 = 0;
  uint8_t h_arrdiv4_fs10_or0 = 0;
  uint8_t h_arrdiv4_fs11_xor1 = 0;
  uint8_t h_arrdiv4_fs11_or0 = 0;
  uint8_t h_arrdiv4_mux2to16_xor0 = 0;
  uint8_t h_arrdiv4_mux2to17_xor0 = 0;
  uint8_t h_arrdiv4_mux2to18_xor0 = 0;
  uint8_t h_arrdiv4_not2 = 0;
  uint8_t h_arrdiv4_fs12_xor0 = 0;
  uint8_t h_arrdiv4_fs12_and0 = 0;
  uint8_t h_arrdiv4_fs13_xor1 = 0;
  uint8_t h_arrdiv4_fs13_or0 = 0;
  uint8_t h_arrdiv4_fs14_xor1 = 0;
  uint8_t h_arrdiv4_fs14_or0 = 0;
  uint8_t h_arrdiv4_fs15_xor1 = 0;
  uint8_t h_arrdiv4_fs15_or0 = 0;
  uint8_t h_arrdiv4_not3 = 0;

  h_arrdiv4_fs0_xor0 = (fs(((a >> 3) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  h_arrdiv4_fs0_and0 = (fs(((a >> 3) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  h_arrdiv4_fs1_xor1 = (fs((0x00), ((b >> 1) & 0x01), ((h_arrdiv4_fs0_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs1_or0 = (fs((0x00), ((b >> 1) & 0x01), ((h_arrdiv4_fs0_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs2_xor1 = (fs((0x00), ((b >> 2) & 0x01), ((h_arrdiv4_fs1_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs2_or0 = (fs((0x00), ((b >> 2) & 0x01), ((h_arrdiv4_fs1_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs3_xor1 = (fs((0x00), ((b >> 3) & 0x01), ((h_arrdiv4_fs2_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs3_or0 = (fs((0x00), ((b >> 3) & 0x01), ((h_arrdiv4_fs2_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_mux2to10_xor0 = (mux2to1(((h_arrdiv4_fs0_xor0 >> 0) & 0x01), ((a >> 3) & 0x01), ((h_arrdiv4_fs3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_mux2to11_and1 = (mux2to1(((h_arrdiv4_fs1_xor1 >> 0) & 0x01), (0x00), ((h_arrdiv4_fs3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_mux2to12_and1 = (mux2to1(((h_arrdiv4_fs2_xor1 >> 0) & 0x01), (0x00), ((h_arrdiv4_fs3_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_not0 = not_gate(((h_arrdiv4_fs3_or0 >> 0) & 0x01));
  h_arrdiv4_fs4_xor0 = (fs(((a >> 2) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  h_arrdiv4_fs4_and0 = (fs(((a >> 2) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  h_arrdiv4_fs5_xor1 = (fs(((h_arrdiv4_mux2to10_xor0 >> 0) & 0x01), ((b >> 1) & 0x01), ((h_arrdiv4_fs4_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs5_or0 = (fs(((h_arrdiv4_mux2to10_xor0 >> 0) & 0x01), ((b >> 1) & 0x01), ((h_arrdiv4_fs4_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs6_xor1 = (fs(((h_arrdiv4_mux2to11_and1 >> 0) & 0x01), ((b >> 2) & 0x01), ((h_arrdiv4_fs5_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs6_or0 = (fs(((h_arrdiv4_mux2to11_and1 >> 0) & 0x01), ((b >> 2) & 0x01), ((h_arrdiv4_fs5_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs7_xor1 = (fs(((h_arrdiv4_mux2to12_and1 >> 0) & 0x01), ((b >> 3) & 0x01), ((h_arrdiv4_fs6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs7_or0 = (fs(((h_arrdiv4_mux2to12_and1 >> 0) & 0x01), ((b >> 3) & 0x01), ((h_arrdiv4_fs6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_mux2to13_xor0 = (mux2to1(((h_arrdiv4_fs4_xor0 >> 0) & 0x01), ((a >> 2) & 0x01), ((h_arrdiv4_fs7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_mux2to14_xor0 = (mux2to1(((h_arrdiv4_fs5_xor1 >> 0) & 0x01), ((h_arrdiv4_mux2to10_xor0 >> 0) & 0x01), ((h_arrdiv4_fs7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_mux2to15_xor0 = (mux2to1(((h_arrdiv4_fs6_xor1 >> 0) & 0x01), ((h_arrdiv4_mux2to11_and1 >> 0) & 0x01), ((h_arrdiv4_fs7_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_not1 = not_gate(((h_arrdiv4_fs7_or0 >> 0) & 0x01));
  h_arrdiv4_fs8_xor0 = (fs(((a >> 1) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  h_arrdiv4_fs8_and0 = (fs(((a >> 1) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  h_arrdiv4_fs9_xor1 = (fs(((h_arrdiv4_mux2to13_xor0 >> 0) & 0x01), ((b >> 1) & 0x01), ((h_arrdiv4_fs8_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs9_or0 = (fs(((h_arrdiv4_mux2to13_xor0 >> 0) & 0x01), ((b >> 1) & 0x01), ((h_arrdiv4_fs8_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs10_xor1 = (fs(((h_arrdiv4_mux2to14_xor0 >> 0) & 0x01), ((b >> 2) & 0x01), ((h_arrdiv4_fs9_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs10_or0 = (fs(((h_arrdiv4_mux2to14_xor0 >> 0) & 0x01), ((b >> 2) & 0x01), ((h_arrdiv4_fs9_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs11_xor1 = (fs(((h_arrdiv4_mux2to15_xor0 >> 0) & 0x01), ((b >> 3) & 0x01), ((h_arrdiv4_fs10_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs11_or0 = (fs(((h_arrdiv4_mux2to15_xor0 >> 0) & 0x01), ((b >> 3) & 0x01), ((h_arrdiv4_fs10_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_mux2to16_xor0 = (mux2to1(((h_arrdiv4_fs8_xor0 >> 0) & 0x01), ((a >> 1) & 0x01), ((h_arrdiv4_fs11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_mux2to17_xor0 = (mux2to1(((h_arrdiv4_fs9_xor1 >> 0) & 0x01), ((h_arrdiv4_mux2to13_xor0 >> 0) & 0x01), ((h_arrdiv4_fs11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_mux2to18_xor0 = (mux2to1(((h_arrdiv4_fs10_xor1 >> 0) & 0x01), ((h_arrdiv4_mux2to14_xor0 >> 0) & 0x01), ((h_arrdiv4_fs11_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_not2 = not_gate(((h_arrdiv4_fs11_or0 >> 0) & 0x01));
  h_arrdiv4_fs12_xor0 = (fs(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 0) & 0x01;
  h_arrdiv4_fs12_and0 = (fs(((a >> 0) & 0x01), ((b >> 0) & 0x01), (0x00)) >> 1) & 0x01;
  h_arrdiv4_fs13_xor1 = (fs(((h_arrdiv4_mux2to16_xor0 >> 0) & 0x01), ((b >> 1) & 0x01), ((h_arrdiv4_fs12_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs13_or0 = (fs(((h_arrdiv4_mux2to16_xor0 >> 0) & 0x01), ((b >> 1) & 0x01), ((h_arrdiv4_fs12_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs14_xor1 = (fs(((h_arrdiv4_mux2to17_xor0 >> 0) & 0x01), ((b >> 2) & 0x01), ((h_arrdiv4_fs13_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs14_or0 = (fs(((h_arrdiv4_mux2to17_xor0 >> 0) & 0x01), ((b >> 2) & 0x01), ((h_arrdiv4_fs13_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_fs15_xor1 = (fs(((h_arrdiv4_mux2to18_xor0 >> 0) & 0x01), ((b >> 3) & 0x01), ((h_arrdiv4_fs14_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_arrdiv4_fs15_or0 = (fs(((h_arrdiv4_mux2to18_xor0 >> 0) & 0x01), ((b >> 3) & 0x01), ((h_arrdiv4_fs14_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_arrdiv4_not3 = not_gate(((h_arrdiv4_fs15_or0 >> 0) & 0x01));

  h_arrdiv4_out |= ((h_arrdiv4_not3 >> 0) & 0x01) << 0;
  h_arrdiv4_out |= ((h_arrdiv4_not2 >> 0) & 0x01) << 1;
  h_arrdiv4_out |= ((h_arrdiv4_not1 >> 0) & 0x01) << 2;
  h_arrdiv4_out |= ((h_arrdiv4_not0 >> 0) & 0x01) << 3;
  return h_arrdiv4_out;
}