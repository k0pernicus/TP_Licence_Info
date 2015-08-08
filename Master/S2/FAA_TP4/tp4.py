#-*- coding: utf-8 -*-
"""
Created on Mon Fev 02 10:32:36 2015

@author: alexandre
"""

import numpy as numpy
import matplotlib.pyplot as pyplot

"""
Charge les données
"""
def load_data():
        print("Chargement des données en cours...")
        global N, matrix, f, h, y, x
        f = numpy.loadtxt('x.txt')
        print("Chargement des données des femmes... OK")
        h = numpy.loadtxt('y.txt')
        print("Chargement des données des hommes... OK")
        matrix = numpy.concatenate((f, h), axis=0)
        N = len(matrix)
        x = numpy.vstack((matrix[:,0], numpy.ones(N)))
        y = matrix[:,1]


"""
Calcul du pas pour la descente de gradient batch
"""
def pas_batch(val):
        A = 1.0
        B = 10000
        C = 1000
        return ((A/(C + (B * val))))


"""
Calcul de f_Theta
"""
def f_theta(theta):
        return numpy.dot(theta.T, x)


"""
Affiche les résultats graphiques
"""
def print_graphs():
        """
        Nuages de points avec les données taille/poid pour les hommes et les femmes
        """

        pyplot.figure(1)
        pyplot.title("poids/taille homme/femme")
        pyplot.plot(f[:,0],f[:,1], '.', label="femme")
        pyplot.plot(h[:,0],h[:,1], '.', label="homme")
        pyplot.plot(matrix[:,0], f_theta(batch_gradient_descent()), label="theta")
        pyplot.legend()
        print("Affichage des nuages de points avec les données taille/poid pour les hommes et les femmes... OK\n")
        
        """
        Figure de la sigmoïde obtenu pour les poids homme/femme
        """
        print("Affichage de la figure de la sigmoïde obtenu pour les poids homme/femme\n")
        theta_poids = batch_gradient_descent()
        pyplot.figure(2)
        pyplot.title("Sigmoide poids homme/femme")
        xones = numpy.vstack((matrix[:,0],numpy.ones(len(matrix))))
        pyplot.plot(matrix[:,0], sigmoid(numpy.dot(numpy.array(theta_poids).T,xones)),".", label="theta")
        pyplot.legend()

        """
        Figure de la sigmoïde obtenu pour les tailles homme/femme
        """
        print("Affichage de la figure de la sigmoïde obtenu pour les tailles homme/femme\n")
        theta_taille = batch_gradient_descent()
        pyplot.figure(3)
        pyplot.title("Sigmoide taille homme/femme")
        xones = numpy.vstack((matrix[:,1],numpy.ones(len(matrix))))
        pyplot.plot(matrix[:,1], sigmoid(numpy.dot(numpy.array(theta_taille).T,xones)),".", label="theta")
        pyplot.legend()
        
        print("Cette sigmoïde sert à écraser les points représentant les hommes et les femmes sur les valeurs 0 et 1.\nCet écrasement est caculé à partir de l'apprentissage des données connus fournit à priori. \nPar la suite nous serons en mesure à partir d'un jeu de données poids/tailles de déterminé avec un certain taux d'erreur s'il s'agit d'un homme ou d'une femme à partir juste de son poids ou juste de sa taille ou des deux.")

        """
        PERFORMANCE        
        
        taux = 0.0
        best_taux = 0.0
        best_score = 0.0
        tmp_taux = 0.0
        while(taux <= 1.0):
                tmp_taux = perf(taux, theta_poids)
                if(tmp_taux > best_score):
                        best_taux = taux
                        best_score = tmp_taux
        """


        """
        Affichage des figures
        """
        pyplot.show()


def j_theta(theta):
        tmp = (y - numpy.dot(x.T, theta))
        return ((1.0/N) * numpy.dot(tmp.T, tmp))

"""
Descente de gradient batch
"""
def batch_gradient_descent():
        theta = [1, 1]
        previous = j_theta(theta)
        current = previous + 1
        i = 1
        while (abs(previous - current) > 10e-6):
                previous = current
                theta = theta + (pas_batch(i) * (1.0/N) * numpy.dot(x, (y - numpy.dot(x.T, theta))))
                i+=1
                current = j_theta(theta)
        #print "Batch theta = ", theta
        return theta

"""
Calcul de la sigmoïde
"""
def sigmoid(param):
        a = 1
        b = param.mean(0)

        b = b *(-1)
        
        sig = 1 / (1    + numpy.exp((numpy.dot(a,param) + b)))
        
        return sig

def main():
        load_data()
        print_graphs()


if __name__ == '__main__':
        main()
