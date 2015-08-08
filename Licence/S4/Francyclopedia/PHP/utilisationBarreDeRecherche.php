<?php
session_start();
?>

<?php

// Afficher les erreurs à l'écran
ini_set('display_errors', 1);
// Enregistrer les erreurs dans un fichier de log
ini_set('log_errors', 1);
// Nom du fichier qui enregistre les logs (attention aux droits à l'écriture)
ini_set('error_log', dirname(__file__) . '/log_error_php.txt');

//On inclue les fichiers PHP afin d'utiliser leurs fonctions

//On inclue les fichiers de recherche PHP
include 'rechercheCommune.php';
include 'rechercheINSEE.php';
include 'rechercheComplementaire.php';
include 'rechercheRegionDepartement.php';

//On inclue les fichiers d'affichage
include 'affichageCommune.php';
include 'affichageParListeDe15.php';

//On inclue les fichiers concernant la carte JS
include 'changementPositionCarte.php';

//On inclue les fichiers concernant les sessions PHP
include 'sessionAjouterCommune.php';

if ( (isset($_POST['recherche_com']) && ($_POST['recherche_com'] != "")) || (isset($_POST['regions']) && ($_POST['regions'] != "None")) || (isset($_POST['recherche_pop_maxi']) && ($_POST['recherche_pop_maxi'] != "")) || (isset($_POST['recherche_pop_mini']) && ($_POST['recherche_pop_mini'] != "")) || (isset($_POST['historique']) && ($_POST['historique'] != "None")) ) { 
  if (!isset ($_POST['page_tableau'])) {
    $page = 0;
  }
  else {
    $page = $_POST['page_tableau'];
  }
  $connexionBDD = connexionBDD();
  if (isset($_POST['recherche_com']) && $_POST['recherche_com'] != ""){
    $resultat = trim($_POST['recherche_com']);
    $subResultat = substr($resultat, 0, 2); //On prend les 2 premières lettres de la chaine de caractères, cela servira à voir s'il s'agit d'un département Corse ou non
    if (!is_numeric($resultat) && $subResultat != "2A" && $subResultat != "2B" && $subResultat != "2a" && $subResultat != "2b") {
      //Recherche de la commune 
      rechercheCommune($connexionBDD, $resultat);
    }
    else {
      if (strlen($resultat) >= 5) {
	rechercheINSEE($connexionBDD, $resultat);
      }
      else {
	if (strlen($resultat) == 2) {
	  rechercheRegionDepartement($connexionBDD, $resultat, $page);
	}
	else {
	  echo "Vous devez implémenter un nom de commune, un code-postal (5 chiffres) ou encore un code de département (2 chiffres).";
	}
      }
    }
  }
  else if (isset ($_POST['historique']) && $_POST['historique'] != "None") {
    $subResultat = substr($_POST['historique'], 0, 2); //On prend les 2 premières lettres de la chaine de caractères, cela servira à voir s'il s'agit d'un département Corse ou non
    if (!is_numeric($_POST['historique']) && $subResultat != "2A" && $subResultat != "2B" && $subResultat != "2a" && $subResultat != "2b") {
      rechercheCommune($connexionBDD, $_POST['historique']);
    }
    else {
      rechercheINSEE($connexionBDD, $_POST['historique']);
    }
  }
  else {
    $region = trim($_POST['regions']);
    $pop_min = intval(trim($_POST['recherche_pop_mini']));
    $pop_max = intval(trim($_POST['recherche_pop_maxi']));
    $page = $_POST['page_tableau'];
    if ($region != null && $region != "None") { //Si l'utilisateur a utilisé la recherche de régions
      if ($pop_min == null && $pop_max == null) { //Si l'utilisateur n'a pas utilisé la recherche de population	
	rechercheRegion($connexionBDD, $region, $page);
      }
      else 
	{if ($pop_min == null) {rechercheRegionEtPopMax($connexionBDD, $region, $pop_max, $page);} //Si l'utilisateur n'a pas utilisé la recherche de population minimale
	  else {
	    if ($pop_max == null) {
	      rechercheRegionEtPopMin($connexionBDD, $region, $pop_min, $page);} //Si l'utilisateur n'a pas utilisé la recherche de population maximale
	    else {
	      rechercheRegionEtDeuxPopulations($connexionBDD, $region, $pop_max, $pop_min, $page); //Si l'utilisateur a tout utilisé
	    }
	  }
	}
    }
    else { //Si l'utilisateur n'a pas utilisé la recherche de region
      $page = $_POST['page_tableau'];
      if ($pop_min == null) { //Si l'utilisateur n'a pas utilisé la recherche de population minimale
	recherchePopMax($connexionBDD, $pop_max, $page);
      }
      else { 
	if ($pop_max == null) {//Si l'utilisateur n'a pas utilisé la recherche de population maximale
	  recherchePopMin($connexionBDD, $pop_min, $page);
	}
	else {//Si l'utilisateur a utilisé la recherche de population minimale ET maximale
	  recherchePopMaxEtMin($connexionBDD, $pop_max, $pop_min, $page);
	}
      }
    }
  }
}
else {
  include 'FAQ.php';
}
  ?>
