export CC = gcc
SRC = src/
export BIN = bin
export CFLAGS = -g -W -Wall -Werror
export EXEC = heuristique

all: main

main:
	(cd $(SRC) && $(MAKE))

.PHONY: clean rmexec realclean

clean:
	(cd $(SRC) && $(MAKE) $@)

rmexec:
	(cd $(SRC) && $(MAKE) $@)

realclean:
	(cd $(SRC) && $(MAKE) $@)
