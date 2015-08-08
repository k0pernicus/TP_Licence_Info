#include "tail.h"

/*Fonction permettant la même exécution que la commande UNIX tail - nous utiliserons ici un buffer de 2 * TAILLE_MAX_LIGNE * nombre_de_lignes (demandées par l'utilisateur), ce qui nous permettra de lire une seule fois le fichier donné en paramètre
*/
int mutile(int nbFile, int nbLines) {
  
  /*Variables entières*/
  int i, index, lecture_caracteres_ligne, longueur_buffer, cpt_caractere, change_line;

  /*Caractère lu (en cours)*/
  char caractere_lu;

  /*Pointeurs de début et de fin du buffer*/
  char* buffer_debut;
  char* buffer_fin;
  
  /*On réserve un espace mémoire (par un malloc) qui vaut 2 fois l'espace mémoire demandé (TAILLE_MAX_LIGNE * nombre_lignes) afin de sauver les caractères / lignes du fichier donné*/
  char* buffer = malloc(sizeof(char) * nbLines * 2 * (TAILLE_MAX_LIGNE)+1);

  /*On vérifie que le malloc s'est bien passé*/
  if (buffer == NULL) {
    free(buffer);
    perror("Espace mémoire insuffisant pour le buffer!");
  }

  /*On sauvegarde la longueur du buffer*/
  longueur_buffer = nbLines * 2 * (TAILLE_MAX_LIGNE)+1;

  /*On initialise les variables entières*/
  index = 0;
  lecture_caracteres_ligne = 0;

  /*On définit les pointeurs de début et de fin dans le buffer*/
  buffer_debut = &buffer[index];
  buffer_fin = &buffer[index];

  /*On lira les caractères du fichier un par un*/
  while (read(nbFile, &caractere_lu, 1)) {
    
    /*On incrémente le nombre de caractères lus*/
    cpt_caractere++;
    
    /*Si le nombre de caractères excéde notre taille fixée de caractères lus maximum sur une ligne, on renvoie une erreur*/
    if (cpt_caractere > TAILLE_MAX_LIGNE) {
      perror("Trop de caractères sur une seule ligne!");
      exit(EXIT_FAILURE);
    };

    /*Si le compteur de ligne excède les lignes max demandées à être afficher, alors le pointeur de début est avancé du nombre de caractères contenus à partir de ce pointeur - la variable change_ligne sert à savoir quand avancer le pointeur de début*/
    if (lecture_caracteres_ligne >= nbLines && (change_line == TRUE)) { 
      buffer_debut = buffer_debut+strlen(buffer_debut)+1;
      change_line = FALSE;
    };

    /*Si le caractère lu est un saut de ligne, alors on met à '\0' celui-ci afin de mieux pouvoir modifier le buffer de début, on incrémente le compteur de ligne, l'on passe notre compteur de caractères à 0 et on passe la variable change_ligne à TRUE afin de pouvoir bouger le pointeur de début*/
    if (caractere_lu == '\n') {
      *buffer_fin = '\0';
      lecture_caracteres_ligne++;
      cpt_caractere = 0;
      change_line = TRUE;
    }
    /*Sinon, on imprime seulement le caractère lu*/
    else {
      *buffer_fin = caractere_lu;
    };

    /*On tourne dans le tampon -> On incrémente la position dans le buffer (c'est à dire le pointeur de fin de buffer), modulo la taille du buffer*/
    index = (index + 1) % longueur_buffer;
    buffer_fin = &buffer[index];
  }
  
  /*On remplace tous les '\0' par des sauts de lignes*/
  for (i = 0; i<longueur_buffer; i++) {
    if (buffer[i] == '\0') buffer[i] = '\n';
  };

  /*On écrit sur la sortie standard tout ce que le buffer contient*/
  write(STDOUT_FILENO, buffer_debut, buffer_fin-buffer_debut);

  /*On libère la mémoire allouée par le malloc*/
  free(buffer);

  /*Tout s'est bien passé, on retourne 0...*/
  return 0;

}
