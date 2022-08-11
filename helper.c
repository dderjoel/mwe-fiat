#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
void fill_random(uint64_t dest[], const int len) {
  for (int i = 0; i < len; i++) {
    dest[i] = (uint64_t)rand();
    dest[i] |= ((uint64_t)rand()) >> 32;
  }
}

int parseArg(int argc, char **argv) {
  if (argc < 2) {
    return -1;
  }
  return atoi(argv[1]);
}
