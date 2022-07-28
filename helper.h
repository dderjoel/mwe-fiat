#ifndef helper_h
#include <stdint.h>

/**
 * @param dest with @param len random uint64_t's
 */
void fill_random(uint64_t dest[], const int len);

/**
 * parses arguments returns int of first arguments.
 * prints error to stderr if there is none, and returns 0
 */
int parseArg(int argc, char **argv);
#define helper_h
#endif
