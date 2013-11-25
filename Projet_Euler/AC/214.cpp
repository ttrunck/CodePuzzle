#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int N=40000000;

int main(){

  vector<int> phi(N);
  for(int i=0;i<N;++i)
    phi[i]=i;
  for(int i=2;i<N;++i)
    if(phi[i]==i){
      --phi[i];
      for(int j=i+i;j<N;j+=i)
	phi[j]=phi[j]/i*(i-1);
    }
    
  vector<int> chain(N,1);
  for(int i=2;i<N;++i)
    chain[i]=1+chain[phi[i]];

  ll res=0;

  for(int i=2;i<N;++i)
    if(phi[i]==i-1 && chain[i]==25)
      res+=i;

  cout << res << '\n';  
}
