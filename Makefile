CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Werror -pedantic
CPPFLAGS ?=
LDFLAGS ?=
DEPFLAGS = -MMD -MP

PROGRAM := fizzbuzz
SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
DEP := $(OBJ:.o=.d)
TESTS := $(sort $(wildcard tests/*.sh))

.PHONY: all clean help test check-src

all: $(PROGRAM)

check-src:
	@test -n "$(SRC)" || { \
		printf '%s\n' 'make: no C sources found in src/' >&2; \
		exit 1; \
	}

$(PROGRAM): check-src $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJ) $(DEP)

test: $(PROGRAM)
	@if [ -n "$(TESTS)" ]; then \
		for test_script in $(TESTS); do \
			sh "$$test_script" || exit $$?; \
		done; \
	else \
		printf '%s\n' 'make: no shell tests found in tests/'; \
	fi

help:
	@printf '%s\n' 'Targets: all fizzbuzz test clean help'

-include $(DEP)
