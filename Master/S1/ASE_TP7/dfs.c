#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "define_values.h"
#include "hardware.h"
#include "drive.h"
#include "vol.h"

extern struct mbr_s mbr;

extern struct superbloc_s superbloc;

extern unsigned int volume;

static void
empty_it()
{
    return;
}

int main(void) {

	unsigned int i = 0;

    double factor = 0.0;

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
	dfs after
    */

    read_mbr();

    load_super(volume);

    /*
    Print all the informations about the volume
    */

    printf("==%s==\n", superbloc.volume_name);
    printf("Superbloc inode : %d\n", superbloc.id_inode);
    printf("%d free blocs\n", superbloc.free_blocs_number + 1);
    printf("first free bloc: %d\n", superbloc.first_free_bloc);

    factor = (100 / mbr.volumes[volume].nb_sectors);

    printf("blocs used: %f percent\n", (superbloc.free_blocs_number + 1) * factor);

	return 0;

}