#include<iostream>
#include<gmpxx.h>


using namespace std;

typedef mpz_class ent;

int const N=100;

ent power(ent a,ent b){
  ent res=1;
  for(ent i=0;i<b;++i)
    res*=a;
  return res;
}

ent sum(ent n){
  ent res=0;
  while(n!=0){
    res+=n%10;
    n/=10;
  }
  return res;
}

int main(){
  ent res=0;
  for(int a=1;a<N;++a)
    for(int b=1;b<N;++b)
      res=max(sum(power(a,b)),res);
  
  cout << res << '\n';
}
