#TD_Reponses

Auteurs
-------
Carette Antonin  
Piton Christophe

###Remarques:

#Question de cours

##Question 1

Nous considérons la distance comme le nombre de permutations à effectuer entre deux profils d'utilisateurs, pour les rendre identiques.  
A : 035142  
B : 243150  
C : 051342

A: 035142 -> 035142 -> 035142 -> 035142   
B: 243150 -> 043152 -> 034152 -> 035142  
**Nombre de permutations (A-B)** = 3

A: 035142 -> 035142 -> 035142  
C: 051342 -> 031542 -> 035142  
**Nombre de permutations (A-C)** = 2

Ainsi, distance(A-C) < distance(A-B). Donc, le profil utilisateur le plus proche de A est C.

##Question 2

Voici les inversions de préférences entre A et B:

(2,4), (2,3), (2,1), (2,5), (2,0), (4,3), (4,1), (4,5), (4,0), (3,0), (1,5), (1,0), (5,0)

**Nombre d'invertions (A-B)** = 13

Le pire cas est donné si le tableau de préférences de B est inversé par rapport à celui de A.  
Si l'on veut obtenir le nombre d'inversions de préférences de ce cas, on aura une *Somme de i, allant de i = 0 à n*.

##Question 3

Le nombre d’inversions de *Yx* = *d(X-Y)* -> le calcul d'inversions dans UNE liste.

#Implémentation

###Remarques: implémentation en C.
=======
##Question 4

Nous allons itérer sur la liste, afin d'en établir une nouvelle en sortie - normalisée.  
Cela se fera via une boucle "For" sur la liste à normaliser (O(n)), et en utilisant une hashMap qui contiendra en clef la préférence à normaliser, et en valeur la position de cet entier dans la liste normalisée - ce qui nous fera à chaque fois un coup de O(1).  
**En tout, cet algorithme sera bien en O(n)**

##Question 5.2

Idée: 

*   Faire une boucle sur le tableau à normaliser - pointer sur l'entier courant (celui à comparer) **O(n) global**
*   Tri fusion de l'entier courant jusqu'à n **O(log)**
*   Tout ce qui sera en dessous de l'entier courant sera forcément à inverser -> on incrémente du nombre d'entiers à gauche de l'entier courant
*   Renvoyer le compteur

**En tout, cet algorithme sera bien en O(n log(n)).**

##Question 6

Les 2 méthodes à implémenter seront les questions 5.1 et 5.2, après l'algo de la question 4.

##Question 7

Sur de petits tableaux (ex1.dat à ex5.dat), la différence de temps d'exécution n'est pas visible sur notre machine de test.  
Par contre, à partir des tableaux suivants, la différence est très importante.  
Pour le fichier ex6.dat, le premier algorithme a besoin de plusieurs dizaines de secondes alors que le second est quasiment instantané.  

On constate donc que le premier algorithme en **O(n²)** devient rapidement impraticable avec de grands tableaux alors que le second en **O(n log n)** reste praticable et même efficace sur ces mêmes tableaux.