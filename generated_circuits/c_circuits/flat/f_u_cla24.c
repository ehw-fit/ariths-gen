#include <stdio.h>
#include <stdint.h>

uint64_t f_u_cla24(uint64_t a, uint64_t b){
  uint64_t f_u_cla24_out = 0;
  uint8_t f_u_cla24_pg_logic0_or0 = 0;
  uint8_t f_u_cla24_pg_logic0_and0 = 0;
  uint8_t f_u_cla24_pg_logic0_xor0 = 0;
  uint8_t f_u_cla24_pg_logic1_or0 = 0;
  uint8_t f_u_cla24_pg_logic1_and0 = 0;
  uint8_t f_u_cla24_pg_logic1_xor0 = 0;
  uint8_t f_u_cla24_xor1 = 0;
  uint8_t f_u_cla24_and0 = 0;
  uint8_t f_u_cla24_or0 = 0;
  uint8_t f_u_cla24_pg_logic2_or0 = 0;
  uint8_t f_u_cla24_pg_logic2_and0 = 0;
  uint8_t f_u_cla24_pg_logic2_xor0 = 0;
  uint8_t f_u_cla24_xor2 = 0;
  uint8_t f_u_cla24_and1 = 0;
  uint8_t f_u_cla24_and2 = 0;
  uint8_t f_u_cla24_and3 = 0;
  uint8_t f_u_cla24_and4 = 0;
  uint8_t f_u_cla24_or1 = 0;
  uint8_t f_u_cla24_or2 = 0;
  uint8_t f_u_cla24_pg_logic3_or0 = 0;
  uint8_t f_u_cla24_pg_logic3_and0 = 0;
  uint8_t f_u_cla24_pg_logic3_xor0 = 0;
  uint8_t f_u_cla24_xor3 = 0;
  uint8_t f_u_cla24_and5 = 0;
  uint8_t f_u_cla24_and6 = 0;
  uint8_t f_u_cla24_and7 = 0;
  uint8_t f_u_cla24_and8 = 0;
  uint8_t f_u_cla24_and9 = 0;
  uint8_t f_u_cla24_and10 = 0;
  uint8_t f_u_cla24_and11 = 0;
  uint8_t f_u_cla24_or3 = 0;
  uint8_t f_u_cla24_or4 = 0;
  uint8_t f_u_cla24_or5 = 0;
  uint8_t f_u_cla24_pg_logic4_or0 = 0;
  uint8_t f_u_cla24_pg_logic4_and0 = 0;
  uint8_t f_u_cla24_pg_logic4_xor0 = 0;
  uint8_t f_u_cla24_xor4 = 0;
  uint8_t f_u_cla24_and12 = 0;
  uint8_t f_u_cla24_or6 = 0;
  uint8_t f_u_cla24_pg_logic5_or0 = 0;
  uint8_t f_u_cla24_pg_logic5_and0 = 0;
  uint8_t f_u_cla24_pg_logic5_xor0 = 0;
  uint8_t f_u_cla24_xor5 = 0;
  uint8_t f_u_cla24_and13 = 0;
  uint8_t f_u_cla24_and14 = 0;
  uint8_t f_u_cla24_and15 = 0;
  uint8_t f_u_cla24_or7 = 0;
  uint8_t f_u_cla24_or8 = 0;
  uint8_t f_u_cla24_pg_logic6_or0 = 0;
  uint8_t f_u_cla24_pg_logic6_and0 = 0;
  uint8_t f_u_cla24_pg_logic6_xor0 = 0;
  uint8_t f_u_cla24_xor6 = 0;
  uint8_t f_u_cla24_and16 = 0;
  uint8_t f_u_cla24_and17 = 0;
  uint8_t f_u_cla24_and18 = 0;
  uint8_t f_u_cla24_and19 = 0;
  uint8_t f_u_cla24_and20 = 0;
  uint8_t f_u_cla24_and21 = 0;
  uint8_t f_u_cla24_or9 = 0;
  uint8_t f_u_cla24_or10 = 0;
  uint8_t f_u_cla24_or11 = 0;
  uint8_t f_u_cla24_pg_logic7_or0 = 0;
  uint8_t f_u_cla24_pg_logic7_and0 = 0;
  uint8_t f_u_cla24_pg_logic7_xor0 = 0;
  uint8_t f_u_cla24_xor7 = 0;
  uint8_t f_u_cla24_and22 = 0;
  uint8_t f_u_cla24_and23 = 0;
  uint8_t f_u_cla24_and24 = 0;
  uint8_t f_u_cla24_and25 = 0;
  uint8_t f_u_cla24_and26 = 0;
  uint8_t f_u_cla24_and27 = 0;
  uint8_t f_u_cla24_and28 = 0;
  uint8_t f_u_cla24_and29 = 0;
  uint8_t f_u_cla24_and30 = 0;
  uint8_t f_u_cla24_and31 = 0;
  uint8_t f_u_cla24_or12 = 0;
  uint8_t f_u_cla24_or13 = 0;
  uint8_t f_u_cla24_or14 = 0;
  uint8_t f_u_cla24_or15 = 0;
  uint8_t f_u_cla24_pg_logic8_or0 = 0;
  uint8_t f_u_cla24_pg_logic8_and0 = 0;
  uint8_t f_u_cla24_pg_logic8_xor0 = 0;
  uint8_t f_u_cla24_xor8 = 0;
  uint8_t f_u_cla24_and32 = 0;
  uint8_t f_u_cla24_or16 = 0;
  uint8_t f_u_cla24_pg_logic9_or0 = 0;
  uint8_t f_u_cla24_pg_logic9_and0 = 0;
  uint8_t f_u_cla24_pg_logic9_xor0 = 0;
  uint8_t f_u_cla24_xor9 = 0;
  uint8_t f_u_cla24_and33 = 0;
  uint8_t f_u_cla24_and34 = 0;
  uint8_t f_u_cla24_and35 = 0;
  uint8_t f_u_cla24_or17 = 0;
  uint8_t f_u_cla24_or18 = 0;
  uint8_t f_u_cla24_pg_logic10_or0 = 0;
  uint8_t f_u_cla24_pg_logic10_and0 = 0;
  uint8_t f_u_cla24_pg_logic10_xor0 = 0;
  uint8_t f_u_cla24_xor10 = 0;
  uint8_t f_u_cla24_and36 = 0;
  uint8_t f_u_cla24_and37 = 0;
  uint8_t f_u_cla24_and38 = 0;
  uint8_t f_u_cla24_and39 = 0;
  uint8_t f_u_cla24_and40 = 0;
  uint8_t f_u_cla24_and41 = 0;
  uint8_t f_u_cla24_or19 = 0;
  uint8_t f_u_cla24_or20 = 0;
  uint8_t f_u_cla24_or21 = 0;
  uint8_t f_u_cla24_pg_logic11_or0 = 0;
  uint8_t f_u_cla24_pg_logic11_and0 = 0;
  uint8_t f_u_cla24_pg_logic11_xor0 = 0;
  uint8_t f_u_cla24_xor11 = 0;
  uint8_t f_u_cla24_and42 = 0;
  uint8_t f_u_cla24_and43 = 0;
  uint8_t f_u_cla24_and44 = 0;
  uint8_t f_u_cla24_and45 = 0;
  uint8_t f_u_cla24_and46 = 0;
  uint8_t f_u_cla24_and47 = 0;
  uint8_t f_u_cla24_and48 = 0;
  uint8_t f_u_cla24_and49 = 0;
  uint8_t f_u_cla24_and50 = 0;
  uint8_t f_u_cla24_and51 = 0;
  uint8_t f_u_cla24_or22 = 0;
  uint8_t f_u_cla24_or23 = 0;
  uint8_t f_u_cla24_or24 = 0;
  uint8_t f_u_cla24_or25 = 0;
  uint8_t f_u_cla24_pg_logic12_or0 = 0;
  uint8_t f_u_cla24_pg_logic12_and0 = 0;
  uint8_t f_u_cla24_pg_logic12_xor0 = 0;
  uint8_t f_u_cla24_xor12 = 0;
  uint8_t f_u_cla24_and52 = 0;
  uint8_t f_u_cla24_or26 = 0;
  uint8_t f_u_cla24_pg_logic13_or0 = 0;
  uint8_t f_u_cla24_pg_logic13_and0 = 0;
  uint8_t f_u_cla24_pg_logic13_xor0 = 0;
  uint8_t f_u_cla24_xor13 = 0;
  uint8_t f_u_cla24_and53 = 0;
  uint8_t f_u_cla24_and54 = 0;
  uint8_t f_u_cla24_and55 = 0;
  uint8_t f_u_cla24_or27 = 0;
  uint8_t f_u_cla24_or28 = 0;
  uint8_t f_u_cla24_pg_logic14_or0 = 0;
  uint8_t f_u_cla24_pg_logic14_and0 = 0;
  uint8_t f_u_cla24_pg_logic14_xor0 = 0;
  uint8_t f_u_cla24_xor14 = 0;
  uint8_t f_u_cla24_and56 = 0;
  uint8_t f_u_cla24_and57 = 0;
  uint8_t f_u_cla24_and58 = 0;
  uint8_t f_u_cla24_and59 = 0;
  uint8_t f_u_cla24_and60 = 0;
  uint8_t f_u_cla24_and61 = 0;
  uint8_t f_u_cla24_or29 = 0;
  uint8_t f_u_cla24_or30 = 0;
  uint8_t f_u_cla24_or31 = 0;
  uint8_t f_u_cla24_pg_logic15_or0 = 0;
  uint8_t f_u_cla24_pg_logic15_and0 = 0;
  uint8_t f_u_cla24_pg_logic15_xor0 = 0;
  uint8_t f_u_cla24_xor15 = 0;
  uint8_t f_u_cla24_and62 = 0;
  uint8_t f_u_cla24_and63 = 0;
  uint8_t f_u_cla24_and64 = 0;
  uint8_t f_u_cla24_and65 = 0;
  uint8_t f_u_cla24_and66 = 0;
  uint8_t f_u_cla24_and67 = 0;
  uint8_t f_u_cla24_and68 = 0;
  uint8_t f_u_cla24_and69 = 0;
  uint8_t f_u_cla24_and70 = 0;
  uint8_t f_u_cla24_and71 = 0;
  uint8_t f_u_cla24_or32 = 0;
  uint8_t f_u_cla24_or33 = 0;
  uint8_t f_u_cla24_or34 = 0;
  uint8_t f_u_cla24_or35 = 0;
  uint8_t f_u_cla24_pg_logic16_or0 = 0;
  uint8_t f_u_cla24_pg_logic16_and0 = 0;
  uint8_t f_u_cla24_pg_logic16_xor0 = 0;
  uint8_t f_u_cla24_xor16 = 0;
  uint8_t f_u_cla24_and72 = 0;
  uint8_t f_u_cla24_or36 = 0;
  uint8_t f_u_cla24_pg_logic17_or0 = 0;
  uint8_t f_u_cla24_pg_logic17_and0 = 0;
  uint8_t f_u_cla24_pg_logic17_xor0 = 0;
  uint8_t f_u_cla24_xor17 = 0;
  uint8_t f_u_cla24_and73 = 0;
  uint8_t f_u_cla24_and74 = 0;
  uint8_t f_u_cla24_and75 = 0;
  uint8_t f_u_cla24_or37 = 0;
  uint8_t f_u_cla24_or38 = 0;
  uint8_t f_u_cla24_pg_logic18_or0 = 0;
  uint8_t f_u_cla24_pg_logic18_and0 = 0;
  uint8_t f_u_cla24_pg_logic18_xor0 = 0;
  uint8_t f_u_cla24_xor18 = 0;
  uint8_t f_u_cla24_and76 = 0;
  uint8_t f_u_cla24_and77 = 0;
  uint8_t f_u_cla24_and78 = 0;
  uint8_t f_u_cla24_and79 = 0;
  uint8_t f_u_cla24_and80 = 0;
  uint8_t f_u_cla24_and81 = 0;
  uint8_t f_u_cla24_or39 = 0;
  uint8_t f_u_cla24_or40 = 0;
  uint8_t f_u_cla24_or41 = 0;
  uint8_t f_u_cla24_pg_logic19_or0 = 0;
  uint8_t f_u_cla24_pg_logic19_and0 = 0;
  uint8_t f_u_cla24_pg_logic19_xor0 = 0;
  uint8_t f_u_cla24_xor19 = 0;
  uint8_t f_u_cla24_and82 = 0;
  uint8_t f_u_cla24_and83 = 0;
  uint8_t f_u_cla24_and84 = 0;
  uint8_t f_u_cla24_and85 = 0;
  uint8_t f_u_cla24_and86 = 0;
  uint8_t f_u_cla24_and87 = 0;
  uint8_t f_u_cla24_and88 = 0;
  uint8_t f_u_cla24_and89 = 0;
  uint8_t f_u_cla24_and90 = 0;
  uint8_t f_u_cla24_and91 = 0;
  uint8_t f_u_cla24_or42 = 0;
  uint8_t f_u_cla24_or43 = 0;
  uint8_t f_u_cla24_or44 = 0;
  uint8_t f_u_cla24_or45 = 0;
  uint8_t f_u_cla24_pg_logic20_or0 = 0;
  uint8_t f_u_cla24_pg_logic20_and0 = 0;
  uint8_t f_u_cla24_pg_logic20_xor0 = 0;
  uint8_t f_u_cla24_xor20 = 0;
  uint8_t f_u_cla24_and92 = 0;
  uint8_t f_u_cla24_or46 = 0;
  uint8_t f_u_cla24_pg_logic21_or0 = 0;
  uint8_t f_u_cla24_pg_logic21_and0 = 0;
  uint8_t f_u_cla24_pg_logic21_xor0 = 0;
  uint8_t f_u_cla24_xor21 = 0;
  uint8_t f_u_cla24_and93 = 0;
  uint8_t f_u_cla24_and94 = 0;
  uint8_t f_u_cla24_and95 = 0;
  uint8_t f_u_cla24_or47 = 0;
  uint8_t f_u_cla24_or48 = 0;
  uint8_t f_u_cla24_pg_logic22_or0 = 0;
  uint8_t f_u_cla24_pg_logic22_and0 = 0;
  uint8_t f_u_cla24_pg_logic22_xor0 = 0;
  uint8_t f_u_cla24_xor22 = 0;
  uint8_t f_u_cla24_and96 = 0;
  uint8_t f_u_cla24_and97 = 0;
  uint8_t f_u_cla24_and98 = 0;
  uint8_t f_u_cla24_and99 = 0;
  uint8_t f_u_cla24_and100 = 0;
  uint8_t f_u_cla24_and101 = 0;
  uint8_t f_u_cla24_or49 = 0;
  uint8_t f_u_cla24_or50 = 0;
  uint8_t f_u_cla24_or51 = 0;
  uint8_t f_u_cla24_pg_logic23_or0 = 0;
  uint8_t f_u_cla24_pg_logic23_and0 = 0;
  uint8_t f_u_cla24_pg_logic23_xor0 = 0;
  uint8_t f_u_cla24_xor23 = 0;
  uint8_t f_u_cla24_and102 = 0;
  uint8_t f_u_cla24_and103 = 0;
  uint8_t f_u_cla24_and104 = 0;
  uint8_t f_u_cla24_and105 = 0;
  uint8_t f_u_cla24_and106 = 0;
  uint8_t f_u_cla24_and107 = 0;
  uint8_t f_u_cla24_and108 = 0;
  uint8_t f_u_cla24_and109 = 0;
  uint8_t f_u_cla24_and110 = 0;
  uint8_t f_u_cla24_and111 = 0;
  uint8_t f_u_cla24_or52 = 0;
  uint8_t f_u_cla24_or53 = 0;
  uint8_t f_u_cla24_or54 = 0;
  uint8_t f_u_cla24_or55 = 0;

  f_u_cla24_pg_logic0_or0 = ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
  f_u_cla24_pg_logic0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  f_u_cla24_pg_logic0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  f_u_cla24_pg_logic1_or0 = ((a >> 1) & 0x01) | ((b >> 1) & 0x01);
  f_u_cla24_pg_logic1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  f_u_cla24_pg_logic1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  f_u_cla24_xor1 = ((f_u_cla24_pg_logic1_xor0 >> 0) & 0x01) ^ ((f_u_cla24_pg_logic0_and0 >> 0) & 0x01);
  f_u_cla24_and0 = ((f_u_cla24_pg_logic0_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic1_or0 >> 0) & 0x01);
  f_u_cla24_or0 = ((f_u_cla24_pg_logic1_and0 >> 0) & 0x01) | ((f_u_cla24_and0 >> 0) & 0x01);
  f_u_cla24_pg_logic2_or0 = ((a >> 2) & 0x01) | ((b >> 2) & 0x01);
  f_u_cla24_pg_logic2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  f_u_cla24_pg_logic2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  f_u_cla24_xor2 = ((f_u_cla24_pg_logic2_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or0 >> 0) & 0x01);
  f_u_cla24_and1 = ((f_u_cla24_pg_logic2_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic0_or0 >> 0) & 0x01);
  f_u_cla24_and2 = ((f_u_cla24_pg_logic0_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic2_or0 >> 0) & 0x01);
  f_u_cla24_and3 = ((f_u_cla24_and2 >> 0) & 0x01) & ((f_u_cla24_pg_logic1_or0 >> 0) & 0x01);
  f_u_cla24_and4 = ((f_u_cla24_pg_logic1_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic2_or0 >> 0) & 0x01);
  f_u_cla24_or1 = ((f_u_cla24_and3 >> 0) & 0x01) | ((f_u_cla24_and4 >> 0) & 0x01);
  f_u_cla24_or2 = ((f_u_cla24_pg_logic2_and0 >> 0) & 0x01) | ((f_u_cla24_or1 >> 0) & 0x01);
  f_u_cla24_pg_logic3_or0 = ((a >> 3) & 0x01) | ((b >> 3) & 0x01);
  f_u_cla24_pg_logic3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  f_u_cla24_pg_logic3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  f_u_cla24_xor3 = ((f_u_cla24_pg_logic3_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or2 >> 0) & 0x01);
  f_u_cla24_and5 = ((f_u_cla24_pg_logic3_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic1_or0 >> 0) & 0x01);
  f_u_cla24_and6 = ((f_u_cla24_pg_logic0_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic2_or0 >> 0) & 0x01);
  f_u_cla24_and7 = ((f_u_cla24_pg_logic3_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic1_or0 >> 0) & 0x01);
  f_u_cla24_and8 = ((f_u_cla24_and6 >> 0) & 0x01) & ((f_u_cla24_and7 >> 0) & 0x01);
  f_u_cla24_and9 = ((f_u_cla24_pg_logic1_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic3_or0 >> 0) & 0x01);
  f_u_cla24_and10 = ((f_u_cla24_and9 >> 0) & 0x01) & ((f_u_cla24_pg_logic2_or0 >> 0) & 0x01);
  f_u_cla24_and11 = ((f_u_cla24_pg_logic2_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic3_or0 >> 0) & 0x01);
  f_u_cla24_or3 = ((f_u_cla24_and8 >> 0) & 0x01) | ((f_u_cla24_and11 >> 0) & 0x01);
  f_u_cla24_or4 = ((f_u_cla24_and10 >> 0) & 0x01) | ((f_u_cla24_or3 >> 0) & 0x01);
  f_u_cla24_or5 = ((f_u_cla24_pg_logic3_and0 >> 0) & 0x01) | ((f_u_cla24_or4 >> 0) & 0x01);
  f_u_cla24_pg_logic4_or0 = ((a >> 4) & 0x01) | ((b >> 4) & 0x01);
  f_u_cla24_pg_logic4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  f_u_cla24_pg_logic4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  f_u_cla24_xor4 = ((f_u_cla24_pg_logic4_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or5 >> 0) & 0x01);
  f_u_cla24_and12 = ((f_u_cla24_or5 >> 0) & 0x01) & ((f_u_cla24_pg_logic4_or0 >> 0) & 0x01);
  f_u_cla24_or6 = ((f_u_cla24_pg_logic4_and0 >> 0) & 0x01) | ((f_u_cla24_and12 >> 0) & 0x01);
  f_u_cla24_pg_logic5_or0 = ((a >> 5) & 0x01) | ((b >> 5) & 0x01);
  f_u_cla24_pg_logic5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  f_u_cla24_pg_logic5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  f_u_cla24_xor5 = ((f_u_cla24_pg_logic5_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or6 >> 0) & 0x01);
  f_u_cla24_and13 = ((f_u_cla24_or5 >> 0) & 0x01) & ((f_u_cla24_pg_logic5_or0 >> 0) & 0x01);
  f_u_cla24_and14 = ((f_u_cla24_and13 >> 0) & 0x01) & ((f_u_cla24_pg_logic4_or0 >> 0) & 0x01);
  f_u_cla24_and15 = ((f_u_cla24_pg_logic4_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic5_or0 >> 0) & 0x01);
  f_u_cla24_or7 = ((f_u_cla24_and14 >> 0) & 0x01) | ((f_u_cla24_and15 >> 0) & 0x01);
  f_u_cla24_or8 = ((f_u_cla24_pg_logic5_and0 >> 0) & 0x01) | ((f_u_cla24_or7 >> 0) & 0x01);
  f_u_cla24_pg_logic6_or0 = ((a >> 6) & 0x01) | ((b >> 6) & 0x01);
  f_u_cla24_pg_logic6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  f_u_cla24_pg_logic6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  f_u_cla24_xor6 = ((f_u_cla24_pg_logic6_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or8 >> 0) & 0x01);
  f_u_cla24_and16 = ((f_u_cla24_or5 >> 0) & 0x01) & ((f_u_cla24_pg_logic5_or0 >> 0) & 0x01);
  f_u_cla24_and17 = ((f_u_cla24_pg_logic6_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic4_or0 >> 0) & 0x01);
  f_u_cla24_and18 = ((f_u_cla24_and16 >> 0) & 0x01) & ((f_u_cla24_and17 >> 0) & 0x01);
  f_u_cla24_and19 = ((f_u_cla24_pg_logic4_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic6_or0 >> 0) & 0x01);
  f_u_cla24_and20 = ((f_u_cla24_and19 >> 0) & 0x01) & ((f_u_cla24_pg_logic5_or0 >> 0) & 0x01);
  f_u_cla24_and21 = ((f_u_cla24_pg_logic5_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic6_or0 >> 0) & 0x01);
  f_u_cla24_or9 = ((f_u_cla24_and18 >> 0) & 0x01) | ((f_u_cla24_and20 >> 0) & 0x01);
  f_u_cla24_or10 = ((f_u_cla24_or9 >> 0) & 0x01) | ((f_u_cla24_and21 >> 0) & 0x01);
  f_u_cla24_or11 = ((f_u_cla24_pg_logic6_and0 >> 0) & 0x01) | ((f_u_cla24_or10 >> 0) & 0x01);
  f_u_cla24_pg_logic7_or0 = ((a >> 7) & 0x01) | ((b >> 7) & 0x01);
  f_u_cla24_pg_logic7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  f_u_cla24_pg_logic7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  f_u_cla24_xor7 = ((f_u_cla24_pg_logic7_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or11 >> 0) & 0x01);
  f_u_cla24_and22 = ((f_u_cla24_or5 >> 0) & 0x01) & ((f_u_cla24_pg_logic6_or0 >> 0) & 0x01);
  f_u_cla24_and23 = ((f_u_cla24_pg_logic7_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic5_or0 >> 0) & 0x01);
  f_u_cla24_and24 = ((f_u_cla24_and22 >> 0) & 0x01) & ((f_u_cla24_and23 >> 0) & 0x01);
  f_u_cla24_and25 = ((f_u_cla24_and24 >> 0) & 0x01) & ((f_u_cla24_pg_logic4_or0 >> 0) & 0x01);
  f_u_cla24_and26 = ((f_u_cla24_pg_logic4_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic6_or0 >> 0) & 0x01);
  f_u_cla24_and27 = ((f_u_cla24_pg_logic7_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic5_or0 >> 0) & 0x01);
  f_u_cla24_and28 = ((f_u_cla24_and26 >> 0) & 0x01) & ((f_u_cla24_and27 >> 0) & 0x01);
  f_u_cla24_and29 = ((f_u_cla24_pg_logic5_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic7_or0 >> 0) & 0x01);
  f_u_cla24_and30 = ((f_u_cla24_and29 >> 0) & 0x01) & ((f_u_cla24_pg_logic6_or0 >> 0) & 0x01);
  f_u_cla24_and31 = ((f_u_cla24_pg_logic6_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic7_or0 >> 0) & 0x01);
  f_u_cla24_or12 = ((f_u_cla24_and25 >> 0) & 0x01) | ((f_u_cla24_and30 >> 0) & 0x01);
  f_u_cla24_or13 = ((f_u_cla24_and28 >> 0) & 0x01) | ((f_u_cla24_and31 >> 0) & 0x01);
  f_u_cla24_or14 = ((f_u_cla24_or12 >> 0) & 0x01) | ((f_u_cla24_or13 >> 0) & 0x01);
  f_u_cla24_or15 = ((f_u_cla24_pg_logic7_and0 >> 0) & 0x01) | ((f_u_cla24_or14 >> 0) & 0x01);
  f_u_cla24_pg_logic8_or0 = ((a >> 8) & 0x01) | ((b >> 8) & 0x01);
  f_u_cla24_pg_logic8_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  f_u_cla24_pg_logic8_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  f_u_cla24_xor8 = ((f_u_cla24_pg_logic8_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or15 >> 0) & 0x01);
  f_u_cla24_and32 = ((f_u_cla24_or15 >> 0) & 0x01) & ((f_u_cla24_pg_logic8_or0 >> 0) & 0x01);
  f_u_cla24_or16 = ((f_u_cla24_pg_logic8_and0 >> 0) & 0x01) | ((f_u_cla24_and32 >> 0) & 0x01);
  f_u_cla24_pg_logic9_or0 = ((a >> 9) & 0x01) | ((b >> 9) & 0x01);
  f_u_cla24_pg_logic9_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  f_u_cla24_pg_logic9_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  f_u_cla24_xor9 = ((f_u_cla24_pg_logic9_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or16 >> 0) & 0x01);
  f_u_cla24_and33 = ((f_u_cla24_or15 >> 0) & 0x01) & ((f_u_cla24_pg_logic9_or0 >> 0) & 0x01);
  f_u_cla24_and34 = ((f_u_cla24_and33 >> 0) & 0x01) & ((f_u_cla24_pg_logic8_or0 >> 0) & 0x01);
  f_u_cla24_and35 = ((f_u_cla24_pg_logic8_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic9_or0 >> 0) & 0x01);
  f_u_cla24_or17 = ((f_u_cla24_and34 >> 0) & 0x01) | ((f_u_cla24_and35 >> 0) & 0x01);
  f_u_cla24_or18 = ((f_u_cla24_pg_logic9_and0 >> 0) & 0x01) | ((f_u_cla24_or17 >> 0) & 0x01);
  f_u_cla24_pg_logic10_or0 = ((a >> 10) & 0x01) | ((b >> 10) & 0x01);
  f_u_cla24_pg_logic10_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  f_u_cla24_pg_logic10_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  f_u_cla24_xor10 = ((f_u_cla24_pg_logic10_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or18 >> 0) & 0x01);
  f_u_cla24_and36 = ((f_u_cla24_or15 >> 0) & 0x01) & ((f_u_cla24_pg_logic9_or0 >> 0) & 0x01);
  f_u_cla24_and37 = ((f_u_cla24_pg_logic10_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic8_or0 >> 0) & 0x01);
  f_u_cla24_and38 = ((f_u_cla24_and36 >> 0) & 0x01) & ((f_u_cla24_and37 >> 0) & 0x01);
  f_u_cla24_and39 = ((f_u_cla24_pg_logic8_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic10_or0 >> 0) & 0x01);
  f_u_cla24_and40 = ((f_u_cla24_and39 >> 0) & 0x01) & ((f_u_cla24_pg_logic9_or0 >> 0) & 0x01);
  f_u_cla24_and41 = ((f_u_cla24_pg_logic9_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic10_or0 >> 0) & 0x01);
  f_u_cla24_or19 = ((f_u_cla24_and38 >> 0) & 0x01) | ((f_u_cla24_and40 >> 0) & 0x01);
  f_u_cla24_or20 = ((f_u_cla24_or19 >> 0) & 0x01) | ((f_u_cla24_and41 >> 0) & 0x01);
  f_u_cla24_or21 = ((f_u_cla24_pg_logic10_and0 >> 0) & 0x01) | ((f_u_cla24_or20 >> 0) & 0x01);
  f_u_cla24_pg_logic11_or0 = ((a >> 11) & 0x01) | ((b >> 11) & 0x01);
  f_u_cla24_pg_logic11_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  f_u_cla24_pg_logic11_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  f_u_cla24_xor11 = ((f_u_cla24_pg_logic11_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or21 >> 0) & 0x01);
  f_u_cla24_and42 = ((f_u_cla24_or15 >> 0) & 0x01) & ((f_u_cla24_pg_logic10_or0 >> 0) & 0x01);
  f_u_cla24_and43 = ((f_u_cla24_pg_logic11_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic9_or0 >> 0) & 0x01);
  f_u_cla24_and44 = ((f_u_cla24_and42 >> 0) & 0x01) & ((f_u_cla24_and43 >> 0) & 0x01);
  f_u_cla24_and45 = ((f_u_cla24_and44 >> 0) & 0x01) & ((f_u_cla24_pg_logic8_or0 >> 0) & 0x01);
  f_u_cla24_and46 = ((f_u_cla24_pg_logic8_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic10_or0 >> 0) & 0x01);
  f_u_cla24_and47 = ((f_u_cla24_pg_logic11_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic9_or0 >> 0) & 0x01);
  f_u_cla24_and48 = ((f_u_cla24_and46 >> 0) & 0x01) & ((f_u_cla24_and47 >> 0) & 0x01);
  f_u_cla24_and49 = ((f_u_cla24_pg_logic9_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic11_or0 >> 0) & 0x01);
  f_u_cla24_and50 = ((f_u_cla24_and49 >> 0) & 0x01) & ((f_u_cla24_pg_logic10_or0 >> 0) & 0x01);
  f_u_cla24_and51 = ((f_u_cla24_pg_logic10_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic11_or0 >> 0) & 0x01);
  f_u_cla24_or22 = ((f_u_cla24_and45 >> 0) & 0x01) | ((f_u_cla24_and50 >> 0) & 0x01);
  f_u_cla24_or23 = ((f_u_cla24_and48 >> 0) & 0x01) | ((f_u_cla24_and51 >> 0) & 0x01);
  f_u_cla24_or24 = ((f_u_cla24_or22 >> 0) & 0x01) | ((f_u_cla24_or23 >> 0) & 0x01);
  f_u_cla24_or25 = ((f_u_cla24_pg_logic11_and0 >> 0) & 0x01) | ((f_u_cla24_or24 >> 0) & 0x01);
  f_u_cla24_pg_logic12_or0 = ((a >> 12) & 0x01) | ((b >> 12) & 0x01);
  f_u_cla24_pg_logic12_and0 = ((a >> 12) & 0x01) & ((b >> 12) & 0x01);
  f_u_cla24_pg_logic12_xor0 = ((a >> 12) & 0x01) ^ ((b >> 12) & 0x01);
  f_u_cla24_xor12 = ((f_u_cla24_pg_logic12_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or25 >> 0) & 0x01);
  f_u_cla24_and52 = ((f_u_cla24_or25 >> 0) & 0x01) & ((f_u_cla24_pg_logic12_or0 >> 0) & 0x01);
  f_u_cla24_or26 = ((f_u_cla24_pg_logic12_and0 >> 0) & 0x01) | ((f_u_cla24_and52 >> 0) & 0x01);
  f_u_cla24_pg_logic13_or0 = ((a >> 13) & 0x01) | ((b >> 13) & 0x01);
  f_u_cla24_pg_logic13_and0 = ((a >> 13) & 0x01) & ((b >> 13) & 0x01);
  f_u_cla24_pg_logic13_xor0 = ((a >> 13) & 0x01) ^ ((b >> 13) & 0x01);
  f_u_cla24_xor13 = ((f_u_cla24_pg_logic13_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or26 >> 0) & 0x01);
  f_u_cla24_and53 = ((f_u_cla24_or25 >> 0) & 0x01) & ((f_u_cla24_pg_logic13_or0 >> 0) & 0x01);
  f_u_cla24_and54 = ((f_u_cla24_and53 >> 0) & 0x01) & ((f_u_cla24_pg_logic12_or0 >> 0) & 0x01);
  f_u_cla24_and55 = ((f_u_cla24_pg_logic12_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic13_or0 >> 0) & 0x01);
  f_u_cla24_or27 = ((f_u_cla24_and54 >> 0) & 0x01) | ((f_u_cla24_and55 >> 0) & 0x01);
  f_u_cla24_or28 = ((f_u_cla24_pg_logic13_and0 >> 0) & 0x01) | ((f_u_cla24_or27 >> 0) & 0x01);
  f_u_cla24_pg_logic14_or0 = ((a >> 14) & 0x01) | ((b >> 14) & 0x01);
  f_u_cla24_pg_logic14_and0 = ((a >> 14) & 0x01) & ((b >> 14) & 0x01);
  f_u_cla24_pg_logic14_xor0 = ((a >> 14) & 0x01) ^ ((b >> 14) & 0x01);
  f_u_cla24_xor14 = ((f_u_cla24_pg_logic14_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or28 >> 0) & 0x01);
  f_u_cla24_and56 = ((f_u_cla24_or25 >> 0) & 0x01) & ((f_u_cla24_pg_logic13_or0 >> 0) & 0x01);
  f_u_cla24_and57 = ((f_u_cla24_pg_logic14_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic12_or0 >> 0) & 0x01);
  f_u_cla24_and58 = ((f_u_cla24_and56 >> 0) & 0x01) & ((f_u_cla24_and57 >> 0) & 0x01);
  f_u_cla24_and59 = ((f_u_cla24_pg_logic12_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic14_or0 >> 0) & 0x01);
  f_u_cla24_and60 = ((f_u_cla24_and59 >> 0) & 0x01) & ((f_u_cla24_pg_logic13_or0 >> 0) & 0x01);
  f_u_cla24_and61 = ((f_u_cla24_pg_logic13_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic14_or0 >> 0) & 0x01);
  f_u_cla24_or29 = ((f_u_cla24_and58 >> 0) & 0x01) | ((f_u_cla24_and60 >> 0) & 0x01);
  f_u_cla24_or30 = ((f_u_cla24_or29 >> 0) & 0x01) | ((f_u_cla24_and61 >> 0) & 0x01);
  f_u_cla24_or31 = ((f_u_cla24_pg_logic14_and0 >> 0) & 0x01) | ((f_u_cla24_or30 >> 0) & 0x01);
  f_u_cla24_pg_logic15_or0 = ((a >> 15) & 0x01) | ((b >> 15) & 0x01);
  f_u_cla24_pg_logic15_and0 = ((a >> 15) & 0x01) & ((b >> 15) & 0x01);
  f_u_cla24_pg_logic15_xor0 = ((a >> 15) & 0x01) ^ ((b >> 15) & 0x01);
  f_u_cla24_xor15 = ((f_u_cla24_pg_logic15_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or31 >> 0) & 0x01);
  f_u_cla24_and62 = ((f_u_cla24_or25 >> 0) & 0x01) & ((f_u_cla24_pg_logic14_or0 >> 0) & 0x01);
  f_u_cla24_and63 = ((f_u_cla24_pg_logic15_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic13_or0 >> 0) & 0x01);
  f_u_cla24_and64 = ((f_u_cla24_and62 >> 0) & 0x01) & ((f_u_cla24_and63 >> 0) & 0x01);
  f_u_cla24_and65 = ((f_u_cla24_and64 >> 0) & 0x01) & ((f_u_cla24_pg_logic12_or0 >> 0) & 0x01);
  f_u_cla24_and66 = ((f_u_cla24_pg_logic12_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic14_or0 >> 0) & 0x01);
  f_u_cla24_and67 = ((f_u_cla24_pg_logic15_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic13_or0 >> 0) & 0x01);
  f_u_cla24_and68 = ((f_u_cla24_and66 >> 0) & 0x01) & ((f_u_cla24_and67 >> 0) & 0x01);
  f_u_cla24_and69 = ((f_u_cla24_pg_logic13_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic15_or0 >> 0) & 0x01);
  f_u_cla24_and70 = ((f_u_cla24_and69 >> 0) & 0x01) & ((f_u_cla24_pg_logic14_or0 >> 0) & 0x01);
  f_u_cla24_and71 = ((f_u_cla24_pg_logic14_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic15_or0 >> 0) & 0x01);
  f_u_cla24_or32 = ((f_u_cla24_and65 >> 0) & 0x01) | ((f_u_cla24_and70 >> 0) & 0x01);
  f_u_cla24_or33 = ((f_u_cla24_and68 >> 0) & 0x01) | ((f_u_cla24_and71 >> 0) & 0x01);
  f_u_cla24_or34 = ((f_u_cla24_or32 >> 0) & 0x01) | ((f_u_cla24_or33 >> 0) & 0x01);
  f_u_cla24_or35 = ((f_u_cla24_pg_logic15_and0 >> 0) & 0x01) | ((f_u_cla24_or34 >> 0) & 0x01);
  f_u_cla24_pg_logic16_or0 = ((a >> 16) & 0x01) | ((b >> 16) & 0x01);
  f_u_cla24_pg_logic16_and0 = ((a >> 16) & 0x01) & ((b >> 16) & 0x01);
  f_u_cla24_pg_logic16_xor0 = ((a >> 16) & 0x01) ^ ((b >> 16) & 0x01);
  f_u_cla24_xor16 = ((f_u_cla24_pg_logic16_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or35 >> 0) & 0x01);
  f_u_cla24_and72 = ((f_u_cla24_or35 >> 0) & 0x01) & ((f_u_cla24_pg_logic16_or0 >> 0) & 0x01);
  f_u_cla24_or36 = ((f_u_cla24_pg_logic16_and0 >> 0) & 0x01) | ((f_u_cla24_and72 >> 0) & 0x01);
  f_u_cla24_pg_logic17_or0 = ((a >> 17) & 0x01) | ((b >> 17) & 0x01);
  f_u_cla24_pg_logic17_and0 = ((a >> 17) & 0x01) & ((b >> 17) & 0x01);
  f_u_cla24_pg_logic17_xor0 = ((a >> 17) & 0x01) ^ ((b >> 17) & 0x01);
  f_u_cla24_xor17 = ((f_u_cla24_pg_logic17_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or36 >> 0) & 0x01);
  f_u_cla24_and73 = ((f_u_cla24_or35 >> 0) & 0x01) & ((f_u_cla24_pg_logic17_or0 >> 0) & 0x01);
  f_u_cla24_and74 = ((f_u_cla24_and73 >> 0) & 0x01) & ((f_u_cla24_pg_logic16_or0 >> 0) & 0x01);
  f_u_cla24_and75 = ((f_u_cla24_pg_logic16_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic17_or0 >> 0) & 0x01);
  f_u_cla24_or37 = ((f_u_cla24_and74 >> 0) & 0x01) | ((f_u_cla24_and75 >> 0) & 0x01);
  f_u_cla24_or38 = ((f_u_cla24_pg_logic17_and0 >> 0) & 0x01) | ((f_u_cla24_or37 >> 0) & 0x01);
  f_u_cla24_pg_logic18_or0 = ((a >> 18) & 0x01) | ((b >> 18) & 0x01);
  f_u_cla24_pg_logic18_and0 = ((a >> 18) & 0x01) & ((b >> 18) & 0x01);
  f_u_cla24_pg_logic18_xor0 = ((a >> 18) & 0x01) ^ ((b >> 18) & 0x01);
  f_u_cla24_xor18 = ((f_u_cla24_pg_logic18_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or38 >> 0) & 0x01);
  f_u_cla24_and76 = ((f_u_cla24_or35 >> 0) & 0x01) & ((f_u_cla24_pg_logic17_or0 >> 0) & 0x01);
  f_u_cla24_and77 = ((f_u_cla24_pg_logic18_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic16_or0 >> 0) & 0x01);
  f_u_cla24_and78 = ((f_u_cla24_and76 >> 0) & 0x01) & ((f_u_cla24_and77 >> 0) & 0x01);
  f_u_cla24_and79 = ((f_u_cla24_pg_logic16_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic18_or0 >> 0) & 0x01);
  f_u_cla24_and80 = ((f_u_cla24_and79 >> 0) & 0x01) & ((f_u_cla24_pg_logic17_or0 >> 0) & 0x01);
  f_u_cla24_and81 = ((f_u_cla24_pg_logic17_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic18_or0 >> 0) & 0x01);
  f_u_cla24_or39 = ((f_u_cla24_and78 >> 0) & 0x01) | ((f_u_cla24_and80 >> 0) & 0x01);
  f_u_cla24_or40 = ((f_u_cla24_or39 >> 0) & 0x01) | ((f_u_cla24_and81 >> 0) & 0x01);
  f_u_cla24_or41 = ((f_u_cla24_pg_logic18_and0 >> 0) & 0x01) | ((f_u_cla24_or40 >> 0) & 0x01);
  f_u_cla24_pg_logic19_or0 = ((a >> 19) & 0x01) | ((b >> 19) & 0x01);
  f_u_cla24_pg_logic19_and0 = ((a >> 19) & 0x01) & ((b >> 19) & 0x01);
  f_u_cla24_pg_logic19_xor0 = ((a >> 19) & 0x01) ^ ((b >> 19) & 0x01);
  f_u_cla24_xor19 = ((f_u_cla24_pg_logic19_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or41 >> 0) & 0x01);
  f_u_cla24_and82 = ((f_u_cla24_or35 >> 0) & 0x01) & ((f_u_cla24_pg_logic18_or0 >> 0) & 0x01);
  f_u_cla24_and83 = ((f_u_cla24_pg_logic19_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic17_or0 >> 0) & 0x01);
  f_u_cla24_and84 = ((f_u_cla24_and82 >> 0) & 0x01) & ((f_u_cla24_and83 >> 0) & 0x01);
  f_u_cla24_and85 = ((f_u_cla24_and84 >> 0) & 0x01) & ((f_u_cla24_pg_logic16_or0 >> 0) & 0x01);
  f_u_cla24_and86 = ((f_u_cla24_pg_logic16_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic18_or0 >> 0) & 0x01);
  f_u_cla24_and87 = ((f_u_cla24_pg_logic19_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic17_or0 >> 0) & 0x01);
  f_u_cla24_and88 = ((f_u_cla24_and86 >> 0) & 0x01) & ((f_u_cla24_and87 >> 0) & 0x01);
  f_u_cla24_and89 = ((f_u_cla24_pg_logic17_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic19_or0 >> 0) & 0x01);
  f_u_cla24_and90 = ((f_u_cla24_and89 >> 0) & 0x01) & ((f_u_cla24_pg_logic18_or0 >> 0) & 0x01);
  f_u_cla24_and91 = ((f_u_cla24_pg_logic18_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic19_or0 >> 0) & 0x01);
  f_u_cla24_or42 = ((f_u_cla24_and85 >> 0) & 0x01) | ((f_u_cla24_and90 >> 0) & 0x01);
  f_u_cla24_or43 = ((f_u_cla24_and88 >> 0) & 0x01) | ((f_u_cla24_and91 >> 0) & 0x01);
  f_u_cla24_or44 = ((f_u_cla24_or42 >> 0) & 0x01) | ((f_u_cla24_or43 >> 0) & 0x01);
  f_u_cla24_or45 = ((f_u_cla24_pg_logic19_and0 >> 0) & 0x01) | ((f_u_cla24_or44 >> 0) & 0x01);
  f_u_cla24_pg_logic20_or0 = ((a >> 20) & 0x01) | ((b >> 20) & 0x01);
  f_u_cla24_pg_logic20_and0 = ((a >> 20) & 0x01) & ((b >> 20) & 0x01);
  f_u_cla24_pg_logic20_xor0 = ((a >> 20) & 0x01) ^ ((b >> 20) & 0x01);
  f_u_cla24_xor20 = ((f_u_cla24_pg_logic20_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or45 >> 0) & 0x01);
  f_u_cla24_and92 = ((f_u_cla24_or45 >> 0) & 0x01) & ((f_u_cla24_pg_logic20_or0 >> 0) & 0x01);
  f_u_cla24_or46 = ((f_u_cla24_pg_logic20_and0 >> 0) & 0x01) | ((f_u_cla24_and92 >> 0) & 0x01);
  f_u_cla24_pg_logic21_or0 = ((a >> 21) & 0x01) | ((b >> 21) & 0x01);
  f_u_cla24_pg_logic21_and0 = ((a >> 21) & 0x01) & ((b >> 21) & 0x01);
  f_u_cla24_pg_logic21_xor0 = ((a >> 21) & 0x01) ^ ((b >> 21) & 0x01);
  f_u_cla24_xor21 = ((f_u_cla24_pg_logic21_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or46 >> 0) & 0x01);
  f_u_cla24_and93 = ((f_u_cla24_or45 >> 0) & 0x01) & ((f_u_cla24_pg_logic21_or0 >> 0) & 0x01);
  f_u_cla24_and94 = ((f_u_cla24_and93 >> 0) & 0x01) & ((f_u_cla24_pg_logic20_or0 >> 0) & 0x01);
  f_u_cla24_and95 = ((f_u_cla24_pg_logic20_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic21_or0 >> 0) & 0x01);
  f_u_cla24_or47 = ((f_u_cla24_and94 >> 0) & 0x01) | ((f_u_cla24_and95 >> 0) & 0x01);
  f_u_cla24_or48 = ((f_u_cla24_pg_logic21_and0 >> 0) & 0x01) | ((f_u_cla24_or47 >> 0) & 0x01);
  f_u_cla24_pg_logic22_or0 = ((a >> 22) & 0x01) | ((b >> 22) & 0x01);
  f_u_cla24_pg_logic22_and0 = ((a >> 22) & 0x01) & ((b >> 22) & 0x01);
  f_u_cla24_pg_logic22_xor0 = ((a >> 22) & 0x01) ^ ((b >> 22) & 0x01);
  f_u_cla24_xor22 = ((f_u_cla24_pg_logic22_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or48 >> 0) & 0x01);
  f_u_cla24_and96 = ((f_u_cla24_or45 >> 0) & 0x01) & ((f_u_cla24_pg_logic21_or0 >> 0) & 0x01);
  f_u_cla24_and97 = ((f_u_cla24_pg_logic22_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic20_or0 >> 0) & 0x01);
  f_u_cla24_and98 = ((f_u_cla24_and96 >> 0) & 0x01) & ((f_u_cla24_and97 >> 0) & 0x01);
  f_u_cla24_and99 = ((f_u_cla24_pg_logic20_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic22_or0 >> 0) & 0x01);
  f_u_cla24_and100 = ((f_u_cla24_and99 >> 0) & 0x01) & ((f_u_cla24_pg_logic21_or0 >> 0) & 0x01);
  f_u_cla24_and101 = ((f_u_cla24_pg_logic21_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic22_or0 >> 0) & 0x01);
  f_u_cla24_or49 = ((f_u_cla24_and98 >> 0) & 0x01) | ((f_u_cla24_and100 >> 0) & 0x01);
  f_u_cla24_or50 = ((f_u_cla24_or49 >> 0) & 0x01) | ((f_u_cla24_and101 >> 0) & 0x01);
  f_u_cla24_or51 = ((f_u_cla24_pg_logic22_and0 >> 0) & 0x01) | ((f_u_cla24_or50 >> 0) & 0x01);
  f_u_cla24_pg_logic23_or0 = ((a >> 23) & 0x01) | ((b >> 23) & 0x01);
  f_u_cla24_pg_logic23_and0 = ((a >> 23) & 0x01) & ((b >> 23) & 0x01);
  f_u_cla24_pg_logic23_xor0 = ((a >> 23) & 0x01) ^ ((b >> 23) & 0x01);
  f_u_cla24_xor23 = ((f_u_cla24_pg_logic23_xor0 >> 0) & 0x01) ^ ((f_u_cla24_or51 >> 0) & 0x01);
  f_u_cla24_and102 = ((f_u_cla24_or45 >> 0) & 0x01) & ((f_u_cla24_pg_logic22_or0 >> 0) & 0x01);
  f_u_cla24_and103 = ((f_u_cla24_pg_logic23_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic21_or0 >> 0) & 0x01);
  f_u_cla24_and104 = ((f_u_cla24_and102 >> 0) & 0x01) & ((f_u_cla24_and103 >> 0) & 0x01);
  f_u_cla24_and105 = ((f_u_cla24_and104 >> 0) & 0x01) & ((f_u_cla24_pg_logic20_or0 >> 0) & 0x01);
  f_u_cla24_and106 = ((f_u_cla24_pg_logic20_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic22_or0 >> 0) & 0x01);
  f_u_cla24_and107 = ((f_u_cla24_pg_logic23_or0 >> 0) & 0x01) & ((f_u_cla24_pg_logic21_or0 >> 0) & 0x01);
  f_u_cla24_and108 = ((f_u_cla24_and106 >> 0) & 0x01) & ((f_u_cla24_and107 >> 0) & 0x01);
  f_u_cla24_and109 = ((f_u_cla24_pg_logic21_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic23_or0 >> 0) & 0x01);
  f_u_cla24_and110 = ((f_u_cla24_and109 >> 0) & 0x01) & ((f_u_cla24_pg_logic22_or0 >> 0) & 0x01);
  f_u_cla24_and111 = ((f_u_cla24_pg_logic22_and0 >> 0) & 0x01) & ((f_u_cla24_pg_logic23_or0 >> 0) & 0x01);
  f_u_cla24_or52 = ((f_u_cla24_and105 >> 0) & 0x01) | ((f_u_cla24_and110 >> 0) & 0x01);
  f_u_cla24_or53 = ((f_u_cla24_and108 >> 0) & 0x01) | ((f_u_cla24_and111 >> 0) & 0x01);
  f_u_cla24_or54 = ((f_u_cla24_or52 >> 0) & 0x01) | ((f_u_cla24_or53 >> 0) & 0x01);
  f_u_cla24_or55 = ((f_u_cla24_pg_logic23_and0 >> 0) & 0x01) | ((f_u_cla24_or54 >> 0) & 0x01);

  f_u_cla24_out |= ((f_u_cla24_pg_logic0_xor0 >> 0) & 0x01) << 0;
  f_u_cla24_out |= ((f_u_cla24_xor1 >> 0) & 0x01) << 1;
  f_u_cla24_out |= ((f_u_cla24_xor2 >> 0) & 0x01) << 2;
  f_u_cla24_out |= ((f_u_cla24_xor3 >> 0) & 0x01) << 3;
  f_u_cla24_out |= ((f_u_cla24_xor4 >> 0) & 0x01) << 4;
  f_u_cla24_out |= ((f_u_cla24_xor5 >> 0) & 0x01) << 5;
  f_u_cla24_out |= ((f_u_cla24_xor6 >> 0) & 0x01) << 6;
  f_u_cla24_out |= ((f_u_cla24_xor7 >> 0) & 0x01) << 7;
  f_u_cla24_out |= ((f_u_cla24_xor8 >> 0) & 0x01) << 8;
  f_u_cla24_out |= ((f_u_cla24_xor9 >> 0) & 0x01) << 9;
  f_u_cla24_out |= ((f_u_cla24_xor10 >> 0) & 0x01) << 10;
  f_u_cla24_out |= ((f_u_cla24_xor11 >> 0) & 0x01) << 11;
  f_u_cla24_out |= ((f_u_cla24_xor12 >> 0) & 0x01) << 12;
  f_u_cla24_out |= ((f_u_cla24_xor13 >> 0) & 0x01) << 13;
  f_u_cla24_out |= ((f_u_cla24_xor14 >> 0) & 0x01) << 14;
  f_u_cla24_out |= ((f_u_cla24_xor15 >> 0) & 0x01) << 15;
  f_u_cla24_out |= ((f_u_cla24_xor16 >> 0) & 0x01) << 16;
  f_u_cla24_out |= ((f_u_cla24_xor17 >> 0) & 0x01) << 17;
  f_u_cla24_out |= ((f_u_cla24_xor18 >> 0) & 0x01) << 18;
  f_u_cla24_out |= ((f_u_cla24_xor19 >> 0) & 0x01) << 19;
  f_u_cla24_out |= ((f_u_cla24_xor20 >> 0) & 0x01) << 20;
  f_u_cla24_out |= ((f_u_cla24_xor21 >> 0) & 0x01) << 21;
  f_u_cla24_out |= ((f_u_cla24_xor22 >> 0) & 0x01) << 22;
  f_u_cla24_out |= ((f_u_cla24_xor23 >> 0) & 0x01) << 23;
  f_u_cla24_out |= ((f_u_cla24_or55 >> 0) & 0x01) << 24;
  return f_u_cla24_out;
}