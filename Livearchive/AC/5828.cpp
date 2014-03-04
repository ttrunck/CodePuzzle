#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

const ent MOD=1000000007;
const ent N=10000000;

ent pow(ent a, ent b){
  if(b==0) return 1;
  ent tmp=pow(a,b/2);
  if(b%2==0) return (tmp*tmp)%MOD;
  else return a*((tmp*tmp)%MOD)%MOD;
    
}

int main(){
  vector<bool> prime(N,true);
  prime[0]=false;
  prime[1]=false;
  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
  vector<int> prem;
  for(int i=0;i<N;++i)
    if(prime[i])
      prem.push_back(i);

  int n;
  while(cin >> n && n!=0){
    ent res=1;
    for(int i=0;i<int(prem.size());++i){
      int curr=0;
      ent p=prem[i];
      while(n/p!=0){
	curr+=n/p;
	p*=prem[i];
      }
      if(curr%2==1) curr--;
      res=(res*pow(prem[i],curr))%MOD;
    }
    cout << res << '\n';
  }
}
