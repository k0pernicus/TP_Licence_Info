#ifndef MI_SYSCALL_H
#define MI_SYSCALL_H

/*
Appels systèmes possibles
*/
#define SYSCALL_SWTCH_0 16
#define SYSCALL_SWTCH_1 17

#define MMU_FAULT_ADDR  0xCD
#define TLB_ADD_ENTRY   0xCE
#define TLB_DEL_ENTRY   0xDE

extern int current_process;

extern FILE* swap_file;

extern int vpage_courante;

extern struct tlb_entry_s tlb;

/*
MAITRE
*/

/*
 * correspondance entre une adresse virtuelle vaddr
 * et une page d'addresse physique dans le cas d'un partage
 * de N addresse entre deux processus
 *
 */
int ppage_of_vaddr(int, unsigned int);

/*
 * Handler d'interruptions associé à la MMU, appelé quand l'adresse accédée est fautive
 */
void mmuhandler(void);

/*
 * Handler d'interruptions associé à la MMU, appelé quand l'adresse accédée est fautive
 * Un algorithme est utilisé ici si l'adresse accédée est fautive
 * 1 _ On sauvegarde la page dans le fichier de swap
 * 2 _ On supprime le mapping dans la TLB pour cette page
 * 3 _ On charge la page correspondant à l'adresse fautive
 * 4 _ On met à jour la TLB en conséquence
 */
void mmuhandler_simple(void);

/*
 * Fonction permettant d'ouvrir le fichier utilisé comme swap
 * Retourne -1 en cas d'échec, 0 en cas de succès
 */
char init_swap(const char*);

/*
 * Fonction permettant de stocker dans le fichier de swap la page virtuelle de numéro vpage, dont le contenu est actuellement stocké dans la page physique ppage
 * Param : 1 - le premier paramètre contient le numéro de page virtuelle
 * Param : 2 - le second paramètre contient le numéro de page physique
 * Retourne -1 en cas d'échec, 0 en cas de succès
 */
char store_to_swap(int, int);

/*
 * Fonction permettant de lire dans le fichier de swap la page virtuelle de numéro vpage, et en écrit le contenu dans la page physique ppage
 * Retourne -1 en cas d'échec, 0 en cas de succès
 */
char fetch_from_swap(int, int);

/*
UTILISATEUR
*/

/*
 * Fonction permettant de faire la somme du contenu du pointeur prit en paramètre
 */
int sum(void*);

#endif
