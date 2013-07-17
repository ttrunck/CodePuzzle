#include <iostream>
#include <cmath>
#include <gmpxx.h>

using namespace std;

typedef int ent;

int const N=10000;

ent d(ent n){
  ent res=0;
  for(ent i=1;i<n;++i)
    if(n%i==0) res+=i;
  return res;
}

bool amis(ent a){
  return (d(a)!=a && d(d(a))==a);
}

int main(){
  ent res=0;
  for(int i=0;i<N;++i)
    if(amis(i)) res+=i;

  cout << res << '\n';
}
