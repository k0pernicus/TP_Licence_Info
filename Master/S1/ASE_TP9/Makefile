# Carette Antonin
# Owczarek Valentin
# Makefile type
# jeudi 27 nov
# Modification pour TP ASE gestion memoire
#------------------------------------------------------------

CC      = gcc
CFLAGS  = -pedantic -Wall -Wextra -Wstrict-prototypes
CFLAGS += -Wpointer-arith -Wcast-qual
CFLAGS += -Wcast-align -Wwrite-strings -Wnested-externs -g
#CFLAGS += -Werror #not human anymore
LDFLAGS = -g

SRC = src
ROOTDIR =
LIBDIR = $(ROOTDIR)lib/
LIBS = -L$(LIBDIR) -lhardware

BINARIES = main
OBJECTS =mi_kernel.o mi_user.o
TARGET = main.o
TRASHFILES= *~

all : $(BINARIES) $(OBJECTS) $(TARGET)

###------------------------------
### Entries
###------------------------------------------------------------
main:$(SRC)/mi_kernel.o $(SRC)/mi_user.o $(SRC)/main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

#make depend---------------------------------------------------
main.o: src/main.c src/../include/hardware.h src/../include/mi_syscall.h
mi_kernel.o: src/mi_kernel.c src/../include/mi_syscall.h \
 src/../include/hardware.h src/../include/tlb.h
mi_user.o: src/mi_user.c src/../include/hardware.h \
 src/../include/mi_syscall.h
###------------------------------
### Misc.
###------------------------------------------------------------
.PHONY: clean realclean depend
clean::
	$(RM) $(SRC)/$(OBJECTS) $(SRC)/$(TARGET)
realclean:: clean
	$(RM) $(BINARIES) $(SRC)/$(TRASHFILES) $(OTHER)

depend:
	$(CC) $(CFLAGS) -MM $(SRC)/*.c
