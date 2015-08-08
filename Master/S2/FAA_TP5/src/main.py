# -*- coding: utf8 -*-

import os
import sys
import math
import numpy as np

BAD = -1
BAD_SEC = 0
GOOD = 1

def load_data():

	global x
	global y
	global length_x
	global length_y
	global INPUTS
	global SCORE

	#Chargement des fichiers d'exemple
	x = np.loadtxt("../ex/x.txt")
	y = np.loadtxt("../ex/y.txt")

	length_x = length_y = len(x)

	#Entrées
	INPUTS = np.vstack((x,y))
	#Score de toutes les entrées -> BAD sur celles de x et GOOD sur celles de y pour commencer
	SCORE = np.hstack((BAD * np.ones(length_x), np.ones(length_y)))

def adaboost():
	"""
	==Algorithme adaboost==
	Adaboost fait partie du boosting - une méthode permettant de créer un classifieur fort à partir de\
	classifieurs/règles faibles mais garantis meilleurs que le hasard (la 1ère règle faible 1 est la\
	meilleure des deux, la 2ème étant celle obtenue par l'élimination des mots bien classés par cette règle).
	"""

	global x
	global y
	global length_x
	global length_y
	global INPUTS
	global SCORE

	#t est l'itération
	t = 1
	#E
	E = 1
	#ksi
	ksi = 0
	#D est la distribution de poids associée à chaque élément de x, pour une itération t
	D = np.ones(length_x)

	for i in range(0, length_x):
		D[i] = D[i] / length_x

	while E > ksi:

		#epsilon_t (epsilon pour la transition t)
		epsilon_t = 0

		#variable calculant la somme de 0 à i pour la distribution de poids
		somme_D = 0

		#règle forte
		H = np.ones(length_y)

		if (t != 1):
			ht=np.vstack((ht,np.empty(SCORE.shape)))
		else:
			ht=np.empty(SCORE.shape)

		#Calcul de la classe faible -> sum(D[i]) si ht[i] != SCORE[i]
		for i in range(0, length_y):
			if (ht[i] != SCORE[i]):
				epsilon_t = epsilon_t + D[i]

		#Calcul de alpha_t (le pas d'apprentissage) -> (1/2) * ln((1-epsilon_t) / epsilon_t)
		alpha_t = (1.0/2.0) * math.log((1-epsilon_t) / epsilon_t)

		#Mise-à-jour de la distribution de poids
		#Calcul de la somme de 0 à i
		for poids in D:
			somme_D = somme_D + poids
		#Réelle mise-à-jour pour la distribution de poids
		for i in range(0, length_y):
			D[i] = (D[i] * math.exp(-alpha_t * SCORE[i]) * ht[i]) / somme_D

		#Calcul de la règle forte
		for i in range(0, length_y):
			if (alpha_t * ht[i]) > 1:
				H[i] = GOOD
			else:
				H[i] = BAD_SEC

		#Calcul de l'erreur de classification
		for i in range(0, length_y):
			if(H[i] != SCORE[i]):
				E = E + (1.0 / length_y)

		#Incrémentation de l'itération
		t = t + 1

	#Fin de l'algorithme -> Renvoie de l'état de l'itération ainsi que de la règle forte
	return (t, H)

if __name__ == "__main__":
	"""
	Main du TP5
	Le but du boosting est de trouver une combinaison linéaire de règles (faibles) produisant une règle forte sur x (entrée).

	"""
	load_data()
	t, H = adaboost()
	print("t : ".format(t))
	print("H : ".format(H))