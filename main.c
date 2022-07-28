#include "fiat/curve25519_64.c"

#include "helper.h"

#define LEN 10

int main(int argc, char **argv) {

  uint64_t input1[LEN];
  uint64_t input2[LEN];
  uint64_t output[LEN];

  fill_random(input1, LEN);
  fill_random(input2, LEN);

  int iterations = parseArg(argc, argv);

  for (int i = 0; i < iterations; i++) {
    fiat_25519_carry_mul(output, input1, input2);
  }

  return 0;
}
