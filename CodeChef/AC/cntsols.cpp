#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

ll exp(ll x, ll n, ll m){
  ll y = 1;
  while(n != 0){
    if ((n & 1) == 1)
      y = (y * x) % m;
    x = (x * x) % m;
    n = n >> 1;
  }
  return y%m;
}

int main(){

  int T;
  cin >> T;
  ll upper, d, m, N;
  while(cin >> upper >> d >> m >> N){

    vector<ll> touch(N,0);
    
    for(int i=0;i<=min(N-1,upper);++i)
      touch[exp(i,d,N)]+=1+(upper-i)/N;

    ll res=0;
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j)
	for(int k=0;k<N;++k)
	  if((((i+j+k-m)%N+N)%N)==0)
	    res = (res + ((((touch[i]*touch[j])%MOD)*touch[k])%MOD))%MOD;

    cout << res << '\n';

  }
}
