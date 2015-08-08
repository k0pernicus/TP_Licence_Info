ASE_TP9
=======

Auteurs
-------
Carette Antonin - antonin.carette@etudiant.univ-lille1.fr

Owczarek Valentin - valentin.owczarek@etudiant.univ-lille1.fr

###Liste des fichiers

ETC

* hardware.ini -> Fichier hardware

SRC

* src/main.c -> Main du projet 1
* src/mi_kernel.c -> Fichier contenant toutes les fonctions et séquences de code exécutées en mode maître
* src/mi_user.c -> Fichier contenant toutes les fonctions et séquences de code exécutées en mode utilisateur

INCLUDE

* include/hardware.h -> Fichier d'entête partagé (fichier hardware)
* include/mi_syscall.h -> Fichier d'entête partagé par le fichier maître et utilisateur
* include/tlb.h -> Fichier d'entête de src/tlb.c

###Ce qui a été réalisé

* Makefile générique
* Hiérarchisation de fichiers
* TP1 - non testé

###Compilation

* Se placer dans le répertoire source
* <code>make</code>
* <code>./main</code>
