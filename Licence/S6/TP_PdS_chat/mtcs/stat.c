#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "tools.h"
#include "config.h"
#include "stat.h"

/*Déclaration d'un tableau de structure de client_t*/
static struct client_t *tab[MAX_CONNECTION];
static int cpt = 0;

/*Fonction permettant d'initialiser le tableau de client_t*/
void init_tab() {
    int i;
    for (i = 0; i<MAX_CONNECTION; i++)
        tab[i] = (struct client_t*)malloc(sizeof(int));
    return;
}

/*Fonction permettant d'ajouter un client dans le tableau de client_t
fd -> L'identifiant client*/
void add_client(int fd) {
    static struct client_t *client;
    client = (struct client_t*)malloc(sizeof(struct client_t));
    tab[cpt] = client;
    tab[cpt] -> id_client = fd;
    tab[cpt] -> nb_lignesRecues_client = 0;
    tab[cpt] -> nb_lignesEnvoyees_client = 0;
    tab[cpt] -> activite = 1;
    cpt++;
    return;
}

/*Fonction permettant de supprimer un client dans le tableau de client_t
fd -> L'identifiant client
*/
void del_client(int fd) {
    int i;
    for (i = 0; i<cpt;i++)
      if ((tab[i] -> id_client) == fd)
            tab[i] -> activite = 0;
    return;
}

/*Fonction permettant d'incrémenter le nombre de lignes envoyées et/ou reçues par client
fd -> L'identifiant client
*/
void incr_msg_client(int fd) {
    int i;
    for (i = 0; i<cpt;i++) {
        if (tab[i]->activite == 1)
            tab[i]->nb_lignesRecues_client += 1;
        if (tab[i]->id_client == fd)
            tab[i]->nb_lignesEnvoyees_client += 1;
    }
    return;
}

/*Fonction permettant l'affichage des statistiques sur le serveur*/
void display_stat() {
    int i;
    
    /*Message d'entrée*/
    printf("Affichage des statistiques\n");
    
    /*Affichage des statistiques générales*/
    printf("\nStatistiques générales - serveur\n\n");
    printf("Nombre de clients connectés actuellement: %d\n", statistiques.nb_clients - 1);
    printf("Nombre de clients qui se sont connectés: %d\n", statistiques.nb_max_clients - 1);
    printf("Nombre de lignes reçues - pour tous clients: %d\n",statistiques.nb_lignes_reception);
    printf("Nombre de lignes envoyées - pour tous clients: %d\n", statistiques.nb_lignes_envoie);
    
    /*Affichage des statistiques par client*/
    printf("\nStatistiques par client\n\n");
    for (i = 0; i<cpt - 1; i++) {
      printf("Client numéro %d ", tab[i]->id_client);
      if (tab[i]->activite == 1) printf("connecté");
      else printf("non-connecté");
        printf(" - envoie de %d messages - reçu %d messages\n", tab[i]->nb_lignesEnvoyees_client, tab[i]->nb_lignesRecues_client);
    }
    printf("\n");
    return;
}
