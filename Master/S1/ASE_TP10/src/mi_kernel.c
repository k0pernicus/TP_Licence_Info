#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/mi_syscall.h"
#include "../include/hardware.h"
#include "../include/tlb.h"
#include "../include/swap.h"

/*
Fonction permettant de convertir une adresse virtuelle en adresse physique
*/
#define VPAGE_OF_VADD(vaddr) ((vaddr >> 12) & 0xfff)

/*
Processus courant
*/
int current_process;

/*
Fichier de swap
*/
FILE* swap_file;

/*
Table permettant de retrouver pour toute page virtuelle la page physique associée
*/
struct vm_s vm_mapping[VM_PAGES];

/*
Table permettant de retrouver pour toute page physique la page virtuelle associée
*/
struct pm_s pm_mapping[PM_PAGES];

/*
Page virtuelle courante
*/
int vpage_courante = -1;

/*
Page physique courante - sera écrasée à chaque défault sur la table de page physique
*/
int ppage_courante = 1;

/*
TLB
*/
struct tlb_entry_s tlb;

void mmuhandler(void) {

  /*
  fault permettra de recueillir l'adresse de la page, en vue de la vérifier
  */
  unsigned int fault, ppage, vpage;

  struct vm_s vm;

  struct pm_s pm;

  /*
  Récupération de l'adresse virtuelle
  */
  fault = _in(MMU_FAULT_ADDR);

  /*
  Récupération de la page physique
  */
  ppage = ppage_of_vaddr(current_process, fault);

  /*
  Récupération de la page virtuelle : 12 bits de l'adresse virtuelle
  */
  vpage = (fault >> 12) & 0xFF;

  /*
  Vérification que l'adresse obtenue par FAULT est correcte
  */
  assert((fault > (unsigned int) virtual_memory) && (fault < (unsigned int) ((unsigned int)virtual_memory + VM_SIZE - 1)));

  /*
  Sauvegarde de la structure vm_s donnée par VPAGE_OF_VADD(default_page)
  */
  vm = vm_mapping[VPAGE_OF_VADD(fault)];

  /*
  Si la structure virtuelle est mappée, on modifie la page physique de la TLB ainsi que la page virtuelle, avant de la sauver
  */
  if (vm.mappee) {
    tlb.phys_page = vm.ppage;
    tlb.virt_page = vpage;
    _out(TLB_ADD_ENTRY, *(int*)&tlb);
    return;
  }

  /*
  Sauvegarde de la structure pm_s donnée par victime_rr
  */
  pm = pm_mapping[ppage_courante];

  /*
  Si la structure physique est mappée, on stocke la page virtuelle contenue dans la structure pm, on modifie la tlb et on la stock
  */
  if (pm.mappee) {
    store_to_swap(pm.vpage, ppage_courante);
    pm.mappee = 0;
    vm_mapping[pm.vpage].mappee = 0;
    tlb.virt_page = pm.vpage;
    _out(TLB_DEL_ENTRY, *(int*)&tlb);
  }

  /*
  Lecture dans le fichier de swap de la page virtuelle de numéro VPAGE_OF_VADD(fault), et en écrit le contenu dans la page physique ppage_courante
  */
  fetch_from_swap(VPAGE_OF_VADD(fault), ppage_courante);

  /*
  On map la structure de la page physique, et l'on modifie le numéro de la page virtuelle associée
  */
  pm.mappee = 1;

  pm.vpage = VPAGE_OF_VADD(fault);

  vm.mappee = 1;

  vm.ppage = ppage_courante;

  /*
  Modification de la tlb
  */
  tlb.phys_page = ppage_courante;
  tlb.virt_page = VPAGE_OF_VADD(fault);
  tlb.x_access = 1;
  tlb.w_access = 0;
  tlb.r_access = 1;
  tlb.is_active = 1;

  /*
  Sauvegarde de la tlb
  */
  _out(TLB_ADD_ENTRY, *(int*)&tlb);

  /*
  On modifie la page physique courante : +1 avec modulo sur 255 pages
  */
  ppage_courante = (ppage_courante % PM_PAGES) + 1;

}

void mmuhandler_simple(void) {

  /*
  La page virtuelle courante existe-t-elle...?
  Mystère-mystère!
  */
  assert(vpage_courante != -1);

  /*
  On vérifie que la page courante est bien contenue dans le bloc de mémoire virtuelle
  */
  if ((vpage_courante < (unsigned int) virtual_memory) || (vpage_courante > (int) ((unsigned int)virtual_memory + (N/2) * PAGE_SIZE - 1))) {
    printf("La page courante n'est pas contenue entre virtual_memory et (virtual_memory + (N/2) * PAGE_SIZE - 1)\n");
    return;
  }

  /*
  On sauvegarde la page courage dans le fichier swap
  */
  store_to_swap(vpage_courante, 1);

  /*
  Suppression de l'entrée dans TLB
  */
  _out(TLB_DEL_ENTRY, *(int*)&tlb);

  /*
  Disparition du lien VM/PM
  */

  /*
  On charge la page correspondante à l'adresse fautive - page de mémoire physique numéro 1 (car 0 -> contient le vecteur d'interruptions)
  */
  fetch_from_swap(_in(MMU_FAULT_ADDR), 1);

  /*
  On ajoute cette page à la TLB
  */
  _out(TLB_ADD_ENTRY, *(int*)&tlb);

  /*
  RODRIGUEEEZ!
  */
}

int ppage_of_vaddr(int process, unsigned vaddr){
  /*test preliminaire*/
  if((vaddr < (int) virtual_memory) ||( vaddr > ((int)virtual_memory+(N/2)*PAGE_SIZE-1))){
    return -1;
  }

  return (VPAGE_OF_VADD(vaddr) + (process *N/2) +1);

}

char init_swap(const char* path) {
  /*
  Ouverture du fichier en mode w+ -> troncature du fichier à chaque fois, ce qui effacera le contenu du fichier swap
  */
  swap_file = fopen(path, "w+");

  /*
  On vérifie si le fichier a bien été ouvert
  */
  assert(swap_file != NULL);

  return 0;

}

char store_to_swap(int vpage, int ppage) {

  /*
  Positionnement au niveau de vpage afin d'ajouter la valeur contenue dans vpage (à une position donnée), dans le swap à la même position
  */
  if (fseek(swap_file, vpage * PAGE_SIZE, SEEK_SET) == -1)
    return -1;

  /*
  Ecriture de la page physique (de taille PAGE_SIZE) dans le fichier swap_file, à la position (ppage * PAGE_SIZE)
  */
  if (fwrite((char*)physical_memory + (ppage * PAGE_SIZE), sizeof(char), PAGE_SIZE, swap_file) < PAGE_SIZE)
    return -1;

  return 0;

}

char fetch_from_swap(int vpage, int ppage) {
  /*
  Positionnement au niveau de vpage afin de lire la valeur contenue dans le swap à la position de vpage
  */
  if (fseek(swap_file, vpage * PAGE_SIZE, SEEK_SET) == -1)
    return -1;

  /*
  Lecture de la page virtuelle contenue dans swap_file, et écriture dans la page physique à la position (ppage * PAGE_SIZE)
  */
  if (fread((char*)physical_memory + (ppage * PAGE_SIZE), sizeof(char), PAGE_SIZE, swap_file) < PAGE_SIZE)
    return -1;

  return 0;

}
