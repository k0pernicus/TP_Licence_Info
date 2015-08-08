#include <stdio.h>
#include <stdlib.h>

#include "../include/hardware.h"
#include "../include/mi_syscall.h"

int sum(void *ptr)
{
  int i;
  int sum = 0;

  for(i = 0; i < PAGE_SIZE * N/2 ; i++)
    sum += ((char*)ptr)[i];

  return sum;
}
