export CC=gcc
export CFLAGS=-W -Wall
export LINKER=`pkg-config --cflags --libs glib-2.0`
SRC=src

all: normalisation

normalisation:
	(cd $(SRC) && $(MAKE))

.PHONY: clean cleanall

clean:
	(cd $(SRC) && $(MAKE) $@)

rmexec:
	(cd $(SRC) && $(MAKE) $@)

realclean: clean rmexec