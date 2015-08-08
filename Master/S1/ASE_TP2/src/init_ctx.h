#ifndef INIT_CTX

#define INIT_CTX

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
*/
enum state_e { CTX_INIT, CTX_ACTIVATED };

/*
Définition de la structure ctx_s, nous servant à mémoriser un contexte d'exécution
@param ctx_magic Champ permettant de stocker un entier définitif, permettant au développeur de se rendre compte d'une corruption mémoire
@param ctx_ebp Champ permettant de stocker le pointeur de base de pile
@param ctx_esp Champ permettant de stocker le pointeur de sommet de pile
@param ctx_func Champ permettant de stocker la fonction exécutée pour un contexte
@param ctx_args Champ permettant de stocker tous les arguments de la fonction contenue dans le champ ctx_func
@param ctx_ptr_malloc Champ permettant de stocker l'adresse rendue par le malloc sauvant une pile d'exécution
*/
struct ctx_s
{
	unsigned int ctx_magic;
	void* ctx_ebp;
	void* ctx_esp;
	func_t *ctx_func;
	void* ctx_args;
	void* ctx_ptr_malloc;
	enum state_e state;
};

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

#endif