ACT_TP5
=======

Auteur
------
Carette Antonin  
antonin.carette@etudiant.univ-lille1.fr

###Packages

*	README.md -> README du projet
*	Makefile -> Makefile maître

**SRC**  
*	Makefile -> Makefile esclave
*	main.c
*	heuristique.{c|h} -> Contient toutes les heuristiques implémentées

**DONNEES** -> Dossier contenant tous les fichiers test
*	ex_donnees_1.txt -> fichier d'exemple erroné
*	ex_donnees_2.txt
*	ex_donnees_3.txt
* ex_donnees_4.txt
* ex_donnees_5.txt -> gros fichier d'exemple

###Ce qui a été réalisé

* Implémentation des 3 heuristiques pour le problème BinPack
* Implémentation du mode 'online'/'offline' pour le problème BinPack
* Réalisation du rapport

###Ce qu'il reste à faire

* Adaptation sur un problème lié à SUM ou Partition

###Compilation

* Se placer à la racine du projet
* <code>make</code>
* ./bin/heuristique <your_file> <option> <online/offline> (online par défaut)
