Rapport du TP04 d'ACT
=====================

Auteurs
-------
Carette Antonin  
Piton Christophe

##Question 1

1.	Un **certificat** est une solution proposée à un problème donné. 
2.	L'implémentation du certificat se fera sous la forme d'une **matrice de booléens** (tableau à deux dimensions à  *k * n*) - chaque entrée *k* du tableau étant un sac, et chaque entrée *n* du tableau étant le nombre d'objets (non-fixé).
3. La taille des certificats sera de ***k * n* bits**, *k* étant le nombre de sacs et *n* étant le nombre d'objets. 
 
	#####Explications:
	*	La taille des certificats sera de *k * n* bits,
	*	*k * n* est inférieur ou égal à *n^2* bits,
	* 	donc *k * n* est inférieur ou égal à la taille du *certificat^2*

	Ainsi, la taille des certificats est bien bornée polynomialement par rapport à la taille de l'entrée.
4.	On vérifiera si : 
	*	la **somme des poids des objets des sacs est bien égale à la capacité**,
	* 	qu'**un objet x est bien dans un sac**, pour tous les objets connus.

	######Algorithme 1  
	```
	Pour chaque sac,  
		Somme des objets de ce sac  
	Si cette somme est différente de la capacité,  
		return False;  
	return True;
	```

	######Algorithme 2
	```
	Pour chaque objet  
		On initialise un booléen (*vu*) à False  
		Pour chaque sac  
			Si l'objet est dans le sac,  
				vu = True  
	Si vu == False,  
		return False;  
	return True;
	```
		
##Question 2

Il faudra appeler autant de fois le programme qu'il n'y a de témoin (ou certificat).

##Question 3