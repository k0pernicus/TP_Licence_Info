#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "init_ctx.h"

int init_ctx(struct ctx_s *ctx, int stack_size, func_t f, void *args) {

	//Malloc de la pile d'exécution, vérification que tout se passe bien
	assert(ctx->ctx_ptr_malloc = malloc(stack_size));

	//assert OK

	//Stockage du "nombre magique"
	ctx->ctx_magic = MAGIC_NUMBER;

	//Stockage d'un pointeur sur la fonction f
	ctx->ctx_func = f;

	//Stockage d'un pointeur sur les arguments de la fonction f
	ctx->ctx_args = args;

	//Stockage du pointeur de base de pile, du pointeur de sommet de pile (même adresse que celui de base de pile)
	ctx->ctx_ebp = ctx->ctx_esp = (char *)ctx->ctx_ptr_malloc + stack_size - sizeof(void*);

	ctx->state = CTX_INIT;

	return 0;
}