#include <stdio.h>
#include <stdint.h>

uint64_t f_u_csabam8_rca_h5_v5(uint64_t a, uint64_t b){
  uint64_t f_u_csabam8_rca_h5_v5_out = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and0_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and1_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and2_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and3_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and4_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and5_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and6_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and7_5 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and0_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha0_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha0_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and1_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha1_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha1_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and2_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha2_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha2_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and3_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha3_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha3_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and4_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha4_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha4_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and5_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha5_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha5_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and6_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha6_6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_ha6_6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and7_6 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and0_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa0_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa0_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa0_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa0_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa0_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and1_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa1_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa1_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa1_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa1_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa1_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and2_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa2_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa2_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa2_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa2_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa2_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and3_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa3_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa3_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa3_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa3_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa3_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and4_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa4_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa4_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa4_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa4_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa4_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and5_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa5_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa5_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa5_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa5_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa5_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and6_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa6_7_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa6_7_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa6_7_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa6_7_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_fa6_7_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_and7_7 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_ha_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_ha_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa1_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa1_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa1_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa2_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa2_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa2_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa3_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa3_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa3_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa4_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa4_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa4_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa5_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa5_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa5_or0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa6_and0 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa6_and1 = 0;
  uint8_t f_u_csabam8_rca_h5_v5_u_rca8_fa6_or0 = 0;

  f_u_csabam8_rca_h5_v5_and0_5 = ((a >> 0) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and1_5 = ((a >> 1) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and2_5 = ((a >> 2) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and3_5 = ((a >> 3) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and4_5 = ((a >> 4) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and5_5 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and6_5 = ((a >> 6) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and7_5 = ((a >> 7) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_rca_h5_v5_and0_6 = ((a >> 0) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha0_6_xor0 = ((f_u_csabam8_rca_h5_v5_and0_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and1_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha0_6_and0 = ((f_u_csabam8_rca_h5_v5_and0_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and1_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and1_6 = ((a >> 1) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha1_6_xor0 = ((f_u_csabam8_rca_h5_v5_and1_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and2_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha1_6_and0 = ((f_u_csabam8_rca_h5_v5_and1_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and2_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and2_6 = ((a >> 2) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha2_6_xor0 = ((f_u_csabam8_rca_h5_v5_and2_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and3_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha2_6_and0 = ((f_u_csabam8_rca_h5_v5_and2_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and3_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and3_6 = ((a >> 3) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha3_6_xor0 = ((f_u_csabam8_rca_h5_v5_and3_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and4_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha3_6_and0 = ((f_u_csabam8_rca_h5_v5_and3_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and4_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and4_6 = ((a >> 4) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha4_6_xor0 = ((f_u_csabam8_rca_h5_v5_and4_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and5_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha4_6_and0 = ((f_u_csabam8_rca_h5_v5_and4_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and5_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and5_6 = ((a >> 5) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha5_6_xor0 = ((f_u_csabam8_rca_h5_v5_and5_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and6_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha5_6_and0 = ((f_u_csabam8_rca_h5_v5_and5_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and6_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and6_6 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_ha6_6_xor0 = ((f_u_csabam8_rca_h5_v5_and6_6 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and7_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_ha6_6_and0 = ((f_u_csabam8_rca_h5_v5_and6_6 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and7_5 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and7_6 = ((a >> 7) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_rca_h5_v5_and0_7 = ((a >> 0) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa0_7_xor0 = ((f_u_csabam8_rca_h5_v5_and0_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha1_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa0_7_and0 = ((f_u_csabam8_rca_h5_v5_and0_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha1_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa0_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa0_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha0_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa0_7_and1 = ((f_u_csabam8_rca_h5_v5_fa0_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha0_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa0_7_or0 = ((f_u_csabam8_rca_h5_v5_fa0_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa0_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and1_7 = ((a >> 1) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa1_7_xor0 = ((f_u_csabam8_rca_h5_v5_and1_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha2_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa1_7_and0 = ((f_u_csabam8_rca_h5_v5_and1_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha2_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa1_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa1_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha1_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa1_7_and1 = ((f_u_csabam8_rca_h5_v5_fa1_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha1_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa1_7_or0 = ((f_u_csabam8_rca_h5_v5_fa1_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa1_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and2_7 = ((a >> 2) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa2_7_xor0 = ((f_u_csabam8_rca_h5_v5_and2_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha3_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa2_7_and0 = ((f_u_csabam8_rca_h5_v5_and2_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha3_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa2_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa2_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha2_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa2_7_and1 = ((f_u_csabam8_rca_h5_v5_fa2_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha2_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa2_7_or0 = ((f_u_csabam8_rca_h5_v5_fa2_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa2_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and3_7 = ((a >> 3) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa3_7_xor0 = ((f_u_csabam8_rca_h5_v5_and3_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha4_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa3_7_and0 = ((f_u_csabam8_rca_h5_v5_and3_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha4_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa3_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa3_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha3_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa3_7_and1 = ((f_u_csabam8_rca_h5_v5_fa3_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha3_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa3_7_or0 = ((f_u_csabam8_rca_h5_v5_fa3_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa3_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and4_7 = ((a >> 4) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa4_7_xor0 = ((f_u_csabam8_rca_h5_v5_and4_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha5_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa4_7_and0 = ((f_u_csabam8_rca_h5_v5_and4_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha5_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa4_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa4_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha4_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa4_7_and1 = ((f_u_csabam8_rca_h5_v5_fa4_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha4_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa4_7_or0 = ((f_u_csabam8_rca_h5_v5_fa4_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa4_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and5_7 = ((a >> 5) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa5_7_xor0 = ((f_u_csabam8_rca_h5_v5_and5_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha6_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa5_7_and0 = ((f_u_csabam8_rca_h5_v5_and5_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha6_6_xor0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa5_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa5_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha5_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa5_7_and1 = ((f_u_csabam8_rca_h5_v5_fa5_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha5_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa5_7_or0 = ((f_u_csabam8_rca_h5_v5_fa5_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa5_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and6_7 = ((a >> 6) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_fa6_7_xor0 = ((f_u_csabam8_rca_h5_v5_and6_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_and7_6 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa6_7_and0 = ((f_u_csabam8_rca_h5_v5_and6_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_and7_6 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa6_7_xor1 = ((f_u_csabam8_rca_h5_v5_fa6_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_ha6_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa6_7_and1 = ((f_u_csabam8_rca_h5_v5_fa6_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_ha6_6_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_fa6_7_or0 = ((f_u_csabam8_rca_h5_v5_fa6_7_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_fa6_7_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_and7_7 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_ha_xor0 = ((f_u_csabam8_rca_h5_v5_fa1_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa0_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_ha_and0 = ((f_u_csabam8_rca_h5_v5_fa1_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa0_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor0 = ((f_u_csabam8_rca_h5_v5_fa2_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa1_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa1_and0 = ((f_u_csabam8_rca_h5_v5_fa2_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa1_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_u_rca8_ha_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa1_and1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_u_rca8_ha_and0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa1_or0 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor0 = ((f_u_csabam8_rca_h5_v5_fa3_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa2_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa2_and0 = ((f_u_csabam8_rca_h5_v5_fa3_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa2_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa2_and1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa2_or0 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor0 = ((f_u_csabam8_rca_h5_v5_fa4_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa3_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa3_and0 = ((f_u_csabam8_rca_h5_v5_fa4_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa3_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa3_and1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa3_or0 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor0 = ((f_u_csabam8_rca_h5_v5_fa5_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa4_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa4_and0 = ((f_u_csabam8_rca_h5_v5_fa5_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa4_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa4_and1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa4_or0 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor0 = ((f_u_csabam8_rca_h5_v5_fa6_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa5_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa5_and0 = ((f_u_csabam8_rca_h5_v5_fa6_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa5_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa5_and1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa5_or0 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_and1 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor0 = ((f_u_csabam8_rca_h5_v5_and7_7 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_fa6_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa6_and0 = ((f_u_csabam8_rca_h5_v5_and7_7 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_fa6_7_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa6_and1 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor0 >> 0) & 0x01) & ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_or0 >> 0) & 0x01);
  f_u_csabam8_rca_h5_v5_u_rca8_fa6_or0 = ((f_u_csabam8_rca_h5_v5_u_rca8_fa6_and0 >> 0) & 0x01) | ((f_u_csabam8_rca_h5_v5_u_rca8_fa6_and1 >> 0) & 0x01);

  f_u_csabam8_rca_h5_v5_out |= (0x00) << 0;
  f_u_csabam8_rca_h5_v5_out |= (0x00) << 1;
  f_u_csabam8_rca_h5_v5_out |= (0x00) << 2;
  f_u_csabam8_rca_h5_v5_out |= (0x00) << 3;
  f_u_csabam8_rca_h5_v5_out |= (0x00) << 4;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_and0_5 >> 0) & 0x01ull) << 5;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_ha0_6_xor0 >> 0) & 0x01ull) << 6;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_fa0_7_xor1 >> 0) & 0x01ull) << 7;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_ha_xor0 >> 0) & 0x01ull) << 8;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa1_xor1 >> 0) & 0x01ull) << 9;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa2_xor1 >> 0) & 0x01ull) << 10;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa3_xor1 >> 0) & 0x01ull) << 11;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa4_xor1 >> 0) & 0x01ull) << 12;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa5_xor1 >> 0) & 0x01ull) << 13;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa6_xor1 >> 0) & 0x01ull) << 14;
  f_u_csabam8_rca_h5_v5_out |= ((f_u_csabam8_rca_h5_v5_u_rca8_fa6_or0 >> 0) & 0x01ull) << 15;
  return f_u_csabam8_rca_h5_v5_out;
}