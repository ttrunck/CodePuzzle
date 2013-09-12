#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> t;
  for(int i=0;i<n;++i){
    ll tmp;
    cin >> tmp;
    if(tmp<0)
      t.push_back(tmp);
  }
  sort(begin(t), end(t));

  ll x;
  cin >> x;

  ll res=0;
  ll op=0;
  n=t.size();
  if(x-1<n){
    op=-t[x-1];
    res+=op*x;
    n=x-1;
  }

  for(int i=0;i<n;++i)
    res+=-t[i]-op;

  cout << res << '\n';
}
