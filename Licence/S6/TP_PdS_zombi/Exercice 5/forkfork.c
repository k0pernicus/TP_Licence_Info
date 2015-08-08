#include "forkfork.h"

/*Fonction forkfork
Permet la création de 2 processus fils pour un père - le but étant de faire exécuter une fonction quelconque par le processus 'petit-fils', en tuant le processus 'fils', afin que INIT ne le récupère - le processus père doit toujours fonctionner*/

void forkfork(func_t f, void *arg) {

  /*2 pid -> Le fils et le père*/
  pid_t pidP;
  pid_t pidF;

  /*1er fork -> Création du fils*/
  pidP = fork();

  /*On switch sur le pid créé par le 1er fork()*/
  switch(pidP) {
    /*Si erreur -> perror(), on s'arrête*/
  case -1:
    perror("No pid\n");
    exit(EXIT_FAILURE);
    /*Si succès (pid du fils), on crée un nouveau processus (petit-fils) et on termine le processus-fils*/
  case 0:
    printf("Je suis le fils %d\n",getpid());
    pidF = fork();
    /*On switch sur le pid du petit-fils*/
    switch(pidF) {
    /*Si erreur -> perror(), on s'arrête*/
    case -1:
      perror("No pid\n");
      exit(EXIT_FAILURE);
      /*On atteint le petit-fils, on exécute alors la fonction donnée en paramètre avant un EXIT_SUCCESS*/
    case 0:
      printf("Je suis le petit-fils %d, fils de %d\n",getpid(), getppid());
      printf("J'exécute la fonction FACTORIELLE, et j'obtiens...");
      f(arg);
      printf("Maintenant, je suis devenu le fils de %d\n",getppid());
      exit(EXIT_SUCCESS);
      /*On s'arrête*/
    default:
      exit(EXIT_SUCCESS);
    };
    /*Si on se trouve dans le père, on attend la fin du processus fils*/
  default:
    /*On fait travailler le père pendant un peu plus de 4 secondes, afin de montrer qu'il est toujours 'vivant' après l'exécution du programme par le petit-fils (et son rattachement à init)*/
    printf("Je suis le père %d de %d\n",getpid(), pidP);
    sleep(6);
    printf("Je suis le processus %d, et je suis toujours vivant!!\n", getpid());
    wait(NULL);
    break;
  };
  
}

/*Fonction factorielle -> exécute une factorielle, selon un nombre lui ayant été donné en paramètre*/
void factorielle(void* nombre) {

  int res;

  int nbre;

  nbre = atoi(nombre);

  res = 1;

  while (nbre != 1) {
    res = res * nbre;
    nbre--;
  }

  sleep(3);

  printf("%d\n", res);

}

/*Main de forkfork*/
int main(int argc, char* argv[]) {

  void* nombre;

  nombre = argv[1];

  forkfork(&factorielle, nombre);

  return 0;

}
