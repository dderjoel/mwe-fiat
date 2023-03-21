#include "fiat/p256_64.c"
#define LEN 4
int main() {
  uint64_t input1[LEN] = {0};
  uint64_t input2[LEN] = {0};
  uint64_t output[LEN] = {0};

  for (int i = 0; i < 100000; i++) {
    fiat_p256_mul(output, input1, input2);
  }
  return 0;
}
