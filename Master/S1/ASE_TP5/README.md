ASE_TP5
=======

Auteur
------
Carette Antonin

###Liste des fichiers

*	**drive.{c|h}**  
	Bibliothèque contenant les fonctions permettant de lire, écrire et formater un secteur du disque virtuel
*	**dmps.c**  
	Programme permettant de lire un secteur du disque virtuel
*	**frmt.c**
	Programme permettant de formater tout le disque virtuel

###Ce qui a été fait

*	Ecriture de la bibliothèque drive
*	Ecriture du programme dmps
*	Ecriture du programme frmt

###Compilation

*	Se placer dans le répertoire racine
*	<code>make</code>
*	Pour dmps: <code>./dmps</code>  
	Pour changer la valeur du cylindre et du secteur, il faut changer les deux premières valeurs dans la fonction read_sector() du main
*	Pour frmt: <code>./frmt</code>

Contact
-------
antonin.carette[at]etudiant.univ-lille1[dot]fr