import os
import sys
import random
import ProgressBar

from client import Server
from client import ServerError

BASE_URL = "http://pac.bouillaguet.info/TP3/"
TP_ACTUEL = "ElGamal-encryption/"
GET_PARAM = "parameters/"
GET_CHALLENGE = "challenge/"
VALIDATION = "validate/"

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

def inv(a, b):
	"""
	Fonction permettant de retourner directement l'inverse du modulo
	"""
	(_,x,_) = XGCD(a,b)
	return x

if __name__ == "__main__":
	"""
	Programme permettant de valider la partie 'ElGamal' du TP3 de PAC
	"""

	#Récupération du login de l'utilisateur
	login = sys.argv[1]

	progressBar = ProgressBar.ProgressBar(100,100,"Progression...")

	#Implémentation de l'URL
	server = Server(BASE_URL + TP_ACTUEL)

	#Récupération d'un dictionnaire contenant 'p' et 'q'
	#'p' est un nombre premier, tandis que 'q' est un générateur
	reponse_server = server.query(GET_PARAM + login)

	progressBar.update(20)

	p = reponse_server['p']
	g = reponse_server['g']

	#Génération d'un nombre aléatoire compris entre 1 et (p-1)
	x = random.randint(1, p-1)
	#Calcul de la clef publique en calculant g^x
	public_key = pow(g, x, p)

	challenge_a_envoyer = {'h' : public_key}

	reponse_server = server.query(GET_CHALLENGE + login, challenge_a_envoyer)

	progressBar.update(50)

	ciphertext = reponse_server['ciphertext']

	a = ciphertext[0]
	b = ciphertext[1]

	#Déchiffrement
	h = pow(a,x,p)
	h_1 = inv(h,p)

	progressBar.update(80)

	m = (b * h_1) % p

	plaintext = {'plaintext' : m}

	progressBar.update(100)

	reponse_server = server.query(VALIDATION + login, plaintext)

	print(reponse_server)