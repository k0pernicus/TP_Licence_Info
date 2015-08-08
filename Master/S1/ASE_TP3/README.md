ASE_TP3
=======

TP concernant l'ordonnancement

Auteur
------
Carette Antonin

###Liste des fichiers

*	README.md
*	Makefile
*	src/Makefile
*	src/create_ctx.{c|h} -> contient la fonction yield(), init_ctx(), switch_to_ctx()
*	src/hw.{c|h}
*	src/start_schedule.c

###Ce qui a été réalisé

*	Modification de la bibliothèque init_ctx
*	Modification de la bibliothèque switch_to (erreur quand à la première initialisation de la structure courante)
*	Ajout de la fonction create_ctx
*	Ajout de la fonction yield
*	La partie sur l'ordonnancement sur interruptions (start_sched + appels à irq_disable/irq_enable dans la fonction yield)

###Les problèmes rencontrés

*	Lors de l'exécution du programme, il y a un soucis quant au remplissage de la variable globale ctxs, alors qu'elle a bien été initialisé... Problème non résolu.

###Contact

antonin.carette[at]etudiant.univ-lille1[dot]fr