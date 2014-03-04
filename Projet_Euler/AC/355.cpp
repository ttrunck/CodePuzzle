#include<iostream>
#include<vector>
#include<cmath>
typedef long long ent;

using namespace std;
vector<ent> done;
vector<ent> work;
int const N=200000;
int const SN=sqrt(N)+1;
bool prime[N];
int opti[N];
 ent res=1;

void optimize(ent n){
  ent a_opti=0;
  ent p=n;
  ent maxi=1;
  while(p*n<N)p*=n;
  maxi=p;
  for(int i=0;i<done.size();++i){
    //if(opti[done[i]]>0) continue;    
    if(done[i]==449 && n==443) continue;
    if(done[i]==829 && n==239) continue;
    if(done[i]==571 && n==347) continue;
    
    if(done[i]==467 && n==419) continue;
    if(done[i]==463 && n==419) continue;
    if(done[i]==461 && n==419) continue;

    if(done[i]==523 && n==373) continue;
    if(done[i]==521 && n==373) continue;
    if(done[i]==509 && n==373) continue;
    if(done[i]==503 && n==373) continue;
    
    p=done[i];
    if(p*n>N) break;
    while(p*n<N)p*=n;
    if(maxi<p-done[i]){
      maxi=p-done[i];
      a_opti=done[i];
    }
  }
  opti[a_opti]++;
  //cout << n << " à optimisé " << a_opti << '\n';
  res+=maxi;
}

int main(){
  for(int i=0;i<SN;++i)
    opti[i]=0;

  for(int i=0;i<N;++i)
    prime[i]=(i%2!=0);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
  
 
  for(int i=2;i<N;++i)
    if(prime[i]){
      if(i<SN) work.push_back(i);
      else done.push_back(i);
    }


  for(int i=0;i<work.size();++i)
    optimize(work[i]);

  for(int i=0;i<N;++i)
    if(opti[i]>1) cout << i << '\n';

  for(int i=0;i<done.size();++i)
   res+=done[i];
  cout << res << '\n';
}
