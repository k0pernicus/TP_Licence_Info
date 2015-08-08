import sys
import os
import re
import time

def tri_valeurs_decr(x, y):
    """
    Fonction permettant de trier deux valeurs d'un dictionnaire de façon décroissante (du plus grand au plus petit)
    """
    if x[1] > y[1]:
        return -1
    elif x[1] ==y [1]:
        return 0
    return 1

def analyse_texte(texte):
    """
    Fonction permettant de télécharger du texte issu de Wikipédia.
    Les textes sont issus de http://redac.univ-tlse2.fr/corpus/wikipedia.html
    """
    unigrammes = dict()
    bigrammes = dict()
    with open(texte, encoding='utf-8') as fichier_txt:
        #Pour chaque ligne du fichier, on va la lire et la traiter en une suite de bigrammes
        for ligne in fichier_txt:
            #Regex pour échapper le numéro de ligne
            ligne = re.search('\d+\s(.*)',ligne).group(1)
            #Regex pour remplacer toute la ponctuation de chaque ligne
            ligne = re.sub(r'[^\w\s]',' ',ligne)
            split_ligne = ligne.split(' ')
            #Formation des unigrammes
            #Les bigrammes seront organisés de la façon {'mot_avant' : {'mot_apres_1' : nbr_occurence, 'mot_apres_2' : nbr_occurence, ...}, ...}
            for i in range (1, len(split_ligne)):
                valeur = split_ligne[i-1]
                clef = split_ligne[i]
                if valeur in unigrammes.keys():
                    if clef in unigrammes[valeur]:
                        unigrammes[valeur][clef] = unigrammes[valeur][clef] + 1
                    else:
                        unigrammes[valeur][clef] = 1
                else:
                    bigrammes[valeur] = {}
                    bigrammes[valeur][clef] = 1
            #Formation des trigrammes
            for i in range (2, len(split_ligne)):
                valeur1 = split_ligne[i-2]
                valeur2 = split_ligne[i-1]
                clef = split_ligne[i]
                if (valeur1, valeur2) in bigrammes.keys():
                    if clef in bigrammes[(valeur1, valeur2)]:
                        bigrammes[(valeur1, valeur2)][clef] = bigrammes[(valeur1, valeur2)][clef] + 1
                    else:
                        bigrammes[(valeur1, valeur2)][clef] = 1
                else:
                    bigrammes[(valeur1, valeur2)] = {}
                    bigrammes[(valeur1, valeur2)][clef] = 1
    #return mots, bigrammes, trigrammes
    return unigrammes, bigrammes

def fonction_aide():
    print("python3.4 main.py <votre_fichier_base>")
    quit()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        fonction_aide()

    if "-debug" in sys.argv:
        debug_mode = True
    else:
        debug_mode = False

    if debug_mode:
        print("-> Analyse de texte commencée...")

    temps_deb = time.time()

    #Analyse du texte et transformation du texte en un ensemble de bigrammes
    #bigrammes, trigrammes = analyse_texte(sys.argv[1])
    unigrammes, bigrammes = analyse_texte(sys.argv[1])

    temps_fin = time.time()

    if debug_mode:
        print("-> Analyse de texte terminée...")
        print("Temps total d'exécution : {0}m{1}sec".format( (temps_fin - temps_deb)//60, (temps_fin - temps_deb)%60 ))
        print()
        print("-> Tri du tableau selon les valeurs décroissantes")

    if debug_mode:
        print("-> Visualisation des grammes...")
        #print("--> grammes : {0}".format(mots))
        print("--> bigrammes : {0}".format(bigrammes))
        #print("--> trigrammes : {0}".format(trigrammes))

    print("Entrez votre phrase (incomplète / -QUIT- pour quitter): ")

    phrase = input()

    while (phrase != "-QUIT-"):

        tab_phrase = phrase.split(' ')

        liste_triee = []

        if len(tab_phrase) > 1:
            liste_triee = sorted(bigrammes[(tab_phrase[-2], tab_phrase[-1])], key=bigrammes[(tab_phrase[-2], tab_phrase[-1])].get)
            if len(liste_triee) >= 3:
                liste_triee = [liste_triee[-1], liste_triee[-2], liste_triee[-3]]
        else:
            liste_triee = sorted(unigrammes[tab_phrase[-1]], key=unigrammes[tab_phrase[-1]].get)
            if len(liste_triee) >= 3:
                liste_triee = [liste_triee[-1], liste_triee[-2], liste_triee[-3]]

        print("Valeurs possibles : ")

        for mot in liste_triee:
            print("\t{0} {1}".format(phrase, mot))

        print()

        print("Entrez votre phrase (incomplète / -QUIT- pour quitter): ")

        phrase = input()
