# -*- coding: utf8 -*-

#import numpy
import numpy as np
#import matplotlib -> pyplot pour le tracé de graph
import matplotlib.pyplot as plt
#import algo
from algo import algo

class descente_gradient_stoch(algo):
    """
    Classe permettant d'implémenter l'algorithme de descente de gradient stochastique
    """

    def __init__(self, p_matrix, t_matrix, n):
        """
        Constructeur de l'objet quant à la descente de gradient stochastique
        """
        #Construction de la super-classe
        algo.__init__(self, p_matrix, t_matrix, n)
        self.A = 0.1
        self.B = 0.0001
        self.C = 1.0

    def calculerDerivee(self, t):
        f_p = np.dot(np.array(self.theta).T, [[self.t_matrix[0][t]], [1]])
        f_p = self.p_matrix[t] - f_p
        f_p = np.dot([[self.t_matrix[0][t]], [1]], f_p)
        f_p = np.dot(self.calculerPasApprentissage(t),f_p)
        return f_p

    def calculerProchainPoint(self, t):
        return self.theta + self.calculerDerivee(t)

    def calculer(self):

        err = self.calculerJTheta(self.theta)

        for i in range(0, self.n):
            self.theta = self.calculerProchainPoint(i)
            self.tab_points.append(self.theta)
            err = err - self.calculerJTheta(self.theta)
