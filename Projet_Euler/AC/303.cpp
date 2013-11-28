#include<iostream>

using namespace std;

typedef long long ll;

void inc(ll& n){
  n+=1;
  ll mod=10;
  while((n%mod)/(mod/10)>2){
    n-=3*mod/10;
    n+=mod;
    mod*=10;
  }
}

int main(){
  ll res=1111333355557778;
  for(int i=1;i<=10000;++i){
    if(i==9999) continue;
    ll n=1;
    while(n%i!=0) inc(n);
    cerr << i << ' ' << n << endl;
    res+=n/i;
  }
  cout << res << endl;
}
