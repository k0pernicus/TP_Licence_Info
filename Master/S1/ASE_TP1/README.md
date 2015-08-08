#TP1 ASE
##Bibliothèque Try/Throw

###Auteur: Carette Antonin
-----------------------

###Fichiers
*	README (format Markdown)
*	Makefile (maître)
*	src_mul/Makefile (Makefile esclave pour le programme try_mul)
*	src_mul/try.c (Fichier source de la bibliothèque Try/Throw)
*	src_mul/try.h (Headers de la bibliothèque Try/Throw)
* 	src_mul/try_mul.c (Programme de multiplication, en utilisant la bibliothèque Try/Throw)
*  	src_display_stack/display_stack.c (Première implémentation - sujet de TD)
*	src_display_stack/Makefile (Makefile esclave pour le programme display_stack)

###Ce qui a été réalisé

*	try_mul: programme de multiplication, avec utilisation de la bibliothèque try/throw
*	display_stack: programme permettant d'observer la pile d'exécution du programme, au fil de l'appel de fonction, de retour,...

###Compilation

*	Se placer dans le répertoire racine
*	<code>make</code>
*	<code>cd bin/</code>
*	<code>./try_mul</code> OU <code>./display_stack</code>

###Contact
Carette Antonin, antonin[dot]carette[at]etudiant[dot]univ-lille1[dot]fr