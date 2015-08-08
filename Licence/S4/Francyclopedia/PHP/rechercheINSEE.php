
<?php

/*Fonction de recherche du numéro INSEE -> chaîne de caractères conmptant 5 lettres*/
function rechercheINSEE($bdd, $resultat) {
  $code_departement = substr($resultat, 0, 2); //On prend les 2 premières lettres de la chaîne de caractères (ex : 59500 -> 59)
  $code_commune = substr($resultat, 2, 4); //On prend les 3 dernières lettres de la chaîne de caractères (ex : 59500 -> 500)
  $stmt = $bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE dept='$code_departement' AND comm='$code_commune'");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichage($stmt, $resultat);
}
?>