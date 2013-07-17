let decompose x=
  let curr= ref x and i=ref 2 in
  while !curr<>1 do
    if (!curr mod !i) =0 then begin
      curr:= !curr/ !i;
      print_int !i;
      print_newline();
    end
    else
      incr i;
  done;;
    

decompose 8;;
