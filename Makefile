# unitlint build

CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic
CPPFLAGS ?=
LDFLAGS ?=
DEPFLAGS = -MMD -MP

SRC := \
	src/main.c \
	src/cli.c \
	src/file_io.c \
	src/parser.c \
	src/registry.c \
	src/report_check.c \
	src/report_summary.c \
	src/report_directives.c

OBJ := $(SRC:.c=.o)
DEP := $(OBJ:.o=.d)

.PHONY: all clean help test

all: unitlint

unitlint: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f unitlint $(OBJ) $(DEP)

test: unitlint
	sh tests/smoke_build.sh

help:
	@printf '%s\n' 'Targets: all unitlint test clean help'

-include $(DEP)
