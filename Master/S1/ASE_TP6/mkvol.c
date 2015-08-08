#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hardware.h"
#include "drive.h"
#include "mbr.h"
#include "define_values.h"

/*
	mkvol is a program which permits to create a volume in the sector and cylinder done, with a fixed size
*/

extern struct mbr_s mbr;

struct volume_position_s new_volume_position;

struct volume_s new_volume;

void usage(void);

static void
empty_it()
{
    return;
}

int main(int argc, char* argv[]) {

	/*
	argv[0] : program name
	argv[1] : cylinder
	argv[2] : sector
	argv[3] : size of the volume	
	*/

	unsigned int i = 0;

	int cylinder_verification = 0;

	int sector_verification = 0;

	int size_verification = 0;

	unsigned int cylinder = 0;

	unsigned int sector = 0;

	unsigned int size = 0;

	/*
	HARDWARE INITIALIZATION
	*/

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
	END OF INITIALIZATION
    */

	printf("=======================\n");
	printf("=====Welcome to %s=====\n", argv[0]);
	printf("=======================\n\n");

	if (argc != 4) {
		usage();
		exit(EXIT_FAILURE);
	}

	printf("Struct : \n");

	cylinder_verification = atoi(argv[1]);

	sector_verification = atoi(argv[2]);

	size_verification = atoi(argv[3]);

	if (verification_cylinder_sector_size(cylinder_verification, sector_verification, size_verification) == 0)
		exit(EXIT_FAILURE);

	cylinder = cylinder_verification;

	printf("\tCylinder : %d\n",cylinder);

	sector = sector_verification;

	printf("\tSector : %d\n",sector);

	size = size_verification;

	printf("\tSize : %d\n", size);

	printf("\n");

	if (verification_overwrite_mbr(cylinder, sector) == 0)
		exit(EXIT_FAILURE);

	/*
	Read MBR
	*/
	read_mbr();

	/*
	Add the volume defined by cylinder, sector and size
	*/
	add_vol(cylinder, sector, size);

	return 0;

}

/*
	Usage function
*/
void usage(void) {

	printf("USAGE : \n");

	printf("\targv[0] : program name\n");
	printf("\targv[1] : cylinder number\n");
	printf("\targv[2] : sector number\n");
	printf("\targv[3] : size of the volume\n");

}