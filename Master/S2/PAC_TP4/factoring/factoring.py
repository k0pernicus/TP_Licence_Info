import sys
import random

from client import Server
from client import ServerError

BASE_URL = "http://pac.bouillaguet.info/TP4/"
TP_ACTUEL = "factoring/"
GET_PARAM = "get/"
SUBMIT_PARAM = "submit/"

primal_numbers = [  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                    59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
                    127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
                    257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
                    331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
                    401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                    467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557,
                    563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619,
                    631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
                    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787,
                    797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
                    877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953,
                    967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021]

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

def PGCD(a, b):
    """
    Calcul du PGCD d'un nombre, via l'appel de XGCD
    """
    d, _, _ = XGCD(a, b)
    return d

def heron(nbr):
    """
    Fonction permettant de calculer la racine carrée entière d'un nombre entier, via la méthode de Héron d'Alexandrie
    """

    s1 = 1

    while True:
        s2 = (s1 + nbr // s1) // 2
        if abs(s1 - s2) < 2:
            if ((s1 * s1) <= n) and ((s1 + 1) * (s1 + 1)) > nbr:
                return s1
        s1 = s2

def expmod(rn, b, n):
    x = 1
    while b > 0:
        if b & 1 == 0:
            b >>= 1
        else:
            x = (x * rn) % n
            b = (b - 1) >> 1
        rn = (rn * rn) % n

    return x

def rabin(rn, n):

    """
    Méthode de Rabin
    """

    b = n - 1
    a = 0

    while b % 2 == 0:
        b >>= 1
        a += 1

    rnpow = expmod(rn, b, n)

    if rnpow == 1:
        return True

    for i in range(0, a):
        if expmod(rn, b, n) == n-1:
            return True
            b *= 2

    return False

def isprime(nbr):
    """
    Fonction permettant de vérifier si le nombre donné en paramètre est premier ou non
    """

    #Si le nombre est un grand entier, on utilisera la méthode de Rabin
    if len(str(nbr)) > 9:
        for i in range(0, 20):
            rn = random.randint(1, nbr-1)
            if not rabin(rn, nbr):
                return False
    else:
        if (nbr < 1024):
            if (nbr not in primal_numbers):
                return False
            else:
                return True

    #Sinon, on vérifiera manuellement la chose...
    if (nbr & 1) == 0:
        return False

    #Décomposition
    k = 3
    sqrt_nbr = heron(nbr)

    while k <= sqrt_nbr:
        if (nbr % k) == 0:
            return False
        k += 2

    return True

def factorsdiv2(n):
    """Décomposition par division de n (entier) en 2 facteurs quelconques"""

    pstack = [2, 3, 5, 7, 11]

    sqrtn = heron(n)

    for p in pstack:
        if p > sqrtn:
            return [n, 1]
        if n % p == 0:
            return [p, n // p]

    p = pstack[-1] + 2

    while p <= sqrtn:
        if n % p == 0:
            return [p, n // p]
        p += 2

    return [n, 1]

def pollard_rho(n):
    """
    Algorithme de John M. Pollar, permettant de calculer facilement la factorisation du nombre n donné en paramètre
    """
    x = 2
    y = 2
    d = 1
    while (d == 1):
        x = g(x, n)
        y = g(g(y, n), n)
        x_y = (x - y)

        for i in range(100):
            x = g(x, n)
            y = g(g(y, n), n)
            x_2 = g(x, n)
            y_2 = g(g(y, n), n)
            x_y *= ((x - y) * (x_2 - y_2)) % n
            x = x_2
            y = y_2

        d = PGCD(x_y, n)

    return [d, n // d]

def g(x, n):
    """
    Fonction utilisée dans pollard_rho, afin de donner le nouveau résultat concernant x et y
    """
    return ((pow(x, 2) + 1) % n)

if __name__ == "__main__":

    login = sys.argv[1]

    level_spe = sys.argv[2]

    class_spe = sys.argv[3]

    server = Server(BASE_URL + TP_ACTUEL)

    reponse = server.query(GET_PARAM + level_spe + "/" + class_spe)

    id = reponse['id']

    n = reponse['n']

    print("n: {0}".format(n))

    fact_tab = []

    stack = [n]

    while len(stack) != 0:
        x = stack.pop(-1)
        if isprime(x):
            fact_tab.append(x)
        else:
            x, y = pollard_rho(x)

            if (x == 1) or (y == 1):
                x, y = factorsdiv2(x)

            stack.append(x)
            stack.append(x)

    print(fact_tab)

    #Partie vérification

    rst = 1

    for nbr in fact_tab:
        rst = rst * nbr

    if (rst != n):
        print("ERREUR - RST et N ne sont pas égaux!")
        print("rst: {0}".format(rst))
        exit()

    dict = {'id' : id, 'factors' : fact_tab}

    print(server.query(SUBMIT_PARAM + "/" + login, dict))
