#ifndef MBR

#define MBR

#define MBR_MAGIC 0xDEADBEEF

#include "define_values.h"

/*
	Define the type of the volume
	BASE -> base volume for the files system
	APPENDICE -> appendice volume for the files system
	OTHER -> other type of volume, does not associated with the files system
*/
enum vol_type_e {BASE, APPENDICE, OTHER};

/*
	Structure which represents the volume position, defined by his cylinder and his sector
	@param cylinder The number of the cylinder
	@param sector The number of the sector, attached to the cylinder
*/
struct volume_position_s 
{
	unsigned int cylinder;
	unsigned int sector;
};

/*
	Structure which represents the volume
	@param volume_type The type of the volume (see enum vol_type_e documentation)
	@param nb_sectors The number of sectors contains in the volume
	@param volume_position The position of the volume, in the disk (see struct volume_position_s documentation)
	@param valid A number to verify if the struct is always validate, or not
*/
struct volume_s
{
	enum vol_type_e volume_type;
	unsigned int nb_sectors;
	struct volume_position_s volume_position;
	int valid;
};

/*
	Structure which represents the MBR
	@param nb_volumes The number of volumes contains in the MBR
	@param volumes The volumes contains in the MBR
	@param magic The MAGIC number - represented by MBR_MAGIC
*/
struct mbr_s
{
	unsigned int nb_volumes;
	struct volume_s volumes[MAX_VOLUMES];
	int magic;
};

void init_MBR (void);

/*
	Function to read the MBR. If the MBR is not initialized, we do it!
*/
void read_mbr(void);

/*
	Function to write the structure mbr_s into the MBR
*/
void write_mbr(void);

/*
	Function to convert a sector number to a bloc number
	@return The sector number
*/
unsigned int nsec_of_nbloc(unsigned int, unsigned int);

/*
	Function to convert a cylinder number to a bloc number
	@return The cylinder number
*/
unsigned int ncyl_of_nbloc(unsigned int, unsigned int);

/*
	Function which allows to read blocs
	@param vol The volume of the bloc
	@param nbloc The blocs to read
	@param buffer The buffer which allows to save into some bloc informations
*/
void read_bloc(unsigned int vol, unsigned int nbloc, unsigned char* buffer);

/*
	Function which allows to write blocs
	@param vol The volume of the bloc
	@param nbloc The blocs to read
	@param buffer The buffer which contains the informations to save on bloc(s)
*/
void write_bloc(unsigned int vol, unsigned int nbloc, unsigned char* buffer);

/*
	Function which allows to formate blocs
	@param vol The volume to formate
*/
void formate_vol(unsigned int vol);

/*
	Function which allows to verify if the cylinder, sector and size are corrects
	@param cylinder The cylinder number
	@param sector The sector number
	@param size The size of the sectors
*/
int verification_cylinder_sector_size(int cylinder, int sector, int size);

/*
	Function which allows to verify if the cylinder and the sector are not the cylinder & sector of the MBR
	@param cylinder The cylinder number
	@param sector The sector number
*/
int verification_overwrite_mbr(unsigned int cylinder, unsigned int sector);

/*
	Function which allows to verify if the volume to delete is corrected done by his number
	@param volume The volume number
*/
int verification_del_vol(int volume);

/*
	Function which allows to add a volume, in the mbr_s global structure
	@param cylinder The cylinder of the volume to add
	@param sector The sector of the volume to add
	@param size The size of the volume to add
*/
void add_vol(unsigned int cylinder, unsigned int sector, unsigned int size);

/*
	Function which allows to delete a volume
	@param volume The volume to delete
*/
void del_vol(unsigned int volume);

/*
	Function which allows to print a volume
*/
void print_vol(void);

#endif