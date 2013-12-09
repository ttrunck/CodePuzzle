#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
  ll n, c;
  cin >> n >> c;
  vector<ll> t(n);

  for(int i=0;i<n;++i)
    cin >> t[i];

  ll sum=0;
  for(ll x:t)
    sum+=x;

  if(sum<c)
    cout << "IMPOSSIBLE\n";
  
  else{
    sort(begin(t), end(t));
    for(int i=0;i<n;++i){
      ll paye=min(t[i], c/(n-i));
      cout << paye << '\n';
      c-=paye;
    }
  }
}
