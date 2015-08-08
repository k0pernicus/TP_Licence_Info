all: mtail msimpliste

CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
EXEC = mtail msimpliste
OBJECTS = mefficace.o mutile.o main.o

msimpliste: msimpliste.c
	$(CC) $(CFLAGS) msimpliste.c -o msimpliste

mefficace: mefficace.c
	$(CC) $(CFLAGS) -c mefficace.c

mutile: mutile.c
	$(CC) $(CFLAGS) -c mutile.c

main : main.c
	$(CC) $(CFLAGS) -c main.c

mtail: mefficace mutile main
	$(CC) $(CFLAGS) $(OBJECTS) -o mtail

.PHONY: clean realclean

clean:
	rm -fR *~ *.dSYM .DS_Store

rmobjects:
	rm -f *.o

realclean:
	rm -f $(EXEC)
