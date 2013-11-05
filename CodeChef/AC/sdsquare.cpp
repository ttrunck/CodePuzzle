#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

bool perfect(ll n){
  while(n){
    int l=n%10;
    if(l!=0 && l!=1 && l!= 4 && l!=9)
      return false;
    n/=10;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> t;
  for(ll i=0;i<=100000;++i)
    if(perfect(i*i))
      t.push_back(i*i);

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    ll a,b;
    cin >> a >> b;
    int res=0;
    for(ll x:t)
      if(x>=a && x<=b)
	++res;
    cout << res << '\n';
  }
}
