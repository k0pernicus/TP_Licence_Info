#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

/*
  Renvoie le nom du programme demandé
*/
char* renvoie_pointeur_programme(char* path) {

  /*Longueur du chemin donné*/
  int longueur_path;

  /*Longueur réelle du chemin*/
  longueur_path = strlen(path) - 1;

  while (path[longueur_path] != '/') {
    longueur_path--;
  }

  /*On retourne un pointeur débutant au nom du programme demandé/appelé*/
  return path+longueur_path+1;

}

/*
  Fonction permettant de retourner les droits de l'utilisateur sur un fichier / répertoire
*/
int maccess(char *path, int amode, int verbose) {

  char* programme_path;
  int code_retour_access;

  code_retour_access = access(path, amode);
    
  /*Si le mode VERBOSE a été activé...*/
  if (verbose == 1) {
    if (code_retour_access == 0) printf("Accès de %s en mode %d autorisé\n", path, amode);
    else switch(errno) {
      case EACCES:
	perror("Le droit d'accès demandé au fichier n'est pas positionné ");
	break;
      case ENOENT:
	perror("Le fichier n'existe pas ");
	break;
      case ENOTDIR:
	perror("Une des composantes du nom de fichier n'est pas un répertoire ");
	break;
      case ENAMETOOLONG:
	programme_path = renvoie_pointeur_programme(path);
	if (strlen(programme_path) > NAME_MAX) {
	  perror("Le nom du fichier est trop long ");
	  break;
	}
	else {
	  perror("Une des composantes du nom de fichier est trop longue ");
	  break;
	};
      case ELOOP:
	perror("Le nom du fichier comporte trop de liens symboliques ");
	break;
      default:
	perror("problème d'accès ");
	break;
      };
  }
  /*Si le mode verbose n'a pas été activé...*/
  else printf("Accès %d, code sortie: %d\n", amode, code_retour_access); 

  return 0;

}

/*
Main du programme maccess
*/
int main(int argc, char** argv) {

  int verbose;
  char* chemin_vers_acces;
  char acces_lu;
  int nombre_acces;
  int i;
  int j;
  int acces_entier;

  verbose = 0;

  assert(argc >= 3);
  chemin_vers_acces = argv[2];
  nombre_acces = strlen(argv[1]);
  /*On regarde si l'utilisateur a utilisé le système '-objects' ou '--objects'*/
  if (argv[1][1] != '-') {
    j = 1;
  } 
  else { 
    j = 2;
  };

  /*On vérifie si le mode verbose a été activé ou non*/
  for (i = j; i<nombre_acces; i++) {
    if (strncmp(&argv[1][i],"v",1) == 0) verbose = 1;
  };
  
  /*On vérifie les accès*/
  for (i = j; i<nombre_acces; i++) {
    acces_lu = argv[1][j];
    j++;
    if (strncmp(&acces_lu,"v",1) == 0) { 
      continue;
    }
    else if (strncmp(&acces_lu,"r",1) == 0) acces_entier = R_OK;
    else if (strncmp(&acces_lu,"w",1) == 0) acces_entier = W_OK;
    else if (strncmp(&acces_lu,"x",1) == 0) acces_entier = X_OK;
    else { 
      perror("Le droit d'accès demandé au fichier n'est pas positionné "); 
      return 1;
    };
    
    /*On exécute la fonction maccess pour chaque demande d'accès noeud*/
    maccess(chemin_vers_acces, acces_entier, verbose);
  };

  return 0;

}
