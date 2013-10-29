#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef unsigned long long ll;

const int N=64000000;

bool isSqrt(ll n){
  ll tmp=sqrt(n);
  return tmp*tmp==n;
}

int main(){
  vector<ll> t(N,0);
  for(ll i=1;i<N;++i)
    for(ll j=i;j<N;j+=i)
      t[j]+=i*i;
  
  ll res=0;
  for(ll i=1;i<N;++i)
    if(isSqrt(t[i])){
      cerr << i << '\n';
      res+=i;
    }
  cout << res << endl;
}
