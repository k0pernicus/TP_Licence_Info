#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "init_ctx.h"
#include "switch_to.h"

void switch_to_ctx(struct ctx_s *ctx) {

	//Vérification - struct_reference est-il initialisé?
	if(!struct_reference)
		struct_reference = ctx;

	assert(struct_reference->ctx_magic == MAGIC_NUMBER);

	/*
	==============================
	SAUVEGARDE DU CONTEXTE COURANT
	==============================
	*/

	asm("mov %%esp, %0"
		:"=r"(struct_reference->ctx_esp));

	asm("mov %%ebp, %0"
		:"=r"(struct_reference->ctx_ebp));

	/*
	======================
	CHANGEMENT DE CONTEXTE
	======================
	*/
	struct_reference = ctx;

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
	switch(struct_reference->state) {

		/*Contexte initialisé*/
		case CTX_INIT:
			//Activation du contexte
			struct_reference->state = CTX_ACTIVATED;
			//Exécution de la fonction f
			(struct_reference->ctx_func)(struct_reference->ctx_args);
			//On boucle indéfiniement
			while(1);
		/*Contexte activé*/
		case CTX_ACTIVATED:
			//On dépile le 'switch_to', si et seulement si le contexte est activé
			return;

	}

}