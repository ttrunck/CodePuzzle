#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int P=10000000;
const int N=1000000000;

ll powMod(ll x, ll n, ll m) {
  ll y = 1;
  while (n != 0) {
    if ((n & 1) == 1)
      y = (y * x) % m;
    x = (x * x) % m;
    n = n >> 1;
  }
  return y;
}

int main(){

  vector<bool> prime(P, true);
  prime[0]=prime[1]=false;
  for(int i=2;i<P;++i)
    if(prime[i])
      for(int j=i+i;j<P;j+=i)
	prime[j]=false;

  int comp=40;
  int res=0;
  int curr=2;
  while(comp){
    if(powMod(10,N,9*curr)==1){
      res+=curr;
      comp--;
      cerr << curr << endl;
    }
    curr++;
    while(curr<P && !prime[curr]) curr++;
  }
  cout << res << endl;
}
