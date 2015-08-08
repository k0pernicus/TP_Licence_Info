/*
Fonction permettant de calculer les inversions contenues dans un tableau en O(n²)
@param tab Le tableau pour lequel on calculera les inversions à apporter, afin de le rendre semblable à un tableau normalisé
@param longueur La longueur du tableau pris en paramètre
*/
unsigned int calcul_inversions(int* tab, int longueur);

/*
Fonction permettant de calculer les inversions contenues dans un tableau en O(n log n)
@param tab Le tableau pour lequel on calculera les inversions à apporter, afin de le rendre semblable à un tableau normalisé
@param longueur La longueur du tableau pris en paramètre
*/
unsigned int calcul_inversions_2(int *tab, unsigned int longueur);
