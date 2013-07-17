#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class ent;

ent const N=1000000;

ent fact(ent n){
  if(n<=0) return 1;
  else return n*fact(n-1);
}

bool over(ent n, ent r){
  return fact(n)/(fact(r)*fact(n-r)) >N;
}

int main(){
  int res=0;
  for(int n=0;n<=100;++n)
    for(int r=0;r<=n;++r)
      if(over(n,r)) res++;

  cout << res << '\n';
}
