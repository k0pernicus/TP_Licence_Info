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
X, Y = datasets.make_blobs(centers=nb_centers, n_samples=n_samples, cluster_std=0.3, random_state=0)
#Création du plot
fig, axes = plt.subplots(nrows=1, ncols=1)
#Imposition de la taille de fig
fig.set_size_inches(7,7)

axes.scatter(X[:,0], X[:,1], c=Y)

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

##FIN DE LA VÉRIFICATION

#On trace chaque cercle permettant d'entourer chaque point des clusters, POUR LES VECTEURS SUPPORTS de l'objet SVC

for i in svc.support_vectors_:
    circle_to_add = plt.Circle((i[0], i[1]), .08, color='r', fill=False)
    axes.add_artist(circle_to_add)

#On trace maintenant la droite de séparation

#On sauve chaque poids dans w, contenu dans coef_
w = svc.coef_

#w1x1 + w2+x2 = 0 --> b aspiré dans wT

#Rajout du coefficient constant 'b' -> le 'b' n'est pas calculé, il est prit directement de 'intercept()'
b = svc.intercept_

w1 = w[0, 0]

w2 = w[0, 1]

x2 = []

x1 = 0

for i in range(0, 2):
    x2_to_add = ((-(w1 * x1)) - b) / w2
    x2.append(x2_to_add)
    x1 = 50

#Maintenant, x2 représentent les deux points pour tracer la droite
#On trace donc la droite séparatrice
line = plt.Line2D([0, 50], x2, color='y')
axes.add_line(line)

#Représentation des marges

#Calcul de la marge
m = 1 / np.linalg.norm(w)

print("marge : {0}".format(m))

#On dessine les droites représentant les marges

#1ÈRE MARGE
w1 = w[0, 0]

w2 = w[0, 1]

x2 = []

x1 = 0

for i in range(0, 2):
    x2_to_add = ((-(w1 * x1)) - b + 1) / w2
    x2.append(x2_to_add)
    x1 = 50

#Maintenant, x2 représentent les deux points pour tracer la droite
#On trace donc la droite séparatrice
line = plt.Line2D([0, 50], x2, color='g')
axes.add_line(line)

#2ÈME MARGE
w1 = w[0, 0]

w2 = w[0, 1]

x2 = []

x1 = 0

for i in range(0, 2):
    x2_to_add = ((-(w1 * x1)) - b - 1) / w2
    x2.append(x2_to_add)
    x1 = 50

#Maintenant, x2 représentent les deux points pour tracer la droite
#On trace donc la droite séparatrice
line = plt.Line2D([0, 50], x2, color='g')
axes.add_line(line)

#Cas linéaire OK!!!!!!!!!

#Cas non-linéaire (make_circles pour induire des travaux non-linéaires)
# -> Changement manuel d'espace
#   --> Changement d'espace avec XX (c'est à dire un polynome d'ordre 2 x1, x2, x1x2, x1^2 et x2^2) - TOUJOURS LE NOYAU LINÉAIRE!!!
# -> Changement induit par le noyau
#   --> NOYAU POLY (avec degree = 2)

#On montre le plot
plt.show()
