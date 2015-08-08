import random

_mrpt_num_trials = 5 # number of bases to test

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

def mod_inv(a, b):
    """
    Calcul du modulo inverse de a, mod b
    """
    _, d, _ = XGCD(a, b)
    return d

def get_legendre_symb(a, p):
    """
    Calcul le symbole de Legendre par le critère d'Euler ( a^((p-1)/2) mod p )
    """
    return pow(a, (p-1) // 2, p)

def is_square_mod(a, p):
    """
    Le symbole de Legendre permet de décider la résiduosité quadratique modulo p
    Si le symbole de Legendre vaut 1, alors il s'agit d'un résidu quadratique modulo p -> donc que a est un carré!
    """
    return (get_legendre_symb(a,p) == 1)

def newton_method(n):
   """ renvoie le plus grand entier k tel que k^2 <= n. Méthode de Newton."""
   x = n
   y = (x + 1) // 2
   while y < x:
       x = y
       y = (x + n // x) // 2
   return x

def compute_square_root(n):
    """
    Fonction permettant de calculer la racine carrée x de y - méthode héritée de heron-square
    """
    s1 = 1
    while True:
        s2 = (s1 + n // s1) // 2
        if abs(s1 - s2) < 2:
            if s1 * s1 <= n and (s1 + 1) * (s1 + 1) > n:
                return s1
        s1 = s2

def get_primal_number():
    """
    Génération d'un nombre aléatoire de plus de 2048 bits
    """
    nbr = 2
    while not (is_probable_prime(nbr)):
        nbr = random.getrandbits(1029) * 2 + 1
    return nbr

def is_probable_prime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.

    >>> is_probable_prime(1)
    Traceback (most recent call last):
        ...
    AssertionError
    >>> is_probable_prime(2)
    True
    >>> is_probable_prime(3)
    True
    >>> is_probable_prime(4)
    False
    >>> is_probable_prime(5)
    True
    >>> is_probable_prime(123456789)
    False

    >>> primes_under_1000 = [i for i in range(2, 1000) if is_probable_prime(i)]
    >>> len(primes_under_1000)
    168
    >>> primes_under_1000[-10:]
    [937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

    >>> is_probable_prime(6438080068035544392301298549614926991513861075340134\
3291807343952413826484237063006136971539473913409092293733259038472039\
7133335969549256322620979036686633213903952966175107096769180017646161\
851573147596390153)
    True

    >>> is_probable_prime(7438080068035544392301298549614926991513861075340134\
3291807343952413826484237063006136971539473913409092293733259038472039\
7133335969549256322620979036686633213903952966175107096769180017646161\
851573147596390153)
    False
    """
    if pow(42, n, n) != 42:
        return False

    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n-1)

    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True # n is definitely composite

    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False

    return True # no base tested showed n as composite
