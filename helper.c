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
    fprintf(stderr,
            "Please call with number of iterations to perform.\n%s 1000\n",
            argv[0]);
    return 0;
  }
  return atoi(argv[1]);
}
