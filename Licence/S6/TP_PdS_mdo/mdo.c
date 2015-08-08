#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>
#include "makeargv.h"

/*OPTIONS*/

/* - Contient 'OR' ou 'AND'
   Par défaut, nous initialiserons la variable à 0 -> AND
*/
static int optionANDOR;

/* - Contient 'CC'
   Par défaut, nous initialiserons la variable à 0
*/
static int optionCC;

/* - Contient 'KILL'
   Par défaut, nous initialiserons la variable à 0
*/
static int optionKILL;

/*POSITION_CMD
  Entier valant la position par défaut de la 1ère commande donnée lors de l'exécution du programme*/
static int position_cmd;

/*FONCTION - MAIN*/
/*
  Fonction permettant de vérifier les options données en paramètres du programme mdo
  Cette fonction prend en argument la chaîne contenant les arguments du main, et différenciera elle-même les options des commandes
  Cette fonction renvoie un entier, comme quoi le programme s'est bien exécuté.
*/
int verif_options(char *arguments[]) {

  while(*arguments) {
    /*Si deux options sont données à la suite (AND après OR) alors on déclenche une erreur...*/
    /*Si option OR, alors on active cette option et on incrémente la position du premier programme dans la chaîne des arguments*/
    if (strcmp(*arguments, "--or") == 0) { 
      optionANDOR = 1; 
      position_cmd++; 
    }
    /*Pareil pour AND (voir en haut)*/
    if (strcmp(*arguments, "--and") == 0) {
      position_cmd++;
    }
    /*Option CC*/
    if (strcmp(*arguments, "--cc") == 0) {
      optionCC = 1;
      position_cmd++;
    }
    /*Option KILL -> On mettra un entier valant 2, on vérifiera ensuite la présente de CC pour activer l'option KILL*/
    if (strcmp(*arguments, "--kill") == 0) {
      optionKILL = 2;
      position_cmd++;
    }
    /*On incrémente l'adresse du prochain argument*/
    arguments++;
  }

  /*On vérifie la présence de CC et KILL*/
  if ((optionCC == 1) && (optionKILL == 2)) optionKILL = 1;

  /*Si tout s'est bien passé, on renvoit 1*/
  return 1;
}

/*
  MAIN
*/
int main (int argc, char *argv[]) {
  /*
    i -> Sert pour la boucle concernant les arguments du programme
    j -> Sert pour la boucle concernant les options du programme
    result -> Statut formé de la conjonction ou disjonction des statuts retournés par les commandes selon la valeur de l'option
    stat_cmd -> Valeur de makeargv; sert pour assert() afin de vérifier que tout s'est bien passé pour cette fonction
    status -> Valeur concernant le retour du fils par le père
  */
  int i, j, k, result, stat_cmd, status, nbproc;
  pid_t pid;
  pid_t *tableau_de_processus;
  /*On vérifie que le nombre d'arguments est bien supérieur à 1*/
  assert(argc > 1);

  /*Initialisation des variables globales*/
  optionANDOR = 0; /*0 pour AND, par défaut*/
  optionCC = 0; /*0 pour CC, par défaut*/
  optionKILL = 0; /*0 pour KILL, par défaut*/
  position_cmd = 1; /*1 car 0 est le nom du programme*/
  
  verif_options(argv);

  /*on connait le nombre de processus à créer */
  nbproc = argc-position_cmd;

  /*Si l'utilisateur demande l'option KILL mais qu'il n'a pas spécifié CC, on lui renvoie un message d'erreur, et on arrête le programme*/
  if (optionKILL == 2) {
    perror("Option non valable: --kill doit etre utilise avec l'option --cc");
    exit(EXIT_FAILURE);
  }

  /*On initialise un tableau de processus, contenant des processus fils, pour les tuer dans le cas de KILL*/
  tableau_de_processus = malloc(sizeof(pid_t)*nbproc);

  /* traiter argv[i], à partir de la position de la 1ère commande donnée en paramètre */
  for (i = position_cmd; i<argc; i++) { 
        
    /*On déclare un tableau, qui contiendra le programme ainsi que ses options (s'il y a), afin de pouvoir l'exécuter*/
    char **cmdargv;
    
    /*On remplit le tableau contenant la commande, avec ses options*/
    stat_cmd = makeargv(argv[i], " \t", &cmdargv);
    /*On vérifie si le makeargv s'est bien passé*/
    assert(stat_cmd);

    /*On switch -> fork()*/
    switch(pid=fork()) {
      /*Cas d'erreur...*/
    case -1:
      printf("Erreur processus - n: %d\n", getpid());
      exit(EXIT_FAILURE);
      /*Cas du fils...*/
    case 0:
      /*On ajoute le numero du processus du fils dans le tableau des processus*/
      tableau_de_processus[(i-position_cmd)] = pid;
      printf("Execution du programme %s: en cours...\n", cmdargv[0]);
      execvp(cmdargv[0], cmdargv);
      exit(EXIT_FAILURE);
      /*Cas du père: on ne fait rien*/
    default:
      break;
    }

    /*On vide le tableau de caractères, rempli par markargv()*/
    freeargv(cmdargv);
  }

  switch(optionANDOR) {
    /*OR vaut 1*/
  case 1:
    for (j=position_cmd; j<argc; j++) {
      wait(&status);
      if (WIFEXITED(status)) {
	if (WEXITSTATUS(status)==0 ) {
	  /*Si CC activé, alors on retourne status, on arrête*/
	  if (optionCC == 1) {
	    /*L'option kill est activé, on termine tous les processus fils ouverts*/
	    if (optionKILL==1) {
	      for(k=0; k<nbproc; k++) {
		kill(tableau_de_processus[k], SIGTERM);
	      }
	    }
	    exit(EXIT_SUCCESS);
	    /*La variable result vaut le OR entre lui-même et le status renvoyé par le dernier processus fils*/
	    result = result || status;
	  }
	}
      }
    }
    break;
    /*DEFAULT vaut 0*/
  default:
    for (j=position_cmd; j<argc; j++) {
      wait(&status);
      if (WIFEXITED(status)) {
	if (WEXITSTATUS(status)==0) {
	  /*result vaut le AND entre lui-même et le status renvoyé par le dernier processus fils*/
	  result = result && status;
	}
	else {
	  /*On plante si option*/
	  if (optionCC == 1) {
	    if (optionKILL==1) {
	      for(k=0; k<nbproc; k++) {
		kill(tableau_de_processus[k], SIGTERM);
	      }
	    }
	    exit(EXIT_FAILURE);
	  }
	}
      }
    }
    break;
  };

  /*On libere le tableau de processus*/
  free(tableau_de_processus);

  /*On retourne result*/
  return result;
}
