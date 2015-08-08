TP_PdS_shell
============

#Auteurs:
* Carette Antonin
* Maréchal Tanguy


### Ce qui a été réalisé

Implémentation des commandes suivantes:
* kill
* fg
* bg
* exit
* jobs
Ainsi que les pipes à N commandes.

### Compilation

Compilation automatique.

	make

### Utilisation

Pour utiliser la fonction ‘historique’ du shell, complétez comme ceci:

	ledit  ./mshell [-v]

ou encore:

	rlwrap ./mshell [-v]

Un exemple d'utilisation du mshell, avec un fichier test.txt (contenant une suite de répliques cultes du film 'Tron'):

	xeyes&
	jobs
	fg [np xeyes]
	(Ctrl-Z)
	kill [np xeyes]
	xeyes
	(Ctrl-Z)
	jobs
	fg [np xeyes]
	(Ctrl-C)
	jobs (n'affiche rien)
	cat test.txt | grep Bit | grep Oui
	jobs (n'affiche rien)
	xeyes | xeyes &
	jobs (affiche les pid des 2 processus créés)
	kill [np 1rst xeyes]
	kill [np 2nd xeyex]
	jobs (n'affiche rien)
	exit

### Remarques

* Implémentation du signal SIGKILL à place de SIGTERM pour l'exécution de programmes graphiques dans le mshell -> processus stoppé, nous n'avons pas la main, donc la commande ‘kill’ ne tuera jamais le processus graphique créé, avec le signal SIGTERM.
* Toutes les fonctions do, jobs, etc... fonctionnent correctement.
* Implémentation du pipe pour N processus fils effectué. Malgré l’apport de la fonction addjob() dans le programme, nous n’avons pu réaliser la coupure de tous via l’utilisation de la commande ‘kill’, sur le pid du groupe de processus (notre idée étant que ce pgid devait être le tout premier processus créé - voir Premierpid dans pipe.c).
