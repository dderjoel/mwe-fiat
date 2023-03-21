#include "fiat/poly1305_64.c"
#define LEN 3
int main() {
  uint64_t input1[LEN] = {0};
  uint64_t output[LEN] = {0};

  for (int i = 0; i < 100000; i++) {
    fiat_poly1305_carry_square(output, input1);
  }
  return 0;
}
