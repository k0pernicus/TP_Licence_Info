import sys
import random

from libs.maths_lib import PGCD
from libs.maths_lib import mod_inv
from libs.maths_lib import get_primal_number
from libs.maths_lib import is_probable_prime

from libs.rsa_lib import get_phi

from libs.client_lib import Server
from libs.client_lib import ServerError

BASE_URL = "http://pac.bouillaguet.info/TP5/RSA-keygen/"
GET_CHALLENGE = "challenge/"
GET_PK = "PK/"
CONFIRMATION = "confirmation/"

debug_mode = False

if __name__ == "__main__":
    login = sys.argv[1]

    if "-debug" in sys.argv:
        debug_mode = True

    #Récupération de l'exposant
    server = Server(BASE_URL)

    e = server.query(GET_CHALLENGE + login)['e']
    #Choix de p et q

    p = 1
    q = 1
    phi_n = 1

    #Vérification de p et q - ok si p != q et que si e est premier avec phi_n
    while ((p == q) or (PGCD(e, phi_n) != 1)):
        p = get_primal_number()
        q = get_primal_number()
        phi_n = get_phi(p,q)

    #Calcul de n, en fonction de p et q choisis
    n = p * q

    #Calcul de d, inverse de e mod (phi_n)
    d = (mod_inv(e, phi_n)) % phi_n

    if debug_mode:
        print("e: {0}".format(e))
        print("p: {0}".format(p))
        print("q: {0}".format(q))
        print("n: {0}".format(n))
        print("d: {0}".format(d))
        print("phi_n: {0}".format(phi_n))

    to_send = {'n' : n, 'e' : e}

    #Récupération du chiffré
    c = server.query(GET_PK + login, to_send)['ciphertext']

    if debug_mode:
        print("c: {0}".format(c))

    #Déchiffrement du message
    m = pow(c, d, n)

    if debug_mode:
        print("m: {0}".format(m))

    print(server.query(CONFIRMATION + login, {'m' : m}))
