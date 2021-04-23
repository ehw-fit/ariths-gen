#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) ^ ((b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) | ((b >> 0) & 0x01);
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t ha_out = 0;
  uint8_t ha_xor0 = 0;
  uint8_t ha_and0 = 0;

  ha_xor0 = xor_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  ha_and0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));

  ha_out |= ((ha_xor0 >> 0) & 0x01) << 0;
  ha_out |= ((ha_and0 >> 0) & 0x01) << 1;
  return ha_out;
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

  fa_out |= ((fa_xor1 >> 0) & 0x01) << 0;
  fa_out |= ((fa_or0 >> 0) & 0x01) << 1;
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

  pg_logic_out |= ((pg_logic_or0 >> 0) & 0x01) << 0;
  pg_logic_out |= ((pg_logic_and0 >> 0) & 0x01) << 1;
  pg_logic_out |= ((pg_logic_xor0 >> 0) & 0x01) << 2;
  return pg_logic_out;
}

uint64_t u_cla6(uint64_t a, uint64_t b){
  uint8_t u_cla6_out = 0;
  uint8_t u_cla6_pg_logic0_or0 = 0;
  uint8_t u_cla6_pg_logic0_and0 = 0;
  uint8_t u_cla6_pg_logic0_xor0 = 0;
  uint8_t u_cla6_pg_logic1_or0 = 0;
  uint8_t u_cla6_pg_logic1_and0 = 0;
  uint8_t u_cla6_pg_logic1_xor0 = 0;
  uint8_t u_cla6_xor1 = 0;
  uint8_t u_cla6_and0 = 0;
  uint8_t u_cla6_or0 = 0;
  uint8_t u_cla6_pg_logic2_or0 = 0;
  uint8_t u_cla6_pg_logic2_and0 = 0;
  uint8_t u_cla6_pg_logic2_xor0 = 0;
  uint8_t u_cla6_xor2 = 0;
  uint8_t u_cla6_and1 = 0;
  uint8_t u_cla6_and2 = 0;
  uint8_t u_cla6_and3 = 0;
  uint8_t u_cla6_and4 = 0;
  uint8_t u_cla6_or1 = 0;
  uint8_t u_cla6_or2 = 0;
  uint8_t u_cla6_pg_logic3_or0 = 0;
  uint8_t u_cla6_pg_logic3_and0 = 0;
  uint8_t u_cla6_pg_logic3_xor0 = 0;
  uint8_t u_cla6_xor3 = 0;
  uint8_t u_cla6_and5 = 0;
  uint8_t u_cla6_and6 = 0;
  uint8_t u_cla6_and7 = 0;
  uint8_t u_cla6_and8 = 0;
  uint8_t u_cla6_and9 = 0;
  uint8_t u_cla6_and10 = 0;
  uint8_t u_cla6_and11 = 0;
  uint8_t u_cla6_or3 = 0;
  uint8_t u_cla6_or4 = 0;
  uint8_t u_cla6_or5 = 0;
  uint8_t u_cla6_pg_logic4_or0 = 0;
  uint8_t u_cla6_pg_logic4_and0 = 0;
  uint8_t u_cla6_pg_logic4_xor0 = 0;
  uint8_t u_cla6_xor4 = 0;
  uint8_t u_cla6_and12 = 0;
  uint8_t u_cla6_or6 = 0;
  uint8_t u_cla6_pg_logic5_or0 = 0;
  uint8_t u_cla6_pg_logic5_and0 = 0;
  uint8_t u_cla6_pg_logic5_xor0 = 0;
  uint8_t u_cla6_xor5 = 0;
  uint8_t u_cla6_and13 = 0;
  uint8_t u_cla6_and14 = 0;
  uint8_t u_cla6_and15 = 0;
  uint8_t u_cla6_or7 = 0;
  uint8_t u_cla6_or8 = 0;

  u_cla6_pg_logic0_or0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cla6_pg_logic0_and0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cla6_pg_logic0_xor0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 2) & 0x01;
  u_cla6_pg_logic1_or0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 0) & 0x01;
  u_cla6_pg_logic1_and0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 1) & 0x01;
  u_cla6_pg_logic1_xor0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 2) & 0x01;
  u_cla6_xor1 = xor_gate(((u_cla6_pg_logic1_xor0 >> 0) & 0x01), ((u_cla6_pg_logic0_and0 >> 0) & 0x01));
  u_cla6_and0 = and_gate(((u_cla6_pg_logic0_and0 >> 0) & 0x01), ((u_cla6_pg_logic1_or0 >> 0) & 0x01));
  u_cla6_or0 = or_gate(((u_cla6_pg_logic1_and0 >> 0) & 0x01), ((u_cla6_and0 >> 0) & 0x01));
  u_cla6_pg_logic2_or0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 0) & 0x01;
  u_cla6_pg_logic2_and0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 1) & 0x01;
  u_cla6_pg_logic2_xor0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 2) & 0x01;
  u_cla6_xor2 = xor_gate(((u_cla6_pg_logic2_xor0 >> 0) & 0x01), ((u_cla6_or0 >> 0) & 0x01));
  u_cla6_and1 = and_gate(((u_cla6_pg_logic2_or0 >> 0) & 0x01), ((u_cla6_pg_logic0_or0 >> 0) & 0x01));
  u_cla6_and2 = and_gate(((u_cla6_pg_logic0_and0 >> 0) & 0x01), ((u_cla6_pg_logic2_or0 >> 0) & 0x01));
  u_cla6_and3 = and_gate(((u_cla6_and2 >> 0) & 0x01), ((u_cla6_pg_logic1_or0 >> 0) & 0x01));
  u_cla6_and4 = and_gate(((u_cla6_pg_logic1_and0 >> 0) & 0x01), ((u_cla6_pg_logic2_or0 >> 0) & 0x01));
  u_cla6_or1 = or_gate(((u_cla6_and3 >> 0) & 0x01), ((u_cla6_and4 >> 0) & 0x01));
  u_cla6_or2 = or_gate(((u_cla6_pg_logic2_and0 >> 0) & 0x01), ((u_cla6_or1 >> 0) & 0x01));
  u_cla6_pg_logic3_or0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 0) & 0x01;
  u_cla6_pg_logic3_and0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 1) & 0x01;
  u_cla6_pg_logic3_xor0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 2) & 0x01;
  u_cla6_xor3 = xor_gate(((u_cla6_pg_logic3_xor0 >> 0) & 0x01), ((u_cla6_or2 >> 0) & 0x01));
  u_cla6_and5 = and_gate(((u_cla6_pg_logic3_or0 >> 0) & 0x01), ((u_cla6_pg_logic1_or0 >> 0) & 0x01));
  u_cla6_and6 = and_gate(((u_cla6_pg_logic0_and0 >> 0) & 0x01), ((u_cla6_pg_logic2_or0 >> 0) & 0x01));
  u_cla6_and7 = and_gate(((u_cla6_pg_logic3_or0 >> 0) & 0x01), ((u_cla6_pg_logic1_or0 >> 0) & 0x01));
  u_cla6_and8 = and_gate(((u_cla6_and6 >> 0) & 0x01), ((u_cla6_and7 >> 0) & 0x01));
  u_cla6_and9 = and_gate(((u_cla6_pg_logic1_and0 >> 0) & 0x01), ((u_cla6_pg_logic3_or0 >> 0) & 0x01));
  u_cla6_and10 = and_gate(((u_cla6_and9 >> 0) & 0x01), ((u_cla6_pg_logic2_or0 >> 0) & 0x01));
  u_cla6_and11 = and_gate(((u_cla6_pg_logic2_and0 >> 0) & 0x01), ((u_cla6_pg_logic3_or0 >> 0) & 0x01));
  u_cla6_or3 = or_gate(((u_cla6_and8 >> 0) & 0x01), ((u_cla6_and11 >> 0) & 0x01));
  u_cla6_or4 = or_gate(((u_cla6_and10 >> 0) & 0x01), ((u_cla6_or3 >> 0) & 0x01));
  u_cla6_or5 = or_gate(((u_cla6_pg_logic3_and0 >> 0) & 0x01), ((u_cla6_or4 >> 0) & 0x01));
  u_cla6_pg_logic4_or0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 0) & 0x01;
  u_cla6_pg_logic4_and0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 1) & 0x01;
  u_cla6_pg_logic4_xor0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 2) & 0x01;
  u_cla6_xor4 = xor_gate(((u_cla6_pg_logic4_xor0 >> 0) & 0x01), ((u_cla6_or5 >> 0) & 0x01));
  u_cla6_and12 = and_gate(((u_cla6_or5 >> 0) & 0x01), ((u_cla6_pg_logic4_or0 >> 0) & 0x01));
  u_cla6_or6 = or_gate(((u_cla6_pg_logic4_and0 >> 0) & 0x01), ((u_cla6_and12 >> 0) & 0x01));
  u_cla6_pg_logic5_or0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 0) & 0x01;
  u_cla6_pg_logic5_and0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 1) & 0x01;
  u_cla6_pg_logic5_xor0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 2) & 0x01;
  u_cla6_xor5 = xor_gate(((u_cla6_pg_logic5_xor0 >> 0) & 0x01), ((u_cla6_or6 >> 0) & 0x01));
  u_cla6_and13 = and_gate(((u_cla6_or5 >> 0) & 0x01), ((u_cla6_pg_logic5_or0 >> 0) & 0x01));
  u_cla6_and14 = and_gate(((u_cla6_and13 >> 0) & 0x01), ((u_cla6_pg_logic4_or0 >> 0) & 0x01));
  u_cla6_and15 = and_gate(((u_cla6_pg_logic4_and0 >> 0) & 0x01), ((u_cla6_pg_logic5_or0 >> 0) & 0x01));
  u_cla6_or7 = or_gate(((u_cla6_and14 >> 0) & 0x01), ((u_cla6_and15 >> 0) & 0x01));
  u_cla6_or8 = or_gate(((u_cla6_pg_logic5_and0 >> 0) & 0x01), ((u_cla6_or7 >> 0) & 0x01));

  u_cla6_out |= ((u_cla6_pg_logic0_xor0 >> 0) & 0x01) << 0;
  u_cla6_out |= ((u_cla6_xor1 >> 0) & 0x01) << 1;
  u_cla6_out |= ((u_cla6_xor2 >> 0) & 0x01) << 2;
  u_cla6_out |= ((u_cla6_xor3 >> 0) & 0x01) << 3;
  u_cla6_out |= ((u_cla6_xor4 >> 0) & 0x01) << 4;
  u_cla6_out |= ((u_cla6_xor5 >> 0) & 0x01) << 5;
  u_cla6_out |= ((u_cla6_or8 >> 0) & 0x01) << 6;
  return u_cla6_out;
}

uint64_t h_u_dadda_cla4(uint64_t a, uint64_t b){
  uint8_t h_u_dadda_cla4_out = 0;
  uint8_t h_u_dadda_cla4_and_3_0 = 0;
  uint8_t h_u_dadda_cla4_and_2_1 = 0;
  uint8_t h_u_dadda_cla4_ha0_xor0 = 0;
  uint8_t h_u_dadda_cla4_ha0_and0 = 0;
  uint8_t h_u_dadda_cla4_and_3_1 = 0;
  uint8_t h_u_dadda_cla4_ha1_xor0 = 0;
  uint8_t h_u_dadda_cla4_ha1_and0 = 0;
  uint8_t h_u_dadda_cla4_and_2_0 = 0;
  uint8_t h_u_dadda_cla4_and_1_1 = 0;
  uint8_t h_u_dadda_cla4_ha2_xor0 = 0;
  uint8_t h_u_dadda_cla4_ha2_and0 = 0;
  uint8_t h_u_dadda_cla4_and_1_2 = 0;
  uint8_t h_u_dadda_cla4_and_0_3 = 0;
  uint8_t h_u_dadda_cla4_fa0_xor1 = 0;
  uint8_t h_u_dadda_cla4_fa0_or0 = 0;
  uint8_t h_u_dadda_cla4_and_2_2 = 0;
  uint8_t h_u_dadda_cla4_and_1_3 = 0;
  uint8_t h_u_dadda_cla4_fa1_xor1 = 0;
  uint8_t h_u_dadda_cla4_fa1_or0 = 0;
  uint8_t h_u_dadda_cla4_and_3_2 = 0;
  uint8_t h_u_dadda_cla4_fa2_xor1 = 0;
  uint8_t h_u_dadda_cla4_fa2_or0 = 0;
  uint8_t h_u_dadda_cla4_and_0_0 = 0;
  uint8_t h_u_dadda_cla4_and_1_0 = 0;
  uint8_t h_u_dadda_cla4_and_0_2 = 0;
  uint8_t h_u_dadda_cla4_and_2_3 = 0;
  uint8_t h_u_dadda_cla4_and_0_1 = 0;
  uint8_t h_u_dadda_cla4_and_3_3 = 0;
  uint64_t h_u_dadda_cla4_u_cla6_a = 0;
  uint64_t h_u_dadda_cla4_u_cla6_b = 0;
  uint64_t h_u_dadda_cla4_u_cla6_out = 0;

  h_u_dadda_cla4_and_3_0 = and_gate(((a >> 3) & 0x01), ((b >> 0) & 0x01));
  h_u_dadda_cla4_and_2_1 = and_gate(((a >> 2) & 0x01), ((b >> 1) & 0x01));
  h_u_dadda_cla4_ha0_xor0 = (ha(((h_u_dadda_cla4_and_3_0 >> 0) & 0x01), ((h_u_dadda_cla4_and_2_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_dadda_cla4_ha0_and0 = (ha(((h_u_dadda_cla4_and_3_0 >> 0) & 0x01), ((h_u_dadda_cla4_and_2_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_dadda_cla4_and_3_1 = and_gate(((a >> 3) & 0x01), ((b >> 1) & 0x01));
  h_u_dadda_cla4_ha1_xor0 = (ha(((h_u_dadda_cla4_ha0_and0 >> 0) & 0x01), ((h_u_dadda_cla4_and_3_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_dadda_cla4_ha1_and0 = (ha(((h_u_dadda_cla4_ha0_and0 >> 0) & 0x01), ((h_u_dadda_cla4_and_3_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_dadda_cla4_and_2_0 = and_gate(((a >> 2) & 0x01), ((b >> 0) & 0x01));
  h_u_dadda_cla4_and_1_1 = and_gate(((a >> 1) & 0x01), ((b >> 1) & 0x01));
  h_u_dadda_cla4_ha2_xor0 = (ha(((h_u_dadda_cla4_and_2_0 >> 0) & 0x01), ((h_u_dadda_cla4_and_1_1 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_dadda_cla4_ha2_and0 = (ha(((h_u_dadda_cla4_and_2_0 >> 0) & 0x01), ((h_u_dadda_cla4_and_1_1 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_dadda_cla4_and_1_2 = and_gate(((a >> 1) & 0x01), ((b >> 2) & 0x01));
  h_u_dadda_cla4_and_0_3 = and_gate(((a >> 0) & 0x01), ((b >> 3) & 0x01));
  h_u_dadda_cla4_fa0_xor1 = (fa(((h_u_dadda_cla4_ha2_and0 >> 0) & 0x01), ((h_u_dadda_cla4_and_1_2 >> 0) & 0x01), ((h_u_dadda_cla4_and_0_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_dadda_cla4_fa0_or0 = (fa(((h_u_dadda_cla4_ha2_and0 >> 0) & 0x01), ((h_u_dadda_cla4_and_1_2 >> 0) & 0x01), ((h_u_dadda_cla4_and_0_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_dadda_cla4_and_2_2 = and_gate(((a >> 2) & 0x01), ((b >> 2) & 0x01));
  h_u_dadda_cla4_and_1_3 = and_gate(((a >> 1) & 0x01), ((b >> 3) & 0x01));
  h_u_dadda_cla4_fa1_xor1 = (fa(((h_u_dadda_cla4_fa0_or0 >> 0) & 0x01), ((h_u_dadda_cla4_and_2_2 >> 0) & 0x01), ((h_u_dadda_cla4_and_1_3 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_dadda_cla4_fa1_or0 = (fa(((h_u_dadda_cla4_fa0_or0 >> 0) & 0x01), ((h_u_dadda_cla4_and_2_2 >> 0) & 0x01), ((h_u_dadda_cla4_and_1_3 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_dadda_cla4_and_3_2 = and_gate(((a >> 3) & 0x01), ((b >> 2) & 0x01));
  h_u_dadda_cla4_fa2_xor1 = (fa(((h_u_dadda_cla4_fa1_or0 >> 0) & 0x01), ((h_u_dadda_cla4_ha1_and0 >> 0) & 0x01), ((h_u_dadda_cla4_and_3_2 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_dadda_cla4_fa2_or0 = (fa(((h_u_dadda_cla4_fa1_or0 >> 0) & 0x01), ((h_u_dadda_cla4_ha1_and0 >> 0) & 0x01), ((h_u_dadda_cla4_and_3_2 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_dadda_cla4_and_0_0 = and_gate(((a >> 0) & 0x01), ((b >> 0) & 0x01));
  h_u_dadda_cla4_and_1_0 = and_gate(((a >> 1) & 0x01), ((b >> 0) & 0x01));
  h_u_dadda_cla4_and_0_2 = and_gate(((a >> 0) & 0x01), ((b >> 2) & 0x01));
  h_u_dadda_cla4_and_2_3 = and_gate(((a >> 2) & 0x01), ((b >> 3) & 0x01));
  h_u_dadda_cla4_and_0_1 = and_gate(((a >> 0) & 0x01), ((b >> 1) & 0x01));
  h_u_dadda_cla4_and_3_3 = and_gate(((a >> 3) & 0x01), ((b >> 3) & 0x01));
  h_u_dadda_cla4_u_cla6_a |= ((h_u_dadda_cla4_and_1_0 >> 0) & 0x01) << 0;
  h_u_dadda_cla4_u_cla6_a |= ((h_u_dadda_cla4_and_0_2 >> 0) & 0x01) << 1;
  h_u_dadda_cla4_u_cla6_a |= ((h_u_dadda_cla4_ha0_xor0 >> 0) & 0x01) << 2;
  h_u_dadda_cla4_u_cla6_a |= ((h_u_dadda_cla4_ha1_xor0 >> 0) & 0x01) << 3;
  h_u_dadda_cla4_u_cla6_a |= ((h_u_dadda_cla4_and_2_3 >> 0) & 0x01) << 4;
  h_u_dadda_cla4_u_cla6_a |= ((h_u_dadda_cla4_fa2_or0 >> 0) & 0x01) << 5;
  h_u_dadda_cla4_u_cla6_b |= ((h_u_dadda_cla4_and_0_1 >> 0) & 0x01) << 0;
  h_u_dadda_cla4_u_cla6_b |= ((h_u_dadda_cla4_ha2_xor0 >> 0) & 0x01) << 1;
  h_u_dadda_cla4_u_cla6_b |= ((h_u_dadda_cla4_fa0_xor1 >> 0) & 0x01) << 2;
  h_u_dadda_cla4_u_cla6_b |= ((h_u_dadda_cla4_fa1_xor1 >> 0) & 0x01) << 3;
  h_u_dadda_cla4_u_cla6_b |= ((h_u_dadda_cla4_fa2_xor1 >> 0) & 0x01) << 4;
  h_u_dadda_cla4_u_cla6_b |= ((h_u_dadda_cla4_and_3_3 >> 0) & 0x01) << 5;
  h_u_dadda_cla4_u_cla6_out = u_cla6(h_u_dadda_cla4_u_cla6_a, h_u_dadda_cla4_u_cla6_b);

  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_and_0_0 >> 0) & 0x01) << 0;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 0) & 0x01) << 1;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 1) & 0x01) << 2;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 2) & 0x01) << 3;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 3) & 0x01) << 4;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 4) & 0x01) << 5;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 5) & 0x01) << 6;
  h_u_dadda_cla4_out |= ((h_u_dadda_cla4_u_cla6_out >> 6) & 0x01) << 7;
  return h_u_dadda_cla4_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 16; i++){
    for (int j = 0; j < 16; j++){
      assert((i * j) == h_u_dadda_cla4(i,j));
    }
  }
  return 0;
}