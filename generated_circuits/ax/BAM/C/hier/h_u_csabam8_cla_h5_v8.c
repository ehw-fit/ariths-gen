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

uint64_t u_cla7(uint64_t a, uint64_t b){
  uint8_t u_cla7_out = 0;
  uint8_t u_cla7_pg_logic0_or0 = 0;
  uint8_t u_cla7_pg_logic0_and0 = 0;
  uint8_t u_cla7_pg_logic0_xor0 = 0;
  uint8_t u_cla7_pg_logic1_or0 = 0;
  uint8_t u_cla7_pg_logic1_and0 = 0;
  uint8_t u_cla7_pg_logic1_xor0 = 0;
  uint8_t u_cla7_xor1 = 0;
  uint8_t u_cla7_and0 = 0;
  uint8_t u_cla7_or0 = 0;
  uint8_t u_cla7_pg_logic2_or0 = 0;
  uint8_t u_cla7_pg_logic2_and0 = 0;
  uint8_t u_cla7_pg_logic2_xor0 = 0;
  uint8_t u_cla7_xor2 = 0;
  uint8_t u_cla7_and1 = 0;
  uint8_t u_cla7_and2 = 0;
  uint8_t u_cla7_and3 = 0;
  uint8_t u_cla7_and4 = 0;
  uint8_t u_cla7_or1 = 0;
  uint8_t u_cla7_or2 = 0;
  uint8_t u_cla7_pg_logic3_or0 = 0;
  uint8_t u_cla7_pg_logic3_and0 = 0;
  uint8_t u_cla7_pg_logic3_xor0 = 0;
  uint8_t u_cla7_xor3 = 0;
  uint8_t u_cla7_and5 = 0;
  uint8_t u_cla7_and6 = 0;
  uint8_t u_cla7_and7 = 0;
  uint8_t u_cla7_and8 = 0;
  uint8_t u_cla7_and9 = 0;
  uint8_t u_cla7_and10 = 0;
  uint8_t u_cla7_and11 = 0;
  uint8_t u_cla7_or3 = 0;
  uint8_t u_cla7_or4 = 0;
  uint8_t u_cla7_or5 = 0;
  uint8_t u_cla7_pg_logic4_or0 = 0;
  uint8_t u_cla7_pg_logic4_and0 = 0;
  uint8_t u_cla7_pg_logic4_xor0 = 0;
  uint8_t u_cla7_xor4 = 0;
  uint8_t u_cla7_and12 = 0;
  uint8_t u_cla7_or6 = 0;
  uint8_t u_cla7_pg_logic5_or0 = 0;
  uint8_t u_cla7_pg_logic5_and0 = 0;
  uint8_t u_cla7_pg_logic5_xor0 = 0;
  uint8_t u_cla7_xor5 = 0;
  uint8_t u_cla7_and13 = 0;
  uint8_t u_cla7_and14 = 0;
  uint8_t u_cla7_and15 = 0;
  uint8_t u_cla7_or7 = 0;
  uint8_t u_cla7_or8 = 0;
  uint8_t u_cla7_pg_logic6_or0 = 0;
  uint8_t u_cla7_pg_logic6_and0 = 0;
  uint8_t u_cla7_pg_logic6_xor0 = 0;
  uint8_t u_cla7_xor6 = 0;
  uint8_t u_cla7_and16 = 0;
  uint8_t u_cla7_and17 = 0;
  uint8_t u_cla7_and18 = 0;
  uint8_t u_cla7_and19 = 0;
  uint8_t u_cla7_and20 = 0;
  uint8_t u_cla7_and21 = 0;
  uint8_t u_cla7_or9 = 0;
  uint8_t u_cla7_or10 = 0;
  uint8_t u_cla7_or11 = 0;

  u_cla7_pg_logic0_or0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic0_and0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic0_xor0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 2) & 0x01;
  u_cla7_pg_logic1_or0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic1_and0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic1_xor0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 2) & 0x01;
  u_cla7_xor1 = xor_gate(((u_cla7_pg_logic1_xor0 >> 0) & 0x01), ((u_cla7_pg_logic0_and0 >> 0) & 0x01));
  u_cla7_and0 = and_gate(((u_cla7_pg_logic0_and0 >> 0) & 0x01), ((u_cla7_pg_logic1_or0 >> 0) & 0x01));
  u_cla7_or0 = or_gate(((u_cla7_pg_logic1_and0 >> 0) & 0x01), ((u_cla7_and0 >> 0) & 0x01));
  u_cla7_pg_logic2_or0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic2_and0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic2_xor0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 2) & 0x01;
  u_cla7_xor2 = xor_gate(((u_cla7_pg_logic2_xor0 >> 0) & 0x01), ((u_cla7_or0 >> 0) & 0x01));
  u_cla7_and1 = and_gate(((u_cla7_pg_logic2_or0 >> 0) & 0x01), ((u_cla7_pg_logic0_or0 >> 0) & 0x01));
  u_cla7_and2 = and_gate(((u_cla7_pg_logic0_and0 >> 0) & 0x01), ((u_cla7_pg_logic2_or0 >> 0) & 0x01));
  u_cla7_and3 = and_gate(((u_cla7_and2 >> 0) & 0x01), ((u_cla7_pg_logic1_or0 >> 0) & 0x01));
  u_cla7_and4 = and_gate(((u_cla7_pg_logic1_and0 >> 0) & 0x01), ((u_cla7_pg_logic2_or0 >> 0) & 0x01));
  u_cla7_or1 = or_gate(((u_cla7_and3 >> 0) & 0x01), ((u_cla7_and4 >> 0) & 0x01));
  u_cla7_or2 = or_gate(((u_cla7_pg_logic2_and0 >> 0) & 0x01), ((u_cla7_or1 >> 0) & 0x01));
  u_cla7_pg_logic3_or0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic3_and0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic3_xor0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 2) & 0x01;
  u_cla7_xor3 = xor_gate(((u_cla7_pg_logic3_xor0 >> 0) & 0x01), ((u_cla7_or2 >> 0) & 0x01));
  u_cla7_and5 = and_gate(((u_cla7_pg_logic3_or0 >> 0) & 0x01), ((u_cla7_pg_logic1_or0 >> 0) & 0x01));
  u_cla7_and6 = and_gate(((u_cla7_pg_logic0_and0 >> 0) & 0x01), ((u_cla7_pg_logic2_or0 >> 0) & 0x01));
  u_cla7_and7 = and_gate(((u_cla7_pg_logic3_or0 >> 0) & 0x01), ((u_cla7_pg_logic1_or0 >> 0) & 0x01));
  u_cla7_and8 = and_gate(((u_cla7_and6 >> 0) & 0x01), ((u_cla7_and7 >> 0) & 0x01));
  u_cla7_and9 = and_gate(((u_cla7_pg_logic1_and0 >> 0) & 0x01), ((u_cla7_pg_logic3_or0 >> 0) & 0x01));
  u_cla7_and10 = and_gate(((u_cla7_and9 >> 0) & 0x01), ((u_cla7_pg_logic2_or0 >> 0) & 0x01));
  u_cla7_and11 = and_gate(((u_cla7_pg_logic2_and0 >> 0) & 0x01), ((u_cla7_pg_logic3_or0 >> 0) & 0x01));
  u_cla7_or3 = or_gate(((u_cla7_and8 >> 0) & 0x01), ((u_cla7_and11 >> 0) & 0x01));
  u_cla7_or4 = or_gate(((u_cla7_and10 >> 0) & 0x01), ((u_cla7_or3 >> 0) & 0x01));
  u_cla7_or5 = or_gate(((u_cla7_pg_logic3_and0 >> 0) & 0x01), ((u_cla7_or4 >> 0) & 0x01));
  u_cla7_pg_logic4_or0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic4_and0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic4_xor0 = (pg_logic(((a >> 4) & 0x01), ((b >> 4) & 0x01)) >> 2) & 0x01;
  u_cla7_xor4 = xor_gate(((u_cla7_pg_logic4_xor0 >> 0) & 0x01), ((u_cla7_or5 >> 0) & 0x01));
  u_cla7_and12 = and_gate(((u_cla7_or5 >> 0) & 0x01), ((u_cla7_pg_logic4_or0 >> 0) & 0x01));
  u_cla7_or6 = or_gate(((u_cla7_pg_logic4_and0 >> 0) & 0x01), ((u_cla7_and12 >> 0) & 0x01));
  u_cla7_pg_logic5_or0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic5_and0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic5_xor0 = (pg_logic(((a >> 5) & 0x01), ((b >> 5) & 0x01)) >> 2) & 0x01;
  u_cla7_xor5 = xor_gate(((u_cla7_pg_logic5_xor0 >> 0) & 0x01), ((u_cla7_or6 >> 0) & 0x01));
  u_cla7_and13 = and_gate(((u_cla7_or5 >> 0) & 0x01), ((u_cla7_pg_logic5_or0 >> 0) & 0x01));
  u_cla7_and14 = and_gate(((u_cla7_and13 >> 0) & 0x01), ((u_cla7_pg_logic4_or0 >> 0) & 0x01));
  u_cla7_and15 = and_gate(((u_cla7_pg_logic4_and0 >> 0) & 0x01), ((u_cla7_pg_logic5_or0 >> 0) & 0x01));
  u_cla7_or7 = or_gate(((u_cla7_and14 >> 0) & 0x01), ((u_cla7_and15 >> 0) & 0x01));
  u_cla7_or8 = or_gate(((u_cla7_pg_logic5_and0 >> 0) & 0x01), ((u_cla7_or7 >> 0) & 0x01));
  u_cla7_pg_logic6_or0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 0) & 0x01;
  u_cla7_pg_logic6_and0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 1) & 0x01;
  u_cla7_pg_logic6_xor0 = (pg_logic(((a >> 6) & 0x01), ((b >> 6) & 0x01)) >> 2) & 0x01;
  u_cla7_xor6 = xor_gate(((u_cla7_pg_logic6_xor0 >> 0) & 0x01), ((u_cla7_or8 >> 0) & 0x01));
  u_cla7_and16 = and_gate(((u_cla7_or5 >> 0) & 0x01), ((u_cla7_pg_logic5_or0 >> 0) & 0x01));
  u_cla7_and17 = and_gate(((u_cla7_pg_logic6_or0 >> 0) & 0x01), ((u_cla7_pg_logic4_or0 >> 0) & 0x01));
  u_cla7_and18 = and_gate(((u_cla7_and16 >> 0) & 0x01), ((u_cla7_and17 >> 0) & 0x01));
  u_cla7_and19 = and_gate(((u_cla7_pg_logic4_and0 >> 0) & 0x01), ((u_cla7_pg_logic6_or0 >> 0) & 0x01));
  u_cla7_and20 = and_gate(((u_cla7_and19 >> 0) & 0x01), ((u_cla7_pg_logic5_or0 >> 0) & 0x01));
  u_cla7_and21 = and_gate(((u_cla7_pg_logic5_and0 >> 0) & 0x01), ((u_cla7_pg_logic6_or0 >> 0) & 0x01));
  u_cla7_or9 = or_gate(((u_cla7_and18 >> 0) & 0x01), ((u_cla7_and20 >> 0) & 0x01));
  u_cla7_or10 = or_gate(((u_cla7_or9 >> 0) & 0x01), ((u_cla7_and21 >> 0) & 0x01));
  u_cla7_or11 = or_gate(((u_cla7_pg_logic6_and0 >> 0) & 0x01), ((u_cla7_or10 >> 0) & 0x01));

  u_cla7_out |= ((u_cla7_pg_logic0_xor0 >> 0) & 0x01ull) << 0;
  u_cla7_out |= ((u_cla7_xor1 >> 0) & 0x01ull) << 1;
  u_cla7_out |= ((u_cla7_xor2 >> 0) & 0x01ull) << 2;
  u_cla7_out |= ((u_cla7_xor3 >> 0) & 0x01ull) << 3;
  u_cla7_out |= ((u_cla7_xor4 >> 0) & 0x01ull) << 4;
  u_cla7_out |= ((u_cla7_xor5 >> 0) & 0x01ull) << 5;
  u_cla7_out |= ((u_cla7_xor6 >> 0) & 0x01ull) << 6;
  u_cla7_out |= ((u_cla7_or11 >> 0) & 0x01ull) << 7;
  return u_cla7_out;
}

uint64_t h_u_csabam8_cla_h5_v8(uint64_t a, uint64_t b){
  uint64_t h_u_csabam8_cla_h5_v8_out = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and3_5 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and4_5 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and5_5 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and6_5 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and7_5 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and2_6 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha2_6_xor0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha2_6_and0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and3_6 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha3_6_xor0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha3_6_and0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and4_6 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha4_6_xor0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha4_6_and0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and5_6 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha5_6_xor0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha5_6_and0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and6_6 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha6_6_xor0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha6_6_and0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and7_6 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and1_7 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha1_7_xor0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_ha1_7_and0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and2_7 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa2_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa2_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and3_7 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa3_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa3_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and4_7 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa4_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa4_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and5_7 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa5_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa5_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and6_7 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa6_7_xor1 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_fa6_7_or0 = 0;
  uint8_t h_u_csabam8_cla_h5_v8_and7_7 = 0;
  uint64_t h_u_csabam8_cla_h5_v8_u_cla7_a = 0;
  uint64_t h_u_csabam8_cla_h5_v8_u_cla7_b = 0;
  uint64_t h_u_csabam8_cla_h5_v8_u_cla7_out = 0;

  h_u_csabam8_cla_h5_v8_and3_5 = and_gate(((a >> 3) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h5_v8_and4_5 = and_gate(((a >> 4) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h5_v8_and5_5 = and_gate(((a >> 5) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h5_v8_and6_5 = and_gate(((a >> 6) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h5_v8_and7_5 = and_gate(((a >> 7) & 0x01), ((b >> 5) & 0x01));
  h_u_csabam8_cla_h5_v8_and2_6 = and_gate(((a >> 2) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h5_v8_ha2_6_xor0 = (ha(((h_u_csabam8_cla_h5_v8_and2_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and3_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_ha2_6_and0 = (ha(((h_u_csabam8_cla_h5_v8_and2_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and3_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and3_6 = and_gate(((a >> 3) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h5_v8_ha3_6_xor0 = (ha(((h_u_csabam8_cla_h5_v8_and3_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and4_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_ha3_6_and0 = (ha(((h_u_csabam8_cla_h5_v8_and3_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and4_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and4_6 = and_gate(((a >> 4) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h5_v8_ha4_6_xor0 = (ha(((h_u_csabam8_cla_h5_v8_and4_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and5_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_ha4_6_and0 = (ha(((h_u_csabam8_cla_h5_v8_and4_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and5_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and5_6 = and_gate(((a >> 5) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h5_v8_ha5_6_xor0 = (ha(((h_u_csabam8_cla_h5_v8_and5_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and6_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_ha5_6_and0 = (ha(((h_u_csabam8_cla_h5_v8_and5_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and6_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and6_6 = and_gate(((a >> 6) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h5_v8_ha6_6_xor0 = (ha(((h_u_csabam8_cla_h5_v8_and6_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and7_5 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_ha6_6_and0 = (ha(((h_u_csabam8_cla_h5_v8_and6_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and7_5 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and7_6 = and_gate(((a >> 7) & 0x01), ((b >> 6) & 0x01));
  h_u_csabam8_cla_h5_v8_and1_7 = and_gate(((a >> 1) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_ha1_7_xor0 = (ha(((h_u_csabam8_cla_h5_v8_and1_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha2_6_xor0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_ha1_7_and0 = (ha(((h_u_csabam8_cla_h5_v8_and1_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha2_6_xor0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and2_7 = and_gate(((a >> 2) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_fa2_7_xor1 = (fa(((h_u_csabam8_cla_h5_v8_and2_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha3_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha2_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_fa2_7_or0 = (fa(((h_u_csabam8_cla_h5_v8_and2_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha3_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha2_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and3_7 = and_gate(((a >> 3) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_fa3_7_xor1 = (fa(((h_u_csabam8_cla_h5_v8_and3_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha4_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha3_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_fa3_7_or0 = (fa(((h_u_csabam8_cla_h5_v8_and3_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha4_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha3_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and4_7 = and_gate(((a >> 4) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_fa4_7_xor1 = (fa(((h_u_csabam8_cla_h5_v8_and4_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha5_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha4_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_fa4_7_or0 = (fa(((h_u_csabam8_cla_h5_v8_and4_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha5_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha4_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and5_7 = and_gate(((a >> 5) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_fa5_7_xor1 = (fa(((h_u_csabam8_cla_h5_v8_and5_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha6_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha5_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_fa5_7_or0 = (fa(((h_u_csabam8_cla_h5_v8_and5_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha6_6_xor0 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha5_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and6_7 = and_gate(((a >> 6) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_fa6_7_xor1 = (fa(((h_u_csabam8_cla_h5_v8_and6_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and7_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha6_6_and0 >> 0) & 0x01)) >> 0) & 0x01;
  h_u_csabam8_cla_h5_v8_fa6_7_or0 = (fa(((h_u_csabam8_cla_h5_v8_and6_7 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_and7_6 >> 0) & 0x01), ((h_u_csabam8_cla_h5_v8_ha6_6_and0 >> 0) & 0x01)) >> 1) & 0x01;
  h_u_csabam8_cla_h5_v8_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));
  h_u_csabam8_cla_h5_v8_u_cla7_a |= ((h_u_csabam8_cla_h5_v8_fa2_7_xor1 >> 0) & 0x01ull) << 0;
  h_u_csabam8_cla_h5_v8_u_cla7_a |= ((h_u_csabam8_cla_h5_v8_fa3_7_xor1 >> 0) & 0x01ull) << 1;
  h_u_csabam8_cla_h5_v8_u_cla7_a |= ((h_u_csabam8_cla_h5_v8_fa4_7_xor1 >> 0) & 0x01ull) << 2;
  h_u_csabam8_cla_h5_v8_u_cla7_a |= ((h_u_csabam8_cla_h5_v8_fa5_7_xor1 >> 0) & 0x01ull) << 3;
  h_u_csabam8_cla_h5_v8_u_cla7_a |= ((h_u_csabam8_cla_h5_v8_fa6_7_xor1 >> 0) & 0x01ull) << 4;
  h_u_csabam8_cla_h5_v8_u_cla7_a |= ((h_u_csabam8_cla_h5_v8_and7_7 >> 0) & 0x01ull) << 5;
  h_u_csabam8_cla_h5_v8_u_cla7_a |= (0x00) << 6;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= (0x00) << 0;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= ((h_u_csabam8_cla_h5_v8_fa2_7_or0 >> 0) & 0x01ull) << 1;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= ((h_u_csabam8_cla_h5_v8_fa3_7_or0 >> 0) & 0x01ull) << 2;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= ((h_u_csabam8_cla_h5_v8_fa4_7_or0 >> 0) & 0x01ull) << 3;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= ((h_u_csabam8_cla_h5_v8_fa5_7_or0 >> 0) & 0x01ull) << 4;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= ((h_u_csabam8_cla_h5_v8_fa6_7_or0 >> 0) & 0x01ull) << 5;
  h_u_csabam8_cla_h5_v8_u_cla7_b |= (0x00) << 6;
  h_u_csabam8_cla_h5_v8_u_cla7_out = u_cla7(h_u_csabam8_cla_h5_v8_u_cla7_a, h_u_csabam8_cla_h5_v8_u_cla7_b);

  h_u_csabam8_cla_h5_v8_out |= (0x00) << 0;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 1;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 2;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 3;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 4;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 5;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 6;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 7;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 0) & 0x01ull) << 8;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 1) & 0x01ull) << 9;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 2) & 0x01ull) << 10;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 3) & 0x01ull) << 11;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 4) & 0x01ull) << 12;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 5) & 0x01ull) << 13;
  h_u_csabam8_cla_h5_v8_out |= ((h_u_csabam8_cla_h5_v8_u_cla7_out >> 6) & 0x01ull) << 14;
  h_u_csabam8_cla_h5_v8_out |= (0x00) << 15;
  return h_u_csabam8_cla_h5_v8_out;
}