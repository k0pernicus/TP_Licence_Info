TP_PdS_zombi
============

Implémentation des question 5 et 6 (FEUILLE TD/TP PdS)

Fichiers rendus: pas de ff.c -> Le main ainsi que la fonction sont directement dans le fichier forkfork.c

EXERCICE 5

Réponse question 2

-> Il va falloir créer un canal de communication entre le père et le fils, afin de pouvoir remonter l'information (le pid du petit-fils) au père, pour qu'il puisse le reconnaître.

Réponse question 3

-> Le père est dupliqué 2 fois, lors du 1er et du 2ème fork - il existe donc 3 fois lors de l'exécution du programme, avant que le fils ne se termine. Il peut donc être très coûteux de faire ce double-fork pour des programmes lourds, car nous avons une copie qui ne sert à rien, vu que l'on utilise le processus petit-fils.

Utilisation EXERCICE 5: 
	$make
	$./forkfork [number_for_function]

Utilisation EXERCICE 6:
	$make
	$./race

Suppression de fichiers caches, programmes, fichiers objets, etc...
	$make clean
	$make realclean
	$make rmobjects
