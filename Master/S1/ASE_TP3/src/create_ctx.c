#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "create_ctx.h"
#include "hw.h"

int create_ctx(int stack_size, func_t f, void* args) {

	irq_disable();

	//Allocation de mémoire pour stocker un nouveau contexte -> MALLOC RÉSERVERA UN ESPACE MÉMOIRE DE TAILLE sizeof(struct ctx_s)
	struct ctx_s* ctx_new = malloc(sizeof(struct ctx_s));

	assert(ctx_new);

	//Initialisation du nouveau contexte
	init_ctx(ctx_new, stack_size, f, args);

	//Ajout dans la liste de contextes

	//Si la liste de contextes existe, on ajoute alors ce nouveau contexte (ctx_new) dans le contexte suivant la liste de contextes
	if (ctxs) {
		ctx_new -> ctx_next = ctxs -> ctx_next;
		ctxs -> ctx_next = ctx_new;
	}
	//Si la liste de contextes n'existe pas, ce contexte est alors le premier dans la liste de contexte -> on pointe sur lui!!
	else {
		ctxs = ctx_new;
		ctxs -> ctx_next = ctx_new;
	}

	irq_enable();

	return 0;

}

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

	ctx->ctx_state = CTX_INIT;

	return 0;
}

void yield(void) {

	//Isolation de la section critique de code
	irq_disable();

	//Si la structure courante existe, on va switcher sur un suivant qui n'est pas terminé
	if (struct_reference) {
		struct ctx_s* tmp;
		//On va chercher le prochain contexte non-terminé, ne pointant pas sur nous-mêmes
		while (struct_reference -> ctx_next -> ctx_state == CTX_TERMINATED && struct_reference -> ctx_next != struct_reference) {
			tmp = struct_reference -> ctx_next;
			struct_reference -> ctx_next = struct_reference -> ctx_next -> ctx_next;
			free(tmp -> ctx_ptr_malloc);
			free(tmp);
		}
		//Switch_to sur le prochain contexte s'il n'est pas encore terminé
		if (struct_reference -> ctx_next -> ctx_state != CTX_TERMINATED) {
			switch_to_ctx(struct_reference -> ctx_next);
		}
		//Sinon, on pointe sur soi -> EXIT
		else {
			exit(EXIT_SUCCESS);
		}
	}
	//Si la structure courante n'existe pas, on switch directement sur le contexte pointé dans la pile ctxs
	else {
		if (ctxs != NULL) {
			switch_to_ctx(ctxs);
		}
	}

}

void switch_to_ctx(struct ctx_s *ctx) {

	//Vérification - struct_reference est-il initialisé?
	if(struct_reference) {

		/*
		==============================
		SAUVEGARDE DU CONTEXTE COURANT
		==============================
		*/

		asm("mov %%esp, %0"
			:"=r"(struct_reference->ctx_esp));

		asm("mov %%ebp, %0"
			:"=r"(struct_reference->ctx_ebp));

	}

	/*
	======================
	CHANGEMENT DE CONTEXTE
	======================
	*/
	struct_reference = ctx;

	assert(struct_reference->ctx_state != CTX_TERMINATED);

	assert(struct_reference->ctx_magic == MAGIC_NUMBER);

	/*
	============
	RESTAURATION
	============
	*/

	/*
	Restauration des registres
	*/
	asm("mov %0, %%esp"
		::"r"(struct_reference->ctx_esp));
	
	asm("mov %0, %%ebp"
		::"r"(struct_reference->ctx_ebp));

	/*
	Déclenchement des actions, en fonction de l'état du contexte
	*/
	switch(struct_reference->ctx_state) {

		/*Contexte initialisé*/
		case CTX_INIT:
			//Activation du contexte
			struct_reference->ctx_state = CTX_ACTIVATED;
			//Activation
			irq_enable();
			//Exécution de la fonction f
			(struct_reference->ctx_func)(struct_reference->ctx_args);
			//Après l'exécution de la fin par le contexte, on le nomme comme terminé
			struct_reference->ctx_state = CTX_TERMINATED;
			//Switch de contexte
			yield();
			assert(0);
		default:
			irq_enable();
			return;

	}
	exit(EXIT_FAILURE);

}