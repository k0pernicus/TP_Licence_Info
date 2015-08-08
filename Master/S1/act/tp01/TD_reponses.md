#TP1 ASE

Auteurs
-------
Piton Christophe  
Carette Antonin

###Fichier de réponses

***Remarque:* Tous les graphes sont disponibles dans le dossier "graphiques" - merci de vous y référer quant à la lecture des réponses aux questions.**

##Question 2

Comme nous pouvons le voir sur le graph 'comparaisons\_AleaT_AleaL.png', les courbes de *AleaT* avec/sans répétitions se ressemblent et ont la même allure asymptotique, de même pour *AleaL* avec/sans répétitions.  
Ainsi, nous pouvons en conclure que le nombre de répétitions n'a pas d'influence sur les courbes.

##Question 3

En admettant que la machine dispose d'un générateur de nombres aléatoires, nous avons 1 chance sur *x* (*x* étant la taille de l'ensemble des entiers disponibles pour ce générateur) d'obtenir un nombre quelconque.  
Ainsi, il y a équiprobabilité sur la génération des nombres.  
Chaque insertion d'un entier aléatoire dans un tableau suit une règle selon laquelle un entier *x* ne peut être épuisé au niveau de la génération, même s'il est déjà inséré.

Ainsi, nous pouvons théoriquement obtenir autant d'entiers différents lors de l'insertion aléatoire, preuve d'une permutation équiprobable. 

##Question 5

Comme nous pouvons le voir sur le graph 'comparaisons\_RechercheT_RechercheL.png', les courbes concernant la *rechercheL* sont très similaires - la répétition n'a donc aucune influence sur celles-ci.  
Contrairement à *rechercheL*, les courbes concernant *rechercheT* ne se ressemblent pas - la répétition influence donc celles-ci. Sans répétition, la mesure augmente très fortement sur de grands jeux de données (6.10-2 secondes), contrairement aux répétitions, où nous arrivons à un temps de 3.10-2 secondes pour les mêmes jeux de données.

##Question 6

Nous pouvons voir que la recherche d'éléments via la méthode issue de la librairie JAVA est plus lente que l'algorithme de recherche séquentiel, que ce soit pour la permutation aléatoire de nombre dans le tableau/ArrayList d'entiers, ou encore pour la recherche d'entier dans la structure de données correspondante.  
Aussi, le temps de l'insertion d'éléments est 10 fois plus élevé que le temps de recherche d'éléments, pour les deux méthodes, concernant les deux structures de données.

##Question 7

L'algorithme de la méthode *rechercheT* utilise une recherche dite "séquentielle" (on part de l'indice 0, on incrémente tant que l'on a pas trouvé notre nombre, jusqu'à la fin de la structure de données), contrairement à l'autre méthode qui utilise une méthode issue de la librairie JAVA (*contains()*, sur une ArrayList). Qu'importe les variations de répétition, l'algorithme fonctionnera toujours de la même façon - on mise sur une équiprobabilité quant à l'insertion des entiers.

La méthode *contains* est implémentée via un algorithme à un temps linéaire (d'après la Javadoc Oracle), contenu dans indexOf().  
Soit une complexité à O(n) pour le temps.

##Question 8

**<span style="color: red">Le temps de calcul peut varier ou non en fonction de la répétition des éléments insérés dans la structure de données, en fonction de la structure de données et/ou de l'algorithme employé/étudié.</span>**

##Question 10

L'algorithme (X)\*L utilise comme structure de données une ArrayList, tandis que l'algorithme (X)\*T utilise un tableau.  
Par le graphique, nous pouvons voir que, sans répétitions, la comparaison sur les structures ArrayList est beaucoup plus longue que pour les structures de tableau classique .

##Question 11

Ainsi, la recherche de minimum est beaucoup plus efficace via une recherche séquentielle sur une structure de tableau classique. 

***Remarque:* Merci de se référer aux graphiques 'comparaisons\_q12_vX.png', pour les question 12 et 13**

##Question 12

Nous pouvons facilement récupérer les valeurs pour tracer les courbes des fonctions de référence. Par contre ces données ne sont pas tracables facilement sur un même graphique. En effet, ces fonctions croissent à des vitesses tellement différentes qu'on ne peut pas les faire toutes apparaître.

##Question 13

Log est maximisée par toutes les autres

Nlogn est maximisée par N^k

KpN est maximisée par Exp

Du plus efficace au moins efficace:
Log / Nlogn / NpK / KpN / Exp

##Question 14

Nous pouvons voir que, plus nous augmentons le paramètre Epsilon et plus nous atteignons une valeur sur l'ordonnée tendant vers 0.

##Question 15

Analyse d'après la courbe:  
*	Plus Epsilon augmente, et plus la place de la courbe (pour l'axe des ordonnées) augmente,
*	Plus on augmente Epsilon, et plus n^Epsilon prend de la valeur,
*	Si Epsilon est très grand, la place de la courbe sera très grande aussi dans l'axe des ordonnées -> la limite tendra vers +infini,
*	Ainsi, si la limite tend vers +infini quand Epsilon devient grand, nous pouvons dire que log(n) appartient à O(n^k).

Analyse mathématique:
*	log(n) <= n pour n >= 1,
*	n^E >= n pour E > 0, et n >= 1,
*	Ainsi, nous pouvons en conclure ici que, pour n >= 1 et un E > 0, n^E > log(n).

##Question 16

Le tracé correspondant à la comparaison des tracés sur un seul graphique est donné par 'comparaisons_q16.png'.

##Question 17

<span style="color: red">Pas de conclusion visuelle</span>

##Question 18

***mystereL*:**
*	On recherche le minimum d'une partie de la collection, comprise entre l'index i et la fin de la structure de données
*	On récupère l'index du minimum, dans la collection
*	On inverse la position de tous les éléments entre l'index du minimum et la taille de la liste -> le minimum se trouve en fin de collection
*	On inverse ensuite toute la collection -> le minimum se trouve ainsi en début de collection.
*	Et on recommence...  

**Ainsi, *mystereL* trie la collection de façon croissante.**

***mystereT*:**
*	On prend l'index 0
* 	Les 3 fonctions "For" consécutives vont bouger le minimum en fin de tableau, et à la fin de l'algorithme en début de tableau.
*  En on recommence...

**Ainsi, *mystereT* trie la collection de façon croissante, elle aussi.**

##Question 19

***mystereL*:**
*	**Meilleur cas**: collection triée de façon croissante.
Si la collection est déjà triée, on fera une boucle de *n* itérations -> sur cette boucle, on effectue *1* opération de recherche de minimum (il sera en début de collection), et *1* opération de recherche d'index. Ensuite, on retourne 2 fois la collection, avec une complexité de *n/2* -> *(2 * n/2)* = *n*.  
Ainsi, on a *n * (n + 2)* opérations pour le meilleur cas, soit une complexité de ***O(n^2)***.
*	**Pire cas**: collection triée de façon décroissante.
On fera là-aussi une boucle de *n* itérations -> sur cette boucle, on effectue *n* opérations de recherche de minimum (il sera en fin de collection), et *1* opération de recherche d'index.
Ensuite, on retourne 2 fois la collection: *1* opération, et *n* opération : *n + 1*.  
Ainsi, on a *n * (n+1)* opérations pour le pire cas, soit une complexité de ***O(n^2)***.

***mystereT*:**
*	**Meilleur cas**: tableau trié de façon décroissante.
Si le tableau est déjà trié (de façon décroissante), on fera une boucle de *n* itérations -> sur cette boucle, on effectue *n* opérations pour rechercher le minimum (en fin de tableau), pas de 2ème boucle imbriquée, et *n/2* opérations pour la fin de la boucle principale.  
Ainsi, on a *n * (n + n/2)* opérations pour le meilleur cas, soit une complexité de ***O(n^2)***.
* 	**Pire cas**: collection triée de façon croissante. Si le tableau est déjà trié (de façon croissante), on fera une boucle de *n* itérations -> sur cette boucle, on effectue *1* opération pour recherche le minimum (en début de tableau), et *n / 2* opérations 2 fois de suite (pour la 2ème et 3ème boucle imbriquée) : *n*.  
Ainsi, on a *n * (n+1)* opérations pour le pire cas, soit une complexité de ***O(n^2)***.
