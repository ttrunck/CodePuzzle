#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

ll mypow(ll a, ll b){
  if(b==0) return 1;
  ll tmp=mypow(a,b/2);
  tmp = (tmp*tmp) % MOD;
  if(b%2==1)
    tmp = (a*tmp) % MOD;
  return tmp;
}

int main(){
  int n, x;
  cin >> n >> x;

  vector<ll> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  ll sum=0;
  for(ll elt:t)
    sum+=elt;

  for(ll& elt:t)
    elt=sum-elt;

  sort(begin(t), end(t));
  reverse(begin(t), end(t));

  // for(int x:t)
  //  cerr << x << ' ';
  //cerr << endl;

  bool cont=true;
  while(cont){
    cont=false;
    int cnt=1;
    ll v=t.back();
    t.pop_back();
    while(t.back()==v){
      ++cnt;
      t.pop_back();
    }
    if(cnt%x==0)
      for(int i=0;i<cnt/x;++i){
	cont=true;
	t.push_back(v+1);
      }
    if(!cont)
      t.push_back(v);
  }

  cout << mypow(x,min(sum,t.back())) << '\n';
}
