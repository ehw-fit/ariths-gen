#include <stdio.h>
#include <stdint.h>

uint8_t not_gate(uint8_t a){
  return ~(((a >> 0) & 0x01)) & 0x01;
}