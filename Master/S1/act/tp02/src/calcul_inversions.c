#include <stdio.h>
#include <stdlib.h>

unsigned int calcul_inversions(int* tab, unsigned int longueur) {

	unsigned int i, j;

	int n_courant, n_suivant;

	unsigned int cpt = 0;

	for (i = 0; i < longueur; i++) {

		n_courant = *(tab+i);

		for (j = i; j < longueur; j++) {

			n_suivant = *(tab+j);

			if (n_courant > n_suivant)
				cpt++;

		}

	}

	return cpt;

}

unsigned int fusion(int *tab, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;
 
  int L[n1], R[n2];

  unsigned int cpt = 0;

  for(i = 0; i < n1; i++)
    L[i] = tab[l + i];
  for(j = 0; j < n2; j++)
    R[j] = tab[m + 1+ j];
 
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      tab[k] = L[i];
      i++;
    }
    else {
      tab[k] = R[j];
      j++;
      /* Ajout du nombre d'inversions */
      cpt = cpt + (n1 - i);
    }
    k++;
  }
 
  while (i < n1) {
    tab[k] = L[i];
    i++;
    k++;
  }
 
  while (j < n2) {
    tab[k] = R[j];
    j++;
    k++;
  }

  return cpt;
}

unsigned int tri_fusion(int *tab, int l, int r) {
  unsigned int cpt = 0;
  if (l < r) {
    int m = l+(r-l)/2;
    cpt = tri_fusion(tab, l, m);
    cpt += tri_fusion(tab, m+1, r);
    cpt += fusion(tab, l, m, r);
  }
  return cpt;
}

unsigned int calcul_inversions_2(int *tab, unsigned int longueur) {
  unsigned int cpt = 0;
  int *tab_tmp = malloc(longueur * sizeof(int));
  int i;

  /* On travaille avec un tableau temporaire pour ne pas trier le tableau initial */
  for(i = 0 ; i < longueur ; i++)
    tab_tmp[i] = tab[i];
  
  if (longueur > 0)
    cpt = tri_fusion(tab_tmp, 0, longueur - 1);
  
  free(tab_tmp);

  return cpt;
}
