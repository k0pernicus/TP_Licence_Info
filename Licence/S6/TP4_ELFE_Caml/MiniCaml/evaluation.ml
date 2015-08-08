(**
   Evaluateur de phrases pour mini CAML
   Evaluation par valeurs. Liaison dynamique.

   Necessite les modules [Lexical] et [Syntaxe].

   Compilation
   - [ocamlc -c lexical.cmo syntaxe.cmo evaluation.ml{i}]

   @authors TEAM-TAMC
*)

(* directive pour ne pas prefixer toutes les fonctions du module 
   Syntaxe
*)
open Syntaxe

type valeur = 
    Valeur of Syntaxe.expression 
  | Liaison of (string * valeur) 
  | Aucune
and environnement = (string * valeur) list

exception Variable_non_liee of string
exception Condition_incorrecte
exception Application_impossible
exception Typage_incorrect

let subs = fun (x: string) e1 e2 ->
 match Valeur (e1) with 
 |Liaison (x, v) -> 
   let l =(Liaison (x, Valeur (e2))) in
   match l with
   |Valeur (y) -> y
 |_ ->failwith("Ici")
  ;;



let rec eval_expr = fun (env: environnement) -> function
 | Expr_int n -> Valeur (Expr_int n)
  | Expr_bool b -> Valeur (Expr_bool b)
  | Expr_var v -> 
    begin
      try
	List.assoc v env;
      with 
	|Not_found -> raise (Variable_non_liee v);
    end
  | Expr_fonc (f,v) -> Valeur(Expr_fonc (f,v))
  | Expr_unaire (op,v) -> 
    begin
      match op,(eval_expr env v) with
	|Moins, Valeur (Expr_int n) -> Valeur (Expr_int (-n))
	|Not, Valeur (Expr_bool n) -> Valeur(Expr_bool(not n))
	|_ -> raise (Typage_incorrect)
    end
  | Expr_binaire (op, e1, e2) ->
    begin
      match op,(eval_expr env e2),(eval_expr env e1) with
	|Add,Valeur(Expr_int eval2),Valeur(Expr_int eval1) -> Valeur (Expr_int (eval1 + eval2))
	|Sub,Valeur(Expr_int eval2),Valeur(Expr_int eval1) -> Valeur (Expr_int (eval1 - eval2))
	|Mult,Valeur(Expr_int eval2),Valeur(Expr_int eval1) -> Valeur (Expr_int (eval1 * eval2))
	|Div,Valeur(Expr_int eval2),Valeur(Expr_int eval1) -> Valeur (Expr_int (eval1 / eval2))
	|And,Valeur(Expr_bool eval2),Valeur(Expr_bool eval1) -> Valeur (Expr_bool(eval1 && eval2))
	|Or,Valeur(Expr_bool eval2),Valeur(Expr_bool eval1) -> Valeur (Expr_bool(eval1 || eval1))
	|Eq,Valeur(Expr_int eval2), Valeur(Expr_int eval1) -> Valeur (Expr_bool(eval1 = eval2))
	|Eq,Valeur(Expr_bool eval2), Valeur(Expr_bool eval1) -> Valeur (Expr_bool(eval1 = eval2))
	|Inf,Valeur(Expr_int eval2),Valeur(Expr_int eval1) -> Valeur (Expr_bool(eval1 <= eval2))
	|Inf,Valeur(Expr_bool eval2),Valeur(Expr_bool eval1) -> Valeur (Expr_bool(eval1 <= eval2))
	|_ -> raise (Typage_incorrect)
    end
 
  | Expr_cond (e1, e2, e3) ->
    begin
      match (eval_expr env e1) with
      |Valeur (Expr_bool true) -> eval_expr env e2
      |Valeur (Expr_bool false) -> eval_expr env e3
      |_ -> raise (Condition_incorrecte)
    end
  |Expr_appl (e1, e2) ->
    begin
     (*let v2 = (eval_expr env e2) in*)
      let v1 = (eval_expr env e1) in
      match v1 with 
      |Valeur (Expr_fonc(f, e)) ->  eval_expr env (subs f e1 e2)
      |_ -> raise Application_impossible	
    end
 
 
let eval = fun (env: environnement) p ->
  match p with
    | Decl (Decla (x,e)) -> 
      let v = eval_expr env e in
	((x, v)::env, Liaison (x, v))
    | Expr e -> (env, eval_expr env e)
    | Vide -> (env, Aucune)

let signe = fun n ->
if n=0 then 0
else if n<0 then -1 else 1

