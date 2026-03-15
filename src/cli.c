#include "fizzbuzz.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_long(const char *text, long *out_value)
{
    int rc = -1;
    char *end = NULL;
    long value = 0;

    goto validate_input;

validate_input:
    if (!text || !out_value || text[0] == '\0')
        goto cleanup;
    goto transform_state;

transform_state:
    errno = 0;
    value = strtol(text, &end, 10);
    if (errno != 0 || end == text || *end != '\0')
        goto cleanup;
    goto emit_results;

emit_results:
    *out_value = value;
    rc = 0;

cleanup:
    return rc;
}

int fizzbuzz_parse_args(int argc, char **argv, struct config *cfg)
{
    int rc = EXIT_FAILURE_USAGE;
    int i = 0;
    int positional_count = 0;
    long positional_values[2] = {0, 0};

    goto validate_input;

validate_input:
    if (!argv || !cfg)
        goto cleanup;
    goto initialize_state;

initialize_state:
    *cfg = (struct config){
        .start = 0,
        .end = 0,
        .rule1 = {3, "Fizz"},
        .rule2 = {5, "Buzz"},
        .show_help = 0,
        .show_version = 0
    };
    goto read_inputs;

read_inputs:
    for (i = 1; i < argc; ++i) {
        const char *arg = argv[i];

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            cfg->show_help = 1;
            continue;
        }

        if (strcmp(arg, "-V") == 0 || strcmp(arg, "--version") == 0) {
            cfg->show_version = 1;
            continue;
        }

        if (strcmp(arg, "-a") == 0 || strcmp(arg, "-b") == 0) {
            long divisor = 0;

            if (++i >= argc) {
                fprintf(stderr, "missing value for option %s\n", arg);
                goto cleanup;
            }

            if (parse_long(argv[i], &divisor) != 0) {
                fprintf(stderr, "invalid integer for option %s: %s\n", arg, argv[i]);
                goto cleanup;
            }

            if (divisor == 0) {
                fprintf(stderr, "divisor for option %s must not be zero\n", arg);
                goto cleanup;
            }

            if (strcmp(arg, "-a") == 0)
                cfg->rule1.divisor = divisor;
            else
                cfg->rule2.divisor = divisor;

            continue;
        }

        if (strcmp(arg, "-A") == 0 || strcmp(arg, "-B") == 0) {
            if (++i >= argc) {
                fprintf(stderr, "missing value for option %s\n", arg);
                goto cleanup;
            }

            if (argv[i][0] == '\0') {
                fprintf(stderr, "word for option %s must not be empty\n", arg);
                goto cleanup;
            }

            if (strcmp(arg, "-A") == 0)
                cfg->rule1.word = argv[i];
            else
                cfg->rule2.word = argv[i];

            continue;
        }

        if (arg[0] == '-') {
            fprintf(stderr, "unsupported option: %s\n", arg);
            goto cleanup;
        }

        if (positional_count >= 2) {
            fprintf(stderr, "expected exactly two positional arguments\n");
            goto cleanup;
        }

        if (parse_long(arg, &positional_values[positional_count]) != 0) {
            fprintf(stderr, "invalid integer argument: %s\n", arg);
            goto cleanup;
        }

        ++positional_count;
    }
    goto check_invariants;

check_invariants:
    if (cfg->show_help || cfg->show_version) {
        if (positional_count != 0) {
            fprintf(stderr, "help/version options do not accept positional arguments\n");
            goto cleanup;
        }

        rc = EXIT_OK;
        goto cleanup;
    }

    if (positional_count != 2) {
        fprintf(stderr, "expected exactly two positional arguments\n");
        goto cleanup;
    }

    cfg->start = positional_values[0];
    cfg->end = positional_values[1];

    if (cfg->start > cfg->end) {
        fprintf(stderr, "start must be less than or equal to end\n");
        goto cleanup;
    }
    goto emit_results;

emit_results:
    rc = EXIT_OK;

cleanup:
    return rc;
}
