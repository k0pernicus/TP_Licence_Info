SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
PRG=act-tp2

all: main

main: $(OBJ)
	$(CC) -o $(PRG) $(LINKER) $^

%.o:%.c
	$(CC) $(CLAGS) -o $@ $(LINKER) -c $<

clean:
	rm -f *.o

rmexec:
	rm -f $(PRG)