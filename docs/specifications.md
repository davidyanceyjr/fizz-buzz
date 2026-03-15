# FizzBuzz Teaching Tool --- Specifications

Version: 0.1\
Language: C\
Platform: Linux CLI

This document defines the complete external behavior and functional
requirements for the FizzBuzz Teaching Tool. It serves as the single
source of truth for implementation, testing, and issue creation.

------------------------------------------------------------------------

## 1. System Overview

The FizzBuzz Teaching Tool is a Linux command-line application that
evaluates integers within a user-provided range and applies configurable
divisibility rules.

The application demonstrates:

-   CLI design
-   argument parsing
-   input validation
-   deterministic program output
-   shell-driven testing
-   modular C program structure

------------------------------------------------------------------------

## 2. Execution Model

The program runs synchronously as a single process.

Input: command line arguments\
Output channels:

-   stdout --- normal result output
-   stderr --- diagnostics

Program sequence:

1.  Parse arguments
2.  Validate invocation
3.  Establish rule configuration
4.  Iterate through range
5.  Evaluate rules
6.  Print results
7.  Exit with status code

------------------------------------------------------------------------

## 3. Command Line Interface

### Program Name

fizzbuzz

### Command Synopsis

fizzbuzz \[options\] `<start>`{=html} `<end>`{=html}\
fizzbuzz --help\
fizzbuzz --version

------------------------------------------------------------------------

## 4. Positional Arguments

### start

Signed base‑10 integer representing first number in the inclusive range.

### end

Signed base‑10 integer representing final number in the inclusive range.

------------------------------------------------------------------------

## 5. Options

-a `<divisor>`{=html}\
Set divisor for rule 1 (default: 3)

-A `<word>`{=html}\
Set replacement word for rule 1 (default: Fizz)

-b `<divisor>`{=html}\
Set divisor for rule 2 (default: 5)

-B `<word>`{=html}\
Set replacement word for rule 2 (default: Buzz)

-h, --help\
Show help and exit 0

-V, --version\
Show version and exit 0

------------------------------------------------------------------------

## 6. Default Rule Configuration

Rule 1: 3 → Fizz\
Rule 2: 5 → Buzz

------------------------------------------------------------------------

## 7. Rule Evaluation

For each integer n from start through end inclusive:

1.  token = ""
2.  if n % rule1_divisor == 0 → append rule1_word
3.  if n % rule2_divisor == 0 → append rule2_word
4.  if token != "" print token
5.  else print n

Each result printed with newline.

------------------------------------------------------------------------

## 8. Output Rules

stdout\
• result lines only

stderr\
• diagnostics and usage errors

Failure rules

If invocation fails:

• stdout must remain empty\
• diagnostics written to stderr\
• exit code non‑zero

------------------------------------------------------------------------

## 9. Exit Codes

0 successful execution\
1 general failure\
2 CLI usage / validation failure

------------------------------------------------------------------------

## 10. Validation Rules

### Integer Parsing

These must be valid integers:

start\
end\
rule1 divisor\
rule2 divisor

Non‑numeric values cause failure.

### Range Order

start must be ≤ end.

### Divisors

Divisors must not equal zero.

### Unknown Options

Unsupported flags cause invocation failure.

### Positional Count

Exactly two positional arguments required unless help/version requested.

------------------------------------------------------------------------

## 11. Word Validation

Replacement words must:

• be non‑empty\
• be literal strings\
• remain case‑sensitive

------------------------------------------------------------------------

## 12. Help Output

Help must include:

• program name\
• usage synopsis\
• positional arguments\
• options\
• default rules\
• usage examples

Example structure:

Usage: fizzbuzz \[options\] `<start>`{=html} `<end>`{=html} fizzbuzz
--help fizzbuzz --version

Options: -a `<divisor>`{=html} first divisor (default 3) -A
`<word>`{=html} first word (default Fizz) -b `<divisor>`{=html} second
divisor (default 5) -B `<word>`{=html} second word (default Buzz) -h,
--help help -V, --version version

------------------------------------------------------------------------

## 13. Version Output

Format:

fizzbuzz `<version>`{=html}

Example:

fizzbuzz 0.1.0

------------------------------------------------------------------------

## 14. Behavioral Examples

### Classic Example

Command

fizzbuzz 1 15

Output

1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz

Exit code 0

------------------------------------------------------------------------

### Custom Rules

Command

fizzbuzz -a 2 -A Foo -b 7 -B Bar 1 14

Output

1 Foo 3 Foo 5 Foo Bar Foo 9 Foo 11 Foo 13 FooBar

Exit code 0

------------------------------------------------------------------------

### Invalid Range

fizzbuzz 10 1

stdout empty\
stderr diagnostic\
exit non‑zero

------------------------------------------------------------------------

### Invalid Divisor

fizzbuzz -a 0 1 10

stdout empty\
stderr diagnostic\
exit non‑zero

------------------------------------------------------------------------

### Non‑Numeric Input

fizzbuzz one 10

stdout empty\
stderr diagnostic\
exit non‑zero

------------------------------------------------------------------------

## 15. Determinism

Identical inputs must produce identical output. No randomness or
time‑dependent behavior.

------------------------------------------------------------------------

## 16. Test Contract

Automated tests must verify:

• classic fizzbuzz output\
• custom rules\
• inclusive ranges\
• help output\
• version output\
• invalid ranges\
• invalid divisors\
• invalid numeric input\
• unknown options\
• stdout / stderr separation

------------------------------------------------------------------------

## 17. Out of Scope (v0.1)

• config files\
• environment configuration\
• more than two rules\
• colored output\
• localization\
• GUI\
• streaming input\
• performance optimization for huge ranges

------------------------------------------------------------------------

## 18. Traceable Specification Units

SPEC‑1 CLI parsing\
SPEC‑2 argument validation\
SPEC‑3 rule configuration\
SPEC‑4 range iteration\
SPEC‑5 fizzbuzz evaluation\
SPEC‑6 stdout printing\
SPEC‑7 stderr diagnostics\
SPEC‑8 help command\
SPEC‑9 version command\
SPEC‑10 exit codes\
SPEC‑11 input validation\
SPEC‑12 deterministic behavior\
SPEC‑13 automated testing
