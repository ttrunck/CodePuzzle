#include<iostream>
#include<vector>
using namespace std;

int const N=1000000;

bool prime[N];
int phit[N];
vector<int> p;

int phi(int n){
  if(phit[n]!=-1) return phit[n];
  int i=0;
  while(n%p[i]!=0)++i;
  int pp=p[i];
  int pk=1;
  while(n%(pk*pp*pp)==0) pk*=pp;
  int tmp= (pp-1)*pk*phi(n/(pk*pp));
  phit[n]=tmp;
  return tmp;
}

int main(){
  for(int i=0;i<N;++i){
    phit[i]=-1;
    prime[i]=(i%2==1);
  }
  phit[0]=1;
  phit[1]=1;
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    if(prime[i])
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  for(int i=2;i<N;++i)
    if(prime[i]) p.push_back(i);

  double maxi;
  int res;

  /*  for(int i=2;i<10;++i)
    cout << i << ' ' << phi(i) << '\n';
  */
  for(int i=2;i<N;++i){
    if(i%10000==0) cout << i << '\n';
 if((double)i/(double)phi(i)>maxi){
      res=i;
      maxi=(double)i/(double)phi(i);
    }
  }
  cout << res << ' ' << phi(res) << '\n';
}
