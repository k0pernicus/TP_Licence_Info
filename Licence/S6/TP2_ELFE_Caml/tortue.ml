#load "graphics.cma";;
open Graphics;;
open Stack;;
#use "lsysteme.ml";;

(*
  Etat caractéristique de la "tortue graphique"
  x -> position courante de l'axe des abcisses
  y -> position courange de l'axe des ordonnées
  cap -> angle par rapport à l'axe des abcisses, exprimé en radians
*)
type etat = {
  x : float;
  y : float;
  cap : float;
};;

(*
  Permet de déclarer un type pour les paramètres graphiques
*)
type param_graphiques = {
  pas : float;
  facteur : float;
  angle : float;
  etat : etat;
};;

(*
  Déclaration de pi
*)
let pi = 4. *. atan(1.);;

(*
  Déclaration de avance -> calcule le nouvel état de la tortue après avoir avancé d’une distance d passée en paramètre, avec tracé
  e -> état
  d -> distance (float) avec laquelle on veut avancer
*)
let avance = fun e d ->
  moveto (int_of_float e.x) (int_of_float e.y);
  let tx = e.x +. d *.cos(e.cap)
  and ty = e.y +. d *.sin(e.cap) in
  lineto (int_of_float tx) (int_of_float ty);
  {x = tx; y = ty; cap = e.cap};;

(*
  Déclaration de vole -> calcule le nouvel état de la tortue après s'être déplacée d'une distante d passée en paramètre, sans tracé
  e -> état
  d -> distance (float) avec laquelle on veut avancer
*)
let vole = fun e d -> 
  {x = e.x +. d *.cos(e.cap); y = e.y +. d *.sin(e.cap); cap = e.cap};;

(*
  Déclaration de tourne_gauche -> calcule le nouvel état de la torture après avoir modifié son cap d'une valeur a passée en paramètre, sans tracé
  e -> état
  a -> angle
*)
let tourne_gauche = fun e a ->
  {x = e.x; y = e.y; cap = e.cap +. a};;

(*
  Déclaration de tourne_droite -> calcule le nouvel état de la torture après avoir modifié son cap d'une valeur a passée en paramètre, sans tracé
  e -> état
  a -> angle
*)
let tourne_droite = fun e a ->
  {x = e.x; y = e.y; cap = e.cap -. a};;


(* Partie 4 : EXTENSIONS  *)
  
let memoire = create ()

(*
  Fonction qui permete la mémorisatioh d'un état en le placant au sommet de la pile d'état.
*)
let memorise = fun e ->
  push e memoire;
  {x = e.x; y = e.y; cap = e.cap}

(*
  Fonction qui permet de rappeler le dernier état mémomrisé en dépilant le sommet de la pile d'états.
*)
let rappelle () = pop memoire


(*
  Déclaration de interprete_symbole -> calcule le nouvel état de la tortue selon le symbole s donné en paramètre
*)
let interprete_symbole = fun d a e s ->
  match s with
  |A -> avance e d
  |G -> tourne_gauche e a
  |D -> tourne_droite e a
  |M -> memorise e (* ajout de la partie 4 *)
  |R -> rappelle ()
  |_ -> e;;

(*
  Déclaration de interprete_mot -> calcule le nouvel état de la tortue selon le mot m donné en paramètre
  ATTENTION!! Utilisation de ignore() afin d'ignorer le résultat d'interpréter de symbole, et passer le type en unit()
*)
let rec interprete_mot = fun d a e m ->
  match m with
  |[] -> ();
  |h::t -> interprete_mot d a (interprete_symbole d a e h) t
;;      

(*
  EXERCICE 10
  C'est une liste de couples: un l_systeme ainsi qu'un param_graphiques.
  Le type est donc un (l_systeme * param_graphiques) list.
*)

let liste_parametres = [ 
  (vonKoch1,{pas=540.;facteur=(1./.3.);angle=(pi/.3.);etat={x=50.;y=50.;cap=0.}});
  (vonKoch2,{pas=360.;facteur=(1./.3.);angle=(pi/.3.);etat={x=100.;y=360.;cap=0.}});
  (vonKoch3,{pas=360.;facteur=(1./.3.);angle=(pi/.3.);etat={x=100.;y=100.;cap=0.}});
  (hilbert,{pas=400.;facteur=(1./.2.);angle=(pi/.2.);etat={x=150.;y=400.;cap=0.}});
  (peano,{pas=400.;facteur=(1./.3.);angle=(pi/.2.);etat={x=100.;y=240.;cap=0.}});
  (ileDeKoch,{pas=300.;facteur=(1./.4.);angle=(pi/.2.);etat={x=150.;y=100.;cap=0.}});
  (brindille,{pas=390.;facteur=(1./.3.);angle=(25.*.pi/.180.);etat={x=320.;y=50.;cap=(pi/.2.)}});
  (broussaille,{pas=280.;facteur=(2./.5.);angle=(25.*.pi/.180.);etat={x=320.;y=50.;cap=(pi/.2.)}});
]

(*
  Fonction permettant de déterminer le pas initial, le facteur de réduction, l’angle et l’état initial d’un L-système, donné en paramètre (a) dans une liste de paramètres en fonction d'un L-système (l). 
*)
let donne_assoc = fun a l ->
  List.assq a l;;

(*
  Fonction permettant de calculer la longueur des segments dans le tracé d'un mot d'ordre n d'un L-Syteme : la longueur est réduite proportionnellement à l'ordre (le facteur étant <1)
*)
let longueur_segment = fun n param ->
  param.pas *. ((param.facteur)**n)

(*
  Fonction qui permet l'affichage dans une fenêtre graphique d'un mot d'ordre n en fonction du LSysteme choisi.
*)
let dessine ls n  =
  open_graph " 640x520";
  let mot = derive_nieme ls  n in
  let param =(donne_assoc ls liste_parametres) in
  interprete_mot (longueur_segment (float_of_int n) param) param.angle param.etat mot
(* l'écriture du code du type "fun ls n ->" serait ici trtès peu lisibile. Nou avons donc opté pour ce code plus facile à interpréter *)

