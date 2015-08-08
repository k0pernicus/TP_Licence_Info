# -*- coding: utf8 -*-

#import numpy
import numpy as np
#import matplotlib -> pyplot pour le tracé de graph
import matplotlib.pyplot as plt
#import algo
from algo import algo

class descente_gradient(algo):
    """
    Classe permettant d'implémenter l'algorithme de descente de gradient
    """

    def __init__(self, p_matrix, t_matrix, n):
        """
        Constructeur de l'objet quant à la descente de gradient
        """
        #Construction de la super-classe
        algo.__init__(self, p_matrix, t_matrix, n)
        self.A = 100.0
        self.B = 10000.0
        self.C = 1.0

    def calculerDerivee(self, t):
        f_p = self.p_matrix - np.dot(self.t_matrix.T, self.theta)
        f_p = np.dot(self.t_matrix, f_p)
        f_p = (1.0/self.n) * f_p
        f_p = (self.calculerPasApprentissage(t) * f_p)
        return f_p

    def calculerProchainPoint(self, t):
        return self.theta + self.calculerDerivee(t)

    def calculer(self):
        i = 1

        err = algo.calculerJTheta(self, self.theta)

        while (abs(err) < 10000):
            self.theta = self.calculerProchainPoint(i)
            self.tab_points.append(self.theta)
            i = i + 1
            err = err - self.calculerJTheta(self.theta)