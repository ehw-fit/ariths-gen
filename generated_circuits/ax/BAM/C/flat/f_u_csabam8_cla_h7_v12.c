#include <stdio.h>
#include <stdint.h>

uint64_t f_u_csabam8_cla_h7_v12(uint64_t a, uint64_t b){
  uint64_t f_u_csabam8_cla_h7_v12_out = 0;
  uint8_t f_u_csabam8_cla_h7_v12_and5_7 = 0;
  uint8_t f_u_csabam8_cla_h7_v12_and6_7 = 0;
  uint8_t f_u_csabam8_cla_h7_v12_and7_7 = 0;

  f_u_csabam8_cla_h7_v12_and5_7 = ((a >> 5) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_cla_h7_v12_and6_7 = ((a >> 6) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_cla_h7_v12_and7_7 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);

  f_u_csabam8_cla_h7_v12_out |= (0x00) << 0;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 1;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 2;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 3;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 4;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 5;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 6;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 7;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 8;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 9;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 10;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 11;
  f_u_csabam8_cla_h7_v12_out |= ((f_u_csabam8_cla_h7_v12_and5_7 >> 0) & 0x01ull) << 12;
  f_u_csabam8_cla_h7_v12_out |= ((f_u_csabam8_cla_h7_v12_and6_7 >> 0) & 0x01ull) << 13;
  f_u_csabam8_cla_h7_v12_out |= ((f_u_csabam8_cla_h7_v12_and7_7 >> 0) & 0x01ull) << 14;
  f_u_csabam8_cla_h7_v12_out |= (0x00) << 15;
  return f_u_csabam8_cla_h7_v12_out;
}