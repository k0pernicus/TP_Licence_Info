SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) -o ../$(EXEC) $^ -m32 $(LDFLAGS)

%.o:%.c
	$(CC) -m32 -o $@ $(CFLAGS) -c $<

.PHONY: clean rmexec realclean

clean:
	rm -rf *.o

rmexec:
	rm ../$(EXEC)

realclean: clean rmexec