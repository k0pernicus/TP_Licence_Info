# -*- coding: utf8 -*-

#import numpy
import numpy as np
#import matplotlib -> pyplot pour le tracé de graph
import matplotlib.pyplot as plt

def calculer_theta():
    """
    Fonction permettant de calculer le theta
    """
    global t

    global p

    global txp

    #Chargement des fichiers contenant les matrices - fichiers contenus dans ../ex/
    t = np.loadtxt("../ex/t.txt")
    p = np.loadtxt("../ex/p.txt")

    #Concaténation des matrices de t et de 1
    txp = np.vstack((t, np.ones(len(t))))

    #Calcul
    #(XXt)^(-1) * (XY)
    return np.dot(np.linalg.inv(np.dot(txp, txp.T)), np.dot(txp, p))

def calculer_f_theta():
    """
    Fonction permettant de calculer la fonction permettant de prédire la position avec le temps
    """
    global t

    global theta

    global txp

    return np.dot(theta.T, txp)

def calculer_erreur_moyenne_quadratique():
    """
    Fonction permettant de calculer l'erreur quadratique moyenne
    """
    global t

    global p

    global txp

    global theta

    #Calcul
    #1/N * ||(Y - Xt*theta)t||^2 mais ||A||^2 = At*A
    #--> 1/N * ((Y - Xt*theta)t * (Y - Xt*theta))
    A = p - (np.dot(theta.T, txp))
    At = A.T

    return (1.0 / len(t)) * np.dot(At,A)

def trace_graph(f_theta):
    """
    Fonction permettant de dessiner un graph contenant la ligne directrice position = f_theta(temps)
    """
    global t

    global p

    plt.plot(t,p, '*')
    plt.plot(t, f_theta)
    plt.xlabel('Temps(s)')
    plt.ylabel('Position(m)')
    plt.title("TP1 - Fonction = f_theta(Temps)")
    plt.grid(True)
    plt.show()

if __name__ == '__main__':

    #t contiendra une matrice de deux colones : xi et 1
    global t

    #p contiendra une matrice de une colone : yi
    global p

    #theta contiendra la valeur du calcul de theta
    global theta

    theta = calculer_theta()

    f_theta = calculer_f_theta()

    e_q_moy = calculer_erreur_moyenne_quadratique()

    print "Theta : {0}\nF_theta : {1}\nErreur moyenne quadratique : {2}".format(theta, f_theta, e_q_moy)

    print "Vous pouvez voir sur le graphe la droite la plus représentative du nuage de points, via la méthode des moindres carrés"

    trace_graph(f_theta)
