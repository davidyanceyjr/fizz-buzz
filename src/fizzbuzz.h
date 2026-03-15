#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <stdio.h>

#define FIZZBUZZ_VERSION "0.1.0"

enum exit_code {
    EXIT_OK = 0,
    EXIT_FAILURE_GENERAL = 1,
    EXIT_FAILURE_USAGE = 2
};

struct rule {
    long divisor;
    const char *word;
};

struct config {
    long start;
    long end;
    struct rule rule1;
    struct rule rule2;
    int show_help;
    int show_version;
};

int fizzbuzz_parse_args(int argc, char **argv, struct config *cfg);
int fizzbuzz_emit_sequence(const struct config *cfg, FILE *stream);
void fizzbuzz_print_help(FILE *stream);
void fizzbuzz_print_version(FILE *stream);

#endif
