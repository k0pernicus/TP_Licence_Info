<?php

function rechercheCommune($bdd, $resultat) {
  $stmt = $bdd->prepare("SELECT region, dept, nom, comm, population, latitude, longitude FROM public.communes WHERE nom='$resultat'");
  $stmt->execute();
  $stmt->setFetchMode(PDO::FETCH_ASSOC);
  //Affichage des réponses
  affichage($stmt, $resultat);
}

?>