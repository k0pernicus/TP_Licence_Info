#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define NUMBER_COUNT 5000000

/*Fonction allant compter de 0 à une variable number, donnée en paramètre*/
int count(int number) {

  int i, j;
  j = 0;

  for (i = 0; i<number; i++) {
    j+=1;
  }

  return 0;

}

/*Fonction race; ce programme va créé dix fils, chacun des fils compte jusqu'à 5 millions, affiche un message, et compte de nouveau jusqu'à 5 millions.
On attend après la fin des processus (des 10 fils) et on affiche l'ordre d'arrivée des fils à la fin.*/
void race(int numberProc) {

  int j;
 
  j = 0;

  printf("\n");

  for(j = 0;j<10;j++) {
    switch (fork()) {
    case -1:
      printf("Erreur dans %d", getpid());
      perror("fork");
      exit(EXIT_FAILURE);
    case 0:
      count(NUMBER_COUNT);
      printf("Je suis %d, j'ai compté jusque %d, et je vais recompter... ", getpid(), NUMBER_COUNT);
      count(NUMBER_COUNT);
      printf("%d a fini de compter!\n", getpid());
      exit(EXIT_SUCCESS);
    default:
      break;
    }
  }

  for (j = 0;j<10;j++) {
    wait(NULL);
  }
}

/*Main de race*/
int main(void) {

  race(10);

  return 0;

}
