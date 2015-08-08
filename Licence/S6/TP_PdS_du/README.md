TP de Pratique des Systèmes numéro 2 (mdu)
===========
TP réalisé par:
Antonin Carette
Maréchal Tanguy

-
Implémentation de la commande UNIX 'du'
	
Utilisation désormais des 4 options suivantes:
	<ul>
	<li> <code>-a</code> permet de lister tous les sous-répertoires existants, ainsi que leur taille</li>
	<li> <code>-b</code> permet de donner la taille des répertoires en octets</li>
	<li> <code>-L</code> permet de donner la taille des répertoires, avec les informations effectives des liens symboliques</li>
	<li> <code>-h</code> permet de demander l'aide sur le programme ->
	lister les options du programme ou encore comment l'utiliser,
	quels sont les programmeurs, etc...</li>
	</ul>
Ces options peuvent être utilisées simultanément via <code>-abL</code>
	et non <code>-a -b -L</code>, sauf <code>-h</code> qui doit être utilisé seul (les autres options placées avant / après seront annulées).

-
Utilisation:
<ul>
<li><code>$make</code></li>
<li><code>./mdu options file-or-directory</code></li>
<li>Pour effacer l'exécutable et autres fichiers cachés <code>make
clean realclean</code></li>
</ul>
