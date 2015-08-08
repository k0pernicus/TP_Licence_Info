/* ------------------------------
   $Id: cnct.c,v 1.3 2007/04/04 15:18:50 marquet Exp $
   ------------------------------------------------------------

   mtcs - a multithreaded chat serveur
   Philippe Marquet, Apr 2005

   Gestion de la connexion d'un client par un thread
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

#include "config.h"
#include "tools.h"
#include "cnct.h"
#include "stat.h"

/* Gestion des sockets */
static int sockets[MAX_CONNECTION];
/*Ajout d'un thread global*/
static pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;

/*Typedef pour fonction (void*)*/
typedef void* func_t (void *);

static void
add_socket(int fd)
{
    int i;
    
    pgrs_in();
    
    /*On verrouille l'accès au tableau global*/
    
    pthread_mutex_lock(&verrou);
    
    if (verbose)
        printf("add_so cket: Je viens d'entrer dans un verrou");
    
    for (i=0; i<MAX_CONNECTION; i++) {
      /*Ajout du client (identifiant fd) dans le tableau de clients*/
      add_client(fd);
      /*Incrémentation du nombre de clients dans le tableau statistiques*/
      statistiques.nb_clients++;
      /*Si le nombre de clients vaut plus que le nombre de clients maximums, alors on change sa valeur*/
      if (statistiques.nb_clients > statistiques.nb_max_clients) statistiques.nb_max_clients = statistiques.nb_clients;
      if (sockets[i] == 0) {
	sockets[i] = fd;
	break;
      }
    }

    /*On déverrouille l'accès au tableau global AVANT le assert -> Si le assert plante, l'accès est toujours verrouillé*/
    pthread_mutex_unlock(&verrou);
    
    if (verbose)
      printf("add_socket: Je viens de sortir d'un verrou");
    
    assert(i!=MAX_CONNECTION);
    pgrs_out();
}

static void
del_socket(int fd)
{
  int i;
  
  pgrs_in();
  
  /*On verrouille l'accès au tableau global*/
  pthread_mutex_lock(&verrou);
  if (verbose)
    printf("del_socket: Je viens d'entrer dans un verrou");
  
  for (i=0; i<MAX_CONNECTION; i++) {
    if (sockets[i] == fd) {
      del_client(fd);
      statistiques.nb_clients--;
      sockets[i] = 0;
      break;
    }
  }
  
  /*On déverrouille l'accès au tableau global AVANT le assert -> Si le assert plante, l'accès est toujours verrouillé*/
  pthread_mutex_unlock(&verrou);
  
  if (verbose)
    printf("del_socket: Je viens d'entrer dans un verrou");
    
  assert(i!=MAX_CONNECTION);
  pgrs_out();
}

/* Un client  */
static void
repeater(int sckt)
{
    char buf[MAX_BUFFER];
    int nbc, i;
    const char WELCOME[] = "mtcs : bienvenu\n";

    pgrs_in();
    
    write(sckt, WELCOME, strlen(WELCOME));
  
    pgrs("enregistrement d'une socket");
    add_socket(sckt);
    
    while (1) {
      pgrs("attente read");
    
      nbc = read(sckt, buf, MAX_BUFFER);
        
      if (nbc <= 0) {
        pgrs("fin lecture client");
        pgrs("desenregistrement d'une socket");
        del_socket(sckt);
        close(sckt);
        pgrs_out();
        return;
        }
      pgrs("boucle ecriture");

      /*Verrouillage de l'accès en écriture dans la boucle FOR*/
      pthread_mutex_lock(&verrou);
      for(i=0; i<MAX_CONNECTION; i++)
        if (sockets[i]) {
            write(sockets[i], buf, nbc);
            statistiques.nb_lignes_reception++;
        }
      incr_msg_client(sckt);
        statistiques.nb_lignes_envoie++;
    pthread_mutex_unlock(&verrou);
    /*Déverrouillage de cet accès*/

    pgrs("fin boucle ecriture");
  }
}

void* th_repeater (void* fd) {

  repeater((intptr_t) fd);
  return NULL;

}

/* CrÈation d'un client 
   CrÈation d'un thread exÈcutant la fonction 'repeater', ‡ chaque nouvelle demande de connexion*/
int
manage_cnct(int fd)
{    
  pthread_t threadCree;
  pthread_attr_t tattr;
  int status_tab, status;
    
  intptr_t fd_t = (intptr_t) fd;
  
  assert(sizeof(int) <= sizeof(void *));
  
  if (verbose)
    printf("manage_cnct: Entering\n");
  
  pgrs_in();
  
  /*DÈclaration de la structure contenant les attributs du pthread*/
  status_tab = pthread_attr_init(&tattr);
  if (verbose)
    printf("manage_cnct: Init the structure who contains attributes\n");
  
  assert(status_tab == 0);
  
  /*Initialisation de la structure -> ajout de l'option detachstate permettant de dÈtacher le thread*/
  status_tab = pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_DETACHED);

  assert(status_tab == 0);
  
  /*On crÈe le thread -> gestion de la fonction repeater avec prise en arguments de fd*/
  status = pthread_create(&threadCree, &tattr, th_repeater, (void*) fd_t);
  if (status != 0) {
    perror("manage_cnct: Error status\n");
    if (verbose)
      printf("manage_cnct: Error pthread [%d], executing function repeater\n", (int) threadCree);
    exit(EXIT_FAILURE);
  }
  
  pgrs_out();
  
  pthread_attr_destroy(&tattr);
  if (verbose)
    printf("manage_cnct: Destroy the structure [%d] who contains attributes\n", (int) threadCree);
  
  if (verbose)
    printf("manage_cnct: Exiting\n");
  
  return 0;
}
