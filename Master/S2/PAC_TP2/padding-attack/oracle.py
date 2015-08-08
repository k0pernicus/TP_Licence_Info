from client import ServerError
from client import Server

class Oracle:
	"""
	Classe permettant de créer un Oracle pour Padding-Attack
	L'oracle va permettre, à partir d'un message chiffré, de renvoyer une réponse\
	concernant le padding du message (bien identifié, retiré, ou alors erreur de conception...)
	"""

	def __init__(self, base_url, url, login, seed):
		"""
		Constructeur de l'oracle
		base_url : base de l'URL sur laquelle envoyer la requête
		url : fin de l'URL sur laquelle envoyer la requête
		
		"""
		self.base_url = base_url
		self.url = url
		self.login = login
		self.seed = seed

	def __del__(self):
		"""
		Destructeur de l'oracle
		"""
		pass

	def demande_informations(self, message, IV):
		"""
		Méthode permettant d'envoyer une requête à l'oracle.
		Prend en paramètre un message chiffré (en hexadécimal).
		"""
		server = Server(self.base_url)
		#Le message à envoyer sera contenu dans le paramètre 'cyphertext'
		msg_a_envoyer = {'ciphertext' : message, 'IV' : IV}
		#print("Envoie de la requête à l'oracle...")
		return server.query(self.url + self.login, msg_a_envoyer)