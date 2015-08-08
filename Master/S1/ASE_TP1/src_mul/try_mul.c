#include <stdio.h>
#include <stdlib.h>
#include "try.h"

static struct ctx_s struct_contexte;

static int mul(int depth){

	int i;

	switch(scanf("%d", &i)){
		case EOF:
			return 1;
		case 0:
			return mul(depth + 1);
		case 1:
			if (i)
				return i*mul(depth + 1);
			else
				throw(&struct_contexte, 0);
	}

	return 0;

}

int main() {

	int product;

	product = 0;

	printf("**Début du programme**\n");

	product = try(&struct_contexte, mul, 5);

	/*
	Si EOF (Ctrl+D) -> retourne le produit
	Si 0 -> retourne l'adresse pointée par main
	*/

	printf("**Fin du programme, product = %d**\n", product);

	return 0;

}