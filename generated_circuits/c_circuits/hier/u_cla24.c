#include <stdio.h>
#include <stdint.h>

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t pg_logic(uint8_t a, uint8_t b){
  uint8_t pg_logic_out = 0;
  uint8_t pg_logic_or0 = 0;
  uint8_t pg_logic_and0 = 0;
  uint8_t pg_logic_xor0 = 0;

  pg_logic_or0 = or_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  pg_logic_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  pg_logic_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));

  pg_logic_out |= ((pg_logic_or0 >> 0) & 0x01ull) << 0;
  pg_logic_out |= ((pg_logic_and0 >> 0) & 0x01ull) << 1;
  pg_logic_out |= ((pg_logic_xor0 >> 0) & 0x01ull) << 2;
  return pg_logic_out;
}

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

  u_cla24_pg_logic0_or0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic0_and0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic0_xor0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 2) & 0x01;
  u_cla24_pg_logic1_or0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic1_and0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic1_xor0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 2) & 0x01;
  u_cla24_xor1 = xor_gate(((u_cla24_pg_logic1_xor0 >> 0) & 0x01), ((u_cla24_pg_logic0_and0 >> 0) & 0x01));
  u_cla24_and0 = and_gate(((u_cla24_pg_logic0_and0 >> 0) & 0x01), ((u_cla24_pg_logic1_or0 >> 0) & 0x01));
  u_cla24_or0 = or_gate(((u_cla24_pg_logic1_and0 >> 0) & 0x01), ((u_cla24_and0 >> 0) & 0x01));
  u_cla24_pg_logic2_or0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic2_and0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic2_xor0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 2) & 0x01;
  u_cla24_xor2 = xor_gate(((u_cla24_pg_logic2_xor0 >> 0) & 0x01), ((u_cla24_or0 >> 0) & 0x01));
  u_cla24_and1 = and_gate(((u_cla24_pg_logic2_or0 >> 0) & 0x01), ((u_cla24_pg_logic0_or0 >> 0) & 0x01));
  u_cla24_and2 = and_gate(((u_cla24_pg_logic0_and0 >> 0) & 0x01), ((u_cla24_pg_logic2_or0 >> 0) & 0x01));
  u_cla24_and3 = and_gate(((u_cla24_and2 >> 0) & 0x01), ((u_cla24_pg_logic1_or0 >> 0) & 0x01));
  u_cla24_and4 = and_gate(((u_cla24_pg_logic1_and0 >> 0) & 0x01), ((u_cla24_pg_logic2_or0 >> 0) & 0x01));
  u_cla24_or1 = or_gate(((u_cla24_and3 >> 0) & 0x01), ((u_cla24_and4 >> 0) & 0x01));
  u_cla24_or2 = or_gate(((u_cla24_pg_logic2_and0 >> 0) & 0x01), ((u_cla24_or1 >> 0) & 0x01));
  u_cla24_pg_logic3_or0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic3_and0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic3_xor0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 2) & 0x01;
  u_cla24_xor3 = xor_gate(((u_cla24_pg_logic3_xor0 >> 0) & 0x01), ((u_cla24_or2 >> 0) & 0x01));
  u_cla24_and5 = and_gate(((u_cla24_pg_logic3_or0 >> 0) & 0x01), ((u_cla24_pg_logic1_or0 >> 0) & 0x01));
  u_cla24_and6 = and_gate(((u_cla24_pg_logic0_and0 >> 0) & 0x01), ((u_cla24_pg_logic2_or0 >> 0) & 0x01));
  u_cla24_and7 = and_gate(((u_cla24_pg_logic3_or0 >> 0) & 0x01), ((u_cla24_pg_logic1_or0 >> 0) & 0x01));
  u_cla24_and8 = and_gate(((u_cla24_and6 >> 0) & 0x01), ((u_cla24_and7 >> 0) & 0x01));
  u_cla24_and9 = and_gate(((u_cla24_pg_logic1_and0 >> 0) & 0x01), ((u_cla24_pg_logic3_or0 >> 0) & 0x01));
  u_cla24_and10 = and_gate(((u_cla24_and9 >> 0) & 0x01), ((u_cla24_pg_logic2_or0 >> 0) & 0x01));
  u_cla24_and11 = and_gate(((u_cla24_pg_logic2_and0 >> 0) & 0x01), ((u_cla24_pg_logic3_or0 >> 0) & 0x01));
  u_cla24_or3 = or_gate(((u_cla24_and8 >> 0) & 0x01), ((u_cla24_and11 >> 0) & 0x01));
  u_cla24_or4 = or_gate(((u_cla24_and10 >> 0) & 0x01), ((u_cla24_or3 >> 0) & 0x01));
  u_cla24_or5 = or_gate(((u_cla24_pg_logic3_and0 >> 0) & 0x01), ((u_cla24_or4 >> 0) & 0x01));
  u_cla24_pg_logic4_or0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic4_and0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic4_xor0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 2) & 0x01;
  u_cla24_xor4 = xor_gate(((u_cla24_pg_logic4_xor0 >> 0) & 0x01), ((u_cla24_or5 >> 0) & 0x01));
  u_cla24_and12 = and_gate(((u_cla24_or5 >> 0) & 0x01), ((u_cla24_pg_logic4_or0 >> 0) & 0x01));
  u_cla24_or6 = or_gate(((u_cla24_pg_logic4_and0 >> 0) & 0x01), ((u_cla24_and12 >> 0) & 0x01));
  u_cla24_pg_logic5_or0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic5_and0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic5_xor0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 2) & 0x01;
  u_cla24_xor5 = xor_gate(((u_cla24_pg_logic5_xor0 >> 0) & 0x01), ((u_cla24_or6 >> 0) & 0x01));
  u_cla24_and13 = and_gate(((u_cla24_or5 >> 0) & 0x01), ((u_cla24_pg_logic5_or0 >> 0) & 0x01));
  u_cla24_and14 = and_gate(((u_cla24_and13 >> 0) & 0x01), ((u_cla24_pg_logic4_or0 >> 0) & 0x01));
  u_cla24_and15 = and_gate(((u_cla24_pg_logic4_and0 >> 0) & 0x01), ((u_cla24_pg_logic5_or0 >> 0) & 0x01));
  u_cla24_or7 = or_gate(((u_cla24_and14 >> 0) & 0x01), ((u_cla24_and15 >> 0) & 0x01));
  u_cla24_or8 = or_gate(((u_cla24_pg_logic5_and0 >> 0) & 0x01), ((u_cla24_or7 >> 0) & 0x01));
  u_cla24_pg_logic6_or0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic6_and0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic6_xor0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 2) & 0x01;
  u_cla24_xor6 = xor_gate(((u_cla24_pg_logic6_xor0 >> 0) & 0x01), ((u_cla24_or8 >> 0) & 0x01));
  u_cla24_and16 = and_gate(((u_cla24_or5 >> 0) & 0x01), ((u_cla24_pg_logic5_or0 >> 0) & 0x01));
  u_cla24_and17 = and_gate(((u_cla24_pg_logic6_or0 >> 0) & 0x01), ((u_cla24_pg_logic4_or0 >> 0) & 0x01));
  u_cla24_and18 = and_gate(((u_cla24_and16 >> 0) & 0x01), ((u_cla24_and17 >> 0) & 0x01));
  u_cla24_and19 = and_gate(((u_cla24_pg_logic4_and0 >> 0) & 0x01), ((u_cla24_pg_logic6_or0 >> 0) & 0x01));
  u_cla24_and20 = and_gate(((u_cla24_and19 >> 0) & 0x01), ((u_cla24_pg_logic5_or0 >> 0) & 0x01));
  u_cla24_and21 = and_gate(((u_cla24_pg_logic5_and0 >> 0) & 0x01), ((u_cla24_pg_logic6_or0 >> 0) & 0x01));
  u_cla24_or9 = or_gate(((u_cla24_and18 >> 0) & 0x01), ((u_cla24_and20 >> 0) & 0x01));
  u_cla24_or10 = or_gate(((u_cla24_or9 >> 0) & 0x01), ((u_cla24_and21 >> 0) & 0x01));
  u_cla24_or11 = or_gate(((u_cla24_pg_logic6_and0 >> 0) & 0x01), ((u_cla24_or10 >> 0) & 0x01));
  u_cla24_pg_logic7_or0 = (pg_logic(((a >> 7) & 0x01), ((b >> 7) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic7_and0 = (pg_logic(((a >> 7) & 0x01), ((b >> 7) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic7_xor0 = (pg_logic(((a >> 7) & 0x01), ((b >> 7) & 0x01)) >> 2) & 0x01;
  u_cla24_xor7 = xor_gate(((u_cla24_pg_logic7_xor0 >> 0) & 0x01), ((u_cla24_or11 >> 0) & 0x01));
  u_cla24_and22 = and_gate(((u_cla24_or5 >> 0) & 0x01), ((u_cla24_pg_logic6_or0 >> 0) & 0x01));
  u_cla24_and23 = and_gate(((u_cla24_pg_logic7_or0 >> 0) & 0x01), ((u_cla24_pg_logic5_or0 >> 0) & 0x01));
  u_cla24_and24 = and_gate(((u_cla24_and22 >> 0) & 0x01), ((u_cla24_and23 >> 0) & 0x01));
  u_cla24_and25 = and_gate(((u_cla24_and24 >> 0) & 0x01), ((u_cla24_pg_logic4_or0 >> 0) & 0x01));
  u_cla24_and26 = and_gate(((u_cla24_pg_logic4_and0 >> 0) & 0x01), ((u_cla24_pg_logic6_or0 >> 0) & 0x01));
  u_cla24_and27 = and_gate(((u_cla24_pg_logic7_or0 >> 0) & 0x01), ((u_cla24_pg_logic5_or0 >> 0) & 0x01));
  u_cla24_and28 = and_gate(((u_cla24_and26 >> 0) & 0x01), ((u_cla24_and27 >> 0) & 0x01));
  u_cla24_and29 = and_gate(((u_cla24_pg_logic5_and0 >> 0) & 0x01), ((u_cla24_pg_logic7_or0 >> 0) & 0x01));
  u_cla24_and30 = and_gate(((u_cla24_and29 >> 0) & 0x01), ((u_cla24_pg_logic6_or0 >> 0) & 0x01));
  u_cla24_and31 = and_gate(((u_cla24_pg_logic6_and0 >> 0) & 0x01), ((u_cla24_pg_logic7_or0 >> 0) & 0x01));
  u_cla24_or12 = or_gate(((u_cla24_and25 >> 0) & 0x01), ((u_cla24_and30 >> 0) & 0x01));
  u_cla24_or13 = or_gate(((u_cla24_and28 >> 0) & 0x01), ((u_cla24_and31 >> 0) & 0x01));
  u_cla24_or14 = or_gate(((u_cla24_or12 >> 0) & 0x01), ((u_cla24_or13 >> 0) & 0x01));
  u_cla24_or15 = or_gate(((u_cla24_pg_logic7_and0 >> 0) & 0x01), ((u_cla24_or14 >> 0) & 0x01));
  u_cla24_pg_logic8_or0 = (pg_logic(((a >> 8) & 0x01), ((b >> 8) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic8_and0 = (pg_logic(((a >> 8) & 0x01), ((b >> 8) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic8_xor0 = (pg_logic(((a >> 8) & 0x01), ((b >> 8) & 0x01)) >> 2) & 0x01;
  u_cla24_xor8 = xor_gate(((u_cla24_pg_logic8_xor0 >> 0) & 0x01), ((u_cla24_or15 >> 0) & 0x01));
  u_cla24_and32 = and_gate(((u_cla24_or15 >> 0) & 0x01), ((u_cla24_pg_logic8_or0 >> 0) & 0x01));
  u_cla24_or16 = or_gate(((u_cla24_pg_logic8_and0 >> 0) & 0x01), ((u_cla24_and32 >> 0) & 0x01));
  u_cla24_pg_logic9_or0 = (pg_logic(((a >> 9) & 0x01), ((b >> 9) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic9_and0 = (pg_logic(((a >> 9) & 0x01), ((b >> 9) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic9_xor0 = (pg_logic(((a >> 9) & 0x01), ((b >> 9) & 0x01)) >> 2) & 0x01;
  u_cla24_xor9 = xor_gate(((u_cla24_pg_logic9_xor0 >> 0) & 0x01), ((u_cla24_or16 >> 0) & 0x01));
  u_cla24_and33 = and_gate(((u_cla24_or15 >> 0) & 0x01), ((u_cla24_pg_logic9_or0 >> 0) & 0x01));
  u_cla24_and34 = and_gate(((u_cla24_and33 >> 0) & 0x01), ((u_cla24_pg_logic8_or0 >> 0) & 0x01));
  u_cla24_and35 = and_gate(((u_cla24_pg_logic8_and0 >> 0) & 0x01), ((u_cla24_pg_logic9_or0 >> 0) & 0x01));
  u_cla24_or17 = or_gate(((u_cla24_and34 >> 0) & 0x01), ((u_cla24_and35 >> 0) & 0x01));
  u_cla24_or18 = or_gate(((u_cla24_pg_logic9_and0 >> 0) & 0x01), ((u_cla24_or17 >> 0) & 0x01));
  u_cla24_pg_logic10_or0 = (pg_logic(((a >> 10) & 0x01), ((b >> 10) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic10_and0 = (pg_logic(((a >> 10) & 0x01), ((b >> 10) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic10_xor0 = (pg_logic(((a >> 10) & 0x01), ((b >> 10) & 0x01)) >> 2) & 0x01;
  u_cla24_xor10 = xor_gate(((u_cla24_pg_logic10_xor0 >> 0) & 0x01), ((u_cla24_or18 >> 0) & 0x01));
  u_cla24_and36 = and_gate(((u_cla24_or15 >> 0) & 0x01), ((u_cla24_pg_logic9_or0 >> 0) & 0x01));
  u_cla24_and37 = and_gate(((u_cla24_pg_logic10_or0 >> 0) & 0x01), ((u_cla24_pg_logic8_or0 >> 0) & 0x01));
  u_cla24_and38 = and_gate(((u_cla24_and36 >> 0) & 0x01), ((u_cla24_and37 >> 0) & 0x01));
  u_cla24_and39 = and_gate(((u_cla24_pg_logic8_and0 >> 0) & 0x01), ((u_cla24_pg_logic10_or0 >> 0) & 0x01));
  u_cla24_and40 = and_gate(((u_cla24_and39 >> 0) & 0x01), ((u_cla24_pg_logic9_or0 >> 0) & 0x01));
  u_cla24_and41 = and_gate(((u_cla24_pg_logic9_and0 >> 0) & 0x01), ((u_cla24_pg_logic10_or0 >> 0) & 0x01));
  u_cla24_or19 = or_gate(((u_cla24_and38 >> 0) & 0x01), ((u_cla24_and40 >> 0) & 0x01));
  u_cla24_or20 = or_gate(((u_cla24_or19 >> 0) & 0x01), ((u_cla24_and41 >> 0) & 0x01));
  u_cla24_or21 = or_gate(((u_cla24_pg_logic10_and0 >> 0) & 0x01), ((u_cla24_or20 >> 0) & 0x01));
  u_cla24_pg_logic11_or0 = (pg_logic(((a >> 11) & 0x01), ((b >> 11) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic11_and0 = (pg_logic(((a >> 11) & 0x01), ((b >> 11) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic11_xor0 = (pg_logic(((a >> 11) & 0x01), ((b >> 11) & 0x01)) >> 2) & 0x01;
  u_cla24_xor11 = xor_gate(((u_cla24_pg_logic11_xor0 >> 0) & 0x01), ((u_cla24_or21 >> 0) & 0x01));
  u_cla24_and42 = and_gate(((u_cla24_or15 >> 0) & 0x01), ((u_cla24_pg_logic10_or0 >> 0) & 0x01));
  u_cla24_and43 = and_gate(((u_cla24_pg_logic11_or0 >> 0) & 0x01), ((u_cla24_pg_logic9_or0 >> 0) & 0x01));
  u_cla24_and44 = and_gate(((u_cla24_and42 >> 0) & 0x01), ((u_cla24_and43 >> 0) & 0x01));
  u_cla24_and45 = and_gate(((u_cla24_and44 >> 0) & 0x01), ((u_cla24_pg_logic8_or0 >> 0) & 0x01));
  u_cla24_and46 = and_gate(((u_cla24_pg_logic8_and0 >> 0) & 0x01), ((u_cla24_pg_logic10_or0 >> 0) & 0x01));
  u_cla24_and47 = and_gate(((u_cla24_pg_logic11_or0 >> 0) & 0x01), ((u_cla24_pg_logic9_or0 >> 0) & 0x01));
  u_cla24_and48 = and_gate(((u_cla24_and46 >> 0) & 0x01), ((u_cla24_and47 >> 0) & 0x01));
  u_cla24_and49 = and_gate(((u_cla24_pg_logic9_and0 >> 0) & 0x01), ((u_cla24_pg_logic11_or0 >> 0) & 0x01));
  u_cla24_and50 = and_gate(((u_cla24_and49 >> 0) & 0x01), ((u_cla24_pg_logic10_or0 >> 0) & 0x01));
  u_cla24_and51 = and_gate(((u_cla24_pg_logic10_and0 >> 0) & 0x01), ((u_cla24_pg_logic11_or0 >> 0) & 0x01));
  u_cla24_or22 = or_gate(((u_cla24_and45 >> 0) & 0x01), ((u_cla24_and50 >> 0) & 0x01));
  u_cla24_or23 = or_gate(((u_cla24_and48 >> 0) & 0x01), ((u_cla24_and51 >> 0) & 0x01));
  u_cla24_or24 = or_gate(((u_cla24_or22 >> 0) & 0x01), ((u_cla24_or23 >> 0) & 0x01));
  u_cla24_or25 = or_gate(((u_cla24_pg_logic11_and0 >> 0) & 0x01), ((u_cla24_or24 >> 0) & 0x01));
  u_cla24_pg_logic12_or0 = (pg_logic(((a >> 12) & 0x01), ((b >> 12) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic12_and0 = (pg_logic(((a >> 12) & 0x01), ((b >> 12) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic12_xor0 = (pg_logic(((a >> 12) & 0x01), ((b >> 12) & 0x01)) >> 2) & 0x01;
  u_cla24_xor12 = xor_gate(((u_cla24_pg_logic12_xor0 >> 0) & 0x01), ((u_cla24_or25 >> 0) & 0x01));
  u_cla24_and52 = and_gate(((u_cla24_or25 >> 0) & 0x01), ((u_cla24_pg_logic12_or0 >> 0) & 0x01));
  u_cla24_or26 = or_gate(((u_cla24_pg_logic12_and0 >> 0) & 0x01), ((u_cla24_and52 >> 0) & 0x01));
  u_cla24_pg_logic13_or0 = (pg_logic(((a >> 13) & 0x01), ((b >> 13) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic13_and0 = (pg_logic(((a >> 13) & 0x01), ((b >> 13) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic13_xor0 = (pg_logic(((a >> 13) & 0x01), ((b >> 13) & 0x01)) >> 2) & 0x01;
  u_cla24_xor13 = xor_gate(((u_cla24_pg_logic13_xor0 >> 0) & 0x01), ((u_cla24_or26 >> 0) & 0x01));
  u_cla24_and53 = and_gate(((u_cla24_or25 >> 0) & 0x01), ((u_cla24_pg_logic13_or0 >> 0) & 0x01));
  u_cla24_and54 = and_gate(((u_cla24_and53 >> 0) & 0x01), ((u_cla24_pg_logic12_or0 >> 0) & 0x01));
  u_cla24_and55 = and_gate(((u_cla24_pg_logic12_and0 >> 0) & 0x01), ((u_cla24_pg_logic13_or0 >> 0) & 0x01));
  u_cla24_or27 = or_gate(((u_cla24_and54 >> 0) & 0x01), ((u_cla24_and55 >> 0) & 0x01));
  u_cla24_or28 = or_gate(((u_cla24_pg_logic13_and0 >> 0) & 0x01), ((u_cla24_or27 >> 0) & 0x01));
  u_cla24_pg_logic14_or0 = (pg_logic(((a >> 14) & 0x01), ((b >> 14) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic14_and0 = (pg_logic(((a >> 14) & 0x01), ((b >> 14) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic14_xor0 = (pg_logic(((a >> 14) & 0x01), ((b >> 14) & 0x01)) >> 2) & 0x01;
  u_cla24_xor14 = xor_gate(((u_cla24_pg_logic14_xor0 >> 0) & 0x01), ((u_cla24_or28 >> 0) & 0x01));
  u_cla24_and56 = and_gate(((u_cla24_or25 >> 0) & 0x01), ((u_cla24_pg_logic13_or0 >> 0) & 0x01));
  u_cla24_and57 = and_gate(((u_cla24_pg_logic14_or0 >> 0) & 0x01), ((u_cla24_pg_logic12_or0 >> 0) & 0x01));
  u_cla24_and58 = and_gate(((u_cla24_and56 >> 0) & 0x01), ((u_cla24_and57 >> 0) & 0x01));
  u_cla24_and59 = and_gate(((u_cla24_pg_logic12_and0 >> 0) & 0x01), ((u_cla24_pg_logic14_or0 >> 0) & 0x01));
  u_cla24_and60 = and_gate(((u_cla24_and59 >> 0) & 0x01), ((u_cla24_pg_logic13_or0 >> 0) & 0x01));
  u_cla24_and61 = and_gate(((u_cla24_pg_logic13_and0 >> 0) & 0x01), ((u_cla24_pg_logic14_or0 >> 0) & 0x01));
  u_cla24_or29 = or_gate(((u_cla24_and58 >> 0) & 0x01), ((u_cla24_and60 >> 0) & 0x01));
  u_cla24_or30 = or_gate(((u_cla24_or29 >> 0) & 0x01), ((u_cla24_and61 >> 0) & 0x01));
  u_cla24_or31 = or_gate(((u_cla24_pg_logic14_and0 >> 0) & 0x01), ((u_cla24_or30 >> 0) & 0x01));
  u_cla24_pg_logic15_or0 = (pg_logic(((a >> 15) & 0x01), ((b >> 15) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic15_and0 = (pg_logic(((a >> 15) & 0x01), ((b >> 15) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic15_xor0 = (pg_logic(((a >> 15) & 0x01), ((b >> 15) & 0x01)) >> 2) & 0x01;
  u_cla24_xor15 = xor_gate(((u_cla24_pg_logic15_xor0 >> 0) & 0x01), ((u_cla24_or31 >> 0) & 0x01));
  u_cla24_and62 = and_gate(((u_cla24_or25 >> 0) & 0x01), ((u_cla24_pg_logic14_or0 >> 0) & 0x01));
  u_cla24_and63 = and_gate(((u_cla24_pg_logic15_or0 >> 0) & 0x01), ((u_cla24_pg_logic13_or0 >> 0) & 0x01));
  u_cla24_and64 = and_gate(((u_cla24_and62 >> 0) & 0x01), ((u_cla24_and63 >> 0) & 0x01));
  u_cla24_and65 = and_gate(((u_cla24_and64 >> 0) & 0x01), ((u_cla24_pg_logic12_or0 >> 0) & 0x01));
  u_cla24_and66 = and_gate(((u_cla24_pg_logic12_and0 >> 0) & 0x01), ((u_cla24_pg_logic14_or0 >> 0) & 0x01));
  u_cla24_and67 = and_gate(((u_cla24_pg_logic15_or0 >> 0) & 0x01), ((u_cla24_pg_logic13_or0 >> 0) & 0x01));
  u_cla24_and68 = and_gate(((u_cla24_and66 >> 0) & 0x01), ((u_cla24_and67 >> 0) & 0x01));
  u_cla24_and69 = and_gate(((u_cla24_pg_logic13_and0 >> 0) & 0x01), ((u_cla24_pg_logic15_or0 >> 0) & 0x01));
  u_cla24_and70 = and_gate(((u_cla24_and69 >> 0) & 0x01), ((u_cla24_pg_logic14_or0 >> 0) & 0x01));
  u_cla24_and71 = and_gate(((u_cla24_pg_logic14_and0 >> 0) & 0x01), ((u_cla24_pg_logic15_or0 >> 0) & 0x01));
  u_cla24_or32 = or_gate(((u_cla24_and65 >> 0) & 0x01), ((u_cla24_and70 >> 0) & 0x01));
  u_cla24_or33 = or_gate(((u_cla24_and68 >> 0) & 0x01), ((u_cla24_and71 >> 0) & 0x01));
  u_cla24_or34 = or_gate(((u_cla24_or32 >> 0) & 0x01), ((u_cla24_or33 >> 0) & 0x01));
  u_cla24_or35 = or_gate(((u_cla24_pg_logic15_and0 >> 0) & 0x01), ((u_cla24_or34 >> 0) & 0x01));
  u_cla24_pg_logic16_or0 = (pg_logic(((a >> 16) & 0x01), ((b >> 16) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic16_and0 = (pg_logic(((a >> 16) & 0x01), ((b >> 16) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic16_xor0 = (pg_logic(((a >> 16) & 0x01), ((b >> 16) & 0x01)) >> 2) & 0x01;
  u_cla24_xor16 = xor_gate(((u_cla24_pg_logic16_xor0 >> 0) & 0x01), ((u_cla24_or35 >> 0) & 0x01));
  u_cla24_and72 = and_gate(((u_cla24_or35 >> 0) & 0x01), ((u_cla24_pg_logic16_or0 >> 0) & 0x01));
  u_cla24_or36 = or_gate(((u_cla24_pg_logic16_and0 >> 0) & 0x01), ((u_cla24_and72 >> 0) & 0x01));
  u_cla24_pg_logic17_or0 = (pg_logic(((a >> 17) & 0x01), ((b >> 17) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic17_and0 = (pg_logic(((a >> 17) & 0x01), ((b >> 17) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic17_xor0 = (pg_logic(((a >> 17) & 0x01), ((b >> 17) & 0x01)) >> 2) & 0x01;
  u_cla24_xor17 = xor_gate(((u_cla24_pg_logic17_xor0 >> 0) & 0x01), ((u_cla24_or36 >> 0) & 0x01));
  u_cla24_and73 = and_gate(((u_cla24_or35 >> 0) & 0x01), ((u_cla24_pg_logic17_or0 >> 0) & 0x01));
  u_cla24_and74 = and_gate(((u_cla24_and73 >> 0) & 0x01), ((u_cla24_pg_logic16_or0 >> 0) & 0x01));
  u_cla24_and75 = and_gate(((u_cla24_pg_logic16_and0 >> 0) & 0x01), ((u_cla24_pg_logic17_or0 >> 0) & 0x01));
  u_cla24_or37 = or_gate(((u_cla24_and74 >> 0) & 0x01), ((u_cla24_and75 >> 0) & 0x01));
  u_cla24_or38 = or_gate(((u_cla24_pg_logic17_and0 >> 0) & 0x01), ((u_cla24_or37 >> 0) & 0x01));
  u_cla24_pg_logic18_or0 = (pg_logic(((a >> 18) & 0x01), ((b >> 18) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic18_and0 = (pg_logic(((a >> 18) & 0x01), ((b >> 18) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic18_xor0 = (pg_logic(((a >> 18) & 0x01), ((b >> 18) & 0x01)) >> 2) & 0x01;
  u_cla24_xor18 = xor_gate(((u_cla24_pg_logic18_xor0 >> 0) & 0x01), ((u_cla24_or38 >> 0) & 0x01));
  u_cla24_and76 = and_gate(((u_cla24_or35 >> 0) & 0x01), ((u_cla24_pg_logic17_or0 >> 0) & 0x01));
  u_cla24_and77 = and_gate(((u_cla24_pg_logic18_or0 >> 0) & 0x01), ((u_cla24_pg_logic16_or0 >> 0) & 0x01));
  u_cla24_and78 = and_gate(((u_cla24_and76 >> 0) & 0x01), ((u_cla24_and77 >> 0) & 0x01));
  u_cla24_and79 = and_gate(((u_cla24_pg_logic16_and0 >> 0) & 0x01), ((u_cla24_pg_logic18_or0 >> 0) & 0x01));
  u_cla24_and80 = and_gate(((u_cla24_and79 >> 0) & 0x01), ((u_cla24_pg_logic17_or0 >> 0) & 0x01));
  u_cla24_and81 = and_gate(((u_cla24_pg_logic17_and0 >> 0) & 0x01), ((u_cla24_pg_logic18_or0 >> 0) & 0x01));
  u_cla24_or39 = or_gate(((u_cla24_and78 >> 0) & 0x01), ((u_cla24_and80 >> 0) & 0x01));
  u_cla24_or40 = or_gate(((u_cla24_or39 >> 0) & 0x01), ((u_cla24_and81 >> 0) & 0x01));
  u_cla24_or41 = or_gate(((u_cla24_pg_logic18_and0 >> 0) & 0x01), ((u_cla24_or40 >> 0) & 0x01));
  u_cla24_pg_logic19_or0 = (pg_logic(((a >> 19) & 0x01), ((b >> 19) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic19_and0 = (pg_logic(((a >> 19) & 0x01), ((b >> 19) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic19_xor0 = (pg_logic(((a >> 19) & 0x01), ((b >> 19) & 0x01)) >> 2) & 0x01;
  u_cla24_xor19 = xor_gate(((u_cla24_pg_logic19_xor0 >> 0) & 0x01), ((u_cla24_or41 >> 0) & 0x01));
  u_cla24_and82 = and_gate(((u_cla24_or35 >> 0) & 0x01), ((u_cla24_pg_logic18_or0 >> 0) & 0x01));
  u_cla24_and83 = and_gate(((u_cla24_pg_logic19_or0 >> 0) & 0x01), ((u_cla24_pg_logic17_or0 >> 0) & 0x01));
  u_cla24_and84 = and_gate(((u_cla24_and82 >> 0) & 0x01), ((u_cla24_and83 >> 0) & 0x01));
  u_cla24_and85 = and_gate(((u_cla24_and84 >> 0) & 0x01), ((u_cla24_pg_logic16_or0 >> 0) & 0x01));
  u_cla24_and86 = and_gate(((u_cla24_pg_logic16_and0 >> 0) & 0x01), ((u_cla24_pg_logic18_or0 >> 0) & 0x01));
  u_cla24_and87 = and_gate(((u_cla24_pg_logic19_or0 >> 0) & 0x01), ((u_cla24_pg_logic17_or0 >> 0) & 0x01));
  u_cla24_and88 = and_gate(((u_cla24_and86 >> 0) & 0x01), ((u_cla24_and87 >> 0) & 0x01));
  u_cla24_and89 = and_gate(((u_cla24_pg_logic17_and0 >> 0) & 0x01), ((u_cla24_pg_logic19_or0 >> 0) & 0x01));
  u_cla24_and90 = and_gate(((u_cla24_and89 >> 0) & 0x01), ((u_cla24_pg_logic18_or0 >> 0) & 0x01));
  u_cla24_and91 = and_gate(((u_cla24_pg_logic18_and0 >> 0) & 0x01), ((u_cla24_pg_logic19_or0 >> 0) & 0x01));
  u_cla24_or42 = or_gate(((u_cla24_and85 >> 0) & 0x01), ((u_cla24_and90 >> 0) & 0x01));
  u_cla24_or43 = or_gate(((u_cla24_and88 >> 0) & 0x01), ((u_cla24_and91 >> 0) & 0x01));
  u_cla24_or44 = or_gate(((u_cla24_or42 >> 0) & 0x01), ((u_cla24_or43 >> 0) & 0x01));
  u_cla24_or45 = or_gate(((u_cla24_pg_logic19_and0 >> 0) & 0x01), ((u_cla24_or44 >> 0) & 0x01));
  u_cla24_pg_logic20_or0 = (pg_logic(((a >> 20) & 0x01), ((b >> 20) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic20_and0 = (pg_logic(((a >> 20) & 0x01), ((b >> 20) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic20_xor0 = (pg_logic(((a >> 20) & 0x01), ((b >> 20) & 0x01)) >> 2) & 0x01;
  u_cla24_xor20 = xor_gate(((u_cla24_pg_logic20_xor0 >> 0) & 0x01), ((u_cla24_or45 >> 0) & 0x01));
  u_cla24_and92 = and_gate(((u_cla24_or45 >> 0) & 0x01), ((u_cla24_pg_logic20_or0 >> 0) & 0x01));
  u_cla24_or46 = or_gate(((u_cla24_pg_logic20_and0 >> 0) & 0x01), ((u_cla24_and92 >> 0) & 0x01));
  u_cla24_pg_logic21_or0 = (pg_logic(((a >> 21) & 0x01), ((b >> 21) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic21_and0 = (pg_logic(((a >> 21) & 0x01), ((b >> 21) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic21_xor0 = (pg_logic(((a >> 21) & 0x01), ((b >> 21) & 0x01)) >> 2) & 0x01;
  u_cla24_xor21 = xor_gate(((u_cla24_pg_logic21_xor0 >> 0) & 0x01), ((u_cla24_or46 >> 0) & 0x01));
  u_cla24_and93 = and_gate(((u_cla24_or45 >> 0) & 0x01), ((u_cla24_pg_logic21_or0 >> 0) & 0x01));
  u_cla24_and94 = and_gate(((u_cla24_and93 >> 0) & 0x01), ((u_cla24_pg_logic20_or0 >> 0) & 0x01));
  u_cla24_and95 = and_gate(((u_cla24_pg_logic20_and0 >> 0) & 0x01), ((u_cla24_pg_logic21_or0 >> 0) & 0x01));
  u_cla24_or47 = or_gate(((u_cla24_and94 >> 0) & 0x01), ((u_cla24_and95 >> 0) & 0x01));
  u_cla24_or48 = or_gate(((u_cla24_pg_logic21_and0 >> 0) & 0x01), ((u_cla24_or47 >> 0) & 0x01));
  u_cla24_pg_logic22_or0 = (pg_logic(((a >> 22) & 0x01), ((b >> 22) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic22_and0 = (pg_logic(((a >> 22) & 0x01), ((b >> 22) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic22_xor0 = (pg_logic(((a >> 22) & 0x01), ((b >> 22) & 0x01)) >> 2) & 0x01;
  u_cla24_xor22 = xor_gate(((u_cla24_pg_logic22_xor0 >> 0) & 0x01), ((u_cla24_or48 >> 0) & 0x01));
  u_cla24_and96 = and_gate(((u_cla24_or45 >> 0) & 0x01), ((u_cla24_pg_logic21_or0 >> 0) & 0x01));
  u_cla24_and97 = and_gate(((u_cla24_pg_logic22_or0 >> 0) & 0x01), ((u_cla24_pg_logic20_or0 >> 0) & 0x01));
  u_cla24_and98 = and_gate(((u_cla24_and96 >> 0) & 0x01), ((u_cla24_and97 >> 0) & 0x01));
  u_cla24_and99 = and_gate(((u_cla24_pg_logic20_and0 >> 0) & 0x01), ((u_cla24_pg_logic22_or0 >> 0) & 0x01));
  u_cla24_and100 = and_gate(((u_cla24_and99 >> 0) & 0x01), ((u_cla24_pg_logic21_or0 >> 0) & 0x01));
  u_cla24_and101 = and_gate(((u_cla24_pg_logic21_and0 >> 0) & 0x01), ((u_cla24_pg_logic22_or0 >> 0) & 0x01));
  u_cla24_or49 = or_gate(((u_cla24_and98 >> 0) & 0x01), ((u_cla24_and100 >> 0) & 0x01));
  u_cla24_or50 = or_gate(((u_cla24_or49 >> 0) & 0x01), ((u_cla24_and101 >> 0) & 0x01));
  u_cla24_or51 = or_gate(((u_cla24_pg_logic22_and0 >> 0) & 0x01), ((u_cla24_or50 >> 0) & 0x01));
  u_cla24_pg_logic23_or0 = (pg_logic(((a >> 23) & 0x01), ((b >> 23) & 0x01)) >> 0) & 0x01;
  u_cla24_pg_logic23_and0 = (pg_logic(((a >> 23) & 0x01), ((b >> 23) & 0x01)) >> 1) & 0x01;
  u_cla24_pg_logic23_xor0 = (pg_logic(((a >> 23) & 0x01), ((b >> 23) & 0x01)) >> 2) & 0x01;
  u_cla24_xor23 = xor_gate(((u_cla24_pg_logic23_xor0 >> 0) & 0x01), ((u_cla24_or51 >> 0) & 0x01));
  u_cla24_and102 = and_gate(((u_cla24_or45 >> 0) & 0x01), ((u_cla24_pg_logic22_or0 >> 0) & 0x01));
  u_cla24_and103 = and_gate(((u_cla24_pg_logic23_or0 >> 0) & 0x01), ((u_cla24_pg_logic21_or0 >> 0) & 0x01));
  u_cla24_and104 = and_gate(((u_cla24_and102 >> 0) & 0x01), ((u_cla24_and103 >> 0) & 0x01));
  u_cla24_and105 = and_gate(((u_cla24_and104 >> 0) & 0x01), ((u_cla24_pg_logic20_or0 >> 0) & 0x01));
  u_cla24_and106 = and_gate(((u_cla24_pg_logic20_and0 >> 0) & 0x01), ((u_cla24_pg_logic22_or0 >> 0) & 0x01));
  u_cla24_and107 = and_gate(((u_cla24_pg_logic23_or0 >> 0) & 0x01), ((u_cla24_pg_logic21_or0 >> 0) & 0x01));
  u_cla24_and108 = and_gate(((u_cla24_and106 >> 0) & 0x01), ((u_cla24_and107 >> 0) & 0x01));
  u_cla24_and109 = and_gate(((u_cla24_pg_logic21_and0 >> 0) & 0x01), ((u_cla24_pg_logic23_or0 >> 0) & 0x01));
  u_cla24_and110 = and_gate(((u_cla24_and109 >> 0) & 0x01), ((u_cla24_pg_logic22_or0 >> 0) & 0x01));
  u_cla24_and111 = and_gate(((u_cla24_pg_logic22_and0 >> 0) & 0x01), ((u_cla24_pg_logic23_or0 >> 0) & 0x01));
  u_cla24_or52 = or_gate(((u_cla24_and105 >> 0) & 0x01), ((u_cla24_and110 >> 0) & 0x01));
  u_cla24_or53 = or_gate(((u_cla24_and108 >> 0) & 0x01), ((u_cla24_and111 >> 0) & 0x01));
  u_cla24_or54 = or_gate(((u_cla24_or52 >> 0) & 0x01), ((u_cla24_or53 >> 0) & 0x01));
  u_cla24_or55 = or_gate(((u_cla24_pg_logic23_and0 >> 0) & 0x01), ((u_cla24_or54 >> 0) & 0x01));

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