import sys
import json

from oracle import Oracle
from helpers import Block
from helpers import Message
from client import Server
from client import ServerError

UTF8_DECODING = 'utf-8'

BASE_URL = "http://pac.bouillaguet.info/TP2/padding-attack/"
ORACLE_URL = "oracle/"
TP1_URL = "last-byte/"
TP2_URL = "last-block/"

SEED = <VOTRE_SEED>
SEED_STR = str(SEED)

BLOCK_DEFAULT = 'E05351180A526C58F318F7E8F1179A00'
BYTES_IS_BLOCK_DEFAULT = '00000000000000000000000000000000'

debug = 0

def load_msg_enc():
	"""
	Fonction permettant de charger le vecteur d'initialisation ainsi que le message encodé du fichier 'msg_enc(0).txt'
	"""
	msg_enc = open("msg_enc(0).txt", "r")
	msg_enc_open = msg_enc.read()
	msg_enc.close()

	#On retourne le dictionnaire contenant le vecteur d'initialisation, ainsi que le message chiffré
	return json.loads(msg_enc_open)

def trouver_dernier_octet(login, IV, r, Y_n_before, Y_n):
	"""
	Fonction permettant de trouver le dernier octet de X_n, en fonction des blocs Y_n-1 et Y_n.
	Renverra l'octet trouvé, ainsi que son état intermédiaire (dans un tuple)
	login : login de l'utilisateur
	IV : vecteur d'initialisation, donné par le serveur lors de la demande avec SEED
	r : l'objet Block aléatoire permettant l'attaque
	Y_n_before : bloc Y_n-1
	Y_n : bloc Y_n
	"""

	#Création de l'oracle
	oracle = Oracle(BASE_URL, ORACLE_URL, login, SEED)

	i = 0

	while True:
		h = "0x{:02x}".format(i)
		r[15] = int(h, 16)
		if debug:
			print("i : {0} ; r : {1}".format(h, r.hex() + Y_n.hex()))
		reponse = oracle.demande_informations(r.hex() + Y_n.hex(), IV.hex())
		if reponse['status'] != 'invalid padding':
			print("VALIDE : " + reponse['status'] + " - " + str(i))
			break
		i = i+1

	#L'octet intermédiaire est i ^ 01
	byte_IS = i ^ 1

	#Le dernier octet de X_n est donc byte_IS ^ Y_n[len(Y_n)-1]
	last_byte = byte_IS ^ Y_n_before[15]

	last_byte = hex(last_byte)

	#Récupération des deux derniers hexa -> un octet
	last_byte = last_byte[2:]
	
	#Vérification - si la longueur vaut 1, dans ce cas on concatène 0 avec le dernier octet
	if len(last_byte) == 1:
		last_byte = "0"+last_byte

	#Destruction de l'oracle
	del oracle

	return (byte_IS, last_byte)

def trouver_bloc(login, bytes_IS_block, IV, r, Y_n_before, Y_n, last_byte, nb_block):
	"""
	Fonction permettant de trouver le dernier bloc X_n du message à déchiffrer.
	Renverra le bloc contenant tous les octets trouvés.
	login : login de l'utilisateur
	bytes_IS_block : objet Block qui contenant absolument tous les états intermédiaires calculés (pour évaluation padding)
	IV : vecteur d'initialisation, donné par le serveur lors de la demande avec SEED
	r : l'objet Block aléatoire permettant l'attaque
	Y_n_before : bloc Y_n-1
	Y_n : bloc Y_n
	last_byte : dernier octet trouvé du bloc sur lequel on effectue l'attaque
	"""
	
	#Création de l'oracle
	oracle = Oracle(BASE_URL, ORACLE_URL, login, SEED)

	#Bloc d'octets - initialisé à last_byte
	bloc = last_byte

	#i sert à chercher l'octet en question
	i = 0

	#j sert à changer de position dans le block (on décrémente)
	j = 14

	#Boucle permettant de calculer le bloc entier concerné 
	while True:
		#Calcul de h en hexadécimal
		h = "0x{:02x}".format(i)
		#Transformation de r[j] via h entier (hexa)
		r[j] = int(h, 16)
		if debug:
			print("i : {0} ; r : {1}".format(h, r.hex() + Y_n.hex()))
		reponse = oracle.demande_informations(r.hex() + Y_n.hex(), IV.hex())
		#Si la réponse renvoyée par le serveur n'est pas invalide, le padding est bon!
		if reponse['status'] == 'invalid padding':
			i = i+1
		else:
			if debug:
				print("VALIDE : {0} - i={1}".format(reponse['status'],str(i)))
			#L'octet de l'état intermédiaire est calculé
			bytes_IS_block[j] = i ^ (16 - j)
			#On le xor avec le bloc précédent à l'état j+1
			byte = bytes_IS_block[j] ^ Y_n_before[j]
			byte = hex(byte)
			byte = byte[2:]
			if len(byte) == 1:
				byte = "0"+byte
			print("L'octet {0} de X_n est {1}".format(j, byte))
			#envoie_octet_intermediaire(login, (nb_block * 16 + (16 - j)), byte)
			bloc = "{0}{1}".format(byte, bloc)
			#L'état intermédiaire est modifié de façon à calculer le nouvel octet à la position donnée
			for k in range (j, 16):
				r[k] = bytes_IS_block[k] ^ (16 - (j - 1))
			#On décrémente j -> passage vers une position moindre
			j = j-1
			#Réinitialisation de i, permettant de commencer l'attaque à 0
			i=0
			#Si la position de l'octet est inférieure à 0, on stoppe!
			if j<0:
				break

	#Destruction de l'oracle
	del oracle

	return bloc

def envoie_dernier_octet(login, last_byte):
	"""
	Fonction permettant d'envoyer le dernier octet trouvé du dernier bloc du message à déchiffrer
	login : login de l'utilisateur
	last_byte : l'octet trouvé (en hexadécimal)
	"""
	server = Server(BASE_URL)
	#Le message à envoyer sera contenu dans le paramètre 'cyphertext'
	msg_a_envoyer = {'value' : last_byte}
	print(server.query(TP1_URL + login + "/" + SEED_STR, msg_a_envoyer))

def envoie_octet_intermediaire(login, i, byte):
	"""
	Fonction permettant d'envoyer un octet pour vérification, à la position i (en partant de la fin) d'un bloc X_n du message à déchiffrer
	login : login de l'utilisateur)
	i : position (en partant de la fin) de l'octet 'byte'
	byte : octet envoyé pour vérification (en hexadécimal)
	"""
	server = Server(BASE_URL)
	msg_a_envoyer = {'value' : byte}
	print(server.query(TP1_URL + login + "/" + SEED_STR + "/" + str(i), msg_a_envoyer))

def envoie_dernier_bloc(login, bloc):
	"""
	Fonction permettant d'envoyer un bloc (X[0...n]) pour vérification
	login : login de l'utilisateur
	bloc : bloc envoyé pour vérification (une chaîne de caractères, contenant des octets hexadécimaux)
	"""
	server = Server(BASE_URL)
	msg_a_envoyer = {'value' : bloc}
	print(server.query(TP2_URL + login + "/" + SEED_STR, msg_a_envoyer))	

if __name__ == "__main__":

	#Login de l'utilisateur
	login = sys.argv[1]

	if '-debug' in sys.argv:
		debug = 1

	#Chargement du vecteur d'initialisation ainsi que du message chiffré
	dic_msg_chif = load_msg_enc()

	#Création d'un objet Message, à partir du message chiffré
	ciphertext = Message(dic_msg_chif["ciphertext"])

	#Vecteur d'initialisation du chiffrement, donné par le fichier texte donné par le serveur
	IV = Block(dic_msg_chif["IV"])

	all_blocs = ""

	length_ciphertext = len(ciphertext)

	for i in range (length_ciphertext - 1, -1, -1):
		if debug:
			print("Bloc {0}".format(i))

		#Bloc de tous les byte_IS
		bytes_IS_block = Block(BYTES_IS_BLOCK_DEFAULT)
		#Construction de r, un bloc de 128 bits aléatoires
		r = Block(BLOCK_DEFAULT)
		if i!= 0:
			Y_n_before = ciphertext[i-1]
		else:
			Y_n_before = IV
		Y_n = ciphertext[i]

		(byte_IS, last_byte) = trouver_dernier_octet(login, IV, r, Y_n_before, Y_n)
		if debug:
			print("Le dernier octet de X_n est {0}".format(last_byte))	
		
		bytes_IS_block[15] = int(hex(byte_IS), 16)
		#Changement de r[15]
		r[15] = 2 ^ bytes_IS_block[15]
		#Envoie du dernier octet du bloc X_n
		#envoie_dernier_octet(login, last_byte)
		
		#nb-block vaut 15-i -> numéro du block!
		last_bloc = trouver_bloc(login, bytes_IS_block, IV, r, Y_n_before, Y_n, last_byte, (length_ciphertext - 1) - i)
		print("Bloc {0} vaut {1}".format(i, last_bloc))
		#envoie_dernier_bloc(login, last_bloc)
		
		all_blocs = last_bloc + all_blocs

	message = Message(all_blocs)

	message_to_return = ""

	for block in message:
		 message_to_return += bytes(block).decode(UTF8_DECODING)

	print("Message décodé : {0}".format(message_to_return))