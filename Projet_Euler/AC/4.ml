let rec is_palindrome s pos=
  let l=String.length s in
  if pos>l-pos-1 then true
  else s.[pos]=s.[l-pos-1] && is_palindrome s (pos+1);;
 
let res= ref 0 in
for i=999 downto 0 do
  for j=999 downto 0 do
    let s=string_of_int (i*j) in
    if is_palindrome s 0 then res:= max !res (i*j);
  done;done;
!res;;
