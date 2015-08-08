#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>

#include "tail.h"
 
int mefficace(int fileSrc, int nbline) {
	/* compteur de caractères d'une ligne : permettra de gérer le cas où les lignes font plus de 1000 caractères */
	int cpt_char_une_ligne;
	/* compteur de caractères de l'ensemble des n lignes que l'on souhaite garder*/
	int cpt_char_n_lignes;
	/*index du buffer permettant de remplir le buffer en commençant par la fin*/
	int index;
	/*nombre de lignes lues*/
	int nombreLignes;
	/*buffer servant à stocker le caractère lu à l'appel de read*/
	char bufferOneChar[1];
	/* buffer servant à stocker les lignes que l'on souhaitera renvoyé ensuite sur l'entree standard*/
	char* buffer=malloc((sizeof(char))*(nbline*(TAILLE_MAX_LIGNE)+1));

	/*initialisation des variables*/
	cpt_char_une_ligne=0;
	cpt_char_n_lignes=0;
	index = nbline*(TAILLE_MAX_LIGNE);
	nombreLignes=0;

	buffer[index] = '\n';
	index--;
	
	/*on lit les caracteres un par un*/
	/*on entre les caracteres dans une section du buffer jsuqu'à rencontrer un '\n'*/
	/*dans quel cas on change de section du buffer pour sauver la porchaine ligne*/
	while(nombreLignes<(nbline)) {
		/*on vérifie que la ligne ne dépasse pas 1000 caractères*/
		if(cpt_char_une_ligne>TAILLE_MAX_LIGNE) 
		{perror("Trop de caractères sur une seule ligne!"); exit(EXIT_FAILURE); }
		/*lecture d'un caractère*/
		read(fileSrc,  bufferOneChar, 1);
   
		/*on incrémente le cpt_char qui compte le nombre de caractères d'une ligne*/
		cpt_char_une_ligne++;
		cpt_char_n_lignes++;
		/* si le caractère est un retour chariot, on le compte*/
		if (bufferOneChar[0] == '\n') {
			nombreLignes++;
			cpt_char_une_ligne=0;
		}
    
		/*on a lu autant de lignes qu'on le souhaitait, on sort de la boucle sans exécuter le reste des instructions*/
		if ( nombreLignes==(nbline) ) break;
        
		/*copie du caractère lu dans le buffer*/
		/* décalage de l'index du buffer*/
		buffer[index] = bufferOneChar[0];  
		index--;
	
		/*décalage au caractère précédent, on recule de 2 car le read à avancer le pointeur d'un caractère
		 si lseek renvoie une erreur, c'est qu'on a cherché à lire un caractère placé avant le début du fichier.
		On a donc lu l'entièreté du fichier : le fichier comporte moins de lignes que demandées. On sort de la boucle. */
		if((lseek(fileSrc, (-2), SEEK_CUR))==-1) break;
	}

	/*les nbline ont été lues, ou il y a moins de lignes que souhaitées : on affiche ce qui a été lu sur la sortie standard*/
	write(STDOUT_FILENO, buffer, (nbline*(TAILLE_MAX_LIGNE)+1));
	
	/*on libère l'espace alloué pour le buffer*/
	free(buffer);
	return 0;
}
