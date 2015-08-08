#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "hardware.h"
#include "define_values.h"
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

int main (int argc, char* argv[]) {

	int random_number = 0;
	int* tab_blocs = malloc(sizeof(int) * HDA_SECTORSIZE);
	int i = 0;
	int int_ret = 0;

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

    load_super(volume);

    srand(time(NULL));

    i = 0;

    printf("\nALLOCATION\n");

	/*
	Allocation of all free blocs
	*/
	while((int_ret = new_bloc()) != 0) {
		printf("bloc %d\n", int_ret);
		tab_blocs[i] = int_ret;
		i++;
	}

    printf("\nFULL DISK\n");

	assert(superbloc.free_blocs_number == 0);

	random_number = rand() % mbr.volumes[volume].nb_sectors;

	printf("random number : %d\n", random_number);

    printf("\nUNALLOCATION\n");

	while(random_number-- != 0) {
		printf("bloc %d free\n", i);
		free_bloc(tab_blocs[i--]);
	}

	/*
	Affichage de la taille du disque en taille libre
	*/

	printf("%d free blocs remaining\n", superbloc.free_blocs_number);


	return 0;

}