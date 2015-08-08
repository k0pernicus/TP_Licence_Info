<?php
session_start();
?>

<?php
include 'header.php';
include 'PHP/connexionBDD.php';
include 'PHP/affichageHistorique.php';
?>

<hr>

<div id="part_left">
  <div id="rech_prin">
  <form action="homepage.php" id="recherche" method="post">
  <input type="text" title="Veuillez entrer le nom d'une commune, une région (2 chiffres), un département (2 chiffres) ou un numéro INSEE (5 numéros)" id="recherche_com" name="recherche_com" placeholder="Commune (ex: Lille), Code INSEE (ex: 59001), département (ex: 59)" pattern="([a-zA-Zéèïîà]+)|([a-zA-Zéèïîà]+-[a-zA-Zéèïîà]+)|[^134567890]{1}([A-B]|[a-b])[0-9]{3}|([0-9]{2})|([0-9]{5})" >
  <div id="recherche_plus" style="display:none;">	 
  <label for="regions">Choisissez une région</label>
<select id="regions" name="regions">
  <option value="None">--</option>
  <?php
  $connexionBDD = connexionBDD();
$stmt = $connexionBDD->prepare("SELECT code, nom FROM public.regions ORDER BY nom");
$stmt->execute();
$stmt->setFetchMode(PDO::FETCH_ASSOC);
while ($ligne = $stmt->fetch()) {
  echo "<option value=\"{$ligne['code']}\"> {$ligne['nom']} </option>";
  }
?>
</select></br>
<label for="recherche_pop_mini">Population minimale</label><input type="text" id="recherche_pop_mini" name="recherche_pop_mini" placeholder="Population_mini" pattern="[0-9]*"></br>
<label for="recherche_pop_maxi">Population maximale</label><input type="text" id="recherche_pop_maxi" name="recherche_pop_maxi" placeholder="Population_maxi" pattern="[0-9]*"></br>
  <label for="historique">Votre historique</label>
<select id="historique" name="historique">
  <?php
  affichageHistorique();
?>
</select>
<a href="PHP/logout.php">Supprimer l'historique</a></br>
  </div>
  <input type="hidden" id="rech_carte" name="recherche_region" value="">   
  <input type="hidden" id="page_tableau" name="page_tableau" value="0">	
  <input type="submit" name="Go">
  <input type="button" id="plus" value="Plus d'options" onclick="changeBouton(); afficherCacher();">
  <input type="button" id="reset" value="R&eacute;initialisation" onclick="window.location='homepage.php';">
  </form>
  </div>
  
  </div>
  
  </br></br>
  
  <div id="informations">
  
  <div id="carte">
  </div>
  <div onload="document.form('recherche').elements[regions].option[0].setValue('youpi');"></div>
  <div id="part_informations">	
  <fieldset>
  <center>
  <?php
  include 'PHP/utilisationBarreDeRecherche.php';
?>
</center>
</fieldset>
</div>

</div>

</div>

<hr>

<?php
  include 'footer.php';
?>
