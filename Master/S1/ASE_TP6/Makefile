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
BINARIES= mkhd mkvol dvol delvol
OBJECTS	= $(addsuffix .o,\
	  mkhd, mkvol, dvol, delvol)

all: $(BINARIES) $(OBJECTS)


###------------------------------
### Main rules 
###------------------------------------------------------------
%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(INCDIR) $(LIBS)

mkhd: mkhd.o
	$(CC) $(CFLAGS) -o mkhd $^ $(LIBS)

mkvol: mkvol.o drive.o mbr.o
	$(CC) $(CFLAGS) -o mkvol $^ $(LIBS)

dvol: dvol.o drive.o mbr.o
	$(CC) $(CFLAGS) -o dvol $^ $(LIBS)

delvol: delvol.o drive.o mbr.o
	$(CC) $(CFLAGS) -o delvol $^ $(LIBS)
###------------------------------
### Misc.
###------------------------------------------------------------
.PHONY: clean realclean depend
clean:
	$(RM) *.o $(BINARIES)
realclean: clean 
	$(RM) vdiskA.bin vdiskB.bin
