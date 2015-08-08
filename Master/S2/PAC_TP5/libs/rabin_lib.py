import math

from libs.maths_lib import XGCD

def is_congruent(n):
    """
    Fonction concernant la génération des clefs pour le chiffrement de Rabin.
    Retourne un booléen concernant : "n (doit-être premier) est-il congrue à 3 mod 4?"
    """
    return (n % 4) == 3

def get_Rabin_PK(p,q):
    """
    Fonction retournant la multiplication des deux paramètres.
    Ces paramètres doivent être premiers et congrus à 3 mod 4.
    """
    return p * q

def get_primal_signature(y, p, q, n, debug_mode):
    """
    Fonction permettant de retourner la signature de Rabin
    y: Le calcul de H(m||U)
    U: Le bourrage
    """
    x1p = pow(y, ((p + 1) // 4), p)
    x2p = p - x1p

    if debug_mode:
        print('x1p:', x1p)

        if pow(x1p, 2, p) == y:
            print('x1p OK!')
        else:
            raise('x1p error!')

        print('x2p:', x2p)
        if pow(x2p, 2, p) == y:
            print('x2p OK!')
        else:
            raise('x2p error!')

    x1q = pow(y, ((q + 1) // 4), q)
    x2q = q - x1q

    if debug_mode:
        print('x1q:', x1q)

        if pow(x1q, 2, q) == y:
            print('x1q OK!')
        else:
            raise('x1q error!')

        print('x2q:', x2q)
        if pow(x2q, 2, q) == y:
            print('x2q OK!')
        else:
            raise('x2q error!')

    _, r, s = XGCD(p, q)

    return ((x1q * r * p) + ( x1p * s * q)) % n
