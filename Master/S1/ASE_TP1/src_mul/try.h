#ifndef TRY
#define TRY

#define MAGIC_NUMBER 0xDEADBEEF

/*Fonction prenant un entier en paramètre, et renvoyant un entier*/
typedef int (func_t)(int);

/*ctx_s: structure mémorisant un contexte
@param ctx_ebp: pointeur mémorisant le contenu du registre ebp
@param ctx_esp: pointeur mémorisant le contenu du registre esp
@param ctx_magic_number: entier (4 octets) permettant de remarquer s'il y a eu corruption mémoire ou non*/
struct ctx_s {
	void* ctx_ebp;
	void* ctx_esp;
	unsigned int ctx_magic_number;
};

/*
try: fonction permettant de mémoriser un contexte
@param *p_ctx: pointeur de structure ctx_s
@param *f: pointeur de fonction
@param arg: entier valant l'argument à prendre en compte dans la fonction f
@return Valeur retournée par la fonction f, prenant en paramètre arg
*/
int try(struct ctx_s *p_ctx, func_t *f, int arg);

/*
throw: fonction permettant de retourner à un contexte, précédemment mémorisé
@param *p_ctx: pointeur de structure ctx_s
@param val: entier retourné par l'invocation de la fonction au travers de la fonction try()
@return Le paramètre val
*/
int throw(struct ctx_s *p_ctx, int val);

#endif