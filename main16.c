#include "fiat/secp256k1_64.c"

#define LEN 4
int main() {
  uint64_t input1[LEN] = {0};
  uint64_t output[LEN] = {0};

  for (int i = 0; i < 100000; i++) {
    fiat_secp256k1_square(output, input1);
  }
  return 0;
}
