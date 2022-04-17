#include <stdio.h>
#include <stdint.h>

uint8_t and_gate(uint8_t a, uint8_t b){
  return ((a >> 0) & 0x01) & ((b >> 0) & 0x01);
}

uint64_t h_u_csatm8_pg_rca_k7(uint64_t a, uint64_t b){
  uint64_t h_u_csatm8_pg_rca_k7_out = 0;
  uint8_t h_u_csatm8_pg_rca_k7_and7_7 = 0;

  h_u_csatm8_pg_rca_k7_and7_7 = and_gate(((a >> 7) & 0x01), ((b >> 7) & 0x01));

  h_u_csatm8_pg_rca_k7_out |= (0x00) << 0;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 1;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 2;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 3;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 4;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 5;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 6;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 7;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 8;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 9;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 10;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 11;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 12;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 13;
  h_u_csatm8_pg_rca_k7_out |= ((h_u_csatm8_pg_rca_k7_and7_7 >> 0) & 0x01ull) << 14;
  h_u_csatm8_pg_rca_k7_out |= (0x00) << 15;
  return h_u_csatm8_pg_rca_k7_out;
}