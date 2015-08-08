#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hardware.h"
#include "../include/mi_syscall.h"

static void
switch_to_process0(void)
{
  current_process = 0;
  _out(MMU_CMD, MMU_RESET);
}

static void
switch_to_process1(void)
{
  current_process = 1;
  _out(MMU_CMD, MMU_RESET);
}

int
main(void)
{
  void* ptr;
  int res;

  if (init_hardware("./etc/hardware.ini") == 0) {
    printf("Initialization hardware : Error...");
    exit(EXIT_FAILURE);
  }

  IRQVECTOR[MMU_IRQ] = mmuhandler;

  IRQVECTOR[SYSCALL_SWTCH_0] = switch_to_process0;
  IRQVECTOR[SYSCALL_SWTCH_1] = switch_to_process1;
  _mask(0x1001);

  ptr = virtual_memory;

  _int(SYSCALL_SWTCH_0);
  memset(ptr, 1, PAGE_SIZE * (N/2));
  
  _int(SYSCALL_SWTCH_1);
  memset(ptr, 3, PAGE_SIZE * (N/2));

  _int(SYSCALL_SWTCH_0);
  res = sum(ptr);
  printf("Resultat du processus 0 : %d\n",res);

  _int(SYSCALL_SWTCH_1);
  res = sum(ptr);
  printf("Resultat du processus 1 : %d\n",res);

  return 1;

}
