all: mdo

CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
OBJECTS = makeargv.o mdo.o
EXEC = mdo

mdo: makeargv main
	$(CC) $(OBJECTS) -o mdo

makeargv: makeargv.c
	$(CC) $(CFLAGS) -c makeargv.c

main: mdo.c
	$(CC) $(CFLAGS) -c mdo.c

.PHONY: clean realclean rmobjects

clean:
	rm -Rf *~ *.dSYM *.DS_Store

realclean:
	rm -f $(OBJECTS)

rmexec:
	rm -f $(EXEC)
