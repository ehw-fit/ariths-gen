#include <stdio.h>
#include <stdint.h>

uint64_t f_u_csabam8_rca_h7_v7(uint64_t a, uint64_t b){
  uint64_t f_u_csabam8_rca_h7_v7_out = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and0_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and1_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and2_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and3_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and4_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and5_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and6_7 = 0;
  uint8_t f_u_csabam8_rca_h7_v7_and7_7 = 0;

  f_u_csabam8_rca_h7_v7_and0_7 = ((a >> 0) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and1_7 = ((a >> 1) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and2_7 = ((a >> 2) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and3_7 = ((a >> 3) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and4_7 = ((a >> 4) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and5_7 = ((a >> 5) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and6_7 = ((a >> 6) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h7_v7_and7_7 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);

  f_u_csabam8_rca_h7_v7_out |= (0x00) << 0;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 1;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 2;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 3;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 4;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 5;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 6;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and0_7 >> 0) & 0x01ull) << 7;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and1_7 >> 0) & 0x01ull) << 8;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and2_7 >> 0) & 0x01ull) << 9;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and3_7 >> 0) & 0x01ull) << 10;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and4_7 >> 0) & 0x01ull) << 11;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and5_7 >> 0) & 0x01ull) << 12;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and6_7 >> 0) & 0x01ull) << 13;
  f_u_csabam8_rca_h7_v7_out |= ((f_u_csabam8_rca_h7_v7_and7_7 >> 0) & 0x01ull) << 14;
  f_u_csabam8_rca_h7_v7_out |= (0x00) << 15;
  return f_u_csabam8_rca_h7_v7_out;
}