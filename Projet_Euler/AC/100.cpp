#include<iostream>
#include<cmath>
#include<gmpxx.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef mpz_class ent;

ent const N=1000000000000;
ent const Q=1000000;
vector<ent> t;

bool is_square(ent n){
  ent tmp=sqrt(n);
  return tmp*tmp==n;
}

int main(){
  for(ent q=1;q<Q;++q){
    if(is_square(2*q*q+1)){
      ent p=q+sqrt(2*q*q+1);
      if(p*p-q*q>N)
	t.push_back(p*p-q*q);
    }
    if(is_square(2*q*q-1)){
      ent p=q+sqrt(2*q*q-1);
      if(2*p*q>N)
	t.push_back(2*p*q);
    }
  }

  sort(t.begin(),t.end());
  
  ent tt=t[0];
  ent tmp=1+2*tt*(tt-1);
  cout << (1+(ent)sqrt(tmp))/2 << ' ' << tt << '\n';
}
