#include<iostream>

using namespace std;

typedef long long ent;

int const N=1000000000;

ent reverse(ent n){
  ent res=0;
  while(n!=0){
    res=10*res+n%10;
    n/=10;
  }
  return res;
}

bool reversible(ent n){
  if(n%10==0) return false;
  ent nn=n+reverse(n);
  while(nn!=0){
    if(nn%2==0) return false;
    nn/=10;
  }
  return true;
}

int main(){
  int res=0;
  for(int i=0;i<=N;++i)
      if(reversible(i)) res++;
  cout << res << '\n';
}
