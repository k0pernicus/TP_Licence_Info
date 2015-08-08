type booleen = Vrai | Faux;;
type int_etendu = Non_defini | Int of int;;
type liste_entiers = Vide | Cons of (int*liste_entiers);;

let quotient = fun x y -> if (y = 0) then Non_defini else Int (x / y);;

let liste = Cons(1,Cons(2,Cons(3,Cons(1,Vide))));;

let neg = function 
  |Vrai -> Faux
  |Faux -> Vrai;;

let quotient2 = fun p n ->
  match p, n with
  |Int p, Int 0 -> Non_defini
  |Int p, Int n -> Int(p / n)
  |_ -> failwith("Utilisation Non_defini détectée");;

let rec longueur_liste = function
  |Vide -> 0
  |Cons(n, l) -> 1 + (longueur_liste l);;

let rang = fun entier liste ->
  let rec rang2 = fun entier liste ->
    match liste with
    |Vide -> 0
    |Cons(x, _) when x = entier -> 0
    |Cons(x, y) -> 1 + rang2 entier y in
  match liste with
  |Vide -> Non_defini
  |_ -> Int(rang2 entier liste);;
