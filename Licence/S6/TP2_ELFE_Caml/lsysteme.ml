(* Définition du type symbole *)
type symbole =
|A
|G
|D
|X
|Y
|M
|R;;

(* Définition du type mot *)
type mot = symbole list;;

(* Définition du type lsysteme *)
type l_systeme = {
  axiome: mot;
  regles: symbole -> mot
}

(* Expression des différents lsystemes *)
let vonKoch1 = { 
  axiome = [A]; 
  regles = function 
  | A -> [A;G;A;D;D;A;G;A] 
  | x -> [x] 
} 

let vonKoch2 = { 
  axiome = [A;D;D;A;D;D;A;D;D]; regles = function 
  | A -> [A;G;A;D;D;A;G;A] 
  | x -> [x] 
} 

let vonKoch3 = { 
  axiome = [A;G;G;A;G;G;A;G;G]; 
  regles = function 
  | A -> [A;G;A;D;D;A;G;A] 
  | x -> [x] 
}

let hilbert = { 
  axiome = [X]; 
  regles = function 
  | X -> [D;Y;A;G;X;A;X;G;A;Y;D] 
  | Y -> [G;X;A;D;Y;A;Y;D;A;X;G] 
  | x -> [x] 
}

let peano = { 
  axiome = [A]
  ; regles = function 
  | A -> [A;A;G;A;G;A;G;A;A;G;A;G;A;D;A] 
  | x -> [x] 
}

let ileDeKoch = {
  axiome = [A;G;A;G;A;G;A]
  ; regles = function
  | A -> [A;G;A;D;A;D;A;A;G;A;G;A;D;A]
  | x -> [x]
}

let brindille = {
  axiome = [A];
  regles = function
    | A -> [A;M;G;A;R;A;M;D;A;R;A]
    | x -> [x]
}

let broussaille = {
  axiome = [A];
  regles = function
    | A -> [A;A;G;M;G;A;D;A;D;A;R;D;M;D;A;G;A;G;A;R]
    | x -> [x]
}
(*
  Exercice 2 - 3
  Question 1
*)

let calcule_mot = fun lsys symb ->
  lsys.regles symb;;

(*
  Exercice 2 - 3
  Question 2
*)

let rec transforme_mot = 
  fun lsys m->
    match m with
    |[] -> []
    |h::t -> (calcule_mot lsys h) @ (transforme_mot lsys t);;

(*
  Exercice 2 - 4
  Question 3
*)
let rec itere f n e =
  if n <> 0 then itere f (n-1) (f e)
  else e;;

let derive_nieme =
  fun lsys n ->
    itere (transforme_mot lsys) n lsys.axiome;;

(*
  # List.length (derive_nieme vonKoch1 0);;
  - : int = 1
  # List.length (derive_nieme vonKoch1 1);;
  - : int = 8
  # List.length (derive_nieme vonKoch1 2);;
  - : int = 36
  # List.length (derive_nieme vonKoch1 3);;
  - : int = 148
*)
