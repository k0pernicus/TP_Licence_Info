#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hardware.h"
#include "drive.h"
#include "define_values.h"

void seek_sector(unsigned int cylinder, unsigned int sector) {

	/*
	TO SAVE THE CYLINDER
	*/

	/*
	Save the 8 first bits of the cylinder
	*/
	_out(HDA_DATAREGS, (unsigned char) (cylinder >> 8));

	/*
	Save the 8 last bits of the cylinder
	*/
	_out(HDA_DATAREGS + 1, (unsigned char) cylinder);

	/*
	TO SAVE THE SECTOR
	*/

	/*
	Save the 8 first bits of the sector
	*/
	_out(HDA_DATAREGS + 2, (unsigned char) (sector >> 8));

	/*
	Save the 8 last bits of the sector
	*/
	_out(HDA_DATAREGS + 3, (unsigned char) sector);

	/*
	Move the reader head
	*/
	_out(HDA_CMDREG, CMD_SEEK);

	/*
	Master disk is doing his stuff - we let him to do all he needs
	*/
	_sleep(HDA_IRQ);

	return;

}

void read_sector(unsigned int cylinder, unsigned int sector, unsigned char* buffer) {

	seek_sector(cylinder, sector);

	/*
	We want to read only one sector
	*/
	_out(HDA_DATAREGS, 0);
	_out(HDA_DATAREGS + 1, 1);

	/*
	Read command
	*/
	_out(HDA_CMDREG, CMD_READ);

	/*
	Master disk is doing his stuff - we let him to do all he needs
	*/
	_sleep(HDA_IRQ);

	/*
	Copy HDA_SECTORSIZE bytes of MASTERBUFFER to buffer
	*/
	memcpy(buffer, MASTERBUFFER, HDA_SECTORSIZE);

	return;

}

void write_sector(unsigned int cylinder, unsigned int sector, unsigned char* buffer) {

	/*
	Copy HDA_SECTORSIZE bytes of buffer to MASTERBUFFER, to obtains the data to write into the sector
	*/
	memcpy(MASTERBUFFER, buffer, HDA_SECTORSIZE);

	seek_sector(cylinder, sector);

	/*
	We want to write data on 1 sector
	*/
	_out(HDA_DATAREGS, 0);

	_out(HDA_DATAREGS + 1, 1);

	/*
	Write command
	*/
	_out(HDA_CMDREG, CMD_WRITE);

	_sleep(HDA_IRQ);

	return;
	
}

void formate_sector(unsigned int cylinder, unsigned int sector, unsigned int nsector, unsigned int value) {
	
	seek_sector(cylinder, sector);

	/*
	One sector
	*/
	_out(HDA_DATAREGS, (unsigned int) (nsector >> 8));
	_out(HDA_DATAREGS + 1, (unsigned int) (nsector));

	/*
	Enter the value of 'value' in each byte
	*/
	_out(HDA_DATAREGS + 2, (unsigned int) (value >> 24));
	_out(HDA_DATAREGS + 3, (unsigned int) (value >> 16));
	_out(HDA_DATAREGS + 4, (unsigned int) (value >> 8));
	_out(HDA_DATAREGS + 5, (unsigned int) (value));

	/*
	Format command
	*/
	_out(HDA_CMDREG, CMD_FORMAT);

	_sleep(HDA_IRQ);

	return;
}