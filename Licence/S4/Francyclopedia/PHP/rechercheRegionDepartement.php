<?php
/*Fonction de recherche du code de région -> chaîne de caractères conmptant 2 lettres*/
function rechercheRegionDepartement($bdd, $resultat, $page) {
  $code_region_dept = $resultat;
  $stmt = $bdd->prepare("SELECT region, dept, comm, nom, population, latitude, longitude FROM public.communes WHERE region='$code_region_dept' OR dept='$code_region_dept'");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage
  affichageParListeDe15($code_region_dept, 'null', 'null', 'null', ($stmt->fetchAll()), $page);
}
?>

