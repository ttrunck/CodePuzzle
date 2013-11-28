#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

bool check(const vector<int>& t, int k, int x){
  if(t.size()<=1) return true;

  vector<int> dp(t.size());
  for(int i=0;i<int(t.size());++i){
    dp[i]=1;
    for(int j=0;j<i;++j){
      long long dist = abs(t[i]-t[j]);
      if (dist<=(i-j)*x) dp[i]=max(dp[i],dp[j]+1);
    }
  }

  ll res=0;
  for(ll elt:dp)
    res=max(res, elt);
  return res+k>=int(t.size());
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  ll lo=0, hi=2.1e9;
  while(hi-lo>1){
    int x=(hi+lo)/2;
    if(check(t, k, x))
      hi=x;
    else
      lo=x;
  }

  if(check(t,k,lo))
    cout << lo << '\n';
  else
    cout << hi << '\n';
}
