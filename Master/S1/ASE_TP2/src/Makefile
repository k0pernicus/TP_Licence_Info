SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) -o ../$(EXEC) $^ $(LDFLAGS)

%.o:%.c
	$(CC) -m32 -o $@ $(CFLAGS) -c $<

.PHONY: clean rmexec

clean:
	rm -rf *.o

rmexec:
	rm ../$(EXEC)