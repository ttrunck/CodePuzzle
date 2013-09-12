#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
  return (b==0)?a:gcd(b,a%b);
}

int next(int cost, int lo, int n){
  int hi=n+1;
  while(hi!=lo){
    int x=(hi+lo)/2;
    if(n/x<cost)
      hi=x;
    else
      lo=x+1;
  }
  return lo;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int n;
  while(cin >> n){
    long long res=0;
    int start=1;
    while(start<100000 && start<=n){
      res+=n/start;
      start++;
    }
    while(start<=n){
      int cost=n/start;
      int future=next(cost,start,n);
      res+=cost*(future-start);
      start=future;
    }

    ll nn=n;
    ll div=gcd(nn*nn, res);
    cout << res/div << '/' << nn*nn/div << '\n';
  }
}
