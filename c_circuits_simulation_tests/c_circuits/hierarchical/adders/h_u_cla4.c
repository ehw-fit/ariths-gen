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

  pg_logic_out |= ((pg_logic_or0 >> 0) & 0x01) << 0;
  pg_logic_out |= ((pg_logic_and0 >> 0) & 0x01) << 1;
  pg_logic_out |= ((pg_logic_xor0 >> 0) & 0x01) << 2;
  return pg_logic_out;
}

uint64_t h_u_cla4(uint64_t a, uint64_t b){
  uint8_t h_u_cla4_out = 0;
  uint8_t h_u_cla4_pg_logic0_or0 = 0;
  uint8_t h_u_cla4_pg_logic0_and0 = 0;
  uint8_t h_u_cla4_pg_logic0_xor0 = 0;
  uint8_t h_u_cla4_pg_logic1_or0 = 0;
  uint8_t h_u_cla4_pg_logic1_and0 = 0;
  uint8_t h_u_cla4_pg_logic1_xor0 = 0;
  uint8_t h_u_cla4_xor1 = 0;
  uint8_t h_u_cla4_and0 = 0;
  uint8_t h_u_cla4_or0 = 0;
  uint8_t h_u_cla4_pg_logic2_or0 = 0;
  uint8_t h_u_cla4_pg_logic2_and0 = 0;
  uint8_t h_u_cla4_pg_logic2_xor0 = 0;
  uint8_t h_u_cla4_xor2 = 0;
  uint8_t h_u_cla4_and1 = 0;
  uint8_t h_u_cla4_and2 = 0;
  uint8_t h_u_cla4_and3 = 0;
  uint8_t h_u_cla4_and4 = 0;
  uint8_t h_u_cla4_or1 = 0;
  uint8_t h_u_cla4_or2 = 0;
  uint8_t h_u_cla4_pg_logic3_or0 = 0;
  uint8_t h_u_cla4_pg_logic3_and0 = 0;
  uint8_t h_u_cla4_pg_logic3_xor0 = 0;
  uint8_t h_u_cla4_xor3 = 0;
  uint8_t h_u_cla4_and5 = 0;
  uint8_t h_u_cla4_and6 = 0;
  uint8_t h_u_cla4_and7 = 0;
  uint8_t h_u_cla4_and8 = 0;
  uint8_t h_u_cla4_and9 = 0;
  uint8_t h_u_cla4_and10 = 0;
  uint8_t h_u_cla4_and11 = 0;
  uint8_t h_u_cla4_or3 = 0;
  uint8_t h_u_cla4_or4 = 0;
  uint8_t h_u_cla4_or5 = 0;

  h_u_cla4_pg_logic0_or0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 0) & 0x01;
  h_u_cla4_pg_logic0_and0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 1) & 0x01;
  h_u_cla4_pg_logic0_xor0 = (pg_logic(((a >> 0) & 0x01), ((b >> 0) & 0x01)) >> 2) & 0x01;
  h_u_cla4_pg_logic1_or0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 0) & 0x01;
  h_u_cla4_pg_logic1_and0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 1) & 0x01;
  h_u_cla4_pg_logic1_xor0 = (pg_logic(((a >> 1) & 0x01), ((b >> 1) & 0x01)) >> 2) & 0x01;
  h_u_cla4_xor1 = xor_gate(((h_u_cla4_pg_logic1_xor0 >> 0) & 0x01), ((h_u_cla4_pg_logic0_and0 >> 0) & 0x01));
  h_u_cla4_and0 = and_gate(((h_u_cla4_pg_logic0_and0 >> 0) & 0x01), ((h_u_cla4_pg_logic1_or0 >> 0) & 0x01));
  h_u_cla4_or0 = or_gate(((h_u_cla4_pg_logic1_and0 >> 0) & 0x01), ((h_u_cla4_and0 >> 0) & 0x01));
  h_u_cla4_pg_logic2_or0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 0) & 0x01;
  h_u_cla4_pg_logic2_and0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 1) & 0x01;
  h_u_cla4_pg_logic2_xor0 = (pg_logic(((a >> 2) & 0x01), ((b >> 2) & 0x01)) >> 2) & 0x01;
  h_u_cla4_xor2 = xor_gate(((h_u_cla4_pg_logic2_xor0 >> 0) & 0x01), ((h_u_cla4_or0 >> 0) & 0x01));
  h_u_cla4_and1 = and_gate(((h_u_cla4_pg_logic2_or0 >> 0) & 0x01), ((h_u_cla4_pg_logic0_or0 >> 0) & 0x01));
  h_u_cla4_and2 = and_gate(((h_u_cla4_pg_logic0_and0 >> 0) & 0x01), ((h_u_cla4_pg_logic2_or0 >> 0) & 0x01));
  h_u_cla4_and3 = and_gate(((h_u_cla4_and2 >> 0) & 0x01), ((h_u_cla4_pg_logic1_or0 >> 0) & 0x01));
  h_u_cla4_and4 = and_gate(((h_u_cla4_pg_logic1_and0 >> 0) & 0x01), ((h_u_cla4_pg_logic2_or0 >> 0) & 0x01));
  h_u_cla4_or1 = or_gate(((h_u_cla4_and3 >> 0) & 0x01), ((h_u_cla4_and4 >> 0) & 0x01));
  h_u_cla4_or2 = or_gate(((h_u_cla4_pg_logic2_and0 >> 0) & 0x01), ((h_u_cla4_or1 >> 0) & 0x01));
  h_u_cla4_pg_logic3_or0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 0) & 0x01;
  h_u_cla4_pg_logic3_and0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 1) & 0x01;
  h_u_cla4_pg_logic3_xor0 = (pg_logic(((a >> 3) & 0x01), ((b >> 3) & 0x01)) >> 2) & 0x01;
  h_u_cla4_xor3 = xor_gate(((h_u_cla4_pg_logic3_xor0 >> 0) & 0x01), ((h_u_cla4_or2 >> 0) & 0x01));
  h_u_cla4_and5 = and_gate(((h_u_cla4_pg_logic3_or0 >> 0) & 0x01), ((h_u_cla4_pg_logic1_or0 >> 0) & 0x01));
  h_u_cla4_and6 = and_gate(((h_u_cla4_pg_logic0_and0 >> 0) & 0x01), ((h_u_cla4_pg_logic2_or0 >> 0) & 0x01));
  h_u_cla4_and7 = and_gate(((h_u_cla4_pg_logic3_or0 >> 0) & 0x01), ((h_u_cla4_pg_logic1_or0 >> 0) & 0x01));
  h_u_cla4_and8 = and_gate(((h_u_cla4_and6 >> 0) & 0x01), ((h_u_cla4_and7 >> 0) & 0x01));
  h_u_cla4_and9 = and_gate(((h_u_cla4_pg_logic1_and0 >> 0) & 0x01), ((h_u_cla4_pg_logic3_or0 >> 0) & 0x01));
  h_u_cla4_and10 = and_gate(((h_u_cla4_and9 >> 0) & 0x01), ((h_u_cla4_pg_logic2_or0 >> 0) & 0x01));
  h_u_cla4_and11 = and_gate(((h_u_cla4_pg_logic2_and0 >> 0) & 0x01), ((h_u_cla4_pg_logic3_or0 >> 0) & 0x01));
  h_u_cla4_or3 = or_gate(((h_u_cla4_and8 >> 0) & 0x01), ((h_u_cla4_and11 >> 0) & 0x01));
  h_u_cla4_or4 = or_gate(((h_u_cla4_and10 >> 0) & 0x01), ((h_u_cla4_or3 >> 0) & 0x01));
  h_u_cla4_or5 = or_gate(((h_u_cla4_pg_logic3_and0 >> 0) & 0x01), ((h_u_cla4_or4 >> 0) & 0x01));

  h_u_cla4_out |= ((h_u_cla4_pg_logic0_xor0 >> 0) & 0x01) << 0;
  h_u_cla4_out |= ((h_u_cla4_xor1 >> 0) & 0x01) << 1;
  h_u_cla4_out |= ((h_u_cla4_xor2 >> 0) & 0x01) << 2;
  h_u_cla4_out |= ((h_u_cla4_xor3 >> 0) & 0x01) << 3;
  h_u_cla4_out |= ((h_u_cla4_or5 >> 0) & 0x01) << 4;
  return h_u_cla4_out;
}

#include <assert.h>
int main(){
  for (int i = 0; i < 16; i++){
    for (int j = 0; j < 16; j++){
      assert((i + j) == h_u_cla4(i,j));
    }
  }
  return 0;
}