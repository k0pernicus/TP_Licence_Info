#include <stdio.h>
#include <stdlib.h>

static int hello_out = 2;

int f(int a) {

	void* esp_dis;
	void* ebp_dis;

	/*Petit code assembleur afin d'afficher la valeur des registres %esp et %ebp de main*/
	asm("mov %%esp, %0"
		:"=r"(esp_dis));

	asm("mov %%ebp, %0"
		:"=r"(ebp_dis));

	printf("\t\t>>>>>Fonction f, à un paramètre entier: a>>>>>\n");

	printf("\t\tesp address: %p\n", esp_dis);
	printf("\t\tebp address: %p\n", ebp_dis);

	printf("\t\t\tAdresse de la variable a = %p\n", &a);

	printf("\t\t<<<<<Fonction f<<<<<\n");
	
	return 0;

}

int g(int b, int c) {

	void* esp_dis;
	void* ebp_dis;

	/*Petit code assembleur afin d'afficher la valeur des registres %esp et %ebp de main*/
	asm("mov %%esp, %0"
		:"=r"(esp_dis));

	asm("mov %%ebp, %0"
		:"=r"(ebp_dis));

	printf("\t\t>>>>>Fonction g, à deux paramètres entiers: b et c>>>>>\n");
	printf("\t\tesp address: %p\n", esp_dis);
	printf("\t\tebp address: %p\n", ebp_dis);

	printf("\t\tCréation de la variable locale entière d\n");

	int d;

	//static int hello_in = 2;

	printf("\t\t\tAdresse de la variable b = %p (prend la place de la variable a, dans la fonction f)\n", &b);
	printf("\t\t\tAdresse de la variable c = %p\n", &c);
	printf("\t\t\tAdresse de la variable d = %p - décalage de 8 octets en plus, car différence de stockage entre les paramètres de fonction, et l'allocation de variable locale dans la pile\n", &d);
	//printf("\t\t\tAdresse de la variable hello_in = %p\n", &hello_in);

	printf("\t\t<<<<<Fonction g<<<<<\n");
	
	return 0;

}

int k(int a, int b, int c) {

	void* esp_dis;
	void* ebp_dis;

	/*Petit code assembleur afin d'afficher la valeur des registres %esp et %ebp de main*/
	asm("mov %%esp, %0"
		:"=r"(esp_dis));

	asm("mov %%ebp, %0"
		:"=r"(ebp_dis));

	printf("\t\t>>>>>Fonction k, à trois paramètres entiers: a, b et c>>>>>\n");
	
	printf("\t\tesp address: %p\n", esp_dis);
	printf("\t\tebp address: %p\n", ebp_dis);

	printf("\tCréation de la variable locale entière: d\n");

	int d;

	printf("\t\tAdresse de la variable a = %p\n", &a);
	printf("\t\tAdresse de la variable b = %p\n", &b);
	printf("\t\tAdresse de la variable c = %p\n", &c);
	printf("\t\tAdresse de la variable d = %p\n", &d);


	f(a);

	g(b, a);

	printf("\t\t<<<<<Fonction k<<<<<\n");
	
	return 0;

}

int main() {

	void* esp_dis;
	void* ebp_dis;

	/*Petit code assembleur afin d'afficher la valeur des registres %esp et %ebp de main*/
	asm("mov %%esp, %0"
		:"=r"(esp_dis));

	asm("mov %%ebp, %0"
		:"=r"(ebp_dis));

	printf("esp address: %p\n", esp_dis);
	printf("ebp address: %p\n", ebp_dis);

	printf("esp_dis address: %p\n", &esp_dis);
	printf("ebp_dis address: %p\n", &ebp_dis);

	int a = 1;
	int b = 2;

	printf("\tAdresse de la variable a = %p\n", &a);
	printf("\tAdresse de la variable b = %p\n", &b);

	//printf("a est 8 octets au dessus de la base de la pile\n");

	printf("\tAdresse de la variable hello_out = %p\n", &hello_out);

	printf("Tiens, ce n'est pas la même adresse hexadécimale sur 4 octets... La pile contient donc les variables locales, mais pas les globales!!\n");

	f(a);

	printf("Création de la variable c...\n");

	int c = 3;

	g(b, c);

	printf("Création de la variable d...\n");

	int d = 4;

	printf("Mais, où sont a, b, c et d dans le main?\n");
	printf("...\n");
	printf("...\n");
	printf("...\n");
	printf("Toujours a la même adresse (pour a, b)! La preuve: \n");

	printf("\tAdresse de la variable a = %p\n", &a);
	printf("\tAdresse de la variable b = %p\n", &b);
	printf("\tAdresse de la variable c = %p : adresse de b - 4 octets\n", &c);
	printf("\tAdresse de la variable d = %p : adresse de c - 4 octets\n", &d);

	k(a, b, c);

	printf("Et l'on remonte...!\n");

	printf("\tAdresse de la variable a = %p\n", &a);
	printf("\tAdresse de la variable b = %p\n", &b);

	printf("Une petite boucle pour finir, afin de montrer que la variable incrémentée reste toujours à la même position dans la pile?\n");

	int i;

	printf("\tAdresse de la variable i (non-initialisée) = %p\n", &i);

	for (i = 0; i < 5; i++) {
		printf("\tAdresse de la variable i à %d = %p\n", i, &i);
		f(i);
	}

	return 0;

}