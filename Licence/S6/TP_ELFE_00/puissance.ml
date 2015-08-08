let rec puissance entier n = 
  if n = 1 then entier
  else entier * puissance entier (n-1);;

let _ = Printf.printf "%d\n" (puissance 2 3);;
