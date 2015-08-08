#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*Variable contenant l'activation ou non du suivi des liens symboliques*/
static int opt_follow_links = 0;
/*Variable contenant l'activation ou non de l'intention de lister tous les dossiers/fichiers du répertoire*/
static int opt_list_all = 0;
/*Variable contenant l'activation ou non de la représentation des données du contenu du répertoire*/
static int opt_apparent_size = 0;

/*Fonction permettant de savoir si le chemin (donné en paramètre) est valide ou non*/
int valid_name(const char *name) {

	return ((strcmp(name, ".") != 0) && (strcmp(name, "..") != 0));

}

/*Fonction du_file -> Permet de donner l'espace mémoire ROM utilisé par le chemin donné en paramètre de la fonction*/
int du_file(const char *pathname) {

	/*Variable contenant le répertoire*/
	DIR *dirp;
	/*Variable path*/
	char path[PATH_MAX + 1], link_path[PATH_MAX + 1];
	/*Structure du répertoire*/
	struct dirent *dp;
	/*Variable contenant la taille du répertoire donné + d'un répertoire qui sera remis à 0 ensuite*/
	int r = 0, dir_size = 0, status;
	/*Structure stat*/
	struct stat sb;

	status = lstat(pathname, &sb);

	/*Si le chemin donné mène vers un fichier, on retourne l'espace mémoire utilisé*/
	if (S_ISREG(sb.st_mode)) {
		return opt_apparent_size?sb.st_size:sb.st_blocks;
	}
	/*Sinon -> répertoire / lien symbolique*/
	else {
	  /*Si c'est un répertoire...*/
	  if (S_ISDIR(sb.st_mode)) {
	    /*On s'assure que l'on peut ouvrir le dossier donné en paramètre*/
	    assert(dirp = opendir(pathname));
	    /*On lit les sous-dossiers*/
	    while((dp=readdir(dirp))) {
	      if(valid_name(dp -> d_name)) {
		assert(strlen(pathname)+1+strlen(dp->d_name)+1 <= PATH_MAX);
		/*On concatène le chemin donné en paramètre avec l'autre dossier ouvert*/
		strcpy(path, pathname);
		strcat(path,"/");
		strcat(path,dp->d_name);
		r+=du_file(path);
		/*Vérification du list_all (option -a)*/
		if (opt_list_all == 1) {
		  dir_size = du_file(path);
		  printf("%d      %s\n",dir_size,path);
		};
		/*Fin de vérification du list_all*/
	      };
	    }
	    r+=opt_apparent_size?sb.st_size:sb.st_blocks;
	    closedir(dirp);
	  }
	  else {
	    /*On vérifie si ce n'est pas un lien symbolique, et si l'option demandé par l'utilisateur est bon*/
	    if (S_ISLNK(sb.st_mode) && (opt_follow_links == 1)) {
	      /*S'il est bon, on fait un readlink sur le pathname, que l'on stocke dans link_path*/
	      status = readlink(pathname, link_path, PATH_MAX);
	      /*Si tout va bien...*/
	      if (status > 0) {
		/*On ferme la chaîne par \0*/
		link_path[status] = '\0';
		/*On ajoute en mémoire l'espace mémoire utilisé pour le fichier pointé par le lien symbolique*/
		r+=opt_apparent_size?sb.st_size:sb.st_blocks;
		r+=du_file(link_path);
	      }
	    }
	  }
	  return r;
	}
	return 0;
}

/*Fonction permettant de vérifier les options une à une; on s'en limitera à 2 ici:
  a -> la taille de chaque fichier / dossier contenu dans celui donné en paramètre
  b -> la taille apparente (le nombre d'octets contenus dans le fichier)
  L -> le suivi des liens symboliques
*/
int verify_options(char* options) {

  /*Tant qu'il y a des options...*/
  while(*options) {
    switch(*options) {

    /*On gère le cas "list_all"*/
    case 'a':
      opt_list_all = 1;
      break;
    /*On gère le cas "apparent_size"*/
    case 'b':
      opt_apparent_size = 1;
      break;
    /*On gère le cas "follow_links"*/
    case 'L':
      opt_follow_links = 1;
      break;
    /*On gère le cas où l'utilisateur demande de l'aide sur le programme*/
    case 'h':
      printf("\n/*******************/\n");
      printf("/ Programme du_file /\n");
      printf("/ Créé par:         /\n");
      printf("/ Carette Antonin   /\n");
      printf("/ Marechal Tanguy   /\n");
      printf("/*******************/\n\n");
      printf("Utilisation du programme:\n");
      printf("Permet de donner l'espace mémoire ROM utilisé par le chemin que vous devrez donné en paramètre.\n");
      printf("Options possibles pour le programme:\n");
      printf("-a: la taille de chaque fichier / dossier contenu dans celui donné en paramètre\n");
      printf("-b: la taille apparente (le nombre d'octets contenus dans le fichier)\n");
      printf("-L: active le suivi des liens symboliques\n\n");
      return 2;
    default:
      perror("Option inconnue! Veuillez revérifier les options données svp...\n");
      return 1;
    };

    options++;
  };

  return 0;

}

/*Main du programme*/
int main(int argc, char* argv[]) {

  /*Les retours des fonctions 'du' et 'verify_options'*/
  int retour_du, retour_options, test_to_verify;
  /*Chaine de caractères constituant le pathname*/
  char* pathname;
  /*Chaine de caractères constituant la liste des options demandées par l'utilisateur*/
  char* options = NULL;

  test_to_verify = 0;

  /*Si trop d'arguments -> erreur*/
  if (argc>3) {
    perror("Utilisation: ./du_file [-abL] or [-h] [pathname]\n");
    return 1;
  }

  if (argv[1][0] == '-') {
    test_to_verify = 1;
    options = &argv[1][1];
  };

  /*Si 2 ou 3 arguments pris en compte alors...*/
  if (argc == 3) {
    /*On regarde s'il y a bien 3 arguments...*/
    assert(argv[1][0] == '-');
    pathname = argv[2];
  }
  /*...ou alors 2*/
  else {
    /*Si ce n'est pas une option (-h), alors le 1er argument est le chemin du fichier*/
    if (test_to_verify != 1) pathname = argv[1];
  };

  /*Si des options ont été entrés, alors on va les vérifier une par une*/
  if (test_to_verify == 1) {
    retour_options = verify_options(options);
  };

  if (retour_options != 0) return 1;

  retour_du = du_file(pathname);
  
  printf("%d      %s\n",retour_du,pathname);

  return 0;

}
