#include <iostream>
#include <cmath>

using namespace std;

typedef long long ent;

ent const N=10000000;

ent fact(ent n){
  ent res=1;
  for(ent i=2;i<=n;++i)
    res*=i;
  return res;
}

ent add_fact(ent n){
  ent res=0;
  while(n!=0){
    res+=fact(n%10);
    n/=10;
  }
  return res;
}

int main(){
  ent res=0;
  for(ent i=10;i<N;++i)
    if(add_fact(i)==i){
      cout << i << '\n';
      res+=i;
    }
  cout << res << '\n';
}
