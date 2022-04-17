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

  ha_out |= ((ha_xor0 >> 0) & 0x01ull) << 0;
  ha_out |= ((ha_and0 >> 0) & 0x01ull) << 1;
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

uint64_t u_cla4(uint64_t a, uint64_t b){
  uint8_t u_cla4_out = 0;
  uint8_t u_cla4_pg_logic0_or0 = 0;
  uint8_t u_cla4_pg_logic0_and0 = 0;
  uint8_t u_cla4_pg_logic0_xor0 = 0;
  uint8_t u_cla4_pg_logic1_or0 = 0;
  uint8_t u_cla4_pg_logic1_and0 = 0;
  uint8_t u_cla4_pg_logic1_xor0 = 0;
  uint8_t u_cla4_xor1 = 0;
  uint8_t u_cla4_and0 = 0;
  uint8_t u_cla4_or0 = 0;
  uint8_t u_cla4_pg_logic2_or0 = 0;
  uint8_t u_cla4_pg_logic2_and0 = 0;
  uint8_t u_cla4_pg_logic2_xor0 = 0;
  uint8_t u_cla4_xor2 = 0;
  uint8_t u_cla4_and1 = 0;
  uint8_t u_cla4_and2 = 0;
  uint8_t u_cla4_and3 = 0;
  uint8_t u_cla4_and4 = 0;
  uint8_t u_cla4_or1 = 0;
  uint8_t u_cla4_or2 = 0;
  uint8_t u_cla4_pg_logic3_or0 = 0;
  uint8_t u_cla4_pg_logic3_and0 = 0;
  uint8_t u_cla4_pg_logic3_xor0 = 0;
  uint8_t u_cla4_xor3 = 0;
  uint8_t u_cla4_and5 = 0;
  uint8_t u_cla4_and6 = 0;
  uint8_t u_cla4_and7 = 0;
  uint8_t u_cla4_and8 = 0;
  uint8_t u_cla4_and9 = 0;
  uint8_t u_cla4_and10 = 0;
  uint8_t u_cla4_and11 = 0;
  uint8_t u_cla4_or3 = 0;
  uint8_t u_cla4_or4 = 0;
  uint8_t u_cla4_or5 = 0;

  u_cla4_pg_logic0_or0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cla4_pg_logic0_and0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cla4_pg_logic0_xor0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 2) & 0x01;
  u_cla4_pg_logic1_or0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 0) & 0x01;
  u_cla4_pg_logic1_and0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 1) & 0x01;
  u_cla4_pg_logic1_xor0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 2) & 0x01;
  u_cla4_xor1 = xor_gate(((u_cla4_pg_logic1_xor0 >> 0) & 0x01), ((u_cla4_pg_logic0_and0 >> 0) & 0x01));
  u_cla4_and0 = and_gate(((u_cla4_pg_logic0_and0 >> 0) & 0x01), ((u_cla4_pg_logic1_or0 >> 0) & 0x01));
  u_cla4_or0 = or_gate(((u_cla4_pg_logic1_and0 >> 0) & 0x01), ((u_cla4_and0 >> 0) & 0x01));
  u_cla4_pg_logic2_or0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 0) & 0x01;
  u_cla4_pg_logic2_and0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 1) & 0x01;
  u_cla4_pg_logic2_xor0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 2) & 0x01;
  u_cla4_xor2 = xor_gate(((u_cla4_pg_logic2_xor0 >> 0) & 0x01), ((u_cla4_or0 >> 0) & 0x01));
  u_cla4_and1 = and_gate(((u_cla4_pg_logic2_or0 >> 0) & 0x01), ((u_cla4_pg_logic0_or0 >> 0) & 0x01));
  u_cla4_and2 = and_gate(((u_cla4_pg_logic0_and0 >> 0) & 0x01), ((u_cla4_pg_logic2_or0 >> 0) & 0x01));
  u_cla4_and3 = and_gate(((u_cla4_and2 >> 0) & 0x01), ((u_cla4_pg_logic1_or0 >> 0) & 0x01));
  u_cla4_and4 = and_gate(((u_cla4_pg_logic1_and0 >> 0) & 0x01), ((u_cla4_pg_logic2_or0 >> 0) & 0x01));
  u_cla4_or1 = or_gate(((u_cla4_and3 >> 0) & 0x01), ((u_cla4_and4 >> 0) & 0x01));
  u_cla4_or2 = or_gate(((u_cla4_pg_logic2_and0 >> 0) & 0x01), ((u_cla4_or1 >> 0) & 0x01));
  u_cla4_pg_logic3_or0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 0) & 0x01;
  u_cla4_pg_logic3_and0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 1) & 0x01;
  u_cla4_pg_logic3_xor0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 2) & 0x01;
  u_cla4_xor3 = xor_gate(((u_cla4_pg_logic3_xor0 >> 0) & 0x01), ((u_cla4_or2 >> 0) & 0x01));
  u_cla4_and5 = and_gate(((u_cla4_pg_logic3_or0 >> 0) & 0x01), ((u_cla4_pg_logic1_or0 >> 0) & 0x01));
  u_cla4_and6 = and_gate(((u_cla4_pg_logic0_and0 >> 0) & 0x01), ((u_cla4_pg_logic2_or0 >> 0) & 0x01));
  u_cla4_and7 = and_gate(((u_cla4_pg_logic3_or0 >> 0) & 0x01), ((u_cla4_pg_logic1_or0 >> 0) & 0x01));
  u_cla4_and8 = and_gate(((u_cla4_and6 >> 0) & 0x01), ((u_cla4_and7 >> 0) & 0x01));
  u_cla4_and9 = and_gate(((u_cla4_pg_logic1_and0 >> 0) & 0x01), ((u_cla4_pg_logic3_or0 >> 0) & 0x01));
  u_cla4_and10 = and_gate(((u_cla4_and9 >> 0) & 0x01), ((u_cla4_pg_logic2_or0 >> 0) & 0x01));
  u_cla4_and11 = and_gate(((u_cla4_pg_logic2_and0 >> 0) & 0x01), ((u_cla4_pg_logic3_or0 >> 0) & 0x01));
  u_cla4_or3 = or_gate(((u_cla4_and8 >> 0) & 0x01), ((u_cla4_and11 >> 0) & 0x01));
  u_cla4_or4 = or_gate(((u_cla4_and10 >> 0) & 0x01), ((u_cla4_or3 >> 0) & 0x01));
  u_cla4_or5 = or_gate(((u_cla4_pg_logic3_and0 >> 0) & 0x01), ((u_cla4_or4 >> 0) & 0x01));

  u_cla4_out |= ((u_cla4_pg_logic0_xor0 >> 0) & 0x01ull) << 0;
  u_cla4_out |= ((u_cla4_xor1 >> 0) & 0x01ull) << 1;
  u_cla4_out |= ((u_cla4_xor2 >> 0) & 0x01ull) << 2;
  u_cla4_out |= ((u_cla4_xor3 >> 0) & 0x01ull) << 3;
  u_cla4_out |= ((u_cla4_or5 >> 0) & 0x01ull) << 4;
  return u_cla4_out;
}

uint64_t h_u_csabam8_cla_h1_v11(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_cla_h1_v11_out = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and7_4 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and6_5 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_ha6_5_xor0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_ha6_5_and0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and7_5 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and5_6 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_ha5_6_xor0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_ha5_6_and0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and6_6 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_fa6_6_xor1 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_fa6_6_or0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and7_6 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and4_7 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_ha4_7_xor0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_ha4_7_and0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and5_7 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_fa5_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_fa5_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and6_7 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h1_v11_and7_7 = 0;
  uint64_t h_u_csabam8_cla_h1_v11_u_cla4_a = 0;
  uint64_t h_u_csabam8_cla_h1_v11_u_cla4_b = 0;
  uint64_t h_u_csabam8_cla_h1_v11_u_cla4_out = 0;

  h_u_csabam8_cla_h1_v11_and7_4 = and_gate(((a >> 7) & 0x01), ((b >> 4) & 0x01));
  h_u_csabam8_cla_h1_v11_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h1_v11_ha6_5_xor0 = (ha(((h_u_csabam8_cla_h1_v11_and6_5 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_and7_4 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h1_v11_ha6_5_and0 = (ha(((h_u_csabam8_cla_h1_v11_and6_5 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_and7_4 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h1_v11_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h1_v11_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h1_v11_ha5_6_xor0 = (ha(((h_u_csabam8_cla_h1_v11_and5_6 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha6_5_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h1_v11_ha5_6_and0 = (ha(((h_u_csabam8_cla_h1_v11_and5_6 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha6_5_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h1_v11_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h1_v11_fa6_6_xor1 = (fa(((h_u_csabam8_cla_h1_v11_and6_6 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_and7_5 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha6_5_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h1_v11_fa6_6_or0 = (fa(((h_u_csabam8_cla_h1_v11_and6_6 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_and7_5 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha6_5_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h1_v11_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h1_v11_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h1_v11_ha4_7_xor0 = (ha(((h_u_csabam8_cla_h1_v11_and4_7 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha5_6_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h1_v11_ha4_7_and0 = (ha(((h_u_csabam8_cla_h1_v11_and4_7 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha5_6_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h1_v11_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h1_v11_fa5_7_xor1 = (fa(((h_u_csabam8_cla_h1_v11_and5_7 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha5_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h1_v11_fa5_7_or0 = (fa(((h_u_csabam8_cla_h1_v11_and5_7 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_fa6_6_xor1 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_ha5_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h1_v11_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h1_v11_fa6_7_xor1 = (fa(((h_u_csabam8_cla_h1_v11_and6_7 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_and7_6 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_fa6_6_or0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h1_v11_fa6_7_or0 = (fa(((h_u_csabam8_cla_h1_v11_and6_7 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_and7_6 >> 0) & 0x01), ((h_u_csabam8_cla_h1_v11_fa6_6_or0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h1_v11_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h1_v11_u_cla4_a |= ((h_u_csabam8_cla_h1_v11_fa5_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_cla_h1_v11_u_cla4_a |= ((h_u_csabam8_cla_h1_v11_fa6_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csabam8_cla_h1_v11_u_cla4_a |= ((h_u_csabam8_cla_h1_v11_and7_7 >> 0) & 0x01ull) << 2;
  h_u_csabam8_cla_h1_v11_u_cla4_a |= (0x00) << 3;
  h_u_csabam8_cla_h1_v11_u_cla4_b |= (0x00) << 0;
  h_u_csabam8_cla_h1_v11_u_cla4_b |= ((h_u_csabam8_cla_h1_v11_fa5_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_cla_h1_v11_u_cla4_b |= ((h_u_csabam8_cla_h1_v11_fa6_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_cla_h1_v11_u_cla4_b |= (0x00) << 3;
  h_u_csabam8_cla_h1_v11_u_cla4_out = u_cla4(h_u_csabam8_cla_h1_v11_u_cla4_a, h_u_csabam8_cla_h1_v11_u_cla4_b);

  h_u_csabam8_cla_h1_v11_out |= (0x00) << 0;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 1;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 2;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 3;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 4;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 5;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 6;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 7;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 8;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 9;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 10;
  h_u_csabam8_cla_h1_v11_out |= ((h_u_csabam8_cla_h1_v11_u_cla4_out >> 0) & 0x01ull) << 11;
  h_u_csabam8_cla_h1_v11_out |= ((h_u_csabam8_cla_h1_v11_u_cla4_out >> 1) & 0x01ull) << 12;
  h_u_csabam8_cla_h1_v11_out |= ((h_u_csabam8_cla_h1_v11_u_cla4_out >> 2) & 0x01ull) << 13;
  h_u_csabam8_cla_h1_v11_out |= ((h_u_csabam8_cla_h1_v11_u_cla4_out >> 3) & 0x01ull) << 14;
  h_u_csabam8_cla_h1_v11_out |= (0x00) << 15;
  return h_u_csabam8_cla_h1_v11_out;
}