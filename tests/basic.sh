#!/bin/sh

set -eu

prog=./fizzbuzz

tmpdir=$(mktemp -d)
trap 'rm -rf "$tmpdir"' EXIT HUP INT TERM

expect_failure() {
    label=$1
    expected_stderr=$2
    shift 2

    stdout_file=$tmpdir/"$label"_stdout.txt
    stderr_file=$tmpdir/"$label"_stderr.txt

    if "$prog" "$@" >"$stdout_file" 2>"$stderr_file"; then
        printf 'expected command to fail: %s\n' "$label" >&2
        exit 1
    fi

    test ! -s "$stdout_file"
    grep -q "$expected_stderr" "$stderr_file"
}

expected_classic=$tmpdir/expected_classic.txt
cat <<'EOF' >"$expected_classic"
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
EOF

"$prog" 1 15 >"$tmpdir/actual_classic.txt"
cmp "$expected_classic" "$tmpdir/actual_classic.txt"

expected_custom=$tmpdir/expected_custom.txt
cat <<'EOF' >"$expected_custom"
1
Pop
3
PopSnap
5
Pop
7
PopSnap
EOF

"$prog" -a 2 -A Pop -b 4 -B Snap 1 8 >"$tmpdir/actual_custom.txt"
cmp "$expected_custom" "$tmpdir/actual_custom.txt"

"$prog" --help >"$tmpdir/help.txt"
grep -q '^Usage: fizzbuzz' "$tmpdir/help.txt"

"$prog" --version >"$tmpdir/version.txt"
grep -q '^fizzbuzz 0.1.0$' "$tmpdir/version.txt"

expect_failure invalid_range 'start must be less than or equal to end' 5 1
expect_failure unknown_option 'unsupported option: --bogus' --bogus
expect_failure zero_divisor 'divisor for option -a must not be zero' -a 0 1 3
expect_failure help_with_args 'help/version options do not accept positional arguments' --help 1 3
expect_failure missing_a_value 'missing value for option -a' -a
expect_failure missing_A_value 'missing value for option -A' -A
expect_failure missing_b_value 'missing value for option -b' -b
expect_failure missing_B_value 'missing value for option -B' -B
expect_failure invalid_a_integer 'invalid integer for option -a: nope' -a nope 1 3
expect_failure invalid_b_integer 'invalid integer for option -b: nope' -b nope 1 3
expect_failure invalid_start_integer 'invalid integer argument: nope' nope 3
expect_failure invalid_end_integer 'invalid integer argument: nope' 1 nope

expected_longmax=$tmpdir/expected_longmax.txt
long_bits=$(getconf LONG_BIT)

case "$long_bits" in
    32) long_max=2147483647 ;;
    64) long_max=9223372036854775807 ;;
    *)
        printf 'unsupported long width for test: %s\n' "$long_bits" >&2
        exit 1
        ;;
esac

printf '%s\n' "$long_max" >"$expected_longmax"

"$prog" "$long_max" "$long_max" >"$tmpdir/actual_longmax.txt"
cmp "$expected_longmax" "$tmpdir/actual_longmax.txt"
