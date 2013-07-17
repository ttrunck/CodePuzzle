#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

int const N=10000000;

bool prime[N];
vector<int> p;

int phi(int n){
  if(n==1) return 1;
  int i=0;
  while(n%p[i]!=0)++i;
  int pp=p[i];
  int pk=1;
  while(n%(pk*pp*pp)==0) pk*=pp;
  int tmp= (pp-1)*pk*phi(n/(pk*pp));
  return tmp;
}

ent powMod(ent x, ent n, ent m){
  ent y = 1;
  while (n != 0) {
    if ((n & 1) == 1)
      y = (y * x) % m;
    x = (x * x) % m;
    n = n >> 1;
  }
  return y;
}

ent gcd(ent x, ent y) { while (y) { x %= y; swap(x, y); } return x; }

ent hyp(ent a, ent k, ent mod){
  //cerr << a << ' ' << k << ' ' << mod << endl;
  if(k==1) return a%mod;
  if(gcd(a,mod)!=1)
    cerr << "Problème a,mod " << a << ' ' << mod << endl; 
  ent tmp=hyp(a,k-1,phi(mod));
  return powMod(a,tmp,mod);
}

int main(){
  for(int i=0;i<N;++i){
    prime[i]=(i%2==1);
  }
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    if(prime[i])
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  for(int i=2;i<N;++i)
    if(prime[i]) p.push_back(i);

  cout << hyp(1777,1855,100000000) << endl;
}
