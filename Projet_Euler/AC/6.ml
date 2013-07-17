let res= ref 0 in
for i=1 to 100 do
res:= !res+i;
done;
res:= !res* !res;
for i=1 to 100 do
res:= !res - i*i;
done;
!res;;
