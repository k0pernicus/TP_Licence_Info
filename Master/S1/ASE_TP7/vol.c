#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vol.h"
#include "drive.h"
#include "define_values.h"

/*
	The Master Boot Record
*/
struct mbr_s mbr;

/*
	The superbloc structure
*/
struct superbloc_s superbloc;

/*
	The volume to work with (for the superbloc )
*/
unsigned int volume;

/*
ABOUT MBR ->  INIT, READ, WRITE
*/

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

	mbr.magic = MAGIC_NUMBER;

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
	if (mbr.magic != MAGIC_NUMBER) {
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

	assert(mbr.magic == MAGIC_NUMBER);

	memset(buffer, 0, HDA_SECTORSIZE);

	memcpy(buffer, &mbr, sizeof(struct mbr_s));

	write_sector(0, 0, buffer);

}

/*
POSITION OF SECTORS / CYLINDERS
*/

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

/*
READ/WRITE/FORMATE VOLUMES
*/

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

/*
VERIFICATION METHODS
*/

int verification_cylinder_sector_size(int cylinder, int sector, int size) {
	
	/*
	Verification all is positive
	*/
	if (cylinder < 0 || sector < 0 || size <= 0 || size > HDA_MAXSECTOR) {
		printf("The volume can't be create...\n");
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

/*
VOLUME ADD/DEL/DISPLAY
*/

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
		assert(mbr.magic == MAGIC_NUMBER);
		for (i = 0; i < MAX_VOLUMES; i++) {
			if (mbr.volumes[i].valid)
				printf("Volume %d : %d first cylinder, %d first sector, %d sectors\n", i, mbr.volumes[i].volume_position.cylinder, mbr.volumes[i].volume_position.sector, mbr.volumes[i].nb_sectors);
		}
	}

}

/*
DESCRIPTOR AND INITIALIZATION OF VOLUMES
*/

void init_super(unsigned int vol) {

	struct free_bloc_s free_bloc;
	unsigned char buff[HDA_SECTORSIZE];

	printf("Superbloc initialization\n");

	/*
	superbloc initialization
	*/
	superbloc.magic = MAGIC_NUMBER;
	superbloc.serial_number = vol;
	strncpy(superbloc.volume_name,"Volume_tp6",NAME_LENGTH);
	superbloc.id_inode = 0;
	superbloc.first_free_bloc = mbr.volumes[vol].volume_position.sector + 1;
	superbloc.free_blocs_number = mbr.volumes[vol].nb_sectors - 1;

	printf("Free bloc initialization\n");

	/*
	free bloc initialization
	*/
	free_bloc.size = mbr.volumes[vol].nb_sectors - 1;
	free_bloc.next_free_blocs = 0;

	printf("Before saving\n");

	save_super();

	printf("After saving\n");

	/*
	We store the free_bloc structure in a buffer
	*/
	memset(buff, 0, HDA_SECTORSIZE);
	memcpy(buff, &free_bloc, sizeof(struct free_bloc_s));

	/*
	Overwrite the bloc 1 with the free_bloc_s structure
	*/
	write_bloc(vol, 1, buff);

}

int load_super(unsigned int vol) {

	unsigned char buff[HDA_SECTORSIZE];

	memset(buff, 0, HDA_SECTORSIZE);

	/*
	We read the superbloc
	*/
	read_bloc(vol, 0, buff);

	/*
	We copy the buffer in the superbloc structure
	*/
	memcpy(&superbloc, buff, sizeof(struct superbloc_s));

	/*
	We verify if the superbloc is active (return 0) or not (return -1)
	*/
	if (superbloc.magic == MAGIC_NUMBER)
		return 0;
	return -1;

}

void save_super(void) {

	/*
	We store the superbloc in a buffer
	*/
	unsigned char buff[HDA_SECTORSIZE];
	memset(buff, 0, HDA_SECTORSIZE);

	memcpy(buff, &superbloc, sizeof(struct superbloc_s));

	/*
	Overwrite the bloc 0 with the superbloc_s structure
	*/
	write_bloc(volume, 0, buff);

}

unsigned int new_bloc() {

	unsigned int res;
	unsigned char buffer[HDA_SECTORSIZE];
	struct free_bloc_s* free_bloc;

	/*
	If no free blocs, we stop
	*/
	if (superbloc.free_blocs_number <= 0) {
		printf("No free bloc...\n");
		return 0;
	}

	/*
	Read the block first_free_bloc, volume vol
	*/
	read_bloc(volume, superbloc.first_free_bloc, buffer);

	free_bloc = (struct free_bloc_s*) buffer;
	res = superbloc.first_free_bloc;

	if (free_bloc->size >= 1) {
		superbloc.first_free_bloc++;
		free_bloc -> size--;
		write_bloc(volume, superbloc.first_free_bloc, buffer);
	}
	else
		superbloc.first_free_bloc = free_bloc -> next_free_blocs;

	superbloc.free_blocs_number--;

	/*
	Save superbloc
	*/
	save_super();

	return res;

}

void free_bloc(unsigned int bloc) {

	unsigned char buffer[HDA_SECTORSIZE];
	struct free_bloc_s free_bloc;

	/*
	Write the new free bloc
	*/

	free_bloc.size = 1;
	free_bloc.next_free_blocs = superbloc.first_free_bloc;

	/*
	Overwrite new informations
	*/

	printf("Memset\n");

	memset(buffer, 0, HDA_SECTORSIZE);

	printf("Write bloc : begin\n");

	memcpy(buffer, &free_bloc, sizeof(struct free_bloc_s));

	/*
	??????
	*/
	write_bloc(volume, bloc, buffer);

	printf("Write bloc : end\n");

	/*
	New free_bloc!
	*/	

	superbloc.first_free_bloc = bloc;

	superbloc.free_blocs_number++;

	/*
	Save the new superbloc
	*/

	save_super();

}

