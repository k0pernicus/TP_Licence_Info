export CC=gcc
export CFLAGS=-W -Wall
export LDFLAGS=-m32
export EXEC_DIR=bin
export SRC=src
export EXEC=$(EXEC_DIR)/ping_pong

all: ping_pong

ping_pong:
	(cd $(SRC) && $(MAKE))

.PHONY: clean rmexec

clean:
	(cd $(SRC) && $(MAKE) $@)

rmexec:
	(cd $(SRC) && $(MAKE) $@)