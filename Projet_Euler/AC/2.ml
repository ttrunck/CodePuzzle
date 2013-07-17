let fibo_next=function
|a::b::l -> a+b::a::b::l
|_-> failwith "Liste vide";;

let rec iter cond f elt=
  if cond elt then
    iter cond f (f elt)
  else elt;;

let l=iter (fun x-> (List.hd x)<4000000) fibo_next [2;1];;

let rec even_sum =function
  |x::l-> if (x mod 2)=0 then x+(even_sum l) else even_sum l
  |[]-> 0;; 

even_sum l;;
