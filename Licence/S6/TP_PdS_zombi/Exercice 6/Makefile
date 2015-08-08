all: race

CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
OBJECTS = race

race: race.c
	$(CC) $(CFLAGS) race.c -o race

.PHONY: clean realclean rmobjects

clean:
	rm -Rf *~ *.dSYM *.DS_Store

realclean:
	rm -f *.o

rmobjects:
	rm -f $(OBJECTS)
