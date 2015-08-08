#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mbr.h"
#include "drive.h"
#include "define_values.h"

struct mbr_s mbr;

void init_mbr (void) {
	
	unsigned int i = 0;

	for ( i = 0; i < MAX_VOLUMES; i++ ) {

		mbr.volumes[i].volume_type = 0;

		mbr.volumes[i].nb_sectors = 0;

		mbr.volumes[i].volume_position.cylinder = 0;

		mbr.volumes[i].volume_position.sector = 0;

		mbr.volumes[i].valid = 0;
	}

	mbr.nb_volumes = 0;

	mbr.magic = MBR_MAGIC;

	return;
}

void read_mbr(void) {

	unsigned char buffer[HDA_SECTORSIZE];

	/*
	|\_/|
	(0,0) contains the MBR - we read at coordinates
	*/
	read_sector(0, 0, buffer);

	/*
	We copy the buffer into the MBR emplacement
	*/
	memcpy(&mbr, buffer, sizeof(struct mbr_s));

	/*
	If the MBR is not initialized, we do it
	*/
	if (mbr.magic != MBR_MAGIC) {
		/*
		We initialize the volumes
		*/
		init_mbr();

		/*
		We write all the modifications in the MBR
		*/
		write_mbr();
	}

}

void write_mbr(void) {

	unsigned char buffer[HDA_SECTORSIZE];

	assert(mbr.magic == MBR_MAGIC);

	memset(buffer, 0, HDA_SECTORSIZE);

	memcpy(buffer, &mbr, sizeof(struct mbr_s));

	write_sector(0, 0, buffer);

}

unsigned int nsec_of_nbloc(unsigned int nVolume, unsigned int nBloc) {

	/*
	We save the volume we're looking for
	*/
	struct volume_s volume = mbr.volumes[nVolume];
	
	/*
	Return the sector
	*/
	return (volume.volume_position.sector + nBloc) % HDA_MAXSECTOR;

}

unsigned int ncyl_of_nbloc(unsigned int nVolume, unsigned int nBloc) {

	/*
	We save the volume we're looking for
	*/
	struct volume_s volume = mbr.volumes[nVolume];
	
	/*
	Return the cylinder
	*/
	return volume.volume_position.cylinder + ((volume.volume_position.sector + nBloc) / HDA_MAXSECTOR);

}

void read_bloc(unsigned int vol, unsigned int nbloc, unsigned char* buffer) {

	unsigned int nsec;
	unsigned int ncyl;

	/*
		Transformation bloc -> sector(s) and bloc -> cylinder
	*/
	nsec = nsec_of_nbloc(vol, nbloc);
	ncyl = ncyl_of_nbloc(vol, nbloc);

	/*
		Read informations in the cylinder and secors done by vol/nbloc
	*/
	read_sector(ncyl, nsec, buffer);

}

void write_bloc(unsigned int vol, unsigned int nbloc, unsigned char* buffer) {	
	
	unsigned int nsec;
	unsigned int ncyl;

	nsec = nsec_of_nbloc(vol, nbloc);
	ncyl = ncyl_of_nbloc(vol, nbloc);

	write_sector(ncyl, nsec, buffer);

}

void formate_vol(unsigned int vol) {

	/*
	We search the cylinder, the first sector and the number of sectors
	*/
	unsigned int cyl = mbr.volumes[vol].volume_position.cylinder;
	unsigned int first_sect = mbr.volumes[vol].volume_position.sector;
	unsigned int nbsec = mbr.volumes[vol].nb_sectors;
	
	/*
	Default: 0 per value
	*/
	formate_sector(cyl, first_sect, nbsec, 0);
	
}

int verification_cylinder_sector_size(int cylinder, int sector, int size) {
	
	/*
	Verification all is positive
	*/
	if (cylinder < 0 || sector < 0 || size <= 0) {
		printf("Cylinder || sectore || size <= 0 -> Can't be possible\n");
		return 0;
	}

	return 1;
}

int verification_overwrite_mbr(unsigned int cylinder, unsigned int sector) {

	/*
	Don't overwrite the MBR
	*/
	if (cylinder == 0 && sector == 0){
		printf("No overwrite of the Master Boot Records allows!\n");
		return 0;
	}

	return 1;
}

int verification_del_vol(int volume) {

	/*
	Verification
	*/
	if (volume > mbr.nb_volumes || volume < 0) {
		printf("ERROR: value lower of bigger than the volume number -> Can't be possible\n");
		return 0;
	}

	return 1;
}

void add_vol(unsigned int cylinder, unsigned int sector, unsigned int size) {

	unsigned int i = 0;

	/*
		We search the volume to initiliaze
	*/
	while ((i < MAX_VOLUMES) && (mbr.volumes[i].valid)) {
		i++;
	}

	/*
	Initialization
	*/
	mbr.volumes[i].nb_sectors = size;
	
	mbr.volumes[i].volume_position.cylinder = cylinder;
	
	mbr.volumes[i].volume_position.sector = sector;
	
	mbr.volumes[i].valid = 1;
	
	mbr.nb_volumes++;

	write_mbr();

	return;
}

void del_vol(unsigned int volume) {

	/*
	Verification
	*/
	if (volume >= mbr.nb_volumes)
		exit(EXIT_FAILURE);

	/*
	Volume erased
	*/
	mbr.volumes[volume].volume_type = 0;

	mbr.volumes[volume].nb_sectors = 0;

	mbr.volumes[volume].volume_position.cylinder = 0;

	mbr.volumes[volume].volume_position.sector = 0;

	mbr.volumes[volume].valid = 0;

	mbr.nb_volumes--;

	write_mbr();

	return;

}

void print_vol(void) {

	unsigned int i = 0;

	if (mbr.nb_volumes == 0)
		printf("No volume in MBR...\n");
	else {
		printf("%d volumes\n", mbr.nb_volumes);
		assert(mbr.magic == MBR_MAGIC);
		for (i = 0; i < MAX_VOLUMES; i++) {
			if (mbr.volumes[i].valid)
				printf("Volume %d : %d first cylinder, %d first sector, %d sectors\n", i, mbr.volumes[i].volume_position.cylinder, mbr.volumes[i].volume_position.sector, mbr.volumes[i].nb_sectors);
		}
	}

}