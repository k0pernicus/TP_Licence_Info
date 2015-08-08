import sys
import os
import random

from libs.client_lib import ServerError
from libs.client_lib import Server

from libs.maths_lib import newton_method
from libs.maths_lib import mod_inv
from libs.maths_lib import PGCD

BASE_URL = "http://pac.bouillaguet.info/TP5/"
RSA_RED = "RSA-reductions/"
PHI_PART = "phi/"
D_PART = "d/"
GET_CHALLENGE = "challenge/"
CHECK = "check/"

debug_mode = False
login = "none"
choice = "none"

def resolve_phi_part(phi, e, n):

    #Identité remarquable!

    s = -phi + 1 + n

    #Calcul du delta
    delta = pow(s, 2) - (-4 * -n)

    r_1 = (-s - newton_method(delta)) // -2

    #Calcul seul de r_1
    if debug_mode:
        print("s : {0}".format(s))
        print("del : {0}".format(delta))
        print("r_1 : {0}".format(r_1))

    #r_1 EST p
    return r_1

if __name__ == "__main__":

    if "-debug" in sys.argv:
        debug_mode = True

    login = sys.argv[1]

    if login == "-debug":
        raise Exception("First argument must be your login...")

    print("Hello {0}!".format(login))

    while choice != "phi" and choice != "d":
        choice = input("Would you resolve 'phi' part or 'd' part?")

    #PHI
    if choice == "phi":

        server_phi = Server(BASE_URL + RSA_RED + PHI_PART)

        try:
            #Récupération de e,n et phi
            if debug_mode:
                print("Response... ", end='')
            response_phi = server_phi.query(GET_CHALLENGE + login)
            if debug_mode:
                print("OK!")
        except:
            #Login faux??
            if debug_mode:
                print("ERROR!")
            print("Exiting...")

        e = response_phi['e']
        phi = response_phi['phi']
        n = response_phi['n']

        if debug_mode:
            print("e : {0}".format(e))
            print("phi : {0}".format(phi))
            print("n : {0}".format(n))

        p = resolve_phi_part(phi,e,n)

        if debug_mode:
            print("p : {0}".format(p))

        try:
            if debug_mode:
                print("Sending p... ", end='')
            server_phi.query(CHECK + login, {'p' : p})
            if debug_mode:
                print("OK!")
        except Exception as inst:
            #p false?
            if debug_mode:
                print("ERROR!")
                print(inst)
            print("Exiting...")

    #D
    else:

        #Pour l'explication en largeur de la résolution du problème, voir ce post : http://stackoverflow.com/questions/2921406/calculate-primes-p-and-q-from-private-exponent-d-public-exponent-e-and-the

        server_d = Server(BASE_URL + RSA_RED + D_PART)

        try:
            #Récupération de la clef publique RSA + clef secrète
            if debug_mode:
                print("Get public & secret keys... ", end='')
            response_d = server_d.query(GET_CHALLENGE + login)
            if debug_mode:
                print("OK!")
        except:
            if debug_mode:
                print("ERROR!")
            print("Exiting...")

        e = response_d['e']
        d = response_d['d']
        n = response_d['n']

        k = (e * d) - 1

        if debug_mode:
            print('k : ', k)

        r = k // 2

        while (r % 2) == 0:
            r = r // 2

        if debug_mode:
            print('r : ', r)

        t = 1

        tmp = pow(2, t) * r

        while k != tmp:
            t += 1
            tmp = pow(2, t) * r

        if debug_mode:
            print('t : ', t)

        flag = False

        for i in range(1, 101):

            if debug_mode:
                print("i : {0}".format(i))

            flag31 = False
            flag5 = False
            g = random.randint(0, n - 1)
            y = pow(g, r, n)

            if y == 1 or y == n - 1:
                continue

            for j in range(1, t):
                x = pow(y, 2, n)

                if x == 1:
                    flag5 = True
                    break

                if x == n - 1:
                    flag31 = True
                    break

                y = x

            if flag5:
                flag = True
                break

            if flag31:
                continue

            x = pow(y, 2, n)

            if x == 1:
                flag = True
                break

        if not flag:
            raise Exception('Prime factor not found!')

        p = PGCD(y - 1, n)

        if debug_mode:
            print('p : ', p)

    try:
        if debug_mode:
            print("Sending p... ", end='')
        server_d.query(CHECK + login, {'p' : p})
        if debug_mode:
            print("OK!")
    except Exception as inst:
        #p false?
        if debug_mode:
            print("ERROR!")
            print(inst)
        print("Exiting...")
