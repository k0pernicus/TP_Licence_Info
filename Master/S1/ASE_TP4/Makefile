export CC = gcc
export CFLAGS = -g -W -Wall
export LFLAGS = -m32
export EXEC = bin/prodcons
SRC = src/

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