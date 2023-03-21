#include "fiat/p448_solinas_64.c"

#define LEN 8
int main() {
  uint64_t input1[LEN] = {0};
  uint64_t input2[LEN] = {0};
  uint64_t output[LEN] = {0};

  for (int i = 0; i < 100000; i++) {
    fiat_p448_carry_mul(output, input1, input2);
  }
  return 0;
}
