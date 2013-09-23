#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll binomial(ll k, ll n){
  ll res = 1;
  for (int i = 1; i <= k; ++i)
    res = (n - k + i) * res / i;
  return res;
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    vector<pll> res;
    ll m;
    cin >> m;
    ll n=6, k=3;
    ll tmp=binomial(k, n);
    while(n*(n-1)*(n-2)/6<=m && tmp<=m){
      while(k<=n/2 && tmp<=m){
	if(tmp==m){
	  res.push_back(pll(n,k));
	  if(k!=n-k){
	    res.push_back(pll(n,n-k));
	  }
	}
	k++;
	tmp=binomial(k,n);
      }
      k=3;
      n++;
      tmp=binomial(k,n);
    }

    n=(1+sqrt(1+8*m))/2;
    if(n*(n-1)/2==m){
      res.push_back(pll(n,2));
      if(n!=4)
	res.push_back(pll(n,n-2));
    }

    res.push_back(pll(m,1));
    if(m!=2)
      res.push_back(pll(m,m-1));

    sort(res.begin(), res.end());
    res.resize(distance(res.begin(), unique(res.begin(), res.end())));

    cout << res.size() << '\n';
    for(int i=0;i<int(res.size());++i){
      if(i>0)
	cout << ' '; 
      cout << '(' << res[i].first << ',' << res[i].second << ')';
    }
    cout << '\n';
  }
}
