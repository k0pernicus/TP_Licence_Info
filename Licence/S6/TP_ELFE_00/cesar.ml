let initiale string = 
  String.sub string 0 1;;

let saufInitiale string =
  String.sub string 1 ((String.length string)- 1);;

let decale rang string =
  let character = (String.get string 0) in
  let entier_char = int_of_char(character) in
  if (entier_char >= 65 && entier_char <= 90) then 
    begin
      if (entier_char >=88 && entier_char <= 90) then
	char_of_int(((entier_char + rang) mod 90) + 64)
     else char_of_int(entier_char + rang);
    end
  else
    if (entier_char >= 97 && entier_char <= 122) then
      begin
	if (entier_char >= 120 && entier_char <= 122) then
	  char_of_int(((entier_char + rang) mod 122) + 96)
	else char_of_int(entier_char + rang);
      end
    else character;;

let rec cesar rang string = 
  if (String.length string = 0) then string
  else 
    (String.make 1 (decale rang (initiale string))) ^ (cesar rang (saufInitiale string));;

let main() =
  let n = int_of_string Sys.argv.(1)
  and s = Sys.argv.(2) in
  Printf.printf "%s\n" (cesar n s);
  exit 0;;

let _ = main();;
