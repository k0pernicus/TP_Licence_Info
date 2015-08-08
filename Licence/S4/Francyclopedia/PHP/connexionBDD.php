<?php

function connexionBDD() {
   try {
   $connexionProjet = new PDO("pgsql:host=localhost;dbname=projetWeb", "LOGIN", "MDP"); 
   return $connexionProjet;
   }
   catch(PDOException $e) {
     echo ("Erreur connexion : ".$e->getMessage());
     exit();
   }
}

?>
