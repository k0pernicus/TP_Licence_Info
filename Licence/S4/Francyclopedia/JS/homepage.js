/**Fonction qui permet d'afficher / cacher la partie de recherche
@author Carette Antonin
@version 1.0
*/
function afficherCacher() {
    var div = document.getElementById("recherche_plus");
    
    if (div.style.display == "none"){
	div.style.display = "block";
    }
    else {
	div.style.display = "none";
    }
}

/**Fonction qui permet de changer la couleur du bouton Plus
@author Carette Antonin
@version 1.0
*/
function changeBouton() {
    var button = document.getElementById("plus");
    if (button.style.color == "white") {
	button.style.color = "black";
	button.style.backgroundColor = "white";
    }
    else {
	button.style.backgroundColor = "grey";
	button.style.color = "white";
    }
}

/**Fonction qui permet de basculer de l'affichage d'une série de 15 communes
à l'affichage d'une autre série en cliquant sur le numéro de la série de 15
correspondant 
@author Tanguy Maréchal
@version 1.0
*/
function changement_de_page(commune, regions, popmin, popmax, page) {
if (commune != null) {var com = document.getElementById("recherche_com");
	com.setAttribute('value', commune);}
if (regions == null) {var rech = document.getElementById('regions');
rech.options[0].setAttribute('value', '');}
else {var rech = document.getElementById('regions');
rech.options[0].setAttribute('value', regions);};
var pop_min = document.getElementById("recherche_pop_mini");
	pop_min.setAttribute('value', popmin);
var pop_max = document.getElementById("recherche_pop_maxi");
	pop_max.setAttribute('value', popmax);	
var lapage = document.getElementById("page_tableau");
	lapage.setAttribute('value', page);
	}

