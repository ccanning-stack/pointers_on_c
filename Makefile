CC     := clang
CFLAGS := -Wall -Wextra -std=c11

SRCS       := $(wildcard *.c)
BINS       := $(SRCS:.c=)

DEBUG_DIR  := build/debug
DEBUG_BINS := $(addprefix $(DEBUG_DIR)/,$(BINS))

.PHONY: all debug clean distclean

all: $(BINS)

debug: $(DEBUG_BINS)

%: %.c
	$(CC) $(CFLAGS) -O2 -o $@ $@.c

$(DEBUG_DIR)/%: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -g -O0 -fsanitize=address,undefined -o $@ $(@F).c

clean:
	rm -rf $(BINS) build

distclean: clean
	rm -f *~ \#*\#
