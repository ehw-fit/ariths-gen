#include <stdio.h>
#include <stdint.h>

uint64_t f_u_csabam8_pg_rca_h5_v11(uint64_t a, uint64_t b){
  uint64_t f_u_csabam8_pg_rca_h5_v11_out = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and6_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and7_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and5_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_ha5_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_ha5_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and6_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_ha6_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_ha6_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and7_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and4_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_ha4_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_ha4_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and5_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa5_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa5_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa5_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa5_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa5_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and6_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa6_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa6_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa6_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa6_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_fa6_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_and7_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_and2 = 0;
  uint8_t f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_or2 = 0;

  f_u_csabam8_pg_rca_h5_v11_and6_5 = ((a >> 6) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and7_5 = ((a >> 7) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and5_6 = ((a >> 5) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_ha5_6_xor0 = ((f_u_csabam8_pg_rca_h5_v11_and5_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_and6_5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_ha5_6_and0 = ((f_u_csabam8_pg_rca_h5_v11_and5_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_and6_5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and6_6 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_ha6_6_xor0 = ((f_u_csabam8_pg_rca_h5_v11_and6_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_and7_5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_ha6_6_and0 = ((f_u_csabam8_pg_rca_h5_v11_and6_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_and7_5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and7_6 = ((a >> 7) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and4_7 = ((a >> 4) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_ha4_7_xor0 = ((f_u_csabam8_pg_rca_h5_v11_and4_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_ha5_6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_ha4_7_and0 = ((f_u_csabam8_pg_rca_h5_v11_and4_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_ha5_6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and5_7 = ((a >> 5) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa5_7_xor0 = ((f_u_csabam8_pg_rca_h5_v11_and5_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_ha6_6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa5_7_and0 = ((f_u_csabam8_pg_rca_h5_v11_and5_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_ha6_6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa5_7_xor1 = ((f_u_csabam8_pg_rca_h5_v11_fa5_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_ha5_6_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa5_7_and1 = ((f_u_csabam8_pg_rca_h5_v11_fa5_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_ha5_6_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa5_7_or0 = ((f_u_csabam8_pg_rca_h5_v11_fa5_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h5_v11_fa5_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and6_7 = ((a >> 6) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa6_7_xor0 = ((f_u_csabam8_pg_rca_h5_v11_and6_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_and7_6 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa6_7_and0 = ((f_u_csabam8_pg_rca_h5_v11_and6_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_and7_6 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa6_7_xor1 = ((f_u_csabam8_pg_rca_h5_v11_fa6_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_ha6_6_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa6_7_and1 = ((f_u_csabam8_pg_rca_h5_v11_fa6_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_ha6_6_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_fa6_7_or0 = ((f_u_csabam8_pg_rca_h5_v11_fa6_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h5_v11_fa6_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_and7_7 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_xor0 = ((f_u_csabam8_pg_rca_h5_v11_fa6_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_fa5_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_and0 = ((f_u_csabam8_pg_rca_h5_v11_fa6_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_fa5_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor0 = ((f_u_csabam8_pg_rca_h5_v11_and7_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_fa6_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_and0 = ((f_u_csabam8_pg_rca_h5_v11_and7_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_fa6_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor1 = ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_and2 = ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_and0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_or2 = ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_and2 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_and0 >> 0) & 0x01);

  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 0;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 1;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 2;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 3;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 4;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 5;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 6;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 7;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 8;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 9;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 10;
  f_u_csabam8_pg_rca_h5_v11_out |= ((f_u_csabam8_pg_rca_h5_v11_fa5_7_xor1 >> 0) & 0x01ull) << 11;
  f_u_csabam8_pg_rca_h5_v11_out |= ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa1_xor0 >> 0) & 0x01ull) << 12;
  f_u_csabam8_pg_rca_h5_v11_out |= ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_pg_fa2_xor1 >> 0) & 0x01ull) << 13;
  f_u_csabam8_pg_rca_h5_v11_out |= ((f_u_csabam8_pg_rca_h5_v11_u_pg_rca4_or2 >> 0) & 0x01ull) << 14;
  f_u_csabam8_pg_rca_h5_v11_out |= (0x00) << 15;
  return f_u_csabam8_pg_rca_h5_v11_out;
}