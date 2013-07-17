#include <iostream>

using namespace std;

typedef long long ent;

ent res=0;
ent const N=10000000;

ent next(ent i){
  ent res=0;
  while(i!=0){
    res+= (i%10)*(i%10);
    i=i/10;
  }
  return res;
}

int is_89(ent n){
  if(n==1) return 0;
  if(n==89) return 1;
  return is_89(next(n));
}

int main(){
  for(ent i=1;i<=N;++i)
    res+=is_89(i);
  cout << res << '\n';
}
