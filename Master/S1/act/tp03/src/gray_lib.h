#define NB_GRIS_MAX 256

struct structRetour {
   int* tab;
   int taille;
};

/**
   Calcule le niveau de gris d'un intervalle donné
   @param gris Le tableau d'intensité des gris
   @param poids Le tableau des poids des gris
   @param deb La position de début
   @param fin La position de fin
   @return Le niveau de gris donnant la distance minimale après fusion
   @return -1 si la position de début est supérieure à la position de fin
*/
int meilleurGris(unsigned char* gris, int* poids, int deb, int fin);

/**
   Calcule la distance minimale qu'entraînera la fusion d'un intervalle de la palette
   @param gris Le tableau d'intensité des gris
   @param poids Le tableau des poids des gris
   @param deb La position de début
   @param fin La position de fin
   @return La distance minimale qu'entraînera la fusion d'un intervalle de la palette
 */
int distanceMin(unsigned char* gris, int* poids, int deb, int fin);

/**
   Calcule la distance minimale qu'entraînera la réduction du nombre de couleurs
   d'une palette de <n> gris à <k> gris
   @param gris Le tableau d'intensité des gris
   @param poids Le tableau des poids des gris
   @param n Le nombre de couleurs de la palette actuelle
   @param k Le nombre de couleurs cible
   @return La distance minimale pour réduire le nombre de couleurs de <n> à <k>
 */
int distanceMinFin(unsigned char* gris, int* poids, int n, int k);

/*
   Fonction permettant le calcul de la distance minimale, en utilisant la fonction distanceMinFin
   @param gris Le tableau d'intensité des gris
   @param poids Le tableau des poids des gris
   @param n Le nombre de couleurs de la palette actuelle
   @param k Le nombre de couleurs cible
   @param pos ??????
   @return La distance minimale pour réduire le nombre de couleurs de <n> à <k>
*/
int distanceMinFin_(unsigned char* gris, int* poids, int n, int k, int pos);

/*
   Algorithme permettant de calculer la distance minimale, via la programmation dynamique
   @param dm Un pointeur vers le tableau à remplir
   @param gris Le tableau d'intensité des gris
   @param poids Le tableau des poids des gris
   @param n Le nombre de couleurs de la palette actuelle
   @param k Le nombre de couleurs cible
   @return Le tableau contenant tous les calculs de prog. dyn.
*/
int** distanceMinDyn(unsigned char* gris, int* poids, int n, int k);

/*
   Permet d'imprimer le tableau contenant toutes les distances
   @param dm Un pointeur vers le tableau à remplir
   @param n Le nombre de couleurs de la palette actuelle
   @param k Le nombre de couleurs cible
*/
void imprTabDyn(int** dm, int n, int k);

/*
   Permet de renvoyer le chemin menant de 0 jusqu'à la valeur optimale calculée en programmation dynamique
   @param dm Un pointeur vers le tableau de prog. dyn
   @param n Le nombre de couleurs de la palette actuelle
   @param k Le nombre de couleurs cible
   @return Une structure contenant le chemin (en tableau de valeurs), ainsi qu'un entier valant la taille du tableau
*/
struct structRetour* retourVersLeDebut(int** dm, int n, int k);



