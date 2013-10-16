#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

const int P=100000;

ll powMod(ll x, ll n, ll m) {
  ll y = 1;
  while (n != 0) {
    if ((n & 1) == 1)
      y = (y * x) % m;
    x = (x * x) % m;
    n = n >> 1;
  }
  return y;
}

int main(){

  vector<bool> prime(P, true);
  prime[0]=prime[1]=false;
  for(int i=2;i<P;++i)
    if(prime[i])
      for(int j=i+i;j<P;j+=i)
	prime[j]=false;

  ll res=2+3+5;
  for(int p=7;p<P;++p){
    if(!prime[p]) continue;
    ll mod=10;
    set<int> s;
    while(s.find(mod)==end(s)){
      s.insert(mod);
      mod=powMod(mod, 10, p);
      if(mod==1){
	cerr << p << endl;
	res-=p;
	break;
      }
    }
    res+=p;
  }
  cout << res << endl;
}
