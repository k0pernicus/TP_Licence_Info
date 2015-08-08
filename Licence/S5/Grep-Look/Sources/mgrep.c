#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maxline.h"

/*Programme mgrep
 */

/* Définition de la fonction mgrep, qui nous servira dans le main à chercher le mot demandé, dans le fichier donné en 1er argument du programme
 */
int mgrep(FILE*, char*);

/*Main du programme mgrep
 * @param: argc, le nombre d'arguments pris en paramètres du programme
 * @param: argv[], un tableau contenant les arguments pris en paramètres du programme
*/
int main(int argc, char* argv[]) {

  /* Déclaration de variables
   */
  FILE *fichier;
  char *mot_a_chercher;
  char *fichier_lu;
  int retour_mgrep;

  /* Initialisation des variables déclarées
   */
  fichier_lu = argv[1];
  mot_a_chercher = argv[2];
  fichier = fopen(argv[1], "r");

  /*Vérification du fichier, s'il est nul, on renverra un message d'erreur
   */
  if (fichier == NULL || ((fichier != NULL) && (argc <= 2))){ /*Si le fichier ouvert est vide*/
    printf("\nRègles d'utilisation du programme %s\n\nCe programme prend en paramètres: ./mgrep [1] [2]\n1 _ un fichier .txt non vide,\n2 _ un mot.\n\nCe programme se chargera de chercher le mot dans le fichier .txt, s'il le trouve dans une ligne, on imprimera le numéro de la ligne, ainsi que la ligne.\n\nUn problème? Une critique? Contactez-moi : antonin.carette[at]gmail[dot]com\n\n",argv[0]); /*Message d\'erreur*/
    exit(EXIT_FAILURE); /*Sortie d\'erreur*/
  }

  /* Si tout va bien pour le fichier, on cherche le mot à l\'intérieur de celui-ci; on sauvegarde la valeur de retour
   */
  retour_mgrep = mgrep(fichier, mot_a_chercher);

  /* On regarde si la fermeture du fichier est correcte, sinon on renverra un message d'erreur
   */
  if (fclose(fichier) == EOF) { /*Si le fichier ouvert ne peut se fermer -> pas de EOF*/
    printf("Problème de fermeture du fichier %s\n", fichier_lu); /*Message d\'erreur*/
    exit(EXIT_FAILURE); /*Sortie d\'erreur*/
  }

  /* Le programme s\'est bien exécuté
   */
  return retour_mgrep;

}

/* Fonction mgrep
 * @param: fichier, un fichier de type FILE
 * @param: mot_a_chercher, le mot que l\'on veut rechercher dans le fichier donné en 1er paramètre
 */
int mgrep(FILE* fichier, char* mot_a_chercher) {

  /* Déclaration de variables
   */
  char ligne_lue[MAXLINE];
  int nb_ligne;
  char* mot;

  /* Initialisation des variables déclarées
   */
  nb_ligne = 0;
  mot = mot_a_chercher;
  
  /* On lira toutes les lignes du fichier, tant que l'une d'entre elles n'est pas NULL
   * On incrémentera le compteur de lignes lues
   * On regardera si la ligne lue contient le mot chercher via la fonction strstr(); si oui, le retour de cette fonction nous retournera une valeur non nulle, on imprimera alors la ligne et son numéro; sinon, on passera à la ligne suivante
   */
  while(fgets(ligne_lue, MAXLINE, fichier) != NULL) {
    nb_ligne = nb_ligne+1;
    if (strstr(ligne_lue, mot) != NULL) {
      printf("Ligne %d: %s",nb_ligne, ligne_lue);
    }
  }

  /*Le programme s\'est bien exécuté, on retourne 0*/
  return 0;
}
