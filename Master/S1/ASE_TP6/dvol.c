#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hardware.h"
#include "drive.h"
#include "mbr.h"
#include "define_values.h"

extern struct mbr_s mbr;

static void
empty_it()
{
    return;
}

int main(void) {

	int i = 0;

	if(init_hardware("hardware.ini") == 0) {
    	fprintf(stderr, "Error in hardware initialization\n");
    	exit(EXIT_FAILURE);
    }

    /* Interrupt handlers */
    for(i=0; i<16; i++)
      	IRQVECTOR[i] = empty_it;

    /* Allows all IT */
    _mask(1);

    /*
    Read MBR
    */
    read_mbr();

    /*
    Print the informations about volumes
    */
	print_vol();
	
	return 0;
}