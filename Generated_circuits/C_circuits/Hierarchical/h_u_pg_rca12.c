#include <stdio.h>
#include <stdint.h>

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t xnor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint8_t nor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) | ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) | ((_b >> 0) & 0x01);
}

uint8_t constant_wire_value_0(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t constant_wire_value_0_a = 0;
  uint8_t constant_wire_value_0_b = 0;
  uint8_t constant_wire_value_0_y0 = 0;
  uint8_t constant_wire_value_0_y1 = 0;
  uint8_t constant_wire_0 = 0;

  constant_wire_value_0_a = ((a >> 0) & 0x01);
  constant_wire_value_0_b = ((b >> 0) & 0x01);
  constant_wire_value_0_y0 = xor_gate(constant_wire_value_0_a, constant_wire_value_0_b);
  constant_wire_value_0_y1 = xnor_gate(constant_wire_value_0_a, constant_wire_value_0_b);
  constant_wire_0 = nor_gate(constant_wire_value_0_y0, constant_wire_value_0_y1);

  out |= (constant_wire_0 & 0x01) << 0;
  return out;
}

uint8_t fa_cla(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t fa_cla_a = 0;
  uint8_t fa_cla_b = 0;
  uint8_t fa_cla_y0 = 0;
  uint8_t fa_cla_y1 = 0;
  uint8_t fa_cla_cin = 0;
  uint8_t fa_cla_y2 = 0;

  fa_cla_a = ((a >> 0) & 0x01);
  fa_cla_b = ((b >> 0) & 0x01);
  fa_cla_cin = ((cin >> 0) & 0x01);
  fa_cla_y0 = xor_gate(fa_cla_a, fa_cla_b);
  fa_cla_y1 = and_gate(fa_cla_a, fa_cla_b);
  fa_cla_y2 = xor_gate(fa_cla_y0, fa_cla_cin);

  out |= (fa_cla_y0 & 0x01) << 0;
  out |= (fa_cla_y1 & 0x01) << 1;
  out |= (fa_cla_y2 & 0x01) << 2;
  return out;
}

uint64_t h_u_pg_rca12(uint64_t a, uint64_t b){
  uint64_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t a_4 = 0;
  uint8_t a_5 = 0;
  uint8_t a_6 = 0;
  uint8_t a_7 = 0;
  uint8_t a_8 = 0;
  uint8_t a_9 = 0;
  uint8_t a_10 = 0;
  uint8_t a_11 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t b_4 = 0;
  uint8_t b_5 = 0;
  uint8_t b_6 = 0;
  uint8_t b_7 = 0;
  uint8_t b_8 = 0;
  uint8_t b_9 = 0;
  uint8_t b_10 = 0;
  uint8_t b_11 = 0;
  uint8_t constant_wire_0 = 0;
  uint8_t h_u_pg_rca12_fa0_y0 = 0;
  uint8_t h_u_pg_rca12_fa0_y1 = 0;
  uint8_t h_u_pg_rca12_fa0_y2 = 0;
  uint8_t h_u_pg_rca12_and0_y0 = 0;
  uint8_t h_u_pg_rca12_or0_y0 = 0;
  uint8_t h_u_pg_rca12_fa1_y0 = 0;
  uint8_t h_u_pg_rca12_fa1_y1 = 0;
  uint8_t h_u_pg_rca12_fa1_y2 = 0;
  uint8_t h_u_pg_rca12_and1_y0 = 0;
  uint8_t h_u_pg_rca12_or1_y0 = 0;
  uint8_t h_u_pg_rca12_fa2_y0 = 0;
  uint8_t h_u_pg_rca12_fa2_y1 = 0;
  uint8_t h_u_pg_rca12_fa2_y2 = 0;
  uint8_t h_u_pg_rca12_and2_y0 = 0;
  uint8_t h_u_pg_rca12_or2_y0 = 0;
  uint8_t h_u_pg_rca12_fa3_y0 = 0;
  uint8_t h_u_pg_rca12_fa3_y1 = 0;
  uint8_t h_u_pg_rca12_fa3_y2 = 0;
  uint8_t h_u_pg_rca12_and3_y0 = 0;
  uint8_t h_u_pg_rca12_or3_y0 = 0;
  uint8_t h_u_pg_rca12_fa4_y0 = 0;
  uint8_t h_u_pg_rca12_fa4_y1 = 0;
  uint8_t h_u_pg_rca12_fa4_y2 = 0;
  uint8_t h_u_pg_rca12_and4_y0 = 0;
  uint8_t h_u_pg_rca12_or4_y0 = 0;
  uint8_t h_u_pg_rca12_fa5_y0 = 0;
  uint8_t h_u_pg_rca12_fa5_y1 = 0;
  uint8_t h_u_pg_rca12_fa5_y2 = 0;
  uint8_t h_u_pg_rca12_and5_y0 = 0;
  uint8_t h_u_pg_rca12_or5_y0 = 0;
  uint8_t h_u_pg_rca12_fa6_y0 = 0;
  uint8_t h_u_pg_rca12_fa6_y1 = 0;
  uint8_t h_u_pg_rca12_fa6_y2 = 0;
  uint8_t h_u_pg_rca12_and6_y0 = 0;
  uint8_t h_u_pg_rca12_or6_y0 = 0;
  uint8_t h_u_pg_rca12_fa7_y0 = 0;
  uint8_t h_u_pg_rca12_fa7_y1 = 0;
  uint8_t h_u_pg_rca12_fa7_y2 = 0;
  uint8_t h_u_pg_rca12_and7_y0 = 0;
  uint8_t h_u_pg_rca12_or7_y0 = 0;
  uint8_t h_u_pg_rca12_fa8_y0 = 0;
  uint8_t h_u_pg_rca12_fa8_y1 = 0;
  uint8_t h_u_pg_rca12_fa8_y2 = 0;
  uint8_t h_u_pg_rca12_and8_y0 = 0;
  uint8_t h_u_pg_rca12_or8_y0 = 0;
  uint8_t h_u_pg_rca12_fa9_y0 = 0;
  uint8_t h_u_pg_rca12_fa9_y1 = 0;
  uint8_t h_u_pg_rca12_fa9_y2 = 0;
  uint8_t h_u_pg_rca12_and9_y0 = 0;
  uint8_t h_u_pg_rca12_or9_y0 = 0;
  uint8_t h_u_pg_rca12_fa10_y0 = 0;
  uint8_t h_u_pg_rca12_fa10_y1 = 0;
  uint8_t h_u_pg_rca12_fa10_y2 = 0;
  uint8_t h_u_pg_rca12_and10_y0 = 0;
  uint8_t h_u_pg_rca12_or10_y0 = 0;
  uint8_t h_u_pg_rca12_fa11_y0 = 0;
  uint8_t h_u_pg_rca12_fa11_y1 = 0;
  uint8_t h_u_pg_rca12_fa11_y2 = 0;
  uint8_t h_u_pg_rca12_and11_y0 = 0;
  uint8_t h_u_pg_rca12_or11_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  a_4 = ((a >> 4) & 0x01);
  a_5 = ((a >> 5) & 0x01);
  a_6 = ((a >> 6) & 0x01);
  a_7 = ((a >> 7) & 0x01);
  a_8 = ((a >> 8) & 0x01);
  a_9 = ((a >> 9) & 0x01);
  a_10 = ((a >> 10) & 0x01);
  a_11 = ((a >> 11) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  b_4 = ((b >> 4) & 0x01);
  b_5 = ((b >> 5) & 0x01);
  b_6 = ((b >> 6) & 0x01);
  b_7 = ((b >> 7) & 0x01);
  b_8 = ((b >> 8) & 0x01);
  b_9 = ((b >> 9) & 0x01);
  b_10 = ((b >> 10) & 0x01);
  b_11 = ((b >> 11) & 0x01);
  constant_wire_0 = (constant_wire_value_0(a_0, b_0) >> 0) & 0x01;
  h_u_pg_rca12_fa0_y0 = (fa_cla(a_0, b_0, constant_wire_0) >> 0) & 0x01;
  h_u_pg_rca12_fa0_y1 = (fa_cla(a_0, b_0, constant_wire_0) >> 1) & 0x01;
  h_u_pg_rca12_fa0_y2 = (fa_cla(a_0, b_0, constant_wire_0) >> 2) & 0x01;
  h_u_pg_rca12_and0_y0 = and_gate(constant_wire_0, h_u_pg_rca12_fa0_y0);
  h_u_pg_rca12_or0_y0 = or_gate(h_u_pg_rca12_and0_y0, h_u_pg_rca12_fa0_y1);
  h_u_pg_rca12_fa1_y0 = (fa_cla(a_1, b_1, h_u_pg_rca12_or0_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa1_y1 = (fa_cla(a_1, b_1, h_u_pg_rca12_or0_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa1_y2 = (fa_cla(a_1, b_1, h_u_pg_rca12_or0_y0) >> 2) & 0x01;
  h_u_pg_rca12_and1_y0 = and_gate(h_u_pg_rca12_or0_y0, h_u_pg_rca12_fa1_y0);
  h_u_pg_rca12_or1_y0 = or_gate(h_u_pg_rca12_and1_y0, h_u_pg_rca12_fa1_y1);
  h_u_pg_rca12_fa2_y0 = (fa_cla(a_2, b_2, h_u_pg_rca12_or1_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa2_y1 = (fa_cla(a_2, b_2, h_u_pg_rca12_or1_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa2_y2 = (fa_cla(a_2, b_2, h_u_pg_rca12_or1_y0) >> 2) & 0x01;
  h_u_pg_rca12_and2_y0 = and_gate(h_u_pg_rca12_or1_y0, h_u_pg_rca12_fa2_y0);
  h_u_pg_rca12_or2_y0 = or_gate(h_u_pg_rca12_and2_y0, h_u_pg_rca12_fa2_y1);
  h_u_pg_rca12_fa3_y0 = (fa_cla(a_3, b_3, h_u_pg_rca12_or2_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa3_y1 = (fa_cla(a_3, b_3, h_u_pg_rca12_or2_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa3_y2 = (fa_cla(a_3, b_3, h_u_pg_rca12_or2_y0) >> 2) & 0x01;
  h_u_pg_rca12_and3_y0 = and_gate(h_u_pg_rca12_or2_y0, h_u_pg_rca12_fa3_y0);
  h_u_pg_rca12_or3_y0 = or_gate(h_u_pg_rca12_and3_y0, h_u_pg_rca12_fa3_y1);
  h_u_pg_rca12_fa4_y0 = (fa_cla(a_4, b_4, h_u_pg_rca12_or3_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa4_y1 = (fa_cla(a_4, b_4, h_u_pg_rca12_or3_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa4_y2 = (fa_cla(a_4, b_4, h_u_pg_rca12_or3_y0) >> 2) & 0x01;
  h_u_pg_rca12_and4_y0 = and_gate(h_u_pg_rca12_or3_y0, h_u_pg_rca12_fa4_y0);
  h_u_pg_rca12_or4_y0 = or_gate(h_u_pg_rca12_and4_y0, h_u_pg_rca12_fa4_y1);
  h_u_pg_rca12_fa5_y0 = (fa_cla(a_5, b_5, h_u_pg_rca12_or4_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa5_y1 = (fa_cla(a_5, b_5, h_u_pg_rca12_or4_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa5_y2 = (fa_cla(a_5, b_5, h_u_pg_rca12_or4_y0) >> 2) & 0x01;
  h_u_pg_rca12_and5_y0 = and_gate(h_u_pg_rca12_or4_y0, h_u_pg_rca12_fa5_y0);
  h_u_pg_rca12_or5_y0 = or_gate(h_u_pg_rca12_and5_y0, h_u_pg_rca12_fa5_y1);
  h_u_pg_rca12_fa6_y0 = (fa_cla(a_6, b_6, h_u_pg_rca12_or5_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa6_y1 = (fa_cla(a_6, b_6, h_u_pg_rca12_or5_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa6_y2 = (fa_cla(a_6, b_6, h_u_pg_rca12_or5_y0) >> 2) & 0x01;
  h_u_pg_rca12_and6_y0 = and_gate(h_u_pg_rca12_or5_y0, h_u_pg_rca12_fa6_y0);
  h_u_pg_rca12_or6_y0 = or_gate(h_u_pg_rca12_and6_y0, h_u_pg_rca12_fa6_y1);
  h_u_pg_rca12_fa7_y0 = (fa_cla(a_7, b_7, h_u_pg_rca12_or6_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa7_y1 = (fa_cla(a_7, b_7, h_u_pg_rca12_or6_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa7_y2 = (fa_cla(a_7, b_7, h_u_pg_rca12_or6_y0) >> 2) & 0x01;
  h_u_pg_rca12_and7_y0 = and_gate(h_u_pg_rca12_or6_y0, h_u_pg_rca12_fa7_y0);
  h_u_pg_rca12_or7_y0 = or_gate(h_u_pg_rca12_and7_y0, h_u_pg_rca12_fa7_y1);
  h_u_pg_rca12_fa8_y0 = (fa_cla(a_8, b_8, h_u_pg_rca12_or7_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa8_y1 = (fa_cla(a_8, b_8, h_u_pg_rca12_or7_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa8_y2 = (fa_cla(a_8, b_8, h_u_pg_rca12_or7_y0) >> 2) & 0x01;
  h_u_pg_rca12_and8_y0 = and_gate(h_u_pg_rca12_or7_y0, h_u_pg_rca12_fa8_y0);
  h_u_pg_rca12_or8_y0 = or_gate(h_u_pg_rca12_and8_y0, h_u_pg_rca12_fa8_y1);
  h_u_pg_rca12_fa9_y0 = (fa_cla(a_9, b_9, h_u_pg_rca12_or8_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa9_y1 = (fa_cla(a_9, b_9, h_u_pg_rca12_or8_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa9_y2 = (fa_cla(a_9, b_9, h_u_pg_rca12_or8_y0) >> 2) & 0x01;
  h_u_pg_rca12_and9_y0 = and_gate(h_u_pg_rca12_or8_y0, h_u_pg_rca12_fa9_y0);
  h_u_pg_rca12_or9_y0 = or_gate(h_u_pg_rca12_and9_y0, h_u_pg_rca12_fa9_y1);
  h_u_pg_rca12_fa10_y0 = (fa_cla(a_10, b_10, h_u_pg_rca12_or9_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa10_y1 = (fa_cla(a_10, b_10, h_u_pg_rca12_or9_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa10_y2 = (fa_cla(a_10, b_10, h_u_pg_rca12_or9_y0) >> 2) & 0x01;
  h_u_pg_rca12_and10_y0 = and_gate(h_u_pg_rca12_or9_y0, h_u_pg_rca12_fa10_y0);
  h_u_pg_rca12_or10_y0 = or_gate(h_u_pg_rca12_and10_y0, h_u_pg_rca12_fa10_y1);
  h_u_pg_rca12_fa11_y0 = (fa_cla(a_11, b_11, h_u_pg_rca12_or10_y0) >> 0) & 0x01;
  h_u_pg_rca12_fa11_y1 = (fa_cla(a_11, b_11, h_u_pg_rca12_or10_y0) >> 1) & 0x01;
  h_u_pg_rca12_fa11_y2 = (fa_cla(a_11, b_11, h_u_pg_rca12_or10_y0) >> 2) & 0x01;
  h_u_pg_rca12_and11_y0 = and_gate(h_u_pg_rca12_or10_y0, h_u_pg_rca12_fa11_y0);
  h_u_pg_rca12_or11_y0 = or_gate(h_u_pg_rca12_and11_y0, h_u_pg_rca12_fa11_y1);

  out |= (h_u_pg_rca12_fa0_y2 & 0x01) << 0;
  out |= (h_u_pg_rca12_fa1_y2 & 0x01) << 1;
  out |= (h_u_pg_rca12_fa2_y2 & 0x01) << 2;
  out |= (h_u_pg_rca12_fa3_y2 & 0x01) << 3;
  out |= (h_u_pg_rca12_fa4_y2 & 0x01) << 4;
  out |= (h_u_pg_rca12_fa5_y2 & 0x01) << 5;
  out |= (h_u_pg_rca12_fa6_y2 & 0x01) << 6;
  out |= (h_u_pg_rca12_fa7_y2 & 0x01) << 7;
  out |= (h_u_pg_rca12_fa8_y2 & 0x01) << 8;
  out |= (h_u_pg_rca12_fa9_y2 & 0x01) << 9;
  out |= (h_u_pg_rca12_fa10_y2 & 0x01) << 10;
  out |= (h_u_pg_rca12_fa11_y2 & 0x01) << 11;
  out |= (h_u_pg_rca12_or11_y0 & 0x01) << 12;
  return out;
}