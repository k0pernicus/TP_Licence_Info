|-----------------------/
|     TP_PdS_mTail     /
|=====================/
| Projet réalisé par /
|-------------------/
|Carette Antonin   /
|Maréchal Tanguy  /
|________________/

Fonction C permettant d'afficher les n dernières lignes d'un fichier donné en paramètre (voir commande UNIX tail)

==CE QUI A ÉTÉ RÉALISÉ==
	- la commande tail version 'simpliste' (sans option 'n' - valeur par défaut de 10 lignes)
	- la commande tail version 'utile'
	- la commande tail version 'efficace'

REMARQUE: La commande tail version 'simpliste' ne se trouve pas dans le main général contenant les 2 autres fonctions, elle n'a pas été implémentée avec l'option 'n' aussi - il s'agit du programme 'msimpliste'.
Des tests de fichiers se trouvent dans le dossier 'tests'
==UTILISATION==
	Compilation des programmes: $make
	Pour utiliser le programme 'msimpliste' : $./msimpliste myFile
	Pour utiliser le programme 'mtail' : $./mtail [-n ...] myFile

REMARQUE: Si non utilisation de l'option 'n', la prise en charge du nombre de lignes à afficher, par défaut, est de 10.

==REMARQUES GENERALES==
	Afin de pouvoir nettoyer le dossier contenant les fichiers sources, veuillez exécuter ces commandes: 
	Pour supprimer les fichiers caches, dossiers .dSYM et .DS_Store: $make clean
	Pour supprimer les fichiers exécutables (mtail, msimpliste): $make realclean
	Pour supprimer les fichier objets (*.o): $make rmobjects
