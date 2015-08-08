<?php

function affichage($tableau, $resultat) {
  $ligne=$tableau->fetch();
  if ($ligne != null) {
    echo "<table border-color: transparent;><thead><b>Résultats de votre recherche</b></thead><tr><td><b>Nom de commune</b></td><td><b>Numéro INSEE</b></td><td><b>Code région</b></td><td><b>Population</b></td></tr>";
    echo "<tr><td>{$ligne['nom']}</td><td>{$ligne['dept']}{$ligne['comm']}</td><td>{$ligne['region']}</td><td> {$ligne['population']}</td></tr>";
    echo "</table>";
    //On enregistre dans l'historique ce qu'a entré l'utilisateur
    sessionAjouterCommune($resultat);
    //On zoome sur la carte
    $X = floatval($ligne['longitude']);
    $Y = floatval($ligne['latitude']);
    changementPositionCarte($X, $Y);
  }
  else {
    echo "Désolé mais la commune ou la région demandée n'est pas répertoriée dans notre base de données ...</br>Vous pouvez utiliser notre recherche spécialisée (sur la gauche) pour pouvoir effectuer votre recherche.";
  }
}
?>