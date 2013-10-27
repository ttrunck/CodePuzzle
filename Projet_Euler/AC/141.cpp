#include<iostream>
#include<cmath>
#include<set>

using namespace std;

typedef long long ll;

const ll N{1000000000000};

bool isSquare(ll n){
  ll tmp=sqrt(n);
  return tmp*tmp==n;
}

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(){
  set<ll> s;
  for(ll a=1;a<=10000;++a)
    for(ll b=1;b<a;++b){
      if(gcd(a,b)!=1) continue;
      for(ll c=1; ;++c){
	ll n=a*a*a*b*c*c+b*b*c;
	if(n>N) break;
	if(isSquare(n))
	  s.insert(n);
      }
    }

  ll res=0;
  for(ll n:s)
    res+=n;
  cout << res << '\n';
}
