<?php
   session_start();
?>

<!DOCTYPE html>
<html>

<head>
<meta http-equiv="Content-type" content="text/html; charset=utf-8" /> 
<title>
--Francyclopedia accueil -- 
</title>
<link href='http://fonts.googleapis.com/css?family=Vollkorn:400italic,700italic,400,700' rel='stylesheet' type='text/css'>
<link rel="stylesheet" type="text/css" href="CSS/accueil_francyclopedia.css"/>
<link rel="stylesheet" type="text/css" href="CSS/footer.css"/>
<script type="text/javascript" src="JS/regions.js"></script>
<script>
function affichage_utilisation(nom_de_la_page, nom_interne_de_la_fenetre)
{
window.open (nom_de_la_page, nom_interne_de_la_fenetre, config='height=600, width=500, toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, directories=no, status=no')
}
</script>

</head>

<body>
<h1>
Francyclopedia
</h1>
<h2>L'encyclopédie </br>
des communes </br>
de France</h2>

<a href="javascript:affichage_utilisation('utilisation_accueil.html','Documentation de Francyclopedia');" style="color: blue; text-decoration: none; font-family: sans-serif;">Comment utiliser Francyclopedia ?</a>

 </div> 
<div id="txt_recherche">Votre recherche :</div>

<div id="recherche">
<form action="homepage.php" id="recherche" method="post">
  <input type="text" title="Veuillez entrer le nom d'une commune, une région (2 chiffres), un département (2 chiffres) ou un numéro INSEE (5 numéros)" id="recherche_com" name="recherche_com" placeholder="Commune (ex: Lille), Code INSEE (ex: 59001), département (ex: 59)" pattern="([a-zA-Zéèïîà]+)|([a-zA-Zéèïîà]+-[a-zA-Zéèïîà]+)|[^134567890]{1}([A-B]|[a-b])[0-9]{3}|([0-9]{2})|([0-9]{5})" >
  <input type="submit" name="Valider"/>
</form>



</div>
<div id="recherche_complementaire">Les options disponibles
<ul>
<li>Région</li>
<li>Département</li>
<li>Population (+/-10%)</li>
</ul>
</div> 

<!-- affichage et gestion de la carte -->
<img id="carte_fond" src=" images/images_accueil/france.png" alt="" usemap="#france_map">

<div  class ="Map" id="area_image">
                  <img id="carte" src=" images/images_accueil/france.png" alt="" usemap="#france_map">
                  </div>

<!-- définition de toutes les zones de la cartes des régions -->
<map name="france_map">
<area shape="poly" title="region1"
<area shape="poly" coords="443,104,456,102,465,106,456,124,448,138,444,159,446,185,436,190,425,182,420,170,431,144,427,142,434,119,420,112,425,104,439,111"  nohref 
		  onMouseOver="change_image('alsace')" 
		  onMouseOut="hide_image()" alt="Alsace"
		  onClick="change_value_hidden('42');document.forms['recherche'].submit();">
	 
<area shape="poly" coords="444,103,439,110,424,102,420,111,433,119,424,138,427,146,419,167,386,165,377,156,377,148,355,133,347,117,354,93,356,79,366,79,378,80,400,84,419,99,438,97"
nohref
		  onMouseOver="change_image('lorraine')" 
		  onMouseOut="hide_image()" alt="Lorraine"
onClick="change_value_hidden('41');document.forms['recherche'].submit();"> 

<area shape="poly" coords="363,77,355,82,351,113,352,126,379,147,378,158,383,170,376,178,366,183,351,178,351,169,344,162,320,168,305,151,296,143,299,123,309,97,317,91,325,60,337,58,344,50,346,65,359,73," nohref 
		  onMouseOver="change_image('champagne_ardenne')" 
		  onMouseOut="hide_image()" alt="Champagne Ardenne"
onClick="change_value_hidden('21');document.forms['recherche'].submit();"> 

<area shape="poly" coords="322,59,322,45,306,39,304,34,292,28,292,21,281,18,268,14,265,2,235,10,233,39,250,47,263,46,280,56,306,57," 
nohref
		  onMouseOver="change_image('npdc')" 
		  onMouseOut="hide_image()" alt="Nord Pas-de-Calais"
		onClick="change_value_hidden('31');document.forms['recherche'].submit();"
> 

<area shape="poly" coords="233,42,225,56,238,65,238,101,257,102,269,108,286,103,298,118,305,105,306,95,314,93,317,76,323,59,299,55,281,56,266,51,245,41," 
nohref 
		  onMouseOver="change_image('picardie')" 
		  onMouseOut="hide_image()" alt="Picardie"
onClick="change_value_hidden('22');document.forms['recherche'].submit();"> 

<area shape="poly" coords="227,54,237,67,239,97,222,123,206,125,191,114,187,87,179,84,188,70,217,62," 
nohref
		  onMouseOver="change_image('haute_normandie')" 
		  onMouseOut="hide_image()" alt="Haute Normandie"
		onClick="change_value_hidden('23')document.forms['recherche'].submit();;"> 

<area shape="poly" coords="229,112,236,129,248,148,262,148,269,159,284,154,285,144,297,141,298,125,298,117,289,107,262,105,238,100,232,104," 
nohref 
		  onMouseOver="change_image('ile_de_france')" 
		  onMouseOut="hide_image()" alt="Basse Normandie"
		onClick="change_value_hidden('11');document.forms['recherche'].submit();"> 

<area shape="poly" coords="188,87,191,115,204,123,211,142,202,152,191,145,191,135,174,141,168,133,152,137,133,136,120,128,129,125,121,117,121,95,114,83,114,70,136,72,139,88,169,94," 
nohref
		  onMouseOver="change_image('basse_normandie')" 
		  onMouseOut="hide_image()" alt="Basse Normandie"
		onClick="change_value_hidden('25');document.forms['recherche'].submit();"> 

<area shape="poly" coords="141,136,137,151,139,160,127,172,112,176,85,187,60,174,29,162,19,163,9,151,11,126,36,116,65,108,82,128,120,127,127,136,134,132," 
nohref 
		  onMouseOver="change_image('bretagne')" 
		  onMouseOut="hide_image()" alt="Bretagne"
		onClick="change_value_hidden('53');document.forms['recherche'].submit();"> 

<area shape="poly" coords="138,135,138,160,131,174,123,170,99,179,82,192,103,206,97,217,116,246,132,251,154,245,142,214,177,208,183,183,194,183,205,167,204,151,194,147,188,139,174,141,166,134,153,137," 
nohref
		  onMouseOver="change_image('pays_de_la_loire')" 
		  onMouseOut="hide_image()" alt="Pays de la Loire"
		onClick="change_value_hidden('52');document.forms['recherche'].submit();"> 

<area shape="poly" coords="230,116,234,130,245,148,281,154,286,163,276,176,280,195,283,226,257,245,214,249,200,217,188,217,176,206,182,183,194,184,205,166,203,151,211,137,201,127,216,122," nohref 
		  onMouseOver="change_image('centre')" 
		  onMouseOut="hide_image()" alt="Centre"
		onClick="change_value_hidden('24');document.forms['recherche'].submit();"> 


<area shape="poly" coords="295,143,316,165,345,159,368,181,371,215,371,245,354,239,350,259,335,253,328,261,312,257,320,245,308,231,285,230,277,196,281,174,284,164,279,155,284,146," 
nohref
		  onMouseOver="change_image('bourgogne')" 
		  onMouseOut="hide_image()" alt="Bourgogne"
		onClick="change_value_hidden('26');document.forms['recherche'].submit();"> 

<area shape="poly" coords="394,242,411,221,430,184,423,175,410,164,387,163,368,179,373,200,361,219,368,242,374,252,387,251," 
nohref
		  onMouseOver="change_image('franche_comte')" 
		  onMouseOut="hide_image()" alt="Franche Comte"
		onClick="change_value_hidden('43');document.forms['recherche'].submit();"> 

<area shape="poly" coords="176,207,196,215,217,246,201,255,204,271,181,301,169,315,145,306,124,279,133,266,126,259,133,249,150,249,150,229,140,215,163,211," 
nohref
		  onMouseOver="change_image('poitou_charentes')" 
		  onMouseOut="hide_image()" alt="Poitou Charentes"
		onClick="change_value_hidden('54');document.forms['recherche'].submit();"> 

<area shape="poly" coords="217,249,238,246,256,248,267,256,270,270,260,277,264,302,247,323,224,321,215,309,220,300,209,290,197,285,208,272,203,261,206,250," nohref
		  onMouseOver="change_image('limousin')" 
		  onMouseOut="hide_image()" alt="Limousin"
		onClick="change_value_hidden('74');document.forms['recherche'].submit();"> 

<area shape="poly" coords="265,235,282,227,307,229,320,245,314,257,307,280,318,301,333,302,338,309,315,335,298,325,284,338,274,327,265,340,253,344,248,322,264,303,261,279,270,271,264,256,258,247," nohref
		  onMouseOver="change_image('auvergne')" 
		  onMouseOut="hide_image()" alt="Auvergne"
		onClick="change_value_hidden('83');document.forms['recherche'].submit();">

<area shape="poly" coords="315,257,351,258,356,243,368,243,385,253,402,247,422,243,431,267,423,277,440,295,435,304,407,314,405,326,379,348,384,360,378,365,357,359,336,358,321,351,315,335,332,321,337,308,330,303,318,301,319,291,309,281," nohref
		  onMouseOver="change_image('rhone_alpes')" 
		  onMouseOut="hide_image()" alt="Rhone Alpes"
		onClick="change_value_hidden('82');document.forms['recherche'].submit();">

<area shape="poly" coords="421,313,437,328,433,347,435,358,450,363,460,358,464,364,456,385,436,401,415,417,395,420,375,413,352,408,335,403,347,386,352,372,345,360,367,360,378,368,388,358,379,353,386,340,408,325,408,315," nohref
		  onMouseOver="change_image('paca')" 
		  onMouseOut="hide_image()" alt="Provence Alpes Côte d'Azur"
		onClick="change_value_hidden('93');document.forms['recherche'].submit();">

<area shape="poly" coords="316,337,323,357,345,358,352,374,332,403,325,398,301,413,288,427,288,456,269,464,246,464,239,453,251,444,242,440,243,425,234,414,244,405,267,405,270,393,283,393,299,376,299,366,289,361,284,341,287,327,302,326," nohref
		  onMouseOver="change_image('languedoc_roussillon')" 
		  onMouseOut="hide_image()" alt="Languedoc Roussillon"
		onClick="change_value_hidden('91');document.forms['recherche'].submit();">

<area shape="poly" coords="275,327,289,355,299,371,290,386,273,396,266,405,243,407,235,414,245,425,247,441,235,451,196,434,194,444,157,439,168,411,169,399,160,395,161,377,199,373,210,352,220,333,226,323,250,325,255,344,265,338," nohref
		  onMouseOver="change_image('midi_pyrenees')" 
		  onMouseOut="hide_image()" alt="Midi Pyrenees"
		onClick="change_value_hidden('73');document.forms['recherche'].submit();">

<area shape="poly" coords="225,321,221,330,209,349,201,368,189,373,162,378,157,393,163,400,169,413,153,431,142,437,133,426,100,409,119,381,130,292,150,309,159,314,171,316,185,301,193,287,210,292,218,304,217,315," nohref
		  onMouseOver="change_image('aquitaine')" 
		  onMouseOut="hide_image()" alt="Aquitaine"
		onClick="change_value_hidden('72');document.forms['recherche'].submit();">

<area shape="poly" 
coords="17,490,39,494,54,512,54,531,35,536,8,527,3,507,5,497," 
nohref
		  onMouseOver="change_image('la_reunion')" 
		  onMouseOut="hide_image()" alt="La Réunion"
		onClick="change_value_hidden('04');document.forms['recherche'].submit();">

<area shape="poly" 
coords="106,478,138,494,149,503,142,519,126,543,103,547,93,540,104,515,92,504,97,492," 
nohref
		  onMouseOver="change_image('guyane')" 
		  onMouseOut="hide_image()" alt="Guyane"
		onClick="change_value_hidden('03');document.forms['recherche'].submit();">

<area shape="poly" 
coords="195,491,209,492,227,510,236,532,231,547,220,539,203,536,199,517,192,493," 
nohref
		  onMouseOver="change_image('martinique')" 
		  onMouseOut="hide_image()" alt="Martinique"
		onClick="change_value_hidden('02');document.forms['recherche'].submit();">

<area shape="poly" coords="281,502,294,507,304,501,300,493,308,485,314,500,333,508,307,516,297,518,299,533,287,539,281,530,274,511,280,499,323,532,316,540,323,548,330,537," 
nohref
		  onMouseOver="change_image('guadeloupe')" 
		  onMouseOut="hide_image()" alt="Guadeloupe"
			onClick="change_value_hidden('01');document.forms['recherche'].submit();">

<area shape="poly" coords="466,399,472,402,480,441,466,487,447,471,439,434,444,423,458,415,467,413," 
nohref
		  onMouseOver="change_image('corse')" 
		  onMouseOut="hide_image()" alt="Corse"
		onClick="change_value_hidden('94');document.forms['recherche'].submit();">

</map>
	  
	<script>
  preload_image('images/images_accueil/france.png');
  preload_image('images/images_accueil/france_alsace.png');
  preload_image('images/images_accueil/france_aquitaine.png');
  preload_image('images/images_accueil/france_auvergne.png');
  preload_image('images/images_accueil/france_basse_normandie.png');
  preload_image('images/images_accueil/france_bourgogne.png');
  preload_image('images/images_accueil/france_bretagne.png');
  preload_image('images/images_accueil/france_centre.png');
  preload_image('images/images_accueil/france_champagne_ardenne.png');
  preload_image('images/images_accueil/france_corse.png');
  preload_image('images/images_accueil/france_franche_comte.png');
  preload_image('images/images_accueil/france_guadeloupe.png');
  preload_image('images/images_accueil/france_guyane.png');
  preload_image('images/images_accueil/france_haute_normandie.png');
  preload_image('images/images_accueil/france_ile_de_france.png');
  preload_image('images/images_accueil/france_languedoc_roussillon.png');
  preload_image('images/images_accueil/france_la_reunion.png');
  preload_image('images/images_accueil/france_limousin.png');
  preload_image('images/images_accueil/france_lorraine.png');
  preload_image('images/images_accueil/france_martinique.png');
  preload_image('images/images_accueil/france_midi_pyrenees.png');
  preload_image('images/images_accueil/france_npdc.png');
  preload_image('images/images_accueil/france_paca.png');
  preload_image('images/images_accueil/france_pays_de_la_loire.png');
  preload_image('images/images_accueil/france_picardie.png');
  preload_image('images/images_accueil/france_poitou_charentes.png');
  preload_image('images/images_accueil/france_rhone_alpes.png');
  </script>

<hr>

<?php
   include 'footer.php';
?>


