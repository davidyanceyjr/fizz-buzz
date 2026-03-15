# Implementation Plan: Issue #1 Track FizzBuzz Teaching Tool CLI Slice

## Goal

Regularize the current FizzBuzz CLI slice with the smallest meaningful
follow-on implementation work: remove the signed-overflow risk in range
emission and expand shell coverage for known CLI edge cases.

## Slice 1: Make range emission overflow-safe

Problem:

`fizzbuzz_emit_sequence()` currently uses a signed `long` incrementing
loop that can overflow when `cfg->end == LONG_MAX`.

Files to change:

- `src/output.c`
- `src/fizzbuzz.h` only if a helper declaration becomes necessary

Interface impact:

- Prefer no public API change.
- Keep `fizzbuzz_emit_sequence(const struct config *, FILE *)` stable.

Approach:

- Replace the current `for` loop with a form that emits the current
  value, then stops before increment when `value == cfg->end`.
- Preserve the current output format and exit behavior exactly.

Validation command:

- `make test`

Likely commit boundary:

- `fix: avoid signed overflow in sequence emission`

Risk:

- Low. Behavior should remain identical for ordinary ranges.

## Slice 2: Expand shell tests for CLI edge cases

Problem:

Current shell tests do not directly cover several parser failure paths
identified in the design review.

Files to change:

- `tests/basic.sh`

Interface impact:

- None.

Approach:

- Add failing-invocation coverage for missing values after `-a`, `-A`,
  `-b`, and `-B`.
- Add malformed numeric input cases for option divisors and positional
  arguments.
- If Slice 1 lands, add an overflow-adjacent regression check that is
  safe to run quickly.

Validation command:

- `make test`

Likely commit boundary:

- `test: cover cli edge cases`

Risk:

- Low. Main risk is overfitting tests to exact wording instead of
  behavior.

## Slice 3: Reassess whether evaluation needs further separation

Problem:

The current implementation keeps rule evaluation and stream emission in
the same module. That is acceptable now, but may become less clear if
testing needs grow.

Files to change:

- `src/output.c`
- `src/fizzbuzz.h`
- possibly a new source file if a pure evaluation helper is introduced

Interface impact:

- Optional and should be avoided unless Slice 2 shows clear need.

Approach:

- Only proceed if tests or review feedback show that the current
  boundary is impeding clarity.
- Prefer a small internal helper over a broader redesign.

Validation command:

- `make test`

Likely commit boundary:

- `refactor: isolate fizzbuzz value rendering`

Risk:

- Medium. This is the first slice that can introduce unnecessary
  complexity if done prematurely.

## Recommended Order

1. Implement Slice 1.
2. Add Slice 2 test coverage.
3. Skip Slice 3 unless new evidence justifies it.

## Recommended Next Action

Start with Slice 1 in `src/output.c`. It is the only known correctness
risk in the current code and can be verified with the existing test
flow.
