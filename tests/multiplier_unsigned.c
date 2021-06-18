#include <assert.h>
#include <stdio.h>
#include <stdint.h>

uint64_t CNAME(uint64_t a, uint64_t b);


int main() {
  int result = 0;
  for (int i = 0; i < 256; i++){
    for (int j = 0; j < 256; j++){
      result = i * j;
  
      assert(result == (int)CNAME(i,j));
    }
  }
  return 0;
}