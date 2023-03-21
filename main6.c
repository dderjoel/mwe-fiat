#include "fiat/p384_64.c"

#define LEN 6
int main() {
  uint64_t input1[LEN] = {0};
  uint64_t output[LEN] = {0};

  for (int i = 0; i < 100000; i++) {
    fiat_p384_square(output, input1);
  }
  return 0;
}
