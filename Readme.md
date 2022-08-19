# Minimum Working example for running fiat - methods

## Usage

### Compile

Generate the binary `mwe.out` with

```bash
make
```

### Run

Run it with the iterations to perform (defaults to 10000, if none is specified)
`./mwe.out 10000`
or use the `run` target of the Makefile with

```bash
make run
```

to run it through `time`


## Methods of interest

Those are the current methods that we are optimizing.
The ~`mul` functions need parameters `out`, `in`, `in`, the ~`square` functions only `out`, `in`.


```
fiat_25519_carry_mul
fiat_25519_carry_square
fiat_p384_mul
fiat_p384_square
fiat_p224_mul
fiat_p224_square
fiat_p448_carry_mul
fiat_p448_carry_square
fiat_p521_carry_mul
fiat_p521_carry_square
fiat_p434_mul
fiat_p434_square
fiat_p256_mul
fiat_p256_square
fiat_secp256k1_mul
fiat_secp256k1_square
fiat_poly1305_carry_mul
fiat_poly1305_carry_square
```
List obtained with: `grep -e ' [a-z0-9_]\+\(square\|mul\)(' -r fiat -ho | sed 's/(//g'`

## Credit

The Fiat-files in the `fiat` directory are from the [Fiat Cryptography](https://github.com/mit-plv/fiat-crypto/tree/0f61b56dda31384cbeb76f14b03b522d21e27b26/fiat-c/src) project.
The SCMUL function is based on from [OpenSSL](https://github.com/openssl/openssl/blob/master/crypto/ec/curve25519.c) and [SUPERCOP](https://bench.cr.yp.to/supercop.html), replacing the field-method with the one's from fiat.
