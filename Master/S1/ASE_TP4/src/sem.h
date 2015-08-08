#ifndef CTX

#define CTX

#define MAGIC_NUMBER 0xDEADBEEF

/*
Définition du type func_t
@param param Un paramètre de type void*
*/
typedef void (func_t) (void* param);

/*
Enumération de l'état de la structure sauvant le contexte d'exécution
@enum CTX_INIT Enum permettant de décrire que le contexte vient d'être initialisé - la fonction prise en compte dans le contexte n'a donc pas encore été appelée!
@enum CTX_ACTIVATED Enum permettant de décrire que le contexte est activé
@enum CTX_TERMINATED Enum permettant de décrire que le contexte est terminé
@enum CTX_BLOCKED Enum permettant de décrire que le contexte est bloqué dans un sémaphore
*/
enum state_e { CTX_INIT, CTX_ACTIVATED, CTX_TERMINATED, CTX_BLOCKED };

/*
Définition de la structure ctx_s, nous servant à mémoriser un contexte d'exécution
@param ctx_magic Champ permettant de stocker un entier définitif, permettant au développeur de se rendre compte d'une corruption mémoire
@param ctx_ebp Champ permettant de stocker le pointeur de base de pile
@param ctx_esp Champ permettant de stocker le pointeur de sommet de pile
@param ctx_func Champ permettant de stocker la fonction exécutée pour un contexte
@param ctx_args Champ permettant de stocker tous les arguments de la fonction contenue dans le champ ctx_func
@param ctx_ptr_malloc Champ permettant de stocker l'adresse rendue par le malloc sauvant une pile d'exécution
@param ctx_state Champ permettant de stocker l'état du contexte (voir l'énumération state_e)
@param ctx_next Champ permettant de stocker le prochain contexte à activer
@param ctx_blocked_next Champ permettant de stocker le prochain contexte bloqué
*/
struct ctx_s
{
	unsigned int ctx_magic;
	void* ctx_ebp;
	void* ctx_esp;
	func_t *ctx_func;
	void* ctx_args;
	void* ctx_ptr_malloc;
	enum state_e ctx_state;
	struct ctx_s* ctx_next;
	struct ctx_s* ctx_blocked_next;
};

/**
Structure permettant de déclarer un sémaphore
@param sem_cpt Compteur du sémaphore, correspondant au nombre de contextes à prendre en compte dans celui-ci
@param sem_list Liste de contextes bloqués
@param sem_magic_number Entier permettant de vérifier s'il n'y a pas eu corruption mémoire
*/
struct sem_s
{
	int sem_cpt;
	struct ctx_s* sem_list;
	int sem_magic_number;
};

/*
Variable globale permettant de sauver la liste des contextes
*/
static struct ctx_s* ctxs = NULL;

/*
Structure permettant de sauver toutes les informations de la pile d'exécution en cours, à un instant T
*/
static struct ctx_s* struct_reference = NULL;

/*
Fonction permettant d'initialiser un contexte d'exécution
@param *ctx Un pointeur vers une structure de type ctx_s, servant à sauver toutes les informations dans celui-ci
@param stack_size La taille de la pile que l'on veut alouer via le malloc
@param f La fonction à exécuter lors de l'initialisation du contexte
@param args Les arguments à prendre en compte, pour la fonction f
@return 0 si tout s'est bien passé
@return EXIT_FAILURE si le malloc s'est mal passé (voir la fonction C 'assert')
*/
int init_ctx(struct ctx_s *ctx, int stack_size, func_t f, void *args);


/**
Fonction ajoutant l'allocation dynamique de contexte dans une liste pré-établie
Cette fonction se fera en phase:
	1 _ Demande d'allocation mémoire contenant la structure
	2 _ Initialisation de la structure (du contexte)
	3 _ Ajout dans la liste de contextes
@param stack_size Taille de la pile
@param f La fonction donnée, pour une exécution de contexte
@param args Les arguments de la fonction f
*/
int create_ctx(int stack_size, func_t f, void* args);

/**
Cette fonction permettra au contexte courant de passer la main au contexte suivant, pointé par le courant (déterminé par l'ordonnancement)
*/
void yield(void);

/*
Fonction permettant de sauver et restaurer des contextes
@param ctx Pointeur vers une structure de contexte - contexte à restaurer
*/
void switch_to_ctx(struct ctx_s *ctx);

/**
Fonction permettant d'initialiser un sémaphore
@param sem Le sémaphore à initialiser
@param nbr_ctx Le nombre de contextes, ou compteur
*/
void sem_init(struct sem_s* sem, unsigned int nbr_ctx);

/**
Fonction permettant de décrémenter le compteur associé au sémaphore.
Si la valeur du compteur est négative, le contexte appelant se bloque dans la file d'attente (sem_list)
@param sem Le sémaphore à prendre en compte pour la décrémentation du compteur + gestion de la file d'attente
*/
void sem_down(struct sem_s* sem);

/**
Fonction permettant d'incrémenter le compteur associé au sémaphore.
A chaque changement du compteur, un contexte sera réveillé. Son état sera donc 'ACTIVATED', et il sera enlevé de la boucle des contextes endormis dans le sémaphore
@param sem Le sémaphore à prendre en compte pour la décrémentation du compteur + gestion de la file d'attente
*/
void sem_up(struct sem_s* sem);

#endif