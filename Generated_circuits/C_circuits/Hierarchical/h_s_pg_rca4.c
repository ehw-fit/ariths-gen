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

int64_t h_s_pg_rca4(int64_t a, int64_t b){
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
  uint8_t h_s_pg_rca4_fa0_y0 = 0;
  uint8_t h_s_pg_rca4_fa0_y1 = 0;
  uint8_t h_s_pg_rca4_fa0_y2 = 0;
  uint8_t h_s_pg_rca4_and0_y0 = 0;
  uint8_t h_s_pg_rca4_or0_y0 = 0;
  uint8_t h_s_pg_rca4_fa1_y0 = 0;
  uint8_t h_s_pg_rca4_fa1_y1 = 0;
  uint8_t h_s_pg_rca4_fa1_y2 = 0;
  uint8_t h_s_pg_rca4_and1_y0 = 0;
  uint8_t h_s_pg_rca4_or1_y0 = 0;
  uint8_t h_s_pg_rca4_fa2_y0 = 0;
  uint8_t h_s_pg_rca4_fa2_y1 = 0;
  uint8_t h_s_pg_rca4_fa2_y2 = 0;
  uint8_t h_s_pg_rca4_and2_y0 = 0;
  uint8_t h_s_pg_rca4_or2_y0 = 0;
  uint8_t h_s_pg_rca4_fa3_y0 = 0;
  uint8_t h_s_pg_rca4_fa3_y1 = 0;
  uint8_t h_s_pg_rca4_fa3_y2 = 0;
  uint8_t h_s_pg_rca4_and3_y0 = 0;
  uint8_t h_s_pg_rca4_or3_y0 = 0;
  uint8_t h_s_pg_rca4_xor0_y0 = 0;
  uint8_t h_s_pg_rca4_xor1_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  constant_wire_0 = (constant_wire_value_0(a_0, b_0) >> 0) & 0x01;
  h_s_pg_rca4_fa0_y0 = (fa_cla(a_0, b_0, constant_wire_0) >> 0) & 0x01;
  h_s_pg_rca4_fa0_y1 = (fa_cla(a_0, b_0, constant_wire_0) >> 1) & 0x01;
  h_s_pg_rca4_fa0_y2 = (fa_cla(a_0, b_0, constant_wire_0) >> 2) & 0x01;
  h_s_pg_rca4_and0_y0 = and_gate(constant_wire_0, h_s_pg_rca4_fa0_y0);
  h_s_pg_rca4_or0_y0 = or_gate(h_s_pg_rca4_and0_y0, h_s_pg_rca4_fa0_y1);
  h_s_pg_rca4_fa1_y0 = (fa_cla(a_1, b_1, h_s_pg_rca4_or0_y0) >> 0) & 0x01;
  h_s_pg_rca4_fa1_y1 = (fa_cla(a_1, b_1, h_s_pg_rca4_or0_y0) >> 1) & 0x01;
  h_s_pg_rca4_fa1_y2 = (fa_cla(a_1, b_1, h_s_pg_rca4_or0_y0) >> 2) & 0x01;
  h_s_pg_rca4_and1_y0 = and_gate(h_s_pg_rca4_or0_y0, h_s_pg_rca4_fa1_y0);
  h_s_pg_rca4_or1_y0 = or_gate(h_s_pg_rca4_and1_y0, h_s_pg_rca4_fa1_y1);
  h_s_pg_rca4_fa2_y0 = (fa_cla(a_2, b_2, h_s_pg_rca4_or1_y0) >> 0) & 0x01;
  h_s_pg_rca4_fa2_y1 = (fa_cla(a_2, b_2, h_s_pg_rca4_or1_y0) >> 1) & 0x01;
  h_s_pg_rca4_fa2_y2 = (fa_cla(a_2, b_2, h_s_pg_rca4_or1_y0) >> 2) & 0x01;
  h_s_pg_rca4_and2_y0 = and_gate(h_s_pg_rca4_or1_y0, h_s_pg_rca4_fa2_y0);
  h_s_pg_rca4_or2_y0 = or_gate(h_s_pg_rca4_and2_y0, h_s_pg_rca4_fa2_y1);
  h_s_pg_rca4_fa3_y0 = (fa_cla(a_3, b_3, h_s_pg_rca4_or2_y0) >> 0) & 0x01;
  h_s_pg_rca4_fa3_y1 = (fa_cla(a_3, b_3, h_s_pg_rca4_or2_y0) >> 1) & 0x01;
  h_s_pg_rca4_fa3_y2 = (fa_cla(a_3, b_3, h_s_pg_rca4_or2_y0) >> 2) & 0x01;
  h_s_pg_rca4_and3_y0 = and_gate(h_s_pg_rca4_or2_y0, h_s_pg_rca4_fa3_y0);
  h_s_pg_rca4_or3_y0 = or_gate(h_s_pg_rca4_and3_y0, h_s_pg_rca4_fa3_y1);
  h_s_pg_rca4_xor0_y0 = xor_gate(a_3, b_3);
  h_s_pg_rca4_xor1_y0 = xor_gate(h_s_pg_rca4_xor0_y0, h_s_pg_rca4_or3_y0);

  out |= (h_s_pg_rca4_fa0_y2 & 0x01) << 0;
  out |= (h_s_pg_rca4_fa1_y2 & 0x01) << 1;
  out |= (h_s_pg_rca4_fa2_y2 & 0x01) << 2;
  out |= (h_s_pg_rca4_fa3_y2 & 0x01) << 3;
  out |= (h_s_pg_rca4_xor1_y0 & 0x01) << 4;
  return out;
}