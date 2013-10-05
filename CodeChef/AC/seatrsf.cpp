#include<iostream>

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

ll pow(ll x, ll n){
  ll y = 1;
  while(n>0){
    if((n & 1) == 1)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n = n >> 1;
  }
  return y%MOD;
}

int stupid(int n, int m, int q){
  int res=0;
  for(int x=0;x<pow(m,n);++x){
    int mini=m+1, maxi=0;
    int mask=x;
    for(int i=0;i<n;++i){
      mini=min(mini, mask%m);
      maxi=max(maxi, mask%m);
      mask/=m;
    }
    if(maxi-mini==q)
      res++;
  }
  return res;
}

int clever(ll n, ll m, ll q){
  return (max(0LL, m-q)*
	  ((((pow(q+1, n)-2*pow(q, n)+pow(q-1,n))%MOD)+MOD)%MOD)
	  )%MOD;
}

int main(){
  /*
  for(int i=1;i<8;++i)
    for(int j=1;j<8;++j)
      for(int k=1;k<8;++k)
	if(stupid(i,j,k)!=clever(i,j,k))
	  cout << i << ' ' << j << ' ' << k << endl;
  */

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    cout << clever(n, m, q) << '\n';
  }
}
