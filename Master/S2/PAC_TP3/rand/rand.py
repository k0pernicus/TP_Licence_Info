import os
import sys
import time
import math

from client import Server
from client import ServerError

from Random import Random

def XGCD(a, b):
	"""
	Extension de l'algorithme d'Euclide
	Fonction reprise de PAC - Cours 6
	"""
	u = (1, 0) #Représentation de a
	v = (0, 1) #Représentation de b
	while (b != 0):
		q, r = divmod(a, b)
		a = b
		b = r
		#MàJ des représentations
		tmp = (u[0] - q*v[0], u[1] - q*v[1])
		u = v
		v = tmp
	return a, u[0], u[1]

def mod_inv(a, b):
	"""
	Fonction permettant de retourner directement l'inverse modulaire de a pour b
	"""
	(_,x,_) = XGCD(a,b)
	return x

def verif_next(t, next):
	if next == t:
		return True
	return False

def calculer_next(previous, next):
	rand_nbr = Random()
	tab_to_return = []
	for i in range(0, (2**16)+1):
		for j in range(0,2):
			t = 0
			t = j
			t = t << 15 | previous
			t = t << 16 | i
			rand_nbr.srand(t)
			if (verif_next(rand_nbr.rand(), next)):
				tab_to_return.append(t)
	return tab_to_return


if __name__ == "__main__":
	"""
	Main du programme rand
	"""
	login = sys.argv[1]

	if "-debug" in sys.argv:
		debug_mode = True
	else:
		debug_mode = False

	server = Server("http://pac.bouillaguet.info/TP3/rand/")

	rand_nbr = Random()

	inverse_modulaire = mod_inv(1103515245, 2**32)

	IV = server.query('/challenge/' + login)

	if debug_mode:
		print("IV[0] : {0}".format(IV["IV"][0]))
		print("IV[1] : {0}".format(IV["IV"][1]))

	#1er envoi
	k3_possibles = calculer_next(IV["IV"][0], IV["IV"][1])

	if debug_mode:
		print("Liste des k3 possibles: ", end = "")
		print("{0}".format(k3_possibles))

	#Liste des valeurs possibles pour la seed
	liste_des_possibles = []

	i = 0

	#Calcul des valeurs des clefs (seed)
	for val_possible in k3_possibles:
		liste_des_possibles.append([])
		for j in range(0, 5):
			if j == 0:
				nbr = val_possible
			else:
				nbr = liste_des_possibles[i][j-1]
			liste_des_possibles[i].append(inverse_modulaire * (nbr - 12345) % 2**32)
		i = i + 1


	if debug_mode:
		print("Liste des possibles: ")

	#On renverse les listes, afin de pouvoir utiliser le dernier élément comme graine
	for i in range(0, len(liste_des_possibles)):
		liste_des_possibles[i] = liste_des_possibles[i][::-1]
		if debug_mode:
			print("{0}".format(liste_des_possibles[i]))

	#Utilisation de la graine
	rand_nbr.srand(liste_des_possibles[0][0])
	#Calcul des clefs
	keys = [rand_nbr.rand(), rand_nbr.rand(), rand_nbr.rand(), rand_nbr.rand()]

	#On envoie le tout!
	try:
		reponse = server.query("validation/"+login, {'key' : keys})
		print(reponse)
	except ServerError as e:
		print("Bad key for {0}".format(keys))
