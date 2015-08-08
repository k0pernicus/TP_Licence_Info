SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) -o ../$(BIN)/$(EXEC) $^ $(LDFLAGS) -lm

%.o:%.c
	$(CC) -o $@ $(CFLAGS) -c $<

.PHONY: clean rmexec realclean

clean:
	rm -rf *.o

rmexec:
	rm ../$(BIN)/$(EXEC)

realclean: clean rmexec
