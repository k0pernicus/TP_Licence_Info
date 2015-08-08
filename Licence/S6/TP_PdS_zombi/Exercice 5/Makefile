all: forkfork

CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
OBJECTS = forkfork

forkfork: forkfork.c
	$(CC) $(CFLAGS) forkfork.c -o forkfork

.PHONY: clean realclean rmobjects

clean:
	rm -Rf *~ *.dSYM *.DS_Store

realclean:
	rm -f *.o

rmobjects:
	rm -f $(OBJECTS)
