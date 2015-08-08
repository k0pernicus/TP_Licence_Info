<?php

// Afficher les erreurs à l'écran
ini_set('display_errors', 1);
// Enregistrer les erreurs dans un fichier de log
ini_set('log_errors', 1);
// Nom du fichier qui enregistre les logs (attention aux droits à l'écriture)
ini_set('error_log', dirname(__file__) . '/log_error_php.txt');

//Si la région a été spécifiée

function rechercheRegion($bdd, $region, $page) {
  $stmt=$bdd->prepare("SELECT region, nom, dept, comm, population, latitude, longitude FROM public.communes WHERE public.communes.region='$region'");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', $region, 'null', 'null', ($stmt->fetchAll()), $page);
}

function rechercheRegionEtPopMax($bdd, $region, $populationMax, $page) {
  $stmt=$bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE region='$region' AND population <= $populationMax");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', $region, 'null', $populationMax, ($stmt->fetchAll()), $page);
}

function rechercheRegionEtPopMin($bdd, $region, $populationMin, $page) {
  $stmt=$bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE region='$region' AND population >= $populationMin");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', $region, $populationMin, 'null', ($stmt->fetchAll()), $page);
} 

function rechercheRegionEtDeuxPopulations($bdd, $region, $populationMax, $populationMin, $page) {
  $stmt=$bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE region='$region' AND population <= $populationMax AND population >= $populationMin");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', $region, $populationMin, $populationMax, ($stmt->fetchAll()), $page);
}

//Si la région n'a pas été spécifiée

function recherchePopMax($bdd, $populationMax, $page) {
$stmt=$bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE population <= $populationMax");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', 'null', 'null', $populationMax, ($stmt->fetchAll()), $page);
}

function recherchePopMin($bdd, $populationMin, $page) {
$stmt=$bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE population >= $populationMin");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', 'null', $populationMin, 'null', ($stmt->fetchAll()), $page);
}
 
function recherchePopMaxEtMin($bdd, $populationMax, $populationMin, $page) {
$stmt=$bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE population <= $populationMax AND population >= $populationMin");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15('null', 'null', $populationMin, $populationMax,  ($stmt->fetchAll()), $page);
} 

?>
