/*
Heuristique avec principe simple:
	Présence d'un sac courant - à chaque objet, on le met dans le sac courant s'il y a assez de place.
	Sinon, on crée un nouveau sac courant et on y met l'objet.
@param tab_objets Un tableau de n cases (correspondant au nombre d'objets), dans lequel sera affiché le sac dans lequel l'objet est contenu
*/
void next_fit(int* tab_objets);

/*
Seconde heuristique:
	Pour chaque objet, on regarde s'il entre dans un des sacs créés.
	Si ok -> on le met dans le premier (s'il convient).
	Sinon, on crée un nouveau sac et on y met l'objet.
@param tab_objets Un tableau de n cases (correspondant au nombre d'objets), dans lequel sera affiché le sac dans lequel l'objet est contenu
*/
void first_fit(int* tab_objets);

/*
Troisième heuristique:
	Pour chaque objet, on regarde s'il entre dans un des sacs créés.
	Si ok -> on le met dans celui le plus rempli, parmi ceux qui conviennent.
	Sinon, on crée un nouveau sac et on y met l'objet.
@param tab_objets Un tableau de n cases (correspondant au nombre d'objets), dans lequel sera affiché le sac dans lequel l'objet est contenu
*/
void best_fit(int* tab_objets);
