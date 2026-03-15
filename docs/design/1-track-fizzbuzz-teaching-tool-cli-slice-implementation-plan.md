# Implementation Plan: Issue #1 Track FizzBuzz Teaching Tool CLI Slice

## Goal

Record the current completion state of the regularized FizzBuzz CLI
slice so the workflow artifacts match the implementation and shell-test
coverage already present in the repository.

## Slice 1: Overflow-safe range emission

Status:

- Completed.

Problem addressed:

`fizzbuzz_emit_sequence()` needed to avoid signed overflow when the
inclusive range ended at `LONG_MAX`.

Files changed:

- `src/output.c`

Interface impact:

- None. `fizzbuzz_emit_sequence(const struct config *, FILE *)`
  remained stable.

Implemented approach:

- The emission loop now prints the current value, stops when
  `value == cfg->end`, and never performs a signed increment past the
  final value.

Validation command:

- `make test`

Likely commit boundary:

- `fix: avoid signed overflow in sequence emission`

Residual risk:

- Low. Ordinary range behavior remains unchanged.

## Slice 2: Shell coverage for CLI edge cases

Status:

- Completed.

Problem addressed:

The shell suite needed direct coverage for parser failure paths and an
overflow-adjacent boundary case.

Files changed:

- `tests/basic.sh`

Interface impact:

- None.

Implemented approach:

- Added failing-invocation checks for missing values after `-a`, `-A`,
  `-b`, and `-B`.
- Added malformed numeric input cases for option divisors and
  positional arguments.
- Added a single-value `LONG_MAX` range regression check.

Validation command:

- `make test`

Likely commit boundary:

- `test: cover cli edge cases`

Residual risk:

- Low. The main remaining limitation is that coverage is still
  acceptance-level shell testing rather than unit-level isolation.

## Slice 3: Reassess evaluation separation

Status:

- Deferred.

Problem:

Rule evaluation and stream emission remain in the same module. That is
acceptable for the current teaching-scale implementation, but a
refactor could become justified if future testing or review reveals a
clarity problem.

Files to change if revisited:

- `src/output.c`
- `src/fizzbuzz.h`
- possibly a new source file if a pure evaluation helper is introduced

Interface impact:

- Optional and should be avoided unless a concrete need emerges.

Approach if revisited:

- Prefer a small internal helper over a broader redesign.
- Proceed only if tests or review feedback show that the current module
  boundary is impeding clarity.

Validation command:

- `make test`

Likely commit boundary:

- `refactor: isolate fizzbuzz value rendering`

Risk:

- Medium. This is the first slice that can introduce unnecessary
  complexity if done prematurely.

## Recommended Order

1. Treat Slice 1 as complete.
2. Treat Slice 2 as complete.
3. Revisit Slice 3 only if new evidence justifies it.

## Recommended Next Action

Move Issue #1 into closure-oriented workflow work such as patch review,
docs sync, PR preparation, or explicit issue closure if no additional
artifacts are required.
