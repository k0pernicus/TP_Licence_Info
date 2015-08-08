all: compile .PHONY

MLOOK = Sources/mlook.c
MGREP = Sources/mgrep.c
OBJECT = mlook.o mgrep.o

OPTIONS = -Wall -ansi -Werror -pedantic

compile: compileMgrep compileMlook

compileMlook: mlook
	gcc $(OPTIONS) -o mlook mlook.o

mlook: $(MLOOK)
	gcc $(OPTIONS) -c $(MLOOK)

compileMgrep: mgrep
	gcc $(OPTIONS) -o mgrep mgrep.o

mgrep: $(MGREP)
	gcc $(OPTIONS) -c $(MGREP)

.PHONY: realclean clean

clean:
	rm -f *~ Sources/*~

realclean:
	rm -f $(OBJECT)
