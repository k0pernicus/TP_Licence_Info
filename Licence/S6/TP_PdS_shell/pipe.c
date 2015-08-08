/* 
   mshell project - do_pipe
   Carette Antonin
   Mar�chal Tanguy
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "pipe.h"
#include "jobs.h"
#include "cmd.h"

#define ENTREE 1
#define SORTIE 0

/*Fonction permettant de forker ainsi que d'ex�cuter la commande (et options) donn�s en param�tre
On donne un tableau de cha�nes de caract�res (cmds_exec)
On donne un pgid - pid de groupe (pgid)
On donne une entr�e (pipe_entree - peut �tre nul)
On donne une sortie (pipe_sortie - peut �tre nul)
On donne un entier - vaut la position de la commande (cmd_nbr)
*/
pid_t fork_redirections(char* cmds_exec[], pid_t pgid, int* pipe_entree, int* pipe_sortie, int cmd_nbr) {

  /*pidEnCours*/
  pid_t pidEnCours;

  /*On switch sur le pid*/
  switch(pidEnCours = fork()) {
    /*Si erreur, alors...*/
  case -1:
    /*On explique pourquoi*/
    perror("do_pipe: fork error\n");
    /*En cas d'activation 'verbose', on explique plus en d�tail*/
    if (verbose) 
      printf("Fork error, pid [%d] for command number %d [%s]", getpid(), cmd_nbr, cmds_exec[0]);
    /*Si l'on a renseign� le champ 'pipe_entree', alors on ferme l'entr�e et la sortie du pipe en lecture*/
    if (pipe_entree != NULL) {
      close(pipe_entree[ENTREE]);
      close(pipe_entree[SORTIE]);
    }
    /*Si l'on a renseign� le champ 'pipe_sortie', alors on ferme l'entr�e et la sortie du pipe en sortie*/
    if (pipe_sortie != NULL) {
      close(pipe_sortie[ENTREE]);
      close(pipe_sortie[SORTIE]);
    }
    /*On retourne le pid*/
    return pidEnCours;
    /*S'il s'agit du processus fils, alors...*/
  case 0:
    /*On regarde si la pose du processus donn� en param�tre est bien ajout� dans la liste contenant tous les processus du tube*/
    if (setpgid(0,pgid))
	printf("do_pipe: error setting gid fromm %d to %d", getpid(), pgid);
    /*En cas d'activation 'verbose', on explique plus en d�tail l'ex�cution de la commande par tel processus*/
    if (verbose)
      printf("do_pipe: Processing pid [%d] for command number %d [%s]\n", getpid(), cmd_nbr, cmds_exec[0]);
    /*On ferme la sortie si l'on a renseign� le champ du pipe_sortie, et inversement*/
    if (pipe_entree != NULL) dup2(pipe_entree[SORTIE], STDIN_FILENO);
    if (pipe_sortie != NULL) dup2(pipe_sortie[ENTREE], STDOUT_FILENO);
    /*On ex�cute le programme et ses options -> Si erreur lors de l'execvp, on ex�cutera la suite du code*/
    execvp(cmds_exec[0], cmds_exec);
    /*SI (ET SEULEMENT SI) ERREUR LORS DE L'EXECUTION DU PROGRAMME, ON EXECUTERA LA SUITE DU CODE...*/
    /*Signalement de l'erreur*/
    perror("do_pipe: execvp error\n");
    /*Explication plus pouss�e de l'erreur si activation du mode 'verbose'*/
    if (verbose)
      printf("Execvp error, pid [%d] for command %s\n", getpid(), cmds_exec[0]);
    /*On ferme la sortie si l'on a renseign� le champ du pipe_sortie, et inversement*/
    if (pipe_entree != NULL) close(pipe_entree[SORTIE]);
    if (pipe_sortie != NULL) close(pipe_sortie[ENTREE]);
    /*On quitte le programme*/
    exit(EXIT_FAILURE);
    /*Si l'on se trouve dans le p�re, alors...*/
  default:
    if (verbose)
      printf("do_pipe: Exiting pid [%d] by pid %d\n", pidEnCours, getpid());
    /*On ferme la sortie si l'on a renseign� le champ du pipe_sortie, et inversement*/
    if (pipe_entree != NULL) close(pipe_entree[SORTIE]);
    if (pipe_sortie != NULL) close(pipe_sortie[ENTREE]);
    /*On retourne le pid du processus en cours*/
    return pidEnCours;
  }
}

/*Fonction permettant de cr�er un pipe pour N commandes
On donne un tableau de tableau de cha�nes de caract�res (cmds)
Un nombre de commandes � ex�cuter (nbcmd)
Un bool�en pour savoir si la commande est � ex�cuter en arri�re-plan (1) ou non (0) (bg)
*/
void do_pipe(char *cmds[MAXCMDS][MAXARGS], int nbcmd, int bg) {

  /*Vaut le premier Pid (celui g�r� en premier; ne prend qu'une sortie dans le pipe, pas d'entr�e)*/
  pid_t Premierpid;
  /*Tableau de pipe, longueur de MAXCMDS*/
  int pipelines[MAXCMDS][2];
  /*Parcours de la boucle (pour nbcmd commandes)*/
  int i;

  /*Si activation du mode 'verbose', alors on d�clare � l'utilisateur que nous sommes entr� dans la fonction do_pipe*/
  if (verbose) 
    printf("Pipe entering\n");
  
  /*Pour toutes les commandes, alors...*/
  for (i=0; i<nbcmd; i++) {

    /*Vaut un pid "normal"*/
    pid_t pid;

    /*On assure la cr�ation du pipe*/
    assert(pipe(pipelines[i]) == 0);

    /*Si la commande en attente d'ex�cution est la premi�re, dans ce cas on ne fera qu'un acc�s en �criture, et pas en lecture!*/
    if (i==0) {
      Premierpid = fork_redirections(cmds[i], 0, NULL, pipelines[i], i);
      /*On ajoute le job -> il sera le groupe de pid*/
      jobs_addjob(Premierpid, (bg == 1? BG : FG), *cmds[0]);
    }
    /*Si la commande en attente d'ex�cution est la derni�re, dans ce cas on ne fera qu'un acc�s en lecture, et pas en �criture!*/
    else if (i == (nbcmd - 1)) {
      pid = fork_redirections(cmds[i], Premierpid, pipelines[i-1], NULL, i);
      /*On ajoute le job au groupe pr�c�demment �tabli*/
      jobs_addjob(pid, (bg == 1? BG : FG), *cmds[i]);
    }
    /*Si l'on se trouve en position interm�diaire entre les deux commandes pr�c�dentes, on fera un acc�s en lecture mais aussi en �criture!*/
    else {
      pid = fork_redirections(cmds[i], Premierpid, pipelines[i - 1], pipelines[i], i);
      /*On ajoute le job au groupe pr�c�demment �tabli*/
      jobs_addjob(pid, (bg == 1? BG : FG), *cmds[i]);
    }
    
  }
  
  /*Si l'ensemble des commandes est � ex�cuter en premier plan, alors on ex�cute la fonction waitfg sur le groupe de pid*/
  if (bg == 0)
    waitfg(Premierpid);

  /*On fermera tous les pipes ici*/
  for (i = 0; i<nbcmd; i++) {
    close(pipelines[i][ENTREE]);
    close(pipelines[i][SORTIE]);
  }

  /*Si activation du mode 'verbose', alors on d�clare � l'utilisateur que nous allons quitter la fonction do_pipe*/
  if (verbose)
    printf("Pipe exiting\n");

  return;

}

/*

  Concernant le pipe pour 2 processus (g�r� dans le fils)

	pid_t pid;
	int fd[2];

	if (verbose)
	  printf("Pipe entering\n");
	
	Assure pipe is not null
	
	assert(pipe(fd) == 0);
	
	Execvp of the 1rst command
	
	switch (pid = fork()) {
	case -1:
	  perror("Fork ERROR\n");
	  exit(EXIT_FAILURE);
	case 0:
	  close(fd[0]);
	  dup2(fd[1], STDOUT_FILENO);
	  close(fd[1]);
	  execvp(cmds[0][0], cmds[0]);
	  
	  execvp not run
	  
	  if (verbose) printf("execvp for %s impossible by %d", cmds[0][0], pid);
	  exit(EXIT_FAILURE);
	default:
	  break;
	}
	
	Execvp of the 2nd command
	
	switch (pid = fork()) {
	case -1:
	  perror("Fork ERROR\n");
	  exit(EXIT_FAILURE);
	case 0:
	  close(fd[1]);
	  dup2(fd[0], STDIN_FILENO);
	  close(fd[0]);
	  execvp(cmds[1][0], cmds[1]);
	  if (verbose) printf("execvp for %s impossible by %d", cmds[0][0], pid);
	  exit(EXIT_FAILURE);
	default:
	  break;
	}
	
	Finish the job of the pipe -> close all & wait
	
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	
	if (verbose)
	  printf("Pipe exiting\n");
	
	return;
*/
