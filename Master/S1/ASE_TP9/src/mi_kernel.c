#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/mi_syscall.h"
#include "../include/hardware.h"
#include "../include/tlb.h"

int current_process;

#define VPAGE_OF_VADD(vaddr) ((vaddr >> 12) & 0xfff)


void mmuhandler(void) {

  int vaddr = _in(MMU_FAULT_ADDR);

  int ppage;
  struct tlb_entry_s tlb;
  
  if((ppage = ppage_of_vaddr(current_process, vaddr)) == -1)
    exit(EXIT_FAILURE);

  tlb.unused = 0;
  tlb.virt_page = VPAGE_OF_VADD(vaddr);
  tlb.phys_page = ppage;
  tlb.x_access = 1;
  tlb.w_access = 1;
  tlb.r_access = 1;
  tlb.is_active = 1;

  _out(TLB_ADD_ENTRY, *((int*)&tlb));

}


int ppage_of_vaddr(int process, unsigned vaddr){
  /*test preliminaire*/
  if((vaddr < (int) virtual_memory) ||( vaddr > ((int)virtual_memory+(N/2)*PAGE_SIZE-1))){
    return -1;
  }

  return (VPAGE_OF_VADD(vaddr) + (process *N/2) +1);

}
