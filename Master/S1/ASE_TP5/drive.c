#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hardware.h"
#include "drive.h"

/*
	0x110 -> HDA_DATAREGS (+15)
	0x3F6 -> HDA_CMDREG
	14 -> HDA_IRQ (Master)
	15 -> HDA_IRQ (Slave)
*/

void seek_sector(unsigned int cylinder, unsigned int sector) {

	/*
	TO SAVE THE CYLINDER
	*/

	/*
	Save the 8 first bits of the cylinder
	*/
	_out(0x110, (unsigned char) (cylinder >> 8));

	/*
	Save the 8 last bits of the cylinder
	*/
	_out(0x111, (unsigned char) cylinder);

	/*
	TO SAVE THE SECTOR
	*/

	/*
	Save the 8 first bits of the sector
	*/
	_out(0x112, (unsigned char) (sector >> 8));

	/*
	Save the 8 last bits of the sector
	*/
	_out(0x113, (unsigned char) sector);

	/*
	Move the reader head
	*/
	_out(0x3F6, CMD_SEEK);

	/*
	Master disk is doing his stuff - we let him to do all he needs
	*/
	_sleep(14);

	return;

}

void read_sector(unsigned int cylinder, unsigned int sector, unsigned char* buffer) {

	int sectorsize;

	_out(0x3F6, CMD_DSKINFO);

	sectorsize = (_in(0x114) << 8) + _in(0x115);

	seek_sector(cylinder, sector);

	/*
	We want to read only one sector
	*/
	_out(0X110, 0x00);
	_out(0X111, 0x01);

	/*
	Read command
	*/
	_out(0x3F6, CMD_READ);

	/*
	Master disk is doing his stuff - we let him to do all he needs
	*/
	_sleep(14);

	/*
	Copy HDA_SECTORSIZE bytes of MASTERBUFFER to buffer
	*/
	memcpy(buffer, MASTERBUFFER, sectorsize);

	return;

}

void write_sector(unsigned int cylinder, unsigned int sector, unsigned char* buffer) {

	int sectorsize;

	_out(0x3F6, CMD_DSKINFO);

	sectorsize = (_in(0x114) << 8) + _in(0x115);

	/*
	Copy HDA_SECTORSIZE bytes of buffer to MASTERBUFFER, to obtains the data to write into the sector
	*/
	memcpy(MASTERBUFFER, buffer, sectorsize);

	seek_sector(cylinder, sector);

	/*
	We want to write data on 1 sector
	*/
	_out(0x110, 0x00);
	_out(0x110, 0x01);

	/*
	Write command
	*/
	_out(0x3F6, CMD_WRITE);

	_sleep(14);

	return;
	
}

void format_sector(unsigned int cylinder, unsigned int sector, unsigned int nsector, unsigned int value) {
	
	seek_sector(cylinder, sector);

	/*
	One sector
	*/
	_out(0x110, (unsigned int) (nsector >> 8));
	_out(0x111, (unsigned int) (nsector));

	/*
	Enter the value of 'value' in each byte
	*/
	_out(0x112, (unsigned int) (value >> 24));
	_out(0x113, (unsigned int) (value >> 16));
	_out(0x114, (unsigned int) (value >> 8));
	_out(0x115, (unsigned int) (value));

	/*
	Format command
	*/
	_out(0x3F6, CMD_FORMAT);

	_sleep(14);

	return;
}