function change_image(region) {
var ShowItem = document.getElementById("carte" );
ShowItem.setAttribute("src", 'images/images_accueil/france_'+region+'.png');
return true;
}


function hide_image() {
var ShowItem = document.getElementById("carte" );
ShowItem.setAttribute("src", 'images/images_accueil/france.png');
return true;
}

function preload_image(a){var b=new Image;b.src=a}

function change_value_hidden(region) {
    var valeur_region = document.getElementById("recherche_com");
    valeur_region.setAttribute("value", region);
}