#ifndef TLB_H
#define TLB_H

struct tlb_entry_s {
  unsigned unused: 8;
  unsigned virt_page: 12;
  unsigned phys_page: 8;
  unsigned x_access: 1;
  unsigned w_access: 1;
  unsigned r_access: 1;
  unsigned is_active: 1;
};


#endif
