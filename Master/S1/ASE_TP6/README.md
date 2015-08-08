ASE_TP6
=======

Auteur
------
Carette Antonin

###Liste des fichiers

*	define_values.h
*	drive.{c|h}
*	mbr.{c|h}
*	mkhd.c
*	main.c
*	mkvol.c
*	dvol.c

###Ce qui été effectué

*	Ecriture de la librairie mbr
*	Ecriture du programme mkvol
*	Ecriture du programme dvol
*       Ecriture du programe delvol

###Ce qui a été réalisé pour ce TP

*	Programme permettant la création d'un volume : **mkvol**
*	Programme permettant l'affichage des volumes du MBR : **dvol**
*       Programme permettant de supprimer un volume du MBR : **delvol**

###Compilation

*	Se placer à la racine du projet (ASE_TP6_Carette)
*	<code>make</code>
*	<code>./mkvol cylinder sector size</code>
*	<code>./dvol</code>

Exemple:

<code>
antonin@debian:~/Documents/Fac/ASE_TP6$ ./mkvol 0 1 12

=====Welcome to ./mkvol=====

Struct : 
        Cylinder : 0
        Sector : 1
        Size : 12

<W>SSSSSSSSSSSSSSSS  
<W>SSSSSSSSSSSSSSSS

	--------------------------------

antonin@debian:~/Documents/Fac/ASE_TP6$ ./dvol  
1 volumes  
Volume 0 : 0 first cylinder, 1 first sector, 12 sectors

	-------------------------------

antonin@debian:~/Documents/Fac/ASE_TP6$ ./mkvol 1 2 25

=====Welcome to ./mkvol=====

Struct : 
        Cylinder : 1
        Sector : 2
        Size : 25

<W>SSSSSSSSSSSSSSSS

	-------------------------------

antonin@debian:~/Documents/Fac/ASE_TP6$ ./dvol  
2 volumes  
Volume 0 : 0 first cylinder, 1 first sector, 12 sectors  
Volume 1 : 1 first cylinder, 2 first sector, 25 sectors

	-------------------------------

antonin@debian:~/Documents/Fac/ASE_TP6$ ./delvol 0  
1 volumes  
Volume 0 : 1 first cylinder, 2 first sector, 25 sectors
</code>

###Contact
antonin.carette[at]etudiant.univ-lille1[dot]fr