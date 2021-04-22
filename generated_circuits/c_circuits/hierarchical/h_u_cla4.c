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

uint8_t or_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) | ((_b >> 0) & 0x01);
}

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
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

uint8_t pg_logic(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t pg_logic_a = 0;
  uint8_t pg_logic_b = 0;
  uint8_t pg_logic_y0 = 0;
  uint8_t pg_logic_y1 = 0;
  uint8_t pg_logic_y2 = 0;

  pg_logic_a = ((a >> 0) & 0x01);
  pg_logic_b = ((b >> 0) & 0x01);
  pg_logic_y0 = or_gate(pg_logic_a, pg_logic_b);
  pg_logic_y1 = and_gate(pg_logic_a, pg_logic_b);
  pg_logic_y2 = xor_gate(pg_logic_a, pg_logic_b);

  out |= (pg_logic_y0 & 0x01) << 0;
  out |= (pg_logic_y1 & 0x01) << 1;
  out |= (pg_logic_y2 & 0x01) << 2;
  return out;
}

uint64_t h_u_cla4(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t constant_wire_0 = 0;
  uint8_t h_u_cla4_pg_logic0_y0 = 0;
  uint8_t h_u_cla4_pg_logic0_y1 = 0;
  uint8_t h_u_cla4_pg_logic0_y2 = 0;
  uint8_t h_u_cla4_xor0_y0 = 0;
  uint8_t h_u_cla4_and0_y0 = 0;
  uint8_t h_u_cla4_or0_y0 = 0;
  uint8_t h_u_cla4_pg_logic1_y0 = 0;
  uint8_t h_u_cla4_pg_logic1_y1 = 0;
  uint8_t h_u_cla4_pg_logic1_y2 = 0;
  uint8_t h_u_cla4_xor1_y0 = 0;
  uint8_t h_u_cla4_and1_y0 = 0;
  uint8_t h_u_cla4_and2_y0 = 0;
  uint8_t h_u_cla4_and3_y0 = 0;
  uint8_t h_u_cla4_and4_y0 = 0;
  uint8_t h_u_cla4_or1_y0 = 0;
  uint8_t h_u_cla4_or2_y0 = 0;
  uint8_t h_u_cla4_pg_logic2_y0 = 0;
  uint8_t h_u_cla4_pg_logic2_y1 = 0;
  uint8_t h_u_cla4_pg_logic2_y2 = 0;
  uint8_t h_u_cla4_xor2_y0 = 0;
  uint8_t h_u_cla4_and5_y0 = 0;
  uint8_t h_u_cla4_and6_y0 = 0;
  uint8_t h_u_cla4_and7_y0 = 0;
  uint8_t h_u_cla4_and8_y0 = 0;
  uint8_t h_u_cla4_and9_y0 = 0;
  uint8_t h_u_cla4_and10_y0 = 0;
  uint8_t h_u_cla4_and11_y0 = 0;
  uint8_t h_u_cla4_and12_y0 = 0;
  uint8_t h_u_cla4_and13_y0 = 0;
  uint8_t h_u_cla4_or3_y0 = 0;
  uint8_t h_u_cla4_or4_y0 = 0;
  uint8_t h_u_cla4_or5_y0 = 0;
  uint8_t h_u_cla4_pg_logic3_y0 = 0;
  uint8_t h_u_cla4_pg_logic3_y1 = 0;
  uint8_t h_u_cla4_pg_logic3_y2 = 0;
  uint8_t h_u_cla4_xor3_y0 = 0;
  uint8_t h_u_cla4_and14_y0 = 0;
  uint8_t h_u_cla4_and15_y0 = 0;
  uint8_t h_u_cla4_and16_y0 = 0;
  uint8_t h_u_cla4_and17_y0 = 0;
  uint8_t h_u_cla4_and18_y0 = 0;
  uint8_t h_u_cla4_and19_y0 = 0;
  uint8_t h_u_cla4_and20_y0 = 0;
  uint8_t h_u_cla4_and21_y0 = 0;
  uint8_t h_u_cla4_and22_y0 = 0;
  uint8_t h_u_cla4_and23_y0 = 0;
  uint8_t h_u_cla4_and24_y0 = 0;
  uint8_t h_u_cla4_and25_y0 = 0;
  uint8_t h_u_cla4_and26_y0 = 0;
  uint8_t h_u_cla4_and27_y0 = 0;
  uint8_t h_u_cla4_and28_y0 = 0;
  uint8_t h_u_cla4_and29_y0 = 0;
  uint8_t h_u_cla4_or6_y0 = 0;
  uint8_t h_u_cla4_or7_y0 = 0;
  uint8_t h_u_cla4_or8_y0 = 0;
  uint8_t h_u_cla4_or9_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  constant_wire_0 = (constant_wire_value_0(a_0, b_0) >> 0) & 0x01;
  h_u_cla4_pg_logic0_y0 = (pg_logic(a_0, b_0) >> 0) & 0x01;
  h_u_cla4_pg_logic0_y1 = (pg_logic(a_0, b_0) >> 1) & 0x01;
  h_u_cla4_pg_logic0_y2 = (pg_logic(a_0, b_0) >> 2) & 0x01;
  h_u_cla4_xor0_y0 = xor_gate(h_u_cla4_pg_logic0_y2, constant_wire_0);
  h_u_cla4_and0_y0 = and_gate(h_u_cla4_pg_logic0_y0, constant_wire_0);
  h_u_cla4_or0_y0 = or_gate(h_u_cla4_pg_logic0_y1, h_u_cla4_and0_y0);
  h_u_cla4_pg_logic1_y0 = (pg_logic(a_1, b_1) >> 0) & 0x01;
  h_u_cla4_pg_logic1_y1 = (pg_logic(a_1, b_1) >> 1) & 0x01;
  h_u_cla4_pg_logic1_y2 = (pg_logic(a_1, b_1) >> 2) & 0x01;
  h_u_cla4_xor1_y0 = xor_gate(h_u_cla4_pg_logic1_y2, h_u_cla4_or0_y0);
  h_u_cla4_and1_y0 = and_gate(h_u_cla4_pg_logic0_y0, constant_wire_0);
  h_u_cla4_and2_y0 = and_gate(h_u_cla4_pg_logic1_y0, constant_wire_0);
  h_u_cla4_and3_y0 = and_gate(h_u_cla4_and2_y0, h_u_cla4_and1_y0);
  h_u_cla4_and4_y0 = and_gate(h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic0_y1);
  h_u_cla4_or1_y0 = or_gate(h_u_cla4_and4_y0, h_u_cla4_and3_y0);
  h_u_cla4_or2_y0 = or_gate(h_u_cla4_pg_logic1_y1, h_u_cla4_or1_y0);
  h_u_cla4_pg_logic2_y0 = (pg_logic(a_2, b_2) >> 0) & 0x01;
  h_u_cla4_pg_logic2_y1 = (pg_logic(a_2, b_2) >> 1) & 0x01;
  h_u_cla4_pg_logic2_y2 = (pg_logic(a_2, b_2) >> 2) & 0x01;
  h_u_cla4_xor2_y0 = xor_gate(h_u_cla4_pg_logic2_y2, h_u_cla4_or2_y0);
  h_u_cla4_and5_y0 = and_gate(h_u_cla4_pg_logic0_y0, constant_wire_0);
  h_u_cla4_and6_y0 = and_gate(h_u_cla4_pg_logic1_y0, constant_wire_0);
  h_u_cla4_and7_y0 = and_gate(h_u_cla4_and6_y0, h_u_cla4_and5_y0);
  h_u_cla4_and8_y0 = and_gate(h_u_cla4_pg_logic2_y0, constant_wire_0);
  h_u_cla4_and9_y0 = and_gate(h_u_cla4_and8_y0, h_u_cla4_and7_y0);
  h_u_cla4_and10_y0 = and_gate(h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic0_y1);
  h_u_cla4_and11_y0 = and_gate(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic0_y1);
  h_u_cla4_and12_y0 = and_gate(h_u_cla4_and11_y0, h_u_cla4_and10_y0);
  h_u_cla4_and13_y0 = and_gate(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic1_y1);
  h_u_cla4_or3_y0 = or_gate(h_u_cla4_and13_y0, h_u_cla4_and9_y0);
  h_u_cla4_or4_y0 = or_gate(h_u_cla4_or3_y0, h_u_cla4_and12_y0);
  h_u_cla4_or5_y0 = or_gate(h_u_cla4_pg_logic2_y1, h_u_cla4_or4_y0);
  h_u_cla4_pg_logic3_y0 = (pg_logic(a_3, b_3) >> 0) & 0x01;
  h_u_cla4_pg_logic3_y1 = (pg_logic(a_3, b_3) >> 1) & 0x01;
  h_u_cla4_pg_logic3_y2 = (pg_logic(a_3, b_3) >> 2) & 0x01;
  h_u_cla4_xor3_y0 = xor_gate(h_u_cla4_pg_logic3_y2, h_u_cla4_or5_y0);
  h_u_cla4_and14_y0 = and_gate(h_u_cla4_pg_logic0_y0, constant_wire_0);
  h_u_cla4_and15_y0 = and_gate(h_u_cla4_pg_logic1_y0, constant_wire_0);
  h_u_cla4_and16_y0 = and_gate(h_u_cla4_and15_y0, h_u_cla4_and14_y0);
  h_u_cla4_and17_y0 = and_gate(h_u_cla4_pg_logic2_y0, constant_wire_0);
  h_u_cla4_and18_y0 = and_gate(h_u_cla4_and17_y0, h_u_cla4_and16_y0);
  h_u_cla4_and19_y0 = and_gate(h_u_cla4_pg_logic3_y0, constant_wire_0);
  h_u_cla4_and20_y0 = and_gate(h_u_cla4_and19_y0, h_u_cla4_and18_y0);
  h_u_cla4_and21_y0 = and_gate(h_u_cla4_pg_logic1_y0, h_u_cla4_pg_logic0_y1);
  h_u_cla4_and22_y0 = and_gate(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic0_y1);
  h_u_cla4_and23_y0 = and_gate(h_u_cla4_and22_y0, h_u_cla4_and21_y0);
  h_u_cla4_and24_y0 = and_gate(h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic0_y1);
  h_u_cla4_and25_y0 = and_gate(h_u_cla4_and24_y0, h_u_cla4_and23_y0);
  h_u_cla4_and26_y0 = and_gate(h_u_cla4_pg_logic2_y0, h_u_cla4_pg_logic1_y1);
  h_u_cla4_and27_y0 = and_gate(h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic1_y1);
  h_u_cla4_and28_y0 = and_gate(h_u_cla4_and27_y0, h_u_cla4_and26_y0);
  h_u_cla4_and29_y0 = and_gate(h_u_cla4_pg_logic3_y0, h_u_cla4_pg_logic2_y1);
  h_u_cla4_or6_y0 = or_gate(h_u_cla4_and29_y0, h_u_cla4_and20_y0);
  h_u_cla4_or7_y0 = or_gate(h_u_cla4_or6_y0, h_u_cla4_and25_y0);
  h_u_cla4_or8_y0 = or_gate(h_u_cla4_or7_y0, h_u_cla4_and28_y0);
  h_u_cla4_or9_y0 = or_gate(h_u_cla4_pg_logic3_y1, h_u_cla4_or8_y0);

  out |= (h_u_cla4_xor0_y0 & 0x01) << 0;
  out |= (h_u_cla4_xor1_y0 & 0x01) << 1;
  out |= (h_u_cla4_xor2_y0 & 0x01) << 2;
  out |= (h_u_cla4_xor3_y0 & 0x01) << 3;
  out |= (h_u_cla4_or9_y0 & 0x01) << 4;
  return out;
}