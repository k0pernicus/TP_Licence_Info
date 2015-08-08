#include <stdio.h>
#include <stdlib.h>
#include "drive.h"
#include "hardware.h"

int main(void) {

	int i = 0, j = 0, nbcylinder = 0, nbsector = 0;

	/*
	We look for the size of cylinders and sectors
	*/
	_out(0x3F6, CMD_DSKINFO);

	/*
	We save the size of a cylinder
	*/
	nbcylinder = (_in(0x110) << 8) + _in(0x111);
	
	/*

	*/
	nbsector = (_in(0x112) << 8) + _in(0x113);

	for (i = 0; i < nbcylinder; i++) {

		for (j = 0; j < nbsector; j++) {

			/*
			Formate all the disk
			*/
			format_sector(i, j, nbsector, 0);

		}

	}

	return 0;

}