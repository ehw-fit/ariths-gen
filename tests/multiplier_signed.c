#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int64_t CNAME(int64_t a, int64_t b);


int main() {
  int result = 0;
  for (int i = -128; i < 128; i++){
    for (int j = -128; j < 128; j++){
      result = i * j;
      
      // Calculating 2's complement in case of negative sum
      if (result < 0) {
        result = 65536 + result;  
      }

      assert(result == (int)CNAME(i,j));
    }
  }
  return 0;
}