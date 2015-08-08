#ifndef DRIVE

#define DRIVE

/**
	seek_sector: Function to seek a sector
	@param cylinder: The cylinder which contains the sector to seek
	@param sector: The sector to seek
*/
void seek_sector(unsigned int cylinder, unsigned int sector);

/**
	read_sector: Function to read a sector
	@param cylinder: The cylinder which contains the sector to read
	@param sector: The sector to read
	@param buffer: A buffer which will contains the data
*/
void read_sector(unsigned int cylinder, unsigned int sector, unsigned char* buffer);

/**
	write_sector: Function to write the buffer in a sector
	@param cylinder: The cylinder which contains the sector to write into
	@param sector: The sector to write into
	@param buffer: A buffer which contains the data to write into the sector	
*/
void write_sector(unsigned int cylinder, unsigned int sector, unsigned char* buffer);

/**
	format_sector: Function to formate a sector
	@param cylinder: The cylinder which contains the sector to write into
	@param sector: The sector to write into
	@param nsector: The number of sectors to formate
	@param value: The value to use to overwrite the data (default: 0)
*/
void formate_sector(unsigned int cylinder, unsigned int sector, unsigned int nsector, unsigned int value);

#endif