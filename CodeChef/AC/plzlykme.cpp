#include<iostream>

using namespace std;

typedef long long ll;

const ll INF=1000000000;

ll pow(ll a, ll b){
  if(a==1) return 1;

  ll res=1;
  for(int i=0;i<b;++i){
    res*=a;
    if(res>=INF)
      return INF;
  }
  
  return res;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll l, d, s, c;
    cin >> l >> d >> s >> c;
    if(s*pow(c+1, d-1)>=l)
      cout << "ALIVE AND KICKING\n";
    else
      cout << "DEAD AND ROTTING\n";
  }
}
