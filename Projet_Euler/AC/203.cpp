#include<iostream>
#include<set>
#include<vector>

using namespace std;

const int N=50;

typedef long long ll;

vector<bool> prime(10000,true);

ll binomial(ll k, ll n) {
  ll res = 1;
  for (ll i = 1; i <= k; ++i)
    res = (n - k + i) * res / i;
  return res;
}

bool sqfree(ll n){
  for(ll i=0;i<ll(prime.size());++i)
    if(prime[i]){
      if(i*i>n) break;
      if(n%(i*i)==0)
	return false;
    }

    return true;
}

int main(){
  prime[0]=prime[1]=false;
  for(ll i=2;i<ll(prime.size());++i)
    if(prime[i])
      for(ll j=i+i;j<ll(prime.size());j+=i)
	prime[j]=false;

  set<ll> s;
  for(ll i=0;i<N;++i)
    for(ll j=0;j<=i/2;++j)
      s.insert(binomial(j,i));

  ll res=0;
  for(ll x:s)
    if(sqfree(x))
      res+=x;

  cout << res << endl;
}
