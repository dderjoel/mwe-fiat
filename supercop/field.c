#include "field.h"
#include "../fiat/curve25519_64.c"

int fe51_mul(fe51 out, const fe51 in1, const fe51 in2) {
  fiat_25519_carry_mul(out, in1, in2);
  return 1;
};
int fe51_sq(fe51 out, const fe51 in1) {
  fiat_25519_carry_square(out, in1);
  return 1;
};
int fe51_mul121666(fe51 out, const fe51 in1) {
  fiat_25519_carry_scmul_121666(out, in1);
  return 1;
};
