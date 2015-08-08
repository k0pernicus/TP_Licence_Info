#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hardware.h"
#include "drive.h"
#include "vol.h"

extern unsigned int volume;

static void
empty_it()
{
    return;
}

void usage(void) {
	printf("0 : program name\n");
	printf("1 : The volume to initialize\n");
}

int main(int argc, char* argv[]) {

	unsigned int i = 0;

	if (argc != 2) {
		usage();
		exit(EXIT_FAILURE);
	}

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

	volume = atoi(argv[1]);

	assert(volume >= 0 && volume <= MAX_VOLUMES);

	init_super(volume);

	return 0;

}