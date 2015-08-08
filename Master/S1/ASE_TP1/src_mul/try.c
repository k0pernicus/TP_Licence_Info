#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "try.h"

int try(struct ctx_s *p_ctx, func_t *f, int arg) {

	/*
	Initialisation du champ magic_number -> entier (4 octets) permettant de voir s'il y a eu corruption mémoire
	*/
	p_ctx->ctx_magic_number = MAGIC_NUMBER;

	/*Morceau d'assembleur permettant de récupérer les valeurs détenues dans les registres 32 bits du processeur esp et ebp, afin de pouvoir mémoriser
	  où l'on se trouvait précédemment*/


	/*
	Sauvegarde de esp
	*/
	asm("mov %%esp, %0"
		:"=r"(p_ctx->ctx_esp));

	/*
	Sauvegarde de ebp
	*/
	asm("mov %%ebp, %0"
		:"=r"(p_ctx->ctx_ebp));

	/*Fin de la récupération des adresses, pointées par les registres*/

	/*On retourne le résultat de la fonction f, avec le paramètre arg*/
	return f(arg);

}

int throw(struct ctx_s *p_ctx, int val) {

	static int val_value = 0;

	val_value = val;

	/*Vérification de la bonne conformation du champ magic_number (DEADBEEF initialement)*/
	assert(p_ctx->ctx_magic_number == MAGIC_NUMBER);

	/*Morceau d'assembleur permettant d'envoyer dans les registres esp et ebp les adresses précédemment enregistrées dans la structure prise en paramètre
	*/

	/*
	Restauration dans esp
	*/
	asm("mov %0, %%esp"
		::"r"(p_ctx->ctx_esp));

	/*
	Restauration dans ebp
	*/
	asm("mov %0, %%ebp"
		::"r"(p_ctx->ctx_ebp));

	/*Fin de la restauration des registres*/

	/*On retourne l'entier val*/
	return val_value;

}