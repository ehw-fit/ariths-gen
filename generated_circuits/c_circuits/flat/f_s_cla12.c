#include <stdio.h>
#include <stdint.h>

int64_t f_s_cla12(int64_t a, int64_t b){
  uint64_t f_s_cla12_out = 0;
  uint8_t f_s_cla12_pg_logic0_or0 = 0;
  uint8_t f_s_cla12_pg_logic0_and0 = 0;
  uint8_t f_s_cla12_pg_logic0_xor0 = 0;
  uint8_t f_s_cla12_pg_logic1_or0 = 0;
  uint8_t f_s_cla12_pg_logic1_and0 = 0;
  uint8_t f_s_cla12_pg_logic1_xor0 = 0;
  uint8_t f_s_cla12_xor1 = 0;
  uint8_t f_s_cla12_and0 = 0;
  uint8_t f_s_cla12_or0 = 0;
  uint8_t f_s_cla12_pg_logic2_or0 = 0;
  uint8_t f_s_cla12_pg_logic2_and0 = 0;
  uint8_t f_s_cla12_pg_logic2_xor0 = 0;
  uint8_t f_s_cla12_xor2 = 0;
  uint8_t f_s_cla12_and1 = 0;
  uint8_t f_s_cla12_and2 = 0;
  uint8_t f_s_cla12_and3 = 0;
  uint8_t f_s_cla12_and4 = 0;
  uint8_t f_s_cla12_or1 = 0;
  uint8_t f_s_cla12_or2 = 0;
  uint8_t f_s_cla12_pg_logic3_or0 = 0;
  uint8_t f_s_cla12_pg_logic3_and0 = 0;
  uint8_t f_s_cla12_pg_logic3_xor0 = 0;
  uint8_t f_s_cla12_xor3 = 0;
  uint8_t f_s_cla12_and5 = 0;
  uint8_t f_s_cla12_and6 = 0;
  uint8_t f_s_cla12_and7 = 0;
  uint8_t f_s_cla12_and8 = 0;
  uint8_t f_s_cla12_and9 = 0;
  uint8_t f_s_cla12_and10 = 0;
  uint8_t f_s_cla12_and11 = 0;
  uint8_t f_s_cla12_or3 = 0;
  uint8_t f_s_cla12_or4 = 0;
  uint8_t f_s_cla12_or5 = 0;
  uint8_t f_s_cla12_pg_logic4_or0 = 0;
  uint8_t f_s_cla12_pg_logic4_and0 = 0;
  uint8_t f_s_cla12_pg_logic4_xor0 = 0;
  uint8_t f_s_cla12_xor4 = 0;
  uint8_t f_s_cla12_and12 = 0;
  uint8_t f_s_cla12_or6 = 0;
  uint8_t f_s_cla12_pg_logic5_or0 = 0;
  uint8_t f_s_cla12_pg_logic5_and0 = 0;
  uint8_t f_s_cla12_pg_logic5_xor0 = 0;
  uint8_t f_s_cla12_xor5 = 0;
  uint8_t f_s_cla12_and13 = 0;
  uint8_t f_s_cla12_and14 = 0;
  uint8_t f_s_cla12_and15 = 0;
  uint8_t f_s_cla12_or7 = 0;
  uint8_t f_s_cla12_or8 = 0;
  uint8_t f_s_cla12_pg_logic6_or0 = 0;
  uint8_t f_s_cla12_pg_logic6_and0 = 0;
  uint8_t f_s_cla12_pg_logic6_xor0 = 0;
  uint8_t f_s_cla12_xor6 = 0;
  uint8_t f_s_cla12_and16 = 0;
  uint8_t f_s_cla12_and17 = 0;
  uint8_t f_s_cla12_and18 = 0;
  uint8_t f_s_cla12_and19 = 0;
  uint8_t f_s_cla12_and20 = 0;
  uint8_t f_s_cla12_and21 = 0;
  uint8_t f_s_cla12_or9 = 0;
  uint8_t f_s_cla12_or10 = 0;
  uint8_t f_s_cla12_or11 = 0;
  uint8_t f_s_cla12_pg_logic7_or0 = 0;
  uint8_t f_s_cla12_pg_logic7_and0 = 0;
  uint8_t f_s_cla12_pg_logic7_xor0 = 0;
  uint8_t f_s_cla12_xor7 = 0;
  uint8_t f_s_cla12_and22 = 0;
  uint8_t f_s_cla12_and23 = 0;
  uint8_t f_s_cla12_and24 = 0;
  uint8_t f_s_cla12_and25 = 0;
  uint8_t f_s_cla12_and26 = 0;
  uint8_t f_s_cla12_and27 = 0;
  uint8_t f_s_cla12_and28 = 0;
  uint8_t f_s_cla12_and29 = 0;
  uint8_t f_s_cla12_and30 = 0;
  uint8_t f_s_cla12_and31 = 0;
  uint8_t f_s_cla12_or12 = 0;
  uint8_t f_s_cla12_or13 = 0;
  uint8_t f_s_cla12_or14 = 0;
  uint8_t f_s_cla12_or15 = 0;
  uint8_t f_s_cla12_pg_logic8_or0 = 0;
  uint8_t f_s_cla12_pg_logic8_and0 = 0;
  uint8_t f_s_cla12_pg_logic8_xor0 = 0;
  uint8_t f_s_cla12_xor8 = 0;
  uint8_t f_s_cla12_and32 = 0;
  uint8_t f_s_cla12_or16 = 0;
  uint8_t f_s_cla12_pg_logic9_or0 = 0;
  uint8_t f_s_cla12_pg_logic9_and0 = 0;
  uint8_t f_s_cla12_pg_logic9_xor0 = 0;
  uint8_t f_s_cla12_xor9 = 0;
  uint8_t f_s_cla12_and33 = 0;
  uint8_t f_s_cla12_and34 = 0;
  uint8_t f_s_cla12_and35 = 0;
  uint8_t f_s_cla12_or17 = 0;
  uint8_t f_s_cla12_or18 = 0;
  uint8_t f_s_cla12_pg_logic10_or0 = 0;
  uint8_t f_s_cla12_pg_logic10_and0 = 0;
  uint8_t f_s_cla12_pg_logic10_xor0 = 0;
  uint8_t f_s_cla12_xor10 = 0;
  uint8_t f_s_cla12_and36 = 0;
  uint8_t f_s_cla12_and37 = 0;
  uint8_t f_s_cla12_and38 = 0;
  uint8_t f_s_cla12_and39 = 0;
  uint8_t f_s_cla12_and40 = 0;
  uint8_t f_s_cla12_and41 = 0;
  uint8_t f_s_cla12_or19 = 0;
  uint8_t f_s_cla12_or20 = 0;
  uint8_t f_s_cla12_or21 = 0;
  uint8_t f_s_cla12_pg_logic11_or0 = 0;
  uint8_t f_s_cla12_pg_logic11_and0 = 0;
  uint8_t f_s_cla12_pg_logic11_xor0 = 0;
  uint8_t f_s_cla12_xor11 = 0;
  uint8_t f_s_cla12_and42 = 0;
  uint8_t f_s_cla12_and43 = 0;
  uint8_t f_s_cla12_and44 = 0;
  uint8_t f_s_cla12_and45 = 0;
  uint8_t f_s_cla12_and46 = 0;
  uint8_t f_s_cla12_and47 = 0;
  uint8_t f_s_cla12_and48 = 0;
  uint8_t f_s_cla12_and49 = 0;
  uint8_t f_s_cla12_and50 = 0;
  uint8_t f_s_cla12_and51 = 0;
  uint8_t f_s_cla12_or22 = 0;
  uint8_t f_s_cla12_or23 = 0;
  uint8_t f_s_cla12_or24 = 0;
  uint8_t f_s_cla12_or25 = 0;
  uint8_t f_s_cla12_xor12 = 0;
  uint8_t f_s_cla12_xor13 = 0;

  f_s_cla12_pg_logic0_or0 = ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
  f_s_cla12_pg_logic0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_s_cla12_pg_logic0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_s_cla12_pg_logic1_or0 = ((a >> 1) & 0x01) | ((b >> 1) & 0x01);
  f_s_cla12_pg_logic1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_s_cla12_pg_logic1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_s_cla12_xor1 = ((f_s_cla12_pg_logic1_xor0 >> 0) & 0x01) ^ ((f_s_cla12_pg_logic0_and0 >> 0) & 0x01);
  f_s_cla12_and0 = ((f_s_cla12_pg_logic0_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic1_or0 >> 0) & 0x01);
  f_s_cla12_or0 = ((f_s_cla12_pg_logic1_and0 >> 0) & 0x01) | ((f_s_cla12_and0 >> 0) & 0x01);
  f_s_cla12_pg_logic2_or0 = ((a >> 2) & 0x01) | ((b >> 2) & 0x01);
  f_s_cla12_pg_logic2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_s_cla12_pg_logic2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_s_cla12_xor2 = ((f_s_cla12_pg_logic2_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or0 >> 0) & 0x01);
  f_s_cla12_and1 = ((f_s_cla12_pg_logic2_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic0_or0 >> 0) & 0x01);
  f_s_cla12_and2 = ((f_s_cla12_pg_logic0_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic2_or0 >> 0) & 0x01);
  f_s_cla12_and3 = ((f_s_cla12_and2 >> 0) & 0x01) & ((f_s_cla12_pg_logic1_or0 >> 0) & 0x01);
  f_s_cla12_and4 = ((f_s_cla12_pg_logic1_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic2_or0 >> 0) & 0x01);
  f_s_cla12_or1 = ((f_s_cla12_and3 >> 0) & 0x01) | ((f_s_cla12_and4 >> 0) & 0x01);
  f_s_cla12_or2 = ((f_s_cla12_pg_logic2_and0 >> 0) & 0x01) | ((f_s_cla12_or1 >> 0) & 0x01);
  f_s_cla12_pg_logic3_or0 = ((a >> 3) & 0x01) | ((b >> 3) & 0x01);
  f_s_cla12_pg_logic3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_s_cla12_pg_logic3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_s_cla12_xor3 = ((f_s_cla12_pg_logic3_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or2 >> 0) & 0x01);
  f_s_cla12_and5 = ((f_s_cla12_pg_logic3_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic1_or0 >> 0) & 0x01);
  f_s_cla12_and6 = ((f_s_cla12_pg_logic0_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic2_or0 >> 0) & 0x01);
  f_s_cla12_and7 = ((f_s_cla12_pg_logic3_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic1_or0 >> 0) & 0x01);
  f_s_cla12_and8 = ((f_s_cla12_and6 >> 0) & 0x01) & ((f_s_cla12_and7 >> 0) & 0x01);
  f_s_cla12_and9 = ((f_s_cla12_pg_logic1_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic3_or0 >> 0) & 0x01);
  f_s_cla12_and10 = ((f_s_cla12_and9 >> 0) & 0x01) & ((f_s_cla12_pg_logic2_or0 >> 0) & 0x01);
  f_s_cla12_and11 = ((f_s_cla12_pg_logic2_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic3_or0 >> 0) & 0x01);
  f_s_cla12_or3 = ((f_s_cla12_and8 >> 0) & 0x01) | ((f_s_cla12_and11 >> 0) & 0x01);
  f_s_cla12_or4 = ((f_s_cla12_and10 >> 0) & 0x01) | ((f_s_cla12_or3 >> 0) & 0x01);
  f_s_cla12_or5 = ((f_s_cla12_pg_logic3_and0 >> 0) & 0x01) | ((f_s_cla12_or4 >> 0) & 0x01);
  f_s_cla12_pg_logic4_or0 = ((a >> 4) & 0x01) | ((b >> 4) & 0x01);
  f_s_cla12_pg_logic4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  f_s_cla12_pg_logic4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  f_s_cla12_xor4 = ((f_s_cla12_pg_logic4_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or5 >> 0) & 0x01);
  f_s_cla12_and12 = ((f_s_cla12_or5 >> 0) & 0x01) & ((f_s_cla12_pg_logic4_or0 >> 0) & 0x01);
  f_s_cla12_or6 = ((f_s_cla12_pg_logic4_and0 >> 0) & 0x01) | ((f_s_cla12_and12 >> 0) & 0x01);
  f_s_cla12_pg_logic5_or0 = ((a >> 5) & 0x01) | ((b >> 5) & 0x01);
  f_s_cla12_pg_logic5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_s_cla12_pg_logic5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  f_s_cla12_xor5 = ((f_s_cla12_pg_logic5_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or6 >> 0) & 0x01);
  f_s_cla12_and13 = ((f_s_cla12_or5 >> 0) & 0x01) & ((f_s_cla12_pg_logic5_or0 >> 0) & 0x01);
  f_s_cla12_and14 = ((f_s_cla12_and13 >> 0) & 0x01) & ((f_s_cla12_pg_logic4_or0 >> 0) & 0x01);
  f_s_cla12_and15 = ((f_s_cla12_pg_logic4_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic5_or0 >> 0) & 0x01);
  f_s_cla12_or7 = ((f_s_cla12_and14 >> 0) & 0x01) | ((f_s_cla12_and15 >> 0) & 0x01);
  f_s_cla12_or8 = ((f_s_cla12_pg_logic5_and0 >> 0) & 0x01) | ((f_s_cla12_or7 >> 0) & 0x01);
  f_s_cla12_pg_logic6_or0 = ((a >> 6) & 0x01) | ((b >> 6) & 0x01);
  f_s_cla12_pg_logic6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_s_cla12_pg_logic6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  f_s_cla12_xor6 = ((f_s_cla12_pg_logic6_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or8 >> 0) & 0x01);
  f_s_cla12_and16 = ((f_s_cla12_or5 >> 0) & 0x01) & ((f_s_cla12_pg_logic5_or0 >> 0) & 0x01);
  f_s_cla12_and17 = ((f_s_cla12_pg_logic6_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic4_or0 >> 0) & 0x01);
  f_s_cla12_and18 = ((f_s_cla12_and16 >> 0) & 0x01) & ((f_s_cla12_and17 >> 0) & 0x01);
  f_s_cla12_and19 = ((f_s_cla12_pg_logic4_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic6_or0 >> 0) & 0x01);
  f_s_cla12_and20 = ((f_s_cla12_and19 >> 0) & 0x01) & ((f_s_cla12_pg_logic5_or0 >> 0) & 0x01);
  f_s_cla12_and21 = ((f_s_cla12_pg_logic5_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic6_or0 >> 0) & 0x01);
  f_s_cla12_or9 = ((f_s_cla12_and18 >> 0) & 0x01) | ((f_s_cla12_and20 >> 0) & 0x01);
  f_s_cla12_or10 = ((f_s_cla12_or9 >> 0) & 0x01) | ((f_s_cla12_and21 >> 0) & 0x01);
  f_s_cla12_or11 = ((f_s_cla12_pg_logic6_and0 >> 0) & 0x01) | ((f_s_cla12_or10 >> 0) & 0x01);
  f_s_cla12_pg_logic7_or0 = ((a >> 7) & 0x01) | ((b >> 7) & 0x01);
  f_s_cla12_pg_logic7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_s_cla12_pg_logic7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_s_cla12_xor7 = ((f_s_cla12_pg_logic7_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or11 >> 0) & 0x01);
  f_s_cla12_and22 = ((f_s_cla12_or5 >> 0) & 0x01) & ((f_s_cla12_pg_logic6_or0 >> 0) & 0x01);
  f_s_cla12_and23 = ((f_s_cla12_pg_logic7_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic5_or0 >> 0) & 0x01);
  f_s_cla12_and24 = ((f_s_cla12_and22 >> 0) & 0x01) & ((f_s_cla12_and23 >> 0) & 0x01);
  f_s_cla12_and25 = ((f_s_cla12_and24 >> 0) & 0x01) & ((f_s_cla12_pg_logic4_or0 >> 0) & 0x01);
  f_s_cla12_and26 = ((f_s_cla12_pg_logic4_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic6_or0 >> 0) & 0x01);
  f_s_cla12_and27 = ((f_s_cla12_pg_logic7_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic5_or0 >> 0) & 0x01);
  f_s_cla12_and28 = ((f_s_cla12_and26 >> 0) & 0x01) & ((f_s_cla12_and27 >> 0) & 0x01);
  f_s_cla12_and29 = ((f_s_cla12_pg_logic5_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic7_or0 >> 0) & 0x01);
  f_s_cla12_and30 = ((f_s_cla12_and29 >> 0) & 0x01) & ((f_s_cla12_pg_logic6_or0 >> 0) & 0x01);
  f_s_cla12_and31 = ((f_s_cla12_pg_logic6_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic7_or0 >> 0) & 0x01);
  f_s_cla12_or12 = ((f_s_cla12_and25 >> 0) & 0x01) | ((f_s_cla12_and30 >> 0) & 0x01);
  f_s_cla12_or13 = ((f_s_cla12_and28 >> 0) & 0x01) | ((f_s_cla12_and31 >> 0) & 0x01);
  f_s_cla12_or14 = ((f_s_cla12_or12 >> 0) & 0x01) | ((f_s_cla12_or13 >> 0) & 0x01);
  f_s_cla12_or15 = ((f_s_cla12_pg_logic7_and0 >> 0) & 0x01) | ((f_s_cla12_or14 >> 0) & 0x01);
  f_s_cla12_pg_logic8_or0 = ((a >> 8) & 0x01) | ((b >> 8) & 0x01);
  f_s_cla12_pg_logic8_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  f_s_cla12_pg_logic8_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  f_s_cla12_xor8 = ((f_s_cla12_pg_logic8_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or15 >> 0) & 0x01);
  f_s_cla12_and32 = ((f_s_cla12_or15 >> 0) & 0x01) & ((f_s_cla12_pg_logic8_or0 >> 0) & 0x01);
  f_s_cla12_or16 = ((f_s_cla12_pg_logic8_and0 >> 0) & 0x01) | ((f_s_cla12_and32 >> 0) & 0x01);
  f_s_cla12_pg_logic9_or0 = ((a >> 9) & 0x01) | ((b >> 9) & 0x01);
  f_s_cla12_pg_logic9_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  f_s_cla12_pg_logic9_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  f_s_cla12_xor9 = ((f_s_cla12_pg_logic9_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or16 >> 0) & 0x01);
  f_s_cla12_and33 = ((f_s_cla12_or15 >> 0) & 0x01) & ((f_s_cla12_pg_logic9_or0 >> 0) & 0x01);
  f_s_cla12_and34 = ((f_s_cla12_and33 >> 0) & 0x01) & ((f_s_cla12_pg_logic8_or0 >> 0) & 0x01);
  f_s_cla12_and35 = ((f_s_cla12_pg_logic8_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic9_or0 >> 0) & 0x01);
  f_s_cla12_or17 = ((f_s_cla12_and34 >> 0) & 0x01) | ((f_s_cla12_and35 >> 0) & 0x01);
  f_s_cla12_or18 = ((f_s_cla12_pg_logic9_and0 >> 0) & 0x01) | ((f_s_cla12_or17 >> 0) & 0x01);
  f_s_cla12_pg_logic10_or0 = ((a >> 10) & 0x01) | ((b >> 10) & 0x01);
  f_s_cla12_pg_logic10_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  f_s_cla12_pg_logic10_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  f_s_cla12_xor10 = ((f_s_cla12_pg_logic10_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or18 >> 0) & 0x01);
  f_s_cla12_and36 = ((f_s_cla12_or15 >> 0) & 0x01) & ((f_s_cla12_pg_logic9_or0 >> 0) & 0x01);
  f_s_cla12_and37 = ((f_s_cla12_pg_logic10_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic8_or0 >> 0) & 0x01);
  f_s_cla12_and38 = ((f_s_cla12_and36 >> 0) & 0x01) & ((f_s_cla12_and37 >> 0) & 0x01);
  f_s_cla12_and39 = ((f_s_cla12_pg_logic8_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic10_or0 >> 0) & 0x01);
  f_s_cla12_and40 = ((f_s_cla12_and39 >> 0) & 0x01) & ((f_s_cla12_pg_logic9_or0 >> 0) & 0x01);
  f_s_cla12_and41 = ((f_s_cla12_pg_logic9_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic10_or0 >> 0) & 0x01);
  f_s_cla12_or19 = ((f_s_cla12_and38 >> 0) & 0x01) | ((f_s_cla12_and40 >> 0) & 0x01);
  f_s_cla12_or20 = ((f_s_cla12_or19 >> 0) & 0x01) | ((f_s_cla12_and41 >> 0) & 0x01);
  f_s_cla12_or21 = ((f_s_cla12_pg_logic10_and0 >> 0) & 0x01) | ((f_s_cla12_or20 >> 0) & 0x01);
  f_s_cla12_pg_logic11_or0 = ((a >> 11) & 0x01) | ((b >> 11) & 0x01);
  f_s_cla12_pg_logic11_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  f_s_cla12_pg_logic11_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  f_s_cla12_xor11 = ((f_s_cla12_pg_logic11_xor0 >> 0) & 0x01) ^ ((f_s_cla12_or21 >> 0) & 0x01);
  f_s_cla12_and42 = ((f_s_cla12_or15 >> 0) & 0x01) & ((f_s_cla12_pg_logic10_or0 >> 0) & 0x01);
  f_s_cla12_and43 = ((f_s_cla12_pg_logic11_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic9_or0 >> 0) & 0x01);
  f_s_cla12_and44 = ((f_s_cla12_and42 >> 0) & 0x01) & ((f_s_cla12_and43 >> 0) & 0x01);
  f_s_cla12_and45 = ((f_s_cla12_and44 >> 0) & 0x01) & ((f_s_cla12_pg_logic8_or0 >> 0) & 0x01);
  f_s_cla12_and46 = ((f_s_cla12_pg_logic8_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic10_or0 >> 0) & 0x01);
  f_s_cla12_and47 = ((f_s_cla12_pg_logic11_or0 >> 0) & 0x01) & ((f_s_cla12_pg_logic9_or0 >> 0) & 0x01);
  f_s_cla12_and48 = ((f_s_cla12_and46 >> 0) & 0x01) & ((f_s_cla12_and47 >> 0) & 0x01);
  f_s_cla12_and49 = ((f_s_cla12_pg_logic9_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic11_or0 >> 0) & 0x01);
  f_s_cla12_and50 = ((f_s_cla12_and49 >> 0) & 0x01) & ((f_s_cla12_pg_logic10_or0 >> 0) & 0x01);
  f_s_cla12_and51 = ((f_s_cla12_pg_logic10_and0 >> 0) & 0x01) & ((f_s_cla12_pg_logic11_or0 >> 0) & 0x01);
  f_s_cla12_or22 = ((f_s_cla12_and45 >> 0) & 0x01) | ((f_s_cla12_and50 >> 0) & 0x01);
  f_s_cla12_or23 = ((f_s_cla12_and48 >> 0) & 0x01) | ((f_s_cla12_and51 >> 0) & 0x01);
  f_s_cla12_or24 = ((f_s_cla12_or22 >> 0) & 0x01) | ((f_s_cla12_or23 >> 0) & 0x01);
  f_s_cla12_or25 = ((f_s_cla12_pg_logic11_and0 >> 0) & 0x01) | ((f_s_cla12_or24 >> 0) & 0x01);
  f_s_cla12_xor12 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  f_s_cla12_xor13 = ((f_s_cla12_xor12 >> 0) & 0x01) ^ ((f_s_cla12_or25 >> 0) & 0x01);

  f_s_cla12_out |= ((f_s_cla12_pg_logic0_xor0 >> 0) & 0x01) << 0;
  f_s_cla12_out |= ((f_s_cla12_xor1 >> 0) & 0x01) << 1;
  f_s_cla12_out |= ((f_s_cla12_xor2 >> 0) & 0x01) << 2;
  f_s_cla12_out |= ((f_s_cla12_xor3 >> 0) & 0x01) << 3;
  f_s_cla12_out |= ((f_s_cla12_xor4 >> 0) & 0x01) << 4;
  f_s_cla12_out |= ((f_s_cla12_xor5 >> 0) & 0x01) << 5;
  f_s_cla12_out |= ((f_s_cla12_xor6 >> 0) & 0x01) << 6;
  f_s_cla12_out |= ((f_s_cla12_xor7 >> 0) & 0x01) << 7;
  f_s_cla12_out |= ((f_s_cla12_xor8 >> 0) & 0x01) << 8;
  f_s_cla12_out |= ((f_s_cla12_xor9 >> 0) & 0x01) << 9;
  f_s_cla12_out |= ((f_s_cla12_xor10 >> 0) & 0x01) << 10;
  f_s_cla12_out |= ((f_s_cla12_xor11 >> 0) & 0x01) << 11;
  f_s_cla12_out |= ((f_s_cla12_xor13 >> 0) & 0x01) << 12;
  return f_s_cla12_out;
}