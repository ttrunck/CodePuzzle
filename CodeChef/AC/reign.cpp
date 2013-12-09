#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){

  int T;
  cin >> T;
  while(T--){
    int n, k;
    cin >> n >> k;
    vector<ll> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];

    vector<ll> bestLastIn(n);
    bestLastIn[n-1]=t[n-1];
    for(int i=n-2;i>=0;--i)
      bestLastIn[i]=max(t[i], bestLastIn[i+1]+t[i]);

    vector<ll> bestLast(n);
    bestLast[n-1]=bestLastIn[n-1];
    for(int i=n-2;i>=0;--i)
      bestLast[i]=max(bestLastIn[i], bestLast[i+1]);

    ll res=t[0]+t.back();
    ll curr=0;

    for(int i=0;i<n-k-1;++i){
      curr=max(t[i], curr+t[i]);
      res = max(res, curr+bestLast[i+k+1]);
    }

    cout << res << '\n';
  }
}
