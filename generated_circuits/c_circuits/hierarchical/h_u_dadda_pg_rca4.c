#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) & ((_b >> 0) & 0x01);
}

uint8_t xor_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01);
}

uint8_t or_gate(uint8_t _a, uint8_t _b){
  return ((_a >> 0) & 0x01) | ((_b >> 0) & 0x01);
}

uint8_t xnor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) ^ ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint8_t nor_gate(uint8_t _a, uint8_t _b){
  return ~(((_a >> 0) & 0x01) | ((_b >> 0) & 0x01)) & 0x01 << 0;
}

uint8_t ha(uint8_t a, uint8_t b){
  uint8_t out = 0;
  uint8_t ha_a = 0;
  uint8_t ha_b = 0;
  uint8_t ha_y0 = 0;
  uint8_t ha_y1 = 0;

  ha_a = ((a >> 0) & 0x01);
  ha_b = ((b >> 0) & 0x01);
  ha_y0 = xor_gate(ha_a, ha_b);
  ha_y1 = and_gate(ha_a, ha_b);

  out |= (ha_y0 & 0x01) << 0;
  out |= (ha_y1 & 0x01) << 1;
  return out;
}

uint8_t fa(uint8_t a, uint8_t b, uint8_t cin){
  uint8_t out = 0;
  uint8_t fa_a = 0;
  uint8_t fa_b = 0;
  uint8_t fa_y0 = 0;
  uint8_t fa_y1 = 0;
  uint8_t fa_cin = 0;
  uint8_t fa_y2 = 0;
  uint8_t fa_y3 = 0;
  uint8_t fa_y4 = 0;

  fa_a = ((a >> 0) & 0x01);
  fa_b = ((b >> 0) & 0x01);
  fa_cin = ((cin >> 0) & 0x01);
  fa_y0 = xor_gate(fa_a, fa_b);
  fa_y1 = and_gate(fa_a, fa_b);
  fa_y2 = xor_gate(fa_y0, fa_cin);
  fa_y3 = and_gate(fa_y0, fa_cin);
  fa_y4 = or_gate(fa_y1, fa_y3);

  out |= (fa_y2 & 0x01) << 0;
  out |= (fa_y4 & 0x01) << 1;
  return out;
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

uint64_t u_pg_rca6(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t a_4 = 0;
  uint8_t a_5 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t b_4 = 0;
  uint8_t b_5 = 0;
  uint8_t constant_wire_0 = 0;
  uint8_t u_pg_rca6_fa0_y0 = 0;
  uint8_t u_pg_rca6_fa0_y1 = 0;
  uint8_t u_pg_rca6_fa0_y2 = 0;
  uint8_t u_pg_rca6_and0_y0 = 0;
  uint8_t u_pg_rca6_or0_y0 = 0;
  uint8_t u_pg_rca6_fa1_y0 = 0;
  uint8_t u_pg_rca6_fa1_y1 = 0;
  uint8_t u_pg_rca6_fa1_y2 = 0;
  uint8_t u_pg_rca6_and1_y0 = 0;
  uint8_t u_pg_rca6_or1_y0 = 0;
  uint8_t u_pg_rca6_fa2_y0 = 0;
  uint8_t u_pg_rca6_fa2_y1 = 0;
  uint8_t u_pg_rca6_fa2_y2 = 0;
  uint8_t u_pg_rca6_and2_y0 = 0;
  uint8_t u_pg_rca6_or2_y0 = 0;
  uint8_t u_pg_rca6_fa3_y0 = 0;
  uint8_t u_pg_rca6_fa3_y1 = 0;
  uint8_t u_pg_rca6_fa3_y2 = 0;
  uint8_t u_pg_rca6_and3_y0 = 0;
  uint8_t u_pg_rca6_or3_y0 = 0;
  uint8_t u_pg_rca6_fa4_y0 = 0;
  uint8_t u_pg_rca6_fa4_y1 = 0;
  uint8_t u_pg_rca6_fa4_y2 = 0;
  uint8_t u_pg_rca6_and4_y0 = 0;
  uint8_t u_pg_rca6_or4_y0 = 0;
  uint8_t u_pg_rca6_fa5_y0 = 0;
  uint8_t u_pg_rca6_fa5_y1 = 0;
  uint8_t u_pg_rca6_fa5_y2 = 0;
  uint8_t u_pg_rca6_and5_y0 = 0;
  uint8_t u_pg_rca6_or5_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  a_4 = ((a >> 4) & 0x01);
  a_5 = ((a >> 5) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  b_4 = ((b >> 4) & 0x01);
  b_5 = ((b >> 5) & 0x01);
  constant_wire_0 = (constant_wire_value_0(a_0, b_0) >> 0) & 0x01;
  u_pg_rca6_fa0_y0 = (fa_cla(a_0, b_0, constant_wire_0) >> 0) & 0x01;
  u_pg_rca6_fa0_y1 = (fa_cla(a_0, b_0, constant_wire_0) >> 1) & 0x01;
  u_pg_rca6_fa0_y2 = (fa_cla(a_0, b_0, constant_wire_0) >> 2) & 0x01;
  u_pg_rca6_and0_y0 = and_gate(constant_wire_0, u_pg_rca6_fa0_y0);
  u_pg_rca6_or0_y0 = or_gate(u_pg_rca6_and0_y0, u_pg_rca6_fa0_y1);
  u_pg_rca6_fa1_y0 = (fa_cla(a_1, b_1, u_pg_rca6_or0_y0) >> 0) & 0x01;
  u_pg_rca6_fa1_y1 = (fa_cla(a_1, b_1, u_pg_rca6_or0_y0) >> 1) & 0x01;
  u_pg_rca6_fa1_y2 = (fa_cla(a_1, b_1, u_pg_rca6_or0_y0) >> 2) & 0x01;
  u_pg_rca6_and1_y0 = and_gate(u_pg_rca6_or0_y0, u_pg_rca6_fa1_y0);
  u_pg_rca6_or1_y0 = or_gate(u_pg_rca6_and1_y0, u_pg_rca6_fa1_y1);
  u_pg_rca6_fa2_y0 = (fa_cla(a_2, b_2, u_pg_rca6_or1_y0) >> 0) & 0x01;
  u_pg_rca6_fa2_y1 = (fa_cla(a_2, b_2, u_pg_rca6_or1_y0) >> 1) & 0x01;
  u_pg_rca6_fa2_y2 = (fa_cla(a_2, b_2, u_pg_rca6_or1_y0) >> 2) & 0x01;
  u_pg_rca6_and2_y0 = and_gate(u_pg_rca6_or1_y0, u_pg_rca6_fa2_y0);
  u_pg_rca6_or2_y0 = or_gate(u_pg_rca6_and2_y0, u_pg_rca6_fa2_y1);
  u_pg_rca6_fa3_y0 = (fa_cla(a_3, b_3, u_pg_rca6_or2_y0) >> 0) & 0x01;
  u_pg_rca6_fa3_y1 = (fa_cla(a_3, b_3, u_pg_rca6_or2_y0) >> 1) & 0x01;
  u_pg_rca6_fa3_y2 = (fa_cla(a_3, b_3, u_pg_rca6_or2_y0) >> 2) & 0x01;
  u_pg_rca6_and3_y0 = and_gate(u_pg_rca6_or2_y0, u_pg_rca6_fa3_y0);
  u_pg_rca6_or3_y0 = or_gate(u_pg_rca6_and3_y0, u_pg_rca6_fa3_y1);
  u_pg_rca6_fa4_y0 = (fa_cla(a_4, b_4, u_pg_rca6_or3_y0) >> 0) & 0x01;
  u_pg_rca6_fa4_y1 = (fa_cla(a_4, b_4, u_pg_rca6_or3_y0) >> 1) & 0x01;
  u_pg_rca6_fa4_y2 = (fa_cla(a_4, b_4, u_pg_rca6_or3_y0) >> 2) & 0x01;
  u_pg_rca6_and4_y0 = and_gate(u_pg_rca6_or3_y0, u_pg_rca6_fa4_y0);
  u_pg_rca6_or4_y0 = or_gate(u_pg_rca6_and4_y0, u_pg_rca6_fa4_y1);
  u_pg_rca6_fa5_y0 = (fa_cla(a_5, b_5, u_pg_rca6_or4_y0) >> 0) & 0x01;
  u_pg_rca6_fa5_y1 = (fa_cla(a_5, b_5, u_pg_rca6_or4_y0) >> 1) & 0x01;
  u_pg_rca6_fa5_y2 = (fa_cla(a_5, b_5, u_pg_rca6_or4_y0) >> 2) & 0x01;
  u_pg_rca6_and5_y0 = and_gate(u_pg_rca6_or4_y0, u_pg_rca6_fa5_y0);
  u_pg_rca6_or5_y0 = or_gate(u_pg_rca6_and5_y0, u_pg_rca6_fa5_y1);

  out |= (u_pg_rca6_fa0_y2 & 0x01) << 0;
  out |= (u_pg_rca6_fa1_y2 & 0x01) << 1;
  out |= (u_pg_rca6_fa2_y2 & 0x01) << 2;
  out |= (u_pg_rca6_fa3_y2 & 0x01) << 3;
  out |= (u_pg_rca6_fa4_y2 & 0x01) << 4;
  out |= (u_pg_rca6_fa5_y2 & 0x01) << 5;
  out |= (u_pg_rca6_or5_y0 & 0x01) << 6;
  return out;
}

uint64_t h_u_dadda_pg_rca4(uint64_t a, uint64_t b){
  uint8_t out = 0;
  uint8_t a_0 = 0;
  uint8_t a_1 = 0;
  uint8_t a_2 = 0;
  uint8_t a_3 = 0;
  uint8_t b_0 = 0;
  uint8_t b_1 = 0;
  uint8_t b_2 = 0;
  uint8_t b_3 = 0;
  uint8_t h_u_dadda_pg_rca4_and_3_0_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_2_1_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_ha0_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_ha0_y1 = 0;
  uint8_t h_u_dadda_pg_rca4_and_3_1_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_ha1_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_ha1_y1 = 0;
  uint8_t h_u_dadda_pg_rca4_and_2_0_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_1_1_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_ha2_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_ha2_y1 = 0;
  uint8_t h_u_dadda_pg_rca4_and_1_2_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_0_3_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_fa0_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_fa0_y4 = 0;
  uint8_t h_u_dadda_pg_rca4_and_2_2_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_1_3_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_fa1_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_fa1_y4 = 0;
  uint8_t h_u_dadda_pg_rca4_and_3_2_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_fa2_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_fa2_y4 = 0;
  uint8_t h_u_dadda_pg_rca4_and_0_0_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_1_0_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_0_2_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_2_3_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_0_1_y0 = 0;
  uint8_t h_u_dadda_pg_rca4_and_3_3_y0 = 0;
  uint64_t h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a = 0;
  uint64_t h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b = 0;
  uint64_t h_u_dadda_pg_rca4_u_pg_rca6_out = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_fa0_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_fa1_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_fa2_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_fa3_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_fa4_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_fa5_y2 = 0;
  uint8_t h_u_dadda_pg_rca4_u_pg_rca6_or5_y0 = 0;

  a_0 = ((a >> 0) & 0x01);
  a_1 = ((a >> 1) & 0x01);
  a_2 = ((a >> 2) & 0x01);
  a_3 = ((a >> 3) & 0x01);
  b_0 = ((b >> 0) & 0x01);
  b_1 = ((b >> 1) & 0x01);
  b_2 = ((b >> 2) & 0x01);
  b_3 = ((b >> 3) & 0x01);
  h_u_dadda_pg_rca4_and_3_0_y0 = and_gate(a_3, b_0);
  h_u_dadda_pg_rca4_and_2_1_y0 = and_gate(a_2, b_1);
  h_u_dadda_pg_rca4_ha0_y0 = (ha(h_u_dadda_pg_rca4_and_3_0_y0, h_u_dadda_pg_rca4_and_2_1_y0) >> 0) & 0x01;
  h_u_dadda_pg_rca4_ha0_y1 = (ha(h_u_dadda_pg_rca4_and_3_0_y0, h_u_dadda_pg_rca4_and_2_1_y0) >> 1) & 0x01;
  h_u_dadda_pg_rca4_and_3_1_y0 = and_gate(a_3, b_1);
  h_u_dadda_pg_rca4_ha1_y0 = (ha(h_u_dadda_pg_rca4_ha0_y1, h_u_dadda_pg_rca4_and_3_1_y0) >> 0) & 0x01;
  h_u_dadda_pg_rca4_ha1_y1 = (ha(h_u_dadda_pg_rca4_ha0_y1, h_u_dadda_pg_rca4_and_3_1_y0) >> 1) & 0x01;
  h_u_dadda_pg_rca4_and_2_0_y0 = and_gate(a_2, b_0);
  h_u_dadda_pg_rca4_and_1_1_y0 = and_gate(a_1, b_1);
  h_u_dadda_pg_rca4_ha2_y0 = (ha(h_u_dadda_pg_rca4_and_2_0_y0, h_u_dadda_pg_rca4_and_1_1_y0) >> 0) & 0x01;
  h_u_dadda_pg_rca4_ha2_y1 = (ha(h_u_dadda_pg_rca4_and_2_0_y0, h_u_dadda_pg_rca4_and_1_1_y0) >> 1) & 0x01;
  h_u_dadda_pg_rca4_and_1_2_y0 = and_gate(a_1, b_2);
  h_u_dadda_pg_rca4_and_0_3_y0 = and_gate(a_0, b_3);
  h_u_dadda_pg_rca4_fa0_y2 = (fa(h_u_dadda_pg_rca4_ha2_y1, h_u_dadda_pg_rca4_and_1_2_y0, h_u_dadda_pg_rca4_and_0_3_y0) >> 0) & 0x01;
  h_u_dadda_pg_rca4_fa0_y4 = (fa(h_u_dadda_pg_rca4_ha2_y1, h_u_dadda_pg_rca4_and_1_2_y0, h_u_dadda_pg_rca4_and_0_3_y0) >> 1) & 0x01;
  h_u_dadda_pg_rca4_and_2_2_y0 = and_gate(a_2, b_2);
  h_u_dadda_pg_rca4_and_1_3_y0 = and_gate(a_1, b_3);
  h_u_dadda_pg_rca4_fa1_y2 = (fa(h_u_dadda_pg_rca4_fa0_y4, h_u_dadda_pg_rca4_and_2_2_y0, h_u_dadda_pg_rca4_and_1_3_y0) >> 0) & 0x01;
  h_u_dadda_pg_rca4_fa1_y4 = (fa(h_u_dadda_pg_rca4_fa0_y4, h_u_dadda_pg_rca4_and_2_2_y0, h_u_dadda_pg_rca4_and_1_3_y0) >> 1) & 0x01;
  h_u_dadda_pg_rca4_and_3_2_y0 = and_gate(a_3, b_2);
  h_u_dadda_pg_rca4_fa2_y2 = (fa(h_u_dadda_pg_rca4_fa1_y4, h_u_dadda_pg_rca4_ha1_y1, h_u_dadda_pg_rca4_and_3_2_y0) >> 0) & 0x01;
  h_u_dadda_pg_rca4_fa2_y4 = (fa(h_u_dadda_pg_rca4_fa1_y4, h_u_dadda_pg_rca4_ha1_y1, h_u_dadda_pg_rca4_and_3_2_y0) >> 1) & 0x01;
  h_u_dadda_pg_rca4_and_0_0_y0 = and_gate(a_0, b_0);
  h_u_dadda_pg_rca4_and_1_0_y0 = and_gate(a_1, b_0);
  h_u_dadda_pg_rca4_and_0_2_y0 = and_gate(a_0, b_2);
  h_u_dadda_pg_rca4_and_2_3_y0 = and_gate(a_2, b_3);
  h_u_dadda_pg_rca4_and_0_1_y0 = and_gate(a_0, b_1);
  h_u_dadda_pg_rca4_and_3_3_y0 = and_gate(a_3, b_3);
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a |= (h_u_dadda_pg_rca4_and_1_0_y0 & 0x01) << 0;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a |= (h_u_dadda_pg_rca4_and_0_2_y0 & 0x01) << 1;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a |= (h_u_dadda_pg_rca4_ha0_y0 & 0x01) << 2;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a |= (h_u_dadda_pg_rca4_ha1_y0 & 0x01) << 3;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a |= (h_u_dadda_pg_rca4_and_2_3_y0 & 0x01) << 4;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a |= (h_u_dadda_pg_rca4_fa2_y4 & 0x01) << 5;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b |= (h_u_dadda_pg_rca4_and_0_1_y0 & 0x01) << 0;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b |= (h_u_dadda_pg_rca4_ha2_y0 & 0x01) << 1;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b |= (h_u_dadda_pg_rca4_fa0_y2 & 0x01) << 2;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b |= (h_u_dadda_pg_rca4_fa1_y2 & 0x01) << 3;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b |= (h_u_dadda_pg_rca4_fa2_y2 & 0x01) << 4;
  h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b |= (h_u_dadda_pg_rca4_and_3_3_y0 & 0x01) << 5;
  h_u_dadda_pg_rca4_u_pg_rca6_out = u_pg_rca6(h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_a, h_u_dadda_pg_rca4_u_pg_rca6_u_pg_rca6_b);
  h_u_dadda_pg_rca4_u_pg_rca6_fa0_y2 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 0) & 0x01);
  h_u_dadda_pg_rca4_u_pg_rca6_fa1_y2 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 1) & 0x01);
  h_u_dadda_pg_rca4_u_pg_rca6_fa2_y2 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 2) & 0x01);
  h_u_dadda_pg_rca4_u_pg_rca6_fa3_y2 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 3) & 0x01);
  h_u_dadda_pg_rca4_u_pg_rca6_fa4_y2 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 4) & 0x01);
  h_u_dadda_pg_rca4_u_pg_rca6_fa5_y2 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 5) & 0x01);
  h_u_dadda_pg_rca4_u_pg_rca6_or5_y0 = ((h_u_dadda_pg_rca4_u_pg_rca6_out >> 6) & 0x01);

  out |= (h_u_dadda_pg_rca4_and_0_0_y0 & 0x01) << 0;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_fa0_y2 & 0x01) << 1;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_fa1_y2 & 0x01) << 2;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_fa2_y2 & 0x01) << 3;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_fa3_y2 & 0x01) << 4;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_fa4_y2 & 0x01) << 5;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_fa5_y2 & 0x01) << 6;
  out |= (h_u_dadda_pg_rca4_u_pg_rca6_or5_y0 & 0x01) << 7;
  return out;
}