all: mdu clean

CC = gcc -Wall -Werror -ansi -pedantic -g
EXEC = mdu

mdu: mdu.c
	$(CC) -D_XOPEN_SOURCE=500 mdu.c -o mdu

clean:
	rm -Rf *~ *.dSYM

realclean:
	rm $(EXEC)
