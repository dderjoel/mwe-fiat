# Minimum Working example for running fiat - methods

## Usage

### Compile

Generate the binary `mwe.out` with

```bash
make
```

### Run

Run it with the iterations to perform.
`./mwe.out 10000`
or use the `run` target of the Makefile with

```bash
make run
```

to run it through `time`

## Credit

The Fiat-files in the `fiat` directory are from the [Fiat Cryptography](https://github.com/mit-plv/fiat-crypto/tree/0f61b56dda31384cbeb76f14b03b522d21e27b26/fiat-c/src) project.
