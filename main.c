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

  for (int i = 0; i < iterations; i++) {
    // To measure a diferent method, include a different c-file first
    // then change the method here.
    fiat_25519_carry_mul(output, input1, input2);
  }

  return 0;
}

// Methods of interest:
//
// grep -e ' [a-z0-9_]\+\(square\|mul\)(' -r fiat -ho
//
// fiat_25519_carry_mul
// fiat_25519_carry_square
// fiat_p384_mul
// fiat_p384_square
// fiat_p224_mul
// fiat_p224_square
// fiat_p448_carry_mul
// fiat_p448_carry_square
// fiat_p521_carry_mul
// fiat_p521_carry_square
// fiat_p434_mul
// fiat_p434_square
// fiat_p256_mul
// fiat_p256_square
// fiat_secp256k1_mul
// fiat_secp256k1_square
// fiat_poly1305_carry_mul
// fiat_poly1305_carry_square
