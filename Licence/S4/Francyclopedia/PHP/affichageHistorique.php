<?php
function affichageHistorique() {
if (isset($_SESSION['communes']['nom'])) {
  echo '<option value="None">--</option>';
  foreach (array_unique($_SESSION['communes']['nom']) as $tableau) {
    echo "<option value=\"".$tableau."\">$tableau</option>";
  }
}
else {
   echo '<option value="None">--</option>';
}
}
?>