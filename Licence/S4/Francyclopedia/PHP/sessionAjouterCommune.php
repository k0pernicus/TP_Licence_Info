<?php
function sessionAjouterCommune($resultat) {
  if (!isset($_SESSION['communes']['nom'])) {
    $_SESSION['communes']['nom'] = array();
}
    array_push($_SESSION['communes']['nom'], $resultat);
}
?>