#include <stdio.h>
#include <stdlib.h>
#include "gray_lib.h"

int meilleurGris(unsigned char* gris, int* poids, int deb, int fin) {
  int i;
  int tot = 0;
  int cpt = 0;
  
  for (i = deb ; i <= fin ; i++) {
      tot += poids[i] * gris[i];
      cpt += poids[i];
  }

  if(cpt == 0)
      return 0;
  else
      return (tot / cpt);
}

int distanceMin(unsigned char* gris, int* poids, int deb, int fin) {
  int dist, i, best;

  dist = 0;
  best = meilleurGris(gris, poids, deb, fin);

  for(i = deb ; i <= fin ; i++) {
      dist += ((gris[i] - best) * (gris[i] - best)) * poids[i];
  }

  return dist;
}

int distanceMinFin_(unsigned char* gris, int* poids, int n, int k, int pos) {
  if ((n <= k)) {
      /* printf("Pour n = %d et k = %d :\n", n, k); */
      /* printf("pos = %d\n", pos); */
      /* printf("Renvoie 0\n\n"); */
      
      return 0;
  }
  else {
      int i;
      int min;
      int ind;
      int indMin;
      int tmp;
      
      ind = n - k;
      indMin = ind;
      min = distanceMin(gris, poids, pos, pos + ind) + distanceMinFin_(gris, poids, n - (ind + 1), k - 1, pos + ind + 1);
      ind--;
      
      while(ind > 0) {
        if ((tmp = (distanceMin(gris, poids, pos, pos + ind) + distanceMinFin_(gris, poids, n - (ind + 1), k - 1, pos + ind + 1))) < min) {
      min = tmp;
      indMin = ind;
        }
        ind--;
      }

      /* printf("Pour n = %d et k = %d :\n", n, k); */
      /* printf("pos = %d\npos + indMin = %d\n", pos, pos + indMin); */
      /* printf("Renvoie min = %d\n", min); */
      /* printf("Meilleur gris = %d\n\n", meilleurGris(gris, poids, pos, pos+indMin)); */

      return min;
  }
}

int distanceMinFin(unsigned char* gris, int* poids, int n, int k) {
  return distanceMinFin_(gris, poids, n, k, 0);
}

int** distanceMinDyn(unsigned char* gris, int* poids, int n, int k) {

    int i = 0, j = 0, l = 0, min = 0, tmp = 0;

    if (k >= n)
        exit(EXIT_FAILURE);

    int** dm = malloc(sizeof(int*) * n);

    for (i = 0; i < n ; i++)
        dm[i] = malloc(sizeof(int) * (k+1));

    /* Calcul des valeurs */

    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j <= k ; j++ ) {
            if((j == 0) || (i == 0))
                dm[i][j] = 0;
            else {
                if(j == 1)
                    dm[i][j] = distanceMin(gris, poids, 0, i);
                else {
                    dm[i][j] = -1;
                    // min = dm[i-1][j-1] + distanceMin(gris, poids, i, i);
                    min = dm[i-1][j-1];

                    /* Calcul du tableau */

                    for( l = 0 ; l < i ; l++ ) {
                        tmp = dm[i-1-l][j-1] + distanceMin(gris, poids, i-l, i);
                        if(tmp < min)
                            min = tmp;
                    }

                    dm[i][j] = min;
                }
            }
        }

    }

    return dm;

}

int** distanceMinDyn2(unsigned char* gris, int* poids, int n, int k) {

    int i = 0, j = 0, l = 0, min = 0, tmp = 0;

    if (k >= n)
        exit(EXIT_FAILURE);

    int** dm = malloc(sizeof(int*) * k);

    for (i = 0; i < n ; i++)
        dm[i] = malloc(sizeof(int) * 2);

    /* Calcul des valeurs */

    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j <= k ; j++ ) {
            if((j == 0) || (i == 0))
                dm[i][j] = 0;
            else {
                if(j == 1)
                    dm[i][j] = distanceMin(gris, poids, 0, i);
                else {
                    dm[i][j] = -1;
                    // min = dm[i-1][j-1] + distanceMin(gris, poids, i, i);
                    min = dm[i-1][j-1];

                    /* Calcul du tableau */

                    for( l = 0 ; l < i ; l++ ) {
                        tmp = dm[i-1-l][j-1] + distanceMin(gris, poids, i-l, i);
                        if(tmp < min)
                            min = tmp;
                    }

                    dm[i][j] = min;
                }
            }
        }

    }

    return dm;

}

void imprTabDyn(int** dm, int n, int k) {
  
    int i = 0, j = 0;

    /* Impression du tableau */

    printf("                  |  k = 0 |  k = 1 |  k = 2 |  k = 3 |\n");
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j <= k ; j++) {
            if(j == 0)
                printf("Ind couleurs = %2d | %6d |", i, dm[i][j]);
            else
                printf(" %6d |", dm[i][j]);
            if(j == k)
                printf("\n");
        }
    }

}

struct structRetour* retourVersLeDebut(int** dm, int n, int k) {

  /*
  On part de [n-1][k], on remonte en haut, gauche et en travers, jusqu'à [0][0]
  */

  int entierCourant = 0;
  int i = 0, h = 0, l = 0;
  int* tabRetour = (int*)malloc((n+k+1) * sizeof(int));

  struct structRetour* structRetour_s = malloc(sizeof(struct structRetour));

  h = n-1;

  l = k;

  entierCourant = dm[h][l];

  while (h != 0 && l != 0) {

    tabRetour[i] = entierCourant;

    i++;

    //printf("%d-%d\n", h, l);

    //EGALITE

    //DIAG
    if (dm[h-1][l-1] == entierCourant) {
      //printf("Diag - entierCourant\n");
      h = h - 1;
      l = l - 1;
      entierCourant = dm[h][l];
      continue;
    }
    //GAUCHE
    if (dm[h][l-1] == entierCourant) {
      //printf("Gauche - entierCourant\n");
      l = l - 1;
      entierCourant = dm[h][l];
      continue;
    }
    //HAUT
    if (dm[h-1][l] == entierCourant) {
      //printf("Droit - entierCourant\n");
      h = h - 1;
      entierCourant = dm[h][l];
      continue;
    }

    //INFERIORITE

    //DIAG
    if (dm[h-1][l-1] < entierCourant) {
      //printf("Diag - inf\n");
      h = h - 1;
      l = l - 1;
      entierCourant = dm[h][l];
      continue;
    }
    if (dm[h][l-1] < entierCourant) {
      //printf("Gauche - inf\n");
      l = l - 1;
      entierCourant = dm[h][l];
      continue;
    }
    //HAUT
    if (dm[h-1][l] < entierCourant) {
      //printf("Droit - inf\n");
      h = h - 1;
      entierCourant = dm[h][l];
      continue;
    }

  }

  structRetour_s -> taille = i;
  structRetour_s -> tab = tabRetour;

  return structRetour_s;

}
