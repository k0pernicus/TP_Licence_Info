Rapport - TP5 Algorithmes et Complexité
=======================================

Auteur
------
Carette Antonin

###Exercice 3

Voici les résultats du programme, pour les différents algorithmes implémentés

##Online  
On prend les objets dans l’ordre d’énumération donné en entrée.

####Exemple 1

#####NextFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 6
i = 3 : 4
i = 4 : 2
Mode NextFit : OK
Le poids du tableau d'objets (n° 2) : 6 est supérieur à 5
```

Pas besoin d'expérimenter les autres comportements, étant donné qu'ils repéreront tous la même erreur de capacité.

####Exemple 2

#####NextFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 1
i = 3 : 5
i = 4 : 4
Mode NextFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 2, sac 0
Objet 1, poids 3, sac 0
Objet 2, poids 1, sac 1
Objet 3, poids 5, sac 2
Objet 4, poids 4, sac 3
```

#####FirstFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 1
i = 3 : 5
i = 4 : 4
Mode FirstFit : OK
Algorithme prenant ici 3 sacs
Objet 0, poids 2, sac 0
Objet 1, poids 3, sac 0
Objet 2, poids 1, sac 1
Objet 3, poids 5, sac 2
Objet 4, poids 4, sac 1
```

#####BestFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 1
i = 3 : 5
i = 4 : 4
Mode BestFit : OK
Algorithme prenant ici 3 sacs
Objet 0, poids 2, sac 0
Objet 1, poids 3, sac 0
Objet 2, poids 1, sac 1
Objet 3, poids 5, sac 2
Objet 4, poids 4, sac 1
```

####Exemple 3

#####NextFit

```
N objets: 8
Capacite: 8
Tableau de poids:
i = 0 : 1
i = 1 : 6
i = 2 : 2
i = 3 : 5
i = 4 : 8
i = 5 : 7
i = 6 : 1
i = 7 : 2
Mode NextFit : OK
Algorithme prenant ici 5 sacs
Objet 0, poids 1, sac 0
Objet 1, poids 6, sac 0
Objet 2, poids 2, sac 1
Objet 3, poids 5, sac 1
Objet 4, poids 8, sac 2
Objet 5, poids 7, sac 3
Objet 6, poids 1, sac 3
Objet 7, poids 2, sac 4
```

#####FirstFit

```
N objets: 8
Capacite: 8
Tableau de poids:
i = 0 : 1
i = 1 : 6
i = 2 : 2
i = 3 : 5
i = 4 : 8
i = 5 : 7
i = 6 : 1
i = 7 : 2
Mode FirstFit : OK
Algorithme prenant ici 5 sacs
Objet 0, poids 1, sac 0
Objet 1, poids 6, sac 0
Objet 2, poids 2, sac 1
Objet 3, poids 5, sac 1
Objet 4, poids 8, sac 2
Objet 5, poids 7, sac 3
Objet 6, poids 1, sac 0
Objet 7, poids 2, sac 4
```

#####BestFit

```
N objets: 8
Capacite: 8
Tableau de poids:
i = 0 : 1
i = 1 : 6
i = 2 : 2
i = 3 : 5
i = 4 : 8
i = 5 : 7
i = 6 : 1
i = 7 : 2
Mode BestFit : OK
Algorithme prenant ici 5 sacs
Objet 0, poids 1, sac 0
Objet 1, poids 6, sac 0
Objet 2, poids 2, sac 1
Objet 3, poids 5, sac 1
Objet 4, poids 8, sac 2
Objet 5, poids 7, sac 3
Objet 6, poids 1, sac 0
Objet 7, poids 2, sac 4
```

####Exemple 4

#####NextFit

```
N objets: 7
Capacite: 8
Tableau de poids:
i = 0 : 7
i = 1 : 6
i = 2 : 5
i = 3 : 8
i = 4 : 3
i = 5 : 2
i = 6 : 1
Mode NextFit : OK
Algorithme prenant ici 5 sacs
Objet 0, poids 7, sac 0
Objet 1, poids 6, sac 1
Objet 2, poids 5, sac 2
Objet 3, poids 8, sac 3
Objet 4, poids 3, sac 4
Objet 5, poids 2, sac 4
Objet 6, poids 1, sac 4
```

#####FirstFit

```
N objets: 7
Capacite: 8
Tableau de poids:
i = 0 : 7
i = 1 : 6
i = 2 : 5
i = 3 : 8
i = 4 : 3
i = 5 : 2
i = 6 : 1
Mode FirstFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 7, sac 0
Objet 1, poids 6, sac 1
Objet 2, poids 5, sac 2
Objet 3, poids 8, sac 3
Objet 4, poids 3, sac 2
Objet 5, poids 2, sac 1
Objet 6, poids 1, sac 0
```

#####BestFit

```
N objets: 7
Capacite: 8
Tableau de poids:
i = 0 : 7
i = 1 : 6
i = 2 : 5
i = 3 : 8
i = 4 : 3
i = 5 : 2
i = 6 : 1
Mode BestFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 7, sac 0
Objet 1, poids 6, sac 1
Objet 2, poids 5, sac 2
Objet 3, poids 8, sac 3
Objet 4, poids 3, sac 2
Objet 5, poids 2, sac 1
Objet 6, poids 1, sac 0
```

####Exemple 5

#####NextFit

```
N objets: 100
Capacite: 99
Tableau de poids:
i = 0 : 2
i = 1 : 16
i = 2 : 98
i = 3 : 56
i = 4 : 45
i = 5 : 87
i = 6 : 1
i = 7 : 1
i = 8 : 95
i = 9 : 34
i = 10 : 23
i = 11 : 56
i = 12 : 84
i = 13 : 34
i = 14 : 92
i = 15 : 99
i = 16 : 23
i = 17 : 23
i = 18 : 34
i = 19 : 85
i = 20 : 74
i = 21 : 65
i = 22 : 56
i = 23 : 23
i = 24 : 94
i = 25 : 6
i = 26 : 54
i = 27 : 45
i = 28 : 23
i = 29 : 84
i = 30 : 73
i = 31 : 23
i = 32 : 46
i = 33 : 48
i = 34 : 48
i = 35 : 18
i = 36 : 20
i = 37 : 40
i = 38 : 60
i = 39 : 56
i = 40 : 69
i = 41 : 90
i = 42 : 99
i = 43 : 49
i = 44 : 92
i = 45 : 24
i = 46 : 56
i = 47 : 78
i = 48 : 85
i = 49 : 91
i = 50 : 84
i = 51 : 41
i = 52 : 4
i = 53 : 1
i = 54 : 9
i = 55 : 59
i = 56 : 5
i = 57 : 45
i = 58 : 86
i = 59 : 10
i = 60 : 20
i = 61 : 17
i = 62 : 39
i = 63 : 78
i = 64 : 75
i = 65 : 48
i = 66 : 29
i = 67 : 28
i = 68 : 59
i = 69 : 23
i = 70 : 29
i = 71 : 56
i = 72 : 69
i = 73 : 91
i = 74 : 86
i = 75 : 74
i = 76 : 62
i = 77 : 65
i = 78 : 55
i = 79 : 35
i = 80 : 86
i = 81 : 75
i = 82 : 44
i = 83 : 91
i = 84 : 89
i = 85 : 56
i = 86 : 34
i = 87 : 84
i = 88 : 72
i = 89 : 28
i = 90 : 19
i = 91 : 22
i = 92 : 78
i = 93 : 80
i = 94 : 47
i = 95 : 51
i = 96 : 52
i = 97 : 30
i = 98 : 24
i = 99 : 39
Mode NextFit : OK
Algorithme prenant ici 69 sacs
Objet 0, poids 2, sac 0
Objet 1, poids 16, sac 0
Objet 2, poids 98, sac 1
Objet 3, poids 56, sac 2
Objet 4, poids 45, sac 3
Objet 5, poids 87, sac 4
Objet 6, poids 1, sac 4
Objet 7, poids 1, sac 4
Objet 8, poids 95, sac 5
Objet 9, poids 34, sac 6
Objet 10, poids 23, sac 6
Objet 11, poids 56, sac 7
Objet 12, poids 84, sac 8
Objet 13, poids 34, sac 9
Objet 14, poids 92, sac 10
Objet 15, poids 99, sac 11
Objet 16, poids 23, sac 12
Objet 17, poids 23, sac 12
Objet 18, poids 34, sac 12
Objet 19, poids 85, sac 13
Objet 20, poids 74, sac 14
Objet 21, poids 65, sac 15
Objet 22, poids 56, sac 16
Objet 23, poids 23, sac 16
Objet 24, poids 94, sac 17
Objet 25, poids 6, sac 18
Objet 26, poids 54, sac 18
Objet 27, poids 45, sac 19
Objet 28, poids 23, sac 19
Objet 29, poids 84, sac 20
Objet 30, poids 73, sac 21
Objet 31, poids 23, sac 21
Objet 32, poids 46, sac 22
Objet 33, poids 48, sac 22
Objet 34, poids 48, sac 23
Objet 35, poids 18, sac 23
Objet 36, poids 20, sac 23
Objet 37, poids 40, sac 24
Objet 38, poids 60, sac 25
Objet 39, poids 56, sac 26
Objet 40, poids 69, sac 27
Objet 41, poids 90, sac 28
Objet 42, poids 99, sac 29
Objet 43, poids 49, sac 30
Objet 44, poids 92, sac 31
Objet 45, poids 24, sac 32
Objet 46, poids 56, sac 32
Objet 47, poids 78, sac 33
Objet 48, poids 85, sac 34
Objet 49, poids 91, sac 35
Objet 50, poids 84, sac 36
Objet 51, poids 41, sac 37
Objet 52, poids 4, sac 37
Objet 53, poids 1, sac 37
Objet 54, poids 9, sac 37
Objet 55, poids 59, sac 38
Objet 56, poids 5, sac 38
Objet 57, poids 45, sac 39
Objet 58, poids 86, sac 40
Objet 59, poids 10, sac 40
Objet 60, poids 20, sac 41
Objet 61, poids 17, sac 41
Objet 62, poids 39, sac 41
Objet 63, poids 78, sac 42
Objet 64, poids 75, sac 43
Objet 65, poids 48, sac 44
Objet 66, poids 29, sac 44
Objet 67, poids 28, sac 45
Objet 68, poids 59, sac 45
Objet 69, poids 23, sac 46
Objet 70, poids 29, sac 46
Objet 71, poids 56, sac 47
Objet 72, poids 69, sac 48
Objet 73, poids 91, sac 49
Objet 74, poids 86, sac 50
Objet 75, poids 74, sac 51
Objet 76, poids 62, sac 52
Objet 77, poids 65, sac 53
Objet 78, poids 55, sac 54
Objet 79, poids 35, sac 54
Objet 80, poids 86, sac 55
Objet 81, poids 75, sac 56
Objet 82, poids 44, sac 57
Objet 83, poids 91, sac 58
Objet 84, poids 89, sac 59
Objet 85, poids 56, sac 60
Objet 86, poids 34, sac 60
Objet 87, poids 84, sac 61
Objet 88, poids 72, sac 62
Objet 89, poids 28, sac 63
Objet 90, poids 19, sac 63
Objet 91, poids 22, sac 63
Objet 92, poids 78, sac 64
Objet 93, poids 80, sac 65
Objet 94, poids 47, sac 66
Objet 95, poids 51, sac 66
Objet 96, poids 52, sac 67
Objet 97, poids 30, sac 67
Objet 98, poids 24, sac 68
Objet 99, poids 39, sac 68
```

#####FirstFit

```
N objets: 100
Capacite: 99
Tableau de poids:
i = 0 : 2
i = 1 : 16
i = 2 : 98
i = 3 : 56
i = 4 : 45
i = 5 : 87
i = 6 : 1
i = 7 : 1
i = 8 : 95
i = 9 : 34
i = 10 : 23
i = 11 : 56
i = 12 : 84
i = 13 : 34
i = 14 : 92
i = 15 : 99
i = 16 : 23
i = 17 : 23
i = 18 : 34
i = 19 : 85
i = 20 : 74
i = 21 : 65
i = 22 : 56
i = 23 : 23
i = 24 : 94
i = 25 : 6
i = 26 : 54
i = 27 : 45
i = 28 : 23
i = 29 : 84
i = 30 : 73
i = 31 : 23
i = 32 : 46
i = 33 : 48
i = 34 : 48
i = 35 : 18
i = 36 : 20
i = 37 : 40
i = 38 : 60
i = 39 : 56
i = 40 : 69
i = 41 : 90
i = 42 : 99
i = 43 : 49
i = 44 : 92
i = 45 : 24
i = 46 : 56
i = 47 : 78
i = 48 : 85
i = 49 : 91
i = 50 : 84
i = 51 : 41
i = 52 : 4
i = 53 : 1
i = 54 : 9
i = 55 : 59
i = 56 : 5
i = 57 : 45
i = 58 : 86
i = 59 : 10
i = 60 : 20
i = 61 : 17
i = 62 : 39
i = 63 : 78
i = 64 : 75
i = 65 : 48
i = 66 : 29
i = 67 : 28
i = 68 : 59
i = 69 : 23
i = 70 : 29
i = 71 : 56
i = 72 : 69
i = 73 : 91
i = 74 : 86
i = 75 : 74
i = 76 : 62
i = 77 : 65
i = 78 : 55
i = 79 : 35
i = 80 : 86
i = 81 : 75
i = 82 : 44
i = 83 : 91
i = 84 : 89
i = 85 : 56
i = 86 : 34
i = 87 : 84
i = 88 : 72
i = 89 : 28
i = 90 : 19
i = 91 : 22
i = 92 : 78
i = 93 : 80
i = 94 : 47
i = 95 : 51
i = 96 : 52
i = 97 : 30
i = 98 : 24
i = 99 : 39
Mode FirstFit : OK
Algorithme prenant ici 57 sacs
Objet 0, poids 2, sac 0
Objet 1, poids 16, sac 0
Objet 2, poids 98, sac 1
Objet 3, poids 56, sac 0
Objet 4, poids 45, sac 2
Objet 5, poids 87, sac 3
Objet 6, poids 1, sac 0
Objet 7, poids 1, sac 0
Objet 8, poids 95, sac 4
Objet 9, poids 34, sac 2
Objet 10, poids 23, sac 0
Objet 11, poids 56, sac 5
Objet 12, poids 84, sac 6
Objet 13, poids 34, sac 5
Objet 14, poids 92, sac 7
Objet 15, poids 99, sac 8
Objet 16, poids 23, sac 9
Objet 17, poids 23, sac 9
Objet 18, poids 34, sac 9
Objet 19, poids 85, sac 10
Objet 20, poids 74, sac 11
Objet 21, poids 65, sac 12
Objet 22, poids 56, sac 13
Objet 23, poids 23, sac 11
Objet 24, poids 94, sac 14
Objet 25, poids 6, sac 2
Objet 26, poids 54, sac 15
Objet 27, poids 45, sac 15
Objet 28, poids 23, sac 12
Objet 29, poids 84, sac 16
Objet 30, poids 73, sac 17
Objet 31, poids 23, sac 13
Objet 32, poids 46, sac 18
Objet 33, poids 48, sac 18
Objet 34, poids 48, sac 19
Objet 35, poids 18, sac 9
Objet 36, poids 20, sac 13
Objet 37, poids 40, sac 19
Objet 38, poids 60, sac 20
Objet 39, poids 56, sac 21
Objet 40, poids 69, sac 22
Objet 41, poids 90, sac 23
Objet 42, poids 99, sac 24
Objet 43, poids 49, sac 25
Objet 44, poids 92, sac 26
Objet 45, poids 24, sac 17
Objet 46, poids 56, sac 27
Objet 47, poids 78, sac 28
Objet 48, poids 85, sac 29
Objet 49, poids 91, sac 30
Objet 50, poids 84, sac 31
Objet 51, poids 41, sac 21
Objet 52, poids 4, sac 2
Objet 53, poids 1, sac 1
Objet 54, poids 9, sac 2
Objet 55, poids 59, sac 32
Objet 56, poids 5, sac 3
Objet 57, poids 45, sac 25
Objet 58, poids 86, sac 33
Objet 59, poids 10, sac 6
Objet 60, poids 20, sac 20
Objet 61, poids 17, sac 20
Objet 62, poids 39, sac 27
Objet 63, poids 78, sac 34
Objet 64, poids 75, sac 35
Objet 65, poids 48, sac 36
Objet 66, poids 29, sac 22
Objet 67, poids 28, sac 32
Objet 68, poids 59, sac 37
Objet 69, poids 23, sac 35
Objet 70, poids 29, sac 36
Objet 71, poids 56, sac 38
Objet 72, poids 69, sac 39
Objet 73, poids 91, sac 40
Objet 74, poids 86, sac 41
Objet 75, poids 74, sac 42
Objet 76, poids 62, sac 43
Objet 77, poids 65, sac 44
Objet 78, poids 55, sac 45
Objet 79, poids 35, sac 37
Objet 80, poids 86, sac 46
Objet 81, poids 75, sac 47
Objet 82, poids 44, sac 45
Objet 83, poids 91, sac 48
Objet 84, poids 89, sac 49
Objet 85, poids 56, sac 50
Objet 86, poids 34, sac 38
Objet 87, poids 84, sac 51
Objet 88, poids 72, sac 52
Objet 89, poids 28, sac 39
Objet 90, poids 19, sac 28
Objet 91, poids 22, sac 36
Objet 92, poids 78, sac 53
Objet 93, poids 80, sac 54
Objet 94, poids 47, sac 55
Objet 95, poids 51, sac 55
Objet 96, poids 52, sac 56
Objet 97, poids 30, sac 43
Objet 98, poids 24, sac 42
Objet 99, poids 39, sac 50
```

#####BestFit

```
N objets: 100
Capacite: 99
Tableau de poids:
i = 0 : 2
i = 1 : 16
i = 2 : 98
i = 3 : 56
i = 4 : 45
i = 5 : 87
i = 6 : 1
i = 7 : 1
i = 8 : 95
i = 9 : 34
i = 10 : 23
i = 11 : 56
i = 12 : 84
i = 13 : 34
i = 14 : 92
i = 15 : 99
i = 16 : 23
i = 17 : 23
i = 18 : 34
i = 19 : 85
i = 20 : 74
i = 21 : 65
i = 22 : 56
i = 23 : 23
i = 24 : 94
i = 25 : 6
i = 26 : 54
i = 27 : 45
i = 28 : 23
i = 29 : 84
i = 30 : 73
i = 31 : 23
i = 32 : 46
i = 33 : 48
i = 34 : 48
i = 35 : 18
i = 36 : 20
i = 37 : 40
i = 38 : 60
i = 39 : 56
i = 40 : 69
i = 41 : 90
i = 42 : 99
i = 43 : 49
i = 44 : 92
i = 45 : 24
i = 46 : 56
i = 47 : 78
i = 48 : 85
i = 49 : 91
i = 50 : 84
i = 51 : 41
i = 52 : 4
i = 53 : 1
i = 54 : 9
i = 55 : 59
i = 56 : 5
i = 57 : 45
i = 58 : 86
i = 59 : 10
i = 60 : 20
i = 61 : 17
i = 62 : 39
i = 63 : 78
i = 64 : 75
i = 65 : 48
i = 66 : 29
i = 67 : 28
i = 68 : 59
i = 69 : 23
i = 70 : 29
i = 71 : 56
i = 72 : 69
i = 73 : 91
i = 74 : 86
i = 75 : 74
i = 76 : 62
i = 77 : 65
i = 78 : 55
i = 79 : 35
i = 80 : 86
i = 81 : 75
i = 82 : 44
i = 83 : 91
i = 84 : 89
i = 85 : 56
i = 86 : 34
i = 87 : 84
i = 88 : 72
i = 89 : 28
i = 90 : 19
i = 91 : 22
i = 92 : 78
i = 93 : 80
i = 94 : 47
i = 95 : 51
i = 96 : 52
i = 97 : 30
i = 98 : 24
i = 99 : 39
Mode BestFit : OK
Algorithme prenant ici 56 sacs
Objet 0, poids 2, sac 0
Objet 1, poids 16, sac 0
Objet 2, poids 98, sac 1
Objet 3, poids 56, sac 0
Objet 4, poids 45, sac 2
Objet 5, poids 87, sac 3
Objet 6, poids 1, sac 1
Objet 7, poids 1, sac 3
Objet 8, poids 95, sac 4
Objet 9, poids 34, sac 2
Objet 10, poids 23, sac 0
Objet 11, poids 56, sac 5
Objet 12, poids 84, sac 6
Objet 13, poids 34, sac 5
Objet 14, poids 92, sac 7
Objet 15, poids 99, sac 8
Objet 16, poids 23, sac 9
Objet 17, poids 23, sac 9
Objet 18, poids 34, sac 9
Objet 19, poids 85, sac 10
Objet 20, poids 74, sac 11
Objet 21, poids 65, sac 12
Objet 22, poids 56, sac 13
Objet 23, poids 23, sac 11
Objet 24, poids 94, sac 14
Objet 25, poids 6, sac 7
Objet 26, poids 54, sac 15
Objet 27, poids 45, sac 15
Objet 28, poids 23, sac 12
Objet 29, poids 84, sac 16
Objet 30, poids 73, sac 17
Objet 31, poids 23, sac 17
Objet 32, poids 46, sac 18
Objet 33, poids 48, sac 18
Objet 34, poids 48, sac 19
Objet 35, poids 18, sac 9
Objet 36, poids 20, sac 2
Objet 37, poids 40, sac 13
Objet 38, poids 60, sac 20
Objet 39, poids 56, sac 21
Objet 40, poids 69, sac 22
Objet 41, poids 90, sac 23
Objet 42, poids 99, sac 24
Objet 43, poids 49, sac 19
Objet 44, poids 92, sac 25
Objet 45, poids 24, sac 22
Objet 46, poids 56, sac 26
Objet 47, poids 78, sac 27
Objet 48, poids 85, sac 28
Objet 49, poids 91, sac 29
Objet 50, poids 84, sac 30
Objet 51, poids 41, sac 21
Objet 52, poids 4, sac 4
Objet 53, poids 1, sac 7
Objet 54, poids 9, sac 5
Objet 55, poids 59, sac 31
Objet 56, poids 5, sac 14
Objet 57, poids 45, sac 32
Objet 58, poids 86, sac 33
Objet 59, poids 10, sac 3
Objet 60, poids 20, sac 27
Objet 61, poids 17, sac 20
Objet 62, poids 39, sac 31
Objet 63, poids 78, sac 34
Objet 64, poids 75, sac 35
Objet 65, poids 48, sac 32
Objet 66, poids 29, sac 26
Objet 67, poids 28, sac 36
Objet 68, poids 59, sac 36
Objet 69, poids 23, sac 35
Objet 70, poids 29, sac 37
Objet 71, poids 56, sac 37
Objet 72, poids 69, sac 38
Objet 73, poids 91, sac 39
Objet 74, poids 86, sac 40
Objet 75, poids 74, sac 41
Objet 76, poids 62, sac 42
Objet 77, poids 65, sac 43
Objet 78, poids 55, sac 44
Objet 79, poids 35, sac 42
Objet 80, poids 86, sac 45
Objet 81, poids 75, sac 46
Objet 82, poids 44, sac 44
Objet 83, poids 91, sac 47
Objet 84, poids 89, sac 48
Objet 85, poids 56, sac 49
Objet 86, poids 34, sac 43
Objet 87, poids 84, sac 50
Objet 88, poids 72, sac 51
Objet 89, poids 28, sac 38
Objet 90, poids 19, sac 34
Objet 91, poids 22, sac 20
Objet 92, poids 78, sac 52
Objet 93, poids 80, sac 53
Objet 94, poids 47, sac 54
Objet 95, poids 51, sac 54
Objet 96, poids 52, sac 55
Objet 97, poids 30, sac 49
Objet 98, poids 24, sac 46
Objet 99, poids 39, sac 55
```

##Offline  
Trie les objets par poids décroissants.

####Exemple 2

#####NextFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 1
i = 3 : 5
i = 4 : 4
Offline mode : OK
5 4 3 2 1
Mode NextFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 5, sac 0
Objet 1, poids 4, sac 1
Objet 2, poids 3, sac 2
Objet 3, poids 2, sac 2
Objet 4, poids 1, sac 3
```

#####FirstFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 1
i = 3 : 5
i = 4 : 4
Offline mode : OK
5 4 3 2 1
Mode FirstFit : OK
Algorithme prenant ici 3 sacs
Objet 0, poids 5, sac 0
Objet 1, poids 4, sac 1
Objet 2, poids 3, sac 2
Objet 3, poids 2, sac 2
Objet 4, poids 1, sac 1
```

#####BestFit

```
N objets: 5
Capacite: 5
Tableau de poids:
i = 0 : 2
i = 1 : 3
i = 2 : 1
i = 3 : 5
i = 4 : 4
Offline mode : OK
5 4 3 2 1
Mode BestFit : OK
Algorithme prenant ici 3 sacs
Objet 0, poids 5, sac 0
Objet 1, poids 4, sac 1
Objet 2, poids 3, sac 2
Objet 3, poids 2, sac 2
Objet 4, poids 1, sac 1
```

####Exemple 3

#####NextFit

```
N objets: 8
Capacite: 8
Tableau de poids:
i = 0 : 1
i = 1 : 6
i = 2 : 2
i = 3 : 5
i = 4 : 8
i = 5 : 7
i = 6 : 1
i = 7 : 2
Offline mode : OK
8 7 6 5 2 2 1 1
Mode NextFit : OK
Algorithme prenant ici 5 sacs
Objet 0, poids 8, sac 0
Objet 1, poids 7, sac 1
Objet 2, poids 6, sac 2
Objet 3, poids 5, sac 3
Objet 4, poids 2, sac 3
Objet 5, poids 2, sac 4
Objet 6, poids 1, sac 4
Objet 7, poids 1, sac 4
```

#####FirstFit

```
N objets: 8
Capacite: 8
Tableau de poids:
i = 0 : 1
i = 1 : 6
i = 2 : 2
i = 3 : 5
i = 4 : 8
i = 5 : 7
i = 6 : 1
i = 7 : 2
Offline mode : OK
8 7 6 5 2 2 1 1
Mode FirstFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 8, sac 0
Objet 1, poids 7, sac 1
Objet 2, poids 6, sac 2
Objet 3, poids 5, sac 3
Objet 4, poids 2, sac 2
Objet 5, poids 2, sac 3
Objet 6, poids 1, sac 1
Objet 7, poids 1, sac 3
```

#####BestFit

```
N objets: 8
Capacite: 8
Tableau de poids:
i = 0 : 1
i = 1 : 6
i = 2 : 2
i = 3 : 5
i = 4 : 8
i = 5 : 7
i = 6 : 1
i = 7 : 2
Offline mode : OK
8 7 6 5 2 2 1 1
Mode BestFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 8, sac 0
Objet 1, poids 7, sac 1
Objet 2, poids 6, sac 2
Objet 3, poids 5, sac 3
Objet 4, poids 2, sac 2
Objet 5, poids 2, sac 3
Objet 6, poids 1, sac 1
Objet 7, poids 1, sac 3
```

####Exemple 4

#####NextFit

```
N objets: 7
Capacite: 8
Tableau de poids:
i = 0 : 7
i = 1 : 6
i = 2 : 5
i = 3 : 8
i = 4 : 3
i = 5 : 2
i = 6 : 1
Offline mode : OK
8 7 6 5 3 2 1
Mode NextFit : OK
Algorithme prenant ici 5 sacs
Objet 0, poids 8, sac 0
Objet 1, poids 7, sac 1
Objet 2, poids 6, sac 2
Objet 3, poids 5, sac 3
Objet 4, poids 3, sac 3
Objet 5, poids 2, sac 4
Objet 6, poids 1, sac 4
```

#####FirstFit

```
N objets: 7
Capacite: 8
Tableau de poids:
i = 0 : 7
i = 1 : 6
i = 2 : 5
i = 3 : 8
i = 4 : 3
i = 5 : 2
i = 6 : 1
Offline mode : OK
8 7 6 5 3 2 1
Mode FirstFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 8, sac 0
Objet 1, poids 7, sac 1
Objet 2, poids 6, sac 2
Objet 3, poids 5, sac 3
Objet 4, poids 3, sac 3
Objet 5, poids 2, sac 2
Objet 6, poids 1, sac 1
```

#####BestFit

```
N objets: 7
Capacite: 8
Tableau de poids:
i = 0 : 7
i = 1 : 6
i = 2 : 5
i = 3 : 8
i = 4 : 3
i = 5 : 2
i = 6 : 1
Offline mode : OK
8 7 6 5 3 2 1
Mode BestFit : OK
Algorithme prenant ici 4 sacs
Objet 0, poids 8, sac 0
Objet 1, poids 7, sac 1
Objet 2, poids 6, sac 2
Objet 3, poids 5, sac 3
Objet 4, poids 3, sac 3
Objet 5, poids 2, sac 2
Objet 6, poids 1, sac 1
```

####Exemple 5

#####NextFit

```
N objets: 100
Capacite: 99
Tableau de poids:
i = 0 : 2
i = 1 : 16
i = 2 : 98
i = 3 : 56
i = 4 : 45
i = 5 : 87
i = 6 : 1
i = 7 : 1
i = 8 : 95
i = 9 : 34
i = 10 : 23
i = 11 : 56
i = 12 : 84
i = 13 : 34
i = 14 : 92
i = 15 : 99
i = 16 : 23
i = 17 : 23
i = 18 : 34
i = 19 : 85
i = 20 : 74
i = 21 : 65
i = 22 : 56
i = 23 : 23
i = 24 : 94
i = 25 : 6
i = 26 : 54
i = 27 : 45
i = 28 : 23
i = 29 : 84
i = 30 : 73
i = 31 : 23
i = 32 : 46
i = 33 : 48
i = 34 : 48
i = 35 : 18
i = 36 : 20
i = 37 : 40
i = 38 : 60
i = 39 : 56
i = 40 : 69
i = 41 : 90
i = 42 : 99
i = 43 : 49
i = 44 : 92
i = 45 : 24
i = 46 : 56
i = 47 : 78
i = 48 : 85
i = 49 : 91
i = 50 : 84
i = 51 : 41
i = 52 : 4
i = 53 : 1
i = 54 : 9
i = 55 : 59
i = 56 : 5
i = 57 : 45
i = 58 : 86
i = 59 : 10
i = 60 : 20
i = 61 : 17
i = 62 : 39
i = 63 : 78
i = 64 : 75
i = 65 : 48
i = 66 : 29
i = 67 : 28
i = 68 : 59
i = 69 : 23
i = 70 : 29
i = 71 : 56
i = 72 : 69
i = 73 : 91
i = 74 : 86
i = 75 : 74
i = 76 : 62
i = 77 : 65
i = 78 : 55
i = 79 : 35
i = 80 : 86
i = 81 : 75
i = 82 : 44
i = 83 : 91
i = 84 : 89
i = 85 : 56
i = 86 : 34
i = 87 : 84
i = 88 : 72
i = 89 : 28
i = 90 : 19
i = 91 : 22
i = 92 : 78
i = 93 : 80
i = 94 : 47
i = 95 : 51
i = 96 : 52
i = 97 : 30
i = 98 : 24
i = 99 : 39
Offline mode : OK
99 99 98 95 94 92 92 91 91 91 90 89 87 86 86 86 85 85 84 84 84 84 80 78 78 78 75 75 74 74 73 72 69 69 65 65 62 60 59 59 56 56 56 56 56 56 56 55 54 52 51 49 48 48 48 47 46 45 45 45 44 41 40 39 39 35 34 34 34 34 30 29 29 28 28 24 24 23 23 23 23 23 23 23 22 20 20 19 18 17 16 10 9 6 5 4 2 1 1 1
Mode NextFit : OK
Algorithme prenant ici 67 sacs
Objet 0, poids 99, sac 0
Objet 1, poids 99, sac 1
Objet 2, poids 98, sac 2
Objet 3, poids 95, sac 3
Objet 4, poids 94, sac 4
Objet 5, poids 92, sac 5
Objet 6, poids 92, sac 6
Objet 7, poids 91, sac 7
Objet 8, poids 91, sac 8
Objet 9, poids 91, sac 9
Objet 10, poids 90, sac 10
Objet 11, poids 89, sac 11
Objet 12, poids 87, sac 12
Objet 13, poids 86, sac 13
Objet 14, poids 86, sac 14
Objet 15, poids 86, sac 15
Objet 16, poids 85, sac 16
Objet 17, poids 85, sac 17
Objet 18, poids 84, sac 18
Objet 19, poids 84, sac 19
Objet 20, poids 84, sac 20
Objet 21, poids 84, sac 21
Objet 22, poids 80, sac 22
Objet 23, poids 78, sac 23
Objet 24, poids 78, sac 24
Objet 25, poids 78, sac 25
Objet 26, poids 75, sac 26
Objet 27, poids 75, sac 27
Objet 28, poids 74, sac 28
Objet 29, poids 74, sac 29
Objet 30, poids 73, sac 30
Objet 31, poids 72, sac 31
Objet 32, poids 69, sac 32
Objet 33, poids 69, sac 33
Objet 34, poids 65, sac 34
Objet 35, poids 65, sac 35
Objet 36, poids 62, sac 36
Objet 37, poids 60, sac 37
Objet 38, poids 59, sac 38
Objet 39, poids 59, sac 39
Objet 40, poids 56, sac 40
Objet 41, poids 56, sac 41
Objet 42, poids 56, sac 42
Objet 43, poids 56, sac 43
Objet 44, poids 56, sac 44
Objet 45, poids 56, sac 45
Objet 46, poids 56, sac 46
Objet 47, poids 55, sac 47
Objet 48, poids 54, sac 48
Objet 49, poids 52, sac 49
Objet 50, poids 51, sac 50
Objet 51, poids 49, sac 51
Objet 52, poids 48, sac 51
Objet 53, poids 48, sac 52
Objet 54, poids 48, sac 52
Objet 55, poids 47, sac 53
Objet 56, poids 46, sac 53
Objet 57, poids 45, sac 54
Objet 58, poids 45, sac 54
Objet 59, poids 45, sac 55
Objet 60, poids 44, sac 55
Objet 61, poids 41, sac 56
Objet 62, poids 40, sac 56
Objet 63, poids 39, sac 57
Objet 64, poids 39, sac 57
Objet 65, poids 35, sac 58
Objet 66, poids 34, sac 58
Objet 67, poids 34, sac 59
Objet 68, poids 34, sac 59
Objet 69, poids 34, sac 60
Objet 70, poids 30, sac 60
Objet 71, poids 29, sac 60
Objet 72, poids 29, sac 61
Objet 73, poids 28, sac 61
Objet 74, poids 28, sac 61
Objet 75, poids 24, sac 62
Objet 76, poids 24, sac 62
Objet 77, poids 23, sac 62
Objet 78, poids 23, sac 62
Objet 79, poids 23, sac 63
Objet 80, poids 23, sac 63
Objet 81, poids 23, sac 63
Objet 82, poids 23, sac 63
Objet 83, poids 23, sac 64
Objet 84, poids 22, sac 64
Objet 85, poids 20, sac 64
Objet 86, poids 20, sac 64
Objet 87, poids 19, sac 65
Objet 88, poids 18, sac 65
Objet 89, poids 17, sac 65
Objet 90, poids 16, sac 65
Objet 91, poids 10, sac 65
Objet 92, poids 9, sac 65
Objet 93, poids 6, sac 65
Objet 94, poids 5, sac 66
Objet 95, poids 4, sac 66
Objet 96, poids 2, sac 66
Objet 97, poids 1, sac 66
Objet 98, poids 1, sac 66
Objet 99, poids 1, sac 66
```

#####FirstFit

```
N objets: 100
Capacite: 99
Tableau de poids:
i = 0 : 2
i = 1 : 16
i = 2 : 98
i = 3 : 56
i = 4 : 45
i = 5 : 87
i = 6 : 1
i = 7 : 1
i = 8 : 95
i = 9 : 34
i = 10 : 23
i = 11 : 56
i = 12 : 84
i = 13 : 34
i = 14 : 92
i = 15 : 99
i = 16 : 23
i = 17 : 23
i = 18 : 34
i = 19 : 85
i = 20 : 74
i = 21 : 65
i = 22 : 56
i = 23 : 23
i = 24 : 94
i = 25 : 6
i = 26 : 54
i = 27 : 45
i = 28 : 23
i = 29 : 84
i = 30 : 73
i = 31 : 23
i = 32 : 46
i = 33 : 48
i = 34 : 48
i = 35 : 18
i = 36 : 20
i = 37 : 40
i = 38 : 60
i = 39 : 56
i = 40 : 69
i = 41 : 90
i = 42 : 99
i = 43 : 49
i = 44 : 92
i = 45 : 24
i = 46 : 56
i = 47 : 78
i = 48 : 85
i = 49 : 91
i = 50 : 84
i = 51 : 41
i = 52 : 4
i = 53 : 1
i = 54 : 9
i = 55 : 59
i = 56 : 5
i = 57 : 45
i = 58 : 86
i = 59 : 10
i = 60 : 20
i = 61 : 17
i = 62 : 39
i = 63 : 78
i = 64 : 75
i = 65 : 48
i = 66 : 29
i = 67 : 28
i = 68 : 59
i = 69 : 23
i = 70 : 29
i = 71 : 56
i = 72 : 69
i = 73 : 91
i = 74 : 86
i = 75 : 74
i = 76 : 62
i = 77 : 65
i = 78 : 55
i = 79 : 35
i = 80 : 86
i = 81 : 75
i = 82 : 44
i = 83 : 91
i = 84 : 89
i = 85 : 56
i = 86 : 34
i = 87 : 84
i = 88 : 72
i = 89 : 28
i = 90 : 19
i = 91 : 22
i = 92 : 78
i = 93 : 80
i = 94 : 47
i = 95 : 51
i = 96 : 52
i = 97 : 30
i = 98 : 24
i = 99 : 39
Offline mode : OK
99 99 98 95 94 92 92 91 91 91 90 89 87 86 86 86 85 85 84 84 84 84 80 78 78 78 75 75 74 74 73 72 69 69 65 65 62 60 59 59 56 56 56 56 56 56 56 55 54 52 51 49 48 48 48 47 46 45 45 45 44 41 40 39 39 35 34 34 34 34 30 29 29 28 28 24 24 23 23 23 23 23 23 23 22 20 20 19 18 17 16 10 9 6 5 4 2 1 1 1
Mode FirstFit : OK
Algorithme prenant ici 55 sacs
Objet 0, poids 99, sac 0
Objet 1, poids 99, sac 1
Objet 2, poids 98, sac 2
Objet 3, poids 95, sac 3
Objet 4, poids 94, sac 4
Objet 5, poids 92, sac 5
Objet 6, poids 92, sac 6
Objet 7, poids 91, sac 7
Objet 8, poids 91, sac 8
Objet 9, poids 91, sac 9
Objet 10, poids 90, sac 10
Objet 11, poids 89, sac 11
Objet 12, poids 87, sac 12
Objet 13, poids 86, sac 13
Objet 14, poids 86, sac 14
Objet 15, poids 86, sac 15
Objet 16, poids 85, sac 16
Objet 17, poids 85, sac 17
Objet 18, poids 84, sac 18
Objet 19, poids 84, sac 19
Objet 20, poids 84, sac 20
Objet 21, poids 84, sac 21
Objet 22, poids 80, sac 22
Objet 23, poids 78, sac 23
Objet 24, poids 78, sac 24
Objet 25, poids 78, sac 25
Objet 26, poids 75, sac 26
Objet 27, poids 75, sac 27
Objet 28, poids 74, sac 28
Objet 29, poids 74, sac 29
Objet 30, poids 73, sac 30
Objet 31, poids 72, sac 31
Objet 32, poids 69, sac 32
Objet 33, poids 69, sac 33
Objet 34, poids 65, sac 34
Objet 35, poids 65, sac 35
Objet 36, poids 62, sac 36
Objet 37, poids 60, sac 37
Objet 38, poids 59, sac 38
Objet 39, poids 59, sac 39
Objet 40, poids 56, sac 40
Objet 41, poids 56, sac 41
Objet 42, poids 56, sac 42
Objet 43, poids 56, sac 43
Objet 44, poids 56, sac 44
Objet 45, poids 56, sac 45
Objet 46, poids 56, sac 46
Objet 47, poids 55, sac 47
Objet 48, poids 54, sac 48
Objet 49, poids 52, sac 49
Objet 50, poids 51, sac 50
Objet 51, poids 49, sac 51
Objet 52, poids 48, sac 50
Objet 53, poids 48, sac 51
Objet 54, poids 48, sac 52
Objet 55, poids 47, sac 49
Objet 56, poids 46, sac 52
Objet 57, poids 45, sac 48
Objet 58, poids 45, sac 53
Objet 59, poids 45, sac 53
Objet 60, poids 44, sac 47
Objet 61, poids 41, sac 40
Objet 62, poids 40, sac 38
Objet 63, poids 39, sac 37
Objet 64, poids 39, sac 39
Objet 65, poids 35, sac 36
Objet 66, poids 34, sac 34
Objet 67, poids 34, sac 35
Objet 68, poids 34, sac 41
Objet 69, poids 34, sac 42
Objet 70, poids 30, sac 32
Objet 71, poids 29, sac 33
Objet 72, poids 29, sac 43
Objet 73, poids 28, sac 44
Objet 74, poids 28, sac 45
Objet 75, poids 24, sac 26
Objet 76, poids 24, sac 27
Objet 77, poids 23, sac 28
Objet 78, poids 23, sac 29
Objet 79, poids 23, sac 30
Objet 80, poids 23, sac 31
Objet 81, poids 23, sac 46
Objet 82, poids 23, sac 54
Objet 83, poids 23, sac 54
Objet 84, poids 22, sac 54
Objet 85, poids 20, sac 23
Objet 86, poids 20, sac 24
Objet 87, poids 19, sac 22
Objet 88, poids 18, sac 25
Objet 89, poids 17, sac 46
Objet 90, poids 16, sac 54
Objet 91, poids 10, sac 11
Objet 92, poids 9, sac 10
Objet 93, poids 6, sac 5
Objet 94, poids 5, sac 4
Objet 95, poids 4, sac 3
Objet 96, poids 2, sac 6
Objet 97, poids 1, sac 2
Objet 98, poids 1, sac 5
Objet 99, poids 1, sac 6
```

#####BestFit

```
N objets: 100
Capacite: 99
Tableau de poids:
i = 0 : 2
i = 1 : 16
i = 2 : 98
i = 3 : 56
i = 4 : 45
i = 5 : 87
i = 6 : 1
i = 7 : 1
i = 8 : 95
i = 9 : 34
i = 10 : 23
i = 11 : 56
i = 12 : 84
i = 13 : 34
i = 14 : 92
i = 15 : 99
i = 16 : 23
i = 17 : 23
i = 18 : 34
i = 19 : 85
i = 20 : 74
i = 21 : 65
i = 22 : 56
i = 23 : 23
i = 24 : 94
i = 25 : 6
i = 26 : 54
i = 27 : 45
i = 28 : 23
i = 29 : 84
i = 30 : 73
i = 31 : 23
i = 32 : 46
i = 33 : 48
i = 34 : 48
i = 35 : 18
i = 36 : 20
i = 37 : 40
i = 38 : 60
i = 39 : 56
i = 40 : 69
i = 41 : 90
i = 42 : 99
i = 43 : 49
i = 44 : 92
i = 45 : 24
i = 46 : 56
i = 47 : 78
i = 48 : 85
i = 49 : 91
i = 50 : 84
i = 51 : 41
i = 52 : 4
i = 53 : 1
i = 54 : 9
i = 55 : 59
i = 56 : 5
i = 57 : 45
i = 58 : 86
i = 59 : 10
i = 60 : 20
i = 61 : 17
i = 62 : 39
i = 63 : 78
i = 64 : 75
i = 65 : 48
i = 66 : 29
i = 67 : 28
i = 68 : 59
i = 69 : 23
i = 70 : 29
i = 71 : 56
i = 72 : 69
i = 73 : 91
i = 74 : 86
i = 75 : 74
i = 76 : 62
i = 77 : 65
i = 78 : 55
i = 79 : 35
i = 80 : 86
i = 81 : 75
i = 82 : 44
i = 83 : 91
i = 84 : 89
i = 85 : 56
i = 86 : 34
i = 87 : 84
i = 88 : 72
i = 89 : 28
i = 90 : 19
i = 91 : 22
i = 92 : 78
i = 93 : 80
i = 94 : 47
i = 95 : 51
i = 96 : 52
i = 97 : 30
i = 98 : 24
i = 99 : 39
Offline mode : OK
99 99 98 95 94 92 92 91 91 91 90 89 87 86 86 86 85 85 84 84 84 84 80 78 78 78 75 75 74 74 73 72 69 69 65 65 62 60 59 59 56 56 56 56 56 56 56 55 54 52 51 49 48 48 48 47 46 45 45 45 44 41 40 39 39 35 34 34 34 34 30 29 29 28 28 24 24 23 23 23 23 23 23 23 22 20 20 19 18 17 16 10 9 6 5 4 2 1 1 1
Mode BestFit : OK
Algorithme prenant ici 55 sacs
Objet 0, poids 99, sac 0
Objet 1, poids 99, sac 1
Objet 2, poids 98, sac 2
Objet 3, poids 95, sac 3
Objet 4, poids 94, sac 4
Objet 5, poids 92, sac 5
Objet 6, poids 92, sac 6
Objet 7, poids 91, sac 7
Objet 8, poids 91, sac 8
Objet 9, poids 91, sac 9
Objet 10, poids 90, sac 10
Objet 11, poids 89, sac 11
Objet 12, poids 87, sac 12
Objet 13, poids 86, sac 13
Objet 14, poids 86, sac 14
Objet 15, poids 86, sac 15
Objet 16, poids 85, sac 16
Objet 17, poids 85, sac 17
Objet 18, poids 84, sac 18
Objet 19, poids 84, sac 19
Objet 20, poids 84, sac 20
Objet 21, poids 84, sac 21
Objet 22, poids 80, sac 22
Objet 23, poids 78, sac 23
Objet 24, poids 78, sac 24
Objet 25, poids 78, sac 25
Objet 26, poids 75, sac 26
Objet 27, poids 75, sac 27
Objet 28, poids 74, sac 28
Objet 29, poids 74, sac 29
Objet 30, poids 73, sac 30
Objet 31, poids 72, sac 31
Objet 32, poids 69, sac 32
Objet 33, poids 69, sac 33
Objet 34, poids 65, sac 34
Objet 35, poids 65, sac 35
Objet 36, poids 62, sac 36
Objet 37, poids 60, sac 37
Objet 38, poids 59, sac 38
Objet 39, poids 59, sac 39
Objet 40, poids 56, sac 40
Objet 41, poids 56, sac 41
Objet 42, poids 56, sac 42
Objet 43, poids 56, sac 43
Objet 44, poids 56, sac 44
Objet 45, poids 56, sac 45
Objet 46, poids 56, sac 46
Objet 47, poids 55, sac 47
Objet 48, poids 54, sac 48
Objet 49, poids 52, sac 49
Objet 50, poids 51, sac 50
Objet 51, poids 49, sac 51
Objet 52, poids 48, sac 50
Objet 53, poids 48, sac 51
Objet 54, poids 48, sac 52
Objet 55, poids 47, sac 49
Objet 56, poids 46, sac 52
Objet 57, poids 45, sac 48
Objet 58, poids 45, sac 53
Objet 59, poids 45, sac 53
Objet 60, poids 44, sac 47
Objet 61, poids 41, sac 40
Objet 62, poids 40, sac 38
Objet 63, poids 39, sac 37
Objet 64, poids 39, sac 39
Objet 65, poids 35, sac 36
Objet 66, poids 34, sac 34
Objet 67, poids 34, sac 35
Objet 68, poids 34, sac 41
Objet 69, poids 34, sac 42
Objet 70, poids 30, sac 32
Objet 71, poids 29, sac 33
Objet 72, poids 29, sac 43
Objet 73, poids 28, sac 44
Objet 74, poids 28, sac 45
Objet 75, poids 24, sac 26
Objet 76, poids 24, sac 27
Objet 77, poids 23, sac 28
Objet 78, poids 23, sac 29
Objet 79, poids 23, sac 30
Objet 80, poids 23, sac 31
Objet 81, poids 23, sac 46
Objet 82, poids 23, sac 54
Objet 83, poids 23, sac 54
Objet 84, poids 22, sac 54
Objet 85, poids 20, sac 46
Objet 86, poids 20, sac 23
Objet 87, poids 19, sac 22
Objet 88, poids 18, sac 24
Objet 89, poids 17, sac 25
Objet 90, poids 16, sac 54
Objet 91, poids 10, sac 11
Objet 92, poids 9, sac 10
Objet 93, poids 6, sac 5
Objet 94, poids 5, sac 4
Objet 95, poids 4, sac 3
Objet 96, poids 2, sac 28
Objet 97, poids 1, sac 2
Objet 98, poids 1, sac 5
Objet 99, poids 1, sac 23
```

###Remarques
On remarque des différences entre le nombre de sacs utilisés, autant pour le mode **online** que pour le mode **offline**.  
On remarque que l'on gagne 2 sacs sur le mode **offline** pour l'exemple de données 5 sur FirstFit, et 1 sac sur le mode **offline** pour l'exemple de données 5 sur BestFit - ce qui est l'exemple le plus flagrant que le mode **offline** est plus profitable en mémoire que le mode **online**, car il stocke dans moins d'élèments d'un tableau de sacs.

###Exercice 4

##Online

| Exemple | NextFit | FirstFit | BestFit | (en microsecondes)  
|   2     |    1    |     2    |    2    |  
|   3     |    2    |     2    |    3    |  
|   4     |    1    |     2    |    2    |  
|   5     |    6    |    32    |   156   |

##Offline

| Exemple | NextFit | FirstFit | BestFit | (en microsecondes)  
|   2     |    2    |     2    |    3    |  
|   3     |    2    |     3    |    5    |  
|   4     |    2    |     2    |    4    |  
|   5     |    4    |    42    |   163   |  

Pour cet exercice, nous pouvons voir que le temps d'exécution des algorithmes FirstFit et BestFit augmentent légérement en Offline qu'en Online, contrairement au NextFit - ceci est dû en effet que le NextFit est beaucoup plus performant en ajoutant les plus gros poids d'abord et les moins gros à la fin, contrairement aux autres qui, pour les perfectionner, consistent plus à prendre en compte les objets les moins gros en premier pour.
