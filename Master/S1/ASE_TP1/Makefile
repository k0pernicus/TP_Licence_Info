export CC=gcc
export CFLAGS=-W -Wall
export LDFLAGS=-m32
EXEC_DIR=bin
SRC_DIR_MUL=src_mul
SRC_DIR_DS=src_display_stack
EXEC=$(EXEC_DIR)/try_mul

all: mul ds

mul:
	(cd $(SRC_DIR_MUL) && $(MAKE))

ds:
	(cd $(SRC_DIR_DS) && $(MAKE))

.PHONY: clean rmexec

clean:
	(cd $(SRC_DIR_MUL) && $(MAKE) $@)
	(cd $(SRC_DIR_DS) && $(MAKE) $@)

rmexec:
	(cd $(SRC_DIR_MUL) && $(MAKE) $@)
	(cd $(SRC_DIR_DS) && $(MAKE) $@)