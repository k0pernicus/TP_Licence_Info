#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#include "heuristique.h"

#ifdef __APPLE__
	#define OS "MacOS"
#elif _linux
	#define OS "Linux"
#endif

/*
n_objets est le nombre d'objets - NOBJETS est le nombre d'objets à attribuer à la variable
*/
unsigned int n_objets = 0;

/*
capacite est la capacité d'un sac - CAPACITE est la capacité à attribuer à la variable
*/
unsigned int capacite = 0;

/*
tableau_poids est le tableau contenant les poids des n_objets objets - NULL au départ, généré dans generer_tableau_poids()
*/
int* tableau_poids = NULL;

void parse_fichier(char*);
void verification_mode(char*);
void tri_obj_decroissant(void);
void verification_online_offline(char*);

/*
Fonctions globales au programme
*/
void usage(void);

/*
Définition de fonctions concernant la génération de tableau de poids
*/
void print_tableau_poids(void);
void free_tableau_poids(void);

/*
Main
argv[0] : nom du programme
argv[1] : fichier
argv[2] : mode
*/
int main(int argc, char* argv[]) {

	if (argc != 3 && argc != 4)
		usage();

	/*
	Parse le fichier passé en paramètre
	*/
	parse_fichier(argv[1]);
	/*
	Donne toutes les indications nécessaires pour le/les calcul(s)
	*/
	print_tableau_poids();
	/*
	Vérification du mode "online"/"offline"
	*/
	if (argc == 4)
		verification_online_offline(argv[3]);
	/*
	Vérification du mode donné en paramètre
	*/
	verification_mode(argv[2]);
	/*
	Libération du tableau de poids des objets
	*/
	free_tableau_poids();

	return 0;

}

/*
Vérification du mode:
	-n : next_fit
	-f : first_fit
	-b : best_fit
*/
void verification_mode(char* mode) {

	int* tab_objets = (int*) malloc(sizeof(int) * n_objets);

	if (strcmp(mode, "-n") == 0) {
		printf("Mode NextFit : OK\n");
		next_fit(tab_objets);
		return;
	}
	if (strcmp(mode, "-f") == 0) {
		printf("Mode FirstFit : OK\n");
		first_fit(tab_objets);
		return;
	}
	if (strcmp(mode, "-b") == 0) {
		printf("Mode BestFit : OK\n");
		best_fit(tab_objets);
		return;
	}

	free(tab_objets);

	perror("Le mode n'existe pas...");
	exit(EXIT_FAILURE);
}

/*
Vérification du mode:
	-online : online - par ordre d'énumération donné (par défaut)
	-offline : offline - tri des objets par ordre décroissant
*/
void verification_online_offline(char* mode) {

	if (strcmp(mode, "-offline") == 0) {
		printf("Offline mode : OK\n");
		tri_obj_decroissant();
		return;
	}
	if (strcmp(mode, "-online") == 0) {
		printf("Online mode : OK\n");
		return;
	}
	/*
	Z mode -> 3ème état: tri du tableau d'objets par ordre croissant de leurs poids
	*/
	if (strcmp(mode, "-z") == 0) {
		printf("Z mode : OK\n");
		return;
	}

	perror("Le mode n'existe pas...");
	exit(EXIT_FAILURE);

}

/*
 * Algorithme utilisé pour trié le tableau d'objets, par ordre croissant
 */
void tri_obj_decroissant() {

	int tmp = 0;

	unsigned int i = 0;

	unsigned int j = 0;

	for (i = 0; i < n_objets; i++) {

		for (j = i+1; j < n_objets; j++) {

			if (tableau_poids[i] < tableau_poids[j]) {
				tmp = tableau_poids[i];
				tableau_poids[i] = tableau_poids[j];
				tableau_poids[j] = tmp;
 			}

		}

	}

	for (i = 0; i < n_objets; i++)
		printf("%d ", tableau_poids[i]);

	printf("\n");

}

/*
* Algorithme utilisé pour trié le tableau d'objets, par ordre décroissant
*/
void tri_obj_croissant() {

	int tmp = 0;

	unsigned int i = 0;

	unsigned int j = 0;

	for (i = 0; i < n_objets; i++) {

		for (j = i+1; j < n_objets; j++) {

			if (tableau_poids[i] > tableau_poids[j]) {
				tmp = tableau_poids[i];
				tableau_poids[i] = tableau_poids[j];
				tableau_poids[j] = tmp;
			}

		}

	}

	for (i = 0; i < n_objets; i++)
		printf("%d ", tableau_poids[i]);

	printf("\n");

}

/*
Parseur du fichier
*/
void parse_fichier(char* fichier) {

	FILE* file;

	char buf[10];

	unsigned int i = 0;

	unsigned int iterator = 0;

	/*
	Ouverture du fichier 'fichier' en lecture seule
	*/
	file = fopen(fichier, "r");

	if (file) {
		/*
		Lecture
		*/
		while (fgets(buf,10, file)!=NULL) {
			/*
			On s'arrête à la première ligne vide
			*/
			if (buf[0] == '\n')
				break;
			if (buf != NULL) {
				/*
				A la 1ère itération, on récupère le nombre d'objets
				*/
        	if (i == 0) {
        		n_objets = atoi(buf);
        		printf("N objets: %d\n", n_objets);
        		tableau_poids = malloc(sizeof(int) * n_objets);
        		iterator += n_objets + 1;
        		i++;
        		continue;
        	}
				/*
				On détient le nombre de sacs une fois arrivé à l'itérateur
				*/
        	if (i == iterator) {
        		capacite = atoi(buf);
        		printf("Capacite: %d\n", capacite);
        		i++;
        		continue;
        	}
	        	/*
				sinon, on remplit le tableau d'objets
	        	*/
        	tableau_poids[i - 1] = atoi(buf);
        	i++;
			}
	  }
	}
	else {
		perror("Le fichier n'existe pas...");
		exit(EXIT_FAILURE);
	}

    fclose(file);

}

/*
Fonctions
*/

void usage(void) {

	if (strcmp(OS, "MacOS") == 0) {
		system("say Bonjour Monsieur Bouillaguet, bienvenue sur le programme de Antonin Carette. Vous avez du mal à exécuter le programme? Pas de soucis! Tout d'abord, veuillez entrer un fichier d'exemple - ensuite, le choix de l'algorithme : tiret n pour next fit, tiret f pour first fit, tiret b pour best fit. Enfin, vous pouvez spécifier le mode online et offline. Merci de m'avoir écouté, à bientôt...");
	}
	else {
		printf("Arguments:\n");
		printf("[1] : fichier d'exemple (voir répertoire donnees)\n");
		printf("[2] : option\n");
		printf("\t -n : algorithme next_fit\n");
		printf("\t -f : algorithme first_fit\n");
		printf("\t -b : algorithme best_fit\n");
	}
	exit(EXIT_FAILURE);

}

void print_tableau_poids(void) {

	unsigned int i = 0;

	printf("Tableau de poids: \n");

	for (i = 0; i < n_objets ; i++)
		printf("i = %d : %d\n", i, tableau_poids[i]);

}

void free_tableau_poids(void) {

	free(tableau_poids);

}
