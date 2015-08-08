Remarque: $ -> prompt du Shell

--Programme mgrep

Principe:
Ce programme a pour principe de rechercher un mot dans un fichier (la lecture sur l'entrée standard n'a pas été prise en compte pour cause d'inutilité), tous les deux étant donnés en arguments du programme. Le programme va lire chaque ligne du fichier (les 80 premiers caractères d'une ligne pour être précis) et, s'il trouve le mot demandé dans la ligne, va retourner sur la sortie standard la ligne, et son numéro dans le fichier; sinon, il n'en fera rien et passera à la ligne suivante s'il y en a une!

Utilisation:
Pour afficher le "How To" du programme, il suffit simplement de faire $./mgrep, ou de ne renseigner qu'un argument sur les 2 requis.
ATTENTION, ce programme prend en compte la casse du mot recherché!
Ce programme prend en arguments un fichier .txt [1] (contenant le texte que nous voulons analyser), et un mot à chercher [2].
   $./mgrep [1] [2]
ex:$./mgrep monfichier.txt monmot

--Programme mlook

Principe:
Ce programme a pour principe de rechercher un mot dans un fichier (la lecture sur l'entrée standard n'a pas non plus été prise en compte), tous deux donnés en arguments du programme. Le programme va lire chaque ligne du fichier (les 80 premiers caractères d'une ligne pour être précis) et, s'il trouve le mot demandé dans en début de ligne seulement, va retourner sur la sortie standard la ligne, et son numéro dans le fichier; sinon, il n'en fera rien et passera à la ligne suivante, s'il y en a une!

Utilisation:
Pour afficher le "How To" du programme, il suffit simplement de faire $./mlook, ou de ne renseigner qu'un argument sur les 2 requis.
ATTENTION, ce programme prend en compte la casse du mot recherché!
Ce programme prend en arguments un fichier .txt [1] (contenant le texte que nous voulons analyser), et un mot à chercher [2].
   $./mlook [1] [2]
ex:$./mlook monfichier.txt monmot

2013 - Carette Antonin, antonin.carette[at]gmail[dot]com
