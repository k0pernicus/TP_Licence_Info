SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
PRG=act-tp3
BIN=../bin

all: main

main: $(OBJ)
	$(CC) -o $(BIN)/$(PRG) $^

%.o:%.c
	$(CC) $(CLAGS) -o $@ -c $<

clean:
	rm -f *.o

rmexec:
	rm -f $(BIN)/$(PRG)
