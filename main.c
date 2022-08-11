#include "fiat/curve25519_64.c"

#include "helper.h"

// running `grep -ri 'typedef uint' -e fiat` shows, that the longest element is
// currenlty 9 uint's long
#define LEN 9

int main(int argc, char **argv) {

  int iterations = parseArg(argc, argv);

  uint64_t input1[LEN] = {0};
  uint64_t input2[LEN] = {0};
  uint64_t output[LEN] = {0};

  // Optionally fill the input with random data.
  fill_random(input1, LEN);
  fill_random(input2, LEN);
  if (iterations == -1) {
    iterations = 10000;
  }

  for (int i = 0; i < iterations; i++) {
    // To measure a diferent method, include a different c-file first
    // then change the method here.
    fiat_25519_carry_mul(output, input1, input2);
  }

  return 0;
}
