# -*- coding: utf8 -*-

#import numpy
import numpy as np
#import matplotlib -> pyplot pour le tracé de graph
import matplotlib.pyplot as plt

class algo:
    """
    Classe permettant d'implémenter un algorithme de descente de gradient
    """

    def __init__(self, p_matrix, t_matrix, n):
        #Matrice de départ P
        self.p_matrix = p_matrix
        #Matrice de départ T
        self.t_matrix = t_matrix
        #Longueur de la matrice T
        self.n = n
        #Matrice theta
        self.theta = [0,0]
        #Définit le tableau de points calculés à partir de self.point_depart
        self.tab_points = [self.theta]
        #Définit la variable A nécessaire au calcul du pas d'apprentissage
        self.A = 1.0
        self.B = 1.0
        self.C = 1.0

    def calculerPasApprentissage(self, t):
        """
        Méthode permettant de calculer le pas d'apprentissage -> alpha_t = A / (B + C * t)
        """
        return (self.A / (self.B + (self.C * t)))

    def calculerJTheta(self, theta):
        """
        Méthode permettant de minimiser l'erreur quadratique moyenne
        """
        deb_matrix = self.p_matrix - np.dot(self.t_matrix.T, theta)
        return ((1.0/self.n) * np.dot(deb_matrix.T, deb_matrix))

    def calculerProchainPoint(self, t):
        """
        Méthode permettant de calculer la prochaine position d'un point
        """
        pass

    def calculerDerivee(self, t):
        """
        Méthode permettant de calculer la dérivée
        """
        pass
