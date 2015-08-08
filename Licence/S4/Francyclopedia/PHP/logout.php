<?php

session_start();

$_SESSION = array(); //On écrase le tableau de session

session_destroy(); //On détruit la session

//Redirection vers homepage

header('Location: ../homepage.php');      

?>