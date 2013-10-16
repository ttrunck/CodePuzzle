#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int P=20000000;
const int N=20000000;
const int K=15000000;

ll app(int p, int n){
  ll res=0;
  while(n/p>0){
    res+=n/p;
    n/=p;
  }
  return res;
}

int main(){
  vector<bool> prime(P, true);
  prime[0]=prime[1]=false;
  for(int i=2;i<P;++i)
    if(prime[i])
      for(int j=i+i;j<P;j+=i)
	prime[j]=false;

  ll res=0;
  for(ll p=2;p<P;++p)
    if(prime[p]){
      res+=p*(app(p,N)-app(p,K)-app(p,N-K));
    }

  cout << res << endl;
}
