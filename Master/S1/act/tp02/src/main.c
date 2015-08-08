#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "normalisation.h"
#include "calcul_inversions.h"

unsigned int get_longueur_dat(unsigned int* longueur, const char* path_file){

	FILE* dat_file = fopen(path_file, "r");

	int c;

	while ((c = fgetc(dat_file)) != EOF){
		if (c != '\n') {
			//Conversion du caractère en entier
			int i = c - '0';
			*longueur = ((*longueur) * 10) + i;
		}
		else
			break;
	}

	fclose(dat_file);

	return 1;

}

int parse_fichier(int* tab1, int* tab2, const char* path_file){

	FILE* dat_file = fopen(path_file, "r");

	int c, nbr = 0, i = 0, tour = 0;

	while ((c = fgetc(dat_file)) != EOF){
		//Condition de sortie
		if (tour > 2)
			break;
		if (c == '\n') {
			tour++; 
			nbr = 0;
			i = 0;
		}
		else{
			if (c != ' ') {
				int entier = c - '0';
				nbr = (nbr * 10) + entier;
			}
			else {
				if (tour == 1)
					tab1[i] = nbr;
				if (tour == 2)
					tab2[i] = nbr;
				i++;
				nbr = 0;
			}
		}
	}

	fclose(dat_file);

	return 1;

}

int main(int argc, char** argv) {

	int i;

	unsigned int longueur = 0;

	const char* path_file = argv[1];

	if (!get_longueur_dat(&longueur, path_file)){
		printf("Erreur lors du parsing de fichier [Taille des tableaux]\n");
		exit(EXIT_FAILURE);
	}

	printf("Longueur = %u\n",longueur);

	int* tab_norm = malloc(sizeof(int) * longueur);

		//Deux tableaux
	int tab1[longueur], tab2[longueur];

	parse_fichier(tab1, tab2, path_file);

	printf("Table1: ");
	for (i = 0; i < longueur; i++)
		printf("%d ", tab1[i]);
	printf("\n");

	printf("Table2: ");
	for (i = 0; i < longueur; i++)
		printf("%d ", tab2[i]);
	printf("\n");

	int* tabN = malloc(sizeof(int) * longueur);

	for (i = 0; i < longueur; i++) {
		int position = tab1[i];
		tabN[position] = i;
	}

	printf("Normalisation de Table2 par rapport à Table1: ");

	normalisation_algo(tab2, tabN, tab_norm, longueur);

	printf("Calcul du nombre d'inversions (version initiale):\n");
	
	unsigned int inv = calcul_inversions(tab_norm, longueur);

	printf("Inversions à apporter: %u\n", inv);

	printf("Calcul du nombre d'inversions (version \"Diviser pour régner\"):\n");

	unsigned int inv_2 = calcul_inversions_2(tab_norm, longueur);

	printf("Inversions à apporter: %u\n", inv_2);

	free(tab_norm);

	printf("Longueur : %d\n", longueur);

	exit(EXIT_SUCCESS);

}
