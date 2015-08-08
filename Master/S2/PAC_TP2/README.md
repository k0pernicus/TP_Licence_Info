PAC - TP2
---------

Auteur : Carette Antonin  

Utilisation de **Python 3.4**

#TODOList

*	[X] : two-time-pad
*	[X] : mersenne-twister
*	[X] : padding-attack
*	[ ] : md5-collisions (EN COURS)
*	[ ] : differential-cryptanalysis

#Utilisation

*	two-time-pad : ```cd two-time-pad && python3.4 two-time-pad.py <votre_login>```
*	mersenne-twister : ```cd mersenne-twister && python3.4 mersenne-twister.py <votre_login> (<votre_fichier.txt>)```
*	padding-attack : ```cd padding-attack && python3.4 padding-attack.py <votre_login>```

#Remarques

*	Mersenne-Twister : créer un fichier 'mersenne_ex.txt' (contenant les 1000 premiers exemples générés par le PRNG) dans le dossier mersenne-twister, afin que le programme puisse charger automatiquement vos 1000 premiers exemples **OU** donner votre fichier en second paramètre du programme
*	Padding-Attack : un fichier msg_enc(0).txt est requis pour l'exécution du programme - il s'agit du premier message chiffré à télécharger avec une SEED. Aussi, la SEED est requise dans le fichier padding-attack.py (dans la variable SEED)