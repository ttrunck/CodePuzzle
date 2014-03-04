#include <iostream>
#include <cmath>
#include <gmpxx.h>

using namespace std;

typedef mpz_class ent;

ent const A=15499, B=94744;

bool ok(ent n, ent eul){
  return(B*eul<A*(n-1));
}

int main(){
  ent p=1;
  ent n=p;
  ent eul=1;
  for(int i=0;i<9;++i){
    mpz_nextprime(p.get_mpz_t(),p.get_mpz_t());
    n*=p;
    eul*=(p-1);
    cout << p << ' ' << n << ' ' << eul << ' ' << ok(n,eul) << '\n';
  }
  p=4;
  n*=p;
  eul*=p;
  cout << p << ' ' << n << ' ' << eul << ' ' << ok(n,eul) << '\n';

}
