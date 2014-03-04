#include <iostream>
#include <gmpxx.h>

using namespace std;

typedef mpz_class ent;

ent const N=10000000000;

ent powermod(ent a, ent b, ent n){
  if(b==0) return 1;
  ent tmp=powermod(a,b/2,n);
  if(b%2==0) return (tmp*tmp)%n;
  return (a*tmp*tmp)%n;
}

int main(){
  cout << ((28433*powermod(2,7830457,N)+1))%N << '\n';

}
