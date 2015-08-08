TP-PdS-chat
===========

Auteurs:
* Carette Antonin
* Maréchal Tanguy

But: Implantation d'un chat multi-threadé en langage C

### Ce qui a été réalisé

* Implémentation de verrous (non-récursifs) pour l’ajout et la suppression de sockets
* Implémentation des statistiques (pour le chat en général, ainsi que pour les clients)

### Compilation: 

* ATTENTION: Pour une utilisation du programme sur MacOS, veuillez modifier le Makefile (mtcs/Makefile) en supprimant l'option '-pthread' présent en ligne 19, avant d'exécuter le Makefile!

Compilation automatique.

	$make

### Utilisation: 

1° Dans un terminal:

	$./mtcs

2° Dans un autre terminal, ouvrez un client telnet en localhost, associé au port du programme donné (8011 ou 8012):

	$telnet localhost "PORT"

3° Dans un autre terminal encore, refaites la prérogative numéro 2

4° Maintenant, discutez sur l’un et l’autre du chat

5° Une fois avoir lancé quelques conversations, veuillez quitter l’un des clients telnet:

	>Ctrl-[

	>QUIT

6° Pour afficher les statistiques, entrer dans le telnet quitté: 

	$kill -10 PID-PROGRAMME
