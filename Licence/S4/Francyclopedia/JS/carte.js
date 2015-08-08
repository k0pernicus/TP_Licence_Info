var map;
var zoom = 12;
var bool = true; //Si l'on a trouvé [true] -> On place un marqueur ; sinon [false] -> On ne place rien
//Initialisation de la carte
function init(longitude, latitude, bool){
    //On crée la map et on lui ajoute un fond -> OSM()
    map = new OpenLayers.Map("carte");//Création de l'objet carte; tableau vide pour les contrôles de la carte 
    map.addLayer(new OpenLayers.Layer.OSM()); //On ajoute le fond de carte à la map -> addLayer

    //On ajoute à la map un calque contenant les marqueurs
    calqueMarkers = new OpenLayers.Layer.Markers("Repères");
    map.addLayer(calqueMarkers);

    //On donne 2 contrôles à l'utilisateur : la possibilité de zoomer et la possiblité d'ajouter ou d'enlever les calques
    map.addControl(new OpenLayers.Control.MousePosition());
    map.addControl(new OpenLayers.Control.LayerSwitcher({'ascending':false}));
    
    //On effectue une projection pour pouvoir repérer les bonnes coordonnées
    var projCarte = map.getProjectionObject();
    var projSpherique = new OpenLayers.Projection("EPSG:4326"); 
    
    //On fait la conversion des coordonnées
    var coord = new OpenLayers.LonLat(longitude,latitude); // coordonnées en longitude/latitude
    coord.transform(projSpherique,projCarte);
    map.setCenter(coord, zoom);
    
    //Si l'on a trouvé la localisation, on crée un marqueur sur la map -- à chaque visite, l'utilisateur trouvera les lieux marqués !
    if (bool != false) {
	var size = new OpenLayers.Size(21,25);
	var offset = new OpenLayers.Pixel(-(size.w/2), -size.h);

	var icon = new OpenLayers.Icon('http://www.openlayers.org/dev/img/marker.png', size, offset);
	
	var marker = new OpenLayers.Marker(coord);
	calqueMarkers.addMarker(marker);
	//essai d'ajout d'un marqueur sur la carte : fonctionne
	/*
	  var coord2 = new OpenLayers.LonLat(3.1814,50.6889); // coordonnées en longitude/latitude
	  coord2.transform(projSpherique,projCarte);
	  var marker2 = new OpenLayers.Marker(coord2);
	  calqueMarkers.addMarker(marker2);
	*/
    }
}

function ajouterMarqueur(X, Y) {
    var coordsup = new OpenLayers.LonLat(Y,X); // coordonnées en longitude/latitude
    coordsup.transform(projSpherique,projCarte);
  	var markersup = new OpenLayers.Marker(coordsup);
    calqueMarkersSup.addMarker(markersup);
}

//Création de la carte, avec X et Y, 2 paramètres
function start(X, Y) {
    if (typeof(X) == "undefined" || typeof(Y) == "undefined") {
	//Valeurs par défaut de X et Y
	X = 2.2096674442291;
	 Y = 46.448503605859;
	zoom = 5;
	bool = false;
    }
    init(parseFloat(X), parseFloat(Y), bool);
}


