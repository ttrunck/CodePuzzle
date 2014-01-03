#include<iostream>
#include<cassert>

using namespace std;

typedef long long ll;

ll costNaif(ll a, ll b){
  ll res=0;
  for(int i=a;i<=b;++i){
    int nb=0;
    ll ii=i;    
    while(ii!=0){
      ++nb;
      ii/=10;
    }
    res += nb;
  }
  return res;
}

ll cost(ll a, ll b){
  ll sup_a=1, nba=0, aa=a;
  while(aa!=0){
    ++nba;
    sup_a*=10;
    aa/=10;
  }
  ll sup_b=1, nbb=0, bb=b;
  while(bb!=0){
    ++nbb;
    sup_b*=10;
    bb/=10;
  }

  
  if(nba==nbb)
    return (b-a+1)*nba;

  ll res=nba*(sup_a-a);

  while(sup_a<sup_b/10){
    res+=(nba+1)*(sup_a*9);
    sup_a*=10;
    ++nba;
  }

  res+=nbb*(b-sup_b/10+1);

  return res;
}

int main(){
  /*for(int a=1;a<100;++a){
    cerr << a << endl;
    for(int b=a;b<10000;++b)
      if(costNaif(a,b,2)!=cost(a,b,2)){
	cerr << a << ' ' << b << endl;
	cerr << costNaif(a,b,2) << ' ' << cost(a,b,2) << endl;
	return 0;
      }
  }
  */

  ll w, m, k;
  cin >> w >> m >> k;

  ll lo=m, hi=200000000000000009L;

  while(lo<hi){
    ll x=(lo+hi)/2;
    if(cost(m, x)<w/k)
      lo=x+1;
    else
      hi=x;
  }

  if(cost(m,lo)>w/k)
    --lo;

  cout << lo-m+1 << '\n';
}
