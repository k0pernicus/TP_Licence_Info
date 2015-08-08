#include "tail.h"
#include "all_tail.h"

/*ICI - LES OPTIONS*/
/*Nombre de lignes demandées*/
static int nbLines;

/*FONCTIONS*/
/*Fonction permettant de vérifier extérieurement chaque option donnée par l'utilisateur
- options: la liste des options
- argument: l'argument donné (argv[2]) par l'utilisateur - comme le nombre de lignes
*/
int verify_options(char* options, char* argument) {

  while (*options) {
    switch(*options) {
    /*n vérifiera les n dernières lignes*/
    case 'n':
      assert(nbLines = atoi(argument));
      break;
    default:
      perror("Erreur d'option : 'Option inconnue'\n");
      return 1;
    }
    options++;
  }

  return 0;

}

/*MAIN*/
/*Main du programme mtail*/
int main(int argc, char* argv[]) {

	/*Numéro d'entrée de fichier dans la table des fichiers ouverts du système*/
	int fileSrc;
	/*Numéro permettant de vérifier la bonne exécution de la fonction lseek*/
	int returnLseek;
	/*Liste des options demandées par l'utilisateur*/
	char* options;
	/*Chemin du fichier*/
	char* pathname;

	options = NULL;

	/*On vérifie que le nombre d'arguments est compris entre 2 et 4, mais n'est pas égal à 3*/
	assert(argc == 2 || argc == 4);

	/*Si l'on a 3 arguments après le nom du fichier, alors...*/
	if (argc == 4) {
		/*On vérifie si le 1er argument commence par un tiret (option)*/
		assert(argv[1][0] == '-');
		options = &argv[1][1];
		/*Le nombre de lignes correspond au 2ème argument, on le convertit en entier (en vérifiant que l'on peut le convertir)*/
		verify_options(options, argv[2]);
		/*Le chemin du fichier est le 3ème argument donné par l'utilisateur*/
		pathname = argv[3];
	}
	else {
		/*On vérifie que l'utilisateur ne s'est pas trompé en donnant seulement une option*/
		assert(argv[1][0] != '-');
		/*Le nombre de lignes prises par défaut est de 10*/
		nbLines = 10;
		/*Le chemin du fichier est le 1er argument donné par l'utilisateur*/
		pathname = argv[1];
	};	

	/*Ouverture du fichier en lecture seule*/
	assert(fileSrc = open(pathname, O_RDONLY));

	/*On déplace la position courante du fichier à la fin (car seule la fonction mefficace prendra en compte ce lseek)*/
	returnLseek = lseek(fileSrc, 0, SEEK_END);

	/*Si le déplacement ne s'est pas fait correctement, on appellera la fonction 'tail utile'*/
	if (returnLseek == -1) {
	  printf("Vous utilisez la fonction 'UTILE'\n");
	  mutile(fileSrc, nbLines);
	}
	/*Sinon, on appellera la fonction 'tail efficace'*/
	else {
	  printf("Vous utilisez la fonction 'EFFICACE'\n");
	  mefficace(fileSrc, nbLines);
	}
	/*On ferme tout, le travail est fini. J'ai gagné. POINT.*/
	close(fileSrc);

	return 0;

}
