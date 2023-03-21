/* Autogenerated: 'src/ExtractionOCaml/unsaturated_solinas' --inline --static
 * --use-value-barrier poly1305 64 3 '2^130 - 5' carry_mul carry_square carry
 * add sub opp selectznz to_bytes from_bytes relax */
/* curve description: poly1305 */
/* machine_wordsize = 64 (from "64") */
/* requested operations: carry_mul, carry_square, carry, add, sub, opp,
 * selectznz, to_bytes, from_bytes, relax */
/* n = 3 (from "3") */
/* s-c = 2^130 - [(1, 5)] (from "2^130 - 5") */
/* tight_bounds_multiplier = 1 (from "") */
/*  */
/* Computed values: */
/*   carry_chain = [0, 1, 2, 0, 1] */
/*   eval z = z[0] + (z[1] << 44) + (z[2] << 87) */
/*   bytes_eval z = z[0] + (z[1] << 8) + (z[2] << 16) + (z[3] << 24) + (z[4] <<
 * 32) + (z[5] << 40) + (z[6] << 48) + (z[7] << 56) + (z[8] << 64) + (z[9] <<
 * 72) + (z[10] << 80) + (z[11] << 88) + (z[12] << 96) + (z[13] << 104) + (z[14]
 * << 112) + (z[15] << 120) + (z[16] << 128) */
/*   balance = [0x1ffffffffff6, 0xffffffffffe, 0xffffffffffe] */

#include <stdint.h>
typedef unsigned char fiat_poly1305_uint1;
typedef signed char fiat_poly1305_int1;
#if defined(__GNUC__) || defined(__clang__)
#define FIAT_POLY1305_FIAT_EXTENSION __extension__
#define FIAT_POLY1305_FIAT_INLINE __inline__
#else
#define FIAT_POLY1305_FIAT_EXTENSION
#define FIAT_POLY1305_FIAT_INLINE
#endif

FIAT_POLY1305_FIAT_EXTENSION typedef signed __int128 fiat_poly1305_int128;
FIAT_POLY1305_FIAT_EXTENSION typedef unsigned __int128 fiat_poly1305_uint128;

/* The type fiat_poly1305_loose_field_element is a field element with loose
 * bounds. */
/* Bounds: [[0x0 ~> 0x300000000000], [0x0 ~> 0x180000000000], [0x0 ~>
 * 0x180000000000]] */
typedef uint64_t fiat_poly1305_loose_field_element[3];

/* The type fiat_poly1305_tight_field_element is a field element with tight
 * bounds. */
/* Bounds: [[0x0 ~> 0x100000000000], [0x0 ~> 0x80000000000], [0x0 ~>
 * 0x80000000000]] */
typedef uint64_t fiat_poly1305_tight_field_element[3];

#if (-1 & 3) != 3
#error "This code only works on a two's complement system"
#endif

#if !defined(FIAT_POLY1305_NO_ASM) && (defined(__GNUC__) || defined(__clang__))
static __inline__ uint64_t fiat_poly1305_value_barrier_u64(uint64_t a) {
  __asm__("" : "+r"(a) : /* no inputs */);
  return a;
}
#else
#define fiat_poly1305_value_barrier_u64(x) (x)
#endif

/*
 * The function fiat_poly1305_addcarryx_u44 is an addition with carry.
 *
 * Postconditions:
 *   out1 = (arg1 + arg2 + arg3) mod 2^44
 *   out2 = ⌊(arg1 + arg2 + arg3) / 2^44⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xfffffffffff]
 *   arg3: [0x0 ~> 0xfffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xfffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_addcarryx_u44(uint64_t *out1, fiat_poly1305_uint1 *out2,
                            fiat_poly1305_uint1 arg1, uint64_t arg2,
                            uint64_t arg3) {
  uint64_t x1;
  uint64_t x2;
  fiat_poly1305_uint1 x3;
  x1 = ((arg1 + arg2) + arg3);
  x2 = (x1 & UINT64_C(0xfffffffffff));
  x3 = (fiat_poly1305_uint1)(x1 >> 44);
  *out1 = x2;
  *out2 = x3;
}

/*
 * The function fiat_poly1305_subborrowx_u44 is a subtraction with borrow.
 *
 * Postconditions:
 *   out1 = (-arg1 + arg2 + -arg3) mod 2^44
 *   out2 = -⌊(-arg1 + arg2 + -arg3) / 2^44⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xfffffffffff]
 *   arg3: [0x0 ~> 0xfffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xfffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_subborrowx_u44(uint64_t *out1, fiat_poly1305_uint1 *out2,
                             fiat_poly1305_uint1 arg1, uint64_t arg2,
                             uint64_t arg3) {
  int64_t x1;
  fiat_poly1305_int1 x2;
  uint64_t x3;
  x1 = ((int64_t)(arg2 - (int64_t)arg1) - (int64_t)arg3);
  x2 = (fiat_poly1305_int1)(x1 >> 44);
  x3 = (x1 & UINT64_C(0xfffffffffff));
  *out1 = x3;
  *out2 = (fiat_poly1305_uint1)(0x0 - x2);
}

/*
 * The function fiat_poly1305_addcarryx_u43 is an addition with carry.
 *
 * Postconditions:
 *   out1 = (arg1 + arg2 + arg3) mod 2^43
 *   out2 = ⌊(arg1 + arg2 + arg3) / 2^43⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0x7ffffffffff]
 *   arg3: [0x0 ~> 0x7ffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0x7ffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_addcarryx_u43(uint64_t *out1, fiat_poly1305_uint1 *out2,
                            fiat_poly1305_uint1 arg1, uint64_t arg2,
                            uint64_t arg3) {
  uint64_t x1;
  uint64_t x2;
  fiat_poly1305_uint1 x3;
  x1 = ((arg1 + arg2) + arg3);
  x2 = (x1 & UINT64_C(0x7ffffffffff));
  x3 = (fiat_poly1305_uint1)(x1 >> 43);
  *out1 = x2;
  *out2 = x3;
}

/*
 * The function fiat_poly1305_subborrowx_u43 is a subtraction with borrow.
 *
 * Postconditions:
 *   out1 = (-arg1 + arg2 + -arg3) mod 2^43
 *   out2 = -⌊(-arg1 + arg2 + -arg3) / 2^43⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0x7ffffffffff]
 *   arg3: [0x0 ~> 0x7ffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0x7ffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_subborrowx_u43(uint64_t *out1, fiat_poly1305_uint1 *out2,
                             fiat_poly1305_uint1 arg1, uint64_t arg2,
                             uint64_t arg3) {
  int64_t x1;
  fiat_poly1305_int1 x2;
  uint64_t x3;
  x1 = ((int64_t)(arg2 - (int64_t)arg1) - (int64_t)arg3);
  x2 = (fiat_poly1305_int1)(x1 >> 43);
  x3 = (x1 & UINT64_C(0x7ffffffffff));
  *out1 = x3;
  *out2 = (fiat_poly1305_uint1)(0x0 - x2);
}

/*
 * The function fiat_poly1305_cmovznz_u64 is a single-word conditional move.
 *
 * Postconditions:
 *   out1 = (if arg1 = 0 then arg2 else arg3)
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xffffffffffffffff]
 *   arg3: [0x0 ~> 0xffffffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xffffffffffffffff]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_cmovznz_u64(uint64_t *out1, fiat_poly1305_uint1 arg1,
                          uint64_t arg2, uint64_t arg3) {
  fiat_poly1305_uint1 x1;
  uint64_t x2;
  uint64_t x3;
  x1 = (!(!arg1));
  x2 = ((fiat_poly1305_int1)(0x0 - x1) & UINT64_C(0xffffffffffffffff));
  x3 = ((fiat_poly1305_value_barrier_u64(x2) & arg3) |
        (fiat_poly1305_value_barrier_u64((~x2)) & arg2));
  *out1 = x3;
}

/*
 * The function fiat_poly1305_carry_mul multiplies two field elements and
 * reduces the result.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 * eval arg2) mod m
 *
 */
void fiat_poly1305_carry_mul(fiat_poly1305_tight_field_element out1,
                             const fiat_poly1305_loose_field_element arg1,
                             const fiat_poly1305_loose_field_element arg2) {
  fiat_poly1305_uint128 x1;
  fiat_poly1305_uint128 x2;
  fiat_poly1305_uint128 x3;
  fiat_poly1305_uint128 x4;
  fiat_poly1305_uint128 x5;
  fiat_poly1305_uint128 x6;
  fiat_poly1305_uint128 x7;
  fiat_poly1305_uint128 x8;
  fiat_poly1305_uint128 x9;
  fiat_poly1305_uint128 x10;
  uint64_t x11;
  uint64_t x12;
  fiat_poly1305_uint128 x13;
  fiat_poly1305_uint128 x14;
  fiat_poly1305_uint128 x15;
  uint64_t x16;
  uint64_t x17;
  fiat_poly1305_uint128 x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  fiat_poly1305_uint1 x26;
  uint64_t x27;
  uint64_t x28;
  x1 = ((fiat_poly1305_uint128)(arg1[2]) * ((arg2[2]) * 0x5));
  x2 = ((fiat_poly1305_uint128)(arg1[2]) * ((arg2[1]) * 0xa));
  x3 = ((fiat_poly1305_uint128)(arg1[1]) * ((arg2[2]) * 0xa));
  x4 = ((fiat_poly1305_uint128)(arg1[2]) * (arg2[0]));
  x5 = ((fiat_poly1305_uint128)(arg1[1]) * ((arg2[1]) * 0x2));
  x6 = ((fiat_poly1305_uint128)(arg1[1]) * (arg2[0]));
  x7 = ((fiat_poly1305_uint128)(arg1[0]) * (arg2[2]));
  x8 = ((fiat_poly1305_uint128)(arg1[0]) * (arg2[1]));
  x9 = ((fiat_poly1305_uint128)(arg1[0]) * (arg2[0]));
  x10 = (x9 + (x3 + x2));
  x11 = (uint64_t)(x10 >> 44);
  x12 = (uint64_t)(x10 & UINT64_C(0xfffffffffff));
  x13 = (x7 + (x5 + x4));
  x14 = (x8 + (x6 + x1));
  x15 = (x11 + x14);
  x16 = (uint64_t)(x15 >> 43);
  x17 = (uint64_t)(x15 & UINT64_C(0x7ffffffffff));
  x18 = (x16 + x13);
  x19 = (uint64_t)(x18 >> 43);
  x20 = (uint64_t)(x18 & UINT64_C(0x7ffffffffff));
  x21 = (x19 * 0x5);
  x22 = (x12 + x21);
  x23 = (x22 >> 44);
  x24 = (x22 & UINT64_C(0xfffffffffff));
  x25 = (x23 + x17);
  x26 = (fiat_poly1305_uint1)(x25 >> 43);
  x27 = (x25 & UINT64_C(0x7ffffffffff));
  x28 = (x26 + x20);
  out1[0] = x24;
  out1[1] = x27;
  out1[2] = x28;
}

/*
 * The function fiat_poly1305_carry_square squares a field element and reduces
 * the result.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 * eval arg1) mod m
 *
 */
void fiat_poly1305_carry_square(fiat_poly1305_tight_field_element out1,
                                const fiat_poly1305_loose_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  fiat_poly1305_uint128 x5;
  fiat_poly1305_uint128 x6;
  fiat_poly1305_uint128 x7;
  fiat_poly1305_uint128 x8;
  fiat_poly1305_uint128 x9;
  fiat_poly1305_uint128 x10;
  fiat_poly1305_uint128 x11;
  uint64_t x12;
  uint64_t x13;
  fiat_poly1305_uint128 x14;
  fiat_poly1305_uint128 x15;
  fiat_poly1305_uint128 x16;
  uint64_t x17;
  uint64_t x18;
  fiat_poly1305_uint128 x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  fiat_poly1305_uint1 x27;
  uint64_t x28;
  uint64_t x29;
  x1 = ((arg1[2]) * 0x5);
  x2 = (x1 * 0x2);
  x3 = ((arg1[2]) * 0x2);
  x4 = ((arg1[1]) * 0x2);
  x5 = ((fiat_poly1305_uint128)(arg1[2]) * x1);
  x6 = ((fiat_poly1305_uint128)(arg1[1]) * (x2 * 0x2));
  x7 = ((fiat_poly1305_uint128)(arg1[1]) * ((arg1[1]) * 0x2));
  x8 = ((fiat_poly1305_uint128)(arg1[0]) * x3);
  x9 = ((fiat_poly1305_uint128)(arg1[0]) * x4);
  x10 = ((fiat_poly1305_uint128)(arg1[0]) * (arg1[0]));
  x11 = (x10 + x6);
  x12 = (uint64_t)(x11 >> 44);
  x13 = (uint64_t)(x11 & UINT64_C(0xfffffffffff));
  x14 = (x8 + x7);
  x15 = (x9 + x5);
  x16 = (x12 + x15);
  x17 = (uint64_t)(x16 >> 43);
  x18 = (uint64_t)(x16 & UINT64_C(0x7ffffffffff));
  x19 = (x17 + x14);
  x20 = (uint64_t)(x19 >> 43);
  x21 = (uint64_t)(x19 & UINT64_C(0x7ffffffffff));
  x22 = (x20 * 0x5);
  x23 = (x13 + x22);
  x24 = (x23 >> 44);
  x25 = (x23 & UINT64_C(0xfffffffffff));
  x26 = (x24 + x18);
  x27 = (fiat_poly1305_uint1)(x26 >> 43);
  x28 = (x26 & UINT64_C(0x7ffffffffff));
  x29 = (x27 + x21);
  out1[0] = x25;
  out1[1] = x28;
  out1[2] = x29;
}

/*
 * The function fiat_poly1305_carry reduces a field element.
 *
 * Postconditions:
 *   eval out1 mod m = eval arg1 mod m
 *
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_carry(fiat_poly1305_tight_field_element out1,
                    const fiat_poly1305_loose_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  x1 = (arg1[0]);
  x2 = ((x1 >> 44) + (arg1[1]));
  x3 = ((x2 >> 43) + (arg1[2]));
  x4 = ((x1 & UINT64_C(0xfffffffffff)) + ((x3 >> 43) * 0x5));
  x5 = ((fiat_poly1305_uint1)(x4 >> 44) + (x2 & UINT64_C(0x7ffffffffff)));
  x6 = (x4 & UINT64_C(0xfffffffffff));
  x7 = (x5 & UINT64_C(0x7ffffffffff));
  x8 = ((fiat_poly1305_uint1)(x5 >> 43) + (x3 & UINT64_C(0x7ffffffffff)));
  out1[0] = x6;
  out1[1] = x7;
  out1[2] = x8;
}

/*
 * The function fiat_poly1305_add adds two field elements.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 + eval arg2) mod m
 *
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_add(fiat_poly1305_loose_field_element out1,
                  const fiat_poly1305_tight_field_element arg1,
                  const fiat_poly1305_tight_field_element arg2) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  x1 = ((arg1[0]) + (arg2[0]));
  x2 = ((arg1[1]) + (arg2[1]));
  x3 = ((arg1[2]) + (arg2[2]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
}

/*
 * The function fiat_poly1305_sub subtracts two field elements.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 - eval arg2) mod m
 *
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_sub(fiat_poly1305_loose_field_element out1,
                  const fiat_poly1305_tight_field_element arg1,
                  const fiat_poly1305_tight_field_element arg2) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  x1 = ((UINT64_C(0x1ffffffffff6) + (arg1[0])) - (arg2[0]));
  x2 = ((UINT64_C(0xffffffffffe) + (arg1[1])) - (arg2[1]));
  x3 = ((UINT64_C(0xffffffffffe) + (arg1[2])) - (arg2[2]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
}

/*
 * The function fiat_poly1305_opp negates a field element.
 *
 * Postconditions:
 *   eval out1 mod m = -eval arg1 mod m
 *
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_opp(fiat_poly1305_loose_field_element out1,
                  const fiat_poly1305_tight_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  x1 = (UINT64_C(0x1ffffffffff6) - (arg1[0]));
  x2 = (UINT64_C(0xffffffffffe) - (arg1[1]));
  x3 = (UINT64_C(0xffffffffffe) - (arg1[2]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
}

/*
 * The function fiat_poly1305_selectznz is a multi-limb conditional select.
 *
 * Postconditions:
 *   out1 = (if arg1 = 0 then arg2 else arg3)
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff]] arg3: [[0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]] Output Bounds: out1: [[0x0
 * ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff]]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_selectznz(uint64_t out1[3], fiat_poly1305_uint1 arg1,
                        const uint64_t arg2[3], const uint64_t arg3[3]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  fiat_poly1305_cmovznz_u64(&x1, arg1, (arg2[0]), (arg3[0]));
  fiat_poly1305_cmovznz_u64(&x2, arg1, (arg2[1]), (arg3[1]));
  fiat_poly1305_cmovznz_u64(&x3, arg1, (arg2[2]), (arg3[2]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
}

/*
 * The function fiat_poly1305_to_bytes serializes a field element to bytes in
 * little-endian order.
 *
 * Postconditions:
 *   out1 = map (λ x, ⌊((eval arg1 mod m) mod 2^(8 * (x + 1))) / 2^(8 * x)⌋)
 * [0..16]
 *
 * Output Bounds:
 *   out1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~>
 * 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~>
 * 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~>
 * 0xff], [0x0 ~> 0xff], [0x0 ~> 0x3]]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_to_bytes(uint8_t out1[17],
                       const fiat_poly1305_tight_field_element arg1) {
  uint64_t x1;
  fiat_poly1305_uint1 x2;
  uint64_t x3;
  fiat_poly1305_uint1 x4;
  uint64_t x5;
  fiat_poly1305_uint1 x6;
  uint64_t x7;
  uint64_t x8;
  fiat_poly1305_uint1 x9;
  uint64_t x10;
  fiat_poly1305_uint1 x11;
  uint64_t x12;
  fiat_poly1305_uint1 x13;
  uint64_t x14;
  uint64_t x15;
  uint8_t x16;
  uint64_t x17;
  uint8_t x18;
  uint64_t x19;
  uint8_t x20;
  uint64_t x21;
  uint8_t x22;
  uint64_t x23;
  uint8_t x24;
  uint8_t x25;
  uint64_t x26;
  uint8_t x27;
  uint64_t x28;
  uint8_t x29;
  uint64_t x30;
  uint8_t x31;
  uint64_t x32;
  uint8_t x33;
  uint64_t x34;
  uint8_t x35;
  uint8_t x36;
  uint64_t x37;
  uint8_t x38;
  uint64_t x39;
  uint8_t x40;
  uint64_t x41;
  uint8_t x42;
  uint64_t x43;
  uint8_t x44;
  uint64_t x45;
  uint8_t x46;
  uint64_t x47;
  uint8_t x48;
  uint8_t x49;
  fiat_poly1305_subborrowx_u44(&x1, &x2, 0x0, (arg1[0]),
                               UINT64_C(0xffffffffffb));
  fiat_poly1305_subborrowx_u43(&x3, &x4, x2, (arg1[1]),
                               UINT64_C(0x7ffffffffff));
  fiat_poly1305_subborrowx_u43(&x5, &x6, x4, (arg1[2]),
                               UINT64_C(0x7ffffffffff));
  fiat_poly1305_cmovznz_u64(&x7, x6, 0x0, UINT64_C(0xffffffffffffffff));
  fiat_poly1305_addcarryx_u44(&x8, &x9, 0x0, x1,
                              (x7 & UINT64_C(0xffffffffffb)));
  fiat_poly1305_addcarryx_u43(&x10, &x11, x9, x3,
                              (x7 & UINT64_C(0x7ffffffffff)));
  fiat_poly1305_addcarryx_u43(&x12, &x13, x11, x5,
                              (x7 & UINT64_C(0x7ffffffffff)));
  x14 = (x12 << 7);
  x15 = (x10 << 4);
  x16 = (uint8_t)(x8 & UINT8_C(0xff));
  x17 = (x8 >> 8);
  x18 = (uint8_t)(x17 & UINT8_C(0xff));
  x19 = (x17 >> 8);
  x20 = (uint8_t)(x19 & UINT8_C(0xff));
  x21 = (x19 >> 8);
  x22 = (uint8_t)(x21 & UINT8_C(0xff));
  x23 = (x21 >> 8);
  x24 = (uint8_t)(x23 & UINT8_C(0xff));
  x25 = (uint8_t)(x23 >> 8);
  x26 = (x15 + (uint64_t)x25);
  x27 = (uint8_t)(x26 & UINT8_C(0xff));
  x28 = (x26 >> 8);
  x29 = (uint8_t)(x28 & UINT8_C(0xff));
  x30 = (x28 >> 8);
  x31 = (uint8_t)(x30 & UINT8_C(0xff));
  x32 = (x30 >> 8);
  x33 = (uint8_t)(x32 & UINT8_C(0xff));
  x34 = (x32 >> 8);
  x35 = (uint8_t)(x34 & UINT8_C(0xff));
  x36 = (uint8_t)(x34 >> 8);
  x37 = (x14 + (uint64_t)x36);
  x38 = (uint8_t)(x37 & UINT8_C(0xff));
  x39 = (x37 >> 8);
  x40 = (uint8_t)(x39 & UINT8_C(0xff));
  x41 = (x39 >> 8);
  x42 = (uint8_t)(x41 & UINT8_C(0xff));
  x43 = (x41 >> 8);
  x44 = (uint8_t)(x43 & UINT8_C(0xff));
  x45 = (x43 >> 8);
  x46 = (uint8_t)(x45 & UINT8_C(0xff));
  x47 = (x45 >> 8);
  x48 = (uint8_t)(x47 & UINT8_C(0xff));
  x49 = (uint8_t)(x47 >> 8);
  out1[0] = x16;
  out1[1] = x18;
  out1[2] = x20;
  out1[3] = x22;
  out1[4] = x24;
  out1[5] = x27;
  out1[6] = x29;
  out1[7] = x31;
  out1[8] = x33;
  out1[9] = x35;
  out1[10] = x38;
  out1[11] = x40;
  out1[12] = x42;
  out1[13] = x44;
  out1[14] = x46;
  out1[15] = x48;
  out1[16] = x49;
}

/*
 * The function fiat_poly1305_from_bytes deserializes a field element from bytes
 * in little-endian order.
 *
 * Postconditions:
 *   eval out1 mod m = bytes_eval arg1 mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~>
 * 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~>
 * 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~>
 * 0xff], [0x0 ~> 0xff], [0x0 ~> 0x3]]
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_from_bytes(fiat_poly1305_tight_field_element out1,
                         const uint8_t arg1[17]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint8_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint8_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
  fiat_poly1305_uint1 x31;
  uint64_t x32;
  uint64_t x33;
  uint64_t x34;
  uint64_t x35;
  uint64_t x36;
  uint64_t x37;
  x1 = ((uint64_t)(arg1[16]) << 41);
  x2 = ((uint64_t)(arg1[15]) << 33);
  x3 = ((uint64_t)(arg1[14]) << 25);
  x4 = ((uint64_t)(arg1[13]) << 17);
  x5 = ((uint64_t)(arg1[12]) << 9);
  x6 = ((uint64_t)(arg1[11]) * 0x2);
  x7 = ((uint64_t)(arg1[10]) << 36);
  x8 = ((uint64_t)(arg1[9]) << 28);
  x9 = ((uint64_t)(arg1[8]) << 20);
  x10 = ((uint64_t)(arg1[7]) << 12);
  x11 = ((uint64_t)(arg1[6]) << 4);
  x12 = ((uint64_t)(arg1[5]) << 40);
  x13 = ((uint64_t)(arg1[4]) << 32);
  x14 = ((uint64_t)(arg1[3]) << 24);
  x15 = ((uint64_t)(arg1[2]) << 16);
  x16 = ((uint64_t)(arg1[1]) << 8);
  x17 = (arg1[0]);
  x18 = (x16 + (uint64_t)x17);
  x19 = (x15 + x18);
  x20 = (x14 + x19);
  x21 = (x13 + x20);
  x22 = (x12 + x21);
  x23 = (x22 & UINT64_C(0xfffffffffff));
  x24 = (uint8_t)(x22 >> 44);
  x25 = (x11 + (uint64_t)x24);
  x26 = (x10 + x25);
  x27 = (x9 + x26);
  x28 = (x8 + x27);
  x29 = (x7 + x28);
  x30 = (x29 & UINT64_C(0x7ffffffffff));
  x31 = (fiat_poly1305_uint1)(x29 >> 43);
  x32 = (x6 + (uint64_t)x31);
  x33 = (x5 + x32);
  x34 = (x4 + x33);
  x35 = (x3 + x34);
  x36 = (x2 + x35);
  x37 = (x1 + x36);
  out1[0] = x23;
  out1[1] = x30;
  out1[2] = x37;
}

/*
 * The function fiat_poly1305_relax is the identity function converting from
 * tight field elements to loose field elements.
 *
 * Postconditions:
 *   out1 = arg1
 *
 */
static FIAT_POLY1305_FIAT_INLINE void
fiat_poly1305_relax(fiat_poly1305_loose_field_element out1,
                    const fiat_poly1305_tight_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  x1 = (arg1[0]);
  x2 = (arg1[1]);
  x3 = (arg1[2]);
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
}
