#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "drive.h"
#include "hardware.h"

void handler() {
	return;
}

int main(void) {

	unsigned int i = 0, sectorsize = 0;

	unsigned char* buffer;

	/*
	Material initialization
	*/
	assert(init_hardware("hardware.ini")!=0);

	/*
	Disable all the signals
	*/
	for (i = 0; i < 16; i++)
		IRQVECTOR[i] = handler;

	/*
	Save the sector size
	*/
	_out(0x3F6, CMD_DSKINFO);

	sectorsize = (_in(0x114) << 8) + _in(0x115);

	buffer = (unsigned char*) malloc(sectorsize);

	/*
	Read the sector 0, cylinder 1
	*/
	read_sector(0, 0, buffer);

	/*
	Print the position and the byte
	*/
	for (i = 0; i < sectorsize; i++)
		printf("%d: 0x%x\n", i, buffer[i]);

	return 0;

}