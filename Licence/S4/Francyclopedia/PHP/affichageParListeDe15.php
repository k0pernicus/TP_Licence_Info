<?php

function affichageParListeDe15($rech_com, $region, $popmin, $popmax, $tableau, $page_du_tableau) {
  $tableExtraite=$tableau;
  if ($tableExtraite != null) { //S'il y a quelque chose dans la table
    $nb_pages_liste = ceil((count($tableExtraite))/15);//partie entière du nombre de communes dans la liste divisé par 15 (par page)
    echo ("La région choisie comporte ".count($tableExtraite)." communes !</br>");   

//affichage des boutons
    if ($page_du_tableau>5) {echo ("<button STYLE='font-size: 6pt' onclick='changement_de_page($rech_com, $region, $popmin, $popmax, ($page_du_tableau-(6)));document.forms[0].submit();'> << </button>");};

    if (($page_du_tableau>=(floor($nb_pages_liste/6)*6)) && $page_du_tableau<$nb_pages_liste) {//gere les sections de moins 6 boutons
  for ($j=(1+(floor($page_du_tableau/6))*6); $j<(1+($nb_pages_liste%6)+((floor($page_du_tableau/6))*6)); $j++) {
      $variable = "<button STYLE='font-size : 6pt' id='page' onclick='changement_de_page($rech_com, $region, $popmin, $popmax, ($j-1));document.forms[0].submit();'>$j </button>";
      //chaque bouton rappelle une nouvelle recherche et renvoie la partie de 15 communes demandées
      echo ($variable);}
}
else
{
    for ($j=(1+(floor($page_du_tableau/6))*6); $j<(7+((floor($page_du_tableau/6))*6)); $j++) {
      $variable = "<button STYLE='font-size : 6pt' id='page' onclick='changement_de_page($rech_com, $region, $popmin, $popmax, ($j-1));document.forms[0].submit();'>$j </button>";
      //chaque bouton rappelle une nouvelle recherche et renvoie la partie de 15 communes demandées
      echo ($variable);}
}
	if ($page_du_tableau<$nb_pages_liste-5) {echo ("<button STYLE='font-size: 6pt' onclick='changement_de_page($rech_com, $region, $popmin, $popmax, ($page_du_tableau+(7-$page_du_tableau%6)));document.forms[0].submit();'> >> </button>");}
  echo "<br/>";
  

//traitement de l'affichage des 15 
if ($page_du_tableau==($nb_pages_liste-1)) {
echo "<table><thead><b>Résultats de votre recherche</b></thead><tr><td><b>Nom de commune</b></td><td><b>Numéro INSEE</b></td><td><b>Code région</b></td><td><b>Population</b></td></tr>";
      //on se centre sur la première ville de la page de la liste
        $X = floatval($tableExtraite[15*($page_du_tableau)]['longitude']);	
	$Y = floatval($tableExtraite[15*($page_du_tableau)]['latitude']);              
      echo "<script>window.onload=function(){start($X, $Y);}</script>";
      for ($i=15*($page_du_tableau); $i<count($tableExtraite); $i++) {
	$laCommune = $tableExtraite[$i]['nom'];
$dept = $tableExtraite[$i]['dept'];
$region = $tableExtraite[$i]['region'];
$population = $tableExtraite[$i]['population'];
$comm = $tableExtraite[$i]['comm'];
	//$Xi = floatval($$tableExtraite[$i]['latitude']);   
	//$Yi = floatval($$tableExtraite[$i]['longitude']);
	echo ("<tr id='comm'><td onclick='change_value_hidden(\"$laCommune\");document.forms[0].submit();'>$laCommune</td><td>$dept$comm</td><td>$region</td><td>$population</td></tr>");
//ajouterMarqueur($Xi, $Yi);
      }
    }
    else
   {//	$X = floatval($tableExtraite[15*($page_du_tableau)][4]);	
//		$Y = floatval($tableExtraite[15*($page_du_tableau)][3]);
 //echo "<script>window.onload=function(){start($X, $Y);}</script>";
	//	$partie_liste = array_slice($liste, (15*$page_du_tableau), 15);
	//echo "<script>window.onload=function(){carte15marqueurs($partie_liste);}</script>";
echo "<table><thead><b>Résultats de votre recherche</b></thead><tr><td><b>Nom de commune</b></td><td><b>Numéro INSEE</b></td><td><b>Code région</b></td><td><b>Population</b></td></tr>";
for ($i=15*($page_du_tableau) ; $i<15+15*($page_du_tableau) ; $i++) {
	  $laCommune = $tableExtraite[$i]['nom'];
$dept = $tableExtraite[$i]['dept'];
$region = $tableExtraite[$i]['region'];
$population = $tableExtraite[$i]['population'];
$comm = $tableExtraite[$i]['comm'];
	//  $Xi = floatval($tableExtraite[$i]['longitude']);	
	 // $Yi = floatval($tableExtraite[$i]['latitude']);
	  echo ("<tr id='comm'><td onclick='change_value_hidden(\"$laCommune\");document.forms[0].submit();'>$laCommune</td><td>$dept$comm</td><td>$region</td><td>$population</td></tr>");
// echo "<script>ajouterMarqueur($X, $Y);</script>";
	}
      }
    echo "</table></br>";
  }		

}









/*
 echo "<table border-color: transparent;><thead><b>Résultats de votre recherche</b></thead><tr><td><b>Nom de commune</b></td><td><b>Numéro INSEE</b></td><td><b>Code région</b></td><td><b>Population</b></td></tr>";
    foreach ($tableExtraite as $ligne) {
    echo "<tr><td>{$ligne['nom']}</td><td>{$ligne['dept']}{$ligne['comm']}</td><td>{$ligne['region']}</td><td> {$ligne['population']}</td></tr>";
    }
    echo "</table>";
  }
  else { //Sinon -> message d'erreur de recherche
    echo "Désolé mais la commune demandée n'est pas répertoriée dans notre base de données ...</br>Vous pouvez utiliser notre recherche spécialisée (sur la gauche) pour pouvoir effectuer votre recherche.";
  }
}*/
?>
