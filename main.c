#include "fiat/curve25519_64.c"
#include "fiat/p224_64.c"
#include "fiat/p256_64.c"
#include "fiat/p384_64.c"
#include "fiat/p434_64.c"
#include "fiat/p448_solinas_64.c"
#include "fiat/p521_64.c"
#include "fiat/poly1305_64.c"
#include "fiat/secp256k1_64.c"

#include "helper.h"
#include "supercop/base.h"

// running `grep -ri 'typedef uint' -e fiat` shows, that the longest element is
// currenlty 9 uint's long
#define LEN 9

void function0(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_25519_carry_mul(output, input1, input2);
}
void function1(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_25519_carry_square(output, input1);
}
void function2(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p384_mul(output, input1, input2);
}
void function3(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p384_square(output, input1);
}
void function4(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p224_mul(output, input1, input2);
}
void function5(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p224_square(output, input1);
}
void function6(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p448_carry_mul(output, input1, input2);
}
void function7(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p448_carry_square(output, input1);
}
void function8(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p521_carry_mul(output, input1, input2);
}
void function9(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p521_carry_square(output, input1);
}
void function10(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p434_mul(output, input1, input2);
}
void function11(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p434_square(output, input1);
}
void function12(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p256_mul(output, input1, input2);
}
void function13(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_p256_square(output, input1);
}
void function14(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_secp256k1_mul(output, input1, input2);
}
void function15(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_secp256k1_square(output, input1);
}
void function16(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_poly1305_carry_mul(output, input1, input2);
}
void function17(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  fiat_poly1305_carry_square(output, input1);
}
// curve25519 - scmul
void function18(uint64_t *output, uint64_t *input1, uint64_t *input2) {
  // needs 32bytes.
  // rn, LEN is 9, ie. 9*uint64_t  = 9*8 bytes =72bytes.
  crypto_scalarmult_base((uint8_t *)output, (uint8_t *)input1);
}

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
    function18(output, input1, input2);
  }

  return 0;
}
