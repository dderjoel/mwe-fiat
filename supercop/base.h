#include <stdint.h>

int crypto_scalarmult(uint8_t out[32], const uint8_t scalar[32],
                      const uint8_t point[32]);
int crypto_scalarmult_base(unsigned char *q, const unsigned char *n);
