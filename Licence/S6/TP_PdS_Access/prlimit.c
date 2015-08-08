#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int prlimit(void) {

  printf("NAME_MAX: %d octets\n", NAME_MAX);
  printf("PATH_MAX: %d octets\n", PATH_MAX);

  return 0;
}

int main(void) {

  prlimit();

  return 0;
  
}
