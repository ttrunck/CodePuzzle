#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const ll N=100000000;
const ll MOD=1000000009;

ll powMod(ll x, ll n){
  ll y = 1;
  while (n != 0) {
    if ((n & 1) == 1)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n = n >> 1;
  }
  return y;
}

ll count(ll p, ll n){
  ll res=0;
  ll pp=p;
  while(n/pp){
    res+=n/pp;
    pp*=p;
  }
  return res;
}

int main(){
  vector<bool> prime(N+1,true);
  prime[0]=prime[1]=false;
  for(int i=2;i<=N;++i)
    if(prime[i])
      for(int j=i+i;j<=N;j+=i)
	prime[j]=false;

  ll res=1;

  for(int i=2;i<=N;++i)
    if(prime[i]){
      ll tmp=count(i,N);
      res= res*(1+powMod(i,tmp*2))%MOD;
    }

  cout << res << '\n';
}
