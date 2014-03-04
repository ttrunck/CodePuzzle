let rec gcd a b=
  if a=0 then b
  else if b=0 then a
  else gcd b (a mod b);; 

let ppcm a b=
  (a*b)/ (gcd a b);;

let res= ref 1 in
for i = 1 to 20 do
  res:= ppcm !res i;
done;
!res;;
