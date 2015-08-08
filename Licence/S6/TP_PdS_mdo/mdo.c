#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>
#include "makeargv.h"

/*OPTIONS*/

/* - Contient 'OR' ou 'AND'
   Par d�faut, nous initialiserons la variable � 0 -> AND
*/
static int optionANDOR;

/* - Contient 'CC'
   Par d�faut, nous initialiserons la variable � 0
*/
static int optionCC;

/* - Contient 'KILL'
   Par d�faut, nous initialiserons la variable � 0
*/
static int optionKILL;

/*POSITION_CMD
  Entier valant la position par d�faut de la 1�re commande donn�e lors de l'ex�cution du programme*/
static int position_cmd;

/*FONCTION - MAIN*/
/*
  Fonction permettant de v�rifier les options donn�es en param�tres du programme mdo
  Cette fonction prend en argument la cha�ne contenant les arguments du main, et diff�renciera elle-m�me les options des commandes
  Cette fonction renvoie un entier, comme quoi le programme s'est bien ex�cut�.
*/
int verif_options(char *arguments[]) {

  while(*arguments) {
    /*Si deux options sont donn�es � la suite (AND apr�s OR) alors on d�clenche une erreur...*/
    /*Si option OR, alors on active cette option et on incr�mente la position du premier programme dans la cha�ne des arguments*/
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
    /*Option KILL -> On mettra un entier valant 2, on v�rifiera ensuite la pr�sente de CC pour activer l'option KILL*/
    if (strcmp(*arguments, "--kill") == 0) {
      optionKILL = 2;
      position_cmd++;
    }
    /*On incr�mente l'adresse du prochain argument*/
    arguments++;
  }

  /*On v�rifie la pr�sence de CC et KILL*/
  if ((optionCC == 1) && (optionKILL == 2)) optionKILL = 1;

  /*Si tout s'est bien pass�, on renvoit 1*/
  return 1;
}

/*
  MAIN
*/
int main (int argc, char *argv[]) {
  /*
    i -> Sert pour la boucle concernant les arguments du programme
    j -> Sert pour la boucle concernant les options du programme
    result -> Statut form� de la conjonction ou disjonction des statuts retourn�s par les commandes selon la valeur de l'option
    stat_cmd -> Valeur de makeargv; sert pour assert() afin de v�rifier que tout s'est bien pass� pour cette fonction
    status -> Valeur concernant le retour du fils par le p�re
  */
  int i, j, k, result, stat_cmd, status, nbproc;
  pid_t pid;
  pid_t *tableau_de_processus;
  /*On v�rifie que le nombre d'arguments est bien sup�rieur � 1*/
  assert(argc > 1);

  /*Initialisation des variables globales*/
  optionANDOR = 0; /*0 pour AND, par d�faut*/
  optionCC = 0; /*0 pour CC, par d�faut*/
  optionKILL = 0; /*0 pour KILL, par d�faut*/
  position_cmd = 1; /*1 car 0 est le nom du programme*/
  
  verif_options(argv);

  /*on connait le nombre de processus � cr�er */
  nbproc = argc-position_cmd;

  /*Si l'utilisateur demande l'option KILL mais qu'il n'a pas sp�cifi� CC, on lui renvoie un message d'erreur, et on arr�te le programme*/
  if (optionKILL == 2) {
    perror("Option non valable: --kill doit etre utilise avec l'option --cc");
    exit(EXIT_FAILURE);
  }

  /*On initialise un tableau de processus, contenant des processus fils, pour les tuer dans le cas de KILL*/
  tableau_de_processus = malloc(sizeof(pid_t)*nbproc);

  /* traiter argv[i], � partir de la position de la 1�re commande donn�e en param�tre */
  for (i = position_cmd; i<argc; i++) { 
        
    /*On d�clare un tableau, qui contiendra le programme ainsi que ses options (s'il y a), afin de pouvoir l'ex�cuter*/
    char **cmdargv;
    
    /*On remplit le tableau contenant la commande, avec ses options*/
    stat_cmd = makeargv(argv[i], " \t", &cmdargv);
    /*On v�rifie si le makeargv s'est bien pass�*/
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
      /*Cas du p�re: on ne fait rien*/
    default:
      break;
    }

    /*On vide le tableau de caract�res, rempli par markargv()*/
    freeargv(cmdargv);
  }

  switch(optionANDOR) {
    /*OR vaut 1*/
  case 1:
    for (j=position_cmd; j<argc; j++) {
      wait(&status);
      if (WIFEXITED(status)) {
	if (WEXITSTATUS(status)==0 ) {
	  /*Si CC activ�, alors on retourne status, on arr�te*/
	  if (optionCC == 1) {
	    /*L'option kill est activ�, on termine tous les processus fils ouverts*/
	    if (optionKILL==1) {
	      for(k=0; k<nbproc; k++) {
		kill(tableau_de_processus[k], SIGTERM);
	      }
	    }
	    exit(EXIT_SUCCESS);
	    /*La variable result vaut le OR entre lui-m�me et le status renvoy� par le dernier processus fils*/
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
	  /*result vaut le AND entre lui-m�me et le status renvoy� par le dernier processus fils*/
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
