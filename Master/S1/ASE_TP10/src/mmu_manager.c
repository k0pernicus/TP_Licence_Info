#include <stdio.h>
#include <stdlib.h>

#include "../include/mi_syscall.h"
#include "../include/swap.h"
#include "../include/hardware.h"

/*
Fonction permettant d'additionner / multiplier deux matrices de grande taille
*/
extern void user_process();

int main() {

	_out(MMU_PROCESS,1);

	/*
	Initialisation du fichier swap
	*/
	if(init_swap("../.swap") != 0) {
		fprintf(stderr, "Error in swap initialization\n");
		exit(EXIT_FAILURE);
	}

	/*
	Initialisation Hardware
	*/
	if(init_hardware("../etc/hardware.ini") == 0) {
		fprintf(stderr, "Error in hardware initialization\n");
		exit(EXIT_FAILURE);
	}

	/*
	À l'interruption MMU_IRQ correspond la fonction mmuhandler
	*/
	IRQVECTOR[MMU_IRQ] = mmuhandler;

	/*
	Masque utilisateur
	*/
	_mask(0x1001);

	/*
	On appelle la fonction user_process (Obviously...)
	*/
	user_process();
	return 0;
}
