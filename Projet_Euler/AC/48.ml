open Big_int;;

let n=big_int_of_string "10000000000"
and res= ref zero_big_int in
for i=1 to 1000 do
  let tmp= big_int_of_int i in
  let tmp= power_big_int_positive_int tmp i in
  res:= add_big_int !res tmp;
  res:= mod_big_int !res n;
done;
print_string (string_of_big_int !res);;
