#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "normalisation.h"

int normalisation_algo(int* tab, int* tabNormalise, int* tab_norm, unsigned int longueur) {

	int i = 0;
	
	for (i = 0; i < longueur; i++) {
		int position = tabNormalise[tab[i]];
		tab_norm[i] = position;			
		printf("%d ",position);
	}

	printf("\n");

	return 1;

}
