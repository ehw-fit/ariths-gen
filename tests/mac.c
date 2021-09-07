#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t mac(uint64_t a,uint64_t b,uint64_t acc);


int main() {
  int result = 0;

  srand(42);
  for(int i = 0; i < 10000; i++) {
      uint64_t a, b, acc;
      a = rand() % 256;
      b = rand() % 256;
      acc = rand() % 65536;
      result = (a * b) + acc;
  
      assert(result == mac(a, b, acc));
  }
  return 0;
}