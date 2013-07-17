#include<iostream>
#include<gmpxx.h>

typedef mpz_class ent;

using namespace std;

ent power(ent a, int b){
  if(b==0) return 1;
  if(b==1) return a;
  ent tmp=power(a,b/2);
  return tmp*tmp*(b%2==0?1:a);
}

int nb_digit(ent a){
  int res=0;
  while(a!=0){
    a/=10;
    res++;
  }
  return res;
}

int main(){
  int res=0;
  for(ent i=1;i<10;++i)
    for(int k=0;k<100;++k)
      if(nb_digit(power(i,k))==k) res++;
  cout << res << '\n';
}
