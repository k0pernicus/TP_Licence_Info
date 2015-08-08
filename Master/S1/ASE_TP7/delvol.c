#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hardware.h"
#include "drive.h"
#include "vol.h"
#include "define_values.h"

extern struct mbr_s mbr;

static void
empty_it()
{
    return;
}

void usage(void);

int main(int argc, char* argv[]) {

    unsigned int i = 0;

    int volume_verification = 0;

	unsigned int volume = 0;

    if (argc < 2) {
        usage();
        exit(EXIT_FAILURE);
    }

    volume_verification = atoi(argv[1]);

    if (verification_del_vol(volume) == 0)
        exit(EXIT_FAILURE);

	if(init_hardware("hardware.ini") == 0) {
    	fprintf(stderr, "Error in hardware initialization\n");
    	exit(EXIT_FAILURE);
    }

    /* Interrupt handlers */
    for(i=0; i<16; i++)
      	IRQVECTOR[i] = empty_it;

    /* Allows all IT */
    _mask(1);

    volume = volume_verification;

    /*
    Read MBR
    */
    read_mbr();

    /*
    Print the informations about volumes
    */
	del_vol(volume);
	
	return 0;
}

/*
    Usage function
*/
void usage(void) {

    printf("USAGE : \n");

    printf("\targv[0] : program name\n");
    printf("\targv[1] : volume number\n");

} 