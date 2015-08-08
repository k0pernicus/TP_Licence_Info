import sys
import json

#Client
from client import ServerError
from client import Server

from mersenne import MersenneTwister

global mersenne_values

BASE_URL = "http://pac.bouillaguet.info/TP2/mersenne-twister/"
URL_PREDICTION = "prediction/"

def load_mersenne_values(file_mersenne_ex):
	"""
	Fonction permettant d'imprimer sur la sortie standard les valeurs Mersenne (par paquet de 624)
	"""
	
	#Tentative d'ouverture du fichier mersenne_ex.txt
	try:
		mersenne_ex = open(file_mersenne_ex, "r");
		mersenne_ex_open = mersenne_ex.read()
		mersenne_ex.close()
		mersenne = json.loads(mersenne_ex_open)
		return mersenne['challenge']
	except:
		print("{0} inconnu...".format(file_mersenne_ex))
		raise
		
def reverse_xor_right1(nbr, shift = 18):
	"""
	Fonction renversant l'algo utilisé pour le premier décalage de bits (à droite)
	"""
	nbr_final = nbr >> shift
	return (nbr_final ^ nbr)

def reverse_xor_left1(nbr, shift = 15, mask = 4022730752):
	"""
	Fonction renversant l'algo utilisé pour le premier décalage de bits (à gauche)
	"""
	nbr_1 = nbr << shift
	return nbr ^ (nbr_1 & mask)

def reverse_xor_left2(nbr, shift = 7, mask = 2636928640):
	"""
	Fonction renversant l'algo utilisé pour le second décalage de bits (à gauche)
	"""
	nbr_1 = nbr << shift
	nbr_2 = nbr ^ (nbr_1 & mask)

	nbr_2 = nbr_2 << shift
	nbr_3 = nbr ^ (nbr_2 & mask)
	
	nbr_3 = nbr_3 << shift
	nbr_4 = nbr ^ (nbr_3 & mask)

	nbr_4 = nbr_4 << shift
	nbr_5 = nbr ^ (nbr_4 & mask)
	
	nbr_5 = nbr_5 << shift

	return nbr ^ (nbr_5 & mask)

def reverse_xor_right2(nbr, shift = 11):
	"""
	Fonction renversant l'algo utilisé pour le second décalage de bits (à droite)
	"""
	nbr_final = nbr >> shift
	nbr_final ^= nbr 
	nbr_final = nbr_final >> shift
	return (nbr_final ^ nbr)

def reverse_number(nbr):
	"""
	Fonction permettant de calculer l'état interne de l'algorithme
	"""
	nbr_to_return = reverse_xor_right1(nbr)
	nbr_to_return = reverse_xor_left1(nbr_to_return)
	nbr_to_return = reverse_xor_left2(nbr_to_return)
	nbr_to_return = reverse_xor_right2(nbr_to_return)
	return nbr_to_return

def reverse_all_part(tab):
	"""
	Fonction qui permet de renverser le tableau (retour aux origines donc), et de générer les 1001èmes valeurs du PRNG
	"""
	m = MersenneTwister()

	for i in range (0, 624):
		m.MT[i] = reverse_number(tab[i])

	for i in range (0, 1000):
		m.rand()

	#Retour de la 1001ème valeur (prédite)
	return m.rand()

if __name__ == "__main__":
	"""
	Programme permettant de résoudre le problème "mersenne-twister".
	Le problème consiste à trouver le 1001-ème nombre qui sera produit par le PRNG (générateur de nombres
pseudo-aléatoires) de Python - voir mersenne.py.
	"""

	len_argv = len(sys.argv)

	#Vérification liée au nombre de paramètres entrés au programme
	if (len_argv < 2) or (len_argv) > 3:
		print("Ce programme nécessite AU MOINS votre login - en second paramètre votre fichier contenant les nombres issus du PRNG (par défaut 'mersenne_ex.txt')")
		quit()

	login = sys.argv[1]	

	#Le 2ème argument est facultatif...
	if len_argv == 2:
		file_mersenne_ex = "mersenne_ex.txt"
	else:
		file_mersenne_ex = sys.argv[2]

	#Chargement des données ici du fichier mersenne_ex.txt
	mersenne_values = load_mersenne_values(file_mersenne_ex)

	nbr = reverse_all_part(mersenne_values)

	print("Nombre trouvé : {0}".format(str(nbr)))

	print("Entrez ceci dans votre navigateur : {0}{1}/{2}".format(BASE_URL + URL_PREDICTION, login, str(nbr)))