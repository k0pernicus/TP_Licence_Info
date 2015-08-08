(*
EXERCICE 1
*)

let rec nth = fun l n ->
  match (n,l) with
    |(0,h::t) -> h
    |(n,h::t) -> nth t (n-1)
    |(_,_) -> failwith "Liste trop courte";;

let rec append = fun l1 l2 ->
  match (l1,l2) with
    |(h::t,l2) -> h :: (append t l2)
    |([], l2) -> l2;;

let rec flatten = fun l ->
  match l with
    |h::[] -> h
    |h::t -> append h (flatten t)
    |_ -> failwith "Error";;

let rec map = fun f l->
  match l with
    |[] -> []
    |h::t -> (f h)::(map f t);;

let rec fold_left = fun f n l ->
  match l with
    |[] -> n
    |h::t -> fold_left f (f n h) t;;

(*
EXERCICE 2

# let l = [];;
val l : 'a list = []
# let x = nth l;;
val x : int -> 'a = <fun>
# x 0;;
Exception: Failure "Liste trop courte".
# let l = [1;2;3;4];;
val l : int list = [1; 2; 3; 4]
# let x = nth l;;
val x : int -> int = <fun>
# x 2;;
- : int = 3
*)

(*
EXERCICE 3
*)

let somme = function l -> fold_left (+) 0 l;;

let length = function l -> somme(map(function x -> x / x) l);;

(*
EXERCICE 4
*)

let rec foncList = fun f x n ->
  match n with
    |(-1) -> []
    |_ -> x :: foncList f (f x) (n-1);;

(*
# foncList (function x -> x+1) 0 20;; 
- : int list =
[0; 1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20]
*)

let useFoncList = function n -> foncList (function x -> x + 1) 0 n;;

(*
# useFoncList 20;;
- : int list =
[0; 1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20]
*)
