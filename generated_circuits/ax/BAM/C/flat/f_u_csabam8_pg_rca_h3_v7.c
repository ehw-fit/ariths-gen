#include <stdio.h>
#include <stdint.h>

uint64_t f_u_csabam8_pg_rca_h3_v7(uint64_t a, uint64_t b){
  uint64_t f_u_csabam8_pg_rca_h3_v7_out = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and4_3 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and5_3 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and6_3 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and7_3 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and3_4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha3_4_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha3_4_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and4_4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha4_4_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha4_4_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and5_4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha5_4_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha5_4_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and6_4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha6_4_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha6_4_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and7_4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and2_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha2_5_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha2_5_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and3_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_5_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_5_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_5_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_5_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_5_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and4_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_5_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_5_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_5_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_5_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_5_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and5_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_5_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_5_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_5_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_5_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_5_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and6_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_5_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_5_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_5_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_5_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_5_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and7_5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and1_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha1_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha1_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and2_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_6_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_6_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_6_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and3_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_6_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_6_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_6_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and4_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_6_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_6_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_6_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and5_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_6_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_6_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_6_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and6_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_6_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_6_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_6_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and7_6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and0_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha0_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_ha0_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and1_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa1_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa1_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa1_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa1_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa1_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and2_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa2_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and3_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa3_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and4_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa4_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and5_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa5_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and6_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_7_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_7_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_7_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_7_and1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_fa6_7_or0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_and7_7 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and2 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or2 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and3 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or3 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or4 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or5 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_and0 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor1 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and6 = 0;
  uint8_t f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or6 = 0;

  f_u_csabam8_pg_rca_h3_v7_and4_3 = ((a >> 4) & 0x01) & ((b >> 3) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and5_3 = ((a >> 5) & 0x01) & ((b >> 3) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and6_3 = ((a >> 6) & 0x01) & ((b >> 3) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and7_3 = ((a >> 7) & 0x01) & ((b >> 3) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and3_4 = ((a >> 3) & 0x01) & ((b >> 4) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha3_4_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and3_4 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and4_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha3_4_and0 = ((f_u_csabam8_pg_rca_h3_v7_and3_4 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and4_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and4_4 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha4_4_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and4_4 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and5_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha4_4_and0 = ((f_u_csabam8_pg_rca_h3_v7_and4_4 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and5_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and5_4 = ((a >> 5) & 0x01) & ((b >> 4) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha5_4_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and5_4 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and6_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha5_4_and0 = ((f_u_csabam8_pg_rca_h3_v7_and5_4 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and6_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and6_4 = ((a >> 6) & 0x01) & ((b >> 4) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha6_4_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and6_4 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and7_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha6_4_and0 = ((f_u_csabam8_pg_rca_h3_v7_and6_4 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and7_3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and7_4 = ((a >> 7) & 0x01) & ((b >> 4) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and2_5 = ((a >> 2) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha2_5_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and2_5 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha3_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha2_5_and0 = ((f_u_csabam8_pg_rca_h3_v7_and2_5 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha3_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and3_5 = ((a >> 3) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_5_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and3_5 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha4_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_5_and0 = ((f_u_csabam8_pg_rca_h3_v7_and3_5 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha4_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_5_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa3_5_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha3_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_5_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa3_5_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha3_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_5_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa3_5_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa3_5_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and4_5 = ((a >> 4) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_5_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and4_5 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha5_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_5_and0 = ((f_u_csabam8_pg_rca_h3_v7_and4_5 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha5_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_5_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa4_5_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha4_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_5_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa4_5_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha4_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_5_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa4_5_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa4_5_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and5_5 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_5_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and5_5 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha6_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_5_and0 = ((f_u_csabam8_pg_rca_h3_v7_and5_5 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha6_4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_5_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa5_5_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha5_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_5_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa5_5_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha5_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_5_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa5_5_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa5_5_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and6_5 = ((a >> 6) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_5_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and6_5 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and7_4 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_5_and0 = ((f_u_csabam8_pg_rca_h3_v7_and6_5 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and7_4 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_5_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa6_5_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha6_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_5_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa6_5_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha6_4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_5_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa6_5_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa6_5_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and7_5 = ((a >> 7) & 0x01) & ((b >> 5) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and1_6 = ((a >> 1) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha1_6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and1_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha2_5_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha1_6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and1_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha2_5_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and2_6 = ((a >> 2) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and2_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa3_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and2_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa3_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_6_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa2_6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha2_5_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_6_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa2_6_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha2_5_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_6_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa2_6_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa2_6_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and3_6 = ((a >> 3) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and3_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa4_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and3_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa4_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_6_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa3_6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa3_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_6_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa3_6_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa3_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_6_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa3_6_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa3_6_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and4_6 = ((a >> 4) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and4_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa5_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and4_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa5_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_6_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa4_6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa4_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_6_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa4_6_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa4_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_6_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa4_6_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa4_6_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and5_6 = ((a >> 5) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and5_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa6_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and5_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa6_5_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_6_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa5_6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa5_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_6_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa5_6_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa5_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_6_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa5_6_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa5_6_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and6_6 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and6_6 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and7_5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and6_6 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and7_5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_6_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa6_6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa6_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_6_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa6_6_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa6_5_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_6_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa6_6_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa6_6_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and7_6 = ((a >> 7) & 0x01) & ((b >> 6) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and0_7 = ((a >> 0) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha0_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and0_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha1_6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_ha0_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and0_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha1_6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and1_7 = ((a >> 1) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa1_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and1_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa2_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa1_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and1_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa2_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa1_7_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa1_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_ha1_6_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa1_7_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa1_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_ha1_6_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa1_7_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa1_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa1_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and2_7 = ((a >> 2) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and2_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa3_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and2_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa3_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_7_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa2_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa2_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_7_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa2_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa2_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa2_7_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa2_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa2_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and3_7 = ((a >> 3) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and3_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa4_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and3_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa4_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_7_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa3_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa3_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_7_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa3_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa3_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa3_7_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa3_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa3_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and4_7 = ((a >> 4) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and4_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa5_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and4_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa5_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_7_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa4_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa4_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_7_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa4_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa4_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa4_7_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa4_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa4_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and5_7 = ((a >> 5) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and5_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa6_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and5_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa6_6_xor1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_7_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa5_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa5_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_7_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa5_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa5_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa5_7_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa5_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa5_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and6_7 = ((a >> 6) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_7_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and6_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_and7_6 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_7_and0 = ((f_u_csabam8_pg_rca_h3_v7_and6_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_and7_6 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_7_xor1 = ((f_u_csabam8_pg_rca_h3_v7_fa6_7_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa6_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_7_and1 = ((f_u_csabam8_pg_rca_h3_v7_fa6_7_xor0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa6_6_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_fa6_7_or0 = ((f_u_csabam8_pg_rca_h3_v7_fa6_7_and0 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_fa6_7_and1 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_and7_7 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_xor0 = ((f_u_csabam8_pg_rca_h3_v7_fa2_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa1_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_and0 = ((f_u_csabam8_pg_rca_h3_v7_fa2_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa1_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor0 = ((f_u_csabam8_pg_rca_h3_v7_fa3_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa2_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_and0 = ((f_u_csabam8_pg_rca_h3_v7_fa3_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa2_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor1 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and2 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_and0 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or2 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and2 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor0 = ((f_u_csabam8_pg_rca_h3_v7_fa4_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa3_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_and0 = ((f_u_csabam8_pg_rca_h3_v7_fa4_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa3_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor1 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or2 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and3 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or2 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or3 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and3 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor0 = ((f_u_csabam8_pg_rca_h3_v7_fa5_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa4_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_and0 = ((f_u_csabam8_pg_rca_h3_v7_fa5_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa4_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor1 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or3 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and4 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or3 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or4 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and4 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor0 = ((f_u_csabam8_pg_rca_h3_v7_fa6_7_xor1 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa5_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_and0 = ((f_u_csabam8_pg_rca_h3_v7_fa6_7_xor1 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa5_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor1 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or4 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and5 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or4 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or5 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and5 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_and0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor0 = ((f_u_csabam8_pg_rca_h3_v7_and7_7 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_fa6_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_and0 = ((f_u_csabam8_pg_rca_h3_v7_and7_7 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_fa6_7_or0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor1 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01) ^ ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or5 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and6 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or5 >> 0) & 0x01) & ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor0 >> 0) & 0x01);
  f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or6 = ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_and6 >> 0) & 0x01) | ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_and0 >> 0) & 0x01);

  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 0;
  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 1;
  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 2;
  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 3;
  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 4;
  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 5;
  f_u_csabam8_pg_rca_h3_v7_out |= (0x00) << 6;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_ha0_7_xor0 >> 0) & 0x01ull) << 7;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_fa1_7_xor1 >> 0) & 0x01ull) << 8;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa1_xor0 >> 0) & 0x01ull) << 9;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa2_xor1 >> 0) & 0x01ull) << 10;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa3_xor1 >> 0) & 0x01ull) << 11;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa4_xor1 >> 0) & 0x01ull) << 12;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa5_xor1 >> 0) & 0x01ull) << 13;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_pg_fa6_xor1 >> 0) & 0x01ull) << 14;
  f_u_csabam8_pg_rca_h3_v7_out |= ((f_u_csabam8_pg_rca_h3_v7_u_pg_rca8_or6 >> 0) & 0x01ull) << 15;
  return f_u_csabam8_pg_rca_h3_v7_out;
}