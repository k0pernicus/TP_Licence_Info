export CC=gcc
export CFLAGS=-W -Wall
SRC=src

all: reduction

reduction:
	(cd $(SRC) && $(MAKE))

.PHONY: clean cleanall

clean:
	(cd $(SRC) && $(MAKE) $@)

rmexec:
	(cd $(SRC) && $(MAKE) $@)

realclean: clean rmexec
