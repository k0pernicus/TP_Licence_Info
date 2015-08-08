# coding: utf-8

import scipy
import numpy as np
import sklearn.datasets as datasets
from sklearn.svm import SVC
from matplotlib import pyplot as plt

def phi(x):
    x_nd = []
    x0 = x[:,0]
    x1 = x[:,1]
    for l in range(0, len(x)):
        x_nd.append([1, x0[l], x1[l], pow(x0[l], 2), pow(x1[l],2)])
    return x_nd

#Nombre de clusters de points
nb_centers = 2

#Nombre de points en tout
n_samples = 500

#Création des clusters
X, Y = datasets.make_circles(n_samples=100, shuffle=True, noise=None, random_state=None, factor=0.8)

#Spécification de phi(x)
X = phi(X)

#Création du svc
svc = SVC(kernel='linear', max_iter=20, C=0.3)

#On agit sur les données
svc.fit(X, Y)

#DÉBUT Vérification de la prédiction
#Utilisation de la fonction 'predict' sur l'ensemble X -> si les y sortis sont égaux aux y2 correspondant à chaque point déjà classé

i=0

for y in svc.predict(X):
    #Si le y prédit sur l'ensemble X est différent du y2 correspondant à Y[i]...
    if y != Y[i]:
        #On retourne un message d'erreur!
        print("false for {0} {1}".format(y, i))
    i = i+1

#OU print(abs(y - Y).sum)

hY = svc.predict(X)

print("Erreur: {0}".format(abs(hY - Y).sum()))
