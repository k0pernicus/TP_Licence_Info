import sys
import random

from client import Server
from client import ServerError

BASE_URL = "http://pac.bouillaguet.info/TP4/"
TP_ACTUEL = "ElGamal-forgery/"
GET_PK = "PK/"
VERIFY = "verify/"

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
    Fonction permettant de retourner l'inverse modulaire de a au modulo b
    """
    _, u0, _ = XGCD(a, b)
    return u0

def get_tmp(a, b):
    """
    Fonction permettant de s'assurer que a est premier avec q
    """
    x, _, _ = XGCD(a, b)
    return x

if __name__ == "__main__":

    #Récupération du login

    login = sys.argv[1]

    #Récupération des éléments

    client = Server(BASE_URL + TP_ACTUEL)

    reponse = client.query(GET_PK + login)

    p = reponse['p']

    q = (p - 1)

    g = reponse['g']

    h = reponse['h']

    #Choix de b et c de façon arbitraire - choix pouvant aller de 1 à q

    b = random.randint(1, q)

    tmp = 0

    while tmp != 1:
        c = random.randint(1, q)
        tmp = get_tmp(c, q)

    #Création de r, où r = (g^b * h^c)
    r = (pow(g, b, p) * pow(h, c, p)) % p

    #Création de s, où s = inverse de 'r' * inverse modulaire de c
    s = (-r * mod_inv(c, q)) % q

    #Enfin, m vaut (b * s)
    m = (b * s) % q

    #On renvoie le tout...
    dict = {'m' : m, 'signature' : (r,s)}

    print(client.query(VERIFY + login, dict))
