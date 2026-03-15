# FizzBuzz Teaching Tool

This repository is a small Linux CLI program written in C17. It uses a
Phase-Oriented C style to keep control flow explicit, behavior
deterministic, and the codebase easy to audit end-to-end.

## Goals

- terminal-first behavior
- offline-friendly build and test flow
- strict input validation
- deterministic stdout/stderr handling
- small, readable modules

## Build

Build with the default system compiler:

```sh
make
```

The resulting executable is:

```sh
./fizzbuzz
```

Useful build targets:

```sh
make help
make clean
make test
```

## Usage

```text
fizzbuzz [options] <start> <end>
fizzbuzz --help
fizzbuzz --version
```

Options:

- `-a <divisor>` set the first divisor, default `3`
- `-A <word>` set the first replacement word, default `Fizz`
- `-b <divisor>` set the second divisor, default `5`
- `-B <word>` set the second replacement word, default `Buzz`
- `-h`, `--help` print help and exit `0`
- `-V`, `--version` print version and exit `0`

Exit codes:

- `0` success
- `1` general failure
- `2` CLI usage or validation failure

## Examples

Classic run:

```sh
./fizzbuzz 1 15
```

Custom rules:

```sh
./fizzbuzz -a 2 -A Pop -b 4 -B Snap 1 8
```

Help and version:

```sh
./fizzbuzz --help
./fizzbuzz --version
```

## Tests

Shell tests live under `tests/` and run through:

```sh
make test
```

The current test coverage includes:

- classic FizzBuzz output
- custom divisor and word behavior
- help and version output
- invalid range rejection
- unknown option rejection
- zero divisor rejection
- help/version misuse with positional arguments
- missing values after `-a`, `-A`, `-b`, and `-B`
- malformed numeric input for divisors and positional arguments
- `LONG_MAX` single-value range handling

## Source Layout

- `src/main.c` program orchestration
- `src/cli.c` argument parsing and validation
- `src/output.c` output formatting and sequence emission
- `src/fizzbuzz.h` shared types and interfaces
- `tests/basic.sh` shell-based acceptance checks

## Design Notes

The code follows the repository's Phase-Oriented C guidance. Functions
use named phases such as `validate_input`, `initialize_state`,
`read_inputs`, `check_invariants`, `emit_results`, and `cleanup` so the
execution path remains explicit during review.
