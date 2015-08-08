all: prlimit maccess

CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
EXEC = prlimit maccess

prlimit: prlimit.c
	$(CC) $(CFLAGS) prlimit.c -o prlimit

maccess: maccess.c
	$(CC) $(CFLAGS) maccess.c -o maccess

.PHONY: clean realclean

clean:
	rm -fR *~ *.dSYM

realclean:
	rm -f $(EXEC)
