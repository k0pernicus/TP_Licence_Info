# -*- coding: utf8 -*-

#import numpy
import numpy as np
#import matplotlib -> pyplot pour le tracé de graph
import matplotlib.pyplot as plt
#import sys
import sys

def calculer_theta(matrice_x, matrice_y):
    """
    Fonction permettant de calculer le theta de deux matrices
    """

    print "Calcul de theta... OK!"

    #Calcul
    #(XXt)^(-1) * (XY)
    return np.dot(np.linalg.inv(np.dot(matrice_x, matrice_x.T)),np.dot(matrice_x, matrice_y))

def calculer_f_theta(theta, txp):
    """
    Fonction permettant de calculer la fonction permettant de prédire la position avec le temps
    """

    print "Calcul de f_theta... OK!"

    return np.dot(theta.T, txp)

def calculer_j_theta(txp, p, theta):
    """
    Méthode permettant de minimiser l'erreur quadratique moyenne
    """

    global length

    print "Calcul de j_theta... OK!"

    deb_matrix = p - np.dot(txp.T, theta)
    return ((1.0/length) * np.dot(deb_matrix.T, deb_matrix))

def i_ve_got_the_powaa(matrice_x, m):
    """
    Calcule la matrice txp - degré m
    m contient le degré du polynome à prendre en compte
    """

    length = len(matrice_x)

    #hyp contient l'espace d'hypothèses
    txp = np.vstack((np.ones(length), matrice_x))

    if m == 0:
        return np.ones(length)

    if m == 1:
        return txp

    #création de l'espace d'hypothèses
    for i in range(2, m):
        #ajout d'une ligne correspondant à x^i
        txp = np.vstack((txp, np.power(matrice_x, i)))

    return txp

def trace_graph(theta, ordre):
    """
    Fonction permettant de dessiner un graph contenant la ligne directrice position = f_theta(temps)
    """
    global t

    global p

    t_powaa_calcul = i_ve_got_the_powaa(t, ordre)

    print("len t_powaa : {0}".format(len(t_powaa_calcul)))

    plt.plot(t,p, '*')
    plt.grid(True)
    plt.xlabel('Temps(s)')
    plt.ylabel('Position(m)')
    plt.title("TP1 - Fonction = f_theta(Temps)")
    plt.scatter(t, calculer_f_theta(calculer_theta(t_powaa_calcul, p), t_powaa_calcul))
    plt.show()

if __name__ == '__main__':
    """
    Main du programme
    Nécessite un argument : nombre d'ordre de l'espace d'hypothèses
    """

    #t contiendra une matrice de une colonne : xi
    global t

    #p contiendra une matrice de une colonne : yi
    global p

    #len contient la longueur de la matrice t
    global length

    m = int(sys.argv[1])

    #chargement des fichiers contenant les matrices - fichiers contenus dans ../ex/
    t = np.loadtxt("../ex/x_C3.txt")
    p = np.loadtxt("../ex/y_C3.txt")

    length = len(t)

    risque_reel_partie = 0

    j = 2

    #Validation croisée en m plis (on effectue les calculs sur 1 pli)
    for i in range(0, m):

        #On split chaque matrice (txp et p) par 10, l'ordre du polynome
        tmp_t = np.split(t, m)
        tmp_p = np.split(p, m)

        #On enlève 10% de chaque matrice -> ne fait pas partie de la base d'apprentissage
        tmp_t.pop(i)
        tmp_p.pop(i)

        #Rassemblement de chaque morceaux de matrices
        tmp_t = np.concatenate(tmp_t)
        tmp_p = np.concatenate(tmp_p)
        
        #Transformation en tableau
        tmp_t = np.array(tmp_t)
        tmp_p = np.array(tmp_p)

        tmp_t = i_ve_got_the_powaa(tmp_t, j)

        #Calcul du theta de chaque partie
        theta_partie = calculer_theta(tmp_t, tmp_p)

        #Calcul du taux d'erreur
        risque_reel_partie = risque_reel_partie + calculer_j_theta(tmp_t, tmp_p, theta_partie)

    risque_reel_definitif = risque_reel_partie + 0.1

    risque_reel_partie = risque_reel_partie / m
    print("Risque réel : {0}".format(risque_reel_partie))

    while(risque_reel_definitif > risque_reel_partie):
        print("risque_reel_definitif : {0}".format(risque_reel_definitif))
        print("risque_reel_partie : {0}".format(risque_reel_partie))
        risque_reel_definitif = risque_reel_partie
        j = j + 1
        print("j : {0}".format(j))
        risque_reel_partie = 0
        for i in range(0, m):
            tmp_t = np.split(t, m)
            tmp_p = np.split(p, m)
          
            tmp_t.pop(i)
            tmp_p.pop(i)
          
            tmp_t = np.concatenate(tmp_t)
            tmp_p = np.concatenate(tmp_p)
              
            tmp_t = np.array(tmp_t)
            tmp_p = np.array(tmp_p)

            tmp_t = i_ve_got_the_powaa(tmp_t, j)
              
            theta_partie = calculer_theta(tmp_t, tmp_p)
            risque_reel_partie = risque_reel_partie + calculer_j_theta(tmp_t, tmp_p, theta_partie)
    
            risque_reel_partie = (risque_reel_partie / m)

    print "Le meilleur ordre polynomial est {0} avec pour risque réel {1}".format(j - 1, risque_reel_definitif)

    print "Tracé du graphe..."

    #Tracé du graph, avec utilisation de l'ordre polynomial
    trace_graph(theta_partie, j - 1)

    print "Tracé du graphe... OK!"

    #The End