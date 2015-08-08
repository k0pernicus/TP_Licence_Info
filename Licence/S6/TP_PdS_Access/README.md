TP_PdS_Access
TP Réalisé par…
Carette Antonin
Maréchal Tanguy

==========

Travaux Pratiques - Pratique du Système : Implémentation de la
commande UNIX Access en C, via la fonction système C access()

Utilisation:

	- se placer dans le répertoire source
	- $ make
	- Pour connaître les valeurs des constants PATH_MAX et NAME_MAX
      sur votre système: $ ./prlimit
	- Pour la commande ACCESS: $ ./maccess -[-][vxrw] path/of/file

Si l'option verbose (<code>-v</code>) est activée, vous aurez droit à une
explication si erreur il y a.
Sinon, faites:
	<code>$ echo $?</code>
pour connaître le code correspondant au retour de ACCESS

Le fichier typescript.txt contient tous les tests demandés pour la
question 3.
