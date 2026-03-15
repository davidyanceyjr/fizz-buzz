# Design Review: Issue #1 Track FizzBuzz Teaching Tool CLI Slice

## Design Summary

The current implementation uses a small three-part structure that fits
the specification and the repository's Phase-Oriented C style:

- `src/main.c` orchestrates phase flow and exit status handling.
- `src/cli.c` owns argument parsing, default configuration, and
  validation.
- `src/output.c` owns help/version formatting and sequence emission.
- `src/fizzbuzz.h` defines shared types, constants, and interfaces.

This boundary is appropriate for the size of the tool. It keeps control
flow auditable without introducing unnecessary abstraction layers.

## Module Boundaries

### `main`

Responsibilities:

- validate process argument pointers
- initialize top-level program state
- delegate CLI parsing
- dispatch help/version fast paths
- invoke sequence emission
- return final exit code

This file should remain thin and procedural.

### `cli`

Responsibilities:

- parse positional arguments and options
- apply default rule configuration
- validate numeric input
- validate positional count and range ordering
- report usage failures to `stderr`

This is the correct place for user-input normalization and invariant
checks.

### `output`

Responsibilities:

- print help text
- print version text
- emit one output line per processed integer
- keep normal output on `stdout`

This module currently combines user-facing text formatting with FizzBuzz
evaluation. For this teaching-scale program that is acceptable, though a
future refinement could separate pure evaluation from output formatting.

## Data Flow

1. `main()` creates a zeroed `struct config`.
2. `fizzbuzz_parse_args()` populates defaults and applies user input.
3. `main()` checks `show_help` and `show_version`.
4. `fizzbuzz_emit_sequence()` iterates from `start` to `end`.
5. The emission loop stops on the final value before any further signed
   increment is attempted.
5. Each value is evaluated against `rule1` and `rule2`.
6. Output is written directly to the provided stream.

The data path is straightforward and easy to audit.

## Interfaces

The public header exposes only the program-facing contract:

- `fizzbuzz_parse_args()`
- `fizzbuzz_emit_sequence()`
- `fizzbuzz_print_help()`
- `fizzbuzz_print_version()`
- shared `struct rule` and `struct config`

That API surface is small enough for a teaching example. There is no
need for additional indirection or hidden state.

## Failure Handling

The current design handles failure in a disciplined way:

- usage and validation errors are detected before normal execution
- diagnostics go to `stderr`
- success and failure exit codes are explicit
- `main()` centralizes cleanup and return flow

This matches the specification and the project's emphasis on explicit
control flow.

## Risks

- Replacement words are borrowed from `argv`, which is acceptable for
  current process-lifetime usage but would need reconsideration if
  configuration ownership changed.
- Shell-based tests cover the known parser failure paths and a
  `LONG_MAX` single-value range, but coverage is still acceptance-level
  rather than unit-level.
- Numeric parsing still relies directly on `strtol()`, so any future
  requirements around stricter range diagnostics or portability-specific
  parsing behavior would need more explicit handling.

## Alternatives Considered

### Keep evaluation inside `output`

Recommended for now. It minimizes files and keeps the teaching example
 easy to follow.

### Split pure evaluation into a separate module

Viable if narrower unit-style tests become a priority. A helper such as
`fizzbuzz_render_value()` could return either the numeric text or the
combined token, leaving `output` to handle only stream emission.

### Replace phase labels with nested control flow

Not recommended. The current phase labels align with repository
guidance and keep cleanup and dispatch logic explicit.

## Testing Implications

- Continue using `make test` as the primary acceptance check.
- The current shell suite now covers missing values after `-a`, `-A`,
  `-b`, and `-B`.
- The current shell suite now covers malformed numeric cases for option
  divisors and positional arguments.
- The current shell suite now includes a `LONG_MAX` single-value
  regression check for the emission boundary.
- If finer-grained change isolation becomes necessary, add smaller tests
  around parsing and value rendering rather than broadening the CLI
  script indefinitely.

## Assumptions

- The current implementation is being regularized after the fact rather
  than redesigned from scratch.
- Help/version behavior should remain mutually exclusive with positional
  execution.
- The project still prefers narrow modules over generalized framework
  code.

## Recommended Approach

Keep the current module split and phase-oriented control flow. The
recent overflow fix and shell-test expansion are sufficient for this
slice, so the next workflow step should be review/PR preparation rather
than further refactoring unless new requirements appear.
