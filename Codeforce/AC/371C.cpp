#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

const ll INF=100000000000000LL;

ll nb, ns, nc, pb, ps, pc;
ll p;
ll cb=0, cs=0, cc=0;

bool ok(ll n){
  ll cost=0;
  cost+=max(n*cb-nb,0LL)*pb;
  cost+=max(n*cs-ns,0LL)*ps;
  cost+=max(n*cc-nc,0LL)*pc;
  return cost<=p;
}

int main(){
  string s;
  cin >> s;
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> p;

  for(char c:s)
    if(c=='B')
      ++cb;
    else if(c=='S')
      ++cs;
    else
      ++cc;

  ll lo=0, hi=INF;
  while(lo<hi){
    ll x=(lo+hi)/2;
    if(ok(x))
      lo=x+1;
    else
      hi=x;
  }
  if(!ok(lo))
    --lo;
  
  cout << lo << '\n';

}
