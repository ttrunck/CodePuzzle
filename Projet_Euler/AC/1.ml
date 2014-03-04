let count n=
let res=ref 0 in
for i=1 to n do
  if (i mod 3)=0 || (i mod 5)=0 then
    res:= !res + i;
done;
!res;;

count 999;;
