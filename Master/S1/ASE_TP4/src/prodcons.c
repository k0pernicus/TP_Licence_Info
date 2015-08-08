#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sem.h"
#include "start_schedule.h"

/*
N représente le nombre de places dans le tampon
*/
#define N 100

/*
Énumération représentation l'état de l'objet (produit, utilisé)
*/
enum usage_value_object {PRODUCING_OBJECT, USING_OBJECT};

/*
Structure représentant un objet quelconque, produit par la producteur et consommé par le consommateur
*/
struct object_s {
	enum usage_value_object object_state;
};

typedef struct object_s object_t;

/*
Définition des structures de sémaphores:
	-mutex: contrôle d'accès au tampon
	-empty: nombre de contextes libres
	-full: nombre de contextes bloqués
*/
struct sem_s mutex, empty, full;

/*
Entier permettant de comptabiliser le nombre d'objets produits / consommés
*/
int nb_objects_in_list = 0;

/*
Fonction permettant de déclarer un objet comme produit
*/
void produce_object(object_t *object) {
	object -> object_state = PRODUCING_OBJECT;
	return;
}

/*
Fonction permettant de mettre un objet dans une liste d'objets produits
*/
void push_object(void) {
	assert((nb_objects_in_list++) <= N);
}

/*
Fonction permettant de retirer un objet d'une liste d'objets produits
*/
void pull_object(void) {
	/*
	On décrémente le nombre d'objets dans la liste d'objets produits
	*/
	assert((nb_objects_in_list--) >= 0);
}

/*
Fonction permettant de déclarer un objet comme utilisé
*/
void use_object(object_t *object) {
	object -> object_state = USING_OBJECT;
	return;
}

/*
Fonction représentant un producteur
*/
void producer(void){

	object_t object;

	int i = 0;

	while(1) {
		printf("producer: %d / %d\n", nb_objects_in_list, N);
		produce_object(&object);
		sem_down(&empty);
		sem_down(&mutex);
		push_object();
		sem_up(&mutex);
		sem_up(&full);
	}

	return;

}

/*
Fonction représentant un consommateur
*/
void consumer(void){

	object_t object;

	while(1) {
		printf("consumer: %d / %d\n", nb_objects_in_list, N);
		sem_down(&full);
		sem_down(&mutex);
		pull_object();
		sem_up(&mutex);
		sem_up(&empty);
		use_object(&object);
	}

	return;

}

void main(void){

	/*
	Initialisation des structures de sémaphore
	*/
	sem_init(&mutex, 1);
	sem_init(&empty, N);
	sem_init(&full, 0);

	/*
	Création des contextes
	*/
	create_ctx(16384, &producer, NULL);
	create_ctx(16384, &consumer, NULL);

	start_sched();

	exit(EXIT_SUCCESS);

}