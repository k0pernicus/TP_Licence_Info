#ifndef MI_SYSCALL_H
#define MI_SYSCALL_H

/*
Appels systèmes possibles
*/
#define SYSCALL_SWTCH_0 16
#define SYSCALL_SWTCH_1 17

#define MMU_FAULT_ADDR  0xCD
#define TLB_ADD_ENTRY   0xCE

extern int current_process;

/*
MAITRE
*/

/*
 * correspondance entre une adresse virtuelle vaddr
 * et une page d'addresse physique dans le cas d'un partage
 * de N addresse entre deux processus
 *
*/
int ppage_of_vaddr(int process, unsigned vaddr);

/*
Met en oeuvre un mapping N/2 selon lequel deux processus peuvent se partager un espace d'adressage virtuel
Lorsqu'une faute se produit, on ajoute une nouvelle entrée correspondant à la page accédée - erreur de segmentation levée sinon.
*/
void mmuhandler(void);

/*
UTILISATEUR
*/
int sum(void*);


#endif
