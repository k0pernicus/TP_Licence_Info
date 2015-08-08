#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>

int tail(char* pathname, int nb) {
  int cpt;
  int filesrc;
  char caracterelu[1];
  int nchar;
  cpt=0;
  filesrc = open(pathname, O_RDONLY);

  while ( (nchar=read(filesrc, caracterelu, 1)) ) {
    if (caracterelu[0]=='\n') cpt++;
  }

  lseek(filesrc, 0, SEEK_SET);
  /*lignes pour tester que le lseek renvoie bien en debut de fichier*/
  /* read(filesrc, caracterelu, 1);
     printf("%c\n", caracterelu[0]);*/
 
  /*on reavance de n lignes*/
  while (cpt>nb) {
    read(filesrc, caracterelu, 1);
    if (caracterelu[0]=='\n') cpt--;
  }

  /* il reste les n lignes*/
  while( (nchar=read(filesrc, caracterelu, 1)) ) {
    printf("%c", caracterelu[0]);
  }
  return 0;

}


int main (int argc, char* argv[]) {
  if (argc==3) {
    tail(argv[1], atoi(argv[2]));
    return 1;
  }
  else
    {
      tail(argv[1], 10);
      return 0;
    }
}
