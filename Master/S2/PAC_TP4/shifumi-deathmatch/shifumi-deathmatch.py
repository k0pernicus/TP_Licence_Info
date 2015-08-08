import sys
import random
import math
import decimal

from client import Server
from client import ServerError

def help():
    print("argv[1] : Your login")
    print("argv[2] : -debug (no debug mode by default)")

BASE_URL = "http://pac.bouillaguet.info/TP4/shifumi-deathmatch/"
NEW_GAME = "insert-coin/"
NEW_ROUND = "start/"
MOVE = "move"
RESULT = "result"
GET_STATUS = "status/"

#ROCK   LEAP  CISORS
SHIFUMI_CHOICES = [88275625857605,19779480974019653,18939445432636760]
SHIFUMI_CHOICES_HEXA = [0x504945525245, 0x464555494C4C45, 0x43495345415558]
SHIFUMI_CHOICES_ASCII = ["PIERRE", "FEUILLE", "CISEAUX"]

g = 2

p = 26557745870447330330268679481764926291929625360711357148657088802070848521097310614244135421650171032004398195418346262004209119507280047953086389554655572611243211750975490482765000924379548764583700625115364104501244479414864081881264306514001255912115288511224399787573699093889138323123471272457814332145147500808260136883245232626272067265973192184871909084361101774011925441177777963956329858122661335023834378379928921706937810011027433644754349171873395505424202671845024957507393755098438988444563042586086652810342041940368359516875020550205839145219004391904744414025255981413017203709184197174494676398879

def is_a_quadratic_residue(a, p):
    """
    Fonction permettant de savoir si a est un résidu quadratique
    """
    return ((pow(a, (p-1)//2, p)) == 1)

def is_gx_even(gx, p):
    """
    Fonction permettant de savoir si gx est pair
    """
    return ((pow(gx, (p-1)//2, p)) == 1)

def is_gy_even(gy, p):
    """
    Fonction permettant de savoir si gy est pair
    """
    return ((pow(gy, (p-1)//2, p)) == 1)

if __name__ == "__main__":

    """
    Résolution du problème 'shifumi-deathmatch'
    """

    if (len(sys.argv) < 2):
        help()
        quit()

    #DEBUG_MODE
    if ("-debug" in sys.argv):
        debug_mode = True
    else:
        debug_mode = False

    login = sys.argv[1]

    server = Server(BASE_URL)

    if (input("New game? [y/n]") == "y"):
        #DEBUG_MODE
        if debug_mode:
            print("New game...")
        #New game
        if debug_mode:
            print(server.query(NEW_GAME + login))
        else:
            server.query(NEW_GAME+login)
    else:
        print("No new game...")

    score_user = 100

    score_IA = 100

    while ( score_user != 0 and score_IA != 0 ):

        #DEBUG_MODE
        if debug_mode:
            print("New round...")

        response_server = server.query(NEW_ROUND + login)

        foobar_entry = response_server['foobar']
        if 'commitment' in response_server:
            commitment = response_server['commitment']
            status = "OK"
        else:
            status = response_server['status']

        #DEBUG_MODE
        if debug_mode:
            if status=="OK":
                print("Commitment : {0} - foobar : {1}".format(commitment, foobar_entry))
            else:
                print("Status : {0} - foobar : {1}".format(status, foobar_entry))

        #x is the random number (between 1 and 3204252 - step one by one)
        x = random.randrange(1, p)

        #Fast modular exp. (2**32)
        h = pow(g, x, p)

        y = random.randrange(1, p)

        sh_choice = 1

        if status == "OK":
            #We search if a, gx and gy are odds.
            #If they are, the stroke is CISORS - so, we decide to play ROCK
            p_computer = commitment['PK']['p']
            gx_computer = commitment['PK']['h']
            gy_computer = commitment['ciphertext'][0]
            a_computer = commitment['ciphertext'][1]
            if is_gx_even(gx_computer,p_computer) and is_gy_even(gy_computer,p_computer) and is_a_quadratic_residue(a_computer,p_computer):
                sh_choice = 0


        m = SHIFUMI_CHOICES[sh_choice]

        #New random number to encrypt
        gy = pow(g, y, p)

        cypher_choice = (m * pow(h, y, p)) % p

        move_to_return = {'foobar' : foobar_entry, 'commitment' : { 'PK' : { 'g' : g, 'p' : p, 'h' : h}, 'ciphertext' : [gy, cypher_choice]}}

        print("Attente réponse début...", end="")
        response_server = server.query(MOVE, move_to_return)
        print("OK!")

        if debug_mode:
            print(response_server)

        barfoo_entry = response_server['barfoo']

        if status!="OK":
            commitment = response_server['commitment']
            if debug_mode:
                print("Commitment : {0}".format(commitment))
            status = "OK"

        result_to_return = {'move' : SHIFUMI_CHOICES_ASCII[sh_choice], 'k' : y, 'barfoo' : barfoo_entry}

        print("Attente réponse fin...", end="")
        response_server = server.query(RESULT, result_to_return)
        print("OK!")

        if debug_mode:
            print(response_server)
        else:
            print("Status {0}\n\tYour choice : {1}\n\tServer choice : {2}\n\tScore :: Yours {3} / Server {4}".format(response_server['status'], SHIFUMI_CHOICES_ASCII[sh_choice], response_server['move'], response_server['scores']['yours'], response_server['scores']['mine']))

        print("\n")
