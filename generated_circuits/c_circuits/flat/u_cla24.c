#include <stdio.h>
#include <stdint.h>

uint64_t u_cla24(uint64_t a, uint64_t b){
  uint64_t u_cla24_out = 0;
  uint8_t u_cla24_pg_logic0_or0 = 0;
  uint8_t u_cla24_pg_logic0_and0 = 0;
  uint8_t u_cla24_pg_logic0_xor0 = 0;
  uint8_t u_cla24_pg_logic1_or0 = 0;
  uint8_t u_cla24_pg_logic1_and0 = 0;
  uint8_t u_cla24_pg_logic1_xor0 = 0;
  uint8_t u_cla24_xor1 = 0;
  uint8_t u_cla24_and0 = 0;
  uint8_t u_cla24_or0 = 0;
  uint8_t u_cla24_pg_logic2_or0 = 0;
  uint8_t u_cla24_pg_logic2_and0 = 0;
  uint8_t u_cla24_pg_logic2_xor0 = 0;
  uint8_t u_cla24_xor2 = 0;
  uint8_t u_cla24_and1 = 0;
  uint8_t u_cla24_and2 = 0;
  uint8_t u_cla24_and3 = 0;
  uint8_t u_cla24_and4 = 0;
  uint8_t u_cla24_or1 = 0;
  uint8_t u_cla24_or2 = 0;
  uint8_t u_cla24_pg_logic3_or0 = 0;
  uint8_t u_cla24_pg_logic3_and0 = 0;
  uint8_t u_cla24_pg_logic3_xor0 = 0;
  uint8_t u_cla24_xor3 = 0;
  uint8_t u_cla24_and5 = 0;
  uint8_t u_cla24_and6 = 0;
  uint8_t u_cla24_and7 = 0;
  uint8_t u_cla24_and8 = 0;
  uint8_t u_cla24_and9 = 0;
  uint8_t u_cla24_and10 = 0;
  uint8_t u_cla24_and11 = 0;
  uint8_t u_cla24_or3 = 0;
  uint8_t u_cla24_or4 = 0;
  uint8_t u_cla24_or5 = 0;
  uint8_t u_cla24_pg_logic4_or0 = 0;
  uint8_t u_cla24_pg_logic4_and0 = 0;
  uint8_t u_cla24_pg_logic4_xor0 = 0;
  uint8_t u_cla24_xor4 = 0;
  uint8_t u_cla24_and12 = 0;
  uint8_t u_cla24_or6 = 0;
  uint8_t u_cla24_pg_logic5_or0 = 0;
  uint8_t u_cla24_pg_logic5_and0 = 0;
  uint8_t u_cla24_pg_logic5_xor0 = 0;
  uint8_t u_cla24_xor5 = 0;
  uint8_t u_cla24_and13 = 0;
  uint8_t u_cla24_and14 = 0;
  uint8_t u_cla24_and15 = 0;
  uint8_t u_cla24_or7 = 0;
  uint8_t u_cla24_or8 = 0;
  uint8_t u_cla24_pg_logic6_or0 = 0;
  uint8_t u_cla24_pg_logic6_and0 = 0;
  uint8_t u_cla24_pg_logic6_xor0 = 0;
  uint8_t u_cla24_xor6 = 0;
  uint8_t u_cla24_and16 = 0;
  uint8_t u_cla24_and17 = 0;
  uint8_t u_cla24_and18 = 0;
  uint8_t u_cla24_and19 = 0;
  uint8_t u_cla24_and20 = 0;
  uint8_t u_cla24_and21 = 0;
  uint8_t u_cla24_or9 = 0;
  uint8_t u_cla24_or10 = 0;
  uint8_t u_cla24_or11 = 0;
  uint8_t u_cla24_pg_logic7_or0 = 0;
  uint8_t u_cla24_pg_logic7_and0 = 0;
  uint8_t u_cla24_pg_logic7_xor0 = 0;
  uint8_t u_cla24_xor7 = 0;
  uint8_t u_cla24_and22 = 0;
  uint8_t u_cla24_and23 = 0;
  uint8_t u_cla24_and24 = 0;
  uint8_t u_cla24_and25 = 0;
  uint8_t u_cla24_and26 = 0;
  uint8_t u_cla24_and27 = 0;
  uint8_t u_cla24_and28 = 0;
  uint8_t u_cla24_and29 = 0;
  uint8_t u_cla24_and30 = 0;
  uint8_t u_cla24_and31 = 0;
  uint8_t u_cla24_or12 = 0;
  uint8_t u_cla24_or13 = 0;
  uint8_t u_cla24_or14 = 0;
  uint8_t u_cla24_or15 = 0;
  uint8_t u_cla24_pg_logic8_or0 = 0;
  uint8_t u_cla24_pg_logic8_and0 = 0;
  uint8_t u_cla24_pg_logic8_xor0 = 0;
  uint8_t u_cla24_xor8 = 0;
  uint8_t u_cla24_and32 = 0;
  uint8_t u_cla24_or16 = 0;
  uint8_t u_cla24_pg_logic9_or0 = 0;
  uint8_t u_cla24_pg_logic9_and0 = 0;
  uint8_t u_cla24_pg_logic9_xor0 = 0;
  uint8_t u_cla24_xor9 = 0;
  uint8_t u_cla24_and33 = 0;
  uint8_t u_cla24_and34 = 0;
  uint8_t u_cla24_and35 = 0;
  uint8_t u_cla24_or17 = 0;
  uint8_t u_cla24_or18 = 0;
  uint8_t u_cla24_pg_logic10_or0 = 0;
  uint8_t u_cla24_pg_logic10_and0 = 0;
  uint8_t u_cla24_pg_logic10_xor0 = 0;
  uint8_t u_cla24_xor10 = 0;
  uint8_t u_cla24_and36 = 0;
  uint8_t u_cla24_and37 = 0;
  uint8_t u_cla24_and38 = 0;
  uint8_t u_cla24_and39 = 0;
  uint8_t u_cla24_and40 = 0;
  uint8_t u_cla24_and41 = 0;
  uint8_t u_cla24_or19 = 0;
  uint8_t u_cla24_or20 = 0;
  uint8_t u_cla24_or21 = 0;
  uint8_t u_cla24_pg_logic11_or0 = 0;
  uint8_t u_cla24_pg_logic11_and0 = 0;
  uint8_t u_cla24_pg_logic11_xor0 = 0;
  uint8_t u_cla24_xor11 = 0;
  uint8_t u_cla24_and42 = 0;
  uint8_t u_cla24_and43 = 0;
  uint8_t u_cla24_and44 = 0;
  uint8_t u_cla24_and45 = 0;
  uint8_t u_cla24_and46 = 0;
  uint8_t u_cla24_and47 = 0;
  uint8_t u_cla24_and48 = 0;
  uint8_t u_cla24_and49 = 0;
  uint8_t u_cla24_and50 = 0;
  uint8_t u_cla24_and51 = 0;
  uint8_t u_cla24_or22 = 0;
  uint8_t u_cla24_or23 = 0;
  uint8_t u_cla24_or24 = 0;
  uint8_t u_cla24_or25 = 0;
  uint8_t u_cla24_pg_logic12_or0 = 0;
  uint8_t u_cla24_pg_logic12_and0 = 0;
  uint8_t u_cla24_pg_logic12_xor0 = 0;
  uint8_t u_cla24_xor12 = 0;
  uint8_t u_cla24_and52 = 0;
  uint8_t u_cla24_or26 = 0;
  uint8_t u_cla24_pg_logic13_or0 = 0;
  uint8_t u_cla24_pg_logic13_and0 = 0;
  uint8_t u_cla24_pg_logic13_xor0 = 0;
  uint8_t u_cla24_xor13 = 0;
  uint8_t u_cla24_and53 = 0;
  uint8_t u_cla24_and54 = 0;
  uint8_t u_cla24_and55 = 0;
  uint8_t u_cla24_or27 = 0;
  uint8_t u_cla24_or28 = 0;
  uint8_t u_cla24_pg_logic14_or0 = 0;
  uint8_t u_cla24_pg_logic14_and0 = 0;
  uint8_t u_cla24_pg_logic14_xor0 = 0;
  uint8_t u_cla24_xor14 = 0;
  uint8_t u_cla24_and56 = 0;
  uint8_t u_cla24_and57 = 0;
  uint8_t u_cla24_and58 = 0;
  uint8_t u_cla24_and59 = 0;
  uint8_t u_cla24_and60 = 0;
  uint8_t u_cla24_and61 = 0;
  uint8_t u_cla24_or29 = 0;
  uint8_t u_cla24_or30 = 0;
  uint8_t u_cla24_or31 = 0;
  uint8_t u_cla24_pg_logic15_or0 = 0;
  uint8_t u_cla24_pg_logic15_and0 = 0;
  uint8_t u_cla24_pg_logic15_xor0 = 0;
  uint8_t u_cla24_xor15 = 0;
  uint8_t u_cla24_and62 = 0;
  uint8_t u_cla24_and63 = 0;
  uint8_t u_cla24_and64 = 0;
  uint8_t u_cla24_and65 = 0;
  uint8_t u_cla24_and66 = 0;
  uint8_t u_cla24_and67 = 0;
  uint8_t u_cla24_and68 = 0;
  uint8_t u_cla24_and69 = 0;
  uint8_t u_cla24_and70 = 0;
  uint8_t u_cla24_and71 = 0;
  uint8_t u_cla24_or32 = 0;
  uint8_t u_cla24_or33 = 0;
  uint8_t u_cla24_or34 = 0;
  uint8_t u_cla24_or35 = 0;
  uint8_t u_cla24_pg_logic16_or0 = 0;
  uint8_t u_cla24_pg_logic16_and0 = 0;
  uint8_t u_cla24_pg_logic16_xor0 = 0;
  uint8_t u_cla24_xor16 = 0;
  uint8_t u_cla24_and72 = 0;
  uint8_t u_cla24_or36 = 0;
  uint8_t u_cla24_pg_logic17_or0 = 0;
  uint8_t u_cla24_pg_logic17_and0 = 0;
  uint8_t u_cla24_pg_logic17_xor0 = 0;
  uint8_t u_cla24_xor17 = 0;
  uint8_t u_cla24_and73 = 0;
  uint8_t u_cla24_and74 = 0;
  uint8_t u_cla24_and75 = 0;
  uint8_t u_cla24_or37 = 0;
  uint8_t u_cla24_or38 = 0;
  uint8_t u_cla24_pg_logic18_or0 = 0;
  uint8_t u_cla24_pg_logic18_and0 = 0;
  uint8_t u_cla24_pg_logic18_xor0 = 0;
  uint8_t u_cla24_xor18 = 0;
  uint8_t u_cla24_and76 = 0;
  uint8_t u_cla24_and77 = 0;
  uint8_t u_cla24_and78 = 0;
  uint8_t u_cla24_and79 = 0;
  uint8_t u_cla24_and80 = 0;
  uint8_t u_cla24_and81 = 0;
  uint8_t u_cla24_or39 = 0;
  uint8_t u_cla24_or40 = 0;
  uint8_t u_cla24_or41 = 0;
  uint8_t u_cla24_pg_logic19_or0 = 0;
  uint8_t u_cla24_pg_logic19_and0 = 0;
  uint8_t u_cla24_pg_logic19_xor0 = 0;
  uint8_t u_cla24_xor19 = 0;
  uint8_t u_cla24_and82 = 0;
  uint8_t u_cla24_and83 = 0;
  uint8_t u_cla24_and84 = 0;
  uint8_t u_cla24_and85 = 0;
  uint8_t u_cla24_and86 = 0;
  uint8_t u_cla24_and87 = 0;
  uint8_t u_cla24_and88 = 0;
  uint8_t u_cla24_and89 = 0;
  uint8_t u_cla24_and90 = 0;
  uint8_t u_cla24_and91 = 0;
  uint8_t u_cla24_or42 = 0;
  uint8_t u_cla24_or43 = 0;
  uint8_t u_cla24_or44 = 0;
  uint8_t u_cla24_or45 = 0;
  uint8_t u_cla24_pg_logic20_or0 = 0;
  uint8_t u_cla24_pg_logic20_and0 = 0;
  uint8_t u_cla24_pg_logic20_xor0 = 0;
  uint8_t u_cla24_xor20 = 0;
  uint8_t u_cla24_and92 = 0;
  uint8_t u_cla24_or46 = 0;
  uint8_t u_cla24_pg_logic21_or0 = 0;
  uint8_t u_cla24_pg_logic21_and0 = 0;
  uint8_t u_cla24_pg_logic21_xor0 = 0;
  uint8_t u_cla24_xor21 = 0;
  uint8_t u_cla24_and93 = 0;
  uint8_t u_cla24_and94 = 0;
  uint8_t u_cla24_and95 = 0;
  uint8_t u_cla24_or47 = 0;
  uint8_t u_cla24_or48 = 0;
  uint8_t u_cla24_pg_logic22_or0 = 0;
  uint8_t u_cla24_pg_logic22_and0 = 0;
  uint8_t u_cla24_pg_logic22_xor0 = 0;
  uint8_t u_cla24_xor22 = 0;
  uint8_t u_cla24_and96 = 0;
  uint8_t u_cla24_and97 = 0;
  uint8_t u_cla24_and98 = 0;
  uint8_t u_cla24_and99 = 0;
  uint8_t u_cla24_and100 = 0;
  uint8_t u_cla24_and101 = 0;
  uint8_t u_cla24_or49 = 0;
  uint8_t u_cla24_or50 = 0;
  uint8_t u_cla24_or51 = 0;
  uint8_t u_cla24_pg_logic23_or0 = 0;
  uint8_t u_cla24_pg_logic23_and0 = 0;
  uint8_t u_cla24_pg_logic23_xor0 = 0;
  uint8_t u_cla24_xor23 = 0;
  uint8_t u_cla24_and102 = 0;
  uint8_t u_cla24_and103 = 0;
  uint8_t u_cla24_and104 = 0;
  uint8_t u_cla24_and105 = 0;
  uint8_t u_cla24_and106 = 0;
  uint8_t u_cla24_and107 = 0;
  uint8_t u_cla24_and108 = 0;
  uint8_t u_cla24_and109 = 0;
  uint8_t u_cla24_and110 = 0;
  uint8_t u_cla24_and111 = 0;
  uint8_t u_cla24_or52 = 0;
  uint8_t u_cla24_or53 = 0;
  uint8_t u_cla24_or54 = 0;
  uint8_t u_cla24_or55 = 0;

  u_cla24_pg_logic0_or0 = ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
  u_cla24_pg_logic0_and0 = ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
  u_cla24_pg_logic0_xor0 = ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
  u_cla24_pg_logic1_or0 = ((a >> 1) & 0x01) | ((b >> 1) & 0x01);
  u_cla24_pg_logic1_and0 = ((a >> 1) & 0x01) & ((b >> 1) & 0x01);
  u_cla24_pg_logic1_xor0 = ((a >> 1) & 0x01) ^ ((b >> 1) & 0x01);
  u_cla24_xor1 = ((u_cla24_pg_logic1_xor0 >> 0) & 0x01) ^ ((u_cla24_pg_logic0_and0 >> 0) & 0x01);
  u_cla24_and0 = ((u_cla24_pg_logic0_and0 >> 0) & 0x01) & ((u_cla24_pg_logic1_or0 >> 0) & 0x01);
  u_cla24_or0 = ((u_cla24_pg_logic1_and0 >> 0) & 0x01) | ((u_cla24_and0 >> 0) & 0x01);
  u_cla24_pg_logic2_or0 = ((a >> 2) & 0x01) | ((b >> 2) & 0x01);
  u_cla24_pg_logic2_and0 = ((a >> 2) & 0x01) & ((b >> 2) & 0x01);
  u_cla24_pg_logic2_xor0 = ((a >> 2) & 0x01) ^ ((b >> 2) & 0x01);
  u_cla24_xor2 = ((u_cla24_pg_logic2_xor0 >> 0) & 0x01) ^ ((u_cla24_or0 >> 0) & 0x01);
  u_cla24_and1 = ((u_cla24_pg_logic2_or0 >> 0) & 0x01) & ((u_cla24_pg_logic0_or0 >> 0) & 0x01);
  u_cla24_and2 = ((u_cla24_pg_logic0_and0 >> 0) & 0x01) & ((u_cla24_pg_logic2_or0 >> 0) & 0x01);
  u_cla24_and3 = ((u_cla24_and2 >> 0) & 0x01) & ((u_cla24_pg_logic1_or0 >> 0) & 0x01);
  u_cla24_and4 = ((u_cla24_pg_logic1_and0 >> 0) & 0x01) & ((u_cla24_pg_logic2_or0 >> 0) & 0x01);
  u_cla24_or1 = ((u_cla24_and3 >> 0) & 0x01) | ((u_cla24_and4 >> 0) & 0x01);
  u_cla24_or2 = ((u_cla24_pg_logic2_and0 >> 0) & 0x01) | ((u_cla24_or1 >> 0) & 0x01);
  u_cla24_pg_logic3_or0 = ((a >> 3) & 0x01) | ((b >> 3) & 0x01);
  u_cla24_pg_logic3_and0 = ((a >> 3) & 0x01) & ((b >> 3) & 0x01);
  u_cla24_pg_logic3_xor0 = ((a >> 3) & 0x01) ^ ((b >> 3) & 0x01);
  u_cla24_xor3 = ((u_cla24_pg_logic3_xor0 >> 0) & 0x01) ^ ((u_cla24_or2 >> 0) & 0x01);
  u_cla24_and5 = ((u_cla24_pg_logic3_or0 >> 0) & 0x01) & ((u_cla24_pg_logic1_or0 >> 0) & 0x01);
  u_cla24_and6 = ((u_cla24_pg_logic0_and0 >> 0) & 0x01) & ((u_cla24_pg_logic2_or0 >> 0) & 0x01);
  u_cla24_and7 = ((u_cla24_pg_logic3_or0 >> 0) & 0x01) & ((u_cla24_pg_logic1_or0 >> 0) & 0x01);
  u_cla24_and8 = ((u_cla24_and6 >> 0) & 0x01) & ((u_cla24_and7 >> 0) & 0x01);
  u_cla24_and9 = ((u_cla24_pg_logic1_and0 >> 0) & 0x01) & ((u_cla24_pg_logic3_or0 >> 0) & 0x01);
  u_cla24_and10 = ((u_cla24_and9 >> 0) & 0x01) & ((u_cla24_pg_logic2_or0 >> 0) & 0x01);
  u_cla24_and11 = ((u_cla24_pg_logic2_and0 >> 0) & 0x01) & ((u_cla24_pg_logic3_or0 >> 0) & 0x01);
  u_cla24_or3 = ((u_cla24_and8 >> 0) & 0x01) | ((u_cla24_and11 >> 0) & 0x01);
  u_cla24_or4 = ((u_cla24_and10 >> 0) & 0x01) | ((u_cla24_or3 >> 0) & 0x01);
  u_cla24_or5 = ((u_cla24_pg_logic3_and0 >> 0) & 0x01) | ((u_cla24_or4 >> 0) & 0x01);
  u_cla24_pg_logic4_or0 = ((a >> 4) & 0x01) | ((b >> 4) & 0x01);
  u_cla24_pg_logic4_and0 = ((a >> 4) & 0x01) & ((b >> 4) & 0x01);
  u_cla24_pg_logic4_xor0 = ((a >> 4) & 0x01) ^ ((b >> 4) & 0x01);
  u_cla24_xor4 = ((u_cla24_pg_logic4_xor0 >> 0) & 0x01) ^ ((u_cla24_or5 >> 0) & 0x01);
  u_cla24_and12 = ((u_cla24_or5 >> 0) & 0x01) & ((u_cla24_pg_logic4_or0 >> 0) & 0x01);
  u_cla24_or6 = ((u_cla24_pg_logic4_and0 >> 0) & 0x01) | ((u_cla24_and12 >> 0) & 0x01);
  u_cla24_pg_logic5_or0 = ((a >> 5) & 0x01) | ((b >> 5) & 0x01);
  u_cla24_pg_logic5_and0 = ((a >> 5) & 0x01) & ((b >> 5) & 0x01);
  u_cla24_pg_logic5_xor0 = ((a >> 5) & 0x01) ^ ((b >> 5) & 0x01);
  u_cla24_xor5 = ((u_cla24_pg_logic5_xor0 >> 0) & 0x01) ^ ((u_cla24_or6 >> 0) & 0x01);
  u_cla24_and13 = ((u_cla24_or5 >> 0) & 0x01) & ((u_cla24_pg_logic5_or0 >> 0) & 0x01);
  u_cla24_and14 = ((u_cla24_and13 >> 0) & 0x01) & ((u_cla24_pg_logic4_or0 >> 0) & 0x01);
  u_cla24_and15 = ((u_cla24_pg_logic4_and0 >> 0) & 0x01) & ((u_cla24_pg_logic5_or0 >> 0) & 0x01);
  u_cla24_or7 = ((u_cla24_and14 >> 0) & 0x01) | ((u_cla24_and15 >> 0) & 0x01);
  u_cla24_or8 = ((u_cla24_pg_logic5_and0 >> 0) & 0x01) | ((u_cla24_or7 >> 0) & 0x01);
  u_cla24_pg_logic6_or0 = ((a >> 6) & 0x01) | ((b >> 6) & 0x01);
  u_cla24_pg_logic6_and0 = ((a >> 6) & 0x01) & ((b >> 6) & 0x01);
  u_cla24_pg_logic6_xor0 = ((a >> 6) & 0x01) ^ ((b >> 6) & 0x01);
  u_cla24_xor6 = ((u_cla24_pg_logic6_xor0 >> 0) & 0x01) ^ ((u_cla24_or8 >> 0) & 0x01);
  u_cla24_and16 = ((u_cla24_or5 >> 0) & 0x01) & ((u_cla24_pg_logic5_or0 >> 0) & 0x01);
  u_cla24_and17 = ((u_cla24_pg_logic6_or0 >> 0) & 0x01) & ((u_cla24_pg_logic4_or0 >> 0) & 0x01);
  u_cla24_and18 = ((u_cla24_and16 >> 0) & 0x01) & ((u_cla24_and17 >> 0) & 0x01);
  u_cla24_and19 = ((u_cla24_pg_logic4_and0 >> 0) & 0x01) & ((u_cla24_pg_logic6_or0 >> 0) & 0x01);
  u_cla24_and20 = ((u_cla24_and19 >> 0) & 0x01) & ((u_cla24_pg_logic5_or0 >> 0) & 0x01);
  u_cla24_and21 = ((u_cla24_pg_logic5_and0 >> 0) & 0x01) & ((u_cla24_pg_logic6_or0 >> 0) & 0x01);
  u_cla24_or9 = ((u_cla24_and18 >> 0) & 0x01) | ((u_cla24_and20 >> 0) & 0x01);
  u_cla24_or10 = ((u_cla24_or9 >> 0) & 0x01) | ((u_cla24_and21 >> 0) & 0x01);
  u_cla24_or11 = ((u_cla24_pg_logic6_and0 >> 0) & 0x01) | ((u_cla24_or10 >> 0) & 0x01);
  u_cla24_pg_logic7_or0 = ((a >> 7) & 0x01) | ((b >> 7) & 0x01);
  u_cla24_pg_logic7_and0 = ((a >> 7) & 0x01) & ((b >> 7) & 0x01);
  u_cla24_pg_logic7_xor0 = ((a >> 7) & 0x01) ^ ((b >> 7) & 0x01);
  u_cla24_xor7 = ((u_cla24_pg_logic7_xor0 >> 0) & 0x01) ^ ((u_cla24_or11 >> 0) & 0x01);
  u_cla24_and22 = ((u_cla24_or5 >> 0) & 0x01) & ((u_cla24_pg_logic6_or0 >> 0) & 0x01);
  u_cla24_and23 = ((u_cla24_pg_logic7_or0 >> 0) & 0x01) & ((u_cla24_pg_logic5_or0 >> 0) & 0x01);
  u_cla24_and24 = ((u_cla24_and22 >> 0) & 0x01) & ((u_cla24_and23 >> 0) & 0x01);
  u_cla24_and25 = ((u_cla24_and24 >> 0) & 0x01) & ((u_cla24_pg_logic4_or0 >> 0) & 0x01);
  u_cla24_and26 = ((u_cla24_pg_logic4_and0 >> 0) & 0x01) & ((u_cla24_pg_logic6_or0 >> 0) & 0x01);
  u_cla24_and27 = ((u_cla24_pg_logic7_or0 >> 0) & 0x01) & ((u_cla24_pg_logic5_or0 >> 0) & 0x01);
  u_cla24_and28 = ((u_cla24_and26 >> 0) & 0x01) & ((u_cla24_and27 >> 0) & 0x01);
  u_cla24_and29 = ((u_cla24_pg_logic5_and0 >> 0) & 0x01) & ((u_cla24_pg_logic7_or0 >> 0) & 0x01);
  u_cla24_and30 = ((u_cla24_and29 >> 0) & 0x01) & ((u_cla24_pg_logic6_or0 >> 0) & 0x01);
  u_cla24_and31 = ((u_cla24_pg_logic6_and0 >> 0) & 0x01) & ((u_cla24_pg_logic7_or0 >> 0) & 0x01);
  u_cla24_or12 = ((u_cla24_and25 >> 0) & 0x01) | ((u_cla24_and30 >> 0) & 0x01);
  u_cla24_or13 = ((u_cla24_and28 >> 0) & 0x01) | ((u_cla24_and31 >> 0) & 0x01);
  u_cla24_or14 = ((u_cla24_or12 >> 0) & 0x01) | ((u_cla24_or13 >> 0) & 0x01);
  u_cla24_or15 = ((u_cla24_pg_logic7_and0 >> 0) & 0x01) | ((u_cla24_or14 >> 0) & 0x01);
  u_cla24_pg_logic8_or0 = ((a >> 8) & 0x01) | ((b >> 8) & 0x01);
  u_cla24_pg_logic8_and0 = ((a >> 8) & 0x01) & ((b >> 8) & 0x01);
  u_cla24_pg_logic8_xor0 = ((a >> 8) & 0x01) ^ ((b >> 8) & 0x01);
  u_cla24_xor8 = ((u_cla24_pg_logic8_xor0 >> 0) & 0x01) ^ ((u_cla24_or15 >> 0) & 0x01);
  u_cla24_and32 = ((u_cla24_or15 >> 0) & 0x01) & ((u_cla24_pg_logic8_or0 >> 0) & 0x01);
  u_cla24_or16 = ((u_cla24_pg_logic8_and0 >> 0) & 0x01) | ((u_cla24_and32 >> 0) & 0x01);
  u_cla24_pg_logic9_or0 = ((a >> 9) & 0x01) | ((b >> 9) & 0x01);
  u_cla24_pg_logic9_and0 = ((a >> 9) & 0x01) & ((b >> 9) & 0x01);
  u_cla24_pg_logic9_xor0 = ((a >> 9) & 0x01) ^ ((b >> 9) & 0x01);
  u_cla24_xor9 = ((u_cla24_pg_logic9_xor0 >> 0) & 0x01) ^ ((u_cla24_or16 >> 0) & 0x01);
  u_cla24_and33 = ((u_cla24_or15 >> 0) & 0x01) & ((u_cla24_pg_logic9_or0 >> 0) & 0x01);
  u_cla24_and34 = ((u_cla24_and33 >> 0) & 0x01) & ((u_cla24_pg_logic8_or0 >> 0) & 0x01);
  u_cla24_and35 = ((u_cla24_pg_logic8_and0 >> 0) & 0x01) & ((u_cla24_pg_logic9_or0 >> 0) & 0x01);
  u_cla24_or17 = ((u_cla24_and34 >> 0) & 0x01) | ((u_cla24_and35 >> 0) & 0x01);
  u_cla24_or18 = ((u_cla24_pg_logic9_and0 >> 0) & 0x01) | ((u_cla24_or17 >> 0) & 0x01);
  u_cla24_pg_logic10_or0 = ((a >> 10) & 0x01) | ((b >> 10) & 0x01);
  u_cla24_pg_logic10_and0 = ((a >> 10) & 0x01) & ((b >> 10) & 0x01);
  u_cla24_pg_logic10_xor0 = ((a >> 10) & 0x01) ^ ((b >> 10) & 0x01);
  u_cla24_xor10 = ((u_cla24_pg_logic10_xor0 >> 0) & 0x01) ^ ((u_cla24_or18 >> 0) & 0x01);
  u_cla24_and36 = ((u_cla24_or15 >> 0) & 0x01) & ((u_cla24_pg_logic9_or0 >> 0) & 0x01);
  u_cla24_and37 = ((u_cla24_pg_logic10_or0 >> 0) & 0x01) & ((u_cla24_pg_logic8_or0 >> 0) & 0x01);
  u_cla24_and38 = ((u_cla24_and36 >> 0) & 0x01) & ((u_cla24_and37 >> 0) & 0x01);
  u_cla24_and39 = ((u_cla24_pg_logic8_and0 >> 0) & 0x01) & ((u_cla24_pg_logic10_or0 >> 0) & 0x01);
  u_cla24_and40 = ((u_cla24_and39 >> 0) & 0x01) & ((u_cla24_pg_logic9_or0 >> 0) & 0x01);
  u_cla24_and41 = ((u_cla24_pg_logic9_and0 >> 0) & 0x01) & ((u_cla24_pg_logic10_or0 >> 0) & 0x01);
  u_cla24_or19 = ((u_cla24_and38 >> 0) & 0x01) | ((u_cla24_and40 >> 0) & 0x01);
  u_cla24_or20 = ((u_cla24_or19 >> 0) & 0x01) | ((u_cla24_and41 >> 0) & 0x01);
  u_cla24_or21 = ((u_cla24_pg_logic10_and0 >> 0) & 0x01) | ((u_cla24_or20 >> 0) & 0x01);
  u_cla24_pg_logic11_or0 = ((a >> 11) & 0x01) | ((b >> 11) & 0x01);
  u_cla24_pg_logic11_and0 = ((a >> 11) & 0x01) & ((b >> 11) & 0x01);
  u_cla24_pg_logic11_xor0 = ((a >> 11) & 0x01) ^ ((b >> 11) & 0x01);
  u_cla24_xor11 = ((u_cla24_pg_logic11_xor0 >> 0) & 0x01) ^ ((u_cla24_or21 >> 0) & 0x01);
  u_cla24_and42 = ((u_cla24_or15 >> 0) & 0x01) & ((u_cla24_pg_logic10_or0 >> 0) & 0x01);
  u_cla24_and43 = ((u_cla24_pg_logic11_or0 >> 0) & 0x01) & ((u_cla24_pg_logic9_or0 >> 0) & 0x01);
  u_cla24_and44 = ((u_cla24_and42 >> 0) & 0x01) & ((u_cla24_and43 >> 0) & 0x01);
  u_cla24_and45 = ((u_cla24_and44 >> 0) & 0x01) & ((u_cla24_pg_logic8_or0 >> 0) & 0x01);
  u_cla24_and46 = ((u_cla24_pg_logic8_and0 >> 0) & 0x01) & ((u_cla24_pg_logic10_or0 >> 0) & 0x01);
  u_cla24_and47 = ((u_cla24_pg_logic11_or0 >> 0) & 0x01) & ((u_cla24_pg_logic9_or0 >> 0) & 0x01);
  u_cla24_and48 = ((u_cla24_and46 >> 0) & 0x01) & ((u_cla24_and47 >> 0) & 0x01);
  u_cla24_and49 = ((u_cla24_pg_logic9_and0 >> 0) & 0x01) & ((u_cla24_pg_logic11_or0 >> 0) & 0x01);
  u_cla24_and50 = ((u_cla24_and49 >> 0) & 0x01) & ((u_cla24_pg_logic10_or0 >> 0) & 0x01);
  u_cla24_and51 = ((u_cla24_pg_logic10_and0 >> 0) & 0x01) & ((u_cla24_pg_logic11_or0 >> 0) & 0x01);
  u_cla24_or22 = ((u_cla24_and45 >> 0) & 0x01) | ((u_cla24_and50 >> 0) & 0x01);
  u_cla24_or23 = ((u_cla24_and48 >> 0) & 0x01) | ((u_cla24_and51 >> 0) & 0x01);
  u_cla24_or24 = ((u_cla24_or22 >> 0) & 0x01) | ((u_cla24_or23 >> 0) & 0x01);
  u_cla24_or25 = ((u_cla24_pg_logic11_and0 >> 0) & 0x01) | ((u_cla24_or24 >> 0) & 0x01);
  u_cla24_pg_logic12_or0 = ((a >> 12) & 0x01) | ((b >> 12) & 0x01);
  u_cla24_pg_logic12_and0 = ((a >> 12) & 0x01) & ((b >> 12) & 0x01);
  u_cla24_pg_logic12_xor0 = ((a >> 12) & 0x01) ^ ((b >> 12) & 0x01);
  u_cla24_xor12 = ((u_cla24_pg_logic12_xor0 >> 0) & 0x01) ^ ((u_cla24_or25 >> 0) & 0x01);
  u_cla24_and52 = ((u_cla24_or25 >> 0) & 0x01) & ((u_cla24_pg_logic12_or0 >> 0) & 0x01);
  u_cla24_or26 = ((u_cla24_pg_logic12_and0 >> 0) & 0x01) | ((u_cla24_and52 >> 0) & 0x01);
  u_cla24_pg_logic13_or0 = ((a >> 13) & 0x01) | ((b >> 13) & 0x01);
  u_cla24_pg_logic13_and0 = ((a >> 13) & 0x01) & ((b >> 13) & 0x01);
  u_cla24_pg_logic13_xor0 = ((a >> 13) & 0x01) ^ ((b >> 13) & 0x01);
  u_cla24_xor13 = ((u_cla24_pg_logic13_xor0 >> 0) & 0x01) ^ ((u_cla24_or26 >> 0) & 0x01);
  u_cla24_and53 = ((u_cla24_or25 >> 0) & 0x01) & ((u_cla24_pg_logic13_or0 >> 0) & 0x01);
  u_cla24_and54 = ((u_cla24_and53 >> 0) & 0x01) & ((u_cla24_pg_logic12_or0 >> 0) & 0x01);
  u_cla24_and55 = ((u_cla24_pg_logic12_and0 >> 0) & 0x01) & ((u_cla24_pg_logic13_or0 >> 0) & 0x01);
  u_cla24_or27 = ((u_cla24_and54 >> 0) & 0x01) | ((u_cla24_and55 >> 0) & 0x01);
  u_cla24_or28 = ((u_cla24_pg_logic13_and0 >> 0) & 0x01) | ((u_cla24_or27 >> 0) & 0x01);
  u_cla24_pg_logic14_or0 = ((a >> 14) & 0x01) | ((b >> 14) & 0x01);
  u_cla24_pg_logic14_and0 = ((a >> 14) & 0x01) & ((b >> 14) & 0x01);
  u_cla24_pg_logic14_xor0 = ((a >> 14) & 0x01) ^ ((b >> 14) & 0x01);
  u_cla24_xor14 = ((u_cla24_pg_logic14_xor0 >> 0) & 0x01) ^ ((u_cla24_or28 >> 0) & 0x01);
  u_cla24_and56 = ((u_cla24_or25 >> 0) & 0x01) & ((u_cla24_pg_logic13_or0 >> 0) & 0x01);
  u_cla24_and57 = ((u_cla24_pg_logic14_or0 >> 0) & 0x01) & ((u_cla24_pg_logic12_or0 >> 0) & 0x01);
  u_cla24_and58 = ((u_cla24_and56 >> 0) & 0x01) & ((u_cla24_and57 >> 0) & 0x01);
  u_cla24_and59 = ((u_cla24_pg_logic12_and0 >> 0) & 0x01) & ((u_cla24_pg_logic14_or0 >> 0) & 0x01);
  u_cla24_and60 = ((u_cla24_and59 >> 0) & 0x01) & ((u_cla24_pg_logic13_or0 >> 0) & 0x01);
  u_cla24_and61 = ((u_cla24_pg_logic13_and0 >> 0) & 0x01) & ((u_cla24_pg_logic14_or0 >> 0) & 0x01);
  u_cla24_or29 = ((u_cla24_and58 >> 0) & 0x01) | ((u_cla24_and60 >> 0) & 0x01);
  u_cla24_or30 = ((u_cla24_or29 >> 0) & 0x01) | ((u_cla24_and61 >> 0) & 0x01);
  u_cla24_or31 = ((u_cla24_pg_logic14_and0 >> 0) & 0x01) | ((u_cla24_or30 >> 0) & 0x01);
  u_cla24_pg_logic15_or0 = ((a >> 15) & 0x01) | ((b >> 15) & 0x01);
  u_cla24_pg_logic15_and0 = ((a >> 15) & 0x01) & ((b >> 15) & 0x01);
  u_cla24_pg_logic15_xor0 = ((a >> 15) & 0x01) ^ ((b >> 15) & 0x01);
  u_cla24_xor15 = ((u_cla24_pg_logic15_xor0 >> 0) & 0x01) ^ ((u_cla24_or31 >> 0) & 0x01);
  u_cla24_and62 = ((u_cla24_or25 >> 0) & 0x01) & ((u_cla24_pg_logic14_or0 >> 0) & 0x01);
  u_cla24_and63 = ((u_cla24_pg_logic15_or0 >> 0) & 0x01) & ((u_cla24_pg_logic13_or0 >> 0) & 0x01);
  u_cla24_and64 = ((u_cla24_and62 >> 0) & 0x01) & ((u_cla24_and63 >> 0) & 0x01);
  u_cla24_and65 = ((u_cla24_and64 >> 0) & 0x01) & ((u_cla24_pg_logic12_or0 >> 0) & 0x01);
  u_cla24_and66 = ((u_cla24_pg_logic12_and0 >> 0) & 0x01) & ((u_cla24_pg_logic14_or0 >> 0) & 0x01);
  u_cla24_and67 = ((u_cla24_pg_logic15_or0 >> 0) & 0x01) & ((u_cla24_pg_logic13_or0 >> 0) & 0x01);
  u_cla24_and68 = ((u_cla24_and66 >> 0) & 0x01) & ((u_cla24_and67 >> 0) & 0x01);
  u_cla24_and69 = ((u_cla24_pg_logic13_and0 >> 0) & 0x01) & ((u_cla24_pg_logic15_or0 >> 0) & 0x01);
  u_cla24_and70 = ((u_cla24_and69 >> 0) & 0x01) & ((u_cla24_pg_logic14_or0 >> 0) & 0x01);
  u_cla24_and71 = ((u_cla24_pg_logic14_and0 >> 0) & 0x01) & ((u_cla24_pg_logic15_or0 >> 0) & 0x01);
  u_cla24_or32 = ((u_cla24_and65 >> 0) & 0x01) | ((u_cla24_and70 >> 0) & 0x01);
  u_cla24_or33 = ((u_cla24_and68 >> 0) & 0x01) | ((u_cla24_and71 >> 0) & 0x01);
  u_cla24_or34 = ((u_cla24_or32 >> 0) & 0x01) | ((u_cla24_or33 >> 0) & 0x01);
  u_cla24_or35 = ((u_cla24_pg_logic15_and0 >> 0) & 0x01) | ((u_cla24_or34 >> 0) & 0x01);
  u_cla24_pg_logic16_or0 = ((a >> 16) & 0x01) | ((b >> 16) & 0x01);
  u_cla24_pg_logic16_and0 = ((a >> 16) & 0x01) & ((b >> 16) & 0x01);
  u_cla24_pg_logic16_xor0 = ((a >> 16) & 0x01) ^ ((b >> 16) & 0x01);
  u_cla24_xor16 = ((u_cla24_pg_logic16_xor0 >> 0) & 0x01) ^ ((u_cla24_or35 >> 0) & 0x01);
  u_cla24_and72 = ((u_cla24_or35 >> 0) & 0x01) & ((u_cla24_pg_logic16_or0 >> 0) & 0x01);
  u_cla24_or36 = ((u_cla24_pg_logic16_and0 >> 0) & 0x01) | ((u_cla24_and72 >> 0) & 0x01);
  u_cla24_pg_logic17_or0 = ((a >> 17) & 0x01) | ((b >> 17) & 0x01);
  u_cla24_pg_logic17_and0 = ((a >> 17) & 0x01) & ((b >> 17) & 0x01);
  u_cla24_pg_logic17_xor0 = ((a >> 17) & 0x01) ^ ((b >> 17) & 0x01);
  u_cla24_xor17 = ((u_cla24_pg_logic17_xor0 >> 0) & 0x01) ^ ((u_cla24_or36 >> 0) & 0x01);
  u_cla24_and73 = ((u_cla24_or35 >> 0) & 0x01) & ((u_cla24_pg_logic17_or0 >> 0) & 0x01);
  u_cla24_and74 = ((u_cla24_and73 >> 0) & 0x01) & ((u_cla24_pg_logic16_or0 >> 0) & 0x01);
  u_cla24_and75 = ((u_cla24_pg_logic16_and0 >> 0) & 0x01) & ((u_cla24_pg_logic17_or0 >> 0) & 0x01);
  u_cla24_or37 = ((u_cla24_and74 >> 0) & 0x01) | ((u_cla24_and75 >> 0) & 0x01);
  u_cla24_or38 = ((u_cla24_pg_logic17_and0 >> 0) & 0x01) | ((u_cla24_or37 >> 0) & 0x01);
  u_cla24_pg_logic18_or0 = ((a >> 18) & 0x01) | ((b >> 18) & 0x01);
  u_cla24_pg_logic18_and0 = ((a >> 18) & 0x01) & ((b >> 18) & 0x01);
  u_cla24_pg_logic18_xor0 = ((a >> 18) & 0x01) ^ ((b >> 18) & 0x01);
  u_cla24_xor18 = ((u_cla24_pg_logic18_xor0 >> 0) & 0x01) ^ ((u_cla24_or38 >> 0) & 0x01);
  u_cla24_and76 = ((u_cla24_or35 >> 0) & 0x01) & ((u_cla24_pg_logic17_or0 >> 0) & 0x01);
  u_cla24_and77 = ((u_cla24_pg_logic18_or0 >> 0) & 0x01) & ((u_cla24_pg_logic16_or0 >> 0) & 0x01);
  u_cla24_and78 = ((u_cla24_and76 >> 0) & 0x01) & ((u_cla24_and77 >> 0) & 0x01);
  u_cla24_and79 = ((u_cla24_pg_logic16_and0 >> 0) & 0x01) & ((u_cla24_pg_logic18_or0 >> 0) & 0x01);
  u_cla24_and80 = ((u_cla24_and79 >> 0) & 0x01) & ((u_cla24_pg_logic17_or0 >> 0) & 0x01);
  u_cla24_and81 = ((u_cla24_pg_logic17_and0 >> 0) & 0x01) & ((u_cla24_pg_logic18_or0 >> 0) & 0x01);
  u_cla24_or39 = ((u_cla24_and78 >> 0) & 0x01) | ((u_cla24_and80 >> 0) & 0x01);
  u_cla24_or40 = ((u_cla24_or39 >> 0) & 0x01) | ((u_cla24_and81 >> 0) & 0x01);
  u_cla24_or41 = ((u_cla24_pg_logic18_and0 >> 0) & 0x01) | ((u_cla24_or40 >> 0) & 0x01);
  u_cla24_pg_logic19_or0 = ((a >> 19) & 0x01) | ((b >> 19) & 0x01);
  u_cla24_pg_logic19_and0 = ((a >> 19) & 0x01) & ((b >> 19) & 0x01);
  u_cla24_pg_logic19_xor0 = ((a >> 19) & 0x01) ^ ((b >> 19) & 0x01);
  u_cla24_xor19 = ((u_cla24_pg_logic19_xor0 >> 0) & 0x01) ^ ((u_cla24_or41 >> 0) & 0x01);
  u_cla24_and82 = ((u_cla24_or35 >> 0) & 0x01) & ((u_cla24_pg_logic18_or0 >> 0) & 0x01);
  u_cla24_and83 = ((u_cla24_pg_logic19_or0 >> 0) & 0x01) & ((u_cla24_pg_logic17_or0 >> 0) & 0x01);
  u_cla24_and84 = ((u_cla24_and82 >> 0) & 0x01) & ((u_cla24_and83 >> 0) & 0x01);
  u_cla24_and85 = ((u_cla24_and84 >> 0) & 0x01) & ((u_cla24_pg_logic16_or0 >> 0) & 0x01);
  u_cla24_and86 = ((u_cla24_pg_logic16_and0 >> 0) & 0x01) & ((u_cla24_pg_logic18_or0 >> 0) & 0x01);
  u_cla24_and87 = ((u_cla24_pg_logic19_or0 >> 0) & 0x01) & ((u_cla24_pg_logic17_or0 >> 0) & 0x01);
  u_cla24_and88 = ((u_cla24_and86 >> 0) & 0x01) & ((u_cla24_and87 >> 0) & 0x01);
  u_cla24_and89 = ((u_cla24_pg_logic17_and0 >> 0) & 0x01) & ((u_cla24_pg_logic19_or0 >> 0) & 0x01);
  u_cla24_and90 = ((u_cla24_and89 >> 0) & 0x01) & ((u_cla24_pg_logic18_or0 >> 0) & 0x01);
  u_cla24_and91 = ((u_cla24_pg_logic18_and0 >> 0) & 0x01) & ((u_cla24_pg_logic19_or0 >> 0) & 0x01);
  u_cla24_or42 = ((u_cla24_and85 >> 0) & 0x01) | ((u_cla24_and90 >> 0) & 0x01);
  u_cla24_or43 = ((u_cla24_and88 >> 0) & 0x01) | ((u_cla24_and91 >> 0) & 0x01);
  u_cla24_or44 = ((u_cla24_or42 >> 0) & 0x01) | ((u_cla24_or43 >> 0) & 0x01);
  u_cla24_or45 = ((u_cla24_pg_logic19_and0 >> 0) & 0x01) | ((u_cla24_or44 >> 0) & 0x01);
  u_cla24_pg_logic20_or0 = ((a >> 20) & 0x01) | ((b >> 20) & 0x01);
  u_cla24_pg_logic20_and0 = ((a >> 20) & 0x01) & ((b >> 20) & 0x01);
  u_cla24_pg_logic20_xor0 = ((a >> 20) & 0x01) ^ ((b >> 20) & 0x01);
  u_cla24_xor20 = ((u_cla24_pg_logic20_xor0 >> 0) & 0x01) ^ ((u_cla24_or45 >> 0) & 0x01);
  u_cla24_and92 = ((u_cla24_or45 >> 0) & 0x01) & ((u_cla24_pg_logic20_or0 >> 0) & 0x01);
  u_cla24_or46 = ((u_cla24_pg_logic20_and0 >> 0) & 0x01) | ((u_cla24_and92 >> 0) & 0x01);
  u_cla24_pg_logic21_or0 = ((a >> 21) & 0x01) | ((b >> 21) & 0x01);
  u_cla24_pg_logic21_and0 = ((a >> 21) & 0x01) & ((b >> 21) & 0x01);
  u_cla24_pg_logic21_xor0 = ((a >> 21) & 0x01) ^ ((b >> 21) & 0x01);
  u_cla24_xor21 = ((u_cla24_pg_logic21_xor0 >> 0) & 0x01) ^ ((u_cla24_or46 >> 0) & 0x01);
  u_cla24_and93 = ((u_cla24_or45 >> 0) & 0x01) & ((u_cla24_pg_logic21_or0 >> 0) & 0x01);
  u_cla24_and94 = ((u_cla24_and93 >> 0) & 0x01) & ((u_cla24_pg_logic20_or0 >> 0) & 0x01);
  u_cla24_and95 = ((u_cla24_pg_logic20_and0 >> 0) & 0x01) & ((u_cla24_pg_logic21_or0 >> 0) & 0x01);
  u_cla24_or47 = ((u_cla24_and94 >> 0) & 0x01) | ((u_cla24_and95 >> 0) & 0x01);
  u_cla24_or48 = ((u_cla24_pg_logic21_and0 >> 0) & 0x01) | ((u_cla24_or47 >> 0) & 0x01);
  u_cla24_pg_logic22_or0 = ((a >> 22) & 0x01) | ((b >> 22) & 0x01);
  u_cla24_pg_logic22_and0 = ((a >> 22) & 0x01) & ((b >> 22) & 0x01);
  u_cla24_pg_logic22_xor0 = ((a >> 22) & 0x01) ^ ((b >> 22) & 0x01);
  u_cla24_xor22 = ((u_cla24_pg_logic22_xor0 >> 0) & 0x01) ^ ((u_cla24_or48 >> 0) & 0x01);
  u_cla24_and96 = ((u_cla24_or45 >> 0) & 0x01) & ((u_cla24_pg_logic21_or0 >> 0) & 0x01);
  u_cla24_and97 = ((u_cla24_pg_logic22_or0 >> 0) & 0x01) & ((u_cla24_pg_logic20_or0 >> 0) & 0x01);
  u_cla24_and98 = ((u_cla24_and96 >> 0) & 0x01) & ((u_cla24_and97 >> 0) & 0x01);
  u_cla24_and99 = ((u_cla24_pg_logic20_and0 >> 0) & 0x01) & ((u_cla24_pg_logic22_or0 >> 0) & 0x01);
  u_cla24_and100 = ((u_cla24_and99 >> 0) & 0x01) & ((u_cla24_pg_logic21_or0 >> 0) & 0x01);
  u_cla24_and101 = ((u_cla24_pg_logic21_and0 >> 0) & 0x01) & ((u_cla24_pg_logic22_or0 >> 0) & 0x01);
  u_cla24_or49 = ((u_cla24_and98 >> 0) & 0x01) | ((u_cla24_and100 >> 0) & 0x01);
  u_cla24_or50 = ((u_cla24_or49 >> 0) & 0x01) | ((u_cla24_and101 >> 0) & 0x01);
  u_cla24_or51 = ((u_cla24_pg_logic22_and0 >> 0) & 0x01) | ((u_cla24_or50 >> 0) & 0x01);
  u_cla24_pg_logic23_or0 = ((a >> 23) & 0x01) | ((b >> 23) & 0x01);
  u_cla24_pg_logic23_and0 = ((a >> 23) & 0x01) & ((b >> 23) & 0x01);
  u_cla24_pg_logic23_xor0 = ((a >> 23) & 0x01) ^ ((b >> 23) & 0x01);
  u_cla24_xor23 = ((u_cla24_pg_logic23_xor0 >> 0) & 0x01) ^ ((u_cla24_or51 >> 0) & 0x01);
  u_cla24_and102 = ((u_cla24_or45 >> 0) & 0x01) & ((u_cla24_pg_logic22_or0 >> 0) & 0x01);
  u_cla24_and103 = ((u_cla24_pg_logic23_or0 >> 0) & 0x01) & ((u_cla24_pg_logic21_or0 >> 0) & 0x01);
  u_cla24_and104 = ((u_cla24_and102 >> 0) & 0x01) & ((u_cla24_and103 >> 0) & 0x01);
  u_cla24_and105 = ((u_cla24_and104 >> 0) & 0x01) & ((u_cla24_pg_logic20_or0 >> 0) & 0x01);
  u_cla24_and106 = ((u_cla24_pg_logic20_and0 >> 0) & 0x01) & ((u_cla24_pg_logic22_or0 >> 0) & 0x01);
  u_cla24_and107 = ((u_cla24_pg_logic23_or0 >> 0) & 0x01) & ((u_cla24_pg_logic21_or0 >> 0) & 0x01);
  u_cla24_and108 = ((u_cla24_and106 >> 0) & 0x01) & ((u_cla24_and107 >> 0) & 0x01);
  u_cla24_and109 = ((u_cla24_pg_logic21_and0 >> 0) & 0x01) & ((u_cla24_pg_logic23_or0 >> 0) & 0x01);
  u_cla24_and110 = ((u_cla24_and109 >> 0) & 0x01) & ((u_cla24_pg_logic22_or0 >> 0) & 0x01);
  u_cla24_and111 = ((u_cla24_pg_logic22_and0 >> 0) & 0x01) & ((u_cla24_pg_logic23_or0 >> 0) & 0x01);
  u_cla24_or52 = ((u_cla24_and105 >> 0) & 0x01) | ((u_cla24_and110 >> 0) & 0x01);
  u_cla24_or53 = ((u_cla24_and108 >> 0) & 0x01) | ((u_cla24_and111 >> 0) & 0x01);
  u_cla24_or54 = ((u_cla24_or52 >> 0) & 0x01) | ((u_cla24_or53 >> 0) & 0x01);
  u_cla24_or55 = ((u_cla24_pg_logic23_and0 >> 0) & 0x01) | ((u_cla24_or54 >> 0) & 0x01);

  u_cla24_out |= ((u_cla24_pg_logic0_xor0 >> 0) & 0x01ull) << 0;
  u_cla24_out |= ((u_cla24_xor1 >> 0) & 0x01ull) << 1;
  u_cla24_out |= ((u_cla24_xor2 >> 0) & 0x01ull) << 2;
  u_cla24_out |= ((u_cla24_xor3 >> 0) & 0x01ull) << 3;
  u_cla24_out |= ((u_cla24_xor4 >> 0) & 0x01ull) << 4;
  u_cla24_out |= ((u_cla24_xor5 >> 0) & 0x01ull) << 5;
  u_cla24_out |= ((u_cla24_xor6 >> 0) & 0x01ull) << 6;
  u_cla24_out |= ((u_cla24_xor7 >> 0) & 0x01ull) << 7;
  u_cla24_out |= ((u_cla24_xor8 >> 0) & 0x01ull) << 8;
  u_cla24_out |= ((u_cla24_xor9 >> 0) & 0x01ull) << 9;
  u_cla24_out |= ((u_cla24_xor10 >> 0) & 0x01ull) << 10;
  u_cla24_out |= ((u_cla24_xor11 >> 0) & 0x01ull) << 11;
  u_cla24_out |= ((u_cla24_xor12 >> 0) & 0x01ull) << 12;
  u_cla24_out |= ((u_cla24_xor13 >> 0) & 0x01ull) << 13;
  u_cla24_out |= ((u_cla24_xor14 >> 0) & 0x01ull) << 14;
  u_cla24_out |= ((u_cla24_xor15 >> 0) & 0x01ull) << 15;
  u_cla24_out |= ((u_cla24_xor16 >> 0) & 0x01ull) << 16;
  u_cla24_out |= ((u_cla24_xor17 >> 0) & 0x01ull) << 17;
  u_cla24_out |= ((u_cla24_xor18 >> 0) & 0x01ull) << 18;
  u_cla24_out |= ((u_cla24_xor19 >> 0) & 0x01ull) << 19;
  u_cla24_out |= ((u_cla24_xor20 >> 0) & 0x01ull) << 20;
  u_cla24_out |= ((u_cla24_xor21 >> 0) & 0x01ull) << 21;
  u_cla24_out |= ((u_cla24_xor22 >> 0) & 0x01ull) << 22;
  u_cla24_out |= ((u_cla24_xor23 >> 0) & 0x01ull) << 23;
  u_cla24_out |= ((u_cla24_or55 >> 0) & 0x01ull) << 24;
  return u_cla24_out;
}