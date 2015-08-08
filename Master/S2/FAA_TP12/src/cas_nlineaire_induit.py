# coding: utf-8

import scipy
import numpy as np
import sklearn.datasets as datasets
from sklearn.svm import SVC
from matplotlib import pyplot as plt

#Nombre de clusters de points
nb_centers = 2

#Nombre de points en tout
n_samples = 500

#Création des clusters
X, Y = datasets.make_circles(n_samples=100, shuffle=True, noise=None, random_state=None, factor=0.8)
#Spécification de
#Création du plot
fig, axes = plt.subplots(nrows=1, ncols=1)
#Imposition de la taille de fig
fig.set_size_inches(7,7)

axes.scatter(X[:,0], X[:,1], c=Y)

#Création du svc
svc = SVC(kernel='poly', max_iter=20, C=0.3, degree=2)

#On agit sur les données
svc.fit(X, Y)

i = 0

for y in svc.predict(X):
    #Si le y prédit sur l'ensemble X est différent du y2 correspondant à Y[i]...
    if y != Y[i]:
        #On retourne un message d'erreur!
        print("false for {0} {1}".format(y, i))
    i = i+1

#OU print(abs(y - Y).sum)

hY = svc.predict(X)

print("Erreur: {0}".format(abs(hY - Y).sum()))
