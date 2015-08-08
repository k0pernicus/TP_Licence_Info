<?php

function changementPositionCarte($X, $Y) { //Ajoutera un marqueur et zoomera sur la position (Y, X)
  echo "<script>var coordsup = new OpenLayers.LonLat($X,$Y);coordsup.transform(projSpherique,projCarte);var markersup = new OpenLayers.Marker(coordsup);calqueMarkers.addMarker(markersup);</script>";
  echo "<script>window.onload=function(){start($X, $Y);}</script>";
}

?>