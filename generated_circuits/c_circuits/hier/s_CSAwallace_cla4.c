#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t nand_gate(uint8_t a, uint8_t b){
  return ~(((a >> 0) & 0x01) & ((b >> 0) & 0x01)) & 0x01;
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
}

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t fa_out = 0;
  uint8_t fa_xor0 = 0;
  uint8_t fa_and0 = 0;
  uint8_t fa_xor1 = 0;
  uint8_t fa_and1 = 0;
  uint8_t fa_or0 = 0;

  fa_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  fa_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  fa_xor1 = xor_gate(((fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));
  fa_and1 = and_gate(((fa_xor0 >> 0) & 0x01), ((cin >> 0) & 0x01));
  fa_or0 = or_gate(((fa_and0 >> 0) & 0x01), ((fa_and1 >> 0) & 0x01));

  fa_out |= ((fa_xor1 >> 0) & 0x01ull) << 0;
  fa_out |= ((fa_or0 >> 0) & 0x01ull) << 1;
  return fa_out;
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

uint64_t csa_component6(uint64_t a, uint64_t b, uint64_t c){
  uint64_t csa_component6_out = 0;
  uint8_t csa_component6_fa0_xor1 = 0;
  uint8_t csa_component6_fa0_or0 = 0;
  uint8_t csa_component6_fa1_xor1 = 0;
  uint8_t csa_component6_fa1_or0 = 0;
  uint8_t csa_component6_fa2_xor1 = 0;
  uint8_t csa_component6_fa2_or0 = 0;
  uint8_t csa_component6_fa3_xor1 = 0;
  uint8_t csa_component6_fa3_or0 = 0;
  uint8_t csa_component6_fa4_xor1 = 0;
  uint8_t csa_component6_fa4_or0 = 0;
  uint8_t csa_component6_fa5_xor1 = 0;
  uint8_t csa_component6_fa5_or0 = 0;

  csa_component6_fa0_xor1 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 0) & 0x01;
  csa_component6_fa0_or0 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 1) & 0x01;
  csa_component6_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 0) & 0x01;
  csa_component6_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 1) & 0x01;
  csa_component6_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 0) & 0x01;
  csa_component6_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 1) & 0x01;
  csa_component6_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 0) & 0x01;
  csa_component6_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 1) & 0x01;
  csa_component6_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 0) & 0x01;
  csa_component6_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 1) & 0x01;
  csa_component6_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 0) & 0x01;
  csa_component6_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 1) & 0x01;

  csa_component6_out |= ((csa_component6_fa0_xor1 >> 0) & 0x01ull) << 0;
  csa_component6_out |= ((csa_component6_fa1_xor1 >> 0) & 0x01ull) << 1;
  csa_component6_out |= ((csa_component6_fa2_xor1 >> 0) & 0x01ull) << 2;
  csa_component6_out |= ((csa_component6_fa3_xor1 >> 0) & 0x01ull) << 3;
  csa_component6_out |= ((csa_component6_fa4_xor1 >> 0) & 0x01ull) << 4;
  csa_component6_out |= ((csa_component6_fa5_xor1 >> 0) & 0x01ull) << 5;
  csa_component6_out |= (0x00) << 6;
  csa_component6_out |= (0x00) << 7;
  csa_component6_out |= ((csa_component6_fa0_or0 >> 0) & 0x01ull) << 8;
  csa_component6_out |= ((csa_component6_fa1_or0 >> 0) & 0x01ull) << 9;
  csa_component6_out |= ((csa_component6_fa2_or0 >> 0) & 0x01ull) << 10;
  csa_component6_out |= ((csa_component6_fa3_or0 >> 0) & 0x01ull) << 11;
  csa_component6_out |= ((csa_component6_fa4_or0 >> 0) & 0x01ull) << 12;
  csa_component6_out |= ((csa_component6_fa5_or0 >> 0) & 0x01ull) << 13;
  return csa_component6_out;
}

uint64_t csa_component7(uint64_t a, uint64_t b, uint64_t c){
  uint64_t csa_component7_out = 0;
  uint8_t csa_component7_fa0_xor1 = 0;
  uint8_t csa_component7_fa0_or0 = 0;
  uint8_t csa_component7_fa1_xor1 = 0;
  uint8_t csa_component7_fa1_or0 = 0;
  uint8_t csa_component7_fa2_xor1 = 0;
  uint8_t csa_component7_fa2_or0 = 0;
  uint8_t csa_component7_fa3_xor1 = 0;
  uint8_t csa_component7_fa3_or0 = 0;
  uint8_t csa_component7_fa4_xor1 = 0;
  uint8_t csa_component7_fa4_or0 = 0;
  uint8_t csa_component7_fa5_xor1 = 0;
  uint8_t csa_component7_fa5_or0 = 0;
  uint8_t csa_component7_fa6_xor1 = 0;
  uint8_t csa_component7_fa6_or0 = 0;

  csa_component7_fa0_xor1 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 0) & 0x01;
  csa_component7_fa0_or0 = (fa(((a >> 0) & 0x01), ((b >> 0) & 0x01), ((c >> 0) & 0x01)) >> 1) & 0x01;
  csa_component7_fa1_xor1 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 0) & 0x01;
  csa_component7_fa1_or0 = (fa(((a >> 1) & 0x01), ((b >> 1) & 0x01), ((c >> 1) & 0x01)) >> 1) & 0x01;
  csa_component7_fa2_xor1 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 0) & 0x01;
  csa_component7_fa2_or0 = (fa(((a >> 2) & 0x01), ((b >> 2) & 0x01), ((c >> 2) & 0x01)) >> 1) & 0x01;
  csa_component7_fa3_xor1 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 0) & 0x01;
  csa_component7_fa3_or0 = (fa(((a >> 3) & 0x01), ((b >> 3) & 0x01), ((c >> 3) & 0x01)) >> 1) & 0x01;
  csa_component7_fa4_xor1 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 0) & 0x01;
  csa_component7_fa4_or0 = (fa(((a >> 4) & 0x01), ((b >> 4) & 0x01), ((c >> 4) & 0x01)) >> 1) & 0x01;
  csa_component7_fa5_xor1 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 0) & 0x01;
  csa_component7_fa5_or0 = (fa(((a >> 5) & 0x01), ((b >> 5) & 0x01), ((c >> 5) & 0x01)) >> 1) & 0x01;
  csa_component7_fa6_xor1 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((c >> 6) & 0x01)) >> 0) & 0x01;
  csa_component7_fa6_or0 = (fa(((a >> 6) & 0x01), ((b >> 6) & 0x01), ((c >> 6) & 0x01)) >> 1) & 0x01;

  csa_component7_out |= ((csa_component7_fa0_xor1 >> 0) & 0x01ull) << 0;
  csa_component7_out |= ((csa_component7_fa1_xor1 >> 0) & 0x01ull) << 1;
  csa_component7_out |= ((csa_component7_fa2_xor1 >> 0) & 0x01ull) << 2;
  csa_component7_out |= ((csa_component7_fa3_xor1 >> 0) & 0x01ull) << 3;
  csa_component7_out |= ((csa_component7_fa4_xor1 >> 0) & 0x01ull) << 4;
  csa_component7_out |= ((csa_component7_fa5_xor1 >> 0) & 0x01ull) << 5;
  csa_component7_out |= ((csa_component7_fa6_xor1 >> 0) & 0x01ull) << 6;
  csa_component7_out |= (0x00) << 7;
  csa_component7_out |= (0x00) << 8;
  csa_component7_out |= ((csa_component7_fa0_or0 >> 0) & 0x01ull) << 9;
  csa_component7_out |= ((csa_component7_fa1_or0 >> 0) & 0x01ull) << 10;
  csa_component7_out |= ((csa_component7_fa2_or0 >> 0) & 0x01ull) << 11;
  csa_component7_out |= ((csa_component7_fa3_or0 >> 0) & 0x01ull) << 12;
  csa_component7_out |= ((csa_component7_fa4_or0 >> 0) & 0x01ull) << 13;
  csa_component7_out |= ((csa_component7_fa5_or0 >> 0) & 0x01ull) << 14;
  csa_component7_out |= ((csa_component7_fa6_or0 >> 0) & 0x01ull) << 15;
  return csa_component7_out;
}

uint64_t u_cla8(uint64_t a, uint64_t b){
  uint64_t u_cla8_out = 0;
  uint8_t u_cla8_pg_logic0_or0 = 0;
  uint8_t u_cla8_pg_logic0_and0 = 0;
  uint8_t u_cla8_pg_logic0_xor0 = 0;
  uint8_t u_cla8_pg_logic1_or0 = 0;
  uint8_t u_cla8_pg_logic1_and0 = 0;
  uint8_t u_cla8_pg_logic1_xor0 = 0;
  uint8_t u_cla8_xor1 = 0;
  uint8_t u_cla8_and0 = 0;
  uint8_t u_cla8_or0 = 0;
  uint8_t u_cla8_pg_logic2_or0 = 0;
  uint8_t u_cla8_pg_logic2_and0 = 0;
  uint8_t u_cla8_pg_logic2_xor0 = 0;
  uint8_t u_cla8_xor2 = 0;
  uint8_t u_cla8_and1 = 0;
  uint8_t u_cla8_and2 = 0;
  uint8_t u_cla8_and3 = 0;
  uint8_t u_cla8_and4 = 0;
  uint8_t u_cla8_or1 = 0;
  uint8_t u_cla8_or2 = 0;
  uint8_t u_cla8_pg_logic3_or0 = 0;
  uint8_t u_cla8_pg_logic3_and0 = 0;
  uint8_t u_cla8_pg_logic3_xor0 = 0;
  uint8_t u_cla8_xor3 = 0;
  uint8_t u_cla8_and5 = 0;
  uint8_t u_cla8_and6 = 0;
  uint8_t u_cla8_and7 = 0;
  uint8_t u_cla8_and8 = 0;
  uint8_t u_cla8_and9 = 0;
  uint8_t u_cla8_and10 = 0;
  uint8_t u_cla8_and11 = 0;
  uint8_t u_cla8_or3 = 0;
  uint8_t u_cla8_or4 = 0;
  uint8_t u_cla8_or5 = 0;
  uint8_t u_cla8_pg_logic4_or0 = 0;
  uint8_t u_cla8_pg_logic4_and0 = 0;
  uint8_t u_cla8_pg_logic4_xor0 = 0;
  uint8_t u_cla8_xor4 = 0;
  uint8_t u_cla8_and12 = 0;
  uint8_t u_cla8_or6 = 0;
  uint8_t u_cla8_pg_logic5_or0 = 0;
  uint8_t u_cla8_pg_logic5_and0 = 0;
  uint8_t u_cla8_pg_logic5_xor0 = 0;
  uint8_t u_cla8_xor5 = 0;
  uint8_t u_cla8_and13 = 0;
  uint8_t u_cla8_and14 = 0;
  uint8_t u_cla8_and15 = 0;
  uint8_t u_cla8_or7 = 0;
  uint8_t u_cla8_or8 = 0;
  uint8_t u_cla8_pg_logic6_or0 = 0;
  uint8_t u_cla8_pg_logic6_and0 = 0;
  uint8_t u_cla8_pg_logic6_xor0 = 0;
  uint8_t u_cla8_xor6 = 0;
  uint8_t u_cla8_and16 = 0;
  uint8_t u_cla8_and17 = 0;
  uint8_t u_cla8_and18 = 0;
  uint8_t u_cla8_and19 = 0;
  uint8_t u_cla8_and20 = 0;
  uint8_t u_cla8_and21 = 0;
  uint8_t u_cla8_or9 = 0;
  uint8_t u_cla8_or10 = 0;
  uint8_t u_cla8_or11 = 0;
  uint8_t u_cla8_pg_logic7_or0 = 0;
  uint8_t u_cla8_pg_logic7_and0 = 0;
  uint8_t u_cla8_pg_logic7_xor0 = 0;
  uint8_t u_cla8_xor7 = 0;
  uint8_t u_cla8_and22 = 0;
  uint8_t u_cla8_and23 = 0;
  uint8_t u_cla8_and24 = 0;
  uint8_t u_cla8_and25 = 0;
  uint8_t u_cla8_and26 = 0;
  uint8_t u_cla8_and27 = 0;
  uint8_t u_cla8_and28 = 0;
  uint8_t u_cla8_and29 = 0;
  uint8_t u_cla8_and30 = 0;
  uint8_t u_cla8_and31 = 0;
  uint8_t u_cla8_or12 = 0;
  uint8_t u_cla8_or13 = 0;
  uint8_t u_cla8_or14 = 0;
  uint8_t u_cla8_or15 = 0;

  u_cla8_pg_logic0_or0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic0_and0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic0_xor0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 2) & 0x01;
  u_cla8_pg_logic1_or0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic1_and0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic1_xor0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 2) & 0x01;
  u_cla8_xor1 = xor_gate(((u_cla8_pg_logic1_xor0 >> 0) & 0x01), ((u_cla8_pg_logic0_and0 >> 0) & 0x01));
  u_cla8_and0 = and_gate(((u_cla8_pg_logic0_and0 >> 0) & 0x01), ((u_cla8_pg_logic1_or0 >> 0) & 0x01));
  u_cla8_or0 = or_gate(((u_cla8_pg_logic1_and0 >> 0) & 0x01), ((u_cla8_and0 >> 0) & 0x01));
  u_cla8_pg_logic2_or0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic2_and0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic2_xor0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 2) & 0x01;
  u_cla8_xor2 = xor_gate(((u_cla8_pg_logic2_xor0 >> 0) & 0x01), ((u_cla8_or0 >> 0) & 0x01));
  u_cla8_and1 = and_gate(((u_cla8_pg_logic2_or0 >> 0) & 0x01), ((u_cla8_pg_logic0_or0 >> 0) & 0x01));
  u_cla8_and2 = and_gate(((u_cla8_pg_logic0_and0 >> 0) & 0x01), ((u_cla8_pg_logic2_or0 >> 0) & 0x01));
  u_cla8_and3 = and_gate(((u_cla8_and2 >> 0) & 0x01), ((u_cla8_pg_logic1_or0 >> 0) & 0x01));
  u_cla8_and4 = and_gate(((u_cla8_pg_logic1_and0 >> 0) & 0x01), ((u_cla8_pg_logic2_or0 >> 0) & 0x01));
  u_cla8_or1 = or_gate(((u_cla8_and3 >> 0) & 0x01), ((u_cla8_and4 >> 0) & 0x01));
  u_cla8_or2 = or_gate(((u_cla8_pg_logic2_and0 >> 0) & 0x01), ((u_cla8_or1 >> 0) & 0x01));
  u_cla8_pg_logic3_or0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic3_and0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic3_xor0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 2) & 0x01;
  u_cla8_xor3 = xor_gate(((u_cla8_pg_logic3_xor0 >> 0) & 0x01), ((u_cla8_or2 >> 0) & 0x01));
  u_cla8_and5 = and_gate(((u_cla8_pg_logic3_or0 >> 0) & 0x01), ((u_cla8_pg_logic1_or0 >> 0) & 0x01));
  u_cla8_and6 = and_gate(((u_cla8_pg_logic0_and0 >> 0) & 0x01), ((u_cla8_pg_logic2_or0 >> 0) & 0x01));
  u_cla8_and7 = and_gate(((u_cla8_pg_logic3_or0 >> 0) & 0x01), ((u_cla8_pg_logic1_or0 >> 0) & 0x01));
  u_cla8_and8 = and_gate(((u_cla8_and6 >> 0) & 0x01), ((u_cla8_and7 >> 0) & 0x01));
  u_cla8_and9 = and_gate(((u_cla8_pg_logic1_and0 >> 0) & 0x01), ((u_cla8_pg_logic3_or0 >> 0) & 0x01));
  u_cla8_and10 = and_gate(((u_cla8_and9 >> 0) & 0x01), ((u_cla8_pg_logic2_or0 >> 0) & 0x01));
  u_cla8_and11 = and_gate(((u_cla8_pg_logic2_and0 >> 0) & 0x01), ((u_cla8_pg_logic3_or0 >> 0) & 0x01));
  u_cla8_or3 = or_gate(((u_cla8_and8 >> 0) & 0x01), ((u_cla8_and11 >> 0) & 0x01));
  u_cla8_or4 = or_gate(((u_cla8_and10 >> 0) & 0x01), ((u_cla8_or3 >> 0) & 0x01));
  u_cla8_or5 = or_gate(((u_cla8_pg_logic3_and0 >> 0) & 0x01), ((u_cla8_or4 >> 0) & 0x01));
  u_cla8_pg_logic4_or0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic4_and0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic4_xor0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 2) & 0x01;
  u_cla8_xor4 = xor_gate(((u_cla8_pg_logic4_xor0 >> 0) & 0x01), ((u_cla8_or5 >> 0) & 0x01));
  u_cla8_and12 = and_gate(((u_cla8_or5 >> 0) & 0x01), ((u_cla8_pg_logic4_or0 >> 0) & 0x01));
  u_cla8_or6 = or_gate(((u_cla8_pg_logic4_and0 >> 0) & 0x01), ((u_cla8_and12 >> 0) & 0x01));
  u_cla8_pg_logic5_or0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic5_and0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic5_xor0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 2) & 0x01;
  u_cla8_xor5 = xor_gate(((u_cla8_pg_logic5_xor0 >> 0) & 0x01), ((u_cla8_or6 >> 0) & 0x01));
  u_cla8_and13 = and_gate(((u_cla8_or5 >> 0) & 0x01), ((u_cla8_pg_logic5_or0 >> 0) & 0x01));
  u_cla8_and14 = and_gate(((u_cla8_and13 >> 0) & 0x01), ((u_cla8_pg_logic4_or0 >> 0) & 0x01));
  u_cla8_and15 = and_gate(((u_cla8_pg_logic4_and0 >> 0) & 0x01), ((u_cla8_pg_logic5_or0 >> 0) & 0x01));
  u_cla8_or7 = or_gate(((u_cla8_and14 >> 0) & 0x01), ((u_cla8_and15 >> 0) & 0x01));
  u_cla8_or8 = or_gate(((u_cla8_pg_logic5_and0 >> 0) & 0x01), ((u_cla8_or7 >> 0) & 0x01));
  u_cla8_pg_logic6_or0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic6_and0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic6_xor0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 2) & 0x01;
  u_cla8_xor6 = xor_gate(((u_cla8_pg_logic6_xor0 >> 0) & 0x01), ((u_cla8_or8 >> 0) & 0x01));
  u_cla8_and16 = and_gate(((u_cla8_or5 >> 0) & 0x01), ((u_cla8_pg_logic5_or0 >> 0) & 0x01));
  u_cla8_and17 = and_gate(((u_cla8_pg_logic6_or0 >> 0) & 0x01), ((u_cla8_pg_logic4_or0 >> 0) & 0x01));
  u_cla8_and18 = and_gate(((u_cla8_and16 >> 0) & 0x01), ((u_cla8_and17 >> 0) & 0x01));
  u_cla8_and19 = and_gate(((u_cla8_pg_logic4_and0 >> 0) & 0x01), ((u_cla8_pg_logic6_or0 >> 0) & 0x01));
  u_cla8_and20 = and_gate(((u_cla8_and19 >> 0) & 0x01), ((u_cla8_pg_logic5_or0 >> 0) & 0x01));
  u_cla8_and21 = and_gate(((u_cla8_pg_logic5_and0 >> 0) & 0x01), ((u_cla8_pg_logic6_or0 >> 0) & 0x01));
  u_cla8_or9 = or_gate(((u_cla8_and18 >> 0) & 0x01), ((u_cla8_and20 >> 0) & 0x01));
  u_cla8_or10 = or_gate(((u_cla8_or9 >> 0) & 0x01), ((u_cla8_and21 >> 0) & 0x01));
  u_cla8_or11 = or_gate(((u_cla8_pg_logic6_and0 >> 0) & 0x01), ((u_cla8_or10 >> 0) & 0x01));
  u_cla8_pg_logic7_or0 = (pg_logic(((a >> 7) & 0x01), ((b >> 7) & 0x01)) >> 0) & 0x01;
  u_cla8_pg_logic7_and0 = (pg_logic(((a >> 7) & 0x01), ((b >> 7) & 0x01)) >> 1) & 0x01;
  u_cla8_pg_logic7_xor0 = (pg_logic(((a >> 7) & 0x01), ((b >> 7) & 0x01)) >> 2) & 0x01;
  u_cla8_xor7 = xor_gate(((u_cla8_pg_logic7_xor0 >> 0) & 0x01), ((u_cla8_or11 >> 0) & 0x01));
  u_cla8_and22 = and_gate(((u_cla8_or5 >> 0) & 0x01), ((u_cla8_pg_logic6_or0 >> 0) & 0x01));
  u_cla8_and23 = and_gate(((u_cla8_pg_logic7_or0 >> 0) & 0x01), ((u_cla8_pg_logic5_or0 >> 0) & 0x01));
  u_cla8_and24 = and_gate(((u_cla8_and22 >> 0) & 0x01), ((u_cla8_and23 >> 0) & 0x01));
  u_cla8_and25 = and_gate(((u_cla8_and24 >> 0) & 0x01), ((u_cla8_pg_logic4_or0 >> 0) & 0x01));
  u_cla8_and26 = and_gate(((u_cla8_pg_logic4_and0 >> 0) & 0x01), ((u_cla8_pg_logic6_or0 >> 0) & 0x01));
  u_cla8_and27 = and_gate(((u_cla8_pg_logic7_or0 >> 0) & 0x01), ((u_cla8_pg_logic5_or0 >> 0) & 0x01));
  u_cla8_and28 = and_gate(((u_cla8_and26 >> 0) & 0x01), ((u_cla8_and27 >> 0) & 0x01));
  u_cla8_and29 = and_gate(((u_cla8_pg_logic5_and0 >> 0) & 0x01), ((u_cla8_pg_logic7_or0 >> 0) & 0x01));
  u_cla8_and30 = and_gate(((u_cla8_and29 >> 0) & 0x01), ((u_cla8_pg_logic6_or0 >> 0) & 0x01));
  u_cla8_and31 = and_gate(((u_cla8_pg_logic6_and0 >> 0) & 0x01), ((u_cla8_pg_logic7_or0 >> 0) & 0x01));
  u_cla8_or12 = or_gate(((u_cla8_and25 >> 0) & 0x01), ((u_cla8_and30 >> 0) & 0x01));
  u_cla8_or13 = or_gate(((u_cla8_and28 >> 0) & 0x01), ((u_cla8_and31 >> 0) & 0x01));
  u_cla8_or14 = or_gate(((u_cla8_or12 >> 0) & 0x01), ((u_cla8_or13 >> 0) & 0x01));
  u_cla8_or15 = or_gate(((u_cla8_pg_logic7_and0 >> 0) & 0x01), ((u_cla8_or14 >> 0) & 0x01));

  u_cla8_out |= ((u_cla8_pg_logic0_xor0 >> 0) & 0x01ull) << 0;
  u_cla8_out |= ((u_cla8_xor1 >> 0) & 0x01ull) << 1;
  u_cla8_out |= ((u_cla8_xor2 >> 0) & 0x01ull) << 2;
  u_cla8_out |= ((u_cla8_xor3 >> 0) & 0x01ull) << 3;
  u_cla8_out |= ((u_cla8_xor4 >> 0) & 0x01ull) << 4;
  u_cla8_out |= ((u_cla8_xor5 >> 0) & 0x01ull) << 5;
  u_cla8_out |= ((u_cla8_xor6 >> 0) & 0x01ull) << 6;
  u_cla8_out |= ((u_cla8_xor7 >> 0) & 0x01ull) << 7;
  u_cla8_out |= ((u_cla8_or15 >> 0) & 0x01ull) << 8;
  return u_cla8_out;
}

int64_t s_CSAwallace_cla4(int64_t a, int64_t b){
  int8_t s_CSAwallace_cla4_out = 0;
  uint8_t s_CSAwallace_cla4_and_0_0 = 0;
  uint8_t s_CSAwallace_cla4_and_1_0 = 0;
  uint8_t s_CSAwallace_cla4_and_2_0 = 0;
  uint8_t s_CSAwallace_cla4_nand_3_0 = 0;
  uint8_t s_CSAwallace_cla4_and_0_1 = 0;
  uint8_t s_CSAwallace_cla4_and_1_1 = 0;
  uint8_t s_CSAwallace_cla4_and_2_1 = 0;
  uint8_t s_CSAwallace_cla4_nand_3_1 = 0;
  uint8_t s_CSAwallace_cla4_and_0_2 = 0;
  uint8_t s_CSAwallace_cla4_and_1_2 = 0;
  uint8_t s_CSAwallace_cla4_and_2_2 = 0;
  uint8_t s_CSAwallace_cla4_nand_3_2 = 0;
  uint8_t s_CSAwallace_cla4_nand_0_3 = 0;
  uint8_t s_CSAwallace_cla4_nand_1_3 = 0;
  uint8_t s_CSAwallace_cla4_nand_2_3 = 0;
  uint8_t s_CSAwallace_cla4_and_3_3 = 0;
  int64_t s_CSAwallace_cla4_csa0_csa_component_pp_row0 = 0;
  int64_t s_CSAwallace_cla4_csa0_csa_component_pp_row1 = 0;
  int64_t s_CSAwallace_cla4_csa0_csa_component_pp_row2 = 0;
  int64_t s_CSAwallace_cla4_csa0_csa_component_out = 0;
  int64_t s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 = 0;
  int64_t s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 = 0;
  int64_t s_CSAwallace_cla4_csa1_csa_component_pp_row3 = 0;
  int64_t s_CSAwallace_cla4_csa1_csa_component_out = 0;
  uint64_t s_CSAwallace_cla4_u_cla8_a = 0;
  uint64_t s_CSAwallace_cla4_u_cla8_b = 0;
  uint64_t s_CSAwallace_cla4_u_cla8_out = 0;
  uint8_t s_CSAwallace_cla4_xor0 = 0;

  s_CSAwallace_cla4_and_0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_cla4_and_1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_cla4_and_2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_cla4_nand_3_0 = nand_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  s_CSAwallace_cla4_and_0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_cla4_and_1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_cla4_and_2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_cla4_nand_3_1 = nand_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  s_CSAwallace_cla4_and_0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_cla4_and_1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_cla4_and_2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_cla4_nand_3_2 = nand_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  s_CSAwallace_cla4_nand_0_3 = nand_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_cla4_nand_1_3 = nand_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_cla4_nand_2_3 = nand_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_cla4_and_3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  s_CSAwallace_cla4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_cla4_and_0_0 >> 0) & 0x01ull) << 0;
  s_CSAwallace_cla4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_cla4_and_1_0 >> 0) & 0x01ull) << 1;
  s_CSAwallace_cla4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_cla4_and_2_0 >> 0) & 0x01ull) << 2;
  s_CSAwallace_cla4_csa0_csa_component_pp_row0 |= ((s_CSAwallace_cla4_nand_3_0 >> 0) & 0x01ull) << 3;
  s_CSAwallace_cla4_csa0_csa_component_pp_row0 |= (0x01) << 4;
  s_CSAwallace_cla4_csa0_csa_component_pp_row0 |= (0x01) << 5;
  s_CSAwallace_cla4_csa0_csa_component_pp_row1 |= (0x00) << 0;
  s_CSAwallace_cla4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_cla4_and_0_1 >> 0) & 0x01ull) << 1;
  s_CSAwallace_cla4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_cla4_and_1_1 >> 0) & 0x01ull) << 2;
  s_CSAwallace_cla4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_cla4_and_2_1 >> 0) & 0x01ull) << 3;
  s_CSAwallace_cla4_csa0_csa_component_pp_row1 |= ((s_CSAwallace_cla4_nand_3_1 >> 0) & 0x01ull) << 4;
  s_CSAwallace_cla4_csa0_csa_component_pp_row1 |= (0x01) << 5;
  s_CSAwallace_cla4_csa0_csa_component_pp_row2 |= (0x00) << 0;
  s_CSAwallace_cla4_csa0_csa_component_pp_row2 |= (0x00) << 1;
  s_CSAwallace_cla4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_cla4_and_0_2 >> 0) & 0x01ull) << 2;
  s_CSAwallace_cla4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_cla4_and_1_2 >> 0) & 0x01ull) << 3;
  s_CSAwallace_cla4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_cla4_and_2_2 >> 0) & 0x01ull) << 4;
  s_CSAwallace_cla4_csa0_csa_component_pp_row2 |= ((s_CSAwallace_cla4_nand_3_2 >> 0) & 0x01ull) << 5;
  s_CSAwallace_cla4_csa0_csa_component_out = csa_component6(s_CSAwallace_cla4_csa0_csa_component_pp_row0, s_CSAwallace_cla4_csa0_csa_component_pp_row1, s_CSAwallace_cla4_csa0_csa_component_pp_row2);
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 0) & 0x01ull) << 0;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 1) & 0x01ull) << 1;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 2) & 0x01ull) << 2;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 3) & 0x01ull) << 3;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 4) & 0x01ull) << 4;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 5) & 0x01ull) << 5;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1 |= (0x01) << 6;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= (0x00) << 0;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= (0x00) << 1;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 9) & 0x01ull) << 2;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 10) & 0x01ull) << 3;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 11) & 0x01ull) << 4;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= ((s_CSAwallace_cla4_csa0_csa_component_out >> 12) & 0x01ull) << 5;
  s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1 |= (0x01) << 6;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= (0x00) << 0;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= (0x00) << 1;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= (0x00) << 2;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_cla4_nand_0_3 >> 0) & 0x01ull) << 3;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_cla4_nand_1_3 >> 0) & 0x01ull) << 4;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_cla4_nand_2_3 >> 0) & 0x01ull) << 5;
  s_CSAwallace_cla4_csa1_csa_component_pp_row3 |= ((s_CSAwallace_cla4_and_3_3 >> 0) & 0x01ull) << 6;
  s_CSAwallace_cla4_csa1_csa_component_out = csa_component7(s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_s1, s_CSAwallace_cla4_csa1_csa_component_s_CSAwallace_cla4_csa_c1, s_CSAwallace_cla4_csa1_csa_component_pp_row3);
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 0) & 0x01ull) << 0;
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 1) & 0x01ull) << 1;
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 2) & 0x01ull) << 2;
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 3) & 0x01ull) << 3;
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 4) & 0x01ull) << 4;
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 5) & 0x01ull) << 5;
  s_CSAwallace_cla4_u_cla8_a |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 6) & 0x01ull) << 6;
  s_CSAwallace_cla4_u_cla8_a |= (0x01) << 7;
  s_CSAwallace_cla4_u_cla8_b |= (0x00) << 0;
  s_CSAwallace_cla4_u_cla8_b |= (0x00) << 1;
  s_CSAwallace_cla4_u_cla8_b |= (0x00) << 2;
  s_CSAwallace_cla4_u_cla8_b |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 11) & 0x01ull) << 3;
  s_CSAwallace_cla4_u_cla8_b |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 12) & 0x01ull) << 4;
  s_CSAwallace_cla4_u_cla8_b |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 13) & 0x01ull) << 5;
  s_CSAwallace_cla4_u_cla8_b |= ((s_CSAwallace_cla4_csa1_csa_component_out >> 14) & 0x01ull) << 6;
  s_CSAwallace_cla4_u_cla8_b |= (0x01) << 7;
  s_CSAwallace_cla4_u_cla8_out = u_cla8(s_CSAwallace_cla4_u_cla8_a, s_CSAwallace_cla4_u_cla8_b);
  s_CSAwallace_cla4_xor0 = not_gate(((s_CSAwallace_cla4_u_cla8_out >> 7) & 0x01));

  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 0) & 0x01ull) << 0;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 1) & 0x01ull) << 1;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 2) & 0x01ull) << 2;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 3) & 0x01ull) << 3;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 4) & 0x01ull) << 4;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 5) & 0x01ull) << 5;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_u_cla8_out >> 6) & 0x01ull) << 6;
  s_CSAwallace_cla4_out |= ((s_CSAwallace_cla4_xor0 >> 0) & 0x01ull) << 7;
  return s_CSAwallace_cla4_out;
}