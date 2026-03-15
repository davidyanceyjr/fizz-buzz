# FizzBuzz Teaching Tool — Requirements

## 1. Purpose

This document defines the testable requirements for the FizzBuzz Teaching Tool, a Linux command-line application written in C.

The goal is to transform the familiar FizzBuzz exercise into a small but disciplined software engineering project with explicit CLI behavior, validation, deterministic output, and shell-testable results.

This document defines what the system must do.
It does not define internal implementation details.

---

## 2. Scope

The application shall:

- run as a terminal-first CLI program on Linux
- evaluate integers over a user-specified inclusive range
- apply two configurable divisibility rules
- print one output line per integer in the selected range
- provide help and version output
- fail clearly and safely on invalid input

The application shall not:

- provide a GUI
- depend on external runtime frameworks
- read configuration files in the initial version
- process unbounded or streaming input in the initial version

---

## 3. Definitions

- **Range**: An inclusive numeric interval from `start` through `end`
- **Rule**: A pair consisting of a non-zero divisor and a replacement word
- **Classic FizzBuzz**: Rule 1 = `3 -> Fizz`, Rule 2 = `5 -> Buzz`
- **Diagnostic output**: Human-readable error or informational output written to standard error
- **Normal output**: Program result lines written to standard output

---

## 4. Functional Requirements

### FR-001 Program Invocation

The application shall be invokable from the Linux command line as a single executable.

### FR-002 Range Input

The application shall accept a start value and an end value as required positional numeric arguments.

### FR-003 Inclusive Range Processing

The application shall process every integer from `start` through `end`, inclusive.

### FR-004 Default Rules

When no custom rules are supplied, the application shall use:

- divisor `3` with word `Fizz`
- divisor `5` with word `Buzz`

### FR-005 Custom Rule 1

The application shall allow the user to override the first divisor and replacement word using command-line options.

### FR-006 Custom Rule 2

The application shall allow the user to override the second divisor and replacement word using command-line options.

### FR-007 Rule Evaluation

For each integer in the selected range, the application shall:

- print the first replacement word if divisible by rule 1 divisor
- print the second replacement word if divisible by rule 2 divisor
- print the concatenation of both words if divisible by both divisors
- print the numeric value if divisible by neither divisor

### FR-008 One Line Per Result

The application shall print exactly one result line per processed integer.

### FR-009 Deterministic Output

Given the same valid inputs, the application shall produce the same output.

### FR-010 Help Output

The application shall provide a help option that prints usage information and exits successfully without normal result output.

### FR-011 Version Output

The application shall provide a version option that prints version information and exits successfully without normal result output.

### FR-012 Invalid Numeric Input

The application shall reject non-numeric values supplied where numeric input is required.

### FR-013 Invalid Range Order

The application shall reject input where `start > end`.

### FR-014 Zero Divisor Rejection

The application shall reject a rule divisor of zero.

### FR-015 Unsupported Option Rejection

The application shall reject unsupported flags or malformed options.

### FR-016 Error Signaling

On invalid input or invalid invocation, the application shall:

- print a clear diagnostic message to standard error
- return a non-zero exit code
- produce no partial normal output

### FR-017 Standard Stream Separation

The application shall write result lines to standard output and diagnostics to standard error.

### FR-018 Shell-Friendly Behavior

The application shall behave predictably in shell pipelines by avoiding prompts, interactive behavior, or non-deterministic formatting.

---

## 5. Non-Functional Requirements

### NFR-001 Language

The application shall be implemented in C.

### NFR-002 Platform

The application shall compile and run on Linux using a standard C toolchain such as `gcc` or `clang`.

### NFR-003 Dependency Restraint

The application shall avoid unnecessary external runtime dependencies.

### NFR-004 Readability

The codebase shall remain small enough for a learner to read end-to-end.

### NFR-005 Modularity

The implementation should separate CLI parsing, validation, evaluation, and output responsibilities into distinct logical units.

### NFR-006 Testability

The application shall be testable from the shell using automated tests.

### NFR-007 Maintainability

The program behavior shall be documented clearly enough that implementation and tests can be checked against the specification.

---

## 6. Constraints

### CON-001 Terminal-First

The initial version shall operate entirely through CLI arguments and standard streams.

### CON-002 Synchronous Execution

The initial version shall execute synchronously in a single process.

### CON-003 Plain Text Output

The initial version shall emit plain text output only.

### CON-004 Bounded Teaching Scope

The initial version shall prioritize clarity and teaching value over extensibility or performance optimization.

---

## 7. Acceptance Criteria

The system shall be considered acceptable when all of the following are true:

### AC-001 Classic Run

Given a valid range such as `1 15`, the application prints the expected classic FizzBuzz sequence.

### AC-002 Small Range Run

Given a valid small range such as `14 17`, the application prints exactly four lines with correct substitutions.

### AC-003 Custom Rule Run

Given valid custom divisors and words, the application prints output according to the configured rules.

### AC-004 Help

Given the help flag, the application exits successfully and prints usage information.

### AC-005 Version

Given the version flag, the application exits successfully and prints version information.

### AC-006 Invalid Range

Given `start > end`, the application exits non-zero, prints a diagnostic to standard error, and prints no result lines.

### AC-007 Non-Numeric Input

Given non-numeric required input, the application exits non-zero, prints a diagnostic to standard error, and prints no result lines.

### AC-008 Zero Divisor

Given a divisor of zero, the application exits non-zero, prints a diagnostic to standard error, and prints no result lines.

### AC-009 Unknown Option

Given an unsupported option, the application exits non-zero, prints a diagnostic to standard error, and prints no result lines.

### AC-010 Stream Discipline

In successful runs, only result lines are written to standard output.
In failure runs, diagnostics are written to standard error.

---

## 8. Traceability Seed

These requirement IDs are intended to map directly into later specification sections, tests, and issue creation.

Suggested early implementation grouping:

- CLI parsing: FR-001, FR-002, FR-010, FR-011, FR-015
- validation: FR-012, FR-013, FR-014, FR-016
- evaluation: FR-003, FR-004, FR-005, FR-006, FR-007, FR-008
- output discipline: FR-009, FR-017, FR-018