#ifndef helper_h
#include <stdint.h>

/**
 * @param dest with @param len random uint64_t's
 */
void fill_random(uint64_t dest[], const int len);

/**
 * parses arguments returns int of first arguments.
 * returns -1 if none was specified.
 */
int parseArg(int argc, char **argv);
#define helper_h
#endif
