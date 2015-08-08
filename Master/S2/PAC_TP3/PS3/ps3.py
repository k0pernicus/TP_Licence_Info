import os
import sys
import random
import decimal

from client import Server
from client import ServerError

import ProgressBar

BASE_URL = "http://pac.bouillaguet.info/TP3/PS3/"
GET_PK = "PK/"
CHANGE_PK = "change/"
TO_SIGN = "sign/"
VALIDATION = "validate/"

def PGCD(k,q):
	"""
	Fonction basique permettant de calculer le PGCD d'un couple d'entiers
	"""
	while q != 0:
		r = k % q
		k = q
		q = r
	return k

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
	Fonction permettant de retourner directement l'inverse du modulo
	"""
	(_,x,_) = XGCD(a,b)
	return x

if __name__ == "__main__":

	login = sys.argv[1]

	if ("-debug" in sys.argv):
		debug_mode = True
	else:
		debug_mode = False
		progressBar = ProgressBar.ProgressBar(100,100,"Progression...")

	#Implémentation du serveur
	server = Server(BASE_URL)

	#Récupération de la PK
	if (debug_mode):
		print("Récupération de la public key...")
	else:
		progressBar.update(20)

	PK = server.query(GET_PK + login)

	p = PK['p']
	g = PK['g']
	h = PK['h']
	q = p - 1

	m0 = random.randint(1, 100)
	m1 = random.randint(1, 100)

	#Récupération de m0
	mc0 = server.query(TO_SIGN + login, {'m' : m0})
	r, s0 = mc0['signature'][0], mc0['signature'][1]
	#Récupération de m1
	mc1 = server.query(TO_SIGN + login, {'m' : m1})
	_, s1 = mc1['signature'][0], mc1['signature'][1]

	while (PGCD(r, q) != 1):

		if debug_mode:
			print("Changement de la public key...")
		#Récupération de la PK
		PK = server.query(GET_PK + login + CHANGE_PK)

		p = PK['p']
		g = PK['g']
		h = PK['h']
		q = p - 1

		#Récupération de m0
		mc0 = server.query(TO_SIGN + login, {'m' : m0})
		r, s0 = mc0['signature'][0], mc0['signature'][1]
		#Récupération de m1
		mc1 = server.query(TO_SIGN + login, {'m' : m1})
		_, s1 = mc1['signature'][0], mc1['signature'][1]

	if debug_mode:
		print("r found : {0}".format(r))
		print("s0 : {0}".format(s0))
		print("s1 : {0}".format(s1))
	else:
		progressBar.update(40)

	if debug_mode:
		print("Récupération de k...")
	k = ((m0 - m1) * mod_inv((s0 - s1), q)) % q

	if debug_mode:
		print("k found : {0}".format(k))
	else:
		progressBar.update(60)

	if debug_mode:
		print("Récupération de x...")

	x = (mod_inv(r, q) * (m0 - (k * s0))) % q

	if debug_mode:
		print("x found : {0}".format(x))
	else:
		progressBar.update(80)

	response = server.query(VALIDATION + login, {'x' : x})

	if not debug_mode:
		progressBar.update(100)

	print(response)
