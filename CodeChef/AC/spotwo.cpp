#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

ll powMod(ll x, ll n) {
  ll y = 1;
  while (n != 0) {
    if ((n & 1) == 1)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n = n >> 1;
  }
  return y;
}

int main(){
  ios::sync_with_stdio(false);

  vector<ll> pow(25);
  pow[0]=1;
  pow[1]=4;
  for(ll i=2;i<25;++i)
    pow[i]=powMod(pow[i-1],10);

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    ll res=1;
    int curr=1;
    while(n!=0){
      if(n%2==1)
	res=(res*pow[curr])%MOD;
      ++curr;
      n/=2;
    }

    cout << res << '\n';
  }
}
