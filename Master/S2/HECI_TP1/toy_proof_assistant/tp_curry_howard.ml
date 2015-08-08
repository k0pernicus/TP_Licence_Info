(** Dans ce pseudo-TP, on va utiliser un "assistant de preuve"
    rudimentaire basé sur le système de type de Caml.

    Le terme "assistant de preuve" est très mal choisi, car le système
    ne vous assiste pas. Au contraire, il vous embête jusqu'à ce que
    votre "preuve" soit CORRECTE. Dans ce sens-la, il vous assiste à
    faire des preuves correctes.

    Il y a un module qui s'appelle Stdlib, fourni avec son interface,
    qui est, elle, soit-disant lisible par des êtres humains.

    Vous devez compiler le tout avec les commandes :

    ocamlc -c stdlib.mli
    ocamlc -c stdlib.ml

    Vous pouvez enfin charger le système :
**)

#load "stdlib.cmo";;
open Stdlib;;

(** pour commencer en douceur, on va démontrer que le ET est
commutatif : écrivez une fonction de type

('a, 'b) et -> ('b, 'a) et

Vous devez pour ça utiliser les fonctions du module Stdlib.
**)

let demo_et a_et_b =
  and_intro (and_elim_r a_et_b) (and_elim_l a_et_b);;

(** même topo avec l'associativité : écrivez une fonction de type

('a, ('b, 'c) et) et -> (('a, 'b) et, 'c) et

**)

let demo_asso a_et_b =
  and_intro (and_intro (and_elim_l a_et_b) (and_elim_l (and_elim_r a_et_b))) (and_elim_r (and_elim_r a_et_b));;

(** Enfin, voici une sélection de petites choses "faciles" :

('a, 'b) et -> 'a
('a, 'a -> 'b) et -> 'b
('a, ('a, 'b) et) ou -> 'a
('a, 'a) ou -> 'a
('a, 'b) ou -> ('b, 'a) ou
'a -> 'a neg neg

**)

let demo_facile_1 a_et_b =
  and_elim_l a_et_b;;

let demo_facile_2 a_et_b =
  (and_elim_r a_et_b) (and_elim_l a_et_b);;

let demo_facile_3 a_ou_b =
  or_elim (fun x -> x) demo_facile_1 a_ou_b;;

let demo_facile_4 a_ou_b =
  or_elim (fun x -> x) (fun x -> x) a_ou_b;;

let demo_facile_5 a_ou_b =
  or_elim (fun x -> or_intro_r x) (fun x -> or_intro_l x) a_ou_b;;

let demo_facile_6 a =
  neg_intro (neg_elim a);;

(** maintenant les choses dures. Il y a deux sources de difficulté, le
"OU" qui oblige à des raisonnements par cas, et la négation qui oblige
à faire des "raisonnements par l'absurde".

('a, ('b, 'c) ou) ou -> (('a, 'b) ou, 'c) ou
('a, ('b, 'c) ou) et -> (('a, 'b) et, ('a, 'c) et) ou
(('a, 'b) et, ('a, 'c) et) ou -> ('a, ('b, 'c) ou) et
('a, ('b, 'c) et) ou -> (('a, 'b) ou, ('a, 'c) ou) et
(('a, 'b) ou, ('a, 'c) ou) et -> ('a, ('b, 'c) et) ou
('a, 'b) et -> ('a neg, 'b neg) ou neg
('a, 'b) ou -> ('a neg, 'b neg) et neg
('a, 'b) ou -> ('a neg, 'b neg) et neg
('a neg, 'b neg) et -> ('a, 'b) ou neg
('a, 'b) ou neg -> ('a neg, 'b neg) et
('a, 'b) ou -> 'a neg -> 'b
('a neg, 'b) ou -> 'a -> 'b

*)

let demo_diff_7 ab =
  neg_intro (or_elim (neg_elim (and_elim_l ab)) (neg_elim (and_elim_r ab)));;

(** Et pour finir les "horribles" : ceux où l'emploi de la fonction
    negneg_elim est indispensable (personne ne sait trop ce qui peut
    se passer si on l'exécute...

('a neg -> bot) -> 'a
unit -> ('a, 'a neg) ou
(('a -> 'b) -> 'a) -> 'a

*)
