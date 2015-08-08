#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>

 int main(int argc, char*argv[]) {

const char* address; /*l'adresse internet a interroger*/
 struct sockaddr_in serveur; /*structure contenant l'adresse a interroger*/
int sockfd;/*le descripteur de  socket */
char* msg;

address = "134.206.16.244";
 msg = "Allo ! René ? Allo";

serveur.sin_family = AF_INET;
serveur.sin_port = SOCK_DGRAM;
serveur.sin_addr = inet_addr(address);
/* mise a zero pour sin_zero */
 memset(&(serveur.sin_zero),'\0',8);

/*Creation du socket*/
/*AF_INET pour internet, SOCK_DGRAM pour UDP, 0 pour protocole par défaut*/
 sockfd = socket(AF_INET, SOCK_DGRAM, 0);

/* test de cretation du socket*/
if (sockfd == -1) {
  perror("Erreur de création du socket !!! Damned !!!");
  exit(EXIT_FAILURE);
 }
 else
   printf("Client-socket ouvert avec succes... Well Done Old BOy !");

 (sendto(sockfd, &msg, 18, 0,serveur, sizeof(serveur)) == 18);

 close(sockfd);

 return 1;
}

