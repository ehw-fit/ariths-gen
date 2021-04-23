#include <stdio.h>
#include <stdint.h>

uint8_t nor_gate(uint8_t a, uint8_t b){
  return ~(((a >> 0) & 0x01) | ((b >> 0) & 0x01)) & 0x01;
}