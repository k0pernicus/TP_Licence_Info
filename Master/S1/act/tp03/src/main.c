#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gray_lib.h"

/**
   Affiche comment utiliser le programme et quitte en erreur
 */
void usage(char *nom) {
  printf("Usage: ");
  printf("act-tp3 <file> <k>\n");
  printf("\t<file> fichier .gray à traiter\n");
  printf("\t<k> nombre de couleurs cible ( > 0 )\n");
  exit(EXIT_FAILURE);
}

/**
   Renvoie la taille d'un fichier
   @param file Pointeur sur le fichier
   @return La taille du fichier
   @return -1 en cas d'erreur
*/
int size_file(FILE *file) {
  int size;
  if (fseek(file, 0, SEEK_END) != 0)
    return -1;
  size = ftell(file);
  if (fseek(file, 0, SEEK_SET) != 0)
    return -1;
  return size;
}

/**
   MAIN
   @param file nom du fichier .gray à traiter
   @param k nombre de couleurs cible ( > 0 )
 */
int main (int argc, char *argv[]) {
  if (argc != 3) {
    usage(argv[0]);
  }
  
  char *image_name;
  FILE *image_file;
  unsigned char *image;
  unsigned char *gris;
  int poids_temp[NB_GRIS_MAX];
  int *poids;
  int size;
  int nbGris;
  int i, j;
  int c;
  int k;

  /* Initialisation des variables */
  image_name = argv[1];
  k = atoi(argv[2]);
  
  if (k == 0) {
    usage(argv[0]);
  }
  
  for(i = 0 ; i < NB_GRIS_MAX ; i++) {
    poids_temp[i] = 0;
  }
  
  /* Ouverture et calcul de la taille du fichier */
  if((image_file = fopen(image_name, "r")) == NULL) {
    printf("Erreur ouverture fichier : %s\n", image_name);
    exit(EXIT_FAILURE);
  }
  size = size_file(image_file);
  printf("Taille du fichier %s : %d\n", image_name, size);

  /* Suite initialisation */
  if ((image = malloc(size)) == NULL) {
    printf("Erreur allocation tableau d'octets de taille %d\n", size);
    fclose(image_file);
    exit(EXIT_FAILURE);
  }
  
  /* Calcul du nombre de gris */
  i=0;
  nbGris = 0;
  while((c = fgetc(image_file)) != EOF) {
    image[i] = (char) c;
    if(poids_temp[image[i]] == 0)
      nbGris++;
    poids_temp[image[i]]++;
    i++;
  }

  /* Initialisation des tableaux gris et poids */
  if ((gris = malloc(nbGris)) == NULL) {
    printf("Erreur allocation tableau des gris\n");
    free(image);
    fclose(image_file);
    exit(EXIT_FAILURE);
  }

  if ((poids = malloc(nbGris)) == NULL) {
    printf("Erreur allocation tableau des poids\n");
    free(image);
    free(gris);
    fclose(image_file);
    exit(EXIT_FAILURE);
  }

  j = 0;
  for(i = 0 ; (i < NB_GRIS_MAX || j == nbGris) ; i++) {
    if (poids_temp[i] != 0) {
      gris[j] = (unsigned char) i;
      poids[j] = poids_temp[i];
      j++;
    }
  }

  /*
  distance minimale causée par la fusion des couleurs i, i+1 , ... , n-1 en k intervalles 
  */
  int** dm = NULL;
  
  /* Test */
  printf("Nombre de gris : %d\n", nbGris);

  printf("Res de meilleurGris(0, 1) : %d\n", meilleurGris(gris, poids, 0, 1));
  printf("Res de meilleurGris(2, 5) : %d\n", meilleurGris(gris, poids, 2, 5));
  printf("Res de meilleurGris(6, 6) : %d\n", meilleurGris(gris, poids, 6, 6));

  int dist = 0;

  dist = distanceMin(gris, poids, 0, 1);
  dist += distanceMin(gris, poids, 2, 5);
  dist += distanceMin(gris, poids, 6, 6);

  printf("Distance mini \"à la main\": %d\n", dist);
  
  dist = distanceMinFin(gris, poids, nbGris, k);

  printf("Distance mini \"récursif\" : %d\n", dist);

  dm = distanceMinDyn(gris, poids, nbGris, k);

  imprTabDyn(dm, nbGris, k);

  printf("Distance mini \"dynamique\" : %d\n", dm[nbGris - 1][k]);

  struct structRetour* structRetour_s = retourVersLeDebut(dm, nbGris, k);

  for (i = structRetour_s -> taille; i >= 0; i--) {

    if (i != 0)
      printf("%d - ", structRetour_s -> tab[i]);
    else
      printf("%d", structRetour_s -> tab[i]);

  }

  /* Fermeture propre */
  fclose(image_file);
  free(image);
  
  exit(EXIT_SUCCESS);
}
