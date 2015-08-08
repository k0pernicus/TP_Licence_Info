ASE_TP10
=======

Auteurs
-------
Carette Antonin - antonin.carette@etudiant.univ-lille1.fr

Owczarek Valentin - valentin.owczarek@etudiant.univ-lille1.fr

###Liste des fichiers

* README.md -> Fichier README
* Makefile -> Makefile maître

ETC

* hardware.ini -> Fichier hardware

SRC

* src/mmu_manager.c -> Fichier source permettant de calculer des matrics de taille N
* src/oracle.c -> Fichier source permettant d'analyser et vérifier les résultats obtenus par le programme mmu_manager
* src/mi_kernel.c -> Fichier contenant toutes les fonctions et séquences de code exécutées en mode maître
* src/mi_user.c -> Fichier contenant toutes les fonctions et séquences de code exécutées en mode utilisateur
* src/matrix.c -> Fichier contenant toutes les fonctions nécessaires pour la création et le calcul de matrices
* src/user_process.c -> Ensemble de fonctions permettant de calculer les matrices de taille N
* Makefile -> Makefile esclave

INCLUDE

* include/hardware.h -> Fichier d'entête partagé (fichier hardware)
* include/hw_config.h -> Fichier de configuration des accès au materiel
* include/matrix.h -> Fichier d'entête partagé (fichier matrix)
* include/mi_syscall.h -> Fichier d'entête partagé par le fichier maître et utilisateur
* include/swap.h -> Fichier d'entête partagé quant à la swap
* include/tlb.h -> Fichier d'entête de src/tlb.c

###Ce qui a été réalisé

* Multiplication de grandes matrices - Addition

###Compilation

* <code>make</code>
* <code>cd src</code>
* <code>./mmu_handler | ./oracle</code>

###Problèmes

* Problème d'exécution : exécution du programme mmu_manager (BUS_ERROR) : MacOSX
