#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <unistd.h>

extern unsigned int n_objets;

extern unsigned int capacite;

extern int* tableau_poids;

void next_fit(int* tab_objets) {

	/*
	Structure de temps - nécessaire au calcul du temps de l'algorithme
	*/
	struct timeval timeval_avant, timeval_apres;

	/*
	Structure de zone de temps
	*/
  	struct timezone timezone;

  	/*
	Variable contenant la différence entre deux mesures du temps
  	*/
  	long long difference_time;

	/*
	Entier permettant de situer où se trouve le sac actuel dans le tableau de tab_objets et de tab_poids_totaux
	*/
	unsigned int sac_actuel = 0;

	unsigned int i = 0;

	/*
	Tableau permettant de stocker combien il reste de poids à placer dans chaque sac
	*/
	int* tab_poids_totaux = (int*) malloc(sizeof(int) * n_objets);

	/*
	Entier permettant de stocker la différence entre la capacité restante d'un sac, et le poids de l'objet actuel
	*/
	int difference = 0;

	/*
	Chaque entier de la table contiendra la capacité d'un sac
	*/
	for (i = 0; i < n_objets; i++)
		tab_poids_totaux[i] = capacite;

	/*
	Début de mesure du temps
	*/
	gettimeofday(&timeval_avant, &timezone);

	/*
	On parcours tous les objets
	*/
	for (i = 0; i < n_objets; i++) {

		/*
		Si on excède la capacité d'un sac pour un objet, on stoppe tout (totally badass...)
		*/
		if ((unsigned int) tableau_poids[i] > capacite) {
			printf("Le poids du tableau d'objets (n° %d) : %d est supérieur à %d", i, tableau_poids[i], capacite);
			exit(EXIT_FAILURE);
		}

		/*
		ELSE
		*/

		/*
		Calcul de la différence entre la capacité restante d'un sac, et le poids de l'objet en cours
		*/
		difference = tab_poids_totaux[sac_actuel] - tableau_poids[i];

		/*
		Si la différence est supérieur ou égale à 0, on peut alors insérer l'objet dans le sac actuel, et l'on passe à l'objet suivant...
		*/
		if (difference >= 0)
			tab_poids_totaux[sac_actuel] = difference;
		/*
		Sinon, on passe au sac suivant, et l'on décrémente de tableau_poids[i] fois le poids total du sac actuel
		*/
		else {
			sac_actuel++;
			if (sac_actuel > n_objets) {
				printf("ERREUR /// somme des poids des objets > capacité");
				exit(EXIT_FAILURE);
			}
			tab_poids_totaux[sac_actuel] -= tableau_poids[i];
		}
		/*
		On ajoute l'objet dans le sac actuel
		*/
		tab_objets[i] = sac_actuel;

	}

	/*
	Fin de mesure du temps
	*/
	gettimeofday(&timeval_apres, &timezone);

	difference_time = ((timeval_apres.tv_sec - timeval_avant.tv_sec) * 1000000L) + (timeval_apres.tv_usec - timeval_avant.tv_usec);

	printf("Algorithme prenant ici %d sacs\n", sac_actuel + 1);

	for (i = 0; i < n_objets; i++)
		printf("\tObjet %d, poids %d, sac %d\n",i,tableau_poids[i],tab_objets[i]);

	printf("Temps pris par l'algorithme : %lld microsecondes\n", difference_time);

	free(tab_poids_totaux);

}

void first_fit(int* tab_objets) {

	/*
	Structure de temps - nécessaire au calcul du temps de l'algorithme
	*/
	struct timeval timeval_avant, timeval_apres;

	/*
	Structure de zone de temps
	*/
  	struct timezone timezone;

  	/*
	Variable contenant la différence entre deux mesures du temps
  	*/
  	long long difference_time;

	unsigned int i = 0;

	unsigned int j = 0;

	unsigned int nb_sacs = 0;

	/*
	Tableau permettant de stocker combien il reste de poids à placer dans chaque sac
	*/
	int* tab_poids_totaux = (int*) malloc(sizeof(int) * n_objets);

	/*
	Entier permettant de stocker la différence entre la capacité restante d'un sac, et le poids de l'objet actuel
	*/
	int difference = 0;

	/*
	Chaque entier de la table contiendra la capacité d'un sac
	*/
	for (i = 0; i < n_objets; i++)
		tab_poids_totaux[i] = capacite;

	/*
	Début de mesure du temps
	*/
	gettimeofday(&timeval_avant, &timezone);

	/*
	On parcours tous les objets
	*/
	for (i = 0; i < n_objets; i++) {

		/*
		Si on excède la capacité d'un sac pour un objet, on stoppe tout (totally badass...)
		*/
		if ((unsigned int) tableau_poids[i] > capacite) {
			printf("Le poids du tableau d'objets (n° %d) : %d est supérieur à %d", i, tableau_poids[i], capacite);
			exit(EXIT_FAILURE);
		}

		/*
		ELSE
		*/

		j = 0;

		while (j <= n_objets) {

			/*
			Cas d'arrêt
			*/
			if (j == n_objets) {
				printf("ERREUR /// somme des poids des objets > capacité");
				exit(EXIT_FAILURE);
			}

			/*
			Calcul de la différence entre la capacité restante d'un sac, et le poids de l'objet en cours
			*/
			difference = tab_poids_totaux[j] - tableau_poids[i];

			/*
			Si la différence est supérieur ou égale à 0, on peut alors insérer l'objet dans le sac actuel, et l'on passe à l'objet suivant...
			*/
			if (difference >= 0) {
				if ((unsigned int)tab_poids_totaux[j] == capacite)
					nb_sacs++;
				tab_poids_totaux[j] = difference;
				tab_objets[i] = j;
				break;
			}

			j++;

		}

	}

	/*
	Fin de mesure du temps
	*/
	gettimeofday(&timeval_apres, &timezone);

	difference_time = ((timeval_apres.tv_sec - timeval_avant.tv_sec) * 1000000L) + (timeval_apres.tv_usec - timeval_avant.tv_usec);

	printf("Algorithme prenant ici %d sacs\n", nb_sacs);

	for (i = 0; i < n_objets; i++)
		printf("\tObjet %d, poids %d, sac %d\n",i,tableau_poids[i],tab_objets[i]);

	printf("Temps pris par l'algorithme : %lld microsecondes\n", difference_time);

	free(tab_poids_totaux);

}

void best_fit(int* tab_objets) {

	/*
	Structure de temps - nécessaire au calcul du temps de l'algorithme
	*/
	struct timeval timeval_avant, timeval_apres;

	/*
	Structure de zone de temps
	*/
  	struct timezone timezone;

  	/*
	Variable contenant la différence entre deux mesures du temps
  	*/
  	long long difference_time;

	unsigned int i = 0;

	unsigned int j = 0;

	unsigned int current_bag = 0;

	int tmp = 0;

	unsigned int nb_sacs = 0;

	/*
	Tableau permettant de stocker combien il reste de poids à placer dans chaque sac
	*/
	int* tab_poids_totaux = (int*) malloc(sizeof(int) * n_objets);

	/*
	Entier permettant de stocker la différence entre la capacité restante d'un sac, et le poids de l'objet actuel
	*/
	int difference = capacite;

	/*
	Chaque entier de la table contiendra la capacité d'un sac
	*/
	for (i = 0; i < n_objets; i++)
		tab_poids_totaux[i] = capacite;

	/*
	Début de mesure du temps
	*/
	gettimeofday(&timeval_avant, &timezone);

	/*
	On parcours tous les objets
	*/
	for (i = 0; i < n_objets; i++) {

		/*
		Si on excède la capacité d'un sac pour un objet, on stoppe tout (totally badass...)
		*/
		if ((unsigned int) tableau_poids[i] > capacite) {
			printf("Le poids du tableau d'objets (n° %d) : %d est supérieur à %d", i, tableau_poids[i], capacite);
			exit(EXIT_FAILURE);
		}

		/*
		ELSE
		*/

		j = 0;

		difference = capacite;

		while (j <= n_objets) {

			/*
			Cas d'arrêt
			*/
			if (j == n_objets) {
				if ((unsigned int)tab_poids_totaux[current_bag] == capacite)
					nb_sacs++;
				tab_poids_totaux[current_bag] = difference;
				tab_objets[i] = current_bag;
				break;
			}

			/*
			Calcul de la différence entre la capacité restante d'un sac, et le poids de l'objet en cours
			*/
			tmp = tab_poids_totaux[j] - tableau_poids[i];

			if (tmp < difference && tmp >= 0) {
				difference = tmp;
				current_bag = j;
			}

			j++;

		}

	}

	/*
	Fin de mesure du temps
	*/
	gettimeofday(&timeval_apres, &timezone);

	difference_time = ((timeval_apres.tv_sec - timeval_avant.tv_sec) * 1000000L) + (timeval_apres.tv_usec - timeval_avant.tv_usec);

	printf("Algorithme prenant ici %d sacs\n", nb_sacs);

	for (i = 0; i < n_objets; i++)
		printf("\tObjet %d, poids %d, sac %d\n",i,tableau_poids[i],tab_objets[i]);

	printf("Temps pris par l'algorithme : %lld microsecondes\n", difference_time);

	free(tab_poids_totaux);

}
