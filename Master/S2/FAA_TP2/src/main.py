# -*- coding: utf8 -*-

#import numpy
import numpy as np
#import matplotlib -> pyplot pour le tracé de graph
import matplotlib.pyplot as plt
#import algo
import algo
#import des algos dérivant de algo
from descente_gradient import descente_gradient
from descente_gradient_stoch import descente_gradient_stoch

def f_theta(theta, txp):
    return np.dot(theta.T, txp)

def print_graphs(t, txp, batch, stoch):

    plt.figure(1)
    plt.title("General - Batch & Stoch")
    plt.grid(True)
    plt.plot(t, f_theta(batch.tab_points[-1], txp), '--', label = "Batch")
    plt.plot(t, f_theta(stoch.tab_points[-1], txp), '.', label = "Stoch")
    plt.legend()

    plt.figure(2)
    plt.title("Batch only")
    plt.grid(True)
    plt.plot(batch.tab_points, '--', label = "Batch")
    plt.legend()

    print("Sur le graph Batch, on voit bien le Theta converger - ici, il y a évolution par progression.")

    plt.figure(3)
    plt.title("Stoch only")
    plt.grid(True)
    plt.plot(stoch.tab_points, '--', label = "Stoch")
    plt.legend()

    print("Sur le graph Stoch, on voit bien qu'il n'y a pas évolution par progression, par l'oscillation première et la courbe tendant vers une valeur rapidement.")

    plt.show()

if __name__ == '__main__':

    #Chargement des fichiers contenant les matrices - fichiers contenus dans ../ex/
    t = np.loadtxt("../ex/t.txt")
    p = np.loadtxt("../ex/p.txt")

    print "Chargement des données... OK!"

    n = len(t)

    #Concaténation des matrices de t et de 1
    txp = np.vstack((t, np.ones(len(t))))

    print "Comparaison des deux méthodes de gradient (batch et stochastique)"

    print "Calcul de la descente de gradient BATCH! -> moins rapide, car s'appuyant sur un calcul évalué sur toutes les données"

    batch = descente_gradient(p, txp, n)
    batch.calculer()

    print "Theta vaut {0} - exactement le même que pour la méthode des moindres carrés!".format(batch.theta)

    stoch = descente_gradient_stoch(p, txp, n)
    stoch.calculer()

    print "Calcul de la descente de gradient STOCHASTIQUE! -> plus rapide, car ne s'appuyant pas sur toutes les données"

    print("Batch: {0}".format(batch.theta))
    print("Stoch: {0}".format(stoch.theta))

    print_graphs(t, txp, batch, stoch)
