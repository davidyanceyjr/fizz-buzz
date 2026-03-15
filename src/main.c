#include "fizzbuzz.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    int rc = EXIT_FAILURE_GENERAL;
    struct config cfg = {0};

    goto validate_input;

validate_input:
    if (!argv) {
        fprintf(stderr, "invalid process arguments\n");
        rc = EXIT_FAILURE_GENERAL;
        goto cleanup;
    }
    goto initialize_state;

initialize_state:
    rc = fizzbuzz_parse_args(argc, argv, &cfg);
    if (rc != EXIT_OK)
        goto cleanup;
    goto transform_state;

transform_state:
    if (cfg.show_help) {
        fizzbuzz_print_help(stdout);
        rc = EXIT_OK;
        goto cleanup;
    }

    if (cfg.show_version) {
        fizzbuzz_print_version(stdout);
        rc = EXIT_OK;
        goto cleanup;
    }
    goto emit_results;

emit_results:
    rc = fizzbuzz_emit_sequence(&cfg, stdout);

cleanup:
    return rc;
}
