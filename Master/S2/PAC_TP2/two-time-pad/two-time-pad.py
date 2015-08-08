import sys
from random import randint
import base64

#Xor
from xor import xor
from xor import xor_byte

#Client
from client import ServerError
from client import Server

#Variables globales -- URL
BASE_URL = "http://pac.bouillaguet.info/TP2/two-time-pad/"
URL_CHALLENGE = "challenge/"
URL_QUESTION = "question/"
URL_ANSWER = "answer/"

#Variables globales -- ENCODAGE
ENCODING_UTF8 = "utf-8"
ENCODING_ASCII = "ascii"

if __name__ == "__main__":
	"""
	Programme permettant de résoudre le problème two-time-pad
	Nécessite en paramètre le login de l'utilisateur
	"""

	#Login du user
	login = sys.argv[1]

	#Graine -> nombre aléatoire entier
	seed = randint(1, 1000)

	server = Server(BASE_URL)

	#Développement de l'URL pour CHALLENGE
	url_challenge = "{0}{1}/{2}".format(URL_CHALLENGE, login, seed)

	#Demande au serveur à l'URL de CHALLENGE
	reponse_challenge = server.query(url_challenge)

	#On récupère le champ A -> normalement en UTF-8, il faut décoder l'hexadécimal en bytes, puis de bytes en unicode
	AxorM = reponse_challenge['A']

	#On récupère le champ B -> normalement en ASCII, il faut décoder l'hexadécimal en bytes, puis de bytes en ascii
	BxorM = reponse_challenge['B']

	#Transformation en bytes pour A et B
	AxorM_decode = base64.b16decode(AxorM, casefold=True)
	BxorM_decode = base64.b16decode(BxorM, casefold=True)

	#Calcul du XOR entre A et B (en bytes) -> élimination du masque M
	AxorB = xor(AxorM_decode, BxorM_decode)

	length_AxorB = len(AxorB)

	msg_AxorB = ""

	#Recherche du message avec Xor sur 0
	for i in range(0, length_AxorB):
		c = chr(xor_byte(AxorB[i], ord('0')))
		if (c.isalpha() == False) and c != "\n" and c != " " :
			c = chr(xor_byte(AxorB[i], ord('1')))
		msg_AxorB += str(c)

	#Impression des deux messages
	#print("msg 0 : {0}".format(msg_AxorB_0))
	#print("msg 1 : {0}".format(msg_AxorB_1))

	#Développement de l'URL pour QUESTION
	url_question = "{0}{1}/{2}".format(URL_QUESTION, login, seed)

	#Demande au serveur, à l'URL de QUESTION
	reponse_question = server.query(url_question)

	print(reponse_question)

	#Word number (à trouver)
	word_nbr = reponse_question['word']
	#Line number (à trouver)
	line_nbr = reponse_question['line']

	word_nbr_found = 0
	line_nbr_found = 0

	word = ""

	msg_AxorB.replace('!', ' ')

	#Recherche du mot
	for c in msg_AxorB:
		if (line_nbr_found == line_nbr and word_nbr_found == word_nbr and c != " " and c != "\n"):
			print(c, end="")
			word += str(c)
		if (c == "\n"):
			line_nbr_found += 1
			word_nbr_found = 0
		if (c == " "):
			word_nbr_found += 1

	word_found = {"word" : word}

	#Développement de l'URL pour QUESTION
	url_answer = "{0}{1}/{2}".format(URL_ANSWER, login, seed)

	print("Word found : {0}".format(word))

	#Demande au serveur, à l'URL de QUESTION
	reponse_answer = server.query(url_answer, word_found)

	print("URL answer : {0}".format(reponse_answer))