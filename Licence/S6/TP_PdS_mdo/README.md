TP_PdS_mdo
==========

	Auteur: Carette Antonin, Mar�chal Tanguy

	TP mdo - Voir exercice 10 de la fiche TD/TP 2

==Ce qui a �t� r�alis�:
   Commande mdo -> commandes avec options --and, --or, --cc, --kill (Attention, prononcez... comme vous voulez, tant qu'on a une bonne note...), et de jolis commentaires.   

==Utilisation:
	$./make
	$./mdo [--and|--or|--cc|--kill] "commande1 options" "commande2 options" ...

Remarque: Pour tuer un processus fils, utilisez le terminal comme ceci:
	$ps aux
	-> Regarder le num�ro de processus du programme en cours d'ex�cution que vous voulez tuer (on l'appellera 'n'), se trouvant dans la deuxi�me colonne de l'affichage
	$kill n

Pour rafraichir (effacer les fichiers caches, fichiers objets, ex�cutable, ...):
	$./make clean realclean rmexec

==Quelques remarques:
	- Les guillemets sont optionnels SI ET SEULEMENT SI la/les commande(s) n'est/ne sont pas accompagn�e(s) d'une ou plusieurs options,
	- Toutes les options peuvent �tre utilis�es, dans n'importe quel sens qu'il soit! ATTENTION, --kill doit TOUJOURS �tre utilis� avec --cc,
	- Am�lioration des blagues dans le README pour le prochain TP.

"Plus fort que les Tortues Ninja, la Team-TAMC!!! (Attention, prononcez "Tank", Merci.)"
