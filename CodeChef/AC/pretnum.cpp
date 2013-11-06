#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int N=1000000;
vector<bool> prime(N,true);

int main(){
prime[0]=prime[1]=false;
  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    ll a,b;
    int res=0;
    cin >> a >> b;

    if(a==1)
      ++a;

    vector<bool> c(b-a+1,true);
    for(ll p=2;p<N && p*p<=b;++p)
      if(prime[p]){
	for(ll j=p*(a/p);j<=b;j+=p)
	  if(j!=p && j-a>=0)
	    c[j-a]=false;
      }

    for(bool b:c)
      if(b)
	++res;

    //    cerr << res << endl;

    for(ll p=2;p<N && p*p<=b;++p)
      if(prime[p]){
	int n=2;
	ll pp=p*p;
	while(pp<=b){
	  if(pp>=a && prime[n+1])
	    ++res;
	  ++n;
	  pp*=p;
	}
      }

    cout << res << '\n';
  }
}
