import random
import os
import sys
import math
import hashlib

from libs.client_lib import Server
from libs.client_lib import ServerError

from libs.maths_lib import get_primal_number
from libs.maths_lib import is_probable_prime
from libs.maths_lib import is_square_mod

from libs.rabin_lib import is_congruent
from libs.rabin_lib import get_Rabin_PK
from libs.rabin_lib import get_primal_signature

BASE_URL = "http://pac.bouillaguet.info/TP5/Rabin-signature/"
GET_CHALLENGE = "challenge/"
CONFIRMATION = "check/"

debug_mode = False

def compute_y():

    global m
    global n
    global p
    global q
    global U
    global y

    p = 1
    q = 1

    #Tant que p et de q ne sont pas congruents à 3 % 4...
    while (not is_congruent(p) or not is_congruent(q)):
        if not is_congruent(p):
            p = get_primal_number()
        if not is_congruent(q):
            q = get_primal_number()

    if debug_mode:
        print('p: {0} - prime: {1}'.format(p, is_probable_prime(p)))
        print('q: {0} - prime: {1}'.format(q, is_probable_prime(q)))

    n = get_Rabin_PK(p,q)

    if debug_mode:
        print('n: {0}'.format(n))

    m = server.query(GET_CHALLENGE + login, {'n' : n})['m']

    #Conversion de m en hexadécimal
    m = int(m, base=16)

    if debug_mode:
        print('m: {0}'.format(m))

    #Apport d'un padding de 2^256
    U = random.randint(2, pow(2, 256))

    sha256 = hashlib.sha256()

    sha256.update("{0:08x}".format(m).encode())
    sha256.update("{0:08x}".format(U).encode())

    y = int(sha256.hexdigest(), base=16)

    #y est-il un carré modulo p?
    if not is_square_mod(y, p):
        if debug_mode:
            print("{0} is not a square mod {1}".format(y, p))
        return False
    else:
        if debug_mode:
            print("{0} is a square mod {1}".format(y, p))

    #y est-il un carré modulo q?
    if not is_square_mod(y, q):
        if debug_mode:
            print("{0} is not a square mod {1}".format(y, q))
        return False
    else:
        if debug_mode:
            print("{0} is a square mod {1}".format(y, q))

    return True

if __name__ == "__main__":

    login = sys.argv[1]

    if "-debug" in sys.argv:
        debug_mode = True

    server = Server(BASE_URL)

    while not compute_y():
        continue

    #Signature de Rabin -> composé d'un couple x (message) et U (random)
    x = get_primal_signature(y, p, q, n, debug_mode)

    U = "{0:08x}".format(U)

    if debug_mode:
        print('x: {0}'.format(x))
        print('U: {0}'.format(U))

    print(server.query(CONFIRMATION + login, {'n': n, 's': x, 'u': U}))
