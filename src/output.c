#include "fizzbuzz.h"

#include <stdio.h>

void fizzbuzz_print_help(FILE *stream)
{
    fprintf(stream,
            "Usage: fizzbuzz [options] <start> <end>\n"
            "       fizzbuzz --help\n"
            "       fizzbuzz --version\n"
            "\n"
            "Options:\n"
            "  -a <divisor>   first divisor (default: 3)\n"
            "  -A <word>      first word (default: Fizz)\n"
            "  -b <divisor>   second divisor (default: 5)\n"
            "  -B <word>      second word (default: Buzz)\n"
            "  -h, --help     show help and exit\n"
            "  -V, --version  show version and exit\n"
            "\n"
            "Examples:\n"
            "  fizzbuzz 1 15\n"
            "  fizzbuzz -a 2 -A Foo -b 7 -B Bar 1 14\n");
}

void fizzbuzz_print_version(FILE *stream)
{
    fprintf(stream, "fizzbuzz %s\n", FIZZBUZZ_VERSION);
}

int fizzbuzz_emit_sequence(const struct config *cfg, FILE *stream)
{
    int rc = EXIT_FAILURE_GENERAL;
    long value = 0;

    goto validate_input;

validate_input:
    if (!cfg || !stream)
        goto cleanup;
    goto read_inputs;

read_inputs:
    value = cfg->start;
    while (value <= cfg->end) {
        int matched = 0;

        if (value % cfg->rule1.divisor == 0) {
            fputs(cfg->rule1.word, stream);
            matched = 1;
        }

        if (value % cfg->rule2.divisor == 0) {
            fputs(cfg->rule2.word, stream);
            matched = 1;
        }

        if (!matched)
            fprintf(stream, "%ld", value);

        fputc('\n', stream);

        if (value == cfg->end)
            break;

        ++value;
    }
    goto emit_results;

emit_results:
    rc = EXIT_OK;

cleanup:
    return rc;
}
