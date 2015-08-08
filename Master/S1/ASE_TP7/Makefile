	# $Id: Makefile,v 1.2 2004/10/12 09:06:17 marquet Exp $
##############################################################################

#ROOTDIR=/home/enseign/ASE
ROOTDIR=.

CC	= gcc
CFLAGS	= -Wall -ansi -pedantic 
CFLAGS  += -g
#LIBDIR  = $(ROOTDIR)/lib
LIBDIR = $(ROOTDIR)
#INCDIR  = -I$(ROOTDIR)/include
INCDIR = -I$(ROOTDIR)
LIBS    = -L$(LIBDIR) -lhardware

###------------------------------
### Main targets 
###------------------------------------------------------------
BINARIES= test delvol mkvol dvol mknfs dfs
OBJECTS	= $(addsuffix .o,\
	 test delvol mkvol dvol mknfs dfs)

all: $(BINARIES) $(OBJECTS)


###------------------------------
### Main rules 
###------------------------------------------------------------
%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(INCDIR) $(LIBS)

test: test.c drive.o vol.o
	$(CC) $(CFLAGS) -o test $^ $(LIBS)

mkvol: mkvol.c drive.o vol.o
	$(CC) $(CFLAGS) -o mkvol $^ $(LIBS)

dvol: dvol.c drive.o vol.o
	$(CC) $(CFLAGS) -o dvol $^ $(LIBS)

delvol: delvol.c drive.o vol.o
	$(CC) $(CFLAGS) -o delvol $^ $(LIBS)

mknfs: mknfs.c drive.o vol.o
	$(CC) $(CFLAGS) -o mknfs $^ $(LIBS)

dfs: dfs.c drive.o vol.o
	$(CC) $(CFLAGS) -o dfs $^ $(LIBS)

###------------------------------
### Misc.
###------------------------------------------------------------
.PHONY: clean realclean depend
clean:
	$(RM) *.o $(BINARIES)
realclean: clean 
	$(RM) vdiskA.bin vdiskB.bin
